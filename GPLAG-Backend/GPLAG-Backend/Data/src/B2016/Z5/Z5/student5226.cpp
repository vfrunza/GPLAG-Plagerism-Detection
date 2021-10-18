/B16/17 (Zadaća 5, Zadatak 5)
//Autotestovi by Berina Cocalic (mail: bcocalic1@etf.unsa.ba)
//Za autotestove se obracati *iskljucivo* osobi koja ih pise
#include <iostream>
#include <stdexcept>
#include <list>
#include <algorithm>
#include <utility>
#include <functional>
class Temperature {
  std::list<int> minimalne;
  std::list<int> maksimalne;
  
  public: 
  Temperature(int minimalna, int maksimalna){
      if(minimalna>maksimalna) throw std::range_error("Nekorektne temperature");
      minimalne.push_back(minimalna);
      maksimalne.push_back(maksimalna);
  }
  
  void RegistrirajTemperature(std::pair<int,int> temperature){
      if(temperature.first>temperature.second) throw std::range_error("Nekorektne temperature");
      minimalne.push_back(temperature.first);
      maksimalne.push_back(temperature.second);
  }
  
  void BrisiSve() {
      for(auto it=minimalne.begin();it!=minimalne.end();it++)
      it=std::erase(it);
  }
  
  int DajBrojRegistriranihTemeperatura() const { return minimalne.size(); }
  int DajMinimalnuTemeperaturu() const {
      int min=9999;
      min=std::min_element(minimalne.begin(),minimalne.end(),std::bind1st(std::greater<int>(),min));
      return min;
  }
  
  int DajMaksimalnuTemperaturu() const {
      int maks=-9999;
      maks=std::max_element(maksimalne.begin(),maksimalne.end(),std::bind1st(std::greater<int>(),maks));
      return maks;
   }
   
   int DajBrojVecihOd(int zadana) const {
     int n=std::count_if(maksimalne.begin(),maksimalne.end(),std::bind1st(std::greater<int>(),zadana));
     return n;
   }
   int DajBrojManjihOd(int zadana) const {
       int n=std::count_if(minimalne.begin(),minimalne.end(),std::bind1st(std::less<int>(),zadana));
       return n;
   }
};
int main ()
{
	return 0;
}