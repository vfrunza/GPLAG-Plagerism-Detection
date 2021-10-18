#include <iostream>
#include <list>
#include <utility>
#include <stdexcept>
class Temperature {
    std::list<int> temperature_max;
    std::list<int> temperature_min;
    public: 
    Temperature (int min, int max);
    void RegistrirajTemperature(std::pair<int, int> temp);
    void BrisiSve();
    void BrisiNegativneTemperature();
    int DajBrojRegistriranihTemperatura() const { return temperature_max.size(); };
    int DajMinimalnuTemperaturu() const;
    int DajMaksimalnuTemperaturu() const;
    int DajBrojTemperaturaVecihOd() const;
    int DajBrojTemperaturaManjihOd() const;
    
};

Temperature::Temperature(int min, int max) {
    if(min > max || min < -273.15 || max > 100) throw std::range_error ("Nekorektne temperature");
    temperature_max.push_back(max);
    temperature_min.push_back(min);
}
void Temperature::RegistrirajTemperature(std::pair<int, int> temp) {
    if(temp.first > temp.second || temp.first < -273.15 || temp.second > 100) throw std::range_error ("Nekorektne temperature");
    temperature_max.push_back(temp.second);
    temperature_min.push_back(temp.first);
}

int main () {
    
	return 0;
}