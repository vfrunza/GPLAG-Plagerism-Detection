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

template <typename type>
Matrica<type> ProduktMatrica(Matrica<type> m1, Matrica<type> m2){
    if(m1.br_kolona != m2.br_redova)
        throw std::domain_error("Matrice nisu saglasne za mnozenje");
    
    Matrica<type> m3 = StvoriMatricu(m1.br_redova, m2.br_kolona);
    
    for(int i = 0; i < m1.br_redova; i++)
        for(int j = 0; j < m2.br_kolona; j++)
            for(int k = 0; k < m1.br_kolona; i++)
                m3[i][j] += m1[i][k] * m2[k][j];
    
    return m3;
}

template <typename type, typename iter>
Matrica<type> MatricniPolinom(Matrica<type> a, int n, iter it){
    if(n < 0)
        throw std::domain_error("Neispravan stepen polinoma");
        
    if(a.br_kolona != a.br_redova)
        throw std::domain_error("Matrica mora biti kvadratna");
        
    
    for(int i = 0; i <= n; i++){
        
    }
    
    
}

int main() {
    Matrica<double> a, b, c; // AUTOMATSKA INICIJALIZACIJA!!!
    int m, n;
    std::cout << "Unesi broj redova i kolona za matrice:\n";
    std::cin >> m >> n;
    
    try {
        a = StvoriMatricu<double>(m, n);
        b = StvoriMatricu<double>(m, n);
        std::cout << "Unesi matricu A:\n";
        UnesiMatricu('A', a);
        std::cout << "Unesi matricu B:\n";
        UnesiMatricu('B', b);
        std::cout << "Zbir ove dvije matrice je:\n";
        IspisiMatricu(c = ZbirMatrica(a, b), 7);
    }
    catch(std::bad_alloc) {
        std::cout << "Nema dovoljno memorije!\n";
    }
    
    UnistiMatricu(a); UnistiMatricu(b); UnistiMatricu(c);
    return 0;
}