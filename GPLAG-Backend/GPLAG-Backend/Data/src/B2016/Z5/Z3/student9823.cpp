/B16/17 (Zadaća 5, Zadatak 3)
//Autotestovi by Enil Pajic (mail: epajic1@etf.unsa.ba)
//Za autotestove se obracati *iskljucivo* osobi koja ih pise
#include <iostream>
#include <stdexcept>
#include <limits>
const long long M = std::numeric_limits<long long>::max(); 
const long long m = std::numeric_limits<long long>::lowest(); 

class Razlomak {
    long long brojnik, nazivnik;
    static long long int NZD(long long p, long long q){
        if(q == 0) return p;
        return NZD(q, p%q);
    }                                                                   
    static long long int saberi(long long a, long long b){      
         if(b > 0 && a > M - b) throw std::overflow_error("Nemoguce dobiti tacan rezultat");
         if(b < 0 && a < m - b) throw std::overflow_error("Nemoguce dobiti tacan rezultat");
         return a+b;
    }                                                       
    static long long int oduzmi(long long a, long long b){
         if(b > 0 && a > m - b) throw std::overflow_error("Nemoguce dobiti tacan rezultat");
         if(b < 0 && a < M - b) throw std::overflow_error("Nemoguce dobiti tacan rezultat");
         return a-b;
    }
    static long long int pomnozi(long long a, long long b){
         if(b > 0 && (a < m / b || a > M / b)) throw std::overflow_error("Nemoguce dobiti tacan rezultat");
         if(b < 0 && (a == m || -a > M / (-b) || -a < m /(-b))) throw std::overflow_error("Nemoguce dobiti tacan rezultat");
         return a*b;
    }
    static long long int podjeli(long long a, long long b){
         return a/b;
    }
public:
    Razlomak(long long a = 0, long long b = 1);
    Razlomak(std::initializer_list<long long> lista);
    long long DajBrojnik() const { return brojnik; }
    long long DajNazivnik() const { return nazivnik; }
    friend Razlomak operator +(const Razlomak &a, const Razlomak &b);
    friend Razlomak operator -(const Razlomak &a, const Razlomak &b);
    friend Razlomak operator *(const Razlomak &a, const Razlomak &b);
    friend Razlomak operator /(const Razlomak &a, const Razlomak &b);
    friend Razlomak operator -(const Razlomak &a);
    friend Razlomak operator +(const Razlomak &a);
    Razlomak operator +=(const Razlomak &b);
    Razlomak operator -=(const Razlomak &b);
    Razlomak operator *=(const Razlomak &b);
    Razlomak operator /=(const Razlomak &b);
    Razlomak &operator ++();
    Razlomak operator ++(int);
    Razlomak &operator --();
    Razlomak operator --(int);
    friend bool operator <(const Razlomak &a, const Razlomak &b);
    friend bool operator <=(const Razlomak &a, const Razlomak &b);
    friend bool operator >(const Razlomak &a, const Razlomak &b);
    friend bool operator >=(const Razlomak &a, const Razlomak &b);
    friend bool operator ==(const Razlomak &a, const Razlomak &b);
    friend bool operator !=(const Razlomak &a, const Razlomak &b);
    friend std::ostream &operator << (std::ostream& ispis, Razlomak m);
    friend std::istream &operator >> (std::istream& ispis, Razlomak &m);
    operator long double() const;
};

Razlomak::Razlomak(long long a, long long b) {
        if(b == 0) throw std::logic_error("Nekorektan razlomak");
        bool jeste(false);
        if (a < 0) { a*= -1; jeste = true; }
        if (b < 0) { b*= -1; jeste = false; }
        if(a == 0) { brojnik = 0; nazivnik = 1; }
        else if(b == 1) { brojnik = a; nazivnik = 1; }
        else {
            long long t = NZD(a, b);
            a/=t; b/=t;
            if(jeste) brojnik = -a; else brojnik = a; 
            nazivnik = b;
        }
    }

Razlomak::Razlomak(std::initializer_list<long long> lista) {
    auto it(lista.begin());
    if(lista.size() == 0) { brojnik = 0; nazivnik = 1; }
    else if(lista.size() == 1) { brojnik = *it; nazivnik = 1; }
    else if(lista.size() == 2) { brojnik = *it++; nazivnik = *it; }
    
    long long a(brojnik), b(nazivnik);
    if(b == 0) throw std::logic_error("Nekorektan razlomak");
    bool jeste(false);
    if (a < 0) { a*= -1; jeste = true; }
    if (b < 0) { b*= -1; jeste = false; }
    if(a == 0) { brojnik = 0; nazivnik = 1; }
    else if(b == 1) { brojnik = a; nazivnik = 1; }
    else {
            long long t = NZD(a, b);
            a/=t; b/=t;
            if(jeste) brojnik = -a; else brojnik = a; 
            nazivnik = b;
    }
}
    
Razlomak operator +(const Razlomak &a, const Razlomak &b) {
    long long int br, naz;
        long long r = Razlomak::NZD(a.nazivnik, b.nazivnik);
        try {
            br = Razlomak::saberi(Razlomak::pomnozi(a.brojnik, Razlomak::podjeli(b.nazivnik , r)), Razlomak::pomnozi(b.brojnik,Razlomak::podjeli(a.nazivnik , r)));
            naz = Razlomak::pomnozi(a.nazivnik, Razlomak::podjeli(b.nazivnik , r));
        }catch(...){
            throw std::overflow_error("Nemoguce dobiti tacan rezultat");
        }
        return {br, naz};
}

