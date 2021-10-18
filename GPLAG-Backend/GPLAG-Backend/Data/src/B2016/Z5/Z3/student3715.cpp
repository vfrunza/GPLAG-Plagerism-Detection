/B16/17 (Zadaća 5, Zadatak 3)
//Autotestovi by Enil Pajic (mail: epajic1@etf.unsa.ba)
//Za autotestove se obracati *iskljucivo* osobi koja ih pise
#include <iostream>
#include <stdexcept>

typedef long long int tip;
class Razlomak {
    tip nazivnik, brojnik;
    tip DajManji(tip naziv, tip br) {
        if(naziv < br)
           return std::abs(naziv);
        else if(naziv > br)
           return std::abs(br);
        else
           return std::abs(naziv);
    }
    tip Skrativi(tip naz, tip broj)
    {
    
        for(tip i = DajManji(naz, broj); i > 1; --i)
            if(naz % i == 0 && broj % i == 0)
               return i;
        return 0;
    }
public:
    Razlomak(tip broj, tip naz) {}
    Razlomak(tip broj) {
        brojnik = broj;
        nazivnik = 1;
    }
    Razlomak() {
        brojnik = 0;
        nazivnik = 1;
    }
    
};
int main ()
{
	return 0;
}