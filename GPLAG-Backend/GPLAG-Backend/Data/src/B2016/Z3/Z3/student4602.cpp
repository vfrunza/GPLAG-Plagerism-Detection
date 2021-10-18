#include <iostream>
#include <iomanip>
#include <stdexcept>
#include <vector>
#include <new>
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
        std::cout << ime_matrice << "(" << i + 1 << "," << j + 1 << ") = ";
        std::cin >> mat.elementi[i][j];
    }
 }
template <typename TipElemenata>
 void IspisiMatricu(const Matrica<TipElemenata> &mat,int sirina_ispisa, int preciznost=2, bool treba_brisati=false) {
     for(int i = 0; i < mat.br_redova; i++) {
         for(int j = 0; j < mat.br_kolona; j++)
         std::cout << std::setw(sirina_ispisa) << setprecision(preciznost)<<mat.elementi[i][j];
         std::cout << std::endl;
 }
 if(treba_brisati==true){
  for(int i=0; i<mat.br_redova; i++) delete[] mat.elementi[i];
  delete[] mat.elementi;
 }
 }

template <typename TipElemenata>
 Matrica<TipElemenata> ZbirMatrica(const Matrica<TipElemenata> &m1,
 const Matrica<TipElemenata> &m2) {
 if(m1.br_redova != m2.br_redova || m1.br_kolona != m2.br_kolona) throw std::domain_error("Matrice nemaju jednake dimenzije!");
 auto m3(StvoriMatricu<TipElemenata>(m1.br_redova, m1.br_kolona));
 for(int i = 0; i < m1.br_redova; i++)
 for(int j = 0; j < m1.br_kolona; j++)
 m3.elementi[i][j] = m1.elementi[i][j] + m2.elementi[i][j];
 return m3;
 }
template <typename t>
Matrica<t> PomnoziSaSkalarom(const Matrica<t>&m1, double a){
 auto m3(StvoriMatricu<t>(m1.br_redova, m1.br_kolona));
 for(int i=0; i<m1.br_redova; i++){
  for(int j=0; j<m1.br_kolona; j++){
   m3.elementi[i][j]=a*m1.elementi[i][j];
  }
 }
 return m3;
}
template<typename t>
Matrica<t> ProduktMatrica(const Matrica<t> &m1, const Matrica<t> &m2){
 if(m1.br_redova!=m2.br_kolona || m1.br_kolona!=m2.br_redova) throw domain_error("Matrice nisu saglasne za mnozenje");
 auto m3(StvoriMatricu<t>(m1.br_redova, m2.br_kolona));
 for(int i=0; i<m1.br_redova; i++){
  for(int j=0; j<m1.br_kolona; j++){
   t suma=0;
   for(int k=0; k<m1.br_kolona; k++){
     suma+=m1.elementi[i][k] * m2.elementi[k][j];
   }
   m3.elementi[i][j]=suma;
  }
 }
 return m3;
}
template<typename t> 
Matrica<t> JedinicnaMatrica(const Matrica<t>m1){
 auto m3(StvoriMatricu<t>(m1.br_redova, m1.br_kolona));
 for(int i=0; i<m1.br_redova; i++){
  for(int j=0; j<m1.br_kolona; j++){
   if(i==j){
    m3.elementi[i][j]=1;
   }
   if(i!=j) m3.elementi[i][j]=0;
  }
 }
 return m3;
}
template<typename t>
Matrica<t> MatricniPolinom(const Matrica<t>&m1, vector<double>v){
 if(m1.br_redova!=m1.br_kolona) throw domain_error("Matrica mora biti kvadratna");
 if(v.size()==0){
  for(int i=0; i<m1.br_redova; i++){
   for(int j=0; j<m1.br_kolona; j++){
    m1.elementi[i][j]=0;
   }
  }
  return m1;
 }
 auto polinom2(StvoriMatricu<t>(m1.br_redova, m1.br_kolona));
 auto polinom3(StvoriMatricu<t>(m1.br_redova, m1.br_kolona));
 auto polinom4(StvoriMatricu<t>(m1.br_redova, m1.br_kolona));
  
 polinom2=PomnoziSaSkalarom(JedinicnaMatrica(m1), v[0]);
  polinom4=ZbirMatrica(PomnoziSaSkalarom(m1, v[1]), polinom2);
 for(int i=2; i<v.size(); i++){
  polinom3=JedinicnaMatrica(m1);
 // UnistiMatricu(JedinicnaMatrica(m1));
    for(int j=1; j<=i; j++){
    polinom3=ProduktMatrica(m1, polinom3);
    UnistiMatricu(ProduktMatrica(m1, polinom3));
    
   }
   polinom3=PomnoziSaSkalarom(polinom3, v[i]);
   UnistiMatricu(PomnoziSaSkalarom(polinom3, v[i]));
   polinom4=ZbirMatrica(polinom4, polinom3);
   UnistiMatricu(ZbirMatrica(polinom4, polinom3));
   
 }
 UnistiMatricu(polinom3);
 UnistiMatricu(polinom2);
 return polinom4;
 
}
 

int main() {
    Matrica<double> a, b, c; 
    int m, n, r;
    double n1;
    vector<double>v;
    std::cout << "Unesite dimenziju kvadratne matrice: ";
    std::cin >> n;
    try {
        a = StvoriMatricu<double>(n, n);
        b = StvoriMatricu<double>(n, n);
        Matrica<double> c;
        std::cout << "Unesite elemente matrice A:\n";
        UnesiMatricu('A', a);
        /*std::cout << "Unesi matricu B:\n";
        UnesiMatricu('B', b);
        std::cout << "Zbir ove dvije matrice je:\n";
        IspisiMatricu(c = ZbirMatrica(a, b), 7);
        cout<<"Produkt ove dvije matrice je:"<<endl;
        IspisiMatricu(d=ProduktMatrica(a,b), 7);*/
        cout<<"Unesite red polinoma: ";
        cin>>r;
        cout<<"Unesite koeficijente polinoma: ";
        while(r>=0){
         cin>>n1;
         v.push_back(n1);
         r--;
        }
        IspisiMatricu(c=MatricniPolinom(a, v), 10, 2, true);
        
    }
    catch(std::bad_alloc) {
     std::cout << "Nema dovoljno memorije!\n";
    }
    UnistiMatricu(a); UnistiMatricu(b); UnistiMatricu(c); 
 return 0;
}
