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
	template <typename Tip2>
	friend std::istream &operator >> (std::istream &ulazni_tok, const Matrica<Tip2> &m);
	template <typename Tip2>
	friend std::ostream &operator << (std::ostream &izlazni_tok, const Matrica<Tip2> &m);

	Matrica operator +(const Matrica &m1) const;
	Matrica operator -(const Matrica &m1) const;
	Matrica operator *(const Matrica &m1) const;
	Matrica operator *(int n) const;
	template <typename Tip2>
	friend Matrica<Tip2> operator *(int n, const Matrica<Tip2> &m);
	Matrica& operator +=(const Matrica &m1);
	Matrica& operator -=(const Matrica &m1);
	Matrica& operator *=(const Matrica &m1);
	Matrica& operator *=(int n);
	TipEl& operator ()(int i, int j) const;
	TipEl* operator [](int i) const;
	operator std::string() const;

	//Nove metode
	void SacuvajUTekstualnuDatoteku(std::string ime_datoteke) const;
	void SacuvajUBinarnuDatoteku(std::string ime_datoteke) const;
	void ObnoviIzTekstualneDatoteke(std::string ime_datoteke);
	void ObnoviIzBinarneDatoteke(std::string ime_datoteke);
	Matrica(std::string ime_datoteke, bool je_binarna);

};

//Implementacija interfejsa
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


//Dodani operatori
template <typename TipEl>
std::istream& operator >> (std::istream &ulazni_tok, const Matrica<TipEl> &m)
{
	for(int i = 0; i < m.br_redova; i++)
		for(int j = 0; j < m.br_kolona; j++) {
			std::cout << m.ime_matrice << "(" << i + 1 << "," << j + 1 << ") = ";
			ulazni_tok >> m.elementi[i][j];
		}
	return ulazni_tok;
}

template <typename TipEl>
std::ostream &operator << (std::ostream &izlazni_tok, const Matrica<TipEl> &m)
{
	int w(izlazni_tok.width());
	for(int i = 0; i < m.br_redova; i++) {
		for(int j = 0; j < m.br_kolona; j++)
			izlazni_tok << std::setw(w) << m.elementi[i][j];
		izlazni_tok << std::endl;
	}
	return izlazni_tok;
}

template <typename TipEl>
Matrica<TipEl> Matrica<TipEl>::operator +(const Matrica<TipEl> &m1) const
{
	if(m1.br_redova != br_redova || m1.br_kolona != br_kolona)
		throw std::domain_error("Matrice nemaju jednake dimenzije!");
	Matrica<TipEl> m3(m1.br_redova, m1.br_kolona);
	for(int i = 0; i < m1.br_redova; i++)
		for(int j = 0; j < m1.br_kolona; j++)
			m3.elementi[i][j] = m1.elementi[i][j] + elementi[i][j];
	return m3;
}

template <typename TipEl>
Matrica<TipEl> Matrica<TipEl>::operator -(const Matrica<TipEl> &m1) const
{
	if(m1.br_redova != br_redova || m1.br_kolona != br_kolona)
		throw std::domain_error("Matrice nemaju jednake dimenzije!");
	Matrica<TipEl> m3(m1.br_redova, m1.br_kolona);
	for(int i = 0; i < m1.br_redova; i++)
		for(int j = 0; j < m1.br_kolona; j++)
			m3.elementi[i][j] = elementi[i][j] - m1.elementi[i][j];
	return m3;
}

template <typename TipEl>
Matrica<TipEl> Matrica<TipEl>::operator *(const Matrica<TipEl> &m1) const
{
	if(br_kolona != m1.br_redova)
		throw std::domain_error ("Matrice nisu saglasne za mnozenje");
	Matrica<TipEl> m2(br_redova, m1.br_kolona);
	for(int i=0; i<br_redova; i++) {
		for(int j=0; j<m1.br_kolona; j++) {
			TipEl suma {};
			for(int k=0; k<m1.br_redova; k++) {
				suma += elementi[i][k]*m1.elementi[k][j];
			}
			m2.elementi[i][j] = suma;
		}
	}
	return m2;
}

template <typename TipEl>
Matrica<TipEl> Matrica<TipEl>::operator *(int n) const
{
	Matrica<TipEl> m2(br_redova, br_kolona);
	for(int i=0; i<br_redova; i++) {
		for(int j=0; j<br_kolona; j++) {
			m2.elementi[i][j] = elementi[i][j] * n;
		}
	}
	return m2;
}

template <typename TipEl>
Matrica<TipEl> operator *(int n, const Matrica<TipEl> &m)
{
	Matrica<TipEl> m2(m.br_redova, m.br_kolona);
	m2 = m*n;
	return m2;
}

template <typename TipEl>
Matrica<TipEl>& Matrica<TipEl>::operator +=(const Matrica<TipEl> &m1)
{
	if(m1.br_redova != br_redova || m1.br_kolona != br_kolona)
		throw std::domain_error("Matrice nemaju jednake dimenzije!");
	for(int i=0; i<br_redova; i++) {
		for(int j=0; j<br_kolona; j++) {
			elementi[i][j] += m1.elementi[i][j];
		}
	}
	return *this;
}

