#include <iostream>
#include <list>
#include <utility>
#include <algorithm>
class Temperatura {
    std::list<int> min, max;
public:
    Temperatura(int min, int max);
    void RegistrirajTemperature(std::pair<int, int> parovi);
    void BrisiSve();
    int DajMinimalnuTemperaturu() const { 
        auto it(std::min(min)); 
        if(it == min.end()) throw std::logic_error("Nema registriranih temperatura");
        return *it;
    }
    int DajMaksimalnuTemperaturu() const { 
        if(it == max.end()) throw std::logic_error("Nema registriranih temperatura");
        return *std::max(max); 
    }
};
Temperatura::Temperatura(int min1, int max1) {
    if(min > max) throw std::range_error("Nekorektne temperature");
    min.insert(min1); max.insert(max1);
void Temperatura::RegistrirajTemperature(std::pair<int, int> parovi) {
    if(parovi->first > parovi->second) throw std::range_error("Nekorektne temperature");
    for(int x : min)
        if(parovi->first < x) throw std::range_error("Nekorektne temperature");
    for(int x : max)
        if(parovi->second > x) throw std::range_error("Nekorektne temperature");
    min.insert(parovi->first); max.insert(parovi->second);
}
void Temperatura::BrisiSve() {
    min.resize(0); max.resize(0);
}
}
int main ()
{
	return 0;
}