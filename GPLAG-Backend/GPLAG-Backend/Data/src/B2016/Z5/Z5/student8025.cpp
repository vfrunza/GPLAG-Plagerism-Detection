#include <list>
#include <iostream>
#include <algorithm>
#include <functional>
#include <stdexcept>
#include <vector>
class Temperature{
    std::list<int>min_temp;
    std::list<int>max_temp;
    public:
    Temperature(int min, int max){
        if(min>max || max<min) throw std::range_error("Neispravne temperature");
        else {
            min_temp.push_back(min);
            max_temp.push_back(max);
        }
    }
    void RegistrirajTemperature(std::pair<int,int> par){
        if(par.first>par.second || par.second<par.first) throw std::range_error("Neispravne temperature");
    min_temp.push_back(par.first);
    max_temp.push_back(par.second);
    }
    void BrisiSve(){
        min_temp.clear();
        max_temp.clear();
    }
    
    int DajBrojRegistriranihTemperatura() const{
    return min_temp.size();
    }
  int DajMaksimalnuTeperaturu() const{
      if(max_temp.size()==0 ) throw std::logic_error("Nema registriranih temperatura");
      int maxi=*(std::max_element(max_temp.begin(), max_temp.end()));
      return maxi;
  }
  int DajMinimalnuTeperaturu() const{
      if(min_temp.size()==0 ) throw std::logic_error("Nema registriranih temperatura");
      int mini=*(std::min_element(min_temp.begin(), min_temp.end()));
      return mini;
  }
 int  DajBrojTeperaturaVecihOd(int n) const{
     if(max_temp.size()==0 ) throw std::logic_error("Nema registriranih temperatura");
    int broj1=std::count_if(min_temp.begin(), min_temp.end(),bind(std::greater<int>(),std::placeholders::_1,n));
    int broj2=std::count_if(max_temp.begin(), max_temp.end(),bind(std::greater<int>(),std::placeholders::_1,n));
     return broj1+broj2;
 }
  int  DajBrojTeperaturaManjihOd(int n) const{
     if(min_temp.size()==0 ) throw std::logic_error("Nema registriranih temperatura");
    int broj1=std::count_if(min_temp.begin(), min_temp.end(),bind(std::less<int>(),std::placeholders::_1,n));
    int broj2=std::count_if(max_temp.begin(), max_temp.end(),bind(std::less<int>(),std::placeholders::_1,n));
     return broj1+broj2;
 }
 bool operator!() const{
     if(min_temp.size()==0 && max_temp.size()==0) return true;
     return false;
 }
 Temperature &operator++() {
     if(std::equal(min_temp.begin(), min_temp.end(), max_temp.begin(),std::less<int>())==false)
     throw std::logic_error("Ilegalna operacija");
     std::transform(min_temp.begin(), min_temp.end(), min_temp.begin(),bind(std::plus<int>(),std::placeholders::_1,1));
     return *this;
 }
 Temperature operator++(int) {
     Temperature pomocni(*this);
     if(std::equal(min_temp.begin(), min_temp.end(), max_temp.begin(),std::less<int>())==false)
     throw std::logic_error("Ilegalna operacija");
     std::transform(min_temp.begin(), min_temp.end(), min_temp.begin(),bind(std::plus<int>(),std::placeholders::_1,1));
     return pomocni;
 }
 Temperature &operator--() {
     if(std::equal(max_temp.begin(), max_temp.end(), min_temp.begin(),std::greater<int>())==false)
     throw std::logic_error("Ilegalna operacija");
     std::transform(max_temp.begin(), max_temp.end(), max_temp.begin(),bind(std::minus<int>(),std::placeholders::_1,1));
     return *this;
 }
 Temperature operator--(int) {
     Temperature pomocni(*this);
     if(std::equal(max_temp.begin(), max_temp.end(), min_temp.begin(),std::greater<int>())==false)
     throw std::logic_error("Ilegalna operacija");
     std::transform(max_temp.begin(), max_temp.end(), max_temp.begin(),bind(std::minus<int>(),std::placeholders::_1,1));
     return pomocni;
 }
 std::vector<int> operator*() const{
     std::vector<int>v(max_temp.size());
     std::transform(max_temp.begin(),max_temp.end(), min_temp.begin(),v.begin(),std::minus<int>());
     return v;
 }
 std::vector<int> operator+() const{
     std::vector<int>v(max_temp.size());
     int n(DajMaksimalnuTeperaturu());
     std::transform(max_temp.begin(),max_temp.end(),v.begin(),bind(std::minus<int>(),n,std::placeholders::_1));
     return v;
 }
  std::vector<int> operator-() const{
     std::vector<int>v(max_temp.size());
     int n(DajMinimalnuTeperaturu());
     std::transform(min_temp.begin(),min_temp.end(),v.begin(),bind(std::minus<int>(),std::placeholders::_1,n));
     return v;
 }
 std::pair<int, int> operator[](int indeks) const{
     indeks-=1;
     std::pair<int,int> par(0,0);
     if(indeks<0 || indeks>max_temp.size()) throw std::range_error("Neispravan indeks");
     else{
     std::vector<int> v1(min_temp.size());
     std::vector<int> v2(max_temp.size());
     std::copy(min_temp.begin(), min_temp.end(),v1.begin());
     std::copy(max_temp.begin(), max_temp.end(), v2.begin());
     par.first=v1[indeks];
     par.second=v2[indeks];
     }
     return par;
 }
 friend Temperature operator+(Temperature t, int n);
 friend Temperature operator-(Temperature t, int n);
 friend Temperature operator+(Temperature t, Temperature z);
 friend Temperature operator-(Temperature t, Temperature z);
 bool operator==(const Temperature &l) const{
     if(std::equal(min_temp.begin(), min_temp.end(), l.min_temp.begin())==false || 
    std::equal(max_temp.begin(), max_temp.end(), l.max_temp.begin())==false ) return false;
    return true;
 }
 bool operator!=(const Temperature &l) const{
     if(std::equal(min_temp.begin(), min_temp.end(), l.min_temp.begin())==false || 
    std::equal(max_temp.begin(), max_temp.end(), l.max_temp.begin())==false ) return true;
    return false;
 }
friend std::ostream &operator<<(std::ostream &tok, const Temperature &t); 
  Temperature &operator+=( int n){
     std::transform(min_temp.begin(), min_temp.end(), min_temp.begin(),bind(std::plus<int>(),std::placeholders::_1,n));
     std::transform(max_temp.begin(), max_temp.end(), max_temp.begin(),bind(std::plus<int>(),std::placeholders::_1,n)); 
    return *this;  
  }
  Temperature &operator-=( int n){
std::transform(min_temp.begin(), min_temp.end(), min_temp.begin(),bind(std::minus<int>(),std::placeholders::_1,n));
std::transform(max_temp.begin(), max_temp.end(), max_temp.begin(),bind(std::minus<int>(),std::placeholders::_1,n));
  return *this;
      
  }
};
Temperature operator+(Temperature t, Temperature z){
  Temperature novi(1,2);
     novi.min_temp.resize(t.min_temp.size());
      novi.max_temp.resize(t.max_temp.size());
     std::transform(t.min_temp.begin(), t.min_temp.end(),z.min_temp.begin(), novi.min_temp.begin(),std::plus<int>());
     std::transform(t.max_temp.begin(), t.max_temp.end(),z.max_temp.begin(), novi.max_temp.begin(),std::plus<int>());
     return novi;  
}
Temperature operator-(Temperature t, Temperature z){
  Temperature novi(1,2);
     novi.min_temp.resize(t.min_temp.size());
      novi.max_temp.resize(t.max_temp.size());
     std::transform(t.min_temp.begin(), t.min_temp.end(),z.min_temp.begin(), novi.min_temp.begin(),std::minus<int>());
     std::transform(t.max_temp.begin(), t.max_temp.end(),z.max_temp.begin(), novi.max_temp.begin(),std::minus<int>());
     return novi;  
}
Temperature operator+(Temperature t, int n){
Temperature novi(1,2);
     novi.min_temp.resize(t.min_temp.size());
      novi.max_temp.resize(t.max_temp.size());
     std::transform(t.min_temp.begin(), t.min_temp.end(), novi.min_temp.begin(),bind(std::plus<int>(),std::placeholders::_1,n));
     std::transform(t.max_temp.begin(), t.max_temp.end(), novi.max_temp.begin(),bind(std::plus<int>(),std::placeholders::_1,n));
     return novi;
}
Temperature operator-(Temperature t, int n){
Temperature novi(1,2);
     novi.min_temp.resize(t.min_temp.size());
      novi.max_temp.resize(t.max_temp.size());
     std::transform(t.min_temp.begin(), t.min_temp.end(), novi.min_temp.begin(),bind(std::minus<int>(),std::placeholders::_1,n));
     std::transform(t.max_temp.begin(), t.max_temp.end(), novi.max_temp.begin(),bind(std::minus<int>(),std::placeholders::_1,n));
     return novi;
}
std::ostream &operator<<(std::ostream &tok, const Temperature &t){
    

}
int main ()
{
    
	return 0;
}