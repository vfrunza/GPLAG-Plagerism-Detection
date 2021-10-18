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
 void IspisiMatricu(const Matrica<TipElemenata> &mat,
 int sirina_ispisa, int preciznost=6, bool treba_brisati=false) {
 for(int i = 0; i < mat.br_redova; i++) {
 for(int j = 0; j < mat.br_kolona; j++)
 std::cout << std::setw(sirina_ispisa)<<std::cout.precision(preciznost) << mat.elementi[i][j];
 std::cout << std::endl;
 } if(treba_brisati) UnistiMatricu(mat);
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
Matrica<TipElemenata> ProduktMatrica(const Matrica<TipElemenata> &mat1, const Matrica<TipElemenata> &mat2) {
       if(mat1.br_kolona!=mat2.br_redova) throw std::domain_error("Matrice nisu saglasne za mnozenje");
       auto rezultat=StvoriMatricu<TipElemenata>(mat1.br_redova, mat2.br_kolona);
       for(int i=0; i<rezultat.br_kolona; i++) {
        for(int j=0; j<rezultat.br_kolona; j++) rezultat.elementi[i][j]=0;
       }
       for(int i=0; i<mat1.br_redova; i++) {
           for(int j=0; j<mat2.br_kolona; j++) {
               for(int k=0; k<mat2.br_redova; k++) {
                   rezultat.elementi[i][j]+=(mat1.elementi[i][k])*(mat2.elementi[k][j]);
               } 
           }
       }
    return rezultat;
}
template <typename TipElemenata>
Matrica<TipElemenata> PomnoziSkalarom(const Matrica<TipElemenata> &mat, double skalar) {
    Matrica<TipElemenata> vrati=StvoriMatricu<TipElemenata>(mat.br_kolona, mat.br_kolona);
     for(int i=0; i<vrati.br_kolona; i++) {
        for(int j=0; j<vrati.br_kolona; j++) vrati.elementi[i][j]=0;
       }
   for(int i=0; i<mat.br_kolona; i++) {
        for(int j=0; j<mat.br_kolona; j++) {
            vrati.elementi[i][j]=skalar*mat.elementi[i][j];
        }
    } return vrati;
}

template <typename TipElemenata>
Matrica<TipElemenata> MatricniPolinom(const Matrica<TipElemenata> &A, std::vector<double> koeficijenti) {
    if(A.br_redova!=A.br_kolona) throw std::domain_error("Matrica mora biti kvadratna");
   Matrica<TipElemenata> polinom, faktor, sabirak;
   try{
       polinom=(StvoriMatricu<TipElemenata>(A.br_kolona, A.br_kolona));
       try{
           faktor=(StvoriMatricu<TipElemenata>(A.br_kolona, A.br_kolona));
           try{
               sabirak=(StvoriMatricu<TipElemenata>(A.br_kolona, A.br_kolona));
           } catch(...) {
               UnistiMatricu(polinom);
               UnistiMatricu(faktor);
               UnistiMatricu(sabirak);
               throw;
           } 
           }catch(...){
               UnistiMatricu(polinom);
               UnistiMatricu(faktor);
               throw; 
           }
       }catch(...) {
               UnistiMatricu(polinom);
               throw;
   }
   for(int i=0; i<polinom.br_redova; i++) {
       for(int j=0; j<polinom.br_kolona; j++) {if(i==j) {polinom.elementi[i][j]=koeficijenti[0];}
       else polinom.elementi[i][j]=0;
       faktor.elementi[i][j]=A.elementi[i][j];
       sabirak.elementi[i][j]=0;
       } 
   }  
   for(int i=1; i<koeficijenti.size(); i++) {
       if(i==1) {
           sabirak=PomnoziSkalarom(faktor, koeficijenti[i]);
           polinom=ZbirMatrica(polinom, sabirak);
       } 
       else { 
           faktor=ProduktMatrica(faktor, A);
           sabirak=PomnoziSkalarom(faktor, koeficijenti[i]);
           polinom=ProduktMatrica(sabirak, polinom);
       }
   }
    return polinom;
}
int main() {
    int m, mprim;
    Matrica<double> A;
    std::cout<<"Unesite dimenzije kvadratnu matrice: ";
    std::cin>>m;
    mprim=m;
    std::cout<<"Unesite elemente matrice A:\n";
    try {
    A=StvoriMatricu<double>(m, mprim);
    UnesiMatricu('A', A);
    } catch(std::bad_alloc) {
        std::cout<<"Nema dovoljno memorije\n";
        return 0;
    } 
    int n;
    std::cout<<"Unesite red polinoma: ";
    std::cin>>n;
    std::vector<double> koeficijenti(n+1);
    double broj;
    std::cout<<"Unesite koeficijente polinoma: ";
    for(int i=0; i<=n; i++) {
        std::cin>>broj;
        koeficijenti.push_back(broj);
    }
    Matrica<double> rezultat;
    
   rezultat=MatricniPolinom(A, koeficijenti);
   IspisiMatricu(rezultat, 10);

    return 0;
}


