/B16/17 (Zadaća 5, Zadatak 3)
//Autotestovi by Enil Pajic (mail: epajic1@etf.unsa.ba)
//Za autotestove se obracati *iskljucivo* osobi koja ih pise
#include <iostream>
#include <stdexcept>
#include <limits>
#include <cmath>

#define epsilon 0.00000001

class Razlomak{
  long long int brojnik,nazivnik;
  static long long int NZD(long long int a, long long int b){
      if(a<b){
          long long int tmp=a;
          a=b;
          b=tmp;
      }
      while(b!=0){
          long long int c(a);
          long long int d(b);
          a=d;
          b=c%d;
      }
      return a;
  }
  const static long long int m=std::numeric_limits<long long int>::min();
  const static long long int M=std::numeric_limits<long long int>::max();
  static void IzvanSabiranja(long long int x, long long int y){
      if(y>0){
          if(x>M-y) throw std::overflow_error("Nemoguce dobiti tacan rezultat");
      }
      else{
          if(x<m-y) throw std::overflow_error("Nemoguce dobiti tacan rezultat");
      }
  }
  static void IzvanOduzimanja(long long int x, long long int y){
      IzvanSabiranja(x,(-1)*y);
  }
  static void IzvanMnozenja(long long int x, long long int y){
      if(y>0){
          if(x<m/y || x>M/y) throw std::overflow_error("Nemoguce dobiti tacan rezultat");
      }
      else{
          if(x==m || (-1)*x>M/((-1)*y) || (-1)*x<m/((-1)*y)) throw std::overflow_error("Nemoguce dobiti tacan rezultat");
      }
  }
public:
    Razlomak(long long int brojnik=0,long long int nazivnik=1):brojnik(brojnik), nazivnik(nazivnik){
        if(nazivnik==0) throw std::logic_error("Nekorektan razlomak");
        if(nazivnik<0 && brojnik>0) {Razlomak::nazivnik=(-1)*nazivnik; Razlomak::brojnik=(-1)*brojnik;}
        if(nazivnik<0 && brojnik<0) {Razlomak::nazivnik=(-1)*nazivnik; Razlomak::brojnik=(-1)*brojnik;}
        
        long long int broj=NZD(brojnik,nazivnik);
        brojnik/=broj;
        this->brojnik=brojnik;
        nazivnik/=broj;
        this->nazivnik=nazivnik;
    };
    Razlomak(const Razlomak &a){
        this->brojnik=a.brojnik;
        this->nazivnik=a.nazivnik;
    }
    void Ispisi() const;
    long long int DajBrojnik() const {return brojnik;}
    long long int DajNazivnik() const {return nazivnik;}
    friend Razlomak operator +(const Razlomak &a, const Razlomak &b);
    friend Razlomak operator -(const Razlomak &a, const Razlomak &b);
    friend Razlomak operator *(const Razlomak &a, const Razlomak &b); 
    friend Razlomak operator /(const Razlomak &a, const Razlomak &b);
    friend Razlomak operator +(const Razlomak &a){ return a;}
    friend Razlomak operator -(const Razlomak &a){ return {-a.brojnik,a.nazivnik};}
    friend Razlomak &operator +=(Razlomak &a, const Razlomak &b);
    friend Razlomak &operator -=(Razlomak &a, const Razlomak &b);
    friend Razlomak &operator *=(Razlomak &a, const Razlomak &b);
    friend Razlomak &operator /=(Razlomak &a, const Razlomak &b);
    friend Razlomak &operator ++(Razlomak &a);
    friend Razlomak operator ++(Razlomak &a, int);
    friend Razlomak &operator --(Razlomak &a);
    friend Razlomak operator --(Razlomak &a, int);
    friend bool operator >(const Razlomak &a, const Razlomak &b);
    friend bool operator <(const Razlomak &a, const Razlomak &b);
    friend bool operator ==(const Razlomak &a, const Razlomak &b);
    friend bool operator !=(const Razlomak &a, const Razlomak &b);
    friend bool operator <=(const Razlomak &a, const Razlomak &b);
    friend bool operator >=(const Razlomak &a, const Razlomak &b);
    friend std::ostream &operator <<(std::ostream &tok, const Razlomak &a);
    friend std::istream &operator >>(std::istream &tok, Razlomak &a);
    operator long double() const{return brojnik/(long double) nazivnik;}
    
};
void Razlomak::Ispisi()const{
    std::cout<<DajBrojnik()<<" "<<DajNazivnik();
}
Razlomak operator +(const Razlomak &a, const Razlomak &b){
    long long int r=Razlomak::NZD(a.nazivnik,b.nazivnik);
    Razlomak::IzvanMnozenja(a.brojnik,b.nazivnik/r);
    Razlomak::IzvanMnozenja(b.brojnik,a.nazivnik/r);
    Razlomak::IzvanMnozenja(a.nazivnik,b.nazivnik/r);
    long long int brojnik=a.brojnik*(b.nazivnik/r)+b.brojnik*(a.nazivnik/r);
    long long int nazivnik=(a.nazivnik*(b.nazivnik/r));
    Razlomak::IzvanSabiranja(brojnik,nazivnik);
    Razlomak novi(brojnik,nazivnik);
    return novi;
}
Razlomak operator -(const Razlomak &a, const Razlomak &b){
    long long int r=Razlomak::NZD(a.nazivnik,b.nazivnik);
    Razlomak::IzvanMnozenja(a.brojnik,b.nazivnik/r);
    Razlomak::IzvanMnozenja(b.brojnik,a.nazivnik/r);
    Razlomak::IzvanMnozenja(a.nazivnik,b.nazivnik/r);
    long long int brojnik=a.brojnik*(b.nazivnik/r)-b.brojnik*(a.nazivnik/r);
    long long int nazivnik=a.nazivnik*(b.nazivnik/r);
    Razlomak::IzvanOduzimanja(brojnik,nazivnik);
    Razlomak novi(brojnik,nazivnik);
    return novi;
}
Razlomak operator *(const Razlomak &a, const Razlomak &b){
    long long int s=Razlomak::NZD(a.brojnik,b.nazivnik);
    long long int t=Razlomak::NZD(b.brojnik,a.nazivnik);
    Razlomak::IzvanMnozenja(a.brojnik/s,b.brojnik/t);
    Razlomak::IzvanMnozenja(a.nazivnik/t,b.nazivnik/s);
    long long int brojnik=(a.brojnik/s)*(b.brojnik/t);
    long long int nazivnik=(a.nazivnik/t)*(b.nazivnik/s);
    Razlomak novi(brojnik,nazivnik);
    return novi;
}
Razlomak operator /(const Razlomak &a, const Razlomak &b){
    long long int u=Razlomak::NZD(a.brojnik,b.brojnik);
    long long int r=Razlomak::NZD(a.nazivnik,b.nazivnik);
    Razlomak::IzvanMnozenja(a.brojnik/u,b.nazivnik/r);
    Razlomak::IzvanMnozenja(a.nazivnik/r,b.brojnik/u);
    long long int brojnik=(a.brojnik/u)*(b.nazivnik/r);
    long long int nazivnik=(a.nazivnik/r)*(b.brojnik/u);
    Razlomak novi(brojnik,nazivnik);
    return novi;
}
Razlomak &operator +=(Razlomak &a, const Razlomak &b){
    long long int r=Razlomak::NZD(a.nazivnik,b.nazivnik);
    Razlomak::IzvanMnozenja(a.brojnik,b.nazivnik/r);
    Razlomak::IzvanMnozenja(b.brojnik,a.nazivnik/r);
    Razlomak::IzvanMnozenja(a.nazivnik,b.nazivnik/r);
    Razlomak::IzvanSabiranja(a.brojnik*(b.nazivnik/r),b.brojnik*(a.nazivnik/r));
    a.brojnik=a.brojnik*(b.nazivnik/r)+b.brojnik*(a.nazivnik/r);
    a.nazivnik=a.nazivnik*(b.nazivnik/r);
    
    long long int broj=Razlomak::NZD(a.brojnik,a.nazivnik);
    a.brojnik/=broj;
    a.nazivnik/=broj;
    return a;
}
Razlomak &operator -=(Razlomak &a, const Razlomak &b){
    long long int r=Razlomak::NZD(a.nazivnik,b.nazivnik);
    Razlomak::IzvanMnozenja(a.brojnik,b.nazivnik/r);
    Razlomak::IzvanMnozenja(b.brojnik,a.nazivnik/r);
    Razlomak::IzvanMnozenja(a.nazivnik,b.nazivnik/r);
    Razlomak::IzvanOduzimanja(a.brojnik*(b.nazivnik/r),b.brojnik*(a.nazivnik/r));
    
    a.brojnik=a.brojnik*(b.nazivnik/r) + b.brojnik*(a.nazivnik/r);
    a.nazivnik=a.nazivnik *(b.nazivnik/r);
    
    long long int broj=Razlomak::NZD(a.brojnik,a.nazivnik);
    a.brojnik/=broj;
    a.nazivnik/=broj;
    
    return a;
}
Razlomak &operator *=(Razlomak &a, const Razlomak &b){
    long long int s=Razlomak::NZD(a.brojnik,b.nazivnik);
    long long int t=Razlomak::NZD(b.brojnik,a.nazivnik);
    Razlomak::IzvanMnozenja(a.brojnik/s,b.brojnik/t);
    Razlomak::IzvanMnozenja(a.nazivnik/t,b.nazivnik/s);
    a.brojnik=(a.brojnik/s)*(b.brojnik/t);
    a.nazivnik=(a.nazivnik/t)*(b.nazivnik/s);
    long long int broj=Razlomak::NZD(a.brojnik,a.nazivnik);
    a.brojnik/=broj;
    a.nazivnik/=broj;
    return a;
}
Razlomak &operator /=(Razlomak &a, const Razlomak &b){
    long long int r=Razlomak::NZD(a.nazivnik,b.nazivnik);
    long long int u=Razlomak::NZD(a.brojnik,b.brojnik);
    Razlomak::IzvanMnozenja(a.brojnik/u,b.nazivnik/r);
    Razlomak::IzvanMnozenja(a.nazivnik/r, b.brojnik/u);
    a.brojnik=(a.brojnik/u)*(b.nazivnik/r);
    a.nazivnik=(a.nazivnik/r)*(b.brojnik/u);
    long long int broj=Razlomak::NZD(a.brojnik,a.nazivnik);
    a.brojnik/=broj;
    a.nazivnik/=broj;
    return a;
}
Razlomak &operator ++(Razlomak &a){
    Razlomak pomocni(1,1);
    a=pomocni+a;
    return a;
}
Razlomak operator ++(Razlomak &a,int){
    Razlomak pomocni=a;
    ++a;
    return pomocni;
}
Razlomak &operator --(Razlomak &a){
    Razlomak pomocni(1,1);
    a=a-pomocni;
    return a;
}
Razlomak operator --(Razlomak &a,int){
    Razlomak pomocni=a;
    --a;
    return pomocni;
}
bool operator <(const Razlomak &a, const Razlomak &b){
    long double prvi=a.brojnik/a.nazivnik;
    long double drugi=b.brojnik/b.nazivnik;
    if(prvi-drugi<0) return true;
    else return false;
}
bool operator >(const Razlomak &a, const Razlomak &b){
    long double prvi=a.brojnik/a.nazivnik;
    long double drugi=b.brojnik/b.nazivnik;
    if(prvi-drugi>0) return true;
    else return false;
}
bool operator ==(const Razlomak &a, const Razlomak &b){
    long double prvi=a.brojnik/a.nazivnik;
    long double drugi=b.brojnik/b.nazivnik;
    if(fabs(prvi-drugi)<epsilon) return true;
    else return false;
}
bool operator !=(const Razlomak &a, const Razlomak &b){
    return !(a==b);
}
bool operator <=(const Razlomak &a, const Razlomak &b){
    return (a<b || a==b);
}
bool operator >=(const Razlomak &a, const Razlomak &b){
    return (a>b || a==b);
}
std::ostream &operator <<(std::ostream &tok, const Razlomak &a){
    if(a.nazivnik==1){
        return tok<<a.brojnik;
    }
    else{
        return tok<<a.brojnik<<"/"<<a.nazivnik;
    }
}
std::istream &operator >>(std::istream &tok, Razlomak &a){
    char znak;
    tok>>std::ws;
    tok>>a.brojnik>>znak;
    if(znak!='/') tok.setstate(std::ios::failbit);
    tok>>a.nazivnik;
    return tok;
}
int main ()
{
    Razlomak razlomak{10,15};
    razlomak.Ispisi();
	return 0;
}