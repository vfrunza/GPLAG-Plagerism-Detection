/B16/17 (Zadaća 5, Zadatak 3)
//Autotestovi by Enil Pajic (mail: epajic1@etf.unsa.ba)
//Za autotestove se obracati *iskljucivo* osobi koja ih pise
#include <iostream>
#include <stdexcept>
#include <limits>
#include <cmath>
#include <cctype>

using namespace std;
class Razlomak{
  long long int brojnik, nazivnik;
  static int nzd(long long int a, long long int b){
      int n;
      for(int i=1; i<=a && i<=b; i++){
          if(a%i==0 && b%i==0){
              n=i;
          }
      }
      return n;
  }
  static bool sabiranje(long long int x,long long int y){
      if(y>0 && x>numeric_limits<long long int>::max()-y) return true;
      else if(y<0 && x<numeric_limits<long long int>::min()-y) return true;
      else return false;
  }
  static bool mnozenje(long long int x, long long int y){
      if(y>0 && (x<(numeric_limits<long long int>::min()/y) || x>numeric_limits<long long int>::max()/y)) return true;
      else if(y<0 && (x<numeric_limits<long long int>::max()/y || x>numeric_limits<long long int>::min()/y)) return true;
      else return false;
  }
  static bool oduzmise(long long int x, long long int y){
      if((y<0 && x>numeric_limits<long long int>::max()+y) || (y>=0 && x<numeric_limits<long long int>::min()+y)) return true;
      else return false;
  }
  static long double DijeliPls(long long int a, long long int b){
      long double c,d,n;
      c=a;
      d=b;
      n=c/d;
      return n;
  }
  public:
  Razlomak(long long int brojnik=0, long long int nazivnik=1){
      if(nazivnik==0) throw logic_error("Nekorektan razlomak");
      if(brojnik<0 && nazivnik<0) {
          brojnik*=-1; 
          nazivnik*=-1;
      
      }
      if(brojnik>0 && nazivnik<0){
          if(brojnik==numeric_limits<long long int>::min()) throw overflow_error("Nekorektan razlomak");
          else {
              brojnik*=-1;
              nazivnik*=-1;
      }
      }
      if(brojnik>1 && nazivnik>1){
          int a=nzd(brojnik, nazivnik);
          if(brojnik%a==0 && nazivnik%a==0){
              brojnik/=a;
              nazivnik/=a;
          }
      }
      Razlomak::brojnik=brojnik;
      Razlomak::nazivnik=nazivnik;
  }
  int DajBrojnik() const{
      return brojnik;
  }
  int DajNazivnik() const{
      return nazivnik;
  }
  
  friend Razlomak operator+(const Razlomak &r1, const Razlomak &r2);
  friend Razlomak operator-(const Razlomak &r1, const Razlomak &r2);
  friend Razlomak operator*(const Razlomak &r1, const Razlomak &r2);
  friend Razlomak operator/(const Razlomak &r1, const Razlomak &r2);
  friend Razlomak operator-(const Razlomak &r){ r.brojnik*(-1); r.nazivnik*(-1); return r;}
  friend Razlomak operator+(const Razlomak &r){return r;}
  friend Razlomak &operator+=(Razlomak &r1, const Razlomak &r2);
  friend Razlomak &operator-=(Razlomak &r1, const Razlomak &r2);
  friend Razlomak &operator*=(Razlomak &r1, const Razlomak &r2);
  friend Razlomak &operator/=(Razlomak &r1, const Razlomak &r2);
  friend Razlomak &operator++(Razlomak &r1);
  friend Razlomak &operator--(Razlomak &r1);
  friend Razlomak operator++(Razlomak &r1,int);
  friend Razlomak operator--(Razlomak &r1,int);
  friend bool operator==(const Razlomak &r1, const Razlomak &r2);
  friend bool operator!=(const Razlomak &r1, const Razlomak &r2);
  friend bool operator<(const Razlomak &r1, const Razlomak &r2);
  friend bool operator>(const Razlomak &r1, const Razlomak &r2);
  friend bool operator<=(const Razlomak &r1, const Razlomak &r2);
  friend bool operator>=(const Razlomak &r1, const Razlomak &r2);
  friend ostream &operator<<(ostream &tok, const Razlomak &r1);
  friend istream &operator>>(istream &tok, const Razlomak &r1);
   operator long double() const {
      long double jojneznam;
      jojneznam = ((static_cast<long double>(brojnik))/(nazivnik));
      return jojneznam;
  }
};
Razlomak operator+(const Razlomak &r1, const Razlomak &r2){
    if(Razlomak::sabiranje(r1.DajBrojnik(), r1.DajNazivnik()) || Razlomak::sabiranje(r2.DajBrojnik(), r2.DajNazivnik())) throw overflow_error("Nemoguce dobiti tacan rezultat");
    int r;
    long long int a,b;
    r=Razlomak::nzd(r1.DajNazivnik(), r2.DajNazivnik());
    a=r1.DajBrojnik()*(r2.DajNazivnik()/r)+r2.DajBrojnik()*(r1.DajNazivnik()/r);
    b=r1.DajNazivnik()*(r2.DajNazivnik()/r);
    Razlomak raza(a,b);
    return raza;
}
Razlomak operator-(const Razlomak &r1, const Razlomak &r2){
    if(Razlomak::oduzmise(r1.DajBrojnik(), r1.DajNazivnik()) || Razlomak::oduzmise(r2.DajBrojnik(), r2.DajNazivnik())) throw overflow_error("Nemoguce dobiti tacan rezultat");
    int r;
    long long int a,b;
    r=Razlomak::nzd(r1.DajNazivnik(), r2.DajNazivnik());
    a=r1.DajBrojnik()*(r2.DajNazivnik()/r)-r2.DajBrojnik()*(r1.DajNazivnik()/r);
    b=r1.DajNazivnik()*(r2.DajNazivnik()/r);
    Razlomak oduzmi_me(a,b);
    return oduzmi_me;
    
}
Razlomak operator*(const Razlomak &r1, const Razlomak &r2){
    if(Razlomak::mnozenje(r1.DajBrojnik(), r1.DajNazivnik()) || Razlomak::mnozenje(r2.DajBrojnik(), r2.DajNazivnik())) throw overflow_error("Nemoguce dobiti tacan rezultat");
    int s=Razlomak::nzd(r1.DajBrojnik(),r2.DajNazivnik());
    int t=Razlomak::nzd(r2.DajBrojnik(), r1.DajNazivnik());
    long long int a, b;
    a=(r1.DajBrojnik()/s)*(r2.DajBrojnik()/t);
    b=(r1.DajNazivnik()/t)*(r2.DajNazivnik()/s);
    Razlomak pomnozi(a,b);
    return pomnozi;
}
Razlomak operator/(const Razlomak &r1, const Razlomak &r2){
    long long int a,b;
    int u=Razlomak::nzd(r1.brojnik,r2.brojnik);
    int r=Razlomak::nzd(r1.nazivnik, r2.nazivnik);
    a=(r1.DajBrojnik()/u)*(r2.DajNazivnik()/r);
    b=(r1.DajNazivnik()/r)*(r2.DajBrojnik()/u);
    Razlomak dijeli(a,b);
    return dijeli;
}

