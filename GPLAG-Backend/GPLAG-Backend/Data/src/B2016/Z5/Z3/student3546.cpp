#include <iostream>
#include <climits>
#include <stdexcept>
#include <iomanip>

using std::cout;
using std::cin;

bool Mnozenje(long long int x,long long int y){
    if(y>0){
        if(x<LLONG_MIN/y || x>LLONG_MAX/y) return true;
        return false;
    }
    else if(y<0){
        if(x==LLONG_MIN || -x>LLONG_MAX/(-y) || -x<LLONG_MIN/(-y)) return true;
        return false;
    }
    
}

bool Sabiranje(long long int x,long long int y){
    if(y>0){
        if(x>LLONG_MAX-y) return true;
        return false;
    }
    else if(y<0){
        if(x<LLONG_MIN-y) return true;
        return false;
    }
}

bool Oduzimanje(long long int x,long long int y){
    return Sabiranje(x,-y);
}

long double DajDecimalni(long long int a,long long int b){
    long double x;
    x=(long double)(a)/b;
    return x;
} 

class Razlomak{
  long long int brojnik,nazivnik;
  static long long int NZD(long long int brojnik,long long int nazivnik){
      if(nazivnik==0) return brojnik;
      else
      return NZD(nazivnik,brojnik%nazivnik);
  }
  public:
  Razlomak(long long int brojnik1=0,long long int nazivnik1=1){
      if(nazivnik1==0) throw std::logic_error("Nekorektan razlomak");
      if(nazivnik1<0){
          nazivnik1*=-1;
          brojnik1*=-1;
      }
      long long int nzd(NZD(brojnik1,nazivnik1));
      brojnik=brojnik1/nzd;
      nazivnik=nazivnik1/nzd;
  }
  long long int DajBrojnik(){return brojnik;}
  long long int DajNazivnik(){return nazivnik;}
  friend Razlomak operator +(const Razlomak &r1,const Razlomak &r2);
  friend Razlomak operator -(const Razlomak &r1,const Razlomak &r2);
  friend Razlomak operator *(const Razlomak &r1,const Razlomak &r2);
  friend Razlomak operator /(const Razlomak &r1,const Razlomak &r2);
  Razlomak operator +(){
      return *this;
  }
  Razlomak operator -(){
      if(Oduzimanje(0,(*this).DajBrojnik())) throw std::overflow_error("Nemoguce dobiti tacan rezultat");
      long long int brojnik1=-(*this).DajBrojnik();
      long long int nazivnik1=(*this).DajNazivnik();
      Razlomak a(brojnik1,nazivnik1);
      return a;
  }
  Razlomak &operator +=(const Razlomak &r1){
      *this=*this+r1;
      return *this;
  }
  Razlomak &operator -=(const Razlomak &r1){
      *this=*this-r1;
      return *this;
  }
  Razlomak &operator *=(const Razlomak &r1){
      *this=*this*r1;
      return *this;
  }
  Razlomak &operator /=(const Razlomak &r1){
      *this=*this/r1;
      return *this;
  }
  Razlomak &operator ++(){
      *this=*this+Razlomak(1);
      return *this;
  }
  Razlomak &operator --(){
      *this=*this-Razlomak(1);
      return *this;
  }
  Razlomak operator ++(int){
      Razlomak a(*this);
      *this=*this+Razlomak(1);
      return a;
  }
  Razlomak operator --(int){
      Razlomak a(*this);
      *this=*this-Razlomak(1);
      return a;
  }
  operator long double() const;
  friend bool operator <(const Razlomak &r1,const Razlomak &r2);
  friend bool operator >(const Razlomak &r1,const Razlomak &r2);
  friend bool operator <=(const Razlomak &r1,const Razlomak &r2);
  friend bool operator >=(const Razlomak &r1,const Razlomak &r2);
  friend bool operator ==(const Razlomak &r1,const Razlomak &r2);
  friend bool operator !=(const Razlomak &r1,const Razlomak &r2);
  friend std::ostream &operator <<(std::ostream &tok,const Razlomak &r);
  friend std::istream &operator >>(std::istream &tok,Razlomak &r);
};

Razlomak operator +(const Razlomak &r1,const Razlomak &r2){
    long long int nzd(Razlomak::NZD(r1.nazivnik,r2.nazivnik));
    if(Mnozenje(r2.brojnik,r1.nazivnik/nzd) || Mnozenje(r1.brojnik,r2.nazivnik/nzd) || Sabiranje(r1.brojnik*(r2.nazivnik/nzd),r2.brojnik*(r1.nazivnik/nzd)) || Mnozenje(r1.nazivnik,r2.nazivnik/nzd)) throw std::overflow_error("Nemoguce dobiti tacan rezultat");
    long long int brojnik1=r1.brojnik*(r2.nazivnik/nzd)+r2.brojnik*(r1.nazivnik/nzd);
    long long int nazivnik1=r1.nazivnik*(r2.nazivnik/nzd);
    Razlomak a(brojnik1,nazivnik1);
    return a;
}

