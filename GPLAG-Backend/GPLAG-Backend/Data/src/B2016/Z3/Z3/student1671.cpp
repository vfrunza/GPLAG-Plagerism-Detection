/B2016/2017: Zadaća 3, Zadatak 3
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
    void UnistiMatricu(Matrica<TipElemenata> mat) {
        if (!mat.elementi) return;
        for (int i = 0; i < mat.br_redova; i++) delete[] mat.elementi[i];
        delete[] mat.elementi;
        mat.elementi = nullptr;
    }
template <typename TipElemenata>
    Matrica<TipElemenata> StvoriMatricu(int br_redova, int br_kolona) {
        Matrica<TipElemenata> mat;
        mat.br_redova = br_redova; mat.br_kolona = br_kolona;
        mat.elementi = new TipElemenata*[br_redova];
        for (int i = 0; i < br_redova; i++) mat.elementi[i] = nullptr;
        try {
            for (int i = 0; i < br_redova; i++)
                mat.elementi[i] = new TipElemenata[br_kolona];
        }
        catch(...) {
            UnistiMatricu(mat);
            throw;
        }
        return mat;
    }
template <typename TipElemenata>
    void UnesiMatricu(char ime_matrice, Matrica<TipElemenata> &mat) {
        for (int i = 0; i < mat.br_redova; i++)
            for (int j = 0; j < mat.br_kolona; j++) {
                std::cout << ime_matrice << "(" << i + 1 << "," << j + 1 << ") = ";
                std::cin >> mat.elementi[i][j];
            }
    }
template <typename TipElemenata>
    void IspisiMatricu(const Matrica<TipElemenata> &mat, int sirina_ispisa, int preciznost = 6, bool treba_brisati = false) {
        for (int i = 0; i < mat.br_redova; i++) {
            for (int j = 0; j < mat.br_kolona; j++)
                std::cout << std::setw(sirina_ispisa) << std::setprecision(preciznost) << mat.elementi[i][j];
            std::cout << std::endl;
        }
        if (treba_brisati) UnistiMatricu(mat);
    }
template <typename TipElemenata>
    Matrica<TipElemenata> ZbirMatrica(const Matrica<TipElemenata> &m1, const Matrica<TipElemenata> &m2) {
        if (m1.br_redova != m2.br_redova || m1.br_kolona != m2.br_kolona)
            throw std::domain_error ("Matrice nemaju jednake dimenzije!");
        auto m3(StvoriMatricu<TipElemenata>(m1.br_redova, m1.br_kolona));
        for (int i = 0; i < m1.br_redova; i++)
            for (int j = 0; j < m1.br_kolona; j++)
                m3.elementi[i][j] = m1.elementi[i][j] + m2.elementi[i][j];
        return m3;
    }
template <typename TipElemenata>
    Matrica<TipElemenata> ProduktMatrica(const Matrica<TipElemenata> &m1, const Matrica<TipElemenata> &m2) {
        if (m1.br_kolona != m2.br_redova) throw std::domain_error ("Matrice nisu saglasne za mnozenje");
        auto m3(StvoriMatricu<TipElemenata>(m1.br_redova, m2.br_kolona));
        for (int i = 0; i < m1.br_redova; i++) {
            for (int j = 0; j < m2.br_kolona; j++) {
                TipElemenata proizvod(0);
                for (int k = 0; k < m1.br_kolona; k++) proizvod += (m1.elementi[i][k]) * (m2.elementi[k][j]);
                m3.elementi[i][j] = proizvod;
            }
        }
        return m3;
    }
template <typename TipElemenata>
    bool DaLiJeKvadratna(const Matrica<TipElemenata> &m1) {
        if(m1.br_kolona != m1.br_redova) return false;
        return true;
    }
template <typename TipElemenata>
    Matrica<TipElemenata> MatricniPolinom(const Matrica<TipElemenata> &A, std::vector<double> koeficijenti) {
        if (!DaLiJeKvadratna(A)) throw std::domain_error ("Matrica mora biti kvadratna");
        auto M(StvoriMatricu<TipElemenata>(A.br_redova, A.br_kolona));
        for (int i = 0; i < A.br_redova; i++)
            for (int j = 0; j < A.br_kolona; j++) M.elementi[i][j] = 0;
        if (!koeficijenti.size()) return M;
        for (int i = 0; i < koeficijenti.size(); i++) {
            auto pom(StvoriMatricu<TipElemenata>(A.br_redova, A.br_kolona));
            for (int k = 0; k < A.br_redova; k++)
                for (int j = 0; j < A.br_kolona; j++) pom.elementi[k][j] = A.elementi[k][j];
            if (i == 0) {
                for (int i = 0; i < pom.br_redova; i++)
                    for (int j = 0; j < pom.br_kolona; j++) {
                        if (i == j) pom.elementi[i][j] = 1;
                        else pom.elementi[i][j] = 0;
                    }
            }   
            else for (int j = 1; j < i; j++) {
                auto temp(StvoriMatricu<TipElemenata>(pom.br_redova, pom.br_kolona));
                for (int u = 0; u < pom.br_redova; u++)
                    for (int l = 0; l < pom.br_kolona; l++) temp.elementi[u][l] = pom.elementi[u][l];
                UnistiMatricu(pom);
                pom = ProduktMatrica(temp, A);
                UnistiMatricu(temp);
            }
            for (int j = 0; j < A.br_redova; j++)
                for (int k = 0; k < A.br_kolona; k++) pom.elementi[j][k] *= koeficijenti[i];
            auto T(StvoriMatricu<TipElemenata>(M.br_redova, M.br_kolona));
            for (int u = 0; u < M.br_redova; u++)
                for (int l = 0; l < M.br_kolona; l++) T.elementi[u][l] = M.elementi[u][l];
            UnistiMatricu(M);
            M = ZbirMatrica(T, pom);
            UnistiMatricu(T);
            UnistiMatricu(pom);
        }
        return M;    
    }

int main() {
    Matrica<double> a, c;
    int m;
    std::cout << "Unesite dimenziju kvadratne matrice: ";
    std::cin >> m;
    try {
        a = StvoriMatricu<double>(m, m); 
        std::cout << "Unesite elemente matrice A:\n";
        UnesiMatricu('A', a);
        int red;
        std::cout << "Unesite red polinoma: ";
        std::cin >> red;
        std::cout << "Unesite koeficijente polinoma: ";
        std::vector<double> v;
        for (int i = 0; i <= red; i++) {
            double broj;
            std::cin >> broj;
            v.push_back(broj);
        }
        IspisiMatricu(c = MatricniPolinom(a, v), 10);
    }
    catch(std::bad_alloc) {
        std::cout << "Nema dovoljno memorije!\n";
        UnistiMatricu(a); UnistiMatricu(c);
    }
    UnistiMatricu(a); UnistiMatricu(c);
    return 0;
}

