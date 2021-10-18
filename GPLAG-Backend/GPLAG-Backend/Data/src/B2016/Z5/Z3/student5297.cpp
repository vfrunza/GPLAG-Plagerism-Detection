/B16/17 (Zadaća 5, Zadatak 3)
//Autotestovi by Enil Pajic (mail: epajic1@etf.unsa.ba)
//Za autotestove se obracati *iskljucivo* osobi koja ih pise
#include <iostream>
#include <stdexcept>
#include <limits>

bool Sabiranje(long long int x, long long y) {
    long long int M(std::numeric_limits<long long int>::max());
    long long int m(std::numeric_limits<long long int>::min());
    if(y>0 && x>M-y) return false;
    if(y<0 && x<m-y) return false;
    return true;
}

bool Oduzimanje(long long int x, long long int y) {
    long long int M(std::numeric_limits<long long int>::max());
    long long int m(std::numeric_limits<long long int>::min());
    if(y<0 && x>M+y) return false;
    if(y>0 && x<m+y) return false;
    return true;
}

bool Mnozenje(long long int x, long long int y) {
    long long int M(std::numeric_limits<long long int>::max());
    long long int m(std::numeric_limits<long long int>::min());
    if(y>0 && (x<m/y || x>M/y)) return false;
    if(y<0 && (x==m || -x>M/(-y) || -x<m/(-y))) return false;
    return true;
}

class Razlomak {
    long long int brojnik, nazivnik;    
    static int NZD(long long int p, long long int q);
public: 
    Razlomak() : brojnik(0), nazivnik(1) {}
    Razlomak(long long int b) : brojnik(b), nazivnik(1) {}
    Razlomak(long long int b, long long int n);
    long long int DajBrojnik() const { return brojnik; }
    long long int DajNazivnik() const { return nazivnik; }
    friend Razlomak operator+(const Razlomak &r1, const Razlomak &r2);
    friend Razlomak operator-(const Razlomak &r1, const Razlomak &r2);
    friend Razlomak operator*(const Razlomak &r1, const Razlomak &r2);
    friend Razlomak operator/(const Razlomak &r1, const Razlomak &r2);
    friend Razlomak &operator+(Razlomak &r) { return r; }
    friend Razlomak &operator-(Razlomak &r);
    friend Razlomak &operator+=(Razlomak &r1, const Razlomak &r2);
    friend Razlomak &operator-=(Razlomak &r1, const Razlomak &r2);
    friend Razlomak &operator*=(Razlomak &r1, const Razlomak &r2);
    friend Razlomak &operator/=(Razlomak &r1, const Razlomak &r2);
    friend Razlomak &operator++(Razlomak &r);
    friend Razlomak operator++(Razlomak &r, int);
    friend Razlomak &operator--(Razlomak &r);
    friend Razlomak operator--(Razlomak &r, int);
    friend bool operator<(const Razlomak &r1, const Razlomak &r2);
    friend bool operator>(const Razlomak &r1, const Razlomak &r2);
    friend bool operator<=(const Razlomak &r1, const Razlomak &r2);
    friend bool operator>=(const Razlomak &r1, const Razlomak &r2);
    friend bool operator==(const Razlomak &r1, const Razlomak &r2);
    friend bool operator!=(const Razlomak &r1, const Razlomak &r2);
    friend std::ostream &operator<<(std::ostream &tok, const Razlomak &r);
    friend std::istream &operator>>(std::istream &tok, Razlomak &r);
    operator long double() const;
};

int Razlomak::NZD(long long int p, long long int q) {
    if(q==0) return p;
    return NZD(q, p%q);
}

Razlomak::Razlomak(long long int b, long long int n) {
    if(n==0) throw std::logic_error("Nekorektan razlomak");
    int nzd(NZD(b,n));
    if(n<0) { n*=-1; b*=-1; }
    brojnik=b/nzd; nazivnik=n/nzd;
}

Razlomak operator+(const Razlomak &r1, const Razlomak &r2) {
    int r(r1.NZD(r1.nazivnik, r2.nazivnik));
    bool x(Mnozenje(r1.brojnik, r2.nazivnik/r));
    bool y(Mnozenje(r2.brojnik, r1.nazivnik/r));
    bool z(Sabiranje(x, y));
    bool k(Mnozenje(r1.nazivnik, r2.nazivnik/r));
    if(z==false || k==false) throw std::overflow_error("Nemoguce dobiti tacan rezultat");
    long long int b(r1.brojnik*int(r2.nazivnik/r)+r2.brojnik*int(r1.nazivnik/r));
    long long int n(r1.nazivnik*int(r2.nazivnik/r));
    Razlomak zbir(b, n);
    return zbir;
}

Razlomak operator-(const Razlomak &r1, const Razlomak &r2) {
    int r(r1.NZD(r1.nazivnik, r2.nazivnik));
    bool x(Mnozenje(r1.brojnik, r2.nazivnik/r));
    bool y(Mnozenje(r2.brojnik, r1.nazivnik/r));
    bool z(Oduzimanje(x, y));
    bool k(Mnozenje(r1.nazivnik, r2.nazivnik/r));
    if(z==false || k==false) throw std::overflow_error("Nemoguce dobiti tacan rezultat");
    long long int b(r1.brojnik*int(r2.nazivnik/r)-r2.brojnik*int(r1.nazivnik/r));
    long long int n(r1.nazivnik*int(r2.nazivnik/r));
    Razlomak razlika(b, n);
    return razlika;
}

