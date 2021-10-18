/B16/17 (Zadaća 5, Zadatak 3)
//Autotestovi by Enil Pajic (mail: epajic1@etf.unsa.ba)
//Za autotestove se obracati *iskljucivo* osobi koja ih pise
#include <iostream>
#include <stdexcept>
#include <cctype>
#include <limits>
using namespace std;
#define M numeric_limits<long long>::max()
#define m numeric_limits<long long>::min()

class Razlomak
{
    long long int gore;
    long long int dolje;
    static long long int s(long long int p, long long int q)
    {
        while(q!=0)
        {
            long long int pom=p;
            p=q;
            q=pom%q;
        }
        return p;
    }
public:
    Razlomak(long long int p=0, long long int q=1)
    {
        if(q==0) throw logic_error("Nekorektan razlomak");
        if(q<0)
        {
            p=-p;
            long long int pom=2*q;
            q-=pom;
        }
        gore=p/s(p,q);
        dolje=q/s(p,q);
    }
    long long int DajNazivnik() const { return dolje;}
    long long int DajBrojnik() const { return gore;}
    friend Razlomak operator-(Razlomak r1,Razlomak r2)
    {
        long long int r=s(r1.dolje,r2.dolje);
        long long int g=r1.gore*(r2.dolje/r)-r2.gore*(r1.dolje/r), d=r1.dolje*(r2.dolje/r);
        if(g>m && d>m && g<M && d<M) { Razlomak a(g,d); return a;}
        else throw overflow_error("Nemoguce dobiti tacan rezultat");
    }
    friend Razlomak &operator +(Razlomak &r) { return r;}
    friend Razlomak &operator -(Razlomak &r)
    {
        Razlomak r1(r.DajBrojnik(),-r.DajNazivnik());
        r=r1;
        return r;
    }
    friend Razlomak operator+(Razlomak r1,Razlomak r2)
    {
        Razlomak r=r1-(-r2);
        return r;
    }
    friend Razlomak &operator +=(Razlomak &r1, Razlomak r2)
    {
        r1=r1-(-r2); return r1;
    }
    friend Razlomak &operator -=(Razlomak &r1, Razlomak &r2)
    {
        r1=r1-r2;
        return r1;
    }
    friend Razlomak operator*(Razlomak r1,Razlomak r2)
    {
        long long int e=s(r1.gore,r2.dolje);
        long long int t=s(r1.dolje,r2.gore);
        long long int p=(r1.gore/e)*(r2.gore/t), q=(r1.dolje/t)*(r2.dolje/e);
        if(p>m && q>m && p<M && q<M)
            return Razlomak(p,q);
        else throw overflow_error("Nemoguce dobiti tacan rezultat");
    }
    friend Razlomak operator/(Razlomak r1,Razlomak r2)
    {
        Razlomak pom(r2.DajNazivnik(), r2.DajBrojnik());
        Razlomak rez=r1*pom;
        return rez;
    }
     friend Razlomak &operator *=(Razlomak &r1, Razlomak &r2)
     {
         r1=r1*r2;
         return r1;
     }
     friend Razlomak &operator /=(Razlomak &r1, Razlomak &r2)
     {
         r1=r1/r2;
         return r1;
     }
     operator long double() const { return (long double) gore/dolje;}
     friend Razlomak &operator++(Razlomak &r1)
    {
        Razlomak jed(1,1);
        r1=r1+jed;
        return r1;
    }
    friend Razlomak &operator--(Razlomak &r1)
    {
        Razlomak jed(-1,1);
        r1=r1+jed;
        return r1;
    }
    friend Razlomak operator++(Razlomak &r1,int)
    {   
        Razlomak r(r1.DajBrojnik(),r1.DajNazivnik()), jed(1,1);
        r1+=jed;
        return r;
    }
    friend Razlomak operator--(Razlomak &r1,int)
    {
        Razlomak r(r1.DajBrojnik(),r1.DajNazivnik()), jed(-1,1);
        r1-=jed;
        return r;
    }
    friend ostream &operator<<(ostream &cout,Razlomak r1)
    {
        cout<<r1.DajBrojnik();
        if(r1.DajNazivnik()!=1 && r1.DajBrojnik()!=0)
            cout<<"/"<<r1.DajNazivnik();
        return cout;
    }
    friend istream &operator>>(istream &cin,Razlomak &r1)
    {
        r1.gore=0;r1.dolje=1;
        long long int a,b=1;
        cin>>a;
        if(cin.peek()!='\n' && cin.peek()!=' ')
        {
            char c;
            cin>>c; if(c=='/') cin>>b;
            
        }
        Razlomak z(a,b);
        r1=z;
        return cin;
    }
    friend bool operator ==(Razlomak r1, Razlomak r2)
    {
 if( r1.gore==r2.gore && r1.dolje!=r2.dolje) return true;
 return false;
    }
    friend bool operator !=(Razlomak r1, Razlomak r2)
    {
        return (r1.gore!=r2.gore || r1.dolje!=r2.dolje);
    }
    friend bool operator >(Razlomak r1, Razlomak r2)
    {
        return (long double)r1.gore/r1.dolje > (long double)r2.gore/r2.dolje;
    }
    friend bool operator <(Razlomak r1, Razlomak r2) { return (long double) r1.gore/r1.dolje < (long double) r2.gore/r2.dolje; }
    friend bool operator >=(Razlomak r1, Razlomak r2) { return !(r1<r2) || r1==r2; }
    friend bool operator <=(Razlomak r1, Razlomak r2) { return !(r1>r2) || r1==r2; }
};

int main ()
{
	Razlomak r, p, q;
	    cout<<"dhht";
        std::cin >> r; //5/17
        cout<<"DSSD";
        std::cout << r << std::endl;
        std::cin.clear(); std::cin.ignore (100, '\n');
        //tri zaredom
        std::cin >> r >> p >> q; //10 20 30 -> 10/1 20/1 30/1
        std::cout << r << " " << p << " " << q << std::endl;
        std::cin.clear(); std::cin.ignore (100, '\n');
        std::cin >> r;
        std::cout << r;
	return 0;
}