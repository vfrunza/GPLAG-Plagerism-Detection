#include <iomanip>
#include <cstring>
#include <stdexcept>
#include <new>
#include <sstream>
#include <string>
#include <fstream>
#include <iostream>
#include <sstream>
#include <vector>


template <typename TipElementa>
class Matrica {
	int broj_redova, broj_kolona;
	TipElementa **elementi;
	char ime_mat;
	static TipElementa **AlocirajMemoriju (int broj_redova, int broj_kolona);
	static void DealocirajMemoriju (TipElementa **elementi, int broj_redova);
	void KopirajElemente (TipElementa **elementi);
public:
	Matrica (int broj_redova, int broj_kolona, char ime = 0);
	Matrica (const Matrica &m);
	Matrica(Matrica &&m);
	~Matrica() { DealocirajMemoriju(elementi, broj_redova); }
	Matrica &operator = (const Matrica &m);
	Matrica &operator = (Matrica &&m);
	template <typename Tip1> 
	friend std::istream &operator>>(std::istream &tok, Matrica <Tip1> &m);
	template <typename Tip2>
	friend std::ostream &operator<< (std::ostream &tok, const Matrica <Tip2> &m);
	template <typename Tip3>
	friend Matrica <Tip3> operator+ (const Matrica <Tip3> &m1, const Matrica <Tip3> &m2);
	Matrica &operator += (const Matrica &m);
	template <typename Tip4>
	friend Matrica <Tip4> operator- (const Matrica <Tip4> &m1, const Matrica <Tip4> &m2);
	Matrica &operator -= (const Matrica &m);
	template <typename Tip5>
	friend Matrica <Tip5> operator * (const Matrica <Tip5> &m1, const Matrica <Tip5> &m2);
	Matrica &operator *= (const Matrica &m);
	template <typename Tip6>
	friend Matrica <Tip6> operator*(const Matrica <Tip6> &m, double br);
	Matrica &operator *=(double br);
	template <typename Tip7>
	friend Matrica <Tip7> operator*(double br, const Matrica <Tip7> &m);
	operator std::string()const;
	
	TipElementa &operator() (int a, int b) {
		if (a<1 || b<1 || a>broj_redova || b>broj_kolona) throw std::range_error("Neispravan indeks");
		return elementi[a-1][b-1];
	}
	TipElementa operator() (int a, int b) const {
		if (a<1 || b<1 || a>broj_redova || b>broj_kolona) throw std::range_error("Neispravan indeks");
		return elementi[a-1][b-1];
	}
	TipElementa *operator [](int a) {
		if (a<0) throw std::range_error ("Neispravan indeks");
		return elementi[a];
	}
	const TipElementa *operator [](int a) const {
		if (a<0) throw std::range_error ("Neispravan indeks");
		return elementi[a];
	}
	
	
	void SacuvajUTekstualnuDatoteku (const char ime_datoteke[]) {
	    
	    std::ofstream izlazni_tok(ime_datoteke);
        if(!izlazni_tok) throw std::logic_error ("Problemi sa upisom u datoteku\n");
        else {
         
            for( int i=0;i < broj_redova;i++) {
                
                for( int j=0;j < broj_kolona;j++) {
                    
                    izlazni_tok << elementi[i][j] ;
                    if(!izlazni_tok) throw std::logic_error ("Problemi sa upisom u datoteku\n");
                    
                    //std::cout << elementi[i][j];
                    if(j < broj_kolona-1) {
                        
                        izlazni_tok << ",";
                        if(!izlazni_tok) throw std::logic_error ("Problemi sa upisom u datoteku\n");
                        //std::cout<< ",";
                    }
                }
                izlazni_tok <<std::endl;
                if(!izlazni_tok) throw std::logic_error ("Problemi sa upisom u datoteku\n");
                //std::cout <<std::endl;
            } 
          
       
        }
	    
	}
	
	
	void SacuvajUBinarnuDatoteku ( const char ime_datoteke[]) {
		 
 		std::ofstream izlazni_tok(ime_datoteke, std::ios::binary);
 		 if(!izlazni_tok) throw std::logic_error ("Problemi sa upisom u datoteku\n");
 		
 		izlazni_tok.write(reinterpret_cast<const char*>(this), sizeof *this);
 		for(int i = 0; i < broj_redova; i++)
 			izlazni_tok.write(reinterpret_cast<char*>(elementi[i]), sizeof(TipElementa));
 		if(!izlazni_tok)  throw std::logic_error ("Problemi sa upisom u datoteku\n");

	}
	
