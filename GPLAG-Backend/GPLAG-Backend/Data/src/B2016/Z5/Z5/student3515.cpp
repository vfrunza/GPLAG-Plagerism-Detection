/B16/17 (Zadaća 5, Zadatak 5)
//Autotestovi by Berina Cocalic (mail: bcocalic1@etf.unsa.ba)
//Za autotestove se obracati *iskljucivo* osobi koja ih pise
#include <iostream>
#include <list>
#include <utility>
#include <stdexcept>
#include <functional>
#include <algorithm>
using namespace std;
class Temperature {
    list<int> maxl;
    list<int> minl;
    public: 
    Temperature(int mint, int maxt);
    void RegistrirajTemperature(pair<int,int> par);
    void BrisiSve();
    void BrisiNegativneTemperature();
    int DajBrojRegistriranihTemperatura() const;
    int DajMinimalnuTemperaturu() const;
    int DajMaksimmalnuTemperaturu() const;
    int DajBrojTemperaturaVecihOd(pair<int, int> par) const;
    int DajBrojTemperaturaManjihOd(pair<int, int> par) const;
    
};
Temperature::Temperature(int mint, int maxt) {
    if(mint>maxt) throw range_error("Nekorektne temperature");
    fill_n(minl.begin(),1,mint);
    fill_n(maxl.begin(),1,maxt);
}
void Temperature::RegistrirajTemperature(pair<int,int> par) {
    if(par.first>par.second) throw range_error("Nekorektne temperature");
    maxl.push_back(par.second);
    minl.push_back(par.first);
}
void Temperature::BrisiSve() {
    int n(99999);
    auto p1=remove_if(maxl.begin(),maxl.end(),bind(less<int>(), placeholders::_1, n));
    auto p2=remove_if(minl.begin(),minl.end(),bind(less<int>(), placeholders::_1, n));
}
 
void Temperature::BrisiNegativneTemperature() {
    int n(0);
    auto p1=remove_if(maxl.begin(),maxl.end(),bind(less<int>(), placeholders::_1,n));
    auto p2=remove_if(minl.begin(),minl.end(),bind(less<int>(), placeholders::_1,n));
}
int Temperature::DajBrojRegistriranihTemperatura() const {
    int n(99999);
    int a=count_if(maxl.begin(),maxl.end(),bind(less<int>(),placeholders::_1,n));
    //int b=count_if(minl.begin(),minl.end(),bind(less<int>(),placeholders::_1,n));
    return a;
}
int Temperature::DajMinimalnuTemperaturu() const {
    auto p=min_element(minl.begin(),minl.end());
    return *p;
}
int Temperature::DajMaksimmalnuTemperaturu() const {
    auto p=max_element(maxl.begin(),maxl.end());
    return *p;
}
int Temperature::DajBrojTemperaturaVecihOd(pair<int, int> par) const {
    int n1=par.first;//min
    int n2=par.second;//max
    return n1;
}
int main ()
{
	return 0;
}