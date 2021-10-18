/B2017/2018: Zadaća 3, Zadatak 3
#include <iostream>
#include <iomanip>
#include <stdexcept>
#include <new>

template <typename TipElementa>
struct Matrica{
 int br_redova, br_kolona;
 TipElementa **elementi=nullptr;
};

template <typename TipElementa>
 void UnistiMatricu(Matrica<TipElementa>mat){
  if(!mat.elementi)return;
   for(int i=0; i<mat.br_redova; i++) delete[] mat.elementi[i];
    delete[] mat.elementi;
  mat.elementi=nullptr;
}
 template<typename TipElementa>
   Matrica<TipElementa>StvoriMatricu(int br_redova, int br_kolona){
   Matrica<TipElementa> mat;
     mat.br_redova=br_redova; mat.br_kolona=br_kolona;
     mat.elementi=new TipElementa*[br_redova];
       for(int i=0; i<br_redova; i++) mat.elementi[i]=nullptr;
  try{
    for(int i=0; i<br_redova; i++)
    mat.elementi[i]=new TipElementa [br_kolona];
  }
  catch (...){
   UnistiMatricu(mat);
   throw;
  }
  return mat;
 }
 template <typename TipElementa>
void UnistiMatricu(char ime_matrice, Matrica<TipElementa> &mat){
  for(int i=0; i<mat.br_redova; i++)
   for(int j=0; j<mat.br_kolona; j++){
     std::cout<<ime_matrice
     <<"("<<i+1<<","<<j+1<<") =";
    std::cin>> mat.elementi[i][j];
 }
}
template<typename TipElementa>
  void IspisiMatricu (const Matrica<TipElementa> &mat, int sirina_ispisa){
     for(int i=0; i<mat.br_redova; i++){
       for(int j=0; j<mat.br_kolona;j++)
         std::cout <<std::setw(sirina_ispisa) <<mat.elementi[i][j];
      std::cout<<std:: endl;
   }
 }
 
 template <typename TipElementa>
  Matrica<TipElementa> ZbirMatrica(const Matrica<TipElementa> &m1,const Matrica<TipElementa> &m2){
   if(m1.br_redova !=m2.br_redova || m1.br_kolona !=m2.br_kolona)
     throw std::domain_error("Matrice nemaju jednake dimenzije!");
     auto m3(StvoriMatricu<TipElementa>(m1.br_redova,m1.br_kolona));
     for(int i=0; i<m1.br_redova; i++)
      for(int j=0; j<m1.br_kolona; j++)
        m3.elementi[i][j]=m1.elementi[i][j]+ m2.elementi[i][j];
        return m3;
  }
 
int main ()
{
 
	return 0;
}