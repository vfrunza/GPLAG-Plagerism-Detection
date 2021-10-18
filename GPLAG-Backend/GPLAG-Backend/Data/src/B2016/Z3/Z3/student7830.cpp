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
 void IspisiMatricu(const Matrica<TipElemenata> &mat, int sirina_ispisa, int preciznost = 6, bool treba_brisati = false) {
 for(int i = 0; i < mat.br_redova; i++) 
 {
    for(int j = 0; j < mat.br_kolona; j++)     
        std::cout << std::setw(sirina_ispisa) << std::setprecision(preciznost) << mat.elementi[i][j];   
    std::cout << std::endl;
 }
 if(treba_brisati)
    UnistiMatricu(mat);
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

template <typename TipElemenata>
Matrica<TipElemenata> ProduktMatrica(const Matrica<TipElemenata> &m1, const Matrica<TipElemenata> &m2)
{
    if(m1.br_kolona != m2.br_redova)
        throw std::domain_error("Matrice nisu saglasne za mnozenje");
    auto m3(StvoriMatricu<TipElemenata>(m1.br_redova, m2.br_kolona));
    for(int i = 0; i < m1.br_redova; i++)
        for(int j = 0; j < m2.br_kolona; j++)
                for(int k = 0; k < m1.br_kolona; k++)
                        m3.elementi[i][j] += m1.elementi[i][k]*m2.elementi[k][j];
    return m3;
}

template<typename TipElemenata, typename TipElemenata2>
Matrica<TipElemenata> MatricniPolinom(const Matrica<TipElemenata> &mat, std::vector<TipElemenata2> vek)
{
    if(mat.br_redova != mat.br_kolona)
        throw std::domain_error ("Matrica mora biti kvadratna");
    if(vek.size() == 0)
    {
        auto mat2(StvoriMatricu<TipElemenata>(mat.br_redova, mat.br_kolona));
        for(int i = 0; i < mat2.br_redova; i++)
            for(int j = 0; j < mat2.br_kolona; j++)
                mat2.elementi[i][j] = 0;
        return  mat2;
    }
    Matrica<TipElemenata> polinom(StvoriMatricu<TipElemenata>(mat.br_redova, mat.br_kolona));
    Matrica<TipElemenata> matk(StvoriMatricu<TipElemenata>(mat.br_redova, mat.br_kolona));
    for(int i = 0; i < polinom.br_redova; i++)
        for(int j = 0; j < polinom.br_kolona; j++)
            polinom.elementi[i][j] = 0;
    for(int i = 0; i < vek.size(); i++)
    {
        if(i == 0)
            for(int k = 0; k < matk.br_redova; k++)
                for(int j = 0; j < matk.br_kolona; j++)
                    if(k == j)
                        matk.elementi[k][j] = 1;
                    else
                        matk.elementi[k][j] = 0;
        else
                matk = ProduktMatrica(matk, mat);
        if(vek[i] == 0)
            continue;
        for(int k = 0; k < matk.br_redova; k++)
            for(int j = 0; j < matk.br_kolona; j++)
                matk.elementi[k][j] *= vek[i];
        for(int k = 0; k < polinom.br_redova; k++)
            for(int j = 0; j < polinom.br_kolona; j++)
                polinom.elementi[k][j] += matk.elementi[k][j];
        for(int k = 0; k < matk.br_redova; k++)
            for(int j = 0; j < matk.br_kolona; j++)
                matk.elementi[k][j] /= vek[i];
    }
    UnistiMatricu(matk);
    return polinom;
}

int main() {
 Matrica<double> a, b, c; 
 int m;
 std::cout << "Unesite dimenziju kvadratne matrice: \n";
 std::cin >> m;
 try {
 a = StvoriMatricu<double>(m, m);
 std::cout << "Unesite elemente matrice A: \n";
 UnesiMatricu('A', a);
 std::cout<< "Unesite red polinoma: ";
 int red;
 std::cin>>red;
 std::cout<<"Unesite koeficijente polinoma: ";
 std::vector<int> vek(red+1);
 for(int i = 0; i < vek.size(); i++)
    std::cin>>vek[i];
 IspisiMatricu(c = MatricniPolinom(a, vek), 10, 6);
 UnistiMatricu(a); UnistiMatricu(b); UnistiMatricu(c);
 }
 catch(std::bad_alloc) {
 std::cout << "Nema dovoljno memorije!\n";
 }
 return 0;
}
