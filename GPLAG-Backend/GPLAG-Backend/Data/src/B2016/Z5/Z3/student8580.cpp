/B16/17 (Zadaća 5, Zadatak 3)
//Autotestovi by Enil Pajic (mail: epajic1@etf.unsa.ba)
//Za autotestove se obracati *iskljucivo* osobi koja ih pise
#include <iostream>
#include <stdexcept>
#include <limits>
#include <initializer_list>
#include <cmath>

bool UslovSabiranje(long long int x, long long int y) {
    long long int m = std::numeric_limits<long long int>::min(), M = std::numeric_limits<long long int>::max();
    if(y > 0) 
        if(x > M-y) throw std::overflow_error("Nemoguce dobiti tacan rezultat");
    if(y < 0)
        if(x < m-y) throw std::overflow_error("Nemoguce dobiti tacan rezultat");
    return true;
}

bool UslovMnozenje(long long int x, long long int y) {
    long long int m = std::numeric_limits<long long int>::min(), M = std::numeric_limits<long long int>::max();
    if(y > 0) 
        if(x < m/y || x > M/y) throw std::overflow_error("Nemoguce dobiti tacan rezultat");
    if(y < 0)
        if(x == m || x*(-1) > M/(y*(-1)) || x*(-1) < m/(y*(-1))) throw std::overflow_error("Nemoguce dobiti tacan rezultat");
    return true;
}

class Razlomak {
    long long int brojnik;
    long long int nazivnik;
    static long long int NZD(long long int p, long long int q);
public:
    Razlomak() : brojnik(0), nazivnik(1) {}
    Razlomak(long long int b) : brojnik(b), nazivnik(1) {}
    Razlomak(long long int b, long long int n);
    Razlomak(std::initializer_list<long long int> lista);
    long long int DajBrojnik() const { return brojnik; }
    long long int DajNazivnik() const { return nazivnik; }
    friend Razlomak operator+(const Razlomak &prvi, const Razlomak &drugi);
    friend Razlomak operator-(const Razlomak &prvi, const Razlomak &drugi);
    friend Razlomak operator*(const Razlomak &prvi, const Razlomak &drugi);
    friend Razlomak operator/(const Razlomak &prvi, const Razlomak &drugi);
    friend Razlomak &operator+(const Razlomak &r);
    friend Razlomak &operator-(const Razlomak &r);
    friend Razlomak &operator+=(Razlomak &prvi, const Razlomak &drugi);
    friend Razlomak &operator-=(Razlomak &prvi, const Razlomak &drugi);
    friend Razlomak &operator*=(Razlomak &prvi, const Razlomak &drugi);
    friend Razlomak &operator/=(Razlomak &prvi, const Razlomak &drugi);
    friend inline Razlomak &operator++(Razlomak &r);
    friend inline Razlomak operator++(Razlomak &r, int);
    friend bool operator<(const Razlomak &prvi, const Razlomak &drugi);
    friend bool operator>(const Razlomak &prvi, const Razlomak &drugi);
    friend bool operator<=(const Razlomak &prvi, const Razlomak &drugi);
    friend bool operator>=(const Razlomak &prvi, const Razlomak &drugi);
    friend bool operator==(const Razlomak &prvi, const Razlomak &drugi);
    friend inline bool operator!=(const Razlomak &prvi, const Razlomak &drugi);
    friend std::ostream &operator<<(std::ostream &tok, const Razlomak &r);
    friend std::istream &operator>>(std::istream &tok, Razlomak &r);
    operator long double() const;
};