Razlomak operator -(const Razlomak &r1,const Razlomak &r2){
    long long int nzd(Razlomak::NZD(r1.nazivnik,r2.nazivnik));
    if(Mnozenje(r2.brojnik,r1.nazivnik/nzd) || Mnozenje(r1.brojnik,r2.nazivnik/nzd) || Oduzimanje(r1.brojnik*(r2.nazivnik/nzd),r2.brojnik*(r1.nazivnik/nzd)) || Mnozenje(r1.nazivnik,r2.nazivnik/nzd)) throw std::overflow_error("Nemoguce dobiti tacan rezultat");
    long long int brojnik1=r1.brojnik*(r2.nazivnik/nzd)-r2.brojnik*(r1.nazivnik/nzd);
    long long int nazivnik1=r1.nazivnik*(r2.nazivnik/nzd);
    Razlomak a(brojnik1,nazivnik1);
    return a;
}

Razlomak operator *(const Razlomak &r1,const Razlomak &r2){
    long long int s(Razlomak::NZD(r1.brojnik,r2.nazivnik));
    long long int t(Razlomak::NZD(r2.brojnik,r1.nazivnik));
    if(Mnozenje(r1.brojnik/s,r2.brojnik/t) || Mnozenje(r1.nazivnik/t,r2.nazivnik/s)) throw std::overflow_error("Nemoguce dobiti tacan rezultat");
    long long int brojnik1=(r1.brojnik/s)*(r2.brojnik/t);
    long long int nazivnik1=(r1.nazivnik/t)*(r2.nazivnik/s);
    Razlomak a(brojnik1,nazivnik1);
    return a;
}

Razlomak operator /(const Razlomak &r1,const Razlomak &r2){
    long long int r(Razlomak::NZD(r1.nazivnik,r2.nazivnik));
    long long int u(Razlomak::NZD(r1.brojnik,r2.brojnik));
    if(Mnozenje(r1.brojnik/u,r2.nazivnik/r) || Mnozenje(r1.nazivnik/r,r2.brojnik/u)) throw std::overflow_error("Nemoguce dobiti tacan rezultat");
    long long int brojnik1=(r1.brojnik/u)*(r2.nazivnik/r);
    long long int nazivnik1=(r1.nazivnik/r)*(r2.brojnik/u);
    Razlomak a(brojnik1,nazivnik1);
    return a;
}

Razlomak::operator long double() const{
    long double broj;
    broj=(long double)(brojnik)/nazivnik;
    return broj;
}

bool operator <(const Razlomak &r1,const Razlomak &r2){
    long double x=DajDecimalni(r1.brojnik,r1.nazivnik);
    long double y=DajDecimalni(r2.brojnik,r2.nazivnik);
    if(x<y) return true;
    return false;
}

bool operator >(const Razlomak &r1,const Razlomak &r2){
    long double x=DajDecimalni(r1.brojnik,r1.nazivnik);
    long double y=DajDecimalni(r2.brojnik,r2.nazivnik);
    if(x>y)return true;
    return false;
}

bool operator <=(const Razlomak &r1,const Razlomak &r2){
    long double x=DajDecimalni(r1.brojnik,r1.nazivnik);
    long double y=DajDecimalni(r2.brojnik,r2.nazivnik);
    if(x<=y)return true;
    return false;
}

bool operator >=(const Razlomak &r1,const Razlomak &r2){
    long double x=DajDecimalni(r1.brojnik,r1.nazivnik);
    long double y=DajDecimalni(r2.brojnik,r2.nazivnik);
    if(x>=y)return true;
    return false;
}

bool operator ==(const Razlomak &r1,const Razlomak &r2){
    long double x=DajDecimalni(r1.brojnik,r1.nazivnik);
    long double y=DajDecimalni(r2.brojnik,r2.nazivnik);
    if(x==y) return true;
    return false;
}

bool operator !=(const Razlomak &r1,const Razlomak &r2){
    long double x=DajDecimalni(r1.brojnik,r1.nazivnik);
    long double y=DajDecimalni(r2.brojnik,r2.nazivnik);
    if(x!=y)return true;
    return false;
}

std::ostream &operator <<(std::ostream &tok,const Razlomak &r){
    if(r.nazivnik!=1)
    tok<<r.brojnik<<"/"<<r.nazivnik;
    else
    tok<<r.brojnik;
    return tok;
}

std::istream &operator >>(std::istream &tok,Razlomak &r){
    char znak;
    long long int x,y;
    tok>>x>>znak;
    if(znak!='/'){
        if(tok.peek()==EOF){
            r=Razlomak(x);
            return tok;
        }
    tok.setstate(std::ios::failbit);
    }
    tok>>y;
    r=Razlomak(x,y);
    return tok;
}

int main ()
{
  Razlomak r;
        std::cin >> r;
        std::cout << r << std::endl;
}