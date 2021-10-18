/B16/17 (Zadaća 5, Zadatak 5)
//Autotestovi by Berina Cocalic (mail: bcocalic1@etf.unsa.ba)
//Za autotestove se obracati *iskljucivo* osobi koja ih pise
#include <iostream>
#include <list>
#include <stdexcept>
#include <algorithm>

class Temperature {
    std::list<int> najmanje;
    std::list<int> najvece;
    public:
    Temperature (int min, int max) {
        if(min>max) throw std::range_error ("Nekorektne temperature");
        najmanje.push_back(min);
        najvece.push_back(max);
    }
    void RegistrirajTemperature (std::pair<int, int> par); 
    void BrisiSve();
};

void Temperature::RegistrirajTemperature(std::pair<int, int> par) {
    if (par.first<*najmanje.begin() || par.second<*najmanje.begin() || 
    par.first>*najvece.begin() || par.second>*najvece.begin() || par.first>par.second )
    throw std::range_error ("Nekorektne temperature");
    najmanje.push_back(par.first);
    najvece.push_back(par.second);
}

/*void Temperature::BrisiSve() {
    for_each(najmanje.begin(), najmanje.end(), );
}*/

int main ()
{
	return 0;
}