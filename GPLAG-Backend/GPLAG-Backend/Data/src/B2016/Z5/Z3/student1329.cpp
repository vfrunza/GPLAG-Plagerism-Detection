#include <iostream>
#include <stdexcept>
#include <limits>

class Razlomak {
    long long int brojnik, nazivnik;
    static long long int nzd(long long int brojnik, long long int nazivnik);
    static void TestirajPrekoracenjePlus(const long long int x,const long long int y);
    static void TestirajPrekoracenjeMinus(const long long int x, const long long int y);
    static void TestirajPrekoracenjeMnozenje(const long long int x, const long long int y);
public:
    Razlomak(long long int brojnik = 0, long long int nazivnik = 1);
    
    long long int DajBrojnik() const { return brojnik; }
    long long int DajNazivnik() const { return nazivnik; }
    
    friend Razlomak operator + (const Razlomak &r1, const Razlomak &r2);
    friend Razlomak operator - (const Razlomak &r1, const Razlomak &r2);
    friend Razlomak operator * (const Razlomak &r1, const Razlomak &r2);
    friend Razlomak operator / (const Razlomak &r1, const Razlomak &r2);
    
    Razlomak &operator + ();
    Razlomak &operator - ();
    Razlomak &operator += (const Razlomak &r1);
    Razlomak &operator -= (const Razlomak &r1);
    Razlomak &operator *= (const Razlomak &r1);
    Razlomak &operator /= (const Razlomak &r1);
    Razlomak &operator ++ ();
    Razlomak &operator -- ();
    Razlomak operator ++ (int);
    Razlomak operator -- (int);
    
    friend bool operator > (const Razlomak &r1, const Razlomak &r2);
    friend bool operator < (const Razlomak &r1, const Razlomak &r2);
    friend bool operator >= (const Razlomak &r1, const Razlomak &r2);
    friend bool operator <= (const Razlomak &r1, const Razlomak &r2);
    friend bool operator == (const Razlomak &r1, const Razlomak &r2);
    friend bool operator != (const Razlomak &r1, const Razlomak &r2);
    
    friend std::ostream &operator << (std::ostream &tok, const Razlomak &r1);
    friend std::istream &operator >> (std::istream &tok, Razlomak &r1);
    
    operator long double();
};

void Razlomak::TestirajPrekoracenjePlus(long long int x, long long int y) {
    if((y > 0 && x > std::numeric_limits<long long int>::max() - y) || (y < 0 && x < std::numeric_limits<long long int>::min() - y))
        throw std::overflow_error("Nemoguce dobiti tacan rezultat");
}

void Razlomak::TestirajPrekoracenjeMinus(long long int x, long long int y) {
    TestirajPrekoracenjePlus(x, -1 * y);
}

void Razlomak::TestirajPrekoracenjeMnozenje(long long int x, long long int y) {
    if(y > 0 && (x < std::numeric_limits<long long int>::min() / y || x > std::numeric_limits<long long int>::max() / y))
        throw std::overflow_error("Nemoguce dobiti tacan rezultat");
    else if(y < 0 && ((x == std::numeric_limits<long long int>::min()) || (-1 * x > std::numeric_limits<long long int>::max() / (-1 * y)) || (-1 * x < std::numeric_limits<long long int>::min() / (-1 * y))))
        throw std::overflow_error("Nemoguce dobiti tacan rezultat");
}

long long int Razlomak::nzd(long long int brojnik, long long int nazivnik) {
    return (nazivnik == 0) ? brojnik : nzd(nazivnik, brojnik % nazivnik);
}

Razlomak::Razlomak(long long int brojnik, long long int nazivnik) {
    if(nazivnik == 0) throw std::logic_error("Nekorektan razlomak");
    Razlomak::brojnik = brojnik; Razlomak::nazivnik = nazivnik;
    long long int najmanji(nzd(Razlomak::brojnik, Razlomak::nazivnik));
    if(najmanji != 0) {
        Razlomak::brojnik /= najmanji; Razlomak::nazivnik /= najmanji;
    }
    if(Razlomak::nazivnik < 0) { 
        if(Razlomak::nazivnik == std::numeric_limits<long long int>::min() || Razlomak::brojnik == std::numeric_limits<long long int>::min())
            throw std::overflow_error("Nemoguce dobiti tacan rezultat");
        Razlomak::nazivnik *= -1; Razlomak::brojnik *= -1; 
    } // ovdje moze brojnik otici u -
}

Razlomak operator + (const Razlomak &r1, const Razlomak &r2) {
    Razlomak r3(r1); return r3 += r2;
}

Razlomak &Razlomak::operator += (const Razlomak &r1) {
    auto r(nzd(nazivnik, r1.nazivnik));
    
    TestirajPrekoracenjeMnozenje(r1.brojnik,nazivnik/r);
    TestirajPrekoracenjeMnozenje(r1.nazivnik,nazivnik/r);
    TestirajPrekoracenjeMnozenje(brojnik, r1.nazivnik/r);
    TestirajPrekoracenjePlus(r1.brojnik * (nazivnik/r), brojnik *(r1.nazivnik /r));

    Razlomak r2(brojnik * (r1.nazivnik / r) + r1.brojnik * (nazivnik / r), nazivnik * (r1.nazivnik / r));
    (*this) = r2;
    return *this;
}

