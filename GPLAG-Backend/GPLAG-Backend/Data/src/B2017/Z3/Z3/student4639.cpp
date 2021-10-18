

/B2017/2018: Zadaća 3, Zadatak 3
#include <iostream>
#include <vector>
#include <iomanip>
#include <stdexcept>
#include <new>
template <typename TipElemenata>
struct Matrica {
    int br_redova,br_kolona;
    TipElemenata **elementi=nullptr;
};
template<typename TipElemenata>
void UnistiMetricu(Matrica<TipElemenata> mat)
{
    if(!mat.elementi) return;
    for(int i=0; i<mat.br_redova;  i++) delete[] mat.elementi[i];
    delete[] mat.elementi;
    mat.elementi=nullptr;

}

template<typename TipElemenata>
Matrica<TipElemenata> StvoriMatricu(int br_redova, int br_kolona)
{
    Matrica<TipElemenata> mat;
    mat.br_redova=br_redova;
    mat.br_kolona=br_kolona;
    mat.elementi= new TipElemenata*[br_redova];
    for(int i=0; i<br_redova; i++) mat.elementi[i]=nullptr;
    try {
        for(int i=0; i<br_kolona; i++) mat.elementi[i]=new TipElemenata[br_kolona];
    } catch(...) {
        UnistiMetricu(mat);
        throw;
    }
    return mat;
}
template<typename TipElemenata>
void UnesiMatricu(char ime_matrice, Matrica<TipElemenata> &mat)
{
    for(int i=0; i<mat.br_redova; i++)
        for(int j=0; j<mat.br_kolona; j++) {
            std::cout<<ime_matrice<<"("<<i+1<<","<<j+1<<") = ";
            std::cin>>mat.elementi[i][j];
        }
}
template<typename TipElemenata>
void IspisiMatricu(const Matrica<TipElemenata> &mat, int sirina_ispisa,int preciznost=6,bool treba_brisati=false)
{
    for(int i=0; i<mat.br_redova; i++) {
        for(int j=0; j<mat.br_kolona; j++)
            std::cout<<std::setw(sirina_ispisa)<<std::setprecision(preciznost)<<mat.elementi[i][j];
        std::cout<<std::endl;
        if(treba_brisati) UnistiMetricu(mat);

    }
}

template <typename TipElemenata>
Matrica<TipElemenata> ZbirMatrica(const Matrica<TipElemenata> &m1,const Matrica<TipElemenata> &m2)
{
    if(m1.br_redova!=m2.br_redova || m1.br_kolona!=m2.br_kolona)
        throw std::domain_error("Matrice nemaju jednake dimenzije!");
    auto m3(StvoriMatricu<TipElemenata>(m1.br_redova,m1.br_kolona));
    for(int i=0; i<m3.br_redova; i++)
        for(int j=0; j<m3.br_kolona; j++)
            m3.elementi[i][j]=m1.elementi[i][j]+m2.elementi[i][j];
    return m3;
}


template <typename TipElemenata>
Matrica<TipElemenata> ProduktMatrica(const Matrica<TipElemenata> &mat1,const Matrica<TipElemenata> &mat2)
{

    if(mat1.br_kolona!=mat2.br_redova) throw std::domain_error("Matrice nisu saglasne za mnozenje");
    Matrica<TipElemenata> mat3(StvoriMatricu<TipElemenata>(mat1.br_kolona,mat2.br_redova));
    for(int i=0; i<mat1.br_redova; i++) {
        for(int j=0; j<mat2.br_kolona; j++) {
            int suma(0);
            for(int k=0; k<mat1.br_kolona; k++)
                suma+=mat1.elementi[i][k]*mat2.elementi[k][j];
            mat3[i][j]=suma;
        }
    }
    return mat3;
}
template <typename TipElemenata, typename Tip>
Matrica<TipElemenata> MaricniPolinom(Matrica<TipElemenata> mat, int stepen, Tip poc)
{
    if(stepen<0) throw std::domain_error("Neispavan stepen polinoma");
    if(mat.br_kolona!=mat.br_redova) throw std::domain_error("Matrica mora biti kvadratna");
    Matrica<TipElemenata> I(StvoriMatricu<TipElemenata>(mat.br_redova,mat.br_kolona));
    for(int i=0; i<mat.br_redova; i++)
        for(int j=0; j<mat.br_kolona; j++) {
            if(i=j) I.elementi[i][j]=*poc;
            else I.elementi[i][j]=0;
        }
    Matrica<TipElemenata>mat1(StvoriMatricu<TipElemenata>(mat.br_redova,mat.br_kolona));
    if(stepen>=1) {

        Matrica<TipElemenata>mat2(StvoriMatricu<TipElemenata>(mat.br_redova,mat.br_kolona));

        
        for(int i=0; i<mat.br_redova; i++)
            for(int j=0; j<mat.br_kolona; j++) {
                mat1.elementi[i][j]=(*poc)*mat.elementi[i][j];
                mat2.elementi[i][j]=mat.elementi[i][j];
            }

        if(stepen=1) return ZbirMatrica(I,mat1);
        else if(stepen>1) {
            mat1=ZbirMatrica(I,mat1);
            for(int k=2; k<stepen; k++) {
                mat2=mat;                   //ne moze ovako
                for(int i=0; i<k; i++) {
                    mat2=ProduktM(mat2,mat);
                }
                poc++;
                for(int j=0; j<mat.br_redova; j++) {
                    for(int i=0; i<mat.br_kolona; i++)
                        mat2[i][j]=(*poc)*mat2[i][j];

                }
                mat1=ZbirMatrica(mat2,mat1);
            }
        }
    }
    return mat1;
}
int main ()
{
    Matrica<double>a,b,c;
    int k,n;
    std::cout<<"Unesite dimenziju kvadratne matrice: ";
    std::cin>>n;
    a=StvoriMatricu<double>(n,n);
    b=StvoriMatricu<double>(n,n);
    std::cout<<"Unesite elemente matricu A: "<<std::endl;
    UnesiMatricu('A',a);

    std::cout<<"Unesite red polinoma: ";
    std::cin>>k;
    std::cout<<"Unesite koeficijente polinoma: ";
    std::vector<int> poc;
    for(int i=0; i<=k; i++) {
        int broj;
        std::cin>>broj;

        poc.push_back(broj);
    }
    c=MaricniPolinom(a,k,poc);
    IspisiMatricu(c,6,6,false);
    return 0;
}
