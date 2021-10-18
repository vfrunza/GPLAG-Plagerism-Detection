#include <iostream>
#include <iomanip>
#include <stdexcept>
#include <new>

template <typename TipElemenata>
struct Matrica {
    int br_redova, br_kolona;
    TipElemenata **elementi = nullptr;
};
template <typename TipElemenata>
void UnistiMatricu(Matrica<TipElemenata> mat)
{
    if(!mat.elementi) return;
    for(int i = 0; i < mat.br_redova; i++) {
        delete [] mat.elementi[i];
    }
    delete[] mat.elementi;
    mat.elementi = nullptr;
}
template<typename TipElemenata>
Matrica<TipElemenata> StvoriMatricu(int br_redova, int br_kolona)
{
    Matrica<TipElemenata> mat;

    mat.br_redova = br_redova;
    mat.br_kolona = br_kolona;
    mat.elementi = new TipElemenata*[br_redova];

    for(int i = 0; i < br_redova; i++) mat.elementi[i] = nullptr;

    try {
        for(int i = 0; i < br_redova; i++) mat.elementi[i] = new TipElemenata[br_kolona];
    } catch(...) {
        UnistiMatricu(mat);
        throw;
    }
    return mat;
}
template<typename TipElemenata>
void UnesiMatricu(char ime_matrice, Matrica<TipElemenata> mat)
{
    for(int i = 0; i < mat.br_redova; i++) {
        for(int j = 0; j < mat.br_kolona; j++) {
            std::cout << ime_matrice << " (" << i+1 << "," << j+1 << ") = ";
            std::cin >> mat.elementi[i][j];
        }
    }
}
template<typename TipElemenata>
void IspisiMatricu (const Matrica<TipElemenata> &mat, int sirina_ispisa, int preciznost = 6, bool treba_brisati = false)
{
    for(int i = 0; i < mat.br_redova; i++) {
        for(int j = 0; j < mat.br_kolona; j++) {
            std::cout << std::setprecision(preciznost) << std::setw(sirina_ispisa) << mat.elementi[i][j];
        }
        std::cout << std::endl;
    }
    if(treba_brisati == true) {
        for(int i = 0; i < mat.br_redova; i++) delete [] mat.elementi[i];
        delete []mat.elementi;
        mat.elementi = nullptr;
    }
}
template<typename TipElemenata>
Matrica<TipElemenata> ZbirMatrica (const Matrica<TipElemenata> &m1, const Matrica<TipElemenata> &m2)
{
    if(m1.br_kolona != m2.br_redova) throw std::domain_error("Matrice nemaju jednake dimenzije!");

    auto m3(StvoriMatricu<TipElemenata>(m1.br_redova, m1.br_kolona));

    for(int i = 0; i < m1.br_redova; i++) {
        for(int j = 0; j < m1.br_kolona; j++) {
            m3.elementi[i][j] = m1.elementi[i][j] + m2.elementi[i][j];
        }
    }
    return m3;
}
template<typename TipElemenata>
Matrica<TipElemenata> ProduktMatrica (const Matrica<TipElemenata> &m1, const Matrica<TipElemenata> &m2)
{
    if(m1.br_redova != m2.br_kolona || m1.br_kolona != m2.br_redova) throw std::domain_error("Matrice nisu saglasne za mnozenje");

    auto m3(StvoriMatricu<TipElemenata>(m1.br_redova,m2.br_kolona));

    for(int i = 0; i < m1.br_redova; i++) {
        for(int j = 0; j < m2.br_kolona; j++) {
            double suma(0);
            for(int k = 0; k < m2.br_redova; k++) {
                suma+= m1.elementi[i][k]*m2.elementi[k][j];
            }
            m3.elementi[i][j] = suma;
        }
    }
    return m3;
}
template<typename TipElemenata>
Matrica<TipElemenata> PomnoziSaSkalarom (Matrica<TipElemenata> &mat, double skalar)
{
    for(int i = 0; i < mat.br_redova; i++) {
        for(int j = 0; j < mat.br_kolona; j++) {
            mat.elementi[i][j]*=skalar;
        }
    }
    return mat;
}
template<typename TipElemenata>
Matrica<TipElemenata> MatricniPolinom (Matrica<TipElemenata> mat, int n, double *it)
{
    if(mat.br_redova != mat.br_kolona) throw std::domain_error("Matrica mora biti kvadratna");
    if(n < 0) throw std::domain_error("Neispravan stepen polinoma");

    auto matrica(StvoriMatricu<TipElemenata>(mat.br_redova,mat.br_kolona));

    auto jedinicna(StvoriMatricu<TipElemenata>(mat.br_redova,mat.br_kolona));
    for(int i = 0; i < jedinicna.br_redova; i++) {
        for(int j = 0; j < jedinicna.br_kolona; j++) {
            if(i == j) jedinicna.elementi[i][j] == 1;
            else jedinicna.elementi[i][j] == 0;
        }
    }
   
   
}
int main ()
{
    int m;
    std::cout << "Unesite dimenziju kvadratne matrice: ";
    std::cin >> m;

    Matrica<double> a;
    try {
        a  = StvoriMatricu<double>(m,m);
        std::cout << "Unesite elemente matrice A:\n";
        UnesiMatricu('A',a);
    } catch(std::bad_alloc) {
        std::cout << "Nema dovoljno memorije!\n";
    }

    UnistiMatricu(a);
    return 0;
}