Razlomak &operator+=(Razlomak &r1, const Razlomak &r2){
    if(Razlomak::sabiranje(r1.DajBrojnik(), r1.DajNazivnik()) || Razlomak::sabiranje(r2.DajBrojnik(), r2.DajNazivnik())) throw overflow_error("Nemoguce dobiti tacan rezultat");
    int r;
    long long int a,b;
    r=Razlomak::nzd(r1.nazivnik, r2.nazivnik);
    a=r1.DajBrojnik()*(r2.DajNazivnik()/r)+r2.DajBrojnik()*(r1.DajNazivnik()/r);
    b=r1.DajNazivnik()*(r2.DajNazivnik()/r);
    Razlomak pomi(a,b);
    r1=pomi;
    return r1;
}
Razlomak &operator-=(Razlomak &r1, const Razlomak &r2){
    if(Razlomak::oduzmise(r1.DajBrojnik(), r1.DajNazivnik()) || Razlomak::oduzmise(r2.DajBrojnik(), r2.DajNazivnik())) throw overflow_error("Nemoguce dobiti tacan rezultat");
    int r;
    long long int a,b;
    r=Razlomak::nzd(r1.nazivnik, r2.nazivnik);
    a=r1.DajBrojnik()*(r2.DajNazivnik()/r)-r2.DajBrojnik()*(r1.DajNazivnik()/r);
    b=r1.DajNazivnik()*(r2.DajNazivnik()/r);
    Razlomak fuj(a,b);
    r1=fuj;
    return r1;
}
Razlomak &operator*=(Razlomak &r1, const Razlomak &r2){
    if(Razlomak::mnozenje(r1.DajBrojnik(), r1.DajNazivnik()) || Razlomak::mnozenje(r2.DajBrojnik(), r2.DajNazivnik())) throw overflow_error("Nemoguce dobiti tacan rezultat.");
    int s=Razlomak::nzd(r1.brojnik,r2.nazivnik);
    int t=Razlomak::nzd(r2.brojnik, r1.nazivnik);
    long long int a,b;
    a=(r1.DajBrojnik()/s)*(r2.DajBrojnik()/t);
    b=(r1.DajNazivnik()/t)*(r2.DajNazivnik()/s);
    Razlomak mnozi(a,b);
    r1=mnozi;
    return r1;
}
Razlomak &operator/=(Razlomak &r1, const Razlomak &r2){
    long long int a,b;
    int u=Razlomak::nzd(r1.brojnik,r2.brojnik);
    int r=Razlomak::nzd(r1.nazivnik, r2.nazivnik);
    a=(r1.DajBrojnik()/u)*(r2.DajNazivnik()/r);
    b=(r1.DajNazivnik()/r)*(r2.DajBrojnik()/u);
    Razlomak mm(a,b);
    r1=mm;
    return r1;
}
Razlomak &operator++(Razlomak &r1){
    long long int a,b;
    a=r1.DajBrojnik()+ 1;
    b=r1.DajNazivnik()+ 1;
    Razlomak huehue(a,b);
    r1=huehue;
    return r1;
}

