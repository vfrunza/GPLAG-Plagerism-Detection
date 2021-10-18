/B16/17 (Zadaća 5, Zadatak 3)
//Autotestovi by Enil Pajic (mail: epajic1@etf.unsa.ba)
//Za autotestove se obracati *iskljucivo* osobi koja ih pise

#include <iostream>
#include <limits>
#include <stdexcept>

using std::cout;
using std::cin;
using std::numeric_limits;
using std::overflow_error;
using std::ostream;

typedef long long int llint;

const llint M = numeric_limits<llint>::max(), m = numeric_limits<llint>::min();

class Razlomak {
    
    long long int brojnik, nazivnik;
    
    static llint NZD(llint p, llint q);
    static llint plus(llint p, llint q);
    static llint minus(llint p, llint q);
    static llint puta(llint p, llint q);
    static llint dijeli(llint p, llint q);
    
    // Binarni ne-relacioni
    friend Razlomak &operator +=(Razlomak &r1, const Razlomak &r2);
    friend Razlomak operator +(const Razlomak &r1, const Razlomak &r2);
    friend Razlomak &operator -=(Razlomak &r1, const Razlomak &r2);
    friend Razlomak operator -(const Razlomak &r1, const Razlomak &r2);
    friend Razlomak &operator *=(Razlomak &r1, const Razlomak &r2);
    friend Razlomak operator *(const Razlomak &r1, const Razlomak &r2);
    friend Razlomak &operator /=(Razlomak &r1, const Razlomak &r2);
    friend Razlomak operator /(const Razlomak &r1, const Razlomak &r2);
    
    // Unarni
    friend Razlomak operator +(const Razlomak &r);
    friend Razlomak operator -(const Razlomak &r);
    friend Razlomak &operator ++(Razlomak &r1);
    friend Razlomak operator ++(Razlomak &r1, int);
    friend Razlomak &operator --(Razlomak &r1);
    friend Razlomak operator --(Razlomak &r1, int);
    
    // Binarni relacioni
    friend bool operator ==(const Razlomak &r1, const Razlomak &r2);
    friend bool operator !=(const Razlomak &r1, const Razlomak &r2);
    friend bool operator <=(const Razlomak &r1, const Razlomak &r2);
    friend bool operator <(const Razlomak &r1, const Razlomak &r2);
    friend bool operator >=(const Razlomak &r1, const Razlomak &r2);
    friend bool operator >(const Razlomak &r1, const Razlomak &r2);
    
    // I/O
    friend ostream &operator <<(ostream &tok, const Razlomak &r);

    public :
        Razlomak(llint brojnik = 0, llint nazivnik = 1);
        
        operator long double() const;
        
        llint DajBrojnik() const { return brojnik; }
        llint DajNazivnik() const { return nazivnik; }
};

llint Razlomak::NZD(llint p, llint q) {
    llint temp;
    while(q != 0) {
        temp = p;
        p = q;
        q = temp % q;
    }
    
    return p;
}

Razlomak::Razlomak(llint brojnik, llint nazivnik)
{
    int predznak1, predznak2;
    predznak1 = brojnik < 0 ? -1 : 1;
    predznak2 = nazivnik < 0 ? -1 : 1;
    
    if (brojnik == nazivnik) {
        brojnik = 1; nazivnik = 1;
        predznak1 = 1; predznak2 = 1;
    } else if (predznak1 == -1 && predznak2 == -1) {
        if (brojnik == m || nazivnik == m) {
            throw overflow_error("Nemoguce dobiti tacan rezultat");
        }
        brojnik *= -1; nazivnik *= -1;
        predznak1 = 1; predznak2 = 1;
    } else if (predznak1 == -1) {
        if (brojnik == m) {
            throw overflow_error("Nemoguce dobiti tacan rezultat");
        }
        brojnik *= -1;
    } else if (predznak2 == -1) {
        if (nazivnik == m) {
            throw overflow_error("Nemoguce dobiti tacan rezultat");
        }
        nazivnik *= -1;
        predznak1 = -1;
        predznak2 = 1;
    }
    
    llint nzd = NZD(brojnik, nazivnik); // Moze i obicni int? maxint * maxint?
    
    Razlomak::brojnik = predznak1 * brojnik / nzd;
    Razlomak::nazivnik = nazivnik / nzd;
}

