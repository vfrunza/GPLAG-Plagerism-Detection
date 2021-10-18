/B16/17 (Zadaća 5, Zadatak 3)
//Autotestovi by Enil Pajic (mail: epajic1@etf.unsa.ba)
//Za autotestove se obracati *iskljucivo* osobi koja ih pise

#include <iostream>
#include <stdexcept>
#include <limits>
#include <utility>
class Razlomak
{
    long long int brojnik;
    long long int nazivnik;
    static const long long int int_max = std::numeric_limits<long long int>::max();
    static const long long int int_min = std::numeric_limits<long long int>::min();
    static long long int NZD (long long int p, long long int q) {
        if(q == 0) return p;
        return NZD(q,p%q);
    }
    static bool test_p (long long int x, long long int y) {
        if ( y > 0) return x > int_max -y;
        else return x < int_min - y;
    }
    static bool test_m (long long int x, long long int y) {
        if ( y > 0) return x < int_min - y;
        else return x > int_max -y;
    }
    static bool test_prmn (long long int x, long long int y) {
        if ( y > 0) {
            if (x < int_min/y or x > int_max/y) return true;
            return false;
        } else {
            if ( x == int_min or -x > int_max/-y or -x < int_min/-y) return true;
            return false;
        }
    }

public :
    Razlomak (long long int brojnik = 0, long long int nazivnik = 1) {
        if (nazivnik < 0) {
            nazivnik *= -1;         // ako je nazivnik negativan
            brojnik  *= -1;         // ako su nazivnik i brojnik nagativni
        } else if (nazivnik == 0) throw std::logic_error ("Nekorektan razlomak");   // nula nazivnik

        long long int nzd(NZD(brojnik,nazivnik));         // skracivanje

        brojnik /= nzd;
        nazivnik /= nzd;
        Razlomak::brojnik = brojnik;
        Razlomak::nazivnik = nazivnik;


    }
    long long int DajBrojnik() const {
        return brojnik;
    }
    long long int DajNazivnik() const {
        return nazivnik;
    }
    Razlomak &operator += (const Razlomak &raz2) {
        return *this = *this + raz2;
    }
    Razlomak &operator -= (const Razlomak &raz2) {
        return *this = *this - raz2;
    }
    Razlomak &operator *= (const Razlomak &raz2) {
        return *this = *this * raz2;
    }
    Razlomak &operator /= (const Razlomak &raz2) {
        return *this = *this/raz2;
    }
    Razlomak &operator ++ () {
        return *this +=1;
    }
    Razlomak &operator -- () {
        return *this -=1;
    }
    Razlomak operator ++ (int) {
        auto t(*this);
        *this+=1;
        return t;
    }
    Razlomak operator -- (int) {
        auto t(*this);
        *this-=1;
        return t;
    }
    Razlomak operator +() {
        return *this;
    }
    Razlomak operator -() {
        auto t(*this);
        t.brojnik*=-1;
        return t;
    }
    operator long double () const {
        return (long double)DajBrojnik()/DajNazivnik();
    }
    friend  std::istream &operator >> (std::istream &tok,Razlomak &raz);
    friend std::ostream &operator << (std::ostream &tok,const Razlomak &raz);
    friend Razlomak operator +(const Razlomak &raz1,const Razlomak &raz2);
    friend Razlomak operator -(const Razlomak &raz1,const Razlomak &raz2);
    friend Razlomak operator *(const Razlomak &raz1,const Razlomak &raz2);
    friend Razlomak operator /(const Razlomak &raz1,const Razlomak &raz2);
    friend Razlomak operator +(const Razlomak &raz1);
    friend Razlomak operator -(const Razlomak &raz1);
    friend bool operator >(const Razlomak &raz1,const Razlomak &raz2);
    friend bool operator <(const Razlomak &raz1,const Razlomak &raz2);
    friend bool operator <=(const Razlomak &raz1,const Razlomak &raz2);
    friend bool operator >=(const Razlomak &raz1,const Razlomak &raz2);
    friend bool operator ==(const Razlomak &raz1,const Razlomak &raz2);
    friend bool operator !=(const Razlomak &raz1,const Razlomak &raz2);
};

