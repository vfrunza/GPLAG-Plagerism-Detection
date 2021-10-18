/B2017/2018: Zadaća 6, Zadatak 3
#include <iostream>
#include <iomanip>
#include <cstring>
#include <stdexcept>
#include <new>
#include <fstream>
#include <string>

template <typename TipEl>
class Matrica {
	public:
	int br_redova, br_kolona;
	TipEl **elementi;
	char ime_matrice;
	static TipEl **AlocirajMemoriju(int br_redova, int br_kolona);
	static void DealocirajMemoriju(TipEl **elementi, int br_redova);
	void KopirajElemente(TipEl **elementi);
	Matrica(int br_redova, int br_kolona, char ime = 0);
	Matrica(const Matrica &m);
	Matrica(Matrica &&m);
	~Matrica() {
		DealocirajMemoriju(elementi, br_redova);
	}
	Matrica &operator =(const Matrica &m);
	Matrica &operator =(Matrica &&m);
	template <typename Tip2>
	friend std::istream &operator >>(std::istream &tok ,Matrica<Tip2> &m);
	template <typename Tip2>
	friend std::ostream &operator <<(std::ostream &tok,const Matrica<Tip2> &m) ;
	template <typename Tip2>
	friend Matrica<Tip2> ZbirMatrica(const Matrica<Tip2> &m1,const Matrica<Tip2> &m2);
	template <typename Tip2>
	friend Matrica<Tip2> &operator +=( Matrica<Tip2> &m1,const Matrica<Tip2> &m2);
	template <typename Tip2>
	friend  Matrica<Tip2> operator +(const Matrica<Tip2> &m1,const Matrica<Tip2> &m2);
	template <typename Tip2>
	friend Matrica<Tip2>operator -(const Matrica<Tip2> &m1,const Matrica<Tip2> &m2);
	template <typename Tip2>
	friend Matrica<Tip2> &operator -=( Matrica<Tip2> &m1,const Matrica<Tip2> &m2);
	template <typename Tip2>
	friend Matrica<Tip2> operator *(const Matrica<Tip2> &m1,const Matrica<Tip2> &m2);
	template <typename Tip2>
	friend Matrica<Tip2> &operator *=( Matrica<Tip2> &m1,const Matrica<Tip2> &m2);
	template <typename Tip2>
	friend Matrica<Tip2> &operator *=( Matrica<Tip2> &m1,int a);
	template <typename Tip2>
	friend Matrica<Tip2> operator *(int a,const Matrica<Tip2> &m2);
	template <typename Tip2>
	friend Matrica<Tip2> operator *(const Matrica<Tip2> &m1,int a);

	TipEl* operator [](int i) {
		if(i<0||i>=br_redova)throw std::range_error {"Neispravan indeks"};
		return elementi[i];
	}
	TipEl &operator () (int i,int j) {
		if(i<=0||j<=0||i>br_redova||j>br_kolona)throw std::range_error {"Neispravan indeks"};
		return elementi[i-1][j-1];
	}
	TipEl operator ()(int i, int j)const {
		if(i<=0||j<=0||i>br_redova||j>br_kolona)throw std::range_error {"Neispravan indeks"};
		return elementi[i-1][j-1];
	}
	Matrica(std::string ime, bool bin_ili_txt) {
	    if(bin_ili_txt) 
	        ObnoviIzBinarneDatoteke(ime);
	    else 
	        ObnoviIzTekstualneDatoteke(ime);
	}
	void SacuvajUTekstualnuDatoteku(std::string ime) {
	    
	}
	
	
};

