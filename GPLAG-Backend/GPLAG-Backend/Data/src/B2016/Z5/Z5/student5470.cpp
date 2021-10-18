/B16/17 (Zadaća 5, Zadatak 5)
//Autotestovi by Berina Cocalic (mail: bcocalic1@etf.unsa.ba)
//Za autotestove se obracati *iskljucivo* osobi koja ih pise
#include <iostream>
#include <list>
#include <stdexcept>
#include <tuple>
#include <algorithm>
#include <functional>
#include <iterator>
#include <vector>

class Temperature
{
    std::list<int> vel,manj;
public:
    Temperature(int najm,int najv)
    {
        if(najm>najv) throw std::logic_error("Nekorektne temperature");
        vel.push_back(najv);
        manj.push_back(najm);
    }
    void RegistrirajTemperature(std::pair<int,int> p);
    void Brisi(){ vel.clear(),manj.clear();}
    void BrisiNegativneTemperature();
    int DajBrojRegistriranihTemperatura() const {return vel.size();}
    int DajMinimalnuTemperaturu()const {return manj.front();}
    int DajMaksimalnuTemperaturu()const {return vel.front();}
    int DajBrojTeperaturaVecihOd(int a)const {return std::count_if(vel.begin(),vel.end(),std::bind(std::greater<int>(),std::placeholders::_1,a))+std::count_if(manj.begin(),manj.end(),std::bind(std::greater<int>(),std::placeholders::_1,a));}
    int DajBrojTeperaturaManjihOd(int a)const {return std::count_if(vel.begin(),vel.end(),std::bind(std::less<int>(),std::placeholders::_1,a))+std::count_if(manj.begin(),manj.end(),std::bind(std::less<int>(),std::placeholders::_1,a));}
    bool operator! ()const{return !vel.size();}
    Temperature operator++();
    std::vector<int> operator*();
    std::vector<int> operator+();
    std::vector<int> operator-();
    const std::pair<int,int> operator[](const int &i);
    friend Temperature operator+(const Temperature &t1,int a);
    friend Temperature operator-(const Temperature &t1,int a);
    friend Temperature operator+(int a,const Temperature &t1);
    friend Temperature operator-(int a,const Temperature &t1);
    Temperature operator+=(int t)
    {
        *this=*this+t;
        return *this;
    }
    Temperature operator-=(int t)
    {
        *this=*this-t;
        return *this;
    }
    bool operator==(Temperature t){return std::equal(vel.begin(),vel.end(),t.vel.begin()) && std::equal(manj.begin(),manj.end(),t.manj.begin());}
    bool operator!=(Temperature t){return !std::equal(vel.begin(),vel.end(),t.vel.begin()) || !std::equal(manj.begin(),manj.end(),t.manj.begin());}
    friend std::ostream &operator <<(std::ostream &tok, const Temperature &t);
};
int main ()
{
    Temperature a(-5,100);
    for(int i=0;i<10;i++) 
        a.RegistrirajTemperature(std::pair<int,int>(i+1,i+50));
    a.BrisiNegativneTemperature();
    std::cout << a;
    return 0;
}
void Temperature::RegistrirajTemperature(std::pair<int,int> p)
{
    if(p.first<manj.front() || p.second>vel.front() || p.first>p.second) throw std::logic_error("Nekorektne temperature");
    vel.push_back(p.second);
    manj.push_back(p.first);
}
void Temperature::BrisiNegativneTemperature()
{
    auto static it1=vel.begin(),it2=manj.begin();
    if(it1!=vel.end())
    {
        if(*it1<0 || *it2<0)
        {
            vel.erase(it1);
            manj.erase(it2);
            it1=vel.begin();
            it2=manj.begin();
        }
        else 
            it1++,it2++;
        BrisiNegativneTemperature();
    }
}
Temperature Temperature::operator++()
{
    return *this;
}
std::vector<int> Temperature::operator*()
{
    std::vector<int> v(vel.size());
    std::transform(vel.begin(),vel.end(),manj.begin(),v.begin(),std::minus<int>());
    return v;
}
std::vector<int> Temperature::operator-()
{
    std::vector<int> v(vel.size());
    std::transform(manj.begin(),manj.end(),v.begin(),std::bind(std::minus<int>(),std::placeholders::_1,manj.front()));
    return v;
}
std::vector<int> Temperature::operator+()
{
    std::vector<int> v(vel.size());
    std::transform(vel.begin(),vel.end(),v.begin(),std::bind(std::minus<int>(),vel.front(),std::placeholders::_1));
    return v;
}
const std::pair<int,int> Temperature::operator[](const int &i)
{
    if(i>vel.size()) throw std::range_error("Neispravan indeks");
    auto it1=manj.begin();
    auto it2=vel.begin();
    std::advance(it1,i-1);
    std::advance(it2,i-1);
    return std::pair<int,int>(*it1,*it2);
}
Temperature operator+(const Temperature &t1,int a)
{
    Temperature t(t1);
    std::transform(t1.vel.begin(),t1.vel.end(),t.vel.begin(),std::bind(std::plus<int>(),std::placeholders::_1,a));
    std::transform(t1.manj.begin(),t1.manj.end(),t.manj.begin(),std::bind(std::plus<int>(),std::placeholders::_1,a));
    return t;
}
Temperature operator-(const Temperature &t1,int a)
{
    Temperature t(t1);
    std::transform(t1.vel.begin(),t1.vel.end(),t.vel.begin(),std::bind(std::minus<int>(),std::placeholders::_1,a));
    std::transform(t1.manj.begin(),t1.manj.end(),t.manj.begin(),std::bind(std::minus<int>(),std::placeholders::_1,a));
    return t;
}
Temperature operator+(int a,const Temperature &t1)
{
    Temperature t(t1);
    std::transform(t1.vel.begin(),t1.vel.end(),t.vel.begin(),std::bind(std::plus<int>(),std::placeholders::_1,a));
    std::transform(t1.manj.begin(),t1.manj.end(),t.manj.begin(),std::bind(std::plus<int>(),std::placeholders::_1,a));
    return t;
}
Temperature operator-(int a,const Temperature &t1)
{
    Temperature t(t1);
    std::transform(t1.vel.begin(),t1.vel.end(),t.manj.begin(),std::bind(std::minus<int>(),a,std::placeholders::_1));
    std::transform(t1.manj.begin(),t1.manj.end(),t.vel.begin(),std::bind(std::minus<int>(),a,std::placeholders::_1));
    return t;
}
std::ostream &operator <<(std::ostream &tok, const Temperature &t)
{
    std::ostream_iterator<int> it(tok," ");
    std::copy(t.manj.begin(),t.manj.end(),it);
    tok << "\n";
    std::copy(t.vel.begin(),t.vel.end(),it);
    return tok;
}