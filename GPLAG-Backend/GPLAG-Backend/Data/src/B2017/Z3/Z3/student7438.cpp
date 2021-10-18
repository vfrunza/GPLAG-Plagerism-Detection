/B2017/2018: Zadaća 3, Zadatak 3
#include <iostream>
#include <cmath>
#include <iomanip>
#include <new>
#include <stdexcept>
#include <vector>

int preciznost(6);
int treba_brisati(false);
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
 void IspisiMatricu(const Matrica<TipElemenata> &mat, int sirina_ispisa, int preciznost, bool treba_brisati) {
 for(int i = 0; i < mat.br_redova; i++) {
 for(int j = 0; j < mat.br_kolona; j++)
 std::cout << std::setw(sirina_ispisa) << std::setprecision(preciznost) <<mat.elementi[i][j];
 std::cout << std::endl;
 if(treba_brisati) UnistiMatricu(mat);
 }
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
     auto m3(StvoriMatricu<TipElemenata>(m1.br_redova, m2.br_kolona));
     for(int i(0); i<m1.br_redova;i++)
     for(int j(0);j<m2.br_kolona;j++)
      for(int k(0);k<m2.br_redova;k++)
         m3.elementi[i][j]+=m1.elementi[i][k]*m2.elementi[k][j];
     return m3;
 }
 
 template <typename TipElementa, typename Kontejner>
 Matrica <TipElementa> MatricniPolinom(const Matrica<TipElementa> &A, int n, Kontejner &p) {
  auto m(StvoriMatricu<TipElementa>(A.br_redova,A.br_kolona));
  auto B(StvoriMatricu<TipElementa>(A.br_redova,A.br_kolona));
  for(int i(0);i<A.br_redova;i++)
  for(int j(0);j<A.br_kolona;j++){
   if(i==j) m.elementi[i][j]=(*p);
   else m.elementi[i][j]=0;
 }
 for(int i(0);i<A.br_redova;i++)
  for(int j(0);j<A.br_kolona;j++){
  if(i==j) B.elementi[i][j]=1;
  else B.elementi[i][j]=0;}
 for(int k(1);k<=n;k++){
  B=ProduktMatrica(B,A);
  p+=1;
 for(int i(0);i<A.br_redova;i++)
  for(int j(0);j<A.br_kolona;j++)
   m.elementi[i][j]+=(*p)*B.elementi[i][j];
}
 return m;
 }
int main ()
{
 Matrica<double> a, b;
 int m, n;
 int niz[5]{0};
 int *p(niz);
 std::cout << "Unesite dimenziju kvadratne matrice: ";
 std::cin >> m ;
 try {
 a = StvoriMatricu<double>(m, m);
 b = StvoriMatricu<double>(m, m);
 std::cout << "Unesite elemente matrice A:\n";
 UnesiMatricu('A', a);
 std::cout<<"Unesite red polinoma: ";
 std::cin>>n;
 std::cout<<"Unesite koeficijente polinoma: ";
 for(int i(0);i<=n;i++)
 std::cin>>niz[i];
 IspisiMatricu(b=MatricniPolinom(a,n,p),10,preciznost,treba_brisati);
 }
 catch(std::bad_alloc) {
 std::cout << "Nema dovoljno memorije!\n";
 }
 UnistiMatricu(a);
	return 0;
}
