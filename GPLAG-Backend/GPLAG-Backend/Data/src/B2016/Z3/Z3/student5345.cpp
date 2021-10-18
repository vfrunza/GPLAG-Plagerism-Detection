/B2016/2017: Zadaća 3, Zadatak 3
#include <iostream>
#include <iomanip>
#include <stdexcept>
#include <new>
#include <vector>

template <typename TipElemenata>
 struct Matrica {
 int br_redova, br_kolona;
 TipElemenata **elementi = nullptr; // VEOMA BITNA INICIJALIZACIJA!
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
 std::cout << ime_matrice
 << "(" << i + 1 << "," << j + 1 << ") = ";
 std::cin >> mat.elementi[i][j];
 }
 }
 
template <typename TipElemenata>
 void IspisiMatricu(const Matrica<TipElemenata> &mat,
 int sirina_ispisa, int preciznost = 6, bool treba_brisati = false) {
 for(int i = 0; i < mat.br_redova; i++) {
 for(int j = 0; j < mat.br_kolona; j++)
 std::cout << std::setw(sirina_ispisa) << std::setprecision(preciznost) << mat.elementi[i][j];
 std::cout << std::endl;
 }
 if (treba_brisati) UnistiMatricu(mat);
 }
 
template <typename TipElemenata>
 Matrica<TipElemenata> ZbirMatrica(const Matrica<TipElemenata> &m1,
 const Matrica<TipElemenata> &m2) {
 if(m1.br_redova != m2.br_redova || m1.br_kolona != m2.br_kolona)
 throw std::domain_error("Matrice nemaju jednake dimenzije!");
 auto m3(StvoriMatricu<TipElemenata>(m1.br_redova, m1.br_kolona));
 for(int i = 0; i < m1.br_redova; i++)
 for(int j = 0; j < m1.br_kolona; j++)
 m3.elementi[i][j] = m1.elementi[i][j] + m2.elementi[i][j];
 return m3;
}

using std::domain_error;

template <typename TipElemenata>
Matrica<TipElemenata> ProduktMatrica(const Matrica<TipElemenata> &m1, const Matrica<TipElemenata> &m2) {
    if (m1.br_kolona != m2.br_redova) throw domain_error("Matrice nisu saglasne za mnozenje");
    auto m3(StvoriMatricu<TipElemenata>(m1.br_redova, m2.br_kolona));
    for (int i = 0; i < m1.br_redova; i++) {
        for (int j = 0; j < m2.br_kolona; j++) {
            m3.elementi[i][j] = 0;
            for (int k = 0; k < m1.br_kolona; k++)
                m3.elementi[i][j] = m3.elementi[i][j] + m1.elementi[i][k] * m2.elementi[k][j];
        }
    }
    return m3;
}

template <typename TipElemenata>
void PomnoziiSaberi(Matrica<TipElemenata> &m1, const Matrica<TipElemenata> &m2, double d) {
    auto nova(StvoriMatricu<TipElemenata>(m2.br_redova, m2.br_kolona));
    for (int i = 0; i < m2.br_redova; i++)
        for (int j = 0; j < m2.br_kolona; j++)
            nova.elementi[i][j] = m2.elementi[i][j] * d;
    auto m(ZbirMatrica(m1, nova));
    auto temp(m);
    temp = m1;
    m1 = m;
    m = temp;
    UnistiMatricu(m);
    UnistiMatricu(nova);
}

template <typename TipElemenata>
void Stepenuj(Matrica<TipElemenata> &m1, const Matrica<TipElemenata> &m2){
    auto m(ProduktMatrica(m1, m2));
    auto temp(m);
    temp = m1;
    m1 = m;
    m = temp;
    UnistiMatricu(m);
}

template <typename TipElemenata>
Matrica<TipElemenata> MatricniPolinom(const Matrica<TipElemenata> &m, std::vector<double> v) {
    if (m.br_kolona != m.br_redova) throw domain_error("Matrica nije kvadratna");
    auto suma(StvoriMatricu<TipElemenata>(m.br_redova, m.br_kolona));
    for (int i = 0; i < m.br_redova; i++)
        for (int j = 0; j < m.br_kolona; j++)
            suma.elementi[i][j] = 0;
            
    auto proizvod(StvoriMatricu<TipElemenata>(m.br_redova, m.br_kolona));
    for (int i = 0; i < m.br_redova; i++)
        for (int j = 0; j < m.br_kolona; j++)
            if (i != j) proizvod.elementi[i][j] = 0; else proizvod.elementi[i][j] = 1;
            
    for (int i = 0; i < v.size(); i++) {
        if (i != 0) Stepenuj(proizvod, m);
        PomnoziiSaberi(suma, proizvod, v[i]);
    }
    UnistiMatricu(proizvod);
    return suma;
}


int main() {
    std::cout << "Unesite dimenziju kvadratne matrice: ";
    int n;
    std::cin >> n;
    auto m(StvoriMatricu<double>(n, n));
    std::cout << "Unesite elemente matrice A:" << std::endl;
    UnesiMatricu('A', m);
    std::cout << "Unesite red polinoma: ";
    int k;
    std::cin >> k;
    std::cout << "Unesite koeficijente polinoma: ";
    std::vector<double> v(k + 1);
    for (int i = 0; i < k + 1; i++) {
        std::cin >> v[i];
    }
    auto m1(MatricniPolinom(m, v));
    IspisiMatricu(m1, 10, 6);
    UnistiMatricu(m1);
    UnistiMatricu(m);
 return 0;
}