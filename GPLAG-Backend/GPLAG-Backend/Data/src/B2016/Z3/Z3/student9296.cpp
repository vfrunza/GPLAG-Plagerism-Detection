/B2016/2017: Zadaća 3, Zadatak 3
#include <iostream>
#include <iomanip>
#include <stdexcept>
#include <new>
#include <vector>
#include <algorithm>
template <typename Tip>
struct Matrica{
    int br_red, br_kol;
    Tip** elementi=nullptr;
};
template <typename Tip>
void UnistiMatricu(Matrica<Tip> matr){
    if(!matr.elementi) return;
    for(int i=0; i<matr.br_red; i++) delete[] matr.elementi[i];
    delete[] matr.elementi;
    mat.elementi=nullptr;
}
template <typename Tip>
Matrica<Tip> StvoriMatricu(int br_red, int br_kol){
    Matrica<Tip> matr;
    matr.br_red=br_red;
    matr.br_kol=br_kol;
    matr.elementi=new*Tip[br_red];
    for(int i=0; i<br_red; i++) matr.elementi[i]=nullptr;
    try{
        for(int i=0; i<br_red; i++) matr.elementi[i]=new Tip[br_kol];
    }
    catch(...){
        UnistiMatricu(matr);
        throw;
    }
    return matr;
}
template <typename Tip>
void UnesiMatricu(char ime, Matrica<Tip> &matr){
    for(int i=0; i<matr.br_red; i++)
        for(int j=0; j<matr.br_kol; j++){
            std::cout<<ime<<"("<<i+1<<","<<j+1<<") = ";
            std::cin>>matr[i][j];
        }
}
template <typename Tip>
void IspisiMatricu(const Matrica<Tip> &matr, int sirina_ispisa){
    for(int i=0; i<matr.br_red; i++){
        for(int j=0; j<matr.br_kol; j++) std::cout<<std::setw(sirina_ispisa)<<mat.elementi[i][j];
        std::cout<<std::endl;
    }
}
template <typename Tip>
Matrica<Tip> ZbirMatrica(const Matrica<Tip> &M1, const Matrica<Tip> &M2){
    if(M1.br_kol!=M2.br_kol || M1.br_red!=M2.br_red) throw std::domain_error("Matrice nemaju jednake dimenzije");
    auto M3(StvoriMatricu<Tip>(M1.br_red, M1.br_kol));
    for(int i=0; i<br_red; i++)
        for(it j=0; j<br_kol; j++)
            M3.elementi[i][j]=M1.elementi[i][j] + M2.elementi[i][j];
    return M3;
}
template <typename Tip>
Matrica<Tip> ProduktMatrice(Matrica<Tip> m1, Matrica<Tip> m2){
    if(m1.br_kol!=m2.br_red) throw std::domain_error("Matrice nisu saglasne za mnozenje");
    
    auto m3(StvoriMatricu<Tip>(m1.br_red, m2.br_kol));
    
    for(int i=0; i<m1.br_red; i++){
        Tip suma(0);
        for(int j=0; j<m2.br_kol; j++)
            for(int k=0; k<m1.br_kol; k++)
                suma+=m1.elementi[i][k]*m2.elementi[k][j];
        m3.elementi[i][j]=suma;
    }
    return m3;
}

Matrica<Tip>Jedinicna(int redovi, int kolone){
    try{
        Matrica<Tip> mat(StvoriMatricu(redovi, kolone));
        for(int i=0; i<redovi; i++)
            for(int j=0; j<redovi; j++){
                if(i==j) mat.elementi[i][j]=1;
                else mat.elementi[i][j]=0;
            }
    }
    catch(...){
        UnistiMatricu(mat);
    }
    return mat;
}

template<typename Tip>
Matrica<Tip>MatricniPolinom(Matrica<Tip>A, std::vector<double> koef){
    if(A.br_kol!=A.br_red) throw std::domain_error("Matrica mora biti kvadratna");
    Matrica<Tip> mpolinom;
    Matrica<Tip> jedinicna;
    Matrica<Tip> zovi_upomoc;
    Matrica<Tip> jos_jednom_zovi_upomoc;
    try{
        mpolinom=StvoriMatricu(A.br_red, A.br_kol);
        jedinicna=Jedinicna(A.br_red,A.br_kol);
        for(int i=0; i<mpolinom.br_red; i++)
            for(int j=0; j<mpolinom.br_kol; j++){
                mpolinom.elementi[i][j]=0;
                mpolinom.elementi[i][j]+=jedinicna[i][j];       //za A^0
            }
        UnistiMatricu(jedinicna);
        for(int i=0; i<koef.size(); i++){
            for(int j=0; j<A.br_red; j++){
                for(int k=0; k<A.br_kol; k++){
                    mpolinom[j][k]+=
                }
            }
        }
    }
    catch(...){
        UnistiMatricu(mpolinom);
        UnesiMatricu(jedinicna);
    }
    return mpolinom;
}

int main ()
{
	return 0;
}