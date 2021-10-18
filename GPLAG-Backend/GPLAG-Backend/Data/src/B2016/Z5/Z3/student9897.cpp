/B16/17 (Zadaća 5, Zadatak 3)
//Autotestovi by Enil Pajic (mail: epajic1@etf.unsa.ba)
//Za autotestove se obracati *iskljucivo* osobi koja ih pise
#include <iostream>
#include <stdexcept>
#include <initializer_list>
#include <limits>

class Razlomak {
    
    long long int brojnik; 
    long long int nazivnik; 
    
    static long long int NZD(long long int p, long long int q) {
        if (q==0) return p; 
        p=p%q; 
        return NZD(q,p); 
    }
    public: 
    
    Razlomak (long long int brojnik, long long int nazivnik) {
        
        if (nazivnik==0) throw std::logic_error ("Nekorektan razlomak"); 
        if ((brojnik>0 && nazivnik<0) || (brojnik<0 && nazivnik<0)) { brojnik=-brojnik; nazivnik=-nazivnik; }
        long long int nzd=NZD(brojnik, nazivnik); 
        
        Razlomak::brojnik=brojnik/nzd; Razlomak::nazivnik=nazivnik/nzd; 
    }
    
    Razlomak(std::initializer_list<long long int> lista) {
        if (nazivnik==0) throw std::logic_error ("Nekorektan razlomak"); 
         if ((brojnik>0 && nazivnik<0) || (brojnik<0 && nazivnik<0)) { brojnik=-brojnik; nazivnik=-nazivnik; }
        long long int nzd=NZD(brojnik, nazivnik); 
        
        Razlomak::brojnik=brojnik/nzd; Razlomak::nazivnik=nazivnik/nzd; 
    }
    
    Razlomak (long long int brojnik) {
      Razlomak::nazivnik=1; Razlomak::brojnik=brojnik/nazivnik; 
    }
    Razlomak() { Razlomak::brojnik=0; Razlomak::nazivnik=1; }
    
    long long int DajBrojnik() const { return brojnik; } 
    long long int DajNazivnik() const { return nazivnik; }
    
    friend Razlomak operator +(const Razlomak &r1, const Razlomak &r2); 
    friend Razlomak operator -(const Razlomak &r1, const Razlomak &r2); 
    friend Razlomak operator *(const Razlomak &r1, const Razlomak &r2); 
    friend Razlomak operator /(const Razlomak &r1, const Razlomak &r2); 
    
    friend Razlomak operator +(const Razlomak &r) { return r; }
    friend Razlomak operator -(const Razlomak &r);
    
    friend Razlomak &operator +=(Razlomak &r1, const Razlomak &r2);
    friend Razlomak &operator -=(Razlomak &r1, const Razlomak &r2); 
    friend Razlomak &operator *=(Razlomak &r1, const Razlomak &r2); 
    friend Razlomak &operator /=(Razlomak &r1, const Razlomak &r2); 
    
    friend Razlomak operator ++(Razlomak &r); 
    friend Razlomak operator ++(Razlomak &r, int); 
    friend Razlomak operator --(Razlomak &r); 
    friend Razlomak operator --(Razlomak &r, int); 
    
    friend bool operator <(const Razlomak &r1, const Razlomak &r2); 
    friend bool operator >(const Razlomak &r1, const Razlomak &r2); 
    friend bool operator <=(const Razlomak &r1, const Razlomak &r2); 
    friend bool operator >=(const Razlomak &r1, const Razlomak &r2); 
    friend bool operator ==(const Razlomak &r1, const Razlomak &r2); 
    friend bool operator !=(const Razlomak &r1, const Razlomak &r2); 
    
    friend std::ostream &operator <<(std::ostream &tok, const Razlomak &r); 
    friend std::istream &operator >>(std::istream &tok, Razlomak &r); 
    
    operator long double () const; 
}; 

Razlomak::operator long double() const {
    long double a=brojnik/nazivnik; 
    return a; 
}

bool operator !=(const Razlomak &r1, const Razlomak &r2) {
    long double a=r1.brojnik/r1.nazivnik;
    long double b=r2.brojnik/r2.nazivnik; 
    return !((a-b)<0.0001); 
}

bool operator ==(const Razlomak &r1, const Razlomak &r2) {
    long double a=r1.brojnik/r2.nazivnik; 
    long double b=r2.brojnik/r2.nazivnik; 
    return (a-b)<0.0001; 
}

bool operator >=(const Razlomak &r1, const Razlomak &r2) {
    long double a=r1.brojnik/r1.nazivnik; 
    long double b=r2.brojnik/r2.nazivnik; 
    return a>=b; 
}

