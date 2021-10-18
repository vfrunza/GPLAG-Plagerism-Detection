/B16/17 (Zadaća 5, Zadatak 5)
//Autotestovi by Berina Cocalic (mail: bcocalic1@etf.unsa.ba)
//Za autotestove se obracati *iskljucivo* osobi koja ih pise
#include <iostream>
#include <stdexcept>
#include <algorithm>
#include <functional>
#include <list>
#include <utility>
#include <vector>
#include <iterator>


class Temperature{
    std::list<int> minimalne, maksimalne;
    int minimalna, maksimalna;
    public:
      Temperature(int mini, int maksi);
      void RegistrirajTemperature(std::pair<int, int> par);
      void BrisiSve();
      void BrisiNegativneTemperature();
      int DajBrojRegistriranihTemperatura() const;
      int DajMinimalnuTemperaturu() const;
      int DajMaksimalnuTemperaturu() const;
      int DajBrojTemperaturaVecihOd(int t) const;
      int DajBrojTemperaturaManjihOd(int t) const;
      bool operator!();
      friend Temperature &operator++ (Temperature &temp);
      friend Temperature operator++ (Temperature &temp, int);
      friend Temperature &operator-- (Temperature &temp);
      friend Temperature operator-- (Temperature &temp, int);
      std::vector<int> operator*();
      std::vector<int> operator-();
      std::vector<int> operator+();
      std::pair<int, int> operator[] (int i) const;
      friend bool operator== (const Temperature &t1, const Temperature &t2);
      friend bool operator!= (const Temperature &t1, const Temperature &t2);
      friend std::ostream &operator<< (std::ostream &tok, const Temperature &temp);
      friend Temperature operator+ (const Temperature &temp, int y);
      friend Temperature &operator+=(Temperature &temp, int y);
      friend Temperature &operator+= (int y, Temperature &temp);
      friend Temperature operator+ (int y, const Temperature &temp);
      friend Temperature operator- (const Temperature &temp, int y);
      friend Temperature operator- (int y, const Temperature &temp);
      friend Temperature &operator-= (Temperature &temp, int y);
      friend Temperature &operator -= (int y, Temperature &temp);
};

Temperature::Temperature(int mini, int maksi){
    if(mini>maksi)
      throw std::range_error("Nekorektne temperature");
    minimalna = mini;
    maksimalna = maksi;
}

void Temperature::RegistrirajTemperature(std::pair<int, int> par){
    if(par.first < minimalna || par.second>maksimalna || par.first>par.second)
      throw std::range_error("Nekorektne temperature");
    minimalne.push_back(par.first);
    maksimalne.push_back(par.second);
}

void Temperature::BrisiSve(){
    minimalne.resize(0);
    maksimalne.resize(0);
}

void Temperature::BrisiNegativneTemperature(){
  auto p = std::find_if(maksimalne.begin(), maksimalne.end(), std::bind(std::less<int>(), std::placeholders::_1, 0));
  int a = std::distance(maksimalne.begin(), p);
  auto q = minimalne.begin();
  std::advance(q, a );
  if(p!=maksimalne.end()){
  p = maksimalne.erase(p);
  q = minimalne.erase(q);
  }
  p = std::find_if(maksimalne.begin(), maksimalne.end(), std::bind(std::less<int>(), std::placeholders::_1, 0));
  if(p!=maksimalne.end())
    BrisiNegativneTemperature();
}




int Temperature::DajBrojRegistriranihTemperatura() const{
    return maksimalne.size();
}

int Temperature::DajMinimalnuTemperaturu() const{
    if(minimalne.size()==0)
      throw std::logic_error("Nema registriranih temperatura");
    auto p = std::min_element(minimalne.begin(), minimalne.end());
    return *p;
}

int Temperature::DajMaksimalnuTemperaturu() const{
    if(maksimalne.size()==0)
      throw std::logic_error("Nema registriranih temperatura");
    auto p = std::max_element(maksimalne.begin(), maksimalne.end());
    return *p;
}