template <typename TipEl>
Matrica<TipEl>& Matrica<TipEl>::operator -=(const Matrica<TipEl> &m1)
{
	if(m1.br_redova != br_redova || m1.br_kolona != br_kolona)
		throw std::domain_error("Matrice nemaju jednake dimenzije!");
	for(int i=0; i<br_redova; i++) {
		for(int j=0; j<br_kolona; j++) {
			elementi[i][j] -= m1.elementi[i][j];
		}
	}
	return *this;
}

template <typename TipEl>
Matrica<TipEl>& Matrica<TipEl>::operator *=(const Matrica<TipEl> &m1)
{
	if(br_kolona != m1.br_redova)
		throw std::domain_error ("Matrice nisu saglasne za mnozenje");
	Matrica<TipEl> m2(br_redova, m1.br_kolona);
	for(int i=0; i<br_redova; i++) {
		for(int j=0; j<m1.br_kolona; j++) {
			TipEl suma {};
			for(int k=0; k<m1.br_redova; k++) {
				suma += elementi[i][k]*m1.elementi[k][j];
			}
			m2.elementi[i][j] = suma;
		}
	}
	*this = m2;
	return *this;
}

template <typename TipEl>
Matrica<TipEl>& Matrica<TipEl>::operator *=(int n)
{
	for(int i=0; i<br_redova; i++) {
		for(int j=0; j<br_kolona; j++)
			elementi[i][j] *= n;
	}
	return *this;
}

template <typename TipEl>
TipEl& Matrica<TipEl>::operator ()(int i, int j) const
{
	if(i<1 || i>br_redova || j<1 || j>br_kolona)
		throw std::range_error ("Neispravan indeks");
	return elementi[i-1][j-1];
}
template <typename TipEl>
TipEl* Matrica<TipEl>::operator [](int i) const
{
	return elementi[i];
}

template <typename TipEl>
Matrica<TipEl>::operator std::string() const
{
	std::string pretvoreni_string("{");
	for(int i=0; i<br_redova; i++) {
		pretvoreni_string+="{";
		for(int j=0; j<br_kolona; j++) {
			std::string tmp;
			tmp = std::to_string(elementi[i][j]);
			//odsjecanje nula
			int posljednja_nenulta(-1);
			for(int i=0; i<tmp.size(); i++)
				if(tmp[i] != '0')
					posljednja_nenulta = i;
			tmp = tmp.substr(0,posljednja_nenulta+1);
			if(*tmp.rbegin()=='.')
				tmp = tmp.substr(0,tmp.length()-1);
			//...
			pretvoreni_string += tmp;
			if(j!=br_kolona-1) pretvoreni_string+=",";
		}
		pretvoreni_string+= "}";
		if(i!=br_redova-1) pretvoreni_string += ",";
	}
	pretvoreni_string+="}";
	return pretvoreni_string;
}

template <typename TipEl>
void Matrica<TipEl>::SacuvajUTekstualnuDatoteku(std::string ime_datoteke) const
{
	std::ofstream tok(ime_datoteke);
	for(int i=0; i<br_redova; i++) {
		for(int j=0; j<br_kolona; j++) {
			tok << elementi[i][j];
			if(!tok)
				throw std::logic_error ("Problemi sa upisom u datoteku");
			if(j != br_kolona-1)
				tok << ",";
			if(!tok)
				throw std::logic_error ("Problemi sa upisom u datoteku");
		}
		tok<<std::endl;
		if(!tok)
			throw std::logic_error ("Problemi sa upisom u datoteku");
	}
}

template <typename TipEl>
void Matrica<TipEl>::SacuvajUBinarnuDatoteku(std::string ime_datoteke) const
{
	std::ofstream tok(ime_datoteke, std::ios::binary);
	tok.write(reinterpret_cast<const char*>(this), sizeof *this);
	if(!tok)
		throw std::logic_error ("Problemi sa upisom u datoteku");
	for(int i=0; i<br_redova; i++) {
		tok.write(reinterpret_cast<char*>(elementi[i]), br_kolona*sizeof (TipEl));
		if(!tok)
			throw std::logic_error ("Problemi sa upisom u datoteku");
	}

}

