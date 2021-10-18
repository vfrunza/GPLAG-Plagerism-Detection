/B2017/2018: Zadaća 3, Zadatak 3
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
 std::cout << ime_matrice << "(" << i + 1 << "," << j + 1 << ") = ";
 std::cin >> mat.elementi[i][j];
 }
 }
template <typename TipElemenata>
 void IspisiMatricu(const Matrica<TipElemenata> &mat, int sirina_ispisa, int preciznost=6, bool treba_brisati=false) {
 for(int i = 0; i < mat.br_redova; i++) {
 for(int j = 0; j < mat.br_kolona; j++)
 std::cout << std::setw(sirina_ispisa) << std::setprecision(preciznost)<< mat.elementi[i][j];
 std::cout << std::endl;
 }
 if(treba_brisati) UnistiMatricu(mat);
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
Matrica<TipElemenata> ProduktMatrica(Matrica<TipElemenata> mat1, Matrica<TipElemenata> mat2){
 if(mat1.br_kolona!=mat2.br_redova) throw std::domain_error("Matrice nisu saglasne za mnozenje");
 Matrica<TipElemenata> mat;
 try{
  mat=StvoriMatricu<TipElemenata>(mat1.br_redova, mat2.br_kolona);
  for(int i=0; i<mat1.br_redova; i++)
  for(int j=0; j<mat2.br_kolona; j++)
  mat.elementi[i][j]=0;
 for(int i=0; i<mat1.br_redova; i++)
  for(int j=0; j<mat2.br_kolona; j++){
   for(int k=0; k<mat1.br_kolona; k++){
   mat.elementi[i][j]+=mat1.elementi[i][k]*mat2.elementi[k][j];}}
 }
   catch(...){
    UnistiMatricu(mat);
    throw;
   }
   return mat;
}

template<typename TipElemenata>
void Kopiraj(Matrica<TipElemenata>mat, Matrica<TipElemenata> mat3){
 for(int i=0; i<mat.br_redova; i++)
  for(int j=0; j<mat.br_kolona; j++)
   mat.elementi[i][j]=mat3.elementi[i][j];
}

template<typename TipElemenata, typename IterTip>
Matrica<TipElemenata>MatricniPolinom(Matrica<TipElemenata>mat, int n, IterTip it){
 if(n<0) throw std::domain_error("Neispravan stepen polinoma");
 Matrica<TipElemenata> mat1, mat2, mat3, m;
 try{
 mat1=StvoriMatricu<TipElemenata>(mat.br_redova, mat.br_kolona); mat2=StvoriMatricu<TipElemenata>(mat.br_redova, mat.br_kolona);
  m=StvoriMatricu<TipElemenata>(mat.br_redova, mat.br_kolona);
  int x(0);
   for(int i=0; i<mat1.br_redova; i++)//kopija originalne matrice
    for(int j=0; j<mat1.br_kolona; j++){
     if(abs(mat.elementi[i][j])<0.0001) x++;
    m.elementi[i][j]=mat.elementi[i][j];
    mat2.elementi[i][j]=0;}
 int p(n+1);
 while(p!=0){
   if(p==n+1&&x!=mat.br_kolona*mat.br_redova){
   for(int i=0; i<mat1.br_redova; i++)
    for(int j=0; j<mat1.br_kolona; j++){
     if(i==j) mat1.elementi[i][j]=1;
     else mat1.elementi[i][j]=0;
    }
    for(int i=0; i<mat2.br_redova; i++)
     for(int j=0; j<mat2.br_kolona; j++)
     mat2.elementi[i][j]=(*it)*mat1.elementi[i][j];
     it++;
     p--;
  }                                           
  else{
   for(int i=0; i<mat2.br_redova; i++)
   for(int j=0; j<mat2.br_kolona; j++)
   mat2.elementi[i][j]+=(*it)*mat.elementi[i][j];
   it++;
   p--;
   mat3=ProduktMatrica(mat, m);
   Kopiraj(mat, mat3);
   UnistiMatricu(mat3);
  }
 }}
 catch(...){
  UnistiMatricu(mat1);
  UnistiMatricu(mat2);
  UnistiMatricu(m);
  throw;
 }
 UnistiMatricu(mat1);
 UnistiMatricu(m);
 return mat2;
}

int main() {
 Matrica<double> a, A; // AUTOMATSKA INICIJALIZACIJA!!!
 int m;
 std::cout << "Unesite dimenziju kvadratne matrice: ";
 std::cin>>m;
 try {
 a = StvoriMatricu<double>(m, m);
 std::cout << "Unesite elemente matrice A:\n";
 UnesiMatricu('A', a);
 std::cout<<"Unesite red polinoma: ";
 int p;
 std::cin>>p;
 int n(p+1);
 std::vector<int> v;
 std::cout<<"Unesite koeficijente polinoma: ";
  while(n!=0){
    int k;
    std::cin>>k;
    v.push_back(k);
    n--;
  }
  auto it=v.begin();
  A=MatricniPolinom(a, p, it);
  IspisiMatricu(A, 10, 6, false);
 }
 catch(std::bad_alloc) {
 std::cout << "Nema dovoljno memorije!\n";
 }
 catch(std::domain_error izuzetak){
  std::cout<<izuzetak.what();
 }
 UnistiMatricu(a);
 UnistiMatricu(A);
 return 0;
}