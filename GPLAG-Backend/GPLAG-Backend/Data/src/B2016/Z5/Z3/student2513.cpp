/B16/17 (Zadaća 5, Zadatak 3)
//Autotestovi by Enil Pajic (mail: epajic1@etf.unsa.ba)
//Za autotestove se obracati *iskljucivo* osobi koja ih pise
#include <iostream>
#include <cmath>
#include <stdexcept>
#include <limits>
using namespace std;

bool da_li_se_mogu_sabrati(long long int a, long long int b) {
    long long int M = numeric_limits<long long int>::max();
    long long int m = numeric_limits<long long int>::min();
    if(b > 0 && a > M - b) throw overflow_error("Nemoguce dobiti tacan rezultat");
    if(b < 0 && a < m - b) throw overflow_error("Nemoguce dobiti tacan rezultat");
    return true;
}

bool da_li_se_mogu_oduzeti(long long int a, long long int b) {
    long long int M = numeric_limits<long long int>::max();
    long long int m = numeric_limits<long long int>::min();
    if(b > 0 && a < m + b) throw overflow_error("Nemoguce dobiti tacan rezultat");
    if(b < 0 && a > M + b) throw overflow_error("Nemoguce dobiti tacan rezultat");
    return true;
}

bool da_li_se_mogu_mnoziti(long long int a, long long int b) {
    long long int M = numeric_limits<long long int>::max();
    long long int m = numeric_limits<long long int>::min();
    if(b > 0 && (a < m/b || a > M/b)) throw overflow_error("Nemoguce dobiti tacan rezultat");
    if(b < 0 && (a == m || -a > M/(-b) || -a < m/(-b))) throw overflow_error("Nemoguce dobiti tacan rezultat");
    return true;
}

class Razlomak {
    long long int brojnik, nazivnik;
    static long long int NZD(long long int p, long long int q) {
        if(q == 0) return p;
        return NZD(q, p%q);
    }
    
public:
    Razlomak(long long int b, long long int n);
    Razlomak(long long int b) { brojnik = b; nazivnik = 1; }
    Razlomak() { brojnik = 0; nazivnik = 1; }
    long long int DajBrojnik() const { return brojnik; }
    long long int DajNazivnik() const { return nazivnik; }
    friend Razlomak operator +(const Razlomak &a1, const Razlomak &a2);
    friend Razlomak operator -(const Razlomak &a1, const Razlomak &a2);
    friend Razlomak operator *(const Razlomak &a1, const Razlomak &a2);
    friend Razlomak operator /(const Razlomak &a1, const Razlomak &a2);
    friend Razlomak operator +(const Razlomak &a);
    friend Razlomak operator -(const Razlomak &a);
    friend Razlomak operator +=(const Razlomak &a1, const Razlomak &a2);
    friend Razlomak operator -=(const Razlomak &a1, const Razlomak &a2);
    friend Razlomak operator *=(const Razlomak &a1, const Razlomak &a2);
    friend Razlomak operator /=(const Razlomak &a1, const Razlomak &a2);
    friend Razlomak operator ++(Razlomak &a);
    friend Razlomak operator --(Razlomak &a);
    friend Razlomak operator ++(Razlomak &a, int);
    friend Razlomak operator --(Razlomak &a, int);
    friend bool operator >(const Razlomak &a1, const Razlomak &a2);
    friend bool operator <(const Razlomak &a1, const Razlomak &a2);
    friend bool operator <=(const Razlomak &a1, const Razlomak &a2);
    friend bool operator >=(const Razlomak &a1, const Razlomak &a2);
    friend bool operator ==(const Razlomak &a1, const Razlomak &a2);
    friend bool operator !=(const Razlomak &a1, const Razlomak &a2);
    friend ostream &operator <<(ostream &tok, const Razlomak &a);
    friend istream &operator >>(istream &tok, const Razlomak &a);
    operator long double() const { return brojnik*(1.)/nazivnik; }
};

