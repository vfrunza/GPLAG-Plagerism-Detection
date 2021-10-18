/B2017/2018: Zadaća 3, Zadatak 3
#include <iostream>
#include <iomanip>
#include <stdexcept>
#include <new>
#include <vector>

template <typename T>
struct Matrica {
    int br_redova, br_kolona;
    T **elementi = nullptr;
};

template <typename T>
void UnisiMatricu (Matrica <T> mat) {
    if (!mat.elementi) {
        return;
    }
    for (int i = 0; i < mat.br_redova; i++) {
        delete[] mat.elementi[i];
    }
    delete[] mat.elementi;
    mat.elementi = nullptr;
}

template <typename T>
Matrica<T> StvoriMatricu (int br_redova, int br_kolona) {
    Matrica<T> mat;
    mat.br_redova = br_redova;
    mat.br_kolona = br_kolona;
    mat.elementi = new T*[br_redova];
    for (int i = 0; i < br_redova; i++) {
        mat.elementi[i] = nullptr;
    }
    try {
        for (int i = 0; i < br_redova; i++) {
            mat.elementi[i] = new T[br_redova];
        }
    }
    catch (...) {
        UnisiMatricu(mat);
        throw;
    }
    return mat;
}

template <typename T>
void UnesiMatricu (char ime_matrice, Matrica<T> &mat) {
    for (int i = 0; i < mat.br_redova; i++) {
        for (int j = 0; j < mat.br_kolona; j++) {
            std::cout << ime_matrice << "(" << i+1 << "," << j+1 << ") = ";
            std::cin >> mat.elementi[i][j];
        }
    }
}

template <typename T>
void IspisiMatricu (const Matrica <T> &mat, int sirina_ispisa, int preciznost = 6, bool treba_brisati = false) {
    for (int i = 0; i < mat.br_redova; i++) {
        for (int j = 0; j < mat.br_kolona; j++) {
            std::cout << std::setw(sirina_ispisa) << std::setprecision(preciznost) << mat.elementi[i][j];
        }
        std::cout << std::endl;
    }
    if (treba_brisati) {
        UnisiMatricu(mat);
    }
    
}

template <typename T>
Matrica<T> ZbirMatrica (const Matrica<T> &m1, const Matrica<T> &m2) {
    if (m1.br_redova != m2.br_redova || m1.br_kolona != m2.br_kolona) {
        throw std::domain_error ("Matrice nemaju jednake dimenzije!");
    }
    auto m3(StvoriMatricu<T>(m1.br_redova, m2.br_kolona));
    for (int i = 0; i < m1.br_redova; i++) {
        for (int j = 0; j  < m1.br_kolona; j++) {
            m3.elementi[i][j] = m1.elementi[i][j] + m2.elementi[i][j];
        }
    }
    return m3;
}

template <typename T>
Matrica<T> ProduktMatrica (const Matrica<T> &m1, const Matrica<T> &m2) {
    if (m1.br_kolona != m2.br_kolona) {
        throw std::domain_error("Matrice nisu saglasne za mnozenje");
    }
    auto m3(StvoriMatricu<T>(m1.br_redova, m2.br_kolona));
    for (int i = 0; i < m1.br_redova; i++) {
        for (int j = 0; j  < m2.br_kolona; j++) {
            int x(0);
            for (int k = 0; k < m1.br_kolona; k++) {
                x += m1.elementi[i][k] * m2.elementi[k][j];
            }
            m3.elementi[i][j] = x;
        }
    }
    return m3;
}

template <typename T>
void PomnoziMatricu (Matrica<T> &m, T n) {
    for (int i = 0; i < m.br_redova; i++) {
        for (int j = 0; j < m.br_kolona; j++) {
            m.elementi[i][j] *= n;
        }
    }
}

template <typename T>
Matrica<T> StepenMatrice (const Matrica<T> &m, int n) {
    auto stepen(StvoriMatricu<T>(m.br_redova, m.br_kolona));

    for (int i = 0; i < m.br_redova; i++) {
        for (int j = 0; j < m.br_redova; j++) {
            stepen.elementi[i][j] = m.elementi[i][j];
        }
    }
    if (n == 0) { //vracam jedinicnu
        for (int i = 0; i < m.br_redova; i++) {
            for (int j = 0; j < m.br_kolona; j++) {
                stepen.elementi[i][j] = 0;
            }
            stepen.elementi[i][i] = 1;
        }
        return stepen;
    }
    for (int i = 1; i < n; i++) {
        auto stara(stepen);
        stepen = ProduktMatrica(stepen, m);
        UnisiMatricu(stara);
    }
    return stepen;
}

template<typename T, typename T2> 
Matrica<T> MatricniPolinom (const Matrica<T> &m, int n, T2 koeficijenti) {
    if (n < 0) {
        throw std::domain_error("Neispravan stepen polinoma");
    }
    if (m.br_redova != m.br_kolona) {
        throw std::domain_error("Matrica mora biti kvadratna");
    }
    auto polinom(StvoriMatricu<T>(m.br_redova, m.br_kolona));
    for (int i = 0; i < polinom.br_redova; i++) {
        for (int j = 0; j < polinom.br_kolona; j++) {
            polinom.elementi[i][j] = 0;
        }
    }
    
    for (int i = 0; i <= n; i++) {
        auto pom = StepenMatrice(m, i), stara = polinom;
        PomnoziMatricu(pom, *koeficijenti);
        polinom = ZbirMatrica(polinom, pom);
        UnisiMatricu(pom);
        UnisiMatricu(stara);
        koeficijenti++;
    }
    return polinom;
}

int main ()
{
    Matrica<double> a;
    int n, red_polinoma;
    std::vector<double> koeficijenti;
    
    std::cout << "Unesite dimenziju kvadratne matrice: ";
    std::cin >> n;
    try {
        a = StvoriMatricu<double> (n, n);
        std::cout << "Unesite elemente matrice A:" << std::endl;
        UnesiMatricu('A', a);
        std::cout << "Unesite red polinoma: ";
        std::cin >> red_polinoma;
        std::cout << "Unesite koeficijente polinoma: ";
        koeficijenti.resize(red_polinoma+1);
        for (int i = 0; i <= red_polinoma; i++) {
            std::cin >> koeficijenti[i];
        }
        auto b = MatricniPolinom(a, red_polinoma, koeficijenti.begin());
        IspisiMatricu(b, 10, 6, true);
    }
    catch (std::bad_alloc) {
        std::cout << "Nema dovoljno memorije!" << std::endl;
    }
    UnisiMatricu(a);
	return 0;
}
