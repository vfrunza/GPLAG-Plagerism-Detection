#include <iostream>
#include <algorithm>
#include <functional>
#include <utility>
#include <list>
#include <stdexcept>
#include <iterator>
#include <vector>
class Temperatura{
    std::list<int> max_temperature;
    std::list<int> min_temperature;
    int max_temp,min_temp;
  public:
  Temperatura(int min_temp,int max_temp){
      if(min_temp>max_temp)throw std::range_error("Nekorektne temperature");
      Temperatura::min_temp=min_temp;
      Temperatura::max_temp=max_temp;
  }
  void RegistrirajTemperature(std::pair<int,int> temp);
  void BrisiSve(){max_temperature.resize(0);min_temperature.resize(0);}
  void BrisiTemperature(std::pair<int,int> temp);
  int DajBrojRegistriranihTemperatura() const{return max_temperature.size();}
  int DajMinimalnuTemperaturu() const;
  int DajMaksimalnuTemperaturu() const;
  int DajBrojTemperaturaVecihOd(int temp) const;
  int DajBrojTemperaturaManjihOd(int temp) const;
  bool operator !() const{return !max_temperature.size();}
  friend Temperatura &operator ++(Temperatura &t);
  inline Temperatura operator ++(int);
  friend Temperatura &operator --(Temperatura &t);
  inline Temperatura operator --(int);
  std::vector<int> operator *() const;
  std::vector<int> operator +() const;
  std::vector<int> operator -() const;
  std::pair<int,int> operator [](int i) const;
  friend std::ostream &operator <<(std::ostream &tok,const Temperatura &t);
  friend bool operator ==(const Temperatura &t1,const Temperatura &t2);
  inline friend bool operator !=(const Temperatura &t1,const Temperatura &t2);
  friend Temperatura operator +(const Temperatura &t1,int x);
  Temperatura &operator +=(int x);
  inline friend Temperatura operator +(int x,const Temperatura &t1);
  inline friend Temperatura operator -(const Temperatura &t1,int x);
  Temperatura operator -=(int x);
  inline friend Temperatura operator -(int x,const Temperatura &t1);
  
};
void Temperatura::RegistrirajTemperature(std::pair<int,int> temp){
    if(temp.first < min_temp || temp.second > max_temp || temp.first > temp.second)
        throw std::range_error("Nekorektne temperature");
    min_temperature.push_back(temp.first);
    max_temperature.push_back(temp.second);
}
int Temperatura::DajMinimalnuTemperaturu() const{
    auto it(std::min_element(min_temperature.begin(),min_temperature.end()));
    if(it == min_temperature.end())
        throw std::logic_error("Nema registriranih temperatura");
    return *it;
}
int Temperatura::DajMaksimalnuTemperaturu() const{
    auto it(std::max_element(max_temperature.begin(),max_temperature.end()));
    if(it == max_temperature.end())
        throw std::logic_error("Nema registriranih temperatura");
    return *it;
}
int Temperatura::DajBrojTemperaturaVecihOd(int temp) const{
    if(!max_temperature.size())
        throw std::logic_error("Nema registriranih temperatura");
    return std::count_if(max_temperature.begin(),max_temperature.end(),
    std::bind(std::greater<int>(),std::placeholders::_1,temp));
}
int Temperatura::DajBrojTemperaturaManjihOd(int temp) const{
    if(!min_temperature.size())
        throw std::logic_error("Nema registriranih temperatura");
    return std::count_if(min_temperature.begin(),min_temperature.end(),
    std::bind(std::less<int>(),std::placeholders::_1,temp));
}
Temperatura &operator ++(Temperatura &t){
    int x(std::count_if(t.max_temperature.begin(),t.max_temperature.end(),
    std::bind(std::equal_to<int>(),t.max_temp,std::placeholders::_1)));
    if(x)throw std::logic_error("Ilegalna operacija");
    std::transform(t.max_temperature.begin(),t.max_temperature.end(),
    t.max_temperature.begin(),std::bind(std::plus<int>(),1,std::placeholders::_1));
    std::transform(t.min_temperature.begin(),t.min_temperature.end(),
    t.min_temperature.begin(),std::bind(std::plus<int>(),1,std::placeholders::_1));
    return t;
}
Temperatura Temperatura::operator ++(int){
    Temperatura t(*this);
    ++(*this);
    return t;
}
Temperatura &operator --(Temperatura &t){
    int x(std::count_if(t.min_temperature.begin(),t.min_temperature.end(),
    std::bind(std::equal_to<int>(),t.min_temp,std::placeholders::_1)));
    if(x)throw std::logic_error("Ilegalna operacija");
    std::transform(t.max_temperature.begin(),t.max_temperature.end(),
    t.max_temperature.begin(),std::bind(std::minus<int>(),std::placeholders::_1,1));
    std::transform(t.min_temperature.begin(),t.min_temperature.end(),
    t.min_temperature.begin(),std::bind(std::minus<int>(),std::placeholders::_1,1));
    return t;
}
Temperatura Temperatura::operator --(int){
    Temperatura t(*this);
    --(*this);
    return t;
}
std::vector<int> Temperatura::operator *() const{
    std::vector<int> v;
    std::transform(max_temperature.begin(),max_temperature.end(),
    min_temperature.begin(),std::back_inserter(v),
    std::minus<int>());
    return v;
}
std::vector<int> Temperatura::operator +() const{
    std::vector<int> v;
    std::transform(max_temperature.begin(),max_temperature.end(),
    std::back_inserter(v),std::bind(std::minus<int>(),max_temp,std::placeholders::_1));
    return v;
}
std::vector<int> Temperatura::operator -() const{
    std::vector<int> v;
    std::transform(min_temperature.begin(),min_temperature.end(),
    std::back_inserter(v),std::bind(std::minus<int>(),std::placeholders::_1,min_temp));
    return v;
}

