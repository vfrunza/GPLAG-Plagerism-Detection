/B2017/2018: Zadaća 3, Zadatak 3
#include <iostream>
#include <vector>
#include <iomanip>
#include <new>
#include <set>
#include <stdexcept>

template < typename TipElemenata >

struct Matrica {
    int br_redova, br_kolona;
    TipElemenata **elementi = nullptr;
};

template < typename TipElemenata >

void UnistiMatricu (Matrica < TipElemenata > mat)
{
    if( ! mat.elementi) return;
    for(int i = 0; i < mat.br_redova; i++) delete [] mat.elementi[i];
    delete [] mat.elementi;
    mat.elementi = nullptr;
}

template < typename TipElemenata >

Matrica < TipElemenata > StvoriMatricu (int br_redova, int br_kolona)
{
    Matrica < TipElemenata > mat;
    mat.br_kolona = br_kolona;
    mat.br_redova = br_redova;
    mat.elementi = new TipElemenata *[br_redova];
    for(int i = 0; i < br_redova; i++) mat.elementi[i] = nullptr;
    try {
        for(int i = 0; i < br_redova; i++)
            mat.elementi[i] = new TipElemenata[br_kolona];
    }

    catch(...) {
        UnistiMatricu(mat);
        throw;
    }
    return mat;
}

template < typename TipElemenata >

void UnesiMatricu (char ime_matrice, Matrica < TipElemenata > &mat)
{
    for(int i = 0; i < mat.br_redova; i++)

        for(int j = 0; j < mat.br_kolona; j++) {
            std::cout << ime_matrice << "("<< i+1 << "," << j+1 << ") = ";
            std::cin >> mat.elementi [i][j];
        }
}

template < typename TipElemenata >

void IspisiMatricu (const Matrica < TipElemenata > &mat, int sirina_ispisa, int preciznost = 6, bool treba_brisati = false)
{
    for(int i = 0; i < mat.br_redova; i++) {
        for(int j = 0; j < mat.br_kolona; j++) {
            std::cout << std::setprecision(preciznost) << std::setw(sirina_ispisa) << mat.elementi[i][j];
        }
        std::cout << std::endl;
    }
    if(treba_brisati) {
        UnistiMatricu(mat);
    }
}

template < typename TipElemenata >

Matrica < TipElemenata > ZbirMatrica (const Matrica < TipElemenata > &m1, const Matrica < TipElemenata > &m2)
{
    if(m1.br_redova != m2.br_redova || m1.br_kolona != m2.br_kolona)
        throw std::domain_error ("Matrice nemaju jednake dimenzije!");
    auto m3(StvoriMatricu<TipElemenata>(m1.br_redova,m1.br_kolona));
    for(int i = 0; i < m1.br_redova; i++)
        for(int j = 0; j < m1.br_kolona; j++)
            m3.elementi[i][j] = m1.elementi[i][j] + m2.elementi[i][j];
    return m3;
}

template < typename TipElemenata >

Matrica < TipElemenata > ProduktMatrica (const Matrica < TipElemenata > &m1, const Matrica < TipElemenata > &m2)
{
    if(m1.br_redova != m2.br_kolona)
        throw std::domain_error ("Matrice nisu saglasne za mnozenje!");
    auto m3(StvoriMatricu<TipElemenata>(m1.br_redova, m1.br_kolona));
    for(int i = 0; i < m1.br_redova; i++) {
        for(int j = 0; j < m2.br_kolona; j++) {
            int suma(0);
            for(int k = 0; k < m1.br_kolona; k++)
                suma += m1.elementi[i][k] * m2.elementi[k][j];
            m3.elementi[i][j] = suma;
        }
    }
    return m3;
}

template < typename TipElemenata, typename PokNaKoef >

Matrica < TipElemenata > MatricniPolinom (const Matrica < TipElemenata > &m1, int n, PokNaKoef pokazivacNaKoeficijente)
{
    if(m1.br_redova != m1.br_kolona)
        throw std::domain_error ("Matrica mora biti kvadratna");
    if(n < 0) throw std::domain_error ("Neispravan stepen polinoma");
    auto m3(StvoriMatricu<TipElemenata>(m1.br_redova,m1.br_kolona));
    try {
        for(int a = 0; a < m3.br_redova; a++)
            for(int b = 0; b < m3.br_kolona; b++) {
                if(a == b)
                    m3.elementi[a][b] = 1 * (*pokazivacNaKoeficijente);
                else m3.elementi[a][b] = 0;
            }

        try {
            auto m2(StvoriMatricu<TipElemenata>(m1.br_redova, m1.br_kolona));
            for(int i = 1; i <= n; i++) {
                pokazivacNaKoeficijente++;
                for(int a = 0; a < m2.br_redova; a++)
                    for(int b = 0; b < m2.br_kolona; b++)
                        m2.elementi[a][b] = m1.elementi[a][b];

                TipElemenata **g, **b;
                for(int j = 1; j < i; j++) {
                    g = ProduktMatrica(m2,m1).elementi;
                    UnistiMatricu(m2);
                    m2.elementi = g;
                }

                int koeficijenti = *pokazivacNaKoeficijente;
                for(int a = 0; a < m2.br_redova; a++)
                    for(int b = 0; b < m2.br_kolona; b++)
                        m2.elementi[a][b] *=  koeficijenti;
                b = ZbirMatrica(m3,m2).elementi;
                UnistiMatricu(m3);
                m3.elementi = b;
            }
            UnistiMatricu(m2);
        } catch(...) {
            UnistiMatricu(m3);
            throw;
        }
    } catch(...) {
        UnistiMatricu(m1);
        throw;
    }
    return m3;
}

int main ()
{
    Matrica < double > a, c;
    int m;
    std::cout << "Unesite dimenziju kvadratne matrice: ";
    std::cin >> m;
    try {
        a = StvoriMatricu < double >(m,m);
        std::cout << "Unesite elemente matrice A:" << std::endl;
        UnesiMatricu('A', a);
        std::cout << "Unesite red polinoma: ";
        int redPolinoma;
        std::cin >> redPolinoma;
        std::cout << "Unesite koeficijente polinoma: ";
        std::vector < int > koef(redPolinoma+1);
        for(int i = 0; i <= redPolinoma; i++) {
            std::cin >> koef[i];
        }
        IspisiMatricu(c = MatricniPolinom(a, redPolinoma, &koef[0]), 10, 6, true);
    }

    catch(...) {
        std::cout << "Nema dovoljno memorije";
    }
    UnistiMatricu(a);
    return 0;
}
