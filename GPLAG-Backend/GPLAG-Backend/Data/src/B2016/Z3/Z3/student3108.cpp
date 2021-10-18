/B2016/2017: Zadaća 3, Zadatak 3
#include <iostream>
#include <iomanip>
#include <stdexcept>
#include <new>
#include <vector>
#include <cmath>

template <typename TipElemenata>
struct Matrica {
    int br_redova, br_kolona;
    TipElemenata **elementi=nullptr;
};
template <typename TipElemenata>
void UnistiMatricu(Matrica<TipElemenata>mat) {
    if(!mat.elementi) return;
    for(int i=0; i<mat.br_redova; i++)
    delete[] mat.elementi[i];
    delete[] mat.elementi;
    mat.elementi=nullptr;
}

template <typename TipElemenata>
Matrica<TipElemenata> StvoriMatricu(int br_redova, int br_kolona) {
    Matrica<TipElemenata>mat;
    mat.br_redova=br_redova;
    mat.br_kolona=br_kolona;
    mat.elementi=new TipElemenata*[br_redova];
    for(int i=0; i<br_redova; i++) mat.elementi[i]=nullptr;
    try {
        for(int i=0; i<br_redova; i++)
        mat.elementi[i]=new TipElemenata[br_kolona];
    }
    catch(...) {
        UnistiMatricu(mat);
        throw;
    }
    return mat;
}

template <typename TipElemenata>
void UnesiMatricu(char ime_matrice, Matrica<TipElemenata>&mat) {
    for(int i=0; i<mat.br_redova; i++)
    for(int j=0; j<mat.br_kolona; j++) {
        std::cout<<ime_matrice<<"("<<i+1<<","<<j+1<<") = ";
        std::cin>>mat.elementi[i][j];
    }
}

template <typename TipElemenata>
void IspisiMatricu(const Matrica<TipElemenata>&mat, int sirina_ispisa, int preciznost=6, bool treba_brisati=false) {
    for(int i=0; i<mat.br_redova; i++) {
        for(int j=0; j<mat.br_kolona; j++){
         
        
        
        
        std::cout<<std::setw(sirina_ispisa)<<std::setprecision(preciznost)<<mat.elementi[i][j];
        }
        std::cout<<std::endl;
        
    }
    if(treba_brisati==true) {
            UnistiMatricu(mat);
        }
}
template <typename TipElemenata>
Matrica<TipElemenata> ZbirMatrica(const Matrica <TipElemenata>&m1, const Matrica<TipElemenata>&m2) {
    if(m1.br_redova != m2.br_redova || m1.br_kolona!= m2.br_kolona)
    throw std::domain_error("Matrice nemaju jednake dimenzije!");
    auto m3(StvoriMatricu<TipElemenata>(m1.br_redova, m1.br_kolona));
    for(int i=0; i<m1.br_redova; i++)
    for(int j=0; j<m1.br_kolona;j++)
    m3.elementi[i][j]=m1.elementi[i][j]+m2.elementi[i][j];
    return m3;
}

template <typename TipElemenata>
Matrica<TipElemenata>ProduktMatrica (const Matrica<TipElemenata>&m1, const Matrica<TipElemenata>&m2){
    if(m1.br_kolona!=m2.br_redova)
    throw std::domain_error("Matrice nisu saglasne za mnozenje");
    auto m3(StvoriMatricu<TipElemenata>(m1.br_redova,m2.br_kolona));
    for(int i=0; i<m1.br_redova; i++) {
        for(int j=0; j<m2.br_kolona; j++) {
            double suma=0;
            for(int k=0; k<m1.br_redova; k++)
            suma+=m1.elementi[i][k]*m2.elementi[k][j];
            m3.elementi[i][j]=suma;
        }
    }
    return m3;
}
template<typename TipElemenata>
Matrica<TipElemenata> MatricniPolinom(const Matrica<TipElemenata>&A, std::vector<double>p) {
    if(A.br_redova!=A.br_kolona)
    throw std::domain_error("Matrica mora biti kvadratna");
    if(p.empty()){
        std::fill(A.elementi[0], A.elementi[0]+A.br_redova*A.br_kolona, 0);
        return A;
    }
    
    int k;
    Matrica<TipElemenata>I;
    I=StvoriMatricu<TipElemenata>(A.br_redova, A.br_kolona);
    for(int i=0; i<A.br_redova; i++) {
        for(int j=0; j<A.br_kolona; j++) {
            if(i==j)
            I.elementi[i][j]=1;
            I.elementi[i][j]=0;
        }
    }
    
    Matrica<TipElemenata> P;
    P=StvoriMatricu<TipElemenata>(A.br_redova, A.br_kolona);
    for(int i=0; i<A.br_redova;i++)
    for(int j=0; j<A.br_kolona; j++)
    P.elementi[0][0]=p[0]*I.elementi[i][j];
    

    for(int i=1; i<=k; i++) {
        for(int j=0; j<A.br_redova; j++) {
            for(int n=0; n<A.br_kolona; n++) {
        
        auto B=ProduktMatrica(A,A);
        P.elementi[j][n]+=p[i]*B.elementi[j][n];
       
    } }}
    return P;
}
int main ()
{
    Matrica<double>A,B;
    std::cout<<"Unesite dimenziju kvadratne matrice";
    int a;
    std::cin>>a;
    try {
    std::cout<<"Unesite elemente matrice A:";
    
    std::cout<<std::endl;
    A=StvoriMatricu<double>(a,a);
    UnesiMatricu('A',A);
    std::cout<<"Unesite red polinoma: ";
    int p;
    std::cin>>p;
    std::cout<<"Unesite koeficijente polinoma: ";
    int k;
    std::vector<double>l;
    for(int i=0; i<=p; i++) {
        std::cin>>k;
        l.push_back(k);
    }
  
    IspisiMatricu(B=MatricniPolinom(A,l),10,6,false); }
    catch(std::bad_alloc) {
        std::cout<<"Nema dovoljno memorije!\n";
    }
    UnistiMatricu(A);
    UnistiMatricu(B);
	return 0;
}