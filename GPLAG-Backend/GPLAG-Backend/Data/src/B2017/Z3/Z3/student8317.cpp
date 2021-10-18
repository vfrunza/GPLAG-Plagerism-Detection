/B2017/2018: Zadaća 3, Zadatak 3
#include <iostream>
#include<iomanip>
#include<stdexcept>
#include<iterator>
#include<vector>
#include<new>

template<typename TipElemenata>
struct Matrica {
    int br_redova,br_kolona;
    TipElemenata **elementi=nullptr;
};

template<typename TipElemenata>
void UnistiMatricu(Matrica<TipElemenata>mat)
{
    if(!mat.elementi) return;
    for(int i=0; i<mat.br_redova; i++)
        delete [] mat.elementi[i];
    delete [] mat.elementi;
    mat.elementi=nullptr;
}
template<typename TipElemenata>
Matrica<TipElemenata> StvoriMatricu(int br_redova,int br_kolona)
{
    Matrica<TipElemenata> mat;
    mat.br_redova=br_redova;
    mat.br_kolona=br_kolona;
    mat.elementi=new TipElemenata*[br_redova];
    for(int i=0; i<br_redova; i++)
        mat.elementi[i]=nullptr;
    try {
        for(int i=0; i<br_redova; i++)
            mat.elementi[i]=new TipElemenata[br_kolona];

    } catch(...) {
        UnistiMatricu(mat);
        throw;
    }
    return mat;
}
template<typename TipElemenata>
void UnesiMatricu(char ime_matrice,Matrica<TipElemenata> &mat)
{
    for(int i=0; i<mat.br_redova; i++) {
        for(int j=0; j<mat.br_kolona; j++) {
            std::cout<<ime_matrice<<"("<<i+1<<","<<j+1<<") = ";
            std::cin>>mat.elementi[i][j];
        }
    }
}

template<typename TipElemenata>
void IspisiMatricu(const Matrica<TipElemenata>&mat,int sirina_ispisa,int preciznost=6,bool treba_brisati=false)
{
    for(int i=0; i<mat.br_redova; i++) {
        for(int j=0; j<mat.br_kolona; j++) {
            std::cout<<std::setw(sirina_ispisa)<<std::setprecision(preciznost)<<mat.elementi[i][j];

        }
        std::cout<<std::endl;
    }
    if(treba_brisati)
        UnistiMatricu(mat);
}
template<typename TipElemenata>
Matrica<TipElemenata> ZbirMatrica(const Matrica<TipElemenata> &m1,const Matrica<TipElemenata> &m2)
{
    if(m1.br_redova!=m2.br_redova || m1.br_kolona!=m1.br_kolona)
        throw std::domain_error("Matrice nemaju jednake dimenzije!");
    auto m3(StvoriMatricu<TipElemenata>(m1.br_redova,m1.br_kolona));
    for(int i=0; i<m1.br_redova; i++)
        for(int j=0; j<m2.br_kolona; j++)
            m3.elementi[i][j]=m1.elementi[i][j]+m2.elementi[i][j];
    return m3;
}
template<typename TipElemenata>
Matrica<TipElemenata> ProduktMatrica(const Matrica<TipElemenata> &m1,const Matrica<TipElemenata> &m2)
{
    if(m1.br_redova!=m2.br_kolona)
        throw std::domain_error("Matrice nisu saglasne za mnozenje");
    auto m3(StvoriMatricu<TipElemenata>(m1.br_redova,m2.br_kolona));
    for(int i=0; i<m1.br_redova; i++) {
        for(int j=0; j<m2.br_kolona; j++) {
            TipElemenata suma=0;
            for(int k=0; k<m2.br_redova; k++)
                suma=m1.elementi[i][k]*m2.elementi[k][j];
            m3.elementi[i][j]=suma;
        }
    }
    return m3;
}
template<typename TipElemenata>
Matrica <TipElemenata> PomnoziSaSkalarom(const Matrica<TipElemenata> &m1, double n)
{
    Matrica<TipElemenata> Rezultat(StvoriMatricu<TipElemenata>(m1.br_redova,m1.br_kolona));
    for(int i=0; i<Rezultat.br_redova; i++)
        for(int j=0; j<Rezultat.br_kolona; j++)
            Rezultat.elementi[i][j]=m1.elementi[i][j]*n;
    return Rezultat;
}
/*template<typename TipElemenata>
Matrica<TipElemenata> MatricniPolinom(const Matrica<TipElemenata> &m,int n,std::vector<int>::iterator it)
{
    if(n<0) throw std::domain_error("Neispravan stepen polinoma");
    if(m.br_kolona!=m.br_redova) throw std::domain_error("Matrica mora biti kvadratna");
    Matrica<TipElemenata> MPolinom;
}*/
int main ()
{
    Matrica<int> mat;
    int dimenzija;
    std::cout<<"Unesi dimenziju kvadratne matrice:\n";
    std::cin>>dimenzija;
    try {
        mat=StvoriMatricu<int>(dimenzija,dimenzija);
        std::cout<<"Unesite elemente matrice A:\n";
        UnesiMatricu('A',mat);
        std::cout<<"Unesite red polinoma: ";
        int red;
        std::cin>>red;
        std::cout<<"Unesite koeficijente polinoma: ";
        std::vector<int>a(dimenzija*dimenzija);
        for(int i=0; i<dimenzija*dimenzija; i++) {
            int elementi;
            std::cin>>elementi;
            a.push_back(elementi);
        }
        //IspisiMatricu(MatricniPolinom(mat,a.begin()),10,6,true);
    } catch(std::bad_alloc) {
        std::cout<<"Problemi s memorijom!";
    } catch(std::domain_error izuzetak) {
        std::cout<<izuzetak.what();
    }
    UnistiMatricu(mat);
    return 0;
}
