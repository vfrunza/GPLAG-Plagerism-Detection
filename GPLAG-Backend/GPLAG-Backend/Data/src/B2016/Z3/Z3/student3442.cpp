/B2016/2017: Zadaća 3, Zadatak 3
#include <iostream>
#include <iomanip>
#include <stdexcept>
#include <vector>
#include <new>

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
    mat.elementi = new TipElemenata* [br_redova];
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
    for(int i = 0; i < mat.br_redova; i++) {
        for(int j = 0; j < mat.br_kolona; j++) {
            std::cout << ime_matrice << "(" << i + 1 << "," << j + 1 << ") = " ;
            std::cin >> mat.elementi[i][j];
        }
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
    if(treba_brisati) {
        UnistiMatricu(mat);
    }
}

template <typename TipElemenata>
Matrica<TipElemenata> ZbirMatrica(const Matrica<TipElemenata> &m1, const Matrica<TipElemenata> &m2) {
    if(m1.br_redova != m2.br_redova || m1.br_kolona != m2.br_kolona) 
        throw std::domain_error("Matrice nemaju jednake dimenzije!");
    auto m3(StvoriMatricu<TipElemenata>(m1.br_kolona, m1.br_kolona));
    for(int i = 0; i < m1.br_redova; i++) {
        for(int j = 0; j < m1.br_kolona; j++) {
            m3.elementi[i][j] = m1.elementi[i][j] + m2.elementi[i][j];
        }
    }
    return m3;
}

// ===================================================================================================================================================== 

template<typename TipElemenata>
void StvoriJedinicnuMatricu(Matrica<TipElemenata> &m) {
    for(int i = 0; i < m.br_redova; i++) {
        for(int j = 0; j < m.br_kolona; j++) {
            if(i == j) m.elementi[i][j] = 1;
            else m.elementi[i][j] = 0;
        }
    }
}

template<typename TipElemenata>
void Kopiraj(Matrica<TipElemenata> &m1, Matrica<TipElemenata> &m2) {
    for(int i = 0; i < m1.br_redova; i++) {
        for(int j = 0; j < m1.br_kolona; j++) {
            m2.elementi[i][j] = m1.elementi[i][j];
        }
    }
}

template <typename TipElemenata>
void Sumiraj(Matrica<TipElemenata> &m1, Matrica<TipElemenata> &m2) {
    for(int i = 0; i < m1.br_redova; i++) {
        for(int j = 0; j < m1.br_kolona; j++) {
            m1.elementi[i][j] += m2.elementi[i][j];
        }
    }

}

template<typename TipElemenata, typename TipSkalar>
void PomnoziSaSkalarom(Matrica<TipElemenata> &m, TipSkalar broj) {
    for(int i = 0; i < m.br_redova; i++) {
        for(int j = 0; j < m.br_kolona; j++) {
            m.elementi[i][j] *= broj;
        }
    }
}

template<typename TipElemenata>
void AnulirajMatricu(Matrica<TipElemenata> &m) {
    for(int i = 0; i < m.br_redova; i++) {
        for(int j = 0; j < m.br_kolona; j++) {
            m.elementi[i][j] = 0;
        }
    }
}

// ===================================================================================================================================================== 

template<typename TipElemenata>
Matrica<TipElemenata> ProduktMatrica(const Matrica<TipElemenata> &m1, const Matrica<TipElemenata> &m2) {
    if(m1.br_kolona != m2.br_redova) 
        throw std::domain_error("Matrice nisu saglasne za mnozenje");
        
    auto m3 = StvoriMatricu<TipElemenata>(m1.br_redova, m2.br_kolona);
    
    for(int i = 0; i < m1.br_redova; i++) {
        for(int j = 0; j < m2.br_kolona; j++) {
            m3.elementi[i][j] = 0;
            for(int k = 0; k < m1.br_kolona; k++) {
                m3.elementi[i][j] += m1.elementi[i][k] * m2.elementi[k][j];
            }
        }
    }
   return m3;
}

template<typename TipElemenata, typename TipVector>
Matrica<TipElemenata> MatricniPolinom(Matrica<TipElemenata> m, const std::vector<TipVector> &v) {
    if(m.br_redova != m.br_kolona)
        throw std::domain_error("Matrice nisu saglasne za mnozenje");
    
    auto temp = StvoriMatricu<TipElemenata>(m.br_redova, m.br_kolona);
    
    if(v.size() == 0) {
        AnulirajMatricu<TipElemenata>(temp);
        return temp;
    }
    
    auto rezultat = StvoriMatricu<TipElemenata>(m.br_redova, m.br_kolona);
    StvoriJedinicnuMatricu(rezultat);
    PomnoziSaSkalarom(rezultat, v[0]);
    
    auto pomnozena_skalarom = StvoriMatricu<TipElemenata>(m.br_redova, m.br_kolona);
    for(int i = 1; i < v.size(); i++) {
        Kopiraj(m, temp);
        for(int j = 1; j < i; j++) {
            auto prime = ProduktMatrica(temp, m);
            Kopiraj(prime, temp);
            UnistiMatricu(prime);
        }
        Kopiraj(temp, pomnozena_skalarom); 
        PomnoziSaSkalarom(pomnozena_skalarom, v[i]);
        Sumiraj(rezultat, pomnozena_skalarom);
    }
    UnistiMatricu(temp); UnistiMatricu(pomnozena_skalarom);
    return rezultat;
}

int main() {
    Matrica<double> A, matpol;
    int n;
    std::cout << "Unesite dimenziju kvadratne matrice: ";
    std::cin >> n;
    try {
        A = StvoriMatricu<double> (n, n);
        std::cout << "Unesite elemente matrice A:\n";
        UnesiMatricu('A', A);
        
        std::cout << "Unesite red polinoma: ";
        int red_polinoma;
        std::cin >> red_polinoma;
        std::cout << "Unesite koeficijente polinoma: ";
        
        std::vector<double> v(red_polinoma+1);
        for(double &x : v) {
            std::cin >> x;
        }
        matpol = MatricniPolinom<double>(A, v);
        IspisiMatricu(matpol, 10);
    }
    catch(std::bad_alloc) {
        std::cout << "Nema dovoljno memorije!\n";
    }
    UnistiMatricu(A); UnistiMatricu(matpol);
    return 0;
}