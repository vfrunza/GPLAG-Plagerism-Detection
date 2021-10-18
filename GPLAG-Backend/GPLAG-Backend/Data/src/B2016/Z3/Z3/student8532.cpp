/B2016/2017: Zadaća 3, Zadatak 3
#include <stdexcept>
#include <iostream>
#include <iomanip>
#include <vector>
#include <new>

template <typename TipElemenata>
    struct Matrica {
        int br_redova, br_kolona;
        TipElemenata **elementi = nullptr;
    };
    
template <typename TipElemenata>
    void UnistiMatricu (Matrica<TipElemenata> mat) {
        if (!mat.elementi)  return;
        for (int i = 0; i < mat.br_redova; ++i)     delete[] mat.elementi[i];
        delete[] mat.elementi;
        mat.elementi = nullptr;
    }
    
template <typename TipElemenata>
    Matrica<TipElemenata> StvoriMatricu (int br_redova, int br_kolona) {
        Matrica<TipElemenata> mat;
        mat.br_redova = br_redova;  mat.br_kolona = br_kolona;
        mat.elementi = new TipElemenata*[br_redova];
        for (int i=0; i<br_redova; ++i) mat.elementi[i] = nullptr;
        try {
            for (int i=0; i<br_redova; ++i)
                mat.elementi[i] = new TipElemenata[br_kolona];
        }
        catch (...) {
            UnistiMatricu(mat); throw;
        }   return mat;
    }
    
template <typename TipElemenata>
    void UnesiMatricu (char ime_matrice, Matrica<TipElemenata> &mat) {
        for (int i=0; i< mat.br_redova; ++i)
            for (int j=0; j < mat.br_kolona; ++j) {
                std::cout << ime_matrice << "(" << i+1 << "," << j+1 << ") = ";
                std::cin >> mat.elementi[i][j];
            }
    }

template <typename TipElemenata>
    void IspisiMatricu (const Matrica <TipElemenata> &mat, int sirina_ispisa) {
        for (int i=0; i< mat.br_redova; ++i)
            for (int j=0; j<mat.br_kolona; ++j) {
                std::cout << std::setw(sirina_ispisa) << mat.elementi[i][j];
            std::cout << std::endl;
            }
    }

template <typename TipElementa>
    Matrica <TipElementa> ZbirMatrica (const Matrica <TipElementa> &m1, const Matrica<TipElementa> &m2) {
        if (m1.br_redova != m2.br_redova or m1.br_kolona != m2.br_kolona)
            throw std::domain_error ("Matrice nemaju jednake dimenzije!");
        auto m3(StvoriMatricu<TipElementa> (m1.br_redova, m1.br_kolona));
        for (int i=0; i< m1.br_redova; ++i) 
            for (int j=0; j<m1.br_kolona; ++j)
                m3.elementi[i][j] = m1.elementi[i][j] + m2.elementi[i][j];
        return m3;
    }
    
template <typename Tip>
    Matrica <Tip> ProduktMatrica (const Matrica <Tip> &mat1, const Matrica <Tip> &mat2)
    {
        if (not(mat1.br_kolona == mat2.br_redova))  throw std::domain_error ("Matrice nisu saglasne za mnozenje");
        
        Matrica<Tip> Produkt_Output {StvoriMatricu(mat1.br_redova, mat2.br_kolona)};
        
    }

int main ()
{
    int dimenzija;
    Matrica<double> Matricica;
    std::cout << "Unesite dimenziju kvadratne matrice: ";
    std::cin >> dimenzija;  std::cin.ignore(10000, '\n');
    try {
        Matricica = StvoriMatricu<double>(dimenzija, dimenzija);
        std::cout << "Unesite elemente matrice A: " << std::endl; UnesiMatricu('A', Matricica);
    }   catch (std::bad_alloc) {
        std::cout << "Nema dovoljno memorije!" << std::endl;
    }
    
    int broj_polinoma;
    std::vector<double> polinom;
    std::cout << "Unesite red polinoma: ";
    std::cin >> broj_polinoma;  std::cin.ignore (10000, '\n');
    std::cout << "Unesite koeficijente polinoma: ";
    for (int i=0; i<broj_polinoma; ++i) {
        double polinomcic;  std::cin >> polinomcic;
        polinom.push_back(polinomcic);
    }   return 0;
}