bool operator >(const Razlomak &r1, const Razlomak &r2) {
    long double a=r1.brojnik/r1.nazivnik; 
    long double b=r2.brojnik/r2.nazivnik; 
    return a>b; 
}

bool operator <=(const Razlomak &r1, const Razlomak &r2) {
    long double a=r1.brojnik/r1.nazivnik; 
    long double b=r2.brojnik/r2.nazivnik; 
    return a<=b; 
}

bool operator <(const Razlomak &r1, const Razlomak &r2) {
    long double a=r1.brojnik/r1.nazivnik; 
    long double b=r2.brojnik/r2.nazivnik; 
    return a<b; 
}

Razlomak operator ++(Razlomak &r) {
    r+=1; 
    return r; 
}

Razlomak operator ++(Razlomak &r, int) {
    Razlomak pomocni(r); 
    r+=1; 
    return pomocni; 
}

Razlomak operator --(Razlomak &r, int) {
    Razlomak pomocni(r); 
    r-=1; 
    return pomocni; 
}

Razlomak operator --(Razlomak &r) {
    r-=1; 
    return r; 
}

std::istream &operator >>(std::istream &tok, Razlomak &r) {
    
    long long int nzd=Razlomak::NZD(r.brojnik, r.nazivnik); 
    r.brojnik=r.brojnik/nzd; r.nazivnik=r.nazivnik/nzd; 
    char znak; 
    tok >> std::ws; 
    
    tok >> r.brojnik;
    if (tok.peek() == ' ') return tok; 
    else {
    
    tok >> znak; if (znak != '/') tok.setstate(std::ios::failbit); 
    tok >> r.nazivnik; 
    }
 
    tok >> std::ws; 

    return tok; 
}

std::ostream &operator <<(std::ostream &tok, const Razlomak &r) {
    if (r.nazivnik==1) tok << r.brojnik; 
    else tok << r.brojnik << "/" << r.nazivnik; 
    return tok;
}

Razlomak &operator /=(Razlomak &r1, const Razlomak &r2) {
    long long int u(Razlomak::NZD(r1.brojnik, r2.brojnik));  
    long long int r(Razlomak::NZD(r1.nazivnik, r2.nazivnik)); 
    
    r1.brojnik=(r1.brojnik/u)*(r2.nazivnik/r); 
    r1.nazivnik=(r1.nazivnik/r)*(r2.brojnik/u);
    long long int nzd=Razlomak::NZD(r1.brojnik, r1.nazivnik); 
    r1.brojnik=r1.brojnik/nzd; r1.nazivnik=r1.nazivnik/nzd; 
    
    return r1; 
}

Razlomak &operator *=(Razlomak &r1, const Razlomak &r2) {
    long long int t(Razlomak::NZD(r2.brojnik, r1.nazivnik)); 
    long long int s(Razlomak::NZD(r1.brojnik, r2.nazivnik)); 
    r1.brojnik=(r1.brojnik/s)*(r2.brojnik/t);
    r1.nazivnik=(r1.nazivnik/t)*(r2.nazivnik/s); 
    
    long long int nzd=Razlomak::NZD(r1.brojnik, r1.nazivnik);
    r1.brojnik=r1.brojnik/nzd; r1.nazivnik=r1.nazivnik/nzd; 
    
    return r1; 
}

Razlomak &operator -=(Razlomak &r1, const Razlomak &r2) {
    long long int r(Razlomak::NZD(r1.nazivnik, r2.nazivnik)); 
    r1.brojnik=r1.brojnik*(r2.brojnik/r)-r2.brojnik*(r1.nazivnik/r); 
    r1.nazivnik=r1.nazivnik*(r2.nazivnik/r); 
    
    long long int nzd=Razlomak::NZD(r1.brojnik, r1.nazivnik); 
    r1.brojnik=r1.brojnik/nzd; r1.nazivnik=r1.nazivnik/nzd; 
    return r1; 
}

Razlomak &operator +=(Razlomak &r1, const Razlomak &r2) {
    long long int r(Razlomak::NZD(r1.nazivnik, r2.nazivnik)); 
    r1.brojnik=r1.brojnik*(r2.brojnik/r)+r2.brojnik*(r1.nazivnik/r); 
    r1.nazivnik=r1.nazivnik*(r2.nazivnik/r);
    
    long long int nzd=Razlomak::NZD(r1.brojnik, r1.nazivnik); 
    r1.brojnik=r1.brojnik/nzd; r1.nazivnik=r1.nazivnik/nzd; 
    return r1; 
}

