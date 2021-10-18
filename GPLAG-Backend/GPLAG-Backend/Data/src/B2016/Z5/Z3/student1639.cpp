#include <iostream>
#include <cmath>
#include <stdexcept>

#define EPS 0.0000000000000000000000000000000001

// TESTIRAJ OPERATORE NA OVERFLOW (i konstruktore)

using namespace std;

class Razlomak {
    long long int brojnik, nazivnik;
    
    void SkratiRazlomak (long long int& brojnik, long long int& nazivnik);
    public:
    
    Razlomak(long long int brojnik = 0, long long int nazivnik = 1) {
        if(nazivnik==0) throw logic_error("Nekorektan razlomak");
        if(nazivnik<0) { // ako je minus dolje
            Razlomak::nazivnik=abs(nazivnik);
            Razlomak::brojnik=-brojnik;
        }
        
        if(nazivnik<0 and brojnik<0) { // oba negativna
            Razlomak::nazivnik=abs(nazivnik);
            Razlomak::brojnik=abs(brojnik);
        }
        
         Razlomak::brojnik=brojnik;
         Razlomak::nazivnik=nazivnik;
         SkratiRazlomak(brojnik,nazivnik);
    }
    
    long long int DajNazivnik() const { return nazivnik;}
    long long int DajBrojnik() const { return brojnik;}
    
    friend long long int NZD (long long int brojnik, long long int nazivnik);
    friend ostream& operator<< (ostream& tok, const Razlomak& r);
    friend istream& operator>> (istream& tok, Razlomak& r);
    friend Razlomak operator+ (const Razlomak& r1, const Razlomak& r2);
    friend Razlomak operator- (const Razlomak& r1, const Razlomak& r2);
    friend Razlomak operator* (const Razlomak& r1, const Razlomak& r2);
    friend Razlomak operator/ (const Razlomak& r1, const Razlomak& r2);
    friend bool operator< (const Razlomak& r1, const Razlomak& r2);
    friend bool operator> (const Razlomak& r1, const Razlomak& r2);
    friend bool operator<= (const Razlomak& r1, const Razlomak& r2);
    friend bool operator>= (const Razlomak& r1, const Razlomak& r2);
    friend bool operator== (const Razlomak& r1, const Razlomak& r2);
    friend bool operator!= (const Razlomak& r1, const Razlomak& r2);
    friend Razlomak operator++ (const Razlomak& r, int);
    friend Razlomak operator-- (const Razlomak& r, int);
    friend Razlomak operator++ (const Razlomak& r);
    friend Razlomak operator-- (const Razlomak& r);
    friend Razlomak operator- (const Razlomak& r);
    friend Razlomak operator+ (const Razlomak& r);
    operator long double();
   
};

Razlomak::operator long double () {
    return (long double) brojnik/nazivnik;
}

long long int NZD (long long int p, long long int q) {
    if(q==0) return p;
    return NZD(q,p%q);
} 


void Razlomak::SkratiRazlomak (long long int& brojnik, long long int& nazivnik) {
    long long int a;
    while((a=NZD(brojnik,nazivnik))!=1) {
        nazivnik/=a;
        brojnik/=a;
    }
}

Razlomak operator+ (const Razlomak& r1, const Razlomak& r2) {
    Razlomak r3;
    long long int r(NZD(r1.DajNazivnik(), r2.DajNazivnik())); 
    r3.brojnik=r1.brojnik*(r2.nazivnik/r)+r2.brojnik*(r1.nazivnik/r);
    r3.nazivnik=r1.nazivnik*(r2.nazivnik/r);
    
    
    r3.SkratiRazlomak(r3.brojnik, r3.nazivnik);
    return r3;
}


Razlomak operator- (const Razlomak& r1, const Razlomak& r2) {
    Razlomak r3;
    long long int r(NZD(r1.DajNazivnik(), r2.DajNazivnik())); 
    r3.brojnik=r1.brojnik*(r2.nazivnik/r)-r2.brojnik*(r1.nazivnik/r);
    r3.nazivnik=r1.nazivnik*(r2.nazivnik/r);
     r3.SkratiRazlomak(r3.brojnik, r3.nazivnik);
    return r3;
}

