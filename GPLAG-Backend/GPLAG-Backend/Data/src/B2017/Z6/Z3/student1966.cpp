/B2017/2018: Zadaća 6, Zadatak 3
#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstring>
#include <stdexcept>
#include <new>

template <typename TipEl>
class Matrica {
	int br_redova, br_kolona;
	TipEl **elementi;
	char ime_matrice;
	static TipEl **AlocirajMemoriju(int br_redova, int br_kolona);
	void DealocirajMemoriju();
	void KopirajElemente(TipEl **elementi);
	 
public:
	Matrica(int br_redova, int br_kolona, char ime = 0);
	Matrica(const Matrica &m);
	Matrica(Matrica &&m);
	Matrica(const std::string &naziv, bool jeLiBinarna) :
		br_redova(0), br_kolona(0), elementi(nullptr), ime_matrice(0) {
			if (jeLiBinarna)
				ObnoviIzBinarneDatoteke(naziv);
			else
				ObnoviIzTekstualneDatoteke(naziv);
		}
	
	~Matrica() { DealocirajMemoriju(); }
	
	Matrica &operator=(const Matrica &m);
	Matrica &operator=(Matrica &&m);
	
	template <typename T>
	friend std::istream &operator>>(std::istream &in, Matrica<T> &m);
	template <typename T>
	friend std::ostream &operator<<(std::ostream &out, const Matrica<T> &m);
	
	template <typename T>
	friend Matrica<T> operator+(const Matrica<T> &m1, const Matrica<T> &m2);
	template <typename T>
	friend Matrica<T> operator-(const Matrica<T> &m1, const Matrica<T> &m2);
	template <typename T>
	friend Matrica<T> operator*(const Matrica<T> &m1, const Matrica<T> &m2);
	template <typename T, typename S>
	friend Matrica<T> operator*(const Matrica<T> &m, S s);
	template <typename T, typename S>
	friend Matrica<T> operator*(S s, const Matrica<T> &m);
	
	Matrica &operator+=(const Matrica &m);
	Matrica &operator-=(const Matrica &m);
	Matrica &operator*=(const Matrica &m);
	Matrica &operator*=(TipEl s);
	
	TipEl *operator[](int red) {
		return elementi[red];
	}
	
	TipEl *operator[](int red) const {
		return elementi[red];
	}
	
	TipEl &operator()(int red, int kolona) {
		if (red < 1 || kolona < 1 || red > br_redova || kolona > br_kolona)
			throw std::range_error("Neispravan indeks");
			
		return elementi[red - 1][kolona - 1];
	}
	
	TipEl operator()(int red, int kolona) const {
		if (red < 1 || kolona < 1 || red > br_redova || kolona > br_kolona)
			throw std::range_error("Neispravan indeks");
			
		return elementi[red - 1][kolona - 1];
	}
	
	operator std::string() const;
	
	void SacuvajUTekstualnuDatoteku(const std::string &naziv) const;
	void SacuvajUBinarnuDatoteku(const std::string &naziv) const;
	void ObnoviIzTekstualneDatoteke(const std::string &naziv);
	void ObnoviIzBinarneDatoteke(const std::string &naziv);
};

template <typename TipEl>
TipEl ** Matrica<TipEl>::AlocirajMemoriju(int br_redova, int br_kolona) {
	TipEl **elementi(new TipEl*[br_redova]{});
	try {
		for(int i = 0; i < br_redova; i++)
			elementi[i] = new TipEl[br_kolona];
	}
	catch(...) {
		for(int i = 0; i < br_redova; i++)
			delete[] elementi[i];
		delete[] elementi;
		
		throw;
	}
	 
	return elementi;
}

template <typename TipEl>
void Matrica<TipEl>::DealocirajMemoriju() {
	for(int i = 0; i < br_redova; i++)
		delete[] elementi[i];
	delete[] elementi;
	elementi = nullptr;
	
	br_redova = 0;
	br_kolona = 0;
}

