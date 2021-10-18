/B16/17 (Zadaća 5, Zadatak 3)
//Autotestovi by Enil Pajic (mail: epajic1@etf.unsa.ba)
//Za autotestove se obracati *iskljucivo* osobi koja ih pise
#include <iostream>
#include <stdexcept>
#include <limits>
#include <cmath>
#include <cstdlib>
const long long int M(std::numeric_limits<long long int>::max());
const long long int m(std::numeric_limits<long long int>::min());

class Razlomak {
    long long int brojnik, nazivnik;
    static long long int NZD(long long int a, long long int b);
    static void OverflowSabiranje(long long int a, long long int b);
    static void OverflowOduzimanje(long long int a, long long int b);
    static void OverflowMnozenje(long long int a, long long int b);
    static bool DaLiSuJednaki(long double x, long double y);
    public:
    Razlomak(long long int brojnik = 0, long long int nazivnik = 1) {
        if (!nazivnik) throw std::logic_error ("Nekorektan razlomak");
        auto visekratnik(NZD(nazivnik, brojnik));
        Razlomak::nazivnik = nazivnik/visekratnik; Razlomak::brojnik = brojnik/visekratnik;
        if (Razlomak::nazivnik < 0 && Razlomak::brojnik < 0) Razlomak::nazivnik = -Razlomak::nazivnik, Razlomak::brojnik = -Razlomak::brojnik;
        if (Razlomak::nazivnik < 0) Razlomak::nazivnik = -Razlomak::nazivnik, Razlomak::brojnik = -Razlomak::brojnik;
    }
    long long int DajBrojnik() const { return brojnik; }
    long long int DajNazivnik() const { return nazivnik; }
    friend Razlomak operator +(const Razlomak &a, const Razlomak &b);
    friend Razlomak operator -(const Razlomak &a, const Razlomak &b);
    friend Razlomak operator *(const Razlomak &a, const Razlomak &b);
    friend Razlomak operator /(const Razlomak &a, const Razlomak &b);
    Razlomak &operator -();
    Razlomak &operator +() { return *this; }
    Razlomak &operator +=(const Razlomak &r);
    Razlomak &operator -=(const Razlomak &r);
    Razlomak &operator *=(const Razlomak &r);
    Razlomak &operator /=(const Razlomak &r);
    Razlomak &operator++() { return *this = *this + Razlomak(1); }
    Razlomak operator++(int);
    Razlomak &operator--() { return *this = *this - Razlomak(1); }
    Razlomak operator--(int);
    friend bool operator >(const Razlomak &a, const Razlomak &b);
    friend bool operator <(const Razlomak &a, const Razlomak &b);
    friend bool operator >=(const Razlomak &a, const Razlomak &b);
    friend bool operator <=(const Razlomak &a, const Razlomak &b);
    friend bool operator ==(const Razlomak &a, const Razlomak &b);
    friend bool operator !=(const Razlomak &a, const Razlomak &b);
    friend std::ostream &operator <<(std::ostream &tok, const Razlomak &r);
    friend std::istream &operator >>(std::istream &tok, Razlomak &r);
    operator long double() const { return brojnik/(long double)nazivnik; };
};
Razlomak Razlomak::operator--(int) {
    Razlomak pom(DajBrojnik(), DajNazivnik());
    (*this)--;
    return pom;
}
Razlomak Razlomak::operator++(int) {
    Razlomak pom(this->DajBrojnik(), this->DajNazivnik());
    (*this)++;
    return pom;
}
std::istream &operator >>(std::istream &tok, Razlomak &r) {
    tok >> std::ws;
    if (!(tok.peek() >= '0' && tok.peek() <= '9')) {
        tok.setstate(std::ios::failbit);
        return tok;
    }
    tok >> r.brojnik;
    char c(tok.peek());
    if (c == EOF || c == '\t' || c == '\n' || c == '\f' || c == '\v' || c == '\r' || c == ' ') {
        r = {r.brojnik};
    }
    else if (c != '/') {
        tok.setstate(std::ios::failbit);
        return tok;
    }
    else {
        char znak;
        tok >> znak;
        if (!(tok.peek() >= '0' && tok.peek() <= '9')) {
            tok.setstate(std::ios::failbit);
            return tok;
        }
        tok >> r.nazivnik;
        char p(tok.peek());
        if (p != EOF && p != '\t' && p != '\v' && p != '\f' && p != '\r' && p != '\n' && p != ' ') {
            tok.setstate(std::ios::failbit);
            return tok;
        }
        r = Razlomak(r.brojnik, r.nazivnik);
    }
    return tok;
}
std::ostream &operator <<(std::ostream &tok, const Razlomak &r) {
    tok << r.DajBrojnik();
    if (r.DajNazivnik() != 1) tok << "/" << r.DajNazivnik();
    return tok;
}
bool Razlomak::DaLiSuJednaki(long double x, long double y) {
    return std::fabs(x - y) <= 1e-10 * (std::fabs(x) + std::fabs(y));
}
bool operator !=(const Razlomak &a, const Razlomak &b) {
    long double x(a.DajBrojnik()/a.DajNazivnik()), y(b.DajBrojnik()/b.DajNazivnik());
    return !Razlomak::DaLiSuJednaki(x, y);
}
bool operator ==(const Razlomak &a, const Razlomak &b) {
    long double x(a.DajBrojnik()/a.DajNazivnik()), y(b.DajBrojnik()/b.DajNazivnik());
    return Razlomak::DaLiSuJednaki(x, y);
}
bool operator <=(const Razlomak &a, const Razlomak &b) {
    long double x(a.DajBrojnik()/a.DajNazivnik()), y(b.DajBrojnik()/b.DajNazivnik());
    return (x < y || Razlomak::DaLiSuJednaki(x, y));
} 
bool operator >=(const Razlomak &a, const Razlomak &b) {
    long double x(a.DajBrojnik()/a.DajNazivnik()), y(b.DajBrojnik()/b.DajNazivnik());
    return (x > y || Razlomak::DaLiSuJednaki(x, y));
}
bool operator >(const Razlomak &a, const Razlomak &b) {
    long double x(a.DajBrojnik()/a.DajNazivnik()), y(b.DajBrojnik()/b.DajNazivnik());
    return (x > y && !Razlomak::DaLiSuJednaki(x, y));
}
bool operator <(const Razlomak &a, const Razlomak &b) {
    long double x(a.DajBrojnik()/a.DajNazivnik()), y(b.DajBrojnik()/b.DajNazivnik());
    return (x < y && !Razlomak::DaLiSuJednaki(x, y));
}
Razlomak &Razlomak::operator /=(const Razlomak &r) {
    *this = *this/r;
    return *this;
}
Razlomak &Razlomak::operator *=(const Razlomak &r) {
    *this = *this * r;
    return *this;
}
Razlomak &Razlomak::operator +=(const Razlomak &r) {
    *this = *this + r;
    return *this;
}
Razlomak &Razlomak::operator -=(const Razlomak &r) {
    *this = *this - r;
    return *this;
}
Razlomak &Razlomak::operator -() {
    if (this->DajBrojnik() == m || this->DajNazivnik() == m || this->DajBrojnik()/(this->DajNazivnik()) == m) throw std::overflow_error ("Nemoguce dobiti tacan rezultat");
    return *this;
}
void Razlomak::OverflowMnozenje(long long int x, long long int y) {
    if (y > 0 && (x < m/y || x > M/y)) throw std::overflow_error ("Nemoguce dobiti tacan rezultat");
    if (y < 0 && (std::fabs(x - m) < 1e-10 || -x > M/(-y) || -x < m/(-y))) throw std::overflow_error ("Nemoguce dobiti tacan rezultat");   
}
void Razlomak::OverflowOduzimanje(long long int x, long long int y) {
    if ((y < 0 && x > M + y) || (y > 0 && x < m + y)) throw std::overflow_error ("Nemoguce dobiti tacan rezultat");
}
void Razlomak::OverflowSabiranje(long long int x, long long int y) {
    if ((y < 0 && x < m - y) || (y > 0 && x > M - y)) throw std::overflow_error ("Nemoguce dobiti tacan rezultat");  
}
Razlomak operator /(const Razlomak &a, const Razlomak &b) {
    long long int r(Razlomak::NZD(a.DajNazivnik(), b.DajNazivnik()));
    long long int u(Razlomak::NZD(a.DajBrojnik(), b.DajBrojnik()));
    long long int brojnik{(a.DajBrojnik()/u) * (b.DajNazivnik()/r)};
    long long int nazivnik{(a.DajNazivnik()/r) * (b.DajBrojnik()/u)};
    return {brojnik, nazivnik};
}
Razlomak operator *(const Razlomak &a, const Razlomak &b) {
    auto s(Razlomak::NZD(a.DajBrojnik(), b.DajNazivnik()));
    auto t(Razlomak::NZD(a.DajNazivnik(), b.DajBrojnik()));
    Razlomak::OverflowMnozenje(a.DajBrojnik()/s, b.DajBrojnik()/t);
    Razlomak::OverflowMnozenje(a.DajNazivnik()/t, b.DajNazivnik()/s);
    long long int brojnik{(a.DajBrojnik()/s) * (b.DajBrojnik()/t)};
    long long int nazivnik{(a.DajNazivnik()/t) * (b.DajNazivnik()/s)};
    return {brojnik, nazivnik};
}
Razlomak operator -(const Razlomak &a, const Razlomak &b) {
    auto r(Razlomak::NZD(a.DajNazivnik(), b.DajNazivnik()));
    Razlomak::OverflowMnozenje(a.DajBrojnik(), b.DajNazivnik()/r);
    Razlomak::OverflowMnozenje(b.DajBrojnik(), a.DajNazivnik()/r);
    Razlomak::OverflowOduzimanje(a.DajBrojnik() * (b.DajNazivnik()/r), b.DajBrojnik() * (a.DajNazivnik()/r));
    Razlomak::OverflowMnozenje(a.DajNazivnik(), b.DajNazivnik()/r);
    long long int brojnik{a.DajBrojnik() * (b.DajNazivnik()/r) - b.DajBrojnik() * (a.DajNazivnik()/r)};
    long long int nazivnik{a.DajNazivnik() * (b.DajNazivnik()/r)};
    return {brojnik, nazivnik};
}
Razlomak operator +(const Razlomak &a, const Razlomak &b) {
    auto nzd(Razlomak::NZD(a.DajNazivnik(), b.DajNazivnik()));
    Razlomak::OverflowMnozenje(a.DajBrojnik(), b.DajNazivnik()/nzd);
    Razlomak::OverflowMnozenje(b.DajBrojnik(), a.DajNazivnik()/nzd);
    Razlomak::OverflowSabiranje(a.DajBrojnik() * (b.DajNazivnik()/nzd), b.DajBrojnik() * (a.DajNazivnik()/nzd));
    Razlomak::OverflowMnozenje(a.DajNazivnik(), b.DajNazivnik()/nzd);
    long long int brojnik{a.DajBrojnik() * (b.DajNazivnik()/nzd) + b.DajBrojnik() * (a.DajNazivnik()/nzd)};
    long long int nazivnik{a.DajNazivnik() * (b.DajNazivnik()/nzd)};
    return {brojnik, nazivnik}; 
}

