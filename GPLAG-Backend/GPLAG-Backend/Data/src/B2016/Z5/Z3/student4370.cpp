/B16/17 (Zadaća 5, Zadatak 3)
//Autotestovi by Enil Pajic (mail: epajic1@etf.unsa.ba)
//Za autotestove se obracati *iskljucivo* osobi koja ih pise
#include <iostream>
#include <stdexcept>
class Razlomak{
    long long int brojnik, nazivnik;
public:
    Razlomak (long long int brojnik=0, long long int nazivnik=1) : brojnik(brojnik), nazivnik(nazivnik) {
        if(nazivnik==0) throw std::logic_error ("Nekorektan razlomak");
        if(nazivnik<0) { nazivnik *= (-1); brojnik *= (-1); }
        long long int x;
        x=NZD(brojnik,nazivnik);
        Razlomak::brojnik =brojnik/x;
        Razlomak::nazivnik = nazivnik/ x;
        
    }
    static long long int NZD (long long int a, long long int b) {
        long long int x;
        x=NZD(b, a%b);
        return x;
        
    }
    long long int DajBrojnik () {return brojnik; } 
    long long int DajNazivnik () {return nazivnik; } 
    
};
int main ()
{
	return 0;
}

