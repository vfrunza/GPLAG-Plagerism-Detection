/B16/17 (Zadaća 5, Zadatak 3)
//Autotestovi by Enil Pajic (mail: epajic1@etf.unsa.ba)
//Za autotestove se obracati *iskljucivo* osobi koja ih pise
#include <iostream>
#include <stdexpcept>

class Razlomak{
    long long int brojnik, nazivnik;
public:
    Razlomak(long long int brojnik, long long int nazivnik);
    
};

Razlomak::Razlomak(long long int brojnik, long long int nazivnik){
    if(nazivnik == 0) throw std::logic_error("Nekorektan razlomak");
    
}

int main ()
{
	return 0;
}