Razlomak operator - (const Razlomak &r1, const Razlomak &r2) {
    Razlomak r3(r1); return r3 -= r2;
}

Razlomak &Razlomak::operator -= (const Razlomak &r1) {
    auto r(nzd(nazivnik, r1.nazivnik));
    
    TestirajPrekoracenjeMnozenje(r1.brojnik,nazivnik/r);
    TestirajPrekoracenjeMnozenje(r1.nazivnik,nazivnik/r);
    TestirajPrekoracenjeMnozenje(brojnik, r1.nazivnik/r);
    TestirajPrekoracenjeMinus(r1.brojnik * (nazivnik/r), brojnik *(r1.nazivnik /r));
    
    Razlomak r2(brojnik * (r1.nazivnik / r) - r1.brojnik * (nazivnik / r), nazivnik * (r1.nazivnik / r));
    (*this) = r2;
    return *this;
}

Razlomak operator * (const Razlomak &r1, const Razlomak &r2) {
    Razlomak r3(r1); return r3 *= r2;
}

Razlomak &Razlomak::operator *= (const Razlomak &r1) {
    auto s(nzd(brojnik, r1.nazivnik)), t(nzd(r1.brojnik, nazivnik));
    
    TestirajPrekoracenjeMnozenje(r1.brojnik/s,brojnik/t);
    TestirajPrekoracenjeMnozenje(r1.nazivnik/t,nazivnik/s);
    
    Razlomak r2((brojnik / s) * (r1.brojnik / t), (nazivnik / t) * (r1.nazivnik / s));
    (*this) = r2;
    return *this;
}

Razlomak operator / (const Razlomak &r1, const Razlomak &r2) {
    Razlomak r3(r1); return r3 /= r2;
}

Razlomak &Razlomak::operator /= (const Razlomak &r1) {
    auto r(nzd(nazivnik, r1.nazivnik)), u(nzd(brojnik, r1.brojnik));
    
    TestirajPrekoracenjeMnozenje(r1.brojnik/u,brojnik/r);
    TestirajPrekoracenjeMnozenje(r1.nazivnik/r,nazivnik/u);
    
    Razlomak r2((brojnik / u) * (r1.nazivnik / r), (nazivnik / r) * (r1.brojnik / u));
    (*this) = r2;
    return *this;
}

Razlomak &Razlomak::operator + () {
    return *this;
}

Razlomak &Razlomak::operator - () {
    return *this *= -1;
}

Razlomak &Razlomak::operator ++ () {
    (*this) += 1;
    return *this;
}

Razlomak &Razlomak::operator -- () {
    (*this) -= 1;
    return *this;
}

Razlomak Razlomak::operator ++ (int) {
    auto r(*this);
    ++(*this);
    return r;
}

Razlomak Razlomak::operator -- (int) {
    auto r(*this);
    --(*this);
    return r;
}

bool operator > (const Razlomak &r1, const Razlomak &r2) {
    long double prvi((long double)r1.brojnik / r1.nazivnik), drugi((long double)r2.brojnik / r2.nazivnik);
    if(prvi - drugi <= 0) return false;
    return true;
}

bool operator < (const Razlomak &r1, const Razlomak &r2) {
    long double prvi((long double)r1.brojnik / r1.nazivnik), drugi((long double)r2.brojnik / r2.nazivnik);
    if(drugi - prvi <= 0) return false;
    return true;
}

bool operator >= (const Razlomak &r1, const Razlomak &r2) {
    return r1 > r2 || r1 == r2;
}

bool operator <= (const Razlomak &r1, const Razlomak &r2) {
    return r1 < r2 || r1 == r2;
}
    
bool operator == (const Razlomak &r1, const Razlomak &r2) {
    return r1.brojnik == r2.brojnik && r1.nazivnik == r2.nazivnik;
}

bool operator != (const Razlomak &r1, const Razlomak &r2) {
    return !(r1 == r2);
}
    
std::ostream &operator << (std::ostream &tok, const Razlomak &r1) {
    return (r1.nazivnik == 1) ? std::cout << r1.brojnik : std::cout << r1.brojnik << "/" << r1.nazivnik;
}
std::istream &operator >> (std::istream &tok, Razlomak &r1) {
    r1.brojnik = 0; r1.nazivnik = 1;
    tok >> r1.brojnik;
    if(tok.peek() != '\n' && tok.peek() != '\t' && tok.peek() != ' ' && tok.peek() != '\f' && tok.peek() != '\v' && tok.peek() != '\r' && tok.peek() != EOF) {
        tok >> std::ws;
        char znak(tok.get());
        if(znak == '/') {
            tok >> std::ws >> r1.nazivnik;
            if(tok.peek() != '\n' && tok.peek() != '\t' && tok.peek() != ' ' && tok.peek() != '\f' && tok.peek() != '\v' && tok.peek() != '\r' && tok.peek() != EOF) { tok.setstate(std::ios::failbit); return tok; }
        }
        else { tok.setstate(std::ios::failbit); return tok; }
    }
    r1 = Razlomak(r1.brojnik, r1.nazivnik);
    return tok;
}

Razlomak::operator long double() {
    return (long double)brojnik / (long double)nazivnik;
}

int main() {
    
    Razlomak r1, r2;
    std::cin >> r1 >> r2;
    std::cout << r1 << " " << r2;
}