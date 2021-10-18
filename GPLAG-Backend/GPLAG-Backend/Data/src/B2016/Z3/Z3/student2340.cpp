/B2016/2017: Zadaća 3, Zadatak 3
#include <iostream>
#include <iomanip>
#include <stdexcept>
#include <new>
#include <vector>

template <typename TipElemenata>
    struct Matrica{
      int br_redova,br_kolona;  
    TipElemenata **elementi=nullptr;
    };

template <typename TipElemenata>
    void UnistiMatricu(Matrica<TipElemenata> mat){
        if(!mat.elementi) return;
        for(int i=0; i<mat.br_redova; i++) delete[] mat.elementi[i];
        delete[] mat.elementi;
        mat.elementi=nullptr;
    }
    
template <typename TipElemenata>
    Matrica<TipElemenata> StvoriMatricu(int br_redova, int br_kolona){
        Matrica<TipElemenata> mat;
        mat.br_redova=br_redova; mat.br_kolona=br_kolona;
        mat.elementi=new TipElemenata*[br_redova];
        for(int i=0; i<br_redova; i++) mat.elementi[i]=nullptr;
        try{
            for(int i=0; i<br_redova;i++)
                mat.elementi[i]=new TipElemenata[br_kolona];
        }
        catch(...){
            UnistiMatricu(mat);
            throw;
        }
        
        return mat;
    }
    
template <typename TipElemenata>
    void UnesiMatricu(char ime_matrice, Matrica<TipElemenata> &mat){
        for(int i=0; i<mat.br_redova; i++)
            for(int j=0; j<mat.br_kolona; j++){
                std::cout<<ime_matrice<<"("<<i+1<<","<<j+1<<") = ";
                    std::cin>>mat.elementi[i][j];
            }
    }

template <typename TipElemenata>
    void IspisiMatricu(Matrica<TipElemenata> &mat, int sirina_ispisa=10,int preciznost=6, bool treba_brisati=false){
        for(int i=0; i<mat.br_redova; i++){
            for(int j=0; j<mat.br_kolona; j++)
                std::cout<<std::setw(sirina_ispisa)<<std::setprecision(preciznost)<<mat.elementi[i][j];
            std::cout<<std::endl;
        }
        
        if(treba_brisati)   UnistiMatricu(mat) ;
    }
 
template <typename TipElemenata>
    Matrica<TipElemenata> ZbirMatrica(const Matrica<TipElemenata> &m1, const Matrica<TipElemenata> &m2){
        if(m1.br_redova != m2.br_redova || m1.br_kolona!=m2.br_kolona)
            throw std::domain_error("Matrice nemaju jednake dimenzije!");
        auto m3(StvoriMatricu<TipElemenata>(m1.br_redova,m1.br_kolona));
        for(int i=0; i<m1.br_redova;i++)
            for(int j=0; j<m1.br_kolona; j++)
            m3.elementi[i][j]=m1.elementi[i][j]+m2.elementi[i][j];
    return m3;
    }
    
template <typename TipElemenata>
    Matrica<TipElemenata> ProduktMatrica(const Matrica<TipElemenata> &m1,const Matrica<TipElemenata> &m2){
        if(m1.br_kolona != m2.br_redova)
            throw std::domain_error("Matrice nisu saglasne za mnozenje");
        auto m3(StvoriMatricu<TipElemenata>(m1.br_redova,m2.br_kolona));
       // m3{};
        for(int i=0; i<m1.br_redova; i++)
            for(int j=0; j<m2.br_kolona; j++){
                m3.elementi[i][j]={};
                    for(int k=0; k<m2.br_redova; k++) m3.elementi[i][j]+=m1.elementi[i][k]*m2.elementi[k][j];
            }
        return m3;
    }
    
template <typename TipElemenata>
    Matrica<TipElemenata> ProduktMatricaSkalar(const Matrica<TipElemenata> &m1,const TipElemenata &v){
     
        Matrica<TipElemenata> m3(StvoriMatricu<TipElemenata>(m1.br_redova,m1.br_kolona));
        for(int i=0; i<m1.br_redova; i++)
            for(int j=0; j<m1.br_kolona; j++)
                m3.elementi[i][j]=m1.elementi[i][j]*v;
                
            
        return m3;
    }
    
template <typename TipElemenata> 
    Matrica<TipElemenata> MatricniPolinom(const Matrica<TipElemenata> &A,std::vector<double> v){
            if(A.br_redova!=A.br_kolona)
                throw std::domain_error("Matrica mora biti kvadratna");
        auto mat(StvoriMatricu<TipElemenata>(A.br_redova,A.br_kolona));
        auto jedinicnamatrica(StvoriMatricu<TipElemenata>(A.br_redova,A.br_kolona));
        auto pomocna(StvoriMatricu<TipElemenata>(A.br_redova,A.br_kolona));
        auto mnozenje(StvoriMatricu<TipElemenata>(A.br_redova,A.br_kolona));
        
        auto nulamatrica(StvoriMatricu<TipElemenata>(A.br_redova,A.br_kolona));
        for(int i=0; i<nulamatrica.br_redova;i++){
            for(int j=0; j<nulamatrica.br_kolona; j++){
                nulamatrica.elementi[i][j]=0;
            }
        }
        
        if(v.size()==0) {     
            UnistiMatricu(pomocna); UnistiMatricu(mnozenje);UnistiMatricu(jedinicnamatrica); UnistiMatricu(mat);
            return nulamatrica;
        }
        else{
        for(int i=0; i<jedinicnamatrica.br_redova;i++){
            for(int j=0; j<jedinicnamatrica.br_kolona; j++){
                if(i==j) jedinicnamatrica.elementi[i][j]=1;
                else jedinicnamatrica.elementi[i][j]=0;
                
                    mat.elementi[i][j]=0;
                    pomocna.elementi[i][j]=A.elementi[i][j];
            }
        }
            mat=ProduktMatricaSkalar(jedinicnamatrica,v[0]);
            pomocna=ProduktMatrica(jedinicnamatrica,A);
            
            for(int i=1; i<v.size();i++){
                mnozenje=ProduktMatricaSkalar(pomocna,v[i]);
                pomocna=ProduktMatrica(pomocna,A);
                mat=ZbirMatrica(mat,mnozenje);
            }
          
            UnistiMatricu(pomocna); UnistiMatricu(mnozenje);UnistiMatricu(jedinicnamatrica); UnistiMatricu(nulamatrica);
        }
        return mat;
    }
    
int main ()
{
    Matrica<double> a,c;
    std::vector<double> v(0);
    int m(0),n(0);
    std::cout<<"Unesite dimenziju kvadratne matrice: ";
    std::cin>>m;
    try{
        a=StvoriMatricu<double>(m,m);
        c=StvoriMatricu<double>(m,m);
        std::cout<<"Unesite elemente matrice A:\n";
        UnesiMatricu('A',a);
        std::cout<<"Unesite red polinoma: ";
        std::cin>>n;
        std::cout<<"Unesite koeficijente polinoma: ";
        for(int i=0; i<n+1; i++){
            double a(0);
            std::cin>>a;
            v.push_back(a);
        }
        
       c=MatricniPolinom<double>(a,v);
       IspisiMatricu(c,10,6);
        
    }

    catch(std::bad_alloc){
        std::cout<<"Nema dovoljno memorije!\n";
    }
    
    UnistiMatricu(a);UnistiMatricu(c);
	return 0;
}