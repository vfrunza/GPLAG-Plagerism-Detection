/B2016/2017: Zadaća 3, Zadatak 3
#include <iostream>
#include <iomanip>
#include <stdexcept>
#include <new>

template <typename TipElemenata>
struct Matrica{
    int br_redova,br_kolona;
    TipElemenata **elementi=nullptr;
};

template <typename TipElemenata>
void UnistiMatricu (Matrica<TipElemenata> mat){
    if(!mat.elementi) return;
    for(int i=0;i<mat.br_redova;i++) delete[] mat.elementi[i];
    delete[] mat.elementi;
    mat.elementi=nullptr;
}

template <typename TipElemenata>
Matrica<TipElemenata> StvoriMatricu(int br_redova, int br_kolona){
    Matrica<TipElemenata> mat;
    mat.br_redova=br_redova; mat.br_kolona=br_kolona;
    mat.elementi=new TipElemenata*[br_redova];
    for(int i=0;i<br_redova;i++) mat.elementi[i]=nullptr;
    try{
        for(int i=0;i<br_redova;i++)
        mat.elementi[i]=new TipElemenata[br_kolona];
    }catch(...){
        UnistiMatricu(mat);
        throw;
    }
    return mat;
}

template <typename TipElemenata>
void UnesiMatricu(char ime_matrice, Matrica<TipElemenata> &mat){
    for(int i=0;i<mat.br_redova;i++){
        for(int j=0;j<mat.br_kolona;j++){
            std::cout<<ime_matrice<<"("<<i+1<<","<<j+1<<") =";
            std::cin>>mat.elementi[i][j];
        }
    }
}

template <typename TipElemenata>
void IspisiMatricu(const Matrica<TipElemenata> &mat, int sirina_ispisa){
    for(int i=0;i<mat.br_redova;i++){
        for(int j=0;j<mat.br_kolona;j++){
            std::cout<<std::setw(sirina_ispisa)<<mat.elementi[i][j];
        }
        std::cout<<"\n";
    }
}

template <typename TipElemenata>
Matrica<TipElemenata> ZbirMatrica(const Matrica<TipElemenata> &m1, const Matrica<TipElemenata> &m2){
    if(m1.br_redova!=m2.br_redova || m1.br_kolona!=m2.br_kolona)
    throw std::domain_error("Matrice nemaju jednake dimenzije!");
    auto m3(StvoriMatricu<TipElemenata>(m1.br_redova, m1.br_kolona));
    for(int i=0;i<m1.br_redova;i++){
        for(int j=0;j<m1.br_kolona;j++){
            m3.elementi[i][j]=m1.elementi[i][j]+m2.elementi[i][j];
        }
    }
    return m3;
}

int main ()
{
    Matrica<double> a,b,c;
    int n;
    std::cout<<"Unesite dimenziju kvadratne matrice: ";
    std::cin>>n;
    try{
        a=StvoriMatricu<double>(n,n);
         std::cout<<"Unesite elemente matrice A: \n";
         UnesiMatricu('A',a);
    }
   
    
	return 0;
}