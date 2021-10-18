/B16/17 (Zadaća 5, Zadatak 3)
//Autotestovi by Enil Pajic (mail: epajic1@etf.unsa.ba)
//Za autotestove se obracati *iskljucivo* osobi koja ih pise
#include <iostream>
#include <cmath>
#include <stdexcept>
class Razlomak{
    long long int brojnik;
    long long int nazivnik;
    friend long long int NZD(long long int a,long long int b);
    friend void koeficienti(long long int &p,long long int &q,long long int &c,long long int &d, Razlomak &a, Razlomak &b);
    public:
    Razlomak (long long int a,long long int b);
    Razlomak();
    Razlomak(long long int a);
    long long int DajBrojnik() const
    {
        return brojnik;
    }
    long long int DajNazivnik() const
    {
        return nazivnik;
    }
 friend  Razlomak &operator +=(Razlomak &a,const Razlomak &b);
 friend Razlomak &operator -=(Razlomak &a,const Razlomak &b);
 friend Razlomak &operator *=(Razlomak &a,const Razlomak &b);
 friend Razlomak &operator /=(Razlomak &a,const Razlomak &b);
 friend Razlomak operator *(const Razlomak &a,const Razlomak &b);
 friend Razlomak operator +(const Razlomak &a,const Razlomak &b);
 friend Razlomak operator -(const Razlomak &a,const Razlomak &b);
 friend Razlomak operator /(const Razlomak &a,const Razlomak &b);
 friend Razlomak operator +(const Razlomak &a){return a;}
 const Razlomak operator -(const Razlomak &b){
     return{-b.brojnik,b.nazivnik};
 }
 friend std::iostream &operator >>(std::iostream &tok,Razlomak &a);
friend  std::ostream &operator <<(std::ostream &tok,const Razlomak &a)
 {
     if(a.brojnik==0)
     {
         tok<<a.DajBrojnik();
         return tok;
     }
     if(a.nazivnik==1)
     {tok<<a.DajBrojnik();
     
         return tok;
     }
     else
     tok<<a.DajBrojnik()<<"/"<<a.DajNazivnik();
     return tok;
 }
};
long long int NZD(long long int a,long long int b){
    int vrati=1;
    if(b==0)
    return a;
    if(a<0)
    a=0-a;
    if(b<0)
    b=0-b;
    long long int manji=a;
    if(a>b)
    manji=b;
    for(long long int i=2;i<=manji;i++)
    if(a%i==0 && b%i==0)
    vrati=i;
    return vrati;
    
    
    
}
void koeficienti(long long int &p,long long int &q,long long int &c,long long int &d, Razlomak &a, Razlomak &b)
{
      p=NZD(a.nazivnik,b.nazivnik);
    long long int s=NZD(a.brojnik,b.brojnik);
    long long int t=NZD(b.brojnik,a.nazivnik);
    long long int u=NZD(a.brojnik,b.brojnik);
    q=s;
    c=t;
    d=u;
}
Razlomak::Razlomak(long long int a,long long int b)
{
    if(b==0)
     {
         throw std::logic_error("Nekorektan razlomak");
     }
    auto djelilac=NZD(a,b);
    if(djelilac!=0)
    {a=a/djelilac;
    b=b/djelilac;
    }
    if(a<0 && b<0)
    {
        a=0-a;
        b=0-b;
    }
    if(a<0 || b<0)
    {
        a=0-a;
        b=0-a;
        a=0-a;
    }
    brojnik=a;
    nazivnik=b;
}
Razlomak::Razlomak()
{
    brojnik=0;
    nazivnik=1;
}
Razlomak::Razlomak(long long int a)
{
    brojnik=a;
    nazivnik=1;
}

Razlomak &operator+=(Razlomak &a,const Razlomak &b)
{
    long long int r=NZD(a.nazivnik,b.nazivnik);
    long long int s=NZD(a.brojnik,b.brojnik);
    long long int t=NZD(b.brojnik,a.nazivnik);
    long long int u=NZD(a.brojnik,b.brojnik);
    a.brojnik=a.brojnik*(b.nazivnik/r)+b.brojnik*(a.nazivnik/r);
    a.nazivnik=a.nazivnik*(b.nazivnik/r);
    long long int djelilac=NZD(a.brojnik,a.nazivnik);
    a.brojnik/=djelilac;
    a.nazivnik/=djelilac;
    return a;
 
    
}
Razlomak &operator -=(Razlomak &a,const Razlomak &b)
{
    long long int r=NZD(a.nazivnik,b.nazivnik);
    a.brojnik=a.brojnik*(b.nazivnik/r)-b.brojnik*(a.nazivnik/r);
    a.nazivnik=a.nazivnik*(b.nazivnik/r);
    long long int djelilac=NZD(a.brojnik,a.nazivnik);
    a.brojnik/=djelilac;
    a.nazivnik/=djelilac;
    return a;
}
Razlomak &operator *=(Razlomak &a,const Razlomak &b)
{
    long long int s=NZD(a.brojnik,b.brojnik);
    long long int t=NZD(b.brojnik,a.nazivnik);
    a.brojnik=(a.brojnik/s)*(b.brojnik/t);
    a.nazivnik=(a.nazivnik/t)*(b.nazivnik/s);
    long long int djelilac=NZD(a.brojnik,a.nazivnik);
    a.brojnik/=djelilac;
    a.nazivnik/=djelilac;
    return a;
}
Razlomak &operator /=(Razlomak &a,const Razlomak &b)
{
    long long int r=NZD(a.nazivnik,b.nazivnik);
    long long int u=NZD(a.brojnik,b.brojnik);

    a.brojnik=(a.brojnik/u)*(b.nazivnik/r);
    a.nazivnik=(a.nazivnik/r)*(b.brojnik/u);
    long long int djelilac=NZD(a.brojnik,a.nazivnik);
    a.brojnik/=djelilac;
    a.nazivnik/=djelilac;
    return a;
    
}
Razlomak operator *(const Razlomak &a,const Razlomak &b)
{
    auto temp(a);
    temp*=b;
    return temp;
    
}
Razlomak operator +(const Razlomak &a,const Razlomak &b)
{
    auto temp(a);
    temp+=b;
    return temp;

}
Razlomak operator -(const Razlomak &a,const Razlomak &b)
 {
     auto temp(a);
     temp-=b;
     return temp;
 }
 Razlomak operator /(const Razlomak &a,const Razlomak &b)
 {
     auto temp(a);
     temp/=b;
     return temp;
 }
 std::iostream &operator >>(std::iostream &tok,Razlomak &a)
 {
     char znak;
     tok>>std::ws;
     tok>>a.brojnik>>znak>>a.brojnik;
     
     if(znak!='/') tok.setstate(std::ios::failbit); 
     
      return tok;
 }
int main ()
 {
     Razlomak a;
     
     std::cout<<a;
    
	return 0;
}