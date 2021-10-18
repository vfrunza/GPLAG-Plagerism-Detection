
#include <iostream>
#include <iomanip>
#include <cstring>
#include <stdexcept>
#include <new>
#include <fstream>
#include <cctype>

template <typename TipEl>
class Matrica
{
	int br_redova, br_kolona;
	TipEl **elementi;
	char ime_matrice;
	static TipEl **AlocirajMemoriju(int br_redova, int br_kolona);
	static void DealocirajMemoriju(TipEl **elementi, int br_redova);
	void KopirajElemente(TipEl **elementi);
	bool TestIndexa(int &i, int &j) const {
		if(i < 1 || i > br_redova || j < 1 || j > br_kolona) return false;
		return true;
	}
public:
    Matrica(const std::string &ime_datoteke, bool hehe);
	Matrica(int br_redova, int br_kolona, char ime = 0);
	Matrica(const Matrica &m);
	Matrica(Matrica &&m);
	~Matrica() {
		DealocirajMemoriju(elementi, br_redova);
	}
	Matrica &operator =(const Matrica &m);
	Matrica &operator =(Matrica &&m);
	TipEl* operator [](int i);
	TipEl& operator ()(int i, int j);
	TipEl* operator [](int i) const;
	TipEl operator ()(int i, int j) const;
	
	template <typename tip2>
	friend std::istream &operator >> (std::istream &tok, Matrica<tip2> &mat);
	template <typename tip2>
	friend std::ostream& operator << (std::ostream &tok, Matrica<tip2> &mat);
	template <typename tip2>
	friend Matrica<tip2> operator +(const Matrica<tip2> &m1, const Matrica<tip2> &m2);
	template <typename tip2>
	friend Matrica<tip2> operator -(Matrica<tip2> &mat);
	template <typename tip2>
	friend Matrica<tip2> operator -(const Matrica<tip2> &mat,const Matrica<tip2> &mat1);
	template <typename tip2>
	friend Matrica<tip2> operator *(Matrica<tip2> &mat, double broj);
	template <typename tip2>
	friend Matrica<tip2> operator *(double broj, Matrica<tip2> &mat);
	template <typename tip2>
	friend Matrica<tip2> operator *(const Matrica<tip2> &mat,const Matrica<tip2> &mat1);
	operator std::string()  const;
	
    Matrica operator +=(const Matrica &mat1) {
    	if(this->br_redova != mat1.br_redova || this->br_kolona != mat1.br_kolona) throw std::domain_error("Matrice nemaju jednake dimenzije!");
		for(int i = 0; i < br_redova; i++) {
			for(int j = 0; j < br_kolona; j++) {
				elementi[i][j] += mat1[i][j];
			}
		}
		return *this;
    }
    Matrica operator -=(const Matrica &mat1) {
    	if(this->br_redova != mat1.br_redova || this->br_kolona != mat1.br_kolona) throw std::domain_error("Matrice nemaju jednake dimenzije!");
		for(int i = 0; i < br_redova; i++) {
			for(int j = 0; j < br_kolona; j++) {
			elementi[i][j] -= mat1[i][j];
			}
		}
		return *this;
    }
    Matrica operator *=(const Matrica &m1) {
    	if(br_kolona != m1.br_redova) throw std::domain_error("Matrice nisu saglasne za mnozenje");
		Matrica m2(*this);
		for(int i = 0; i < br_redova; i++) {
			for(int j = 0; j < m1.br_kolona; j++) {
				elementi[i][j] = 0;
				for(int k = 0; k < m1.br_kolona; k++) {
					elementi[i][j] += m2[i][k] * m1[k][j];
				}
			}
		}
		return *this;
    }
    Matrica operator *=(double broj) {
    	for(int i = 0; i < br_redova; i++) {
		for(int j = 0; j < br_kolona; j++)
			elementi[i][j] *= broj;
	}
	return *this;
    }
    void SacuvajUTekstualnuDatoteku(const std::string &ime_datoteke) const;
    void ObnoviIzTekstualneDatoteke(const std::string &ime_datoteke);
    void SacuvajUBinarnuDatoteku(const std::string &ime_datoteke) const;
    void ObnoviIzBinarneDatoteke(const std::string &ime_datoteke);
};