int Temperature::DajBrojTemperaturaVecihOd(int t) const{
    if(maksimalne.size()==0)
      throw std::logic_error("Nema registriranih temperatura");
    int brojac = std::count_if(maksimalne.begin(), maksimalne.end(), std::bind(std::greater<int>(), std::placeholders::_1, t ));
    return brojac;
}

int Temperature::DajBrojTemperaturaManjihOd(int t) const{
    if(minimalne.size()==0)
      throw std::logic_error("Nema registriranih temperatura");
    int brojac = std::count_if(minimalne.begin(), minimalne.end(), std::bind(std::less<int>(), std::placeholders::_1, t));
    return brojac;
}


bool Temperature::operator! (){
    return (maksimalne.size()==0 && minimalne.size()==0);
}


Temperature &operator++ (Temperature &temp){
  std::transform(temp.minimalne.begin(), temp.minimalne.end(), temp.minimalne.begin(), std::bind(std::plus<int>(), std::placeholders::_1,1));
  std::list<bool> pomocna(temp.minimalne.size());
  std::transform(temp.minimalne.begin(), temp.minimalne.end(), temp.maksimalne.begin(), pomocna.begin(), std::greater<int>());
  int brojac(0);
  brojac = std::count_if(pomocna.begin(), pomocna.end(), std::bind(std::equal_to<bool>(), std::placeholders::_1, true));
  if(brojac!=0){
    std::transform(temp.minimalne.begin(), temp.minimalne.end(), temp.minimalne.begin(), std::bind(std::minus<int>(), std::placeholders::_1,1));
    throw std::logic_error("Ilegalna operacija");
  }
  return temp;
}

Temperature operator++ (Temperature &temp, int){
  Temperature pomocna2(temp);
  std::transform(temp.minimalne.begin(), temp.minimalne.end(), temp.minimalne.begin(), std::bind(std::plus<int>(), std::placeholders::_1,1));
  std::list<bool> pomocna(temp.minimalne.size());
  std::transform(temp.minimalne.begin(), temp.minimalne.end(), temp.maksimalne.begin(), pomocna.begin(), std::greater<int>());
  int brojac(0);
  brojac = std::count_if(pomocna.begin(), pomocna.end(), std::bind(std::equal_to<bool>(), std::placeholders::_1, true));
  if(brojac!=0){
    std::transform(temp.minimalne.begin(), temp.minimalne.end(), temp.minimalne.begin(), std::bind(std::minus<int>(), std::placeholders::_1, 1));
    throw std::logic_error("Ilegalna operacija");
  }
  return pomocna2;
}

Temperature &operator-- (Temperature &temp){
  std::transform(temp.maksimalne.begin(), temp.maksimalne.end(), temp.maksimalne.begin(), std::bind(std::minus<int>(), std::placeholders::_1,1));
  std::list<bool> pomocna(temp.maksimalne.size());
  std::transform(temp.maksimalne.begin(), temp.maksimalne.end(), temp.minimalne.begin(), pomocna.begin(), std::less<int>());
  int brojac(0);
  brojac = std::count_if(pomocna.begin(), pomocna.end(), std::bind(std::equal_to<bool>(), std::placeholders::_1, true));
  if(brojac!=0){
    std::transform(temp.maksimalne.begin(), temp.maksimalne.end(), temp.maksimalne.begin(), std::bind(std::plus<int>(), std::placeholders::_1,1));
    throw std::logic_error("Ilegalna operacija");
  }
  return temp;
}

Temperature operator-- (Temperature &temp, int){
   Temperature pomocna2(temp);
   std::transform(temp.maksimalne.begin(), temp.maksimalne.end(), temp.maksimalne.begin(), std::bind(std::minus<int>(), std::placeholders::_1,1));
   std::list<bool> pomocna(temp.maksimalne.size());
   std::transform(temp.maksimalne.begin(), temp.maksimalne.end(), temp.minimalne.begin(), pomocna.begin(), std::less<int>());
   int brojac(0);
   brojac = std::count_if(pomocna.begin(), pomocna.end(), std::bind(std::equal_to<bool>(), std::placeholders::_1, true));
   if(brojac!=0){
     std::transform(temp.maksimalne.begin(), temp.maksimalne.end(), temp.maksimalne.begin(), std::bind(std::plus<int>(), std::placeholders::_1,1));
     throw std::logic_error("Ilegalna operacija");
   }
   return pomocna2;
}

