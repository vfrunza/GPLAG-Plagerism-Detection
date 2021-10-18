#include <iostream>
#include <list>
#include <stdexcept>
class Temperature{
  std::list<int> maxovi;
  std::list<int> minovi;
  int maxi,mini;
  bool Provjera(int a,int b){
      return a>b;
  }
  public:
  Temperature(int tmini,int tmaxi){
      if(Provjera(mini,maxi))
      throw std::range_error("Nekorektne temperature");
      maxi=tmaxi; mini=tmini;
      }
      void RegistrirajTemperature(std::make_pair<int,int> x){
          if(Provjera(x.first,x.second) || Provjera(mini,x.first) || Provjera(x.second,maxi))
          throw std::range_error("Nekorektne temeperature");
          maxovi.push_back(x.second);
          minovi.push_back(x.first);
      }
      void BrisiSve(){
        for(auto i(maxovi.begin());i!=maxovi.end();i++)
        maxovi.erase(i);
        for(auto i(minovi.begin());i!=minovi.end();i++)
        minovi.erase(i);
      }
      void BrisiNegativneTemperature(){
        for(auto i(maxovi.begin());i!=maxovi.end();i++){
        if(i->first<0 && i->second)
        maxovi.erase(i);
        }
        for(auto i(minovi.begin());i!=minovi.end();i++){
       if(i->first<0 && i->second)
        minovi.erase(i);
      }
      }
      int DajBrojRegistriranihTemperatura() const {
        int br(0);
        for(auto i(maxovi.begin());i!=maxovi.end();i++)
        br++;
        return br;
      }
      
};