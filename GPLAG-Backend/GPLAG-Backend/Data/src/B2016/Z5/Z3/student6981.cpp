/B16/17 (Zadaća 5, Zadatak 3)
//Autotestovi by Enil Pajic (mail: epajic1@etf.unsa.ba)
//Za autotestove se obracati *iskljucivo* osobi koja ih pise
#include <iostream>
#include <stdexcept>
#include <limits>

using std::cout;
using std::cin;
using std::endl;
using std::logic_error;
using std::overflow_error;
using std::numeric_limits;

class Razlomak
{
    long long int brojnik;
    long long int nazivnik;
    static long long int NZD(long long int p, long long int q)
    {
        return NZD(q, p%q);
    }
public:
    Razlomak(long long int brojnik=0, long long int nazivnik=1)
    {
        if(nazivnik<0){brojnik*=-1; nazivnik*=-1;}
        if(nazivnik==0) throw("Nekorektan razlomak");
    }
    long long int DajBrojnik() const {return brojnik;}
    long long int DajNazivnik() const {return nazivnik;}
    
    Razlomak operator+() const {return *this;}
    Razlomak operator-() const {return {-brojnik, -nazivnik};}
    
    Razlomak operator+=(const Razlomak &razlomak);
    Razlomak operator-=(const Razlomak &razlomak);
    Razlomak operator*=(const Razlomak &razlomak);
    Razlomak operator/=(const Razlomak &razlomak);
    
    friend Razlomak operator+(const Razlomak &razlomak1, const Razlomak &razlomak2);
    friend Razlomak operator-(const Razlomak &razlomak1, const Razlomak &razlomak2);
    friend Razlomak operator*(const Razlomak &razlomak1, const Razlomak &razlomak2);
    friend Razlomak operator/(const Razlomak &razlomak1, const Razlomak &razlomak2);
    
    friend bool operator<(const Razlomak &razlomak1, const Razlomak &razlomak2);
    friend bool operator>(const Razlomak &razlomak1, const Razlomak &razlomak2);
    friend bool operator<=(const Razlomak &razlomak1, const Razlomak &razlomak2);
    friend bool operator>=(const Razlomak &razlomak1, const Razlomak &razlomak2);
    friend bool operator==(const Razlomak &razlomak1, const Razlomak &razlomak2);
    friend bool operator!=(const Razlomak &razlomak1, const Razlomak &razlomak2);
    
    friend std::ostream &operator<<(std::ostream &tok, const Razlomak &razlomak);
    
    operator long double() const {return (long double)(brojnik)/nazivnik;}
};



Razlomak operator+(const Razlomak &razlomak1, const Razlomak &razlomak2)
{
    long long int m(numeric_limits<long long int>::min());
    long long int M(numeric_limits<long long int>::max()); 
    long long int r(NZD(razlomak1.nazivnik, razlomak2.nazivnik));
    return Razlomak(razlomak1.brojnik*(razlomak2.nazivnik/r)+razlomak2.brojnik*(razlomak1.nazivnik/r), razlomak1.nazivnik*(razlomak2.nazivnik/r));
}

Razlomak operator-(const Razlomak &razlomak1, const Razlomak &razlomak2)
{
    long long int r(NZD(razlomak1.nazivnik, razlomak2.nazivnik));
    return Razlomak(razlomak1.brojnik*(razlomak2.nazivnik/r)-razlomak2.brojnik*(razlomak1.nazivnik/r), razlomak1.nazivnik*(razlomak2.nazivnik/r));
}

Razlomak operator*(const Razlomak &razlomak1, const Razlomak &razlomak2)
{
    long long int s(NZD(razlomak1.brojnik, razlomak2.nazivnik));
    long long int t(NZD(razlomak2.brojnik, razlomak1.nazivnik));
    return Razlomak((razlomak1.brojnik/s)*(razlomak2.brojnik/t), (razlomak1.nazivnik/t)*(razlomak2.nazivnik/s));
}

Razlomak operator/(const Razlomak &razlomak1, const Razlomak &razlomak2)
{
    long long int u(NZD(razlomak1.brojnik, razlomak2.brojnik));
    long long int r(NZD(razlomak1.nazivnik, razlomak2.nazivnik));
    return Razlomak((razlomak1.brojnik/u)*(razlomak2.nazivnik/r), (razlomak1.nazivnik/r)*(razlomak2.brojnik/u))
}

bool operator<(const Razlomak &razlomak1, const Razlomak &razlomak2)
{
    long double r(NZD(razlomak1.brojnik, razlomak2.brojnik));
    long double s(NZD(razlomak1.nazivnik, razlomak2.nazivnik));
    
    return (razlomak1.brojnik/r)*(razlomak2.nazivnik/s)<(razlomak2.brojnik/r)*(razlomak1.nazivnik/s);
}

bool operator>(const Razlomak &razlomak1, const Razlomak &razlomak2)
{
    long double r(NZD(razlomak1.brojnik, razlomak2.brojnik));
    long double s(NZD(razlomak1.nazivnik, razlomak2.nazivnik));
    
    return (razlomak1.brojnik/r)*(razlomak2.nazivnik/s)>(razlomak2.brojnik/r)*(razlomak1.nazivnik/s);
}

bool operator<=(const Razlomak &razlomak1, const Razlomak &razlomak2)
{
    long double r(NZD(razlomak1.brojnik, razlomak2.brojnik));
    long double s(NZD(razlomak1.nazivnik, razlomak2.nazivnik));
    
    return (razlomak1.brojnik/r)*(razlomak2.nazivnik/s)<=(razlomak2.brojnik/r)*(razlomak1.nazivnik/s);
}

bool operator>=(const Razlomak &razlomak1, const Razlomak &razlomak2)
{
    long double r(NZD(razlomak1.brojnik, razlomak2.brojnik));
    long double s(NZD(razlomak1.nazivnik, razlomak2.nazivnik));
    
    return (razlomak1.brojnik/r)*(razlomak2.nazivnik/s)>=(razlomak2.brojnik/r)*(razlomak1.nazivnik/s);
}

std::ostream operator<<(std::ostream &tok, const Razlomak &razlomak)
{
    if(razlomak.nazivnik==1)tok<<razlomak.brojnik<<endl;
    else tok<<razlomak.brojnik<<"/"<<razlomak.nazivnik<<endl;
    return tok;
}

std::istream operator>>(std::istream &tok, Razlomak &razlomak)
{
    char znak;
    tok>>std::ws;
    tok>>razlomak.brojnik;
    tok>>znak;
    if(znak!='/' || '\n')tok.setstate(std::ios::failbit);
    if(znak=='/')tok>>razlomak.nazivnik;
    return tok;
}

int main ()
{
	return 0;
}