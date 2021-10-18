/B16/17 (Zadaća 5, Zadatak 3)
//Autotestovi by Enil Pajic (mail: epajic1@etf.unsa.ba)
//Za autotestove se obracati *iskljucivo* osobi koja ih pise
#include <iostream>
#include <stdexcept>
#include <cmath>
#include <limits>
const long double Eps(1e-10); 
long long int M = std::numeric_limits<long long int>::max();
class Razlomak {
    long long int brojnik, nazivnik;
    static int Skrati(long long int m, long long int n);
    static bool PrekoracenjeSab(long long int x, long long int y);
    static bool PrekoracenjeOduz(long long int x, long long int y);
    static bool PrekoracenjeMnoz(long long int x, long long int y);
   // static bool PrekoracenjeDj(long long int x, long long int y);
   static void Pokrati(long long int &m, long long int &n) {
       long long int r = Skrati(m, n);
       m /= r; n /= r;
   }
public:
    Razlomak (long long int m = 0, long long int n = 1);
    Razlomak(std::initializer_list<long long int> l);
    long long int DajBrojnik() {
        return brojnik;
    }
    long long int DajNazivnik() {
        return nazivnik;
    }
    Razlomak operator+(const Razlomak &r);
    Razlomak operator -(const Razlomak &r);
    Razlomak operator *(const Razlomak &r);
    Razlomak operator /(const Razlomak &r);
    friend std::ostream &operator <<(std::ostream &tok, Razlomak r);
    friend std::istream &operator >>(std::istream &tok, Razlomak &r);
    Razlomak operator+();
    Razlomak operator-();
    Razlomak &operator += (const Razlomak &r);
    Razlomak &operator -=(const Razlomak &r);
    Razlomak &operator *=(const Razlomak &r);
    Razlomak &operator /=(const Razlomak &r);
    Razlomak &operator ++();
    Razlomak operator++(int);
    Razlomak &operator --();
    Razlomak operator --(int);
    bool operator < (const Razlomak &r);
    bool operator <= (const Razlomak &r);
    bool operator > (const Razlomak &r);
    bool operator >= (const Razlomak &r);
    bool operator ==(const Razlomak &r);
    bool operator !=(const Razlomak &r);
    operator long double();
};
Razlomak::operator long double() {
    long double a;
    a = ((long double) brojnik)/nazivnik;
    return a;
}
bool Razlomak::operator !=(const Razlomak &r) {
    long double a, b;
    a = ((long double)brojnik)/nazivnik;
    b = ((long double)r.brojnik)/r.nazivnik;
    return (std::abs(a-b) > Eps);
}
bool Razlomak::operator ==(const Razlomak &r) {
    long double a, b;
    a = ((long double)brojnik)/nazivnik;
    b = ((long double)r.brojnik)/r.nazivnik;
    return (std::abs(a-b) <= Eps);
}
bool Razlomak::operator >= (const Razlomak &r) {
    long double a, b;
    a = ((long double)brojnik)/nazivnik;
    b = ((long double)r.brojnik)/r.nazivnik;
    if(std::abs(a-b) <= Eps) return true;
    return a > b;
}
bool Razlomak::operator > (const Razlomak &r) {
    long double a, b;
    a = ((long double)brojnik)/nazivnik;
    b = ((long double)r.brojnik)/r.nazivnik;
    if(std::abs(a-b) <= Eps) return false;
    return a > b;
}
bool Razlomak::operator <= (const Razlomak &r) {
    long double a, b;
    a = ((long double)brojnik)/nazivnik;
    b = ((long double)r.brojnik)/r.nazivnik;
    if(std::abs(a-b) <= Eps) return true;
    return a < b;
}
bool Razlomak::operator <(const Razlomak &r) {
    long double a, b;
    a = ((long double)brojnik)/nazivnik;
    b = ((long double)r.brojnik)/r.nazivnik;
    if(std::abs(a-b) <= Eps) return false;
    return a < b;
}
Razlomak Razlomak::operator --(int) {
    Razlomak tmp, vrati(*this);
    try {
        tmp = *this - Razlomak(1);
    } catch(...) {
        throw;
    } *this = tmp;
    Pokrati(brojnik, nazivnik);
    return vrati;
}
Razlomak &Razlomak::operator--() {
    Razlomak tmp;
    try {
        tmp = *this - Razlomak(1);
    } catch(...) {
        throw;
    } *this = tmp;
    Pokrati(brojnik, nazivnik);
    return *this;
}
Razlomak Razlomak::operator ++(int) {
    Razlomak tmp, vrati(*this);
    try {
        tmp = *this + Razlomak(1);
    } catch(...) {
        throw;
    } *this = tmp;
    Pokrati(brojnik, nazivnik);
    return vrati;
}
Razlomak &Razlomak::operator++() {
    Razlomak tmp;
    try {
        tmp = *this + Razlomak(1);
    } catch(...) {
        throw;
    } *this = tmp;
    Pokrati(brojnik, nazivnik);
    return *this;
}
Razlomak &Razlomak::operator /=(const Razlomak &r) {
    Razlomak tmp;
    try {
        tmp = *this / r;
    } catch(...) {
        throw;
    } *this = tmp;
    Pokrati(brojnik, nazivnik);
    return *this;
}
Razlomak &Razlomak::operator *=(const Razlomak &r) {
    Razlomak tmp;
    try {
        tmp = *this * r;
    } catch(...) {
        throw;
    } *this = tmp;
    Pokrati(brojnik, nazivnik);
    return *this;
}
Razlomak &Razlomak::operator -=(const Razlomak &r) {
    Razlomak tmp;
    try {
        tmp = *this - r;
    } catch(...) {
        throw;
    } *this = tmp;
    Pokrati(brojnik, nazivnik);
    return *this;
}
Razlomak &Razlomak::operator += (const Razlomak &r) {
    Razlomak tmp;
    try {
        tmp = *this + r;
    } catch(...) {
        throw;
    } *this = tmp;
    Pokrati(brojnik, nazivnik);
    return *this;
}
Razlomak Razlomak::operator -() {
    if(PrekoracenjeMnoz(brojnik, -1)) throw std::overflow_error("Nemoguce dobiti tacan rezultat");
    brojnik *= -1;
    Pokrati(brojnik, nazivnik);
    return *this;
}
Razlomak Razlomak::operator +() {
    return *this;
}
std::istream &operator >>(std::istream &tok, Razlomak &r) {
    char a;
    tok>>r.brojnik;
    if(tok.peek() == EOF || tok.peek() == '\n' || tok.peek() == '\t' || tok.peek() == ' ' || tok.peek() == '\r' || tok.peek() == '\f') {
        r.nazivnik = 1;
        return tok;
    }
    tok>>a>>r.nazivnik;
    if(a != '/' || tok.peek() != EOF || tok.peek() != '\n' || tok.peek() != '\t' || tok.peek() != ' ' || tok.peek() != '\r' || tok.peek() != '\f') {
        tok.setstate(std::ios::failbit);
        return tok;
    }
    Razlomak::Pokrati(r.brojnik, r.nazivnik);
    return tok;
}
std::ostream &operator <<(std::ostream &tok, Razlomak r) {
    tok<<r.brojnik;
    if(r.nazivnik != 1) tok<<"/"<<r.nazivnik;
    return tok;
}
Razlomak Razlomak::operator /(const Razlomak &r) {
    long long int u = Skrati(brojnik, r.brojnik);
    long long int k = Skrati(nazivnik, r.nazivnik);
    Razlomak rez;
    if(PrekoracenjeMnoz(brojnik/u, r.brojnik/k) || PrekoracenjeMnoz(nazivnik/k, r.brojnik/u))
        throw std::overflow_error("Nemoguce dobiti tacan rezultat");
    rez.brojnik = (brojnik / u) * (r.nazivnik / k);
    rez.nazivnik = (nazivnik / k) * (r.brojnik / u);
    Pokrati(rez.brojnik, rez.nazivnik);
    return rez;
}
Razlomak  Razlomak::operator *(const Razlomak &r) {
    Razlomak rez;
    long long int s = Skrati(brojnik, r.nazivnik);
    long long int t = Skrati(r.brojnik, nazivnik);
    long long int a = (brojnik / s);
    long long int b = (r.brojnik / t);
    rez.brojnik = a * b;
    if(PrekoracenjeMnoz(a, b) || PrekoracenjeMnoz(nazivnik/t, r.nazivnik/s))
        throw std::overflow_error("Nemoguce dobiti tacan rezultat");
    rez.nazivnik = (nazivnik / t) * (r.nazivnik / s);
    Pokrati(rez.brojnik, rez.nazivnik);
    return rez;
}
Razlomak Razlomak::operator-(const Razlomak &r) {
    Razlomak rez;
    long long int k = Skrati(nazivnik, r.nazivnik);
    long long int a = brojnik * (r.nazivnik / k);
    long long int b = r.brojnik * (nazivnik / k);
    if(PrekoracenjeMnoz(brojnik, r.nazivnik/k) || PrekoracenjeMnoz(r.brojnik, nazivnik/k) || PrekoracenjeOduz(a, b) || PrekoracenjeMnoz(nazivnik, r.nazivnik/k))
        throw std::overflow_error("Nemoguce dobiti tacan rezultat");
    rez.brojnik = a - b;
    rez.nazivnik = nazivnik * (r.nazivnik / k);
    Pokrati(rez.brojnik, rez.nazivnik);
    return rez;
}
Razlomak Razlomak::operator+ (const Razlomak &r) {
    Razlomak rez;
    long long int k = Skrati(nazivnik, r.nazivnik);
    long long int a = brojnik * (r.nazivnik / k);
    long long int b = r.brojnik * (nazivnik / k);
    rez.brojnik = a + b;
    if(PrekoracenjeMnoz(brojnik, r.nazivnik/k) || PrekoracenjeMnoz(r.brojnik, nazivnik/k) || PrekoracenjeSab(a, b) || PrekoracenjeMnoz(nazivnik, r.nazivnik / k))
        throw std::overflow_error("Nemoguce dobiti tacan rezultat");
    rez.nazivnik = nazivnik * (r.nazivnik / k);
    Pokrati(rez.brojnik, rez.nazivnik);
    return rez;
}
bool Razlomak::PrekoracenjeMnoz(long long int x, long long int y) {
    long long int m = std::numeric_limits<long long int>::min();
    if(y > 0 && (x < m / y || x > M / y )) return true;
    else if(y < 0 && (x == m || -x > M / (-y) || -x < m / (-y))) return true;
    return false;
}
bool Razlomak::PrekoracenjeOduz(long long int x, long long int y) {
   // long long int M = std::numeric_limits<long long int>::max();
    long long int m = std::numeric_limits<long long int>::min();
    if(y < 0 && x > M + y) return true;
    else if(y > 0 && x < m + y) return true;
    return false;
}
bool Razlomak::PrekoracenjeSab(long long int x, long long int y) {
    //long long int M = std::numeric_limits<long long int>::max();
    long long int m = std::numeric_limits<long long int>::min();
    if(y > 0 && x > M - y) return true;
    else if(y < 0 && x < m - y) return true;
    return false;
}
Razlomak::Razlomak(std::initializer_list<long long int> l) {
    int a(1);
    auto pok = l.begin();
    brojnik = *pok; 
    pok++;
    nazivnik = *pok;
    if(brojnik < 0 && nazivnik < 0) {
        brojnik *= -1; nazivnik *= -1;
    } else if(brojnik < 0 || nazivnik < 0) {
        a = -1;
        brojnik = std::abs(brojnik);
        nazivnik = std::abs(nazivnik);
    }
    long long int r = Skrati(brojnik, nazivnik);
    brojnik /= r; nazivnik /= r;
    brojnik *= a;
}
Razlomak::Razlomak(long long int m, long long int n) {
    if(n == 0) throw std::logic_error("Nekorektan razlomak");
    int a(1);
    if(m < 0 && n < 0) {
        m *= -1; n *= -1;
    } else if(m < 0 || n < 0) {
        a = -1; m = std::abs(m); n = std::abs(n);
    }
    long long int r = Skrati(m, n);
    brojnik = a * (m / r); nazivnik = n / r;
}
int Razlomak::Skrati(long long int m, long long int n) {
    int r;

    do {
        r = m % n;
        if(r == 0) break;
        m = n;
        n = r;
    } while(true);
    return n;
}
int main ()
{
    Razlomak zzz(10, 20);
    std::cout<<zzz;
    Razlomak r(3, 6), t(-2, 3);
    Razlomak v;
    v = r - t;
    r += t;
    r *= t;
    v = r / t;
    v /= 2;
    if(v < r) std::cout<<"Manji je\n";
    else std::cout<<"Veci je \n";
    std::cout<<r.DajBrojnik()<<"/"<<r.DajNazivnik();
    std::cout<<"Unesite razlomak: ";
    Razlomak a;
    std::cin>>a;
    if(a != t) a-= t;
    std::cout<<a;
	return 0;
}