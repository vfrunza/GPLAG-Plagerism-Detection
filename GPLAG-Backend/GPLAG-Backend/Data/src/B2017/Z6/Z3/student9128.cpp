#include <iostream>
#include <iomanip>
#include <new>
#include <stdexcept>
#include <cstring>
#include <string>
#include <cmath>
#include <fstream>

using std::cout;
using std::cin;

void kreirajDatotetkuZbii1()
{
    std::string ime = "matrica1.txt";
    std::ofstream dat(ime);
    dat << "1, 2\n3, 4";
    dat.close();
}

void kreirajDatotetkuZbii4()
{
    std::string ime = "matrica4.txt";
    std::ofstream dat(ime);
    dat << "1.4{2.54@3.7*-4.7";
    dat.close();
}

template <typename TipEl> 
class Matrica {
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
	TipEl* operator[] (int indeks) const;
	TipEl* &operator[] (int indeks);
	TipEl operator() (int i, int j) const;
	TipEl &operator () (int i, int j);
	operator std::string() const;
	template <typename Tip2> friend Matrica<Tip2> operator*(Matrica<Tip2> m1, const Matrica<Tip2> &m2);
	template <typename Tip2> friend std::istream &operator>>(std::istream &tok, Matrica<Tip2> &m);
	template <typename Tip2> friend Matrica<Tip2> &operator*=(Matrica<Tip2> &m1, const Matrica<Tip2> &m2);
	template <typename Tip2> friend Matrica<Tip2> &operator+=( Matrica<Tip2> &m1, const Matrica<Tip2> &m2);
	template <typename Tip2> friend Matrica<Tip2> operator+(Matrica<Tip2> m1, const Matrica<Tip2> &m2);
	template <typename Tip2> friend std::istream &operator>>(std::istream &tok, Matrica<Tip2> &m);
	template <typename Tip2> friend std::ostream &operator<<(std::ostream &tok, const Matrica<Tip2> &m);
	template <typename Tip2> friend Matrica<Tip2> &operator-=(Matrica<Tip2> &m1, const Matrica<Tip2> &m2);
	template <typename Tip2> friend Matrica<Tip2> operator-(Matrica<Tip2> m1, const Matrica<Tip2> &m2);
	template <typename Tip2, typename Skalar> friend Matrica<Tip2> &operator*=(Matrica<Tip2> &m, Skalar s);
	template <typename Tip2, typename Skalar> friend Matrica<Tip2> operator*(Matrica<Tip2> m, Skalar s);
	template <typename Tip2, typename Skalar> friend Matrica<Tip2> operator*(Skalar s, Matrica<Tip2> m);
	
	void ObnoviIzBinarneDatoteke(std::string ime_dat);
	void SacuvajUTekstualnuDatoteku(std::string);
	void SacuvajUBinarnuDatoteku(std::string);
	void ObnoviIzTekstualneDatoteke(std::string);
	
	Matrica(std::string, bool);
};

