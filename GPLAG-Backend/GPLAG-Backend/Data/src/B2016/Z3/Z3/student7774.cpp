#include <iostream>
#include <iostream>
#include <iomanip>
#include <stdexcept>
#include <new>
#include <vector>

using std::cout;
using std::cin;
using std::endl;
using std::vector;

template <typename TipElemenata>
    struct Matrica {
        int br_redova, br_kolona;
        TipElemenata **elementi = nullptr;
    };

template <typename TipElemenata>
 void UnistiMatricu(Matrica<TipElemenata> mat) {
     
    if(!mat.elementi) 
        return;
        
    for(int i = 0; i < mat.br_redova; i++) 
        delete[] mat.elementi[i];
        
    delete[] mat.elementi;
    mat.elementi = nullptr;
 }
 
template <typename TipElemenata>
 Matrica<TipElemenata> StvoriMatricu(int br_redova, int br_kolona) {
     
    Matrica<TipElemenata> mat;
     
    mat.br_redova = br_redova; 
    mat.br_kolona = br_kolona;
     
    mat.elementi = new TipElemenata*[br_redova];
     
    for(int i = 0; i < br_redova; i++)
        mat.elementi[i] = nullptr;
        
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
            std::cout << ime_matrice
            << "(" << i + 1 << "," << j + 1 << ") = ";
            std::cin >> mat.elementi[i][j];
        }
    }    
}

template <typename TipElemenata>
 void IspisiMatricu(const Matrica<TipElemenata> &mat, int sirina_ispisa, int preciznost=6, bool treba_li_brisati=false) {
     
    for(int i = 0; i < mat.br_redova; i++) {
        for(int j = 0; j < mat.br_kolona; j++) {
            std::cout << std::setprecision(preciznost) << std::setw(sirina_ispisa) << mat.elementi[i][j];
        }    
        std::cout << std::endl;
    }
    if(treba_li_brisati)
        UnistiMatricu(mat);
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
 Matrica<TipElemenata> SkalarPutaMatrica (const Matrica<TipElemenata> &A, const Matrica<TipElemenata> nul_mat, double broj) {
     
     int n(A.br_kolona);
     Matrica<TipElemenata> B(ZbirMatrica(A,nul_mat));
     for (int i = 0; i < n; i++) {
         for (int j = 0; j < n; j++) {
             B.elementi[i][j] *= broj;
         }
     }
     return B;
 }
 
template <typename TipElemenata> 
 Matrica<TipElemenata> ProduktMatrica (Matrica<TipElemenata> A, Matrica<TipElemenata> B) {
     
    if(A.br_kolona != B.br_redova)
        throw std::logic_error ("Matrice nisu saglasne za mnozenje");
        
    int m(A.br_redova), n(B.br_kolona), k(A.br_kolona);
    Matrica<TipElemenata> C(StvoriMatricu<TipElemenata>(m,n));;
    TipElemenata suma;
    
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            suma = 0;
            for (int l = 0; l < k; l++) {
                suma += A.elementi[i][l] * B.elementi[l][j];
            }
            C.elementi[i][j] = suma;
        }
    }
    return C;    
 }

template <typename TipElemenata>
 Matrica<TipElemenata> MatricniPolinom (Matrica<TipElemenata> A, std::vector<double> v) { 
     
    if(A.br_redova != A.br_kolona)
        throw std::domain_error ("Matrica mora biti kvadratna");
        
    int n(A.br_kolona);
    Matrica<TipElemenata> nul_mat(StvoriMatricu<TipElemenata>(n,n));
    
    if(v.size()==0) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                    nul_mat.elementi[i][j] = 0;
            }
        }
        return nul_mat;
    }
    
   
    Matrica<TipElemenata> C(StvoriMatricu<TipElemenata>(n,n));
    Matrica<TipElemenata> pocetna(StvoriMatricu<TipElemenata>(n,n));
    pocetna = ZbirMatrica<TipElemenata>(nul_mat, A);
    Matrica<TipElemenata> jed_mat(StvoriMatricu<TipElemenata>(n,n));
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if(i==j)
                jed_mat.elementi[i][j] = 1;
            else 
                jed_mat.elementi[i][j] = 0;
        }
    }
    
    for (int i = 0; i < v.size(); i++) {
        if(i==0){
            C = SkalarPutaMatrica<TipElemenata>(jed_mat, nul_mat, v[0]);
            continue;
        }
        C = ZbirMatrica<TipElemenata>(C, SkalarPutaMatrica<TipElemenata>(A, nul_mat, v[i]));
        A = ProduktMatrica<TipElemenata>(A, pocetna);
    }
    UnistiMatricu<TipElemenata>(nul_mat);
    UnistiMatricu<TipElemenata>(jed_mat);
    UnistiMatricu<TipElemenata>(pocetna);
    
    return C;
 }

int main ()
{
    Matrica<double> A;
    
    int n;
    cout << "Unesite dimenziju kvadratne matrice: ";
    cin >> n;
    
    cout << "Unesite elemente matrice A: " << endl;
    A = StvoriMatricu<double>(n, n);
    UnesiMatricu<double>('A', A);
    
    int p;
    cout << "Unesite red polinoma: ";
    cin >> p;
    
    vector<double> v;
    cout << "Unesite koeficijente polinoma: ";
    
    double broj;
    for (int i = 0; i < p+1; i++) {
        cin >> broj;
        v.push_back(broj);
    }
    
    IspisiMatricu(MatricniPolinom(A,v),10);
    UnistiMatricu(A);
    
	return 0;
}