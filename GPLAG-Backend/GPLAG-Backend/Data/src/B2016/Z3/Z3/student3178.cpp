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
      mat.elementi =new TipEle*[br_redova];
      for(int i=0; i<br_redova; i++) mat.elementi[i] = nullptr;
      try{
           for(int i=0; i<br_redova; i++)
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
       for(int i=0; i<mat.br_redova; i++){
        for(int j=0; j<mat.br_kolona; j++){
            std::cout << ime_matrice << "(" << i+1 << "," << j+1 << ") = ";
            std::cin >> mat.elementi[i][j];
   } }
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
   void PomnoziSaKoeficijentom(Matrica<TipEle> &A, double p){
       for(int i=0; i<A.br_redova; i++){
           for(int j=0; j<A.br_kolona; j++){
             A.elementi[i][j]*=p;
             }
           }
   }

   
template <typename TipEle>
   void ZbrojZaSumu(const  Matrica<TipEle> &A1, const  Matrica<TipEle> &A2){
   if(A1.br_redova != A2.br_redova || A1.br_kolona != A2.br_kolona)
     throw std::domain_error("Matrice nemaju jednake dimenzije!");
 
    for(int i=0; i<A1.br_redova; i++){
        for(int j=0; j<A2.br_kolona; j++){
            A1.elementi[i][j] += A2.elementi[i][j];
        } 
    }   
}
   
template <typename TipEle>
   Matrica<TipEle> ZbirMatrica(const  Matrica<TipEle> &m1, const  Matrica<TipEle> &m2){
   if(m1.br_redova != m2.br_redova || m1.br_kolona != m2.br_kolona)
     throw std::domain_error("Matrice nemaju jednake dimenzije!");
    auto m3(StvoriMatricu<TipEle>(m1.br_redova,m1.br_kolona));
    for(int i=0; i<m1.br_redova; i++)
        for(int j=0; j<m1.br_kolona; j++){
            m3.elementi[i][j] = m1.elementi[i][j] + m2.elementi[i][j];
    return m3;
    }
    
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
   


 template <typename TipEle>
 Matrica<TipEle> DajNulMatricu(const Matrica<TipEle> &A){
     for(int i=0; i<A.br_redova; i++){
        for(int j=0; j<A.br_kolona; j++){
            A.elementi[i][j] = 0 ;}
     }
            return A;
 }
 
 template <typename TipEle>
 Matrica<TipEle> DajJedinicnuMatricu(const Matrica<TipEle> A){
     Matrica<TipEle> B;
      try{
             B=StvoriMatricu<TipEle>(A.br_redova, A.br_kolona);} 
             catch(std::bad_alloc){
                 throw;
             }
    for(int i=0; i<A.br_redova; i++){
        for(int j=0; j<A.br_kolona; j++){
           if(i==j) B.elementi[i][j] = 1 ;
           else B.elementi[i][j] = 0;}
           }
            return B;
 }
 
 
template <typename TipEle>
void UpisiUVektorMat(const Matrica<TipEle> &A1, const Matrica<TipEle> &A2){
       for(int i=0; i<A1.br_redova; i++){
        for(int j=0; j<A1.br_kolona; j++){
         A2.elementi[i][j] = A1.elementi[i][j];   }
         }
   }
    
template <typename TipEle>  
Matrica<TipEle>  MatricniPolinom(const Matrica<TipEle> &A, std::vector<double> v){
      if(A.br_kolona != A.br_redova) throw std::domain_error("Matrica mora biti kvadratna");
      if(v.size() == 0) return DajNulMatricu(A);
      
   std::vector<Matrica<TipEle>> vek_mat(v.size());
    
    try{
        vek_mat[0]=StvoriMatricu<TipEle>(A.br_redova,A.br_kolona);}
    catch(std::bad_alloc) {
        throw;
        }
    
 
    UpisiUVektorMat(DajJedinicnuMatricu(A), vek_mat[0]);
   // UpisiUVektorMat(PomnoziSaKoeficijentom(A, v[1]),vek_mat[1]);
    // IspisiMatricu(vek_mat[0], 10);  
    for(int i=1; i< v.size(); i++){
        try{
            vek_mat[i]=ProduktMatrica<TipEle>(vek_mat[i-1],A);
          //  IspisiMatricu(vek_mat[i], 10);
    }catch(std::bad_alloc){
        for(int i=0; i< v.size(); i++)
           UnistiMatricu(vek_mat[i]);  
        throw;
        }
    }
    
    for(int i= 0; i<v.size(); i++){    
        PomnoziSaKoeficijentom(vek_mat[i],v[i]);
       // ZbrojZaSumu(vek_mat[0],vek_mat[i]);
      //  UnistiMatricu(vek_mat[i]);
    }  
    for(int i= 1; i<v.size(); i++){    
        ZbrojZaSumu(vek_mat[0],vek_mat[i]);
        UnistiMatricu(vek_mat[i]);}
        
    return vek_mat[0];
    }
   
int main(){
    
    Matrica<double>  A;
    int broj;
    std::cout<< "Unesite dimenziju kvadratne matrice: ";
    std::cin >> broj;
    try{
    A=StvoriMatricu<double>(broj,broj);
    std::cout << "Unesite elemente matrice A:\n";
    UnesiMatricu('A', A);
   
    int n;
    std::cout<<"Unesite red polinoma: ";
    std::cin >> n;
    
    std::vector<double> vektor_koeficijenata;
    std::cout<<"Unesite koeficijente polinoma: ";
    int i{0};
    while(i<=n){
        double element;
        std::cin >> element;
        vektor_koeficijenata.push_back(element);
        i++;
    }
    try{

   IspisiMatricu(MatricniPolinom(A,vektor_koeficijenata), 10);
  }
   catch(std::domain_error e){
       std::cout << e.what() << std::endl;
   }
    catch(std::logic_error e){
       std::cout << e.what() << std::endl;
   }
    }
    
    catch(std::bad_alloc){
        std::cout << "Nema dovoljno memorije!\n";
    }
   UnistiMatricu(A); 
    return 0;
    
}

