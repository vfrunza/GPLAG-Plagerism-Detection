/B2017/2018: Zadaća 6, Zadatak 3
#include <iostream>
#include <iomanip>
#include <cstring>
#include <stdexcept>
#include <new>
#include <string>
#include <fstream>




template <typename TipEl>
class Matrica
{
	int br_redova, br_kolona;
	char ime_matrice;
	TipEl **elementi;
	void TestIndeksa(int indeks) const {
		if(indeks < 1 || indeks > br_kolona*br_redova) throw std::range_error("Neispravan indeks");
	}

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

	template <typename TipEl2>
	friend std::istream &operator >>(std::istream &tok, Matrica<TipEl2> &m);

	template <typename TipEl2>
	friend std::ostream &operator <<(std::ostream &tok, const Matrica<TipEl2> &m);

	template <typename Tip2>
	friend Matrica<Tip2> operator +(const Matrica<Tip2> &m1, const Matrica<Tip2> &m2);

	template <typename Tip2>
	friend Matrica<Tip2> operator -(const Matrica<Tip2> &m1, const Matrica<Tip2> &m2);

	template <typename Tip2>
	friend Matrica<Tip2> operator *(const Matrica<Tip2> &m1, const Matrica<Tip2> &m2);

	template <typename Tip2>
	friend Matrica<Tip2> operator *(const Matrica<Tip2> &m1, int n);

	template <typename Tip2>
	friend inline Matrica<Tip2> operator *(int n, const Matrica<Tip2> &m1);

	template <typename Tip2>
	friend Matrica<Tip2> &operator +=(Matrica<Tip2> &m1, const Matrica<Tip2> &m2);

	template <typename Tip2>
	friend Matrica<Tip2> &operator -=(Matrica<Tip2> &m1, const Matrica<Tip2> &m2);

	template <typename Tip2>
	friend Matrica<Tip2> &operator *=(Matrica<Tip2> &m1, const Matrica<Tip2> &m2);

	template <typename Tip2>
	friend Matrica<Tip2> &operator *=(Matrica<Tip2> &m1, int n);

	template <typename Tip2>
	friend inline Matrica<Tip2> &operator *=(int n, Matrica<Tip2> &m1);


	//indeksiranje

	TipEl *operator [](int i) const {
		return elementi[i];
	}
	TipEl *&operator [](int i) {
		return elementi[i];
	}
	TipEl operator ()(int i, int j) const {
		TestIndeksa(i);
		TestIndeksa(j);
		return elementi[i-1][j-1];
	}
	TipEl &operator ()(int i, int j) {
		TestIndeksa(i);
		TestIndeksa(j);
		return elementi[i-1][j-1];
	}
	operator std::string() const;

	//NOVO_____________________________________________________________

//sacuvaj
	void SacuvajUTekstualnuDatoteku(std::string ime_datoteke) const { 
		std::ofstream tok(ime_datoteke.c_str());
		for(int i=0; i<br_redova; i++) {
			for(int j=0; j<br_kolona; j++) {
				tok<<elementi[i][j];
				if(j != br_kolona-1) tok<<",";
			}
			tok<<"\n";
		}
		if(!tok) throw std::logic_error("Problemi sa upisom u datoteku\n");
	}

	void SacuvajUBinarnuDatoteku(std::string ime_datoteke) const {
		std::ofstream tok(ime_datoteke.c_str(), std::ios::binary);
		tok.write(reinterpret_cast<const char*>(this), sizeof *this);
		for(int i=0; i<br_redova; i++) {
			for(int j=0; j<br_kolona; j++) {
				tok.write(reinterpret_cast<const char*>(&elementi[i][j]), sizeof (TipEl));
			}
		}
		if(!tok) throw std::logic_error("Problemi pri upisu u datoteku");
	}
//obnova
	void ObnoviIzTekstualneDatoteke(std::string ime_datoteke) {
		std::ifstream tok(ime_datoteke.c_str());
		if(!tok) throw std::logic_error("Trazena datoteka ne postoji\n");

		//iscitavanje broja kolona i redova u datoteci
		TipEl broj;
		char znak;
		int p(0), q(0);
		bool pocetak(true);
		while(tok>>broj) {
			znak = tok.get();
			q++;
			if(znak == '\n') {
				p++;
				if(pocetak) {
					pocetak = false;
					br_kolona = q;
				} else if(br_kolona != q) {
					br_kolona = 0;
					throw std::logic_error("Datoteka sadrzi besmislene podatke");
				} else {
					q = 0;
				}
			} else if(znak == ',') {

			} else break;
		}
		if(tok.eof()) {
			if(br_redova != 0 || br_kolona != 0) {
				DealocirajMemoriju(elementi, br_redova);
				elementi = nullptr;
				br_kolona = 0;
				br_redova = 0;
			}
			br_redova = p;
			elementi = AlocirajMemoriju(br_redova, br_kolona);

			tok.close();
			tok.open(ime_datoteke.c_str(), std::ios::in);
			char znak;
			for(int i=0; i<br_redova; i++) {
				for(int j=0; j<br_kolona; j++) {
					tok>>elementi[i][j];
					if(j != br_kolona-1) tok>>znak;
				}
			}
		} else if(tok.bad()) {
			throw std::logic_error("Datoteka sadrzi besmislene podatke\n");
		} else if(tok.good()) {
			throw std::logic_error("Datoteka sadrzi besmislene podatke\n");
		}

	}

