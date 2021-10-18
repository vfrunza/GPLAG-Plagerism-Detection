#include <iostream>
#include <list>
#include <iomanip>
#include <functional>
#include <algorithm>
#include <stdexcept>
#include <utility>
#include <vector>
#include <iterator>

class Temperature {
    std::list<int> min_temp;
    std::list<int> max_temp;
    
    public:
    Temperature(int min,int max) {
        if(min>max) 
        throw std::range_error("Nekorektne temperature");
        min_temp.push_back(min);
        max_temp.push_back(max);
    }
  void RegistrirajTemperature(std::pair<int,int> par);
 void BrisiSve();
 void BrisiTemperature(std::pair<int,int> brojevi);
 int DajBrojRegistriranihTemperatura() const {
        return min_temp.size()-1;
}
 int DajMinimalnuTemperaturu() const  {
     auto it(min_temp.begin());
     it++;
     return *std::min_element(it,min_temp.end(),std::less<int>());
 }
int DajMaksimalnuTemperaturu() const {
    auto it(max_temp.begin());
    it++;
    return *std::max_element(it,max_temp.end(),std::less<int>());
}
 int DajBrojTemperaturaVecihOd(int temperatura);
 int DajBrojTemperaturaManjihOd(int temperatura);
 bool operator !() {
     return min_temp.size()==0;
 }
 std::list<int> operator ++();
 std::list<int> operator++(int);
 std::list<int> operator --();
 std::list<int> operator --(int);
 std::vector<int> operator *();
 std::vector<int> operator -();
 std::vector<int> operator +();
 std::pair<int,int> operator [](int indeks);
 friend Temperature operator +(Temperature &temp,int y);
  friend Temperature operator +(int y,Temperature &temp);
 Temperature operator +=(int k);
 Temperature operator -=(int y);
 bool operator ==(Temperature &temp1);
 bool operator !=(Temperature &temp1);
  friend Temperature  operator-(Temperature &temp,int k);
  friend Temperature operator -(int k,Temperature &temp);
 friend std::ostream &operator <<(std::ostream &tok,Temperature &temp);
 friend std::ostream &operator <<(std::ostream &tok,std::vector<int> v);
};
void Temperature::RegistrirajTemperature(std::pair<int,int> par) {
    static int broj(*std::min_element(min_temp.begin(), min_temp.end(), std::greater<int>()));
    static int  pomoc(*std::max_element(max_temp.begin(), max_temp.end(), std::less<int>()));
    if(par.first<broj || par.second>pomoc || par.first>par.second || par.first>pomoc || par.second<broj) {
        throw std::range_error("Nekorektne temperature");
    }
  min_temp.push_back(par.first);
  max_temp.push_back(par.second);
}
void Temperature::BrisiSve() {
    min_temp.erase(min_temp.begin(),min_temp.end());
    max_temp.erase(max_temp.begin(),max_temp.end());
}
void Temperature::BrisiTemperature(std::pair<int,int> brojevi) {
      auto broj(std::find(min_temp.begin(),min_temp.end(),brojevi.first));
      auto cifra(std::find(max_temp.begin(),max_temp.end(),brojevi.second));
    if(broj==min_temp.end() || cifra==max_temp.end()) throw std::logic_error("Takve temperature nisu registrirane");
       else {
           int prvi,drugi;
           prvi=std::distance(min_temp.begin(),broj);
           drugi=std::distance(max_temp.begin(),cifra);
           if(prvi==drugi) {
       min_temp.erase(broj);
       max_temp.erase(cifra);
        }
}
}
int Temperature::DajBrojTemperaturaVecihOd(int temperatura) {
 int broj(std::count_if(min_temp.begin(),min_temp.end(),std::bind(std::greater<int>(),std::placeholders::_1,temperatura)));
 int broj2(std::count_if(max_temp.begin(),max_temp.end(),std::bind(std::less<int>(),std::placeholders::_1,temperatura)));
 return broj+broj2;
    }
int Temperature::DajBrojTemperaturaManjihOd(int temperatura) {
int broj(std::count_if(max_temp.begin(),max_temp.end(),std::bind(std::less<int>(),std::placeholders::_1,temperatura)));
int broj2(std::count_if(max_temp.begin(),max_temp.end(),std::bind(std::greater<int>(),std::placeholders::_1,temperatura)));
}

