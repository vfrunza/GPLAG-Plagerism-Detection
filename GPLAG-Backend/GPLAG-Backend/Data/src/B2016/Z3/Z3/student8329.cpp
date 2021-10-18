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
 for(int i = 0; i < mat.br_redova; i++) {
  delete[] mat.elementi[i];
 }
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
 Matrica<TipElemenata> ProduktMatrica (const Matrica<TipElemenata> &mat1, const Matrica<TipElemenata> &mat2){
  if(!mat1.elementi || !mat2.elementi) return  {};
  if(mat1.br_kolona != mat2.br_redova) throw std::domain_error ("Matrice nisu saglasne za mnozenje");
  Matrica<TipElemenata> povratna;
  povratna=StvoriMatricu<TipElemenata>(mat1.br_redova, mat2.br_kolona);
  for(int i=0; i<mat1.br_redova; i++){
   for(int j=0; j<mat2.br_kolona; j++){
    TipElemenata zbir=0;
    for(int k=0; k<mat2.br_redova; k++){
     zbir+=mat1.elementi[i][k]*mat2.elementi[k][j];
    }
    povratna.elementi[i][j]=zbir;
   }
  }
  return povratna;
 }
 
 template<typename TipElemenata>
 Matrica<TipElemenata> SkalarMnozi(const Matrica<TipElemenata> &mat, int skalar){
  Matrica<TipElemenata> povratna=mat;
  for(int i=0; i<mat.br_redova; i++){
   for(int j=0; j<mat.br_kolona; j++){
    povratna.elementi[i][j]=mat.elementi[i][j];
   }
  }
  for(int i=0; i<mat.br_redova; i++){
   for(int j=0; j<mat.br_kolona; j++){
    povratna.elementi[i][j]*=skalar;
   }
  }
  return povratna;
 }
 
 
 template<typename TipElemenata>
 Matrica<TipElemenata> MatricniPolinom(const Matrica<TipElemenata> &mat,std::vector<double> kvote){
  if(!mat.br_redova) return{};
  if(!kvote.size()) return {};
  if(mat.br_redova != mat.br_kolona) throw std::domain_error ("Matrica mora biti kvadratna");
  Matrica<TipElemenata> povratna;
  povratna=StvoriMatricu<TipElemenata>(mat.br_redova, mat.br_kolona);
  for(int i=0; i<povratna.br_redova; i++){
   for(int j=0; j<povratna.br_kolona; j++){
    povratna.elementi[i][j]=0;
   }
  }
  for(int i=0; i<povratna.br_redova; i++){
   povratna.elementi[i][i]=1;
  }
  povratna=SkalarMnozi(povratna, kvote[0]);
  for(int i=1; i<kvote.size(); i++){
  Matrica<TipElemenata> dupla;
  dupla=StvoriMatricu<TipElemenata>(mat.br_kolona, mat.br_kolona);
  for(int i=0; i<mat.br_redova; i++){
   for(int j=0; j<mat.br_kolona; j++){
    dupla.elementi[i][j]=mat.elementi[i][j];
   }
  }
   for(int j=1; j<i; j++){
    auto pomocna=dupla;
    dupla=ProduktMatrica(dupla, mat);
    UnistiMatricu(pomocna);
   }
 //  auto pomocna=dupla;
   dupla=SkalarMnozi(dupla, kvote[i]);
   
 //  povratna.elementi+=dupla.elementi;
  for(int i=0; i<dupla.br_redova; i++){
   for(int j=0; j<dupla.br_kolona; j++){
    povratna.elementi[i][j]+=dupla.elementi[i][j];
   }
  }
  UnistiMatricu(dupla);
  }
  
  return povratna;
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
 void IspisiMatricu(const Matrica<TipElemenata> &mat,  int sirina_ispisa, int preciznost=6, bool brisanje=false) {
 for(int i = 0; i < mat.br_redova; i++) {
  for(int j = 0; j < mat.br_kolona; j++){
 std::cout << std::setw(sirina_ispisa)<<std::setprecision(preciznost) << mat.elementi[i][j];
 }
 std::cout << std::endl;
 }
 if(brisanje) UnistiMatricu(mat);
 }
 
int main() {
 Matrica<double> mat; // AUTOMATSKA INICIJALIZACIJA!!!
 int m;
 std::cout << "Unesite dimenziju kvadratne matrice: ";
 std::cin >> m;
 try {
 mat = StvoriMatricu<double>(m, m);
 std::cout << "Unesite elemente matrice A: \n";
 UnesiMatricu('A', mat);
 std::cout<<"Unesite red polinoma: ";
 int red;
 std::cin>>red;
 std::vector<double> kvote;
 std::cout<<"Unesite koeficijente polinoma: ";
 for(int i=0; i<red+1; i++){
  int element;
  std::cin>>element;
  kvote.push_back(element);
 }
 auto pomocna=mat;
 mat=MatricniPolinom(mat, kvote);
 UnistiMatricu(pomocna);
 IspisiMatricu(mat,10,6);
 }
 catch(std::bad_alloc) {
 std::cout << "Nema dovoljno memorije!\n";
 }
 UnistiMatricu(mat); 
 return 0;
}
