#include <iostream>
#include <cmath>
#include <stdexcept>
#include <limits>
#include <sstream>

#define eps 1E-10

class Razlomak {
    long long int brojnik, nazivnik;
    static long long int NZD(long long int a, long long int b) { if(b==0) return a; return NZD(b, a%b); }
    static long long int Sabiranje(long long int a, long long int b) { 
        if((b>0 && a>(std::numeric_limits<long long int>::max()-b)) || (b<0 && a<(std::numeric_limits<long long int>::lowest()-b))) throw std::overflow_error("Nemoguce dobiti tacan rezultat"); 
        return a+b;
    }
    static long long int Mnozenje(long long int a, long long int b) {
        bool s=false;
        if(b>0 && (a<(std::numeric_limits<long long int>::lowest()/b) || a>(std::numeric_limits<long long int>::max()/b))) s=true;
        else if(b<0 && (a==std::numeric_limits<long long int>::lowest() || (-1*a)>(std::numeric_limits<long long int>::max()/(-1*b)) || (-1*a)<(std::numeric_limits<long long int>::lowest()/(-1*b)))) s=true;
        if(s) throw std::overflow_error("Nemoguce dobiti tacan rezultat");
        return a*b;
    }
public:
    Razlomak(long long int a=0, long long int b=1);
    long long int DajBrojnik() const { return brojnik; }
    long long int DajNazivnik() const { return nazivnik; }
    
    Razlomak& operator +=(const Razlomak &drugi) { return *this=*this+drugi; }
    Razlomak& operator -=(const Razlomak &drugi) { return *this=*this-drugi; }
    Razlomak& operator *=(const Razlomak &drugi) { return *this=*this*drugi; }
    Razlomak& operator /=(const Razlomak &drugi) { return *this=*this/drugi; }
    
    Razlomak& operator ++() { return *this+=1; }
    Razlomak& operator --() { return *this-=1; }
    Razlomak operator ++(int) { auto pomocna(*this); *this+=1; return pomocna; }
    Razlomak operator --(int) { auto pomocna(*this); *this-=1; return pomocna; }
    
    friend Razlomak operator +(const Razlomak &a, const Razlomak &b);
    friend Razlomak operator -(const Razlomak &a, const Razlomak &b);
    friend Razlomak operator *(const Razlomak &a, const Razlomak &b);
    friend Razlomak operator /(const Razlomak &a, const Razlomak &b);
    friend Razlomak operator +(const Razlomak &a);
    friend Razlomak operator -(const Razlomak &a);
    
    friend bool operator <(const Razlomak &a, const Razlomak &b) { long double x=a.brojnik/a.nazivnik, y=b.brojnik/b.nazivnik; return x<y; }
    friend bool operator <=(const Razlomak &a, const Razlomak &b) { return a<b || (a.brojnik==b.brojnik && a.nazivnik==b.nazivnik); }
    friend bool operator >(const Razlomak &a, const Razlomak &b) { return !(a<=b); }
    friend bool operator >=(const Razlomak &a, const Razlomak &b) { return !(a<b); }
    
    friend std::ostream& operator <<(std::ostream &tok, const Razlomak &a) { tok << a.brojnik; if(a.nazivnik!=1) tok << "/" << a.nazivnik; return tok; }
    friend std::istream& operator >>(std::istream &tok, Razlomak &a);
    
    operator long double() { return brojnik/nazivnik; }
};

Razlomak::Razlomak(long long int a, long long int b) {
    if(b<0) { b*=-1; a*=-1; }
    else if(fabs(b)<eps) throw std::logic_error("Nekorektan razlomak");
    long long int p=NZD(a, b);
    brojnik=a/=p; nazivnik=b/=p;
}

Razlomak operator +(const Razlomak &a, const Razlomak &b) {
    long long int r=Razlomak::NZD(a.nazivnik, b.nazivnik);
    long long int prvi=b.nazivnik/r, drugi=a.nazivnik/r;
    return Razlomak(Razlomak::Sabiranje(Razlomak::Mnozenje(a.brojnik,prvi),Razlomak::Mnozenje(b.brojnik,drugi)), Razlomak::Mnozenje(a.nazivnik,prvi));
}
Razlomak operator -(const Razlomak &a, const Razlomak &b) { return a+(-b); }
Razlomak operator *(const Razlomak &a, const Razlomak &b) {
    long long int s=Razlomak::NZD(a.brojnik, b.nazivnik), t=Razlomak::NZD(b.brojnik, a.nazivnik);
    return Razlomak(Razlomak::Mnozenje(a.brojnik/s, b.brojnik/t),Razlomak::Mnozenje(a.nazivnik/t, b.nazivnik/s));
}
Razlomak operator /(const Razlomak &a, const Razlomak &b) {
    long long int r=Razlomak::NZD(a.nazivnik, b.nazivnik), u=Razlomak::NZD(a.brojnik, b.brojnik);
    return Razlomak(Razlomak::Mnozenje(a.brojnik/u, b.nazivnik/r), Razlomak::Mnozenje(a.nazivnik/r, b.brojnik/u));
}

Razlomak operator +(const Razlomak &a) { return a; }
Razlomak operator -(const Razlomak &a) { return Razlomak(Razlomak::Mnozenje(a.DajBrojnik(),-1), a.DajNazivnik()); }

bool DaLiJeBjelina(char c) {
    if(c=='\n' || c=='\t' || c=='\f' || c=='\v' || c==' ') return true;
    return false;
}

std::istream& operator >>(std::istream &tok, Razlomak &a) {
    tok >> std::ws; char c; long long int x, y;
    tok >> x;
    if(tok.peek()=='/') tok >> c >> y;
    else y=1;
    if(!DaLiJeBjelina(tok.peek())) tok.setstate(std::ios::failbit);
    a=Razlomak(x, y);
    return tok;
}

int main() {
    Razlomak x(4,5); std::cout << x;
    std::cin >> x; std::cout << x;
}