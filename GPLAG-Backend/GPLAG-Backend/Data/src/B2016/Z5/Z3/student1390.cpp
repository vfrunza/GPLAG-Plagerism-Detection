/B16/17 (Zadaća 5, Zadatak 3)
//Autotestovi by Enil Pajic (mail: epajic1@etf.unsa.ba)
//Za autotestove se obracati *iskljucivo* osobi koja ih pise
#include <iostream>
#include <stdexcept>


class Razlomak{
  long long int brojnik,nazivnik;
  static long long int NZD(long long int a, long long int b){
  while(b!=0){
    if(b==0)return a;
    if(a>b)a-=b;
    else b-=a;
  }
  return a;
}
  public:
  Razlomak(){brojnik=0; nazivnik=1;}
  Razlomak(long long int broj){brojnik=broj; nazivnik=1;}
  Razlomak(long long int br,long long int naz);
  long long int DajBrojnik() const{return brojnik;}
  long long int DajNazivnik() const{return nazivnik;}
  friend Razlomak operator +(const Razlomak &r1){return r1;}
  friend Razlomak operator -(const Razlomak &r1){return {-r1.brojnik, -r1.nazivnik};}
  friend Razlomak operator +(const Razlomak &r1, const Razlomak &r2){
    long long int r=NZD(r1.nazivnik,r2.nazivnik);
    Razlomak a;
    a.brojnik=(r1.brojnik*(r2.nazivnik/r)+r2.brojnik*(r1.nazivnik/r));
    a.nazivnik=(r1.nazivnik*(r2.nazivnik/r));
    long long int broj=NZD(a.brojnik,a.nazivnik);
    a.brojnik/=broj;
    a.nazivnik/=broj;
    return a;
  }
  friend Razlomak operator -(const Razlomak &r1, const Razlomak &r2){
      long long int r=NZD(r1.nazivnik,r2.nazivnik);
     Razlomak a;
    a.brojnik=(r1.brojnik*(r2.nazivnik/r)-r2.brojnik*(r1.nazivnik/r));
    a.nazivnik=(r1.nazivnik*(r2.nazivnik/r));
    long long int broj=NZD(a.brojnik,a.nazivnik);
    a.brojnik/=broj;
    a.nazivnik/=broj;
    return a;
  }
  friend Razlomak operator *(const Razlomak &r1, const Razlomak &r2){
    long long int s=NZD(r1.brojnik,r2.nazivnik);
    long long int t=NZD(r2.brojnik,r1.nazivnik);
    Razlomak a;
    a.brojnik=((r1.brojnik/s)*(r2.brojnik/t));
    a.nazivnik=((r1.nazivnik/t)*(r2.nazivnik/s));
    long long int broj=NZD(a.brojnik,a.nazivnik);
    a.brojnik/=broj;
    a.nazivnik/=broj;
    return a;
  }
  friend Razlomak operator /(const Razlomak &r1, const Razlomak &r2){
    long long int u=NZD(r1.brojnik,r2.brojnik);
    long long int r=NZD(r1.nazivnik,r2.nazivnik);
    Razlomak a;
    a.brojnik=((r1.brojnik/u)*(r2.nazivnik/r));
    a.nazivnik=((r1.nazivnik/r)*(r2.brojnik/u));
    long long int broj=NZD(a.brojnik,a.nazivnik);
    a.brojnik/=broj;
    a.nazivnik/=broj;
    return a;
  }
  friend Razlomak operator ++(const Razlomak &r1){return {r1.brojnik+1,r1.nazivnik+1};}
  friend Razlomak operator --(const Razlomak &r1){return {r1.brojnik-1,r1.nazivnik-1};}
  friend std::ostream &operator <<(std::ostream &tok, const Razlomak &r1){
    if(r1.brojnik>0 && r1.nazivnik==1)return tok<<r1.brojnik;
    if(r1.brojnik==0)return tok<<r1.brojnik;
    if(r1.brojnik>0 && r1.nazivnik>0)return tok<<r1.brojnik<<"/"<<r1.nazivnik;
  }
  friend bool operator >(const Razlomak &r1, const Razlomak &r2){
    long double prvi=r1.brojnik/r1.nazivnik;
    long double drugi=r2.brojnik/r2.nazivnik;
    if(prvi>drugi)return true;
    else return false;
  }
  friend bool operator <(const Razlomak &r1, const Razlomak &r2){
    long double prvi=r1.brojnik/r1.nazivnik;
    long double drugi=r2.brojnik/r2.nazivnik;
    if(prvi<drugi)return true;
    else return false;
  }
  friend bool operator >=(const Razlomak &r1, const Razlomak &r2){
    long double prvi=r1.brojnik/r1.nazivnik;
    long double drugi=r2.brojnik/r2.nazivnik;
    if(prvi>=drugi)return true;
    else return false;
  }
  friend bool operator <=(const Razlomak &r1, const Razlomak &r2){
    long double prvi=r1.brojnik/r1.nazivnik;
    long double drugi=r2.brojnik/r2.nazivnik;
    if(prvi<=drugi)return true;
    else return false;
  }
  friend bool operator ==(const Razlomak &r1, const Razlomak &r2){
    if(r1.brojnik==r2.brojnik && r1.nazivnik==r2.nazivnik)return true;
    else return false;
  }
  friend bool operator !=(const Razlomak &r1, const Razlomak &r2){
    if(!(r1.brojnik==r2.brojnik && r1.nazivnik==r2.nazivnik))return true;
    else return false;
  }
  friend std::istream &operator >>(std::istream &tok, Razlomak &r1);
  //friend Razlomak operator ++(const Razlomak &r1, const Razlomak &r2);

};
Razlomak::Razlomak (long long int br,long long int naz){
    long long int broj=NZD(br,naz);
    if(naz==0)throw std::logic_error("Nekorektan razlomak");
    if(naz<0 && br<0){brojnik=(br*-1); nazivnik=(naz*-1);}
    if(naz<0 && br>0){brojnik=(br*-1);nazivnik=(naz*-1);}
    else {
     br/=broj;
     naz/=broj;
     brojnik=br;
     nazivnik=naz;
    }
}
 std::istream &operator >>(std::istream &tok, Razlomak &r1){
    char znak;
    tok>>std::ws;
    long long int a;
    long long int b;
    tok>>a;
    if(tok.peek()!='/'){
      r1.brojnik=a;
      r1.nazivnik=1;
      return tok;
    }
    tok>>znak;
    if(znak!='/')tok.setstate(std::ios::failbit);
    tok>>b;
      if(Razlomak::NZD(a,b)==1){
        r1.brojnik=a;
        r1.nazivnik=b;
        return tok;
        
      }
    else{
      r1.brojnik= a/(Razlomak::NZD(a,b));
      r1.nazivnik=b/(Razlomak::NZD(a,b));
      return tok;
    }
 }


int main ()
{
	return 0;
}