template<typename TipEl>
Matrica<TipEl>::Matrica(const std::string &ime_datoteke, bool hehe)
{
    if(hehe) {
        std::ifstream tok(ime_datoteke, std::ios::binary);
        if(!tok) throw std::logic_error("Trazena datoteka ne postoji");
        tok.read(reinterpret_cast<char*> (this), sizeof(*this));
        elementi = new TipEl*[br_redova] {};
        for(int i = 0; i < br_redova; i++) {
            elementi[i] = new TipEl[br_kolona];
            tok.read(reinterpret_cast<char*> (elementi[i]), sizeof(TipEl) * br_kolona);
        }
        if(!tok) {
         for(int i = 0; i < br_redova; i++) delete[] elementi[i];
         delete[] elementi;
         throw std::logic_error("Datoteka sadrzi besmislene podatke");
        }
    } else {
    	std::ifstream tok(ime_datoteke);
    if(!tok) throw std::logic_error("Trazena datoteka ne postoji");
    int broj_r(0), broj_k(0), pomocni(0);
    TipEl elem;
    char znak;
        while(tok) {
            tok >> elem; 
            if(!tok) break;
            broj_k++;
            if(tok.peek() == '\n' || tok.peek() == EOF) {
            	if(broj_r == 0) {
            		pomocni = broj_k;
            	} else if(pomocni != broj_k) throw std::logic_error("Datoteka sadrzi besmislene podatke"); 
            	broj_r++;
            	broj_k = 0;
            	continue;
            }
            tok >> znak;
            if(znak != ',' || tok.peek() == '\n') throw std::logic_error("Datoteka sadrzi besmislene podatke");
        }
        if(tok.eof());
        else if(tok.bad()) throw std::logic_error("Problemi pri citanju datoteke");
        else throw std::logic_error("Datoteka sadrzi besmislene podatke");
        tok.clear();
	br_kolona = pomocni;
    br_redova = broj_r;
	elementi = new TipEl*[br_redova];
	for(int i = 0;  i < br_redova; i++) elementi[i] = new TipEl[br_kolona];
	tok.seekg(0, std::ios::beg);
	for(int i = 0; i < br_redova; i++) {
		for(int j = 0; j < br_kolona; j++) {
			tok >> elementi[i][j]; tok.get(znak);
            if(!tok) break;
			}
		}
    }
}

template<typename TipEl>
void Matrica<TipEl>::ObnoviIzBinarneDatoteke(const std::string &ime_datoteke)
{
    std::ifstream tok(ime_datoteke, std::ios::binary);
    if(!tok) throw std::logic_error("Trazena datoteka ne postoji");
    for(int i = 0; i < br_redova; i++) delete[] elementi[i];
    delete[] elementi;
    tok.read(reinterpret_cast<char*> (this), sizeof(*this));
    elementi = new TipEl*[br_redova] {};
    for(int i = 0; i < br_redova; i++) {
        elementi[i] = new TipEl[br_kolona];
        tok.read(reinterpret_cast<char*> (elementi[i]), sizeof(TipEl) * br_kolona);
    }
    if(!tok) {
     for(int i = 0; i < br_redova; i++) delete[] elementi[i];
     delete[] elementi;
     throw std::logic_error("Datoteka sadrzi besmislene podatke");
    }

}

template<typename TipEl>
void Matrica<TipEl>::SacuvajUBinarnuDatoteku(const std::string &ime_datoteke) const
{
    std::ofstream tok(ime_datoteke, std::ios::binary);
    tok.write(reinterpret_cast<const char*> (this), sizeof(*this));
    if(!tok) throw std::logic_error("Problemi sa upisom u datoteku");
    for(int i = 0; i < br_redova; i++) {
        tok.write(reinterpret_cast<char*> (elementi[i]), sizeof (TipEl) * br_kolona);
        if(!tok) throw std::logic_error("Problemi sa upisom u datoteku");
    }
}


