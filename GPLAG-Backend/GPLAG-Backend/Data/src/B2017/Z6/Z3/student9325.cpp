/B2017/2018: Zadaća 6, Zadatak 3
#include <iostream>
#include <iomanip>
#include <cstring>
#include <stdexcept>
#include <new>
#include <string>
#include <fstream>
#include <cstdio>
#include <cctype>
#include <vector>

template <typename TipEl>
	class Matrica {
		int br_redova, br_kolona;
		TipEl** elementi;
		char ime_matrice;
		static TipEl** AlocirajMemoriju(int br_redova, int br_kolona);
		static void DealocirajMemoriju(TipEl** elementi, int br_redova);
		void KopirajElemente(TipEl** elementi);
		void TestIndeksa(int indeks, int maksimum) const {
			if (indeks<1 || indeks>maksimum) {
				throw std::range_error("Neispravan indeks");
			}
		}
	public:
	    Matrica(const char ime_datoteke[], bool binarna);
		Matrica(int br_redova, int br_kolona, char ime=0);
		Matrica(const Matrica &m);
		Matrica(Matrica &&m);
		~Matrica() {
			DealocirajMemoriju(elementi, br_redova);
		}
		Matrica &operator =(const Matrica &m);
		Matrica &operator =(Matrica &&m);
		template <typename Tip>
			friend Matrica<Tip> &operator *=(Matrica<Tip> &m1, double broj);
		template <typename Tip>
			friend Matrica<Tip> operator *(const Matrica<Tip> &m1, double broj);
		template <typename Tip>
			friend Matrica<Tip> operator *(double broj, const Matrica<Tip> &m2);
		template <typename Tip>
			friend Matrica<Tip> &operator *=(Matrica<Tip> &m1, const Matrica<Tip> &m2);
		template <typename Tip>
			friend Matrica<Tip> operator *(const Matrica<Tip> &m1, const Matrica<Tip> &m2);
		template <typename Tip>
			friend 	Matrica<Tip> &operator +=(Matrica<Tip> &m1, const Matrica<Tip> &m2);
		template <typename Tip>
			friend Matrica<Tip> operator +(const Matrica<Tip> &m1, const Matrica<Tip> &m2);
		template <typename Tip>
			friend Matrica<Tip> &operator -=(Matrica<Tip> &m1, const Matrica<Tip> &m2);
		template <typename Tip>
			friend Matrica<Tip> operator -(const Matrica<Tip> &m1, const Matrica<Tip> &m2);
		template <typename Tip>
			friend std::istream &operator >>(std::istream &tok, Matrica<Tip> &m);
		template <typename Tip>
			friend std::ostream &operator <<(std::ostream &tok, const Matrica<Tip> &m);
		operator std::string() const;
		TipEl* operator [](int x) const {
			return elementi[x];
		}
		TipEl* &operator [](int x) {
			return elementi[x];
		}
		TipEl operator ()(int x, int y) const {
			TestIndeksa(x, br_redova);
			TestIndeksa(y, br_kolona);
			return elementi[x-1][y-1];
		}
		TipEl &operator ()(int x, int y) {
			TestIndeksa(x, br_redova);
			TestIndeksa(y, br_kolona);
			return elementi[x-1][y-1];
		}
		void SacuvajUTekstualnuDatoteku(const char ime_datoteke[]) const;
		void SacuvajUBinarnuDatoteku(const char ime_datoteke[]) const;
		void ObnoviIzTekstualneDatoteke(const char ime_datoteke[]);
		void ObnoviIzBinarneDatoteke(const char ime_datoteke[]);
	};
	
