#include <iostream>
#include <iomanip>
#include <stdexcept>
#include <new>
#include <vector>
using std::vector;
template <typename TipElemenata>
 struct Matrica {
 int br_redova, br_kolona;
 TipElemenata **elementi=nullptr ;// VEOMA BITNA INICIJALIZACIJA!
 };
 
template <typename TipElemenata>
 Matrica<TipElemenata> StvoriMatricu(int br_redova, int br_kolona) {
 Matrica<TipElemenata> mat;
 mat.br_redova = br_redova; mat.br_kolona = br_kolona;
 mat.elementi = new TipElemenata*[br_redova];
 for(int i = 0; i < br_redova; i++) mat.elementi[i] = nullptr;
 try {
 for(int i = 0; i < br_redova; i++){
 mat.elementi[i] = new TipElemenata[br_kolona];
 }
 }
 catch(...) {
 UnistiMatricu(mat);
 throw;
 }
 return mat;
 }

template<typename TipElemenata>
void Nuliraj(Matrica<TipElemenata> &Mat){
 for(int i=0;i<Mat.br_redova;i++){
  for(int j=0;j<Mat.br_kolona;j++){
   Mat.elementi[i][j]=0;
  }
 }
}
template<typename TipElemenata>
Matrica<TipElemenata> ProduktMatrica(const Matrica<TipElemenata> &mat1,const Matrica<TipElemenata> &mat2){
    if(mat1.br_kolona != mat2.br_redova) throw std::domain_error("Matrice nisu saglasne za mnozenje");
    Matrica<TipElemenata> mat;
    mat=StvoriMatricu<TipElemenata>(mat1.br_redova,mat2.br_kolona);
    for(int i=0;i<mat.br_redova;i++){
     for(int j=0;j<mat.br_kolona;j++){
      mat.elementi[i][j]=0;
     }
    }
    for(int i=0;i<mat.br_redova;i++){
     for(int j=0;j<mat.br_kolona;j++){
      int suma(0);
      for(int k=0;k<mat1.br_kolona;k++){
       suma+=mat1.elementi[i][k]*mat2.elementi[k][j];
      }
      mat.elementi[i][j]=suma;
     }
    }
    return mat;
} 
template<typename TipElemenata>
void PomonoziSkalarom(Matrica<TipElemenata> &mat,double x){
 for(int i=0;i<mat.br_redova;i++){
  for(int j=0;j<mat.br_kolona;j++){
   mat.elementi[i][j]*=x;
  }
 }
}
template<typename TipElemenata>
void Prepisi(Matrica<TipElemenata> &mat,const Matrica<TipElemenata> &Pomocna){
 for(int i=0;i<mat.br_redova;i++){
  for(int j=0;j<mat.br_kolona;j++){
   mat.elementi[i][j]=Pomocna.elementi[i][j];
  }
 }
}
template<typename TipElemenata>
Matrica<TipElemenata> MatricniPolinom(const Matrica<TipElemenata> &A,vector<double> v){
  Matrica<TipElemenata> mat;
  if(A.br_kolona!=A.br_redova) throw("Matrica mora biti kvadratna");
  int m(A.br_redova),n(A.br_kolona);
  mat=StvoriMatricu<TipElemenata>(m,n);
    Nuliraj(mat);

  if(v.size()==0){
   return mat;
  }
  Matrica<TipElemenata> Pomocna1;
  Pomocna1=StvoriMatricu<TipElemenata>(m,n);
  Prepisi<TipElemenata>(Pomocna1,A);
  Matrica<TipElemenata> Pomocna3;
  Pomocna3=StvoriMatricu<TipElemenata>(m,n);
  Prepisi<TipElemenata>(Pomocna3,A);
  for(int i=0;i<mat.br_redova;i++){
   for(int j=0;j<mat.br_kolona;j++){
    if(i==j) mat.elementi[i][j]=v[0];
   }
  }
    Matrica<TipElemenata> Pomocna;
 for(int i=1;i<v.size();i++){
  if(i==1){
   PomonoziSkalarom(Pomocna1,v[i]);
   Pomocna=ZbirMatrica(mat,Pomocna1);
   Prepisi<TipElemenata>(mat,Pomocna);
   UnistiMatricu(Pomocna);
   UnistiMatricu(Pomocna1);
   continue;
  }
  
   Matrica<TipElemenata> Pomocna2;
   Pomocna2=ProduktMatrica(Pomocna3,A);
   Prepisi<TipElemenata>(Pomocna3,Pomocna2);
   PomonoziSkalarom(Pomocna2,v[i]);
   Pomocna=ZbirMatrica(mat,Pomocna2);
   Prepisi<TipElemenata>(mat,Pomocna);
   UnistiMatricu(Pomocna);
   UnistiMatricu(Pomocna2);
  
  
 }

  UnistiMatricu(Pomocna3);
 return mat;
}



template <typename TipElemenata>
 void UnistiMatricu(Matrica<TipElemenata> mat) {
 if(!mat.elementi) return;
 for(int i = 0; i < mat.br_redova; i++) delete[] mat.elementi[i];
 delete[] mat.elementi;
 mat.elementi = nullptr;
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
 int sirina_ispisa,int preciznost=6,bool treba_brisati=false) {
 for(int i = 0; i < mat.br_redova; i++) {
 for(int j = 0; j < mat.br_kolona; j++)
 std::cout << std::setw(sirina_ispisa) << std::setprecision(preciznost)<<mat.elementi[i][j];
 std::cout << std::endl;
 }
 if(treba_brisati) UnistiMatricu(mat);
 }
 template <typename TipElemenata>
 Matrica<TipElemenata> ZbirMatrica(const Matrica<TipElemenata> &m1,
 const Matrica<TipElemenata> &m2) {
 if(m1.br_redova != m2.br_redova || m1.br_kolona != m2.br_kolona)
 throw std::domain_error("Matrice nemaju jednake dimenzije!");
 auto m3(StvoriMatricu<TipElemenata>(m1.br_redova, m1.br_kolona));
 Nuliraj(m3);
 for(int i = 0; i < m1.br_redova; i++)
 for(int j = 0; j < m1.br_kolona; j++)
 m3.elementi[i][j] = m1.elementi[i][j] + m2.elementi[i][j];
 return m3;
 }

int main() {
 Matrica<double> a,b; // AUTOMATSKA INICIJALIZACIJA!!!
 int m;
 std::cout << "Unesite dimenziju kvadratne matrice: ";
 std::cin >>m;
 try {
 a = StvoriMatricu<double>(m, m);
 std::cout << "Unesite elemente matrice A:\n";
 UnesiMatricu('A', a);
 std::cout<<"Unesite red polinoma: ";
 int n;
 std::cin>>n;
 n++;
 vector<double> v(n);
 std::cout<<"Unesite koeficijente polinoma: ";
 for(int i=0;i<n;i++){
  std::cin>>v[i];
 }
 b=MatricniPolinom<double>(a,v);
 IspisiMatricu(b,10);
 }catch(std::bad_alloc) {
 std::cout << "Nema dovoljno memorije!\n";
 }
 UnistiMatricu(a); UnistiMatricu(b);
 return 0;
}
