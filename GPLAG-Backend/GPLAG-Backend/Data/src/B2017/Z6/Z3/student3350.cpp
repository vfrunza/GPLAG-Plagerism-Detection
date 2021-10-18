/B2017/2018: Zadaća 6, Zadatak 3

#include <iostream>
#include <iomanip>
#include <cstring>
#include <stdexcept>
#include <new>
#include <string>
#include <fstream>
#include <sstream>

template <typename T> std::string PretvoriUString(T x) {
    std::ostringstream s; s << x; return s.str();
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
 	
 	Matrica(std::string ime, bool binarna) {
 	    br_kolona=0; br_redova=0; elementi=nullptr; ime_matrice=0;
 	    if (binarna) ObnoviIzBinarneDatoteke(ime);
 	    else ObnoviIzTekstualneDatoteke(ime);
 	}
 	
 	Matrica(Matrica &&m);
 	~Matrica() { DealocirajMemoriju(elementi, br_redova); }
 	Matrica &operator =(const Matrica &m);
 	Matrica &operator =(Matrica &&m);
 	
 	template <typename Tip2>
 	friend std::istream &operator >> (std::istream &tok, Matrica<Tip2> &mat);
 	template <typename Tip2>
    friend std::ostream &operator <<(std::ostream &tok, const Matrica<Tip2> &mat);
 	template <typename Tip2>
 	friend Matrica<Tip2> operator +(const Matrica<Tip2> &m1, const Matrica<Tip2> &m2);
 	template <typename Tip2>
    friend Matrica<Tip2> operator -(const Matrica<Tip2> &m1, const Matrica<Tip2> &m2);
 	template <typename TipElemenata>
    friend Matrica<TipElemenata> operator *(double n, Matrica<TipElemenata> mat);
    template <typename TipElemenata>
    friend Matrica<TipElemenata> operator *(Matrica<TipElemenata> mat, double n);
    template <typename TipElemenata>
    friend Matrica<TipElemenata> operator * (const Matrica<TipElemenata> &m1, const Matrica<TipElemenata> &m2) ;
    
    template <typename TipElemenata>
    friend Matrica<TipElemenata> operator += (Matrica<TipElemenata> &m1, const Matrica<TipElemenata> &m2);
    template <typename TipElemenata>
    friend Matrica<TipElemenata> operator *= (Matrica<TipElemenata> &m1, const Matrica<TipElemenata> &m2);
    template <typename TipElemenata>
    friend Matrica<TipElemenata> operator -= (Matrica<TipElemenata> &m1, const Matrica<TipElemenata> &m2);
    template <typename TipElemenata>
    friend Matrica<TipElemenata> &operator *= (Matrica<TipElemenata> &m1, double n);
    
    
    TipEl* operator [](int indeks) const {
        return elementi[indeks];
    }
    TipEl* &operator [](int indeks) {
        return elementi[indeks];
    }

    TipEl operator ()(int i, int j) const {
        if (i<1 || i>br_redova) throw std::range_error("Neispravan indeks");
        if (j<1 || j>br_kolona) throw std::range_error("Neispravan indeks");
        return elementi[i-1][j-1];
    }
    
    TipEl &operator ()(int i, int j) {
        if (i<1 || i>br_redova) throw std::range_error("Neispravan indeks");
        if (j<1 || j>br_kolona) throw std::range_error("Neispravan indeks");
        return elementi[i-1][j-1];
    }
    
    operator std::string() const {
        std::string s("{");
        for(int i = 0; i < br_redova; i++) {
            s=s+"{";
 		    for(int j = 0; j < br_kolona; j++) {
 		        s=s+PretvoriUString(elementi[i][j]);
 		        if (j!=br_kolona-1) s=s+",";
 		    }
 		    s=s+"}";
 		    if (i!=br_redova-1) s=s+",";
        }
        s=s+"}";
        return s;
    }
    
    void SacuvajUTekstualnuDatoteku (std::string ime) const {
        std::ofstream izlaz(ime);
        if (!izlaz) throw std::logic_error("Problemi sa upisom u datoteku");
        
        for (int i=0; i<br_redova; i++) {
            for (int j=0; j<br_kolona; j++) {
                izlaz << elementi[i][j];
                if (!izlaz) throw std::logic_error("Problemi sa upisom u datoteku");
                if (j<br_kolona-1) izlaz << ",";
                if (!izlaz) throw std::logic_error("Problemi sa upisom u datoteku");
            }
            if (i<br_redova-1) izlaz << std::endl;
            if (!izlaz) throw std::logic_error("Problemi sa upisom u datoteku");
        }
        return;
    }
   
    void SacuvajUBinarnuDatoteku (std::string ime) const {
        std::ofstream izlaz (ime, std::ios::binary);
        if (!izlaz) throw std::logic_error("Problemi sa upisom u datoteku");
        
        
        izlaz.write(reinterpret_cast<const char*>(this), sizeof *this);
        if (!izlaz) throw std::logic_error("Problemi sa upisom u datoteku");
        
        for (int i=0; i<br_redova; i++) {
            for (int j=0; j<br_kolona; j++) {
                izlaz.write(reinterpret_cast<char*>(&(elementi[i][j])), sizeof (TipEl));
                if (!izlaz) throw std::logic_error("Problemi sa upisom u datoteku");
            }
        }   
        
        return;
    }
    
    void ObnoviIzTekstualneDatoteke (std::string ime) {
        
        std::ifstream ulaz (ime);
        if (!ulaz) throw std::logic_error("Trazena datoteka ne postoji");
        
        int redovi(0), kolone(0), temp_kolone(0);
        TipEl x;
        char znak;
        bool prvi_put(true);
        
        for(;;) {
            temp_kolone=0;
            while (ulaz >> x) {
                ulaz.clear();
                znak=ulaz.get();
                temp_kolone++;
                if (znak=='\n' || ulaz.eof()) break;
                if (znak!=',') throw std::logic_error("Datoteka sadrzi besmislene podatke");
            }
            if (ulaz.eof()) break;
            if (!ulaz) throw std::logic_error("Datoteka sadrzi besmislene podatke");
            if (prvi_put) kolone=temp_kolone; prvi_put=false;
            if (ulaz.bad()) throw std::logic_error("Problemi pri citanju datoteke");
            if (kolone!=temp_kolone) throw std::logic_error("Datoteka sadrzi besmislene podatke");
            if (!ulaz) throw std::logic_error("Datoteka sadrzi besmislene podatke");
            redovi++;
        }
        ulaz.close();
        
        DealocirajMemoriju(elementi, br_redova); 
        
        br_redova=redovi+1;
        br_kolona=kolone;
        
        elementi=AlocirajMemoriju(br_redova, br_kolona);
        
        ulaz.open(ime);
        
        
        for (int i=0; i<br_redova; i++) {
            for (int j=0; j<br_kolona; j++) {
                ulaz >> x;
                elementi[i][j]=x;
                ulaz.clear();
                ulaz.get();
            }
        }
        
        return;
    }
    
    void ObnoviIzBinarneDatoteke (std::string ime) {
        
        std::ifstream ulaz(ime, std::ios::binary);
        if (!ulaz) throw std::logic_error("Trazena datoteka ne postoji");
        
        DealocirajMemoriju(elementi, br_redova);
        
        ulaz.read(reinterpret_cast<char*>(this), sizeof *this);
        
        if (!ulaz) throw std::logic_error("Problemi pri citanju datoteke");
        elementi=AlocirajMemoriju(br_redova, br_kolona);
        
        for (int i=0; i<br_redova; i++) {
            for (int j=0; j<br_kolona; j++) {
                ulaz.read(reinterpret_cast<char*>(&(elementi[i][j])), sizeof(TipEl));
                if (!ulaz) {
                    DealocirajMemoriju(elementi, br_redova);
                    throw std::logic_error("Problemi pri citanju datoteke");
                }
            }
        }
        if (!ulaz) {
            DealocirajMemoriju(elementi, br_redova);
            throw std::logic_error("Problemi pri citanju datoteke");
        }
    }
    
    
};

