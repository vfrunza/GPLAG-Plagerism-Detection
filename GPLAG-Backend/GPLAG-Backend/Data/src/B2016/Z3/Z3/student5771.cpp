/B2016/2017: Zadaća 3, Zadatak 3
#include <iostream>
#include <iomanip>
#include <stdexcept>
#include <new>
#include<iomanip>
#include<vector>
using namespace std;
const int parametar(6);
const bool treba_brisati(false);
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
 std::cout << ime_matrice<< "(" << i + 1 << "," << j + 1 << ") = ";
 std::cin >> mat.elementi[i][j];
 }
 }
template <typename TipElemenata>
 void IspisiMatricu(const Matrica<TipElemenata> &mat, int sirina_ispisa, int preciznost) {
 for(int i = 0; i < mat.br_redova; i++) {
 for(int j = 0; j < mat.br_kolona; j++)
 std::cout << std::setw(sirina_ispisa) << setprecision(preciznost)<<mat.elementi[i][j];
 std::cout << std::endl;
}
}
template <typename TipElemenata>
 void IspisiMatricu(const Matrica<TipElemenata> &mat, int sirina_ispisa) {
 for(int i = 0; i < mat.br_redova; i++) {
 for(int j = 0; j < mat.br_kolona; j++)
 std::cout << std::setw(sirina_ispisa) <<mat.elementi[i][j];
 std::cout << std::endl;
}
}
template <typename TipElemenata>
 void IspisiMatricu(const Matrica<TipElemenata> &mat, int sirina_ispisa, int preciznost, bool treba_brisati) {
 for(int i = 0; i < mat.br_redova; i++) {
 for(int j = 0; j < mat.br_kolona; j++)
 std::cout << std::setw(sirina_ispisa) << setprecision(preciznost)<<mat.elementi[i][j];
 std::cout << std::endl;
}
if(treba_brisati==true)UnistiMatricu(mat);
}
template <typename TipElemenata>
 Matrica<TipElemenata> ZbirMatrica(const Matrica<TipElemenata> &m1,const Matrica<TipElemenata> &m2) {
 if(m1.br_redova != m2.br_redova || m1.br_kolona != m2.br_kolona)
 throw std::domain_error("Matrice nemaju jednake dimenzije!");
 auto m3(StvoriMatricu<TipElemenata>(m1.br_redova, m1.br_kolona));
 for(int i = 0; i < m1.br_redova; i++)
 for(int j = 0; j < m1.br_kolona; j++)
 m3.elementi[i][j] = m1.elementi[i][j] + m2.elementi[i][j];
 return m3;
 }
  template <typename TipElemenata>
 void Kopiraj(Matrica<TipElemenata> &matrica1,Matrica<TipElemenata> matrica2){
   for(int i=0; i<matrica1.br_redova; i++){
    for(int j=0; j<matrica1.br_kolona; j++){
     matrica1.elementi[i][j]=matrica2.elementi[i][j];
    }
   }
 }
  template <typename TipElemenata>
 void Jedinicna(Matrica<TipElemenata> &matrica){
   for(int i=0; i<matrica.br_redova; i++){
    for(int j=0; j<matrica.br_kolona; j++){
     if(i==j)matrica.elementi[i][j]=1;
     else matrica.elementi[i][j]=0;
    }
   }
 }
 template <typename TipElemenata>
 void MnoziSaSkalarom(Matrica<TipElemenata> &matrica, int skalar){
   for(int i=0; i<matrica.br_redova; i++){
    for(int j=0; j<matrica.br_kolona; j++){
     matrica.elementi[i][j]=matrica.elementi[i][j]*skalar;
    }
   }
 }
 template <typename TipElemenata>
 void VratiNulMatricu( Matrica<TipElemenata> &matrica){
   for(int i=0; i<matrica.br_redova; i++){
    for(int j=0; j<matrica.br_kolona; j++){
     matrica.elementi[i][j]=0;
    }
   }
 }
 template<typename TipElemenata>
