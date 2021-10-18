/B2017/2018: Zadaća 6, Zadatak 3
#include <iostream>
#include <iomanip>
#include <cstring>
#include <stdexcept>
#include <new>
#include <string>
 
template <typename TipEl>
class Matrica
{
	int br_redova, br_kolona;
	TipEl **elementi;
	char ime_matrice;
	static TipEl **AlocirajMemoriju(int br_redova, int br_kolona);
	static void DealocirajMemoriju(TipEl **elementi, int br_redova);
	void KopirajElemente(TipEl **elementi);
	void Test(int x, int y) const
	{
 
		if(x<=0 || y<=0 || x>br_redova|| y>br_kolona) throw std::range_error("Neispravan indeks");
	}
public:
	Matrica(int br_redova, int br_kolona, char ime = 0);
	Matrica(const Matrica &m);
	Matrica(Matrica &&m);
	~Matrica() { DealocirajMemoriju(elementi, br_redova); }
	int DajBrojRedova() const { return br_redova; }
	int DajBrojKolona() const { return br_kolona; }
	TipEl **DajElemente()const { return this->elementi; }
	char DajImeMatrice()const { return this->ime_matrice; }
 
	Matrica &operator =(const Matrica &m);
	Matrica &operator =(Matrica &&m);
	TipEl &operator()(int x, int  y) { Test(x,y); return elementi[x-1][y-1]; }
    TipEl operator()(int  x, int  y) const {Test(x,y);  return elementi[x-1][y-1]; }
	operator std::string() const;
 
  	TipEl  *operator []	(int x) const {return elementi[x];}
  	TipEl* &operator [] (int y) {return elementi[y];}
    void SacuvajUTekstualnuDatoteku(std::string ime);
    void SacuvajUBinarnuDatoteku(std::string ime);
    void ObnoviIzTekstualneDatoteke(std::string ime);
    void ObnoviIzBinarneDatoteke(std::string ime);
 
};
template <typename TipEl>
Matrica<TipEl>::operator std::string() const{
	std::string tok;
	auto elementi=DajElemente();
	tok='{';
	for(int i=0;i<DajBrojRedova();i++)
	{
		tok+='{';
		for(int j=0;j<DajBrojKolona();j++)
		{
		tok+=std::to_string(int(elementi[i][j]));
		if ( j==DajBrojKolona()-1)tok+="}";
		if ( j!=DajBrojKolona()-1)tok+=',';
		}
	
		if(i!=DajBrojRedova()-1)tok+=",";
	}
	tok.push_back('}');

	return tok;
}
 
 
template <typename TipEl>
std::istream &operator >>(std::istream &tok, Matrica<TipEl> &m)
{
	auto elementi = m.DajElemente();
	for (int i = 0; i < m.DajBrojRedova(); i++)
		for (int j = 0; j < m.DajBrojKolona(); j++)
		{
			std::cout << m.DajImeMatrice() << "(" << i + 1 << "," << j + 1 << ") = ";
			tok >> elementi[i][j];
		}
	return tok;
}
 
template <typename TipEl>
std::ostream &operator <<(std::ostream &tok, const Matrica<TipEl> &m) {
	int  sirina_ispisa = tok.width();
	auto elementi = m.DajElemente();
	for (int i = 0; i < m.DajBrojRedova(); i++) {
		for (int j = 0; j < m.DajBrojKolona(); j++)
			tok << std::setw(sirina_ispisa) << elementi[i][j];
		tok << std::endl;
	}
	return tok;
}
 
 
template <typename TipEl>
Matrica<TipEl> operator +(const Matrica<TipEl> &m1, const Matrica<TipEl> &m2)
{
 
	if (m1.DajBrojRedova() != m2.DajBrojRedova() || m1.DajBrojKolona() != m2.DajBrojKolona()) throw std::domain_error("Matrice nemaju jednake dimenzije!");
	Matrica<TipEl> m3(m1.DajBrojRedova(), m1.DajBrojKolona());
	auto elementi3 = m3.DajElemente();
	auto elementi1 = m1.DajElemente();
	auto elementi2 = m2.DajElemente();
	for (int i = 0; i < m1.DajBrojRedova(); i++)
		for (int j = 0; j < m1.DajBrojKolona(); j++)
			elementi3[i][j] = elementi1[i][j] + elementi2[i][j];
	return m3;
 
}
 
