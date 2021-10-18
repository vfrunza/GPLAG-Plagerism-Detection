#include <iostream>
#include <stdexcept>
#include <vector>
#include <initializer_list>
#include <iomanip>

template <typename TipElementa>
    class GMatrica{
        TipElementa matrica[4][4];
        int brojRedova, brojKolona;
        void BaciIzuzetak(){
            throw std::logic_error("Ilegalan format matrice");
        }
    public:
        //Konstruktori
        GMatrica();
        GMatrica(int brojRedova, int brojKolona, TipElementa initVr={});
        template <typename DrugiTipElemenata>
            GMatrica(GMatrica<DrugiTipElemenata> drugacijaMat);
        GMatrica(TipElementa novaMatrica[4][4]);
        GMatrica(std::vector<std::vector<TipElementa>> vektor);
        GMatrica(std::initializer_list<std::initializer_list<TipElementa>> lista);
        
        //Getteri
        int DajBrojRedova() const{
            return brojRedova;
        }
        int DajBrojKolona() const{
            return brojKolona;
        }
        void Ispisi() const{
        for (int i = 0; i < DajBrojRedova(); i++) {
    for (int j = 0; j < DajBrojRedova(); j++) {
        std::cout << matrica[i][j] << " ";
    }
    std::cout << std::endl;
}
    } //Obrisati
        
        template <typename tipPrvog, typename tipDrugog>
            friend auto operator+ (const GMatrica<tipPrvog> &m1, const GMatrica<tipDrugog> &m2) -> decltype (GMatrica<decltype(m1.matrica[0][0] + m2.matrica[0][0])>
            (m1.DajBrojRedova(), m1.DajBrojKolona(), m1.matrica[0][0] + m2.matrica[0][0]));
    	template <typename tipPrvog, typename tipDrugog>
            friend auto operator- (const GMatrica<tipPrvog> &m1, const GMatrica<tipDrugog> &m2) -> decltype (GMatrica<decltype(m1.matrica[0][0] - m2.matrica[0][0])>
            (m1.DajBrojRedova(), m1.DajBrojKolona(), m1.matrica[0][0] - m2.matrica[0][0]));
    	
    	template <typename tipPrvog, typename tipDrugog>
            friend auto operator* (const GMatrica<tipPrvog> &m1, const GMatrica<tipDrugog> &m2) -> decltype (GMatrica<decltype(m1.matrica[0][0] * m2.matrica[0][0])>
            (m1.DajBrojRedova(), m1.DajBrojKolona(), m1.matrica[0][0] * m2.matrica[0][0]));
        
        template <typename tipPrvog, typename tipDrugog>
            friend GMatrica<tipPrvog> operator* (const GMatrica<tipPrvog> &m1, tipDrugog a);
            
        template <typename tipPrvog, typename tipDrugog>
            friend GMatrica<tipPrvog> operator* (tipDrugog a, const GMatrica<tipPrvog> &m1);
    	
    	
    	GMatrica<TipElementa> &operator += (const GMatrica<TipElementa> &m2);
    	    
        GMatrica<TipElementa> &operator -= (const GMatrica<TipElementa> &m1);
    	
    	GMatrica<TipElementa> &operator *= (const GMatrica<TipElementa> &m1);   
    	
        GMatrica &operator *= (TipElementa a);
        
        template <typename tipDrugog>
        bool operator ==(const GMatrica<tipDrugog> &m1){
            if (brojRedova != m1.brojRedova || brojKolona != m1.DajBrojKolona()) return false;
            for (int i = 0; i < brojRedova; i++) for (int j = 0; j < brojKolona; j++) if (matrica[i][j] != m1.matrica[i][j]) return false;
            return true;
        }
        
        template <typename tipDrugog>
        bool operator != (const GMatrica<tipDrugog> &m1){
            if (!(*this == m1)) return true; 
            return false;
        }
      
        
        TipElementa*  operator [](int i) {
            return matrica[i];
        }
        
        TipElementa &operator () (int i, int j){
            if (!(i>0 && i < brojKolona && j > 0 && j < brojKolona)) throw std::range_error ("Nedozvoljen indeks");
            return matrica[i-1][j-1];
        }
        TipElementa operator () (int i, int j) const{
            if (!(i>0 && i < brojKolona && j > 0 && j < brojKolona)) throw std::range_error ("Nedozvoljen indeks");
            return matrica[i-1][j-1];
        }
        
        friend std::istream &operator >> (std::istream &tok, GMatrica<TipElementa> &a){
            if (tok.peek() == '['){
                std::vector<std::vector<TipElementa>> matrica(4);
                int i(0); bool timeToGo(false);
                char znak; tok >> znak;
                while(!timeToGo){
                    int n; tok >> n;
                    if(tok) matrica[i].push_back(n);
                    else{ tok.setstate(std::ios::failbit); return tok;}
                    if (tok.peek() == ',') tok>> znak;
                    else if (tok.peek() == ';'){ tok>>znak; i++;}
                    else if (tok.peek() == ']'){ timeToGo = true; break;}
                    else{ tok.setstate(std::ios::failbit); return tok;}
                }
                matrica.resize(i+1);
                
                a = GMatrica(matrica);
                return tok;
            }
            
            tok.setstate(std::ios::failbit);
            return tok;
        } 
        friend std::ostream &operator << (std::ostream &tok, GMatrica<TipElementa> a){
            int sirina(tok.width()); if (sirina < 6) sirina = 6;
            
            for (int i = 0; i < a.DajBrojRedova(); i++) {
                for (int j = 0; j < a.DajBrojKolona(); j++) std::cout << std::setw(sirina) << a.matrica[i][j];
                std::cout << std::endl;    
            }   
            return tok;
        }
    };