long long int Razlomak::NZD(long long int a, long long int b) {
    if (!b) return a;
    return Razlomak::NZD(b, a%b);
}
/*int main2() {
    {//AT7 (c9): op-, op/, op konverzije, kracenje
         //za _r pogledati 'globalni opseg' komentar i AT6
         std::cout << 10_r / 7_r - 6_r / 11_r; // 10/7 - 6/11
         std::cout << std::endl;
         std::cout << (10_r / 7_r) / (6_r / 11_r); // 10/7 / 6/11
         std::cout << std::endl;
         Razlomak r = 124_r / 4_r;
         std::cout << r;
         r = r - 11_r / 77_r;
         std::cout << std::endl;
         std::cout << r << " je priblizno " << static_cast<long double>(r);
        }
}*/
int main_ () {
       Razlomak r, p, q;
        std::cin >> r; //5/17
        std::cout << r << std::endl;
        std::cin.clear(); std::cin.ignore (100, '\n');
        //tri zaredom
        std::cin >> r >> p >> q; //10 20 30 -> 10/1 20/1 30/1
        std::cout << r << " " << p << " " << q << std::endl;
        std::cin.clear(); std::cin.ignore (100, '\n');
        std::cin >> r;
        std::cout << r;
    return 0;
}
int main ()
{
	Razlomak r(15, 10);
	Razlomak q(9);
	std::cout << "Razlomak r: " << r.DajBrojnik() << "/" << r.DajNazivnik() << std::endl;
	std::cout << "Razlomak q: " << q << std::endl;
	try {
	    std::cout << r << " + " << q << " = " << r + q << std::endl;
	    std::cout << r << " - " << q << " = " << r - q << std::endl;
	    std::cout << r << " * " << q << " = " << r * q << std::endl;
	    std::cout << r << " / " << q << " = " << r / q << std::endl;
	    --r;
	    std::cout << ++r << std::endl;
	    Razlomak a, b;
	    std::cout << "Unesite razlomak a: ";
	    std::cin >> a;
	    std::cout << "Unesite razlomak b: ";
	    std::cin >> b;
	    if (a > b) std::cout << a << " je vece od " << b;
	    else if (a < b) std::cout << a << " je manje od " << b;
	    else std::cout << a << " i " << b << " su jednaki";
	    std::cout << std::endl;
	}
	catch(std::logic_error e) {
	    std::cout << e.what() << std::endl;
	}
	catch(std::overflow_error e) {
	    std::cout << e.what() << std::endl;
	}
	return 0; 
}