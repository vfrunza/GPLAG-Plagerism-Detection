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
 for(int i = 0; i < mat.br_redova; i++)
 delete[] mat.elementi[i];
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
 void IspisiMatricu(const Matrica<TipElemenata> &mat, int sirina_ispisa,int preciznost=6, bool treba_brisati=false) {
 for(int i = 0; i < mat.br_redova; i++) {
 for(int j = 0; j < mat.br_kolona; j++)
 std::cout << std::setw(sirina_ispisa) <<std::setprecision(preciznost)<< mat.elementi[i][j];
 std::cout << std::endl;
 }
 if(treba_brisati==true){
  UnistiMatricu(mat);
 }
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
Matrica<TipElemenata> ProduktMatrica(const Matrica<TipElemenata> &m1, const Matrica<TipElemenata> &m2){
 if(m1.br_kolona!=m2.br_redova) throw std::domain_error("Matrice nisu saglasne za mnozenje");
 try{
 auto m3(StvoriMatricu<double>(m1.br_redova,m2.br_kolona));
 for(int i=0; i<m1.br_redova; i++){
  for(int j=0; j<m2.br_kolona; j++){
   m3.elementi[i][j]=0;
  }
 }
  for(int i=0; i<m1.br_redova; i++){
   for(int j=0; j<m2.br_kolona; j++){
    for(int k=0; k<m1.br_kolona; k++){
     m3.elementi[i][j]+=m1.elementi[i][k]*m2.elementi[k][j];
    }
   }
  }
  return m3;
 } catch(std::domain_error e){
  std::cout<<e.what()<<std::endl;
 }
 return m1;
}

template <typename TipElemenata>
Matrica<TipElemenata> MatricniPolinom(const Matrica<TipElemenata> &A, std::vector<double> pk){
 if(A.br_redova!=A.br_kolona) throw std::domain_error("Matrica mora biti kvadratna");
  try{
  if(pk.size()==0){
  auto mat(StvoriMatricu<double>(A.br_redova, A.br_kolona));
  mat=A;
  for(int i=0; i<A.br_redova; i++){
   for(int j=0; j<A.br_redova; j++){
    mat.elementi[i][j]=0;
   }
  }
  return mat;
 }
   auto pom(StvoriMatricu<double>(A.br_redova, A.br_kolona));
   auto Pn(StvoriMatricu<double>(A.br_redova, A.br_kolona));
   for(int i=0; i<A.br_redova; i++){
    for(int j=0; j<A.br_kolona; j++){
     Pn.elementi[i][j]=0;
   }
  }
  for(int i=0; i<A.br_redova; i++){
    for(int j=0; j<A.br_kolona; j++){
     if(i==j)
     pom.elementi[i][j]=1;
     else
     pom.elementi[i][j]=0;
   }
  }
  for(int k=0; k<pk.size(); k++){
   for(int i=0; i<A.br_redova; i++){
    for(int j=0; j<A.br_kolona; j++){
     Pn.elementi[i][j]+=pk[k]*pom.elementi[i][j];
    }
   } pom=ProduktMatrica(A,pom);
  }
  return Pn;
  } catch(std::domain_error e){
   std::cout<<e.what()<<std::endl;
  }
  return A;
 }

int main() {
 Matrica<double> a, c;
 int m, n;
 std::cout << "Unesite dimenziju kvadratne matrice: ";
 std::cin >> m;
 try {
 a = StvoriMatricu<double>(m, m);
 std::cout << "Unesite elemente matrice A:\n";
 UnesiMatricu('A', a);
 std::vector<double> v;
 std::cout << "Unesite red polinoma: ";
 std::cin >> n;
 v.resize(n+1);
 std::cout<<"Unesite koeficijente polinoma: ";
 for(int i=0; i<v.size(); i++){
  std::cin>>v[i];
 }
 IspisiMatricu(c=MatricniPolinom(a, v),10);
 }
 catch(std::bad_alloc) {
 std::cout << "Nema dovoljno memorije!\n";
 UnistiMatricu(a); UnistiMatricu(c);
 }
 
 
 return 0;
}