template <typename TipElementa>
    GMatrica<TipElementa>::GMatrica()  : brojRedova(0), brojKolona(0){}
    
template <typename TipElementa>
    GMatrica<TipElementa>::GMatrica(int brojRedova, int brojKolona, TipElementa initVr) : brojRedova(brojRedova), brojKolona(brojKolona){
        if (!(brojKolona >= 0 && brojKolona <= 4 && brojRedova >= 0 && brojRedova <= 4)) BaciIzuzetak();
        
        for (int i = 0; i < brojRedova; i++) for (int j = 0; j < brojKolona; j++) matrica[i][j] = initVr; 
    }

template <typename TipElementa>
    template <typename DrugiTipElemenata>
        GMatrica<TipElementa>::GMatrica (GMatrica<DrugiTipElemenata> drugacijaMat) : brojRedova(drugacijaMat.brojRedova), brojKolona(drugacijaMat.brojKolona) {
            for (int i = 0; i < brojRedova; i++) for (int j = 0; j < brojKolona; j++) matrica[i][j] = drugacijaMat[i][j]; 
        }
        
template <typename TipElementa>
    GMatrica<TipElementa>::GMatrica(TipElementa novaMatrica[4][4]): brojRedova(4), brojKolona(4){
        for (int i = 0; i < brojRedova; i++) for (int j = 0; j < brojKolona; j++) matrica[i][j] = novaMatrica[i][j]; 
    }

template <typename TipElementa>
    GMatrica<TipElementa>::GMatrica(std::vector<std::vector<TipElementa>> vektor){
        
        if (vektor.size() < 0 || vektor.size() > 4) BaciIzuzetak();
        int a(vektor[0].size()); if (a < 0 || a > 4) BaciIzuzetak();
        
        
        int i;
        for (i = 1; i < vektor.size(); i++) {
            if (vektor[i].size() != a){break;}
            else if (vektor[i].size() < 0 || vektor[i].size() > 4) BaciIzuzetak();
        }
       
        if (i < vektor.size()) BaciIzuzetak();
        
        brojRedova = vektor.size();
        brojKolona = a;
        for (int i = 0; i < vektor.size(); i++) for (int j = 0; j < a; j++) matrica[i][j]= vektor[i][j];
        
    }
template <typename TipElementa>    
    GMatrica<TipElementa>::GMatrica(std::initializer_list<std::initializer_list<TipElementa>> lista){
        int brojac1(0), brojac2(0), prosli(-5);
        for (auto i : lista) {
            brojac2 = 0;
            for (auto j : i) {
                brojac2++;
            }
            if (prosli == -5){}
            else if (brojac2 != prosli || brojac2 > 4) BaciIzuzetak();
            brojac1++;
            prosli = brojac2;
        }
        if (brojac1 > 4) BaciIzuzetak();
        
        brojRedova = brojac1;
        brojKolona = brojac2;
        int a(0), b(0);
        for (auto i : lista) {
            for (auto j : i) matrica[a][b++] = j;
            a++;
            b=0;
        }
    }

template <typename tipPrvog, typename tipDrugog>
    auto operator+ (const GMatrica<tipPrvog> &m1, const GMatrica<tipDrugog> &m2) -> decltype (GMatrica<decltype(m1.matrica[0][0] + m2.matrica[0][0])>
    (m1.DajBrojRedova(), m1.DajBrojKolona(), m1.matrica[0][0] + m2.matrica[0][0])){

        if(m1.brojRedova != m2.brojRedova || m1.brojKolona != m2.brojKolona)	throw std::domain_error("Nedozvoljena operacija");
        GMatrica<decltype(m1.matrica[0][0] + m2.matrica[0][0])> m3(m1.DajBrojRedova(), m1.DajBrojKolona());
        for (int i = 0; i < m1.brojRedova; i++)	for(int j = 0; j < m1.brojKolona; j++)	m3.matrica[i][j] = m1.matrica[i][j] + m2.matrica[i][j];
        		return m3;
    }
    
