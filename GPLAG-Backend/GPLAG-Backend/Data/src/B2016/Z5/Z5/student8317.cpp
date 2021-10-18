/B16/17 (Zadaća 5, Zadatak 5)
//Autotestovi by Berina Cocalic (mail: bcocalic1@etf.unsa.ba)
//Za autotestove se obracati *iskljucivo* osobi koja ih pise
#include <iostream>
#include <list>
#include <stdexcept>
#include <utility>
#include <algorithm>
#include <iterator>
#include <functional>

class Temperature{
    private:
        std::list<int> min;
        std::list<int> max;
        int h,l;
    public:
        Temperature(int mini, int maxi);
        void RegistrirajTemperature(std::pair<int,int> temp);
        void BrisiSve();
        int DajBrojRegistriranihTemperatura() const {return min.size();}
        friend std::ostream& operator<<(std::ostream& tok, const Temperature &t);
        void BrisiSveNegativneTemperature();
        int DajMinimalnuTemperaturu()const;
        int DajMaksimalnuTemperaturu() const;
        int DajBrojTemperaturaVecihOd(int n) const;
        int DajBrojTemperaturaManjihOd(int n) const;
        bool operator!()const {return min.size()==0;}
        Temperature &operator++();
        Temperature &operator--();
        Temperature operator ++(int);
        Temperature operator --(int);
        friend bool operator==(const Temperature &t1, const Temperature &t2);
        friend bool operator!=(const Temperature &t1, const Temperature &t2);
        std::pair<int,int> operator[](int indeks);
};
std::pair<int,int> Temperature::operator[](int indeks){
    if(indeks<1 || indeks>DajBrojRegistriranihTemperatura())
        throw std::range_error("Neispravan indeks");
    auto minn=min.begin();
    auto maxx=max.begin();
    std::advance(minn,indeks-1);
    std::advance(maxx,indeks-1);
    return {*minn,*maxx};
}
bool operator ==(const Temperature &t1, const Temperature &t2){
    if(t1.DajBrojRegistriranihTemperatura()!=t2.DajBrojRegistriranihTemperatura())
        return false;
    return t1.h==t2.h && t1.l==t2.l && std::equal(t1.min.begin(),t1.min.end(),t2.min.begin()) && std::equal(t1.max.begin(),t1.max.end(),t2.max.begin());
}
bool operator !=(const Temperature &t1, const Temperature &t2){
    return !(t1==t2);
}
Temperature& Temperature::operator++(){
    auto it=std::find_if(min.begin(),min.end(),std::bind(std::greater<int>(), std::placeholders::_1,h-1));
    if(it!=min.end())
        throw std::logic_error("Ilegalna operacija");
    std::transform(min.begin(),min.end(),min.begin(),std::bind(std::plus<int>(),std::placeholders::_1,1));
    return *this;
};
Temperature& Temperature::operator--(){
    auto it=std::find_if(max.begin(),max.end(),std::bind(std::less<int>(), std::placeholders::_1,l+1));
    if(it!=max.end())
        throw std::logic_error("Ilegalna operacija");
    std::transform(max.begin(),max.end(),max.begin(),std::bind(std::minus<int>(),std::placeholders::_1,1));
    return *this;
}
Temperature::Temperature(int mini, int maxi){
    if(mini>maxi)
        throw std::range_error("Nekorektne temperature");
    h=maxi; l=mini;
}
void Temperature::RegistrirajTemperature(std::pair<int,int> temp){
    if(temp.first>temp.second || temp.first<l || temp.second>h)
        throw std::range_error("Nekorektne temperature");
    min.push_back(temp.first);
    max.push_back(temp.second);
}
void Temperature::BrisiSve() {
    if(min.size()==0) return;
    else{
        auto it1=min.begin(),it2=max.begin();
        it2=max.erase(it2);
        it1=min.erase(it1);
        BrisiSve();
    }
}
std::ostream& operator<<(std::ostream& tok, const Temperature &t){
    std::copy(t.min.begin(),t.min.end(),std::ostream_iterator<int>(tok," "));
    tok<<std::endl;
    std::copy(t.max.begin(),t.max.end(),std::ostream_iterator<int>(tok," "));
    return tok;
}
void Temperature::BrisiSveNegativneTemperature(){
    auto it=std::find_if(max.begin(),max.end(),std::bind(std::less<int>(),std::placeholders::_1,0));
    if(it==max.end()) return;
    auto it2=min.begin();
    std::advance(it2,std::distance(max.begin(),it));
    it=max.erase(it);
    it2=min.erase(it2);
    BrisiSveNegativneTemperature();
}
int Temperature::DajMinimalnuTemperaturu() const {
    if(min.size()==0)
        throw std::logic_error("Nema registriranih temperatura");
    return *std::min_element(min.begin(),min.end());
}
int Temperature::DajMaksimalnuTemperaturu()const{
    if(max.size()==0)
        throw std::logic_error("Nema registriranih temperatura");
    return *std::max_element(max.begin(),max.end());
}
int Temperature::DajBrojTemperaturaManjihOd(int n) const {
    if(min.size()==0)
        throw std::logic_error("Nema registriranih temperatura");
    return std::count_if(min.begin(),min.end(),std::bind(std::less<int>(), std::placeholders::_1,n));
}
int Temperature::DajBrojTemperaturaVecihOd(int n) const {
    if(max.size()==0)
        throw std::logic_error("Nema registriranih temperatura");
    return std::count_if(max.begin(),max.end(),std::bind(std::greater<int>(),std::placeholders::_1,n));
}
Temperature Temperature::operator ++(int){
    Temperature pom(*this);
    ++(*this);
    return pom;
}
Temperature Temperature::operator --(int){
    Temperature pom(*this);
    ++(*this);
    return pom;
}
int main ()
{
    Temperature t({-25,30});
    t.RegistrirajTemperature({-24,-24});
    t.RegistrirajTemperature({-20,-2});
    t.RegistrirajTemperature({1,18});
    t.RegistrirajTemperature({-2,-1});
    t.RegistrirajTemperature({8,18});
    std::cout<<t++;
    std::cout<<std::endl;
    
    std::cout<<t[2].first<<" "<<t[2].second;
    
	return 0;
}