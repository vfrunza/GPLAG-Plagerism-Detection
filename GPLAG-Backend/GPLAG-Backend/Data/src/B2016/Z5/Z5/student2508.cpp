/B16/17 (Zadaća 5, Zadatak 5)
//Autotestovi by Berina Cocalic (mail: bcocalic1@etf.unsa.ba)
//Za autotestove se obracati *iskljucivo* osobi koja ih pise
#include <iostream>
#include <algorithm>
#include <list>
#include <utility>
#include <stdexcept>

class Temperature
{
    std::list<int> dmin,dmax;
    int minimalna,maksimalna;
public:

    Temperature(int min,int max){
        if(min>max) throw std::range_error("Nekorektne temperature");
        minimalna=min; maksimalna=max;
    };
    
    void RegistrirajTemperature(std::pair<int,int> temp);
    void BrisiSve();
    void BrisiNegativneTemperature();
//    {
//        std::remove_if(dmin.begin(),dmin.end(),std::bind(std::less(),std::placeholders::_1,0));
//    }
};

void Temperature::RegistrirajTemperature(std::pair<int,int> temp)
{
    if(temp.first<minimalna || temp.second>maksimalna || temp.first>temp.second)
        throw std::range_error("Nekorektne temperature");
    dmin.push_back(temp.first);
    dmax.push_back(temp.second);
}

void Temperature::BrisiNegativneTemperature()
{
    std::list<int> pom(dmin.size());
        for(int x: dmin) std::cout<<x<<" ";
        std::cout<<std::endl;
    std::transform(dmin.begin(),dmin.end(),dmax.begin(),pom.begin(),std::bind(std::logical_or<int>(),std::bind(std::greater<int>(),std::placeholders::_1,0),std::bind(std::greater<int>(),std::placeholders::_2,0)));
   std::transform(dmin.begin(),dmin.end(),dmin.begin(),std::bind(std::plus<int>(),123,std::placeholders::_1));
   std::transform(dmin.begin(),dmin.end(),pom.begin(),dmin.begin(),std::bind(std::multiplies<int>(),std::placeholders::_1,std::placeholders::_2));
   int vel=count_if(dmin.begin(),dmin.end(),std::bind(std::equal_to<int>(),std::placeholders::_1,0));
    std::remove_if(dmin.begin(),dmin.end(),std::bind(std::equal_to<int>(),std::placeholders::_1,0));
    dmin.resize(dmin.size()-vel);
  std::transform(dmin.begin(),dmin.end(),dmin.begin(),std::bind(std::minus<int>(),std::placeholders::_1,123));
    for(int x: pom) std::cout<<x<<" ";
    std::cout<<std::endl;
    for(int x: dmin) std::cout<<x<<" ";
}

void Temperature::BrisiSve()
{
    dmin.resize(0);
    dmax.resize(0);
}



int main ()
{
    Temperature temp(-10,10);
    temp.RegistrirajTemperature(std::pair<int,int>(0,4));
    temp.RegistrirajTemperature(std::pair<int,int>(-5,-3));
    temp.RegistrirajTemperature(std::pair<int,int>(-2,2));
   // temp.RegistrirajTemperature(2,5);
    temp.BrisiNegativneTemperature();
	return 0;
}