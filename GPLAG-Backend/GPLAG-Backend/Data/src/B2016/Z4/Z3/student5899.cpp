/B 2016/2017, Zadaća 4, Zadatak 3
//Napomena: testovi ce biti dostupni dan pred rok!
#include <iostream>

class Razlomak
{
    long long int brojnik;
    long long int nazivnik;
    static int  NZD(long long int p, long long int q, long long int &b, long long int &n);
public:
    Razlomak(long long int b, long long int r)
    {
        long long int x, y;
        NZD(b,r,x,y);
        brojnik=x;
        nazivnik=y;
    }
    long long int DajBrojnik() const { return brojnik;}
    long long int DajNazivnik() const { return nazivnik;}
    void Ispisi() const { std::cout<<DajBrojnik()<<" "<<DajNazivnik();}
    
};

int   Razlomak::NZD(long long int p, long long int q, long long int &b, long long int &n)
{
    if(q==0) return p;
    int help;
    do
    {
        help = p%q;
        if(help==0) break;
        p=q;
        q=help;
    }
    while(true);
    b=p;
    n=q;
    return p;
}
int main ()
{
    Razlomak a(10,15);
    a.Ispisi();
    
	return 0;
}