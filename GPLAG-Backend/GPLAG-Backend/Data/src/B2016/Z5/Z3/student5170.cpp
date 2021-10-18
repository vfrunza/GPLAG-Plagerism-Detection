/B16/17 (Zadaća 5, Zadatak 3)
//Autotestovi by Enil Pajic (mail: epajic1@etf.unsa.ba)
//Za autotestove se obracati *iskljucivo* osobi koja ih pise
#include <iostream>
#include <stdexcept>

long long int nzd(long long int a, long long int b)
{
    if (a%b==0) return b;
    return nzd(b,a%b);
}

class Razlomak
{
    long long int brojnik;
    long long int nazivnik;
public:
    Razlomak (long long int a, long long int b);
    Razlomak(long long int a) {
        brojnik=a;
        nazivnik=1;
    };
    Razlomak() {
        brojnik=0;
        nazivnik=1;
    };
   /* explicit Razlomak(std::initializer_list<long long int> lista) {
        brojnik=*(lista.begin());
        nazivnik=*(lista.begin()+1);
    }*/
    long long int DajBrojnik () const {
        return brojnik;
    };
    long long int DajNazivnik () const {
        return nazivnik;
    };
    friend Razlomak operator +(const Razlomak &a,const Razlomak &b);
    friend long long int nzd(long long int a, long long int b);
    friend Razlomak operator *(const Razlomak &a, const Razlomak &b);
    friend Razlomak operator /(const Razlomak &a, const Razlomak &b);
    friend Razlomak operator -(const Razlomak &a,const Razlomak &b);
    friend Razlomak &operator -(Razlomak &a);
    friend Razlomak &operator +(Razlomak &a);
    Razlomak &operator *=(const Razlomak &a);
    Razlomak &operator +=(const Razlomak &a);
    Razlomak &operator -=(const Razlomak &a);
    Razlomak &operator /=(const Razlomak &a);
    friend Razlomak &operator ++(Razlomak &a);
    friend Razlomak operator ++(Razlomak &a, int);
    friend Razlomak &operator --(Razlomak &a);
    friend Razlomak operator --(Razlomak &a, int);
    friend bool operator >(const Razlomak &a, const Razlomak &b);
    friend bool operator <(const Razlomak &a, const Razlomak &b);
    friend bool operator >=(const Razlomak &a, const Razlomak &b);
    friend bool operator <=(const Razlomak &a, const Razlomak &b);
    friend bool operator ==(const Razlomak &a, const Razlomak &b);
    friend bool operator !=(const Razlomak &a, const Razlomak &b);
    friend std::ostream &operator << (std::ostream &tok,const Razlomak &a) {
        if (a.nazivnik==1) tok << a.brojnik;
        else tok << a.brojnik << "/" << a.nazivnik;
        return tok;
    }
    friend std::istream &operator >> (std::istream &tok,Razlomak &a);
    operator long double () const;

};

Razlomak::Razlomak (long long int a, long long int b)
{
    if(b==0) throw std::logic_error ("Nekorektan razlomak");
    if(a<0 && b<0) {
        a=abs(a);
        b=abs(b);
    }
    if(a>0 && b<0) {
        b=abs(b);
        a=-a;
    }
    long long int k=nzd(a,b);
    if(k!=0) {
        a/=k;
        b/=k;
    }
    brojnik=a;
    nazivnik=b;
}

inline bool operator >(const Razlomak &a, const Razlomak &b)
{
    long double a1=a.brojnik/a.nazivnik;
    long double b1=b.brojnik/b.nazivnik;
    return a1>b1;
}
inline bool operator <(const Razlomak &a, const Razlomak &b)
{
    long double a1=a.brojnik/a.nazivnik;
    long double b1=b.brojnik/b.nazivnik;
    return a1<b1;
}
inline bool operator >=(const Razlomak &a, const Razlomak &b)
{
    long double a1=a.brojnik/a.nazivnik;
    long double b1=b.brojnik/b.nazivnik;
    return a1>=b1;
}
inline bool operator <=(const Razlomak &a, const Razlomak &b)
{
    long double a1=a.brojnik/a.nazivnik;
    long double b1=b.brojnik/b.nazivnik;
    return a1<=b1;
}
inline bool operator ==(const Razlomak &a, const Razlomak &b)
{
    long double a1=a.brojnik/a.nazivnik;
    long double b1=b.brojnik/b.nazivnik;
    return a1==b1;
}
inline bool operator !=(const Razlomak &a, const Razlomak &b)
{
    long double a1=a.brojnik/a.nazivnik;
    long double b1=b.brojnik/b.nazivnik;
    return a1!=b1;
}
Razlomak::operator long double () const {
    return (long double)brojnik/nazivnik;
}

