/B16/17 (Zadaća 5, Zadatak 3)
//Autotestovi by Enil Pajic (mail: epajic1@etf.unsa.ba)
//Za autotestove se obracati *iskljucivo* osobi koja ih pise
#include <iostream>
#include <limits>
#include <stdexcept>
#include <cctype>
using namespace std;
#define M numeric_limits<long long>::max()
#define m numeric_limits<long long>::min()
class Razlomak
{
    long long int naz,br;
    static long long int sadr(long long int a, long long int b){ if(b==0) return a; return sadr(b,a%b); }
public:
    Razlomak(long long b=0, long long n=1)
    {
        if(n==0) throw logic_error("Nekorektan razlomak");
        if(n<0) { n-=2*n; b*=-1; }
        long long int pom=b;
        b/=sadr(b,n); n/=sadr(pom,n);
        naz=n; br=b;
    }
    friend ostream &operator<<(ostream &cout,Razlomak r)
    {
        if(r.naz!=1 && r.br!=0)
            cout<<r.DajBrojnik()<<"/"<<r.DajNazivnik();
        else cout<<r.DajBrojnik();
        return cout;
    }
    long long int DajBrojnik() const { return br;}
    long long int DajNazivnik() const { return naz;}
    operator long double() const { long double a=(long double)br/naz; return a;}
    friend Razlomak &operator + (Razlomak &r) { return r;}
    friend Razlomak &operator - (Razlomak &r)
    {
        Razlomak pom(-r.br, r.naz);
        r.br=pom.br; r.naz=pom.naz;
        if(r.br>m && r.br<M && r.naz<M && r.naz>m)
            return r;
        else throw overflow_error("Nemoguce dobiti tacan rezultat");
    }
    friend Razlomak operator + (Razlomak r1, Razlomak r2)
    {
        long long int a=r1.br*(r2.naz/sadr(r1.naz,r2.naz))+r2.br*(r1.naz/sadr(r1.naz,r2.naz));
        long long int b=r1.naz*(r2.naz/sadr(r1.naz,r2.naz));
        if(a>m && b>m && a<M && b<M) {
             Razlomak rez(a,b);
             return rez;
        }
        else throw overflow_error("Nemoguce dobiti tacan rezultat");
    }
    friend Razlomak operator - (Razlomak r1, Razlomak r2)
    {
        Razlomak rez=r1+(-r2);
        return rez;
    }
    friend Razlomak &operator +=(Razlomak &r1, Razlomak r2)
    {
        r1=r1+r2;
        return r1;
    }
    friend Razlomak &operator -=(Razlomak &r1, Razlomak r2)
    {
        r1+=-r2;
        return r1;
    }
     friend Razlomak &operator++(Razlomak &r)
    {
        Razlomak a(1,1);
        r=r+a;
        return r;
    }
    friend Razlomak &operator--(Razlomak &r)
    {
        Razlomak a(1,1);
        r=r-a;
        return r;
    }
    friend Razlomak operator++(Razlomak &r1,int)
    {   
        Razlomak r(r1.br,r1.naz), a(1,1);
        r1+=a;
        return r;
    }
    friend Razlomak operator--(Razlomak &r1,int)
    {
        Razlomak r(r1.br,r1.naz), a(1,1);
        r1-=a;
        return r;
    }
    friend Razlomak operator *(Razlomak r1, Razlomak r2)
    {
        long long int a=(r1.br/sadr(r1.br,r2.naz))*(r2.br/sadr(r1.naz,r2.br));
        long long int b=(r1.naz/sadr(r1.naz,r2.br))*(r2.naz/sadr(r1.br,r2.naz));
        if(a>m && b>m && a<M && b<M) {
            Razlomak rez(a,b);
            return rez;
        }
        else throw overflow_error("Nemoguce dobiti tacan rezultat");
    }
    friend Razlomak &operator *=(Razlomak &r1, Razlomak r2)
    {
        r1=r1*r2;
        return r1;
    }
    friend Razlomak operator/(Razlomak r1,Razlomak r2)
    {
        long long int a=(r1.br/sadr(r1.br,r2.br))*(r2.naz/sadr(r1.naz,r2.naz));
        long long int b=(r1.naz/sadr(r1.naz,r2.naz))*(r2.br/sadr(r1.br,r2.br));
        if(a>m && b>m && a<M && b<M) {
            Razlomak rez(a,b); return rez;
        }
        else throw overflow_error("Nemoguce dobiti tacan rezultat");
    }
    friend Razlomak &operator /=(Razlomak &r1, Razlomak r2)
    {
        r1=r1/r2;
        return r1;
    }
    friend istream &operator>>(istream &cin,Razlomak &r)
    {
        Razlomak pom;
        r=pom;
        cin>>r.br;
        if(cin.peek()!='\n' && cin.peek()!=' ')
        {
            char p;
            cin>>p>>r.naz;
            
        }
        Razlomak pom1(r.br,r.naz);
        r=pom1;
        return cin;
    }
};

int main ()
{
	return 0;
}