Razlomak operator -(const Razlomak &a, const Razlomak &b) {
        long long brjnik, naznvik;
        long long r = Razlomak::NZD(a.nazivnik, b.nazivnik);
        try {
            brjnik = Razlomak::oduzmi(Razlomak::pomnozi(a.brojnik, Razlomak::podjeli(b.nazivnik , r)), Razlomak::pomnozi(b.brojnik, Razlomak::podjeli(a.nazivnik , r)));
            naznvik = Razlomak::pomnozi(a.nazivnik, Razlomak::podjeli( b.nazivnik , r));
        } catch(...){
            throw std::overflow_error("Nemoguce dobiti tacan rezultat");
        }
        return Razlomak(brjnik, naznvik);
}

Razlomak operator *(const Razlomak &a, const Razlomak &b) {
    long long brjnik, naznvik;
        long long t = Razlomak::NZD(b.brojnik, a.nazivnik);
        long long s = Razlomak::NZD(a.brojnik, b.nazivnik);
        try {
            brjnik = Razlomak::pomnozi(Razlomak::podjeli(a.brojnik , s) , Razlomak::podjeli(b.brojnik, t));
            naznvik = Razlomak::pomnozi(Razlomak::podjeli(a.nazivnik, t), Razlomak::podjeli(b.nazivnik , s));
        }catch(...){
            throw std::overflow_error("Nemoguce dobiti tacan rezultat");
        }
        return Razlomak(brjnik, naznvik);
}

Razlomak operator /(const Razlomak &a, const Razlomak &b) {
            long long brjnik, naznvik;
        long long r = Razlomak::NZD(a.nazivnik, b.nazivnik);
        long long u = Razlomak::NZD(a.brojnik, b.brojnik);
        try {
            brjnik =  Razlomak::pomnozi(Razlomak::podjeli(a.brojnik, u) , Razlomak::podjeli(b.nazivnik , r));
            naznvik = Razlomak::pomnozi(Razlomak::podjeli(a.nazivnik , r) , Razlomak::podjeli(b.brojnik , u));
        }catch(...){
            throw std::overflow_error("Nemoguce dobiti tacan rezultat");
        }
        return Razlomak(brjnik, naznvik);
}

Razlomak operator -(const Razlomak &a) { 
    if(a.brojnik == m) throw std::overflow_error("Nemoguce dobiti tacan rezultat"); 
    return a - Razlomak(a.brojnik, a.nazivnik);
}

Razlomak operator +(const Razlomak &a) { 
    return a; 
}

Razlomak Razlomak::operator +=(const Razlomak &b){ 
    *this = *this + b; 
    return *this;
}

Razlomak Razlomak::operator -=(const Razlomak &b){ 
    *this = *this - b; 
    return *this;
}

Razlomak Razlomak::operator *=(const Razlomak &b){ 
    *this = *this * b; 
    return *this;
}

Razlomak Razlomak::operator /=(const Razlomak &b){ 
    *this = *this / b; 
    return *this;
}

Razlomak &Razlomak::operator ++() {
    *this += 1;
    return *this;
}

Razlomak Razlomak::operator ++(int) {
    Razlomak a(this->DajBrojnik(), this->DajNazivnik());
    ++(*this);
    return a;
}

Razlomak &Razlomak::operator --() {
    *this -= 1;
    return *this;
}

Razlomak Razlomak::operator --(int) {
    Razlomak a(this->DajBrojnik(), this->DajNazivnik());
    --(*this);
    return a;
}

bool operator <(const Razlomak &a, const Razlomak &b) {
        long double prvi(a.brojnik/a.nazivnik), drugi(b.brojnik/b.nazivnik);
        return prvi < drugi;
}

bool operator <=(const Razlomak &a, const Razlomak &b) {
        long double prvi(a.brojnik/a.nazivnik), drugi(b.brojnik/b.nazivnik);
        return prvi <= drugi;

}

bool operator >(const Razlomak &a, const Razlomak &b) {
        long double prvi(a.brojnik/a.nazivnik), drugi(b.brojnik/b.nazivnik);
        return prvi > drugi;
}

bool operator >=(const Razlomak &a, const Razlomak &b) {
        long double prvi(a.brojnik/a.nazivnik), drugi(b.brojnik/b.nazivnik);
        return prvi >= drugi;
}

bool operator ==(const Razlomak &a, const Razlomak &b) {
        long double prvi(a.brojnik/a.nazivnik), drugi(b.brojnik/b.nazivnik);
        return prvi == drugi;
}

bool operator !=(const Razlomak &a, const Razlomak &b) {
        long double prvi(a.brojnik/a.nazivnik), drugi(b.brojnik/b.nazivnik);
        return prvi != drugi;
}

std::ostream &operator << (std::ostream& ispis, Razlomak m) {
    char a = '/';
    if(m.DajNazivnik() == 1) ispis << m.DajBrojnik(); 
    else ispis << m.DajBrojnik() << a << m.DajNazivnik();
    return ispis;
}

std::istream &operator >> (std::istream& ispis, Razlomak &m) {
    long long br, naz;
    ispis >> br;
    m = Razlomak(br);
    if(ispis.peek() == '/'){
        ispis.get();
        ispis >>  naz;
        if(ispis.peek() != ' ') ispis.setstate(std::ios::failbit);
        m = Razlomak(br, naz);
    } 
    return ispis;
}

Razlomak::operator long double() const {
    return static_cast<long double>(DajBrojnik())/DajNazivnik();
}

int main ()
{
	return 0;
}