template <typename Tip>
    Matrica<Tip>::Matrica(const char ime_datoteke[], bool binarna) {
        if (binarna) {
            std::ifstream ulazni_tok(ime_datoteke, std::ios::binary);
            if (!ulazni_tok) throw std::logic_error("Trazena datoteka ne postoji");
            ulazni_tok.read(reinterpret_cast<char*>(this), sizeof *this);
            elementi=AlocirajMemoriju(br_redova, br_kolona);
            for (int i=0; i<br_redova; i++) {
            	ulazni_tok.read(reinterpret_cast<char*>(elementi[i]), br_kolona*sizeof(Tip));
            }
            if (!ulazni_tok) {
            	DealocirajMemoriju(elementi, br_redova);
            	throw std::logic_error("Problemi pri citanju datoteke");
            }
        }
        else {
            std::ifstream ulazni_tok(ime_datoteke);
        	if (!ulazni_tok) throw std::logic_error("Trazena datoteka ne postoji");
        	std::vector<std::vector<Tip>> vektor;
        	std::vector<Tip> vektor_reda;
        	while (1) {
        		if (ulazni_tok.peek()==EOF) break;
        		Tip element;
        		ulazni_tok >> element;
        		if (!ulazni_tok) throw std::logic_error("Datoteka sadrzi besmislene podatke");
        		if (ulazni_tok.peek()!=',' && ulazni_tok.peek()!='\n' && ulazni_tok.peek()!=EOF)
        			throw std::logic_error("Datoteka sadrzi besmislene podatke");
        		vektor_reda.push_back(element);
        		if (ulazni_tok.peek()==EOF) {
        			vektor.push_back(vektor_reda);
        			if (vektor_reda.size()!=vektor.at(0).size())
        				throw std::logic_error("Datoteka sadrzi besmislene podatke");
        			break;
        		}
        		else if (ulazni_tok.peek()=='\n') {
        			vektor.push_back(vektor_reda);
        			if (vektor_reda.size()!=vektor.at(0).size())
        				throw std::logic_error("Datoteka sadrzi besmislene podatke");
        			vektor_reda.resize(0);
        		}
        		ulazni_tok.get();
        		if (ulazni_tok.peek()==',')
        			throw std::logic_error("Datoteka sadrzi besmislene podatke");
        	}
        	br_redova=vektor.size();
        	br_kolona=vektor.at(0).size();
        	elementi=AlocirajMemoriju(br_redova, br_kolona);
        	ulazni_tok.close();
        	ulazni_tok.open(ime_datoteke);
        	int i(0), j(0);
        	while (1) {
        		if (ulazni_tok.peek()==EOF) break;
        		Tip element;
        		ulazni_tok >> element;
        		elementi[i][j++]=element;
        		if (ulazni_tok.peek()==EOF) break;
        		else if (ulazni_tok.peek()=='\n') {
        			i++; j=0;
        		}
        		ulazni_tok.get();
        	}
        }
    }
	
template <typename Tip>
    void Matrica<Tip>::SacuvajUTekstualnuDatoteku(const char ime_datoteke[]) const {
        std::ofstream izlazni_tok(ime_datoteke);
        if (!izlazni_tok) throw std::logic_error("Problemi sa upisom u datoteku");
        for (int i=0; i<br_redova-1; i++) {
        	for (int j=0; j<br_kolona-1; j++) {
        		izlazni_tok << elementi[i][j] << ",";
        		if (!izlazni_tok) throw std::logic_error("Problemi sa upisom u datoteku");
        	}
        	izlazni_tok << elementi[i][br_kolona-1] << std::endl;
        	if (!izlazni_tok) throw std::logic_error("Problemi sa upisom u datoteku");
        }
        for (int j=0; j<br_kolona-1; j++) {
        	izlazni_tok << elementi[br_redova-1][j] << ",";
        	if (!izlazni_tok) throw std::logic_error("Problemi sa upisom u datoteku");
        }
        izlazni_tok << elementi[br_redova-1][br_kolona-1];
        if (!izlazni_tok) throw std::logic_error("Problemi sa upisom u datoteku");
    }

template <typename Tip>
    void Matrica<Tip>::SacuvajUBinarnuDatoteku(const char ime_datoteke[]) const {
        std::ofstream izlazni_tok(ime_datoteke, std::ios::binary);
        izlazni_tok.write(reinterpret_cast<const char*>(this), sizeof *this);
        for (int i=0; i<br_redova; i++) {
            izlazni_tok.write(reinterpret_cast<char*>(elementi[i]), br_kolona*sizeof(Tip));
        }
        if (!izlazni_tok) throw std::logic_error("Problemi sa upisom u datoteku");
    }
    
