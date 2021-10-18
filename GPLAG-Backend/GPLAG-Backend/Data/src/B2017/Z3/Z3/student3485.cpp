/B2017/2018: Zadaća 3, Zadatak 3
#include <iostream>
#include <stdexcept>
#include <new>
#include <vector>
#include <iomanip>

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
    Matrica<TipElemenata> StvoriMatricu(int br_redova, int br_kolona) {
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
    void IspisiMatricu(const Matrica<TipElemenata> &mat, int sirina_ispisa) {
        for(int i = 0; i < mat.br_redova; i++) {
            for(int j = 0; j < mat.br_kolona; j++)
                std::cout << std::setw(sirina_ispisa) << mat.elementi[i][j];
                    std::cout << std::endl;
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
    Matrica <TipElemenata> ProduktMatrica(const Matrica<TipElemenata> &m1, const Matrica<TipElemenata> &m2)
    {
        if(m1.br_kolona != m2.br_redova)
            throw std::domain_error("Matrice nisu saglasne za mnozenje");
        auto mat = StvoriMatricu<TipElemenata>(m1.br_redova, m2.br_kolona);
        for(int i=0; i<m1.br_redova; i++)
        {
            for(int j=0; j<m2.br_kolona; j++)
            {
                TipElemenata produkt(0);
                for(int k=0; k<m1.br_redova; k++)
                    produkt += m1.elementi[i][k] * m2.elementi[k][j];
                    mat.elementi[i][j] = produkt;
            }
        }
        return mat;
    }

template <typename TipElemenata>
    bool Kvadratna(const Matrica<TipElemenata> &m)
    {
        if(m.br_kolona != m.br_redova)
            return false;
        return true;
    }
template <typename TipElemenata>
    Matrica<TipElemenata> MatricniPolinom(const Matrica<TipElemenata> &M, int n, TipElemenata *p1)
    {
        if(n < 0) throw std::domain_error("Neispravan stepen polinoma");
        if(!Kvadratna(M)) throw std::domain_error("Matrica mora biti kvadratna");
        auto Mat(StvoriMatricu<TipElemenata>(M.br_redova, M.br_kolona));
        
        return Mat;
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
        /*int v = 10;
        for (int i = 0; i <= red; i++) {
            double broj;
            std::cin >> broj;
            v.push_back(broj);
        }
        c = MatricniPolinom(a, v, 10);
        IspisiMatricu(c, 10);*/
    }
    catch(std::bad_alloc) {
        std::cout << "Nema dovoljno memorije!\n";
        UnistiMatricu(a); UnistiMatricu(c);
    }
    UnistiMatricu(a); UnistiMatricu(c);
    return 0;
}














