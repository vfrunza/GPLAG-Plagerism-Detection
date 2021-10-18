/B16/17 (Zadaća 5, Zadatak 5)
//Autotestovi by Berina Cocalic (mail: bcocalic1@etf.unsa.ba)
//Za autotestove se obracati *iskljucivo* osobi koja ih pise
#include <iostream>
#include <list>
#include <stdexcept>
#include <vector>
#include <functional>
#include <algorithm>
class Temperature{
    std::list<int> minimalne;
    std::list<int> maksimalne;
    int min;
    int max;
    public:
    Temperature(int min,int max):min(min),max(max){
        if(min>max) throw std::range_error("Nekorektne temperature");
    }
    void RegistrirajTemperature(std::pair<int,int> temp);
    void BrisiSve();
    void BrisiTemperature(std::pair<int,int> temp);
    int DajBrojRegistriranihTemperatura() const { return minimalne.size();}
    int DajMinimalnuTemperaturu() const ;
    int DajMaksimalnuTemperaturu() const;
    int DajBrojTemperaturaVecihOd(int temp) const;
     int DajBrojTemperaturaManjihOd(int temp) const;
    bool operator !(){ return maksimalne.size()==0;}
    friend Temperature &operator ++(Temperature &temp);
    friend Temperature &operator --(Temperature &temp);
    friend Temperature operator ++(Temperature &temp,int);
    friend Temperature operator --(Temperature &temp,int);
    std::pair<int,int> operator [](int n);
    friend std::vector<int> operator *(const Temperature &t);
    void BrisiNegativneTemperature();
    friend Temperature operator-(const Temperature &temp,int n);
    friend Temperature operator+(const Temperature &temp,int n);
    friend Temperature operator-(int n,const Temperature &temp);
    Temperature &operator-=(int n);
    Temperature &operator+=(int n);
    friend bool operator ==(const Temperature &t1,const Temperature &t2);
    friend bool operator !=(const Temperature &t1,const Temperature &t2);

};
std::pair<int,int> Temperature::operator [](int n){
    if(n>minimalne.size()||n<1) throw std::range_error("Neispravan indeks");
    auto it1(minimalne.begin()); auto it2(maksimalne.begin());
    std::advance(it1,n-1); std::advance(it2,n-1);
    return std::make_pair(*it1,*it2);
}
Temperature operator ++(Temperature &temp,int){
    auto pomocna(temp);
    ++temp; return pomocna;
}
Temperature operator --(Temperature &temp,int){
    auto pomocna(temp);
    --temp; return pomocna;
}
Temperature &operator ++(Temperature &temp){
    auto tmp(temp);
    std::transform(temp.minimalne.begin(),temp.minimalne.end(),temp.minimalne.begin(),std::bind(std::plus<int>(),std::placeholders::_1,1));
    std::vector<int> v(*temp);
    auto it(std::find_if(v.begin(),v.end(),std::bind(std::less<int>(),std::placeholders::_1,0)));
    if(it!=v.end()){
        temp=tmp;
        throw std::logic_error("Ilegalna operacija");
    }
    return temp;
}
Temperature &operator --(Temperature &temp){
    auto tmp(temp);
    std::transform(temp.maksimalne.begin(),temp.maksimalne.end(),temp.maksimalne.begin(),std::bind(std::plus<int>(),std::placeholders::_1,-1));
    auto v(*temp);
    auto it(std::find_if(v.begin(),v.end(),std::bind(std::less<int>(),std::placeholders::_1,0)));
    if(it!=v.end()){
        temp=tmp;
        throw std::logic_error("Ilegalna operacija");
    }
    return temp;
}
int Temperature::DajBrojTemperaturaVecihOd(int temp) const{
    if(maksimalne.size()==0) throw std::logic_error("Nema registriranih temperatura");
    return std::count_if(maksimalne.begin(),maksimalne.end(),std::bind(std::greater<int>(),std::placeholders::_1,temp));
}
int Temperature::DajBrojTemperaturaManjihOd(int temp) const{
    if(minimalne.size()==0) throw std::logic_error("Nema registriranih temperatura");
    return std::count_if(minimalne.begin(),minimalne.end(),std::bind(std::less<int>(),std::placeholders::_1,temp));
}
int Temperature::DajMinimalnuTemperaturu() const{
    auto it(std::min_element(minimalne.begin(),minimalne.end()));
    if(it==minimalne.end()) throw std::logic_error("Nema registriranih temperatura");
    return *it;
}
int Temperature::DajMaksimalnuTemperaturu() const{
    auto it(std::max_element(maksimalne.begin(),maksimalne.end()));
    if(it==maksimalne.end()) throw std::logic_error("Nema registriranih temperatura");
    return *it;
}
void Temperature::RegistrirajTemperature(std::pair<int,int> temp){
    if(temp.first<min||temp.second>max||temp.first>temp.second) throw std::range_error("Nekorektne temperature");
    minimalne.emplace_back(temp.first); maksimalne.emplace_back(temp.second);
}
void Temperature::BrisiSve(){
    minimalne.clear(); maksimalne.clear();
}
std::vector<int> operator *(const Temperature &t){
    std::vector<int> v(t.minimalne.size());
    std::transform(t.maksimalne.begin(),t.maksimalne.end(),t.minimalne.begin(),v.begin(),std::minus<int>());
    return v;
}
void Temperature::BrisiNegativneTemperature(){
    static int a=0;
    auto it1=minimalne.begin(); auto it2=maksimalne.begin();
    std::advance(it1,a); std::advance(it2,a);
    if(a!=minimalne.size()){
        if(*it1<0&&*it2<0){
            minimalne.erase(it1); maksimalne.erase(it2);
            BrisiNegativneTemperature();
        }
        else {a++; BrisiNegativneTemperature();}
    }
}
Temperature operator-(const Temperature &temp,int n){
    auto tmp(temp);
    std::transform(tmp.maksimalne.begin(),tmp.maksimalne.end(),
    tmp.maksimalne.begin(),std::bind(std::minus<int>(),std::placeholders::_1,n));
    std::transform(tmp.minimalne.begin(),tmp.minimalne.end(),tmp.minimalne.begin(),
    std::bind(std::minus<int>(),std::placeholders::_1,n));
    if(tmp.DajBrojTemperaturaManjihOd(tmp.min)!=0) throw std::logic_error("Prekoracen dozvoljeni opseg temperatura");
    return tmp;
}
Temperature operator+(const Temperature &temp,int n){
    auto tmp(temp);
    std::transform(tmp.maksimalne.begin(),tmp.maksimalne.end(),
    tmp.maksimalne.begin(),std::bind(std::plus<int>(),std::placeholders::_1,n));
    std::transform(tmp.minimalne.begin(),tmp.minimalne.end(),tmp.minimalne.begin(),
    std::bind(std::plus<int>(),std::placeholders::_1,n));
    if(tmp.DajBrojTemperaturaVecihOd(tmp.max)!=0) throw std::logic_error("Prekoracen dozvoljeni opseg temperatura");
    return tmp;
}
Temperature operator+(int n,const Temperature &temp){
    return temp+n;
}
Temperature operator-(int n,const Temperature &temp){
    auto tmp(temp);
    std::transform(temp.maksimalne.begin(),temp.maksimalne.end(),tmp.minimalne.begin(),std::bind(std::minus<int>(),n,
    std::placeholders::_1));
    std::transform(temp.minimalne.begin(),temp.minimalne.end(),tmp.maksimalne.end(),std::bind(std::minus<int>(),n,
    std::placeholders::_1));
    if(tmp.DajBrojTemperaturaVecihOd(tmp.max)!=0||tmp.DajBrojTemperaturaManjihOd(tmp.min)!=0)
    throw std::logic_error("Prekoracen dozvoljeni opseg temperatura");
    return tmp;
}
Temperature& Temperature::operator-=(int n){
    *this=*this-n;
    return *this;
}
Temperature& Temperature:: operator+=(int n){
    *this=*this+n;
    return *this;
}
bool operator ==(const Temperature &t1,const Temperature &t2){
    return (t1.minimalne==t2.minimalne&&t1.maksimalne==t2.maksimalne&&t1.min==t2.min&&t1.max==t2.max);
}
bool operator !=(const Temperature &t1,const Temperature &t2){
    return !(t1.minimalne==t2.minimalne&&t1.maksimalne==t2.maksimalne&&t1.min==t2.min&&t1.max==t2.max);
}
int main ()
{
    Temperature t(-15,10);
    t.RegistrirajTemperature(std::make_pair(5,6));
    std::cout<<t.DajBrojTemperaturaManjihOd(10);
    t.RegistrirajTemperature(std::make_pair(-10,-2));
    std::cout<<std::endl<<t.DajBrojRegistriranihTemperatura();
    t.BrisiNegativneTemperature();
      
      std::cout<<std::endl<<t.DajMinimalnuTemperaturu();
      t++;
    
      std::cout<<std::endl<<t[1].first;
      auto t1(t+3);
     std::cout<<t1.DajMaksimalnuTemperaturu();
	return 0;
}