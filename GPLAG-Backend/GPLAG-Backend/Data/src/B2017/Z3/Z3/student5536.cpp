/B2017/2018: Zadaća 3, Zadatak 3
#include <iostream>
#include <iomanip>
#include <stdexcept>
#include <new>
#include <vector>

template <typename TipElementa>
struct Matrica {
    int br_redova, br_kolona;
    TipElementa **elementi=nullptr;
};

template <typename TipElementa>
void UnistiMatricu (Matrica<TipElementa> mat)
{
    if (!mat.elementi) return;
    for (int i = 0; i < mat.br_redova; i++) delete [] mat.elementi[i];
    delete [] mat.elementi;
    mat.elementi = nullptr;
}

template <typename TipElementa>
Matrica<TipElementa> StvoriMatricu (int br_redova, int br_kolona)
{
    Matrica<TipElementa> mat;
    mat.br_redova = br_redova;
    mat.br_kolona=br_kolona;
    mat.elementi = new TipElementa*[br_redova];
    for (int i = 0; i < br_redova; i++) mat.elementi[i] = nullptr;
    try {
        for (int i = 0; i < br_redova; i++) mat.elementi[i] = new TipElementa[br_kolona]{};
    } catch (...) {
        UnistiMatricu(mat);
        throw;
    }
    return mat;
}

template <typename TipElementa>
void UnesiMatricu (char ime_matrice , Matrica<TipElementa> &mat)
{
    for (int i = 0; i < mat.br_redova; i++)
        for (int j = 0; j<mat.br_kolona; j++) {
            std::cout<<ime_matrice<<"("<<i+1<<","<<j+1<<") = ";
            std::cin>>mat.elementi[i][j];
        }
}

template <typename TipElementa>
void IspisiMatricu (const Matrica<TipElementa> &mat, int sirina_ispisa, int preciznost=6, bool treba_brisati=false)
{
    for (int i = 0; i < mat.br_redova; i++) {
        for (int j = 0; j < mat.br_kolona; j++)
            std::cout<<std::setw(sirina_ispisa)<<std::setprecision(preciznost)<<mat.elementi[i][j];
        std::cout<<std::endl;
    }
    if (treba_brisati) UnistiMatricu(mat);
}

template <typename TipElementa>
Matrica<TipElementa> ZbirMatrica (const Matrica<TipElementa> &m1, const Matrica<TipElementa> &m2)
{
    if (m1.br_redova != m2.br_redova || m1.br_kolona != m2.br_kolona) throw std::domain_error ("Matrice nemaju jednake dimenzije!");
    auto m3 (StvoriMatricu<TipElementa>(m1.br_redova, m1.br_kolona));
    for (int i = 0; i < m1.br_redova; i++)
        for (int j = 0; j < m1.br_kolona; j++)
            m3.elementi[i][j] = m1.elementi[i][j] + m2.elementi[i][j];
    return m3;
}

template <typename TipElementa>
Matrica<TipElementa> JedinicnaMatrica (int n)
{
    auto m(StvoriMatricu<TipElementa>(n,n));
    for (int i = 0; i<m.br_redova; i++)
        for (int j = 0; j<m.br_kolona; j++)
            if (i==j) m.elementi[i][j]=1;
            else m.elementi[i][j]=0;
    return m;
}

template <typename TipElementa>
Matrica<TipElementa> NulaMatrica (int n)
{
    auto m(StvoriMatricu<TipElementa>(n,n));
    for (int i = 0; i<n; i++)
        for (int j = 0; j<n; j++)
            m.elementi[i][j]=0;
    return m;
} // Postavlja sve elemente matrice na nulu

template<typename TipElementa>
Matrica<TipElementa> ProduktMatrica (const Matrica<TipElementa> &m1, const Matrica<TipElementa> &m2)
{
    if(m1.br_kolona!=m2.br_redova) throw std::domain_error("Matrice nisu saglasne za mnozenje");
    auto m3 (StvoriMatricu<TipElementa>(m1.br_redova,m2.br_kolona));
    for (int i = 0; i<m1.br_redova; i++)
        for (int j = 0; j<m2.br_kolona; j++) {
            TipElementa suma(0);
            for (int k = 0; k < m2.br_redova; k++) suma+=m1.elementi[i][k]*m2.elementi[k][j];
            m3.elementi[i][j]=suma;
        }
    return m3;
}

template<typename TipElementa>
Matrica<TipElementa> PomnoziNPuta (const Matrica<TipElementa> &m, int n)   // Mnozi matricu m samu sa sobom n puta
{
    if (n==0) return JedinicnaMatrica<TipElementa>(m.br_kolona);
    auto nova(StvoriMatricu<TipElementa>(m.br_redova,m.br_kolona)), kopija(nova);
    for (int i = 0; i<m.br_redova; i++)
        for (int j = 0; j<m.br_kolona; j++)
            nova.elementi[i][j]=m.elementi[i][j];
            for (int i = 1; i<n; i++)
            {
                nova=ProduktMatrica(m,nova);
                UnistiMatricu(kopija);
                kopija = nova;
            }
    return nova;
}

template<typename TipElementa,typename TipKoeficijenta>
Matrica<TipElementa> PomnoziSaKoeficijentom (Matrica<TipElementa> m, const TipKoeficijenta x)   // Mnozi matricu m sa nekim koeficijentom x
{
    auto jed(JedinicnaMatrica<TipElementa>(m.br_redova));
    for (int i = 0; i<m.br_redova; i++)
        for (int j = 0; j<m.br_kolona; j++)
            jed.elementi[i][j]=x*jed.elementi[i][j];
    m=ProduktMatrica(jed,m);
    UnistiMatricu(jed);
    return m;
}

template<typename TipElementa, typename TipIteratora>
Matrica<TipElementa> MatricniPolinom (const Matrica<TipElementa> m, int n, TipIteratora iter)
{
    if (n<0) throw std::domain_error("Neispravan stepen polinoma");
    auto vrati(NulaMatrica<TipElementa>(m.br_redova)), stara(vrati);
    for (int i = 0; i<=n; i++) {
        auto n_puta(PomnoziNPuta(m,i));
        auto sa_koef(PomnoziSaKoeficijentom(n_puta,*iter));
        vrati = ZbirMatrica(vrati,sa_koef);
        UnistiMatricu(n_puta); UnistiMatricu(sa_koef); UnistiMatricu(stara);
        stara=vrati;
        iter++;
    }
    return vrati;
}

int main ()
{
    Matrica<double> a;
    Matrica<double> b;
    int k;
    std::cout<<"Unesite dimenziju kvadratne matrice: ";
    std::cin>>k;
    try {
        a=StvoriMatricu<double>(k,k);
        std::cout<<"Unesite elemente matrice A: \n";
        UnesiMatricu('A',a);
        std::cout<<"Unesite red polinoma: ";
        int n;
        std::cin>>n;
        std::cout<<"Unesite koeficijente polinoma: ";
        std::vector<double> polinom;
        for (int i = 0; i<n+1; i++) {
            double koeficijent;
            std::cin>>koeficijent;
            polinom.push_back(koeficijent);
        }
        IspisiMatricu (b=MatricniPolinom(a,n,polinom.begin()),10);
    } catch (std::bad_alloc) {
        std::cout<<"Nema dovoljno memorije!\n";
    }
    UnistiMatricu(a);
    UnistiMatricu(b);
    return 0;
}