template <typename TipEl>
Matrica<TipEl>::Matrica(int br_redova, int br_kolona, char ime) :
	br_redova(br_redova), br_kolona(br_kolona), 
	elementi(AlocirajMemoriju(br_redova, br_kolona)),
	ime_matrice(ime) {}

template <typename TipEl>
void Matrica<TipEl>::KopirajElemente(TipEl **elementi) {
	for(int i = 0; i < br_redova; i++)
		for(int j = 0; j < br_kolona; j++)
			Matrica::elementi[i][j] = elementi[i][j];
}

template <typename TipEl>
Matrica<TipEl>::Matrica(const Matrica<TipEl> &m) : br_redova(m.br_redova),
	br_kolona(m.br_kolona), ime_matrice(m.ime_matrice),
	elementi(AlocirajMemoriju(m.br_redova, m.br_kolona)) {
		KopirajElemente(m.elementi);
}

template <typename TipEl>
Matrica<TipEl>::Matrica(Matrica<TipEl> &&m) : br_redova(m.br_redova),
	br_kolona(m.br_kolona), elementi(m.elementi), ime_matrice(m.ime_matrice) {
		m.br_redova = 0; m.elementi = nullptr;
}

template <typename TipEl>
Matrica<TipEl> &Matrica<TipEl>::operator=(const Matrica<TipEl> &m) {
	if(br_redova < m.br_redova || br_kolona < m.br_kolona) {
		TipEl **novi_prostor(AlocirajMemoriju(m.br_redova, m.br_kolona));
		DealocirajMemoriju();
		elementi = novi_prostor;
	}
	else if(br_redova > m.br_redova)
		for(int i = m.br_redova; i < br_redova; i++)
			delete elementi[i];
	
	br_redova = m.br_redova; br_kolona = m.br_kolona;
	ime_matrice = m.ime_matrice; KopirajElemente(m.elementi);
	return *this;
}

template <typename TipEl>
Matrica<TipEl> &Matrica<TipEl>::operator=(Matrica<TipEl> &&m) {
	std::swap(br_redova, m.br_redova); std::swap(br_kolona, m.br_kolona);
	std::swap(ime_matrice, m.ime_matrice); std::swap(elementi, m.elementi);
	return *this;
}

template <typename TipEl>
std::istream &operator>>(std::istream &in, Matrica<TipEl> &m) {
	for(int i = 0; i < m.br_redova; i++)
		for(int j = 0; j < m.br_kolona; j++) {
			std::cout << m.ime_matrice << "(" << i + 1 << "," << j + 1 << ") = ";
			in >> m.elementi[i][j];
		}
		
	return in;
}

template <typename TipEl>
std::ostream &operator<<(std::ostream &out, const Matrica<TipEl> &m) {
	unsigned int sirina_ispisa = out.width();
	
	for(int i = 0; i < m.br_redova; i++) {
		for(int j = 0; j < m.br_kolona; j++)
			out << std::setw(sirina_ispisa) << m.elementi[i][j];
		out << std::endl;
	}
	
	return out;
}

template <typename T>
Matrica<T> operator+(const Matrica<T> &m1, const Matrica<T> &m2) {
	if(m1.br_redova != m2.br_redova || m1.br_kolona != m2.br_kolona)
		throw std::domain_error("Matrice nemaju jednake dimenzije!");
	
	Matrica<T> m3(m1.br_redova, m2.br_kolona);
	for(int i = 0; i < m1.br_redova; i++)
		for(int j = 0; j < m1.br_kolona; j++)
			m3.elementi[i][j] = m1.elementi[i][j] + m2.elementi[i][j];
			
	return m3;
}

template <typename T>
Matrica<T> operator-(const Matrica<T> &m1, const Matrica<T> &m2) {
	if(m1.br_redova != m2.br_redova || m1.br_kolona != m2.br_kolona)
		throw std::domain_error("Matrice nemaju jednake dimenzije!");
	
	Matrica<T> m3(m1.br_redova, m2.br_kolona);
	for(int i = 0; i < m1.br_redova; i++)
		for(int j = 0; j < m1.br_kolona; j++)
			m3.elementi[i][j] = m1.elementi[i][j] - m2.elementi[i][j];
			
	return m3;
}

