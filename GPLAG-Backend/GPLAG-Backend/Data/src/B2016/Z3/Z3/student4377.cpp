/B2016/2017: Zadaća 3, Zadatak 3
#include <iostream>
#include <iomanip>
#include <stdexcept>
#include <new>
#include <vector>

template <typename TipElemenata>
struct Matrica 
{
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
    mat.br_redova = br_redova; mat.br_kolona = br_kolona;
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
        std::cout << ime_matrice << "(" << i + 1 << "," << j + 1 << ") = ";
        std::cin >> mat.elementi[i][j];
    }
}
 
template <typename TipElemenata>
void IspisiMatricu(const Matrica<TipElemenata> &mat, int sirina_ispisa, int preciznost = 6, bool treba_brisati = false) 
{
    for(int i = 0; i < mat.br_redova; i++) 
    {
        for(int j = 0; j < mat.br_kolona; j++)
        std::cout << std::setw(sirina_ispisa) << std::setprecision(preciznost) << mat.elementi[i][j];
        std::cout << std::endl;
    }
    if(treba_brisati) UnistiMatricu(mat);
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

template <typename TipElemenata>
Matrica<TipElemenata> ProduktMatrica(const Matrica<TipElemenata> &m1, const Matrica<TipElemenata> &m2) 
{
    if(m1.br_kolona != m2.br_redova) throw std::domain_error("Matrice nisu saglasne za mnozenje");
    auto m3(StvoriMatricu<TipElemenata>(m1.br_redova, m2.br_kolona));
    for(int i=0; i<m1.br_redova; i++)
    for(int j=0; j<m2.br_kolona; j++) m3.elementi[i][j] = 0;
    for(int i=0; i<m1.br_redova; i++)
    for(int j=0; j<m2.br_kolona; j++)
    for(int n=0; n<m1.br_kolona; n++)
    m3.elementi[i][j] += m1.elementi[i][n] * m2.elementi[n][j];

    return m3;
}

template <typename TipElemenata, typename Tip>
Matrica<TipElemenata> PomnoziSkalarom(const Matrica<TipElemenata> &m1, Tip a) 
{
    auto m3(StvoriMatricu<TipElemenata>(m1.br_redova, m1.br_kolona));
    for(int i=0; i<m1.br_redova; i++)
    for(int j=0; j<m1.br_kolona; j++)
    m3.elementi[i][j] = m1.elementi[i][j]*a;
    return m3;
}

template <typename TipElemenata, typename TipVek>
Matrica<TipElemenata> MatricniPolinom(const Matrica<TipElemenata> &m1, const std::vector<TipVek> &v) 
{
    if(m1.br_redova != m1.br_kolona) throw std::domain_error("Matrica mora biti kvadratna");
    
    auto polinom(StvoriMatricu<TipElemenata>(m1.br_redova, m1.br_redova));
    auto a(StvoriMatricu<TipElemenata>(m1.br_redova, m1.br_redova));
    auto skalarna(StvoriMatricu<TipElemenata>(m1.br_redova, m1.br_redova));
    
    for(int i=0; i<m1.br_redova; i++) 
    for(int j=0; j<m1.br_kolona; j++)
    {
        a.elementi[i][j] = m1.elementi[i][j];
        if(i == j) polinom.elementi[i][j] = 1*v[0];
        else
        polinom.elementi[i][j] = 0;
    }
    for(int i=1; i<v.size(); i++)
    {
        if(i!=1)
        {
            auto del_boy(a);
            a = ProduktMatrica(a, m1);
            UnistiMatricu(del_boy);
        }
        auto del_boy(skalarna);
        skalarna = PomnoziSkalarom(a, v[i]);
        UnistiMatricu(del_boy);
        auto rodney(polinom);
        polinom = ZbirMatrica(polinom, skalarna);
        UnistiMatricu(rodney);
    }
    UnistiMatricu(a); UnistiMatricu(skalarna);
    return polinom;
}

int main() 
{
    Matrica<double> a, b, c; // AUTOMATSKA INICIJALIZACIJA!!!
    int n;
    std::cout << "Unesite dimenziju kvadratne matrice: ";
    std::cin >> n;
    try 
    {
        a = StvoriMatricu<double>(n, n);
        std::cout << "Unesite elemente matrice A:\n";
        UnesiMatricu('A', a);
        std::cout << "Unesite red polinoma: ";
        std::cin >> n;
        std::vector<double> v(n+1);
        std::cout << "Unesite koeficijente polinoma: ";
        for(int i=0; i<=n; i++) std::cin >> v[i];
        IspisiMatricu(MatricniPolinom(a, v), 10, 10, true);
    }
    catch(std::bad_alloc) 
    {
        std::cout << "Nema dovoljno memorije!\n";
    }
    UnistiMatricu(a); UnistiMatricu(b); UnistiMatricu(c);
    return 0;
}
