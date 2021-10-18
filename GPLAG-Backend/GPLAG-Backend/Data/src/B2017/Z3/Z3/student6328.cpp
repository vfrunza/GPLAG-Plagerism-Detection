#include <iostream>
#include <iomanip>
#include <stdexcept>
#include <new>
#include <vector>
#include <list>
template<typename TipElemenata>
struct Matrica {
    int br_redova, br_kolona;
    TipElemenata **elementi=nullptr;
};
template <typename TipElemenata>
void UnistiMatricu(Matrica<TipElemenata> mat)
{
    if(!mat.elementi) return;
    for(int i=0; i<mat.br_redova; i++) delete [] mat.elementi[i];
    delete [] mat.elementi;
    mat.elementi=nullptr;
}
template <typename TipElemenata>
Matrica<TipElemenata> StvoriMatricu(int br_redova, int br_kolona){
    Matrica<TipElemenata> mat;
    mat.br_redova=br_redova;
    mat.br_kolona=br_kolona;
    mat.elementi=new TipElemenata* [br_redova];
    for(int i=0; i<br_redova; i++) mat.elementi[i]=nullptr;
    try {
        for(int i=0; i<br_redova; i++) mat.elementi[i]=new TipElemenata[br_kolona];
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
            std::cout<<ime_matrice<<"("<<i+1<<","<<j+1<<") = ";
            std::cin>>mat.elementi[i][j];
        }
}
template <typename TipElemenata>
void IspisiMatricu(const Matrica<TipElemenata> &mat, int sirina_ispisa, int preciznost=6,bool treba_brisati=false){
    for(int i=0; i<mat.br_redova; i++) {
        for(int j=0; j<mat.br_kolona; j++) std::cout<<std::setw(sirina_ispisa)<<std::setprecision(preciznost)<<mat.elementi[i][j];
        std::cout<<std::endl;
    }
    if(treba_brisati) UnistiMatricu(mat);
    
}
template <typename TipElemenata>
Matrica<TipElemenata> ZbirMatrica (const Matrica<TipElemenata> &m1, const Matrica<TipElemenata> &m2)
{
    if(m1.br_redova!=m2.br_redova || m1.br_kolona!=m2.br_kolona) throw std::domain_error("Matrice nemaju jednake dimenzije!");
    auto m3(StvoriMatricu<TipElemenata>(m1.br_redova,m1.br_kolona));
    for(int i=0; i<m1.br_redova; i++)
        for (int j=0; j<m1.br_kolona; j++) {
            TipElemenata suma(0);
            
        suma=m1.elementi[i][j]+m2.elementi[i][j];
        m3.elementi[i][j]=suma;
        }
    return m3;
}
template <typename TipElemenata>
Matrica<TipElemenata> ProduktMatrica(const Matrica<TipElemenata> &m1, const Matrica<TipElemenata> &m2)
{
    if(m1.br_kolona!=m2.br_redova) throw std::domain_error("Matrice nisu saglasne za množenje!");
    auto m3(StvoriMatricu<TipElemenata>(m1.br_redova,m2.br_kolona));
    for(int i=0; i<m1.br_redova; i++) 
        for(int j=0; j<m2.br_kolona; j++){ 
            TipElemenata suma(0);
            for(int k=0; k<m2.br_redova; k++) {
                suma+=m1.elementi[i][k]*m2.elementi[k][j];
            }
            m3.elementi[i][j]=suma;
    }
    return m3;
}

template<typename TipElemenata>
void PomnoziSaSkalarom(Matrica<TipElemenata> mat, double skalar)
{
    for(int i=0; i<mat.br_redova; i++) 
        for(int j=0; j<mat.br_kolona; j++) mat.elementi[i][j]*=skalar;
    
}
template <typename TipElemenata>
Matrica<TipElemenata> MatricniPolinom(Matrica<TipElemenata> mat, int n, std::list<TipElemenata>::iterator pol)
{
    if (n<0) throw std::domain_error("Neispravan stepen polinoma!");
    if(mat.br_kolona!=mat.br_redova) throw std::domain_error("Matrica mora biti kvadratna!");
    auto polinom(StvoriMatricu<TipElemenata>(mat.br_kolona, mat.br_kolona));
    
    for(int i=0; i<mat.br_redova; i++) 
        for(int j=0; j<mat.br_kolona; j++) mat.elementi[i][j]=0;
    
    for(auto it=pol.begin(); it<n; it++) {
        if(*it==0) continue;
        try {
            auto jedinicna=StvoriMatricu<TipElemenata>(mat.br_redova,mat.br_kolona);
            for(int i=0; i<mat.br_redova; i++)
                for(int j=0; j<mat.br_kolona; j++) {
                    if (i==j) jedinicna.elementi[i][j]=1;
                    else jedinicna.elementi[i][j]=0;
                }
            for(int j=0; j<it; j++) {
                auto tmp(jedinicna);
                try {
                    jedinicna=ProduktMatrica(mat, jedinicna);
                    UnistiMatricu(tmp);
                } catch(...) {
                    UnistiMatricu(jedinicna);
                    throw;
                }
            }
            
            PomnoziSaSkalarom(jedinicna, *it);
            try {
                auto tmp(polinom);
                polinom=ZbirMatrica(polinom,jedinicna);
                UnistiMatricu(jedinicna);
                UnistiMatricu(tmp);
            } catch(...) {
                UnistiMatricu(jedinicna);
                throw;
            }
           
        } catch(...) {
            UnistiMatricu(polinom);
            throw;
        }
    }
    return polinom;

}
int main ()
{
    Matrica<double> mat;
    std::cout<<"Unesite dimenziju kvadratne matrice: ";
    int m,n,red;
    std::list<double> pol;
    std::cin>>m;
    try{
        mat=StvoriMatricu<double>(m,m);
        std::cout<<"Unesite elemente matrice A: "<<std::endl;
        UnesiMatricu('A',mat);
        std::cout<<"Unesite red polinoma: ";
        std::cin>>n;
        std::cout<<"Unesite koeficijente polinoma: ";
        for(int i=0;i<=n;i++){
            double br;
            std::cin>>br;
            pol.push_back(br);
        }
        IspisiMatricu(MatricniPolinom(mat,red,pol.begin()),10,6,true);
        UnistiMatricu(mat);
    }
    catch(...){
        UnistiMatricu(mat);
    }
    return 0;
}