template <typename TipEl>
Matrica<TipEl> operator +=(Matrica<TipEl> &m1, const Matrica<TipEl> &m2)
{
	if (m1.DajBrojRedova() != m2.DajBrojRedova() || m1.DajBrojKolona() != m2.DajBrojKolona()) throw std::domain_error("Matrice nemaju jednake dimenzije!");
	m1=m1 + m2;
	return m1;
 
}
 
template <typename TipEl>
Matrica<TipEl> operator -(const Matrica<TipEl> &m1, const Matrica<TipEl> &m2)
{
	if (m1.DajBrojRedova() != m2.DajBrojRedova() || m1.DajBrojKolona() != m2.DajBrojKolona()) throw std::domain_error("Matrice nemaju jednake dimenzije!");
	Matrica<TipEl> m3(m1.DajBrojRedova(), m1.DajBrojKolona());
	auto elementi3 = m3.DajElemente();
	auto elementi1 = m1.DajElemente();
	auto elementi2 = m2.DajElemente();
	for (int i = 0; i < m1.DajBrojRedova(); i++)
		for (int j = 0; j < m1.DajBrojKolona(); j++)
			elementi3[i][j] = elementi1[i][j] - elementi2[i][j];
	return m3;
}
 
template <typename TipEl>
Matrica<TipEl> operator -=(Matrica<TipEl> &m1, const Matrica<TipEl> &m2)
{
	if (m1.DajBrojRedova() != m2.DajBrojRedova() || m1.DajBrojKolona() != m2.DajBrojKolona()) throw std::domain_error("Matrice nemaju jednake dimenzije!");
	m1= m1- m2;
	return m1;
}
 
template <typename TipEl>
Matrica<TipEl> operator *(const Matrica<TipEl> &m1, const Matrica<TipEl> &m2)
{
	if (m1.DajBrojKolona() != m2.DajBrojRedova()) throw std::domain_error("Matrice nisu saglasne za mnozenje");
	Matrica<TipEl> m3(m1.DajBrojRedova(), m2.DajBrojKolona());
	auto elementi3 = m3.DajElemente();
	auto elementi1 = m1.DajElemente();
	auto elementi2 = m2.DajElemente();
	for (int i = 0;i<m1.DajBrojRedova();i++) {
		for (int j = 0;j<m2.DajBrojKolona();j++) {
			elementi3[i][j] = 0;
			for (int k = 0;k<m1.DajBrojRedova();k++) {
				elementi3[i][j] = elementi3[i][j] + (elementi1[i][k] * elementi2[k][j]);
			}
		}
	}
	return m3;
}
 
template <typename TipEl>
Matrica<TipEl> operator *=(Matrica<TipEl> &m1, const Matrica<TipEl> &m2)
{
	if (m1.DajBrojRedova() != m2.DajBrojRedova() || m1.DajBrojKolona() != m2.DajBrojKolona()) throw std::domain_error("Matrice nemaju jednake dimenzije!");
	m1 =m1*m2;
	return m1;
}
 
 
template<typename TipEl>
Matrica<TipEl> operator *(int n, const Matrica<TipEl> &m1)
{
	Matrica<TipEl> m3(m1.DajBrojRedova(), m1.DajBrojKolona());
	auto elementi3 = m3.DajElemente();
	auto elementi1 = m1.DajElemente();
	for (int i = 0;i<m1.DajBrojRedova();i++)
		for (int j = 0;j<m1.DajBrojKolona();j++)
			elementi3[i][j] = n*elementi1[i][j];
	return m3;
}
 
template<typename TipEl>
Matrica<TipEl> operator *(const Matrica<TipEl> &m1,int n)
{
	Matrica<TipEl> m3(m1.DajBrojRedova(), m1.DajBrojKolona());
	auto elementi3 = m3.DajElemente();
	auto elementi1 = m1.DajElemente();
	for (int i = 0;i<m1.DajBrojRedova();i++)
		for (int j = 0;j<m1.DajBrojKolona();j++)
			elementi3[i][j] = n*elementi1[i][j];
	return m3;
}
 
 
template<typename TipEl>
Matrica<TipEl> operator *=(int n, Matrica<TipEl> &m1)
{
	m1=n*m1;
	return m1;
}
 