template <typename TipEl>
void Matrica<TipEl>::ObnoviIzTekstualneDatoteke(std::string ime_datoteke)
{
	std::ifstream tok(ime_datoteke);
	if(!tok)
		throw std::logic_error ("Trazena datoteka ne postoji");
	TipEl tmp;
	char zarez;
	int br_kolona_tmp = 0;
	int br_redova_tmp = 0;
	int tmp_br_kolona(0);
	while (tok >> tmp) {
		if(tok.peek() == '\n') {
			br_redova_tmp++;
			if(br_kolona_tmp != 0 && tmp_br_kolona != br_kolona_tmp)
				throw std::logic_error ("Datoteka sadrzi besmislene podatke");
			br_kolona_tmp = tmp_br_kolona;
			tmp_br_kolona = 0;
			continue;
		}
		tok >> zarez;
		if(zarez != ',')
			throw std::logic_error ("Datoteka sadrzi besmislene podatke");
		tmp_br_kolona++;
	}
	if(!tok.eof() && !tok)
		throw std::logic_error ("Datoteka sadrzi besmislene podatke");

	tok.close();
	for(int i=0; i<br_redova; i++)
		delete elementi[i];
	delete[] elementi;
	br_kolona = br_kolona_tmp+1;
	br_redova=br_redova_tmp+1;
	elementi = new TipEl*[br_redova] {};
	for(int i=0; i<br_redova; i++) elementi[i] = new TipEl[br_kolona] {};
	tok.open(ime_datoteke);
	for(int i = 0; i<br_redova; i++) {
		for(int j=0; j<br_kolona; j++) {
			TipEl broj;
			tok >> broj;
			elementi[i][j] = broj;
			if(j != br_kolona-1)
				tok >> zarez;
		}
	}

}

template <typename TipEl>
Matrica<TipEl>::Matrica(std::string ime_datoteke, bool je_binarna)
{
	if(je_binarna) {
		std::ifstream tok(ime_datoteke, std::ios::binary);
		if(!tok)
			throw std::logic_error ("Trazena datoteka ne postoji");
		tok.read(reinterpret_cast<char*>(this), sizeof *this);
		elementi = new TipEl*[br_redova] {};
		for(int i=0; i<br_redova; i++)
			elementi[i] = new TipEl[br_kolona];
		for(int i=0; i<br_kolona; i++)
			tok.read(reinterpret_cast<char*>(elementi[i]), br_kolona*sizeof (TipEl));
		if(!tok)
			throw std::logic_error ("Problemi pri citanju datoteke");
	} else {
		std::ifstream tok(ime_datoteke);
		if(!tok)
			throw std::logic_error ("Trazena datoteka ne postoji");
		TipEl tmp;
		char zarez;
		br_kolona = 0;
		br_redova = 0;
		int tmp_br_kolona(0);
		while (tok >> tmp) {
			if(tok.peek() == '\n') {
				br_redova++;
				if(br_kolona != 0 && tmp_br_kolona != br_kolona)
					throw std::logic_error ("Datoteka sadrzi besmislene podatke");
				br_kolona = tmp_br_kolona;
				tmp_br_kolona = 0;
				continue;
			}
			tok >> zarez;
			if(zarez != ',')
				throw std::logic_error ("Datoteka sadrzi besmislene podatke");
			tmp_br_kolona++;
		}
		if(!tok.eof() && !tok)
			throw std::logic_error ("Datoteka sadrzi besmislene podatke");

		tok.close();
		br_redova++;
		br_kolona++;
		elementi = new TipEl*[br_redova] {};
		for(int i=0; i<br_redova; i++) elementi[i] = new TipEl[br_kolona] {};
		tok.open(ime_datoteke);
		for(int i = 0; i<br_redova; i++) {
			for(int j=0; j<br_kolona; j++) {
				TipEl broj;
				tok >> broj;
				elementi[i][j] = broj;
				if(j != br_kolona-1)
					tok >> zarez;
			}
		}
	}
}

template <typename TipEl>
void Matrica<TipEl>::ObnoviIzBinarneDatoteke(std::string ime_datoteke)
{
	std::ifstream tok(ime_datoteke, std::ios::binary);
	if(!tok)
		throw std::logic_error ("Trazena datoteka ne postoji");
	Matrica pomocna(*this);

	for(int i=0; i<br_redova; i++)
		delete elementi[i];
	delete[] elementi;

	tok.read(reinterpret_cast<char*>(this), sizeof *this);
	elementi = new TipEl*[br_redova] {};
	for(int i=0; i<br_redova; i++)
		elementi[i] = new TipEl[br_kolona];
	for(int i=0; i<br_redova; i++)
		tok.read(reinterpret_cast<char*>(elementi[i]), br_kolona*sizeof (TipEl));
	if(!tok) {
		*this = std::move(pomocna);
		throw std::logic_error ("Problemi pri citanju datoteke");
	}

}

int main()
{
	std::string ime = "matrica.txt";
	std::ofstream dat(ime);
	dat << "1, 2\n3, 4\n5, 6\n7, 8";
	dat.close();
	Matrica<int> m1("matrica.txt", false);
	std::cout << std::setw(6) << m1;
	std::string ime1 = "matrica1.txt";
	std::ofstream datt(ime1);
	datt << "1, 2\n3, 5\n5, 6\n7, 8";
	datt.close();
	m1.ObnoviIzTekstualneDatoteke("matrica1.txt");
	std::cout << std::setw(6) << m1;
	return 0;
}