template<typename TipEl>
void Matrica<TipEl>::SacuvajUTekstualnuDatoteku(const std::string &ime_datoteke) const
{
    std::ofstream tok(ime_datoteke);
    for(int i = 0; i < br_redova; i++) {
        
        for(int j = 0; j < br_kolona; j++) {
            if(j != br_kolona - 1) tok << elementi[i][j] << ",";
            else tok << elementi[i][j] << std::endl;
            if(!tok) throw std::logic_error("Problemi sa upisom u datoteku");
        }
    }
    
}
template<typename TipEl>
void Matrica<TipEl>::ObnoviIzTekstualneDatoteke(const std::string &ime_datoteke)
{
    std::ifstream tok(ime_datoteke);
    if(!tok) throw std::logic_error("Trazena datoteka ne postoji");
    int broj_r(0), broj_k(0), pomocni(0);
    TipEl elem;
    char znak = ',';
        while(tok) {
            tok >> elem; 
            if(!tok) break;
            broj_k++;
            if(tok.peek() == '\n' || tok.peek() == EOF) {
            	if(broj_r == 0) {
            		pomocni = broj_k;
            	} else if(pomocni != broj_k) throw std::logic_error("Datoteka sadrzi besmislene podatke"); 
            	broj_r++;
            	broj_k = 0;
            	continue;
            }
            tok >> znak;
            if(!tok) break;
            if(znak != ',' || tok.peek() == '\n') throw std::logic_error("Datoteka sadrzi besmislene podatke");
        }
        if(tok.eof());
        else if(tok.bad()) throw std::logic_error("Problemi pri citanju datoteke");
        else throw std::logic_error("Datoteka sadrzi besmislene podatke");
        tok.clear();
    for(int i = 0; i < br_redova; i++) delete[] elementi[i];
	delete[] elementi;
	br_kolona = pomocni;
    br_redova = broj_r;
	elementi = new TipEl*[br_redova];
	for(int i = 0;  i < br_redova; i++) elementi[i] = new TipEl[br_kolona];
	tok.seekg(0, std::ios::beg);
	for(int i = 0; i < br_redova; i++) {
		for(int j = 0; j < br_kolona; j++) {
			tok >> elementi[i][j]; tok.get(znak);
            if(!tok) break;
			}
		}
}

template<typename tip2>
Matrica<tip2>::operator std::string()  const {
		std::string s;
		s.push_back('{');
		for(int i = 0; i < br_redova; i++) {
			s.push_back('{');
			for(int j = 0; j < br_kolona; j++) {
				s += std::to_string(int(elementi[i][j]));
				if(j != br_kolona - 1)
					s+=(',');
			}
			if(i != br_redova-1)
				s+="},";
			 else s.push_back('}');
			
		}
		s.push_back('}');
		return s;
	}

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
template <typename Tip>
Tip* Matrica<Tip>::operator [](int i)
{
	return elementi[i];
}
template <typename Tip>
Tip& Matrica<Tip>::operator ()(int i, int j)
{
	if(!TestIndexa(i,j)) throw std::range_error("Neispravan indeks");
	return elementi[i-1][j-1];
}
template <typename Tip>
Tip Matrica<Tip>::operator ()(int i, int j) const
{
	if(!TestIndexa(i,j)) throw std::range_error("Neispravan indeks");
	return elementi[i-1][j-1];
}
template <typename Tip>
Tip* Matrica<Tip>::operator [](int i) const
{
	return elementi[i];
}

template <typename tip2>
std::istream &operator >> (std::istream &tok, Matrica<tip2> &mat)
{
	for(int i = 0; i < mat.br_redova; i++)
		for(int j = 0; j < mat.br_kolona; j++) {
			std::cout << mat.ime_matrice << "(" << i + 1 << "," << j + 1 << ") = ";
			tok >> mat.elementi[i][j];
		}
		return tok;
}