template<typename TipEl>
Matrica<TipEl> operator *=( Matrica<TipEl> &m1,int n)
{
	m1=m1*n;
	return m1;
}
template <typename TipEl>
TipEl ** Matrica<TipEl>::AlocirajMemoriju(int br_redova, int br_kolona)
{
	TipEl **elementi(new TipEl*[br_redova] {});
	try {
		for (int i = 0; i < br_redova; i++)
			elementi[i] = new TipEl[br_kolona]{};
	}
	catch (...)
	{
		DealocirajMemoriju(elementi, br_redova);
		throw;
	}
	return elementi;
}
 
template <typename TipEl>
void Matrica<TipEl>::DealocirajMemoriju(TipEl **elementi, int br_redova)
{
	for (int i = 0; i < br_redova; i++)
		delete[] elementi[i];
	delete[] elementi;
}
 
 
template <typename TipEl>
Matrica<TipEl>::Matrica(int br_redova, int br_kolona, char ime) : br_redova(br_redova), br_kolona(br_kolona), elementi(AlocirajMemoriju(br_redova, br_kolona)), ime_matrice(ime) {}
 
template <typename TipEl>
void Matrica<TipEl>::KopirajElemente(TipEl **elementi)
{
	for (int i = 0; i < br_redova; i++)
		for (int j = 0; j < br_kolona; j++)
			Matrica::elementi[i][j] = elementi[i][j];
}
 
template <typename TipEl>
Matrica<TipEl>::Matrica(const Matrica<TipEl> &m) : br_redova(m.br_redova), br_kolona(m.br_kolona), ime_matrice(m.ime_matrice), elementi(AlocirajMemoriju(m.br_redova, m.br_kolona))
{
	KopirajElemente(m.elementi);
}
 
 
template <typename TipEl>
Matrica<TipEl>::Matrica(Matrica<TipEl> &&m) : br_redova(m.br_redova), br_kolona(m.br_kolona), elementi(m.elementi), ime_matrice(m.ime_matrice)
{
	m.br_redova = 0; m.elementi = nullptr;
}
 
template <typename TipEl>
Matrica<TipEl> &Matrica<TipEl>::operator =(const Matrica<TipEl> &m)
{
	if (br_redova < m.br_redova || br_kolona < m.br_kolona)
	{
		TipEl **novi_prostor(AlocirajMemoriju(m.br_redova, m.br_kolona));
		DealocirajMemoriju(elementi, br_redova);
		elementi = novi_prostor;
	}
	else if (br_redova > m.br_redova)
		for (int i = m.br_redova; i < br_redova; i++) delete elementi[i];
	br_redova = m.br_redova; br_kolona = m.br_kolona;
	ime_matrice = m.ime_matrice;
	KopirajElemente(m.elementi);
	return *this;
}
 
 
template <typename TipEl>
Matrica<TipEl> &Matrica<TipEl>::operator =(Matrica<TipEl> &&m)
{
	std::swap(br_redova, m.br_redova); std::swap(br_kolona, m.br_kolona);
	std::swap(ime_matrice, m.ime_matrice); std::swap(elementi, m.elementi);
	return *this;
}
int main() {
 int m, n;
 std::cout << "Unesi broj redova i kolona za matrice:\n";
 std::cin >> m >> n;
 try {
 Matrica<double> a(m, n, 'A'), b(m, n, 'B');
 std::cout << "Unesi matricu A:\n";
std::cin>>a;
 std::cout << "Unesi matricu B:\n";
std::cin>>b;
 std::cout << "Zbir ove dvije matrice je:\n";
std::cout<<a+b;
 }
 catch(std::bad_alloc) {
 std::cout << "Nema dovoljno memorije!\n";
 }
 catch(std::range_error izuzetak){
  std::cout<<izuzetak.what()<<"\n";
 }
 catch(std::domain_error izuzetak){
  std::cout<<izuzetak.what()<<"\n";
 }
 return 0;
}