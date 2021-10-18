/B2017/2018: Zadaća 3, Zadatak 3
#include <iostream>
#include <iomanip>
#include <stdexcept>
#include <new>
#include <vector>

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
    mat.elementi=new TipElemenata*[br_redova];
    for(int i=0; i<br_redova; i++) mat.elementi[i]=nullptr;
    try {
        for(int i=0; i<br_redova; i++) mat.elementi[i]=new TipElemenata[br_kolona];
    } catch(...) {
        UnistiMatricu(mat);
        throw;
    }
    return mat;
}

template<typename TipElemenata>
void UnesiMatricu(char ime_matrice, Matrica<TipElemenata> &mat)
{
    for(int i=0; i<mat.br_redova; i++) {
        for(int j=0; j<mat.br_kolona; j++) {
            std::cout<<ime_matrice<<"("<<i+1<<","<<j+1<<") = ";
            std::cin>>mat.elementi[i][j];
        }
    }
}

template<typename TipElemenata>
void IspisiMatricu(const Matrica<TipElemenata> &mat, int sirina_ispisa, int preciznost=6, bool treba_brisati=false)
{
    for(int i=0; i<mat.br_redova; i++) {
        for(int j=0; j<mat.br_kolona; j++) std::cout<<std::setw(sirina_ispisa)<<std::setprecision(preciznost)<<mat.elementi[i][j];
        std::cout<<std::endl;
    }
    if(treba_brisati) UnistiMatricu(mat);
}

template <typename TipElemenata>
Matrica<TipElemenata> ZbirMatrica(const Matrica<TipElemenata> &m1, const Matrica<TipElemenata> &m2)
{
    if(m1.br_redova!=m2.br_redova || m1.br_kolona!=m2.br_kolona) throw std::domain_error("Matrice nemaju jednake dimenzije!");
    auto m3(StvoriMatricu<TipElemenata>(m1.br_redova, m1.br_kolona));
    for(int i=0; i<m1.br_redova; i++)
        for(int j=0; j<m1.br_kolona; j++) m3.elementi[i][j]=m1.elementi[i][j]+m2.elementi[i][j];
    return m3;
}

template<typename TipElemenata>
Matrica<TipElemenata> ProduktMatrica(Matrica<TipElemenata> m1, Matrica<TipElemenata> m2)
{
    if(m1.br_kolona!=m2.br_redova) throw std::domain_error("Matrice nisu saglasne za mnozenje");
    auto m3(StvoriMatricu<TipElemenata>(m1.br_redova, m2.br_kolona));
    for(int i=0; i<m1.br_redova; i++) {
        for(int j=0; j<m1.br_redova; j++) {
            double suma(0);
            int br(0);
            while(br<m1.br_kolona) {
                suma+=m1.elementi[i][br]*m2.elementi[br][j];
                br++;
            }
            m3.elementi[i][j]=suma;
        }
    }
    return m3;
}

template<typename TipElemenata>
Matrica<TipElemenata> ProizvodMatriceISkalara(Matrica<TipElemenata> m, double broj)
{
    Matrica<TipElemenata> proizvod(StvoriMatricu<TipElemenata>(m.br_redova, m.br_kolona));
    for(int i=0; i<m.br_redova; i++)
        for(int j=0; j<m.br_kolona; j++) proizvod.elementi[i][j]=broj*m.elementi[i][j];
    return proizvod;
}

template<typename TipElemenata>
void JedinicnaMatrica(Matrica<TipElemenata> &m)
{
    for(int i=0; i<m.br_redova; i++)
        for(int j=0; j<m.br_kolona; j++)
            if(i==j) m.elementi[i][j]=1;
            else m.elementi[i][j]=0;
}

template<typename TipElemenata, typename TipIteratora>
Matrica<TipElemenata> MatricniPolinom(const Matrica<TipElemenata> &a, int red, TipIteratora it)
{
    if(red<0) throw std::domain_error("Neispravan stepen polinoma");
    if(a.br_redova!=a.br_kolona) throw std::domain_error("Matrica mora biti kvadratna");
    Matrica<TipElemenata> p(StvoriMatricu<TipElemenata>(a.br_redova, a.br_kolona));
    JedinicnaMatrica(p);
    for(int i=0; i<p.br_redova; i++)
        for(int j=0; j<p.br_kolona; j++) p.elementi[i][j]*=*it;
    it++;
    Matrica<TipElemenata> pom(StvoriMatricu<TipElemenata>(a.br_redova, a.br_kolona));
    JedinicnaMatrica(pom);
    for(int stepen=0; stepen<red; stepen++) {
        auto pom2(pom);
        pom=ProduktMatrica(a, pom);
        auto tmp(ProizvodMatriceISkalara(pom, *it));
        auto p2(p);
        p=ZbirMatrica(p2, tmp);
        it++;
        UnistiMatricu(pom2);
        UnistiMatricu(p2);
        UnistiMatricu(tmp);
    }
    UnistiMatricu(pom);
    return p;
}

int main ()
{
    int dimenzija, red;
    std::cout<<"Unesite dimenziju kvadratne matrice: ";
    std::cin>>dimenzija;
    Matrica<double> mat(StvoriMatricu<double>(dimenzija, dimenzija));
    std::cout<<"Unesite elemente matrice A: "<<std::endl;
    UnesiMatricu('A', mat);
    std::cout<<"Unesite red polinoma: ";
    std::cin>>red;
    std::cout<<"Unesite koeficijente polinoma: ";
    std::vector<double> v(red+1);
    for(int i=0; i<=red; i++) {
        std::cin>>v[i];
    }
    auto mat_polinom(MatricniPolinom(mat, red, v.begin()));
    IspisiMatricu(mat_polinom, 10);
    UnistiMatricu(mat);
    UnistiMatricu(mat_polinom);
    return 0;
}