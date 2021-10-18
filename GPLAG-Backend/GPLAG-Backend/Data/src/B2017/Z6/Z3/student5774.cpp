#include <iostream>
#include <iomanip>
#include <cstring>
#include <string>
#include <fstream>
#include <stdexcept>
#include <new>
#include <sstream>
#include <iomanip>

template <typename T>
class Matrica
{
	int br_redova{}, br_kolona;
	T **elementi{};
	char ime_matrice;
	static T **AlocirajMemoriju(int br_redova, int br_kolona);
	static void DealocirajMemoriju(T **elementi, int br_redova);
	void KopirajElemente(T **elementi);
public:
	Matrica(int br_redova, int br_kolona, char ime = 0);
	Matrica(const std::string &ime, bool b)
	{
		if (b) ObnoviIzBinarneDatoteke(ime);
		else ObnoviIzTekstualneDatoteke(ime);
	}
	Matrica(const Matrica &m);
	Matrica(Matrica &&m);
	~Matrica() { DealocirajMemoriju(elementi, br_redova); }
	Matrica &operator =(const Matrica &m);
	Matrica &operator =(Matrica &&m);
	T *operator[](int i) { return elementi[i]; }
	const T *operator[](int i) const { return elementi[i]; }
	T &operator()(int i, int j);
	T operator()(int i, int j) const;
	Matrica &operator +=(const Matrica&);
	Matrica &operator -=(const Matrica&);
    Matrica &operator *=(const Matrica&);
	template <typename U> Matrica &operator *=(U x);
	template <typename U> friend Matrica<U> operator +(Matrica<U> a, const Matrica<U> &b);
	template <typename U> friend Matrica<U> operator -(Matrica<U> a, const Matrica<U> &b);
	template <typename U> friend Matrica<U> operator *(Matrica<U> m1, const Matrica<U> &m2);
	template <typename U> friend std::istream &operator >>(std::istream &is, Matrica<U> &m);
	template <typename U> friend std::ostream &operator <<(std::ostream &o, const Matrica<U> &m);
	operator std::string();
	
	void SacuvajUTekstualnuDatoteku(const std::string&);
	void SacuvajUBinarnuDatoteku(const std::string&);
	void ObnoviIzTekstualneDatoteke(const std::string&);
	void ObnoviIzBinarneDatoteke(const std::string&);
};
//Pomocne funkcije za izuzetke
void ne_postoji() { throw std::logic_error("Trazena datoteka ne postoji"); }
void problem_upis() { throw std::logic_error("Problemi sa upisom u datoteku"); }
void problem_citanje() { throw std::logic_error("Problemi pri citanju datoteke"); }
void besmisleni() { throw std::logic_error("Datoteka sadrzi besmislene podatke"); }

template <typename T> void Matrica<T>::SacuvajUTekstualnuDatoteku(const std::string &ime)
{
	std::ofstream f(ime);
	if (!f) problem_upis();
    for (int i(0); i < br_redova && f.good(); ++i)
    {
    	if (i != 0) f << '\n';
    	for (int j(0); j < br_kolona; ++j)
    	{
    		if (j != 0) f << ',';
    		if (!(f << elementi[i][j])) problem_upis();
    	}
    }
}
template <typename T> void Matrica<T>::SacuvajUBinarnuDatoteku(const std::string &ime)
{
	std::ofstream f(ime, std::ios::binary);
	if (!f) problem_upis();
	f.write(reinterpret_cast<char*>(&br_kolona), sizeof br_kolona);
	for (int i(0); i < br_redova; ++i)
		if (!f.write(reinterpret_cast<char*>(elementi[i]), br_kolona * sizeof(T)))
			problem_upis();
}
//?Sta ako datoteka ima viska ili manjka podataka
template <typename T> void Matrica<T>::ObnoviIzBinarneDatoteke(const std::string &ime)
{
	std::ifstream f(ime, std::ios::binary);
	if (!f) ne_postoji();
	//Citanje broja kolona
	int m, n;
	f.read(reinterpret_cast<char*>(&n), sizeof n);
	//Mjerenje duzine fajla
	f.seekg(0, std::ios::end);
	m = int(f.tellg()) - int(sizeof(br_kolona));
	m /= n * sizeof(T);
	if (f.bad()) problem_citanje();
	T **mat(AlocirajMemoriju(m, n));
	f.seekg(sizeof n);
	for (int i(0); i < m && f.good(); ++i) try
	{
		if (f.read(reinterpret_cast<char*>(mat[i]), n * sizeof(T)).bad()) problem_citanje();
	}
	catch (...) { DealocirajMemoriju(mat, m); throw; }
	DealocirajMemoriju(elementi, br_redova);
	elementi = mat;
	br_redova = m; br_kolona = n;
}
template <typename T> void Matrica<T>::ObnoviIzTekstualneDatoteke(const std::string &ime)
{
	std::ifstream f(ime, std::ios::in);
	if (!f) ne_postoji();
	int m(0), n(-1), p(0);
	T x;
	char c(0);
	while (f.good())
	{
		if (f.peek() == '\n' || (c == ',' && f.eof())) besmisleni();
		if (f.bad()) problem_citanje();
		if (f.eof()) break;
		f >> x; ++p;
		if (f.eof() || (c = f.peek()) == '\n')
		{
			if (n == -1) n = p;
			else if (n != p) besmisleni();
			p = 0;
			++m;
		}
		else if (c != ',') besmisleni();
		if (!f.eof()) f.get();
		if (f.bad()) problem_citanje();
	}
	if (n < 1) m = n = 0;
	T **mat(AlocirajMemoriju(m, n));
	f.clear();
	f.seekg(0);
	for (int i(0); i < m ; ++i) 
		for (int j(0); j < n; ++j) try
		{
			f >> mat[i][j];
			if (!f.eof()) f.get();
			if (f.bad()) problem_citanje();
		}
	catch (...) { DealocirajMemoriju(mat, m); throw; }
	DealocirajMemoriju(elementi, br_redova);
	elementi = mat;
	br_redova = m; br_kolona = n;
}

