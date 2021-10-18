/B16/17 (Zadaća 5, Zadatak 3)
//Autotestovi by Enil Pajic (mail: epajic1@etf.unsa.ba)
//Za autotestove se obracati *iskljucivo* osobi koja ih pise
#include <iostream>
#include <iomanip>
#include <cstring>
#include <stdexcept>
#include <new>
#include <string>
#include <cmath>
#include <map>
#include <vector>
#include <memory>
#include <climits>
#include <sstream>
using namespace std;
int NZD(int p,int q){
      int ostatak(1);
      if(p<q){
          int pomocna(p);
          p=q;
          q=pomocna;
      }
      if(p%q==0)return q;
      while(ostatak!=0){
        if(p%q==0)break;
        else {ostatak=p%q;
        p=q;
        q=ostatak;
        }
      }
      return ostatak;
  }
class Razlomak{
  long long int brojnik,nazivnik;
  bool PrekoracenjeMnozenja(long long int x,long long int y)const{
    if(y>0 && (x<LLONG_MIN/y || x>LLONG_MAX/y))return true;
    if(y<0 && (x==LLONG_MIN || -x>LLONG_MAX/(-y) || -x<LLONG_MIN/(-y)))return true;
    return false;
    }
  bool PrekoracenjeSabiranja(long long int x,long long int y)const{
    if(y>0 && x>LLONG_MAX-y)return true;
    if(y<0 && x<LLONG_MIN-y)return true;
    return false;
    }
  bool PrekoracenjeOduzimanja(long long int x,long long int y)const{
    if(y<0 && x>LLONG_MAX+y)return true;
    if(y>0 && x<LLONG_MIN+y)return true;
    return false;
    }
  
  public:
  Razlomak(long long int b,long long int n){
      if(b<0 && n<0){b*=-1;n*=-1;}
      else if(n<0){b*=-1;n*=-1;}
      if(n==0)throw logic_error("Nekorektan razlomak");
      if(b%n==0){
        brojnik=b/n;
        nazivnik=1;
      }
      else{
      nazivnik=n/(NZD(n,b));
      brojnik=b/(NZD(n,b));
        
      }
      
  }
  Razlomak(long long int brojnik){
      Razlomak::brojnik=brojnik;
      Razlomak::nazivnik=1;
  }
  Razlomak(){
      Razlomak::brojnik=0;Razlomak::nazivnik=1;
  }
  Razlomak &operator=(const Razlomak &r){
    brojnik=r.brojnik;
    nazivnik=r.nazivnik;
    return *this;
  }
  Razlomak &operator += (const Razlomak &q){
      long long int r(NZD(q.nazivnik,nazivnik));
      if(PrekoracenjeMnozenja(brojnik,q.nazivnik/r) || PrekoracenjeMnozenja(q.brojnik,nazivnik/r) || PrekoracenjeSabiranja(brojnik*(q.nazivnik/r),q.brojnik*(nazivnik/r)) || PrekoracenjeMnozenja(nazivnik,q.nazivnik/r))throw overflow_error("Nemoguce dobiti tacan rezultat");
      brojnik=brojnik*(q.nazivnik/r)+q.brojnik*(nazivnik/r);
      nazivnik=nazivnik*(q.nazivnik/r);
      long long int b=brojnik;
      long long int n=nazivnik;
      brojnik=brojnik/NZD(b,n);
      nazivnik=nazivnik/NZD(b,n);
      return *this;
  }
  Razlomak &operator -= (const Razlomak &q){
      long long int r(NZD(q.nazivnik,nazivnik));
      if(PrekoracenjeMnozenja(brojnik,q.nazivnik/r) || PrekoracenjeMnozenja(q.brojnik,nazivnik/r) || PrekoracenjeOduzimanja(brojnik*(q.nazivnik/r),q.brojnik*(nazivnik/r)) || PrekoracenjeMnozenja(nazivnik,q.nazivnik/r))throw overflow_error("Nemoguce dobiti tacan rezultat");
      brojnik=brojnik*(q.nazivnik/r)-q.brojnik*(nazivnik/r);
      nazivnik=nazivnik*(q.nazivnik/r);
      long long int b=brojnik;
      long long int n=nazivnik;
      brojnik=brojnik/NZD(b,n);
      nazivnik=nazivnik/NZD(b,n);
      return *this;
  }
  Razlomak &operator *= (const Razlomak &q){
      long long int s(NZD(brojnik,q.nazivnik)),t(NZD(q.brojnik,nazivnik));
      if(PrekoracenjeMnozenja(brojnik/s,q.brojnik/t) || PrekoracenjeMnozenja(nazivnik/t,q.nazivnik/s))throw overflow_error("Nemoguce dobiti tacan rezultat");
      brojnik=(brojnik/s)*(q.brojnik/t);
      nazivnik=(nazivnik/t)*(q.nazivnik/s);
      long long int b=brojnik;
      long long int n=nazivnik;
      brojnik=brojnik/NZD(b,n);
      nazivnik=nazivnik/NZD(b,n);
      return *this;
  }
  Razlomak &operator /= (const Razlomak &q){
      long long int r(NZD(nazivnik,q.nazivnik)),u(NZD(q.brojnik,brojnik));
      if(PrekoracenjeMnozenja(brojnik/u,q.nazivnik/r) || PrekoracenjeMnozenja(nazivnik/r,q.brojnik/u))throw overflow_error("Nemoguce dobiti tacan rezultat");
      brojnik=(brojnik/u)*(q.nazivnik/r);
      nazivnik=(nazivnik/r)*(q.brojnik/u);
      long long int b=brojnik;
      long long int n=nazivnik;
      brojnik=brojnik/NZD(b,n);
      nazivnik=nazivnik/NZD(b,n);
      return *this;
  }
  Razlomak operator -() const {
      return{-brojnik,-nazivnik};
  }
  Razlomak operator +() const {
      return{brojnik,nazivnik};
  }
  Razlomak &operator ++ (){
      this->brojnik+=this->nazivnik;
      return *this;
  }
  Razlomak &operator -- (){
      this->brojnik-=this->nazivnik;
      return *this;
  }
  Razlomak operator ++(int){
      Razlomak pomocni(*this);
      this->brojnik+=this->nazivnik;
      return pomocni;
  }
  Razlomak operator --(int){
      Razlomak pomocni(*this);
      this->brojnik-=this->nazivnik;
      return pomocni;
  }
  long long int DajBrojnik() const {return brojnik;}
  long long int DajNazivnik() const {return nazivnik;}
  bool operator <(const Razlomak &r2){
      if((long double)this->brojnik/this->nazivnik<(long double)r2.brojnik/r2.nazivnik)return true;
      return false;
  }
  bool operator >(const Razlomak &r2){
      if((long double)this->brojnik/this->nazivnik>(long double)r2.brojnik/r2.nazivnik)return true;
      return false;
  }
  bool operator <=(const Razlomak &r2){
      if((long double)this->brojnik/this->nazivnik<=(long double)r2.brojnik/r2.nazivnik)return true;
      return false;
  }
  bool operator >=(const Razlomak &r2){
      if((long double)this->brojnik/this->nazivnik>=(long double)r2.brojnik/r2.nazivnik)return true;
      return false;
  }
  bool operator ==(const Razlomak &r2){
      if(this->brojnik/NZD(brojnik,nazivnik)==r2.brojnik/NZD(r2.brojnik,r2.nazivnik) && this->nazivnik/NZD(brojnik,nazivnik)==r2.nazivnik/NZD(r2.brojnik,r2.nazivnik))return true;
      return false;
  }
  bool operator !=(const Razlomak &r2){
      if(this->brojnik/NZD(brojnik,nazivnik)!=r2.brojnik/NZD(r2.brojnik,r2.nazivnik) || this->nazivnik/NZD(brojnik,nazivnik)!=r2.nazivnik/NZD(r2.brojnik,r2.nazivnik))return true;
      return false;
  }
  friend ostream& operator <<(ostream &tok,const Razlomak &r);
  friend istream& operator >>(istream &tok,Razlomak &r);
  friend inline Razlomak operator + (Razlomak r1,const Razlomak &r2);
  friend inline Razlomak operator - (Razlomak r1,const Razlomak &r2);
  friend Razlomak operator * (Razlomak r1,const Razlomak &r2);
  friend Razlomak operator / (Razlomak r1,const Razlomak &r2);
  friend int StringUInt(string s);
  void Ispis()const{
      cout<<brojnik<<"/"<<nazivnik;
      
  }
  operator long double()const{return static_cast<long double>(brojnik)/nazivnik;}
};