Razlomak &operator--(Razlomak &r1){
    long long int a,b;
    a=r1.DajBrojnik()- 1;
    b=r1.DajNazivnik()- 1;
    Razlomak uh(a,b);
    r1=uh;
    return r1;
}
Razlomak operator++(Razlomak &r1,int){
    long long int a,b;
    a=r1.DajBrojnik()+ 1;
    b=r1.DajNazivnik()+ 1;
    Razlomak p(a,b);
    r1=p;
    return r1;
}
Razlomak operator--(Razlomak &r1,int){
    long long int a,b;
    a=r1.DajBrojnik() - 1;
    b=r1.DajNazivnik()- 1;
    Razlomak pp(a,b);
    r1=pp;
    return r1;
}

bool operator==(const Razlomak &r1, const Razlomak &r2){
    long double rez1, rez2;
    rez1=Razlomak::DijeliPls(r1.DajBrojnik(), r1.DajNazivnik());
    rez2=Razlomak::DijeliPls(r2.DajBrojnik(), r2.DajNazivnik());
    return(rez1==rez2);
}
bool operator!=(const Razlomak &r1, const Razlomak &r2){
    long double rezi, rezi2;
    rezi=Razlomak::DijeliPls(r1.DajBrojnik(),r1.DajNazivnik());
    rezi2=Razlomak::DijeliPls(r2.DajBrojnik(), r2.DajNazivnik());
    return(!(rezi==rezi2));
}
bool operator<(const Razlomak &r1, const Razlomak &r2){
    long double rezii, reziii;
    rezii=Razlomak::DijeliPls(r1.DajBrojnik(), r1.DajNazivnik());
    reziii=Razlomak::DijeliPls(r2.DajBrojnik(), r2.DajNazivnik());
    return(rezii<reziii);
}
bool operator>(const Razlomak &r1, const Razlomak &r2){
    long double raza1, raza2;
    raza1=Razlomak::DijeliPls(r1.DajBrojnik(), r1.DajNazivnik());
    raza2=Razlomak::DijeliPls(r2.DajBrojnik(), r2.DajNazivnik());
    return(raza1>raza2);
}
bool operator<=(const Razlomak &r1, const Razlomak &r2){
    long double rr, rrr;
    rr=Razlomak::DijeliPls(r1.DajBrojnik(), r1.DajNazivnik());
    rrr=Razlomak::DijeliPls(r2.DajBrojnik(), r2.DajNazivnik());
    return(rr<=rrr);
}
bool operator>=(const Razlomak &r1, const Razlomak &r2){
    long double razl, razlo;
    razl=Razlomak::DijeliPls(r1.DajBrojnik(), r1.DajNazivnik());
    razlo=Razlomak::DijeliPls(r2.DajBrojnik(), r2.DajNazivnik());
    return(razl>=razlo);
}
ostream &operator<<(ostream &tok, const Razlomak &r1){
    if(r1.DajNazivnik()==1){
        tok<<r1.DajBrojnik();
    }
    else {
        tok<<r1.DajBrojnik();
        tok<<"/";
        tok<<r1.DajNazivnik();
    }
    return tok;
}

istream &operator>>(istream &tok, Razlomak &r1){
    char znakic;
    long long int a,b;
    tok>>ws;
    
    if (isdigit(tok.peek())) {
    tok>>a;
    }
    else {
        tok.setstate(ios::failbit);
        return tok;
    }
    
    if(tok.peek() != '/'){
        b=1;
        Razlomak novi=Razlomak(a,b);
        r1=novi;
    }
    else if (tok.peek() == '/') {
    tok>> znakic >> b;
    Razlomak novi=Razlomak(a,b);
    r1=novi;
    }
    
    if (!isblank(tok.peek())) {
        tok.setstate(ios::failbit);
    }
    return tok;
}

int main ()
{
   Razlomak r(1,2), p(3,4);
   cout<<r<<endl;
   cout<<p<<endl;
   r+=p;
   cout<<r<<endl;
   cout<<r+p<<endl;
   if(r>p) cout<<"Razlomak r je veci od razlomka p."<<endl;
   else cout<<"Razlomak r nije veci od razlomka p."<<endl;
   if(r<p) cout<<"Razlomak r je manji od razlomka p."<<endl;
   else cout<<"Razlomak r je veci od razlomka p."<<endl;
   if(r==p) cout<<"Razlomci su isti."<<endl;
   else cout<<"Razlomci su razliciti."<<endl;
   p*=r;
   cout<<p<<endl;
   cout<<p*r<<endl;
   if(p>r) cout<<"Razlomak p je veci od razlomka r"<<endl;
   else cout<<"Razlomak p nije veci od razlomka r."<<endl;
   p/=r;
   cout<<p<<endl;
   cout<<p/r<<endl;
   

   
    return 0;
}