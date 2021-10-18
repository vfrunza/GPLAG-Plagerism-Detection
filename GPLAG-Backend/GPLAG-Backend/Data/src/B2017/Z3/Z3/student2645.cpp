/B2017/2018: Zadaća 3, Zadatak 3
#include <iostream>
#include <iomanip>
#include <stdexcept>
#include <new>
#include <vector>

template <typename Tip>
struct Matrica {
    int br_redova, br_kolona;
    Tip **elementi = nullptr;
};

template <typename Tip>
void UnistiMatricu(Matrica<Tip> mat) {
    if(!mat.elementi) return;
    for(int i(0); i < mat.br_redova; i++) {
        delete[] mat.elementi[i];
    }
    delete[] mat.elementi;
    mat.elementi = nullptr;
}

template <typename Tip>
Matrica<Tip> StvoriMatricu(int br_redova, int br_kolona) {
    Matrica<Tip> mat;
    mat.br_redova = br_redova;
    mat.br_kolona = br_kolona;
    mat.elementi = new Tip*[br_redova];
    for(int i(0); i < br_redova; i++) {
        mat.elementi[i] = nullptr;
    }
    try {
        for(int i(0); i < br_redova; i++) {
            mat.elementi[i] = new Tip[br_kolona];
        }
    }
    catch(...) {
        UnistiMatricu(mat);
        throw;
    }
    return mat;
}

template <typename Tip>
void UnesiMatricu(char ime_matrice, Matrica<Tip> &mat) {
    for(int i(0); i < mat.br_redova; i++) {
        for(int j(0); j < mat.br_kolona; j++) {
            std::cout << ime_matrice << "(" << i + 1 << "," << j + 1 << ") = ";
            std::cin >> mat.elementi[i][j];
        }
    }
}

template <typename Tip>
void IspisiMatricu(const Matrica<Tip> &mat, int sirina_ispisa, int preciznost = 6, bool treba_brisati = false) {
    for(int i(0); i < mat.br_redova; i++) {
        for(int j(0); j < mat.br_kolona; j++) {
            std::cout << std::setw(sirina_ispisa) << std::setprecision(preciznost) << mat.elementi[i][j];
        }
        std::cout << std::endl;
    }
    if(treba_brisati) UnistiMatricu(mat);
}

template <typename Tip>
Matrica<Tip> ZbirMatrica(const Matrica<Tip> &m1, const Matrica<Tip> &m2) {
    if(m1.br_redova != m2.br_redova || m1.br_kolona != m2.br_kolona) throw std::domain_error("Matrice nemaju jednake dimenzije!");
    auto m3(StvoriMatricu<Tip>(m1.br_redova, m1.br_kolona));
    for(int i(0); i < m1.br_redova; i++) {
        for(int j(0); j < m1.br_kolona; j++) {
            m3.elementi[i][j] = m1.elementi[i][j] + m2.elementi[i][j];
        }
    }
    return m3;
}

template <typename Tip>
Matrica<Tip> ProduktMatrica(const Matrica<Tip> &m1, const Matrica<Tip> &m2) {
    if(m1.br_kolona != m2.br_redova) throw std::domain_error("Matrice nisu saglasne za mnozenje");
    auto m3(StvoriMatricu<Tip>(m1.br_redova, m2.br_kolona));
    for(int i(0); i < m3.br_redova; i++) {
        for(int j(0); j < m3.br_kolona; j++) {
            m3.elementi[i][j] = 0;
        }
    }
    for(int i(0); i < m3.br_redova; i++) {
        for(int j(0); j < m3.br_kolona; j++) {
            for(int k(0); k < m1.br_kolona; k++) {
                m3.elementi[i][j] += m1.elementi[i][k] * m2.elementi[k][j];
            }
        }
    }
    return m3;
}

template <typename Tip, typename IterTip>
Matrica<Tip> MatricniPolinom(const Matrica<Tip> &A, int n, IterTip it) {
    if(n < 0) throw std::domain_error("Neispravan stepen polinoma");
    if(A.br_kolona != A.br_redova) throw std::domain_error("Matrica mora biti kvadratna");
    auto rezultat = StvoriMatricu<Tip>(A.br_redova, A.br_kolona);
    for(int i(0); i < rezultat.br_redova; i++) {
        for(int j(0); j < rezultat.br_kolona; j++) {
            rezultat.elementi[i][j] = 0;
        }
    }
    for(int i(0); i <= n; i++) {
        try {
            auto jedinicna(StvoriMatricu<Tip>(A.br_kolona, A.br_kolona));
            for(int j(0); j < jedinicna.br_redova; j++) {
                for(int k(0); k < jedinicna.br_kolona; k++) {
                    if(j == k) jedinicna.elementi[j][k] = 1;
                    else jedinicna.elementi[j][k] = 0;
                }
            }
            for(int j(0); j < i; j++) {
                auto drugi = jedinicna;
                try {
                    jedinicna = ProduktMatrica(jedinicna, A);
                    UnistiMatricu(drugi);
                }
                catch(...) {
                    UnistiMatricu(jedinicna);
                    throw;
                }
            }
            for(int j(0); j < jedinicna.br_redova; j++) {
                for(int k(0); k < jedinicna.br_kolona; k++) {
                    jedinicna.elementi[j][k] = jedinicna.elementi[j][k] * *it;
                }
            }
            auto kopija = rezultat;
            try {
                rezultat = ZbirMatrica(jedinicna, rezultat);
                UnistiMatricu(kopija);
                UnistiMatricu(jedinicna);
                it++;
            }
            catch(...) {
                UnistiMatricu(jedinicna);
                throw;
            }
        }
        catch(...) {
            UnistiMatricu(rezultat);
        }
    }
    return rezultat;
}

int main () {
    std::cout << "Unesite dimenziju kvadratne matrice: ";
    int dimenzija;
    std::cin >> dimenzija;
    Matrica<int> mat;
    try {
        mat = StvoriMatricu<int>(dimenzija, dimenzija);
        std::cout << "Unesite elemente matrice A: " << std::endl;
        UnesiMatricu('A', mat);
        std::cout << "Unesite red polinoma: ";
        int n;
        std::cin >> n;
        std::vector<int> koeficijenti;
        std::cout << "Unesite koeficijente polinoma: ";
        for(int i(0); i <= n; i++) {
            int koef;
            std::cin >> koef;
            koeficijenti.push_back(koef);
        }
        IspisiMatricu(MatricniPolinom(mat, n, koeficijenti.begin()), 10, 6, true);
    }
    catch(...) {
        // neki ispis za memoriju
    }
    UnistiMatricu(mat);
	return 0;
}
