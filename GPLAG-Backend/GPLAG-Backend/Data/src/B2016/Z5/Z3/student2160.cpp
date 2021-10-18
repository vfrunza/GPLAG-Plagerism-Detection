/B16/17 (Zadaća 5, Zadatak 3)
//Autotestovi by Enil Pajic (mail: epajic1@etf.unsa.ba)
//Za autotestove se obracati *iskljucivo* osobi koja ih pise
#include <iostream>
#include <cmath>
#include <stdexcept>
#include <limits>
#include <sstream>
class Razlomak
{
    long long int brojnik, nazivnik;
    static long long int NZD(long long int b, long long int n)
    {
        if(n == 0)
            return b;
            
        return NZD(n, b % n);
    }
    static void OFSabiranje(long long int a, long long int b)
    {
        if((b > 0 && std::numeric_limits<long long int>::max() - b < a) || 
           (b < 0 && std::numeric_limits<long long int>::lowest() - b > a))
            throw std::overflow_error("Nemoguce dobiti tacan rezultat");
    }
    static void OFOduzimanje(long long int a, long long int b)
    {
        if((b > 0 && std::numeric_limits<long long int>::max() - b > a) ||
        (b < 0 && std::numeric_limits<long long int>::lowest() - b < a))
            throw std::overflow_error("Nemoguce dobiti tacan rezultat");
    }
    static void OFMnozenje(long long int x, long long int y)
    {
        if((y > 0 && (x < std::numeric_limits<long long int>::lowest() / y 
          || x > std::numeric_limits<long long int>::max() / y))
          || (y < 0 && (x > std::numeric_limits<long long int>::lowest() / y 
          || x < std::numeric_limits<long long int>::max() / y)))
            throw std::overflow_error("Nemoguce dobiti tacan rezultat");
    }
public:
    Razlomak(long long int b = 0, long long int n = 1)
    {
        if(n == 0)
            throw std::logic_error("Nekorektan razlomak");
        
        else if(n < 0 && b < 0)
        {
            if(n == std::numeric_limits<long long int>::lowest() || b == std::numeric_limits<long long int>::lowest())
                throw std::overflow_error("Nemoguce dobiti tacan rezultat");
            b = -b, n = -n;
        }
            
        int a = NZD(b, n);
        brojnik = b / a; 
        nazivnik = n / a;
    }
    /*Razlomak(std::initializer_list<long long int> r) 
    {
        if()
        auto i = lista.begin();
        brojnik = *i;
    }*/
    long long int DajBrojnik() const { return brojnik; }
    long long int DajNazivnik() const { return nazivnik; }
    friend Razlomak &operator += (Razlomak &r1, const Razlomak &r2);
    friend Razlomak &operator -= (Razlomak &r1, const Razlomak &r2);
    Razlomak operator + (const Razlomak &r2) const { Razlomak r3 = *this; r3 += r2; return r3; }
    Razlomak operator - (const Razlomak &r2) const { Razlomak r3 = *this; r3 -= r2; return r3; }
    friend Razlomak &operator *= (Razlomak &r1, const Razlomak &r2);
    friend Razlomak &operator /= (Razlomak &r1, const Razlomak &r2);
    Razlomak operator * (const Razlomak &r2) { Razlomak r3 = *this; r3 *= r2; return r3; }
    Razlomak operator / (const Razlomak &r2) { Razlomak r3 = *this; r3 /= r2; return r3;}
    Razlomak operator + () const { return *this; }
    Razlomak operator - () const 
    { 
        Razlomak r = *this; 
        if(r.brojnik == std::numeric_limits<long long int>::lowest()) 
            throw std::overflow_error("Nemoguce dobiti tacan rezultat"); 
        r.brojnik = -r.brojnik; 
        return r; 
    }
    Razlomak &operator ++ () { return *this += 1; }
    Razlomak operator ++ (int) { Razlomak r3 = *this; ++*this; return r3; }
    Razlomak &operator -- () { return *this -= 1; }
    Razlomak operator -- (int) { Razlomak r3 = *this; --*this; return r3; }
    operator long double() const { return (long double)(brojnik) / (long double)(nazivnik); }
    friend bool operator < (const Razlomak &r1, const Razlomak &r2) { return (long double)(r1) < (long double)(r2); }
    friend bool operator > (const Razlomak &r1, const Razlomak &r2) { return (long double)(r1) > (long double)(r2); }
    friend bool operator <= (const Razlomak &r1, const Razlomak &r2) { return r1 < r2 || r1 == r2; }
    friend bool operator >= (const Razlomak &r1, const Razlomak &r2) { return r1 > r2 || r1 == r2; }
    bool operator == (const Razlomak &r1) { return brojnik == r1.brojnik && nazivnik == r1.nazivnik; }
    bool operator != (const Razlomak &r2) { return !(*this == r2); }
    friend std::ostream &operator << (std::ostream &tok, const Razlomak &r);
    friend std::istream &operator >> (std::istream &tok, Razlomak &r);
    
};
Razlomak &operator += (Razlomak &r1, const Razlomak &r2)
{

    long long int r = Razlomak::NZD(r1.nazivnik, r2.nazivnik);
    Razlomak::OFMnozenje(r1.brojnik, r2.nazivnik / r);
    Razlomak::OFMnozenje(r2.brojnik, r1.nazivnik / r);
    Razlomak::OFMnozenje(r1.nazivnik, r2.nazivnik / r);
    Razlomak::OFSabiranje(r1.brojnik * (r2.nazivnik / r), r2.brojnik * (r1.nazivnik / r));
    long double brojnik = r1.brojnik * (r2.nazivnik / r) + r2.brojnik * (r1.nazivnik / r);
    long double nazivnik = r1.nazivnik * (r2.nazivnik / r);
    Razlomak r3(brojnik, nazivnik);
    r1 = r3;
    return r1;
}
Razlomak &operator -= (Razlomak &r1, const Razlomak &r2)
{
    r1 += -r2;
    return r1;
}
Razlomak &operator *= (Razlomak &r1, const Razlomak &r2)
{
    long long int s = Razlomak::NZD(r1.brojnik, r2.nazivnik);
    long long int t = Razlomak::NZD(r2.brojnik, r1.nazivnik);
    Razlomak::OFMnozenje(r1.brojnik, 1 / s);
    Razlomak::OFMnozenje(r2.brojnik, 1 / t);
    Razlomak::OFMnozenje(r1.nazivnik, 1 / t);
    Razlomak::OFMnozenje(r2.nazivnik, 1 / s);
    Razlomak::OFMnozenje((r1.brojnik / s), (r2.brojnik / t));
    Razlomak::OFMnozenje((r1.nazivnik / t), (r2.nazivnik / s));
    r1.brojnik = (r1.brojnik / s) * (r2.brojnik / t);
    r1.nazivnik = (r1.nazivnik / t) * (r2.nazivnik / s);
    return r1;
} 
Razlomak &operator /= (Razlomak &r1, const Razlomak &r2)
{
    Razlomak temp(r2.nazivnik, r2.brojnik);
    r1 *= temp;
    return r1;
}
std::istream &operator >> (std::istream &tok, Razlomak &r)
{
    char znak;
    long long int brojnik, nazivnik;
    tok >> std::ws;
    tok >> brojnik;
    if(!tok)
    {
        tok.setstate(std::ios::failbit);
        return tok;
    }
    if(std::isspace(tok.peek()) || tok.eof())
    {
        r = Razlomak(brojnik);
        return tok;
    }
    tok >> znak;
    if(znak != '/' && !std::isspace(znak))
    {
        tok.setstate(std::ios::failbit);
        return tok;
    }
    tok >> nazivnik;
    if(!std::isspace(tok.peek()) && !tok.eof())
    {
        tok.setstate(std::ios::failbit);
        return tok;
    }
    r = Razlomak(brojnik, nazivnik);
    return tok;
}
std::ostream &operator << (std::ostream &tok, const Razlomak &r)
{
    if(r.nazivnik == 1)
        return tok << r.brojnik;
        
    else
        return tok << r.brojnik << "/" << r.nazivnik;
}
int main ()
{
    Razlomak r;
      std::istringstream is("17/ 4"); //neispravno
    is.clear();
    is >> r;
    if (is.fail()) std::cout << "OK, neispravno!" << std::endl;
    else std::cout << "Nije OK! Ovo nije ispravan unos!" << std::endl;
    return 0;
}