std::vector<int> Temperature::operator*(){
  std::vector<int> v(maksimalne.size());
  std::transform(maksimalne.begin(), maksimalne.end(), minimalne.begin(), v.begin(), std::minus<int>());
  return v;
}

std::vector<int> Temperature::operator- (){
  std::vector<int> v(minimalne.size());
  std::transform(minimalne.begin(), minimalne.end(), v.begin(), std::bind(std::minus<int>(), std::placeholders::_1, minimalna));
  return v;
}

std::vector<int> Temperature::operator+ (){
  std::vector<int> v(maksimalne.size());
  std::transform(maksimalne.begin(), maksimalne.end(), v.begin(), std::bind(std::minus<int>(), maksimalna, std::placeholders::_1));
  return v;
}

std::pair<int, int> Temperature::operator[] (int i) const{
  if(i<1 || i>maksimalne.size())
    throw std::range_error("Neispravan indeks");
  auto p(maksimalne.begin());
  auto q(minimalne.begin());
  std::advance(p, i - 1);
  std::advance(q, i - 1);
  return std::make_pair(*p, *q);
}

bool operator== (const Temperature &t1,const Temperature &t2){
  if(t1.maksimalne.size()!=t2.maksimalne.size())
    return false;
  if(t1.maksimalna!=t2.maksimalna || t1.minimalna!=t2.minimalna)
    return false;
  if(std::equal(t1.maksimalne.begin(), t1.maksimalne.end(), t2.maksimalne.begin()) && std::equal(t1.minimalne.begin(), t1.minimalne.end(), t2.minimalne.begin()))
    return true;
  return false;
}

inline bool operator!= (const Temperature &t1, const Temperature &t2){
  return !(t1==t2);
}

std::ostream &operator<< (std::ostream &tok, const Temperature &temp){
  std::copy(temp.minimalne.begin(), temp.minimalne.end(), std::ostream_iterator<int>(tok, " "));
  tok<<std::endl;
  std::copy(temp.maksimalne.begin(), temp.maksimalne.end(), std::ostream_iterator<int>(tok, " "));
  return tok;
}

Temperature operator+ (const Temperature &temp, int y){
  Temperature novi_temp(temp.minimalna, temp.maksimalna);
  novi_temp.minimalne.resize(temp.minimalne.size());
  novi_temp.maksimalne.resize(temp.maksimalne.size());
  std::transform(temp.minimalne.begin(), temp.minimalne.end(), novi_temp.minimalne.begin(), std::bind(std::plus<int>(), std::placeholders::_1, y));
  std::transform(temp.maksimalne.begin(), temp.maksimalne.end(), novi_temp.maksimalne.begin(), std::bind(std::plus<int>(), std::placeholders::_1, y));
  int brojac(0);
  brojac = std::count_if(novi_temp.minimalne.begin(), novi_temp.minimalne.end(), std::bind(std::greater<int>(), std::placeholders::_1, novi_temp.maksimalna));
  if(brojac!=0)
   throw std::logic_error("Prekoracen dozvoljeni opseg temperatura");
  brojac = std::count_if(novi_temp.maksimalne.begin(), novi_temp.maksimalne.end(), std::bind(std::greater<int>(), std::placeholders::_1, novi_temp.maksimalna));
  if(brojac!=0)
    throw std::logic_error("Prekoracen dozvoljeni opseg temperatura");
  return novi_temp;
}
inline Temperature operator+ (int y, const Temperature &temp){
  return temp + y;
}

