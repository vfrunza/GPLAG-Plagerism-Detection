/B16/17 (Zadaća 5, Zadatak 5)
//Autotestovi by Berina Cocalic (mail: bcocalic1@etf.unsa.ba)
//Za autotestove se obracati *iskljucivo* osobi koja ih pise
#include <iostream>
#include <list>
#include <utility>
#include <stdexcept>

class Temperature {
    std::list<int> minimalne;
    std::list<int> maksimalne;
    std::list<std::pair<int,int>> temperature;
    public:
    Temperature(int minimalna, int maksimalna) {
        if(minimalna>maksimalna) throw std::range_error("Nekorektne temperature");
        minimalne.push_back(minimalna);
        maksimalne.push_back(maksimalna);
    }
    
    void RegistrirajTemperature(std::pair<int,int> temp) {
        if(temp.first>temp.second) throw std::range_error("Nekorektne temperature");
        temperature.push_back(temp);
    }
    
    void BrisiSve() {
        minimalne.resize(0);
        maksimalne.resize(0);
        temperature.resize(0);
    }
    void BrisiNegativneTemperature() {
        for(auto i(temperature.begin()); i!=temperature.end(); i++) {
            if(i->first < 0 && i->second < 0) {
                i->first = 0;
                i->second = 0;
            }
        }
    }
    
    int DajBrojRegistriranihTemperatura() const {
        int br=0;
        for(auto i(temperature.begin()); i!=temperature.end(); i++) 
        br++;
        return br;
    }
    
    int DajMinimalnuTemperaturu() const {
        
    }
    
    
};

int main ()
{
    
	return 0;
}