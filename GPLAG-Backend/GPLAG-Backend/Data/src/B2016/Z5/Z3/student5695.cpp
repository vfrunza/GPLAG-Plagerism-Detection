/B16/17 (Zadaća 5, Zadatak 3)
//Autotestovi by Enil Pajic (mail: epajic1@etf.unsa.ba)
//Za autotestove se obracati *iskljucivo* osobi koja ih pise
#include <iostream>
#include <stdexcept>
#include <climits>


class Razlomak{
    long long int brojnik;
    long long int nazivnik;
   static long long int NZD(long long int p, long long int q)
   {
        if(q==0) return p;
        else return NZD(q,(p%q));
    }
    Razlomak(long long int b=0, long long int n=1)
    {
        if(n==0) throw std::logic_error ("Nekorektan razlomak");
        if((b>0 && n<0) ||(b<0 && n<0) ) {b=-b; n=-n;}
       if(b%n==0){ b=b/n; n=1;}
       long long int temp=NZD(b,n);
       while(b%temp==0 && n%temp==0)
       {
           b/=temp;
           n/=temp;
       }
       
   brojnik=b; nazivnik=n;
   
    }

long long int DajBrojnik() const {return brojnik;}
long long int DajNazivnik() const {return nazivnik;}
friend Razlomak operator+ (const Razlomak &r1, const Razlomak &r2)
{
    long long int br,naz;
    long long int r, t,s;
    r=NZD(r1.DajNazivnik(), r2.DajNazivnik());
    s=NZD(r1.DajBrojnik(), r2.DajNazivnik());
    t=NZD(r2.DajBrojnik(), r1.DajNazivnik());
    br=r1.DajBrojnik()*(r2.DajNazivnik()/r) + r2.DajBrojnik()*(r1.DajNazivnik()/r);
    naz=r1.DajNazivnik()*(r2.DajNazivnik()/r);
    return {br, naz};
}
friend Razlomak operator- (const Razlomak &r1, const Razlomak &r2)
{
    long long int br,naz;
    long long int r, t,s;
    r=NZD(r1.DajNazivnik(), r2.DajNazivnik());
    s=NZD(r1.DajBrojnik(), r2.DajNazivnik());
    t=NZD(r2.DajBrojnik(), r1.DajNazivnik());
    br=r1.DajBrojnik()*(r2.DajNazivnik()/r) - r2.DajBrojnik()*(r1.DajNazivnik()/r);
    naz=r1.DajNazivnik()*(r2.DajNazivnik()/r);
    return {br, naz};
}

friend Razlomak operator* (const Razlomak &r1, const Razlomak &r2)
{
    long long int br,naz;
    long long int r, t,s;
    r=NZD(r1.DajNazivnik(), r2.DajNazivnik());
    s=NZD(r1.DajBrojnik(), r2.DajNazivnik());
    t=NZD(r2.DajBrojnik(), r1.DajNazivnik());
    br=(r1.DajBrojnik()/s)*(r2.DajBrojnik()/t);
    naz=(r1.DajNazivnik()/t)*(r2.DajNazivnik()/s);
    return {br, naz};
}
friend operator/ (const Razlomak &r1, const Razlomak &r2)
{
    long long int br,naz;
    long long int r,u;
    r=NZD(r1.DajNazivnik(), r2.DajNazivnik());
    u=NZD(r1.DajBrojnik(), r2.DajBrojnik());
    br=(r1.DajBrojnik()/u)*(r2.DajNazivnik()/r);
    naz=(r1.DajNazivnik()/r)*(r2,DajBrojnik()/u);
    
}
};
/*long long int NZD(long long int p, long long int q)
   {
        if(q==0) return p;
        else return NZD(q,(p%q));
    }
long long int f(int m, int n){
    long long int temp=NZD(m,n);
       while(m%temp==0 && n%temp==0) {m/=temp; n/=temp;}
       return n;
}
*/

int main ()
{   
	return 0;
}