/B2017/2018: Zadaća 4, Zadatak 2
#include <iostream>

class NepreklapajucaKugla{
    static NepreklapajucaKugla *posljednjaKreirana = nullptr;
    NepreklapajucaKugla *prethodna;
public:
    NepreklapajucaKugla(){
        
        prethodna = posljednjaKreirana;
        posljednjaKreirana = this;
    }
    
    ~NepreklapajucaKugla(){
        
    }
}

int main ()
{
	return 0;
}
