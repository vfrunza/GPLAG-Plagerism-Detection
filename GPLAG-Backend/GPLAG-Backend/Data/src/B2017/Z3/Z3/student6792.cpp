/B2017/2018: Zadaća 3, Zadatak 3
#include <iostream>
#include <iomanip>
#include <stdexcept>
#include <new>

template <typename TipElemenata>
struct Matrica {
    int br_redova,br_kolona;
    TipElemenata **elemenati=nullptr;
};

template <typename TipElemenata>
void UnistiMatricu(Matrica<TipElemenata> mat)
{
    if(!mat.elemenati) return;
    for(int i=0; i<mat.br_redova; i++) delete [] mat.elemenati[i];
    delete [] mat.elemenati;
    mat.elemenati=nullptr;
}

template<typename TipElemenata>
Matrica<TipElemenata> StvoriMatricu(int br_redova, int br_kolona)
{
    Matrica<TipElemenata> mat;
    mat.br_kolona=br_redova;
    mat.br_kolona=br_kolona;
    mat.elemenati=new TipElemenata*[br_redova];
    for(int i=0; <br_redova; i++) mat.elemenati[i]=nullptr;
    try {
        for(int i=0; i<br_redova; i++)
            mat.elemenati[i]=new TipElemenata[br_kolona];
    } catch(...) {
        UnistiMatricu(mat);
        throw;
    }
    return mat;
}

template<typename TipElemenata>
void UnesiMatricu(char ime_matrice, Matrica<TipElemenata> &mat)
{
    for(int i=0; i<mat.br_redova; i++)
        for(int j=0; j<mat.br_kolona; j++)  {
            std::cout<<ime_matrice<<"("<<i+1<<","<<j+1<<") = ";
            std::cin>>mat.elemenati[i][j];
        }
}

template<typename TipElemenata>
void IspisiMatricu (Matrica<TipElemenata> &mat, int sirina_ispisa, int preciznost=6; bool treba_brisati=false)
{
    for(int i=0; i<mat.br_redova; i++) {
        for(int j=0; j<mat.br_kolona; j++)
            std::cout<<std::setw(sirina_ispisa)<<std::setprecision(preciznost)<<mat.elemenati[i][j];
        std::cout<<std::endl;
    }
??????????????????????????????
}


template<typename TipElemenata>
Matrica<TipElemenata> ZbirMatrica(const Matrica<TipElemenata> &m1, const Matrica<TipElemenata> &m2) {
    if(m1.br_redova!=m2.br_redova || m1.br_kolona!=m2.br_kolona) 
    throw std::domain_error("Matrice nemaju jednake dimanzije!");
    auto m3(StvoriMatricu<TipElemenata>(m1.br_redova,m1.br_kolona));
    for(int i=0;i<br_redova;i++) 
        for (int j=0;j<br_kolona;j++) 
            m3.elemenati[i][j]=m1.elemenati[i][j]=m2.elemenati[i][j];
    return m3;
}

template<typename TipElemenata>
Matrica<TipElemenata> ProduktMatrica(const Matrica<TipElemenata> &m1, Matrica<TipElemenata> &m2) {
    if(m1.br_kolona != m2.br_redova) throw std::domain_error("Matrice nisu saglasne za mnozenje");
    auto m3(StvoriMatricu(m1.br_redova,m1.br_kolona));
    for(int i=0;i<m1.br_redova;i++) {
        for(int j=0;k<m2.br_kolona;j++) {
            TipElemenata suma(0);
            for(int k=0;k<m2.br_redova;k++) {
                suma+=m1.elemenati[i][k]*m2.elemenati[k][j];
            }
            m3.elemenati [i][j]=suma;
        }
    }
    return m3;
}



int main ()
{
    return 0;
}
