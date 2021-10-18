/B2017/2018: Zadaća 3, Zadatak 3
#include <iostream>
#include <iomanip>
#include <stdexcept>
#include <new>
#include <vector>

template <typename TipElemenata>
    struct Matrica {
        int br_redova,br_kolona;
        TipElemenata ** elementi=nullptr;
    };
    
    template <typename TipElemenata>
    void UnistiMatricu(Matrica <TipElemenata> mat) {
        if(!mat.elementi)return;
        for(int i=0;i<mat.br_redova;i++) delete [] mat.elementi[i];
        delete [] mat.elementi;
        mat.elementi=nullptr;
    }
    
    template <typename TipElemenata>
    Matrica <TipElemenata> StvoriMatricu (int br_redova, int br_kolona) {
        Matrica <TipElemenata> mat;
        mat.br_redova = br_redova; mat.br_kolona = br_kolona;
        mat.elementi = new TipElemenata*[br_redova];
        for(int i=0;i <br_redova;i++)mat.elementi[i]=nullptr;
        try{
            for(int i=0;i<br_redova;i++) mat.elementi[i]=new TipElemenata[br_kolona];
        }
        catch(...) {
            UnistiMatricu(mat);
            throw;
        }
        return mat;
    }
    
    template <typename TipElemenata>
    void UnesiMatricu (char ime_matrice, Matrica <TipElemenata> &mat) {
        for(int i=0;i<mat.br_redova;i++)
        for(int j=0;j<mat.br_kolona;j++) {
            std::cout<<ime_matrice<<"("<<i+1<<","<<j+1<<") = ";
            std::cin>>mat.elementi[i][j];
        }
    }

    template <typename TipElemenata>
    void IspisiMatricu(const Matrica<TipElemenata>&mat,int sirina_ispisa, int preciznost=6, bool treba_brisati=false) {
        for(int i=0;i<mat.br_redova;i++){
            for(int j=0;j<mat.br_kolona;j++)
            std::cout<<std::setw(sirina_ispisa)<<std::setprecision(preciznost)<<mat.elementi[i][j];
            std::cout<<std::endl;
        }
        if(treba_brisati)UnistiMatricu(mat);
    }
    
    template<typename TipElemenata>
    Matrica <TipElemenata> ZbirMatrica (const Matrica <TipElemenata> &m1, const Matrica<TipElemenata> &m2){
        
        if(m1.br_redova!=m2.br_redova || m1.br_kolona !=m2.br_kolona)
        throw std::domain_error("Matrice nemaju jednake dimenzije!");
        auto m3(StvoriMatricu<TipElemenata>(m1.br_redova,m1.br_kolona));
        for(int i=0;i<m1.br_redova;i++)
        for(int j=0;j<m1.br_kolona;j++)
        m3.elementi[i][j]=m1.elementi[i][j] + m2.elementi[i][j];
        return m3;
    }
    
    template <typename TipElemenata>
    Matrica <TipElemenata> ProduktMatrica (const Matrica <TipElemenata> &m1, const Matrica <TipElemenata> &m2) {
        if(m1.br_kolona!=m2.br_redova)throw std::domain_error("Matrice nisu saglasne za mnozenje");
        auto m3(StvoriMatricu<TipElemenata>(m1.br_redova,m1.br_kolona));
        TipElemenata pomocni=TipElemenata();
          for(int i=0;i<m1.br_redova;i++) {
              for(int j=0;j<m1.br_redova;j++) {
                  for(int k=0;k<m1.br_redova;k++) {
                      pomocni=pomocni+m1.elementi[i][k]*m2.elementi[k][j];
                  }
                  m3.elementi[i][j]=pomocni;
                  pomocni=TipElemenata();
              }
              
          }  
        return m3;
    }
    
    template <typename TipElemenata,typename nekitip>
    Matrica <TipElemenata> MatricniPolinom(Matrica <TipElemenata> m,int n,nekitip pok) {
        if(n<0)throw std::domain_error("Neispravan stepen polinoma");
        if(m.br_redova!= m.br_kolona)throw std::domain_error("Matrica mora biti kvadratna");
        auto m1(StvoriMatricu<TipElemenata>(m.br_redova,m.br_kolona));
     
        
      for(int i=0;i<m1.br_redova;i++) {
          for(int j=0;j<m1.br_kolona;j++) {
              if(i==j)m1.elementi[i][j]=*pok;else m1.elementi[i][j]=0;
          }
      }
      
     pok++; 
   auto m2=m;
     
     for(int i=0;i<n;i++) {
         auto m3=m2;
         if(i!=0)m2=ProduktMatrica(m2,m);
          
         for(int j=0;j<m2.br_redova;j++) {
             for(int k=0;k<m2.br_kolona;k++) {
                 
                 m1.elementi[j][k]=m1.elementi[j][k]+m2.elementi[j][k]* (*pok);
             }
         }
         pok++;
         if(m3.elementi!=m.elementi)UnistiMatricu(m3);
     } UnistiMatricu(m2);
       
     
     return m1;
    }
    

int main ()
{
    std::cout<<"Unesite dimenziju kvadratne matrice: ";
    int n; std::cin>>n; 
    if(n>0) {
    auto matrica=StvoriMatricu<int>(n,n);
    std::cout<<"Unesite elemente matrice A: "; std::cout<<std::endl;
    UnesiMatricu('A',matrica);
    std::cout<<"Unesite red polinoma: "; int red; std::cin>>red;
    std::vector<int> koef; std::cout<<"Unesite koeficijente polinoma: ";
    int broj;
    for(int i=0;i<=red;i++) {std::cin>>broj;koef.push_back(broj);}
    auto m2=matrica;
    matrica=MatricniPolinom(matrica,red,koef.begin());
    UnistiMatricu(m2);
    IspisiMatricu(matrica,10,6);
    UnistiMatricu(matrica);
    }
    
	return 0;
}
