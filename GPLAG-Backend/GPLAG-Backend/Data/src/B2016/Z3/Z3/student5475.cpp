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
void UnistiMatricu (Matrica<TipElemenata> mat) {
    if(!mat.elementi) return;
    for(int i=0; i<mat.br_redova; i++) delete[] mat.elementi[i];
    delete[] mat.elementi;
    mat.elementi = nullptr;
}
template <typename TipElemenata>
Matrica<TipElemenata> StvoriMatricu(int br_redova, int br_kolona) {
    Matrica<TipElemenata> mat;
    mat.br_redova = br_redova; mat.br_kolona = br_kolona;
    mat.elementi = new TipElemenata*[br_redova];
    for(int i=0; i<br_redova; i++) mat.elementi[i] = nullptr;
    try {
        for(int i=0; i<br_redova; i++)
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
    for(int i=0; i<mat.br_redova; i++)
        for(int j=0; j<mat.br_kolona; j++) {
            std::cout << ime_matrice << "(" << i+1 << "," << j+1 << ") = ";
            std::cin >> mat.elementi[i][j];
        }
}
template <typename TipElemenata>
void IspisiMatricu(const Matrica<TipElemenata> &mat, int sirina_ispisa, int preciznost = 6, bool treba_brisati = false) {
    for(int i=0; i<mat.br_redova; i++) {
        for(int j=0; j<mat.br_kolona; j++)
            std::cout << std::setw(sirina_ispisa) << std::setprecision(preciznost) << mat.elementi[i][j];
        std::cout << std::endl;
    }
    if(treba_brisati) UnistiMatricu(mat);
}
template <typename TipElemenata>
Matrica<TipElemenata> ZbirMatrica(const Matrica<TipElemenata> &m1, const Matrica<TipElemenata> &m2) {
    if(m1.br_redova != m2.br_redova || m1.br_kolona != m2.br_kolona) 
        throw std::domain_error("Matrice nemaju jednake dimenzije!");
    auto m3(StvoriMatricu<TipElemenata>(m1.br_redova, m1.br_kolona));
    for(int i=0; i<m1.br_redova; i++)
        for(int j=0; j<m1.br_kolona; j++)
            m3.elementi[i][j] = m1.elementi[i][j] + m2.elementi[i][j];
    return m3;
}
//Moje funkcije
template <typename TipElemenata>
void Nuliraj(Matrica<TipElemenata> &mat) {
    for(int i=0; i<mat.br_redova; i++)
        for(int j=0; j<mat.br_kolona; j++) 
            mat.elementi[i][j] = 0;
}
template <typename TipElemenata>
Matrica<TipElemenata> NapraviKopiju(const Matrica<TipElemenata> &m1) {
    auto m2(StvoriMatricu<TipElemenata>(m1.br_redova, m1.br_kolona));
    for(int i=0; i<m2.br_redova; i++)
        for(int j=0; j<m2.br_kolona; j++)
            m2.elementi[i][j] = m1.elementi[i][j];
    return m2;
}
template <typename TipElemenata>
Matrica<TipElemenata> ProduktMatrica(const Matrica<TipElemenata> &m1, const Matrica<TipElemenata> &m2) {
    if(m1.br_kolona != m2.br_redova) 
        throw std::domain_error("Matrice nisu saglasne za mnozenje");
    auto m3(StvoriMatricu<TipElemenata>(m1.br_redova, m2.br_kolona));
    Nuliraj<TipElemenata>(m3);
    for(int i=0; i<m1.br_redova; i++) 
        for(int j=0; j<m2.br_kolona; j++)
            for(int k=0; k<m2.br_redova; k++)
                m3.elementi[i][j] += m1.elementi[i][k] * m2.elementi[k][j];
    return m3;
}
template <typename TipElemenata>
Matrica<TipElemenata> StepenMatrice(const Matrica<TipElemenata> &m1, int step) {
    Matrica<TipElemenata> m2, temp;
    try {
        m2 = NapraviKopiju<TipElemenata>(m1);
        if(step == 0) {
            Nuliraj<TipElemenata>(m2);
            for(int i=0; i<m2.br_redova; i++)
                m2.elementi[i][i] = 1;
        }
        else
            for(int i=1; i<step; i++) {
                temp = ProduktMatrica<TipElemenata>(m2, m1);
                UnistiMatricu(m2); m2 = NapraviKopiju<TipElemenata>(temp);
                UnistiMatricu(temp);
            }
        return m2;
    }
    catch(...) {
        UnistiMatricu(m2); UnistiMatricu(temp);
        throw;
    }
}
template <typename TipElemenata>
Matrica<TipElemenata> SkalarniProdukt(const Matrica<TipElemenata> &m1, double n) {
    auto m2(NapraviKopiju<TipElemenata>(m1));
    for(int i=0; i<m2.br_redova; i++)
        for(int j=0; j<m2.br_kolona; j++)
            m2.elementi[i][j] *= n;
    return m2;
}
template <typename TipElemenata>
Matrica<TipElemenata> MatricniPolinom(const Matrica<TipElemenata> &A, std::vector<double> v) {
    if(A.br_redova != A.br_kolona) throw std::domain_error("Matrica mora biti kvadratna");
    Matrica<TipElemenata> mat, p1, p2, temp;
    try {
        mat = StvoriMatricu<TipElemenata>(A.br_redova, A.br_kolona);
        Nuliraj<TipElemenata>(mat);
        if(v.size() == 0) return mat;
        for(int i=0; i<v.size(); i++) {
            p1 = StepenMatrice<TipElemenata>(A, i); p2 = SkalarniProdukt<TipElemenata>(p1, v[i]);
            temp = ZbirMatrica<TipElemenata>(mat, p2);
            UnistiMatricu(mat); mat = NapraviKopiju<TipElemenata>(temp);
            UnistiMatricu(p1); UnistiMatricu(p2); UnistiMatricu(temp);
        }
    }
    catch(...) {
        UnistiMatricu(p1); UnistiMatricu(p2); UnistiMatricu(temp); UnistiMatricu(mat);
        throw;
    }
    return mat;
}

int main ()
{
    int vel, n;
    Matrica<double> A;
    std::cout << "Unesite dimenziju kvadratne matrice: ";
    try {
        std::cin >> vel;
        A = StvoriMatricu<double>(vel, vel);
        std::cout << "Unesite elemente matrice A: " << std::endl;
        UnesiMatricu('A', A);
        std::cout << "Unesite red polinoma: ";
        std::cin >> n;
        std::vector<double> v(n+1);
        std::cout << "Unesite koeficijente polinoma: ";
        for(int i=0; i<v.size(); i++) std::cin >> v[i];
        IspisiMatricu(MatricniPolinom<double>(A, v), 10, 6, true);
    }
    catch(std::domain_error e) {
        std::cout << e.what();
        throw;
    } 
    catch(...) {
    }
    UnistiMatricu(A);
    return 0;
}