template <typename TipEl>
Matrica<TipEl>::Matrica(std::string ime_dat, bool bin_text) {
	if(bin_text) {
		std::ifstream dat(ime_dat, std::ios::binary);
		if(!dat) throw std::logic_error("Trazena datoteka ne postoji");
		
		TipEl pomocni;
		char znak;
		int broj_kolona(0), broj_redova(0), tekuci(0);
		
		while(dat && !dat.eof())
		{
			for(;;) {
				for(;;) {
					dat.read((char *)&pomocni, sizeof(TipEl));
					tekuci++;
					if(dat.eof()) break;
					dat.read((char *)&znak, sizeof(znak));
					if(znak=='\n') break;
					else if(znak!=',') throw std::logic_error("Datoteka sadrzi besmislene podatke");
					if(!dat) break;
				}
				if(broj_kolona!=0 && tekuci!=broj_kolona) throw std::logic_error("Datoteka sadrzi besmislene podatke");
				else broj_kolona=tekuci;
				broj_redova++;
				if(dat.eof()) break;
				if(!dat || dat.eof()) break;
				tekuci=0;
			}
		}
		
		if(!dat && !dat.eof()) throw std::logic_error("Problemi pri citanju datoteke");
		
		
		elementi=AlocirajMemoriju(broj_redova, broj_kolona);
		br_redova=broj_redova;
		br_kolona=broj_kolona;
		
		dat.seekg(0, std::ios::beg);
		
		for(int i=0; i<br_redova; i++) {
			for(int j=0; j<br_kolona; j++) {
				dat.read((char *)&elementi[i][j], sizeof(TipEl));
				if(j!=br_kolona-1) dat.read((char *)&znak, sizeof(znak));
			}
		}
	} else {
		std::ifstream dat(ime_dat);
		if(!dat) throw std::logic_error("Trazena datoteka ne postoji");
		
		
		
		TipEl pomocni;
		char znak;
		int broj_kolona(0), broj_redova(0), tekuci(0);
		
		while(dat && !dat.eof())
		{
			for(;;) {
				for(;;) {
					dat>>pomocni;
					tekuci++;
					if(dat.eof()) break;
					if((znak=dat.get())=='\n') break;
					else if(znak!='\n' && znak!=',') throw std::logic_error("Datoteka sadrzi besmislene podatke");
					if(!dat) break;
				}
				if(broj_kolona!=0) {
					if(tekuci!=broj_kolona) throw std::logic_error("Datoteka sadrzi besmislene podatke");
				} else broj_kolona=tekuci;
				broj_redova++;
				if(dat.eof()) break;
				if(!dat || dat.eof()) break;
				tekuci=0;
			}
		}
		if(!dat && !dat.eof()) throw std::logic_error("Problemi pri citanju datoteke");
		
		DealocirajMemoriju(this->elementi, br_redova);
		
		elementi=AlocirajMemoriju(broj_redova, broj_kolona);
		br_redova=broj_redova;
		br_kolona=broj_kolona;
		
		dat.seekg(0, std::ios::beg);
		
		for(int i=0; i<br_redova; i++)
		{
			for(int j=0; j<br_kolona; j++) {
				dat>>elementi[i][j];
				if(j!=br_kolona-1) dat>>znak;
			}
		}
		}
}

template <typename TipEl>
void Matrica<TipEl>::ObnoviIzTekstualneDatoteke(std::string ime_dat) {
    std::ifstream dat(ime_dat);
    if(!dat) throw std::logic_error("Trazena datoteka ne postoji");
    
    
    
    TipEl pomocni;
    char znak;
    int broj_kolona(0), broj_redova(0), tekuci(0);
    
    while(dat && !dat.eof()) {
        for(;;) {
            for(;;) {
                dat>>pomocni;
                tekuci++;
                if(dat.eof()) break;
                if((znak=dat.get())=='\n') break;
                else if(znak!='\n' && znak!=',') throw std::logic_error("Datoteka sadrzi besmislene podatke");
                if(!dat) break;
            }
            if(broj_kolona!=0) {
                if(tekuci!=broj_kolona) throw std::logic_error("Datoteka sadrzi besmislene podatke");
            } else broj_kolona=tekuci;
            broj_redova++;
            if(dat.eof()) break;
            if(!dat || dat.eof()) break;
            tekuci=0;
        }
    }
    if(!dat && !dat.eof()) throw std::logic_error("Problemi pri citanju datoteke");
    
    DealocirajMemoriju(this->elementi, br_redova);
    
    elementi=AlocirajMemoriju(broj_redova, broj_kolona);
    br_redova=broj_redova; br_kolona=broj_kolona;
    
    dat.seekg(0, std::ios::beg);
    
    for(int i=0; i<br_redova; i++) {
        for(int j=0; j<br_kolona; j++) {
            dat>>elementi[i][j];
            if(j!=br_kolona-1) dat>>znak;
        }
    }
}

