/B2017/2018: Zadaća 3, Zadatak 3
#include <iostream>
#include <iomanip>
#include <stdexcept>
#include <new>
#include <vector>

template <typename TipElemenata>
struct Matrica {
    int br_redova, br_kolona;
    TipElemenata **elementi = nullptr;
};

template <typename TipElemenata>
void UnistiMatricu(Matrica<TipElemenata> matrica)
{
    if(!matrica.elementi) return;
    for(int i=0; i<matrica.br_redova; i++) {
        delete [] matrica.elementi[i];
    }
    delete [] matrica.elementi;
    matrica.elementi=nullptr;
}

template <typename TipElemenata>
Matrica<TipElemenata> StvoriMatricu(int br_redova, int br_kolona)
{
    Matrica<TipElemenata> matrica;
    matrica.br_redova=br_redova;
    matrica.br_kolona=br_kolona;
    matrica.elementi= new TipElemenata*[br_redova];
    for(int i=0; i<br_redova; i++) {
        matrica.elementi[i]=nullptr;
    }
    try {
        for(int i=0; i<br_redova; i++) {
            matrica.elementi[i]=new TipElemenata[br_kolona];
        }
    } catch(...) {
        UnistiMatricu(matrica);
        throw;
    }
    return matrica;
}

template <typename TipElemenata>
void UnesiMatricu(char ime_matrice, Matrica<TipElemenata> &matrica)
{
    for(int i=0; i<matrica.br_redova; i++) {
        for(int j=0; j<matrica.br_kolona; j++) {
            std::cout << ime_matrice
                      << "(" << i+1 << "," << j+1 << ") = ";
            std::cin >> matrica.elementi[i][j];
        }
    }
}

template <typename TipElemenata>
void IspisiMatricu(const Matrica<TipElemenata> &matrica, int sirina_ispisa,
                   int preciznost=6, bool treba_brisati=false)
{
    for(int i=0; i<matrica.br_redova; i++) {
        for(int j=0; j<matrica.br_kolona; j++) {
            std::cout << std::setw(sirina_ispisa) << std::setprecision(6) << matrica.elementi[i][j];
        }
        std::cout << std::endl;
    }
    if(treba_brisati) {
        UnistiMatricu(matrica);
    }
}

template <typename TipElemenata>
Matrica<TipElemenata> ZbirMatrica(const Matrica<TipElemenata> &m1, const Matrica<TipElemenata> &m2)
{
    if(m1.br_redova!=m2.br_redova || m1.br_kolona!=m2.br_kolona)
        throw std::domain_error("Matrice nemaju jednake dimenzije!");
    try {
        auto m3(StvoriMatricu<TipElemenata>(m1.br_redova, m1.br_kolona));
        for(int i=0; i<m3.br_redova; i++) {
            for(int j=0; j<m3.br_kolona; j++) {
                m3.elementi[i][j]=m1.elementi[i][j]+m2.elementi[i][j];
            }
        }
        return m3;
    } catch(...) {
        throw;
    }
    return m1;
}

template <typename TipElemenata>
Matrica<TipElemenata> ProduktMatrica(const Matrica<TipElemenata> &m1, const Matrica<TipElemenata> &m2)
{
    if(m1.br_kolona!=m2.br_redova)
        throw std::domain_error("Matrice nisu saglasne za mnozenje!");
    try {
        auto m3(StvoriMatricu<TipElemenata>(m1.br_redova, m2.br_kolona));
        for(int i=0; i<m1.br_redova; i++) {
            for(int k=0; k<m2.br_kolona; k++) {
                TipElemenata suma {};
                for(int j=0; j<m2.br_redova; j++)
                    suma+=m1.elementi[i][j]*m2.elementi[j][k];
                m3.elementi[i][k]=suma;
            }
        }
        return m3;
    } catch(...) {
        throw;
    }
    return m1;
}

template <typename TipElemenata>
Matrica<TipElemenata> Jedinicna(int n)
{
    try {
        Matrica<TipElemenata> m(StvoriMatricu<TipElemenata>(n, n));
        for(int i=0; i<n; i++)
            for(int j=0; j<n; j++) {
                if(i==j) m.elementi[i][j]=1;
                else m.elementi[i][j]=0;
            }
        return m;
    } catch(...) {
        throw;
    }
}

template <typename TipElemenata>
Matrica<TipElemenata> NulaMatrica(int n)
{
    try {
        Matrica<TipElemenata> m(StvoriMatricu<TipElemenata>(n, n));
        for(int i=0; i<n; i++)
            for(int j=0; j<n; j++)
                m.elementi[i][j]=0;
        return m;
    } catch(...) {
        throw;
    }
}

template <typename TipElemenata>
Matrica<TipElemenata> PomnoziSa(const Matrica<TipElemenata> &m, int n)
{
    try {
        auto mat(NulaMatrica<TipElemenata>(m.br_redova));
        for(int i=0; i<m.br_redova; i++)
            for(int j=0; j<m.br_kolona; j++)
                mat.elementi[i][j]=m.elementi[i][j]*n;
        return mat;
    } catch(...) {
        throw;
    }
}

template <typename TipElemenata, typename PokIliIt>
Matrica<TipElemenata> MatricniPolinom(const Matrica<TipElemenata> &A, int n, PokIliIt it)
{
    if(n<0)
        throw std::domain_error("Neispravan stepen polinoma!");
    if(A.br_redova!=A.br_kolona)
        throw std::domain_error("Matrica mora biti kvadratna!");
    Matrica<TipElemenata> a, b, kopija, P, m;
    try {
        int br(0);
        P=(NulaMatrica<TipElemenata>(A.br_redova));
        m=(A);
        for(int i=0; i<n+1; i++) {
            if(i==0) {
                a=(Jedinicna<TipElemenata>(A.br_redova));
                b=(PomnoziSa(a, *it));
                kopija=P;
                P=ZbirMatrica(b, P);
                UnistiMatricu(a);
                UnistiMatricu(b);
                UnistiMatricu(kopija);
                it++;
            } else {
                a=P;
                b=m;
                kopija=PomnoziSa(m, *it);
                P=ZbirMatrica(kopija, P);
                it++;
                m=ProduktMatrica(m, A);
                UnistiMatricu(kopija);
                UnistiMatricu(a);
                if(br>1)
                    UnistiMatricu(b);
            }
            br++;
        }
        UnistiMatricu(m);
        return P;
    } catch(...) {
        UnistiMatricu(a);
        UnistiMatricu(b);
        UnistiMatricu(kopija);
        UnistiMatricu(P);
        UnistiMatricu(m);

        throw;
    }
}

int main ()
{
    std::cout << "Unesite dimenziju kvadratne matrice: ";
    int n;
    std::cin >> n;
    std::cout << "Unesite elemente matrice A: \n";
    auto A(StvoriMatricu<int>(n, n));
    UnesiMatricu('A', A);
    std::cout << "Unesite red polinoma: ";
    int r;
    std::cin >> r;
    std::cout << "Unesite koeficijente polinoma: ";
    std::vector<int> v(r+1);
    for(int i=0; i<r+1; i++)
        std::cin >> v[i];
    auto m(MatricniPolinom(A, r, v.begin()));
    IspisiMatricu(m, 10, 6);
    UnistiMatricu(A);
    UnistiMatricu(m);

    return 0;
}