ostream& operator <<(ostream &tok,const Razlomak &r){
      tok<<r.brojnik;
      if(r.nazivnik!=1)tok<<"/"<<r.nazivnik;
      return tok;
  }
int StringUInt(string s);
istream& operator >>(istream &tok,Razlomak &r){
      char znak;
      int a,b;
      tok>>ws;
      tok>>a;
      if(tok.peek()!='/'){
        r.brojnik=a;
        r.nazivnik=1;
        return tok;
      }
      else {
        tok>>znak>>b;
        if(znak!='/')tok.setstate(ios::failbit);
        r.brojnik=a/NZD(a,b);
        r.nazivnik=b/NZD(a,b);
        if(tok.peek()!=' ')tok.setstate(ios::failbit);
      }
      return tok;
}
inline Razlomak operator + (Razlomak r1,const Razlomak &r2){
      r1.brojnik/=NZD(r1.DajBrojnik(),r1.DajNazivnik());
      return r1+=r2;
  }
inline Razlomak operator - (Razlomak r1,const Razlomak &r2){
      r1.brojnik/=NZD(r1.DajBrojnik(),r1.DajNazivnik());
      return r1-=r2;
  }
Razlomak operator * (Razlomak r1,const Razlomak &r2){
      r1.brojnik/=NZD(r1.DajBrojnik(),r1.DajNazivnik());
      return r1*=r2;
  }
Razlomak operator / (Razlomak r1,const Razlomak &r2){
      r1.brojnik/=NZD(r1.DajBrojnik(),r1.DajNazivnik());
      return r1/=r2;
  }
int StringUInt(string s){
  int konacni(0);
  for(int i=0;i<s.length();i++){
    konacni+=(s[i]-48)*(pow(10,s.length()-1-i));
  }
  return konacni;
}

int main ()
{
 return 0;
}