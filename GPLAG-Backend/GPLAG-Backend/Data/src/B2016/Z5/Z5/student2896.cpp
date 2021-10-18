/B16/17 (Zadaća 5, Zadatak 5)
//Autotestovi by Berina Cocalic (mail: bcocalic1@etf.unsa.ba)
//Za autotestove se obracati *iskljucivo* osobi koja ih pise
#include <iostream>
#include <list>
#include <utility>
#include <stdexcept>
#include <algorithm>
#include <functional>

class Temperature
{
    private:
    std::list<int> mintemperature;
    std::list<int> maxtemperature;
    int dozvoljenamin;
    int dozvoljenamax;
    public:
    Temperature(int min, int max)
    {
        if(min > max) throw std::range_error("Nekorektne temperature");
        dozvoljenamax = max;
        dozvoljenamin = min;
        mintemperature = std::list<int>{};
        maxtemperature = std::list<int>{};
    }
    void RegistrirajTemperature(std::pair<int, int> par);
    void BrisiSve();
    void BrisiNegativneTemperature();
    int DajBrojRegistriranihTemperatura() const;
    int DajMinimalnuTemperaturu() const;
    int DajMaksimalnuTemperaturu() const;
    int DajBrojTemperaturaVecihOd(int) const;
    int DajBrojTemperaturaManjihOd(int) const;
    friend bool operator ! (const Temperature &t);
    friend Temperature &operator ++ (Temperature &t);
    friend Temperature &operator -- (Temperature &t);
    friend Temperature operator ++ (Temperature &t, int);
    friend Temperature operator -- (Temperature &t, int);
};

Temperature &operator ++ (Temperature &t)
{
    int maks;
    maks = *std::max_element(t.mintemperature.begin(), t.mintemperature.end());
    if(maks == t.dozvoljenamax) throw std::logic_error("Ilegalna operacija");
    std::transform(t.mintemperature.begin(),t.mintemperature.end(),t.mintemperature.begin(),std::bind(std::plus<int>(),std::placeholders::_1,1));
    return t;
}

Temperature operator ++ (Temperature &t, int)
{
    Temperature t2 = t;
    ++t;
    return t2;
}

Temperature &operator -- (Temperature &t)
{
    int min;
    min = *std::min_element(t.maxtemperature.begin(), t.maxtemperature.end());
    if(min == t.dozvoljenamin) throw std::logic_error("Ilegalna operacija");
    std::transform(t.maxtemperature.begin(), t.maxtemperature.end(), t.maxtemperature.begin(), std::bind(std::minus<int>(),std::placeholders::_1,1));
    return t;
}

Temperature operator -- (Temperature &t, int)
{
    Temperature t2 = t;
    ++t;
    return t2;
}

bool operator ! (const Temperature &t)
{
    if(t.mintemperature.size() == 0) return true;
    return false;
}

int Temperature::DajBrojTemperaturaManjihOd(int a) const
{
    if(mintemperature.size() == 0) throw std::logic_error("Nema registriranih temperatura");
    int br = std::count_if(mintemperature.begin(), mintemperature.end(), std::bind(std::less<int>(), std::placeholders::_1, a));
    return br;
}

int Temperature::DajBrojTemperaturaVecihOd(int a) const
{
    if(maxtemperature.size() == 0) throw std::logic_error("Nema registriranih temperatura");
    int br =  std::count_if(maxtemperature.begin(), maxtemperature.end(), std::bind(std::greater<int>(), std::placeholders::_1 , a));
    return br;
}

int Temperature::DajMaksimalnuTemperaturu() const
{
    if(maxtemperature.size() == 0) throw std::logic_error("Nema registriranih temperatura");
    auto it = std::max_element(maxtemperature.begin(), maxtemperature.end());
    return *it;
}

int Temperature::DajMinimalnuTemperaturu() const
{
    if(mintemperature.size() == 0) throw std::logic_error("Nema registriranih temperatura");
    auto it = std::min_element(mintemperature.begin(), mintemperature.end());
    return *it;
}

int Temperature::DajBrojRegistriranihTemperatura() const
{
    return mintemperature.size();
}

void Temperature::BrisiNegativneTemperature()
{
    
}

void Temperature::BrisiSve()
{
    mintemperature = std::list<int> {};
    maxtemperature = std::list<int> {};
}

void Temperature::RegistrirajTemperature(std::pair<int,int> par)
{
    if(par.first < dozvoljenamin || par.second > dozvoljenamax) throw std::range_error("Nekorektne temperature");
    if(par.first > par.second) throw std::range_error("Nekorektne temperature");
    mintemperature.push_back(par.first);
    maxtemperature.push_back(par.second);
}


int main ()
{
   
	return 0;
}