template <typename TipEl>
TipEl ** Matrica<TipEl>::AlocirajMemoriju(int br_redova, int br_kolona) {
 	TipEl **elementi(new TipEl*[br_redova]{});
 	try {
 		for(int i = 0; i < br_redova; i++) elementi[i] = new TipEl[br_kolona];
 	}
 	catch(...) {
 		DealocirajMemoriju(elementi, br_redova); throw;
 	}
 	return elementi;
}

template <typename TipEl>
void Matrica<TipEl>::DealocirajMemoriju(TipEl **elementi, int br_redova) {
 	if (elementi!=nullptr) {
 	    for(int i = 0; i < br_redova; i++) if (elementi[i]!=nullptr) { delete[] elementi[i]; elementi[i]=nullptr; }
 	    delete[] elementi; elementi=nullptr;
 	}
}

template <typename TipEl>
Matrica<TipEl>::Matrica(int br_redova, int br_kolona, char ime) : br_redova(br_redova), br_kolona(br_kolona), ime_matrice(ime), elementi(AlocirajMemoriju(br_redova, br_kolona)) {}


template <typename TipEl>
void Matrica<TipEl>::KopirajElemente(TipEl **elementi) {
 	for(int i = 0; i < br_redova; i++)
 		for(int j = 0; j < br_kolona; j++)
 			Matrica::elementi[i][j] = elementi[i][j];
}