template <typename TipEl>
TipEl ** Matrica<TipEl>::AlocirajMemoriju(int br_redova, int br_kolona)
{
	TipEl **elementi(new TipEl*[br_redova] {});
	try {
		for(int i = 0; i < br_redova; i++) elementi[i] = new TipEl[br_kolona];
	} catch(...) {
		DealocirajMemoriju(elementi, br_redova);
		throw;
	}
	return elementi;
}
template <typename TipEl>
void Matrica<TipEl>::DealocirajMemoriju(TipEl **elementi, int br_redova)
{
	for(int i = 0; i < br_redova; i++) delete[] elementi[i];
	delete[] elementi;
}
template <typename TipEl>
Matrica<TipEl>::Matrica(int br_redova, int br_kolona, char ime) :
	br_redova(br_redova), br_kolona(br_kolona), ime_matrice(ime),
	elementi(AlocirajMemoriju(br_redova, br_kolona)) {}
template <typename TipEl>
void Matrica<TipEl>::KopirajElemente(TipEl **elementi)
{
	for(int i = 0; i < br_redova; i++)
		for(int j = 0; j < br_kolona; j++)
			Matrica::elementi[i][j] = elementi[i][j];
}
template <typename TipEl>
Matrica<TipEl>::Matrica(const Matrica<TipEl> &m) : br_redova(m.br_redova),
	br_kolona(m.br_kolona), ime_matrice(m.ime_matrice),
	elementi(AlocirajMemoriju(m.br_redova, m.br_kolona))
{
	KopirajElemente(m.elementi);
}
template <typename TipEl>
Matrica<TipEl>::Matrica(Matrica<TipEl> &&m) : br_redova(m.br_redova),
	br_kolona(m.br_kolona), elementi(m.elementi), ime_matrice(m.ime_matrice)
{
	m.br_redova = 0;
	m.elementi = nullptr;
}
template <typename TipEl>
Matrica<TipEl> &Matrica<TipEl>::operator =(const Matrica<TipEl> &m)
{
	if(br_redova < m.br_redova || br_kolona < m.br_kolona) {
		TipEl **novi_prostor(AlocirajMemoriju(m.br_redova, m.br_kolona));
		DealocirajMemoriju(elementi, br_redova);
		elementi = novi_prostor;
	} else if(br_redova > m.br_redova)
		for(int i = m.br_redova; i < br_redova; i++) delete elementi[i];
	br_redova = m.br_redova;
	br_kolona = m.br_kolona;
	ime_matrice = m.ime_matrice;
	KopirajElemente(m.elementi);
	return *this;
}
template <typename TipEl>
Matrica<TipEl> &Matrica<TipEl>::operator =(Matrica<TipEl> &&m)
{
	std::swap(br_redova, m.br_redova);
	std::swap(br_kolona, m.br_kolona);
	std::swap(ime_matrice, m.ime_matrice);
	std::swap(elementi, m.elementi);
	return *this;
}
template <typename TipEl>
std::istream &operator >>(std::istream &tok,Matrica<TipEl> &mat)
{
	for(int i = 0; i < mat.br_redova; i++)
		for(int j = 0; j < mat.br_kolona; j++) {
			std::cout << mat.ime_matrice << "(" << i + 1 << "," << j + 1 << ") = ";
			tok >> mat.elementi[i][j];
		}
	return tok;
}
template <typename TipEl>
std::ostream &operator <<(std::ostream &tok,const Matrica<TipEl> &m)
{
	int w(tok.width());
	for(int i = 0; i < m.br_redova; i++) {
		for(int j = 0; j < m.br_kolona; j++)
			tok << std::setw(w) << m.elementi[i][j];
		tok << std::endl;
	}
	return tok;
}