	void ObnoviIzBinarneDatoteke(std::string ime_datoteke) {
		std::ifstream tok(ime_datoteke.c_str(), std::ios::binary);
		if(!tok) throw std::logic_error("Trazena datoteka ne postoji\n");
		if(br_redova != 0 || br_kolona != 0) {
			DealocirajMemoriju(elementi, br_redova);
			elementi = nullptr;
			br_kolona = 0;
			br_redova = 0;
		}
		tok.read(reinterpret_cast<char*>(this), sizeof *this);
		elementi = AlocirajMemoriju(br_redova, br_kolona);
		for(int i=0; i<br_redova; i++) {
			for(int j=0; j<br_kolona; j++) {
				tok.read(reinterpret_cast<char*>(&elementi[i][j]), sizeof(TipEl));
			}
		}
		if(!tok) {
			DealocirajMemoriju(elementi, br_redova);
			throw std::logic_error("Datoteka sadrzi besmislene podatke\n");
		}
	}

//konstruktor
	explicit Matrica(std::string ime_datoteke, bool binarna) {
		if(binarna) {
			std::ifstream tok(ime_datoteke.c_str(), std::ios::binary);
			if(!tok) throw std::logic_error("Trazena datoteka ne postoji\n");
			tok.read(reinterpret_cast<char*>(this), sizeof *this);
			elementi = AlocirajMemoriju(br_redova, br_kolona);
			for(int i=0; i<br_redova; i++) {
				for(int j=0; j<br_kolona; j++) {
					tok.read(reinterpret_cast<char*>(&elementi[i][j]), sizeof(TipEl));
				}
			}
			if(!tok) {
				DealocirajMemoriju(elementi, br_redova);
				throw std::logic_error("Datoteka sadrzi besmislene podatke\n");
			}
		} else  {
			std::ifstream tok(ime_datoteke.c_str());
			if(!tok) throw std::logic_error("Trazena datoteka ne postoji\n");

			//iscitavanje broja kolona i redova u datoteci
			TipEl broj;
			char znak;
			int p(0), q(0);
			bool pocetak(true);
			while(tok>>broj) {
				znak = tok.get();
				q++;
				if(znak == '\n') {
					p++;
					if(pocetak) {
						pocetak = false;
						br_kolona = q;
						q=0;
					} else if(br_kolona != q) {
						br_kolona = 0;
						throw std::logic_error("Datoteka sadrzi besmislene podatke\n");
					} else {
						q = 0;
					}
				} else if(znak == ',') {

				} else break;
			}
			if(tok.eof()) {
				p++;
				br_redova = p;
				elementi = AlocirajMemoriju(br_redova, br_kolona);

				tok.close();
				tok.open(ime_datoteke.c_str(), std::ios::in);
				char znak;
				for(int i=0; i<br_redova; i++) {
					for(int j=0; j<br_kolona; j++) {
						tok>>elementi[i][j];
						if(j != br_kolona-1) tok>>znak;
					}
				}
			} else if(tok.bad()) {
				throw std::logic_error("Datoteka sadrzi besmislene podatke\n");
			} else if(tok.good()) {
				throw std::logic_error("Datoteka sadrzi besmislene podatke\n");
			}
		}

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
	for(int i = 0; i < br_redova; i++) {
		delete[] elementi[i];
		elementi[i] = nullptr;
	}
	delete[] elementi;
	elementi = nullptr;
}
template <typename TipEl>
Matrica<TipEl>::Matrica(int br_redova, int br_kolona, char ime) : br_redova(br_redova), br_kolona(br_kolona), ime_matrice(ime),
	elementi(AlocirajMemoriju(br_redova, br_kolona)) {}
template <typename TipEl>
void Matrica<TipEl>::KopirajElemente(TipEl **elementi)
{
	for(int i = 0; i < br_redova; i++)
		for(int j = 0; j < br_kolona; j++)
			Matrica::elementi[i][j] = elementi[i][j];
}
template <typename TipEl>
Matrica<TipEl>::Matrica(const Matrica<TipEl> &m) : br_redova(m.br_redova), br_kolona(m.br_kolona), ime_matrice(m.ime_matrice),
	elementi(AlocirajMemoriju(m.br_redova, m.br_kolona))
{
	KopirajElemente(m.elementi);
}
template <typename TipEl>
Matrica<TipEl>::Matrica(Matrica<TipEl> &&m) : br_redova(m.br_redova),
	br_kolona(m.br_kolona), ime_matrice(m.ime_matrice), elementi(m.elementi)
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
std::istream &operator >>(std::istream &tok, Matrica<TipEl> &m)
{
	for(int i = 0; i < m.br_redova; i++)
		for(int j = 0; j < m.br_kolona; j++) {
			std::cout << m.ime_matrice << "(" << i + 1 << "," << j + 1 << ") = ";
			tok >> m.elementi[i][j];
		}
	return tok;
}
template <typename TipEl>
std::ostream &operator <<(std::ostream &tok, const Matrica<TipEl> &m)
{
	int sirina_ispisa(tok.width());
	for(int i = 0; i < m.br_redova; i++) {
		for(int j = 0; j < m.br_kolona; j++)
			tok << std::setw(sirina_ispisa) << m.elementi[i][j];
		tok << std::endl;
	}
	return tok;
}
template <typename TipEl>
Matrica<TipEl> operator +(const Matrica<TipEl> &m1,
                          const Matrica<TipEl> &m2)
{
	if(m1.br_redova != m2.br_redova || m1.br_kolona != m2.br_kolona)
		throw std::domain_error("Matrice nemaju jednake dimenzije!");
	Matrica<TipEl> m3(m1.br_redova, m1.br_kolona);
	for(int i = 0; i < m1.br_redova; i++)
		for(int j = 0; j < m1.br_kolona; j++)
			m3.elementi[i][j] = m1.elementi[i][j] + m2.elementi[i][j];
	return m3;
}

template <typename TipEl>
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
	if(m1.br_kolona != m2.br_redova) throw std::domain_error("Matrice nisu saglasne za mnozenje");
	Matrica<TipEl> m3(m1.br_redova, m1.br_kolona);
	for(int i = 0; i < m1.br_redova; i++) {
		for(int j = 0; j < m2.br_kolona; j++) {
			TipEl suma {};
			for(int k=0; k < m1.br_kolona; k++) {
				suma += m1.elementi[i][k] * m2.elementi[k][j];
			}
			m3.elementi[i][j] = suma;
		}
	}

