/B2016/2017: Zadaća 3, Zadatak 3
#include <iostream>
#include <iomanip>
#include <stdexcept>
#include <new>
#include<vector>
#include<cmath>
template <typename TipElemenata>
struct Matrica {
    int br_redova, br_kolona;
    TipElemenata **elementi = nullptr; // VEOMA BITNA INICIJALIZACIJA!
};
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
    try {
        for(int i = 0; i < br_redova; i++)
            mat.elementi[i] = new TipElemenata[br_kolona];
    } catch(...) {
        UnistiMatricu(mat);
        throw;
    }
    return mat;
}
//za potrebe zadatka, trebace nam funkcija za dealociranje memorije
template< typename tip>
void Dealociraj(Matrica<tip> m)
{
    if(m.elementi==nullptr) return;
    for(int i=0;i<m.br_redova;i++)
    delete [] m.elementi[i];
    delete [] m.elementi;
    m.elementi=nullptr;
}
template <typename TipElemenata>
void UnesiMatricu(char ime_matrice, Matrica<TipElemenata> &mat)
{
    for(int i = 0; i < mat.br_redova; i++)
        for(int j = 0; j < mat.br_kolona; j++) {
            std::cout << ime_matrice
                      << "(" << i + 1 << "," << j + 1 << ") = ";
            std::cin >> mat.elementi[i][j];
        }
}
template <typename TipElemenata>
void IspisiMatricu(const Matrica<TipElemenata> &mat,
                   int sirina_ispisa)
{
    for(int i = 0; i < mat.br_redova; i++) {
        for(int j = 0; j < mat.br_kolona; j++)
            std::cout << std::setw(sirina_ispisa) << mat.elementi[i][j];
        std::cout << std::endl;
    }
}
template <typename TipElemenata>
Matrica<TipElemenata> ZbirMatrica(const Matrica<TipElemenata> &m1,
                                  const Matrica<TipElemenata> &m2)
{
    if(m1.br_redova != m2.br_redova || m1.br_kolona != m2.br_kolona)
        throw std::domain_error("Matrice nemaju jednake dimenzije!");
    auto m3(StvoriMatricu<TipElemenata>(m1.br_redova, m1.br_kolona));
    for(int i = 0; i < m1.br_redova; i++)
        for(int j = 0; j < m1.br_kolona; j++)
            m3.elementi[i][j] = m1.elementi[i][j] + m2.elementi[i][j];
    return m3;
}
//generička funkcija produkt matrica
template<typename tip>
Matrica<tip> ProduktMatrica(Matrica<tip> &m1, Matrica<tip> &m2)
{
    if(m1.br_kolona!=m2.br_redova) throw std::domain_error("Matrice nisu saglasne za mnozenje");
    auto rezultat=StvoriMatricu<tip>(m1.br_redova, m2.br_kolona);
    int brojRedova=m1.br_redova;
    int brojKolona=m2.br_kolona;
    for(int i=0;i<brojRedova;i++)
    {
        for(int j=0;j<brojKolona;j++)
        {
            tip zbir=0;
            for(int k=0;k<m1.br_kolona;k++)
            {
                zbir=zbir+m1.elementi[i][k]*m2.elementi[k][j];
            }
            rezultat.elementi[i][j]=zbir;
      }
    }
    return rezultat;
}