template <typename TipEl>
void Matrica<TipEl>::ObnoviIzBinarneDatoteke(std::string ime_dat) {
	std::ifstream dat(ime_dat, std::ios::binary);
	if(!dat) throw std::logic_error("Trazena datoteka ne postoji");
	
	TipEl pomocni;
    char znak;
    int broj_kolona(0), broj_redova(0), tekuci(0);
    
	while(dat && !dat.eof()) {
		for(;;) {
			for(;;) {
				dat.read((char *)&pomocni, sizeof(TipEl));
				tekuci++;
				if(dat.eof()) break;
				dat.read((char *)&znak, sizeof(znak));
				if(znak=='\n') break;
				else if(znak!=',') throw std::logic_error("Datoteka sadrzi besmislene podatke");
				if(!dat) break;
			}
			if(broj_kolona!=0 && tekuci!=broj_kolona) throw std::logic_error("Datoteka sadrzi besmislene podatke");
			else broj_kolona=tekuci;
			broj_redova++;
			if(dat.eof()) break;
			if(!dat || dat.eof()) break;
            tekuci=0;
		}
	}
	
	if(!dat && !dat.eof()) throw std::logic_error("Problemi pri citanju datoteke");
    
    DealocirajMemoriju(this->elementi, br_redova);
    
    elementi=AlocirajMemoriju(broj_redova, broj_kolona);
    br_redova=broj_redova; br_kolona=broj_kolona;
    
    dat.seekg(0, std::ios::beg);
    
    for(int i=0; i<br_redova; i++) {
        for(int j=0; j<br_kolona; j++) {
            dat.read((char *)&elementi[i][j], sizeof(TipEl));
            if(j!=br_kolona-1) dat.read((char *)&znak, sizeof(znak));
        }
    }
}

template <typename TipEl>
void Matrica<TipEl>::SacuvajUTekstualnuDatoteku(std::string ime_dat) {
    std::ofstream izlaz(ime_dat);
    for(int i=0; i<br_redova; i++) {
        for(int j=0; j<br_kolona; j++) {
            if(j==br_kolona-1) {
                izlaz<<elementi[i][j];
                if(!izlaz) throw std::logic_error("Problemi sa upisom u datoteku");
            } else {
                izlaz<<elementi[i][j]<<",";
                if(!izlaz) throw std::logic_error("Problemi sa upisom u datoteku");
            }
        }
        if(i!=br_redova-1) izlaz<<"\n";
        if(!izlaz) throw std::logic_error("Problemi sa upisom u datoteku");
    }
}

template <typename TipEl>
void Matrica<TipEl>::SacuvajUBinarnuDatoteku(std::string ime_dat) {
    std::ofstream izlaz(ime_dat, std::ios::binary);
    char pomocni(',');
    for(int i=0; i<br_redova; i++) {
        for(int j=0; j<br_kolona; j++) {
            if(j==br_kolona-1) {
                izlaz.write(reinterpret_cast<char *>(&elementi[i][j]), sizeof(TipEl));
                if(!izlaz) throw std::logic_error("Problemi sa upisom u datoteku");
            } else {
                char pomocni(',');
                izlaz.write(reinterpret_cast<char *>(&elementi[i][j]), sizeof(TipEl));
                izlaz.write(reinterpret_cast<char *>(&pomocni), sizeof(pomocni));
                if(!izlaz) throw std::logic_error("Problemi sa upisom u datoteku");
            }
        }
        pomocni='\n';
        izlaz.write(reinterpret_cast<char *>(&pomocni), sizeof(pomocni));
        if(!izlaz) throw std::logic_error("Problemi sa upisom u datoteku");
        pomocni=',';
    }
}

