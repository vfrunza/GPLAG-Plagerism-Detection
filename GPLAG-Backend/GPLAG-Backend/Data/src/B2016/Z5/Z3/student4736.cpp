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
    long long int brojnik;
    long long int nazivnik;
    static long long int nzd(long long int x, long long int y)
    {
        if (y==0) return x;
        return nzd(y, x%y);
    }

public:
    Razlomak(long long int b=0, long long int n=1)
    {
        if(n==0) throw std::logic_error("Nekorektan razlomak");
        if(n<0) 
        {
            n*=(-1);
            b*=(-1);
        }
        auto p=nzd(b, n);
        b/=p;
        n/=p;
        brojnik=b;
        nazivnik=n;
    }
    
    long long int DajBrojnik () const { return brojnik; }
    long long int DajNazivnik () const { return nazivnik; }
    
    friend istream &operator >> (istream &cin, Razlomak &r)
    {
        cin>>r.brojnik;
        if(cin.peek()!=' ' && cin.peek()!='\n')
        {
            char a;
            cin>>a>>r.nazivnik;
        }
        cin.clear();
        cin.ignore (100, '\n');
        return cin;
    }
    
    friend ostream &operator << (ostream &cout, Razlomak r)
    {
        cout<<r.brojnik;
        if(r.nazivnik!=1) cout<<"/"<<r.nazivnik;
        return cout;
    }
    
    friend Razlomak operator + (Razlomak r1, Razlomak r2)
    {
        auto r=nzd(r1.nazivnik, r2.nazivnik);
        Razlomak rez ((r1.brojnik*(r2.nazivnik/r)+r2.brojnik*(r1.nazivnik/r)), r1.nazivnik*r2.nazivnik/r);
        return rez;
    }
    
    friend Razlomak operator - (Razlomak r1, Razlomak r2)
    {
        auto r=nzd(r1.nazivnik,r2.nazivnik);
        Razlomak rez((r1.brojnik*(r2.nazivnik/r)-r2.brojnik*r1.nazivnik/r),r1.nazivnik*r2.nazivnik/r);
        return rez;
    }
    friend Razlomak operator * (Razlomak r1, Razlomak r2)
    {
        auto s=nzd(r1.brojnik, r2.nazivnik), t=nzd(r2.brojnik,r1.nazivnik);
        Razlomak rez(r1.brojnik/s*r2.brojnik/t, r1.nazivnik/t*r2.nazivnik/s);
        return rez;
    }
    friend Razlomak operator / (Razlomak r1, Razlomak r2)
    {
        auto r=nzd(r1.nazivnik,r2.nazivnik), u=nzd(r1.brojnik, r2.brojnik);
        Razlomak rez(r1.brojnik/u*r2.nazivnik/r, r1.nazivnik/r*r2.brojnik/u);
        return rez;
    }
    

};

int main ()
{
	 Razlomak r (17, 18), t (21), v;
    std::cout << "r = " << r << ", t = " << t << ", v = " << v;
	return 0;
}
    