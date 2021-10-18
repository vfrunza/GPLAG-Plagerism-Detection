/B2016/2017: Zadaća 3, Zadatak 3
#include <iostream>
#include <iomanip>
#include <stdexcept>
#include <new>
#include <vector>
//#include "TestCurenja.h"
template <typename TipElemenata>
struct Matrica{
  int br_redova, br_kolona;
  TipElemenata **elementi = nullptr;
};
template <typename TipElemenata>
void UnistiMatricu(Matrica<TipElemenata> mat){
    if(!mat.elementi) return;
    for (int i=0; i<mat.br_redova; i++) delete[] mat.elementi[i];
    delete[] mat.elementi;
    mat.elementi=nullptr;
}
template <typename TipElemenata>
Matrica<TipElemenata> StvoriMatricu(int br_redova, int br_kolona){
    Matrica<TipElemenata> mat;
    mat.br_kolona = br_kolona;
    mat.br_redova = br_redova;
    mat.elementi = new TipElemenata*[br_redova];
    for ( int i=0; i<br_redova; i++) mat.elementi[i] = nullptr;
    try{
        for(int i=0; i<br_redova; i++){
            mat.elementi[i] = new TipElemenata[br_kolona];
            for( int j(0); j<br_kolona; j++) mat.elementi[i][j] = 0;
        }
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
void IspisiMatricu(const Matrica<TipElemenata> &mat, int sirina_ispisa, int preciznost = 6, bool treba_brisati = false){
    
    for(int i=0; i<mat.br_redova; i++){
    for(int j=0; j<mat.br_kolona; j++){
        std::cout<<std::setprecision(preciznost)<<std::setw(sirina_ispisa)<<mat.elementi[i][j];
    }
    std::cout<<std::endl;
    }
    
    if(treba_brisati) UnistiMatricu(mat);
    
    
}
template <typename TipElemenata>
Matrica<TipElemenata> ZbirMatrica(const Matrica<TipElemenata> &m1, const Matrica<TipElemenata> &m2){
    if(m1.br_redova != m2.br_redova || m1.br_kolona != m2.br_kolona)
    throw std::domain_error("Matrice nemaju jednake dimenzije!");
    auto m3(StvoriMatricu<TipElemenata>(m1.br_redova, m1.br_kolona));
    for(int i=0; i<m1.br_redova; i++)
    for(int j=0; j<m1.br_kolona; j++)
    m3.elementi[i][j]= m1.elementi[i][j] + m2.elementi[i][j];
    
    return m3;
}
template <typename TipElemenata>
Matrica<TipElemenata> ProduktMatrica(const Matrica<TipElemenata> &m1, const Matrica<TipElemenata> &m2){
    if(m1.br_kolona != m2.br_redova){
        UnistiMatricu(m1);
        UnistiMatricu(m2);
        throw std::domain_error("Matrice nisu saglasne za mnozenje");
    }
    Matrica<TipElemenata> m3(StvoriMatricu<TipElemenata>(m1.br_redova,m2.br_kolona));
    for ( int i=0; i< m3.br_redova; i++){
        for(int j=0; j<m3.br_kolona; j++){
            for( int k=0; k<m1.br_kolona; k++){
                m3.elementi[i][j] += m1.elementi[i][k]*m2.elementi[k][j];
            }
        }
    }
    return m3;
}
template <typename TipElemenata>
Matrica<TipElemenata> stepen(const Matrica<TipElemenata> &m, int k){
    if(k == 0){
        Matrica<TipElemenata> help(StvoriMatricu<TipElemenata>(m.br_redova, m.br_kolona));
        for(int i=0; i<help.br_redova; i++){
            for(int j=0; j<help.br_kolona; j++) 
            if(i==j) help.elementi[i][j]=1;
            else help.elementi[i][j]=0;
            return help;
        }
    }
    else if( k == 1){
        Matrica<TipElemenata> help(StvoriMatricu<TipElemenata>(m.br_redova, m.br_kolona));
        help.br_redova = m.br_redova;
        help.br_kolona = m.br_kolona;
        for(int i(0); i<help.br_redova; i++)
        for(int j(0); j<help.br_kolona; j++)
        help.elementi[i][j] = m.elementi[i][j];
        return help;
    }
    
    Matrica<TipElemenata> b(StvoriMatricu<TipElemenata>(m.br_redova, m.br_kolona));
    for (int i(0); i<m.br_redova; i++)
    for (int j(0); j<m.br_kolona; j++) 
    if(i == j) b.elementi[i][j]=1.;
    for(int i(0); i<k; i++){
        Matrica<TipElemenata> pomocna(b);
        b=ProduktMatrica(pomocna, m);
        UnistiMatricu(pomocna);
    }
    return b;
}
template <typename TipElemenata>

Matrica<TipElemenata> MatricniPolinom(const Matrica<TipElemenata>&A, std::vector<double> pk){
    if(A.br_kolona != A.br_redova){
        UnistiMatricu(A);
        throw std::domain_error("Matrica mora biti kvadratna");
        
    }
    if(pk.size()==0){
        UnistiMatricu(A);
        return StvoriMatricu<double>(A.br_redova,A.br_kolona);
    }
    
    Matrica<TipElemenata> h(StvoriMatricu<TipElemenata>(A.br_redova, A.br_kolona));
    for(int k(0); k<int(pk.size()); k++){
        Matrica<TipElemenata> help(StvoriMatricu<TipElemenata>(A.br_redova, A.br_kolona));
        help.br_kolona=A.br_kolona;
        help.br_redova = A.br_redova;
        for( int i(0); i<help.br_redova; i++)
        for(int j(0); j<help.br_kolona;j++) help.elementi[i][j] = A.elementi[i][j];
        
        Matrica<TipElemenata> snaga(stepen(help,k));
        
        for(int i(0); i<snaga.br_redova; i++)
        for(int j(0); j<snaga.br_kolona;j++) snaga.elementi[i][j]*=pk[k];
        
        Matrica<TipElemenata> pomocna = h;
        h=ZbirMatrica(pomocna,snaga);
        UnistiMatricu(help);
        UnistiMatricu(snaga);
        UnistiMatricu(pomocna);
    }
    return h;
}


int main ()
{
    
    std::cout<<"Unesite dimenziju kvadratne matrice: ";
    int dim;
    std::cin>>dim;
    try{
        Matrica<double> m1(StvoriMatricu<double>(dim,dim));
        UnesiMatricu('A',m1);
        std::cout<<"Unesite red polinoma: ";
        int vel;
        std::cin>>vel;
        std::vector<double> v;
        std::cout<<"Unesite koeficijente polinoma: ";
        for(int i(0); i<=vel; i++){
            double temp;
            std::cin>>temp;
            v.push_back(temp);
        }
        auto p(MatricniPolinom(m1,v));
        IspisiMatricu(p,10);
        UnistiMatricu(m1);
        UnistiMatricu(p);
    }
    
    catch(...){
        throw std::domain_error("Curenje memorije");
    }
    
    
    
    
	return 0;
}