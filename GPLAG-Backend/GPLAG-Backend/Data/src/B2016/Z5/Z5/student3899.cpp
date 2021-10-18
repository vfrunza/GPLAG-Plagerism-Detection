/B16/17 (Zadaća 5, Zadatak 5)
//Autotestovi by Berina Cocalic (mail: bcocalic1@etf.unsa.ba)
//Za autotestove se obracati *iskljucivo* osobi koja ih pise
#include <iostream>
#include<list>
#include<utility>
#include<stdexcept>
#include<algorithm>
#include<functional>
class Temperatura{
    int min_dozvoljena;
    int max_dozvoljena;
    std::list<int> min;
    std::list<int> max;
    public:
    Temperatura(int min_temp,int max_temp);
    void RegistrirajTemperature(std::pair<int, int> par);
    void BrisiSve();
    void BrisiTemperature(std::pair<int, int> par);
    int DajBrojRegistriranihTemperatura() const{ return min.size();};
    int DajMinimalnuTemperaturu() const;
    int DajMaksimalnuTemperaturu() const;
    int DajBrojTemperaturaVecihOd(int temp) const;
    int DajBrojTemepraturaManjihOd(int temp) const;
    
    friend bool operator !(const Temperatura &temp);
    friend Temperatura operator ++(Temperatura &temp);
    friend Temperatura operator ++(Temperatura &temp,int);
    friend Temperatura operator --(Temperatura &temp);
    friend Temperatura operator --(Temperatura &temp,int);
    
    
};

bool operator !(const Temperatura &temp){
    int a(temp.min.size()),b(temp.max.size());
    if(a+b!=0) return false;
    else return true;
}

Temperatura::Temperatura(int min_temp,int max_temp){
    if(min_temp>max_temp) throw std::range_error("Nekorektne temperature");
    min_dozvoljena=min_temp;
    max_dozvoljena=max_temp;
}
void Temperatura::RegistrirajTemperature(std::pair<int,int> par){
    if(par.first<min_dozvoljena || par.second>max_dozvoljena || par.first>par.second)  throw std::range_error("Nekorektne temperature");
    
    min.push_back(par.first);
    max.push_back(par.second);
}
void Temperatura::BrisiSve(){
    int br(min.size());
    for(int i=0;i<br;i++){
        min.erase(min.begin());
        max.erase(max.begin());
    }
}
void Temperatura::BrisiTemperature(std::pair<int,int> par){
    auto it1(min.begin());
    auto it2(max.begin());
    bool provjera(false);
    while(it1!=min.end()){
        if(*it1==par.first && *it2==par.second){
            min.erase(it1);
            max.erase(it2);
            provjera=true;
        }
        else{
            it1++;
            it2++;
        }
  
    }
    if(!provjera) throw std::logic_error("Takve temperature nisu registrirane");
   
}
int Temperatura::DajMinimalnuTemperaturu() const{
    auto it(min_element(min.begin(),min.end()));
    if(it==min.end()) throw std::logic_error("Nema registriranih temperatura");
    return *it;
}
int Temperatura::DajMaksimalnuTemperaturu()const{
    auto it(max_element(max.begin(),max.end()));
    if(it==max.end()) throw std::logic_error("Nema registriranih temperatura");
    return *it;
}
int Temperatura::DajBrojTemepraturaManjihOd(int temp) const{
    auto a(count_if(min.begin(),min.end(),std::bind(std::less<int>(),std::placeholders::_1,temp)));
    auto b(count_if(max.begin(),max.end(),std::bind(std::less<int>(),std::placeholders::_1,temp)));
    return a+b;
    
}
int Temperatura::DajBrojTemperaturaVecihOd(int temp) const{
     auto a(count_if(min.begin(),min.end(),std::bind(std::greater<int>(),std::placeholders::_1,temp)));
    auto b(count_if(max.begin(),max.end(),std::bind(std::greater<int>(),std::placeholders::_1,temp)));
    return a+b;
}


int main ()
{
	return 0;
}