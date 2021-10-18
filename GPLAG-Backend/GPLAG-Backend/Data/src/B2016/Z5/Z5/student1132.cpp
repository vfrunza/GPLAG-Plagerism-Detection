/B16/17 (Zadaća 5, Zadatak 5)
//Autotestovi by Berina Cocalic (mail: bcocalic1@etf.unsa.ba)
//Za autotestove se obracati *iskljucivo* osobi koja ih pise
#include <iostream>
#include <algorithm>
#include <functional>
#include <list>
#include <vector>
#include <iterator>
class Temperature
{
    std::list<int> minimalne, maksimalne;
    int min, max;
  public:
    Temperature(int min, int max);
    void RegistrirajTemperature(std::pair<int,int> p);
    void BrisiSve();
    void BrisiNegativneTemperature();
    int DajBrojRegistriranihTemperatura() const;
    int DajMinimalnuTemperaturu() const;
    int DajMaksimalnuTemperaturu() const;
    int DajBrojTemperaturaVecihOd(int t) const;
    int DajBrojTemperaturaManjihOd(int t) const;
    bool operator!();
    Temperature& operator++();
    Temperature& operator--();
    Temperature operator++(int);
    Temperature operator--(int);
    friend std::vector<int> operator*(const Temperature& t);
    friend std::vector<int> operator-(const Temperature& t);
    friend std::vector<int> operator+(const Temperature& t);
    std::pair<int,int> operator[](int indeks) const;
    friend Temperature operator+(const Temperature& t, int x);
    friend Temperature operator+(int x, const Temperature& t);
    friend Temperature operator-(const Temperature& t, int x);
    friend Temperature operator-(int x, const Temperature& t);
    Temperature& operator+=(int x);
    Temperature& operator-=(int x);
    friend bool operator==(const Temperature& t1, const Temperature& t2);
    friend bool operator!=(const Temperature& t1, const Temperature& t2);
    friend std::ostream& operator<<(std::ostream& out, const Temperature& t1);
};

