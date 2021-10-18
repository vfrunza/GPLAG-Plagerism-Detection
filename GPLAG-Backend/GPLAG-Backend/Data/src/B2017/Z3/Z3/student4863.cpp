/B2017/2018: Zadaća 3, Zadatak 3
#include <iostream>
#include <iomanip>
#include <stdexcept>
#include <new>
#include <exception>
#include <vector>
#include <cmath>

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
 void IspisiMatricu(const Matrica<TipElemenata> &mat, int sirina_ispisa=10, int preciznost=6, bool treba_brisati=false) {
 for(int i = 0; i < mat.br_redova; i++) {
 for(int j = 0; j < mat.br_kolona; j++)
 std::cout << std::setw(sirina_ispisa)<<std::setprecision(preciznost) << mat.elementi[i][j];
 std::cout << std::endl;
 }
 if(treba_brisati==true) UnistiMatricu(mat);
 }
template <typename TipElemenata>
 Matrica<TipElemenata> ZbirMatrica(const Matrica<TipElemenata> &m1,
 const Matrica<TipElemenata> &m2) {
  Matrica<TipElemenata> m3;
  try{
 if(m1.br_redova != m2.br_redova || m1.br_kolona != m2.br_kolona)
 throw std::domain_error("Matrice nemaju jednake dimenzije!");
 m3=(StvoriMatricu<TipElemenata>(m1.br_redova, m1.br_kolona));
 for(int i = 0; i < m1.br_redova; i++)
 for(int j = 0; j < m1.br_kolona; j++)
 m3.elementi[i][j] = m1.elementi[i][j] + m2.elementi[i][j];
  }catch(...){
   UnistiMatricu(m1); UnistiMatricu(m2); UnistiMatricu(m3);
   throw;
  }
 return m3;
 }
 
 template<typename tip1>
 Matrica<tip1> ProduktMatrica(Matrica<tip1> m1, Matrica<tip1> m2){
  Matrica<tip1> m3;
     try{
         if(m1.br_kolona!=m2.br_redova) throw std::domain_error("Matrice nisu saglasne za mnozenje");
     m3=StvoriMatricu<tip1>(m1.br_redova, m2.br_kolona);
     for(int i=0; i<m1.br_redova; i++){
         for(int j=0; j<m2.br_kolona; j++){
             tip1 suma{};
             for(int k=0; k<m2.br_redova; k++) suma+=m1.elementi[i][k]*m2.elementi[k][j]; //memorijska greska
             m3.elementi[i][j] = suma;
         }
         }
     } catch(std::domain_error e){
         std::cout<<e.what();
         UnistiMatricu(m2); UnistiMatricu(m1); UnistiMatricu(m3);
         throw;
     }
return m3;
 }
 
 template<typename makaron>
 void NapraviJedinicnu(const Matrica<makaron> &A, Matrica<makaron> &B){
  //Matrica<double> B;
  try{
  //B=StvoriMatricu<double>(A.br_redova, A.br_kolona);
  for(int i=0; i<A.br_redova; i++){
   for(int j=0; j<A.br_kolona; j++){
    if(i==j) B.elementi[i][j]=1;
    else B.elementi[i][j]=0;
   }
  }
  }catch(...){
   //UnistiMatricu(A); UnistiMatricu(B);
   throw;
  }
  //return B;
 }
 
 template<typename sadceramazan>
 Matrica<sadceramazan> Hehe(Matrica<sadceramazan> A, typename std::vector<sadceramazan>::iterator it){
  Matrica<sadceramazan> B;
  try{
  B=StvoriMatricu<sadceramazan>(A.br_redova, A.br_kolona);
  for(int i=0; i<A.br_redova; i++){
   for(int j=0; j<A.br_kolona; j++){
    B.elementi[i][j]=(*it)*A.elementi[i][j];
   }
  }
  }catch(...){
   UnistiMatricu(A); UnistiMatricu(B);
   throw;
  }
  return B;
 }
 
