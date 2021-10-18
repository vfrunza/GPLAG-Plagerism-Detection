/B16/17 (Zadaća 5, Zadatak 3)
//Autotestovi by Enil Pajic (mail: epajic1@etf.unsa.ba)
//Za autotestove se obracati *iskljucivo* osobi koja ih pise
#include <iostream>
#include <stdexcept>
class Razlomak
{
    long long int brojnik,nazivnik;
    static long long int NZD(long long int a,long long int b)
    {
        while(b!=0)
        {
            a=b;
            b=a%b;
        }
        return a;
    }
    public:
    Razlomak(long long int a=0,long long int b=1)
    {
        if(b==0)
        throw std::logic_error("Nekorektan razlomak");
        
    }
};
int main ()
{
	return 0;
}