template <typename Tip>
    void Matrica<Tip>::ObnoviIzTekstualneDatoteke(const char ime_datoteke[]) {
        std::ifstream ulazni_tok(ime_datoteke);
        if (!ulazni_tok) throw std::logic_error("Trazena datoteka ne postoji");
        std::vector<std::vector<Tip>> vektor;
        std::vector<Tip> vektor_reda;
        while (1) {
        	if (ulazni_tok.peek()==EOF) break;
        	Tip element;
        	ulazni_tok >> element;
        	if (!ulazni_tok) throw std::logic_error("Datoteka sadrzi besmislene podatke");
        	if (ulazni_tok.peek()!=',' && ulazni_tok.peek()!='\n' && ulazni_tok.peek()!=EOF)
        		throw std::logic_error("Datoteka sadrzi besmislene podatke");
        	vektor_reda.push_back(element);
        	if (ulazni_tok.peek()==EOF) {
        		vektor.push_back(vektor_reda);
        		if (vektor_reda.size()!=vektor.at(0).size())
        			throw std::logic_error("Datoteka sadrzi besmislene podatke");
        		break;
        	}
        	else if (ulazni_tok.peek()=='\n') {
        		vektor.push_back(vektor_reda);
        		if (vektor_reda.size()!=vektor.at(0).size())
        			throw std::logic_error("Datoteka sadrzi besmislene podatke");
        		vektor_reda.resize(0);
        	}
        	ulazni_tok.get();
        	if (ulazni_tok.peek()==',')
        		throw std::logic_error("Datoteka sadrzi besmislene podatke");
        }
        DealocirajMemoriju(elementi, br_redova);
        br_redova=vektor.size();
        br_kolona=vektor.at(0).size();
        elementi=AlocirajMemoriju(br_redova, br_kolona);
        ulazni_tok.close();
        ulazni_tok.open(ime_datoteke);
        int i(0), j(0);
        while (1) {
        	if (ulazni_tok.peek()==EOF) break;
        	Tip element;
        	ulazni_tok >> element;
        	elementi[i][j++]=element;
        	if (ulazni_tok.peek()==EOF) break;
        	else if (ulazni_tok.peek()=='\n') {
        		i++; j=0;
        	}
        	ulazni_tok.get();
        }
    }
    
template <typename Tip>
    void Matrica<Tip>::ObnoviIzBinarneDatoteke(const char ime_datoteke[]) {
        std::ifstream ulazni_tok(ime_datoteke, std::ios::binary);
        if (!ulazni_tok) throw std::logic_error("Trazena datoteka ne postoji");
        DealocirajMemoriju(elementi, br_redova);
        ulazni_tok.read(reinterpret_cast<char*>(this), sizeof *this);
        elementi=AlocirajMemoriju(br_redova, br_kolona);
        for (int i=0; i<br_redova; i++) {
        	ulazni_tok.read(reinterpret_cast<char*>(elementi[i]), br_kolona*sizeof(Tip));
        }
        if (!ulazni_tok) {
        	DealocirajMemoriju(elementi, br_redova);
        	throw std::logic_error("Problemi pri citanju datoteke");
        }
    }
	
template <typename Tip>
	Matrica<Tip>::operator std::string() const {
		std::string novi;
		novi+="{";
		for (int i=0; i<br_redova; i++) {
			novi+="{";
			for (int j=0; j<br_kolona; j++) {
				novi+=std::to_string(int(elementi[i][j]));
				if (j!=br_kolona-1) novi+=",";
			}
			novi+="}";
			if (i!=br_redova-1) novi+=",";
		}
		novi+="}";
		return novi;
	}
	
template <typename TipEl>
	TipEl** Matrica<TipEl>::AlocirajMemoriju(int br_redova, int br_kolona) {
		TipEl** elementi(new TipEl*[br_redova]{});
		try {
			for (int i=0; i<br_redova; i++) elementi[i]=new TipEl[br_kolona];
		}
		catch(...) {
			DealocirajMemoriju(elementi, br_redova); throw;
		}
		return elementi;
	}
	