//matricni polinom
template<typename tip>
Matrica<tip> MatricniPolinom(Matrica<tip> &m1, std::vector<double> koef)
{
    if(m1.br_redova!=m1.br_kolona) throw std::domain_error("Matrica mora biti kvadratna");
    if(koef.size()==0)
    {
        for(int i=0;i<m1.br_redova;i++)
        for(int j=0;j<m1.br_kolona;j++)
        m1.elementi[i][j]=0;
        return m1;
    }
    Matrica<tip> jedinicnaMatrica=StvoriMatricu<tip>(m1.br_redova,m1.br_kolona);
    for(int i=0;i<m1.br_redova;i++)
        for(int j=0;j<m1.br_kolona;j++)
        if(i==j)
        jedinicnaMatrica.elementi[i][j]=1;
        else
        jedinicnaMatrica.elementi[i][j]=0;
    Matrica<tip> rezultat=StvoriMatricu<tip>(m1.br_redova,m1.br_kolona);
    for(int i=0;i<m1.br_redova;i++)
        for(int j=0;j<m1.br_kolona;j++)
        rezultat.elementi[i][j]=0;
    //ovdje ide množenje sa svakim od koef
  
    for(int i=0;i<koef.size();i++)
    {
        //prvo odredi matricu sa kojom mnozis skalar
        Matrica<tip> xMatrica;
        if(i==0)
        xMatrica=ProduktMatrica(jedinicnaMatrica,jedinicnaMatrica);
        else
        {
            Matrica<tip> x;
            for(int j=1;j<=i;j++)
            {
                if(j==1)
                {
                xMatrica=ProduktMatrica(m1,jedinicnaMatrica);
                }
                else
                {
                    x=ProduktMatrica(xMatrica,jedinicnaMatrica);
                    Dealociraj(xMatrica);
                    xMatrica=ProduktMatrica(x,m1);
                }
                Dealociraj(x);
            }
        }

        //pomnozi sa skalarom
        for(int p=0;p<xMatrica.br_redova;p++)
        for(int r=0;r<xMatrica.br_kolona;r++)
        xMatrica.elementi[p][r]=xMatrica.elementi[p][r]*koef[i];
        //dodaj rezultatnoj matrici
        for(int p=0;p<xMatrica.br_redova;p++)
        for(int r=0;r<xMatrica.br_kolona;r++)
        rezultat.elementi[p][r]= rezultat.elementi[p][r]+xMatrica.elementi[p][r];

        //dealociraj
        Dealociraj(xMatrica);
    }

    Dealociraj(jedinicnaMatrica);
    return rezultat;
}
template<typename tip>
void IspisiMatricu(Matrica<tip> &m1, int sirina=6, int preciznost=6,bool treba_brisati=false)
{
    bool nijeInt=false;
    for(int i=0;i<m1.br_redova;i++)
    {
        for(int j=0;j<m1.br_kolona;j++)
        {
            if((m1.elementi[i][j]-std::round(m1.elementi[i][j]))>0.000001) nijeInt=true;

        }
    }
    
    
    
    for(int i=0;i<m1.br_redova;i++)
    {
        for(int j=0;j<m1.br_kolona;j++)
        {
            if(nijeInt)
            std::cout<<std::setw(sirina)<<std::setprecision(preciznost)<<m1.elementi[i][j];
            else
            std::cout<<std::setw(sirina)<<m1.elementi[i][j];

        }
        std::cout<<std::endl;
    }
    if(treba_brisati==true) Dealociraj(m1);
}
int main()
{
    Matrica<double> a;
    int m, n;
    std::cout << "Unesite dimenziju kvadratne matrice: ";
    std::cin>>n;
    try {
        a = StvoriMatricu<double>(n,n);
        std::cout << "Unesite elemente matrice A: "<<std::endl;
        UnesiMatricu('A', a);
        std::cout << "Unesite red polinoma: ";
        std::cin>>m;
        std::cout<< "Unesite koeficijente polinoma: ";
        std::vector<double> koef;
        for(int i=0;i<=m;i++)
        {
            int k;
            std::cin>>k;
            koef.push_back(k);
        }
        auto x=MatricniPolinom(a,koef);
        IspisiMatricu(x, 10,6,true);
        Dealociraj(a);
    } catch(std::bad_alloc) {
        std::cout << "Nema dovoljno memorije!\n";
    }
    catch(std::domain_error er)
    {
        std::cout<<er.what()<<std::endl;
    }
    return 0;
}

