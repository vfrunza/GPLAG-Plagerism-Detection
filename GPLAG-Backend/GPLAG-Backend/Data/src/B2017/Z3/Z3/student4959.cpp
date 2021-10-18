/B2017/2018: Zadaća 3, Zadatak 3
#include <iostream>
#include <iomanip>
#include <stdexcept>
#include <new>
#include <vector>

template <typename TipElemenata>
struct Matrica{
    int br_redova, br_kolona;
    TipElemenata **elementi = nullptr;
};

template <typename TipElemenata>
void UnistiMatricu(Matrica<TipElemenata> mat){
    if(!mat.elementi)return;
    for(int i(0); i<mat.br_redova; i++)
        delete [] mat.elementi[i];
    delete [] mat.elementi;
    mat.elementi = nullptr;
}

template <typename TipElemenata>
Matrica<TipElemenata> StvoriMatricu (int br_redova, int br_kolona){
    
    Matrica<TipElemenata> mat;
    
    mat.br_kolona = br_kolona;
    mat.br_redova = br_redova;
    
    mat.elementi = new TipElemenata*[br_redova];
    for(int i(0); i<br_redova;i++)mat.elementi[i] = nullptr;
    
    try {
        for(int i(0); i<br_redova; i++)
            mat.elementi[i] = new TipElemenata[br_kolona];
    }
    catch (...) {
        UnistiMatricu(mat);
        throw;
    }
    
    return mat;
}

template <typename TipElemenata>
void UnesiMatricu (char ime_matrice, Matrica<TipElemenata> &mat){
    for(int i(0);i<mat.br_redova;i++)
        for(int j(0); j<mat.br_kolona; j++){
            std::cout<<ime_matrice
            <<"("<<i+1<<","<<j+1<<") = ";
            std::cin>>mat.elementi[i][j];
        }
}

template <typename TipElemenata>
void IspisiMatricu(const Matrica<TipElemenata> &mat, int sirina_ispisa, int preciznost = 6, bool treba_brisati = false){
    for(int i(0); i<mat.br_redova; i++){
        for(int j(0); j<mat.br_kolona; j++)
            std::cout<<std::setw(sirina_ispisa)<<std::setprecision(preciznost)<<mat.elementi[i][j];
        std::cout<<std::endl;    
    }
    if(treba_brisati)UnistiMatricu(mat);
}

template <typename TipElemenata>
Matrica<TipElemenata> ZbirMatrica(const Matrica<TipElemenata> &m1,
const Matrica<TipElemenata> &m2){
    if(m1.br_redova != m2.br_redova || m1.br_kolona != m2.br_kolona)
        throw std::domain_error("Matrice nemaju jenake dimenzije");
    auto m3(StvoriMatricu<TipElemenata>(m1.br_redova, m1.br_kolona));
    for(int i(0); i<m3.br_redova; i++)
        for(int j(0); j<m3.br_kolona; j++)
            m3.elementi[i][j] = m1.elementi[i][j] + m2.elementi[i][j];
    return m3;        
}


template <typename TipElemenata>
Matrica<TipElemenata> ProduktMatrica(const Matrica<TipElemenata> &m1,const Matrica<TipElemenata> &m2){
    if(m1.br_kolona != m2.br_redova)
        throw std::domain_error("Matrice nisu saglasne za mnozenje");
        auto m3(StvoriMatricu<TipElemenata>(m1.br_redova,m2.br_kolona));
        for(int i(0);i<m1.br_redova;i++)
            for(int j(0);j<m2.br_kolona;j++){
                m2.elementi[i][j] = 0;
                for(int k(0);k<m1.br_kolona;k++)
                    m3.elementi[i][j]+= (m1.elementi[i][k]*m2.elementi[k][j]);
            }
    return m3;        
}

template <typename TipElemenata>
void MnozenjeSkalarom(Matrica<TipElemenata> &m, TipElemenata skalar){
    for(int i(0);i<m.br_redova;i++)
        for(int j(0);j<m.br_kolona;j++)
            m.elementi[i][j]*=skalar;
}

template <typename TipElemenata>
Matrica <TipElemenata> MatricniPolinom(Matrica<TipElemenata> m, int n, TipElemenata *pk){
    if(n<0)throw std::domain_error("Neispravan stepen polinoma");
    if(m.br_kolona != m.br_redova)throw std::domain_error("Matrica mora biti kvadratna");
    
    
    
}
int main ()
{
    std::cout<<"Unesite dimenenziju kvadratne matrice: ";
    int dim;
    std::cin>>dim;
    try{
        auto m(StvoriMatricu<int>(dim,dim));
        
        std::cout<<"Unesite elemente matrice A: ";
        UnesiMatricu('A',m);
        
        std::cout<<"Unesite red polinoma: ";
        int n;
        std::cin>>n;
        std::cout<<"Unesite koeficijente polinoma";
        std::vector<int> koef(n+1);
        for(int i(0);i<n+1;i++)
            std::cin>>koef.at(i);
        auto mp(MatricniPolinom(m,n,&koef[0]));
        IspisiMatricu(mp,10);
        UnistiMatricu(mp);
        UnistiMatricu(m);
    }catch(std::domain_error e){
        std::cout<<e.what();
    }
	return 0;
}
