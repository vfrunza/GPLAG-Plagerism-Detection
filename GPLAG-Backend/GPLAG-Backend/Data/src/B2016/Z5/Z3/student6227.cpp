/B16/17 (Zadaća 5, Zadatak 3)
//Autotestovi by Enil Pajic (mail: epajic1@etf.unsa.ba)
//Za autotestove se obracati *iskljucivo* osobi koja ih pise

#include <iostream>
#include <cmath>
#include <stdexcept>
#include <limits>

class Razlomak{
  long long int brojnik, nazivnik;
  static long long int nzd(long long int a, long long int b){
      if(b==0) return a;
      return nzd(b, a%b);
  }
  public:
  Razlomak(long long int br=0, long long int naz=1){
      int a=1;
      if(naz<0) a*=-1;
      if((br==std::numeric_limits<long long int>::lowest() || naz==std::numeric_limits<long long int>::lowest()) && a<0) throw std::overflow_error("Nemoguce dobiti tacan rezultat");
      br*=a;
      naz*=a;
      auto p=nzd(br,naz);
      br/=p;
      naz/=p;
      brojnik=br;
      nazivnik=naz;
  }
};


int main ()
{
	return 0;
}