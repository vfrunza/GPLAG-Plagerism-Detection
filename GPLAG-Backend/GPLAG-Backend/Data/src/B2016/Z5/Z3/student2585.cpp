/B16/17 (Zadaća 5, Zadatak 3)
//Autotestovi by Enil Pajic (mail: epajic1@etf.unsa.ba)
//Za autotestove se obracati *iskljucivo* osobi koja ih pise
#include <iostream>
#include <cmath>
#include <stdexcept>

using namespace std;

class Razlomak
{
    long long int nazivnik, brojnik;
  public:
    Razlomak(const long long int Nazivnik,const long long int Brojnik);
    Razlomak(const long long int Brojnik) {brojnik=Brojnik; nazivnik=1;}
    Razlomak() {brojnik=0; nazivnik=1;}
    
    long long int DajBrojnik() const{ return brojnik;}
    long long int DajNazivnik() const{ return nazivnik;}
    
    friend Razlomak operator+(const Razlomak &r1, const Razlomak &r2);
    friend Razlomak operator-(const Razlomak &r1, const Razlomak &r2);
    friend Razlomak operator*(const Razlomak &r1, const Razlomak &r2);
    friend Razlomak operator/(const Razlomak &r1, const Razlomak &r2);
    friend Razlomak &operator +=(Razlomak &r1, const Razlomak &r2);
    friend Razlomak &operator -=(Razlomak &r1, const Razlomak &r2);
    friend Razlomak &operator *=(Razlomak &r1, const Razlomak &r2);
    friend Razlomak &operator /=(Razlomak &r1, const Razlomak &r2);
    friend Razlomak &operator ++(Razlomak &r);
    friend Razlomak &operator --(Razlomak &r);
    friend Razlomak operator ++(Razlomak &r, int);
    friend Razlomak operator --(Razlomak &r, int);
    friend bool operator <(const Razlomak &r1, const Razlomak &r2);
    friend bool operator >(const Razlomak &r1, const Razlomak &r2);
    friend bool operator <=(const Razlomak &r1, const Razlomak &r2);
    friend bool operator >=(const Razlomak &r1, const Razlomak &r2);
    friend bool operator ==(const Razlomak &r1, const Razlomak &r2);
    friend bool operator !=(const Razlomak &r1, const Razlomak &r2);
    
    friend ostream& operator<<(ostream &cout,const Razlomak &r);
    friend istream& operator>>(istream &cin, Razlomak &r);
    
    
    void Ispisi(){ std::cout<<"brojnik: "<<brojnik<<" nazivnik: "<<nazivnik;}
};

int NZS(long long int b, long long int n)
{
    long long int maxi(1), na, br;
    na=std::abs(n);
    br=std::abs(b);
    
    for(long long int i(2);i<100000;i++)
    {
        if(na%i==0 && br%i==0) {maxi=i;}
    }
    return maxi;
}

Razlomak::Razlomak(const long long int b,const long long int n)
{
    if(n==0) throw std::logic_error("Nekorektan Razlomak");
    long long int maxi;
 
    maxi=NZS(b,n);
    brojnik=b/maxi;
    nazivnik=n/maxi;
    
    if(nazivnik<0 && brojnik<0)
    {
        brojnik*=(-1);
        nazivnik*=(-1);
    }
    
    if(nazivnik<0 && brojnik>0)
    {
        brojnik*=(-1);
        nazivnik*=(-1);
    }
}

Razlomak operator+(const Razlomak &r1,const Razlomak &r2)
{
    Razlomak r3;
    int r=NZS(r1.nazivnik,r2.nazivnik);
    r3.brojnik=((r1.brojnik*r2.nazivnik/r) + (r1.nazivnik*r2.brojnik/r));
    r3.nazivnik=r1.nazivnik*r2.nazivnik/r;
    r=NZS(r3.brojnik, r3.nazivnik);
    r3.brojnik/=r;
    r3.nazivnik/=r;
    return r3;
}

Razlomak operator -(const Razlomak &r1, const Razlomak &r2)
{
    Razlomak r3;
    int r=NZS(r1.nazivnik, r2.nazivnik);
    r3.brojnik=((r1.brojnik*r2.nazivnik/r) - (r1.nazivnik*r2.brojnik/r));
    r3.nazivnik=r1.nazivnik*r2.nazivnik/r;
    r=NZS(r3.brojnik, r3.nazivnik);
    r3.nazivnik/=r;
    r3.brojnik/=r;
    return r3;
}

