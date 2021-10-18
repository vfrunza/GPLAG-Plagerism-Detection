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
            mat.elementi[i] = new TipElemenata[br_kolona]();
    }
    catch (...) {
        UnistiMatricu(mat);
        throw;
    }
    return mat;
}

template <typename TipElemenata>
void UnesiMatricu(char ime_matrice, Matrica<TipElemenata> &mat) {
    for (int i = 0; i <mat.br_redova; i++) 
        for (int j = 0; j < mat.br_kolona; j++) {
            std::cout << ime_matrice << "(" << i + 1 << "," << j + 1 << ") = ";
            std::cin >> mat.elementi[i][j];
        }
}

template <typename TipElemenata>
void IspisiMatricu(const Matrica<TipElemenata> &mat, int sirina,
    int preciznost = 6, bool treba_brisati = false) {
    for (int i = 0; i < mat.br_redova; i++) {
        for (int j = 0; j < mat.br_kolona; j++)
            std::cout << std::setw(sirina) << std::setprecision(preciznost) << mat.elementi[i][j];
        std::cout << std::endl;
    }
    if (treba_brisati) UnistiMatricu(mat);
}

template <typename TipElemenata>
Matrica<TipElemenata> ZbirMatrica(const Matrica<TipElemenata> &m1,
    const Matrica<TipElemenata> &m2) {
        if (m1.br_redova != m2.br_redova || m1.br_kolona != m2.br_kolona)
            throw std::domain_error("Matrice nemaju jednake dimenzije!");
        auto m3(StvoriMatricu<TipElemenata>(m1.br_redova, m1.br_kolona));
        for (int i = 0; i < m1.br_redova; i++)
            for (int j = 0; j < m1.br_kolona; j++)
                m3.elementi[i][j] = m1.elementi[i][j] + m2.elementi[i][j];
        return m3;
}

template <typename TipElemenata>
Matrica<TipElemenata> ProduktMatrica(const Matrica<TipElemenata> &m1,
    const Matrica<TipElemenata> &m2) {
    if (m1.br_kolona != m2.br_redova) 
        throw std::domain_error("Matrice nisu saglasne za mnozenje");
    auto m3(StvoriMatricu<TipElemenata>(m1.br_redova, m2.br_kolona));
    for (int i = 0; i < m1.br_redova; i++) 
        for (int j = 0; j < m2.br_kolona; j++) {
            TipElemenata suma(0);
            for (int k = 0; k < m1.br_kolona; k++)
                suma += m1.elementi[i][k]*m2.elementi[k][j];
            m3.elementi[i][j] = suma;
        }
    return m3;
}

template <typename TipElemenata>
void PretvoriUJedinicnu(Matrica<TipElemenata> &m) {
    for (int i = 0; i < m.br_redova; i++)
        for (int j = 0; j < m.br_kolona; j++)
            if (i == j) m.elementi[i][j] = 1;
            else m.elementi[i][j] = 0;
}

template <typename TipElemenata>
Matrica<TipElemenata> Dodijeli(const Matrica<TipElemenata> &m) {
    auto nova(StvoriMatricu<TipElemenata>(m.br_redova, m.br_kolona));
    for (int i = 0; i < nova.br_redova; i++)
        for (int j = 0; j < nova.br_kolona; j++)
            nova.elementi[i][j] = m.elementi[i][j];
    return nova;
}

template <typename TipElemenata>
void SkalarXMat(Matrica<TipElemenata> &mat, TipElemenata a) {
    for (int i = 0; i < mat.br_redova; i++)
        for (int j = 0; j < mat.br_kolona; j++)
            mat.elementi[i][j] *= a;
}

template <typename TipElemenata, typename ItTip>
Matrica<TipElemenata> MatricniPolinom(const Matrica<TipElemenata> &mat,
    int n, ItTip it) {
    if (n < 0) throw std::domain_error("Neispravan stepen polinoma");
    if (mat.br_redova != mat.br_kolona) 
        throw std::domain_error("Matrica mora biti kvadratna");
    auto matpolinom(StvoriMatricu<TipElemenata>(mat.br_redova, mat.br_kolona));
    for (int k = 0; k <= n; k++) {
        auto proizvod(Dodijeli<TipElemenata>(mat));
        if (k == 0) PretvoriUJedinicnu(proizvod);
        for (int i = 2; i <= k; i++) {
            auto pomocna(proizvod);
            proizvod = ProduktMatrica<TipElemenata>(proizvod, mat);
            UnistiMatricu(pomocna);
        }
        auto pomocna(matpolinom);
        SkalarXMat(proizvod, *it++);
        matpolinom = ZbirMatrica<TipElemenata>(matpolinom, proizvod);
        UnistiMatricu(pomocna);
        UnistiMatricu(proizvod);
    }
    return matpolinom;
}


int main ()
{
    int n;
    std::cout << "Unesite dimenziju kvadratne matrice: ";
    std::cin >> n;
    auto mat(StvoriMatricu<double>(n,n));
    std::cout << "Unesite elemente matrice A:" << std::endl;
    UnesiMatricu('A', mat);
    try {
        std::cout << "Unesite red polinoma: ";
        std::cin >> n;
        std::vector<double> v(n+1);
        std::cout << "Unesite koeficijente polinoma: ";
        for (auto &x : v) std::cin >> x;
        IspisiMatricu(MatricniPolinom(mat, n, v.begin()), 10, 6, true);
        UnistiMatricu(mat);
    }
    catch(std::domain_error e) {
        std::cout << e.what();
        if (mat.elementi) UnistiMatricu(mat);
    }
    catch(...) {
        std::cout << "Greska sa memorijom";
    }
	return 0;
}