long long int Razlomak::NZD(long long int p, long long int q) {
    if(q == 0) return p;
    long long int n = NZD(q, p%q);
    return n;
}
Razlomak::Razlomak(long long int b, long long int n) {
    if(n == 0) throw std::logic_error("Nekorektan razlomak");
    long long int nzd = NZD(b,n);
    if(n < 0) {
        n *= -1;
        b *= -1;
    }
    b /= nzd;
    n /= nzd;
    brojnik = b;
    nazivnik = n;
}
Razlomak::Razlomak(std::initializer_list<long long int> lista) {
    if(lista.size() == 0) { brojnik = 0; nazivnik = 1; }
    else {
        auto it = lista.begin();
        brojnik = *it;
        if(lista.size() == 2) {
            it++;
            nazivnik = *it;
        }
        else nazivnik = 1;
    }
    if(nazivnik < 0) {
        nazivnik *= -1;
        brojnik *= -1;
    }
    long long int nzd = NZD(brojnik, nazivnik);
    brojnik /= nzd;
    nazivnik /= nzd;
}
Razlomak operator+(const Razlomak &prvi, const Razlomak &drugi) {
    long long int r = prvi.NZD(prvi.nazivnik, drugi.nazivnik);
    try {
        bool pom_x = UslovMnozenje(prvi.brojnik, drugi.nazivnik/r);
        bool pom_y = UslovMnozenje(drugi.brojnik, prvi.nazivnik/r);
        bool pomocna = UslovSabiranje(pom_x, pom_y);
        pomocna = UslovMnozenje(prvi.nazivnik, drugi.nazivnik/r);
    }
    catch(std::overflow_error) {
        throw std::overflow_error("Nemoguce dobiti tacan rezultat");
    }
    
    
    long long int b,n;
    b = prvi.brojnik * (drugi.nazivnik/r) + drugi.brojnik * (prvi.nazivnik/r);
    n = prvi.nazivnik * (drugi.nazivnik/r);
    Razlomak novi(b,n);
    return novi;
}
Razlomak operator-(const Razlomak &prvi, const Razlomak &drugi) {
    long long int r = prvi.NZD(prvi.nazivnik, drugi.nazivnik);
    try {
       bool pom_x = UslovMnozenje(prvi.brojnik, drugi.nazivnik/r);
       bool pom_y = UslovMnozenje(drugi.brojnik, prvi.nazivnik/r);
       bool pomocna = UslovSabiranje(pom_x, pom_y * (-1));
       pomocna = UslovMnozenje(prvi.nazivnik, drugi.nazivnik/r);
    }
    catch(std::overflow_error) {
        throw std::overflow_error("Nemoguce dobiti tacan rezultat");
    }
    long long int b, n;
    b = prvi.brojnik * (drugi.nazivnik/r) - drugi.brojnik * (prvi.nazivnik/r);
    n = prvi.nazivnik * (drugi.nazivnik/r);
    Razlomak novi(b,n);
    return novi;
}
Razlomak operator*(const Razlomak &prvi, const Razlomak &drugi) {
    long long int b, n, s = prvi.NZD(prvi.brojnik, drugi.nazivnik), t = prvi.NZD(prvi.nazivnik, drugi.brojnik);
    try {
        bool pomocna = UslovMnozenje(prvi.brojnik/s, drugi.brojnik/t);
        pomocna = UslovMnozenje(prvi.nazivnik/t, drugi.nazivnik/s);
    }
    catch(std::overflow_error) {
        throw std::overflow_error("Nemoguce dobiti tacan rezultat");
    }
    b = (prvi.brojnik/s) * (drugi.brojnik/t);
    n = (prvi.nazivnik/t) * (drugi.nazivnik/s);
    Razlomak novi(b,n);
    return novi;
}
Razlomak operator/(const Razlomak &prvi, const Razlomak &drugi) {
    long long int b, n, u = prvi.NZD(prvi.brojnik, prvi.nazivnik), r = prvi.NZD(drugi.brojnik, drugi.nazivnik);
    try {
       bool pomocna = UslovMnozenje(prvi.brojnik/u, drugi.nazivnik/r);
       pomocna = UslovMnozenje(prvi.nazivnik/r, drugi.brojnik/u);
    }
    catch(std::overflow_error) {
        throw std::overflow_error("Nemoguce dobiti tacan rezultat");
    }
    b = (prvi.brojnik/u) * (drugi.nazivnik/r);
    n = (prvi.nazivnik/r) * (drugi.brojnik/u);
    Razlomak novi(b,n);
    return novi;
}
Razlomak &operator+(Razlomak &r) {
    return r;
}
Razlomak &operator-(Razlomak &r) {
    if(r.DajBrojnik() == std::numeric_limits<long long int>::min()) throw std::overflow_error("Nemoguce dobiti tacan rezultat");
    Razlomak novi(r.DajBrojnik()*(-1), r.DajNazivnik());
    r = novi;
    return r;
}
Razlomak &operator+=(Razlomak &prvi, const Razlomak &drugi) {
    Razlomak novi(prvi.DajBrojnik(), prvi.DajNazivnik());
    prvi = novi + drugi;
    return prvi;
}
Razlomak &operator-=(Razlomak &prvi, const Razlomak &drugi) {
    Razlomak novi(prvi.DajBrojnik(), prvi.DajNazivnik());
    prvi = novi - drugi;
    return prvi;
}
Razlomak &operator*=(Razlomak &prvi, const Razlomak &drugi) {
    Razlomak novi(prvi.DajBrojnik(), prvi.DajNazivnik());
    prvi = novi * drugi;
    return prvi;
}
Razlomak &operator/=(Razlomak &prvi, const Razlomak &drugi) {
    Razlomak novi(prvi.DajBrojnik(), prvi.DajNazivnik());
    prvi = novi / drugi;
    return prvi;
}
inline Razlomak &operator++(Razlomak &r) {
    Razlomak novi(1,1);
    r += novi;
    return r;
}
inline Razlomak operator++(Razlomak &r, int) {
    Razlomak pomocni(r.DajBrojnik(), r.DajNazivnik());
    Razlomak novi(1,1);
    r += novi;
    return pomocni;
}
bool operator<(const Razlomak &prvi, const Razlomak &drugi) {
    long double p = prvi.DajBrojnik()/prvi.DajNazivnik();
    long double q = drugi.DajBrojnik()/drugi.DajNazivnik();
    if(p < q) return true;
    return false;
}
bool operator>(const Razlomak &prvi, const Razlomak &drugi) {
    long double p = (long double)prvi.DajBrojnik()/prvi.DajNazivnik();
    long double q = (long double)drugi.DajBrojnik()/drugi.DajNazivnik();
    if(p > q) return true;
    return false;
}
bool operator<=(const Razlomak &prvi, const Razlomak &drugi) {
    long double p = (long double)prvi.DajBrojnik()/prvi.DajNazivnik();
    long double q = (long double)drugi.DajBrojnik()/drugi.DajNazivnik();
    if(p <= q) return true;
    return false;
}
bool operator>=(const Razlomak &prvi, const Razlomak &drugi) {
    long double p = (long double)prvi.DajBrojnik()/prvi.DajNazivnik();
    long double q = (long double)drugi.DajBrojnik()/drugi.DajNazivnik();
    if(p >= q) return true;
    return false;
}
bool operator==(const Razlomak &prvi, const Razlomak &drugi) {
    long double p = (long double)prvi.DajBrojnik()/prvi.DajNazivnik();
    long double q = (long double)drugi.DajBrojnik()/drugi.DajNazivnik();
    if(p == q) return true;
    return false;
}
inline bool operator!=(const Razlomak &prvi, const Razlomak &drugi) {
    if(!(prvi == drugi)) return true;
    return false;
}
std::ostream &operator<<(std::ostream &tok, const Razlomak &r) {
    if(r.DajNazivnik() == 1) {
        tok << r.DajBrojnik(); return tok;
    }
    tok << r.DajBrojnik() << "/" << r.DajNazivnik();
    return tok;
}
std::istream &operator>>(std::istream &tok, Razlomak &r) {
    int c = (tok >> std::ws).peek();
    char znak;
    if(!std::isdigit(c)) tok.setstate(std::ios::failbit);
    tok >> r.brojnik;
    c = tok.peek();
    if(c == '/') {
        tok >> znak;
        c = tok.peek();
        if(!std::isdigit(c)) tok.setstate(std::ios::failbit);
        tok >> r.nazivnik;
        long long int nzd = Razlomak::NZD(r.brojnik,r.nazivnik);
        r.brojnik /= nzd;
        r.nazivnik /= nzd;
        c = tok.peek();
        if(c == '\n' || c == '\f' || c == '\t' || c == '\v' || c == ' ' || c == EOF) return tok;
        else tok.setstate(std::ios::failbit);
    }
    else if(c == '\n' || c == '\f' || c == '\t' || c == '\v' || c == ' ' || c == EOF) r.nazivnik = 1;
    
    else tok.setstate(std::ios::failbit);
    
    return tok;
}
Razlomak::operator long double() const {
    long double r = (long double)brojnik/nazivnik;
    return r;
}

int main ()
{
    Razlomak r;
    std::cout << "unesi: " << std::endl;
    std::cin >> r;
    std::cout << "!- " << r <<std::endl;
    std::cin.clear();
    std::cin >> r;
    std::cout << "!- " << r << std::endl;
    std::cin >> r;
    std::cout << r;
	return 0;
}