bool operator >(const Razlomak &raz1,const Razlomak &raz2)
{
    long long int p1(raz1.DajBrojnik()), p2(raz2.DajBrojnik()), q1(raz1.DajNazivnik()), q2(raz2.DajNazivnik());
    long long int r(Razlomak::NZD(p1,p2)); // (p1,p2)
    long long int s(Razlomak::NZD(q1,q2)); // (q1,q2)
    if (Razlomak::test_prmn(p1/r,q2/s) or Razlomak::test_prmn(p2/r,q1/s))
        throw std::overflow_error ("1Nemoguce dobititacan rezultat");
    return p1/r*q2/s > p2/r*q1/s;
}
bool operator <(const Razlomak &raz1,const Razlomak &raz2)
{
    long long int p1(raz1.DajBrojnik()), p2(raz2.DajBrojnik()), q1(raz1.DajNazivnik()), q2(raz2.DajNazivnik());
    long long int r(Razlomak::NZD(p1,p2)); // (p1,p2)
    long long int s(Razlomak::NZD(q1,q2)); // (q1,q2)
    if (Razlomak::test_prmn(p1/r,q2/s) or Razlomak::test_prmn(p2/r,q1/s))
        throw std::overflow_error ("2Nemoguce dobititacan rezultat");
    return p1/r*q2/s < p2/r*q1/s;
}
bool operator >=(const Razlomak &raz1,const Razlomak &raz2)
{
    long long int p1(raz1.DajBrojnik()), p2(raz2.DajBrojnik()), q1(raz1.DajNazivnik()), q2(raz2.DajNazivnik());
    long long int r(Razlomak::NZD(p1,p2)); // (p1,p2)
    long long int s(Razlomak::NZD(q1,q2)); // (q1,q2)
    if (Razlomak::test_prmn(p1/r,q2/s) or Razlomak::test_prmn(p2/r,q1/s))
        throw std::overflow_error ("3Nemoguce dobititacan rezultat");
    return p1/r*q2/s >= p2/r*q1/s;
}
bool operator <=(const Razlomak &raz1,const Razlomak &raz2)
{
    long long int p1(raz1.DajBrojnik()), p2(raz2.DajBrojnik()), q1(raz1.DajNazivnik()), q2(raz2.DajNazivnik());
    long long int r(Razlomak::NZD(p1,p2)); // (p1,p2)
    long long int s(Razlomak::NZD(q1,q2)); // (q1,q2)
    if (Razlomak::test_prmn(p1/r,q2/s) or Razlomak::test_prmn(p2/r,q1/s))
        throw std::overflow_error ("4Nemoguce dobititacan rezultat");
    return p1/r*q2/s <= p2/r*q1/s;
}
bool operator ==(const Razlomak &raz1,const Razlomak &raz2)
{
    long long int p1(raz1.DajBrojnik()), p2(raz2.DajBrojnik()), q1(raz1.DajNazivnik()), q2(raz2.DajNazivnik());
    long long int r(Razlomak::NZD(p1,p2)); // (p1,p2)
    long long int s(Razlomak::NZD(q1,q2)); // (q1,q2)
    if (Razlomak::test_prmn(p1/r,q2/s) or Razlomak::test_prmn(p2/r,q1/s))
        throw std::overflow_error ("5Nemoguce dobititacan rezultat");
    return p1/r*q2/s == p2/r*q1/s;
}
bool operator !=(const Razlomak &raz1,const Razlomak &raz2)
{
    long long int p1(raz1.DajBrojnik()), p2(raz2.DajBrojnik()), q1(raz1.DajNazivnik()), q2(raz2.DajNazivnik());
    long long int r(Razlomak::NZD(p1,p2)); // (p1,p2)
    long long int s(Razlomak::NZD(q1,q2)); // (q1,q2)
    if (Razlomak::test_prmn(p1/r,q2/s) or Razlomak::test_prmn(p2/r,q1/s))
        throw std::overflow_error ("6Nemoguce dobititacan rezultat");
    return p1/r*q2/s != p2/r*q1/s;
}

