#include <iostream>
#include <iomanip>
#include <cstring>
#include <stdexcept>
#include <new>
#include <string>
#include <fstream>

// PAZITI NA TEMPLATEOVE

template <typename TipEl>
class Matrica
{
	int br_redova, br_kolona;
	TipEl **elementi;
	char ime_matrice;
	static TipEl **AlocirajMemoriju(int br_redova, int br_kolona);
	static void DealocirajMemoriju(TipEl **elementi, int br_redova);
	void KopirajElemente(TipEl **elementi);
	void TestIndeksa(int i, int j) const {
		if(i<0 || i>br_redova || j<0 || j>br_kolona) throw std::range_error("Neispravan indeks");
	}
public:
	Matrica(int br_redova, int br_kolona, char ime = 0);
	Matrica(const Matrica &m);
	Matrica(Matrica &&m);
	~Matrica() {
		DealocirajMemoriju(elementi, br_redova);
	} Matrica &operator =(const Matrica &m);
	Matrica &operator =(Matrica &&m);
	template <typename TipE1>
	friend std::istream &operator >>(std::istream &tok, Matrica<TipE1> &m);
	template <typename TipE1>
	friend std::ostream &operator <<(std::ostream &tok, const Matrica<TipE1> &m);
	template <typename Tip2>
	friend Matrica<Tip2> operator +(const Matrica<Tip2> &m1, const Matrica<Tip2> &m2);
	TipEl* &operator [](int i) {
		return elementi[i];
	}
	TipEl* operator [](int i) const {
		return elementi[i];
	}
	TipEl &operator()(int i, int j) {
		TestIndeksa(i-1, j-1);
		return elementi[i-1][j-1];
	}
	TipEl operator()(int i, int j) const {
		TestIndeksa(i-1, j-1);
		return elementi[i-1][j-1];
	}
	operator std::string() const;
	template <typename TipNum>
	friend Matrica<TipNum> operator *(const Matrica<TipNum> &m1, const Matrica<TipNum> &m2);
	template <typename TipNum2>
	friend Matrica<TipNum2> operator *(const Matrica<TipNum2> &m, double x);
	template <typename TipNum3>
	friend Matrica<TipNum3> operator *(double x, const Matrica<TipNum3> &m);
	template <typename TipEl5>
	friend Matrica<TipEl5> operator -(const Matrica<TipEl5> &m1, const Matrica<TipEl5> &m2);
	template <typename TipEl0>
	Matrica<TipEl0> &operator +=(const Matrica<TipEl0> &m) {
		if(br_kolona!=m.br_kolona || br_redova!=m.br_redova) throw std::domain_error("Matrice nemaju jednake dimenzije!");
		for(int i=0; i<br_redova; i++)
			for(int j=0; j<br_kolona; j++)
				elementi[i][j]+=m.elementi[i][j];
		return *this;
	}
	template <typename Tip1>
	Matrica<Tip1> &operator -=(const Matrica<Tip1> &m) {
		if(br_kolona!=m.br_kolona || br_redova!=m.br_redova) throw std::domain_error("Matrice nemaju jednake dimenzije!");
		for(int i=0; i<br_redova; i++)
			for(int j=0; j<br_kolona; j++)
				elementi[i][j]-=m.elementi[i][j];
		return *this;
	}
	template <typename Tip0>
	Matrica<Tip0> &operator *=(const Matrica<Tip0> &m) {
		return *this=(*this)*m;
	}
	Matrica<TipEl> &operator *=(double m) {
		return *this=(*this)*m;
	}
	// novi dio zadatka, zbog templateova cemo ga ovdje implementirati
	void SacuvajUTekstualnuDatoteku(const std::string &ime_datoteke) {
		// otvaranje datoteke
		std::ofstream izlaz(ime_datoteke);
		if(!izlaz) throw std::logic_error("Problemi sa upisom u datoteku");
		for(int i=0; i<br_redova; i++) {
			for(int j=0; j<br_kolona; j++) {
				if(j==br_kolona-1) izlaz<<elementi[i][j];
				else izlaz<<elementi[i][j]<<",";
			}
			izlaz<<std::endl;
		}
	}
	void SacuvajUBinarnuDatoteku(const std::string &ime_datoteke) {
		// otvaranje datoteke
		std::ofstream tok(ime_datoteke, std::ios::binary);
		if(!tok) throw std::logic_error("Problemi sa upisom u datoteku");
		// upisivanje broja redova i broja kolona
		tok.write(reinterpret_cast<char*>(&br_redova), sizeof br_redova);
		tok.write(reinterpret_cast<char*>(&br_kolona), sizeof br_kolona);
		// upisivanje elemenata
		for(int i=0; i<br_redova; i++) tok.write(reinterpret_cast<char*>(elementi[i]), sizeof elementi[i]); // istresamo cijeli red
	}
	void ObnoviIzBinarneDatoteke(const std::string &ime_datoteke) {
		std::ifstream tok(ime_datoteke, std::ios::binary);
		if(!tok) throw std::logic_error("Trazena datoteka ne postoji");
		// dealokacija postojecih elemenata
		this->DealocirajMemoriju(elementi, br_redova); // ljepse je pisati this->, estetika
		// overwrite br_redova i br_kolona
		tok.read(reinterpret_cast<char*>(&br_redova), sizeof br_redova);
		tok.read(reinterpret_cast<char*>(&br_kolona), sizeof br_kolona);
		// citanje elemenata, kursor je vec pomjeren
		// provjera je li tok u neispravnom stanju
		if(!tok) throw std::logic_error("Problemi pri citanju datoteke");
		// alociramo memoriju
		this->AlocirajMemoriju(br_redova, br_kolona);
		// upisujemo u memoriju, provjera je li stvarno postoji br_redova i br_kolona
		for(int i=0; i<br_redova; i++) {
			if(!tok) throw std::logic_error("Problemi pri citanju datoteke"); // mogla je i while petlja
			// alocirana memorija - mozemo ucitati citav red
			tok.read(reinterpret_cast<char*>(elementi[i]), sizeof elementi[i]);
		}
	}
	void ObnoviIzTekstualneDatoteke(const std::string &ime_datoteke) {
		std::ifstream tok(ime_datoteke);
		if(!tok) throw std::logic_error("Trazena datoteka ne postoji");
		// dealokacija postojecih elemenata
		this->DealocirajMemoriju(elementi, br_redova);
		// citanje br redova i kolona
		int kolone1(0), kolone2(0), redovi(0);
		while(!tok) {
			char znak(' ');
			kolone1=0;
			kolone2=0;
			// citajmo po znakovima prvi red
			while(znak!='\n' && znak!=EOF) { // EOF c-ovski, ali radi
				kolone1++;
			}
			znak=' ';// samo da nije \n, da je eof, prekinula bi se cijela petlja
			// citajmo po znakovima drugi red
			while(znak!='\n' && znak!=EOF) {
				kolone2++;
			}
			if(kolone1!=kolone2) {
				throw std::logic_error("Datoteka sadrzi besmislene podatke");
				break;
			}
			redovi++;
		}
		br_redova=redovi;
		br_kolona=kolone1; // ako je uredno zavrsila petlja, kolone1=kolone2
		//alociranje memorije
		this->AlocirajMemoriju(redovi, kolone1);
		// citanje, paziti na -, vratiti kursor na pocetak, vjerovatno cita decimalnu tacku kao dio broja
		tok.seekg(0, std::ios::beg);
		char znak;
		for(int i=0; i<br_redova; i++) {
			for(int j=0; j<br_kolona; j++) {
				if(tok.peek()=='-') {
					tok>>znak>>elementi[i][j]>>znak;
					elementi[i][j]*=(-1);
				} else {
					tok>>elementi[i][j]>>znak;
				}
				if(znak!=',' || znak!='\n') throw std::logic_error("Datoteka sadrzi besmislene podatke");
			}
		}
	}
	Matrica(const std::string &ime_datoteke, bool dat) {
		if(dat) {
			std::ifstream tok(ime_datoteke, std::ios::binary);
			if(!tok) throw std::logic_error("Trazena datoteka ne postoji");
			// overwrite br_redova i br_kolona
			tok.read(reinterpret_cast<char*>(&br_redova), sizeof br_redova);
			tok.read(reinterpret_cast<char*>(&br_kolona), sizeof br_kolona);
			// citanje elemenata, kursor je vec pomjeren
			// provjera je li tok u neispravnom stanju
			if(!tok) throw std::logic_error("Problemi pri citanju datoteke");
			// alociramo memoriju
			this->AlocirajMemoriju(br_redova, br_kolona);
			// upisujemo u memoriju, provjera je li stvarno postoji br_redova i br_kolona
			for(int i=0; i<br_redova; i++) {
				if(!tok) throw std::logic_error("Problemi pri citanju datoteke"); // mogla je i while petlja
				// alocirana memorija - mozemo ucitati citav red
				tok.read(reinterpret_cast<char*>(elementi[i]), sizeof elementi[i]);
			}
		} else {
			std::ifstream tok(ime_datoteke);
			if(!tok) throw std::logic_error("Trazena datoteka ne postoji");
			// citanje br redova i kolona
			int kolone1(0), kolone2(0), redovi(0);
			while(!tok) {
				char znak(' ');
				kolone1=0;
				kolone2=0;
				// citajmo po znakovima prvi red
				while(znak!='\n' && znak!=EOF) { // EOF c-ovski, ali radi
					kolone1++;
				}
				znak=' ';// samo da nije \n, da je eof, prekinula bi se cijela petlja
				// citajmo po znakovima drugi red
				while(znak!='\n' && znak!=EOF) {
					kolone2++;
				}
				if(kolone1!=kolone2) {
					throw std::logic_error("Datoteka sadrzi besmislene podatke");
					break;
				}
				redovi++;
			}
			br_redova=redovi;
			br_kolona=kolone1; // ako je uredno zavrsila petlja, kolone1=kolone2
			//alociranje memorije
			this->AlocirajMemoriju(redovi, kolone1);
			// citanje, paziti na -, vratiti kursor na pocetak, vjerovatno cita decimalnu tacku kao dio broja
			tok.seekg(0, std::ios::beg);
			char znak;
			for(int i=0; i<br_redova; i++) {
				for(int j=0; j<br_kolona; j++) {
					if(tok.peek()=='-') {
						tok>>znak>>elementi[i][j]>>znak;
						elementi[i][j]*=(-1);
					} else {
						tok>>elementi[i][j]>>znak;
					}
					if(znak!=',' || znak!='\n') throw std::logic_error("Datoteka sadrzi besmislene podatke");
				}
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
	for(int i = 0; i < br_redova; i++) delete[] elementi[i];
	delete[] elementi;
}

template <typename TipEl>
Matrica<TipEl>::Matrica(int br_redova, int br_kolona, char ime) : br_redova(br_redova), br_kolona(br_kolona), ime_matrice(ime), elementi(AlocirajMemoriju(br_redova, br_kolona)) {}

template <typename TipEl>
void Matrica<TipEl>::KopirajElemente(TipEl **elementi)
{
	for(int i = 0; i < br_redova; i++)

		for(int j = 0; j < br_kolona; j++) Matrica::elementi[i][j] = elementi[i][j];
}

template <typename TipEl>
Matrica<TipEl>::Matrica(const Matrica<TipEl> &m) : br_redova(m.br_redova), br_kolona(m.br_kolona), ime_matrice(m.ime_matrice), elementi(AlocirajMemoriju(m.br_redova, m.br_kolona))
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
		for(int j = 0; j < m.br_kolona; j++) {
			tok << std::setw(sirina_ispisa) << m.elementi[i][j];
		}
		tok << std::endl;
	}
	return tok;
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
}

template <typename TipEl>
Matrica<TipEl>::operator std::string() const { 
	std::string s("{");
	for(int i=0; i<br_redova; i++) {
		s+="{";
		for(int j=0; j<br_kolona; j++) {
			s+=std::to_string(int(elementi[i][j]));
			if(j!=br_kolona-1) s+=",";
		}
		if(i!=br_redova-1) s+="},";
		else s+="}";
	}
	s+="}";
	return s;
}

template <typename TipNum>
Matrica<TipNum> operator *(const Matrica<TipNum> &m1, const Matrica<TipNum> &m2) {
	if(m1.br_kolona!=m2.br_redova) throw std::domain_error("Matrice nisu saglasne za mnozenje");
	Matrica<TipNum> m(m1.br_redova, m2.br_kolona);
	// inicijalizacija na 0 elemenata od m
	for(int i=0; i<m.br_redova; i++) 
		for(int j=0; j<m.br_kolona; j++)
			m[i][j]=0;
	// mnozenje
	for(int i=0; i<m1.br_redova; i++) {
		for(int j=0; j<m2.br_kolona; j++) {
			for(int k=0; k<m1.br_kolona; k++) {
				m.elementi[i][j]+=m1.elementi[i][k]*m2.elementi[k][j];
			}
		}
	}
	return m;
}

template <typename TipNum2>
Matrica<TipNum2> operator *(const Matrica<TipNum2> &m, double x) {
	Matrica<TipNum2> pov(m);
	for(int i=0; i<m.br_redova; i++) 
		for(int j=0; j<m.br_kolona; j++)
			pov.elementi[i][j]*=x;
	return pov;
}

template <typename TipNum3>
Matrica<TipNum3> operator *(double x, const Matrica<TipNum3> &m) {
	return m*x;
}

template <typename TipEl5>
Matrica<TipEl5> operator -(const Matrica<TipEl5> &m1, const Matrica<TipEl5> &m2) {
	if(m1.br_kolona!=m2.br_kolona || m1.br_redova!=m2.br_redova) throw std::domain_error("Matrice nemaju jednake dimenzije!");
	Matrica<TipEl5> m(m1.br_redova, m1.br_kolona);
	for(int i=0; i<m1.br_redova; i++) 
		for(int j=0; j<m1.br_kolona; j++) 
			m.elementi[i][j]=m1.elementi[i][j]-m2.elementi[i][j];
	return m;
}


int main ()
{
	int m(2), n(2);
	Matrica<double> a(m, n, 'A'), b(m, n, 'B');
	std::cout << "Unesi matricu A:\n";
	std::cin >> a;
	std::cout << "Unesi matricu B:\n";
	std::cin >> b;
	std::cout << "Zbir ove dvije matrice je:\n";
	std::cout << std::setw(7) << a+b;
	return 0;
}