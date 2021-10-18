/B2017/2018: Zadaća 3, Zadatak 3
#include <iostream>
#include <stdexcept>
#include <vector>
#include <new>
#include <iomanip>

template <typename TipElementa>
struct Matrica {
    int br_redova, br_kolona;
    TipElementa **elementi = nullptr;
};

template <typename TipElementa>
void UnistiMatricu(Matrica<TipElementa> mat) {
    
    if (!mat.elementi) return;
    for (int i=0; i < mat.br_redova; i++) {
        delete[] mat.elementi[i];
    }
    delete[] mat.elementi;
    mat.elementi = nullptr;
}

template <typename TipElementa>
Matrica<TipElementa> StvoriMatricu(int br_redova, int br_kolona) {
    
    Matrica<TipElementa> mat;
    mat.br_redova = br_redova;
    mat.br_kolona = br_kolona;
    
    try {
        mat.elementi = new TipElementa*[br_redova];
        for (int i=0; i < br_redova; i++) {
            mat.elementi[i] = nullptr;
        }
    }
    catch (...) {
        throw;
    }
    try {
        for (int i = 0; i < br_redova; i++) {
            mat.elementi[i] = new TipElementa[br_kolona];
        }
    }
    catch (...) {
        UnistiMatricu(mat);
        throw;
    }
    return mat;
}

template <typename TipElementa>
void UnesiMatricu (char ime_matrice, Matrica<TipElementa> &mat) {
    for (int i = 0; i < mat.br_redova; i++) {
        for (int j = 0; j < mat.br_kolona; j++) {
            std::cout << ime_matrice << "(" << i+1 << "," << j+1 << ") = ";
            std::cin >> mat.elementi[i][j];
        }
    }
}

template <typename TipElementa>
void IspisiMatricu (const Matrica<TipElementa> &mat, int sirina_ispisa, int preciznost = 6, bool treba_brisati = false) {
    for (int i = 0; i < mat.br_redova; i++) {
        for (int j = 0; j < mat.br_kolona; j++) {
            std::cout << std::setw(sirina_ispisa) << std::setprecision(preciznost) << mat.elementi[i][j];
        }
        std::cout << std::endl;
    }
    if (treba_brisati) {
        UnistiMatricu(mat);
    }
}

template <typename TipElementa>
Matrica<TipElementa> ZbirMatrica(const Matrica<TipElementa> &m1, const Matrica<TipElementa> &m2) {
    if (m1.br_redova != m2.br_redova || m1.br_kolona != m2.br_kolona) throw std::domain_error ("Matrice nemaju jednake dimenzije!");
    try {
        auto m3(StvoriMatricu<TipElementa>(m1.br_redova, m1.br_kolona));
        for (int i = 0; i < m1.br_redova; i++) {
            for (int j = 0; j < m1.br_kolona; j++) {
                m3.elementi[i][j] = m1.elementi[i][j] + m2.elementi[i][j];
            }
        }
        return m3;
    }
    catch (...) {
        throw;
    }
}

template <typename TipElementa>
Matrica<TipElementa> ProduktMatrica (const Matrica<TipElementa> &m1, const Matrica<TipElementa> &m2) {
    if (m1.br_kolona != m2.br_redova) throw std::domain_error ("Matrice nisu saglasne za mnozenje");
    try {
        auto m3(StvoriMatricu<TipElementa>(m1.br_redova, m2.br_kolona));
        for (int i = 0; i < m1.br_redova; i++) {
            for (int j = 0; j < m2.br_kolona; j++) {
                TipElementa suma{};
                for (int k = 0; k < m1.br_kolona; k++) {
                    suma += m1.elementi[i][k] * m2.elementi[k][j];
                }
                m3.elementi[i][j] = suma;
            }
        }
        return m3;
    }
    catch (...) {
        throw;
    }
}

///

template <typename TipElementa>
Matrica<TipElementa> MatricniPolinom (const Matrica<TipElementa> &mat, int n, double* pokazivac_na_niz_koeficijenata) {
    if (mat.br_kolona != mat.br_redova) throw std::domain_error ("Matrica mora biti kvadratna");
    if (n < 0) throw std::domain_error ("Neispravan stepen polinoma");
    
    Matrica<TipElementa> P;
    try {
        P = StvoriMatricu<TipElementa>(mat.br_kolona, mat.br_kolona);
        for (int i = 0; i < mat.br_kolona; i++) {
            for (int j = 0; j < mat.br_kolona; j++) {
                P.elementi[i][j] = 0;
            }
        }
    }
    catch (...) {
        throw;
    }
    
    std::vector<Matrica<TipElementa>> v_pok(n);
    for (int i = 0; i < n; i++) {
        if (i == 0) {
            try {
                auto I(StvoriMatricu<TipElementa>(mat.br_kolona, mat.br_kolona));
                for (int i = 0; i < mat.br_kolona; i++) {
                    for (int j = 0; j < mat.br_kolona; j++) {
                        if (i == j) I.elementi[i][j] = 1;
                        else I.elementi[i][j] = 0;
                    }
                }
                v_pok[i] = I;
            }
            catch (...) {
                
            }
        }
        else {
            try {
                v_pok[i] = ProduktMatrica(mat, v_pok[i-1]);
            }
            catch (...) {
                for (int i = 0; i < n; i++) {
                    UnistiMatricu(v_pok[i]);
                }
            }
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < mat.br_kolona; j++) {
            for (int k = 0; k < mat.br_kolona; k++) {
                P.elementi[j][k] += *pokazivac_na_niz_koeficijenata * (v_pok[i].elementi[j][k]);
            }
        }
        pokazivac_na_niz_koeficijenata++;
    }
    for (int i = 0; i < n; i++) {
        UnistiMatricu(v_pok[i]);
    }
    return P;
}

int main ()
{
    Matrica<double> a;
    int n;
    std::cout << "Unesite dimenziju kvadratne matrice: ";
    std::cin >> n;
    try {
        a = StvoriMatricu<double>(n, n);
        std::cout << "Unesite elemente matrice A: " << std::endl;
        UnesiMatricu('A', a);
    }
    catch (std::bad_alloc) {
        std::cout << "Nema dovoljno memorije!";
    }
    std::cout << "Unesite red polinoma: ";
    std::cin >> n;
    std::vector <double> v1(n+1);
    std::cout << "Unesite koeficijente polinoma: ";
    for (auto &i : v1) {
        std::cin >> i;
    }
    auto P(MatricniPolinom(a, n+1, &v1[0]));
    IspisiMatricu(P,10, 6, true);
    UnistiMatricu(a);
	return 0;
}