Razlomak operator +(const Razlomak &raz1,const Razlomak &raz2)
{
    long long int p1(raz1.DajBrojnik()), p2(raz2.DajBrojnik()), q1(raz1.DajNazivnik()), q2(raz2.DajNazivnik());
    long long int r(Razlomak::NZD(q1,q2)); // (q1,q2)
    if (Razlomak::test_prmn(p1,q2/r) or Razlomak::test_prmn(p2,q1/r) or Razlomak::test_prmn(q1,q2/r) or Razlomak::test_p(p1*(q2/r),p2*(q1/r)))
        throw std::overflow_error ("7Nemoguce dobititacan rezultat");
    return {p1*(q2/r) + p2*(q1/r), q1*(q2/r)};
}

Razlomak operator -(const Razlomak &raz1,const Razlomak &raz2)
{
    long long int p1(raz1.DajBrojnik()), p2(raz2.DajBrojnik()), q1(raz1.DajNazivnik()), q2(raz2.DajNazivnik());
    long long int r(Razlomak::NZD(q1,q2)); // (q1,q2)
    if (Razlomak::test_prmn(p1,q2/r) or Razlomak::test_prmn(p2,q1/r) or Razlomak::test_prmn(q1,q2/r))
        throw std::overflow_error ("8Nemoguce dobititacan rezultat");
    return {p1*(q2/r) - p2*(q1/r), q1*(q2/r)};
}

Razlomak operator *(const Razlomak &raz1,const Razlomak &raz2)
{
    long long int p1(raz1.DajBrojnik()), p2(raz2.DajBrojnik()), q1(raz1.DajNazivnik()), q2(raz2.DajNazivnik());
    long long int s(Razlomak::NZD(p1,q2)); // (p1,q2)
    long long int t(Razlomak::NZD(p2,q1)); // (p2,q1)
    if (Razlomak::test_prmn(p1/s,p2/t) or Razlomak::test_prmn(q1/t,q2/s))
        throw std::overflow_error ("9Nemoguce dobititacan rezultat");
    return { (p1/s)*(p2/t),(q1/t)*(q2/s)};
}

Razlomak operator /(const Razlomak &raz1,const Razlomak &raz2)
{
    long long int p1(raz1.DajBrojnik()), p2(raz2.DajBrojnik()), q1(raz1.DajNazivnik()), q2(raz2.DajNazivnik());
    long long int r(Razlomak::NZD(q1,q2)); // (q1,q2)
    long long int u(Razlomak::NZD(p1,p2)); // (p1,p2)
    if (Razlomak::test_prmn(p1/u,q2/r) or Razlomak::test_prmn(q1/r,p2/u))
        throw std::overflow_error ("10Nemoguce dobititacan rezultat");
    return {(p1/u)*(q2/r),(q1/r)*(p2/u)};
}

std::ostream &operator << (std::ostream &tok,const Razlomak &raz)
{
    tok << raz.DajBrojnik();
    if (raz.DajNazivnik() != 1) tok << "/" << raz.DajNazivnik();
    return tok;
}
std::istream &operator >> (std::istream &tok,Razlomak &raz)
{
    long long int brojnik;
    long long int nazivnik = 1;

    char znak;

    tok >> brojnik;
    znak = tok.peek();
    if (tok and znak == '/') {
        tok.get();
        tok >> nazivnik;
        znak = tok.peek();
        if (znak != ' ' and znak  != '\n')
            tok.setstate(std::ios::failbit);
    }
    if (znak != ' ' and znak  != '\n')
        tok.setstate(std::ios::failbit);
    raz = Razlomak(brojnik,nazivnik);

    return tok;
}

int main ()
{
    



    return 0;
}