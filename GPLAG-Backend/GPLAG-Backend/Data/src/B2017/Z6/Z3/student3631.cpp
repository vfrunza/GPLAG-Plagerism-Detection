
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
public:
	Matrica(int br_redova, int br_kolona, char ime = 0);
	Matrica(const Matrica &m);
	Matrica(Matrica &&m);
	~Matrica() {
		DealocirajMemoriju(elementi, br_redova);
	}
	Matrica &operator =(const Matrica &m);
	Matrica &operator =(Matrica &&m);
	template <typename Tip>
	friend Matrica<Tip> operator +(const Matrica<Tip> &m1, const Matrica<Tip> &m2);
	template <typename Tip>
	friend Matrica<Tip> operator -(const Matrica<Tip> &m1, const Matrica<Tip> &m2);
	template <typename Tip>
	friend Matrica<Tip> operator *(const Matrica<Tip> &m1, const Matrica<Tip> &m2);
	template <typename Tip>
	friend std::ostream &operator <<(std::ostream &tok, const Matrica<Tip> &m);
	template <typename Tip>
	friend std::istream &operator >>(std::istream &tok, Matrica<Tip> &m);
	template <typename Tip>
	friend Matrica<Tip> &operator +=(Matrica<Tip> &m1, const Matrica<Tip> &m2);
	template <typename Tip>
	friend Matrica<Tip> &operator -=(Matrica<Tip> &m1, const Matrica<Tip> &m2);
	template <typename Tip>
	friend Matrica<Tip> &operator*=(Matrica<Tip> &m1, const Matrica<Tip> &m2);
	template <typename Tip>
	friend Matrica<Tip> &operator*=(Matrica<Tip> &m1, int n);
	template <typename Tip>
	friend Matrica<Tip> operator*(Matrica<Tip> &m, double n);
	template <typename Tip>
	friend Matrica<Tip> operator*(int n, Matrica<Tip> &m1);
	TipEl &operator()(int i, int j) const {
		if(i < 1 || j < 1 || i > br_redova || j > br_kolona) throw std::range_error("Neispravan indeks");
		return elementi[i-1][j-1];
	}
	TipEl *operator[](int i) {
		return elementi[i];
	}
	TipEl *operator[](int i) const {
		return elementi[i];
	}
	operator std::string() const {
		std::string s;
		s.push_back('{');
		for(int i=0; i<br_kolona; i++) {
			s.push_back('{');
			for(int j=0; j<br_redova; j++) {
				s+=((std::to_string(int(elementi[i][j]))));
				if(j!=br_redova-1) s.push_back(',');
			}
			s.push_back('}');
			if(i!=br_kolona-1) s.push_back(',');
		}
		s.push_back('}');
		return s;
	}
	template <typename Tip2>
	friend Matrica<Tip2> ZbirMatrica(const Matrica<Tip2> &m1,
	                                 const Matrica<Tip2> &m2);
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
Matrica<TipEl> operator +(const Matrica<TipEl> &m1, const Matrica<TipEl> &m2)
{
	if(m1.br_redova != m2.br_redova || m1.br_kolona != m2.br_kolona)
		throw std::domain_error("Matrice nemaju jednake dimenzije!");
	Matrica<TipEl> m3(m1.br_redova, m1.br_kolona);
	for(int i = 0; i < m1.br_redova; i++)
		for(int j = 0; j < m1.br_kolona; j++)
			m3.elementi[i][j] = m1.elementi[i][j] + m2.elementi[i][j];
	return m3;
}template <typename TipEl>
Matrica<TipEl> operator -(const Matrica<TipEl> &m1, const Matrica<TipEl> &m2)
{
	if(m1.br_redova != m2.br_redova || m1.br_kolona != m2.br_kolona)
		throw std::domain_error("Matrice nemaju jednake dimenzije!");
	Matrica<TipEl> m3(m1.br_redova, m1.br_kolona);
	for(int i = 0; i < m1.br_redova; i++)
		for(int j = 0; j < m1.br_kolona; j++)
			m3.elementi[i][j] = m1.elementi[i][j] - m2.elementi[i][j];
	return m3;
}
template <typename TipEl>
Matrica<TipEl> operator *(const Matrica<TipEl> &m1, const Matrica<TipEl> &m2)
{
	if(m1.br_kolona != m2.br_redova)
		throw std::domain_error("Matrice nisu saglasne za mnozenje");
	Matrica<TipEl> m3(m1.br_redova, m2.br_kolona);
	for(int i = 0; i < m1.br_redova; i++){
		for(int j = 0; j < m2.br_kolona; j++)
		{
			m3.elementi[i][j] = 0;
			for(int k=0;k<m2.br_redova;k++) m3.elementi[i][j] += m1.elementi[i][k] * m2.elementi[k][j];
		}
	}
	return m3;
}
template <typename TipEl>
Matrica<TipEl> operator *(Matrica<TipEl> &m, double n) 
{
	auto ret(m);
	for(int i=0;i<m.br_redova;i++){
		for(int j=0;j<m.br_kolona;j++){
			ret.elementi[i][j] = m.elementi[i][j] * n;
		}
	}
	return ret;
}
template <typename TipEl>
Matrica<TipEl> operator *(int n, Matrica<TipEl> &m) {
	return m*n;
}
template <typename TipEl>
Matrica<TipEl> &operator +=(Matrica<TipEl> &m1, const Matrica<TipEl> &m2)
{
	if(m1.br_redova != m2.br_redova || m1.br_kolona != m2.br_kolona)
		throw std::domain_error("Matrice nemaju jednake dimenzije!");
	for(int i=0; i<m1.br_redova; i++) {
		for(int j=0; j<m1.br_kolona; j++) m1.elementi[i][j] = m1.elementi[i][j] + m2.elementi[i][j];
	}
	return m1;
}
template <typename TipEl>
Matrica<TipEl> &operator -=(Matrica<TipEl> &m1, const Matrica<TipEl> &m2)
{
	if(m1.br_redova != m2.br_redova || m1.br_kolona != m2.br_kolona)
		throw std::domain_error("Matrice nemaju jednake dimenzije!");
	for(int i=0; i<m1.br_redova; i++) {
		for(int j=0; j<m1.br_kolona; j++) m1.elementi[i][j] = m1.elementi[i][j] - m2.elementi[i][j];
	}
	return m1;
}
template <typename TipEl>
Matrica<TipEl> &operator *=(Matrica<TipEl> &m1, const Matrica<TipEl> &m2)
{
	if(m1.br_kolona != m2.br_redova)
		throw std::domain_error("Matrice nisu saglasne za mnozenje");
	Matrica<TipEl> temp(m1);
	for(int i=0; i<m1.br_redova; i++) {
		for(int j=0; j<m2.br_kolona; j++) {
			temp[i][j] = 0;
			for(int k=0; k<m2.br_redova; k++) temp[i][j] +=  m1[i][k] * m2[k][j];
		}
	}
	m1=temp;
	return m1;
}
template <typename TipEl>
Matrica<TipEl> &operator *=(Matrica<TipEl> &m, int n) {
	for(int i=0;i<m.br_redova;i++) {
		for(int j=0;j<m.br_kolona;j++) {
			m.elementi[i][j] = m.elementi[i][j] * n;
		}
	}
	return m;
}
template <typename TipEl>
std::istream &operator>>(std::istream &tok, Matrica<TipEl> &mat)
{
	for(int i = 0; i < mat.br_redova; i++)
		for(int j = 0; j < mat.br_kolona; j++) {
			std::cout<<mat.ime_matrice<<"("<<i+1<<","<<j+1<<") = ";
			tok >> mat.elementi[i][j];
		}
	return tok;
}
template <typename TipEl>
std::ostream &operator <<(std::ostream &tok, const Matrica<TipEl> &mat)
{
	int sirina(tok.width());
	for(int i = 0; i < mat.br_redova; i++) {
		for(int j = 0; j < mat.br_kolona; j++)
			tok << std::setw(sirina) << mat.elementi[i][j];
		tok << std::endl;
	}
	return tok;
}
int main()
{
	/*int m, n;
	std::cout << "Unesi broj redova i kolona za matrice:\n";
	std::cin >> m >> n;
	try {
		Matrica<double> a(m, n, 'A'), b(m, n, 'B');
		std::cout << "Unesi matricu A:\n";
		std::cin >> a;
		std::cout << "Unesi matricu B:\n";
		std::cin >> b;
		std::cout << "Zbir ove dvije matrice je:\n";
		std::cout << std::setw(7) << a + b;

	} catch(std::bad_alloc) {
		std::cout << "Nema dovoljno memorije!\n";
	}*/
//AT11 testiranje operatora [] i eksplicitne konverzije matrice u string
//AT 5 testiranje izraza koji kombinuje više operatora, unosa i ispisa
  int m,n;
  std::cout << "Unesi broj redova i kolona za matrice:\n";
  std::cin >> m >> n;
  try {
    Matrica<double> a(m, n, 'A'), b(m, n, 'B');
    std::cout << "Unesi matricu A:\n";
    std::cin >> a;
    std::cout << "Unesi matricu B:\n";
    std::cin >> b;
    std::cout << a;
//std::cout << std::setw(4) << a;
  }
catch(std::bad_alloc) {
    std::cout << "Nema dovoljno memorije!\n";
  }
    catch(std::domain_error e) {
    std::cout << e.what();
  }
    catch(std::range_error e) {
    std::cout << e.what();
  }
}
