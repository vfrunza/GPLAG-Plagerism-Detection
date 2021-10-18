/B16/17 (Zadaća 5, Zadatak 3)
//Autotestovi by Enil Pajic (mail: epajic1@etf.unsa.ba)
//Za autotestove se obracati *iskljucivo* osobi koja ih pise
#include <iostream>
#include <stdexcept>
#include <cmath>
#include <limits>

const long long int M(std::numeric_limits<long long int>::max());
const long long int m(std::numeric_limits<long long int>::min());

class Razlomak {
    long long int brojnik, nazivnik;
    static long long int NZD(long long int a, long long int b) {
        if (b==0) return a;
        return NZD(b,a%b);
    }
    static bool JesuLiJednaki(long double x, long double y, long double Eps=1e-10) {
        if ((x<0 && y>0) || (x>0 && y<0)) return false;
        return std::fabs(x-y)<=Eps*(std::fabs(x)+std::fabs(y));
    }
    static bool TestPrekoracenjaZaSabiranje(long long int x, long long int y) {
        if ((y>0 && x>M-y) || (y<0 && x<m-y)) return true;
        return false;
    }
    static bool TestPrekoracenjaZaOduzimanje(long long int x, long long int y) {
        if ((y>0 && x<m+y) || (y<0 && x>M+y)) return true;
        return false;
    }
    static bool TestPrekoracenjaZaMnozenje(long long int x, long long int y) {
        if ((y>0 && (x<m/y || x>M/y)) || (y<0 && (x==m || (-x)>M/(-y) || (-x)<m/(-y)))) return true;
        return false;
    }
public:
    Razlomak(long long int b=0, long long int n=1);
    long long int DajBrojnik() const { return brojnik; }
    long long int DajNazivnik() const { return nazivnik; }
    friend Razlomak operator +(const Razlomak &r1, const Razlomak &r2);
    friend Razlomak operator -(const Razlomak &r1, const Razlomak &r2);
    friend Razlomak operator *(const Razlomak &r1, const Razlomak &r2);
    friend Razlomak operator /(const Razlomak &r1, const Razlomak &r2);
    friend Razlomak operator +(const Razlomak &r);
    friend Razlomak operator -(const Razlomak &r);
    friend Razlomak &operator +=(Razlomak &r1, const Razlomak &r2);
    friend Razlomak &operator -=(Razlomak &r1, const Razlomak &r2);
    friend Razlomak &operator *=(Razlomak &r1, const Razlomak &r2);
    friend Razlomak &operator /=(Razlomak &r1, const Razlomak &r2);
    friend Razlomak &operator ++(Razlomak &r);
    friend Razlomak operator ++(Razlomak &r, int);
    friend Razlomak &operator --(Razlomak &r);
    friend Razlomak operator --(Razlomak &r, int);
    friend bool operator <(const Razlomak &r1, const Razlomak &r2);
    friend bool operator >(const Razlomak &r1, const Razlomak &r2);
    friend bool operator <=(const Razlomak &r1, const Razlomak &r2);
    friend bool operator >=(const Razlomak &r1, const Razlomak &r2);
    friend bool operator ==(const Razlomak &r1, const Razlomak &r2);
    friend bool operator !=(const Razlomak &r1, const Razlomak &r2);
    friend std::ostream &operator <<(std::ostream &tok, const Razlomak &r);
    friend std::istream &operator >>(std::istream &tok, Razlomak &r);
    operator long double() const { return (long double) DajBrojnik()/DajNazivnik(); }
};

Razlomak::Razlomak(long long int b, long long int n) {
    if (n==0) throw std::logic_error("Nekorektran razlomak");
    if ((b>0 && n<0) || (b<0 && n<0)) { b*=-1; n*=-1; }
    long long int nzd=Razlomak::NZD(b,n);
    brojnik=b/nzd; nazivnik=n/nzd;
}