template <typename T>
Matrica<T> operator*(const Matrica<T> &m1, const Matrica<T> &m2) {
	if(m1.br_kolona != m2.br_redova)
		throw std::domain_error("Matrice nisu saglasne za mnozenje");
	
	Matrica<T> m3(m1.br_redova, m2.br_kolona);
	for(int i = 0; i < m1.br_redova; i++)
		for(int j = 0; j < m2.br_kolona; j++) {
			m3.elementi[i][j] = 0;
			for (int k = 0; k < m1.br_kolona; k++)
				m3.elementi[i][j] += m1.elementi[i][k] * m2.elementi[k][j];
		}
			
	return m3;
}

template <typename T, typename S>
Matrica<T> operator*(const Matrica<T> &m, S s) {
	Matrica<T> m2(m.br_redova, m.br_kolona);
	for(int i = 0; i < m.br_redova; i++)
		for(int j = 0; j < m.br_kolona; j++)
			m2.elementi[i][j] = m.elementi[i][j] * s;
			
	return m2;
}

template <typename T, typename S>
Matrica<T> operator*(S s, const Matrica<T> &m) {
	return m * s;
}

template <typename T>
Matrica<T> &Matrica<T>::operator+=(const Matrica<T> &m) {
	if(br_redova != m.br_redova || br_kolona != m.br_kolona)
		throw std::domain_error("Matrice nemaju jednake dimenzije!");
	
	for(int i = 0; i < br_redova; i++)
		for(int j = 0; j < br_kolona; j++)
			elementi[i][j] += m.elementi[i][j];
			
	return *this;
}

template <typename T>
Matrica<T> &Matrica<T>::operator-=(const Matrica<T> &m) {
	if(br_redova != m.br_redova || br_kolona != m.br_kolona)
		throw std::domain_error("Matrice nemaju jednake dimenzije!");
	
	for(int i = 0; i < br_redova; i++)
		for(int j = 0; j < br_kolona; j++)
			elementi[i][j] -= m.elementi[i][j];
			
	return *this;
}

template <typename T>
Matrica<T> &Matrica<T>::operator*=(const Matrica<T> &m) {
	if(br_kolona != m.br_redova)
		throw std::domain_error("Matrice nisu saglasne za mnozenje");
	
	Matrica<T> tmp(br_redova, m.br_kolona);
	for(int i = 0; i < br_redova; i++)
		for(int j = 0; j < m.br_kolona; j++) {
			tmp.elementi[i][j] = 0;
			
			for (int k = 0; k < br_kolona; k++)
				tmp.elementi[i][j] += elementi[i][k] * m.elementi[k][j];
		}
	
	*this = tmp;
	return *this;
}
template <typename T>
Matrica<T> &Matrica<T>::operator*=(T s) {
	for (int i = 0; i < br_redova; i++)
		for (int j = 0; j < br_kolona; j++)
			elementi[i][j] *= s;
			
	return *this;
}

template <typename T>
Matrica<T>::operator std::string() const {
	std::string res("{");
	for (int i = 0; i < br_redova; i++)
	{
		res += "{";
		for (int j = 0; j < br_kolona; j++)
		{
			std::string tmp = std::to_string(double(elementi[i][j]));
			
			int pozNenulta = -1;
			for (int t = 0; t < tmp.length(); t++)
				pozNenulta = tmp[t] == '0' ? pozNenulta : t;
				
			tmp = tmp.substr(0, pozNenulta + 1);
			if (*tmp.rbegin() == '.')
				tmp = tmp.substr(0, tmp.length() - 1);
				
			res += tmp;
			res += j != br_kolona - 1 ? "," : "";
		}
		res += "}";
		res += i != br_redova - 1 ? "," : "";
	}
	
	res += "}";
	return res;
}

template <typename T>
void Matrica<T>::SacuvajUTekstualnuDatoteku(const std::string &naziv) const {
	std::ofstream out(naziv);
	for (int i = 0; i < br_redova; i++) {
		for (int j = 0; j < br_kolona; j++) {
			out << (j ? "," : "") << elementi[i][j];
		}
		out << std::endl;
	}
	
	if (!out)
		throw std::logic_error("Problemi sa upisom u datoteku");
}