template <typename TipEl>
	void Matrica<TipEl>::DealocirajMemoriju(TipEl** elementi, int br_redova) {
		for (int i=0; i<br_redova; i++) delete[] elementi[i];
		delete[] elementi;
	}
	
template <typename TipEl>
	Matrica<TipEl>::Matrica(int br_redova, int br_kolona, char ime) : 
	br_redova(br_redova), br_kolona(br_kolona), ime_matrice(ime), 
	 elementi(AlocirajMemoriju(br_redova, br_kolona)) {}
	 
template <typename TipEl>
	void Matrica<TipEl>::KopirajElemente(TipEl** elementi) {
		for (int i=0; i<br_redova; i++) {
			for (int j=0; j<br_kolona; j++) {
				Matrica::elementi[i][j]=elementi[i][j];
			}
		}
	}
	
template <typename TipEl>
	Matrica<TipEl>::Matrica(const Matrica<TipEl> &m) : 
	br_redova(m.br_redova), br_kolona(m.br_kolona), ime_matrice(m.ime_matrice), 
	 elementi(AlocirajMemoriju(m.br_redova, m.br_kolona)) {
		KopirajElemente(m.elementi);
	}
	
template <typename TipEl>
	Matrica<TipEl>::Matrica(Matrica<TipEl> &&m) : 
	br_redova(m.br_redova), br_kolona(m.br_kolona), ime_matrice(m.ime_matrice), 
	 elementi(m.elementi) {
		m.br_redova=0; m.elementi=nullptr;
	}
	
template <typename TipEl>
	Matrica<TipEl> &Matrica<TipEl>::operator =(const Matrica<TipEl> &m) {
		if (br_redova<m.br_redova || br_kolona<m.br_kolona) {
			TipEl** novi_prostor(AlocirajMemoriju(m.br_redova, m.br_kolona));
			DealocirajMemoriju(elementi, br_redova);
			elementi=novi_prostor;
		}
		else if (br_redova>m.br_redova) {
			for (int i=m.br_redova; i<br_redova; i++) {
				delete[] elementi[i];
			}
		}
		br_redova=m.br_redova; br_kolona=m.br_kolona; ime_matrice=m.ime_matrice;
		KopirajElemente(m.elementi);
		return *this;
	}
	
template <typename TipEl>
	Matrica<TipEl> &Matrica<TipEl>::operator =(Matrica<TipEl> &&m) {
		std::swap(br_redova, m.br_redova); std::swap(br_kolona, m.br_kolona);
		std::swap(ime_matrice, m.ime_matrice); std::swap(elementi, m.elementi);
		return *this;
	}
	
template <typename TipEl>
	std::istream &operator >>(std::istream &tok, Matrica<TipEl> &m) {
		for (int i=0; i<m.br_redova; i++) {
			for (int j=0; j<m.br_kolona; j++) {
				std::cout << m.ime_matrice << "(" << i+1 << "," << j+1 << ") = ";
				tok >> m.elementi[i][j];
			}
		}
		return tok;
	}

template <typename TipEl>
	Matrica<TipEl> &operator +=(Matrica<TipEl> &m1, const Matrica<TipEl> &m2) {
		if (m1.br_redova!=m2.br_redova || m1.br_kolona!=m2.br_kolona) {
			throw std::domain_error("Matrice nemaju jednake dimenzije!");
		}
		for (int i=0; i<m1.br_redova; i++) {
			for (int j=0; j<m1.br_kolona; j++) {
				m1.elementi[i][j]+=m2.elementi[i][j];
			}
		}
		return m1;
	}
template <typename Tip>
	Matrica<Tip> operator +(const Matrica<Tip> &m1, const Matrica<Tip> &m2) {
		if (m1.br_redova!=m2.br_redova || m1.br_kolona!=m2.br_kolona) {
			throw std::domain_error("Matrice nemaju jednake dimenzije!");
		}
		Matrica<Tip> m3(m1);
		m3+=m2;
		return m3;
	}
	