Razlomak operator +(const Razlomak &r1, const Razlomak &r2) {
    long long int r=Razlomak::NZD(r1.nazivnik,r2.nazivnik);
    if (Razlomak::TestPrekoracenjaZaMnozenje(r1.brojnik,r2.nazivnik/r))
        throw std::overflow_error("Nemoguce dobiti tacan rezultat");
    else if (Razlomak::TestPrekoracenjaZaMnozenje(r2.brojnik,r1.nazivnik/r))
        throw std::overflow_error("Nemoguce dobiti tacan rezultat");
    else if (Razlomak::TestPrekoracenjaZaSabiranje(r1.brojnik*(r2.nazivnik/r),r2.brojnik*(r1.nazivnik/r)))
        throw std::overflow_error("Nemoguce dobiti tacan rezultat");
    else if (Razlomak::TestPrekoracenjaZaMnozenje(r1.nazivnik,r2.nazivnik/r))
        throw std::overflow_error("Nemoguce dobiti tacan rezultat");
    long long int brojnik=r1.brojnik*(r2.nazivnik/r) + r2.brojnik*(r1.nazivnik/r);
    long long int nazivnik=r1.nazivnik*(r2.nazivnik/r);
    Razlomak r3(brojnik,nazivnik);
    return r3;
}

Razlomak operator -(const Razlomak &r1, const Razlomak &r2) {
    long long int r=Razlomak::NZD(r1.nazivnik,r2.nazivnik);
    if (Razlomak::TestPrekoracenjaZaMnozenje(r1.brojnik,r2.nazivnik/r))
        throw std::overflow_error("Nemoguce dobiti tacan rezultat");
    else if (Razlomak::TestPrekoracenjaZaMnozenje(r2.brojnik,r1.nazivnik/r))
        throw std::overflow_error("Nemoguce dobiti tacan rezultat");
    else if (Razlomak::TestPrekoracenjaZaOduzimanje(r1.brojnik*(r2.nazivnik/r),r2.brojnik*(r1.nazivnik/r)))
        throw std::overflow_error("Nemoguce dobiti tacan rezultat");
    else if (Razlomak::TestPrekoracenjaZaMnozenje(r1.nazivnik,r2.nazivnik/r))
        throw std::overflow_error("Nemoguce dobiti tacan rezultat");
    long long int brojnik=r1.brojnik*(r2.nazivnik/r) - r2.brojnik*(r1.nazivnik/r);
    long long int nazivnik=r1.nazivnik*(r2.nazivnik/r);
    Razlomak r3(brojnik,nazivnik);
    return r3;
}

Razlomak operator *(const Razlomak &r1, const Razlomak &r2) {
    long long int s=Razlomak::NZD(r1.brojnik,r2.nazivnik);
    long long int t=Razlomak::NZD(r2.brojnik,r1.nazivnik);
    if (Razlomak::TestPrekoracenjaZaMnozenje(r1.brojnik/s,r2.brojnik/t))
        throw std::overflow_error("Nemoguce dobiti tacan rezultat");
    else if (Razlomak::TestPrekoracenjaZaMnozenje(r1.nazivnik/t,r2.nazivnik/s))
        throw std::overflow_error("Nemoguce dobiti tacan rezultat");
    long long int brojnik=(r1.brojnik/s)*(r2.brojnik/t);
    long long int nazivnik=(r1.nazivnik/t)*(r2.nazivnik/s);
    Razlomak r3(brojnik,nazivnik);
    return r3;
}

Razlomak operator /(const Razlomak &r1, const Razlomak &r2) {
    long long int u=Razlomak::NZD(r1.brojnik,r2.nazivnik);
    long long int r=Razlomak::NZD(r1.nazivnik,r2.nazivnik);
    if (Razlomak::TestPrekoracenjaZaMnozenje(r1.brojnik/u,r2.nazivnik/r))
        throw std::overflow_error("Nemoguce dobiti tacan rezultat");
    else if (Razlomak::TestPrekoracenjaZaMnozenje(r1.nazivnik/r,r2.brojnik/u))
        throw std::overflow_error("Nemoguce dobiti tacan rezultat");
    long long int brojnik=(r1.brojnik/u)*(r2.nazivnik/r);
    long long int nazivnik=(r1.nazivnik/r)*(r2.brojnik/u);
    Razlomak r3(brojnik,nazivnik);
    return r3;
}

Razlomak operator +(const Razlomak &r) { return r; }

Razlomak operator -(const Razlomak &r) {
    Razlomak r3(r.brojnik*(-1),r.nazivnik);
    return r3;
}

Razlomak &operator +=(Razlomak &r1, const Razlomak &r2) {
    r1=r1+r2;
    return r1;
}

Razlomak &operator -=(Razlomak &r1, const Razlomak &r2) {
    r1=r1-r2;
    return r1;
}

Razlomak &operator *=(Razlomak &r1, const Razlomak &r2) {
    r1=r1*r2;
    return r1;
}

