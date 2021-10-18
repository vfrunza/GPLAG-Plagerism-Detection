#include <iostream>
#include <list>
#include <stdexcept>
#include <utility>
#include <functional>
#include <algorithm>
#include <vector>

class Temperature{
    std::list<int> maximum;
    std::list<int> minimum;
    int mini, maxi;
    public:
    Temperature(int min, int max);
    void RegistrirajTemperature(std::pair<int,int> minmax);
    void BrisiSve();
    void BrisiNegativneTemperature();
    int DajBrojRegistriranihTemperatura();
    int DajMinimalnuTemperaturu();
    int DajMaksimalnuTemperaturu();
    int DajBrojTemperaturaVecihOd(int temp);
    int DajBrojTemperaturaManjihOd(int temp);
    friend bool operator !(Temperature temp);
    friend Temperature &operator ++(Temperature &temp);
    friend Temperature &operator --(Temperature &temp);
    friend Temperature operator ++(Temperature temp, int);
    friend Temperature operator --(Temperature temp, int);
    friend std::vector<int> operator *(Temperature &temp);
    friend std::vector<int> operator -(Temperature &temp);
    friend std::vector<int> operator +(Temperature &temp);
    const std::pair<int,int> operator [](int indeks);
    friend Temperature operator +(Temperature &t, int br);
    friend Temperature operator +(int br, Temperature &t);
    friend Temperature operator -(Temperature &t, int br);
    friend Temperature operator -(int br, Temperature &t);
    friend Temperature operator +(Temperature &t, Temperature &t2);
    friend Temperature operator -(Temperature &t, Temperature &t2);
    Temperature &operator +=(Temperature &t);
    Temperature &operator -=(Temperature &t);
    friend bool operator ==(Temperature &t, Temperature &t1);
    friend bool operator !=(Temperature &t, Temperature &t1);
    friend std::ostream &operator <<(std::ostream &tok, Temperature &t);
};
int main ()
{
	return 0;
}
Temperature::Temperature(int min, int max){
    if(min > max)
        throw std::range_error("Nekorektne temperature");
    mini = min;
    maxi = max;
}
void Temperature::RegistrirajTemperature(std::pair<int,int> minmax){
    if(minmax.first > minmax.second)
        throw std::range_error("Nekorektne temperature");
    minimum.push_back(minmax.first);
    maximum.push_back(minmax.second);
}
void Temperature::BrisiSve(){
    std::list<int> temp(maximum.size());
    std::copy(maximum.begin(),maximum.end(),temp.begin());
    std::for_each(temp.begin(),temp.end(),std::bind(std::remove<std::list<int>::iterator,int>,maximum.begin(),maximum.end(),std::placeholders::_1));
    std::copy(minimum.begin(),minimum.end(),temp.begin());
    std::for_each(temp.begin(),temp.end(),std::bind(std::remove<std::list<int>::iterator,int>,minimum.begin(),minimum.end(),std::placeholders::_1));
}
void Temperature::BrisiNegativneTemperature(){
    
    std::remove_if(maximum.begin(),maximum.end(),std::bind(std::greater<int>(),0,std::placeholders::_1));
    
}
int Temperature::DajBrojRegistriranihTemperatura(){
    return std::count_if(maximum.begin(),maximum.end(),std::bind(std::greater<int>(),1,0));
}
int Temperature::DajMinimalnuTemperaturu(){
    return *(std::min_element(minimum.begin(),minimum.end()));
}
int Temperature::DajMaksimalnuTemperaturu(){
    return *(std::max_element(maximum.begin(),maximum.end()));
}
int Temperature::DajBrojTemperaturaVecihOd(int temp){
    return std::count_if(maximum.begin(),maximum.end(),std::bind(std::greater<int>(),std::placeholders::_1,temp)) + std::count_if(minimum.begin(),minimum.end(),std::bind(std::greater<int>(),std::placeholders::_1,temp));
}
int Temperature::DajBrojTemperaturaManjihOd(int temp){
     return std::count_if(maximum.begin(),maximum.end(),std::bind(std::greater<int>(),temp,std::placeholders::_1)) + std::count_if(minimum.begin(),minimum.end(),std::bind(std::greater<int>(),temp,std::placeholders::_1));
}
bool operator !(Temperature temp){
    std::equal_to<int> a;
    return a(temp.DajBrojRegistriranihTemperatura(),0);
}
Temperature &operator ++(Temperature &temp){
    std::list<int> temp2(temp.maximum.size());
    std::copy(temp.minimum.begin(),temp.minimum.end(),temp2.begin());
    std::transform(temp2.begin(),temp2.end(),temp2.begin(),std::bind(std::plus<int>(),1,std::placeholders::_1));
    int min(*(std::max_element(temp2.begin(),temp2.end())));
    if(std::count_if(temp.maximum.begin(),temp.maximum.end(),std::bind(std::greater<int>(),min,std::placeholders::_1)))
        throw std::logic_error("Ilegalna operacija");
    std::copy(temp2.begin(),temp2.end(),temp.minimum.begin());
    return temp;
}
Temperature &operator --(Temperature &temp2){
    std::list<int> temp(temp2.maximum.size());
    std::copy(temp2.maximum.begin(),temp2.maximum.end(),temp.begin());
    std::transform(temp.begin(),temp.end(),temp.begin(),std::bind(std::minus<int>(),1,std::placeholders::_1));
    int min(*(std::max_element(temp2.minimum.begin(),temp2.minimum.end())));
    if(std::count_if(temp.begin(),temp.end(),std::bind(std::greater<int>(),min,std::placeholders::_1)))
        throw std::logic_error("Ilegalna operacija");
    std::copy(temp.begin(),temp.end(),temp2.maximum.begin());
    return temp2;
}
Temperature operator ++(Temperature temp, int){
    return ++temp;
}
Temperature operator --(Temperature temp, int){
    return --temp;
}
std::vector<int> operator *(Temperature &temp){
    std::vector<int> razlika(temp.maximum.size());
    std::transform(temp.maximum.begin(),temp.maximum.end(),temp.minimum.begin(),razlika.begin(),std::less<int>());
}
std::vector<int> operator -(Temperature &temp){
    std::vector<int> razlika(temp.minimum.size());
    std::transform(temp.minimum.begin(),temp.minimum.end(),razlika.begin(),std::bind(std::less<int>(),std::placeholders::_1,temp.mini));
    return razlika;
}
std::vector<int> operator +(Temperature &temp){
    std::vector<int> razlika(temp.minimum.size());
    std::transform(temp.maximum.begin(),temp.maximum.end(),razlika.begin(),std::bind(std::less<int>(),std::placeholders::_1,temp.maxi));
    return razlika;
}
const std::pair<int,int> Temperature::operator [](int indeks){
    if(indeks < 1 || indeks> minimum.size())
        throw std::range_error("Neispravan indeks");

}
Temperature operator +(Temperature &t, int br);
Temperature operator +(int br, Temperature &t);
Temperature operator -(Temperature &t, int br);
Temperature operator -(int br, Temperature &t);
Temperature operator +(Temperature &t, Temperature &t2);
Temperature operator -(Temperature &t, Temperature &t2);
Temperature &Temperature::operator +=(Temperature &t){}
Temperature &Temperature::operator -=(Temperature &t){}
bool operator ==(Temperature &t, Temperature &t1);
bool operator !=(Temperature &t, Temperature &t1);
std::ostream &operator <<(std::ostream &tok, Temperature &t);