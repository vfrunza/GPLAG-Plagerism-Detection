/B2016/2017: Zadaća 3, Zadatak 3
#include <iostream>
#include <iomanip>
#include <stdexcept>
#include <new>
#include<vector>
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
 template<typename TipElemenata>
bool SaglasnaZaMnozenje(Matrica<TipElemenata> m1, Matrica<TipElemenata>m2){
 return (m1.br_kolona==m2.br_redova);
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
 void IspisiMatricu(const Matrica<TipElemenata> &mat, int sirina_ispisa, int preciznost=6, bool treba_brisati=false) {
 for(int i = 0; i < mat.br_redova; i++) {
 for(int j = 0; j < mat.br_kolona; j++)
 std::cout << std::setw(sirina_ispisa) << std::setprecision(preciznost)<<mat.elementi[i][j];
 std::cout << std::endl;
 
 }
 if(treba_brisati) UnistiMatricu(mat);
 }
template<typename TipElemenata>
Matrica<TipElemenata> ProduktMatrica(const Matrica<TipElemenata> m1, const Matrica<TipElemenata> m2){
 if(!SaglasnaZaMnozenje<TipElemenata>(m1,m2)) throw std::domain_error("Matrice nisu saglasne za mnozenje");
 auto m3(StvoriMatricu<TipElemenata>(m1.br_redova, m2.br_kolona));
 for(int i=0; i<m1.br_redova; i++)
  for(int j=0; j<m2.br_kolona; j++){
   TipElemenata suma{};
   for(int k=0; k<m1.br_kolona; k++)
    suma+=m1.elementi[i][k]*m2.elementi[k][j];
   m3.elementi[i][j]=suma;
  }
 return m3;
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
 
 template<typename TipElemenata>
 Matrica<TipElemenata> MatricniPolinom(Matrica<TipElemenata>m, std::vector<double>p){
  if(m.br_kolona!=m.br_redova) throw std::domain_error("Matrica mora biti kvadratna");
  if(p.size()==0){ auto m1=StvoriMatricu<TipElemenata>(m.br_kolona, m.br_kolona);
  for(int i=0; i<m1.br_redova; i++)
   for(int j=0; j<m1.br_kolona; j++)
    m1.elementi[i][j]=0;
  return m1;
 }
 int n=m.br_kolona;
 Matrica<TipElemenata>m1,E,c,d;
 m1=(StvoriMatricu<TipElemenata>(n,n));
 E=(StvoriMatricu<TipElemenata>(n,n));
 for(int i=0; i<n; i++) 
  for(int j=0; j<n; j++)
   if(i==j) E.elementi[i][j]=1;
   else E.elementi[i][j]=0;
   
   
 for(int i=0; i<p.size(); i++){
     if(i==0){
        for(int j=0; j<n; j++)
           for(int k=0; k<n; k++)
               m1.elementi[j][k]=E.elementi[j][k]*p[i];
        UnistiMatricu(E);
     }
     else if(i==1){
         for(int j=0; j<n; j++)
              for(int k=0; k<n; k++)
                  m1.elementi[j][k]=m1.elementi[j][k]+(m.elementi[j][k]*p[i]);
     }
     else{
          for(int j=0; j<i-1; j++){
              if(j==0) c=ProduktMatrica(m,m);
              else{
                  d=c;
                  c=ProduktMatrica(c,m);
                  UnistiMatricu(d);
              }
          }
          for(int k=0; k<n; k++)
              for(int l=0; l<n; l++)
                  m1.elementi[k][l]=m1.elementi[k][l]+(c.elementi[k][l]*p[i]);
          UnistiMatricu(c);
       }
   }
  
 
 return m1;
 }
 
int main() {
 Matrica<double> a, b, c; // AUTOMATSKA INICIJALIZACIJA!!!
 int m,n;
 std::cout << "Unesite dimenziju kvadratne matrice: ";
 std::cin >> n;
 try {
 a = StvoriMatricu<double>(n, n);
 std::cout << "Unesite elemente matrice A:\n";
 UnesiMatricu('A', a);
 std::cout << "Unesite red polinoma: ";
 std::cin>>m;
 std::vector<double>p(m+1);
 std::cout<<"Unesite koeficijente polinoma: ";
 for(int i=0; i<m+1; i++)
  std::cin>>p[i];
 IspisiMatricu(c = MatricniPolinom(a, p), 10,6);
 }
 catch(std::bad_alloc) {
 std::cout << "Nema dovoljno memorije!\n";
 }
 catch(std::domain_error izuzetak){
  std::cout<<izuzetak.what()<<std::endl;
 }
 UnistiMatricu(a); UnistiMatricu(c);
 return 0;
}
