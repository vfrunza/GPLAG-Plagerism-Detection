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

double Stepen(double baza, int stepen) {
    double proizvod(1);
    for(int i = 0; i < abs(stepen); i++) proizvod *= baza;
    if(stepen < 0) { proizvod = 1. / proizvod; return proizvod; }
    return proizvod;
}

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
    mat.br_redova = br_redova;
    mat.br_kolona = br_kolona;
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
void IspisiMatricu(const Matrica<TipElemenata> &mat, int sirina_ispisa, int preciznost = 6, int treba_brisati = false) {
    for(int i = 0; i < mat.br_redova; i++) {
        for(int j = 0; j < mat.br_kolona; j++)
            std::cout << std::setw(sirina_ispisa) << std::setprecision(preciznost) << mat.elementi[i][j];
        std::cout << std::endl;
    }
    if(treba_brisati) { UnistiMatricu(mat); }
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
    if(m1.br_kolona != m2.br_redova) 
        throw std::domain_error("Matrice nisu saglasne za mnozenje");
    auto m3(StvoriMatricu<TipElemenata>(m1.br_redova, m2.br_kolona));
    for(int i(0);i<m3.br_redova; i++)
        for(int j(0);j<m3.br_kolona; j++) m3.elementi[i][j] = 0;
        
    for(int i = 0; i < m1.br_redova; i++) {
        for(int j = 0; j < m2.br_kolona; j++) {
            for(int k = 0; k < m1.br_kolona; k++) {
                m3.elementi[i][j] += m1.elementi[i][k] * m2.elementi[k][j];
            }
        }
    }
    return m3;
}

template <typename TipElemenata>
Matrica<TipElemenata> MatricniPolinom(const Matrica<TipElemenata> &a, std::vector<double> koeficijenti) {
    if(a.br_redova != a.br_kolona)
        throw std::domain_error("Matrica mora biti kvadratna");
    
    auto Jedinicna(StvoriMatricu<TipElemenata>(a.br_redova, a.br_kolona));
    for(int i = 0; i < a.br_redova; i++) {
        for(int j = 0; j < a.br_kolona; j++) {
            if(i == j) Jedinicna.elementi[i][j] = 1;
            else Jedinicna.elementi[i][j] = 0;
        }
    }
    
    auto m3(StvoriMatricu<TipElemenata>(a.br_redova, a.br_kolona));
    for(int i = 0; i < a.br_redova; i++) {
        for(int j = 0; j < a.br_kolona; j++) m3.elementi[i][j] = 0;
    }
    
    for(int k = 0; k < koeficijenti.size(); k++) {
        if(k == 0) {
            for(int i = 0; i < a.br_redova; i++) {
                for(int j = 0; j < a.br_kolona; j++) m3.elementi[i][j] += Jedinicna.elementi[i][j] * koeficijenti[k];
            }
        }
        
        else {
            auto matrica(StvoriMatricu<TipElemenata>(a.br_redova, a.br_kolona));
            for(int i = 0; i < a.br_redova; i++) {
                for(int j = 0; j < a.br_kolona; j++) matrica.elementi[i][j] = a.elementi[i][j];
            }
            
            for(int i = 1; i < k; i++) {
                auto PomocnaZaBrisanje(matrica);
                matrica = ProduktMatrica(matrica, a);
                UnistiMatricu(PomocnaZaBrisanje);
            }
            
            for(int i = 0; i < a.br_redova; i++) {
                for(int j = 0; j < a.br_kolona; j++) m3.elementi[i][j] += matrica.elementi[i][j] * koeficijenti[k];
            }
            
            UnistiMatricu(matrica);
        }
    }
    
    UnistiMatricu(Jedinicna);
    return m3;
}

int main() {
    Matrica<double> a, b;
    std::cout << "Unesite dimenziju kvadratne matrice: ";
    int n;
    std::cin >> n;
    try {
        a = StvoriMatricu<double>(n, n);
        std::cout << "Unesite elemente matrice A: \n";
        UnesiMatricu('A', a);
        std::cout << "Unesite red polinoma: ";
        std::cin >> n;
        std::vector<double> kofi;
        std::cout << "Unesite koeficijente polinoma: ";
        for(int i = 0; i <= n; i++) {
            double k;
            std::cin >> k;
            kofi.push_back(k);
        }
        IspisiMatricu(b = MatricniPolinom(a, kofi), 10);
    }
    catch(std::bad_alloc) {
        std::cout << "Nema dovoljno memorije!\n";
    }
    UnistiMatricu(a);
    UnistiMatricu(b);
    
    return 0;
}