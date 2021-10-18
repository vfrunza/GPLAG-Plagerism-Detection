/B16/17 (Zadaća 5, Zadatak 5)
//Autotestovi by Berina Cocalic (mail: bcocalic1@etf.unsa.ba)
//Za autotestove se obracati *iskljucivo* osobi koja ih pise
#include <iostream>

class Temperature {
    std::list<int> minimalne, maksimalne;
    static int min,max;
    public:
    Temperature (int min, int max);
    void RegistrirajTemperature(std::pair<int, int> minmax);
    void BrisiSve();
    void BrisiNegativneTemperature();
};

Temperature::Temperature (int min, int max) {
    if(min>max) throw std::range_error("Nekorektne temperature");
    Temperature::min=min; Temperature::max=max;
}
void Temperature::RegistrirajTemperature(std::pair<int, int> minmax) {
    if(minmax.first<min || minmax.second>max || min>max) throw std::range_error("“Nekorektne temperature");
    minimalne.insert(minmax.first);
    maksimalne.insert(minmax.second);
}
void Temperature::BrisiSve() {
    auto it1(minimalne.begin());
    auto it2(maksimalne.begin());
    for(int i=0;i<minimalne.size();i++) {
        it1=minimalne.erase(it1);
    }
    for(int i=0;i<maksimalne.size();i++) {
        it2=maksimalne.erase(it2);
    }
}
void BrisiNegativneTemperature() {
    for(auto x : minimalne) {
        if(x<0) minimalne.erase(x);
    }
    for(auto x : maksimalne) {
        if(x<0) maksimalne.erase(x);
    }  
    
}


int main ()
{
	return 0;
}