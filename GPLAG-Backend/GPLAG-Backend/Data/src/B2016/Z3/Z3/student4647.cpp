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
        std::cout << ime_matrice<< "(" << i + 1 << "," << j + 1 << ") = ";
        std::cin >> mat.elementi[i][j];
    }
 }
 
template <typename TipElemenata>
void IspisiMatricu(const Matrica<TipElemenata> &mat, int sirina_ispisa, int preciznost=6, bool treba_brisati=false) {
    for(int i = 0; i < mat.br_redova; i++) {
    for(int j = 0; j < mat.br_kolona; j++)
        std::cout << std::setprecision(preciznost)<<std::setw(sirina_ispisa) << mat.elementi[i][j];
        std::cout << std::endl;
    }
    if(treba_brisati==true) UnistiMatricu(mat);
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
    if (m1.br_kolona!=m2.br_redova) throw std::domain_error("Matrice nisu saglasne za mnozenje");
    Matrica<TipElemenata> c=StvoriMatricu<TipElemenata>(m1.br_redova, m2.br_kolona);
    
    for(int i=0; i<m1.br_redova; i++)
        for(int j=0; j<m2.br_kolona; j++) {
            c.elementi[i][j]=0;
            for(int k=0; k<m1.br_kolona; k++)
            c.elementi[i][j]=c.elementi[i][j]+(m1.elementi[i][k]*m2.elementi[k][j]);
        }
        
    return c;
}

template <typename TipElemenata>
Matrica<TipElemenata> StepenMatrica(const Matrica<TipElemenata> &m, int br) {
    Matrica<TipElemenata> i=StvoriMatricu<TipElemenata>(m.br_redova, m.br_kolona);
    
    int n=i.br_kolona;
    for(int k=0; k<n; k++)
        for(int j=0; j<n; j++) {
        if(k==j) i.elementi[k][j]=1;
        else i.elementi[k][j]=m.elementi[k][j]*0;
        }
        for(int k=0; k<br; k++)
        i=ProduktMatrica(i,m);
        
    return i;
}

template <typename TipElemenata>
Matrica<TipElemenata> Proizvod(const Matrica<TipElemenata> &m, double br) {
    Matrica<TipElemenata>  mat {StvoriMatricu<TipElemenata>(m.br_redova, m.br_kolona)} ;
    int n=m.br_redova;
    for(int i=0; i<n; i++)
    for(int j=0; j<n; j++) { mat.elementi[i][j]=m.elementi[i][j]*br; }
    return mat;
}
template <typename TipElemenata>
Matrica<TipElemenata> MatricniPolinom(const Matrica<TipElemenata> &m, std::vector<double> v) {
    Matrica<TipElemenata>  I {StvoriMatricu<TipElemenata>(m.br_redova, m.br_kolona)} ;
    int n=I.br_kolona;
    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++) {
        if(i==j) I.elementi[i][j]=v[0];
        else I.elementi[i][j]=m.elementi[i][j]*0;
        }
    auto proizvod=Proizvod(m, v[1]);
     for(int i = 0; i < proizvod.br_redova; i++)//////////////////////////////////
    for(int j = 0; j < proizvod.br_kolona; j++)///////////////////////////////////
        I.elementi[i][j] = I.elementi[i][j] + proizvod.elementi[i][j];////////////
        
 
    UnistiMatricu(proizvod);
    
    for(int j=2; j<v.size(); j++) {
        auto stepen=StepenMatrica(m,j);
        proizvod=Proizvod(stepen, v[j]);
     
     for(int i = 0; i < proizvod.br_redova; i++)//////////////////////////////////
    for(int j = 0; j < proizvod.br_kolona; j++)///////////////////////////////////
        I.elementi[i][j] = I.elementi[i][j] + proizvod.elementi[i][j];////////////
    UnistiMatricu(stepen);
    UnistiMatricu(proizvod);
    }
    
    return I;
}
int main() {
 Matrica<double> A; // AUTOMATSKA INICIJALIZACIJA!!!
 Matrica<double> B;
 int dim;
 std::cout << "Unesite dimenziju kvadratne matrice: ";
 std::cin >> dim;
 try {
 A = StvoriMatricu<double>(dim, dim);
 std::cout << "Unesite elemente matrice A: \n";
 UnesiMatricu('A', A);
 std::cout<<"Unesite red polinoma: ";
 int red;
 std::cin>>red;
 std::cout<<"Unesite koeficijente polinoma: ";
 std::vector<double> v;
 for(int i=0; i<=red; i++){
    double j;
    std::cin>>j;
    v.push_back(j);
 }
 B=MatricniPolinom(A, v);
 IspisiMatricu(B, 10);
 }
 catch(std::bad_alloc) {
 std::cout << "Nema dovoljno memorije!\n";
 }
 UnistiMatricu(A); UnistiMatricu(B);
 
 return 0;
}