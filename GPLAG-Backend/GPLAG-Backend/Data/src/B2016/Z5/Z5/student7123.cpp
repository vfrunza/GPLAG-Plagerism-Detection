#include <iostream>
#include <list>
#include <stdexcept>
#include <utility>
#include <algorithm>

class Temperature {
    std::list<int> min, max;
    public:
    Temperature(int maxi, int mini) {
        if(mini > maxi) throw std::range_error("Nekorektne temperature");
        min.push_back(mini); max.push_back(maxi);
    }
    void RegistrirajTemperature(std::pair<int, int> p); 
    void BrisiSve();
    void BrisiNegativneTemperature();
    int DajMinimalnuTemperaturu();
    int DajMaksimalnuTemperaturu();
    int DajBrojTeperaturaVecihOd(int tmp);
    int DajBrojTeperaturaManjihOd(int tmp);

};

    void Temperature::RegistrirajTemperature(std::pair<int, int> p) {
        if(p.first > p.second) throw std::range_error("Nekorektne temperature");
    }
    
    void Temperature::BrisiSve() {
        min.erase(min.begin(), min.end());
        max.erase(max.begin(), max.end());
    } 
    
    void Temperature::BrisiNegativneTemperature() {
           }
           
    int Temperature::DajMinimalnuTemperaturu() {
        if(min.begin() == min.end()) throw std::logic_error("Nema registriranih temperatura");
        return *(min_element(min.begin(), min.end()));
    }
    
    int Temperature::DajMaksimalnuTemperaturu() {
        if(max.begin() == max.end()) throw std::logic_error("Nema registriranih temperatura");
        return *(max_element(max.begin(), max.end()));
    }
    
    int Temperature::DajBrojTeperaturaVecihOd(int tmp) {
        return count_if(max.begin(), max.end(), [tmp](int x) { return (x>tmp);});
    }
    
    int Temperature::DajBrojTeperaturaManjihOd(int tmp) {
        return count_if(min.begin(), min.end(), [tmp](int x) { return (x<tmp);});
    }
    
int main ()
{
    std::cout <<"Kompajlira se";
	return 0;
}