/B2017/2018: Zadaća 3, Zadatak 3
#include <iostream>
#include <iomanip>
#include <stdexcept>
#include <new>

template <typename TipElemenata>
struct Matrica {
    int br_redova, br_kolona;
    TipElemenata **elementi=nullptr;
};
template <typename TipElemenata>
void UnistiMatricu(Matrica<TipElemenata> mat) {
    if(!mat.elementi) return;
    for(int i=0;i<mat.br_redova;i++) delete[] mat.elementi[i];
    mat.elementi=nullptr;
}
template <typename TipElemenata>
Matrica<TipElemenata> StvoriMatricu(int br_redova, int br_kolona) {
    Matrica<TipElemenata> mat;
    mat.br_redova=br_redova; mat.br_kolona=br_kolona;
    mat.elementi=new TipElemenata* [br_redova];
    for(int i=0;i<br_redova;i++) mat.elementi[i]=nullptr;
    try{
        for(int i=0;i<br_redova;i++)
            mat.elementi[i]=new TipElemenata[br_kolona];
    }
    catch(...) {
        UnistiMatricu(mat);
        throw;
    }
    return mat;
}
template <typename TipElemenata>
void UnesiMatricu(char ime_matrice, Matrica<TipElemenata> &mat) {
    for(int i=0;i<mat.br_redova;i++)
        for(int j=0;j<mat.br_kolona;j++) {
            std::cout<<ime_matrice
            <<"("<<i+1<<","<<j+1<<") = ";
            std::cin>>mat.elementi[i][j];
        }
}
template <typename TipElemenata>
void IspisiMatricu(const Matrica<TipElemenata> &mat, int sirina_ispisa,int preciznost=6,bool treba_brisati=false) {
    for(int i=0;i<mat.br_redova;i++) {
        for(int j=0;j<mat.br_kolona;j++)
            std::cout<<std::setw(sirina_ispisa)<<std::setprecision(preciznost)<<mat.elementi[i][j];
        std::cout<<std::endl;
    }
    if(treba_brisati==true) UnistiMatricu(mat);
}
template <typename TipElemenata>
Matrica<TipElemenata> ZbirMatrica(const Matrica<TipElemenata> &m1, const Matrica<TipElemenata> &m2) {
    if(m1.br_redova!=m2.br_redova || m1.br_kolona!=m2.br_kolona)
        throw std::domain_error("Matrice nemaju jednake dimenzije!");
    auto m3(StvoriMatricu<TipElemenata>(m1.br_redova,m1.br_kolona));
    for(int i=0;i<m1.br_redova;i++)
        for(int j=0;j<m1.br_kolona;j++)
            m3.elementi[i][j]=m1.elementi[i][j]+m2.elementi[i][j];
    return m3;
}
template <typename TipElemenata>
Matrica<TipElemenata> ProduktMatrica(Matrica<TipElemenata> m1,Matrica<TipElemenata> m2) {
    if(m1.br_kolona!=m2.br_redova) throw std::domain_error("Matrice nisu saglasne za mnozenje");
    Matrica<TipElemenata> m3(StvoriMatricu(m1.br_redova,m2.br_kolona));
    for(int i=0;i<m1.br_redova;i++) {
        int suma=0;
        for(int j=0;j<m2.br_redova;j++) {
            suma=0;
            for(int k=0;k<m1.br_kolona;k++) {
                suma+=m1.elementi[i][k]*m2.elementi[k][j];
            }
            m3.elementi[i][j]=suma;
        }
    }
    return m3;
}
template<typename TipElemenata,typename TipElemenata2,typename TipElemenata3>
Matrica<TipElemenata> PomnoziSkalarom(Matrica<TipElemenata> &m,TipElemenata2<TipElemenata3> k) {
    Matrica<TipElemenata> mat(StvoriMatricu(m.br_redova,m.br_kolona));
    for(int i=0;i<m.br_redova;i++)
        for(int j=0;j<m.br_kolona;j++)
            mat.elementi[i][j]=m.elementi[i][j]*k;
    return mat;
}
template<typename TipElemenata>
Matrica<TipElemenata> Stepenuj(Matrica<TipElemenata> m, int n) {
    Matrica<TipElemenata> mat(StvoriMatricu(m.br_redova,m.br_kolona));
    for(int i=0;i<m.br_redova;i++) {
        for(int j=0;j<m.br_kolona;j++) {
            mat.elementi[i][j]=m.elementi[i][j];
        }
    }
    if(stepen==0) {
        for(int i=0;i<mat.br_redova;i++) {
            for(int j=0;j<mat.br_redova;j++) {
                if(i==j) mat[i][j]=1;
                else mat[i][j]=0;
            }
        }
    }
    else {
        for(int i=0;i<n;i++) {
            Matrica<TipElemenata> pom=ProduktMatrica(mat,mat);
            for(int i=0;i<mat.br_redova;i++)
                for(int j=0;j<mat.br_kolona;j++)
                    mat.elementi[i][j]=pom.elementi[i][j];
        }
        UnistiMatricu(pom);
    }
    return mat;
}