template<typename era>
void PrekopirajElemente(const Matrica<era> &A, Matrica<era> &B){
 for(int i=0; i<A.br_redova; i++){
  for(int j=0; j<A.br_kolona; j++){
   B.elementi[i][j]=A.elementi[i][j];
  }
 }
}
 
 template <typename ovojenekitip>
 Matrica<ovojenekitip> MatricniPolinom(Matrica<ovojenekitip> A, int n, typename std::vector<ovojenekitip>::iterator it){
  
     Matrica<ovojenekitip>suma;
   Matrica<ovojenekitip>jedinicna;
   Matrica<ovojenekitip>pomocna;
   Matrica<ovojenekitip>druga;
   //try{
   suma=(StvoriMatricu<ovojenekitip>(A.br_redova, A.br_kolona));
   jedinicna=(StvoriMatricu<ovojenekitip>(A.br_redova, A.br_kolona));
   pomocna=(StvoriMatricu<ovojenekitip>(A.br_redova, A.br_kolona));
   druga=StvoriMatricu<ovojenekitip>(A.br_redova,A.br_kolona);
   //auto druga_za_brisati=druga;
   PrekopirajElemente(A, druga); // ERMIN: UMJESTO druga=A treba PrekopirajElemente(druga, A);
   //UnistiMatricu(druga_za_brisati);
   if(A.br_redova!=A.br_kolona) throw std::domain_error("Matrica mora biti kvadratna");
   if(n<0) throw std::domain_error("Neispravan stepen polinoma");
   //auto jedinicna_za_brisati=jedinicna;
   NapraviJedinicnu(jedinicna, jedinicna);
   //UnistiMatricu(jedinicna_za_brisati);
   auto suma_za_brisati=suma;
   suma=Hehe(jedinicna,it); it++;
   //UnistiMatricu(suma_za_brisati);
   for(int i=0; i<n; i++){ //Mora ici od nule jer tek tad daje dobar rezultat!
              auto pomocna_za_brisati=pomocna;
              auto suma_za_brisati2=suma;
              pomocna=Hehe(druga, it); if(i!=(n-1)) it++; //Problem jer mi petlja mora ici od nule, zato kad uđe u zadnji krug nek se ne uvecava i nece doci do pristupa neinicijalizovanoj vr
              suma=ZbirMatrica(suma, pomocna);
              UnistiMatricu(pomocna_za_brisati); //NOVOO
              UnistiMatricu(suma_za_brisati2); //NOVOOO
              auto druga_za_brisati=druga;
              druga=ProduktMatrica(druga,A);
              UnistiMatricu(druga_za_brisati); //NOVO
   }
   UnistiMatricu(suma_za_brisati);
   
  /*}catch(std::exception &e){
   //std::cout << e.what() << std::endl;
   UnistiMatricu(jedinicna); UnistiMatricu(pomocna); UnistiMatricu(druga); UnistiMatricu(suma); UnistiMatricu(A); UnistiMatricu(suma);
   throw;
  }*/
  UnistiMatricu(jedinicna); UnistiMatricu(pomocna); UnistiMatricu(druga);
    return suma;
 }

int main() {
 Matrica<double> a, b, c; // AUTOMATSKA INICIJALIZACIJA!!!
 int m, d;
 std::cout << "Unesite dimenziju kvadratne matrice: ";
 std::cin >> m;
 try {
 a = StvoriMatricu<double>(m, m);
 //b = StvoriMatricu<double>(m, n);
 std::cout << "Unesite elemente matrice A:\n";
 UnesiMatricu('A', a);
 std::cout << "Unesite red polinoma: ";
 std::cin >> d;
 std::vector<double> v;
 std::cout << "Unesite koeficijente polinoma: ";
 for(int i=0; i<(d+1); i++){
  double clan;
  std::cin >> clan;
  v.push_back(clan);
 }
 //std::cout << "Unesi matricu B:\n";
 //UnesiMatricu('B', b);
 //std::cout << "Zbir ove dvije matrice je:\n";
 //IspisiMatricu(c = ZbirMatrica(a, b), 7);
 std::vector<double>::iterator it(v.begin());
 c=MatricniPolinom(a, d, it);
 IspisiMatricu(c);
 }
 catch(std::bad_alloc) {
 std::cout << "Nema dovoljno memorije!\n";
 UnistiMatricu(a); UnistiMatricu(c);
 }
 UnistiMatricu(a); UnistiMatricu(c);
 return 0;
}