/B16/17 (Zadaća 5, Zadatak 3)
//Autotestovi by Enil Pajic (mail: epajic1@etf.unsa.ba)
//Za autotestove se obracati *iskljucivo* osobi koja ih pise
#include <iostream>
#include <stdexcept>
#include <cmath>
#include <limits>
#include <initializer_list>

class Razlomak{
  long long int brojnik,nazivnik;
  long long int NZD(long long int a, long long int b){
      a=std::abs(a); b=std::abs(b);
      long long int x,y;
      if(a>b) x=a,y=b;
      else if(b>a) x=b,y=a;
      else return a;
      long long int pomocni;
      while(1){
            pomocni=x%y;
          x=y; y=pomocni;
          if(y==0) break;
      }
      return x;
  }
  bool prekoracenje_mnozenja(long long int a, long long int b){
      long long int M(std::numeric_limits<long long int>::max()),m(std::numeric_limits<long long int>::min());
      if((b>0 && (a>M/b || a<m/b)) || (b<0 && (a==m || -a>M/(-b) || -a<m/(-b)))) throw std::overflow_error("Nemoguce dobiti tacan rezultat");
      return true;
  }
  bool prekoracenje_sabiranja(long long int a, long long int b){
      long long int M(std::numeric_limits<long long int>::max()),m(std::numeric_limits<long long int>::min());
      if((b>0 && a>M-b) || (b<0 && a<m-b)) throw std::overflow_error("Nemoguce dobiti tacan rezultat");
      return true;
  }
  bool prekoracenje_oduzimanja(long long int a, long long int b){
      long long int M(std::numeric_limits<long long int>::max()),m(std::numeric_limits<long long int>::min());
      if((b>0 && a>M-b) || (b<0 && a<m-b)) throw std::overflow_error("Nemoguce dobiti tacan rezultat");
      return true;
  }
  bool jednaki(long double a, long double b, double eps=1e-20){
      return std::fabs(a-b) <=eps*(std::fabs(a)+std::fabs(b));
  }
  public:
  Razlomak(long long int a=0,long long int b=1){
      if(b==0) throw std::logic_error("Nekorektan razlomak");
      if((a>0 && b<0) || (a<0 && b<0)) {a*=(-1); b*=(-1); }
      brojnik=a; nazivnik=b;
      if(a!=0){
          long long int nzd=NZD(a,b);
          brojnik/=nzd; nazivnik/=nzd;
      }
  }
  Razlomak(std::initializer_list<long long int> lista){
      if(lista.size()==0) brojnik=0, nazivnik=1;
      else if(lista.size()==1){
          nazivnik=1;
          brojnik=*(lista.begin());
      }else if(lista.size()==2){
          auto it=lista.begin();
          long long int a=*it; it++;
          long long int b=*it;
          if(b==0) throw std::logic_error("Nekorektan razlomak");
          if((a>0 && b<0) || (a<0 && b<0)) { a*=(-1); b*=(-1); }
          brojnik=a; nazivnik=b;
          if(brojnik!=0){
              long long int nzd=NZD(a,b);
              brojnik/=nzd; nazivnik/=nzd;
          }
      }
  }
  long long int DajBrojnik() const { return brojnik; }
  long long int DajNazivnik() const { return nazivnik; }
  Razlomak &operator +=(const Razlomak &a);
  Razlomak &operator -=(const Razlomak &a);
  Razlomak &operator *=(const Razlomak &a);
  Razlomak &operator /=(const Razlomak &a);
  Razlomak operator -();
  Razlomak operator +();
  Razlomak &operator ++();
  Razlomak &operator --();
  bool operator < (const Razlomak &a);
  bool operator <= (const Razlomak &a);
  bool operator > (const Razlomak &a);
  bool operator >= (const Razlomak &a);
  bool operator == (const Razlomak &a);
  bool operator != (const Razlomak &a);
  friend Razlomak operator +(const Razlomak &a, const Razlomak &b);
  friend Razlomak operator -(const Razlomak &a, const Razlomak &b);
  friend Razlomak operator *(const Razlomak &a, const Razlomak &b);
  friend Razlomak operator /(const Razlomak &a, const Razlomak &b);
  friend Razlomak operator ++(Razlomak &a, int);
  friend Razlomak operator --(Razlomak &b, int);
  friend std::ostream &operator << (std::ostream &tok, const Razlomak &a);
  friend std::istream &operator >> (std::istream &tok, Razlomak &a); 
  explicit operator long double () const;
  Razlomak &operator =(const Razlomak &a);
};
Razlomak &Razlomak::operator =(const Razlomak &a){
    if(this!=&a){
        brojnik=a.brojnik; nazivnik=a.nazivnik;
    }
    return *this;
}
Razlomak::operator long double ()const{
    return ((long double)(brojnik))/nazivnik;
}
std::istream &operator >> (std::istream &tok, Razlomak &a){
    char znak;
    tok >> std::ws;
    tok >> a.brojnik;
    if(tok.peek()!='/') a.nazivnik=1;
    else{
        long long int pomocni;
        tok >> znak  >> pomocni;
        Razlomak pom(a.brojnik,pomocni);
        a.brojnik=pom.brojnik; a.nazivnik=pom.nazivnik;
    }
    if(tok.peek()!=' ' && tok.peek()!='\n' && tok.peek()!='\t' && tok.peek()!='\f' && tok.peek()!='\v') tok.setstate(std::ios::failbit);
    return tok;
}
std::ostream &operator  << (std::ostream &tok, const Razlomak &a) {
    tok << a.brojnik;
    if(a.brojnik!=0 && a.nazivnik!=1){
        tok << "/" << a.nazivnik;
    }
    return tok;
}
bool Razlomak::operator ==(const Razlomak &a){
    long double x=((long double)(brojnik))/nazivnik, y=((long double)(a.brojnik))/a.nazivnik;
    return jednaki(x,y);
}
inline bool Razlomak::operator !=(const Razlomak &a){
    return !(*this==a);
}
bool Razlomak::operator < (const Razlomak &a){
    long double x=((long double)(brojnik))/nazivnik, y=((long double)(a.brojnik))/a.nazivnik;
    if(!jednaki(x,y) && x<y) return true;
    return false;
}
bool Razlomak::operator <= (const Razlomak &a){
    long double x=((long double)(brojnik))/nazivnik, y=((long double)(a.brojnik))/a.nazivnik;
    if(jednaki(x,y) ||  x<y) return true;
    return false;
}
bool Razlomak::operator > (const Razlomak &a){
     long double x=((long double)(brojnik))/nazivnik, y=((long double)(a.brojnik))/a.nazivnik;
     if(!jednaki(x,y) && x>y) return true;
     return false;
}
bool Razlomak::operator >=(const Razlomak &a){
    long double x=((long double)(brojnik))/nazivnik, y=((long double)(a.brojnik))/a.nazivnik;
     if(jednaki(x,y) || x>y) return true;
     return false;
}
Razlomak &Razlomak::operator --(){
    if(prekoracenje_oduzimanja(brojnik,nazivnik)){
        Razlomak pomocni(brojnik-nazivnik,nazivnik);
        brojnik=pomocni.brojnik; nazivnik=pomocni.nazivnik;
    }
    return *this;
}
Razlomak &Razlomak::operator ++(){
    if(prekoracenje_sabiranja(brojnik,nazivnik)){
        Razlomak pomocni(brojnik+nazivnik,nazivnik);
        brojnik=pomocni.brojnik; nazivnik=pomocni.nazivnik;
    }
    return *this;
}
Razlomak operator ++(Razlomak &a, int){
    Razlomak pom(a.brojnik,a.nazivnik);
    ++a;
    return pom;
}
inline Razlomak operator --(Razlomak &b, int){
    Razlomak pom(b.brojnik,b.nazivnik);
    --b;
    return pom;
}
Razlomak Razlomak::operator -(){
    Razlomak pom(brojnik,nazivnik);
    if(prekoracenje_mnozenja(pom.brojnik,-1)){
        pom.brojnik*=-1;
    }
    brojnik=pom.brojnik; nazivnik=pom.nazivnik;
    return *this;
}
Razlomak Razlomak::operator +(){
    return *this;
}
Razlomak &Razlomak::operator +=(const Razlomak &a) {
    long long int r=NZD(nazivnik,a.nazivnik);
    if(prekoracenje_mnozenja(nazivnik,a.nazivnik/r) && prekoracenje_mnozenja(a.brojnik,nazivnik/r) && prekoracenje_mnozenja(brojnik,a.nazivnik/r) && prekoracenje_sabiranja(brojnik*(a.nazivnik/r),a.brojnik*(nazivnik/r))){
        long long int pomocni_brojnik=brojnik*(a.nazivnik/r) + a.brojnik*(nazivnik/r);
        long long int pomocni_nazivnik=nazivnik*(a.nazivnik/r);
        Razlomak pomocni(pomocni_brojnik,pomocni_nazivnik);
        brojnik=pomocni.brojnik; nazivnik=pomocni.nazivnik;
    }
    return *this;
}
Razlomak &Razlomak::operator -=(const Razlomak &a){
    long long int r=NZD(nazivnik,a.nazivnik);
    if(prekoracenje_mnozenja(nazivnik,a.nazivnik/r) && prekoracenje_mnozenja(a.brojnik,nazivnik/r) && prekoracenje_mnozenja(brojnik,a.nazivnik/r) && prekoracenje_oduzimanja(brojnik*(a.nazivnik/r),a.brojnik*(nazivnik/r))){
        long long int pomocni_brojnik=brojnik*(a.nazivnik/r) - a.brojnik*(nazivnik/r);
        long long int pomocni_nazivnik=nazivnik*(a.nazivnik/r);
        Razlomak pomocni(pomocni_brojnik,pomocni_nazivnik);
        brojnik=pomocni.brojnik; nazivnik=pomocni.nazivnik;
    }
    return *this;
}
Razlomak &Razlomak::operator *=(const Razlomak &a){
    long long int s=NZD(brojnik,a.nazivnik), t=NZD(a.brojnik,nazivnik);
    if(prekoracenje_mnozenja(brojnik/s,a.brojnik/t) && prekoracenje_mnozenja(nazivnik/t,a.nazivnik/s)){
        long long int pomocni_brojnik=(brojnik/s)*(a.brojnik/t);
        long long int pomocni_nazivnik=(nazivnik/t)*(a.nazivnik/s);
        Razlomak pomocni(pomocni_brojnik,pomocni_nazivnik);
        brojnik=pomocni.brojnik; nazivnik=pomocni.nazivnik;
    }
    return *this;
}
Razlomak &Razlomak::operator /=(const Razlomak &a){
    long long int r=NZD(nazivnik,a.nazivnik), u=NZD(brojnik,a.brojnik);
    if(prekoracenje_mnozenja(brojnik/u,a.nazivnik/r) && prekoracenje_mnozenja(nazivnik/r,a.brojnik/u)){
        long long int pomocni_brojnik=(brojnik/u)*(a.nazivnik/r);
        long long int pomocni_nazivnik=(nazivnik/r)*(a.brojnik/u);
        Razlomak pomocni(pomocni_brojnik,pomocni_nazivnik);
        brojnik=pomocni.brojnik; nazivnik=pomocni.nazivnik;
    }
    return *this;
}
inline Razlomak operator +(const Razlomak &a, const Razlomak &b){
    Razlomak pom(a.brojnik,a.nazivnik);
    pom+=b;
    return pom;
}
inline Razlomak operator -(const Razlomak &a, const Razlomak &b){
    Razlomak pom(a.brojnik,a.nazivnik);
    pom-=b;
    return pom;
}
inline Razlomak operator *(const Razlomak &a, const Razlomak &b){
    Razlomak pom(a.brojnik,a.nazivnik);
    pom*=b;
    return pom;
}
inline Razlomak operator /(const Razlomak &a, const Razlomak &b){
    Razlomak pom(a.brojnik,a.nazivnik);
    pom/=b;
    return pom;
}
int main ()
{
   try{
       Razlomak b=3;
       Razlomak a{1,2};
       auto c=(a+2);
       std::cout << (a*(a+b)+(a-b)/a);
       std::cout << std::endl << 2+a << std::endl << c << std::endl << static_cast<long double>(a*3+2/b-5);
   }catch (std::overflow_error e){
       std::cout << e.what() << std::endl;
   }catch(std::logic_error e){
       std::cout << e.what() << std::endl;
   }
	return 0;
}