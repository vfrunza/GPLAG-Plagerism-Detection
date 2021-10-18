/B16/17 (Zadaća 5, Zadatak 5)
//Autotestovi by Berina Cocalic (mail: bcocalic1@etf.unsa.ba)
//Za autotestove se obracati *iskljucivo* osobi koja ih pise
#include <iostream>
#include <list>
#include <stdexcept>

class Temperature {
    int min, max;
    std::list<int> minimalne, maksimalne;
    bool KakoSiMajkoKakoSiOce(const std::pair<int, int> &parovi){
        if(parovi.first > parovi.second) return true;
        if(parovi.first < min || parovi.second < min) return true;
        if(parovi.first > max || parovi.second > max) return true;
        return false;
    }
public:
    explicit Temperature(int min, int max);
    void RegistrirajTemperature(const std::pair<int, int> &par);
    void BrisiSve();
    void BrisiNegativneTemperature();
    int DajBrojRegistriranihTemperatura() { return minimalne.size();  }
    int DajMinimalnuTemperaturu();
    int DajMaksimalnuTeperaturu();
    int DajBrojTeperaturaVecihOd(int x);
    int DajBrojTeperaturaManjihOd(int x);
};

Temperature::Temperature(int min, int max){
    if(min > max) throw std::range_error("Nekorektne temperature");
    this->min = min; this->max = max;
}

void Temperature::RegistrirajTemperature(const std::pair<int, int> &par){
    if(KakoSiMajkoKakoSiOce(par)) throw std::range_error("Nekorektne temperature");
    minimalne.push_back(par.first); maksimalne.push_back(par.second);
}

void Temperature::BrisiSve() {
    minimalne.resize(0); maksimalne.resize(0);
}

void Temperature::BrisiNegativneTemperature() {
    
}

int Temperature::DajMaksimalnuTeperaturu() {
    
}





int main ()
{
	return 0;
}