template <typename Tip2>
Matrica<Tip2> &operator +=(Matrica<Tip2> &m1,const Matrica<Tip2> &m2)
{
	if(m1.br_redova != m2.br_redova || m1.br_kolona != m2.br_kolona)
		throw std::domain_error("Matrice nemaju jednake dimenzije!");
	for(int i = 0; i < m1.br_redova; i++)
		for(int j = 0; j < m1.br_kolona; j++)
			m1.elementi[i][j] += m2.elementi[i][j];
	return m1;
}
template <typename Tip2>
Matrica<Tip2> operator +(const Matrica<Tip2> &m1,const Matrica<Tip2> &m2)
{
	if(m1.br_redova != m2.br_redova || m1.br_kolona != m2.br_kolona)
		throw std::domain_error("Matrice nemaju jednake dimenzije!");
	Matrica<Tip2> m3(m1.br_redova, m1.br_kolona);
	m3=m1;
	m3+=m2;
	return m3;
}
template <typename Tip2>
Matrica<Tip2> &operator -=( Matrica<Tip2> &m1,const Matrica<Tip2> &m2)
{
	if(m1.br_redova != m2.br_redova || m1.br_kolona != m2.br_kolona)
		throw std::domain_error("Matrice nemaju jednake dimenzije!");
	for(int i = 0; i < m1.br_redova; i++)
		for(int j = 0; j < m1.br_kolona; j++)
			m1.elementi[i][j] -= m2.elementi[i][j];
	return m1;
}
template <typename Tip2>
Matrica<Tip2> operator -(const Matrica<Tip2> &m1,const Matrica<Tip2> &m2)
{
	if(m1.br_redova != m2.br_redova || m1.br_kolona != m2.br_kolona)
		throw std::domain_error("Matrice nemaju jednake dimenzije!");
	Matrica<Tip2> m3(m1.br_redova, m1.br_kolona);
	m3=m1;
	m3-=m2;
	return m3;
}
template <typename TipElemenata>
int broj(Matrica<TipElemenata> a,Matrica<TipElemenata> b,int i,int j)
{
	int suma=0;
	for(int k=0; k<a.br_kolona; k++) {
		suma+=a.elementi[i][k]*b.elementi[k][j];
	}
	return suma;
}
template <typename Tip2>
Matrica<Tip2> &operator *=( Matrica<Tip2> &m1,const Matrica<Tip2> &m2)
{
	if(m1.br_kolona != m2.br_redova )
		throw std::domain_error("Matrice nisu saglasne za mnozenje");
	Matrica<Tip2> m3(m1.br_redova, m2.br_kolona);
	for(int i = 0; i < m2.br_kolona; i++)
		for(int j = 0; j < m1.br_redova; j++)
			m3.elementi[i][j] = broj(m1,m2,i,j);
	m1=m3;
	return m1;
}
template <typename Tip2>
Matrica<Tip2> operator *(const Matrica<Tip2> &m1,const Matrica<Tip2> &m2)
{
	if(m1.br_kolona != m2.br_redova )
		throw std::domain_error("Matrice nisu saglasne za mnozenje");
	Matrica<Tip2> m3(m1.br_redova, m2.br_kolona);
	for(int i = 0; i < m2.br_kolona; i++)
		for(int j = 0; j < m1.br_redova; j++)
			m3.elementi[i][j] = broj(m1,m2,i,j);
	return m3;
}
template <typename Tip2>
Matrica<Tip2> operator *(int a,const Matrica<Tip2> &m2)
{
	Matrica<Tip2> m3(m2.br_redova, m2.br_kolona);
	for(int i = 0; i < m2.br_redova; i++)
		for(int j = 0; j < m2.br_kolona; j++)
			m3.elementi[i][j]=m2.elementi[i][j]*a;
	return m3;
}
template <typename Tip2>
Matrica<Tip2> operator *(const Matrica<Tip2> &m2,int a)
{
	Matrica<Tip2> m3(m2.br_redova, m2.br_kolona);
	for(int i = 0; i < m2.br_redova; i++)
		for(int j = 0; j < m2.br_kolona; j++)
			m3.elementi[i][j]=m2.elementi[i][j]*a;
	return m3;
}
template <typename Tip2>
Matrica<Tip2> &operator *=( Matrica<Tip2> &m1,int a)
{
	for(int i = 0; i < m1.br_kolona; i++)
		for(int j = 0; j < m1.br_redova; j++)
			m1.elementi[i][j] *= a;
	return m1;
}
int main()
{


	return 0;
}