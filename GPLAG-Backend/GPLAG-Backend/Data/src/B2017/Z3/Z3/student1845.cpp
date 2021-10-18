#include <iostream>
#include <iomanip>
#include <stdexcept>
#include <new>
#include <vector>

using namespace std;

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

 template <typename TipElemenata >
 Matrica<TipElemenata> Skalarno(Matrica<TipElemenata> &m1,int pls){
     int si=m1.br_kolona;
     auto m2(StvoriMatricu<TipElemenata>(si,si));
     for(int i=0;i<m1.br_kolona;i++){
         for(int j=0;j<m1.br_kolona;j++){
             m2.elementi[i][j]=m1.elementi[i][j]*pls;
         }
     }
     return m2;
 }



template <typename TipElemenata>
 void UnesiMatricu(char ime_matrice, Matrica<TipElemenata> const &mat) {
 for(int i = 0; i < mat.br_redova; i++)
 for(int j = 0; j < mat.br_kolona; j++) {
 cout << ime_matrice
 << "(" << i + 1 << "," << j + 1 << ") = ";
 cin >> mat.elementi[i][j];
 }
 }

template <typename TipElemenata>
 void IspisiMatricu( Matrica<TipElemenata> &mat, int sirina_ispisa=10,int preciznost=6 ,bool treba_brisat=false) {
 for(int i = 0; i < mat.br_redova; i++) {
 for(int j = 0; j < mat.br_kolona; j++)
 cout<<setprecision(preciznost)<< setw(sirina_ispisa) << mat.elementi[i][j];
 cout<<endl;
 }
 }

template <typename TipElemenata>
 Matrica<TipElemenata> ZbirMatrica(const Matrica<TipElemenata> &m1, const Matrica<TipElemenata> &m2) {
 
 if(m1.br_redova != m2.br_redova || m1.br_kolona != m2.br_kolona)
  throw domain_error("Matrice nemaju jednake dimenzije!");
 
 auto m3(StvoriMatricu<TipElemenata>(m1.br_redova, m1.br_kolona));
 
 for(int i = 0; i < m1.br_redova; i++)
  for(int j = 0; j < m1.br_kolona; j++)
   m3.elementi[i][j] = m1.elementi[i][j] + m2.elementi[i][j];
 
 return m3;
 }
 
 template <typename TipElemenata>
 Matrica<TipElemenata> ProduktMatrica(const Matrica<TipElemenata> &m1,const Matrica<TipElemenata> &m2){
      if(m1.br_redova != m2.br_kolona)throw domain_error("Matrice nisu saglasne za mnozenje");
      auto m3(StvoriMatricu<TipElemenata>(m1.br_redova, m1.br_kolona)); 
      for(int i=0;i<m1.br_kolona;i++){
          for(int j=0;j<m1.br_kolona;j++){
           m3.elementi[i][j]=0;
          }
      }
      int koordx=0,koordy=0;
      for(int i=0;i<m1.br_kolona;i++){
          koordy=0;
          for(int j=0;j<m1.br_kolona;j++){
              for(int k=0;k<m1.br_kolona;k++){
                  m3.elementi[koordx][koordy]+=m1.elementi[i][k]*m2.elementi[k][j];
              }
              koordy++;
          }
          koordx++;
      }
     return m3;
 }
 
 
 template <typename TipElemenata, typename iter >
 Matrica<TipElemenata>MatricniPolinom(Matrica<TipElemenata> &m1,int stepen_polinoma, iter it){
     if(stepen_polinoma<0)throw domain_error("Neispravan stepen polinoma");
     if(m1.br_redova != m1.br_kolona) throw domain_error("“Matrica mora biti kvadratna");
     auto m3(StvoriMatricu<TipElemenata>(m1.br_redova, m1.br_kolona));
     for(int i=0;i<m1.br_kolona;i++){
         for(int j=0;j<m1.br_kolona;j++){
             m3.elementi[i][j]=m1.elementi[i][j];
         }
     }
     auto rez(StvoriMatricu<TipElemenata>(m1.br_redova, m1.br_kolona));
     for(int kom=0;kom<stepen_polinoma+1;kom++){
       
       
        for(int i=0;i<m1.br_kolona;i++){
         for(int j=0;j<m1.br_kolona;j++){
             m3.elementi[i][j]=m1.elementi[i][j];
         }
     }
       
        if(kom==0){
         for(int k=0;k<m1.br_redova;k++){
             for(int l=0;l<m1.br_kolona;l++)
                 if(k==l)m3.elementi[k][l]=1;
                 else m3.elementi[k][l]=0;
         }
        }
        if(kom==1){
         for(int i=0;i<m1.br_kolona;i++){
         for(int j=0;j<m1.br_kolona;j++){
             m3.elementi[i][j]=m1.elementi[i][j];
         }
     }
        }
         for(int j=1;j<kom;j++){
             m3=ProduktMatrica(m3,m1);
            
         }
       rez=ZbirMatrica(rez,Skalarno<TipElemenata>(m3,*it));
       
       it++;
     }
     

     return rez;
 }
 
int main(){
 
try{
 Matrica<double> a,c; // AUTOMATSKA INICIJALIZACIJA!!!
 int m;
 cout << "Unesite dimenziju kvadratne matrice: ";
 cin >> m;
 
 a = StvoriMatricu<double>(m, m);
 cout << "Unesite elemente matrice A: "<<endl;
 UnesiMatricu<double>('A', a);
 cout << "Unesite red polinoma: ";
 int red_polinoma;
 cin >> red_polinoma;
  cout << "Unesite koeficijente polinoma: ";
  
 vector<int>v;
 for(int i=0;i<red_polinoma+1;i++){
     int al;
     cin >> 
     
     al;
     v.push_back(al);
 }


c = MatricniPolinom<double>(a, red_polinoma, v.begin());
IspisiMatricu<double>(c);
     
     
 UnistiMatricu(a);  UnistiMatricu(c);
 }
 catch(bad_alloc) {
 cout << "Nema dovoljno memorije!\n";
 }
 
 return 0;
}