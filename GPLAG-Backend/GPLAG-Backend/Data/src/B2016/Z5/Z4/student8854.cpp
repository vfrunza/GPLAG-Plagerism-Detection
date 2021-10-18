/B16/17 (Zadaća 5, Zadatak 4)
//Autotestovi by Ivona Ivkovic (mail: iivkovic2@etf.unsa.ba)
//Za autotestove se obracati *iskljucivo* osobi koja ih pise
#include <iostream>
#include <stdexcept>
template <typename Tip>
class GMatrica
{
  int redovi, kolone;
  Tip niz[4][4];
  public:
  GMatrica(){
      redovi=kolone=0;
  }
  GMatrica(int red,int kol,Tip vr=0)
  {
     if(red<0 || red>4 || kol<0 || kol>4)
     throw std::logic_error("Ilegalan format matrice");
     
     redovi=red;
     kolone=kol;
     for(int i=0;i<4;i++)
     {
         for(int j=0;j<4;j++)
         niz[i][j]=vr;
     }
  }
  template <typename DrugiTip>
  GMatrica(GMatrica<DrugiTip> a)
  {
    redovi=a.redovi;kolone=a.kolone;
    for(int i=0;i<4;i++)
      for(int j=0;j<4;j++)
      niz[i][j]=a.niz[i][j];
    
  }

  
    
};










int main ()
{
	return 0;
}