Razlomak operator*(const Razlomak &r1, const Razlomak &r2) {
    int s(r1.NZD(r1.brojnik, r2.nazivnik));
    int t(r1.NZD(r2.brojnik, r1.nazivnik));
    bool x(Mnozenje(r1.brojnik/s, r2.brojnik/t));
    bool y(Mnozenje(r1.nazivnik/t, r2.nazivnik/s));
    if(x==false || y==false) throw std::overflow_error("Nemoguce dobiti tacan rezultat");
    long long int b(int(r1.brojnik/s)*int(r2.brojnik/t)); 
    long long int n(int(r1.nazivnik/t)*int(r2.nazivnik/s));
    Razlomak proizvod(b, n);
    return proizvod;
}

Razlomak operator/(const Razlomak &r1, const Razlomak &r2) {
    int r(r1.NZD(r1.nazivnik, r2.nazivnik));
    int u(r1.NZD(r1.brojnik, r2.brojnik));
    bool x(Mnozenje(r1.brojnik/u, r2.nazivnik/r));
    bool y(Mnozenje(r1.nazivnik/r, r2.brojnik/u));
    if(x==false || y==false) throw std::overflow_error("Nemoguce dobiti tacan rezultat");
    long long int b(int(r1.brojnik/u)*int(r2.nazivnik/r));
    long long int n(int(r1.nazivnik/r)*int(r2.brojnik/u));
    Razlomak kolicnik(b, n);
    return kolicnik;
}

Razlomak &operator-(Razlomak &r) {
    if(r.brojnik==std::numeric_limits<long long int>::min()) throw std::overflow_error("Nemoguce dobiti tacan rezultat");
    r.brojnik=-r.brojnik;
    return r;
}

Razlomak &operator+=(Razlomak &r1, const Razlomak &r2) {
    Razlomak pomocni(r1);
    try {
        r1=pomocni+r2;
    } catch(std::overflow_error izuzetak) {
        throw izuzetak;
    }
    return r1;
}

Razlomak &operator-=(Razlomak &r1, const Razlomak &r2) {
    Razlomak pomocni(r1);
    r1=pomocni-r2;
    return r1;
}

Razlomak &operator*=(Razlomak &r1, const Razlomak &r2) {
    Razlomak pomocni(r1);
    r1=pomocni*r2;
    return r1;
}

Razlomak &operator/=(Razlomak &r1, const Razlomak &r2) {
    Razlomak pomocni(r1);
    r1=pomocni/r2;
    return r1;
}

Razlomak &operator++(Razlomak &r) {
    r+=1;
    return r;
}

Razlomak operator++(Razlomak &r, int) {
    Razlomak pomocni(r);
    ++r;
    return pomocni;
}

Razlomak &operator--(Razlomak &r) {
    r-=1;
    return r;
}

Razlomak operator--(Razlomak &r, int) {
    Razlomak pomocni(r);
    --r;
    return pomocni;
}

bool operator<(const Razlomak &r1, const Razlomak &r2) {
    long double razlomak1(r1.brojnik/r1.nazivnik);
    long double razlomak2(r2.brojnik/r2.nazivnik);
    return razlomak1<razlomak2;
}

bool operator>(const Razlomak &r1, const Razlomak &r2) {
    long double razlomak1(r1.brojnik/r1.nazivnik);
    long double razlomak2(r2.brojnik/r2.nazivnik);
    return razlomak1>razlomak2;
}

bool operator<=(const Razlomak &r1, const Razlomak &r2) {
    long double razlomak1(r1.brojnik/r1.nazivnik);
    long double razlomak2(r2.brojnik/r2.nazivnik);
    return razlomak1<=razlomak2;
}

bool operator>=(const Razlomak &r1, const Razlomak &r2) {
    long double razlomak1(r1.brojnik/r1.nazivnik);
    long double razlomak2(r2.brojnik/r2.nazivnik);
    return razlomak1>=razlomak2;
}

bool operator==(const Razlomak &r1, const Razlomak &r2) {
    if(r1.brojnik==r2.brojnik && r1.nazivnik==r2.nazivnik) return true;
    return false;
}

inline bool operator!=(const Razlomak &r1, const Razlomak &r2) {
    return (!(r1==r2));
}

std::ostream &operator<<(std::ostream &tok, const Razlomak &r1) {
    tok << r1.brojnik;
    if(r1.nazivnik==1) return tok;
    tok << "/" << r1.nazivnik;
    return tok;
}

std::istream &operator>>(std::istream &tok, Razlomak &r1) {
    char znak('/');
    if(tok.peek()<'0' && tok.peek()>'9') { tok.setstate(std::ios::failbit); return tok; }
    tok >> std::ws >> r1.brojnik;
    if(tok.peek()!='/') {
        r1.nazivnik=1;
    }
    else {
        if(tok.peek()!='/') { tok.setstate(std::ios::failbit); return tok; }
        tok >> znak;
        if(tok.peek()<'0' && tok.peek()>'9') { tok.setstate(std::ios::failbit); return tok; }
        tok >> std::ws >> r1.nazivnik;
        if(tok.peek()!='\n' && tok.peek()!='\t' && tok.peek()!='\v' && tok.peek()!='\f' && tok.peek()!=' ') tok.setstate(std::ios::failbit);
    }
    r1=Razlomak(r1.brojnik, r1.nazivnik);
    return tok;
}

Razlomak::operator long double() const {
    return brojnik*(1.)/nazivnik;
}

int main () {
    Razlomak a{237, 3012};
    Razlomak b(1, 1);
    Razlomak c;
    Razlomak d(234, -8);
    std::cin >> c;
    std::cout << c << std::endl;
    Razlomak zbir(a+b), razlika(c-=b), proizvod(c*=b), kolicnik(b/a);
    std::cout << zbir << " " << c << " " << -proizvod << " " << +kolicnik << std::endl;
    if(a==b) std::cout << a << std::endl;
    else { std::cout << b-- << " " << --a << " " << c--; }
    if(b>a) std::cout << b.DajBrojnik() << std::endl;
	return 0;
}