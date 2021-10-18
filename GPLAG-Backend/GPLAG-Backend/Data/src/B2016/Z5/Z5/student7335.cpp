/B16/17 (Zadaća 5, Zadatak 5)
//Autotestovi by Berina Cocalic (mail: bcocalic1@etf.unsa.ba)
//Za autotestove se obracati *iskljucivo* osobi koja ih pise
#include <iostream>
#include <list>
#include <stdexcept>
#include <utility>

class Temperature{
    int max_temp;
    int min_temp;
    std::list<int> max_temp_list;
    std::list<int> min_temp_list;
public:
    Temperature(int min, int max);
    void RegistrirajTemperature(std::pair<int, int> par);
};

Temperature::Temperature(int min, int max){
    if(min>max) throw std::range_error("Nekorektne temperature");
    max_temp = max; min_temp = min;
}
void Temperature::RegistrirajTemperature(std::pair<int, int> par){
    if(par.first>max_temp || par.second>max_temp || par.first<min_temp || par.second<min_temp) throw std::range_error("Nekorektne temperature");
    
}

int main ()
{
    std::cout << "radi" << std::endl;
	return 0;
}