/B16/17 (Zadaća 5, Zadatak 3)
//Autotestovi by Enil Pajic (mail: epajic1@etf.unsa.ba)
//Za autotestove se obracati *iskljucivo* osobi koja ih pise

#include <iostream>
#include <limits>
#include <stdexcept>

class Razlomak
{
    typedef long long int lli;
    lli brojnik;
    lli nazivnik;
    
    static constexpr auto min = std::numeric_limits<lli>::min();
    static constexpr auto max = std::numeric_limits<lli>::max();
    
    static void baci()
    {
        throw std::overflow_error("Nemoguce dobiti tacan rezultat");
    }
    
    static lli NZD (lli p, lli q)
    {
        return q == 0 ? p : NZD(q, p % q);
    }
    static lli plus(lli x, lli y)
    {
        if( x > 0 && y > 0 && x > max - y)
            baci();
        if( x > 0 && y < 0 && x < min  - y)
            baci();
        if(x < 0 && y < 0)
            return -plus(-x, -y);
        if(x < 0 &&  y > 0)
            return plus(y, x);
        return x + y;
    }
    
    static lli minus(lli x, lli y)
    {
        return plus(x, -y);
    }
    
    static lli mnozenje(lli x, lli y)
    {
        if( x > 0 && y > 0 &&  (x < min / y || x > max / y) )
            baci();
        if( x > 0 &&  y < 0 && (x == min || -x > max || -x < min /(-y) ))
            baci();
        if(x < 0 && y < 0)
            return mnozenje(-x, -y);
        if(x < 0 &&  y > 0)
            return mnozenje(y, x);
        return x * y;
    }
    
    static long double dijeli(const Razlomak& r)
    {
        return static_cast<long double>(r.DajBrojnik()) / static_cast<long double>(r.DajNazivnik());
    }
    
public:
    
    Razlomak() : brojnik(0), nazivnik(1) {}
    Razlomak(lli x, lli y);
    Razlomak(lli x) : brojnik(x), nazivnik(1) {}
    lli DajBrojnik() const
    {
        return brojnik;
    }
    
    lli DajNazivnik()const
    {
        return nazivnik;
    }
    
    Razlomak& operator+=(const Razlomak& r);
    Razlomak& operator-=(const Razlomak& r);
    Razlomak& operator*=(const Razlomak& r);
    Razlomak& operator/=(const Razlomak& r);
    
    Razlomak& operator ++()
    {
        *this += Razlomak(1);
        return *this;
    }
    
    Razlomak& operator --()
    {
        *this -= Razlomak(1);
        return *this;
    }
    
    Razlomak operator ++(int)
    {
        operator ++();
        return *this;
    }
    
    Razlomak operator --(int)
    {
        operator--();
        return *this;
    }
    
    friend Razlomak operator- (const Razlomak& r1, const Razlomak& r2);
    friend Razlomak operator+ (const Razlomak& r1, const Razlomak& r2);
    friend Razlomak operator* (const Razlomak& r1, const Razlomak& r2);
    friend Razlomak operator/ (const Razlomak& r1, const Razlomak& r2);
    friend bool operator < (const Razlomak& r1, const Razlomak& r2);
    friend bool operator > (const Razlomak& r1, const Razlomak& r2);
    
    Razlomak operator+() const
    {
        return *this;
    }
    
    Razlomak operator-() const
    {
        if(DajBrojnik() == min)
            baci();
        return Razlomak(-DajBrojnik(), DajNazivnik());
    }   
    operator long double() const
    {
        return dijeli(*this);
    }
};

std::ostream& operator<< (std::ostream& os, const Razlomak& r)
{
    if(r.DajNazivnik() == 1)
        return os << r.DajBrojnik();
    return os << r.DajBrojnik() << "/" << r.DajNazivnik();
}

bool bjelina(char c)
{
    return c == ' ' || c == '\n' || c == '\t' || c == '\f' || c == '\v' || c == '\r';
}

std::istream& operator>> (std::istream& os, Razlomak& r)
{
    long long int b, a;
    os >> b; // unesi broj preksace sve bjeline
    
    // ako nije broj ne valja unos od sebe prekid
    if(!os.good())
    {
        if(os.peek() == EOF)
            r = Razlomak(b);
        return os;
    }
        
        
    // ako ceka nazivnik
    if(os.peek() == '/')
    {
        char kosa;
        os >> kosa; // uzmi kosu
        os >> a; // unesi a
    }
    // ako nije kosa i bjelina je to je jedan broj unesi i prekini
    else if(bjelina(os.peek()) || os.peek() == EOF)
    {
        r = Razlomak(b);
        return os;
    }
    
    // unijeli smo drugi broj
    // vidi jel bjelina ako nije znaci ne valja unos
    if(!bjelina(os.peek()) && os.peek() != EOF)
    {
        os.setstate(std::ios_base::failbit) ;
        return os;
    }
    // dobar unos dodijeli brojeve
    r = Razlomak(b, a);
    return os;
}

bool operator == (const Razlomak& r1, const Razlomak& r2)
{
    return (r1.DajBrojnik() == r2.DajBrojnik() && r1.DajNazivnik() == r2.DajNazivnik());
}

bool operator != (const Razlomak& r1, const Razlomak& r2)
{
    return !(r1 == r2);
}