std::istream &operator >> (std::istream &tok,Razlomak &a)
{
    char znak;
    tok >> std::ws;
    tok >> a.brojnik;
    if(tok.peek()!='/')
        a.nazivnik=1;
    else {
        tok >> znak;
        tok >>  a.nazivnik;
        if (tok.peek()!=' ')  tok.setstate(std::ios::failbit);
        a=Razlomak(a.brojnik, a.nazivnik);
    }
        return tok;
}

Razlomak &operator ++(Razlomak &a)
{
    a=(a+Razlomak(1));
    return a;
}
Razlomak operator ++(Razlomak &a, int )
{
    Razlomak pomocni(a);
    ++a;
    return pomocni;
}
Razlomak &operator --(Razlomak &a)
{
    a=(a-Razlomak(1));
    return a;
}
Razlomak operator --(Razlomak &a, int )
{
    Razlomak pomocni(a);
    --a;
    return pomocni;
}
Razlomak &Razlomak::operator +=(const Razlomak &a)
{
    *this=*this+a;
    return *this;
}
Razlomak &Razlomak::operator *=(const Razlomak &a)
{
    brojnik=brojnik*a.brojnik;
    nazivnik=nazivnik*a.nazivnik;
    return *this;
}
Razlomak &Razlomak::operator -=(const Razlomak &a)
{
    *this=*this-a;
    return *this;
}
Razlomak &Razlomak::operator /=(const Razlomak &a)
{
    brojnik=brojnik*a.nazivnik;
    nazivnik=nazivnik*a.brojnik;
    return *this;
}

Razlomak &operator -(Razlomak &a)
{
    a.brojnik=-a.brojnik;
    return a;
}

Razlomak &operator +(Razlomak &a)
{
    return a;
}

Razlomak operator+(const Razlomak &a,const Razlomak &b)
{
    // if((y>0 && x>std::numeric_limits<long long int>::max()-b))
    long long int br=a.brojnik*(b.nazivnik/nzd(a.nazivnik,b.nazivnik))+b.brojnik*(a.nazivnik/nzd(a.nazivnik,b.nazivnik));
    long long int naz=a.nazivnik*(b.nazivnik/nzd(a.nazivnik, b.nazivnik));
    Razlomak c(br, naz);
    return c;
}

Razlomak operator-(const Razlomak &a, const Razlomak &b)
{
    long long int br=a.brojnik*(b.nazivnik/nzd(a.nazivnik,b.nazivnik))-b.brojnik*(a.nazivnik/nzd(a.nazivnik,b.nazivnik));
    long long int naz=a.nazivnik*(b.nazivnik/nzd(a.nazivnik, b.nazivnik));
    Razlomak c(br, naz);
    return c;
}

Razlomak operator *(const Razlomak &a, const Razlomak &b)
{
    long long int br=(a.brojnik/nzd(a.brojnik, b.nazivnik))*(b.brojnik/nzd(b.brojnik, a.nazivnik));
    long long int naz=(a.nazivnik/nzd(b.brojnik,a.nazivnik))*(b.nazivnik/nzd(a.brojnik, b.nazivnik));
    Razlomak c(br, naz);
    return c;
}

Razlomak operator /(const Razlomak &a, const Razlomak& b)
{
    long long int br=(a.brojnik/nzd(a.brojnik, b.brojnik))*(b.nazivnik/nzd(b.nazivnik, a.nazivnik));
    long long int naz=(a.nazivnik/nzd(b.nazivnik,a.nazivnik))*(b.brojnik/nzd(a.brojnik, b.brojnik));
    Razlomak c(br, naz);
    return c;
}

int main ()
{

    return 0;
}