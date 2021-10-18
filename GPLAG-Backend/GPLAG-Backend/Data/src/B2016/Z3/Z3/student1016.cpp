/B2016/2017: Zadaća 3, Zadatak 3
#include <iostream>
#include <iomanip>
#include <stdexcept>
#include <new>
#include <vector>

template <typename TipElemenata>
struct Matrica {
    int br_redova, br_kolona, preciznost=6;
    bool treba_brisati=false;
    TipElemenata **elementi = nullptr;
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

template <typename TipElemenata>
void UnesiMatricu(char ime_matrice, Matrica<TipElemenata> &mat)
{
    for(int i = 0; i < mat.br_redova; i++)
        for(int j = 0; j < mat.br_kolona; j++) {
            std::cout << ime_matrice << "(" << i + 1 << "," << j + 1 << ") = ";
            std::cin >> mat.elementi[i][j];
        }
}

template <typename TipElemenata>
void IspisiMatricu(const Matrica<TipElemenata> &mat, int sirina_ispisa, int preciznost=6, bool treba_brisati=false )
{
    for(int i = 0; i < mat.br_redova; i++) {
        for(int j = 0; j < mat.br_kolona; j++)
            std::cout << std::setw(sirina_ispisa) <<std::setprecision(preciznost) << mat.elementi[i][j];
        std::cout << std::endl;
    }
    if(treba_brisati) UnistiMatricu(mat);
}

template <typename TipElemenata>
Matrica<TipElemenata> ZbirMatrica(const Matrica<TipElemenata> &m1, const Matrica<TipElemenata> &m2)
{
    if(m1.br_redova != m2.br_redova || m1.br_kolona != m2.br_kolona)
        throw std::domain_error("Matrice nemaju jednake dimenzije!");
    try {
        auto m3(StvoriMatricu<TipElemenata>(m1.br_redova, m1.br_kolona));

        for(int i = 0; i < m1.br_redova; i++)
            for(int j = 0; j < m1.br_kolona; j++)
                m3.elementi[i][j] = m1.elementi[i][j] + m2.elementi[i][j];
        return m3;
    } catch (...) {
        throw;
    }
}

template <typename TipElemenata>
Matrica<TipElemenata> ProduktMatrica(const Matrica<TipElemenata> &m1, const Matrica<TipElemenata> &m2)
{
    if(m1.br_kolona != m2.br_redova)
        throw std::domain_error("Matrice nisu saglasne za mnozenje");
    try {
        auto m3(StvoriMatricu<TipElemenata>(m1.br_redova, m2.br_kolona));

        for(int i=0; i<m1.br_redova; i++) {
            for(int j=0; j<m2.br_kolona; j++) {
                m3.elementi[i][j]=0;
                for(int k=0; k<m1.br_kolona; k++) {
                    m3.elementi[i][j]+=m1.elementi[i][k]*m2.elementi[k][j];
                }
            }
        }
        return m3;
    } catch(...) {
        throw;
    }
}

template <typename TipElemenata>
Matrica<TipElemenata> MnozenjeSkalarom (const Matrica<TipElemenata> &m, double x)
{
    try {
        auto m3(StvoriMatricu<TipElemenata>(m.br_redova, m.br_kolona));

        for(int i=0; i<m3.br_redova; i++) {
            for(int j=0; j<m3.br_kolona; j++) {
                m3.elementi[i][j]=m.elementi[i][j];
                m3.elementi[i][j]*=x;
            }
        }
        return m3;
    } catch(...) {
        throw;
    }
}

template <typename TipElemenata>
Matrica<TipElemenata> MatricniPolinom(const Matrica<TipElemenata> &m, std::vector<double> p)
{
    if(m.br_kolona!=m.br_redova) throw std::domain_error ("Matrica mora biti kvadratna");
    try {
        auto polinom(StvoriMatricu<TipElemenata>(m.br_redova, m.br_kolona));
        if(p.size()==0) return polinom;
        auto x(StvoriMatricu<TipElemenata>(m.br_redova, m.br_kolona));

        for(int i=0; i<m.br_redova; i++) {
            for(int j=0; j<m.br_kolona; j++) {
                x.elementi[i][j]=m.elementi[i][j];
                if(i==j) polinom.elementi[i][j]=p[0];
                else polinom.elementi[i][j]=0;
            }
        }
        for(int i=1; i<p.size(); i++) {
            if(i==1) {
                auto k(MnozenjeSkalarom(m, p[i]));
                auto n(polinom);
                polinom=ZbirMatrica(k,n);
                UnistiMatricu(n);
                UnistiMatricu(k);
                continue;
            }
            auto c(ProduktMatrica(x,m));
            auto b(MnozenjeSkalarom(c, p[i]));
            auto n(polinom);
            polinom=ZbirMatrica(b, n);
            UnistiMatricu(n);
            UnistiMatricu(c);
            UnistiMatricu(b);
            auto temp(x);
            x=ProduktMatrica(x,m);
            UnistiMatricu(temp);
        }
        UnistiMatricu(x);
        return polinom;
    } catch(...) {
        throw;
    }
}

int main()
{
    Matrica<double> a;
    int n, m;
    std::cout << "Unesite dimenziju kvadratne matrice: ";
    std::cin >> n;
    try {
        a = StvoriMatricu<double>(n, n);
        std::cout << "Unesite elemente matrice A:\n";
        UnesiMatricu('A', a);
    } catch(std::bad_alloc) {
        std::cout << "Nema dovoljno memorije!";
        return 0;
    }
    std::cout << "Unesite red polinoma: ";
    std::cin >> m;
    std::vector<double> p;
    std::cout << "Unesite koeficijente polinoma: ";
    for(int i=0; i<m+1; i++) {
        double x;
        std::cin >> x;
        p.push_back(x);
    }
    try {
        IspisiMatricu(MatricniPolinom(a, p), 10, 6, true);
    } catch(...) {
        std::cout << "Nema dovoljno memorije!";
        UnistiMatricu(a);
        return 0;
    }
    UnistiMatricu(a);
    return 0;
}
