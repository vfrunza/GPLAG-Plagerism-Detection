/B16/17 (Zadaća 5, Zadatak 5)
//Autotestovi by Berina Cocalic (mail: bcocalic1@etf.unsa.ba)
//Za autotestove se obracati *iskljucivo* osobi koja ih pise
#include <iostream>
#include <list>
#include<stdexcept>
#include<algorithm>
#include<functional>
class Temperature {
    std::list<int> max_temp, min_temp;
    int maksimalna, minimalna;
    public:
    Temperature(int max, int min);
    void RegistrirajTemperature(std::pair<int,int>par);
    void BrisiSve();
    void BrisiNegativneTemperature();
    int DajBrojRegistriranihTemperatura();
    int DajMinimalnuTemperaturu();
    int DajMaksimalnuTemperaturu();
    int DajBrojTemperaturaManjihOd(int temperatura);
    int DajBrojTemperaturaVecihOd(int temperatura);
};
Temperature::Temperature(int max, int min) {
    if (min>max) throw std::range_error ("Nekorektne temperature");
    maksimalna=max;
    minimalna=min;
}
void Temperature::RegistrirajTemperature(std::pair<int,int>par) {
    if (par.first<minimalna || par.second<minimalna || par.first>maksimalna ||par.second>maksimalna || par.second>par.first)
        throw std::range_error ("Nekorektne temperature");
    max_temp.push_back(par.first);
    min_temp.push_back(par.second);
}
void Temperature::BrisiSve() {
    max_temp.clear();
    min_temp.clear();
}
/*void Temperature::BrisiNegativneTemperature() {
    auto it(max_temp.begin());
    while (it!=max_temp.end()) {
        if (*it<0) it=max_temp.erase(it);
        else it++;
    }
    it=min_temp.begin();
    while (it!=min_temp.end()) {
        if(*it<0) it=min_temp.erase(it);
        else it++;
    }
}*/
int Temperature::DajBrojRegistriranihTemperatura() {
    return max_temp.size();
}
int Temperature::DajMinimalnuTemperaturu() {
    if (max_temp.size()==0 && min_temp.size()==0) throw std::logic_error("Nema registriranih temperatura");
    
}
int Temperature::DajMaksimalnuTemperaturu() {
    if (max_temp.size()==0 && min_temp.size()==0) throw std::logic_error("Nema registriranih temperatura");
}
int Temperature::DajBrojTemperaturaVecihOd(int temperatura) {
    if (max_temp.size()==0 && min_temp.size()==0) throw std::logic_error("Nema registriranih temperatura");
}
int Temperature::DajBrojTemperaturaManjihOd(int temperatura) {
    if (max_temp.size()==0 && min_temp.size()==0) throw std::logic_error("Nema registriranih temperatura");
}

int main ()
{
	return 0;
}