Razlomak operator -(const Razlomak &r) {
     long long int m=std::numeric_limits<long long int>::min(); 
     
     Razlomak r1; 
     r1.brojnik=-r.brojnik; 
     if (r1.brojnik/r1.nazivnik<m) throw std::overflow_error ("Nemoguce dobiti tacan rezultat");
     return r1; 
}

Razlomak operator /(const Razlomak &r1, const Razlomak &r2) {
    long long int u(Razlomak::NZD(r1.brojnik, r2.brojnik));
    long long int r(Razlomak::NZD(r1.nazivnik, r2.nazivnik)); 
    Razlomak r3; 
    r3.brojnik=(r1.brojnik/u)*(r2.nazivnik/r); 
    r3.nazivnik=(r1.nazivnik/r)*(r2.brojnik/u);
    long long int nzd=Razlomak::NZD(r3.brojnik, r3.nazivnik); 
    r3.brojnik=r3.brojnik/nzd; 
    r3.nazivnik=r3.nazivnik/nzd; 
    return r3;
}

Razlomak operator *(const Razlomak &r1, const Razlomak &r2) {
    long long int M=std::numeric_limits<long long int>::max(); 
    long long int m=std::numeric_limits<long long int>::min(); 
    
    if ((r2.brojnik/r2.nazivnik)>0) { 
        if ((r1.brojnik/r1.nazivnik)<m/(r2.brojnik/r2.nazivnik) || (r1.brojnik/r1.nazivnik)>M/(r2.brojnik/r2.nazivnik)) 
        throw std::overflow_error ("Nemoguce dobiti tacan rezultat"); 
    }
    else {
        if ((r1.brojnik/r1.nazivnik)==m)
        throw std::overflow_error ("Nemoguce dobiti tacan rezultat");
    }
    
    long long int t(Razlomak::NZD(r2.brojnik, r1.nazivnik)); 
    long long int s(Razlomak::NZD(r1.brojnik, r2.nazivnik)); 
    Razlomak r3; 
    r3.brojnik=(r1.brojnik/s)*(r2.brojnik/t); 
    r3.nazivnik=(r1.nazivnik/t)*(r2.nazivnik/s); 
    long long int nzd=Razlomak::NZD(r3.brojnik, r3.nazivnik); 
    r3.brojnik=r3.brojnik/nzd;
    r3.nazivnik=r3.nazivnik/nzd; 
    return r3;
}

Razlomak operator+(const Razlomak &r1, const Razlomak &r2) {
    long long int M=std::numeric_limits<long long int>::max(); 
    if ((r1.brojnik/r1.nazivnik)>M-(r2.brojnik/r2.nazivnik)) 
    throw std::overflow_error ("Nemoguce dobiti tacan rezultat"); 
    
    long long int r(Razlomak::NZD(r1.nazivnik, r2.nazivnik));
    Razlomak r3; 
    r3.brojnik=(r1.brojnik*(r2.nazivnik/r)+r2.brojnik*(r1.nazivnik/r));
    r3.nazivnik=(r1.nazivnik*(r2.nazivnik/r)); 
    long long int nzd=Razlomak::NZD(r3.brojnik, r3.nazivnik); 
    r3.brojnik=r3.brojnik/nzd; 
    r3.nazivnik=r3.nazivnik/nzd; 
    return r3; 
}

Razlomak operator -(const Razlomak &r1, const Razlomak &r2) {
    long long int m=std::numeric_limits<long long int>::min(); 
    if ((r1.brojnik/r1.nazivnik)<m-(r2.brojnik/r2.nazivnik)) 
    throw std::overflow_error ("Nemoguce dobiti tacan rezultat"); 
    
    long long int r(Razlomak::NZD(r1.nazivnik, r2.nazivnik)); 
    Razlomak r3; 
    r3.brojnik=(r1.brojnik*(r2.nazivnik/r)-r2.brojnik*(r1.nazivnik/r)); 
    r3.nazivnik=(r1.nazivnik*(r2.nazivnik/r));
    long long int nzd=Razlomak::NZD(r3.brojnik, r3.nazivnik); 
    r3.brojnik=r3.brojnik/nzd; 
    r3.nazivnik=r3.nazivnik/nzd; 
    return r3; 
}

int main ()
{
    Razlomak r1(1,2), r2(2,3); 
    
    std::cout << r1+r2 << " " << r1-r2 << " " << r1*r2 << " " << r1/r2; 
    std::cout << std::endl; 
    
    r1++; 
    r2--; 
    
    r1+=r2;
    std::cout << r1;  
    
    r1*=r2; 
    std::cout << std::endl << r1; 
    
    r1/=r2; 
    std::cout << std::endl << r1; 
    
    r1-=r2; 
    std::cout << std::endl << r1; 

	return 0;
}