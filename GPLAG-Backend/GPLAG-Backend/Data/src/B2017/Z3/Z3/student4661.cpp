#include <iostream>
#include <vector>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <iterator>
#include <new>
#include <utility>
#include <stdexcept>
#include <memory>
#include <functional>
#include <cmath>
#include <iomanip>
const int preciznost = 6;
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
 void UnesiMatricu(char ime_matrice, Matrica<TipElemenata> &mat) {
 for(int i = 0; i < mat.br_redova; i++)
 for(int j = 0; j < mat.br_kolona; j++) {
 std::cout << ime_matrice
 << "(" << i + 1 << "," << j + 1 << ") = ";
 std::cin >> mat.elementi[i][j];
 }
 }
 template <typename TipElemenata,typename tip>
 Matrica<TipElemenata> PomnoziSkalarom(const Matrica<TipElemenata> &m1,tip m) {
 for(int i = 0; i < m1.br_redova; i++)
 for(int j = 0; j < m1.br_kolona; j++)
 m1.elementi[i][j]= m*m1.elementi[i][j];
 return m1;
 }
template <typename TipElemenata>
 void IspisiMatricu(const Matrica<TipElemenata> &mat,int sirina_ispisa,bool treba_brisati) {
     sirina_ispisa=preciznost;
     treba_brisati=false;
 for(int i = 0; i < mat.br_redova; i++) {
 for(int j = 0; j < mat.br_kolona; j++)
 std::cout << std::setw(sirina_ispisa) << mat.elementi[i][j];
 std::cout << std::endl;
 }
 if(treba_brisati==true) UnistiMatricu(mat);
 }
 template <typename TipElemenata>
 Matrica<TipElemenata> ProduktMatrica(const Matrica<TipElemenata> &m1,
 const Matrica<TipElemenata> &m2) {
 if(m1.br_kolona != m2.br_redova)
 throw std::domain_error("Matrice nisu saglasne za mnozenje!");
 auto m3(StvoriMatricu<TipElemenata>(m1.br_redova, m2.br_kolona));
 for(int i = 0; i < m1.br_redova; i++)
 for(int j = 0; j < m2.br_kolona; j++)
 for(int k=0;k<m1.br_kolona;k++)
 m3.elementi[i][j] += m1.elementi[i][k] *m2.elementi[k][j];
 return m3;
 }
 template <typename TipElemenata,typename tip>
 Matrica<TipElemenata> MatricniPolinom(const Matrica<TipElemenata> &m1,int n,typename std::vector<tip>::iterator it) {
    std::vector<tip> v(n);
 if(m1.br_kolona != m1.br_redova)
 throw std::domain_error("Matrice nisu saglasne za mnozenje!");
 if(n<0) throw std::domain_error("Neispravan unos");
 auto m3(StvoriMatricu<TipElemenata>(m1.br_redova, m1.br_kolona));
 for(int i=0;i<m1.br_redova;i++){
     for(int j=0;j<m1.br_kolona;j++){
         if(i==j) m3[i][j]=1;
         else m3[i][j]=0;
     }
 }
 m3=*it*m3;
 int k=0;
    for(it=v.begin();it!=v.end();it++){
        k++;
     if(k>=2){
     for(int i=1;i<k;i++){
         ProduktMatrica(m3,m3);
     }}
     m3=PomnoziSkalarom(*it,m3);
 }
 return m3;}
int main() {
 Matrica<int> a, c; // AUTOMATSKA INICIJALIZACIJA!!!
 int m;
 std::cout << "Unesite dimenziju kvadratne matrice:\n";
 std::cin >> m;
 try {
 a = StvoriMatricu<int>(m, m);
 std::cout << "Unesite elemente matrice A:\n";
 UnesiMatricu('A', a);
 std::cout << "Unesite red polinoma: ";
 int m;
 int p;
 std::cin >> m;
 std::vector<int> v;
 std::cout << "Unesite koeficijente polinoma: ";
 for(int i=0;i<m;i++){
     std::cin>>p;
     v.push_back(p);
 }
 std::vector<int>::iterator it1=v.begin();
 IspisiMatricu<double>(c,preciznost,true);
 }
 catch(std::bad_alloc) {
 std::cout << "Nema dovoljno memorije!\n";
 }
 UnistiMatricu(a);
 return 0;
}
