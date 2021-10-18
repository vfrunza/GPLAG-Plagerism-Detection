/B16/17 (Zadaća 5, Zadatak 3)
//Autotestovi by Enil Pajic (mail: epajic1@etf.unsa.ba)
//Za autotestove se obracati *iskljucivo* osobi koja ih pise
#include <iostream>
#include <stdexcept>
#include <climits>
class Razlomak
{
    long long int brojnik, nazivnik;
    static long long int NZD(long long int x, long long int y);
public:
    Razlomak(int x=0, int y=1);
    long long int DajBrojnik()const {
        return brojnik;
    }
    long long int DajNazivnik()const {
        return nazivnik;
    }
    friend std::ostream &operator <<(std::ostream &tok, Razlomak r);
    friend Razlomak operator +(const Razlomak &a, const Razlomak &b);
    friend Razlomak operator -(const Razlomak &a, const Razlomak &b);
    friend Razlomak operator *(const Razlomak &a, const Razlomak &b);
    friend Razlomak operator /(const Razlomak &a, const Razlomak &b);
    friend Razlomak operator +(const Razlomak &a);
    friend Razlomak operator -(const Razlomak &a);
    friend Razlomak &operator +=(Razlomak &a, const Razlomak &b) {
        a.brojnik+=b.brojnik;
        a.nazivnik+=b.nazivnik;
        return a;
    }
    friend Razlomak &operator -=( Razlomak &a, const Razlomak &b) {
        a.brojnik-=b.brojnik;
        a.nazivnik-=b.nazivnik;
        return a;
    }
    friend Razlomak &operator *=( Razlomak &a, const Razlomak &b) {
        a.brojnik*=b.brojnik;
        a.nazivnik*=b.nazivnik;
        return a;
    }
    friend Razlomak &operator /=( Razlomak &a, const Razlomak &b) {
        a.brojnik/=b.brojnik;
        a.nazivnik/=b.nazivnik;
        return a;
    }
    friend Razlomak &operator++(Razlomak &r) {
        Razlomak p(1);
        Razlomak x=r+p;
        r.brojnik=x.brojnik;
        r.nazivnik=x.nazivnik;
        return r;
    }
    friend	Razlomak operator ++(Razlomak &r, int) {
        Razlomak pomocni(r);
        Razlomak p(1);
        Razlomak x=r+p;
        r.brojnik=x.brojnik;
        r.nazivnik=x.nazivnik;
        return pomocni;
    }
    friend Razlomak &operator--(Razlomak &r) {
        Razlomak p(1);
        Razlomak x=r-p;
        r.brojnik=x.brojnik;
        r.nazivnik=x.nazivnik;
        return r;
    }
    friend Razlomak operator --(Razlomak &r, int) {
        Razlomak pomocni(r);
        Razlomak p(1);
        Razlomak x=r-p;
        r.brojnik=x.brojnik;
        r.nazivnik=x.nazivnik;
        return pomocni;
    }
    friend bool operator <(const Razlomak &a, const Razlomak &b);
    friend bool operator >(const Razlomak &a, const Razlomak &b);
    friend bool operator <=(const Razlomak &a, const Razlomak &b);
    friend bool operator >=(const Razlomak &a, const Razlomak &b);
    friend bool operator ==(const Razlomak &a, const Razlomak &b);
    friend bool operator !=(const Razlomak &a, const Razlomak &b);
    operator long double() const;


/*    friend std::istream &operator>>(std::istream &tok, Razlomak &r) {
         char znak;
         r:
         tok >> std::ws; // "Progutaj" razmake...
             tok >> r.brojnik;
             r.nazivnik = 1;
             tok >> znak;
             if(znak != '/') tok.setstate(std::ios::failbit);
             else tok >> r.nazivnik;
                     if(znak=='\n') return tok;

             tok >> std::ws; // "Progutaj" razmake...
             tok>>znak;
             if(znak>='0' && znak<='9') goto r;
             if(znak!='\n' || !(znak>='0' && znak<='9')) tok.setstate(std::ios::failbit);

     }*/
};
long long int Razlomak::NZD(long long int x, long long int y)
{
    while(y!=0) {
        long long int p(x);
        x=y;
        y=p%y;
        p=x;
        if(y==0) break;
    }
    return x;
}
Razlomak::Razlomak(int x, int y)
{
    if(y==0) throw std::logic_error("Nekorektan razlomak");
    if(x>0 && y<0) {
        x*=-1;
        y*=-1;
    }
    if(x<0 && y<0) {
        x*=-1;
        y*=-1;
    }
    long long int p(x);
    long long int q(y);
    if(NZD(x, q)<=x && NZD(x, q)<=y) {
        x=x/NZD(x, q);
        y=y/NZD(p, q);
    }
    Razlomak::brojnik=x;
    Razlomak::nazivnik=y;
}
std::ostream &operator <<(std::ostream &tok, Razlomak r)
{
    if(r.DajBrojnik()==0 || r.DajNazivnik()==1) tok<<r.DajBrojnik();
    else tok<<r.DajBrojnik()<<"/"<<r.DajNazivnik();
    return tok;
}
Razlomak operator +(const Razlomak &a, const Razlomak &b)
{
    if(b.brojnik>0 && b.nazivnik>0) {
        if(double(a.brojnik)/a.nazivnik>(LLONG_MAX-double(b.brojnik)/b.nazivnik)) throw std::overflow_error("Nemoguce dobiti tacan rezultat");

    }
    if(b.brojnik<0 || b.nazivnik<0) {
        if(double(a.brojnik)/a.nazivnik<(LLONG_MIN-double(b.brojnik)/b.nazivnik)) throw std::overflow_error("Nemoguce dobiti tacan rezultat");

    }
    long long int r=Razlomak::NZD(a.DajNazivnik(), b.DajNazivnik());
    return {static_cast<int>(a.DajBrojnik()*(b.DajNazivnik()/r)+b.DajBrojnik()*(a.DajNazivnik()/r)),static_cast<int>(a.DajNazivnik()*(b.DajNazivnik()/r))};
}
Razlomak operator -(const Razlomak &a, const Razlomak &b)
{
    if(b.brojnik>0 && b.nazivnik>0) {
        if(double(a.brojnik)/a.nazivnik<(LLONG_MIN-double(b.brojnik)/b.nazivnik)) throw std::overflow_error("Nemoguce dobiti tacan rezultat");

    }
    if(b.brojnik<0 || b.nazivnik<0) {
        if(double(a.brojnik)/a.nazivnik>(LLONG_MAX-double(b.brojnik)/b.nazivnik)) throw std::overflow_error("Nemoguce dobiti tacan rezultat");

    }
    long long int r=Razlomak::NZD(a.DajNazivnik(), b.DajNazivnik());
    return {static_cast<int>(a.DajBrojnik()*(b.DajNazivnik()/r)-b.DajBrojnik()*(a.DajNazivnik()/r)),static_cast<int>(a.DajNazivnik()*(b.DajNazivnik()/r))};
}
Razlomak operator *(const Razlomak &a, const Razlomak &b)
{
    if(b.brojnik>0 && b.nazivnik>0) {
        if((double(a.brojnik)/a.nazivnik<(LLONG_MIN/double(b.brojnik)/b.nazivnik)) ||(double(a.brojnik)/a.nazivnik>(LLONG_MAX/double(b.brojnik)/b.nazivnik)))throw std::overflow_error("Nemoguce dobiti tacan rezultat");

    }
    if(b.brojnik<0 || b.nazivnik<0) {
        if(double(a.brojnik)/a.nazivnik==LLONG_MIN ||((double(a.brojnik)/a.nazivnik)*-1)>(LLONG_MAX/double(((b.brojnik)/b.nazivnik)*(-1)))||((double(a.brojnik)/a.nazivnik)*-1)<(LLONG_MIN/double(((b.brojnik)/b.nazivnik)*(-1))))throw std::overflow_error("Nemoguce dobiti tacan rezultat");

    }
    long long int s=Razlomak::NZD(a.DajBrojnik(), b.DajNazivnik());
    long long int t=Razlomak::NZD(b.DajBrojnik(), a.DajNazivnik());
    return {static_cast<int>((a.DajBrojnik()/s)*(b.DajBrojnik()/t)),static_cast<int>((a.DajNazivnik()/t)*(b.DajNazivnik()/s))};
}
Razlomak operator /(const Razlomak &a, const Razlomak &b)
{
    long long int u=Razlomak::NZD(a.DajBrojnik(), b.DajBrojnik());
    long long int r=Razlomak::NZD(a.DajNazivnik(), b.DajNazivnik());
    return {static_cast<int>((a.DajBrojnik()/u)*(b.DajNazivnik()/r)),static_cast<int>((a.DajNazivnik()/r)*(b.DajBrojnik()/u))};
}
Razlomak operator +(const Razlomak &a)
{
    return a;
}
Razlomak operator -(const Razlomak &a)
{
    return {static_cast<int>(a.brojnik)*-1, static_cast<int>(a.nazivnik)*-1};
}

