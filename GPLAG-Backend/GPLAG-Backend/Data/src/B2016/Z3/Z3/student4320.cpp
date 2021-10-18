/B2016/2017: Zadaća 3, Zadatak 3
#include <iostream>
#include <vector>
#include <new>
#include <iomanip>
#include <stdexcept>

template <typename TipElemenata>
struct Matrica {
    int br_redova, br_kolona;
    TipElemenata **elementi=nullptr;
};

template <typename TipElemenata>
void UnistiMatricu(Matrica<TipElemenata> mat)
{
    if(!mat.elementi) return;
    for(int i=0; i<mat.br_redova; i++) delete[] mat.elementi[i];
    delete[] mat.elementi;
    mat.elementi=nullptr;
}

template <typename TipElemenata>
Matrica<TipElemenata> StvoriMatricu(int br_redova, int br_kolona)
{
    Matrica<TipElemenata> mat;
    mat.br_redova=br_redova;
    mat.br_kolona=br_kolona;
//  mat.elementi=nullptr;
    mat.elementi = new TipElemenata*[br_redova];
    for(int i=0; i<br_redova; i++) mat.elementi[i]=nullptr;
    try {
        for(int i=0; i<br_redova; i++) mat.elementi[i]= new TipElemenata[br_kolona];
    } catch(...) {
        UnistiMatricu(mat);
        throw;
    }
    return mat;
}


template <typename TipElemenata>
void UnesiMatricu(char ime_matrice, Matrica<TipElemenata> &mat)
{
    for(int i=0; i<mat.br_redova; i++)
        for(int j=0; j<mat.br_kolona; j++) {
            std::cout<< ime_matrice <<"(" << i+1 <<","<<j+1<<") = ";
            std::cin>>mat.elementi[i][j];
        }
}

template <typename TipElemenata>
void IspisiMatricu(const Matrica<TipElemenata> &mat, int sirina_ispisa, int preciznost=6, bool treba_brisati=false)
{
    for(int i=0; i<mat.br_redova; i++) {
        for(int j=0; j<mat.br_kolona; j++)
            std::cout<<std::setw(sirina_ispisa)<<std::setprecision(preciznost)<<mat.elementi[i][j];
        std::cout<<std::endl;
    }
    if(treba_brisati) UnistiMatricu(mat);
}
/*
template <typename TipElemenata>
void IspisiMatricu(const Matrica<TipElemenata> &mat, int sirina_ispisa) {
    for(int i=0; i<mat.br_redova; i++) 
        for(int j=0; j<mat.br_kolona; j++) std::cout<<std::setw(sirina_ispisa)<<mat.elementi[i][j];
        std::cout<<std::endl; 
    }

*/
template <typename TipElemenata>
Matrica<TipElemenata> ZbirMatrica(const Matrica<TipElemenata> &m1, const Matrica<TipElemenata> &m2)
{
    if(m1.br_redova != m2.br_redova || m1.br_kolona != m2.br_kolona)
        throw std::domain_error("Matrica nemaju jednake dimenzije!");
    auto m3(StvoriMatricu<TipElemenata> (m1.br_redova, m1.br_kolona));
   
   // UnistiMatricu(m1);
    for(int i=0; i<m1.br_redova; i++)
        for(int j=0; j<m1.br_kolona; j++)
            m3.elementi[i][j]=m1.elementi[i][j]+m2.elementi[i][j];
    return m3;
}

template <typename TipElemenata>
Matrica<TipElemenata> ProduktMatrica(const Matrica<TipElemenata> &m1, const Matrica<TipElemenata> &m2)
{
    if(m1.br_kolona != m2.br_redova) throw std::domain_error("Matrice nisu saglasne za mnozenje");
    auto m3(StvoriMatricu<TipElemenata> (m1.br_redova, m2.br_kolona));
    for(int i=0; i<m1.br_redova; i++)
        for(int j=0; j<m2.br_kolona; j++)
            m3.elementi[i][j]=0;
    for(int i=0; i<m1.br_redova; i++)
        for(int j=0; j<m2.br_kolona; j++)
            for(int k=0; k<m2.br_redova; k++)
            m3.elementi[i][j]+=m1.elementi[i][k]*m2.elementi[k][j];
    return m3;
}

template <typename TipElemenata>
 Matrica<TipElemenata> Kopiraj(const Matrica<TipElemenata> &m1) {
    auto m2(StvoriMatricu<TipElemenata> (m1.br_redova, m1.br_kolona));
     //   m2.elementi=new int*[m2.br_redova];
          //  for(int i=0; i<m2.br_redova; i++) m2.elementi[i]=new int[m2.br_kolona];
                for(int i=0; i<m2.br_redova; i++)
                        for(int j=0; j<m2.br_kolona; j++) 
                            m2.elementi[i][j]=m1.elementi[i][j];
                            return m2;
            }

