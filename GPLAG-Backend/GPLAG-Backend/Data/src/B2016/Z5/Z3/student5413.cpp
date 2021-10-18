/B16/17 (Zadaća 5, Zadatak 3)
//Autotestovi by Enil Pajic (mail: epajic1@etf.unsa.ba)
//Za autotestove se obracati *iskljucivo* osobi koja ih pise
#include <iostream>
#include <stdexcept>
#include <string>

class Razlomak
{
    long long int brojnik, nazivnik;
    static int NZD(long long int p, long long int q);
public:
    Razlomak() : brojnik(0), nazivnik(1) {}
    Razlomak(long long int p) : brojnik(p), nazivnik(1) {}
    Razlomak(long long int p, long long int q);
    
    long long int DajBrojnik() const { return brojnik; }
    long long int DajNazivnik() const { return nazivnik; }
    
    friend std::istream &operator >> (std::istream &tok, Razlomak &raz);
    friend std::ostream &operator << (std::ostream &tok, const Razlomak &raz); 
    
    friend bool operator == (const Razlomak &r1, const Razlomak &r2);
    friend bool operator != (const Razlomak &r1, const Razlomak &r2);
    friend bool operator <= (const Razlomak &r1, const Razlomak &r2);
    friend bool operator >= (const Razlomak &r1, const Razlomak &r2);
    friend bool operator < (const Razlomak &r1, const Razlomak &r2);
    friend bool operator > (const Razlomak &r1, const Razlomak &r2);

    
    friend Razlomak &operator + (Razlomak &r);
    friend Razlomak &operator - (Razlomak &r);
    
    friend Razlomak operator ++ (Razlomak &r, int);
    friend Razlomak &operator ++ (Razlomak &r);
    friend Razlomak operator -- (Razlomak &r, int);
    friend Razlomak &operator -- (Razlomak &r);
    
    friend Razlomak operator + (const Razlomak &r1, const Razlomak &r2);
    friend Razlomak operator - (const Razlomak &r1, const Razlomak &r2);
    friend Razlomak operator * (const Razlomak &r1, const Razlomak &r2);
    friend Razlomak operator / (const Razlomak &r1, const Razlomak &r2);
    
    friend Razlomak &operator += (Razlomak &r1, const Razlomak &r2);
    friend Razlomak &operator -= (Razlomak &r1, const Razlomak &r2);
    friend Razlomak &operator *= (Razlomak &r1, const Razlomak &r2);
    friend Razlomak &operator /= (Razlomak &r1, const Razlomak &r2);
};

int Razlomak::NZD(long long int p, long long int q)
{
    if(q == 0) return p;
    if(p < 0 || q < 0)
    {
        p = std::abs(p);
        q = std::abs(q);
    }
    
    int nzd;
    for(int i(1); i <= p && i <= q; i++)
    {
        if(p%i == 0 && q%i == 0)
          nzd = i;
    }
    return nzd;
}

Razlomak::Razlomak(long long int p, long long int q) : brojnik(p), nazivnik(q)
{
    if(q == 0)
      throw std::logic_error("Nekorektan razlomak");
    
    if(p < 0 && q < 0)
    {
        brojnik = std::abs(brojnik);
        nazivnik = std::abs(nazivnik);
    }
    else if(brojnik > 0 && nazivnik < 0)
    {
        brojnik = -brojnik;
        nazivnik = std::abs(nazivnik);
    }
    
    int nzd(NZD(p, q));
    
    brojnik /= nzd;
    nazivnik /= nzd;
}

//Operatori
//Ulaz / Izlaz
/*std::istream &operator >> (std::istream &tok, Razlomak &raz)
{
    char znak;
    
    
}*/

std::ostream &operator << (std::ostream &tok, const Razlomak &raz)
{
    tok << raz.brojnik;
    if(raz.nazivnik != 1 && raz.brojnik != 0)
    {
        tok << "/" << raz.nazivnik;
    }
    return tok;
}

//Logicki
bool operator == (const Razlomak &r1, const Razlomak &r2)
{
    return (r1.brojnik == r2.brojnik && r1.nazivnik == r2.nazivnik);
}