template <typename TipEl>
Matrica<TipEl>::Matrica(const Matrica<TipEl> &m) : br_redova(m.br_redova), br_kolona(m.br_kolona), ime_matrice(m.ime_matrice), elementi(AlocirajMemoriju(m.br_redova, m.br_kolona)) {
 	KopirajElemente(m.elementi);
}


template <typename TipEl>
Matrica<TipEl>::Matrica(Matrica<TipEl> &&m) : br_redova(m.br_redova), br_kolona(m.br_kolona), elementi(m.elementi), ime_matrice(m.ime_matrice) {
	m.br_redova = 0; m.elementi = nullptr;
}

template <typename TipEl>
Matrica<TipEl> &Matrica<TipEl>::operator =(const Matrica<TipEl> &m) {
 	if(br_redova < m.br_redova || br_kolona < m.br_kolona) {
 		TipEl **novi_prostor(AlocirajMemoriju(m.br_redova, m.br_kolona));
 		DealocirajMemoriju(elementi, br_redova);
 		elementi = novi_prostor;
 	}
 	else if(br_redova > m.br_redova) for(int i = m.br_redova; i < br_redova; i++) delete elementi[i];
 	
 	br_redova = m.br_redova; br_kolona = m.br_kolona;
 	ime_matrice = m.ime_matrice; KopirajElemente(m.elementi);
 	return *this;
}

template <typename TipEl>
Matrica<TipEl> &Matrica<TipEl>::operator =(Matrica<TipEl> &&m) {
 	std::swap(br_redova, m.br_redova); std::swap(br_kolona, m.br_kolona);
 	std::swap(ime_matrice, m.ime_matrice); std::swap(elementi, m.elementi);
 	return *this;
}

 
template <typename TipEl>
std::ostream &operator <<(std::ostream &tok, const Matrica<TipEl> &mat) {
    
    int sirina(tok.width());
    
 	for(int i = 0; i < mat.br_redova; i++) {
 		for(int j = 0; j < mat.br_kolona; j++) {
 			tok << std::setw(sirina) << mat.elementi[i][j];
 		}
 		tok << std::endl;
 	}
 	
 	return tok;
 }


