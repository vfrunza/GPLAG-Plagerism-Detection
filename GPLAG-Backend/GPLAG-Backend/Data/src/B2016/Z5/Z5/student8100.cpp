/B16/17 (Zadaća 5, Zadatak 5)
//Autotestovi by Berina Cocalic (mail: bcocalic1@etf.unsa.ba)
//Za autotestove se obracati *iskljucivo* osobi koja ih pise
#include <iostream>
#include <list>

class Temperatura {
    std::list<int> min_temp;
    std::list<int> max_temp;
    public:
    
    Temperatura (int min_temp, int max_temp) {
        if (min_temp > max_temp) throw std::range_error ("Nekorektne temperature");
    }
    
    RegistrirajTemperature
};

int main ()
{
    try {
        int n;
    }
    catch (std::range_error izuzetak) {
        std::cout << izuzetak.what() << std:endl;
    }
	return 0;
}