std::list<int> Temperature::operator ++() {
    int najveca(*std::max_element(max_temp.begin(),max_temp.end(),std::greater<int>()));
    std::for_each((min_temp.begin())++,min_temp.end(),std::bind(std::plus<int>(),std::placeholders::_1,1));
    if(std::count_if((min_temp.begin())++,min_temp.end(),std::bind(std::greater<int>(),std::placeholders::_1,najveca))) {
        throw std::logic_error("Ilegalna operacija");
    }
    return min_temp;
}

std::list<int> Temperature::operator ++(int) {
    std::list<int> povratna;
    int najveca(*std::max_element(max_temp.begin(),max_temp.end(),std::greater<int>()));
    std::copy(min_temp.begin(),min_temp.end(),povratna.begin());
    std::for_each((min_temp.begin())++,min_temp.end(),std::bind(std::plus<int>(),std::placeholders::_1,1));
     if(std::count_if((min_temp.begin())++,min_temp.end(),std::bind(std::greater<int>(),std::placeholders::_1,najveca))) {
        throw std::logic_error("Ilegalna operacija");
    }
    return povratna;
}

std::list<int> Temperature::operator --() {
    int najmanja(*std::min_element(min_temp.begin(),min_temp.end(),std::less<int>()));
    std::for_each((max_temp.begin())++,max_temp.end(),std::bind(std::minus<int>(),std::placeholders::_1,1));
 if(count_if((max_temp.begin())++,max_temp.end(),std::bind(std::less<int>(),std::placeholders::_1,najmanja))) {
     throw std::logic_error("Ilegalna operacija");
 }
 return max_temp;
}

std::list<int> Temperature::operator --(int) {
    std::list<int> pomocna;
    int najmanja(*std::min_element(min_temp.begin(),min_temp.end(),std::less<int>()));
    std::copy(max_temp.begin(),max_temp.end(),pomocna.begin());
     std::for_each((max_temp.begin())++,max_temp.end(),std::bind(std::plus<int>(),std::placeholders::_1,1));
     if(std::count_if((max_temp.begin())++,max_temp.end(),std::bind(std::greater<int>(),std::placeholders::_1,najmanja))) {
        throw std::logic_error("Ilegalna operacija");
    }
    return pomocna;
}

std::vector<int> Temperature::operator *() {
    std::vector<int> v;
std::vector<int> v1(min_temp.size());
std::vector<int> v2(max_temp.size());

std::copy(min_temp.begin(),min_temp.end(),v1.begin());
std::copy(max_temp.begin(),max_temp.end(),v2.begin());
std::transform(v1.begin(),v1.end(),v2.begin(),v.begin(),[](int x,int y) {
    return x-y;
});
return v;
}
bool Temperature::operator ==(Temperature &temp1) {
    return (std::equal(min_temp.begin(),min_temp.end(),temp1.min_temp.begin()) && std::equal(max_temp.begin(),max_temp.end(),temp1.max_temp.begin()));
}
 inline bool Temperature::operator !=(Temperature &temp1) {
    return !(*this==temp1);
}

std::pair<int,int> Temperature::operator [] (int indeks) {
    std::pair<int,int> rezultat;
    if(indeks<1 || indeks>min_temp.size())
        throw std::range_error("Neispravan indeks");
    auto it(std::next(min_temp.begin(),indeks));
    rezultat.first=*it;
    
    it=std::next(max_temp.begin(),indeks);
    rezultat.second=*it;
    
    return rezultat;
}