template <typename TipElemenata, typename TipElemenata2>
Matrica<TipElemenata> MatricniPolinom (Matrica<TipElemenata> mat, int n, TipElemenata2 koef) {
    if(n<0) throw std::domain_error("Neispravan stepen polinoma");
    if(mat.br_kolona!=mat.br_redova) throw std::domain_error("Matrica mora biti kvadratna");
    Matrica<TipElemenata> pol(StvoriMatricu(mat.br_redova,mat.br_kolona));
    for(int i=0;i<mat.br_redova;i++) {
        for(int j=0;j<mat.br_kolona;j++) {
            pol.elementi[i][j]=0;
        }
    }
    if(koef.size()==0) return pol;
    Matrica<TipElemenata> fin(StvoriMatricu(mat.br_redova,mat.br_kolona));
    for(int k=0;k<koef.size();k++) {
        for(int i=0;i<mat.br_redova;i++)
            for(int j=0;j<mat.br_kolona;j++)
                fin.elementi[i][j]=mat.elementi[i][j];
        auto mat1(Stepenuj(fin,k));
        auto mat2(PomnoziSkalarom(mat1,koef[k]));
        auto mat3(ZbirMatrica(pol,mat2));
        for(int i=0;i<mat.br_redova;i++)
            for(int j=0;j<mat.br_kolona;j++)
                pol.elementi[i][j]=mat3.elementi[i][j];
        UnistiMatricu(mat3);
        UnistiMatricu(mat2);
        UnistiMatricu(mat1);
        //ispisi matrica?!
        UnistiMatricu(fin);
    }
    return pol;
}



int main ()
{
   std::cout<<"Unesite dimenziju kvadratne matrice: ";
   int dimenzija;
   std::cin>>dimenzija;
   std::cout<<"Unesite elemente matrice A: ";
   try {
      Matrica<TipElemenata> mat(StvoriMatricu(dimenzija,dimenzija));
      UnesiMatricu('A',mat);
      std::cout<<"Unesite red polinoma: ";
      int n;
      std::cin>>n;
      std::cout<<"Unesite koeficijente polinoma: ";
      TipElemenata2<TipElemenata3> koef;
      if(n>0) {
          int br(0);
          for(int i=0;i<n;i++) {
              std::cin<<br;
              koef.push_back(br);
          }
      }
      auto b(MatricniPolinom(mat,n,koef));
      IspisiMatricu(b);
      UnistiMatricu(b);UnistiMatricu(mat);
       
   }
   catch(std::domain_error d) {
       std::cout<<d.what();
       UnistiMatricu(mat);
   }
   catch(std::bad_alloc) {
       std::cout<<"Nema dovoljno memorije";
   }
   return 0;
}