template <typename tipPrvog, typename tipDrugog>
    auto operator- (const GMatrica<tipPrvog> &m1, const GMatrica<tipDrugog> &m2) -> decltype (GMatrica<decltype(m1.matrica[0][0] - m2.matrica[0][0])>
    (m1.DajBrojRedova(), m1.DajBrojKolona(), m1.matrica[0][0] - m2.matrica[0][0])){
        
        if(m1.brojRedova != m2.brojRedova || m1.brojKolona != m2.brojKolona)	throw std::domain_error("Matrice nemaju jednake dimenzije!");
        GMatrica<decltype(m1.matrica[0][0] - m2.matrica[0][0])> m3(m1.DajBrojRedova(), m1.DajBrojKolona());
        for(int i = 0; i < m1.brojRedova; i++)	for(int j = 0; j < m1.brojKolona; j++) m3.matrica[i][j] = m1.matrica[i][j] - m2.matrica[i][j];
        return m3;
    }
    	
template <typename tipPrvog, typename tipDrugog>
    auto operator* (const GMatrica<tipPrvog> &m1, const GMatrica<tipDrugog> &m2) -> decltype (GMatrica<decltype(m1.matrica[0][0] * m2.matrica[0][0])>
    (m1.DajBrojRedova(), m1.DajBrojKolona(), m1.matrica[0][0] * m2.matrica[0][0])){
    
    	if (m1.DajBrojKolona() != m2.DajBrojRedova()) throw std::domain_error ("Nedozvoljena operacija");
        GMatrica<decltype(m1.matrica[0][0] * m2.matrica[0][0])> m3(m1.DajBrojRedova(), m1.DajBrojKolona());
    	for(int i = 0; i < m1.brojRedova; i++)
    		for(int j = 0; j < m2.brojKolona; j++){
    		    decltype(m1.matrica[0][0] * m2.matrica[0][0]) suma{}; 
    		    for (int k = 0; k < m2.DajBrojRedova(); k++) suma += m1.matrica[i][k] * m2.matrica[k][j];
    			    m3.matrica[i][j] = suma;
    			}
    				
    	return m3;
    }

template <typename tipPrvog, typename tipDrugog>
    GMatrica<tipPrvog> operator* (const GMatrica<tipPrvog> &m1, tipDrugog a){
        GMatrica<tipPrvog> m3(m1.DajBrojRedova(), m1.DajBrojKolona());
    	for(int i = 0; i < m1.brojRedova; i++)
    		for(int j = 0; j < m1.brojKolona; j++)
    		    m3.matrica[i][j] = m1.matrica[i][j] * a; 
    				
    	return m3;
    }

template <typename tipPrvog, typename tipDrugog>
    GMatrica<tipPrvog> operator* (tipDrugog a, const GMatrica<tipPrvog> &m1){
        return m1 * a;
    }  

template <typename smrt>
GMatrica<smrt> &GMatrica<smrt>::operator+= (const GMatrica<smrt> &m2){
    	        
                //Testira ako se mogu sabrati. Ako bude ikakav problem bacit ce se izuzetak
            	try{
            	    auto m3 = *this + m2;
            	}
            	catch (...){ throw;}
            	       
            	for (int i = 0; i < DajBrojRedova(); i++) for (int j = 0; j < DajBrojKolona(); j++) matrica[i][j] += m2.matrica[i][j];
            	           
            	return *this;
    	    }

template <typename smrt>
GMatrica<smrt> &GMatrica<smrt>::operator -= (const GMatrica<smrt> &m2){
        //Testira ako se mogu sabrati. Ako bude ikakav problem bacit ce se izuzetak
    	try{
    	auto m3 = *this - m2;
    	}
    	catch (...){ throw;}
    	       
    	for (int i = 0; i < DajBrojRedova(); i++) for (int j = 0; j < DajBrojKolona(); j++) matrica[i][j] -= m2.matrica[i][j];
    	           
    	return *this;
}

template <typename smrt>
GMatrica<smrt> &GMatrica<smrt>::operator *= (const GMatrica<smrt> &m2){
        //Testira ako se mogu sabrati. Ako bude ikakav problem bacit ce se izuzetak
    	try{
    	auto m3 = *this * m2;
    	}
    	catch (...){ throw;}
    	       
    	for (int i = 0; i < DajBrojRedova(); i++) for (int j = 0; j < DajBrojKolona(); j++) matrica[i][j] *= m2.matrica[i][j];
    	           
    	return *this;
}

template <typename TipElementa>
GMatrica<TipElementa> &GMatrica<TipElementa>::operator *= (TipElementa a){
        //Testira ako se mogu sabrati. Ako bude ikakav problem bacit ce se izuzetak
    	try{
    	auto m3 = *this * a;
    	}
    	catch (...){ throw;}
    	       
    	for (int i = 0; i < DajBrojRedova(); i++) for (int j = 0; j < DajBrojKolona(); j++) matrica[i][j] *= a;
    	           
    	return *this;
}

int main (){
    
    //operatori {} i []
   
   GMatrica<int> m1({{1, 2}, {3, 4}});
   std::cout << m1(1,1) << std::endl;
   std::cout << m1[1][1] << std::endl;
    
	return 0;
}