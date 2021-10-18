#include <iomanip>
#include <iostream>
#include <stdexcept>
#include <new>
#include <vector>
#include <cmath>

template <typename TipElemenata>
struct Matrica {
    int br_redova,br_kolona;
    TipElemenata**elementi=nullptr;
};
template<typename TipElemenata>
void UnistiMatricu(Matrica<TipElemenata>mat) {
    if(!mat.elementi)return ;
    for(int i=0;i<mat.br_redova;i++) delete [] mat.elementi [i];
    delete [] mat.elementi;
    mat.elementi=nullptr;
}
template <typename TipElemenata>
Matrica <TipElemenata> StvoriMatricu(int br_redova,int br_kolona) {
    Matrica<TipElemenata> mat;
    mat.br_redova=br_redova;
    mat.br_kolona=br_kolona;
    mat.elementi=new TipElemenata*[br_redova];
    for(int i=0;i<br_redova;i++) 
    mat.elementi[i] = nullptr;
    try{ 
        for(int i=0;i<br_redova;i++) 
        mat.elementi[i]= new TipElemenata[br_kolona];
} catch(...) {
    UnistiMatricu(mat);
    throw;
}
return mat;
}
template<typename TipElemenata>
void UnesiMatricu (char ime_matrice,Matrica<TipElemenata> &mat) {
    for(int i=0;i<mat.br_redova;i++) 
    for(int j=0;j<mat.br_kolona;j++) {
        std::cout<<ime_matrice<<"("<<i+1<<","<<j+1<<") = ";
        std::cin>>mat.elementi[i][j];
    }
    }
    template<typename TipElemenata>
    void IspisiMatricu(const Matrica<TipElemenata> &mat,int sirina_ispisa,int preciznost=6,bool treba_brisati=false)
    {
        for(int i=0;i<mat.br_redova;i++) {
            for(int j=0;j<mat.br_kolona;j++) 
                std::cout<<std::setw(sirina_ispisa)<<std::setprecision(preciznost)<<mat.elementi[i][j];
                std::cout<<std::endl;
            }
            if(treba_brisati==true) 
            UnistiMatricu(mat);
        }
    
    template<typename TipElemenata>
    Matrica<TipElemenata> ZbirMatrica(const Matrica<TipElemenata>&m1,const Matrica<TipElemenata> &m2) {
        if(m1.br_redova!=m2.br_redova || m1.br_kolona!=m2.br_kolona) throw std::domain_error ("Matrice nemaju jednake dimenzije!");
        auto m3(StvoriMatricu<TipElemenata> (m1.br_redova,m2.br_kolona));
        for(int i=0; i<m1.br_redova;i++)
for(int j=0; j<m2.br_kolona;j++)
m3.elementi[i][j]=m1.elementi[i][j]+m2.elementi[i][j];
      return m3;  
    }
    template<typename TipElemenata>
    Matrica<TipElemenata> ProduktMatrica(const Matrica<TipElemenata> &m1,const Matrica<TipElemenata> &m2) {
        if(m1.br_kolona!=m2.br_redova) throw std::domain_error("Matrice nisu saglasne za mnozenje");
        auto m3(StvoriMatricu<TipElemenata>(m1.br_redova,m2.br_kolona));
        for(int i=0;i<m1.br_redova;i++)
        for(int j=0;j<m2.br_kolona;j++) {
        TipElemenata suma=0;
        for(int k=0;k<m2.br_redova;k++)
        suma+=m1.elementi[i][k]*m2.elementi[k][j];
        m3.elementi[i][j]=suma;
        }
        return m3;
    }
    template<typename TipElemenata>
    void ProduktMatricaiBroja(Matrica<TipElemenata> mat,double broj) {
        for(int i=0;i<mat.br_redova;i++) 
        for(int j=0;j<mat.br_kolona;j++) 
        mat.elementi[i][j]*=broj;
    }
    bool Jednako(double x,int y) {
        const double eps (1e-15);
        return std::fabs(x-y)<=eps*(std::fabs(x)+std::fabs(y));
    }
    template<typename TipElemenata, typename NekiTip>
    Matrica<TipElemenata> MatricniPolinom (Matrica<TipElemenata> m,int n,NekiTip p) {
      
       if(n<0) throw std::domain_error("Neispravan stepen polinoma");
      auto Polinom(StvoriMatricu<TipElemenata>(m.br_kolona,m.br_kolona));
      if(m.br_redova!=m.br_kolona) throw std::domain_error("Matrica mora biti kvadratna");
      
      for(int i=0;i<m.br_redova;i++) 
      for(int j=0;j<m.br_kolona;j++)
      Polinom.elementi[i][j]=0;
    
      
      for(int i=0;i<=n;i++) {
          if(Jednako(*p,0)) continue;
          try {
              auto Jedinicna(StvoriMatricu<TipElemenata>(m.br_redova,m.br_kolona));
              for(int i=0;i<m.br_redova;i++)
              for(int j=0;j<m.br_kolona;j++) {
              if(i==j) Jedinicna.elementi[i][j]=1;
              else Jedinicna.elementi[i][j]=0;
          }
        
              try{
                  for(int j=0;j<i;j++) {
              auto mat=Jedinicna;
              try{
                  Jedinicna=ProduktMatrica(m,Jedinicna);
                  UnistiMatricu(mat);
              } catch(...) {
                  UnistiMatricu(Jedinicna);
                  throw;
              }
          }
      ProduktMatricaiBroja(Jedinicna,*p);
      p++;
      
      try {
          auto mat=Polinom;
          Polinom=ZbirMatrica(Polinom,Jedinicna);
          UnistiMatricu(Jedinicna);
          UnistiMatricu(mat);
      }catch(...) {
          UnistiMatricu(Jedinicna);
          throw;
      }
      }catch(...) {
          UnistiMatricu(Polinom);
          throw;
      }
      }
      
        
    return Polinom;
    }
    
    
    int main() {
        Matrica<double> a;
        std::vector<double> vektor1;
        int m,n;
        std::cout<<"Unesite dimenziju kvadratne matrice: ";
        std::cin>>m;
         try{
             a = StvoriMatricu<double>(m,m);
             std::cout<<"Unesite elemente matrice A:\n" ;
             UnesiMatricu('A',a);
             std::cout<<"Unesite red polinoma: ";
             std::cin>>n;
             std::cout<<"Unesite koeficijente polinoma: ";
             for(int i=0;i<=n;i++)
             {
                 double y;
                 std::cin>>y;
                 vektor1.push_back(y);
             }
             
            
             IspisiMatricu(MatricniPolinom(a,n,vektor1.begin()),10,6,true);
             UnistiMatricu(a);
         }catch(...) {
             UnistiMatricu(a);
         }
         return 0;
    }
    
    