Matrica<TipElemenata> ProduktMatrica(const Matrica<TipElemenata> &matrica1, const Matrica<TipElemenata> &matrica2){
    if(matrica1.br_kolona!=matrica2.br_redova)throw domain_error("Matrice nisu saglasne za mnozenje");
    auto proizvod(StvoriMatricu<TipElemenata>(matrica1.br_redova,matrica2.br_kolona));
    for(int i=0; i<matrica1.br_redova; i++){
        for(int j=0; j<matrica2.br_kolona; j++){double suma=0;
         for(int k=0; k<matrica2.br_redova; k++){
      suma+=matrica1.elementi[i][k]*matrica2.elementi[k][j];  
        }
      proizvod.elementi[i][j]=suma;}
    }
    return proizvod;
}
template <typename TipElemenata>
 Matrica<TipElemenata>MatricniPolinom(const Matrica<TipElemenata> &A, vector<double> koeficijenti){
  if(A.br_kolona!=A.br_redova)throw domain_error("Matrica mora biti kvadratna!");
  Matrica<TipElemenata>polinom,stepena,pomocnik;
  try{polinom=StvoriMatricu<TipElemenata>(A.br_redova, A.br_kolona);
  stepena=StvoriMatricu<TipElemenata>(A.br_redova, A.br_kolona);
  pomocnik=StvoriMatricu<TipElemenata>(A.br_redova, A.br_kolona);}
  catch(...){ UnistiMatricu(stepena); UnistiMatricu(pomocnik); UnistiMatricu(polinom); throw;}
  try{
  if(koeficijenti.size()<1)VratiNulMatricu(polinom);//ne alocira//
  else{
    Matrica<TipElemenata>pomocna;
    Jedinicna(pomocnik);//ne alocira//
    MnoziSaSkalarom(pomocnik,koeficijenti[0]);//ne alocira//
    Kopiraj(polinom,pomocnik);//ne alocira//
    Kopiraj(stepena,A);//ne alocira//
    for(int i=1; i<koeficijenti.size(); i++){
    Kopiraj(pomocnik,stepena);//ne alocira//
    MnoziSaSkalarom(pomocnik,koeficijenti[i]);//ne alocira//
    pomocna=ZbirMatrica(pomocnik,polinom);//alocira!//
    Kopiraj(polinom,pomocna);//ne alocira//
    UnistiMatricu(pomocna);//brisi alocirano//
    pomocna=ProduktMatrica(stepena,A);//alocira!//
    Kopiraj(stepena,pomocna);//ne alocira//
    UnistiMatricu(pomocna);//brisi alocirano//
   }
  }
  UnistiMatricu(stepena); UnistiMatricu(pomocnik);//napravljene alocirane brisi//
  return polinom;
  }
  catch(...){ UnistiMatricu(polinom); UnistiMatricu(stepena); UnistiMatricu(pomocnik);
   throw;
  }
 }
int main() {
 Matrica<double> a; // AUTOMATSKA INICIJALIZACIJA!!!
 int n;
 std::cout << "Unesite dimenziju kvadratne matrice: ";
 std::cin >> n;
 cin.ignore(1000,'\n');
 try {
 a = StvoriMatricu<double>(n, n);
 std::cout << "Unesite elemente matrice A: \n";
 UnesiMatricu('A', a);
cout<<"Unesite red polinoma: ";
int red; 
cin>>red;
cout<<"Unesite koeficijente polinoma: ";
vector<double> koeficijenti;
for(int i=0; i<=red; i++){
 double broj;
 cin>> broj;
 koeficijenti.push_back(broj);
}
Matrica<double>matricica;
matricica=MatricniPolinom(a,koeficijenti);
IspisiMatricu(matricica, 10);
UnistiMatricu(matricica);
 }
 catch(std::bad_alloc) {
 std::cout << "Nema dovoljno memorije!\n";
 }
 catch(domain_error izuzetak){
  cout<<izuzetak.what()<<endl;
 }
 UnistiMatricu(a);
 return 0;
}