Temperature &operator+= (Temperature &temp, int y){
  std::transform(temp.minimalne.begin(), temp.minimalne.end(), temp.minimalne.begin(), std::bind(std::plus<int>(), std::placeholders::_1, y));
  std::transform(temp.maksimalne.begin(), temp.maksimalne.end(),temp.maksimalne.begin() ,std::bind(std::plus<int>(), std::placeholders::_1, y));
  int brojac1(0);
  brojac1 = std::count_if(temp.maksimalne.begin(), temp.maksimalne.end(), std::bind(std::greater<int>(), std::placeholders::_1, temp.maksimalna) );
  if(brojac1!=0){
    std::transform(temp.minimalne.begin(), temp.minimalne.end(),temp.minimalne.begin() ,std::bind(std::minus<int>(), std::placeholders::_1, y));
    std::transform(temp.maksimalne.begin(), temp.maksimalne.end(),temp.maksimalne.begin() ,std::bind(std::minus<int>(), std::placeholders::_1, y));
    throw std::logic_error("Prekoracen dozvoljeni opseg temperatura");
  }
  return temp;
}

inline Temperature &operator+= (int y, Temperature &temp){
  return temp+=y;
}

Temperature operator- (const Temperature &temp, int y){
  Temperature novi_temp(temp);
  std::transform(novi_temp.minimalne.begin(), novi_temp.minimalne.end(), novi_temp.minimalne.begin(), std::bind(std::minus<int>(), std::placeholders::_1, y));
  std::transform(novi_temp.maksimalne.begin(), novi_temp.maksimalne.end(), novi_temp.maksimalne.begin(), std::bind(std::minus<int>(), std::placeholders::_1, y));
  int brojac(0);
  brojac = std::count_if(novi_temp.minimalne.begin(), novi_temp.minimalne.end(), std::bind(std::less<int>(), std::placeholders::_1, novi_temp.minimalna));
  if(brojac!=0)
    throw std::logic_error("Prekoracen dozvoljeni opseg temperatura");
  brojac = std::count_if(novi_temp.maksimalne.begin(), novi_temp.maksimalne.end(), std::bind(std::less<int>(), std::placeholders::_1, novi_temp.minimalna));
  if(brojac!=0)
    throw std::logic_error("Prekoracen dozvoljeni opseg temperatura");
  return novi_temp;
}

Temperature operator- (int y, const Temperature &temp){
  Temperature novi_temp(temp.minimalna, temp.maksimalna);
  novi_temp.minimalne.resize(temp.minimalne.size());
  novi_temp.maksimalne.resize(temp.maksimalne.size());
  std::transform(temp.minimalne.begin(), temp.minimalne.end(), novi_temp.maksimalne.begin(), std::bind(std::minus<int>(), y, std::placeholders::_1));
  int brojac(0);
  brojac = std::count_if(novi_temp.maksimalne.begin(), novi_temp.maksimalne.end(), std::bind(std::less<int>(), std::placeholders::_1, novi_temp.minimalna));
  if(brojac!=0)
    throw std::logic_error("Prekoracen dozvoljeni opseg temperatura");
  auto p = std::find_if(novi_temp.maksimalne.begin(), novi_temp.maksimalne.end(), std::bind(std::greater<int>(), std::placeholders::_1, novi_temp.maksimalna));
  if(p!=novi_temp.maksimalne.end())
    throw std::logic_error("Prekoracen dozvoljeni opseg temperatura");
  std::transform(temp.maksimalne.begin(), temp.maksimalne.end(), novi_temp.minimalne.begin(), std::bind(std::minus<int>(),y ,std::placeholders::_1));
  auto s = std::find_if(novi_temp.minimalne.begin(), novi_temp.minimalne.end(), std::bind(std::less<int>(), std::placeholders::_1, novi_temp.minimalna));
  if(s!=novi_temp.minimalne.end())
    throw std::logic_error("Prekoracen dozvoljeni opseg temperatura");
  auto r = std::find_if(novi_temp.minimalne.begin(), novi_temp.minimalne.end(), std::bind(std::greater<int>(), std::placeholders::_1, novi_temp.maksimalna));
  if(r!=novi_temp.minimalne.end())
    throw std::logic_error("Prekoracen dozvoljeni opseg temperatura");
  return novi_temp;
}

