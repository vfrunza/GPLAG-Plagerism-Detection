/B16/17 (Zadaća 5, Zadatak 5)
//Autotestovi by Berina Cocalic (mail: bcocalic1@etf.unsa.ba)
//Za autotestove se obracati *iskljucivo* osobi koja ih pise
#include <iostream>
#include <list>
#include <stdexcept>
#include <utility>
#include <algorithm>
class Temperature {
    std::list<int> min, max;
public:
    Temperature(int mini, int maxi) {
        if(mini > maxi) throw std::range_error("Nekorektne temperature");
        min.push_back(mini); max.push_back(maxi);
    }
    void RegistrirajTemperature(std::pair<int,int> temp) {
        if(temp.first > temp.second) throw std::range_error("Nekorektne temperature");
        min.push_back(temp.first); max.push_back(temp.second);
    }
    void BrisiSve();
    void BrisiNegativneTemperature();
    int DajBrojRegistriranihTemperatura() const {
        return min.size();
    }
    int DajMinimalnuTemperaturu() const;
    int DajMaksimalnuTemperaturu() const;
    int DajBrojTemperaturaVecihOd() const;
    int DajBrojTemperaturaManjihOd() const;
};
    void Temperature::BrisiSve() {
        auto it2 = max.begin();
        for(auto it = min.begin(); it != min.end(); it++) {
            it = min.erase(it);
            it2 = max.erase(it2);
            it2++;
        }
    }
    void Temperature::BrisiNegativneTemperature() {
        auto it2 = max.begin();
        for(auto it = min.begin(); it != min.end(); it++)
        {
            if(*it < 0 && *it2 < 0) {
                it = min.erase(it);
                it2 = max.erase(it2);
            } it2++;
        }
    }
    int Temperature::DajMinimalnuTemperaturu() const {
        if(min.size() == 0) throw std::logic_error("Nema registriranih temperatura");
        auto a = std::min_element(min.begin(), min.end());
        return *a;
    }
    int Temperature::DajMaksimalnuTemperaturu() const  {
        if(max.size() == 0) throw std::logic_error("Nema registriranih temperatura");
        auto a = std::max_element(max.begin(), max.end());
        return *a;
    }
    int Temperature::DajBrojTemperaturaVecihOd() const {
        if(min.size() == 0) throw std::logic_error("Nema registriranih temperatura");
        
    }
int main ()
{
	return 0;
}