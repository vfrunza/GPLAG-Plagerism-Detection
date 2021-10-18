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
  void UnistiMatricu(Matrica<TipElementa> mat){
      if(!mat.elementi) return;
      for(int i=0; i<mat.br_redova; i++) delete[] mat.elementi[i];
      delete[] mat.elementi;
      mat.elementi=nullptr;
  }
template<typename TipElementa>
  Matrica<TipElementa> StvoriMatricu(int br_redova, int br_kolona){
      Matrica<TipElementa> mat;
      mat.br_redova=br_redova;
      mat.br_kolona=br_kolona;
      mat.elementi= new TipElementa* [br_redova];
      for(int i=0; i<br_redova; i++) mat.elementi[i]=nullptr;
      try{
          for(int i=0; i<br_redova; i++)
             mat.elementi[i]= new TipElementa[br_kolona];
      }
      catch(...){
          UnistiMatricu(mat);
          throw;
      }
      return mat;
  }

int main ()
{
	return 0;
}