	void ObnoviIzBinarneDatoteke (const char ime_datoteke[]) {
	
		ObnoviIzBinDatoteke(ime_datoteke,true);
		
		
	}
	
	
	void ObnoviIzTekstualneDatoteke (const char ime_datoteke[]) {
	
		ObnoviIzTextDatoteke(ime_datoteke,true);
		
		
	}
	
		/*std::string replaceChar(std::string str, char ch1,char ch2) {
  for (int i = 0; i < str.length(); ++i) {
    if (str[i] == ch1){
      str[i] = ch2;
    }
  }

  return str;
}*/
	


	
	/*std::vector<std::vector<TipElementa>>*/ void ObnoviIzTextDatoteke(const char ime_datoteke[], bool t) {
		
	std::ifstream ulazni_tok(ime_datoteke);
	
	if(!ulazni_tok) throw std::logic_error ("Trazena datoteka ne postoji");
	std::string s;
	std::string s1;
	int i(0);
	int j(0);
	while(std::getline(ulazni_tok,s)){
		
		if( i == 0 ) {
			
			s1 = s;
			
		}
		i++;
	}
	
	
	if(ulazni_tok.eof());
	else if (ulazni_tok.bad()) throw std::logic_error ("Datoteka je vjerovatno ostecena!\n");
	else {
		
		throw std::logic_error ("Datoteka sadrzi besmislene podatke");
		
		
	}
	
	for ( int k=0;k<s1.size();k++){
		if(s1.at(k)==',') {
			j++;
		}
	}
	
	std::vector<std::vector<TipElementa>> vek(i);
	for( int k1=0;k1<i;k1++) {
		vek.at(k1).resize(j+1);
	}
	ulazni_tok.close();
	ulazni_tok.open(ime_datoteke);
	
	for( int ii=0;ii<i;ii++) {
		
		for(int jj=0;jj<j+1;jj++){
			char cc;
			TipElementa znak;
			ulazni_tok >> znak;
			
			if(jj!=j) {
				ulazni_tok>>cc;
			}
			vek[ii][jj] = znak;
		}
	}
	
	/*if(ulazni_tok.eof());
	 if(ulazni_tok.bad()) throw std::logic_error("Datoteka je vjerovatno ostecena!\n");
	else throw std::logic_error("Datoteka sadrzi besmislene podatke");*/
	


	
	
//	return vek;
	
	
	}


		

	void ObnoviIzBinDatoteke (const char ime_datoteke[], bool del) {


		std::ifstream ulazni_tok(ime_datoteke, std::ios::binary);
 		if(!ulazni_tok) throw std::logic_error("Trazena datoteka ne postoji\n");
 		
 	
 		
 		if (del) {
 			for(int i = 0; i < broj_redova; i++) delete elementi[i];
 			delete[] elementi;
 		}


 		ulazni_tok.read(reinterpret_cast<char*>(this), sizeof (*this));
 		
 		elementi = new TipElementa*[broj_redova];
 		
 		for(int i = 0; i < broj_redova; i++) elementi[i] = nullptr;
 		for(int i = 0; i < broj_redova; i++) {
 			elementi[i] = new TipElementa();
 			ulazni_tok.read(reinterpret_cast<char*>(elementi[i]), broj_redova*sizeof(TipElementa));

 			
 		}
 	
 		/*if(!ulazni_tok) {
 			for(int i = 0; i < broj_redova; i++) delete elementi[i];
 			delete[] elementi;
 			throw std::logic_error("Problemi pri citanju datoteke!");
 		}*/
 		
 	

	
		
	}
	
	
	void Dario (int x , int y , TipElementa z) {
		
		
		elementi[x][y] = z ; 
		
		
		
		
	}
	