bool operator < (const Razlomak& r1, const Razlomak& r2)
{
    return Razlomak::dijeli(r1) < Razlomak::dijeli(r2);
}

bool operator <= (const Razlomak& r1, const Razlomak& r2)
{
    return r1 < r2 || r1 == r2;
}


bool operator >= (const Razlomak& r1, const Razlomak& r2)
{
    return r1 > r2 || r1 == r2;
}

bool operator > (const Razlomak& r1, const Razlomak& r2)
{
    return Razlomak::dijeli(r1) > Razlomak::dijeli(r2);
}



Razlomak& Razlomak::operator*=(const Razlomak& r)
{
    auto s = NZD(DajBrojnik(), r.DajNazivnik());
    auto t = NZD(r.DajBrojnik(), DajNazivnik());
    
    auto r1 = Razlomak(Razlomak::mnozenje(DajBrojnik() / s, r.DajBrojnik()/t), 
                      Razlomak::mnozenje(DajNazivnik() / t, r.DajNazivnik()/s) );
    return *this = r1;
}   

Razlomak& Razlomak::operator/=(const Razlomak& r2)
{
    auto r = NZD(DajNazivnik(), r2.DajNazivnik());
    auto u = NZD(DajBrojnik(), r2.DajBrojnik());
    
    auto r1 = Razlomak(Razlomak::mnozenje(DajBrojnik() / u, r2.DajNazivnik()/r), 
                      Razlomak::mnozenje(DajNazivnik() / r, r2.DajBrojnik()/u) );
    return *this = r1;
    
}

Razlomak operator/ (const Razlomak& r1, const Razlomak& r2)
{
    auto r = r1;
    return r/=r2;
}


Razlomak operator* (const Razlomak& r1, const Razlomak& r2)
{
    auto r = r1;
    return r*=r2;
}

Razlomak& Razlomak::operator-=(const Razlomak& r)
{
    auto nzd = NZD(DajNazivnik(), r.DajNazivnik());
    auto br_1 = Razlomak::mnozenje( DajBrojnik(), r.DajNazivnik()/nzd);
    auto br_2 = Razlomak::mnozenje( r.DajBrojnik(), DajNazivnik()/nzd);
    auto nz = Razlomak::mnozenje(DajNazivnik(), r.DajNazivnik() / nzd);
    auto nr = Razlomak(Razlomak::minus(br_1, br_2), nz);
    *this = nr;
    return *this;
}


Razlomak& Razlomak::operator+=(const Razlomak& r)
{
    auto nzd = NZD(DajNazivnik(), r.DajNazivnik());
    auto br_1 = Razlomak::mnozenje( DajBrojnik(), r.DajNazivnik()/nzd);
    auto br_2 = Razlomak::mnozenje( r.DajBrojnik(), DajNazivnik()/nzd);
    auto nz = Razlomak::mnozenje(DajNazivnik(), r.DajNazivnik() / nzd);
    auto nr = Razlomak(Razlomak::plus(br_1, br_2), nz);
    *this = nr;
    return *this;
}

Razlomak operator+ (const Razlomak& r1, const Razlomak& r2)
{
    auto r = r1;
    return r+=r2;
}

Razlomak operator- (const Razlomak& r1, const Razlomak& r2)
{
    auto r = r1;
    return r-=r2;
}

Razlomak::Razlomak(lli x, lli y)    
{
    if( y == 0)
        throw std::logic_error("Nekorektan razlomak");
    bool n = false, b = false;
    brojnik = x;
    nazivnik = y;
    if(brojnik == 0)
    {
        nazivnik = 1;
        return;
    }
    if(brojnik < 0)
    {
        brojnik *= -1;
        b = true;
    }
    if(nazivnik < 0)
    {
        nazivnik *= -1;
        n = true;
    }
    auto nzd = NZD(brojnik, nazivnik);
    
    if (brojnik > nazivnik)
    {
        while ( nzd != 1 && nazivnik % nzd == 0) {
           nazivnik /= nzd;
           brojnik /= nzd;
        }    
    }
    else
    {
        while ( nzd != 1 && brojnik % nzd == 0) {
            nazivnik /= nzd;
            brojnik /= nzd;
        }    
    }
    if(n != b)
        brojnik *= -1;
}


int main ()
{
    try {
        Razlomak r(1), r1(2,3), r2;
        std::cout << r << " " << r1 << " " << r2 << "\n";
        ++r;--r1;r2++;
        std::cout << r << " " << r1 << " " << r2 << "\n";
        r--;
        -r1;
        +r2;
        std::cout << r << " " << r1 << " " << r2 << "\n";
        r+=r;
        r1-=r2;
        r2 *= r1;
        std::cout << r << " " << r1 << " " << r2 << "\n";
        r /= r2;
        std::cout << r2 << "\n";
        std::cout << r + r1 << " " << r2 - r1 << " " << r1/r2 << " " << r2 * r2 << "\n";
        std::cout << static_cast<long double> (r) << "\n";
        std::cout << (r1 == r2) << " " << (r1 != r1) << " " << (r1 < r2) << " " << (r > r2) << "\n";
        std::cout << (r1 <= r2) << " " << (r1 >= r) << "\n";
    }
    catch (...) {
        
    }
    
}