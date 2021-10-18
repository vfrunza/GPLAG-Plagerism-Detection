/B16/17 (Zadaća 5, Zadatak 3)
//Autotestovi by Enil Pajic (mail: epajic1@etf.unsa.ba)
//Za autotestove se obracati *iskljucivo* osobi koja ih pise
#include <iostream>
#include <stdexcept>
#include <limits>
#include <cctype>

#define M numeric_limits<long long>::max()
#define m numeric_limits<long long>::min()

using namespace std;

class Razlomak
{
    long long int n,b;
    
    static long long int NZD(long long int a,long long int b)
    {
        if(b==0) return a;
        return(NZD(b,a%b));
    }
    
    public:
    Razlomak(long long int b=0,long long int n=1)
    {   
        if(n==0) throw logic_error("Nekorektan razlomak");
        if(n<0){n*=-1;b*=-1;}
        if(n<0 && b<0){n*=-1;b*=-1;}
        long long int a=NZD(b,n);
        if(a!=1){n/=a;b/=a;}
        
        Razlomak::n=n;
        Razlomak::b=b;
    }
    long long int DajNazivnik()const{return n;}
    long long int DajBrojnik()const{return b;}
    
    friend Razlomak operator+(Razlomak r1,Razlomak r2)
    {
        long long int r=NZD(r1.n,r2.n);
        long long int a=r1.b*(r2.n/r)+r2.b*(r1.n/r);
        long long int b=r1.n*(r2.n/r);
    
    
    
        if(a>m && b>m && a<M && b<M)
            return Razlomak(a,b);
        else throw overflow_error("Nemoguce dobiti tacan rezultat");
    }
    friend Razlomak operator-(Razlomak r1,Razlomak r2)
    {
        long long int r=NZD(r1.n,r2.n);
        long long int a=r1.b*(r2.n/r)-r2.b*(r1.n/r);
        long long int b=r1.n*(r2.n/r);
        
        
        if(a>m && b>m && a<M && b<M)
            return Razlomak(a,b);
        else throw overflow_error("Nemoguce dobiti tacan rezultat");
    }
    friend Razlomak operator*(Razlomak r1,Razlomak r2)
    {
        long long int s=NZD(r1.b,r2.n);
        long long int t=NZD(r1.n,r2.b);
        
        long long int a=(r1.b/s)*(r2.b/t);
        long long int b=(r1.n/t)*(r2.n/s);
         
        
        if(a>m && b>m && a<M && b<M)
            return Razlomak(a,b);
        else throw overflow_error("Nemoguce dobiti tacan rezultat");
    }
    friend Razlomak operator/(Razlomak r1,Razlomak r2)
    {
        long long int r=NZD(r1.n,r2.n);
        long long int u=NZD(r1.b,r2.b);
        
        long long int a=(r1.b/u)*(r2.n/r);
        long long int b=(r1.n/r)*(r2.b/u);
        
        if(a>m && b>m && a<M && b<M)
            return Razlomak(a,b);
        else throw overflow_error("Nemoguce dobiti tacan rezultat");
    }
    friend Razlomak &operator+(Razlomak &r1)
    {
        return r1;
    }
    friend Razlomak &operator-(Razlomak &r1)
    {
        r1.b*=-1;
        r1.n*=-1;
        
        if(r1.n<0){r1.n*=-1;}
        if(r1.n<0 && r1.b<0){r1.b*=-1;}
        
        if(r1.b>m && r1.b<M && r1.n<M && r1.n>m)
            return r1;
        else throw overflow_error("Nemoguce dobiti tacan rezultat");
      }
    friend Razlomak &operator+=(Razlomak &r1,Razlomak r2)
    { 
        r1=r1+r2;
        return r1;
    }
    friend Razlomak &operator-=(Razlomak &r1,Razlomak r2)
    {
        r1=r1-r2;
        return r1;
    }
    friend Razlomak &operator*=(Razlomak &r1,Razlomak r2)
    {
        r1=r1*r2;
        return r1;
    }
    friend Razlomak &operator/=(Razlomak &r1,Razlomak r2)
    {
        r1=r1/r2;
        return r1;
    }
    friend Razlomak &operator++(Razlomak &r1)
    {
        r1+=1;
        return r1;
    }
    friend Razlomak &operator--(Razlomak &r1)
    {
        r1-=1;
        return r1;
    }
    friend Razlomak operator++(Razlomak &r1,int)
    {   
        Razlomak r(r1.DajBrojnik(),r1.DajNazivnik());
        r1+=1;
        return r;
    }
    friend Razlomak operator--(Razlomak &r1,int)
    {
        Razlomak r(r1.DajBrojnik(),r1.DajNazivnik());
        r1-=1;
        return r;
    }
    friend ostream &operator<<(ostream &iziso,Razlomak r1)
    {
        if(r1.DajNazivnik()!=1 && r1.DajBrojnik()!=0)
            iziso<<r1.DajBrojnik()<<"/"<<r1.DajNazivnik();
        else iziso<<r1.DajBrojnik();
        return iziso;
    }
    friend istream &operator>>(istream &uso,Razlomak &r1)
    {
        r1.b=0;r1.n=1;
        uso>>r1.b;
        int jel=uso.peek();
        if(jel!='\n' && jel!=' ')
        {
            char c;
            uso>>c>>r1.n;
            
        }
        //else uso.setstate(ios::failbit);
        return uso;
    }
    operator long double()const
    {
        return (long double)b/n;
    }
    
};


int main ()
{   
    Razlomak r1(396679,437786),r2(147419,131439);
    cout<<r1.DajBrojnik()<<" "<<r1.DajNazivnik()<<endl;
    Razlomak r3(1,3);
    ++r3;
    cout<<r3.DajBrojnik()<<" "<<r3.DajNazivnik()<<endl;
    cin>>r3;
    cout<<r3<<endl;
    Razlomak p,q,r;
    cin>>p>>q>>r;
    cout<<p<<" "<<q<<" "<<r;
	return 0;
}