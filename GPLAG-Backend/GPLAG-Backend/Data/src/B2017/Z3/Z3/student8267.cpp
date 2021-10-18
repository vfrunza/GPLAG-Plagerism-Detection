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
 void IspisiMatricu(const Matrica<TipElemenata> &mat, int sirina_ispisa, int preciznost=6, bool treba_brisati=false) {
     for(int i = 0; i < mat.br_redova; i++) {
     for(int j = 0; j < mat.br_kolona; j++)
     std::cout << std::setw(sirina_ispisa) << std::setprecision(preciznost) << mat.elementi[i][j];
     std::cout << std::endl;
     }
     if(treba_brisati) UnistiMatricu(mat);
 }
template <typename TipElemenata>
 Matrica<TipElemenata> ZbirMatrica(Matrica<TipElemenata> &m1, Matrica<TipElemenata> &m2) {
     if(m1.br_redova != m2.br_redova || m1.br_kolona != m2.br_kolona)
     throw std::domain_error("Matrice nemaju jednake dimenzije!");
     for(int i = 0; i < m1.br_redova; i++)
     for(int j = 0; j < m1.br_kolona; j++)
     m1.elementi[i][j] += m2.elementi[i][j];
     return m1;
 }
template <typename TipElemenata>//+
 Matrica<TipElemenata> ProduktMatrica( Matrica<TipElemenata> m1, Matrica<TipElemenata> m2){
     if(m1.br_redova!=m2.br_kolona) throw std::domain_error("Matrice nisu saglasne za mnozenje");
     auto m3(StvoriMatricu<TipElemenata>(m1.br_redova,m2.br_kolona));
     for(int i=0;i<m1.br_redova;i++){
         for(int j=0;j<m2.br_kolona;j++){
            int s(0);
            for(int k=0;k<m1.br_kolona;k++){
                s+=m1.elementi[i][k]*m2.elementi[k][j];
            }
         m3.elementi[i][j]=s;
         }
     }
     return m3;
 }

template <typename TipElemenata>
Matrica<TipElemenata> StepenMatrice(Matrica<TipElemenata> m, int n){
 Matrica<TipElemenata> temp = m, temp2;
 for(int i=1;i<n;i++){
  temp=ProduktMatrica(temp2 = temp,m);
  UnistiMatricu(temp2);
 }
 return temp;
}

template <typename TipElemenata>
Matrica<TipElemenata> SkalarMatrica(TipElemenata p, Matrica<TipElemenata> m){
 Matrica<TipElemenata> mat = StvoriMatricu<TipElemenata>(m.br_redova, m.br_kolona);
 for(int i=0;i<m.br_redova;i++){
  for(int j=0;j<m.br_kolona;j++){
   mat.elementi[i][j]=m.elementi[i][j]*p;
  }
 }
 return mat;
}

template <typename TipElemenata,typename TipIteratora>//+
 Matrica<TipElemenata> MatricniPolinom( Matrica<TipElemenata> m,int n,TipIteratora it){
     if(n<0) throw std::domain_error("Neispravan stepen polinoma");
     if(m.br_kolona!=m.br_redova) throw std::domain_error("Matrica mora biti kvadratna");
     //auto rezultat(StvoriMatricu<TipElemenata>(m.br_redova,m.br_kolona));
     auto jedinicna=StvoriMatricu<TipElemenata>(m.br_redova,m.br_kolona);
     int vel=m.br_kolona;
     if(m.br_redova<m.br_kolona)
      vel=m.br_redova;
     for(int i=0;i<vel;i++){
      for(int j=0;j<vel;j++){
       if(i==j){
        m.elementi[i][j]=1;
       }
       else m.elementi[i][j]=0;
      }
     }
     Matrica<TipElemenata> rezultat,temp,temp2;
     for(int i=0; i<n; i++){
      if(i==0){
       rezultat=SkalarMatrica(*it,jedinicna);
      }
      else if(i==1){
       ZbirMatrica(rezultat, temp=SkalarMatrica(*it,m));
       UnistiMatricu(temp);
      }
      else
      {
       ZbirMatrica(rezultat, temp=SkalarMatrica(*it,temp2=StepenMatrice(m,i)));
       UnistiMatricu(temp);
       UnistiMatricu(temp2);
      }
      it++;
     }
     UnistiMatricu(jedinicna);
     return rezultat;
 }
int main() {
 Matrica<double> a, b, c; // AUTOMATSKA INICIJALIZACIJA!!!
 int m;
 std::cout << "Unesite dimenziju kvadratne matrice: ";
 std::cin >> m;
 try {
 a = StvoriMatricu<double>(m, m);
 std::cout << "Unesite elemente matrice A:\n";
 UnesiMatricu('A', a);
 std::vector<double> aa{3,-2,0,1};
 c=MatricniPolinom(a, 0, aa.begin());
 IspisiMatricu(c,7);
 }
 catch(std::bad_alloc) {
 std::cout << "Nema dovoljno memorije!\n";
 }
 UnistiMatricu(a); UnistiMatricu(b); UnistiMatricu(c);
 return 0;
}
