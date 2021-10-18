#include <iostream>
#include<initializer_list>
#include<stdexcept>
#include <sstream>
#include<cmath>
#include <climits>
class Razlomak
{
    long long int brojnik;
    long long int nazivnik;
    static long long int NZD(long long int a, long long int b);
public:
    Razlomak(long long int b=0, long long int r=1);
    Razlomak(std::initializer_list<long long int> lista);
    long long int DajBrojnik() const {
        return brojnik;
    }
    long long int DajNazivnik() const {
        return nazivnik;
    }
    friend Razlomak operator +(const Razlomak &a, const Razlomak &b) {
         if(b.brojnik>0 && b.nazivnik>0) {
        if(double(a.brojnik)/a.nazivnik>(LLONG_MAX-double(b.brojnik)/b.nazivnik)) throw std::overflow_error("Nemoguce dobiti tacan rezultat");

    }
    if(b.brojnik<0 || b.nazivnik<0) {
        if(double(a.brojnik)/a.nazivnik<(LLONG_MIN-double(b.brojnik)/b.nazivnik)) throw std::overflow_error("Nemoguce dobiti tacan rezultat");

    }
        long long int r=NZD(a.nazivnik, b.nazivnik);
           return {static_cast<int>(a.DajBrojnik()*(b.DajNazivnik()/r)+b.DajBrojnik()*(a.DajNazivnik()/r)),static_cast<int>(a.DajNazivnik()*(b.DajNazivnik()/r))};

    }
    friend Razlomak operator -(const Razlomak &a, const Razlomak &b) {
          if(b.brojnik>0 && b.nazivnik>0) {
        if(double(a.brojnik)/a.nazivnik>(LLONG_MAX-double(b.brojnik)/b.nazivnik)) throw std::overflow_error("Nemoguce dobiti tacan rezultat");

    }
    if(b.brojnik<0 || b.nazivnik<0) {
        if(double(a.brojnik)/a.nazivnik<(LLONG_MIN-double(b.brojnik)/b.nazivnik)) throw std::overflow_error("Nemoguce dobiti tacan rezultat");

    }
        long long int r=NZD(a.nazivnik, b.nazivnik);
            return {static_cast<int>(a.DajBrojnik()*(b.DajNazivnik()/r)-b.DajBrojnik()*(a.DajNazivnik()/r)),static_cast<int>(a.DajNazivnik()*(b.DajNazivnik()/r))};

    }
    friend Razlomak operator *(const Razlomak &a, const Razlomak &b) {
          if(b.brojnik>0 && b.nazivnik>0) {
        if(double(a.brojnik)/a.nazivnik>(LLONG_MAX-double(b.brojnik)/b.nazivnik)) throw std::overflow_error("Nemoguce dobiti tacan rezultat");

    }
    if(b.brojnik<0 || b.nazivnik<0) {
        if(double(a.brojnik)/a.nazivnik<(LLONG_MIN-double(b.brojnik)/b.nazivnik)) throw std::overflow_error("Nemoguce dobiti tacan rezultat");

    }
        long long int s=NZD(a.brojnik, b.nazivnik);
        long long int t=NZD(b.brojnik, a.nazivnik);
            return {static_cast<int>((a.DajBrojnik()/s)*(b.DajBrojnik()/t)),static_cast<int>((a.DajNazivnik()/t)*(b.DajNazivnik()/s))};

    }
    friend Razlomak operator /(const Razlomak &a, const Razlomak &b) {
          if(b.brojnik>0 && b.nazivnik>0) {
        if(double(a.brojnik)/a.nazivnik>(LLONG_MAX-double(b.brojnik)/b.nazivnik)) throw std::overflow_error("Nemoguce dobiti tacan rezultat");

    }
    if(b.brojnik<0 || b.nazivnik<0) {
        if(double(a.brojnik)/a.nazivnik<(LLONG_MIN-double(b.brojnik)/b.nazivnik)) throw std::overflow_error("Nemoguce dobiti tacan rezultat");

    }
        long long int r=NZD(a.nazivnik, b.nazivnik);
        long long int u=NZD(a.brojnik, b.brojnik);
           return {static_cast<int>((a.DajBrojnik()/u)*(b.DajNazivnik()/r)),static_cast<int>((a.DajNazivnik()/r)*(b.DajBrojnik()/u))};

    }
    friend Razlomak operator +(const Razlomak &a) ;
    friend Razlomak operator -(const Razlomak &a) ;
    Razlomak &operator +=(const Razlomak &b) {
        
        long long int r=NZD(nazivnik, b.nazivnik);
        long long int br=brojnik*(b.nazivnik/r)+b.brojnik*(nazivnik/r);
        long long int naz=brojnik*(b.brojnik/r);
        Razlomak s(br, naz);
        brojnik=s.brojnik;
        nazivnik=s.nazivnik;
        return *this;
    }
    Razlomak &operator -=(const Razlomak &b) {
        long long int r=NZD(nazivnik, b.nazivnik);
        long long int br=brojnik*(b.nazivnik/r)-b.brojnik*(nazivnik/r);
        long long int naz=brojnik*(b.brojnik/r);
        Razlomak s(br, naz);
        brojnik=s.brojnik;
        nazivnik=s.nazivnik;
        return *this;
    }
    Razlomak &operator *=(const Razlomak &b) {
        long long int s=NZD(brojnik, b.nazivnik);
        long long int t=NZD(b.brojnik, nazivnik);
        long long int br= (brojnik/s)*(b.brojnik/t);
        long long int naz=(nazivnik/t)*(b.nazivnik/s);
        Razlomak h (br, naz);
        brojnik=h.brojnik;
        nazivnik=h.nazivnik;
        return *this;
    }
    Razlomak &operator /=(const Razlomak &b) {
        long long int r=NZD(nazivnik, b.nazivnik);
        long long int u=NZD(brojnik, b.brojnik);
        long long int br= (brojnik/u)*(b.nazivnik/r);
        long long int naz=(nazivnik/r)*(b.brojnik/u);
        Razlomak s (br, naz);
        brojnik=s.brojnik;
        nazivnik=s.nazivnik;
        return *this;
    }
    friend Razlomak &operator ++(Razlomak &a) {
        Razlomak pom(1);
        Razlomak b=a+pom;
        a.brojnik=b.brojnik;
        a.nazivnik=b.nazivnik;
        return a;
    }
    friend Razlomak operator ++(Razlomak &a, int) {
        Razlomak pom(a);
        Razlomak pom1(1);
        Razlomak b=a+pom;
        a.brojnik=b.brojnik;
        a.nazivnik=b.nazivnik;
        return pom;
    }
    friend Razlomak &operator --(Razlomak &a) {
        Razlomak pom(-1);
        Razlomak b=a+pom;
        a.brojnik=b.brojnik;
        a.nazivnik=b.nazivnik;
        return a;
    }
    friend Razlomak operator --(Razlomak &a, int) {
        Razlomak pom(a);
        Razlomak pom1(-1);
        Razlomak b=a+pom;
        a.brojnik=b.brojnik;
        a.nazivnik=b.nazivnik;
        return pom;
    }
    friend bool operator > (const Razlomak &a, const Razlomak &b) {
        long double r=NZD(a.brojnik, b.brojnik);
        long double s=NZD(a.nazivnik, a.nazivnik);
        if((a.brojnik*r)*(b.nazivnik/s)>(b.brojnik/r)*(a.nazivnik/s)) return true;
        else return false;
    }
    friend bool operator < (const Razlomak &a, const Razlomak &b) {
        long double r=NZD(a.brojnik, b.brojnik);
        long double s=NZD(a.nazivnik, a.nazivnik);
        if((a.brojnik*r)*(b.nazivnik/s)<(b.brojnik/r)*(a.nazivnik/s)) return true;
        else return false;
    }
    friend bool operator <= (const Razlomak &a, const Razlomak &b) {
        long double r=NZD(a.brojnik, b.brojnik);
        long double s=NZD(a.nazivnik, a.nazivnik);
        if((a.brojnik*r)*(b.nazivnik/s)<=(b.brojnik/r)*(a.nazivnik/s)) return true;
        else return false;
    }
    friend bool operator >= (const Razlomak &a, const Razlomak &b){
        long double r=NZD(a.brojnik, b.brojnik);
        long double s=NZD(a.nazivnik, a.nazivnik); 
        if((a.brojnik*r)*(b.nazivnik/s)>=(b.brojnik/r)*(a.nazivnik/s)) return true; 
        else return false; 
    } 
    friend bool operator == (const Razlomak &a, const Razlomak &b){
        long double r=NZD(a.brojnik, b.brojnik);
        long double s=NZD(a.nazivnik, a.nazivnik); 
        if((a.brojnik*r)*(b.nazivnik/s)==(b.brojnik/r)*(a.nazivnik/s)) return true; 
        else return false; 
    } 
    friend bool operator != (const Razlomak &a, const Razlomak &b){
        long double r=NZD(a.brojnik, b.brojnik);
        long double s=NZD(a.nazivnik, a.nazivnik); 
        if((a.brojnik*r)*(b.nazivnik/s)!=(b.brojnik/r)*(a.nazivnik/s)) return true; 
        else return false; 
    } 
    friend  std::ostream &operator <<( std::ostream &tok, const Razlomak &a) {
        if(a.nazivnik==1) tok<<a.brojnik; 
        else {
            tok<<a.brojnik<<"/"<<a.nazivnik; 
        }
        return tok;
    }
  friend std::istream &operator >>(std::istream &tok,  Razlomak &a){ std::cin.ignore(1000, '\n'); 
        char znak; 
        tok>>std::ws; 
        tok>>a.brojnik; 
        a.nazivnik=1;
        
        tok>>std::ws; 
        if(tok.peek()!='/')  tok.setstate(std::ios::failbit); 
        else if(tok.peek()=='/'){ tok>>znak; tok>>a.nazivnik; }
        tok>>std::ws; 
        if(!(tok.peek()>='0' && tok.peek()<='9') ) tok.setstate(std::ios::failbit);
        
        
        //if ( tok.get()!='\n'|| tok.peek()!='\t' || tok.peek()!='\r' || tok.peek()!='\f' || tok.peek()!='\v'|| tok.peek()!=' ')tok.setstate(std::ios::failbit);
       // std::cin.ignore(1000, '\n');
        long long int f=NZD(a.brojnik, a.nazivnik);
        a.brojnik=a.brojnik/f; a.nazivnik=a.nazivnik/f; 
        return tok; 
    }

};
Razlomak operator +(const Razlomak &a)
{
    return a;
}
Razlomak operator -(const Razlomak &a)
{
    return Razlomak (-a.brojnik, a.nazivnik);
}
long long int Razlomak::NZD(long long int x, long long int y)
{
    while(y!=0) {
        long long int p(x);
        x=y;
        y=p%y;
        p=x;
        if(y==0) break;
    }
    return x;
}

Razlomak::Razlomak(std::initializer_list<long long int> lista)
{
    long long int it1=*lista.begin();
    auto it=lista.begin();
    it++;
    long long int it12=(*it);
    if(it12==0) throw std::logic_error("Nekorektan razlomak");
    if(it12<0) {
        it1=it1*(-1);
        it12=it12*(-1);
    }
    long long int a=NZD(it1, it12);
    it1=it1/a;
    it12=it12/a;
    if(lista.size()==0) {
        brojnik=0;
        nazivnik=1;
    }
    if(lista.size()==1)  {
        brojnik=it1;
        nazivnik=1;
    }
    if(lista.size()==2) {
        brojnik=it1;
        nazivnik=it12;
    }
}
Razlomak::Razlomak(long long int b, long long int r) //zasto bne moze biti 0i r1
{
    if(r==0) throw std::logic_error("Nekorektan razlomak");
    if(r<0) {
        b=b*(-1);
        r=r*(-1);
    }
    long long int a=NZD(b,r);
    b=b/a;
    r=r/a;
    brojnik=b;
    nazivnik=r;
}
int main ()
{return 0;
}