/////////////////////////////////////////////// IMPLEMENTACIJE ///////////////////////////////////////////////
Razlomak::Razlomak(long long int b, long long int n) {
    long long int nzd;
    if(n == 0) throw logic_error("Nekorektan razlomak");
    if(n < 0) {
        n = -n;
        b = -b;
    }
    nzd = NZD(b,n);
    brojnik = b/nzd; nazivnik = n/nzd;
}
Razlomak operator +(const Razlomak &a1, const Razlomak &a2) {
    long long int r = a1.NZD(a1.nazivnik, a2.nazivnik);
    bool mnozenje1 = da_li_se_mogu_mnoziti(a1.brojnik, a2.nazivnik/r);
    bool mnozenje2 = da_li_se_mogu_mnoziti(a2.brojnik, a1.nazivnik/r);
    bool sabiranje = da_li_se_mogu_sabrati(mnozenje1, mnozenje2);
    bool mnozenje3 = da_li_se_mogu_mnoziti(a1.nazivnik, a2.nazivnik/r);
    
    if(sabiranje == false || mnozenje3 == false)
        throw overflow_error("Nemoguce dobiti tacan rezultat");
    long long int brojnik = a1.brojnik * int(a2.nazivnik/r) + a2.brojnik * int(a1.nazivnik/r);
    long long int nazivnik = a1.nazivnik * int(a2.nazivnik/r);
    return Razlomak(brojnik, nazivnik);
}

Razlomak operator -(const Razlomak &a1, const Razlomak &a2) {
    long long int r = a1.NZD(a1.nazivnik, a2.nazivnik);
    bool mnozenje1 = da_li_se_mogu_mnoziti(a1.brojnik, a2.nazivnik/r);
    bool mnozenje2 = da_li_se_mogu_mnoziti(a2.brojnik, a1.nazivnik/r);
    bool oduzimanje = da_li_se_mogu_oduzeti(mnozenje1, mnozenje2);
    bool mnozenje3 = da_li_se_mogu_mnoziti(a1.nazivnik, a2.nazivnik/r);
    
    if(oduzimanje == false && mnozenje3 == false)
        throw overflow_error("Nemoguce dobiti tacan rezultat");
    long long int brojnik = a1.brojnik * int(a2.nazivnik/r) - a2.brojnik * int(a1.nazivnik/r);
    long long int nazivnik = a1.nazivnik * int(a2.nazivnik/r);
    return Razlomak(brojnik, nazivnik);
}

Razlomak operator *(const Razlomak &a1, const Razlomak &a2) {
    long long int s = a1.NZD(a1.brojnik, a2.nazivnik);
    long long int t = a1.NZD(a2.brojnik, a1.nazivnik);
    
    bool mnozenje1 = da_li_se_mogu_mnoziti(a1.brojnik/s, a2.brojnik/t);
    bool mnozenje2 = da_li_se_mogu_mnoziti(a1.nazivnik/t, a2.nazivnik/s);
    if(mnozenje1 == false && mnozenje2 == false) 
        throw overflow_error("Nemoguce dobiti tacan rezultat");
    long long int brojnik = int(a1.brojnik/s) * int(a2.brojnik/t);
    long long int nazivnik = int(a1.nazivnik/t) * int(a2.nazivnik/s);
    return Razlomak(brojnik, nazivnik);
}

Razlomak operator /(const Razlomak &a1, const Razlomak &a2) {
    long long int r = a1.NZD(a1.nazivnik, a2.nazivnik);
    long long int u = a1.NZD(a1.brojnik, a2.brojnik);
    
    bool mnozenje1 = da_li_se_mogu_mnoziti(a1.brojnik/u, a2.nazivnik/r);
    bool mnozenje2 = da_li_se_mogu_mnoziti(a1.nazivnik/r, a2.brojnik/u);
    if(mnozenje1 == false && mnozenje2 == false)
        throw overflow_error("Nemoguce dobiti tacan rezultat");
    long long int brojnik = int(a1.brojnik/u) * int(a2.nazivnik/r);
    long long int nazivnik = int(a1.nazivnik/r) * int(a2.brojnik/u);
    return Razlomak(brojnik, nazivnik);
}

