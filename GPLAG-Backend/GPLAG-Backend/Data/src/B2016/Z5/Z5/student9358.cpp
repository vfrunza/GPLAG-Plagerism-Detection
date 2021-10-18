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
    Temperature(int najmanja, int najveca){
        if(najmanja>najveca) throw std::range_error("Nekorektne temperature");
        min.push_back(najmanja);
        max.push_back(najveca);
    }
    void RegistrirajTemperature(std::pair<int,int> par){
       auto it1=min.begin();
       auto it2=max.begin();
       if (par.first<*it1 || par.first>*it2 || par.second<*it1 || par.second>*it2 || par.first>par.second) throw std::range_error("Nekorektne temperature");
       min.push_back(par.first);
       max.push_back(par.second);
    }
    void BrisiSve{
        
    }
    void BrisiNegativne
};
int main ()
{
	return 0;
}