Razlomak operator* (const Razlomak& r1, const Razlomak& r2) {
    Razlomak r3;
    long long int s(NZD(r1.brojnik,r2.nazivnik)), t(NZD(r2.brojnik, r1.nazivnik));
    r3.brojnik=(r1.brojnik/s)*(r2.brojnik/t);
    r3.nazivnik=(r1.nazivnik/t)*(r2.nazivnik/s);
     r3.SkratiRazlomak(r3.brojnik, r3.nazivnik);
    return r3;
}

Razlomak operator/ (const Razlomak& r1, const Razlomak& r2) {
    Razlomak r3;
    long long int r(NZD(r1.DajNazivnik(), r2.DajNazivnik())), u(NZD(r1.brojnik,r1.brojnik));
    r3.brojnik=(r1.brojnik/u)*(r2.nazivnik/r);
     r3.SkratiRazlomak(r3.brojnik, r3.nazivnik);
    return r3;
}

Razlomak operator++ (const Razlomak& r) {
    Razlomak novi;
    novi.brojnik=r.brojnik+r.nazivnik;
    novi.nazivnik=r.nazivnik;
    novi.SkratiRazlomak(novi.brojnik, novi.nazivnik);
    return novi;
}

Razlomak operator-- (const Razlomak& r) {
    Razlomak novi;
    novi.brojnik=r.brojnik-r.nazivnik;
    novi.nazivnik=r.nazivnik;
    novi.SkratiRazlomak(novi.brojnik, novi.nazivnik);
    return novi;
}

Razlomak operator++ (const Razlomak& r, int) {
    Razlomak novi;
    novi.brojnik=r.brojnik+r.nazivnik;
    novi.nazivnik=r.nazivnik;
    return novi;
}

Razlomak operator-- (const Razlomak& r, int) {
    Razlomak novi;
    novi.brojnik=r.brojnik-r.nazivnik;
    novi.nazivnik=r.nazivnik;
    return novi;
}

bool operator< (const Razlomak& r1, const Razlomak& r2) {
    return r1.brojnik/r1.nazivnik < r2.brojnik/r2.nazivnik;
}
bool operator> (const Razlomak& r1, const Razlomak& r2) {
    return r1.brojnik/r1.nazivnik > r2.brojnik/r2.nazivnik;
}
bool operator<= (const Razlomak& r1, const Razlomak& r2) {
    return r1.brojnik/r1.nazivnik <= r2.brojnik/r2.nazivnik;
}
bool operator>= (const Razlomak& r1, const Razlomak& r2) {
    return r1.brojnik/r1.nazivnik >= r2.brojnik/r2.nazivnik;
}
bool operator== (const Razlomak& r1, const Razlomak& r2) {
    return (r1.brojnik/r1.nazivnik)-(r2.brojnik/r2.nazivnik) < EPS;
}
bool operator!= (const Razlomak& r1, const Razlomak& r2) {
    return (r1.brojnik/r1.nazivnik)-(r2.brojnik/r2.nazivnik) > EPS;
}

Razlomak operator- (const Razlomak& r) {
    Razlomak novi;
    novi.brojnik=-r.brojnik;
    novi.nazivnik=-r.nazivnik;
    return novi;
}

Razlomak operator+ (const Razlomak& r) {
    return r;
}

ostream& operator<< (ostream& tok, const Razlomak& r) {
        tok << r.brojnik;
        if(r.nazivnik!=1) tok << "/" << r.nazivnik;
    
        return tok;
    }
    
istream& operator>> (istream& tok, Razlomak& r) {
        int znak;
        tok >> r.brojnik;
        znak = tok.peek();
        if ( znak != '\r' && znak != '\n' && znak != ' ' && znak != EOF ) {
            char c;
            tok>>c;
            znak = c;
            if ( znak == '/' ) tok >> r.nazivnik;
            else r.nazivnik = 1;
        } else 
            r.nazivnik = 1;
            
        znak = tok.peek();
        if ( znak != EOF && znak != '\n' && znak != ' ' && znak != '\r' ) {
            tok.setstate(ios::failbit);
        }
        
        //ako treba skratiti ovdje...
        r.SkratiRazlomak(r.brojnik, r.nazivnik);
        return tok;
}

int main ()
{  Razlomak r (17, 18), t (21), v;
            std::cout << "r = " << r << ", t = " << t << ", v = " << v;
              std::cout <<" " << r << " je priblizno " << static_cast<long double>(r);
	return 0;
}