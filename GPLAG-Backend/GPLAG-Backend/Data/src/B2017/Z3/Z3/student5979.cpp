/B2017/2018: Zadaća 3, Zadatak 3
#include <iostream>
#include <iomanip>
#include <stdexcept>
#include <new>
#include <vector>

template <typename Tip1>
struct Matrica {
    int br_redova, br_kolona;
    Tip1** elementi = nullptr;
};

template <typename Tip2>
void UnistiMatricu(Matrica<Tip2> mat){
    if(!mat.elementi) return;
    for (int i = 0; i < mat.br_redova; i++) {
        delete[] mat.elementi[i];
    }
    delete[] mat.elementi;
    mat.elementi = nullptr;
}

template <typename Tip3>
Matrica<Tip3> StvoriMatricu(int br_redova1, int br_kolona1) {
    Matrica<Tip3> mat;
    mat.br_redova = br_redova1;
    mat.br_kolona = br_kolona1;
    mat.elementi = new Tip3*[br_redova1];
    for (int i = 0; i < br_redova1; i++) {
        mat.elementi[i] = nullptr;
    }
    try {
        for (int i = 0; i < br_redova1; i++) {
            mat.elementi[i] = new Tip3[br_kolona1];
        }
    }
    catch (...) {
        UnistiMatricu(mat);
        throw;
    }
    return mat;
}

template <typename Tip4>
void UnesiMatricu(char ime_matrice, Matrica <Tip4> &mat) {
    for (int i = 0; i < mat.br_redova; i++) {
        for (int j = 0; j < mat.br_kolona; j++) {
            std::cout << ime_matrice << "(" << i+1 << "," << j+1 << ") = ";
            std::cin >> mat.elementi[i][j];
        }
    }
}

template <typename Tip5>
void IspisiMatricu(const Matrica<Tip5> &mat, int sirina_ispisa, int preciznost = 6, bool treba_brisati = false) {
    for (int i = 0; i < mat.br_redova; i++) {
        for (int j = 0; j < mat.br_kolona; j++) {
            std::cout << std::setw(sirina_ispisa) << std::setprecision(preciznost) << mat.elementi[i][j];
        }
        std::cout  << std::endl;
    }
    if(treba_brisati)
        UnistiMatricu(mat);
}

template <typename Tip6>
Matrica<Tip6> ZbirMatrica(const Matrica<Tip6> &m1, const Matrica<Tip6> &m2) {
    if(m1.br_redova != m2.br_redova || m1.br_kolona != m2.br_kolona)
        throw std::domain_error("Matrice nemaju jednake dimenzije!");
    auto m3(StvoriMatricu<Tip6>(m1.br_redova, m1.br_kolona));
    for (int i = 0; i < m1.br_redova; i++) {
        for (int j = 0; j < m1.br_kolona; j++) {
            m3.elementi[i][j] = m1.elementi[i][j] + m2.elementi[i][j];
        }
    }
    return m3;
}

template <typename Tip7>
Matrica<Tip7> ProduktMatrica(Matrica<Tip7> m1, Matrica<Tip7> m2) {
    if(m1.br_kolona != m2.br_redova)
        throw std::domain_error("Matrice nisu saglasne za mnozenje");
    auto m3(StvoriMatricu<Tip7>(m1.br_redova, m2.br_kolona));
    for (int i = 0; i < m1.br_redova; i++) {
        for (int j = 0; j < m2.br_kolona; j++) {
            Tip7 a = Tip7();
            for (int k = 0; k < m1.br_kolona; k++) {
                a += m1.elementi[i][k]*m2.elementi[k][j];
            }
            m3.elementi[i][j] = a;
        }
    }
    return m3;
}

template <typename Tip8, typename Tip9>
Matrica<Tip8> MatricniPolinom(Matrica<Tip8> m, int n, Tip9 it) {
    if(n < 0)
        throw std::domain_error("Neispravan stepen polinoma");
    if(m.br_kolona != m.br_redova)
        throw std::domain_error("Matrica mora biti kvadratna");
    // Matrica<Tip8> rezultat = StvoriMatricu<Tip8>(m.br_redova, m.br_kolona);
    std::vector<Matrica<Tip8>> stepeni;
    auto jedinicna(StvoriMatricu<Tip8>(m.br_redova, m.br_kolona));
    for (int i = 0; i < jedinicna.br_redova; i++) {
        for (int j = 0; j < jedinicna.br_kolona; j++) {
            if(i == j)
                jedinicna.elementi[i][j] = 1.;
            else
                jedinicna.elementi[i][j] = 0.;
        }
    }
    stepeni.push_back(jedinicna);
    for (int i = 0; i < n; i++) {
        stepeni.push_back(ProduktMatrica(stepeni.at(i), m));
    }
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j < stepeni.at(i).br_redova; j++) {
            for (int k = 0; k < stepeni.at(i).br_kolona; k++) {
                stepeni.at(i).elementi[j][k] *= *it;
            }
        }
        it++;
    }
    std::vector<Matrica<Tip8>> zbirovi;
    auto nula = StvoriMatricu<Tip8>(m.br_redova, m.br_kolona);
    for (int i = 0; i < nula.br_redova; i++) {
        for (int j = 0; j < nula.br_kolona; j++) {
            nula.elementi[i][j] = 0;
        }
    }
    zbirovi.push_back(nula);
    for (int i = 0; i < n; i++) {
        zbirovi.push_back(ZbirMatrica(zbirovi.at(i), stepeni.at(i)));
    }
    auto rezultat = ZbirMatrica(zbirovi.at(zbirovi.size() - 1), stepeni.at(stepeni.size() - 1));
    for (int i = 0; i < stepeni.size(); i++) {
        UnistiMatricu(stepeni.at(i));
    }
    for (int i = 0; i < zbirovi.size(); i++) {
        UnistiMatricu(zbirovi.at(i));
    }
    return rezultat;
}

int main ()
{
    std::cout << "Unesite dimenziju kvadratne matrice: ";
    int dimenzija;
    std::cin >> dimenzija;
    std::cout << "Unesite elemente matrice A: " << std::endl;
    Matrica<double> matrica = StvoriMatricu<double>(dimenzija, dimenzija);
    UnesiMatricu('A', matrica);
    std::cout << "Unesite red polinoma: ";
    int red_polinoma;
    std::cin >> red_polinoma;
    std::cout << "Unesite koeficijente polinoma: ";
    int a;
    std::vector<int> koeficijenti;
    for (int i = 0; i <= red_polinoma; i++) {
        std::cin >> a;
        koeficijenti.push_back(a);
    }
    IspisiMatricu(MatricniPolinom(matrica, red_polinoma, koeficijenti.begin()), 10, 6, true);
    UnistiMatricu(matrica);
	return 0;
}
