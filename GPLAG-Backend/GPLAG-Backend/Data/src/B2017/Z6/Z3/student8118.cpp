// Zadatak3.cpp : Defines the entry point for the console application.


#include <iostream>
#include <iomanip>
#include <cstring>
#include <stdexcept>
#include <new>
#include <iomanip>
#include <fstream>
#include <ios>
#include <sstream>


template <typename TipEl>
class Matrica
{
	int br_redova, br_kolona;                                     
	TipEl **elementi;
	char ime_matrice;
	static TipEl **AlocirajMemoriju(int br_redova, int br_kolona);
	static void DealocirajMemoriju(TipEl **elementi, int br_redova);
	void KopirajElemente(TipEl **elementi);
	void TestIndeksa(int index1, int index2) const {
		if (index1<1 || index2<1 || index1>br_redova || index2>br_kolona) throw std::range_error("Neispravan indeks");
	}
public:
	operator std::string() const;
	Matrica(int br_redova, int br_kolona, char ime = 0);
	Matrica(const Matrica &m);
	Matrica(Matrica &&m);
	~Matrica() {
		DealocirajMemoriju(elementi, br_redova);
	}
	Matrica &operator =(const Matrica &m);
	Matrica &operator =(Matrica &&m);
	template <typename Tip>
	friend std::ostream &operator <<(std::ostream &tok, const Matrica<Tip> &mat);
	template <typename Tip>
	friend std::istream &operator >>(std::istream &tok, Matrica<Tip> &mat);
	template <typename Tip>
	friend Matrica<Tip> operator +(const Matrica<Tip> &m1, const Matrica<Tip> &m2);
	template <typename Tip>
	friend Matrica<Tip> operator -(const Matrica<Tip> &m1, const Matrica<Tip> &m2);
	template <typename Tip>
	friend Matrica<Tip> operator *(const Matrica<Tip> &m1, const Matrica<Tip> &m2);
	template <typename Tip>
	friend Matrica<Tip> operator *(const Matrica<Tip> &m1, double broj);
	template <typename Tip>
	friend Matrica<Tip> operator *(double broj, const Matrica<Tip> &m1);
	TipEl* operator [](int b);
	TipEl& operator ()(int a, int b);
	TipEl* operator [](int b) const;
	TipEl operator ()(int a, int b) const;
	Matrica<TipEl>& operator +=(const Matrica<TipEl> &m2);
	Matrica<TipEl>& operator -=(const Matrica<TipEl> &m2);
	Matrica<TipEl>& operator *=(const Matrica<TipEl> &m2);
	Matrica<TipEl>& operator *=(double broj);
	void SacuvajUTekstualnuDatoteku(std::string imedat);
	void SacuvajUBinarnuDatoteku(std::string imedat);
	void ObnoviIzTekstualneDatoteke(std::string imedat);
	void ObnoviIzBinarneDatoteke(std::string imedat);
	Matrica(std::string imedat, bool binarna);
};
template <typename TipEl>
TipEl **Matrica<TipEl>::AlocirajMemoriju(int br_redova, int br_kolona)
{
	TipEl **elementi(new TipEl*[br_redova] {});
	try {
		for (int i = 0; i<br_redova; i++) elementi[i] = new TipEl[br_kolona];
	}
	catch (...) {
		DealocirajMemoriju(elementi, br_redova);
		throw;
	}
	return elementi;
}
template <typename TipEl>
void Matrica<TipEl>::DealocirajMemoriju(TipEl **elementi, int br_redova)
{
	for (int i = 0; i<br_redova; i++) delete[] elementi[i];
	delete[] elementi;
}
template <typename TipEl>
Matrica<TipEl>::Matrica(int br_redova, int br_kolona, char ime) : br_redova(br_redova), br_kolona(br_kolona), ime_matrice(ime), elementi(AlocirajMemoriju(br_redova, br_kolona)) {}
template <typename TipEl>
void Matrica<TipEl>::KopirajElemente(TipEl **elementi)
{
	for (int i = 0; i < br_redova; i++)
		for (int j = 0; j < br_kolona; j++)
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
template <typename Tip>
std::ostream &operator <<(std::ostream &tok, const Matrica<Tip> &mat)
{
	int sirina = tok.width();
	for (int i = 0; i<mat.br_redova; i++) {
		for (int j = 0; j<mat.br_kolona; j++) {
			tok << std::setw(sirina) << mat.elementi[i][j];
		}
		tok << std::endl;
	}
	return tok;
}
template <typename Tip>
std::istream &operator >>(std::istream &tok, Matrica<Tip> &mat)
{
	for (int i = 0; i<mat.br_redova; i++)
		for (int j = 0; j<mat.br_kolona; j++) {
			std::cout << mat.ime_matrice << "(" << i + 1 << "," << j + 1 << ") = ";
			tok >> mat.elementi[i][j];
		}
	return tok;
}
template <typename Tip>
Matrica<Tip> operator +(const Matrica<Tip> &m1, const Matrica<Tip> &m2)
{
	if (m1.br_redova != m2.br_redova || m1.br_kolona != m2.br_kolona)
		throw std::domain_error("Matrice nemaju jednake dimenzije!");
	Matrica<Tip> m3(m1.br_redova, m1.br_kolona);
	for (int i = 0; i<m1.br_redova; i++)
		for (int j = 0; j<m1.br_kolona; j++)
			m3.elementi[i][j] = m1.elementi[i][j] + m2.elementi[i][j];
	return m3;
}
template <typename Tip>
Tip* Matrica<Tip>::operator [](int b)
{
	return elementi[b];
}
template <typename Tip>
Tip& Matrica<Tip>::operator ()(int a, int b)
{
	TestIndeksa(a, b);
	return elementi[a - 1][b - 1];
}
template <typename Tip>
Tip Matrica<Tip>::operator ()(int a, int b) const
{
	TestIndeksa(a, b);
	return elementi[a - 1][b - 1];
}
template <typename Tip>
Tip* Matrica<Tip>::operator [](int b) const
{
	return elementi[b];
}
template <typename TipEl>
Matrica<TipEl>& Matrica<TipEl>::operator +=(const Matrica<TipEl> &m2)
{
	if (br_redova != m2.br_redova || br_kolona != m2.br_kolona)
		throw std::domain_error("Matrice nemaju jednake dimenzije!");
	for (int i = 0; i<br_redova; i++) {
		for (int j = 0; j<br_kolona; j++) {
			elementi[i][j] += m2[i][j];
		}
	}
	return *this;
}
template <typename TipEl>
Matrica<TipEl>& Matrica<TipEl>::operator -=(const Matrica<TipEl> &m2)
{
	if (br_redova != m2.br_redova || br_kolona != m2.br_kolona)
		throw std::domain_error("Matrice nemaju jednake dimenzije!");
	for (int i = 0; i<br_redova; i++) {
		for (int j = 0; j<br_kolona; j++) {
			elementi[i][j] -= m2[i][j];
		}
	}
	return *this;
}
template <typename Tip>
Matrica<Tip> operator *(const Matrica<Tip> &m1, const Matrica<Tip> &m2)
{
	if (m1.br_kolona != m2.br_redova) throw std::domain_error("Matrice nisu saglasne za mnozenje");
	Matrica<Tip> m3(m1.br_redova, m2.br_kolona);
	for (int i = 0; i<m3.br_redova; i++) {
		for (int j = 0; j<m3.br_kolona; j++) {
			Tip suma(0);
			for (int k = 0; k<m1.br_kolona; k++)
				suma += m1.elementi[i][k] * m2.elementi[k][j];
			m3.elementi[i][j] = suma;
		}
	}
	return m3;
}
template <typename Tip>
Matrica<Tip> operator *(const Matrica<Tip> &m1, double broj)
{
	Matrica<Tip> mat(m1);
	for (int i = 0; i<m1.br_redova; i++) {
		for (int j = 0; j<m1.br_kolona; j++) {
			mat[i][j] *= broj;
		}
	}
	return mat;
}
template <typename Tip>
Matrica<Tip> operator *(double broj, const Matrica<Tip> &m1)
{
	return m1*broj;
}
template <typename Tip>
Matrica<Tip> operator -(const Matrica<Tip> &m1, const Matrica<Tip> &m2)
{
	if (m1.br_redova != m2.br_redova || m1.br_kolona != m2.br_kolona)
		throw std::domain_error("Matrice nemaju jednake dimenzije!");
	Matrica<Tip> m3(m1.br_redova, m1.br_kolona);
	for (int i = 0; i<m1.br_redova; i++)
		for (int j = 0; j<m1.br_kolona; j++)
			m3.elementi[i][j] = m1.elementi[i][j] - m2.elementi[i][j];
	return m3;
}
template <typename TipEl>
Matrica<TipEl>& Matrica<TipEl>::operator *=(const Matrica<TipEl> &m2)
{
	return *this = (*this)*m2;
}
template <typename TipEl>
Matrica<TipEl>& Matrica<TipEl>::operator *=(double broj)
{
	return *this = (*this)*broj;
}
template <typename TipEl>
Matrica<TipEl>::operator std::string() const
{
	std::string s;
	s.push_back('{');
	for (int i = 0; i<br_redova; i++) {
		s.push_back('{');
		for (int j = 0; j<br_kolona; j++) {
			if (j == br_kolona - 1) {
				s += std::to_string(int(elementi[i][j]));
				s.push_back('}');
				break;
			}
			s += std::to_string(int(elementi[i][j]));
			s.push_back(',');
		}
		if (i == br_redova - 1) {
			s.push_back('}');
			break;
		}
		s.push_back(',');
	}
	return s;
}
template<typename TipEl>
Matrica<TipEl> &Matrica<TipEl>::operator=(Matrica<TipEl> &&m)
{
	std::swap(br_redova, m.br_redova);
	std::swap(br_kolona, m.br_kolona);
	std::swap(ime_matrice, m.ime_matrice);
	std::swap(elementi, m.elementi);
	return *this;
}
template <typename TipEl>
Matrica<TipEl> &Matrica<TipEl>::operator =(const Matrica<TipEl> &m)
{
	if (br_redova < m.br_redova || br_kolona < m.br_kolona) {
		TipEl **novi_prostor(AlocirajMemoriju(m.br_redova, m.br_kolona));
		DealocirajMemoriju(elementi, br_redova);
		elementi = novi_prostor;
	}
	else if (br_redova > m.br_redova)
		for (int i = m.br_redova; i < br_redova; i++) delete elementi[i];
	br_redova = m.br_redova;
	br_kolona = m.br_kolona;
	ime_matrice = m.ime_matrice;
	KopirajElemente(m.elementi);
	return *this;
}
template <typename TipEl>
void Matrica<TipEl>::SacuvajUTekstualnuDatoteku(std::string imedat) {
	std::ofstream datoteka(imedat);
	for (int i = 0; i < br_redova; i++) {
		for (int j = 0; j < br_kolona; j++) {
			datoteka << elementi[i][j];
			if (j != br_kolona - 1) datoteka << ",";
			if (!datoteka) throw std::logic_error("Problemi sa upisom u datoteku");
		}
		datoteka << std::endl;
	}
}
template <typename TipEl>
void Matrica<TipEl>::SacuvajUBinarnuDatoteku(std::string imedat) {
	std::ofstream datoteka(imedat,std::ofstream::binary);
	datoteka.write(reinterpret_cast<char*>(this), sizeof *this);
	for (int i = 0; i < br_redova; i++) {
		for (int j = 0; j < br_kolona; j++) {
			datoteka.write(reinterpret_cast<char*>(&elementi[i][j]), sizeof elementi[i][j]);
			if (!datoteka) throw std::logic_error("Problemi sa upisom u datoteku");
		}
	}
}
template <typename TipEl> 
void Matrica<TipEl>::ObnoviIzTekstualneDatoteke(std::string imedat) {
	std::ifstream dat(imedat);
	if (!dat) throw std::logic_error("Trazena datoteka ne postoji");
	char znak;
	TipEl broj;
	int redovi(0),kolone(0),kolone2(0);
	std::string linijaudat;
	bool logicka(false);
	for (;;) {
		std::getline(dat,linijaudat);
		if (dat.bad()) throw std::logic_error("Datoteka sadrzi besmislene podatke");
		kolone=0;
		for (std::istringstream input(linijaudat); !input.eof();) {
			input>>std::ws>>broj;
			znak=input.get();
			if (input.bad() || (!input.eof() && znak!=',') || linijaudat.empty() || !std::isdigit(linijaudat.back()))
				throw std::logic_error("Datoteka sadrzi besmislene podatke");
			kolone++;
			if (znak=='\n') break;
		}
		if (kolone!=0) redovi++;
		if (!logicka)  { logicka=true; kolone2=kolone; }
		else if (kolone2!=kolone) throw std::logic_error("Datoteka sadrzi besmislene podatke");
		if (dat.eof()) break;
		}
	if (kolone==0 || redovi==0) throw std::logic_error("Datoteka sadrzi besmislene podatke");
	Matrica<TipEl> mat=Matrica<TipEl>(kolone,redovi,ime_matrice);
	dat.clear();
	dat.seekg(0,std::ios::beg);
	for (int i=0;i<redovi;i++) {
		std::getline(dat,linijaudat);
		std::istringstream input(linijaudat);
		for (int j=0;j<kolone;j++) {
			input>>mat[i][j];
			if (input.get() == '\n' || input.eof()) break;
		}
	}
	*this=std::move(mat);
	
}
template <typename TipEl>
void Matrica<TipEl>::ObnoviIzBinarneDatoteke(std::string imedat) {
	for (int i = 0; i < br_redova; i++) delete[] elementi[i];
	delete[] elementi;
	std::ifstream datoteka(imedat, std::ifstream::binary);
	if (!datoteka) throw std::logic_error("Trazena datoteka ne postoji");
	datoteka.read(reinterpret_cast<char*>(this), sizeof *this);
	elementi = new TipEl*[br_redova];
	for (int i = 0; i < br_redova; i++) elementi[i] = new TipEl[br_kolona];
	for (int i = 0; i < br_redova; i++) {
		for (int j = 0; j < br_kolona; j++) {
			datoteka.read(reinterpret_cast<char*>(&elementi[i][j]), sizeof elementi[i][j]);
			if (!datoteka) throw std::logic_error("Datoteka sadrzi besmislene podatke");
		}
	}
}
template <typename TipEl>
Matrica<TipEl>::Matrica(std::string imedat, bool binarna) : elementi(nullptr), br_redova(0),br_kolona(0),ime_matrice('A') {
	if (binarna) ObnoviIzBinarneDatoteke(imedat);
	else ObnoviIzTekstualneDatoteke(imedat);
}

int main()
{
	int m, n;
	std::cout << "Unesi broj redova i kolona za matrice:\n";
	std::cin >> m >> n;
	std::cout.width(5);
	try {
		Matrica<double> a(m, n, 'A'), b(m, n, 'B');
		std::cout << "Unesi matricu A:\n";
		std::cin >> a;
		std::cout << "Unesi matricu B:\n";
		std::cin >> b;
		a.SacuvajUTekstualnuDatoteku("matrica.txt");
		b.SacuvajUBinarnuDatoteku("matrica2.dat");
		b.ObnoviIzBinarneDatoteke("matrica2.dat");
		a.ObnoviIzTekstualneDatoteke("matrica.txt");
		std::cout<<std::setw(5) << b;
		std::cout<<std::setw(5) << a;
	}
	catch (std::bad_alloc) {
		std::cout << "Nema dovoljno memorije!\n";
	}
	catch (std::domain_error e) {
		std::cout << e.what();
	}
	catch (std::range_error e) {
		std::cout << e.what();
	}
	catch (std::logic_error e) {
		std::cout << e.what();
	}
	return 0;
}