Razlomak operator +(const Razlomak &a) {
    return a;
}
Razlomak operator -(const Razlomak &a) {
    if(a.brojnik == numeric_limits<long long int>::min()) throw overflow_error("Nemoguce dobiti tacan rezultat");
    Razlomak pomocni_razlomak = a;
    pomocni_razlomak.brojnik = -pomocni_razlomak.brojnik;
    return pomocni_razlomak;
}
Razlomak operator +=(Razlomak &a1, const Razlomak &a2) {
    Razlomak pomocni_razlomak;
    pomocni_razlomak = a1;
    a1 = pomocni_razlomak + a2;
    return a1;
}
Razlomak operator -=(Razlomak &a1, const Razlomak &a2) {
    Razlomak pomocni_razlomak;
    pomocni_razlomak = a1;
    a1 = pomocni_razlomak - a2;
    return a1;
}
Razlomak operator *=(Razlomak &a1, const Razlomak &a2) {
    Razlomak pomocni_razlomak;
    pomocni_razlomak = a1;
    a1 = pomocni_razlomak * a2;
    return a1;
}
Razlomak operator /=(Razlomak &a1, const Razlomak &a2) {
    Razlomak pomocni_razlomak;
    pomocni_razlomak = a1;
    a1 = pomocni_razlomak / a2;
    return a1;
}
Razlomak operator ++(Razlomak &a) {
    a += 1;
    return a;
}
Razlomak operator --(Razlomak &a) {
    a -= 1;
    return a;
}
Razlomak operator ++(Razlomak &a, int) {
    Razlomak nova_vrijednost = a;
    ++a;
    return nova_vrijednost;
}
Razlomak operator --(Razlomak &a, int) {
    Razlomak nova_vrijednost = a;
    --a;
    return nova_vrijednost;
}
bool operator <(const Razlomak &a1, const Razlomak &a2) {
    long double r1, r2;
    r1 = a1.brojnik/a1.nazivnik;
    r2 = a2.brojnik/a2.nazivnik;
    return r1 < r2;
}
bool operator >(const Razlomak &a1, const Razlomak &a2) {
    long double r1, r2;
    r1 = a1.brojnik/a1.nazivnik;
    r2 = a2.brojnik/a2.nazivnik;
    return r1 > r2;
}

bool operator <=(const Razlomak &a1, const Razlomak &a2) {
    long long int r1, r2;
    r1 = a1.brojnik/a1.nazivnik;
    r2 = a2.brojnik/a2.nazivnik;
    return r1 <= r2;
}

bool operator >=(const Razlomak &a1, const Razlomak &a2) {
    long long int r1, r2;
    r1 = a1.brojnik/a1.nazivnik;
    r2 = a2.brojnik/a2.nazivnik;
    return r1 >= r2;
}
bool operator ==(const Razlomak &a1, const Razlomak &a2) {
    if(a1.brojnik == a2.brojnik && a1.nazivnik == a2.nazivnik) 
        return true;
    return false;
}

bool operator !=(const Razlomak &a1, const Razlomak &a2) {
    if(a1.brojnik != a2.brojnik || a1.nazivnik != a2.nazivnik)
        return true;
    return false;
}

ostream &operator <<(ostream &tok, const Razlomak &a) {
    tok << a.brojnik;
    if(a.nazivnik == 1) return tok;
    else {
        tok << "/" << a.nazivnik;
    }
    return tok;
}

/*istream &operator >>(istream &tok, Razlomak &a1) {
    
}*/
int main ()
{
    return 0;
}