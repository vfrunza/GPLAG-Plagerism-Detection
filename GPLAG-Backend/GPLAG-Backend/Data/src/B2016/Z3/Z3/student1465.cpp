/B2016/2017: Zadaća 3, Zadatak 3
#include <iostream>
#include <iomanip>
#include <stdexcept>
#include <vector>
using namespace std;

template<typename TipElementa>
struct Matrica {
    int br_redova, br_kolona;
    TipElementa **elementi = nullptr;
};

template<typename TipElementa>
void UnistiMatricu(Matrica<TipElementa> mat)
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
    }
    catch(...) {
        UnistiMatricu(mat);
        throw;
    }
    return mat;
}

template<typename TipElemenata>
void UnesiMatricu(char ime_matrice, Matrica<TipElemenata> &mat)
{
    for(int i = 0; i < mat.br_redova; i++) {
        for(int j = 0; j < mat.br_kolona; j++) {
            std::cout << ime_matrice << "(" << i + 1 << "," << j + 1 << ") = ";
            std::cin >> mat.elementi[i][j];
        }
    }
}

template<typename TipElemenata>
void IspisiMatricu(const Matrica<TipElemenata> &mat, int sirina_ispisa, int preciznost = 6, bool treba_brisati = false)
{
    cout.precision(preciznost);
    for(int i = 0; i < mat.br_redova; i++) {
        for(int j = 0; j < mat.br_kolona; j++)
            std::cout << std::setw(sirina_ispisa) << mat.elementi[i][j];
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
    for(int i = 0; i < m1.br_redova; i++) {
        for(int j = 0; j < m1.br_kolona; j++)
            m3.elementi[i][j] = m1.elementi[i][j] + m2.elementi[i][j];
    }
    return m3;
}

template<typename TipElemenata>
Matrica<TipElemenata>ProduktMatrica(const Matrica<TipElemenata> &mat1, const Matrica<TipElemenata> &mat2)
{
    if(mat1.br_kolona != mat2.br_redova) throw domain_error("Matrice nisu saglasne za mnozenje");
    Matrica<TipElemenata> mat3 = StvoriMatricu<TipElemenata>(mat1.br_redova, mat2.br_kolona);
    for(int i {0}; i < mat3.br_redova; i++) {
        for(int j {0}; j < mat3.br_kolona; j++) {
            mat3.elementi[i][j] = 0; //moramo postaviti na nulu, jer bez toga pristupi nekon neicijalizovanoj vrijednosti
            for(int k {0}; k < mat2.br_redova; k++) {
                mat3.elementi[i][j] += mat1.elementi[i][k] * mat2.elementi[k][j];
            }
        }
    }
    return mat3;
}

template<typename TipElemenata>
Matrica<TipElemenata> ProduktSaSkalarom(const Matrica<TipElemenata> &A, int skalar) 
{
    Matrica<TipElemenata> mat = StvoriMatricu<TipElemenata>(A.br_redova, A.br_kolona);
    for(int i{0}; i < A.br_redova; i++) {
        for(int j{0}; j < A.br_kolona; j++) {
            mat.elementi[i][j] = A.elementi[i][j] * skalar;
        }
    }
    return mat;
}
template<typename TipElemenata>
Matrica<TipElemenata> MatricniPolinom(const Matrica<TipElemenata> &A, vector<double> koeficijenti)
{
    Matrica<TipElemenata> m_polinom;
    Matrica<TipElemenata> jedinicna;
    Matrica<TipElemenata> monom;
    if(A.br_kolona != A.br_redova) throw domain_error("Matrica mora biti kvadratna");

    try {
        m_polinom = StvoriMatricu<TipElemenata>(A.br_redova, A.br_kolona);
        for(int i {0}; i < m_polinom.br_kolona; i++) {
            for(int j {0}; j < m_polinom.br_redova; j++) {
                m_polinom.elementi[i][j] = 0;
            }
        }
        if(koeficijenti.empty()) {
            return m_polinom;
        }
        jedinicna = StvoriMatricu<TipElemenata>(A.br_redova, A.br_kolona);
    } catch(...) {
        UnistiMatricu(m_polinom);
        UnistiMatricu(jedinicna);
        throw;
    }
    for(int i {0}; i < A.br_redova; i++) {
        for(int j {0}; j < A.br_kolona; j++) {
            if(i==j) jedinicna.elementi[i][j] = 1;
            else jedinicna.elementi[i][j] = 0;
        }
    }

    for(int i {0}; i < koeficijenti.size(); i++) {
        auto za_brisanje = monom;
        monom = ProduktSaSkalarom(jedinicna, koeficijenti[i]);
        UnistiMatricu(za_brisanje);
        for(int j{0}; j < i; j++) {
            za_brisanje = monom;
            monom = ProduktMatrica(monom, A);
            UnistiMatricu(za_brisanje);
        }
        za_brisanje = m_polinom;
        m_polinom = ZbirMatrica(m_polinom, monom); 
        UnistiMatricu(za_brisanje);
    }
    UnistiMatricu(jedinicna);
    UnistiMatricu(monom);
    return m_polinom;
}


int main()
{
    Matrica<double> a;
    int dimenzije;
    int red_polinoma;
    int red;
    std::cout << "Unesite dimenziju kvadratne matrice: ";
    std::cin >> dimenzije;
    try {
        a = StvoriMatricu<double>(dimenzije, dimenzije);
        std::cout << "Unesite elemente matrice A:\n";
        UnesiMatricu('A', a);
        std::cout << "Unesite red polinoma: ";
        cin >> red_polinoma;
        std::cout << "Unesite koeficijente polinoma: ";
        vector<double> koeficijenti;
        for(int i {0}; i <= red_polinoma; i++) {
            cin >> red;
            koeficijenti.push_back(red);
        }
        IspisiMatricu(MatricniPolinom(a, koeficijenti), 10, 6, true);
    }
    catch(std::bad_alloc) {
        std::cout << "Nema dovoljno memorije!\n";
    }
    UnistiMatricu(a);
    return 0;
}