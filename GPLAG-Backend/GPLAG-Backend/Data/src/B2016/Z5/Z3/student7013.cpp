/B16/17 (Zadaća 5, Zadatak 3)
//Autotestovi by Enil Pajic (mail: epajic1@etf.unsa.ba)
//Za autotestove se obracati *iskljucivo* osobi koja ih pise
#include <iostream>
#include <stdexcept>
#include <cmath>
#include <limits>
#include <sstream>
#include <cctype>

using namespace std;

#define LONGMAX numeric_limits<long long int>::max()
#define LONGMIN numeric_limits<long long int>::min()
#define EPSILON numeric_limits<long double>::epsilon()

class Razlomak {
    long long int brojnik, nazivnik;
    static long long int NZD(long long int, long long int);
public:
    Razlomak(long long int brojnik = 0, long long int nazivnik = 1);
    long long int DajBrojnik() const { return brojnik; }
    long long int DajNazivnik() const { return nazivnik; }
    friend Razlomak operator+(const Razlomak&, const Razlomak&);
    friend Razlomak operator-(const Razlomak&, const Razlomak&);
    friend Razlomak operator*(const Razlomak&, const Razlomak&);
    friend Razlomak operator/(const Razlomak&, const Razlomak&);
    Razlomak& operator+() { return *this; }
    Razlomak& operator-();
    friend Razlomak& operator+= (Razlomak& r1, const Razlomak& r2);
    friend Razlomak& operator-= (Razlomak& r1, const Razlomak& r2);
    friend Razlomak& operator*= (Razlomak& r1, const Razlomak& r2);
    friend Razlomak& operator/= (Razlomak& r1, const Razlomak& r2);
    Razlomak& operator++();
    Razlomak operator++(int);
    Razlomak& operator--();
    Razlomak operator--(int);
    friend bool operator< (const Razlomak&, const Razlomak&);
    friend bool operator> (const Razlomak&, const Razlomak&);
    friend bool operator<= (const Razlomak&, const Razlomak&);
    friend bool operator>= (const Razlomak&, const Razlomak&);
    friend bool operator== (const Razlomak&, const Razlomak&);
    friend bool operator!= (const Razlomak&, const Razlomak&);
    
    friend ostream& operator<< (ostream&, const Razlomak&);
    friend istream& operator>> (istream&, Razlomak&);
    
    operator long double() const { return (long double)brojnik / (long double)nazivnik; }
};

long long int Razlomak::NZD(long long int p, long long int q) {
    p = fabs(p); q = fabs(q);
    if(q == 0) return p;
    return NZD(q, p % q);
}

Razlomak::Razlomak(long long int brojnik, long long int nazivnik){
    if(nazivnik == 0) throw logic_error("Nekorektan razlomak");
    if(nazivnik < 0){
        nazivnik *= -1;
        brojnik *= -1;
    }
    long long int nzd = NZD(brojnik, nazivnik);
    this->brojnik = brojnik / nzd;
    this->nazivnik = nazivnik / nzd;
}

Razlomak operator+(const Razlomak& x, const Razlomak& y){
    if((y.DajBrojnik() > 0 && x.DajBrojnik() > LONGMAX - y.DajBrojnik()) || (y.DajBrojnik() < 0 && x.DajBrojnik() < LONGMIN - y.DajBrojnik()))
        throw overflow_error("Nemoguce dobiti tacan rezultat");
    if((y.DajNazivnik() > 0 && x.DajNazivnik() > LONGMAX - y.DajNazivnik()) || (y.DajNazivnik() < 0 && x.DajNazivnik() < LONGMIN - y.DajNazivnik()))
        throw overflow_error("Nemoguce dobiti tacan rezultat");
    long long int brojnik, nazivnik;
    long long int r = Razlomak::NZD(x.DajNazivnik(), y.DajNazivnik());
    brojnik = x.DajBrojnik() * (y.DajNazivnik() / r) + y.DajBrojnik() * (x.DajNazivnik() / r);
    nazivnik = x.DajNazivnik() * (y.DajNazivnik() / r);
    return Razlomak(brojnik, nazivnik);
}

Razlomak operator-(const Razlomak& x, const Razlomak& y){
    Razlomak temp = y;
    return x + -temp;
}

Razlomak operator*(const Razlomak& x, const Razlomak& y){
    if(y.DajBrojnik() > 0 && (x.DajBrojnik() < LONGMIN / y.DajBrojnik() || x.DajBrojnik() > LONGMAX / y.DajBrojnik()))
        throw overflow_error("Nemoguce dobiti tacan rezultat");
    if(y.DajNazivnik() > 0 && (x.DajNazivnik() < LONGMIN / y.DajNazivnik() || x.DajNazivnik() > LONGMAX / y.DajNazivnik()))
        throw overflow_error("Nemoguce dobiti tacan rezultat");
    if(y.DajBrojnik() < 0 && (x.DajBrojnik() == LONGMIN || -x.DajBrojnik() > LONGMAX / (-y.DajBrojnik()) || -x.DajBrojnik() < LONGMIN / (-y.DajBrojnik())))
        throw overflow_error("Nemoguce dobiti tacan rezultat");
    if(y.DajNazivnik() < 0 && (x.DajNazivnik() == LONGMIN || -x.DajNazivnik() > LONGMAX / (-y.DajNazivnik()) || -x.DajNazivnik() < LONGMIN / (-y.DajNazivnik())))
        throw overflow_error("Nemoguce dobiti tacan rezultat");
    long long int brojnik, nazivnik;
    long long int s = Razlomak::NZD(x.DajBrojnik(), y.DajNazivnik());
    long long int t = Razlomak::NZD(y.DajBrojnik(), x.DajNazivnik());
    brojnik = (x.DajBrojnik() / s) * (y.DajBrojnik() / t);
    nazivnik = (x.DajNazivnik() / t) * (y.DajNazivnik() / s);
    return Razlomak(brojnik, nazivnik);
}