template <typename TipEl>   
TipEl ** Matrica<TipEl>::AlocirajMemoriju(int br_redova, int br_kolona) {
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
void Matrica<TipEl>::DealocirajMemoriju(TipEl **elementi, int br_redova) {
	for(int i = 0; i < br_redova; i++) delete[] elementi[i];
	delete[] elementi;
}
template <typename TipEl>   
Matrica<TipEl>::Matrica(int br_redova, int br_kolona, char ime) : br_redova(br_redova), br_kolona(br_kolona), ime_matrice(ime), elementi(AlocirajMemoriju(br_redova, br_kolona)) {}

template <typename TipEl>   
void Matrica<TipEl>::KopirajElemente(TipEl **elementi) {
	for(int i = 0; i < br_redova; i++)       
		for(int j = 0; j < br_kolona; j++)         
			Matrica::elementi[i][j] = elementi[i][j];
}

template <typename TipEl>   Matrica<TipEl>::Matrica(const Matrica<TipEl> &m) : br_redova(m.br_redova), br_kolona(m.br_kolona), ime_matrice(m.ime_matrice), elementi(AlocirajMemoriju(m.br_redova, m.br_kolona)) {
	KopirajElemente(m.elementi);
}

template <typename TipEl>   
Matrica<TipEl>::Matrica(Matrica<TipEl> &&m) : br_redova(m.br_redova), br_kolona(m.br_kolona), elementi(m.elementi), ime_matrice(m.ime_matrice) {
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
	} else if(br_redova > m.br_redova) for(int i = m.br_redova; i < br_redova; i++) delete elementi[i];
	br_redova = m.br_redova;
	br_kolona = m.br_kolona;
	ime_matrice = m.ime_matrice;
	KopirajElemente(m.elementi);
	return *this;
}
template <typename TipEl>   
Matrica<TipEl> &Matrica<TipEl>::operator =(Matrica<TipEl> &&m) {
	std::swap(br_redova, m.br_redova);
	std::swap(br_kolona, m.br_kolona);
	std::swap(ime_matrice, m.ime_matrice);
	std::swap(elementi, m.elementi);
	return *this;
}

template <typename TipEl>   
std::istream &operator>>(std::istream &tok, Matrica<TipEl> &m) {
	for(int i = 0; i < m.br_redova; i++)       
		for(int j = 0; j < m.br_kolona; j++) {
			std::cout << m.ime_matrice << "(" << i + 1 << "," << j + 1 << ") = ";
			tok >> m.elementi[i][j];
		}
	return tok;
}
template <typename TipEl>   
std::ostream &operator<<(std::ostream &tok, const Matrica<TipEl> &m) {
	int sirina=tok.width();
	for(int i = 0; i < m.br_redova; i++) {
		for(int j = 0; j < m.br_kolona; j++)  tok << std::setw(sirina) << m[i][j];
		tok << std::endl;
	}
	return tok;
}
template <typename TipEl>   
Matrica<TipEl> &operator+=( Matrica<TipEl> &m1, const Matrica<TipEl> &m2) {
	if(m1.br_redova != m2.br_redova || m1.br_kolona != m2.br_kolona) throw std::domain_error("Matrice nemaju jednake dimenzije!");
	for(int i = 0; i < m1.br_redova; i++)         
		for(int j = 0; j < m1.br_kolona; j++)        
			m1.elementi[i][j] = m1.elementi[i][j] + m2.elementi[i][j];
	return m1;
}

template <typename TipEl>
Matrica<TipEl> operator+(Matrica<TipEl> m1, const Matrica<TipEl> &m2) {
	if(m1.br_redova != m2.br_redova || m1.br_kolona != m2.br_kolona) throw std::domain_error("Matrice nemaju jednake dimenzije!");
	m1+=m2;
	return m1;
}

template <typename TipEl>
Matrica<TipEl> &operator-=(Matrica<TipEl> &m1, const Matrica<TipEl> &m2) {
	if(m1.br_redova != m2.br_redova || m1.br_kolona != m2.br_kolona) throw std::domain_error("Matrice nemaju jednake dimenzije!");
	for(int i=0; i<m1.br_redova; i++) {
		for(int j=0; j<m1.br_kolona; j++) {
			m1.elementi[i][j]= m1.elementi[i][j]-m2.elementi[i][j];
		}
	}
	return m1;
}

