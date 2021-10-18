#include <iostream>
#include <stdexcept>
#include <climits>
#include <cmath>
#define M LLONG_MAX
#define m LLONG_MIN     

class Razlomak {
    long long int brojnik, nazivnik;
    
    long long int static NZD(long long int p, long long int q) { while(q) { long long int x=q; q=p%q; p=x; } return p; }
    static void skrati(long long int &brojnik, long long int &nazivnik) { long long int nzd = NZD(brojnik, nazivnik); brojnik/=nzd; nazivnik/=nzd; }
    static void prekoracenje_zbrajanja(long long int x, long long int y) { if((y>0 && x>M-y) || (y<0 && x<m-y)) throw std::overflow_error("Nemoguce dobiti tacan rezultat"); }
    static void prekoracenje_oduzimanja(long long int x, long long int y) { if((y>0 && x>m-y) || (y<0 && x<M-y)) throw std::overflow_error("Nemoguce dobiti tacan rezultat"); }
    static void prekoracenje_mnozenja(long long int x, long long int y) { if((y>0 && (x<m/y || x>M/y)) || (y<0 && (x==m || -x>M/-y || -x<m/-y) )) throw std::overflow_error("Nemoguce dobiti tacan rezultat"); }
    static bool ProvjeriNaJednakost(long double a,long double b) { long double Eps = 1e-10; if(fabs(a-b) <= Eps * (fabs(a)+fabs(b))) return true; return false; }

    public:
    Razlomak() {brojnik=0; nazivnik=1; }
    Razlomak(long long int brojnik) : brojnik(brojnik), nazivnik(1) {}
    Razlomak(std::initializer_list<long long int>  lista);
    Razlomak(long long int brojnik, long long int nazivnik);
    
    long long int DajBrojnik() const { return brojnik; }
    long long int DajNazivnik() const { return nazivnik; }
    friend Razlomak operator +(Razlomak r1, const Razlomak &r2);
    friend Razlomak operator -(Razlomak r1, const Razlomak &r2);
    friend Razlomak operator *(Razlomak r1, const Razlomak &r2);
    friend Razlomak operator /(Razlomak r1, const Razlomak &r2);

    
    Razlomak operator -() const { return {-brojnik, nazivnik}; }
    Razlomak operator +() const { return {brojnik, nazivnik}; }
    friend Razlomak &operator +=(Razlomak &r1, const Razlomak &r2);
    friend Razlomak &operator -=(Razlomak &r1, const Razlomak &r2);
    friend Razlomak &operator *=(Razlomak &r1, const Razlomak &r2);
    friend Razlomak &operator /=(Razlomak &r1, const Razlomak &r2);
    friend Razlomak &operator ++(Razlomak &r);
    friend Razlomak operator ++(Razlomak &r, int);
    friend Razlomak &operator --(Razlomak &r);
    friend Razlomak operator --(Razlomak &r, int);
    friend bool operator ==(const Razlomak &r1, const Razlomak &r2);
    friend bool operator !=(const Razlomak &r1, const Razlomak &r2);
    friend bool operator <(const Razlomak &r1, const Razlomak &r2);
    friend bool operator >(const Razlomak &r1, const Razlomak &r2);
    friend bool operator <=(const Razlomak &r1, const Razlomak &r2);
    friend bool operator >=(const Razlomak &r1, const Razlomak &r2);
    friend std::istream &operator >>(std::istream &tok, Razlomak &r);
    friend std::ostream &operator <<(std::ostream &tok,const Razlomak &r);
    explicit operator long double() const { return (long double)brojnik/nazivnik; }
};

Razlomak::Razlomak(long long int brojnik, long long int nazivnik) {
        if(nazivnik<0) { nazivnik*=-1; brojnik*=-1; }
        if(nazivnik==0) throw std::logic_error("Nekorektan razlomak");
        
        Razlomak::skrati(brojnik, nazivnik);
        Razlomak::brojnik=brojnik; Razlomak::nazivnik=nazivnik;
} 

