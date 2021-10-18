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
     std::cout << ime_matrice
     << "(" << i + 1 << "," << j + 1 << ") = ";
     std::cin >> mat.elementi[i][j];
     }
   }
template <typename TipElemenata>
  void IspisiMatricu(const Matrica<TipElemenata> &mat, int preciznost=6, bool treba_brisati=false ) {
  for(int i = 0; i < mat.br_redova; i++) {
    for(int j = 0; j < mat.br_kolona; j++)
    std::cout << std::setw(10) << std::setprecision(preciznost) << mat.elementi[i][j];
    std::cout << std::endl;
    if (treba_brisati==true) UnistiMatricu(mat);
  }
 }
template <typename TipElemenata>
  Matrica<TipElemenata> ProduktMatrica( Matrica<TipElemenata> m1, Matrica<TipElemenata> m2) {
     if(m1.br_redova != m2.br_redova || m1.br_kolona != m2.br_kolona)
         throw std::domain_error("Matrice nisu saglasne za mnozenje!");
     auto m3(StvoriMatricu<TipElemenata>(m1.br_redova, m1.br_kolona));
     for(int i = 0; i < m1.br_redova; i++)
       for(int j = 0; j < m1.br_kolona; j++)
       m3.elementi[i][j]=0;
       
       for(int i=0; i<m1.br_redova; i++)
         for (int j=0; j<m1.br_kolona; j++)
           for (int k=0; k< m1.br_kolona; k++){
           m3.elementi[i][j] += m1.elementi[i][k]*m2.elementi[k][j];
           }
       return m3;
 }
 
 template <typename TipElemenata>
  Matrica<TipElemenata> SaberiMatrice (Matrica<TipElemenata> m1, Matrica <TipElemenata> m2){
   auto m3(StvoriMatricu<TipElemenata>(m1.br_redova,m1.br_kolona));
   for (int i=0; i<m1.br_kolona; i++)
    for (int j=0; j<m1.br_redova; j++)
     m3.elementi[i][j]=m1.elementi[i][j]+m2.elementi[i][j];
  return m3;
  }
  
  template <typename TipElemenata>
  Matrica<TipElemenata> MnoziBrojMatricom(Matrica<TipElemenata> &m1, int broj){
   auto m3 (StvoriMatricu<TipElemenata>(m1.br_redova,m1.br_kolona));
   for (int i=0; i<m1.br_kolona; i++)
     for (int j=0; j<m1.br_redova; j++)
      m3.elementi[i][j]=m1.elementi[i][j]*broj;
     
     return m3;
  }
 
 template <typename TipElemenata, typename tip>
 Matrica<TipElemenata> MatricniPolinom (Matrica<TipElemenata> m1, int stepen, tip pok){
  if (stepen<0) throw std::domain_error("Neispravan stepen polinoma");
  auto m3 (StvoriMatricu<TipElemenata>(m1.br_redova,m1.br_kolona));
  
  for (int i=0; i<m1.br_kolona; i++)
    for (int j=0; j<m1.br_kolona;j++)
    m3.elementi[i][j]=0;
        
     auto pom (StvoriMatricu<TipElemenata>(m1.br_redova,m1.br_kolona));
     for (int i=0; i<m1.br_kolona ; i++)
       for (int j=0; j<m1.br_kolona ; j++){
        if (i==j) pom.elementi[i][j]=1;
        else pom.elementi[i][j]=0;
       }
       
     auto pom2 (StvoriMatricu<TipElemenata>(m1.br_redova,m1.br_kolona));
     for (int i=0; i<m1.br_kolona; i++)
        for (int j=0; j<m1.br_kolona; j++){
         pom2.elementi[i][j]=0;
        }
     
     int velicina=stepen;
      for (int i=0; i<=velicina; i++){
       UnistiMatricu(pom2);
       pom2=MnoziBrojMatricom(pom,*pok);
       auto bb=m3;
       m3=SaberiMatrice(m3,pom2);
       UnistiMatricu(bb);
       auto aa=pom;
       pom=ProduktMatrica(m1,pom);
       UnistiMatricu(aa);
       pok++;
      }
      UnistiMatricu(pom2);
      UnistiMatricu(pom);
      
      if(m3.br_redova != m3.br_kolona)
         throw std::domain_error("Matrica mora biti kvadratna!");
         
      return m3;
 }
 
int main() {
 Matrica<int> a, b, c; // AUTOMATSKA INICIJALIZACIJA!!!
 int m;
 std::cout << "Unesite dimenziju kvadratne matrice: ";
 std::cin >> m;;
 try {
 a = StvoriMatricu<int>(m, m);

 std::cout << "Unesite elemente matrice A:\n";
 UnesiMatricu('A', a);
 std::cout << "Unesite red polinoma: ";
 int n;
 std::cin >> n;
 std::cout << "Unesite koeficijente polinoma: ";
 std::vector<double> v;
 
 for (int i=0; i<=n; i++){
  int a;
 std::cin >> a;
 v.push_back(a);
 }
 
 IspisiMatricu(c = MatricniPolinom(a, n, v.begin())); //ovdje dodaj za ispis parametre
 }
 catch(std::bad_alloc) {
 std::cout << "Nema dovoljno memorije!\n";
 }
 catch (std::domain_error izuzetak){
  std::cout << izuzetak.what() << std::endl;
 }
 UnistiMatricu(a); UnistiMatricu(c);
 return 0;
}