template <typename TipEl>
	std::ostream &operator <<(std::ostream &tok, const Matrica<TipEl> &m) {
		int sirina;
		sirina=tok.width();
		for (int i=0; i<m.br_redova; i++) {
			for (int j=0; j<m.br_kolona; j++) {
				tok << std::setw(sirina) << m.elementi[i][j];
			}
			tok << std::endl;
		}
		return tok;
	}
	
template <typename TipEl>
	Matrica<TipEl> &operator -=(Matrica<TipEl> &m1, const Matrica<TipEl> &m2) {
		if (m1.br_redova!=m2.br_redova || m1.br_kolona!=m2.br_kolona) {
			throw std::domain_error("Matrice nemaju jednake dimenzije!");
		}
		for (int i=0; i<m1.br_redova; i++) {
			for (int j=0; j<m1.br_kolona; j++) {
				m1.elementi[i][j]-=m2.elementi[i][j];
			}
		}
		return m1;
	}
	
template <typename Tip>
	Matrica<Tip> operator -(const Matrica<Tip> &m1, const Matrica<Tip> &m2) {
		if (m1.br_redova!=m2.br_redova || m1.br_kolona!=m2.br_kolona) {
			throw std::domain_error("Matrice nemaju jednake dimenzije!");
		}
		Matrica<Tip> m3(m1);
		m3-=m2;
		return m3;
	}

template <typename TipEl>
	Matrica<TipEl> &operator *=(Matrica<TipEl> &m1, double broj) {
		for (int i=0; i<m1.br_redova; i++) {
			for (int j=0; j<m1.br_kolona; j++) {
				m1.elementi[i][j]*=broj;
			}
		}
		return m1;
	}
	
template <typename Tip>
	Matrica<Tip> operator *(const Matrica<Tip> &m1, double broj) {
		Matrica<Tip> m3(m1);
		m3*=broj;
		return m3;
	}
	
template <typename Tip>
	Matrica<Tip> operator *(double broj, const Matrica<Tip> &m1) {
		Matrica<Tip> m3(m1);
		m3*=broj;
		return m3;
	}
	
template <typename TipEl>
	Matrica<TipEl> &operator *=(Matrica<TipEl> &m1, const Matrica<TipEl> &m2) {
		if (m1.br_kolona!=m2.br_redova) {
			throw std::domain_error("Matrice nisu saglasne za mnozenje");
		}
		Matrica<TipEl> pomocna(m1.br_redova, m2.br_kolona);
		for (int i=0; i<m1.br_redova; i++) {
			for (int j=0; j<m1.br_kolona; j++) {
				TipEl rezultat;
				rezultat=TipEl();
				for (int k=0; k<m1.br_kolona; k++) {
					rezultat=rezultat+((m1.elementi[i][k])*(m2.elementi[k][j]));
				}
				pomocna.elementi[i][j]=rezultat;
			}
		}
		m1=pomocna;
		return m1;
	}
	
template <typename Tip>
	Matrica<Tip> operator *(const Matrica<Tip> &m1, const Matrica<Tip> &m2) {
		if (m1.br_kolona!=m2.br_redova) {
			throw std::domain_error("Matrice nisu saglasne za mnozenje");
		}
		Matrica<Tip> m3(m1);
		m3*=m2;
		return m3;
	}

int main ()
{
	int m, n;
	std::cout << "Unesi broj redova i kolona za matrice:\n";
	std::cin >> m >> n;
	try {
		Matrica<double> a(m, n, 'A'), b(m, n, 'B');
		std::cout << "Unesi matricu A:\n";
		std::cin >> a;
		std::cout << "Unesi matricu B:\n";
		std::cin >> b;
		std::cout << "Zbir ove dvije matrice je:\n";
		std::cout << std::setw(7) << a+b;
	}
	catch(std::bad_alloc) {
		std::cout << "Nema dovoljno memorije!\n";
	}
	return 0;
}
