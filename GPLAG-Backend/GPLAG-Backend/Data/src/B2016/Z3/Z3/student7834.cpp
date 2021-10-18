/B2016/2017: Zadaća 3, Zadatak 3
#include <iostream>
#include <iomanip>
#include <stdexcept>
#include <new>
#include <vector>
#include <cmath>

using std::cout;
using std::cin;
using std::endl;
using std::vector;
using std::pow;

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
 void IspisiMatricu(const Matrica<TipElemenata> &mat,int sirina_ispisa, int preciznost=6, bool treba_brisati=false ) {
  
  
 for(int i = 0; i < mat.br_redova; i++) {
 for(int j = 0; j < mat.br_kolona; j++)
 std::cout <<std::setprecision(preciznost) << std::setw(sirina_ispisa) << mat.elementi[i][j];
 std::cout << std::endl;
 }
 if(treba_brisati==true) UnistiMatricu(mat);
 }
template <typename TipElemenata>
 Matrica<TipElemenata> ZbirMatrica(const Matrica<TipElemenata> &m1,
 const Matrica<TipElemenata> &m2) {
 if(m1.br_redova != m2.br_redova || m1.br_kolona != m2.br_kolona)
 throw std::domain_error("Matrice nemaju jednake dimenzije!");
 auto m3(StvoriMatricu<TipElemenata>(m1.br_redova, m1.br_kolona));
 for(int i = 0; i < m1.br_redova; i++)
 for(int j = 0; j < m2.br_kolona; j++)
 m3.elementi[i][j] = m1.elementi[i][j] + m2.elementi[i][j];
 return m3;
 }

template <typename TipElemenata>
 Matrica<TipElemenata> ProduktMatrica( Matrica<TipElemenata> &m1, Matrica<TipElemenata> &m2) {
  if(m1.br_kolona!=m2.br_redova ) throw std::domain_error("Matrice nisu saglasne za mnozenje");
  Matrica<TipElemenata> m3;
  m3=StvoriMatricu<TipElemenata>(m1.br_redova, m2.br_kolona);
  for(int i = 0; i < m1.br_redova; i++) {
   for(int j = 0; j < m2.br_kolona; j++) {
    TipElemenata suma{};
    for(int s=0; s<m2.br_redova; s++) suma+=m1.elementi[i][s]*m2.elementi[s][j];
    m3.elementi[i][j] =suma;
    
   }
  }
  

  
  return m3;
 }

template <typename TipElemenata>
 Matrica<TipElemenata> MatricniPolinom(Matrica<TipElemenata> &m, vector<double> v) {
  if(m.br_kolona!=m.br_redova ) throw std::domain_error("Matrica mora biti kvadratna");
  Matrica<TipElemenata> m3,pom,n;
 
   m3=StvoriMatricu<TipElemenata>(m.br_redova, m.br_kolona);
 
   pom=StvoriMatricu<TipElemenata>(m.br_redova, m.br_kolona);
   n=StvoriMatricu<TipElemenata>(m.br_redova, m.br_kolona);
  
    
    for(int k=0; k<m.br_redova; k++) 
    for(int s=0; s<m.br_kolona; s++) pom.elementi[k][s]=m.elementi[k][s];
    
    
    for(int i = 0; i < m.br_redova; i++) 
    for(int j = 0; j < m.br_kolona; j++) 
    m3.elementi[i][j]=0;
    
    if(v.size()==0) return m3;
   int br(0);
   Matrica<TipElemenata> p;
   
   for(int k=0; k<v.size(); k++) {
    p=ProduktMatrica(pom,m);
    
    
    for(int k=0; k<p.br_redova; k++) 
    for(int s=0; s<p.br_kolona; s++) m.elementi[k][s]=p.elementi[k][s];
    
    UnistiMatricu(p);
    
   for(int i = 0; i < m.br_redova; i++) {
    
    for(int j = 0; j < m.br_kolona; j++) {
     
    if(br==0) {
     if(i==j) m.elementi[i][j]=1;
     else m.elementi[i][j]=0;
    }
   
    n.elementi[i][j]=m3.elementi[i][j];
    m3.elementi[i][j]=v[k]*(m.elementi[i][j]);
     
     
    }
   
   }

   if(k!=0) {
    auto q=ZbirMatrica(m3,n);
   
   for(int k=0; k<m.br_redova; k++) 
    for(int s=0; s<m.br_kolona; s++) m3.elementi[k][s]=q.elementi[k][s];
    
   UnistiMatricu(q);
   }
   br++;
   
   }
  
   UnistiMatricu(pom);
   UnistiMatricu(n);
   return m3;
 }
 
 

int main() {
 Matrica<double> a, b, c; 
 int m;
 std::cout << "Unesite dimenziju kvadratne matrice: ";
 std::cin >> m;
 try {
 a = StvoriMatricu<double>(m, m);

 std::cout << "Unesite elemente matrice A: \n";
 UnesiMatricu('A', a);
 
 std::cout << "Unesite red polinoma: ";
 int red;
 cin>>red;
 cout<<"Unesite koeficijente polinoma: ";
 vector<double> v;
 
 for(int i=0; i<red+1; i++) {
  double a;
  cin>>a;
  v.push_back(a);
 }
 
 
 IspisiMatricu(c = MatricniPolinom(a,v), 10);

 }
 catch(std::bad_alloc) {
 std::cout << "Nema dovoljno memorije!\n";
}
 catch(std::domain_error i) {
 std::cout << i.what();
 }
UnistiMatricu(a); UnistiMatricu(c);
 return 0;
}
