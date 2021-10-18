/B16/17 (Zadaća 5, Zadatak 3)
//Autotestovi by Enil Pajic (mail: epajic1@etf.unsa.ba)
//Za autotestove se obracati *iskljucivo* osobi koja ih pise
#include <iostream>

class Razlomak {
    long long int brojnik, nazivnik;
public:
    Razlomak(long long int brojnik, long long int nazivnik) : brojnik(brojnik), nazivnik(nazivnik) {
        // automatsko skraćivanje razlomka
        // ukoliko je razlomak negativan, negativni znak mora biti zapamćen u brojniku
        // throw std::logic_error("Nekorektan razlomak") ako je nazivnik 0
        // ukoliko se zada samo brojnik, nazivnik automatski na 1
        // realne brojeve - zabraniti
        
    }
    long long int DajBrojnik() {
        return brojnik;
    }
    long long int DajNazivnik() {
        return nazivnik;
    }
};

int main ()
{
	return 0;
}