Razlomak &operator /=(Razlomak &r1, const Razlomak &r2) {
    r1=r1/r2;
    return r1;
}

Razlomak &operator ++(Razlomak &r) { 
    r=r+Razlomak(1); 
    return r; 
}

Razlomak operator ++(Razlomak &r, int) {
    Razlomak pomocni(r);
    r=r+Razlomak(1);
    return pomocni;
}

Razlomak &operator --(Razlomak &r) {
    r=r-Razlomak(1);
    return r;
}

Razlomak operator --(Razlomak &r, int) {
    Razlomak pomocni(r);
    r=r-Razlomak(1);
    return pomocni;
}

bool operator <(const Razlomak &r1, const Razlomak &r2) {
    if ((long double)r1<(long double)r2 && r1!=r2) return true;
    return false;
}

bool operator >(const Razlomak &r1, const Razlomak &r2) { 
    if ((long double)r1>(long double)r2 && r1!=r2) return true;
    return false;
}

bool operator <=(const Razlomak &r1, const Razlomak &r2) {
    if ((long double)r1<=(long double)r2 || r1==r2) return true;
    return false;
}

bool operator >=(const Razlomak &r1, const Razlomak &r2) {
    if ((long double)r1>=(long double)r2 || r1==r2) return true;
    return false;
}

bool operator ==(const Razlomak &r1, const Razlomak &r2) {
    return Razlomak::JesuLiJednaki((long double)r1,(long double)r2);
}

bool operator !=(const Razlomak &r1, const Razlomak &r2) {
    return !(r1==r2);
}

std::ostream &operator <<(std::ostream &tok, const Razlomak &r) {
    if (r.nazivnik==1) {
        tok << r.brojnik;
        return tok;
    }
    tok << r.brojnik << "/" << r.nazivnik;
    return tok;
}

std::istream &operator >>(std::istream &tok, Razlomak &r) {
    char znak;
    long long int brojnik, nazivnik;
    tok >> std::ws;
    if (tok.peek()>='0' && tok.peek()<='9') tok >> brojnik;
    else tok.setstate(std::ios::failbit);
    if (tok.peek()=='/') {
        tok >> znak;
        if (tok.peek()>='0' && tok.peek()<='9') {
            tok >> nazivnik;
            if (tok.peek()==' ' || tok.peek()=='\n' || tok.peek()=='\r' ||
                tok.peek()=='\t' || tok.peek()=='\v' || tok.peek()=='\f' || tok.peek()==EOF) {
                    long long int nzd=Razlomak::NZD(brojnik,nazivnik);
                    r.brojnik=brojnik/nzd;
                    r.nazivnik=nazivnik/nzd;
                    return tok;
                }
            else tok.setstate(std::ios::failbit);
        }
        else tok.setstate(std::ios::failbit);
    }
    else if (tok.peek()==' ' || tok.peek()=='\n' || tok.peek()=='\r' ||
        tok.peek()=='\t' || tok.peek()=='\v' || tok.peek()=='\f' || tok.peek()==EOF) {
            r.brojnik=brojnik;
            r.nazivnik=1;
            return tok;
        }
    else tok.setstate(std::ios::failbit);
    return tok;
}

int main () {
    Razlomak r1, r2;
    std::cin >> r1 >> r2;
    std::cout << r1 << " + " << r2 << " = " << r1+r2 << std::endl;
    std::cout << r1 << " - " << r2 << " = " << r1-r2 << std::endl;
    std::cout << r1 << " * " << r2 << " = " << r1*r2 << std::endl;
    std::cout << r1 << " / " << r2 << " = " << r1/r2 << std::endl;
    if (r1+r2>=r1-r2) std::cout << r1 << " + " << r2 << " >= " << r1 << " - " << r2 << std::endl;
    else std::cout << r1 << " + " << r2 << " <= " << r1 << " - " << r2 << std::endl;
    if (r1*r2<=r1/r2) std::cout << r1 << " * " << r2 << " <= " << r1 << " / " << r2 << std::endl;
    else std::cout << r1 << " * " << r2 << " >= " << r1 << " / " << r2 << std::endl;
    if (r1==r2) std::cout << (long double) r1 << " = " << (long double) r2 << std::endl;
    else if (r1!=r2) {
        if (r1<r2) std::cout << (long double) r1 << " < "  << (long double) r2 << std::endl;
        else if (r1>r2) std::cout << (long double) r1 << " > " << (long double) r2 << std::endl;
    }
    return 0;
}