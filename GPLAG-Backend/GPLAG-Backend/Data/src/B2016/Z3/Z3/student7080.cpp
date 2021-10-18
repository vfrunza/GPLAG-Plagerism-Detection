/B2016/2017: Zadaća 3, Zadatak 3
#include <iostream>
#include <iomanip>
#include <stdexcept>
#include <new>
#include <vector>
#include <cmath>

template <typename TipElemenata>
struct Matrica {
    int br_redova, br_kolona;
    TipElemenata **elementi = nullptr;   // postavljamo dvojni pok na nullptr
};

template <typename TipElemenata>
void UnistiMatricu(Matrica<TipElemenata> mat) {
    if(!mat.elementi) return;   // ako nije bilo nikakve alokacije
    for(int i = 0; i < mat.br_redova; i++) delete[] mat.elementi[i];
    delete[] mat.elementi;
    mat.elementi = nullptr;
}

template <typename TipElemenata>
Matrica<TipElemenata> StvoriMatricu(int br_redova, int br_kolona) {
    Matrica<TipElemenata> mat;
    mat.br_redova = br_redova;
    mat.br_kolona = br_kolona;
    mat.elementi = new TipElemenata*[br_redova];
    
    for(int i = 0; i < br_redova; i++) mat.elementi[i] = nullptr;    // postavljamo niz pokazivaca na nullptr
    try {
        for(int i = 0; i < br_redova; i++) mat.elementi[i] = new TipElemenata[br_kolona];
    }
    catch (...) {
        UnistiMatricu(mat);
        throw;
    }
    return mat;
}

template <typename TipElemenata>
void UnesiMatricu(char ime_matrice, Matrica<TipElemenata> &mat) {      // unos elemenata matrice
    for(int i = 0; i < mat.br_redova; i++)
      for(int j = 0; j < mat.br_kolona; j++) {
          std::cout << ime_matrice << "(" << i + 1 << "," << j + 1 << ") = ";
          std::cin >> mat.elementi[i][j];
      }
}

template <typename TipElemenata>
void IspisiMatricu(const Matrica<TipElemenata> &mat, int sirina_ispisa, int preciznost = 6, bool treba_brisati = false) {
    
    for(int i = 0; i < mat.br_redova; i++) {
        for(int j = 0; j < mat.br_kolona; j++) 
           std::cout << std::setw(sirina_ispisa) << std::setprecision(preciznost) << mat.elementi[i][j];
        
        std::cout << std::endl;
    }
    if(treba_brisati) UnistiMatricu(mat);
}

template <typename TipElemenata>
Matrica<TipElemenata> ZbirMatrica(const Matrica<TipElemenata> &m1, const Matrica<TipElemenata> &m2) {
    if(m1.br_redova != m2.br_redova || m1.br_kolona != m2.br_kolona) throw std::domain_error("Matrice nemaju jednake dimenzije!");
    
    auto m3(StvoriMatricu<TipElemenata>(m1.br_redova, m1.br_kolona));
    
    for(int i = 0; i < m1.br_redova; i++)
      for(int j = 0; j < m1.br_kolona; j++)
        m3.elementi[i][j] = m1.elementi[i][j] + m2.elementi[i][j];
        
    return m3;
}