llint Razlomak::plus(llint p, llint q)
{
    if (q > 0) {
        if (p > M - q) {
            throw overflow_error("Nemoguce dobiti tacan rezultat");
        }
    } else if (q < 0) {
        if (p < m - q) {
            throw overflow_error("Nemoguce dobiti tacan rezultat");
        }
    }
    
    return p + q;
}

llint Razlomak::minus(llint p, llint q) {
    if (q == m) {
        if (p > -1) {
            throw overflow_error("Nemoguce dobiti tacan rezultat");
        } else {
            return plus(p + 1, M);
        }
    }
    
    return plus(p, -q);
}

llint Razlomak::puta(llint p, llint q)
{
    if (q > 0) {
        if ((p < m / q) || (p > M / q)) {
            throw overflow_error("Nemoguce dobiti tacan rezultat");
        }
    } else if (q < 0) {
        if ( p == m || ((-p) < m / (-q)) || ((-p) > M / (-q)) ) {
            throw overflow_error("Nemoguce dobiti tacan rezultat");
        }
    }
    
    return p * q;
}

llint Razlomak::dijeli(llint p, llint q) {
    return puta(p, 1 / q);
}


Razlomak &operator +=(Razlomak &r1, const Razlomak &r2)
{
    llint b1(r1.brojnik), n1(r1.nazivnik), b2(r2.brojnik), n2(r2.nazivnik), nzd = Razlomak::NZD(n1, n2);
    
    b1 = Razlomak::plus( Razlomak::puta(b1, n2 / nzd), Razlomak::puta(b2, n1 / nzd));
    n1 = Razlomak::puta(n1, n2 / nzd);
    
    r1 = Razlomak(b1, n1);

    return r1;
}

Razlomak operator +(const Razlomak &r1, const Razlomak &r2)
{
    Razlomak r3(r1);
    r3 += r2;
    return r3;
}

Razlomak &operator -=(Razlomak &r1, const Razlomak &r2)
{
    llint b1(r1.brojnik), n1(r1.nazivnik), b2(r2.brojnik), n2(r2.nazivnik), nzd = Razlomak::NZD(n1, n2);
    
    b1 = Razlomak::minus( Razlomak::puta(b1, n2 / nzd), Razlomak::puta(b2, n1 / nzd));
    n1 = Razlomak::puta(n1, n2 / nzd);
    
    r1 = Razlomak(b1, n1);

    return r1;
}

Razlomak operator -(const Razlomak &r1, const Razlomak &r2)
{
    Razlomak r3(r1);
    r3 -= r2;
    return r3;
}

Razlomak &operator *=(Razlomak &r1, const Razlomak &r2)
{
    llint b1(r1.brojnik), n1(r1.nazivnik), b2(r2.brojnik), n2(r2.nazivnik),
        nzd1 = Razlomak::NZD(b1, n2), nzd2 = Razlomak::NZD(b2, n1);
    
    b1 = Razlomak::puta(b1 / nzd1, b2 / nzd2);
    n1 = Razlomak::puta(n1 / nzd2, n2 / nzd1);
    
    r1 = Razlomak(b1, n1);

    return r1;
}

Razlomak operator *(const Razlomak &r1, const Razlomak &r2)
{
    Razlomak r3(r1);
    r3 *= r2;
    return r3;
}

