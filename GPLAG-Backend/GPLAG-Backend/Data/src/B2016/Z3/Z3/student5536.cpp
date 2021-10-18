/B2016/2017: Zadaća 3, Zadatak 3
#include <iostream>
#include <iomanip>
#include <stdexcept>
#include <new>
#include <vector>
bool matrica_obrisana(false);
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
 mat.elementi=nullptr;
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
Matrica<TipElemenata> ProduktMatrica(const Matrica<TipElemenata> &mat1, const Matrica<TipElemenata> &mat2){
    if( mat1.br_kolona!=mat2.br_redova)throw std::domain_error("Matrice nisu saglasne za mnozenje");
    Matrica<TipElemenata> mat3;
    try{
    mat3=(StvoriMatricu<TipElemenata>(mat1.br_redova,mat2.br_kolona));
    for(int i=0;i<mat1.br_redova;i++){
        for(int k=0;k<mat2.br_kolona;k++){
            double suma(0);
            for(int j=0;j<mat1.br_kolona;j++){
                suma+=(mat1.elementi[i][j]*mat2.elementi[j][k]);
            }
            mat3.elementi[i][k]=suma;
        }
    }
    }catch(...){
     UnistiMatricu(mat3);
     throw;
    }
    return mat3;
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
 Matrica<TipElemenata> MatricniPolinom (Matrica<TipElemenata> &a, std::vector<double> v){
  if(a.br_redova!=a.br_kolona)throw std::domain_error("Matrica mora biti kvadratna!");
  Matrica<TipElemenata> jedinicna,zbir,proizvod,b,pomocna, pomocna2,pomocna3;
  try{
  if(v.size()==0){
   Matrica<TipElemenata> c;
   try{
   c=StvoriMatricu<TipElemenata>(a.br_redova,a.br_kolona);
   for(int i=0;i<c.br_redova;i++){
    for(int j=0;j<c.br_kolona;j++){
     c.elementi[i][j]=0;
    }
   }
   }catch(std::bad_alloc){
    UnistiMatricu(c);
    throw;
   }
   return c;
  }
  jedinicna=StvoriMatricu<TipElemenata>(a.br_redova,a.br_kolona);
  zbir=StvoriMatricu<TipElemenata>(a.br_redova,a.br_kolona);
  proizvod=StvoriMatricu<TipElemenata>(a.br_redova,a.br_kolona);
  for(int i=0;i<a.br_redova;i++){
   for(int j=0;j<a.br_kolona;j++){
    if(i==j)jedinicna.elementi[i][j]=1;
    else jedinicna.elementi[i][j]=0;
   }
  }
  for(int i=0;i<a.br_redova;i++){
   for(int j=0;j<a.br_kolona;j++){
    proizvod.elementi[i][j]=a.elementi[i][j];
   }
  }
  b=StvoriMatricu<TipElemenata>(a.br_redova,a.br_kolona);
  pomocna=StvoriMatricu<TipElemenata>(a.br_redova,a.br_kolona);
  for(int k=0;k<v.size();k++){
   int pomocna_varijabla(0);
   for(int i=0;i<a.br_redova;i++){
    for(int j=0;j<a.br_kolona;j++){
     if(k==0){
      jedinicna.elementi[i][j]*=v[k];
     }
     if(k>=2){
      try{
      pomocna3=StvoriMatricu<TipElemenata>(a.br_redova,a.br_kolona);
      if(pomocna_varijabla==0){pomocna3=ProduktMatrica(proizvod,a);
      for(int k=0;k<a.br_redova;k++){
       for(int l=0;l<a.br_kolona;l++)proizvod.elementi[k][l]=pomocna3.elementi[k][l];
       }
       UnistiMatricu(pomocna3);
       pomocna_varijabla++;}
      pomocna.elementi[i][j]=proizvod.elementi[i][j]*v[k];
      }catch(...){
       UnistiMatricu(pomocna3);
       throw;
      }
     }
     else{
      b.elementi[i][j]=a.elementi[i][j]*v[k];
     }
    }
   }
   try{
   if(k==1)zbir=ZbirMatrica(jedinicna,b);
   if(k>=2){
    pomocna2=StvoriMatricu<TipElemenata>(a.br_redova,a.br_kolona);
    pomocna2=ZbirMatrica(pomocna,zbir);
    for(int i=0;i<a.br_redova;i++){
     for(int j=0;j<b.br_redova;j++)zbir.elementi[i][j]=pomocna2.elementi[i][j];
    }
  UnistiMatricu(pomocna2);
    
   }
  }catch(...){
   UnistiMatricu(pomocna2);
   throw;
  }
  }
  UnistiMatricu(jedinicna);UnistiMatricu(proizvod);UnistiMatricu(b);UnistiMatricu(pomocna);
  }catch(...){
   UnistiMatricu(b);UnistiMatricu(jedinicna);UnistiMatricu(pomocna);UnistiMatricu(proizvod);UnistiMatricu(zbir);
   std::cout << "Nedovoljno memorije" << std::endl;
   throw;
  }
  return zbir;
 }
template <typename TipElemenata>
 void IspisiMatricu(const Matrica<TipElemenata> &mat,int sirina_ispisa, int preciznost=6,bool treba_brisati=false) {
 for(int i = 0; i < mat.br_redova; i++) {
 for(int j = 0; j < mat.br_kolona; j++)
 std::cout << std::setw(sirina_ispisa) <<std::setprecision(preciznost)<<mat.elementi[i][j];
 std::cout << std::endl;
 }
 if(treba_brisati==true){
  for(int i=0;i<mat.br_redova;i++)delete [] mat.elementi[i];
  delete[] mat.elementi;
  matrica_obrisana=true;
 }
 }


int main() {
 
 Matrica<double> a, matricni_polinom; 
 int m;
 std::cout << "Unesi dimenziju kvadratne matrice: ";
 std::cin >> m ;
 try {
 a = StvoriMatricu<double>(m,m);
 matricni_polinom= StvoriMatricu<double>(m,m);
 std::cout << "Unesite elemente matrice A:\n";
 UnesiMatricu('A', a);
 std::vector<double> v;
 double broj,koeficijenti;
 std::cout << "Unesite red polinoma: ";
 std::cin >> broj;
 if(broj!=0)std::cout << "Unesite koeficijente polinoma: " ;
 for(int i=0;i<=broj;i++){
  std::cin >> koeficijenti;
  v.push_back(koeficijenti);
 }
 matricni_polinom=MatricniPolinom(a,v);
 IspisiMatricu(matricni_polinom,7);
 if(matrica_obrisana==false){
  UnistiMatricu(matricni_polinom);
  UnistiMatricu(a);}
 else UnistiMatricu(a); 
 }catch(std::domain_error e){
  std::cout << e.what() << std::endl;
 }
 catch(...) {
  UnistiMatricu(a);UnistiMatricu(matricni_polinom);
 std::cout << "Nema dovoljno memorije!\n";
 }
 
 return 0;
}
