/B2016/2017: Zadaća 3, Zadatak 3
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
 void IspisiMatricu(Matrica<TipElemenata> &mat, int sirina_ispisa, int preciznost = 6, bool treba_brisati = false) {
 std::setprecision(preciznost);
 for(int i = 0; i < mat.br_redova; i++) {
 for(int j = 0; j < mat.br_kolona; j++)
 std::cout << std::setprecision(preciznost) <<std::setw(sirina_ispisa) << mat.elementi[i][j];
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
 for(int i = 0; i < m1.br_redova; i++)
 for(int j = 0; j < m1.br_kolona; j++)
 m3.elementi[i][j] = m1.elementi[i][j] + m2.elementi[i][j];
 return m3;
 }

template <typename TipElemenata>
Matrica<TipElemenata> ProduktMatrica(const Matrica<TipElemenata> &m1, const Matrica<TipElemenata> &m2){
 Matrica<TipElemenata> p;
 if(m1.br_kolona != m2.br_redova) throw std::domain_error("Matrice nisu saglasne za mnozenje");
 try{
 p = StvoriMatricu<TipElemenata>(m1.br_redova, m2.br_kolona);
 }catch(...){
  UnistiMatricu(p);
  throw std::bad_alloc();
 }
 for(int i=0; i<m1.br_redova; i++){
  for(int j=0; j<m2.br_kolona; j++){
    p.elementi[i][j] = 0;
   for(int k=0; k<m1.br_kolona; k++){
    p.elementi[i][j] += (m1.elementi[i][k] * m2.elementi[k][j]);
   }
  }
 }
 return p;
}

template <typename TipElemenata>
Matrica<TipElemenata> PomnoziSaSkalarom(const Matrica<TipElemenata> &m1, int x){
 Matrica<TipElemenata> m;
 m = StvoriMatricu<TipElemenata>(m1.br_kolona, m1.br_kolona);
 //UnistiMatricu(m1);
 for(int i=0; i<m.br_redova; i++)
  for(int j=0; j<m.br_kolona; j++)
   m.elementi[i][j] = m1.elementi[i][j]*x;
 return m;
}

template <typename TipElemenata>
void NapraviJedinicnu(Matrica<TipElemenata> &m){
 for(int i=0; i<m.br_redova; i++)
  for(int j=0; j<m.br_kolona; j++)
   if(i==j) m.elementi[i][j] = 1;
   else m.elementi[i][j] = 0;
}

template <typename TipElemenata>
 void AdisZbir(Matrica<TipElemenata> &m1, const Matrica<TipElemenata> &m2) {
 if(m1.br_redova != m2.br_redova || m1.br_kolona != m2.br_kolona)
 throw std::domain_error("Matrice nemaju jednake dimenzije!");
 for(int i = 0; i < m1.br_redova; i++)
 for(int j = 0; j < m1.br_kolona; j++)
 m1.elementi[i][j] = m1.elementi[i][j] + m2.elementi[i][j];
 }

template <typename TipElemenata>
Matrica<TipElemenata> MatricniPolinom(const Matrica<TipElemenata> &m, std::vector<double> &v){
 if(m.br_redova != m.br_kolona) throw std::domain_error("Matrica mora biti kvadratna");
 Matrica<TipElemenata> polinom, p, pomnozena, jedinicna, privremena;
 polinom = StvoriMatricu<TipElemenata>(m.br_redova, m.br_kolona);
 for(int i=0; i<polinom.br_kolona; i++)
    for(int j=0; j<polinom.br_kolona; j++)
       polinom.elementi[i][j] = 0;
 if(v.size() == 0) return polinom;    
 p = StvoriMatricu<TipElemenata>(m.br_redova, m.br_kolona);
 pomnozena = StvoriMatricu<TipElemenata>(m.br_redova, m.br_kolona);
 jedinicna = StvoriMatricu<TipElemenata>(m.br_redova, m.br_kolona);
 NapraviJedinicnu<TipElemenata>(jedinicna);
 pomnozena = PomnoziSaSkalarom(jedinicna, v[0]);
 AdisZbir(polinom, pomnozena);
 UnistiMatricu(pomnozena);
 UnistiMatricu(jedinicna);
 
 for(int i=0; i<polinom.br_kolona; i++)
    for(int j=0; j<polinom.br_kolona; j++)
       p.elementi[i][j] = m.elementi[i][j];
    
 for(int i=1; i<v.size(); i++){
  pomnozena = PomnoziSaSkalarom(p, v[i]);
   
  AdisZbir(polinom, pomnozena);
  UnistiMatricu(pomnozena);
 
 privremena = ProduktMatrica(p, m);
   UnistiMatricu(p);
   p = privremena;
 }
 UnistiMatricu(p);
 return polinom;
}

int main() {
 Matrica<double> a, polinom; // AUTOMATSKA INICIJALIZACIJA!!!
 int m;
 std::cout << "Unesite dimenziju kvadratne matrice: ";
 std::cin >> m;
 try {
 a = StvoriMatricu<double>(m, m);
 polinom = StvoriMatricu<double>(m, m);
 std::cout << "Unesite elemente matrice A: \n";
 UnesiMatricu('A', a);
 std::cout << "Unesite red polinoma: ";
 int red;
 std::cin >> red;
 std::cout << "Unesite koeficijente polinoma: ";
 std::vector<double> v(red+1);
 for(int i=0; i<red+1; i++)
  std::cin >> v[i];
 polinom = MatricniPolinom(a, v);
 IspisiMatricu(polinom, 10);
 
 }
 catch(std::bad_alloc) {
 std::cout << "Nema dovoljno memorije!\n";
 UnistiMatricu(a); UnistiMatricu(polinom);
 }
 UnistiMatricu(a); UnistiMatricu(polinom);
 return 0;
}