Razlomak operator *(const Razlomak &r1, const Razlomak &r2)
{
    Razlomak r3;
    int s=NZS(r1.brojnik,r2.nazivnik), t=NZS(r2.brojnik, r1.nazivnik);
    r3.brojnik=(r1.brojnik/s) * (r2.brojnik/t);
    r3.nazivnik=(r1.nazivnik/t) * (r2.nazivnik/s);
    s=NZS(r3.brojnik, r3.nazivnik);
    r3.brojnik/=s;
    r3.nazivnik/=s;
    return r3;
}

Razlomak operator /(const Razlomak &r1, const Razlomak &r2)
{
    int r=NZS(r1.nazivnik, r2.nazivnik), u=NZS(r1.brojnik, r2.brojnik);
    Razlomak r3;
    r3.brojnik=(r1.brojnik/u) * (r2.nazivnik/r);
    r3.nazivnik=(r1.nazivnik/r) * (r2.brojnik/u);
    r=NZS(r3.brojnik, r3.nazivnik);
    r3.nazivnik/=r;
    r3.brojnik/=r;
    return r3;
}

Razlomak &operator+=(Razlomak &r1, const Razlomak &r2)
{
    return r1=r1+r2;
}

Razlomak &operator -=(Razlomak &r1, const Razlomak &r2)
{
    return r1=r1-r2;
}

Razlomak &operator *=(Razlomak &r1, const Razlomak &r2)
{
    return r1=r1*r2;
}

Razlomak &operator /=(Razlomak &r1, const Razlomak &r2)
{
    return r1=r2/r1;
}

Razlomak &operator ++(Razlomak &r)
{
    Razlomak r2(1,1);
    return r=r+r2;
}

Razlomak &operator --(Razlomak &r)
{
    Razlomak r2(1,1);
    return r=r-r2;
}

Razlomak operator ++(Razlomak &r, int)
{
    Razlomak r2(1,1), r1(r);
    r=r+r2;
    return r1;
}

Razlomak operator --(Razlomak &r, int)
{
    Razlomak r1(r), r2(1,1);
    r=r-r2;
    return r1;
}

bool operator <(const Razlomak &r1, const Razlomak &r2)
{
    long double l1, l2;
    l1=r1.brojnik/r1.nazivnik;
    l2=r2.brojnik/r2.nazivnik;
    return l1-l2<0.0000001;
}

bool operator >(const Razlomak &r1, const Razlomak &r2)
{
    long double l1, l2;
    l1=r1.brojnik/r1.nazivnik;
    l2=r2.brojnik/r2.nazivnik;
    return l1-l2>0.0000001;
}

bool operator <=(const Razlomak &r1, const Razlomak &r2)
{
    long double l1, l2;
    l1=r1.brojnik/r1.nazivnik;
    l2=r2.brojnik/r2.nazivnik;
    return l1-l2<=0.0;
}

bool operator >=(const Razlomak &r1, const Razlomak &r2)
{
    long double l1, l2;
    l1=r1.brojnik/r1.nazivnik;
    l2=r2.brojnik/r2.nazivnik;
    return l1-l2>=0.0;
}

bool operator ==(const Razlomak &r1, const Razlomak &r2)
{
    long double l1, l2;
    l1=r1.brojnik/r1.nazivnik;
    l2=r2.brojnik/r2.nazivnik;
   return l1-l2==0.0;
}

bool operator!=(const Razlomak &r1, const Razlomak &r2)
{
    return !(r1==r2);
}

ostream& operator <<(ostream &cout,const Razlomak &r)
{
    if(r.nazivnik==1) std::cout<<r.brojnik;
    else std::cout<<r.brojnik<<"/"<<r.nazivnik;
    return cout;
}


istream& operator >>(istream &cin,Razlomak &r)
{
    char znak;
    std::cin>>r.brojnik>>znak>>r.nazivnik;
    return cin;
}


int main ()
{
    Razlomak r(2,2), z(2,2);
    if(r<=z) std::cout<<"Da";
    else std::cout<<"NE";
    
    
	return 0;
}