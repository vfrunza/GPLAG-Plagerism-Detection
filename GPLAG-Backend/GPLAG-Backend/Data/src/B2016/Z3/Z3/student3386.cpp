/B2016/2017: Zadaća 3, Zadatak 3
#include <iostream>
#include <iomanip>
#include <stdexcept>
#include <new>
#include <vector>

using std::vector;

template <typename TipElemenata>
struct Matrica
{
    int br_redova, br_kolona;
    TipElemenata **elementi = nullptr; // VEOMA BITNA INICIJALIZACIJA!
};
template <typename Tip>
void Jednako(Matrica<Tip> &mat1,Matrica<Tip> mat2)
{
    for(int i=0;i<mat1.br_redova;i++)
        for(int j=0;j<mat1.br_kolona;j++)
            mat1.elementi[i][j]=mat2.elementi[i][j];
}
template <typename Tip>
void Nuliraj(Matrica<Tip> &mat)
{
    for(int i=0;i<mat.br_redova;i++)
        for(int j=0;j<mat.br_kolona;j++)
            mat.elementi[i][j]=0;
}
template <typename TipElemenata>
void UnistiMatricu(Matrica<TipElemenata> mat)
{
    if(!mat.elementi) return;
    for(int i = 0; i < mat.br_redova; i++) delete[] mat.elementi[i];
    delete[] mat.elementi;
    mat.elementi = nullptr;
}
template <typename TipElemenata>
Matrica<TipElemenata> StvoriMatricu(int br_redova, int br_kolona)
{
    Matrica<TipElemenata> mat;
    mat.br_redova = br_redova;
    mat.br_kolona = br_kolona;
    mat.elementi = new TipElemenata*[br_redova];
    for(int i = 0; i < br_redova; i++) mat.elementi[i] = nullptr;
    try
    {
        for(int i = 0; i < br_redova; i++)
            mat.elementi[i] = new TipElemenata[br_kolona];
    }
    catch(...)
    {
        UnistiMatricu(mat);
        throw;
    }
    return mat;
}
template <typename TipElemenata>
void UnesiMatricu(char ime_matrice, Matrica<TipElemenata> &mat)
{
    for(int i = 0; i < mat.br_redova; i++)
        for(int j = 0; j < mat.br_kolona; j++)
        {
            std::cout << ime_matrice
                      << "(" << i + 1 << "," << j + 1 << ") = ";
            std::cin >> mat.elementi[i][j];
        }
}
template <typename TipElemenata>
void IspisiMatricu(const Matrica<TipElemenata> &mat,int sirina_ispisa,int preciznost=6,bool treba_brisati=false)
{
    for(int i = 0; i < mat.br_redova; i++)
    {
        for(int j = 0; j < mat.br_kolona; j++)
            std::cout << std::setw(sirina_ispisa) <<std::setprecision(preciznost)<< mat.elementi[i][j];
        std::cout << std::endl;
    }
    if(treba_brisati)
        UnistiMatricu(mat);
}
template <typename TipElemenata>
Matrica<TipElemenata> ZbirMatrica(const Matrica<TipElemenata> &m1, const Matrica<TipElemenata> &m2)
{
    if(m1.br_redova != m2.br_redova || m1.br_kolona != m2.br_kolona)
        throw std::domain_error("Matrice nemaju jednake dimenzije!");
    auto m3(StvoriMatricu<TipElemenata>(m1.br_redova, m1.br_kolona));
    for(int i = 0; i < m1.br_redova; i++)
        for(int j = 0; j < m1.br_kolona; j++)
            m3.elementi[i][j] = m1.elementi[i][j] + m2.elementi[i][j];
    return m3;
}
template <typename Tip>
Matrica<Tip> ProduktMatrica(const Matrica<Tip> &mat1,const Matrica<Tip> &mat2)
{
    if(mat1.br_kolona!=mat2.br_redova)
        throw std::domain_error("Matrice nisu saglasne za mnozenje");
    auto nova(StvoriMatricu<Tip>(mat1.br_redova,mat2.br_kolona));
    Nuliraj(nova);
    for(int i=0;i<mat1.br_redova;i++)
        for(int j=0;j<mat2.br_kolona;j++)
            for(int k=0;k<mat1.br_kolona;k++)
                nova.elementi[i][j]+=mat1.elementi[i][k]*mat2.elementi[k][j];
    return nova;
}
template <typename Tip>
Matrica<Tip> MnozenjeSkalarom(Matrica<Tip> &mat,double x)
{
    for(int i=0;i<mat.br_redova;i++)
        for(int j=0;j<mat.br_kolona;j++)
            mat.elementi[i][j]*=x;
    return mat;
}
template <typename Tip>
Matrica<Tip> MatricniPolinom(Matrica<Tip> &mat,vector<double> v)
{
    if(mat.br_kolona!=mat.br_redova)    
        throw std::domain_error("Matrica mora biti kvadratna");
    Matrica<Tip> nova(StvoriMatricu<Tip>(mat.br_redova,mat.br_kolona));
    Nuliraj(nova);
    if(v.size()==0)
        return nova;
    for(int i=0;i<mat.br_redova;i++)
            nova.elementi[i][i]=v[0];
    try
    {
        Matrica<Tip> pomoc=StvoriMatricu<Tip>(mat.br_redova,mat.br_kolona);
        Nuliraj(pomoc);
        Jednako(pomoc,mat);
        try
        {
            Matrica<Tip> neka=StvoriMatricu<Tip>(mat.br_redova,mat.br_kolona);
            Nuliraj(neka);
            Jednako(neka,pomoc);
            for(int i=1;i<v.size();i++)
            {
                auto pomoc2(nova);
                nova=ZbirMatrica(nova, MnozenjeSkalarom(neka, v[i]));
                UnistiMatricu(pomoc2);
                auto x(pomoc);
                pomoc=ProduktMatrica(pomoc,mat);
                UnistiMatricu(x);
                Jednako(neka,pomoc);
            }
            UnistiMatricu(neka);
            UnistiMatricu(pomoc);
            return nova;
        }
        catch(std::bad_alloc)
        {
            UnistiMatricu(pomoc);
            throw;
        }
    }
    catch(std::bad_alloc)
    {
        UnistiMatricu(nova);
        throw;
    }
}
int main1()
{
     Matrica<double> m1;
    Matrica<double> m2;
    m1 = StvoriMatricu<double>(2,3);
    UnesiMatricu<double>('1', m1);
    m2 = StvoriMatricu<double>(3,4);
    UnesiMatricu<double>('2', m2);
    Matrica<double> produkt = ProduktMatrica(m1, m2);
    IspisiMatricu(produkt, 3);
    UnistiMatricu(m1);
    UnistiMatricu(m2);
    UnistiMatricu(produkt);
    return 0;
}
int main()
{
    Matrica<double> a,c; // AUTOMATSKA INICIJALIZACIJA!!!
    int m;
    std::cout << "Unesite dimenziju kvadratne matrice: ";
    std::cin >> m;
    try
    {
        a = StvoriMatricu<double>(m, m);
        Nuliraj(a);
        std::cout << "Unesite elemente matrice A:\n";
        UnesiMatricu('A', a);
        std::cout<<"Unesite red polinoma: ";
        int n;
        std::cin>>n;
        vector<double> v(n+1);
        std::cout<<"Unesite koeficijente polinoma: ";
        for(int i=0;i<v.size();i++)
            std::cin>>v[i];
        c=MatricniPolinom(a,v);
        IspisiMatricu(c,10,6);
        /*
        std::cout << "Zbir ove dvije matrice je:\n";
        IspisiMatricu(c = ZbirMatrica(a, b), 7);*/
    }
    catch(std::domain_error e)
    {
        std::cout<<e.what();
        return 0;
    }
    catch(std::bad_alloc)
    {
        std::cout << "Nema dovoljno memorije!\n";
    }
    UnistiMatricu(a);
    UnistiMatricu(c);
    return 0;
}