std::pair<int,int> Temperatura::operator [](int i) const{
    if(i < 1 || i > max_temperature.size())
        throw std::range_error("Neispravan indeks");
    auto max(max_temperature.begin());
    auto min(min_temperature.begin());
    std::advance(max,i-1);
    std::advance(min,i-1);
    return {*min,*max};
}
 std::ostream &operator <<(std::ostream &tok,const Temperatura &t){
    std::copy(t.min_temperature.begin(),t.min_temperature.end(),
    std::ostream_iterator<int>(tok," "));
    tok << std::endl;
    std::copy(t.max_temperature.begin(),t.max_temperature.end(),
    std::ostream_iterator<int>(tok," "));
    return tok;
}
bool operator ==(const Temperatura &t1,const Temperatura &t2){
    return t1.max_temp==t2.max_temp && t1.min_temp == t2.min_temp && 
    std::equal(t1.max_temperature.begin(),t1.max_temperature.end(),t2.max_temperature.begin()) && 
    std::equal(t1.min_temperature.begin(),t1.min_temperature.end(),t2.min_temperature.begin());
}
bool operator !=(const Temperatura &t1,const Temperatura &t2){
    return !(t1==t2);
}
Temperatura operator +(const Temperatura &t1,int x){
    int prekoracenje(std::count_if(t1.max_temperature.begin(),t1.max_temperature.end(),
    std::bind(std::greater<int>(),std::placeholders::_1,t1.max_temp-x))
    +std::count_if(t1.min_temperature.begin(),t1.min_temperature.end(),
    std::bind(std::less<int>(),std::placeholders::_1,t1.min_temp-x)));
    if(prekoracenje)
        throw std::logic_error("Prekoracen dozvoljeni opseg temperatura");
    auto t3(t1);
    std::transform(t1.max_temperature.begin(),t1.max_temperature.end(),
    t3.max_temperature.begin(),std::bind(std::plus<int>(),std::placeholders::_1,x));
    std::transform(t1.min_temperature.begin(),t1.min_temperature.end(),
    t3.min_temperature.begin(),std::bind(std::plus<int>(),std::placeholders::_1,x));
    return t3;
}
Temperatura &Temperatura::operator +=(int x){
    int prekoracenje(std::count_if(max_temperature.begin(),max_temperature.end(),
    std::bind(std::greater<int>(),std::placeholders::_1,max_temp-x))
    +std::count_if(min_temperature.begin(),min_temperature.end(),
    std::bind(std::less<int>(),std::placeholders::_1,min_temp-x)));
    if(prekoracenje)
        throw std::logic_error("Prekoracen dozvoljeni opseg temperatura");
        std::transform(max_temperature.begin(),max_temperature.end(),
    max_temperature.begin(),std::bind(std::plus<int>(),std::placeholders::_1,x));
    std::transform(min_temperature.begin(),min_temperature.end(),
    min_temperature.begin(),std::bind(std::plus<int>(),std::placeholders::_1,x));
    return *this;
}
Temperatura operator +(int x,const Temperatura &t1){
    return t1+x;
}
Temperatura operator -(const Temperatura &t1,int x){
    return t1+(-x);
}
Temperatura operator -(int x,const Temperatura &t1){
    auto t3(t1);
     std::transform(t1.max_temperature.begin(),t1.max_temperature.end(),
    t3.max_temperature.begin(),std::bind(std::minus<int>(),x,std::placeholders::_1));
    std::transform(t1.min_temperature.begin(),t1.min_temperature.end(),
    t3.min_temperature.begin(),std::bind(std::minus<int>(),x,std::placeholders::_1));
    std::swap(t3.max_temperature,t3.min_temperature);
    t3.max_temp=x-t3.min_temp;
    t3.min_temp=x-t3.max_temp;
    return t3;
}
Temperatura Temperatura::operator -=(int x){
    return (*this)+=-x;
}
void BrisiTemperature(std::pair<int,int> temp){
    
}
int main ()
{
    Temperatura a(100,500);
    a.RegistrirajTemperature({125,300});
    a.RegistrirajTemperature({140,400});
    a.RegistrirajTemperature({200,450});
    a.RegistrirajTemperature({400,450});
    a.RegistrirajTemperature({120,360});
    a++;
    std::cout << a++;
	return 0;
}