Temperature::Temperature(int min, int max)
{
  if(min > max) throw std::range_error("Nekorektne temperature");
  this->min = min;
  this->max = max;
}
void Temperature::RegistrirajTemperature(std::pair<int,int> p)
{
  if( p.first > p.second || p.first < min || p.second > max)
    throw std::range_error("Nekorektne temperature");
  minimalne.push_back(p.first);
  maksimalne.push_back(p.second);
}
void Temperature::BrisiSve()
{
  minimalne.clear();
  maksimalne.clear();
}
void Temperature::BrisiNegativneTemperature()
{
 auto it = std::find_if(maksimalne.begin(), maksimalne.end(), std::bind(std::less<int>(),std::placeholders::_1, 0));
 if(it == maksimalne.end()) return;
 int dist = std::distance(maksimalne.begin(), it);
 auto iter = minimalne.begin();
 std::advance(iter, dist);
  maksimalne.erase(it);
 minimalne.erase(iter);
 BrisiNegativneTemperature();
}
int Temperature::DajBrojRegistriranihTemperatura()const
{
  return maksimalne.size();
}
int Temperature::DajMinimalnuTemperaturu()const
{
  if(DajBrojRegistriranihTemperatura() == 0)
      throw std::logic_error("Nema registriranih temperatura");
  return *min_element(minimalne.begin(),minimalne.end());
}
int Temperature::DajMaksimalnuTemperaturu()const
{
  if(DajBrojRegistriranihTemperatura() == 0)
    throw std::logic_error("Nema registriranih temperatura");
  return *max_element(maksimalne.begin(),maksimalne.end());
}
int Temperature::DajBrojTemperaturaVecihOd(int t)const
{
  if(DajBrojRegistriranihTemperatura() == 0)
    throw std::logic_error("Nema registriranih temperatura");
  return std::count_if(minimalne.begin(),minimalne.end(),std::bind(std::greater<int>(),std::placeholders::_1,t));  
}
int Temperature::DajBrojTemperaturaManjihOd(int t)const
{
  if(DajBrojRegistriranihTemperatura() == 0)
    throw std::logic_error("Nema registriranih temperatura");
  return std::count_if(maksimalne.begin(),maksimalne.end(),std::bind(std::less<int>(), std::placeholders::_1, t));
}
bool Temperature::operator!()
{
  return DajBrojRegistriranihTemperatura() == 0;
}
Temperature& Temperature::operator++()
{
  std::transform(minimalne.begin(),minimalne.end(),minimalne.begin(),std::bind(std::plus<int>(), std::placeholders::_1, 1));
  std::vector<bool> b(DajBrojRegistriranihTemperatura());
  std::transform(minimalne.begin(),minimalne.end(),maksimalne.begin(),b.begin(),std::greater<int>());
  if(std::count(b.begin(),b.end(),true) != 0) 
  {
    std::transform(minimalne.begin(),minimalne.end(),minimalne.begin(),std::bind(std::minus<int>(), std::placeholders::_1, 1));
    throw std::logic_error("Ilegalna operacija");
  }
  return *this;
}
Temperature& Temperature::operator--()
{
  std::transform(maksimalne.begin(),maksimalne.end(),maksimalne.begin(),std::bind(std::minus<int>(), std::placeholders::_1, 1));
  std::vector<bool> b(DajBrojRegistriranihTemperatura());
  std::transform(minimalne.begin(),minimalne.end(),maksimalne.begin(),b.begin(),std::greater<int>());
  if(std::count(b.begin(),b.end(),true) != 0) 
  {
    std::transform(maksimalne.begin(),maksimalne.end(),maksimalne.begin(),std::bind(std::plus<int>(), std::placeholders::_1, 1));
    throw std::logic_error("Ilegalna operacija");
  }
  return *this;
}
Temperature Temperature::operator++(int)
{
  return ++*this;
}
Temperature Temperature::operator--(int)
{
  return --*this;
}
std::vector<int> operator*(const Temperature& t)
{
  std::vector<int> v(t.DajBrojRegistriranihTemperatura());
  std::transform(t.maksimalne.begin(),t.maksimalne.end(),t.minimalne.begin(),v.begin(),std::minus<int>());
  return std::move(v);
}
std::vector<int> operator-(const Temperature& t)
{
  std::vector<int> v(t.DajBrojRegistriranihTemperatura());
  std::transform(t.minimalne.begin(),t.minimalne.end(),v.begin(),std::bind(std::minus<int>(),std::placeholders::_1, t.min));
  return std::move(v);
}
std::vector<int> operator+(const Temperature& t)
{
  std::vector<int> v(t.DajBrojRegistriranihTemperatura());
  std::transform(t.maksimalne.begin(),t.maksimalne.end(),v.begin(),std::bind(std::minus<int>(),t.max, std::placeholders::_1));
  return std::move(v);
}
std::ostream& operator<<(std::ostream& out, const Temperature& t)
{
  std::copy(t.minimalne.begin(),t.minimalne.end(),std::ostream_iterator<int>(out, " "));
  std::cout<<std::endl;
  std::copy(t.maksimalne.begin(),t.maksimalne.end(),std::ostream_iterator<int>(out," "));
  std::cout<< std::endl;
  return out;
}
std::pair<int,int> Temperature::operator[](int indeks)const
{
  if(indeks > DajBrojRegistriranihTemperatura() || indeks < 1)
    throw std::range_error("Neispravan indeks");
  auto min_it = minimalne.begin(), max_it = maksimalne.begin();
  std::advance(min_it, indeks-1);
  std::advance(max_it, indeks-1);
  return {*min_it, *max_it};
}
Temperature operator+(const Temperature& t, int x)
{
  Temperature novo(t);
  std::transform(novo.minimalne.begin(),novo.minimalne.end(),novo.minimalne.begin(),std::bind(std::plus<int>(), std::placeholders::_1, x));
  std::transform(novo.maksimalne.begin(),novo.maksimalne.end(),novo.maksimalne.begin(),std::bind(std::plus<int>(), std::placeholders::_1, x));
  if(novo.DajMaksimalnuTemperaturu() > novo.max || novo.DajMinimalnuTemperaturu() < novo.min)
      throw std::logic_error("Prekoracen dozvoljeni opseg temperatura");
  return novo;
}
Temperature operator+(int x, const Temperature& t)
{
  return t + x;
}
Temperature operator-(const Temperature& t, int x)
{
  Temperature novo(t);
  std::transform(novo.minimalne.begin(),novo.minimalne.end(),novo.minimalne.begin(),std::bind(std::minus<int>(),std::placeholders::_1, x));
  std::transform(novo.maksimalne.begin(),novo.maksimalne.end(),novo.maksimalne.begin(),std::bind(std::minus<int>(),std::placeholders::_1, x));
  if(novo.DajMaksimalnuTemperaturu() > novo.max || novo.DajMinimalnuTemperaturu() < novo.min)
    throw std::logic_error("Prekoracen dozvoljeni opseg temperatura");
  return novo;
}
Temperature operator-(int x, const Temperature& t)
{
  Temperature novo(t);
  std::transform(t.minimalne.begin(),t.minimalne.end(),novo.maksimalne.begin(),std::bind(std::minus<int>(), x, std::placeholders::_1));
  std::transform(t.maksimalne.begin(), t.maksimalne.end(), novo.minimalne.begin(),std::bind(std::minus<int>(),x,std::placeholders::_1));
  if(novo.DajMaksimalnuTemperaturu() > novo.max || novo.DajMinimalnuTemperaturu() < novo.min)
    throw std::logic_error("Prekoracen dozvoljeni opseg temperatura");
  return novo;
}
Temperature& Temperature::operator+=(int x)
{
  *this = *this + x;
  return *this;
}
Temperature& Temperature::operator-=(int x)
{
  *this = *this - x;
  return *this;
}
bool operator==(const Temperature& t1, const Temperature& t2)
{
  return t1.min == t2.min && t1.max == t2.max && t1.minimalne == t2.minimalne && t1.maksimalne == t2.maksimalne;
}
bool operator!=(const Temperature& t1, const Temperature& t2)
{
  return !(t1 == t2);
}
int main ()
{
  Temperature t(-54, 54);
  t.RegistrirajTemperature({1,2});
  t.RegistrirajTemperature({3,3});
  t.RegistrirajTemperature({-3,-1});
  t.RegistrirajTemperature({-43,-41});
  t.RegistrirajTemperature({-5,4});
  t.BrisiNegativneTemperature();
  std::cout<< t << std::endl;
  try{++t; --t;}catch(...){}
  std::cout << (t-=2);
  auto v(+t);
  Temperature t2(t+1);
  std::cout<< "\n"<<(t == t2)<<"-"<<(t!=t2)<<"\n";
  std::cout<< t[2].first<<" "<<t[2].second;
	return 0;
}