template <typename TipElemenata>
Matrica<TipElemenata> StepenujMatricu(const Matrica<TipElemenata> &m1, int n) {
    Matrica <TipElemenata> pom, m2;
    
  if(n==1) return m1; try {
//  auto m2(StvoriMatricu<TipElemenata> (m1.br_redova, m1.br_kolona));
 // if(n==1) return m1;
// auto m2=Kopiraj(m1);
 if(n==0) { 
    m2=StvoriMatricu<TipElemenata>(m1.br_redova, m1.br_kolona);
     for(int i=0; i<m1.br_redova; i++)
        for(int j=0; j<m1.br_kolona; j++) 
            if(i==j) m2.elementi[i][j]=1;
            else m2.elementi[i][j]=0;
     return m2;
 }
 m2=StvoriMatricu<TipElemenata>(m1.br_redova, m1.br_kolona);
  m2=Kopiraj(m1);
 // staviti za i=0 da vrati jedinicnu matricu
    for(int i=0; i<n-1; i++) {
    pom=ProduktMatrica(m1, m2); UnistiMatricu(m2); m2=Kopiraj(pom); UnistiMatricu(pom);
  } return m2; } catch(...) {
      UnistiMatricu(m2); UnistiMatricu(pom); throw;
      
  }
   
    return m2; }
    
template <typename TipElemenata>
Matrica<TipElemenata>  PomSaInt( Matrica<TipElemenata> &m1, double n) {
    auto m2(StvoriMatricu<TipElemenata> (m1.br_redova, m1.br_kolona));
    m2=Kopiraj(m1);
  // DODAO
 
    for(int i=0; i<m1.br_redova; i++)
        for(int j=0; j<m1.br_kolona; j++) m2.elementi[i][j]*=n; 
    return m2;
}
    

template <typename TipElemenata>
Matrica<TipElemenata> MatricniPolinom(const Matrica<TipElemenata> &m1, std::vector<double> v) {
   // auto m2(StvoriMatricu<TipElemenata> (m1.br_redova, m1.br_kolona));
  //  auto m3(StvoriMatricu<TipElemenata> (m1.br_redova, m1.br_kolona));
 //  auto m4(StvoriMatricu<TipElemenata> (m1.br_redova, m1.br_kolona));
 Matrica <TipElemenata> m2, m3, m4, pom; try {
 m2=StvoriMatricu<TipElemenata>(m1.br_redova, m1.br_kolona);
 if(v.size()==0) return m2;
        for(int i=0; i<m2.br_redova; i++) {
                for(int j=0; j<m2.br_kolona; j++) m2.elementi[i][j]=0;
        }
        // ovdje sve elemente m2 staviti na 0
        for(int i=0; i<v.size(); i++) {
                m3=StepenujMatricu(m1, i);
                m4=PomSaInt(m3, v[i]);
                pom=ZbirMatrica(m2, m4);
                UnistiMatricu(m2); m2=Kopiraj(pom); UnistiMatricu(m3); UnistiMatricu(m4); UnistiMatricu(pom);
        }
 } catch(...) { UnistiMatricu(m2); UnistiMatricu(m3); UnistiMatricu(m4); UnistiMatricu(pom); 
     
 }
      //  UnistiMatricu(m3); UnistiMatricu(m4);
    return m2;
}

int main()
{
    /*
    Matrica<double> a,b,c;
    int m,n;
    std::cout<<"Unesi broj redova i kolona za matrice:\n";
    std::cin>>m >>n;
    try {
        a=StvoriMatricu<double>(m,n);
        b=StvoriMatricu<double>(m, n);
        std::cout<<"Unesi matricu A:\n";
        UnesiMatricu('A', a);
        std::cout<<"Unesi matricu B:\n";
        UnesiMatricu('B', b);
        std::cout<<"Zbir ove dvije matrice je:\n";
        IspisiMatricu(c=StepenujMatricu(a,3), 7);

    } catch(std::bad_alloc) {
        std::cout<<"Nema dovoljno memorije!\n";
    }
    UnistiMatricu(a);
    UnistiMatricu(b);
    UnistiMatricu(c);
    */
    int m,n;
    std::cout<<"Unesite dimenziju kvadratne matrice: ";
    std::cin>>m;
    n=m;
    Matrica<int> A;
try {
    A=StvoriMatricu<int>(m,n);
    std::cout<<"Unesite elemente matrice A: \n";
    UnesiMatricu('A', A);
    std::cout<<"Unesite red polinoma: ";
    int red; std::cin>>red;
    std::cout<<"Unesite koeficijente polinoma: ";
    std::vector<double> v; 
    for(int i=0; i<=red; i++) { int x; std::cin>>x; v.push_back(x); }
    Matrica<int> B;
    B=MatricniPolinom(A, v);
    IspisiMatricu(B, 10, 6, true);
}
catch(std::domain_error msg) { std::cout<<msg.what(); throw; }
catch(...) { }
UnistiMatricu(A); 


    return 0;
}

