#include <iostream>
#include <iomanip>
#include <stdexcept>
#include <new>
#include <vector>

template<typename TipElemenata>
    struct Matrica{
        int br_redova, br_kolona;
        TipElemenata **elementi=nullptr;
    };

template<typename TipElemenata>
 void UnistiMatricu(Matrica<TipElemenata> mat){
     if(!mat.elementi) return;
     for(int i=0; i<mat.br_redova; i++) delete[] mat.elementi[i];
     delete [] mat.elementi;
     mat.elementi=nullptr;
 }
 
 template<typename TipElemenata>
 Matrica<TipElemenata> StvoriMatricu(int br_redova, int br_kolona){
     Matrica<TipElemenata> mat;
     mat.br_redova = br_redova; mat.br_kolona=br_kolona;
     mat.elementi = new TipElemenata*[br_redova];
     for(int i=0; i<br_redova; i++) 
        mat.elementi[i] = nullptr;
     try{
         for(int i=0; i<br_redova; i++)
          mat.elementi[i]=new TipElemenata[br_kolona];
     }catch(...){
         UnistiMatricu(mat);
         throw;
     }
     return mat;
 }
 
 template<typename TipElemenata>
 void UnesiMatricu(char ime_matrice, Matrica<TipElemenata> &mat){
     for(int i=0; i<mat.br_redova; i++)
        for(int j=0; j<mat.br_kolona; j++){
            std::cout<<ime_matrice<<"("<<i+1<<","<<j+1<<") = ";
            std::cin>>mat.elementi[i][j];
        }
 }
 
 template<typename TipElemenata>
    void IspisiMatricu(Matrica<TipElemenata> mat, int sirina_ispisa, int preciznost=6, bool brisati=false){
        for(int i=0; i<mat.br_redova; i++){
            for(int j=0; j<mat.br_kolona; j++)
                std::cout<<std::setw(sirina_ispisa)<<std::setprecision(preciznost)<<mat.elementi[i][j];
            std::cout << std::endl;
        }
        if(brisati)
        UnistiMatricu(mat);
    }
 
 template<typename TipElemenata>
    Matrica<TipElemenata> ZbirMatrica ( Matrica<TipElemenata> &m1, const Matrica<TipElemenata> &m2){
        if(m1.br_redova!=m2.br_redova or m1.br_kolona!=m2.br_kolona)
            throw std::domain_error ("Matrice nemaju jednake dimenzije!");
  //      auto m3(StvoriMatricu<TipElemenata>(m1.br_redova,m1.br_kolona));
        for(int i=0; i<m1.br_redova; i++)
            for(int j=0; j<m1.br_kolona; j++)
                m1.elementi[i][j] = m1.elementi[i][j] + m2.elementi[i][j];
        return m1;        
    }
 
 template<typename TipElemenata>
    Matrica<TipElemenata> ProduktMatrica(Matrica<TipElemenata> a, Matrica<TipElemenata> b){
        if(a.br_kolona!=b.br_redova)
            throw std::domain_error ("Matrice nisu saglasne za mnozenje");
        auto c(StvoriMatricu<TipElemenata>(a.br_redova,b.br_kolona));
        for(int i=0; i<c.br_redova ; i++){
            for(int j=0; j<c.br_kolona; j++){
                c.elementi[i][j]=0;
            }
        }
        int k(0);
        for(int i=0; i<a.br_redova ; i++){
            TipElemenata suma(0);
            for(int j=0; j<b.br_kolona; j++){
                suma=0;
                for(int l=0; l<a.br_kolona; l++)
               suma+=a.elementi[i][l]*b.elementi[l][j];
               c.elementi[i][k]=suma;
               k++;
            }
            k=0;
        }
        return c;
    }
    
  template<typename TipElemenata>
    Matrica<TipElemenata> MnozenjeSkalarom(Matrica<TipElemenata> &a, double b){
/*        auto c(StvoriMatricu<TipElemenata>(a.br_redova,a.br_kolona));
        for(int k=0; k<c.br_redova; k++)
                    for(int j=0; j<c.br_kolona; j++)
                        c.elementi[k][j]=a.elementi[k][j];    */
            for(int i=0; i<a.br_redova; i++)
                for(int j=0; j<a.br_kolona; j++)
                    a.elementi[i][j]*=b;
            
            return a;
    }
        
 template<typename TipElemenata>
    Matrica<TipElemenata> MatricniPolinom(Matrica<TipElemenata> a,std::vector<double> koef){
        if(a.br_kolona!=a.br_redova){
            UnistiMatricu(a);
            throw std::domain_error ("Matrica mora biti kvadratna");
        }
        auto b(StvoriMatricu<TipElemenata>(a.br_redova,a.br_kolona));
        for(int i=0; i<b.br_redova; i++)
            for(int j=0; j<b.br_kolona; j++)
                b.elementi[i][j]=0;
        if(!koef.size()){
            return b;
        }
        bool logicka(false);
        auto pom(StvoriMatricu<TipElemenata>(a.br_redova,a.br_kolona));
        auto c(StvoriMatricu<TipElemenata>(a.br_redova,a.br_kolona));
        for(int k=0; k<c.br_redova; k++)
                    for(int j=0; j<c.br_kolona; j++)
                        c.elementi[k][j]=a.elementi[k][j];
        
        for(int i=0; i<koef.size(); i++){
            if(i==0){
                for(int k=0; k<b.br_redova; k++)
                    for(int j=0; j<b.br_kolona; j++)
                        if(k==j)
                            b.elementi[k][j]=koef[i];
            }else{
                if(logicka){
                    auto pom2=c;
                    c=ProduktMatrica(c,a);
                    UnistiMatricu(pom2);
                }
                for(int k=0; k<c.br_redova; k++)
                    for(int j=0; j<c.br_kolona; j++)
                        pom.elementi[k][j]=c.elementi[k][j];
                ZbirMatrica(b, MnozenjeSkalarom(pom,koef[i]));
        
                logicka=true;
            }
        }
   //     UnistiMatricu(pom2);
        UnistiMatricu(c);
        UnistiMatricu(pom);
        
        return b;
    }
 
 
int main ()
{
    std::cout<<"Unesite dimenziju kvadratne matrice: ";
    int x;
    std::cin>>x;
    auto a(StvoriMatricu<double>(x,x));
   
    std::cout<<"Unesite elemente matrice A: "<<std::endl;
    UnesiMatricu('A',a);
    std::cout<<"Unesite red polinoma: ";
    int n;
    std::cin>>n;
    std::cout<<"Unesite koeficijente polinoma: ";
    std::vector<double> koef;
    double y;
    for(int i=0; i<=n; i++){
        std::cin>>y;
        koef.push_back(y);
    }
  
    IspisiMatricu(MatricniPolinom(a,koef),10,6,true);
    UnistiMatricu(a);
	return 0;
}