/B2016/2017: Zadaća 3, Zadatak 3
#include <iostream>
#include <iomanip>
#include <stdexcept>
#include <new>
#include <vector>

template <typename TipElemenata>
    struct Matrica {
        int br_redova, br_kolona;
        TipElemenata **elementi = nullptr;
    };
    
template <typename TipElemenata>
    void UnistiMatricu(Matrica<TipElemenata> mat) {
        if(!mat.elementi) return;
        for(int i=0; i<mat.br_redova; i++) delete[] mat.elementi[i];
        
        delete[] mat.elementi;
        mat.elementi=nullptr;
    }
    
template <typename TipElemenata>
    Matrica<TipElemenata> StvoriMatricu(int br_redova, int br_kolona) {
        Matrica<TipElemenata> mat;
        mat.br_redova = br_redova;
        mat.br_kolona = br_kolona;
        mat.elementi=new TipElemenata*[br_redova];
        for(int i=0; i<br_redova; i++) mat.elementi[i] = nullptr;
        try {
            for(int i=0; i<br_redova; i++) {
                mat.elementi[i] = new TipElemenata[br_kolona];
                
            }
        } 
        catch(...) {
            UnistiMatricu(mat);
            throw;
        }
        return mat;
    }

template <typename TipElemenata>
    void UnesiMatricu(char ime_matrice, Matrica<TipElemenata> &mat) {
        for(int i=0; i<mat.br_redova; i++) {
            for(int j=0; j<mat.br_kolona; j++) {
                std::cout<<ime_matrice<<"("<<i+1<<","<<j+1<<") = ";
                std::cin>>mat.elementi[i][j];
            }
        }
    }
    
template<typename TipElemenata>
    void IspisiMatricu(const Matrica<TipElemenata> &mat, int sirina_ispisa, int preciznost=6, bool treba_brisati=false) {
        for(int i=0; i<mat.br_redova; i++) {
            for(int j=0; j<mat.br_kolona; j++) {
                std::cout<<std::setprecision(preciznost)<<std::setw(sirina_ispisa)<<mat.elementi[i][j];
            }
            std::cout<<std::endl;
        }
        
        if(treba_brisati)
            UnistiMatricu(mat);
    }
    
template<typename TipElemenata>
    Matrica<TipElemenata> ZbirMatrica(const Matrica<TipElemenata> &m1, const Matrica<TipElemenata> &m2) {
        if(m1.br_redova!=m2.br_redova || m1.br_kolona!=m2.br_kolona)
            throw std::domain_error ("Matrice nemaju jednake dimenzije!");
            auto m3(StvoriMatricu<TipElemenata>(m1.br_redova, m1.br_kolona));
            for(int i=0; i<m1.br_redova; i++) {
                for(int j=0; j<m1.br_kolona; j++) {
                    m3.elementi[i][j]=m1.elementi[i][j]+m2.elementi[i][j];
                }
            }
            return m3;
    }
    
template<typename TipElemenata>
    Matrica<TipElemenata> DubokaKopija(const Matrica<TipElemenata> &m) {
        
        auto nova(StvoriMatricu<TipElemenata>(m.br_redova, m.br_kolona));
        for(int i=0; i<m.br_redova; i++) {
            for(int j=0; j<m.br_kolona; j++) {
                nova.elementi[i][j]=m.elementi[i][j];
            }
        }
        return nova;
    }
    
template <typename TipElemenata>
    Matrica<TipElemenata> ProduktMatrica(const Matrica<TipElemenata> &m1, const Matrica<TipElemenata> &m2) {
        if(m1.br_kolona!=m2.br_redova)
            throw std::domain_error ("Matrice nisu saglasne za mnozenje");
            
        auto m3(StvoriMatricu<TipElemenata>(m1.br_redova, m2.br_kolona));
        for(int i=0; i<m1.br_redova; i++) {
            for(int j=0; j<m2.br_kolona; j++) {
                double suma(0);
                for(int k=0; k<m2.br_redova; k++)
                    suma+=m1.elementi[i][k]*m2.elementi[k][j];
                m3.elementi[i][j]=suma;
            }
        }
        
        return m3;
    }

template <typename TipElemenata>
    void ProduktMatriceISkalara(Matrica<TipElemenata> &m, double skalar) {
        
        for(int i=0; i<m.br_redova; i++) {
            for(int j=0; j<m.br_kolona; j++) {
                m.elementi[i][j]*=skalar;
            }
        }
        
    }
    
template <typename TipElemenata>
    void NapraviJedinicnu(Matrica<TipElemenata> &m) {
    
        for(int i=0; i<m.br_redova; i++) {
            for(int j=0; j<m.br_kolona; j++) {
                if(i==j) m.elementi[i][j]=1;
                else m.elementi[i][j]=0;
            }
        }
        
    }
    
template <typename TipElemenata>
    void StepenMatrice(Matrica<TipElemenata> &m, int stepen) {
        auto prva(DubokaKopija(m));
        for(int i=1; i<stepen; i++) {
            auto pom(m);
            m=ProduktMatrica(m,prva);
            if(i==0) continue;
            UnistiMatricu(pom);
        }
        UnistiMatricu(prva);
    }
    
    
template <typename TipElemenata>
    Matrica<TipElemenata> MatricniPolinom(const Matrica<TipElemenata> &A, const std::vector<double> &koeficijenti) {
        if(A.br_kolona!=A.br_redova)
            throw std::domain_error ("Matrica mora biti kvadratna");
        
        auto m(StvoriMatricu<TipElemenata>(A.br_redova, A.br_kolona));
        NapraviJedinicnu(m);
        ProduktMatriceISkalara(m, koeficijenti[0]);
        
        for(int i=1; i<koeficijenti.size(); i++) {
            auto pom(m);
            auto A2(DubokaKopija(A));
            StepenMatrice(A2,i);
            ProduktMatriceISkalara(A2,koeficijenti[i]);

            m=ZbirMatrica(m, A2);
            UnistiMatricu(pom);
            UnistiMatricu(A2);
            
        }
        return m;
    }
    
int main () {
    
    Matrica<double> a;
    int n,red;
    std::cout<<"Unesite dimenziju kvadratne matrice: ";
    std::cin>>n;
   
    try {
        a=StvoriMatricu<double>(n,n);
        std::vector<double> koeficijenti;
        std::cout<<"Unesite elemente matrice A: \n";
        UnesiMatricu('A', a);
        std::cout<<"Unesite red polinoma: ";
        std::cin>>red;
        std::cout<<"Unesite koeficijente polinoma: ";
        for(int i=0; i<=red; i++) {
            double clan;
            std::cin>>clan;
            koeficijenti.push_back(clan);
        }

    IspisiMatricu(MatricniPolinom(a,koeficijenti),10,6,true);
    
  
        
        
    }
    catch(std::bad_alloc) {
        std::cout<<"Nema dovoljno memorije!\n";
    }
    UnistiMatricu(a);

	return 0;
}