bool operator <(const Razlomak &a, const Razlomak &b)
{
    long double x=(static_cast<long double>(a.brojnik))/a.nazivnik;
    long double y=(static_cast<long double>(b.brojnik))/b.nazivnik;
    return x<y;
}
bool operator >(const Razlomak &a, const Razlomak &b)
{
    long double x=(static_cast<long double>(a.brojnik))/a.nazivnik;
    long double y=(static_cast<long double>(b.brojnik))/b.nazivnik;
    return x>y;
}
bool operator <=(const Razlomak &a, const Razlomak &b)
{
    long double x=(static_cast<long double>(a.brojnik))/a.nazivnik;
    long double y=(static_cast<long double>(b.brojnik))/b.nazivnik;
    return (x<y || x==y);
}
bool operator >=(const Razlomak &a, const Razlomak &b)
{
    long double x=(static_cast<long double>(a.brojnik))/a.nazivnik;
    long double y=(static_cast<long double>(b.brojnik))/b.nazivnik;
    return (x>y || x==y);
}
bool operator ==(const Razlomak &a, const Razlomak &b)
{
    long double x=(static_cast<long double>(a.brojnik))/a.nazivnik;
    long double y=(static_cast<long double>(b.brojnik))/b.nazivnik;
    return x==y;

}
bool operator !=(const Razlomak &a, const Razlomak &b)
{
    long double x=(static_cast<long double>(a.brojnik))/a.nazivnik;
    long double y=(static_cast<long double>(b.brojnik))/b.nazivnik;
    return !(x==y);
}
Razlomak::operator long double()const
{
    long double x=static_cast<long double>(brojnik)/nazivnik;
    return x;
}
int main ()
{
    return 0;
}