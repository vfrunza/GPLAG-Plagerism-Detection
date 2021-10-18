/B16/17 (Zadaća 5, Zadatak 5)
//Autotestovi by Berina Cocalic (mail: bcocalic1@etf.unsa.ba)
//Za autotestove se obracati *iskljucivo* osobi koja ih pise
#include <iostream>
#include <list>
#include <utility>
#include <algorithm>
#include <functional>
#include <vector>
#include <stdexcept>
#include <iterator>    
class Temperature{
    std::list<int> maks_temperature,min_temperature;
    int max_dozvoljena,min_dozvoljena;
  public:
    Temperature(int min,int max);
    void RegistrirajTemperature(std::pair<int,int> dnevna);
    void BrisiSve();
    void BrisiNegativneTemperature();
    int DajBrojRegistriranihTemperatura()const{return min_temperature.size();}
    int DajMinimalnuTemperaturu()const;
    int DajMaksimalnuTemperaturu()const;
    int DajBrojTemperaturaVecihOd(int temp)const;
    int DajBrojTemperaturaManjihOd(int temp)const;
    friend bool operator!(const Temperature&t);
    friend Temperature&operator++(Temperature&t);
    friend Temperature operator++(Temperature&t,int);
    friend Temperature&operator--(Temperature&t);
    friend Temperature operator--(Temperature&t,int);
    friend std::vector<int> operator*(const Temperature&t);
    friend std::vector<int> operator+(const Temperature&t);
    friend std::vector<int> operator-(const Temperature&t);
    std::pair<int,int> operator[](int indeks);
    friend Temperature operator+(const Temperature&t,int inkrement);
    friend Temperature operator+(int inkrement,const Temperature&t);
    friend Temperature&operator+=(Temperature&t,int inkrement);
    friend Temperature operator-(const Temperature&t,int inkrement);
    friend Temperature operator-(int inkrement,const Temperature&t);
    friend Temperature&operator-=(Temperature&t,int inkrement);
    friend bool operator==(const Temperature&t1,const Temperature&t2);
    friend bool operator!=(const Temperature&t1,const Temperature&t2);
    friend std::ostream&operator<<(std::ostream&tok,const Temperature&t);
};
Temperature::Temperature(int min,int max){
  if(min>max)throw std::range_error("Nekorektne temperature");
  max_dozvoljena=max;
  min_dozvoljena=min;
}
void Temperature::RegistrirajTemperature(std::pair<int,int> dnevna){
  if(dnevna.first<min_dozvoljena || dnevna.second>max_dozvoljena || dnevna.first>dnevna.second)throw std::range_error("Nekorektne temperature");
  min_temperature.push_back(dnevna.first);
  maks_temperature.push_back(dnevna.second);
}
void Temperature::BrisiSve(){
  min_temperature.clear();
  maks_temperature.clear();
}
void Temperature::BrisiNegativneTemperature(){
  
}// nedovrseno
int Temperature::DajMinimalnuTemperaturu()const{
  if(min_temperature.size()==0)throw std::logic_error("Nema registriranih temperatura");
  return *std::min_element(min_temperature.begin(),min_temperature.end());
}
int Temperature::DajMaksimalnuTemperaturu()const{
  if(min_temperature.size()==0)throw std::logic_error("Nema registriranih temperatura");
  return *std::max_element(maks_temperature.begin(),maks_temperature.end());
}
int Temperature::DajBrojTemperaturaVecihOd(int temp)const{
  if(min_temperature.size()==0)throw std::logic_error("Nema registriranih temperatura");
  return std::count_if(maks_temperature.begin(),maks_temperature.end(),std::bind(std::greater<int>(),std::placeholders::_1,temp));
}
int Temperature::DajBrojTemperaturaManjihOd(int temp)const{
  if(min_temperature.size()==0)throw std::logic_error("Nema registriranih temperatura");
  return std::count_if(min_temperature.begin(),min_temperature.end(),std::bind(std::less<int>(),std::placeholders::_1,temp));
}
bool operator!(const Temperature&t){
  if(t.min_temperature.size()==0)return true;
  return false;
}
Temperature&operator++(Temperature&t){
  auto test(*t);
  if(std::count(test.begin(),test.end(),0)) throw std::logic_error("Ilegalna operacija");
  std::transform(t.min_temperature.begin(),t.min_temperature.end(),t.min_temperature.begin(),std::bind(std::plus<int>(),std::placeholders::_1,1));
  return t;
}//bacanje izuzetka
Temperature operator++(Temperature&t,int){
  auto pomocni(t);
  ++t;
  return pomocni;
}
Temperature&operator--(Temperature&t){
  auto test(*t);
  if(std::count(test.begin(),test.end(),0))throw std::logic_error("Ilegalna operacija");
  std::transform(t.maks_temperature.begin(),t.maks_temperature.end(),t.maks_temperature.begin(),std::bind(std::minus<int>(),std::placeholders::_1,1));
  return t;
}
Temperature operator--(Temperature&t,int){
  auto pomocni(t);
  --t;
  return pomocni;
}
std::vector<int> operator*(const Temperature&t){
  std::vector<int> povratni(t.min_temperature.size());
  std::transform(t.maks_temperature.begin(),t.maks_temperature.end(),t.min_temperature.begin(),povratni.begin(),std::minus<int>());
  return povratni;
}
std::vector<int> operator+(const Temperature&t){
  std::vector<int> povratni(t.min_temperature.size());
  std::transform(t.maks_temperature.begin(),t.maks_temperature.end(),povratni.begin(),std::bind(std::minus<int>(),t.max_dozvoljena,std::placeholders::_1));
  return povratni;
}
std::vector<int> operator-(const Temperature&t){
  std::vector<int> povratni(t.min_temperature.size());
  std::transform(t.min_temperature.begin(),t.min_temperature.end(),povratni.begin(),std::bind(std::minus<int>(),std::placeholders::_1,t.min_dozvoljena));
  return povratni;
}
std::pair<int,int> Temperature::operator[](int indeks){
  if(indeks<1 || indeks>min_temperature.size())throw std::range_error("Neispravan indeks");
  auto it1(min_temperature.begin());
  auto it2(maks_temperature.begin());
  std::advance(it1,indeks-1);
  std::advance(it2,indeks-1);
  return{*it1,*it2};
}
Temperature operator+(const Temperature&t,int inkrement){
  auto test(+t);
  if(std::count_if(test.begin(),test.end(),std::bind(std::greater<int>(),inkrement,std::placeholders::_1))) throw std::logic_error("Ilegalna operacija");
  Temperature x(t);
  std::transform(x.min_temperature.begin(),x.min_temperature.end(),x.min_temperature.begin(),std::bind(std::plus<int>(),std::placeholders::_1,inkrement));
  return x;
}
Temperature operator+(int inkrement,const Temperature&t){
  return t+inkrement;
}
Temperature&operator+=(Temperature&t,int inkrement){
  return t=t+inkrement;
}
Temperature operator-(const Temperature&t,int inkrement){
  auto test(-t);
  if(std::count_if(test.begin(),test.end(),std::bind(std::greater<int>(),inkrement,std::placeholders::_1))) throw std::logic_error("Ilegalna operacija");
  Temperature x(t);
  std::transform(x.maks_temperature.begin(),x.maks_temperature.end(),x.maks_temperature.begin(),std::bind(std::minus<int>(),std::placeholders::_1,inkrement));
  return x;
}
Temperature operator-(int inkrement,const Temperature&t){
}//???
Temperature&operator-=(Temperature&t,int inkrement){
  return t=t-inkrement;
}
bool operator==(const Temperature&t1,const Temperature&t2){
  if(t1.max_dozvoljena!=t2.max_dozvoljena || t1.min_dozvoljena!=t2.min_dozvoljena || t1.min_temperature.size()!=t2.min_temperature.size())return false;
  if(t1.maks_temperature!=t2.maks_temperature || t1.min_temperature!= t2.min_temperature)return false;
  return true;
}
bool operator!=(const Temperature&t1,const Temperature&t2){
  return !(t1==t2);
}
std::ostream&operator<<(std::ostream&tok,const Temperature&t){
  std::copy(t.min_temperature.begin(),t.min_temperature.end(),std::ostream_iterator<int>(tok," "));
  tok<<"\n";
  std::copy(t.maks_temperature.begin(),t.maks_temperature.end(),std::ostream_iterator<int>(tok," "));
  return tok;
}
int main (){
  try{
  Temperature t(0,30);
  t.RegistrirajTemperature({1,15});
  t.RegistrirajTemperature({2,20});
  t+3;
  std::cout<<t;
  auto x(-t);
  //for(int i=0;i<x.size();i++)std::cout<<x[i]<<" ";
  }catch(std::logic_error a){ std::cout<<a.what();}
	return 0;
}