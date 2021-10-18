/B16/17 (Zadaća 5, Zadatak 3)
//Autotestovi by Enil Pajic (mail: epajic1@etf.unsa.ba)
//Za autotestove se obracati *iskljucivo* osobi koja ih pise
#include <iostream>
#include <cmath>
#include <stdexcept>
#include <initializer_list>
#include <limits>
#include <string>

using std::string;
using std::cout;
class Razlomak
{
    long long brojnik,nazivnik;
    static long long NZD(long long a,long long b)
    {
        if(b==0)
            return a;
        return NZD(b,a%b);
    }
    static void Prekoracenje(long long int x,long long int y,string s)
    {
        auto m=std::numeric_limits<long long int>::min();
        auto M=std::numeric_limits<long long int>::max();
        if(s == "*")
        {
            if(y>0 and (x<(m/y) or x>(M/y)))
                throw std::overflow_error("Nemoguce dobiti tacan rezultat");
            else if(y<0 and (x == m or -x>(M/(-y)) or -x<(m/(-y))))
                throw std::overflow_error("Nemoguce dobiti tacan rezultat");
        }
        else if(s == "+")
        {
            if((y>0 and x>M-y) or (y<0 and x<m-y))
                throw std::overflow_error("Nemoguce dobiti tacan rezultat");
        }
        else if(s == "-")
        {
            if((y<0 and x>M+y) or (y>0 and x<m+y))
                throw std::overflow_error("Nemoguce dobiti tacan rezultat");
        }
    }
    public:
    Razlomak(long long b = 0,long long n = 1);
    friend Razlomak operator +(const Razlomak &a,const Razlomak &b);
    friend Razlomak operator -(const Razlomak &a,const Razlomak &b);
    friend Razlomak operator *(const Razlomak &a,const Razlomak &b);
    friend Razlomak operator /(const Razlomak &a,const Razlomak &b);
    Razlomak operator +(){return *this;};
    Razlomak operator -(){
        if(this->brojnik==std::numeric_limits<long long int>::min())
            throw std::overflow_error("Nemoguce dobiti tacan rezultat");
        this->brojnik=-(this->brojnik);
        return *this;};
    Razlomak &operator +=(const Razlomak &a);
    Razlomak &operator -=(const Razlomak &a);
    Razlomak &operator *=(const Razlomak &a);
    Razlomak &operator /=(const Razlomak &a);
    Razlomak operator ++(int);
    Razlomak &operator ++();
    friend bool operator >(const Razlomak &a,const Razlomak &b);
    friend bool operator >=(const Razlomak &a,const Razlomak &b);
    friend bool operator <(const Razlomak &a,const Razlomak &b);
    friend bool operator <=(const Razlomak &a,const Razlomak &b);
    friend bool operator ==(const Razlomak &a,const Razlomak &b);
    friend bool operator !=(const Razlomak &a,const Razlomak &b);
    friend std::ostream &operator <<(std::ostream &tok,const Razlomak &a);
    friend std::istream &operator >>(std::istream &tok,Razlomak &a);
    operator long double()
    { return static_cast<long double>(this->brojnik)/this->nazivnik;}
    long long DajBrojnik()const{return brojnik;}
    long long DajNazivnik()const{return nazivnik;}
};
std::ostream &operator <<(std::ostream &tok,const Razlomak &a)
{
    if(a.nazivnik==1)
        tok<<a.brojnik;
    else
        tok<<a.brojnik<<"/"<<a.nazivnik;
    return tok;
}
std::istream &operator >>(std::istream &tok,Razlomak &a)
{
    char znak;
    long long b,c;
    if(!(tok>>b))
    {
        tok.setstate(std::ios::failbit);
        return tok;
    }
    if((tok.peek()==EOF) or (tok.peek()=='\t') or (tok.peek()=='\v') or (tok.peek()=='\f') or (tok.peek()==' ') or (tok.peek()=='\n') or (tok.peek()=='\r'))
    {
        a=Razlomak(b,1);
        return tok;
    }
    else if(tok.peek()=='/')
    {
        tok>>znak;
        if(tok.peek()>'9' or tok.peek()<'0')
        {
            tok.setstate(std::ios::failbit);
            return tok;
        }
        if(!(tok>>c))
        {
            tok.setstate(std::ios::failbit);
            return tok;
        }
        if((tok.peek()!=EOF) and (tok.peek()!='\t') and (tok.peek()!='\v') and (tok.peek()!='\f') and (tok.peek()!=' ') and (tok.peek()!='\n') and (tok.peek()!='\r'))
        {
            //ZASTO MI IZ TOKA UZIMA \ PA TEK ONDA N A NE SVE ZAJEDNO KAO \N
            //ZATO MI PADA OVAJ TEST ?
            tok.setstate(std::ios::failbit);
            return tok;
        }
        a=Razlomak(b,c);
        return tok;
    }
    tok.setstate(std::ios::failbit);
    return tok;
}
bool operator >(const Razlomak &a,const Razlomak &b)
{
    return (static_cast<long double>(a.brojnik)/a.nazivnik) > (static_cast<long double>(b.brojnik)/b.nazivnik);
}
bool operator <(const Razlomak &a,const Razlomak &b)
{
    return (static_cast<long double>(a.brojnik)/a.nazivnik) < (static_cast<long double>(b.brojnik)/b.nazivnik);
}
bool operator >=(const Razlomak &a,const Razlomak &b)
{
    return (static_cast<long double>(a.brojnik)/a.nazivnik) >= (static_cast<long double>(b.brojnik)/b.nazivnik);
}
bool operator <=(const Razlomak &a,const Razlomak &b)
{
    return (static_cast<long double>(a.brojnik)/a.nazivnik) > (static_cast<long double>(b.brojnik)/b.nazivnik);
}
bool operator ==(const Razlomak &a,const Razlomak &b)
{
    return (static_cast<long double>(a.brojnik)/a.nazivnik) == (static_cast<long double>(b.brojnik)/b.nazivnik);
}
bool operator !=(const Razlomak &a,const Razlomak &b)
{
    return (static_cast<long double>(a.brojnik)/a.nazivnik) != (static_cast<long double>(b.brojnik)/b.nazivnik);
}
Razlomak &Razlomak::operator ++()
{
    return *this+=1;
}
Razlomak Razlomak::operator ++(int)
{
    auto pomoc(*this);
    ++(*this);
    return pomoc;
}
Razlomak &Razlomak::operator +=(const Razlomak &a)
{
    return *this=*this+a;
}
Razlomak &Razlomak::operator *=(const Razlomak &a)
{
    return *this=*this*a;
}
Razlomak &Razlomak::operator -=(const Razlomak &a)
{
    return *this=*this-a;
}
Razlomak &Razlomak::operator /=(const Razlomak &a)
{
    return *this=*this/a;
}
Razlomak::Razlomak(long long b,long long n)
{
    if(n == std::numeric_limits<long long int>::min() and b == n)
        n=std::numeric_limits<long long int>::max(),b=n;
    else if(n == std::numeric_limits<long long int>::min())
        n=std::numeric_limits<long long int>::max(),b=-b;
    long long pomoc;
    if(n == 0)
        throw std::logic_error("Nekorektan razlomak");
    if(n<0)
        b=-b,n=-n;
    pomoc=NZD(b,n);
    b/=pomoc;
    n/=pomoc;
    brojnik=b;
    nazivnik=n;
}
Razlomak operator +(const Razlomak &a,const Razlomak &b)
{
    auto r=Razlomak::NZD(a.nazivnik,b.nazivnik);
    Razlomak::Prekoracenje(a.DajNazivnik(),(b.DajNazivnik()/r),"*");
    Razlomak::Prekoracenje(b.DajBrojnik(),(a.DajNazivnik()/r),"*");
    Razlomak::Prekoracenje(a.DajNazivnik(),(b.DajNazivnik()/r),"*");
    Razlomak::Prekoracenje((a.DajBrojnik()*(b.DajNazivnik()/r)),(b.DajBrojnik()*(a.DajNazivnik()/r)),"+");
    return Razlomak((a.DajBrojnik()*(b.DajNazivnik()/r)+(b.DajBrojnik()*(a.DajNazivnik()/r))),(a.DajNazivnik()*(b.DajNazivnik()/r)));
}
Razlomak operator -(const Razlomak &a,const Razlomak &b)
{
    auto r=Razlomak::NZD(a.nazivnik,b.nazivnik);
    Razlomak::Prekoracenje(a.DajBrojnik(),(b.DajNazivnik()/r),"*");
    Razlomak::Prekoracenje(b.DajBrojnik(),(a.DajNazivnik()/r),"*");
    Razlomak::Prekoracenje(a.DajNazivnik(),(b.DajNazivnik()/r),"*");
    Razlomak::Prekoracenje((a.DajBrojnik()*(b.DajNazivnik()/r)),(b.DajBrojnik()*(a.DajNazivnik()/r)),"-");
    return Razlomak((a.DajBrojnik()*(b.DajNazivnik()/r)-(b.DajBrojnik()*(a.DajNazivnik()/r))),(a.DajNazivnik()*(b.DajNazivnik()/r)));
}
Razlomak operator *(const Razlomak &a,const Razlomak &b)
{
    auto s=Razlomak::NZD(a.brojnik,b.nazivnik);
    auto t=Razlomak::NZD(b.brojnik,a.nazivnik);
    Razlomak::Prekoracenje(a.brojnik/s,b.brojnik/t,"*");
    Razlomak::Prekoracenje(a.nazivnik/t,b.nazivnik/s,"*");
    return Razlomak(((a.brojnik/s)*(b.brojnik/t)),((a.nazivnik/t)*(b.nazivnik/s)));
}
Razlomak operator /(const Razlomak &a,const Razlomak &b)
{
    auto u=Razlomak::NZD(a.brojnik,b.brojnik);
    auto r=Razlomak::NZD(a.nazivnik,b.nazivnik);
    Razlomak::Prekoracenje(a.brojnik/u,b.nazivnik/r,"*");
    Razlomak::Prekoracenje(a.nazivnik/r,b.brojnik/u,"*");
    return Razlomak(((a.brojnik/u)*(b.nazivnik/r)),((a.nazivnik/r)*(b.brojnik/u)));
}
int main ()
{
    {//AT4 (c9): operator >> (2/3) (direktno iz std::cin)
     //NAPOMENA: pogledati AT3 za detaljna objasnjenja (i \R znak je bjelina, malo 'r')
        Razlomak r, p, q;
        std::cin >> r; //5/17
        std::cout << r << std::endl;
        std::cin.clear(); std::cin.ignore (100, '\n');
        //tri zaredom
        std::cin >> r >> p >> q; //10 20 30 -> 10/1 20/1 30/1
        std::cout << r << " " << p << " " << q << std::endl;
        std::cin.clear(); std::cin.ignore (100, '\n');
        std::cin >> r;
        std::cout << r;
    }
	return 0;
}