/B16/17 (Zadaća 5, Zadatak 3)
//Autotestovi by Enil Pajic (mail: epajic1@etf.unsa.ba)
//Za autotestove se obracati *iskljucivo* osobi koja ih pise

#include <iostream>
#include <stdexcept>
#include <limits>

class Razlomak {
    long long int brojnik, nazivnik;
    static long long int NZD(long long int x, long long int y);
    static void Prekoracenje(long long int a, long long int b, char o);
public:
    Razlomak(long long int brj=0, long long int nzv=1);
    long long int DajBrojnik() const {return brojnik;}
    long long int DajNazivnik() const {return nazivnik;}
    friend Razlomak operator +(const Razlomak &r1, const Razlomak &razl);
    friend Razlomak operator -(const Razlomak &r1, const Razlomak &razl);
    friend Razlomak operator *(const Razlomak &r1, const Razlomak &razl);
    friend Razlomak operator /(const Razlomak &r1, const Razlomak &razl);
    Razlomak operator +() const {return *this;}
    Razlomak operator -() const;
    Razlomak& operator +=(const Razlomak &razl) {
        *this = *this + razl;
        return *this;
    }
    Razlomak& operator -=(const Razlomak &razl) {
        *this = *this - razl;
        return *this;
    }
    Razlomak& operator *=(const Razlomak &razl) {
        *this = *this * razl;
        return *this;
    }
    Razlomak& operator /=(const Razlomak &razl) {
        *this = *this / razl;
        return *this;
    }
    Razlomak& operator ++();
    Razlomak operator ++(int);
    Razlomak& operator --();
    Razlomak operator --(int);
    friend bool operator < (const Razlomak &r1, const Razlomak &r2);
    friend bool operator <= (const Razlomak &r1, const Razlomak &r2);
    friend bool operator > (const Razlomak &r1, const Razlomak &r2);
    friend bool operator >= (const Razlomak &r1, const Razlomak &r2);
    friend bool operator == (const Razlomak &r1, const Razlomak &r2);
    friend bool operator != (const Razlomak &r1, const Razlomak &r2);
    friend std::ostream& operator <<(std::ostream& tok, const Razlomak &r);
    friend std::istream& operator >>(std::istream& tok, Razlomak &r);
    operator long double () const {
        return (long double) brojnik/nazivnik;
    }
};
void Razlomak::Prekoracenje(long long int x, long long int y, char o) {
    long long int m = std::numeric_limits<long long int>::min(), M= std::numeric_limits<long long int>::max();
    if(o == '+' && ((y > 0 && x > M - y) || (y < 0 && x < m - y))) throw std::overflow_error("Nemoguce dobiti tacan rezultat");
    if(o == '-' && ((y < 0 && x > M + y) || (y > 0 && x < m + y))) throw std::overflow_error("Nemoguce dobiti tacan rezultat");
    if(o == '*' && ((y > 0 && (x < m/y || x > M/y)) || (y < 0 && (x == m || -x > M/(-y) || -x < m/(-y)))))  throw std::overflow_error("Nemoguce dobiti tacan rezultat");
}
Razlomak::Razlomak(long long int brj, long long int nzv) {
    if(!nzv) throw std::logic_error("Nekorektan razlomak");
    auto x(NZD(brj, nzv));
    brj /= x;
    nzv /= x;
    brojnik = brj;
    nazivnik = nzv;
}
long long int Razlomak::NZD(long long int x, long long int y) {
    while(y != 0) {
        auto t = y;
        y = x % y;
        x = t;
    }
    return x;
}
Razlomak operator +(const Razlomak &r1, const Razlomak &razl) {
    long long int p, q;
    auto r = Razlomak::NZD(r1.nazivnik, razl.nazivnik);
    Razlomak::Prekoracenje(r1.brojnik, razl.nazivnik / r, '*');
    Razlomak::Prekoracenje (razl.brojnik, r1.nazivnik / r, '*');
    Razlomak::Prekoracenje(r1.brojnik * (razl.nazivnik /r), razl.brojnik * (r1.nazivnik / r), '+');
    Razlomak::Prekoracenje(r1.nazivnik, razl.nazivnik / r, '*');
    p = r1.brojnik * (razl.nazivnik / r) + razl.brojnik * (r1.nazivnik / r);
    q = r1.nazivnik * (razl.nazivnik / r);
    return Razlomak(p, q);
}
Razlomak operator -(const Razlomak &r1, const Razlomak &razl) {
    long long int p, q;
    auto r = Razlomak::NZD(r1.nazivnik, razl.nazivnik);
    Razlomak::Prekoracenje(r1.brojnik, razl.nazivnik / r, '*');
    Razlomak::Prekoracenje(razl.brojnik, r1.nazivnik / r, '*');
    Razlomak::Prekoracenje(r1.brojnik * (razl.nazivnik / r), razl.brojnik * (r1.nazivnik / r), '-');
    Razlomak::Prekoracenje(r1.nazivnik, razl.nazivnik / r, '*');
    p = r1.brojnik * (razl.nazivnik / r) - razl.brojnik * (r1.nazivnik / r);
    q = r1.nazivnik * (razl.nazivnik / r);
    return Razlomak(p, q);
}
Razlomak operator *(const Razlomak &r1, const Razlomak &razl) {
    long long int p, q;
    auto s = Razlomak::NZD(r1.brojnik, razl.nazivnik), t = Razlomak::NZD(razl.brojnik, r1.nazivnik);
    Razlomak::Prekoracenje(r1.brojnik /s, razl.brojnik / t, '*');
    Razlomak::Prekoracenje(r1.nazivnik / t, razl.nazivnik / s, '*');
    p = (r1.brojnik / s) * (razl.brojnik / t);
    q = (r1.nazivnik / t) * (razl.nazivnik / s);
    return Razlomak(p, q);
}
Razlomak operator /(const Razlomak &r1, const Razlomak &razl) {
    long long int p, q;
    auto r = Razlomak::NZD(r1.nazivnik, razl.nazivnik), u = Razlomak::NZD(r1.brojnik, razl.brojnik);
    Razlomak::Prekoracenje(r1.brojnik / u, razl.nazivnik / r, '*');
    Razlomak::Prekoracenje(r1.nazivnik / r, razl.brojnik / u, '*');
    p = (r1.brojnik / u) * (razl.nazivnik / r);
    q = (r1.nazivnik / r) * (razl.brojnik / u);
    return Razlomak(p, q);
}
Razlomak Razlomak::operator -() const {
    if(brojnik == std::numeric_limits<long long int>::min()) throw std::overflow_error("Nemoguce dobiti tacan rezultat");
    return Razlomak(brojnik, nazivnik);
}
Razlomak& Razlomak::operator ++() {
    *this += Razlomak(1);
    return *this;
}
Razlomak Razlomak::operator ++(int) {
    auto tmp(*this);
    *this += Razlomak(1);
    return tmp;
}
Razlomak& Razlomak::operator --() {
    *this -= Razlomak(1);
    return *this;
}
Razlomak Razlomak::operator --(int) {
    auto tmp(*this);
    *this -= Razlomak(1);
    return tmp;
}
bool operator < (const Razlomak &r1, const Razlomak &r2) {
    return static_cast<long double>(r1) < static_cast<long double>(r2);
}
bool operator <= (const Razlomak &r1, const Razlomak &r2) {
    return static_cast<long double>(r1) <= static_cast<long double>(r2);
}
bool operator > (const Razlomak &r1, const Razlomak &r2) {
    return static_cast<long double>(r1) > static_cast<long double>(r2);
}
bool operator >= (const Razlomak &r1, const Razlomak &r2) {
    return static_cast<long double>(r1) >= static_cast<long double>(r2);
}
bool operator == (const Razlomak &r1, const Razlomak &r2) {
    return static_cast<long double>(r1) == static_cast<long double>(r2);
}
bool operator != (const Razlomak &r1, const Razlomak &r2) {
    return static_cast<long double>(r1) != static_cast<long double>(r2);
}
std::ostream& operator <<(std::ostream& tok, const Razlomak &r) {
    if(r.DajNazivnik() == 1) {
        tok << r.DajBrojnik();
        return tok;
    }
    tok << r.DajBrojnik() << "/" << r.DajNazivnik();
    return tok;
}
std::istream& operator >>(std::istream&tok, Razlomak &r) {
    long double b=0, n=1;
    char c;
    tok >> std::ws;
    tok >> b;
    if(!tok) return tok;
    if(tok.peek() == '\n' || tok.peek() == '\t'|| tok.peek() == '\r' || tok.peek() == ' ' || tok.peek() == '\v' || tok.peek() == '\f' || tok.peek() == EOF) {
        if(b != (long long int)(b)) {
            tok.setstate(std::ios::failbit);
            return tok;   
        }
        r = Razlomak(b,n);
        return tok;
    }
    else {
        tok >> std::ws;
        tok >> c;
        if(c != '/') {
            tok.setstate(std::ios::failbit);
            return tok;   
        }
        tok >> std::ws;
        tok >> n;
        if(!tok || n != (long long int)(n) || !(tok.peek() == '\n' || tok.peek() == '\t' || tok.peek() == '\r' || tok.peek() == ' ' || tok.peek() == '\v' || tok.peek() == '\f' || tok.peek())) {
            tok.setstate(std::ios::failbit);
            return tok;
        }
        r = Razlomak(b,n);
    }
    return tok;
}
int main ()
{
   
	return 0;
}