/B16/17 (Zadaća 5, Zadatak 5)
//Autotestovi by Berina Cocalic (mail: bcocalic1@etf.unsa.ba)
//Za autotestove se obracati *iskljucivo* osobi koja ih pise
#include <iostream>
#include <list>
#include <stdexcept>
#include <utility>
#include <algorithm>
#include <functional>
#include <vector>

class Temperature{
    std::list<int> min;
    std::list<int> max;
    public:
        
        //KONSTRUKTOR SA DVA PARAMETRA(temp po iznosu)
        Temperature(int minimalna,int maximalna);
        
        //METODE   
        void RegistrirajTemperature(std::pair<int,int>par);
        void BrisiSve();
        void BrisiNegativneTemperature();
        int DajBrojRegistriranihTemperatura() const { return min.size(); }
        
        int DajMinimalnuTemperaturu() const { 
            auto it(std::min_element(++min.begin(),min.end())); 
            if(it==min.end())throw std::logic_error("Nema registriranih temperatura");
            else return *(it);
        }
        
        int DajMaksimalnuTeperaturu() const { 
            auto it(std::max_element(++max.begin(),max.end())); 
            if(it==max.end())throw std::logic_error("Nema registriranih temperatura");
            else return *(it);
        }
        
        int DajBrojTeperaturaVecihOd(int temp) const { 
            int br1=std::count_if(++min.begin(),min.end(),std::bind(std::greater<int>(),std::placeholders::_1,temp));
            int br2=std::count_if(++max.begin(),max.end(),std::bind(std::greater<int>(),std::placeholders::_1,temp));
            if(br1+br2==0)throw std::logic_error("Nema registriranih temperatura");
            else return br1+br2;
        }    
        
        int DajBrojTeperaturaManjihOd(int temp) const { 
            int br1=std::count_if(++min.begin(),min.end(),std::bind(std::less<int>(),std::placeholders::_1,temp));
            int br2=std::count_if(++max.begin(),max.end(),std::bind(std::less<int>(),std::placeholders::_1,temp));
            if(br1+br2==0)throw std::logic_error("Nema registriranih temperatura");
            else return br1+br2;
        }    

        friend bool operator !(const Temperature &t);
        friend Temperature &operator++(Temperature &t);
        friend Temperature &operator--(Temperature &t);
        friend std::vector<int> operator*(const Temperature &t);
        friend std::vector<int> operator-(const Temperature &t);
        friend std::vector<int> operator+(const Temperature &t);
        std::pair<int,int> operator[](int indeks);
};

Temperature::Temperature(int minimalna,int maximalna){
    if(minimalna>maximalna)throw std::range_error("Nekorektne temperature");
    min.push_back(minimalna);
    max.push_back(maximalna);
}

void Temperature::RegistrirajTemperature(std::pair<int,int>par){
    if(par.first<*min.begin() || par.second > *max.begin() || par.first>par.second)throw std::range_error("Nekorektne temperature");
    min.push_back(par.first);
    max.push_back(par.second);
}

void Temperature::BrisiSve(){
    auto it1(min.begin()),it2(max.begin());
    while(it1!=min.end() && it2!=max.end()){
        it1=min.erase(it1);
        it2=max.erase(it2);
    }
}

void Temperature::BrisiNegativneTemperature(){
    auto it1(min.begin()),it2(max.begin());
    while(it1!=min.end() && it2!=max.end()){
        if(*it1<0 && *it2<0){
            it1=min.erase(it1);
            it2=max.erase(it2);
        }    
    }
}

bool operator !(const Temperature &t){
    if(t.min.size()>1)return false;
    else return true;
}

Temperature &operator++(Temperature &t){
    std::transform(++t.min.begin(),t.min.end(),++t.min.begin(),std::bind(std::plus<int>(),std::placeholders::_1,1));
    return t;
}

Temperature &operator--(Temperature &t){
    std::transform(++t.min.begin(),t.min.end(),++t.min.begin(),std::bind(std::minus<int>(),std::placeholders::_1,1));
    return t;
}

std::vector<int> operator*(const Temperature &t){
    std::vector<int> v(t.min.size()-1);
    std::transform(++t.min.begin(),t.min.end(),++t.max.begin(),v.begin(),std::bind(std::minus<int>(),std::placeholders::_1,std::placeholders::_2));
    return v;
}

std::vector<int> operator-(const Temperature &t){
    std::vector<int> v(t.max.size()-1);
    std::transform(++t.max.begin(),t.max.end(),v.begin(),std::bind(std::minus<int>(),*t.max.begin(),std::placeholders::_1));
    return v;
}

std::vector<int> operator+(const Temperature &t){
    std::vector<int> v(t.max.size()-1);
    std::transform(++t.min.begin(),t.min.end(),v.begin(),std::bind(std::minus<int>(),std::placeholders::_1,*t.min.begin()));
    return v;
}

std::pair<int,int> Temperature::operator[](int indeks){
    if(indeks<1 || indeks>min.size()) throw std::range_error("Neispravan indeks");
    std::vector<int> v1(min.size()),v2(max.size());
    std::copy(min.begin(),min.end(),v1.begin());
    std::copy(max.begin(),max.end(),v2.begin());
    return std::make_pair(v1[indeks],v2[indeks]);
}

int main ()
{
    Temperature t(12,36);
    t.RegistrirajTemperature({20,30});
    t.RegistrirajTemperature({23,34});
    t.RegistrirajTemperature({18,28});
    t.RegistrirajTemperature({16,30});
    t.RegistrirajTemperature({15,31});
    
    std::pair<int,int> par=t[3];
	return 0;
}