	Matrica (const char ime_datoteke[], bool T) {
		
		
		if( T ) {
			
			ObnoviIzBinDatoteke(ime_datoteke,false);
			
		} else {
			
			ObnoviIzTextDatoteke(ime_datoteke,false);
			
		}
		
		
	}
	

	
	
	
	
	
	
	
	
	
	
};
template <typename TipElementa>
Matrica <TipElementa>::operator std::string() const {
	std::string s;
	for (int i = 0; i < broj_redova; i++) {
		if (i==0) s.push_back('{');
		for (int j=0; j<broj_kolona; j++) {
			if (j==0) {
				s.push_back('{');
				s+=std::to_string((int)elementi[i][j]);
				s.push_back(',');
			}
			else if (j==broj_kolona-1) {
				s+=std::to_string((int)elementi[i][j]);
				s.push_back('}');
				if (i !=broj_redova-1) s.push_back(',');
			}
			else {
				s.push_back(',');
				s+=std::to_string((int)elementi[i][j]);
			}
		}
		if (i==broj_redova-1) s.push_back('}');
	}
	return s;
}
template <typename TipElementa>
TipElementa **Matrica <TipElementa>::AlocirajMemoriju(int broj_redova, int broj_kolona) {
	TipElementa **elementi (new TipElementa*[broj_redova]{});
	try {
		for (int i=0; i<broj_redova; i++) elementi[i] = new TipElementa[broj_kolona];
	}
	catch(...) {
		DealocirajMemoriju(elementi, broj_redova);
		throw;
	}
	return elementi;
}
template <typename TipElementa>
void Matrica <TipElementa>::DealocirajMemoriju(TipElementa **elementi, int broj_redova) {
	for (int i=0; i<broj_redova; i++) delete[] elementi[i];
	delete[] elementi;
}
template <typename TipElementa>
Matrica <TipElementa>::Matrica(int broj_redova, int broj_kolona, char ime):
broj_redova(broj_redova), broj_kolona(broj_kolona),ime_mat(ime), elementi(AlocirajMemoriju(broj_redova,broj_kolona)) {}
template <typename TipElementa>
void Matrica <TipElementa>::KopirajElemente(TipElementa **elementi) {
	for(int i=0; i<broj_redova; i++)
		for (int j=0; j<broj_kolona; j++)
		Matrica::elementi[i][j] = elementi[i][j];
}
template <typename TipElementa>
Matrica <TipElementa>::Matrica(const Matrica<TipElementa> &m): broj_redova(m.broj_redova), broj_kolona(m.broj_kolona), ime_mat(m.ime_mat),elementi(AlocirajMemoriju(m.broj_redova,m.broj_kolona)) {
	KopirajElemente(m.elementi);
}
template <typename TipElementa>
Matrica<TipElementa>::Matrica(Matrica<TipElementa> &&m): broj_redova(m.broj_redova), broj_kolona(m.broj_kolona), elementi(m.elementi), ime_mat(m.ime_mat) {
	m.broj_redova = 0;
	m.elementi = nullptr;
}
template <typename TipElementa>
Matrica <TipElementa> &Matrica<TipElementa>::operator =(const Matrica<TipElementa> &m) {
	if (broj_redova <m.broj_redova || broj_kolona<m.broj_kolona) {
		TipElementa **novi_prostor(AlocirajMemoriju(m.broj_redova, m.broj_kolona));
		DealocirajMemoriju(elementi,broj_redova);
		elementi = novi_prostor;
	}
	else if (broj_redova > m.broj_redova)
		for (int i=0; i<broj_redova; i++) delete elementi[i];
		broj_redova = m.broj_redova;
		broj_kolona = m.broj_kolona;
		ime_mat = m.ime_mat;
		KopirajElemente(m.elementi);
		return *this;
}
template <typename TipElementa>
Matrica<TipElementa> &Matrica<TipElementa>::operator = (Matrica<TipElementa> &&m) {
	std::swap (broj_redova, m.broj_redova);
	std::swap(broj_kolona, m.broj_kolona);
	std::swap(ime_mat, m.ime_mat);
	std::swap(elementi, m.elementi);
	return *this;
}
template <typename TipElementa>
std::istream &operator >> (std::istream &tok, Matrica <TipElementa> &m) {
	for (int i=0; i<m.broj_redova; i++)
		for (int j=0; j<m.broj_kolona; j++) {
			std::cout << m.ime_mat<<"("<<i+1<<","<<j+1<<") = ";
			tok>>m.elementi[i][j];
		}
		return tok;
}
template <typename TipElementa>
std::ostream &operator <<(std::ostream &tok, const Matrica <TipElementa> &m) {
	int sirina_ispisa (tok.width());
	for (int i = 0; i < m.broj_redova; i++) {
		for (int j=0; j<m.broj_kolona; j++) tok<<std::setw(sirina_ispisa)<<m.elementi[i][j];
		tok<<std::endl;
	}
	return tok;
}
template <typename TipElementa>
Matrica <TipElementa> operator + (const Matrica<TipElementa> &m1, const Matrica <TipElementa> &m2) {
	if (m1.broj_redova != m2.broj_redova || m1.broj_kolona != m2.broj_kolona) throw std::domain_error ("Matrice nemaju jednake dimenzije!");
	Matrica<TipElementa> m3(m1.broj_redova, m2.broj_kolona);
	for (int i=0; i<m1.broj_redova; i++)
		for (int j=0; j<m1.broj_kolona; j++)
			m3.elementi[i][j] = m1.elementi[i][j] + m2.elementi[i][j];
	return m3;
}
template <typename TipElementa>
Matrica<TipElementa> &Matrica<TipElementa>::operator -=(const Matrica<TipElementa> &m) {
	if (broj_redova != m.broj_redova || broj_kolona != m.broj_kolona) throw std::domain_error ("Matrice nemaju jednake dimenzije!");
	for (int i=0; i<broj_redova; i++)
		for (int j=0; j<broj_kolona; j++)
			elementi[i][j] = elementi[i][j]-m.elementi[i][j];
	return *this;
}
template <typename TipElementa>
Matrica<TipElementa> operator - (const Matrica<TipElementa> &m1, const Matrica<TipElementa> &m2) {
	Matrica<TipElementa> m3(m1);
	m3-=m2;
	return m3;
}
template <typename TipElementa>
Matrica<TipElementa> &Matrica<TipElementa>::operator *=(const Matrica<TipElementa> &m) {
	*this = *this * m;
	return *this;
}
template <typename TipElementa>
Matrica <TipElementa> operator * (const Matrica<TipElementa> &m1, const Matrica<TipElementa> &m2) {
	if (m1.broj_kolona != m2.broj_redova) throw std::domain_error("Matrice nisu saglasne za mnozenje");
	Matrica<TipElementa> m3 (m1.broj_redova, m2.broj_kolona);
	for (int i=0; i<m1.broj_redova; i++)
		for (int j=0; j< m2.broj_kolona; j++) {
			double suma(0);
			for (int k=0; k<m2.broj_redova; k++) suma+=m1.elementi[i][k]*m2.elementi[k][j];
			m3.elementi[i][j] = suma;
		}
		return m3;
}
template <typename TipElementa>
Matrica<TipElementa> &Matrica<TipElementa>::operator +=(const Matrica<TipElementa> &m) {
	if (broj_redova != m.broj_redova || broj_kolona != m.broj_kolona)
		throw std::domain_error ("Matrice nemaju jednake dimenzije!");
	for (int i=0; i<broj_redova; i++)
		for (int j=0; j<broj_kolona; j++)
			elementi[i][j] = elementi[i][j] + m.elementi[i][j];
			return *this;
}
template <typename Tip7>
Matrica<Tip7> operator *(const Matrica<Tip7> &m, double br) {
	Matrica<Tip7> mat(m);
	for (int i = 0; i < mat.broj_redova; i++) {
		for (int j=0; j<mat.broj_kolona; j++)
			mat.elementi[i][j] = br*mat.elementi[i][j];
	}
	return mat;
}
template <typename Tip>
Matrica<Tip> &Matrica<Tip>::operator *=(double br) {
	for (int i = 0; i < broj_redova; i++) {
		for (int j=0; j<broj_kolona; j++)
			elementi[i][j] = br*elementi[i][j];
	}
	return *this;
}
template <typename Tip>
Matrica<Tip> operator *(double br, const Matrica<Tip> &m) {
	Matrica<Tip> mat(m);
	for (int i=0; i<mat.broj_redova; i++) {
		for (int j=0; j<mat.broj_kolona; j++)
			mat.elementi[i][j] = br*mat.elementi[i][j];
	}
	return mat;
}
int main ()
{
    
    Matrica<int> m(1,1);
    
    /*
     m.SacuvajUBinarnuDatoteku("TestB0.txt");

     m.Dario(1,1,223);
     m.Dario(2,1,223);
     m.Dario(3,1,223);
    
    m.SacuvajUBinarnuDatoteku("TestB223.txt");

    m.SacuvajUTekstualnuDatoteku("TestT.txt");
    
    
     m.Dario(1,1,10);
     m.Dario(2,1,10);
     m.Dario(3,1,10);
    */
    
    //m.ObnoviIzBinarneDatoteke("TestB223.txt");
    
    //m.SacuvajUTekstualnuDatoteku("TestTNOVA.txt");

    m.ObnoviIzTekstualneDatoteke("TestTNOVA.txt");
    
    m.SacuvajUTekstualnuDatoteku("TestTNOVA2.txt");
   
    
    
	return 0;
}