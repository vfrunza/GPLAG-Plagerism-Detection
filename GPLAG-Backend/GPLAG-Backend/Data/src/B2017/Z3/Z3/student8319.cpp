/B2017/2018: Zadaća 3, Zadatak 3
#include <iostream>
#include <iomanip>
#include <stdexcept>
#include <new>
#include <iterator>
#include <vector>

template <typename TipElementa>
struct Matrica {
    int br_redova,br_kolona;
    TipElementa **elementi=nullptr;
};

template <typename TipElementa>
void UnistiMatricu (Matrica<TipElementa> mat)
{
    if (!mat.elementi) return;
    for (int i=0; i<mat.br_redova; i++) delete [] mat.elementi [i];
    delete[] mat.elementi;
    mat.elementi=nullptr;
}

template <typename TipElementa>
Matrica<TipElementa> StvoriMatricu (int br_redova,int br_kolona)
{
    Matrica<TipElementa> mat;
    mat.br_redova=br_redova;
    mat.br_kolona=br_kolona;
    mat.elementi=new TipElementa*[br_redova];
    for (int i=0; i<br_redova; i++) mat.elementi[i]=nullptr;
    try {
        for (int i=0; i<br_redova; i++) mat.elementi[i]=new TipElementa[br_kolona];
    } catch (...) {
        UnistiMatricu(mat);
        throw;
    }
    return mat;
}

template <typename TipElementa>
void UnesiMatricu (char ime_matrice, Matrica<TipElementa> &mat)
{
    for (int i=0; i<mat.br_redova; i++) {
        for (int j=0; j<mat.br_kolona; j++) {
            std::cout<<ime_matrice<<"("<<i+1<<","<<j+1<<") = ";
            std::cin>>mat.elementi[i][j];
        }
    }
}


template <typename TipElementa>
void IspisiMatricu (const Matrica <TipElementa> &mat, int sirina_ispisa,int preciznost=6,bool treba_brisati=false)
{
    for (int i=0; i<mat.br_redova; i++) {
        for (int j=0; j<mat.br_kolona; j++) {
            std::cout<<std::setw(sirina_ispisa)<<std::setprecision(preciznost)<<mat.elementi[i][j];
            std::cout<<std::endl;
        }
    }
    if (treba_brisati==true) UnistiMatricu(mat);
}

template<typename TipElementa>
Matrica<TipElementa> ZbirMatrica (const Matrica <TipElementa> &m1, const Matrica<TipElementa> &m2)
{
    if (m1.br_redova!=m2.br_redova || m1.br_kolona!= m2.br_kolona) throw std::domain_error ("Matrice nemaju jednake dimenzije!");
    auto m3 (StvoriMatricu<TipElementa>(m1.br_redova,m1.br_kolona));
    for (int i=0; i<m1.br_redova; i++) {
        for (int j=0; j<m1.br_kolona; j++) {
            m3.elementi[i][j]=m1.elementi[i][j]+m2.elementi[i][j];
        }
    }
    return m3;
}

template <typename TipElementa> 
Matrica<TipElementa> ProduktMatrica (const Matrica <TipElementa> &m1,const Matrica<TipElementa> &m2) {
    if (m1.br_kolona!=m2.br_redova) throw std::domain_error ("Matrice nisu saglasne za mnozenje");
  auto m3 (StvoriMatricu<TipElementa>(m1.br_redova,m2.br_kolona));
    for (int i=0;i<m1.br_redova;i++) {
        for (int j=0;j<m2.br_kolona;j++) {
            for (int k=0;k<m1.br_kolona;k++) {
                m3[i][j]+=m1[i][k]*m2[k][j];           
                }
        }
    }
    return m3;
}
template<typename TipElementa>
Matrica <TipElementa> PomnoziSkalarom (Matrica<TipElementa> mat,int k) {
    auto m(StvoriMatricu<TipElementa>(mat.br_redova,mat.br_kolona));
    for (int i=0;i<mat.br_redova;i++) {
        for (int j=0;j<mat.br_kolona;j++) {
            m[i][j]=mat[i][j]*k;
        }
    }
    return m;
}
template<typename TipElementa>
Matrica<TipElementa> StepenMatrice (Matrica<TipElementa> mat,int n) {
     auto m(StvoriMatricu<TipElementa>(mat.br_redova,mat.br_kolona));
          for (int i=0;i<mat.br_redova;i++) {
        for (int j=0;j<mat.br_kolona;j++) {
            if (i==j) m[i][j]=1;
            else m[i][j]=0;
        }
    }
     if (n==0)  return m; 
     if (n==1) return mat; 
     
     for (int i=0;i<n;i++) {
         m=ProduktMatrica<TipElementa>(m,mat);
     }

     return m;
}

template <typename TipElementa,typename IterTip>
Matrica<TipElementa> MatricniPolinom ( Matrica<TipElementa> mat,int n,IterTip pok) {
    if (mat.br_kolona!=mat.br_redova) throw std::domain_error ("Matrica mora biti kvadratna");
    if (n<0) throw std::domain_error ("Neispravan stepen polinoma");
    auto m(StvoriMatricu<TipElementa>(mat.br_redova,mat.br_kolona));
   m=PomnoziSkalarom<TipElementa>(StepenMatrice<TipElementa>(mat,0),*pok++);
    for (int i=1;i<=n;i++) {
        m=ZbirMatrica<TipElementa>(m,PomnoziSkalarom<TipElementa>(StepenMatrice<TipElementa>(mat,i),*pok++));
    }
    return m;
}

int main ()
{
    Matrica<int> a,c;
    int m,n;
    std::cout<<"Unesite dimenziju kvadatne matrice  matrice: "<<std::endl;
    std::cin>>m;
    n=m;
    try {
        a=StvoriMatricu<int>(m,n);
        std::cout<<"Unesi elemente matrice A: "<<std::endl;
        UnesiMatricu('A',a) ;
        int n;
        std::cout<<"Unesite red polinoma: ";
        std::cin>>n;
        std::vector<int> k;
        std::cout<<"Unesite koeficijente polinoma: ";
        for (int i=0;i<=n;i++) {
            int br;
            std::cin>>br;
            k.push_back(br);
        }
        
         
       
    } catch(std::bad_alloc) {
        std::cout<<"Nema dovoljno memorije!"<<std::endl;
    }
    UnistiMatricu(a);
    UnistiMatricu(c);
    return 0;
}
