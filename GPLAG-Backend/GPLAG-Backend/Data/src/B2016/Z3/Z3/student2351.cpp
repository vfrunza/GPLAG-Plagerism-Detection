/B2016/2017: Zadaća 3, Zadatak 3
#include <iostream>
#include <iomanip>
#include <stdexcept>
#include <new>
#include <vector>

using std::cin;
using std::cout;
using std::endl;

template <typename TipElemenata>
struct Matrica {
    int br_redova, br_kolona;
    TipElemenata **elementi = nullptr; // VEOMA BITNA INICIJALIZACIJA
};

template <typename TipElemenata>
void UnistiMatricu (Matrica <TipElemenata> mat) {
    if (!mat.elementi) return;
    for (int i=0; i<mat.br_redova; i++) delete [] mat.elementi[i];
    delete[] mat.elementi;
    mat.elementi = nullptr;
}
template <typename TipElemenata>
Matrica <TipElemenata> StvoriMatricu (int br_redova, int br_kolona) {
    Matrica <TipElemenata> mat;
    mat.br_redova = br_redova; mat.br_kolona = br_kolona;
    mat.elementi = new TipElemenata*[br_redova];
    for (int i=0; i<br_redova; i++) mat.elementi[i] = nullptr;
    try {
        for (int i=0; i<br_redova; i++) 
        mat.elementi[i] = new TipElemenata[br_kolona];
    }
    catch (...) {
        UnistiMatricu(mat);
        throw;
    }
    return mat;
}

template <typename TipElemenata>
void UnesiMatricu (char ime_matrice, Matrica<TipElemenata> &mat) {
    for (int i=0; i<mat.br_redova; i++)
    for (int j=0; j<mat.br_kolona; j++) {
        cout << ime_matrice
        << "(" << i+1 << "," << j+1 << ") = ";
        cin >> mat.elementi[i][j];
        }
}

template <typename TipElemenata>
void IspisiMatricu(const Matrica<TipElemenata> &mat,int sirina_ispisa) {
    for (int i=0; i<mat.br_redova; i++) {
        for (int j=0; j<mat.br_kolona; j++)
        cout << std::setw(sirina_ispisa) << mat.elementi[i][j];
        cout << endl;
    }
}

template <typename TipElemenata>
Matrica<TipElemenata> ZbirMatrica (const Matrica<TipElemenata> &m1, const Matrica<TipElemenata> &m2) {
    if (m1.br_redova !=m2.br_redova || m1.br_kolona!=m2.br_kolona) 
    throw std::domain_error ("Matrice nemaju jednake dimenzije!");
    auto m3(StvoriMatricu<TipElemenata> (m1.br_redova, m1.br_kolona));
    for (int i=0; i<m1.br_redova; i++)
    for (int j=0; j<m1.br_kolona; i++)
    m3.elementi [i][j] = m1.elementi[i][j] + m2.elementi[i][j];
    return m3;
}

template <typename TipElemenata>
Matrica<TipElemenata> ProduktMatrica (const Matrica<TipElemenata> &m1, const Matrica<TipElemenata> &m2) {
    if (m1.br_kolona!=m2.br_redova) throw std::domain_error ("Matrice nisu saglasne za mnozenje");
    auto m3 (StvoriMatricu<TipElemenata>(m1.br_kolona, m2.br_redova));
    for (int i=0; i<m1.br_redova; i++) {
        for (int j=0; j<m2.br_kolona; j++) {
            for (int k=0; k<m1.br_kolona; k++) {
                m3[i][j]+=m1[i][k]*m2[k][j];
            }
        }
    }
    return m3;
}

template <typename TipElemenata>
Matrica<TipElemenata> MatricniPolinom (const Matrica<TipElemenata> &mat1,  std::vector<double> v) {
    if (mat1.br_redova!=mat1.br_kolona) throw std::domain_error ("Matrica mora biti kvadratna");
    auto A (StvoriMatricu<TipElemenata>(mat1.br_redova, mat1.br_kolona));
    auto pomocna(StvoriMatricu<TipElemenata>(mat1.br_redova,mat1.br_kolona));
    auto polinom(StvoriMatricu<TipElemenata>(mat1.br_redova,mat1.br_kolona));
    for (int i=0; i<mat1.br_redova; i++) 
        for (int j=0; j<mat1.br_kolona; j++) A.elementi[i][j]=0;
           
            pomocna = A;
            
            
            for (int i=0; i<v.size(); i++) {
                for (int j=0; j<v.size(); j++) {
                    polinom+=v[j] * (ProduktMatrica(A,pomocna));
                    A = ProduktMatrica(A,pomocna);
                    
                }
            }
    
    return polinom;
}

int main ()
{
    Matrica <double> a;
    int m,n,koeficijenti;
    cout << "Unesite dimenziju kvadratne matrice: ";
    cin >> m;
    //try {
        a = StvoriMatricu<double>(m,m);
        cout << "Unesite elemente matrice A: \n";
        UnesiMatricu('A', a);
        cout << "Unesite red polinoma: ";
        cin >> n;
        cout << "Unesite koeficijente polinoma:";
        cin >> koeficijenti;
        std::vector<double> v;
        IspisiMatricu(MatricniPolinom<double> (a,v),3);
      
        UnistiMatricu (a); 
        //UnistiMatricu (b); 
        return 0;
}