Temperature &operator-= (Temperature &temp, int y){
  std::transform(temp.minimalne.begin(), temp.minimalne.end(), temp.minimalne.begin(), std::bind(std::minus<int>(), std::placeholders::_1, y));
  std::transform(temp.maksimalne.begin(), temp.maksimalne.end(), temp.maksimalne.begin(), std::bind(std::minus<int>(), std::placeholders::_1, y));
  auto p = std::find_if(temp.minimalne.begin(), temp.minimalne.end(), std::bind(std::less<int>(), std::placeholders::_1, temp.minimalna));
  if(p!=temp.minimalne.end()){
    std::transform(temp.minimalne.begin(), temp.minimalne.end(), temp.minimalne.begin(), std::bind(std::plus<int>(), std::placeholders::_1, y));
    std::transform(temp.maksimalne.begin(), temp.maksimalne.end(), temp.maksimalne.begin(), std::bind(std::plus<int>(), std::placeholders::_1, y));
    throw std::logic_error("Prekoracen dozvoljeni opseg temperatura");
  }
  return temp;
}

Temperature &operator-= (int y, Temperature &temp){
  Temperature novi_temp(temp);
  std::transform(novi_temp.maksimalne.begin(), novi_temp.maksimalne.end(), temp.minimalne.begin(), std::bind(std::minus<int>(), y, std::placeholders::_1));
  std::transform(novi_temp.minimalne.begin(), novi_temp.minimalne.end(), temp.maksimalne.begin(), std::bind(std::minus<int>(),y, std::placeholders::_1));
  auto p = std::find_if(temp.maksimalne.begin(), temp.maksimalne.end(), std::bind(std::greater<int>(), std::placeholders::_1, temp.maksimalna));
  auto q = std::find_if(temp.minimalne.begin(), temp.minimalne.end(), std::bind(std::less<int>(), std::placeholders::_1, temp.minimalna));
  if(p!=temp.maksimalne.end() || q!=temp.minimalne.end()){
    temp = novi_temp;
    throw std::logic_error("Prekoracen dozvoljeni opseg temperatura");
  }
  return temp;
}

int main ()
{
  Temperature t(-30, 45);
  t.RegistrirajTemperature({-20, -1});
  t.RegistrirajTemperature({-20, -5});
  t.RegistrirajTemperature({10, 19});
  t.RegistrirajTemperature({-8, 13});
  t.RegistrirajTemperature({-20, -5});
  t.RegistrirajTemperature({-15, 29});
  t.RegistrirajTemperature({-20, -1});
  
  std::cout<<t.DajMinimalnuTemperaturu()<<" "<<t.DajMaksimalnuTemperaturu();
  t+=10;
  std::cout<<"\n"<<t.DajMinimalnuTemperaturu()<<" "<<t.DajMaksimalnuTemperaturu();
  t-=5;
  std::cout<<"\n"<<t.DajMinimalnuTemperaturu()<<" "<<t.DajMaksimalnuTemperaturu();
  10-=t;
  std::cout<<"\n"<<t.DajMinimalnuTemperaturu()<<" "<<t.DajMaksimalnuTemperaturu();
  t++;
  ++t;
  Temperature t2(t);
  if(t==t2)
    std::cout<<"\nObjekti t i t2 sadrze iste elemente\n";
  else if(t!=t2)
    std::cout<<"Objekti t i t2 sadrze razlicite elemente\n";
  std::cout<<t<<std::endl;
  t--;
  --t;
  std::cout<<"\n t:\n"<<t<<std::endl;
  std::cout<<"\n"<<(t + 3)<<std::endl;
  std::cout<<"\n"<<(t2 - 2)<<std::endl;
  std::cout<<t.DajBrojTemperaturaVecihOd(10)<<" "<<t.DajBrojTemperaturaManjihOd(-10)<<" "<<t.DajBrojRegistriranihTemperatura()<<std::endl;
  std::cout<<"\n"<<t;
  t.BrisiNegativneTemperature();
  std::cout<<"\n*****\n"<<t;
	return 0;
}