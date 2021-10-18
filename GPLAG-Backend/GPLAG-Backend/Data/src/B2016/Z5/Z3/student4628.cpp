/B16/17 (Zadaća 5, Zadatak 3)
//Autotestovi by Enil Pajic (mail: epajic1@etf.unsa.ba)
//Za autotestove se obracati *iskljucivo* osobi koja ih pise
#include <iostream>
#include <stdexcept>
#include <limits>

long long int M = std::numeric_limits<long long int>::max();
long long int m = std::numeric_limits<long long int>::min();

class Razlomak {
    long long int brojnik;
    long long int nazivnik;
    static int NZD (long long int p, long long int q) {
        while(q != 0) {
            long long int tmp(p);
            p = q;
            q = tmp % q;
        }
        return p;
    }
public:
    Razlomak(long long int b, long long int n) {
        if(n == 0) throw std::logic_error ("Nekorektan razlomak");
        if(n < 0 && b > 0) n *= -1, b *= -1;
        if(n < 0 && b < 0) n *= -1, b *= -1;
        long long int nzd = NZD(b, n);
        n /= nzd; b /= nzd;
        brojnik = b;
        nazivnik = n;
    }
    
    Razlomak(long long int b) { brojnik = b; nazivnik = 1; }
    Razlomak() { brojnik = 0; nazivnik = 1; }
    long long int DajBrojnik() const{ return brojnik; }
    long long int DajNazivnik() const{ return nazivnik; }
    operator long double() const;
    friend Razlomak operator +(const Razlomak &z1, const Razlomak &z2);         //URADI PREKORACENJE!!!
    friend Razlomak operator -(const Razlomak &z1, const Razlomak &z2);
    friend Razlomak operator *(const Razlomak &z1, const Razlomak &z2);
    friend Razlomak operator /(const Razlomak &z1, const Razlomak &z2);
    friend Razlomak &operator -(Razlomak &z);
    friend Razlomak &operator +(Razlomak &z);
    friend Razlomak operator +=(const Razlomak &z1, const Razlomak &z2);        
    friend Razlomak operator -=(const Razlomak &z1, const Razlomak &z2);
    friend Razlomak operator *=(const Razlomak &z1, const Razlomak &z2);
    friend Razlomak operator /=(const Razlomak &z1, const Razlomak &z2);
    friend Razlomak &operator ++(Razlomak &z);
    friend Razlomak operator ++(Razlomak &z, int);
    friend Razlomak &operator --(Razlomak &z);
    friend Razlomak operator --(Razlomak &z, int);
    friend bool operator <(const Razlomak &z1, const Razlomak &z2);
    friend bool operator <=(const Razlomak &z1, const Razlomak &z2);
    friend bool operator >(const Razlomak &z1, const Razlomak &z2);
    friend bool operator >=(const Razlomak &z1, const Razlomak &z2);
    friend bool operator ==(const Razlomak &z1, const Razlomak &z2);
    friend bool operator !=(const Razlomak &z1, const Razlomak &z2);
    friend std::ostream &operator <<(std::ostream &tok, const Razlomak &z);
    friend std::istream &operator >>(std::istream &tok, Razlomak &z);
}; 
Razlomak::operator long double() const {
    return (long double)brojnik / nazivnik;
}
Razlomak operator +(const Razlomak &z1, const Razlomak &z2) {
    long long int r = Razlomak::NZD(z1.nazivnik, z2.nazivnik);
    long long int n = z1.nazivnik * int(z2.nazivnik / r);
    long long int b = z1.brojnik * int(z2.nazivnik / r) + z2.brojnik * int(z1.nazivnik / r);
    Razlomak z3(b, n);
    return z3;
}
Razlomak operator -(const Razlomak &z1, const Razlomak &z2) {
    long long int r = Razlomak::NZD(z1.nazivnik, z2.nazivnik);
    long long int n = z1.nazivnik * int(z2.nazivnik / r);
    long long int b = z1.brojnik * int(z2.nazivnik / r) - z2.brojnik * int(z1.nazivnik / r);
    Razlomak z3(b, n);
    return z3;
}
Razlomak operator *(const Razlomak &z1, const Razlomak &z2) {
    long long int s = Razlomak::NZD(z1.brojnik, z2.nazivnik);
    long long int t = Razlomak::NZD(z2.brojnik, z1.nazivnik);
    long long int b = int(z1.brojnik / s) * int(z2.brojnik / t);
    long long int n = int(z1.nazivnik / t) * int(z2.nazivnik / s);
    Razlomak z3(b, n);
    return z3;
}
Razlomak operator /(const Razlomak &z1, const Razlomak &z2) {
    long long int u = Razlomak::NZD(z1.brojnik, z2.brojnik);
    long long int r = Razlomak::NZD(z1.nazivnik, z2.nazivnik);
    long long int b = int(z1.brojnik / u) * int(z2.nazivnik / r);
    long long int n = int(z1.nazivnik / r) * int(z2.brojnik / u);
    Razlomak z3(b, n);
    return z3;
}
Razlomak &operator -(Razlomak &z) {
    z.brojnik *= -1;
    return z;
}
Razlomak &operator +(Razlomak &z) { return z; }
Razlomak operator +=(const Razlomak &z1, const Razlomak &z2) {
    return z1 + z2;
}
Razlomak operator -=(const Razlomak &z1, const Razlomak &z2) {
    return z1 - z2;
}
Razlomak operator *=(const Razlomak &z1, const Razlomak &z2) {
    return z1 * z2;
}
Razlomak operator /=(const Razlomak &z1, const Razlomak &z2) {
    return z1 / z2;
}
Razlomak &operator ++(Razlomak &z) {
    z += 1;
    return z;
}
Razlomak operator ++(Razlomak &z, int){
    Razlomak tmp(z);
    z += 1;
    return tmp;
}
Razlomak &operator --(Razlomak &z) {
    z -= 1;
    return z;
}
Razlomak operator --(Razlomak &z, int){
    Razlomak tmp(z);
    z -= 1;
    return tmp;
}
bool operator <(const Razlomak &z1, const Razlomak &z2) {
    long double p = (long double)z1.brojnik / z1.nazivnik;
    long double q = (long double)z2.brojnik / z2.nazivnik;
    return p < q;
}
bool operator >(const Razlomak &z1, const Razlomak &z2) {
    long double p = (long double) z1.brojnik / z1.nazivnik;
    long double q = (long double) z2.brojnik / z2.nazivnik;
    return p > q;
}
bool operator <=(const Razlomak &z1, const Razlomak &z2) {
    long double p = (long double) z1.brojnik / z1.nazivnik;
    long double q = (long double) z2.brojnik / z2.nazivnik;
    return p <= q;
}
bool operator >=(const Razlomak &z1, const Razlomak &z2) {
    long double p = (long double) z1.brojnik / z1.nazivnik;
    long double q = (long double) z2.brojnik / z2.nazivnik;
    return p >= q;
}
bool operator ==(const Razlomak &z1, const Razlomak &z2) {
    long double p = (long double) z1.brojnik / z1.nazivnik;
    long double q = (long double) z2.brojnik / z2.nazivnik;
    return p == q;
}
bool operator !=(const Razlomak &z1, const Razlomak &z2) {
    long double p = (long double) z1.brojnik / z1.nazivnik;
    long double q = (long double) z2.brojnik / z2.nazivnik;
    return p != q;
}
std::ostream &operator <<(std::ostream &tok, const Razlomak &z) {
    long long int nzd = Razlomak::NZD(z.brojnik, z.nazivnik);
    Razlomak z1(z);
    z1.brojnik /= nzd; z1.nazivnik /= nzd;
    if(z1.nazivnik == 1) return tok << z1.brojnik;
    return tok << z1.brojnik << "/" << z1.nazivnik;
}
std::istream &operator >>(std::istream &tok, Razlomak &z) {
    char znak;
    tok >> std::ws;
    tok >> z.brojnik;
    if(tok.peek() != '/') z.nazivnik = 1;
    else { 
        tok >> znak >> z.nazivnik;
        if(znak != '/') tok.setstate(std::ios::failbit);
        tok.clear();
        //if(tok.peek() != ' ' || tok.peek() != '\n' || tok.peek() != '\t' || tok.peek() != '\v' || tok.peek() != '\f') tok.setstate(std::ios::failbit);
    }
    return tok;
}

int main ()
{
	return 0;
}