template <typename TipEl>
Matrica<TipEl> operator +(const Matrica<TipEl> &m1, const Matrica<TipEl> &m2) {
 	if(m1.br_redova != m2.br_redova || m1.br_kolona != m2.br_kolona) throw std::domain_error("Matrice nemaju jednake dimenzije!");
 	Matrica<TipEl> m3(m1.br_redova, m1.br_kolona);
 	for(int i = 0; i < m1.br_redova; i++)
 		for(int j = 0; j < m1.br_kolona; j++)
 			m3.elementi[i][j] = m1.elementi[i][j] + m2.elementi[i][j];
 	return m3;
}

template <typename TipEl>
Matrica<TipEl> operator -(const Matrica<TipEl> &m1, const Matrica<TipEl> &m2) {
 	if(m1.br_redova != m2.br_redova || m1.br_kolona != m2.br_kolona) throw std::domain_error("Matrice nemaju jednake dimenzije!");
 	Matrica<TipEl> m3(m1.br_redova, m1.br_kolona);
 	for(int i = 0; i < m1.br_redova; i++)
 		for(int j = 0; j < m1.br_kolona; j++)
 			m3.elementi[i][j] = m1.elementi[i][j] - m2.elementi[i][j];
 	return m3;
}


template <typename TipEl>
std::istream &operator >> (std::istream &tok, Matrica<TipEl> &mat) {
    
    for(int i = 0; i < mat.br_redova; i++)
 		for(int j = 0; j < mat.br_kolona; j++) {
 			std::cout << mat.ime_matrice << "(" << i + 1 << "," << j + 1 << ") = ";
 		tok >> mat.elementi[i][j];
 	}
    
 	return tok;
}

template <typename TipElemenata>
Matrica<TipElemenata> operator * (const Matrica<TipElemenata> &m1, const Matrica<TipElemenata> &m2) {
    if (m1.br_kolona!=m2.br_redova) throw std::domain_error("Matrice nisu saglasne za mnozenje");
    
    Matrica<TipElemenata> m3(m1.br_redova, m2.br_kolona);
    for (int i=0; i<m1.br_redova; i++) {
        for (int j=0; j<m2.br_kolona; j++) {
            m3.elementi[i][j]=0;
            for (int k=0; k<m1.br_kolona; k++) m3.elementi[i][j]+=(m1.elementi[i][k]*m2.elementi[k][j]);
        }
    }
    return m3;
}

template <typename TipElemenata>
Matrica<TipElemenata> operator *(Matrica<TipElemenata> mat, double n) {
    Matrica<TipElemenata> nova(mat.br_redova, mat.br_kolona);
    for (int j=0; j<mat.br_redova; j++) {
        for (int k=0; k<mat.br_kolona; k++) {
            nova.elementi[j][k]=mat.elementi[j][k]*n;
        }
    }
    return nova;
}

template <typename TipElemenata>
Matrica<TipElemenata> &operator *= (Matrica<TipElemenata> &m1, double n) {
    m1=m1*n;
    return m1;
}

template <typename TipElemenata>
Matrica<TipElemenata> operator *(double n, Matrica<TipElemenata> mat) {
    Matrica<TipElemenata> nova(mat.br_redova, mat.br_kolona);
    nova=mat*n;
    return nova;
}

template <typename TipElemenata>
Matrica<TipElemenata> operator += (Matrica<TipElemenata> &m1, const Matrica<TipElemenata> &m2) {
    m1=m1+m2;
    return m1;
}

template <typename TipElemenata>
Matrica<TipElemenata> operator -= (Matrica<TipElemenata> &m1, const Matrica<TipElemenata> &m2) {
    m1=m1-m2;
    return m1;
}

template <typename TipElemenata>
Matrica<TipElemenata> operator *= (Matrica<TipElemenata> &m1, const Matrica<TipElemenata> &m2) {
    m1=m1*m2;
    return m1;
}


int main() {
    
    
    
 	return 0;
}