template <typename TipEl>
Matrica<TipEl> operator-(Matrica<TipEl> m1, const Matrica<TipEl> &m2) {
	if(m1.br_redova != m2.br_redova || m1.br_kolona != m2.br_kolona) throw std::domain_error("Matrice nemaju jednake dimenzije!");
	m1-=m2;
	return m1;
}

template <typename TipEl> 
Matrica<TipEl> &operator*=(Matrica<TipEl> &m1, const Matrica<TipEl> &m2) {
    if(m1.br_kolona!=m2.br_redova) throw std::domain_error("Matrice nisu saglasne za mnozenje");
    Matrica<TipEl> m3(m1.br_redova, m2.br_kolona);
    
    for(int i=0; i<m1.br_redova; i++) {
        for(int j=0; j<m2.br_kolona; j++) {
        	m3.elementi[i][j]=0;
            for(int k=0; k<m1.br_kolona; k++) {
                m3.elementi[i][j]+=m1.elementi[i][k]*m2.elementi[k][j];
            }
        }
    }
    m1=m3;
    return m1;
}

template <typename TipEl>
Matrica<TipEl> operator*(Matrica<TipEl> m1, const Matrica<TipEl> &m2) {
	if(m1.br_kolona!=m2.br_redova) throw std::domain_error("Matrice nisu saglasne za mnozenje");
	
	m1*=m2;
	return m1;
}

template <typename TipEl>
TipEl* Matrica<TipEl>::operator[] (int indeks) const {
	return elementi[indeks];
}

template <typename TipEl>
TipEl* &Matrica<TipEl>::operator[](int indeks) {
	return elementi[indeks];
}

template <typename TipEl>
TipEl &Matrica<TipEl>::operator()(int i, int j) {
	if(i>br_redova+1 || j>br_kolona+1 || i<=0 || j<=0) throw std::range_error("Neispravan indeks");
	return elementi[i-1][j-1];
}

template <typename TipEl>
TipEl Matrica<TipEl>::operator()(int i, int j) const {
	if(i>br_redova+1 || j>br_kolona+1) throw std::range_error("Neispravan indeks");
	return elementi[i-1][j-1];
}

template <typename TipEl, typename Skalar>
Matrica<TipEl> &operator*=(Matrica<TipEl> &m, Skalar s) {
	for(int i=0; i<m.br_redova; i++) 
		for(int j=0; j<m.br_kolona; j++) 
			m.elementi[i][j]*=s;
	return m;
}

template <typename TipEl, typename Skalar>
Matrica<TipEl> operator*(Matrica<TipEl> m, Skalar s) {
	m*=s;
	return m;
}

template <typename TipEl, typename Skalar>
Matrica<TipEl> operator*(Skalar s, Matrica<TipEl> m) {
	m*=s;
	return m;
}

template <typename TipEl>
Matrica<TipEl>::operator std::string() const {
	std::string povratni;
	povratni.push_back('{');
	for(int i=0; i<br_redova; i++) {
		povratni.push_back('{');
		for(int j=0; j<br_kolona; j++) {
			if(j!=0)povratni.push_back(',');
			if(fabs(elementi[i][j]-int(elementi[i][j]))<=10e-5) povratni+=std::to_string(int(elementi[i][j]));
			else povratni+=std::to_string(elementi[i][j]);
		}
		povratni.push_back('}');
		if(i!=br_redova-1) povratni.push_back(',');
	}
	povratni.push_back('}');
	return povratni;
}

int main ()
{
    kreirajDatotetkuZbii1();
    kreirajDatotetkuZbii4();
    Matrica<int> m1("matrica1.txt", false);
    try
    {
        
        std::cout << std::setw(6) << m1;
        m1.ObnoviIzTekstualneDatoteke("matrica4.txt");
        std::cout << "Ovo se ne smije ispisati." << std::endl;
    }
    catch (const std::logic_error& e)
    {
        std::cout << "Izuzetak: " << e.what() << std::endl;
        std::cout << std::setw(6) << m1 << std::endl << std::endl;
    }

	
	

	return 0;
}