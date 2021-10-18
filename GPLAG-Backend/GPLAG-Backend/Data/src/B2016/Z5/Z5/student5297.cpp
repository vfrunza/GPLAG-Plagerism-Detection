/B16/17 (Zadaća 5, Zadatak 5)
//Autotestovi by Berina Cocalic (mail: bcocalic1@etf.unsa.ba)
//Za autotestove se obracati *iskljucivo* osobi koja ih pise
#include <iostream>
#include <list>
#include <stdexcept>

class Temperature {
    std::list<int> max_temperature;
    std::list<int> min_temperature;
public:
    Temperature(int min, int max);
    void RegistrirajTemperature(std::pair<int, int> parovi);
    
    
};

Temperature::Temperature(int min, int max) {
    if(min<max) throw std::range_error("Nekorektne temperature");
    max_temperature.push_back(max);
    min_temperature.push_back(min);
}

void Temperature::RegistrirajTemperature(std::pair<int, int> parovi) {
    if(parovi.first>parovi.second) throw std::range_error("Nekorektne temperature");
    max_temperature.push_back(parovi.second);
    min_temperature.push_back(parovi.first);
    //for(auto x: min_temperature) {
       // if()
   // }
}




int main () {
	return 0;
}