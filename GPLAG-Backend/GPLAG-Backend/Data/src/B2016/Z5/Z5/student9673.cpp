/B16/17 (Zadaća 5, Zadatak 5)
//Autotestovi by Berina Cocalic (mail: bcocalic1@etf.unsa.ba)
//Za autotestove se obracati *iskljucivo* osobi koja ih pise

#include <iostream>
#include <list>
#include <stdexcept>

class Temperature{
    std::list<int> min;
    std::list<int> max;
public:
    Temperature(int min_t, int max_t){
        if(min_t > max_t) throw std::range_error("Nekorektne temperature");
        min.push_back(min_t); max.push_back(max_t);                             // konstruktor
    }
    
    void RegistrirajTemperature(std::pair<int, int> par);
    void BrisiSve();
    
};

void Temperature::RegistrirajTemperature(std::pair<int, int> par){
    auto p_max(max.begin());
    auto p_min(min.begin());
    if(par.first > par.second or !(par.first >= *p_min and par.first <= *p_max) or !(par.second >= *p_min and par.second <= *p_max)) throw std::range_error("Nekorektne temperature");
    min.push_back(par.first);
    max.push_back(par.second);
}



int main ()
{
	return 0;
}