template <typename tip2>
std::ostream &operator << (std::ostream &tok, Matrica<tip2> &mat)
{
	int w = tok.width();
	for(int i = 0; i < mat.br_redova; i++) {
		for(int j = 0; j < mat.br_kolona; j++)
			tok << std::setw(w) << mat.elementi[i][j];
		tok << std::endl;
	}
	return tok;
}

template <typename tip2>
Matrica<tip2> operator +(const Matrica<tip2> &m1, const Matrica<tip2> &m2)
{
	if(m1.br_redova != m2.br_redova || m1.br_kolona != m2.br_kolona) throw std::domain_error("Matrice nemaju jednake dimenzije!");
	Matrica<tip2> m3(m1.br_redova, m1.br_kolona);
	for(int i = 0; i < m1.br_redova; i++)
		for(int j = 0; j < m1.br_kolona; j++)
			m3.elementi[i][j] = m1.elementi[i][j] + m2.elementi[i][j];
	return m3;
}

template <typename tip2>
Matrica<tip2> operator -(Matrica<tip2> &mat) 
{
	for(int i = 0; i < mat.br_redova; i++) {
		for(int j = 0; j < mat.br_kolona; j++)
			mat.elementi[i][j] = - mat.elementi[i][j];
	}
	return mat;
}

template <typename tip2>
Matrica<tip2> operator -(const Matrica<tip2> &m1,const Matrica<tip2> &m2)
{
	if(m1.br_redova != m2.br_redova || m1.br_kolona != m2.br_kolona) throw std::domain_error("Matrice nemaju jednake dimenzije!");
	Matrica<tip2> m3(m1.br_redova, m1.br_kolona);
	for(int i = 0; i < m1.br_redova; i++)
		for(int j = 0; j < m1.br_kolona; j++)
			m3.elementi[i][j] = m1.elementi[i][j] - m2.elementi[i][j];
	return m3;
}

template <typename tip2>
Matrica<tip2> operator *(Matrica<tip2> &mat, double broj)
{
		Matrica<tip2> m3(mat.br_redova, mat.br_kolona);
	for(int i = 0; i < mat.br_redova; i++) {
		for(int j = 0; j < mat.br_kolona; j++)
			m3.elementi[i][j] = mat.elementi[i][j] * broj;
	}
	return m3;
}

template <typename tip2>
Matrica<tip2> operator *(double broj, Matrica<tip2> &mat)
{
		Matrica<tip2> m3(mat.br_redova, mat.br_kolona);
	for(int i = 0; i < mat.br_redova; i++) {
		for(int j = 0; j < mat.br_kolona; j++)
			m3.elementi[i][j] = mat.elementi[i][j] * broj;
	}
	return m3;
}


template <typename tip2>
Matrica<tip2> operator *(const Matrica<tip2> &m1,const Matrica<tip2> &m2)
{
	if(m1.br_kolona != m2.br_redova) throw std::domain_error("Matrice nisu saglasne za mnozenje");
	Matrica<tip2> m3(m1.br_redova, m2.br_kolona);
	for(int i = 0; i < m1.br_redova; i++) {
		for(int j = 0; j < m2.br_kolona; j++) {
			m3.elementi[i][j] = 0;
			for(int k = 0; k < m2.br_redova; k++) {
				m3.elementi[i][j] += m1.elementi[i][k] * m2.elementi[k][j];
			}
		}
	}
	return m3;
}

int main()
{
	int m,n;
  std::cout << "Unesi broj redova i kolona za matrice:\n";
  std::cin >> m >> n;
  try {
	  Matrica<double> a(m, n, 'A');/*, b(m, n, 'B');
	    std::cout << "Unesi matricu :\n";
	    std::cin >> a;
	    a.SacuvajUTekstualnuDatoteku("aki.txt"); 
	    a.SacuvajUBinarnuDatoteku("aki.dat");
	    b.ObnoviIzBinarneDatoteke("aki.dat");
	    std::cout << std::setw(4) << b;
	    Matrica<double> c("aki.dat", true);
	    std::cout << c ;*/
	    a.ObnoviIzTekstualneDatoteke("aki.txt");
	    std::cout << std::setw(4) << a;
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
	return 0;
}