Razlomak &operator /=(Razlomak &r1, const Razlomak &r2)
{
    llint b1(r1.brojnik), n1(r1.nazivnik), b2(r2.brojnik), n2(r2.nazivnik),
        nzd1 = Razlomak::NZD(b1, b2), nzd2 = Razlomak::NZD(n1, n2);
    
    b1 = Razlomak::puta(b1 / nzd1, n2 / nzd2);
    n1 = Razlomak::puta(n1 / nzd2, b2 / nzd1);
    
    r1 = Razlomak(b1, n1);

    return r1;
}

Razlomak operator /(const Razlomak &r1, const Razlomak &r2)
{
    Razlomak r3(r1);
    r3 /= r2;
    return r3;
}

Razlomak operator +(const Razlomak &r) {
    return r;
}

Razlomak operator -(const Razlomak &r)
{
    if (r. brojnik == m) {
        throw overflow_error("Nemoguce dobiti tacan rezultat");
    }
    return Razlomak(-r.brojnik, r.nazivnik);
}

Razlomak &operator ++(Razlomak &r1)
{
    r1.brojnik = Razlomak::plus(r1.brojnik, r1.nazivnik);
    return r1;
}

Razlomak operator ++(Razlomak &r1, int)
{
    Razlomak pomocni(r1);
    r1.brojnik = Razlomak::plus(r1.brojnik, r1.nazivnik);
    return pomocni;
}

Razlomak &operator --(Razlomak &r1)
{
    r1.brojnik = Razlomak::minus(r1.brojnik, r1.nazivnik);
    return r1;
}

Razlomak operator --(Razlomak &r1, int)
{
    Razlomak pomocni(r1);
    r1.brojnik = Razlomak::minus(r1.brojnik, r1.nazivnik);
    return pomocni;
}

bool operator ==(const Razlomak &r1, const Razlomak &r2) {
    return ((long double)r1.brojnik) / r1.nazivnik == ((long double) r2.brojnik / r2.nazivnik);
}

bool operator !=(const Razlomak &r1, const Razlomak &r2) {
    return !(r1 == r2);
}

bool operator <=(const Razlomak &r1, const Razlomak &r2) {
    return ((long double)r1.brojnik) / r1.nazivnik <= ((long double) r2.brojnik / r2.nazivnik);
}

bool operator <(const Razlomak &r1, const Razlomak &r2) {
    return ((long double)r1.brojnik) / r1.nazivnik < ((long double) r2.brojnik / r2.nazivnik);
}

bool operator >=(const Razlomak &r1, const Razlomak &r2) {
    return !(r1 < r2);
}

bool operator >(const Razlomak &r1, const Razlomak &r2) {
    return !(r1 <= r2);
}

ostream &operator <<(ostream &tok, const Razlomak &r)
{
    tok << r.brojnik;
    if (r.nazivnik == 1)
        return tok;
    else
        return tok << "/" << r.nazivnik;
}

Razlomak::operator long double() const {
    return ((long double) brojnik) / nazivnik;
}

int main ()
{
    cout << "Unesite brojeve: \n";
    Razlomak r1(1000, -512), r2(100000000000000, 3);
    cout << r1 + r2 << " " << r1 - r2 << " " << r1 * r2 << " " << r1 / r2 << " "
        << (r1 == r2) << " " << (r1 <= r1) << " " << (r1 < r2) << " " << (r1 >= r2)
        << " " << (r1 > r2);
    r1++;
    r2--;
    --r1;
    ++r2;
    cout << +r1 << " " << -r2;
    r1 += r2;
    r1 -= r2;
    r2 *= r1;
    r2 /= r1;
    
    cout << r1 << " " << r2 << "\n";
    
    try {
        Razlomak(1, m);
    } catch(overflow_error &e) {
        cout << e.what();
    }
    cout << "\n";
    
    cout << 2.45 + (long double)Razlomak{255, 100};
    cout << Razlomak{5} + Razlomak() + Razlomak{} + Razlomak(1);
    cout << (int) Razlomak(256, 71);

	return 0;
}