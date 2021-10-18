#include <new>
#include <memory>
#include <vector>
#include <string>
#include <cstring>
#include <iostream>
#include <utility>
#include <stdexcept>
#include <algorithm>
#include <cmath>
#include <iomanip>

template <typename TipEle>
   struct Matrica{
       int br_redova, br_kolona;
       TipEle **elementi = nullptr;
   };
   
   
template <typename TipEle>
   void UnistiMatricu(Matrica<TipEle> mat){
       if(!mat.elementi) return;
       for(int i=0; i<mat.br_redova; i++) delete[] mat.elementi[i];
       delete[] mat.elementi;
       mat.elementi=nullptr;
   }
   

template <typename TipEle>
   Matrica<TipEle> StvoriMatricu(int br_redova, int br_kolona){
      Matrica<TipEle> mat;
      mat.br_redova = br_redova; mat.br_kolona = br_kolona;
      mat.elementi = new TipEle*[br_redova];
      for(int i=0; i<br_redova; i++) mat.elementi[i] = nullptr;
      try{
           for(int i=0; i<br_kolona; i++)
              mat.elementi[i] = new TipEle[br_kolona];
   }
   catch(...){
       UnistiMatricu(mat);
       throw;
   }
   return mat;
   }
   
   
template <typename TipEle>
   void UnesiMatricu(char ime_matrice, Matrica<TipEle> &mat){
       for(int i=0; i<mat.br_redova; i++)
        for(int j=0; j<mat.br_redova; j++){
            std::cout << ime_matrice << "(" << i+1 << "," << j+1 << ") = ";
            std::cin >> mat.elementi[i][j];
   }
}

template <typename TipEle>
   void IspisiMatricu(const  Matrica<TipEle> mat, int sirina_ispisa, int preciznost=6, bool treba_brisati=false ){
       for(int i=0; i<mat.br_redova; i++){
        for(int j=0; j<mat.br_kolona; j++){
            std::cout << std::setprecision(preciznost) << std::setw(sirina_ispisa) << mat.elementi[i][j];}
        std::cout << std::endl;
        }
        if(treba_brisati==true) UnistiMatricu(mat);
   }
   
   
template <typename TipEle>  
Matrica<TipEle>   ProduktMatrica(const Matrica<TipEle> &m1,const Matrica<TipEle> &m2){
         if(m1.br_kolona != m2.br_redova) throw std::domain_error("Matrice nisu saglasne za mnozenje");
         Matrica<TipEle> m3;
         try{
             m3=StvoriMatricu<TipEle>(m1.br_redova, m2.br_kolona);} 
             catch(std::bad_alloc){throw;
             }
             
             for(int i=0; i<m1.br_redova; i++){
                 for(int j=0; j<m2.br_kolona; j++){
                     TipEle suma{}; // TipEle suma{};
                     for(int k=0; k<m1.br_kolona; k++){
                         suma+=m1.elementi[i][k]*m2.elementi[k][j];
                 }
                 m3.elementi[i][j] =suma;
                 }
             }
     return m3;
    }
   
   
   
int main ()
{
    
     Matrica<double> m1;
    Matrica<double> m2;
    m1 = StvoriMatricu<double>(2,3);
    UnesiMatricu<double>('1', m1);
    m2 = StvoriMatricu<double>(3,4);
    UnesiMatricu<double>('2', m2);
    Matrica<double> produkt = ProduktMatrica(m1, m2);
    IspisiMatricu(produkt, 3);
    UnistiMatricu(m1);
    UnistiMatricu(m2);
    UnistiMatricu(produkt);
	return 0;
}