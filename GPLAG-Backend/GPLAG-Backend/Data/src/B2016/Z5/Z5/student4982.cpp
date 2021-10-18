/B16/17 (Zadaća 5, Zadatak 5)
//Autotestovi by Berina Cocalic (mail: bcocalic1@etf.unsa.ba)
//Za autotestove se obracati *iskljucivo* osobi koja ih pise
#include <iostream>
#include <list>
#include <stdexcept>
#include <algorithm>
#include <functional>

class Temperature
{
    std::list<int> minimalne, maksimalne;
    int min,max;
    public:
    Temperature(int max, int min) { if(min>max) throw std::range_error("Nekorektne temperature"); Temperature::min=min; Temperature::max=max; }
    void RegistrirajTemperature(std::pair<int,int> temp);
    void BrisiSve();
    void BrisiNegativneTemperature();
    int DajBrojRegistriranihTemperatura() const;
    int DajMinimalnuTemperaturu() const;
    int DajMaksimalnuTemperaturu() const;
    int DajBrojTemperaturaVecihOd(int br) const;
    int DajBrojTemperaturaManjihOd(int br) const;
};
int main ()
{
	return 0;
}