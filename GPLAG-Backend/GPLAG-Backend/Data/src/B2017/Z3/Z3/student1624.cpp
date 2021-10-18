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
            std::cout << ime_matrice
                      << "(" << i + 1 << "," << j + 1 << ") = ";
            std::cin >> mat.elementi[i][j];
        }
}
template <typename TipElemenata>
Matrica<TipElemenata> MatricniPolinom (const Matrica<TipElemenata> &A, int n, std::vector<int> v)
{
    if(A.br_redova != A.br_kolona)
        throw std::domain_error("Matrica mora biti kvadratna");
    else if(n<1) throw std::domain_error("Neispravan stepen polinoma");
    int k = 1;
    auto I(StvoriMatricu<TipElemenata>(A.br_redova, A.br_kolona));
    auto H(StvoriMatricu<TipElemenata>(A.br_redova, A.br_kolona));
    auto pomocna(StvoriMatricu<TipElemenata>(A.br_redova, A.br_kolona));
    for(int i = 0; i < A.br_redova; i++)
        for(int j = 0; j < A.br_kolona; j++)
            H.elementi[i][j] = 0;
    while (k <= n) {
        pomocna = A;
        int br = 1;
        while (br < k) {
            pomocna = ProduktMatrica(pomocna, A);
            br++;
        }
        for(int i = 0; i < A.br_redova; i++)
            for(int j = 0; j < A.br_kolona; j++)
                pomocna.elementi[i][j] = pomocna.elementi[i][j]*v[k-1];
        std::cout << std::endl;
        IspisiMatricu(pomocna, 6);
        std::cout << std::endl;
        H = ZbirMatrica(H, pomocna);
        for(int i = 0; i < A.br_redova; i++)
            for(int j = 0; j < A.br_kolona; j++)
                H.elementi[i][j] *= 1./double(k);
        k++;
    }
    UnistiMatricu(pomocna);
    UnistiMatricu(I);
    return H;
}
template <typename TipElemenata>
void IspisiMatricu(const Matrica<TipElemenata> &mat,
                   int sirina_ispisa, int preciznost = 6, bool treba_brisati = false)
{
    for(int i = 0; i < mat.br_redova; i++) {
        for(int j = 0; j < mat.br_kolona; j++)
            std::cout << std::setw(sirina_ispisa)  << std::setprecision(preciznost) << mat.elementi[i][j];
        std::cout << std::endl;
    }
    if(treba_brisati) UnistiMatricu(mat);
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
template <typename TipElemenata>
Matrica<TipElemenata> ProduktMatrica(const Matrica<TipElemenata> &m1,
                                     const Matrica<TipElemenata> &m2)
{
    if(m1.br_kolona != m2.br_redova)
        throw std::domain_error("Matrice nisu saglasne za mnozenje");
    auto m3(StvoriMatricu<TipElemenata>(m1.br_redova, m2.br_kolona));
    for(int i = 0; i < m1.br_redova; i++) {
        for(int j = 0; j < m2.br_kolona; j++) {
            m3.elementi[i][j] = 0;
            for(int k = 0; k < m1.br_kolona; k++) {
                m3.elementi[i][j] = m3.elementi[i][j] + m1.elementi[i][k] * m2.elementi[k][j];
            }
        }
    }
    return m3;
}
int main()
{
    Matrica<double> a, b, c;
    int m, r;
    std::cout << "Unesite dimenziju kvadratne matrice: ";
    std::cin >> m ;
    try {
        a = StvoriMatricu<double>(m, m);
        std::cout << "Unesite elemente matrice A: " << std::endl;
        UnesiMatricu('A', a);
        std::cout << "Unesite red polinoma: ";
        std::cin >> r;
        std::vector<int> koef (r+1);
        std::cout << "Unesite koeficijente polinoma: ";
        for(int i = 0; i <= r; i++)
            std::cin >> koef[i];
        IspisiMatricu(MatricniPolinom(a, r, koef),6);
    } catch(std::bad_alloc) {
        std::cout << "Nema dovoljno memorije! " << std::endl;
    }
    UnistiMatricu(a);
    UnistiMatricu(b);
    UnistiMatricu(c);
    return 0;
}