template <typename TipElemenata>
Matrica<TipElemenata> ProduktMatrica(const Matrica<TipElemenata> &m1, const Matrica<TipElemenata> &m2) {
    if(m1.br_kolona != m2.br_redova) throw std::domain_error("Matrice nisu saglasne za mnozenje");
    
    auto m3(StvoriMatricu<TipElemenata>(m1.br_redova, m2.br_kolona));
    
    for(int i = 0; i < m1.br_redova; i++) {
        for(int j = 0; j < m2.br_kolona; j++) {
            for(int k = 0; k < m1.br_kolona; k++) {
                m3.elementi[i][j] += m1.elementi[i][k] * m2.elementi[k][j];
            }
        }
    }
    
    return m3;
}
/*
template <typename TipElemenata>
TipElemenata Determinanta(const Matrica<TipElemenata> &mat) {
    
    int p;
    TipElemenata d = 1, mi = 0;
    for(int k = 0; k < mat.br_redova; i++) {
        p = k;
        for(int int i = k + 1; i < mat.br_redova; i++) {
            if(std::fabs(mat.elementi[i][k]) > std::fabs(mat.elementi[p][k])) p = i;
        }
        if(p != k) {
            for(int j = 0; j < mat.br_redova; j++) {  // razmijenimo k-ti i p-ti red matrice
                TipElemenata temp = mat.elementi[k][j];
                mat.elementi[k][j] = mat.elementi[p][j];
                mat.elementi[p][j] = temp;
            }
            d = -d;
        }
        for(int i = k + 1; i < mat.br_redova; i++) {
            mi = mat.elementi[i][k] / mat.elementi[k][k];
            for(int j = k + 1; j < mat.br_redova; j++)
              mat.elementi[i][j] = mat.elementi[i][j] - (mi * mat.elementi[k][j]);
        }
    }
    for(int i = 0; i < mat.br_redova; i++)
      d = d * mat.elementi[i][i];
      
    return d;
}
*/

template <typename TipElemenata>
Matrica<TipElemenata> MatricniPolinom(const Matrica<TipElemenata> &a, const std::vector<double> &v) {
    if(a.br_redova != a.br_kolona) throw std::domain_error("Matrica mora biti kvadratna");
    if(v.empty()) {
        auto m(a);
        for(int i = 0; i < m.br_redova; i++)
          for(int j = 0; j < m.br_kolona; j++)
             m.elementi[i][j] = 0;
             
        return m;
    }
    
    auto jedinicna(StvoriMatricu<TipElemenata>(a.br_redova, a.br_kolona));
    
    for(int i = 0; i < a.br_redova; i++) {
        for(int j = 0; j < a.br_kolona; j++) {
            if(i == j) jedinicna.elementi[i][j] = 1;
            else jedinicna.elementi[i][j] == 0;
        }
    }
    
    auto b(StvoriMatricu<TipElemenata>(a.br_redova, a.br_kolona));
    for(int k = 0; k < v.size(); k++) {   // petlja po stepenima polinoma
        for(int i = 0; i < a.br_redova; i++) {
            for(int j = 0; j < a.br_kolona; j++) {
                b[i][j] += v[k] * a[i][j];
            }
        }
    }
    
    UnistiMatricu(jedinicna);
    
    return b;
}

int main ()
{
    Matrica<double> a, m1, m2, m3;
    int n, z, g;
    std::cout << "Unesite dimenziju kvadratne matrice: ";
    std::cin >> n >> z >> g;
    try {
        a = StvoriMatricu<double>(n,n);
        std::cout << "Unesite elemente matrice A: \n";
        UnesiMatricu<double>('A', a);
        IspisiMatricu(a, 5, 2);
        m1 = StvoriMatricu<double>(n, z);
        m2 = StvoriMatricu<double>(z, g);
        std::cout << "Unesite elemente matrice 1: \n";
        UnesiMatricu<double>('1', m1);
        IspisiMatricu(m1, 5, 2);
        std::cout << "Unesite elemente matrice 2: \n";
        UnesiMatricu('2', m2);
        m3 = ProduktMatrica(m1, m2);
        IspisiMatricu(m3, 3);
        
        std::cout << "Unesite red polinoma: ";
        int d;
        std::cin >> d;
        int vel = d + 1;
        std::vector<double> polinom(vel);
        std::cout << "Unesite koeficijente polinoma: ";
        for(int i = 0; i < polinom.size(); i++)
          std::cin >> polinom[i];
          
        
    }
    catch (std::bad_alloc) {
        std::cout << "Nema dovoljno memorije!\n";
    }
    
    UnistiMatricu(a);
    UnistiMatricu(m1);
    UnistiMatricu(m2);
    UnistiMatricu(m3);
    
	return 0;
}