Razlomak operator/(const Razlomak& x, const Razlomak& y){

    long long int r = Razlomak::NZD(x.DajNazivnik(), y.DajNazivnik());
    long long int u = Razlomak::NZD(x.DajBrojnik(), y.DajBrojnik());
    //PROVJERA PROVJERA
    long long int brojnik = (x.DajBrojnik() / u) * (y.DajNazivnik() / r);
    long long int nazivnik = (x.DajNazivnik() / r) * (y.DajBrojnik() / u);
    return Razlomak(brojnik, nazivnik);
    
}

Razlomak& Razlomak::operator-(){
    if(brojnik < 0 && -brojnik >= LONGMAX)
        throw overflow_error("Nemoguce dobiti tacan rezultat");
    if(brojnik > 0 && -brojnik <= LONGMIN)
        throw overflow_error("Nemoguce dobiti tacan rezultat");
    brojnik *= -1;
    return *this;
}

Razlomak& operator+= (Razlomak& r1, const Razlomak& r2) { return r1 = r1 + r2; }
Razlomak& operator-= (Razlomak& r1, const Razlomak& r2) { return r1 = r1 - r2; }
Razlomak& operator*= (Razlomak& r1, const Razlomak& r2) { return r1 = r1 * r2; }
Razlomak& operator/= (Razlomak& r1, const Razlomak& r2) { return r1 = r1 / r2; }

Razlomak& Razlomak::operator++(){
    if(brojnik + 1 == LONGMIN || nazivnik + 1 == LONGMIN)
        throw overflow_error("Nemoguce dobiti tacan rezultat");
    brojnik += 1; nazivnik += 1;
    return *this;
}

Razlomak Razlomak::operator++(int n){
    Razlomak temp(*this);
    ++(*this);
    return temp;
}

Razlomak& Razlomak::operator--(){
    if(brojnik - 1 == LONGMAX || nazivnik - 1 == LONGMAX)
        throw overflow_error("Nemoguce dobiti tacan rezultat");
    brojnik -= 1; nazivnik -= 1;
    return *this;
}

Razlomak Razlomak::operator--(int n){
    Razlomak temp(*this);
    --(*this);
    return temp;
}

bool operator< (const Razlomak& x, const Razlomak& y){
    long double r1 = (long double)x.DajBrojnik() / (long double)x.DajNazivnik();
    long double r2 = (long double)y.DajBrojnik() / (long double)y.DajNazivnik();
    return r1 < r2;
}

bool operator> (const Razlomak& x, const Razlomak& y){
    long double r1 = (long double)x.DajBrojnik() / (long double)x.DajNazivnik();
    long double r2 = (long double)y.DajBrojnik() / (long double)y.DajNazivnik();
    return r1 > r2;
}

bool operator<= (const Razlomak& x, const Razlomak& y){
    return x < y || x == y;
}

bool operator>= (const Razlomak& x, const Razlomak& y){
    return x > y || x == y;
}

bool operator== (const Razlomak& x, const Razlomak& y){
    long double r1 = (long double)x.DajBrojnik() / (long double)x.DajNazivnik();
    long double r2 = (long double)y.DajBrojnik() / (long double)y.DajNazivnik();
    return r1 < r2 ? r2 - r1 < EPSILON : r1 - r2 < EPSILON;
}

bool operator!= (const Razlomak& x, const Razlomak& y){
    return !(x == y);
}

ostream& operator<< (ostream& tok, const Razlomak& r){
    r.DajNazivnik() == 1 ? tok << r.DajBrojnik() : tok << r.DajBrojnik() << "/" << r.DajNazivnik();
    return tok;
}

istream& operator>> (istream& tok, Razlomak& r){
    long long int brojnik(0), nazivnik(0);
    bool bezNazivnika(true);
    tok >> ws >> brojnik;
    if(!tok){
        tok.setstate(ios_base::failbit);
        return tok;
    }
    if(tok.peek() == char_traits<char>::to_int_type('/')){
        bezNazivnika = false;
        tok.get();
        tok >> nazivnik;
        //cout << "ooooooooovdje: " << nazivnik << endl;
        if(!tok){
            tok.setstate(ios_base::failbit);
            return tok;
        }
    }
    /*
    if(tok.peek() != std::char_traits<char>::to_int_type(' ') && tok.peek() != std::char_traits<char>::eof()){
        tok.setstate(ios_base::failbit);
        return tok;
    }
    */
    if(isspace(tok.peek()) == 0 && tok.peek() != std::char_traits<char>::eof()){
        tok.setstate(ios_base::failbit);
        return tok;
    }
    
    bezNazivnika ? r = brojnik : r = {brojnik, nazivnik};
    return tok;
}


int main ()
{return 0;
        }