template <typename T>
void Matrica<T>::SacuvajUBinarnuDatoteku(const std::string &naziv) const {
	std::ofstream out(naziv);
	out.write(reinterpret_cast<const char *>(&br_redova), sizeof(br_redova));
	out.write(reinterpret_cast<const char *>(&br_kolona), sizeof(br_kolona));
	for (int i = 0; i < br_redova; i++)
		out.write((char *)elementi[i], sizeof(T) * br_kolona);
	
	if (!out)
		throw std::logic_error("Problemi sa upisom u datoteku");
}

template <typename T>
void Matrica<T>::ObnoviIzTekstualneDatoteke(const std::string &naziv)
{
	std::ifstream in(naziv);
	if (!in)
		throw std::logic_error("Trazena datoteka ne postoji");
	
	int t_br_redova(0), t_br_kolona(0);
	do {
		int tmpBrKolona(0);
		char znak(-1);
		do {
			T tmpBr;
			in >> tmpBr;
			if (!in)
				break;
			tmpBrKolona++;
			znak = in.get();
		}
		while (in && znak == ',');
		
		if (in && (znak != '\n' || (t_br_kolona && tmpBrKolona != t_br_kolona)))
			throw std::logic_error("Datoteka sadrzi besmislene podatke");
		
		if (tmpBrKolona) {
			t_br_redova++;
			t_br_kolona = tmpBrKolona;
		}
	}
	while (in);
	
	if (in.bad())
		throw std::logic_error("Problemi pri citanju datoteke");
	else if (!in.eof())
		throw std::logic_error("Datoteka sadrzi besmislene podatke");
	
	if (elementi)
		DealocirajMemoriju();
	elementi = AlocirajMemoriju(t_br_redova, t_br_kolona);
	br_redova = t_br_redova;
	br_kolona = t_br_kolona;
	
	in.close();
	in.open(naziv);
	
	for (int i = 0; i < br_redova; i++) {
		for (int j = 0; j < br_kolona; j++) {
			in >> elementi[i][j];
			in.get();
		}
	}
}

template <typename T>
void Matrica<T>::ObnoviIzBinarneDatoteke(const std::string &naziv) {
	std::ifstream in(naziv);
	if (!in)
		throw std::logic_error("Trazena datoteka ne postoji");
	
	int t_br_redova, t_br_kolona;
	in.read(reinterpret_cast<char *>(&t_br_redova), sizeof(br_redova));
	in.read(reinterpret_cast<char *>(&t_br_kolona), sizeof(br_kolona));
	if (!in)
		throw std::logic_error("Problemi pri citanju datoteke");
	
	if (elementi)
		DealocirajMemoriju();
	elementi = AlocirajMemoriju(t_br_redova, t_br_kolona);
	br_redova = t_br_redova;
	br_kolona = t_br_kolona;
	
	for (int i = 0; i < br_redova; i++)
		in.read((char *)elementi[i], sizeof(T) * br_kolona);
	
	if (!in)
		throw std::logic_error("Problemi pri citanju datoteke");
}
	
int main() {
	int m, n;
	std::cout << "Unesi broj redova i kolona za matrice:\n";
	std::cin >> m >> n;
	
	try {
		Matrica<int> a(m, n, 'A'), b(m, n, 'B');
		std::cout << "Unesi matricu A:\n";
		std::cin >> a;
		std::cout << "Unesi matricu B:\n";
		std::cin >> b;
		std::cout << "Zbir ove dvije matrice je:\n";
		std::cout << std::setw(7) << a + b;
		std::cout << std::string(a + b) << std::endl;
		(2 * (a + b)).SacuvajUTekstualnuDatoteku("test.txt");
		Matrica<int> c("test.txt", 0);
		std::cout << c << std::endl;
		
	}
	catch(std::bad_alloc) {
		std::cout << "Nema dovoljno memorije!\n";
	}

    return 0;
}