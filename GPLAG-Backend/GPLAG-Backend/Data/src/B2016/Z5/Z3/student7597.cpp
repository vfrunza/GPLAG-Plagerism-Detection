#include <iostream>
#include <limits>
#include <stdexcept>
#include <sstream>
#include <cmath>
class Razlomak{
    long long int brojnik;
    long long int nazivnik;
    static long long int nzd(long long int a,long long int b){
    if(b==0) return std::abs(a);                                    
    return nzd(b,a%b);                                     
    }
    public:
     Razlomak(long long int brojnik,long long int nazivnik);
    Razlomak():brojnik(0),nazivnik(1){}
     Razlomak(long long int brojnik):brojnik(brojnik),nazivnik(1){}
     Razlomak& operator =(const Razlomak &b);
    long long int DajBrojnik()const { return brojnik;}
    long long int DajNazivnik()const{return nazivnik;}
    Razlomak& operator =(Razlomak &&b);
    Razlomak(const Razlomak &a);
    Razlomak(Razlomak &&a);
    operator long double() const { return (long double)(this->brojnik)/this->nazivnik; }
    friend Razlomak& operator +=(Razlomak &a,const Razlomak &b);
    friend Razlomak operator +(const Razlomak &a,const Razlomak &b);
    friend Razlomak operator -(const Razlomak &a,const Razlomak &b);
    friend Razlomak operator *(const Razlomak &a,const Razlomak &b);
    friend Razlomak operator /(Razlomak a,const Razlomak b);
    friend Razlomak& operator-=(Razlomak &a,const Razlomak &b);
    friend Razlomak& operator *=(Razlomak &a,const Razlomak &b);
    friend Razlomak& operator /=(Razlomak &a,const Razlomak &b);
    friend Razlomak operator-(const Razlomak &a);
    friend Razlomak operator+(const Razlomak &a);
    friend  bool operator ==(const Razlomak &a,const Razlomak &b);
    friend  bool operator >=(const Razlomak &a,const Razlomak &b);
    friend  bool operator <=(const Razlomak &a,const Razlomak &b);
    friend  bool operator >(const Razlomak &a,const Razlomak &b);
    friend  bool operator <(const Razlomak &a,const Razlomak &b);
    friend bool operator !=(const Razlomak &a,const Razlomak &b);
    friend Razlomak operator++(Razlomak &a,int);
    friend Razlomak operator--(Razlomak &a,int);
    friend Razlomak& operator++(Razlomak &a);
    friend Razlomak& operator--(Razlomak &a);
    friend  std::ostream &operator <<(std::ostream &tok,const Razlomak &a);
    friend std::istream &operator >>(std::istream &tok,Razlomak &a);
};
Razlomak::Razlomak(const Razlomak &a){ this->brojnik=a.brojnik; this->nazivnik=a.nazivnik;}
Razlomak::Razlomak(Razlomak &&a){ this->brojnik=a.brojnik; this->nazivnik=a.nazivnik;}
Razlomak operator-(const Razlomak &a){
    if(a.brojnik==std::numeric_limits<long long int>::min()) throw std::overflow_error("Nemoguce dobiti tacan rezultat");
    return Razlomak(-(a.DajBrojnik()),a.DajNazivnik());
}
 Razlomak operator+(const Razlomak &a){
    return a;
}
bool testoverflowsab(long long int a,long long int b){
    if(b>0)return a>(std::numeric_limits<long long int>::max()-b);
    return a<std::numeric_limits<long long int>::min()-b;
}
bool testoverflowmnozenje(long long int a,long long int b){
    if(b>0&&a>(std::numeric_limits<long long int>::max()/b) || b>0&&a<(std::numeric_limits<long long int>::min()/b)) return true;
    if(a==std::numeric_limits<long long int>::min()&&b<0 ||
    b<0&&(-a)>(std::numeric_limits<long long int>::max()/(-b)) || b<0&&(-a)<(std::numeric_limits<long long int>::min()/(-b))) return true; return false;
}
Razlomak::Razlomak(long long int brojnik,long long int nazivnik){
    if(nazivnik==0) throw std::logic_error("Nekorektan razlomak");
    auto NZD(nzd(brojnik,nazivnik));
    Razlomak::brojnik=brojnik/NZD; Razlomak::nazivnik=nazivnik/NZD;
    if(Razlomak::nazivnik<0) {Razlomak::brojnik*=-1; Razlomak::nazivnik*=-1; }
}
Razlomak operator +(const Razlomak &a,const Razlomak &b){
       auto a1(a); return a1+=b;
}
Razlomak operator -(const Razlomak &a,const Razlomak &b){
      auto a1(a); return a1-=b;
}
Razlomak operator * (const Razlomak &a,const Razlomak &b){
     auto a1(a); return a1*=b;
}
Razlomak operator /(Razlomak a,const Razlomak b){
      return a*=Razlomak(b.DajNazivnik(),b.DajBrojnik());
}
 Razlomak& operator +=(Razlomak &a,const Razlomak &b){
     auto r(Razlomak::nzd(a.nazivnik,b.nazivnik));
    if(testoverflowmnozenje(a.brojnik,b.nazivnik/r)||testoverflowmnozenje(b.brojnik,a.nazivnik/r)||testoverflowmnozenje(a.nazivnik,b.nazivnik/r)||
    testoverflowsab(a.brojnik*(b.nazivnik/r),(b.brojnik*(a.nazivnik/r)))) throw std::overflow_error("Nemoguce dobiti tacan rezultat");
    auto tmp1=(a.brojnik*(b.nazivnik/r))+(b.brojnik*(a.nazivnik/r)); 
    auto tmp2=a.nazivnik*(b.nazivnik/r);
    auto NZD=Razlomak::nzd(tmp1,tmp2); a.brojnik=tmp1/NZD; a.nazivnik=tmp2/NZD;
    return a;
 }
 Razlomak& operator-=(Razlomak &a,const Razlomak &b){
     return a+=Razlomak((-b.brojnik),b.nazivnik);
 }
 Razlomak& operator *=(Razlomak &a,const Razlomak &b){
    auto s=Razlomak::nzd(a.brojnik,b.nazivnik); auto t=Razlomak::nzd(b.brojnik,a.nazivnik);
    if(testoverflowmnozenje((a.brojnik/s),(b.brojnik/t))||testoverflowmnozenje(a.nazivnik/t,b.nazivnik/s)) throw std::overflow_error("Nemoguce dobiti tacan rezultat");
    auto tmp1=(a.brojnik/s)*(b.brojnik/t); auto tmp2=(a.nazivnik/t)*(b.nazivnik/s); auto tmp3=Razlomak::nzd(tmp1,tmp2);
    a.brojnik=tmp1/tmp3; a.nazivnik=tmp2/tmp3;
    return a;
 }
  Razlomak& Razlomak::operator =(const Razlomak &b){ this->brojnik=b.brojnik;this->nazivnik=b.nazivnik; return *this; }
  Razlomak& Razlomak::operator =(Razlomak &&b){ this->brojnik=b.brojnik;this->nazivnik=b.nazivnik; return *this; }
 Razlomak& operator /=(Razlomak &a,const Razlomak &b){
     return a*=Razlomak(b.DajNazivnik(),b.DajBrojnik());
 }
 Razlomak& operator++(Razlomak &a){
     a+=Razlomak(1); return a;
 }
 Razlomak& operator--(Razlomak &a){
     a-=Razlomak(1); return a;
 }
 Razlomak operator++(Razlomak &a,int){
     auto tmp(a);
     a+=Razlomak(1); return tmp;
 }
 Razlomak operator--(Razlomak &a,int){
     auto tmp(a);
     a-=(Razlomak(1)); return tmp;
 }
 bool operator==(const Razlomak &a,const Razlomak &b){
     return (a.brojnik==b.brojnik&&a.nazivnik==b.nazivnik);
 }
 bool operator >(const Razlomak &a,const Razlomak &b){
     auto r=Razlomak::nzd(a.brojnik,b.brojnik); auto s=Razlomak::nzd(a.nazivnik,b.nazivnik);
     if(testoverflowmnozenje(a.brojnik/r,b.nazivnik/s)||testoverflowmnozenje(b.brojnik/r,(a.nazivnik/s))) throw std::overflow_error("Nemoguce dobiti tacan rezultat");
     return (a.brojnik/r)*(b.nazivnik/s)>(b.brojnik/r)*(a.nazivnik/s);
 }
  bool operator <(const Razlomak &a,const Razlomak &b){
     auto r=Razlomak::nzd(a.brojnik,b.brojnik); auto s=Razlomak::nzd(a.nazivnik,b.nazivnik);
     if(testoverflowmnozenje(a.brojnik/r,b.nazivnik/s)||testoverflowmnozenje(b.brojnik/r,(a.nazivnik/s))) throw std::overflow_error("Nemoguce dobiti tacan rezultat");
     return ((a.brojnik/r)*(b.nazivnik/s)<(b.brojnik/r)*(a.nazivnik/s));
 }
 bool operator >=(const Razlomak &a,const Razlomak &b){
     return (a==b||a>b);
 }
 bool operator <=(const Razlomak &a,const Razlomak &b){
     return (a==b||a<b);
 }
 bool operator !=(const Razlomak &a,const Razlomak &b){
     return (a.brojnik!=b.brojnik||a.nazivnik!=b.nazivnik);
 }
 std::ostream &operator <<(std::ostream &tok,const Razlomak &a){
     tok<<a.brojnik;
     if(a.nazivnik!=1){ tok<<"/"; tok<<a.nazivnik; }
     return tok;
 }
 std::istream &operator >>(std::istream &tok,Razlomak &a){
     tok>>std::ws;
     char znak;
     if(!(tok>>a.brojnik)){tok.setstate(std::ios::failbit); return tok;}
     a.nazivnik=1;
     if(tok.peek()=='/'){
         tok>>znak;
         if(!(tok>>a.nazivnik)){tok.setstate(std::ios::failbit); return tok;}
         if(tok.peek()!=' '&&tok.peek()!='\n'&&tok.peek()!='\t'&&tok.peek()!='\v'&&tok.peek()!='\f'&&tok.peek()!=EOF){tok.setstate(std::ios::failbit); return tok;}
     }
     a=Razlomak(a.brojnik,a.nazivnik);
     return tok;
 }
int main()
{
    std::cout<<"Unesite dva razlomka formata a/b: "<<std::endl;
    Razlomak a,b;
    std::cin>>a>>b;
    std::cout<<"Zbir: "<<a+b<<std::endl;
    std::cout<<"Proizvod: "<<a*b<<std::endl;
    std::cout<<"Razlika: "<<a-b<<std::endl;
    std::cout<<"Kolicnik: "<<a/b<<std::endl;
}
      