Razlomak operator +(Razlomak r1, const Razlomak &r2) {
    Razlomak x;
    x.brojnik = r1.brojnik*(r2.nazivnik/Razlomak::NZD(r1.nazivnik, r2.nazivnik))+r2.brojnik*(r1.nazivnik/Razlomak::NZD(r1.nazivnik, r2.nazivnik)); x.nazivnik = r1.nazivnik*(r2.nazivnik/Razlomak::NZD(r1.nazivnik, r2.nazivnik));
   try{ Razlomak::prekoracenje_zbrajanja(x.brojnik, x.nazivnik); } catch(...) { throw; } 
    Razlomak::skrati(x.brojnik, x.nazivnik);
    if(x.nazivnik<0) { x.nazivnik*=-1; x.brojnik*=-1; }
    return x;
} 
Razlomak operator -(Razlomak r1, const Razlomak &r2) {
    Razlomak x{r1.brojnik*(r2.nazivnik/Razlomak::NZD(r1.nazivnik, r2.nazivnik))-r2.brojnik*(r1.nazivnik/Razlomak::NZD(r1.nazivnik, r2.nazivnik)), r1.nazivnik*(r2.nazivnik/Razlomak::NZD(r1.nazivnik, r2.nazivnik))};
    try{ Razlomak::prekoracenje_oduzimanja(x.brojnik, x.nazivnik); } catch(...) { throw; }
    if(x.nazivnik<0) { x.nazivnik*=-1; x.brojnik*=-1; }
    Razlomak::skrati(x.brojnik, x.nazivnik);
    return x;
} 
Razlomak operator *(Razlomak r1, const Razlomak &r2) {
    Razlomak y{(r1.brojnik/Razlomak::NZD(r1.brojnik, r2.nazivnik))*(r2.brojnik/ Razlomak::NZD(r2.brojnik, r1.nazivnik)), (r1.nazivnik/Razlomak::NZD(r2.brojnik, r1.nazivnik))*(r2.nazivnik/Razlomak::NZD(r1.brojnik, r2.nazivnik))};
    try{ Razlomak::prekoracenje_mnozenja(y.brojnik, y.nazivnik); } catch(...) { throw; }
    Razlomak::skrati(y.brojnik, y.nazivnik);
        if(y.nazivnik<0) { y.nazivnik*=-1; y.brojnik*=-1; }

    return y;
} 
Razlomak operator /(Razlomak r1, const Razlomak &r2) {
    Razlomak x{(r1.brojnik/Razlomak::NZD(r1.brojnik, r2.brojnik))*(r2.nazivnik/Razlomak::NZD(r1.nazivnik, r2.nazivnik)), (r1.nazivnik/Razlomak::NZD(r1.nazivnik, r2.nazivnik))*(r2.brojnik/Razlomak::NZD(r1.brojnik, r2.brojnik))};
    Razlomak::skrati(x.brojnik, x.nazivnik);
        if(x.nazivnik<0) { x.nazivnik*=-1; x.brojnik*=-1; }

    return x;
}

Razlomak::Razlomak(std::initializer_list<long long int>  lista) {
        if(lista.size()==1) { brojnik=*lista.begin(); nazivnik=1; }
        else {
            auto iter1=lista.begin(), iter2=lista.begin()+1;
            if(*iter2==0) throw std::logic_error("Nekorektan razlomak");
            brojnik=*iter1; nazivnik=*iter2;
            Razlomak::skrati(brojnik, nazivnik);
         }
        if(nazivnik<0) { nazivnik*=-1; brojnik*=-1; }
}

Razlomak &operator +=(Razlomak &r1, const Razlomak &r2) {
    Razlomak x;
    x.brojnik = r1.brojnik*(r2.nazivnik/Razlomak::NZD(r1.nazivnik, r2.nazivnik))+r2.brojnik*(r1.nazivnik/Razlomak::NZD(r1.nazivnik, r2.nazivnik)); x.nazivnik = r1.nazivnik*(r2.nazivnik/Razlomak::NZD(r1.nazivnik, r2.nazivnik));
    try{ Razlomak::prekoracenje_zbrajanja(x.brojnik, x.nazivnik); } catch(...) { throw; }
    Razlomak::skrati(x.brojnik, x.nazivnik);
    if(x.nazivnik<0) { x.nazivnik*=-1; x.brojnik*=-1; }

    r1=x;
    return r1;
}
Razlomak &operator *=(Razlomak &r1, const Razlomak &r2) {
     Razlomak y{(r1.brojnik/Razlomak::NZD(r1.brojnik, r2.nazivnik))*(r2.brojnik/ Razlomak::NZD(r2.brojnik, r1.nazivnik)), (r1.nazivnik/Razlomak::NZD(r2.brojnik, r1.nazivnik))*(r2.nazivnik/Razlomak::NZD(r1.brojnik, r2.nazivnik))};
    try{ Razlomak::prekoracenje_mnozenja(y.brojnik, y.nazivnik); } catch(...) { throw; }
    Razlomak::skrati(y.brojnik, y.nazivnik);
        if(y.nazivnik<0) { y.nazivnik*=-1; y.brojnik*=-1; }

    r1=y;
    return r1;
}
Razlomak &operator -=(Razlomak &r1, const Razlomak &r2) {
     Razlomak x{r1.brojnik*(r2.nazivnik/Razlomak::NZD(r1.nazivnik, r2.nazivnik))-r2.brojnik*(r1.nazivnik/Razlomak::NZD(r1.nazivnik, r2.nazivnik)), r1.nazivnik*(r2.nazivnik/Razlomak::NZD(r1.nazivnik, r2.nazivnik))};
    try{ Razlomak::prekoracenje_oduzimanja(x.brojnik, x.nazivnik); } catch(...) { throw; }
    if(x.nazivnik<0) { x.nazivnik*=-1; x.brojnik*=-1; }
    Razlomak::skrati(x.brojnik, x.nazivnik);
        if(x.nazivnik<0) { x.nazivnik*=-1; x.brojnik*=-1; }

    r1=x;
    return r1;
}
Razlomak &operator /=(Razlomak &r1, const Razlomak &r2) {
        Razlomak x{r1.brojnik/Razlomak::NZD(r1.brojnik, r2.brojnik)*(r2.nazivnik/Razlomak::NZD(r1.nazivnik, r2.nazivnik)), (r1.nazivnik/Razlomak::NZD(r1.nazivnik, r2.nazivnik))};
    Razlomak::skrati(x.brojnik, x.nazivnik);
        if(x.nazivnik<0) { x.nazivnik*=-1; x.brojnik*=-1; }

    r1=x;
    return r1;
}

