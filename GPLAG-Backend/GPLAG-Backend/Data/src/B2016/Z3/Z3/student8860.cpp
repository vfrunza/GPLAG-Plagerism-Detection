/B2016/2017: Zadaća 3, Zadatak 3
#include <iostream>
#include <iomanip>
#include <stdexcept>
#include <new>
#include <vector>
using namespace std;
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
 void IspisiMatricu(const Matrica<TipElemenata> &mat,
 int sirina_ispisa, int preciznost=6 , bool treba_brisati=false) {
 for(int i = 0; i < mat.br_redova; i++) {
 for(int j = 0; j < mat.br_kolona; j++)
 std::cout << std::setw(sirina_ispisa)<<std::setprecision(preciznost)<< mat.elementi[i][j];
 std::cout << std::endl;
 }
 if(treba_brisati){ for(int i = 0; i < mat.br_redova; i++) delete[] mat.elementi[i];
 delete[] mat.elementi;
}
 }
 template <typename TipElemenata>
 Matrica<TipElemenata> ProduktMatrica(const Matrica<TipElemenata> &m1,
 const Matrica<TipElemenata> &m2){
      if(m1.br_kolona != m2.br_redova)
 throw std::domain_error("Matrice nisu saglasne za mnozenje!");
      auto m3(StvoriMatricu<TipElemenata>(m1.br_redova, m2.br_kolona));
      for(int i = 0; i < m1.br_redova; i++){
 for(int j = 0; j < m2.br_kolona; j++){
 m3.elementi[i][j] = 0;
 for(int k=0;k<m1.br_kolona;k++){ m3.elementi[i][j]= m3.elementi[i][j]+m1.elementi[i][k]*m2.elementi[k][j];}}}
 return m3;
 }
 template <typename TipElemenata>
Matrica<TipElemenata> MatricniPolinom(const Matrica<TipElemenata> &m1,vector<double> koeficijenti){
 if(m1.br_redova!=m1.br_kolona) throw std::domain_error("Matrica mora biti kvadratna");
     auto mat(StvoriMatricu<TipElemenata>(m1.br_redova, m1.br_kolona));
     for(int i = 0; i < m1.br_redova; i++)
 for(int j = 0; j < m1.br_kolona; j++){
     mat.elementi[i][j]=0;
 }
 if(koeficijenti.size()==0) return mat;
          for(int i = 0; i < m1.br_redova; i++)
 for(int j = 0; j < m1.br_kolona; j++){
     if(i==j) mat.elementi[i][j]=koeficijenti[0]; else mat.elementi[i][j]=0;
 }
 if(koeficijenti.size()==1) return mat;
 for(int i = 0; i < m1.br_redova; i++)
 for(int j = 0; j < m1.br_kolona; j++){
     if(i==j) mat.elementi[i][j]=koeficijenti[0]+koeficijenti[1]*m1.elementi[i][j]; else mat.elementi[i][j]=koeficijenti[1]*m1.elementi[i][j];
 }
 if(koeficijenti.size()==2) return mat;
 auto pomocna(StvoriMatricu<TipElemenata>(m1.br_redova, m1.br_kolona));
  for(int p=0;p<m1.br_redova;p++){
               for(int q=0;q<m1.br_redova;q++){
                pomocna.elementi[p][q]=m1.elementi[p][q];
               }
              }
 for(int k=2;k<koeficijenti.size();k++){
    auto mat1=ProduktMatrica(pomocna,m1);
              for(int i = 0; i < m1.br_redova; i++){
 for(int j = 0; j < m1.br_kolona; j++){
  mat.elementi[i][j]=mat.elementi[i][j]+koeficijenti[k]*mat1.elementi[i][j];
  
 }
              }
              for(int p=0;p<m1.br_redova;p++){
               for(int q=0;q<m1.br_redova;q++){
                pomocna.elementi[p][q]=mat1.elementi[p][q];
               }
              }
              UnistiMatricu(mat1);
 }
 UnistiMatricu(pomocna);
 return mat;
}
int main() {
 Matrica<double> a, b;
 int n;
 std::cout << "Unesite dimenziju kvadratne matrice: ";
 std::cin >> n;
 try {
 a = StvoriMatricu<double>(n, n);
 std::cout << "Unesite elemente matrice A: \n";
 UnesiMatricu('A', a);
cout<<"Unesite red polinoma: ";
int red;
cin>>red;
cout<<"Unesite koeficijente polinoma: ";
vector<double> koeficijenti;
for(int i=0;i<red+1;i++){
    double broj;
    cin>>broj;
    koeficijenti.push_back(broj);
}
try{
auto b = MatricniPolinom(a,koeficijenti);
 IspisiMatricu(b, 10,6,true);}
 catch(std::domain_error izuzetak){
   UnistiMatricu(a);
  cout<<izuzetak.what();
 }
 UnistiMatricu(a);
 UnistiMatricu(b);
 }
 catch(std::bad_alloc) {
 std::cout << "Nema dovoljno memorije!\n";
 }
 return 0;
}