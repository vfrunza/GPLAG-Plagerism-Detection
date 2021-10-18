#include <iostream>
#include <list>
#include <algorithm>
#include <stdexcept>
#include <utility>
#include <functional>
#include <vector>
#include <iterator>
class Manji {
    const int n;  
    public:
        Manji(int n) : n(n) {}
        bool operator ()(int x) { return x < n; }
};
class Veci{
    const int n;
    public:
        Veci(int n) : n(n) {}
        bool operator ()(int x) { return x > n; }  
};
class Temperature{
    static int max_d;
    static int min_d;
    std::list<int> mini;
    std::list<int> maxi;
    public:
        Temperature(int a,int b);
        void RegistrirajTemperature(std::pair<int,int> p);
        void BrisiSve(){mini.resize(0);maxi.resize(0);}
        void BrisiNegativneTemperature();
        int  DajBrojRegistriranihTemperatura()const {return mini.size();}
        int DajMinimalnuTemperaturu() const;
        int DajMaksimalnuTemperaturu() const;
        int DajBrojTemperaturaVecihOd(int n) const;
        int DajBrojTemperaturaManjihOd(int n) const;
        friend bool operator!(const Temperature &t);
        friend std::vector<int> operator*(const Temperature &t);
        std::pair<int,int> operator[](int i);
        friend bool operator==(const Temperature &t1,const Temperature &t2);
        inline friend bool operator!=(const Temperature &t1,const Temperature &t2){return !(t1==t2);}
};
int Temperature::min_d=0;
int Temperature::max_d=0;
Temperature::Temperature(int a,int b){
    if(a>b)throw std::range_error("Nekorektne temperature");
    min_d=a;
    max_d=b;
}
void Temperature::RegistrirajTemperature(std::pair<int,int> p){
    if(p.first<min_d || p.second>max_d ||p.first>p.second)throw std::range_error("Nekorektne temperature");
    mini.push_back(p.first);
    maxi.push_back(p.second);
}
void Temperature::BrisiNegativneTemperature(){
    std::remove_if(mini.begin(),mini.end(),Manji(0));
}
int Temperature::DajMinimalnuTemperaturu() const{
    if(maxi.size()<=0 || mini.size()<=0)throw std::logic_error("Nema registriranih temperatura");
    return *(min_element(mini.begin(),mini.end()));
}
int  Temperature::DajMaksimalnuTemperaturu() const{
    if(maxi.size()<=0 || mini.size()<=0)throw std::logic_error("Nema registriranih temperatura");
    return *(max_element(maxi.begin(),maxi.end()));
}
int Temperature::DajBrojTemperaturaVecihOd(int n) const{
    if(maxi.size()<=0 || mini.size()<=0)throw std::logic_error("Nema registriranih temperatura");
    int broj=count_if(mini.begin(),mini.end(),Veci(n));
    broj+=count_if(maxi.begin(),maxi.end(),Veci(n));
    return broj;
}
int Temperature::DajBrojTemperaturaManjihOd(int n) const{
    if(maxi.size()<=0 || mini.size()<=0)throw std::logic_error("Nema registriranih temperatura");
    int broj=count_if(mini.begin(),mini.end(),Manji(n));
    broj+=count_if(maxi.begin(),maxi.end(),Manji(n));
    return broj;
}
bool operator!(const Temperature &t){
    return (t.maxi.size()==0 || t.mini.size()==0);
}
std::vector<int> operator*(const Temperature &t){
    std::vector<int> vrati(t.maxi.size());
    std::transform(t.maxi.begin(),t.maxi.end(),t.mini.begin(),vrati.begin(),std::minus<int>{});
    return vrati;
}
std::pair<int,int> Temperature::operator[](int i){
    if(i<0 || i>maxi.size() || mini.size())throw std::range_error("Neispravan indeks");
    auto it1=maxi.begin();
    auto it2=mini.begin();
    std::advance(it1,i-1);
    std::advance(it2,i-1);
    return std::make_pair(*it1,*it2);
}
bool operator==(const Temperature &t1,const Temperature &t2){
    return (t1.maxi.size()==t2.maxi.size() && t1.mini.size()==t2.mini.size() && std::equal(t1.maxi.begin(),t1.maxi.end(),t2.maxi.begin()) && std::equal(t1.mini.begin(),t1.mini.end(),t2.mini.begin()));
}
int main (){
    Temperature s(-20,20);
    s.RegistrirajTemperature(std::make_pair(-12,13));
    s.RegistrirajTemperature(std::make_pair(-6,7));
    std::cout<<s.DajBrojTemperaturaManjihOd(20);
	return 0;
}