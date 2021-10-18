/B16/17 (Zadaća 5, Zadatak 3)
//Autotestovi by Enil Pajic (mail: epajic1@etf.unsa.ba)
//Za autotestove se obracati *iskljucivo* osobi koja ih pise
#include <iostream>
#include <cctype>
#include <stdexcept>
#include <limits>

using namespace std;

class Razlomak
{
    long long int brojnik, nazivnik;
    static long long int nzd(long long int x, long long int y)
    {
        if(y==0) return x;
        return nzd(y,x%y);
    }
public:
    Razlomak(long long int b=0, long long int n=1)
    {
        if(n==0) throw logic_error("Nekorektan razlomak");
        if(n<0) { n=-n; b=-b;}
        auto p=nzd(b,n);
        b/=p;
        n/=p;
        brojnik=b;
        nazivnik=n;
    }
    long long int DajBrojnik() const { return brojnik;}
    long long int DajNazivnik() const { return nazivnik;}
    friend istream &operator >> (istream &cin, Razlomak &r)
    {
        r.brojnik=0; r.nazivnik=1;
        cin>>r.brojnik;
        if(cin.peek()!=' ' && cin.peek()!='\n') { char a; cin>>a>>r.nazivnik;}
        return cin;
    }
    friend ostream &operator << (ostream &cout, Razlomak r)
    {
        cout<<r.brojnik;
        if(r.nazivnik!=1) cout<<"/"<<r.nazivnik;
        return cout;
    }
    operator long double()const
    {
        return (long double) brojnik/nazivnik;
    }
    friend Razlomak operator + (Razlomak r1, Razlomak r2)
    {
        auto r=nzd(r1.nazivnik,r2.nazivnik);
        Razlomak rez((r1.brojnik*(r2.nazivnik/r)+r2.brojnik*r1.nazivnik/r),r1.nazivnik*r2.nazivnik/r);
        return rez;
    }
    friend Razlomak &operator += (Razlomak &r1, Razlomak r2)
    {
        r1=r1+r2;
        return r1;
    }
    friend Razlomak operator - (Razlomak r1, Razlomak r2)
    {
        auto r=nzd(r1.nazivnik,r2.nazivnik);
        Razlomak rez((r1.brojnik*(r2.nazivnik/r)-r2.brojnik*r1.nazivnik/r),r1.nazivnik*r2.nazivnik/r);
        return rez;
    }
    friend Razlomak &operator -= (Razlomak &r1, Razlomak r2)
    {
        r1=r1-r2;
        return r1;
    }
    friend Razlomak operator * (Razlomak r1, Razlomak r2)
    {
        auto s=nzd(r1.brojnik, r2.nazivnik), t=nzd(r2.brojnik,r1.nazivnik);
        Razlomak rez(r1.brojnik/s*r2.brojnik/t, r1.nazivnik/t*r2.nazivnik/s);
        return rez;
    }
    friend Razlomak &operator *= (Razlomak &r1, Razlomak r2)
    {
        r1=r1*r2;
        return r1;
    }
    friend Razlomak operator / (Razlomak r1, Razlomak r2)
    {
        auto r=nzd(r1.nazivnik,r2.nazivnik), u=nzd(r1.brojnik, r2.brojnik);
        Razlomak rez(r1.brojnik/u*r2.nazivnik/r, r1.nazivnik/r*r2.brojnik/u);
        return rez;
    }
    friend Razlomak &operator /= (Razlomak &r1, Razlomak r2)
    {
        r1=r1/r2;
        return r1;
    }
    friend Razlomak &operator +(Razlomak &r) { return r;}
    friend Razlomak &operator -(Razlomak &r)
    {
        r.brojnik=-r.brojnik;
        return r;
    }
    friend Razlomak &operator ++(Razlomak &r)
    {
        Razlomak p{1,1};
        r+=p;
        return r;
    }
    friend Razlomak operator ++(Razlomak &r, int)
    {
        Razlomak p=r, t{1,1};
        r+=t;
        return p;
    }
    friend bool operator ==(Razlomak r1, Razlomak r2)
    {
        return r1.brojnik==r2.brojnik && r1.nazivnik==r2.nazivnik;
    }
    friend bool operator !=(Razlomak r1, Razlomak r2)
    {
        return !(r1.brojnik==r2.brojnik && r1.nazivnik==r2.nazivnik);
    }
    friend bool operator >(Razlomak r1, Razlomak r2)
    {
        long double b1=r1.brojnik/r1.nazivnik, b2=r2.brojnik/r2.nazivnik;
        return b1>b2;
    }
    friend bool operator <(Razlomak r1, Razlomak r2) { return !(r1>r2); }
    friend bool operator >=(Razlomak r1, Razlomak r2) { return r1>r2 || r1==r2; }
    friend bool operator <=(Razlomak r1, Razlomak r2) { return r1<r2 || r1==r2; }
    
};

int main ()
{
	 Razlomak r (17, 18), t (21), v;
	 t++;
    std::cout << "r = " << r << ", t = " << t << ", v = " << v;
	return 0;
}