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
    if(!mat.elementi) return;
    for(int i = 0; i < mat.br_redova; i++) delete[] mat.elementi[i];
    delete[] mat.elementi;
    mat.elementi = nullptr;
}
template <typename TipElemenata>
Matrica<TipElemenata> StvoriMatricu(int br_redova, int br_kolona) { // dodao i da mi incijalizira matricu tj. da svi njeni elementi budu = 0
    Matrica<TipElemenata> mat;
    mat.br_redova = br_redova; mat.br_kolona = br_kolona;
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
    for (int i = 0; i < br_redova; i++) {
        for (int j = 0; j < br_kolona; j++) {
            mat.elementi[i][j] = 0;
        }
    }
    return mat;
}
template <typename TipElemenata>
void UnesiMatricu(char ime_matrice, Matrica<TipElemenata> &mat) {
    for(int i = 0; i < mat.br_redova; i++)
        for(int j = 0; j < mat.br_kolona; j++) {
            std::cout << ime_matrice << "(" << i + 1 << "," << j + 1 << ") = ";
            std::cin >> mat.elementi[i][j];
    }
}
template <typename TipElemenata>
void IspisiMatricu(const Matrica<TipElemenata> &mat, int sirina_ispisa, int preciznost = 6, bool treba_brisati = false) {
    for(int i = 0; i < mat.br_redova; i++) {
        for(int j = 0; j < mat.br_kolona; j++) {
            std::cout << std::setw(sirina_ispisa) << std::setprecision(preciznost) << mat.elementi[i][j];
        }
        std::cout << std::endl;
    }
    if (treba_brisati) {
        UnistiMatricu(mat);
    }
}
template <typename TipElemenata>
Matrica<TipElemenata> ZbirMatrica(const Matrica<TipElemenata> &m1, const Matrica<TipElemenata> &m2) {
    if(m1.br_redova != m2.br_redova || m1.br_kolona != m2.br_kolona)
        throw std::domain_error("Matrice nemaju jednake dimenzije!");
    auto m3(StvoriMatricu<TipElemenata>(m1.br_redova, m1.br_kolona));
    for(int i = 0; i < m1.br_redova; i++)
        for(int j = 0; j < m1.br_kolona; j++)
            m3.elementi[i][j] = m1.elementi[i][j] + m2.elementi[i][j];
    return m3;
}
template <typename TipElemenata>
Matrica<TipElemenata> ProduktMatrica(const Matrica<TipElemenata> &m1, const Matrica<TipElemenata> &m2) {
    if (m1.br_kolona != m2.br_redova) {
        throw std::domain_error("Matrice nisu saglasne za mnozenje");
    }
    auto m = StvoriMatricu<TipElemenata>(m1.br_redova, m2.br_kolona);
    for (int i = 0; i < m1.br_redova; i++) {
        for (int j = 0; j < m2.br_kolona; j++) {
            for (int k = 0; k < m1.br_kolona; k++) {
                m.elementi[i][j] += m1.elementi[i][k] * m2.elementi[k][j];
            }
        }
    }
    return m;
}
template <typename TipElemenata>
Matrica<TipElemenata> MatricniPolinom(const Matrica<TipElemenata> &M, std::vector<double> k) {
    if (M.br_kolona !=M.br_redova) {
        throw std::domain_error("Matrica mora biti kvadratna");
    }
    if (k.size() == 0) {
        return StvoriMatricu<TipElemenata>(M.br_redova, M.br_kolona);
    }
    
    auto mat = StvoriMatricu<TipElemenata>(M.br_redova, M.br_kolona);
    
    for (int i = 0; i < k.size(); i++) {
        auto pom = StvoriMatricu<TipElemenata>(M.br_redova, M.br_kolona);
        Matrica<TipElemenata> pom2;
        for (int m = 0; m < pom.br_redova; m++) {
            for (int n = 0; n < pom.br_kolona; n++) {
                if (m == n) {
                    pom.elementi[m][n] = 1;
                }
            }
        }
        
        if (i > 0) {
            for (int m = 0; m < i; m++) {
                pom2 = pom;
                pom = ProduktMatrica(pom, M);
                UnistiMatricu(pom2);
            }
        }
        
        for (int m = 0; m < pom.br_redova; m++) {
            for (int n = 0; n < pom.br_kolona; n++) {
                pom.elementi[m][n] *= k[i];
            }
        }
        pom2 = mat;
        mat = ZbirMatrica(mat, pom);
        UnistiMatricu(pom2);
        UnistiMatricu(pom);
    }
    
    return mat;
}
int main() {
    Matrica<double> a;
    int m, r;
    std::vector<double> polinom;
    std::cout << "Unesite dimenziju kvadratne matrice: ";
    std::cin >> m;
    try {
        a = StvoriMatricu<double>(m, m);
        std::cout << "Unesite elemente matrice A:" << std::endl;
        UnesiMatricu('A', a);
        std::cout << "Unesite red polinoma: ";
        std::cin >> r;
        std::cout << "Unesite koeficijente polinoma: ";
        polinom.resize(r+1);
        for (int i = 0; i < polinom.size(); i++) {
            std::cin >> polinom[i];
        }
        IspisiMatricu(MatricniPolinom(a, polinom), 10, 6, true);
    }
    catch(std::bad_alloc) {
        std::cout << "Nema dovoljno memorije!\n";
    }
    catch(std::domain_error e) {
        std::cout << e.what() << std::endl;
    }
    UnistiMatricu(a);
    return 0;
}