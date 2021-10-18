//Autotestovi by Berina Cocalic (mail: bcocalic1@etf.unsa.ba)
#include <iostream>
#include <list>
#include <utility>
#include <stdexcept>
#include <algorithm>
#include <functional>

class Temperature{
    std::list<int> mini,maxi;  
    int prag_min,prag_max;
    public:
    Temperature(int min,int max);
    void RegistrirajTemperaturu(std::pair<int,int> par);
    void BrisiSve(){mini.clear(); maxi.clear(); }
    void BrisiNegativneTemperature();
    int DajBrojRegistriranihTemperatura(){ return mini.size(); }
    int DajMinimalnuTemperaturu();
    int DajMaksimalnuTemperaturu();
    int DajBrojTemperaturaVecihOd(int x);
    int DajBrojTemperaturaManjihOd(int x);
    bool operator!()const{return mini.empty();}
    void operator++();
    
};
Temperature::Temperature(int min,int max){
    if(min > max) throw std::range_error ("Nekorektne temperature");
    prag_min=min; prag_max=max;
}
void Temperature::RegistrirajTemperaturu(std::pair<int,int> par){
    if(par.first>prag_max || par.second>prag_max || par.first<prag_min || par.second<prag_min || par.first>par.second) throw std::range_error ("Nekorektne temperature");
    mini.push_back(par.first); maxi.push_back(par.second);
 //   std::cout<<mini.size();
}
void Temperature::BrisiNegativneTemperature(){
    int brojac(1);
    for(auto it(mini.begin()); it!=mini.end(); it++){
        if(*it<0){
            auto it1(maxi.begin());
            for(int i=0; i<brojac; i++){
                it1++;
            }
            if(*it1<0){
                mini.erase(it);
                maxi.erase(it1);
            }
        }
        brojac++;
    }
}
int Temperature::DajMinimalnuTemperaturu(){
    if(mini.empty()) throw std::logic_error("Nema registriranih temperatura");
    //std::cout<<mini.size();
    //for(auto it(mini.begin()); it!=mini.end();it++) std::cout<<*it<<"kungala";
    return *std::min_element(mini.begin(),mini.end());
}
int Temperature::DajMaksimalnuTemperaturu(){
    if(maxi.empty()) throw std::logic_error("Nema registriranih temperatura");
    return *std::max_element(maxi.begin(),maxi.end());
}
int Temperature::DajBrojTemperaturaVecihOd(int x){
    if(mini.empty() || maxi.empty()) throw std::logic_error("Nema registriranih temperatura");
    return std::count_if(mini.begin(),mini.end(),std::bind(std::greater<int>(),std::placeholders::_1,x)) + std::count_if(maxi.begin(),maxi.end(),std::bind(std::greater<int>(),std::placeholders::_1,x));
}
int Temperature::DajBrojTemperaturaManjihOd(int x){
    if(mini.empty() || maxi.empty()) throw std::logic_error("Nema registriranih temperatura");
    return std::count_if(mini.begin(),mini.end(),std::bind(std::less<int>(),std::placeholders::_1,x)) + std::count_if(maxi.begin(),maxi.end(),std::bind(std::less<int>(),std::placeholders::_1,x));
}
void Temperature::operator++(){
    if(mini.end()==std::find_if(mini.begin(),mini.end(),std::bind(std::greater<double>(),std::placeholders::_1,prag_max-1))) throw std::logic_error("Ilegalna operacija");
    else std::for_each(mini.begin(),mini.end(),std::bind(std::plus<int>(),std::placeholders::_1,1));
}

int main ()
{
	return 0;
}