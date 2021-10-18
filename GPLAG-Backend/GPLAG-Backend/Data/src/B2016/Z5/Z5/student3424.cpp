/B16/17 (Zadaća 5, Zadatak 5)
//Autotestovi by Berina Cocalic (mail: bcocalic1@etf.unsa.ba)
//Za autotestove se obracati *iskljucivo* osobi koja ih pise
#include <iostream>
#include <list>
#include <stdexcept>
#include <algorithm>
#include <functional>

class Temperature
{
    int max, min;
    std::list<int> max_temp, min_temp;
public:
    explicit Temperature(int max, int min);
    
    void RegistrirajTemperature(std::pair<int,int> min_max);
    void BrisiSve();
    void BrisiNegativneTemperature();
    
    int DajBrojRegistriranihTemperatura() const;
    int DajMinimalnuTemperaturu() const;
    int DajMaksimalnuTemperaturu() const;
    int DajBrojTemperaturaVecihOd(int x) const;
    
    bool operator ! () { return max_temp.empty(); }
    bool operator == (const Temperature &t);
    bool operator != (const Temperature &t);
    
    friend Temperature operator ++ (Temperature &t);
    friend Temperature operator -- (Temperature &t);
    friend Temperature operator ++ (Temperature &t, int);
    friend Temperature operator -- (Temperature &t, int);
    
    /*friend std::vector<int> */

    
    friend std::vector<int> operator + (const Temperature &t1, const Temperature &t2);
    friend std::vector<int> operator - (const Temperature &t1, const Temperature &t2);
    
    std::pair<int,int> operator [](int i);
    
    friend std::ostream &operator << (std::ostream &tok, const Temperature &t);
};

Temperature::Temperature(int max, int min) : max(max), min(min)
{
    if(max < min) throw std::range_error("Nekorektne temperature");
}

void Temperature::RegistrirajTemperature(std::pair<int,int> min_max)
{
    if(min_max.first < min || min_max.second > max || min_max.first > min_max.second)
      throw std::range_error("Nekorektne temperature");
    
    min_temp.push_back(min_max.first);
    max_temp.push_back(min_max.second);
}

void Temperature::BrisiSve()
{
    min_temp.erase(min_temp.begin(), min_temp.end());
    max_temp.erase(max_temp.begin(), max_temp.end());
}


int Temperature::DajBrojRegistriranihTemperatura() const 
{
    if(max_temp.empty())
      throw std::logic_error("Nema registriranih temperatura");
    return max_temp.size();
}

int Temperature::DajMinimalnuTemperaturu() const 
{ 
     if(min_temp.empty())
      throw std::logic_error("Nema registriranih temperatura");
    return *std::min_element(min_temp.begin(), min_temp.end()); 
}

int Temperature::DajMaksimalnuTemperaturu() const 
{
     if(max_temp.empty())
      throw std::logic_error("Nema registriranih temperatura");
    return *std::max_element(max_temp.begin(), max_temp.end()); 
}

int Temperature::DajBrojTemperaturaVecihOd(int x) const 
{
    if(max_temp.empty())
      throw std::logic_error("Nema registriranih temperatura");
    
    return std::count_if(max_temp.begin(), max_temp.end(), [x](int y){ return x > y ;}) +
           std::count_if(min_temp.begin(), min_temp.end(), [x](int y){ return x > y ;});
}

int main ()
{
	return 0;
}