template <typename T>
std::istream &operator >>(std::istream &is, Matrica<T> &m)
{
	for(int i = 0; i < m.br_redova; i++)
		for(int j = 0; j < m.br_kolona; j++)
		{
			std::cout << m.ime_matrice << "(" << i + 1 << "," << j + 1 << ") = ";
			is >> m.elementi[i][j];
		}
	return is;
}
template <typename T>
std::ostream &operator <<(std::ostream &o, const Matrica<T> &m)
{
	int w(o.width());
	for(int i = 0; i < m.br_redova; i++)
	{
		for(int j = 0; j < m.br_kolona; j++)
			o << std::setw(w) << m.elementi[i][j];
			o << std::endl;
	}
	return o;
}
template <typename T, typename U> Matrica<T> operator *(Matrica<T> m, U x) { return m *= x; }
template <typename T, typename U> Matrica<T> operator *(U x, Matrica<T> m) { return m *= x; }
template <typename T>
T ** Matrica<T>::AlocirajMemoriju(int br_redova, int br_kolona)
{
	T **elementi(new T*[br_redova]{});
	try {
		for(int i = 0; i < br_redova; i++) elementi[i] = new T[br_kolona];
	} catch(...) {
		DealocirajMemoriju(elementi, br_redova); throw;
	}
	return elementi;
}
template <typename T>
void Matrica<T>::DealocirajMemoriju(T **elementi, int br_redova)
{
	for(int i = 0; i < br_redova; i++) delete[] elementi[i];
	delete[] elementi;
}
template <typename T>
Matrica<T>::Matrica(int br_redova, int br_kolona, char ime) : br_redova(br_redova), br_kolona(br_kolona), elementi(AlocirajMemoriju(br_redova, br_kolona)), ime_matrice(ime) {}
template <typename T>
void Matrica<T>::KopirajElemente(T **elementi)
{
	for(int i = 0; i < br_redova; i++)
		for(int j = 0; j < br_kolona; j++)
			Matrica::elementi[i][j] = elementi[i][j];
}
template <typename T> Matrica<T>::Matrica(const Matrica<T> &m) : br_redova(m.br_redova), br_kolona(m.br_kolona), elementi(AlocirajMemoriju(m.br_redova, m.br_kolona)), ime_matrice(m.ime_matrice)
{
	KopirajElemente(m.elementi);
}
template <typename T>
Matrica<T>::Matrica(Matrica<T> &&m) : br_redova(m.br_redova), br_kolona(m.br_kolona), elementi(m.elementi), ime_matrice(m.ime_matrice)
{
	m.br_redova = 0;
	m.elementi = nullptr;
}
template <typename T>
Matrica<T> &Matrica<T>::operator =(const Matrica<T> &m)
{
	if (br_redova < m.br_redova || br_kolona < m.br_kolona)
	{
		T **novi_prostor(AlocirajMemoriju(m.br_redova, m.br_kolona));
		DealocirajMemoriju(elementi, br_redova);
		elementi = novi_prostor;
	}
	else if (br_redova > m.br_redova)
		for (int i(m.br_redova); i < br_redova; i++) delete elementi[i];
	br_redova = m.br_redova;
	br_kolona = m.br_kolona;
	ime_matrice = m.ime_matrice;
	KopirajElemente(m.elementi);
	return *this;
}
template <typename T>
Matrica<T> &Matrica<T>::operator =(Matrica<T> &&m)
{
	std::swap(br_redova, m.br_redova);
	std::swap(br_kolona, m.br_kolona);
	std::swap(ime_matrice, m.ime_matrice);
	std::swap(elementi, m.elementi);
	return *this;
}
template <typename T> T &Matrica<T>::operator()(int i, int j)
{
	if (i < 1 || j < 1 || i > br_redova || j > br_kolona) throw std::range_error("Neispravan indeks"); 
	return elementi[i-1][j-1];
}
template <typename T> T Matrica<T>::operator()(int i, int j) const
{
	if (i < 1 || j < 1 || i > br_redova || j > br_kolona) throw std::range_error("Neispravan indeks"); 
	return elementi[i-1][j-1];
}
template <typename T> Matrica<T> &Matrica<T>::operator +=(const Matrica<T> &b)
{
	if(br_redova != b.br_redova || br_kolona != b.br_kolona)
		throw std::domain_error("Matrice nemaju jednake dimenzije!");
	for(int i = 0; i < br_redova; i++)
		for(int j = 0; j < br_kolona; j++)
			elementi[i][j] += b.elementi[i][j];
	return *this;
}
template <typename T> Matrica<T> &Matrica<T>::operator -=(const Matrica<T> &b)
{
	if(br_redova != b.br_redova || br_kolona != b.br_kolona)
		throw std::domain_error("Matrice nemaju jednake dimenzije!");
	for(int i = 0; i < br_redova; i++)
		for(int j = 0; j < br_kolona; j++)
			elementi[i][j] -= b.elementi[i][j];
	return *this;
}
template <typename T> Matrica<T> &Matrica<T>::operator *=(const Matrica<T> &m2)
{
	if(br_kolona != m2.br_redova)
		throw std::domain_error("Matrice nisu saglasne za mnozenje");
	Matrica m(*this);
	for(int i = 0; i < br_redova; ++i)
		for(int j = 0; j < br_kolona; ++j)
		{
			double x(0);
			for (int k(0); k < br_kolona; ++k)
				x += m.elementi[i][k] * m2.elementi[k][j];
			elementi[i][j] = x;
		}
	return *this;
}
template <typename T> template <typename U> Matrica<T> &Matrica<T>::operator *=(U x)
{
	for (int i(0); i < br_redova; ++i)
		for (int j(0); j < br_kolona; ++j)
			(*this)[i][j] *= x;
	return *this;
}
template <typename T>
Matrica<T> operator -(Matrica<T> a, const Matrica<T> &b) { return a -= b; }
template <typename T>
Matrica<T> operator +(Matrica<T> a, const Matrica<T> &b) { return a += b; }
template <typename T>
Matrica<T> operator *(Matrica<T> m1, const Matrica<T> &m2) { return m1 *= m2; }
template <typename T> Matrica<T>::operator std::string()
{
	std::string s("{");
	for (int i(0); i < br_redova; ++i)
	{
		(i != 0 ? s += ',' : s ) += '{';
		for (int j(0); j < br_kolona; ++j)
		{
			std::ostringstream oss;
			oss << (*this)[i][j];
			(j != 0 ? s += ',' : s) += oss.str();
		}
		s += '}';
	}
	return s += '}';
}
int main()
{
	Matrica<double> m(5, 5);
	for (int i(0); i < 5; ++i)
		for (int j(0); j < 5; ++j)
			m[i][j] = i + 2 * j + j / 10.;
	try
	{
		m.SacuvajUBinarnuDatoteku("binarna.bin");
		m.SacuvajUTekstualnuDatoteku("tekstualna.txt");
		m.ObnoviIzBinarneDatoteke("binarna.bin");
		std::cout << std::left << std::setw(5) << m;
		m.ObnoviIzTekstualneDatoteke("tekstualna.txt");
		std::cout << '\n' << std::setw(5) << m;
		m = Matrica<double>("binarna.bin", true);
		std::cout << '\n' << std::setw(5) << m;
	} catch (const std::exception &e) { std::cout << e.what(); }
	return 0;
}