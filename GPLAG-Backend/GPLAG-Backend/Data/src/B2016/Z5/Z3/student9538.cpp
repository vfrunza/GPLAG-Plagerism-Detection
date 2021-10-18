/B16/17 (Zadaća 5, Zadatak 3)
//Autotestovi by Enil Pajic (mail: epajic1@etf.unsa.ba)
//Za autotestove se obracati *iskljucivo* osobi koja ih pise
#include <iostream>
#include <stdexcept>
#include <limits>


#define maxi numeric_limits<long long>::max();
#define mini numeric_limits<long long>::min();

using namespace std;

class Razlomak
{
  long long int n,b;
  static long long int Djelilac(long long int broj,long long int naz)
  {
      if(naz==0) return broj;
      return (Djelilac(naz,broj%naz));
  }
  
  public:
  Razlomak(long long int broj=0,long long int naz=1);
  long long int DajBrojnik()const{return b;}
  long long int DajNazivnik()const{return n;}
  
  friend Razlomak operator+(Razlomak &r1,Razlomak &r2)
  {
      long long int d=Djelilac(r1.n,r2.n);
      long long int p=r1.n;long long int q=r2.n;
      long long int r=r2.b;long long int t=r1.b;
      
      return Razlomak(t*(q/d)+r*(p/d),q/d);
  }
  friend Razlomak operator-(Razlomak &r1,Razlomak &r2)
  {
      
  }
  friend Razlomak operator*(Razlomak &r1,Razlomak &r2);
  friend Razlomak operator/(Razlomak &r1,Razlomak &r2);
  
  friend Razlomak &operator+(Razlomak &r1);
  friend Razlomak &operator-(Razlomak &r1);
  
  friend Razlomak &operator+=(Razlomak &r1,Razlomak &r2);
  friend Razlomak &operator-=(Razlomak &r1,Razlomak &r2);
  friend Razlomak &operator*=(Razlomak &r1,Razlomak &r2);
  friend Razlomak &operator/=(Razlomak &r1,Razlomak &r2);
  
  friend Razlomak &operator++(Razlomak &r1);
  friend Razlomak &operator--(Razlomak &r1);
  friend Razlomak &operator++(Razlomak &r1,int);
  friend Razlomak &operator--(Razlomak &r1,int);
  
  friend ostream &operator<<(ostream &cout,Razlomak r1);
  friend istream &operator>>(ostream &cin,Razlomak &r1);
  
  operator long double()const {return (long double)b/n;}
  
};

Razlomak::Razlomak(long long int broj,long long int naz)
  {     
      
      if(naz!=0)
      {
         if(naz<0){naz*=-1;broj*=-1;}
         else if(naz<0 && broj<0){naz*=-1;broj*=-1;}
         
         long long int nzd=Djelilac(broj,naz);
         
         if(nzd!=1)
            {naz/=nzd;broj/=nzd;}
         
         Razlomak::b=broj;
         Razlomak::n=naz;
         
      }else throw logic_error("Nekorektan razlomak");
  }
  
 
  Razlomak Razlomak::operator-(Razlomak &r1,Razlomak &r2);
  Razlomak Razlomak::operator*(Razlomak &r1,Razlomak &r2);
  Razlomak Razlomak::operator/(Razlomak &r1,Razlomak &r2);
  
int main ()
{   
    Razlomak(8,3);
	return 0;
}