Razlomak &operator ++(Razlomak &r) {
    r.brojnik+=1; 
    try{ Razlomak::prekoracenje_zbrajanja(r.brojnik, r.nazivnik); } catch(...) { throw; }
    Razlomak::skrati(r.brojnik, r.nazivnik);
    return r;
}
Razlomak &operator --(Razlomak &r) {
    r.brojnik-=1;
    try{ Razlomak::prekoracenje_oduzimanja(r.brojnik, r.nazivnik); } catch(...) { throw; }
    Razlomak::skrati(r.brojnik, r.nazivnik);
    return r;
}

Razlomak operator ++(Razlomak &r, int) {
    Razlomak pom(r); ++r; return pom;
}
Razlomak operator --(Razlomak &r, int) {
    Razlomak pom(r); --r; return pom;
}

bool operator ==(const Razlomak &r1, const Razlomak &r2) {
    long double x = (long double)r1.brojnik/r2.brojnik, y = (long double)r1.nazivnik/r2.nazivnik;
    if(Razlomak::ProvjeriNaJednakost(x,y)) return true;
    return false;
}
bool operator !=(const Razlomak &r1, const Razlomak &r2) {
    long double x = (long double)r1.brojnik/r2.brojnik, y = (long double)r1.nazivnik/r2.nazivnik;
    if(!Razlomak::ProvjeriNaJednakost(x,y)) return true;
    return false;
}
    
bool operator <(const Razlomak &r1, const Razlomak &r2) {
    return (long double) r1.brojnik/r1.nazivnik<(long double)r2.brojnik/r2.nazivnik;
}
bool operator >(const Razlomak &r1, const Razlomak &r2) {
    return (long double)r1.brojnik/r1.nazivnik>(long double)r2.brojnik/r2.nazivnik;
}

bool operator <=(const Razlomak &r1, const Razlomak &r2) {
    long double x = (long double)r1.brojnik/r1.nazivnik, y = (long double)r1.nazivnik/r2.nazivnik;
    if(x<y || Razlomak::ProvjeriNaJednakost(x,y)) return true;
    return false;
}
bool operator >=(const Razlomak &r1, const Razlomak &r2) {
    long double x = (long double)r1.brojnik/r1.nazivnik, y = (long double)r1.nazivnik/r2.nazivnik;
    if(x>y || Razlomak::ProvjeriNaJednakost(x,y)) return true;
    return false;
}
  

std::ostream &operator << (std::ostream &tok,const Razlomak &r) {
    if(r.nazivnik==1) { tok << r.brojnik; return tok; }
    tok << r.brojnik << "/" << r.nazivnik;
    return tok;
}
std::istream &operator >> (std::istream &tok, Razlomak &r) {
    char znak;
    
    tok >> std::ws;
    tok >> r.brojnik;
    if(tok.peek()!='/') { r.nazivnik=1; return tok; }
    tok >> znak;
   // if(znak!='/') tok.setstate(std::ios::failbit);
    tok >> r.nazivnik; 
    if(tok.peek()!=' ' && tok.peek()!='\n' && tok.peek()!='\t' && tok.peek()!='\v' && tok.peek()!='\f') tok.setstate(std::ios::failbit);
    long long int nzd = Razlomak::NZD(r.brojnik, r.nazivnik);
    r.brojnik/=nzd; r.nazivnik/=nzd;
    return tok;
}

int main () {
    Razlomak a{21,37}, b, c(23);
    std::cin >> b;
    std::cout << "razlomak b je jednak: " << b << std::endl;
    a=a+b; std::cout << a << std::endl;
    c=c-b; std::cout << c << std::endl;
    b=c*a; std::cout << b << std::endl;
    a=c/b; std::cout << a << std::endl;
    b+=c; std::cout << b << std::endl;
    c-=a; std::cout << c << std::endl;
    a*=b; std::cout << a << std::endl;
    b/=a; std::cout << b << std::endl;
    if(a>b) std::cout << "vece je a" << std::endl;
    if(a<b) std::cout << "manje  je a" << std::endl;
    if(a==c) std::cout << "isti su" << std::endl;
    if(b!=c) std::cout << "razliciti su" << std::endl;
    std::cout << -b << std::endl;
    std::cout << "Pretvorba " << static_cast<long double>(a);
  //std::cin >> a >> b;
  
  	return 0;
} 