	return m3;
}

template <typename TipEl>
Matrica<TipEl> operator *(const Matrica<TipEl> &m1, int n)
{
	Matrica<TipEl> m3(m1.br_redova, m1.br_kolona);
	for(int i = 0; i < m1.br_redova; i++) {
		for(int j = 0; j < m1.br_kolona; j++) {
			m3.elementi[i][j] = m1.elementi[i][j] * n;
		}
	}
	return m3;
}

template <typename TipEl>
inline Matrica<TipEl> operator *(int n, const Matrica<TipEl> &m1)
{
	return m1*n;
}

template <typename TipEl>
Matrica<TipEl> &operator +=(Matrica<TipEl> &m1, const Matrica<TipEl> &m2)
{
	if(m1.br_redova != m2.br_redova || m1.br_kolona != m2.br_kolona)
		throw std::domain_error("Matrice nemaju jednake dimenzije!");
	for(int i = 0; i < m1.br_redova; i++)
		for(int j = 0; j < m1.br_kolona; j++)
			m1.elementi[i][j] += m2.elementi[i][j];
	return m1;
}

template <typename TipEl>
Matrica<TipEl> &operator -=(Matrica<TipEl> &m1, const Matrica<TipEl> &m2)
{
	if(m1.br_redova != m2.br_redova || m1.br_kolona != m2.br_kolona)
		throw std::domain_error("Matrice nemaju jednake dimenzije!");
	for(int i = 0; i < m1.br_redova; i++)
		for(int j = 0; j < m1.br_kolona; j++)
			m1.elementi[i][j] -= m2.elementi[i][j];
	return m1;
}

template <typename TipEl>
Matrica<TipEl> &operator *=(Matrica<TipEl> &m1, const Matrica<TipEl> &m2)
{
	if(m1.br_kolona != m2.br_redova) throw std::domain_error("Matrice nisu saglasne za mnozenje");
	Matrica<TipEl> m3(m1.br_redova, m2.br_kolona);

	for(int i = 0; i < m1.br_redova; i++) {
		for(int j = 0; j < m2.br_kolona; j++) {
			TipEl suma {};
			for(int k=0; k < m1.br_kolona; k++) {
				suma += m1.elementi[i][k] * m2.elementi[k][j];
			}
			m3.elementi[i][j] = suma;
		}
	}
	m1 = m3;
	return m1;
}

template <typename TipEl>
Matrica<TipEl> &operator *=(Matrica<TipEl> &m1, int n)
{
	for(int i = 0; i < m1.br_redova; i++) {
		for(int j = 0; j < m1.br_kolona; j++) {
			m1.elementi[i][j] *= n;
		}
	}
	return m1;
}

template <typename TipEl>
inline Matrica<TipEl> &operator *=(int n, Matrica<TipEl> &m1)
{
	return m1*n;
}

template<typename TipEl>
Matrica<TipEl>::operator std::string () const
{
	std::string s;
	s.push_back('{');
	for(int i=0; i<br_redova; i++) {
		if(i!=0) s.push_back(',');
		s.push_back('{');
		for(int j=0; j<br_kolona; j++) {
			if(j!=0) s.push_back(',');
			
			s += (std::to_string(int(elementi[i][j])));
			
		}
		s.push_back('}');
	}
	s.push_back('}');
	return s;
}



int main()
{
	
	return 0;
}
