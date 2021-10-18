/B16/17 (Zadaća 5, Zadatak 5)
//Autotestovi by Berina Cocalic (mail: bcocalic1@etf.unsa.ba)
//Za autotestove se obracati *iskljucivo* osobi koja ih pise
#include <iostream>
#include <list>
#include <stdexcept>
using namespace std;
class Temperature{
  list<int>min;
  list<int>max;
  public:
  Temperature(int min, int max){ //konstruktor sa dva parametra
    if(min>max) throw range_error("Nekorektne temperature");
    Temperature::min.push_back(min);
    Temperature::max.push_back(max);
  }
  void RegistrirajTemperature(pair<int, int> p){
     if(p.first>p.second) throw range_error("Nekorektne temperature");
     auto it1=min.begin();
     auto it2=max.begin();
     if(p.first<*it1 || p.second>*it2) throw range_error("Nekorektne temperature");
     min.push_back(p.first);
     max.push_back(p.second);
  }
  void BrisiSve(){
      min.erase(min.begin(), min.end());
      max.erase(max.begin(), max.end());
  }
  void BrisiNegativneTemperature();
  
};
int main ()
{
	return 0;
}