std::vector<int> Temperature::operator -() {
    std::vector<int> v(min_temp.size());
    std::list<int> lista;
    std::copy(min_temp.begin(),min_temp.end(),lista.begin());
    int najmanja(*std::min_element(min_temp.begin(),min_temp.end(),std::less<int>()));
    std::for_each((lista.begin()),lista.end(),std::bind(std::minus<int>(),std::placeholders::_1,najmanja));
    std::copy(lista.begin(),lista.end(),v.begin());                                  
   return v;
}
std::vector<int> Temperature::operator +() {
    std::vector<int> v(max_temp.size());
    std::list<int> lista;
    std::copy(max_temp.begin(),max_temp.end(),lista.begin());
    int najveca(*std::max_element(max_temp.begin(),max_temp.end(),std::greater<int>()));
    std::for_each(lista.begin(),lista.end(),std::bind(std::minus<int>(),std::placeholders::_1,najveca));
    std::copy(lista.begin(),lista.end(),v.begin());
    return v;
}
std::ostream &operator <<(std::ostream &tok,Temperature &temp) {
 auto  it(temp.max_temp.begin());
    auto it2(temp.min_temp.begin());
  tok<<*it<<" ";
  it=temp.max_temp.erase(it);
  if(it!=temp.max_temp.end()) {
      tok<<temp;
  }
  else {
      tok<<std::endl;
  tok<<*it2<<" ";
  auto it3(temp.min_temp.begin());
  it3++;
  if(it2==temp.min_temp.begin()) {
      it2=it3;
  }
  }
  if(it2!=temp.min_temp.end()) {
      tok<<temp;
  }
  tok<<std::endl;
  return tok;
}
std::ostream &operator <<(std::ostream &tok,std::vector<int> v) {
    auto it(v.begin());
    tok<<*it;
    it++;
    if(it!=v.end()) {
        tok<<*it;
        it++;
    }
    return tok;
} 
Temperature operator +(Temperature &temp,int y) {
    Temperature novi(0,0);
    std::copy(temp.min_temp.begin(),temp.min_temp.end(),novi.min_temp.begin());
    std::copy(temp.max_temp.begin(),temp.max_temp.end(),novi.max_temp.begin());
    std::for_each(novi.min_temp.begin(),novi.min_temp.end(),std::bind(std::plus<int>(),std::placeholders::_1,y));
    std::for_each(novi.max_temp.begin(),novi.max_temp.end(),std::bind(std::plus<int>(),std::placeholders::_1,y));
    return novi;
}
Temperature operator -(Temperature &temp,int k) {
    Temperature novi(0,0);
    std::copy(temp.min_temp.begin(),temp.min_temp.end(),novi.min_temp.begin());
    std::copy(temp.max_temp.begin(),temp.max_temp.end(),novi.max_temp.begin());
    std::for_each(novi.min_temp.begin(),novi.min_temp.end(),std::bind(std::minus<int>(),std::placeholders::_1,k));
    std::for_each(novi.max_temp.begin(),novi.max_temp.end(),std::bind(std::minus<int>(),std::placeholders::_1,k));
    return novi;
}
inline Temperature operator +(int y,Temperature &temp) {
    return temp+y;
}
Temperature operator -(int k,Temperature &temp) {
    Temperature novi(0,0);
    int najmanja(*std::min_element(temp.min_temp.begin(),temp.min_temp.end(),std::less<int>())); 
    int najveca(*std::max_element(temp.max_temp.begin(),temp.max_temp.end(),std::greater<int>()));
    std::copy(temp.min_temp.begin(),temp.min_temp.end(),novi.min_temp.begin());
    std::copy(temp.max_temp.begin(),temp.max_temp.end(),novi.max_temp.begin());
    std::swap(novi.min_temp,novi.max_temp);
    std::for_each(novi.min_temp.begin(),novi.min_temp.end(),std::bind(std::minus<int>(),std::placeholders::_1,k));
    std::for_each(novi.max_temp.begin(),novi.max_temp.end(),std::bind(std::minus<int>(),std::placeholders::_1,k));
     
  if(std::count_if((novi.max_temp.begin())++,novi.max_temp.end(),std::bind(std::greater<int>(),std::placeholders::_1,najveca)) || std::count_if((novi.min_temp.begin())++,novi.min_temp.end(),std::bind(std::less<int>(),std::placeholders::_1,najmanja))) 
        throw std::logic_error("Ilegalna operacija");
    
     return novi;
}
Temperature Temperature::operator +=(int k) {
    return (*this+k);
}
Temperature Temperature::operator -=(int y) {
    return (*this-y);
}

int main ()
{
    std::cout<<"Unesite maksimalnu i minimalnu temperaturu: ";
    int m,n;
    std::cin>>m>>n;
    Temperature temp(m,n);
    std::cout<<"Unesite temperature za sedam dana: ";
    std::vector<std::pair<int,int>> v(7);
    std::fill(v.begin(),v.end(),std::make_pair(0,0));
    std::transform(v.begin(),v.end(),v.begin(),[&temp](std::pair<int,int> &par) {
        std::cin>>par.first>>par.second;
        try {
        temp.RegistrirajTemperature(std::make_pair(par.first,par.second));
        return par;
        }
        catch(std::range_error e) {
            std::cout<<e.what()<<" Molimo,ponovite unos: "<<std::endl;
        }
    return std::make_pair(0,0);
    });
    
    std::cout<<"Najniza temperatura je: "<<temp.DajMinimalnuTemperaturu()<<std::endl;
    std::cout<<temp;
	return 0;
}