bool operator != (const Razlomak &r1, const Razlomak &r2)
{
    return !(r1 == r2);
}

bool operator <= (const Razlomak &r1, const Razlomak &r2)
{
    auto x(Razlomak::NZD(r1.brojnik, r2.brojnik)), y(Razlomak::NZD(r2.nazivnik, r2.nazivnik));
    return (r1.brojnik / x) * (r2.nazivnik / y) <= (r2.brojnik / x) * (r1.nazivnik / y);   
}

bool operator >= (const Razlomak &r1, const Razlomak &r2)
{
    auto x(Razlomak::NZD(r1.brojnik, r2.brojnik)), y(Razlomak::NZD(r2.nazivnik, r2.nazivnik));
    return (r1.brojnik / x) * (r2.nazivnik / y) >= (r2.brojnik / x) * (r1.nazivnik / y);   
}

bool operator < (const Razlomak &r1, const Razlomak &r2)
{
    auto x(Razlomak::NZD(r1.brojnik, r2.brojnik)), y(Razlomak::NZD(r2.nazivnik, r2.nazivnik));
    return (r1.brojnik / x) * (r2.nazivnik / y) < (r2.brojnik / x) * (r1.nazivnik / y);   
}

bool operator > (const Razlomak &r1, const Razlomak &r2)
{
    auto x(Razlomak::NZD(r1.brojnik, r2.brojnik)), y(Razlomak::NZD(r2.nazivnik, r2.nazivnik));
    return (r1.brojnik / x) * (r2.nazivnik / y) <= (r2.brojnik / x) * (r1.nazivnik / y);   
}

//Unarni
Razlomak &operator + (Razlomak &r) { return r; }

Razlomak &operator - (Razlomak &r) { r.brojnik = -r.brojnik; return r;}
    
/*Razlomak operator ++ (Razlomak &r, int)
{
    Razlomak x(r);
    
}*/

/*friend Razlomak &operator ++ (Razlomak &r);
    friend Razlomak operator -- (Razlomak &r, int);
    friend Razlomak &operator -- (Razlomak &r);*/
    
Razlomak &operator += (Razlomak &r1, const Razlomak &r2)
{
    auto x(Razlomak::NZD(r2.nazivnik, r2.nazivnik));
    
    r1.brojnik = r1.brojnik * (r2.nazivnik / x) + r2.brojnik * (r1.nazivnik / x);
    r1.nazivnik *= (r2.nazivnik / x);
    
    r1 = Razlomak(r1.brojnik, r2.nazivnik);
    return r1;
}

Razlomak &operator -= (Razlomak &r1, const Razlomak &r2)
{
    auto x(Razlomak::NZD(r2.nazivnik, r2.nazivnik));
    
    r1.brojnik = r1.brojnik * (r2.nazivnik / x) - r2.brojnik * (r1.nazivnik / x);
    r1.nazivnik *= (r2.nazivnik / x);
    
    r1 = Razlomak(r1.brojnik, r2.nazivnik);
    return r1;
}

Razlomak &operator *= (Razlomak &r1, const Razlomak &r2)
{
    auto x(Razlomak::NZD(r1.brojnik, r2.nazivnik)), y(Razlomak::NZD(r2.brojnik, r1.nazivnik));
    
    r1.brojnik = (r1.brojnik / x) * (r2.brojnik / y);
    r1.nazivnik = (r1.nazivnik / y) * (r2.nazivnik / x);
    
    r1 = Razlomak(r1.brojnik, r2.nazivnik);
    return r1;
}

Razlomak &operator /= (Razlomak &r1, const Razlomak &r2)
{
    auto x(Razlomak::NZD(r1.nazivnik, r2.nazivnik)), y(Razlomak::NZD(r1.brojnik, r2.brojnik));
    
    r1.brojnik = (r1.brojnik / y) * (r2.nazivnik / x);
    r1.nazivnik = (r1.nazivnik / x) * (r2.brojnik / y);
    
    r1 = Razlomak(r1.brojnik, r2.nazivnik);
    return r1;
}

int main ()
{
    Razlomak r1(7, -5), r2(7, -5);
    
    r1 *= r2;
    std::cout << r1;
	return 0;
}