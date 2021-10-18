/B16/17 (Zadaća 5, Zadatak 5)
//Autotestovi by Berina Cocalic (mail: bcocalic1@etf.unsa.ba)
//Za autotestove se obracati *iskljucivo* osobi koja ih pise
#include <iostream>
#include <utility>
#include <list>
#include <algorithm>
#include <functional>
#include <stdexcept>



class Temperatura{
    
    std::list<int> mi;
    std::list<int> ma;
    
    public:
    
    Temperatura(int min,int max){
        if(min>=max) throw std::range_error("Nekorektne temperature");
        mi.push_back(min);
        ma.push_back(max);
    }
    void RegistrirajTemperature(std::pair<int,int> a){
        if(a.first>a.second) throw std::range_error("Nekorektne temperature");
        if(*mi.begin()<a.first) throw std::range_error("Nekorektne temperature");
        if(*ma.begin()>a.second) throw std::range_error("Nekorektne temperature");
        mi.push_back(a.first);
        ma.push_back(a.second);
    }
    void BrisiSve(){
        
    }
};



int main ()
{
	return 0;
}