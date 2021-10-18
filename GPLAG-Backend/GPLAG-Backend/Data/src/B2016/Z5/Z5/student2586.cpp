/B16/17 (Zadaća 5, Zadatak 5)
//Autotestovi by Berina Cocalic (mail: bcocalic1@etf.unsa.ba)
//Za autotestove se obracati *iskljucivo* osobi koja ih pise

#include <list>
#include <iostream>
#include <stdexcept>
#include <utility>
#include <algorithm>
#include <functional>
#include <iterator>

class Temperature
{
    int min_t, max_t;
    std::list<int> min, max;
public:
    Temperature(int x, int y) : min_t(x), max_t(y)
    {
        if(max_t < min_t)
            throw std::range_error("Nekorektne temperature");
    }
    
    void RegistrirajTemperature(const std::pair<int, int>& t);
    void BrisiSve()
    {
        min.resize(0);
        max.resize(0);
    }
    
    void BrisiNegativneTemperature();
    int DajBrojRegistriranihTemperatura() const
    {
        return min.size();
    }
    int DajMinimalnuTemperaturu() const
    {
        if(DajBrojRegistriranihTemperatura() == 0)
            throw std::logic_error("Nema registriranih temperatura");
        return *std::min_element(min.begin(), min.end());
    }
    
    int DajMaksimalnuTemperaturu() const
    {
        if(DajBrojRegistriranihTemperatura() == 0)
            throw std::logic_error("Nema registriranih temperatura");
        return *std::max_element(min.begin(), min.end());
    }
    
    bool operator!()const
    {
        return DajBrojRegistriranihTemperatura() == 0;
    }
    
    Temperature& operator++();
    Temperature operator++(int);
    
    Temperature& operator--();
    Temperature operator--(int);
    
    std::vector<int> operator*() const;
    std::vector<int> operator-() const;
    std::vector<int> operator+() const;
    
    std::pair<int, int> operator [] (int i) const;
    
    Temperature operator +(int) const;
    friend Temperature operator +(int, const Temperature&);
    
    Temperature operator -(int) const;
    friend Temperature operator -(int, const Temperature&);
    
    
    Temperature& operator+=(int x);

    
    Temperature& operator-=(int x);
 
    bool operator ==(const Temperature& t)
    {
        return min_t == t.min_t && max_t == t.max_t && min == t.min && max == t.max;
    }
    
    bool operator !=(const Temperature& t)
    {
        return !(*this == t);
    }
    
    friend std::ostream& operator<< (std::ostream&, const Temperature& t);
    
    int DajBrojTeperaturaVecihOd(int t) const;
    int DajBrojTeperaturaManjihOd(int t) const;
    
};


int Temperature::DajBrojTeperaturaVecihOd(int t) const
{
     if(DajBrojRegistriranihTemperatura() == 0)
            throw std::logic_error("Nema registriranih temperatura");
    return std::count_if(min.begin(), min.end(), std::bind(std::greater<int>(), std::placeholders::_1, t)) + 
        std::count_if(max.begin(), max.end(), std::bind(std::greater<int>(), std::placeholders::_1, t));
}

int Temperature::DajBrojTeperaturaManjihOd(int t) const
{
     if(DajBrojRegistriranihTemperatura() == 0)
            throw std::logic_error("Nema registriranih temperatura");
    return std::count_if(min.begin(), min.end(), std::bind(std::less<int>(), std::placeholders::_1, t)) + 
        std::count_if(max.begin(), max.end(), std::bind(std::less<int>(), std::placeholders::_1, t));
}

std::ostream& operator<< (std::ostream& os, const Temperature& t)
{
    std::copy(t.min.begin(), t.min.end(), std::ostream_iterator<int>(os, " ") );
    os << '\n';
    std::copy(t.max.begin(), t.max.end(), std::ostream_iterator<int>(os, " ") );
    os << '\n';
    return os;
}

Temperature operator -(int x, const Temperature& t)
{
    auto t1 = t;
    std::transform(t.min.begin(), t.min.end(), t1.max.begin(), std::bind(std::minus<int>(), std::placeholders::_1, x));
    if(std::any_of(t1.min.begin(), t1.min.end(), std::bind(std::less<int>(), std::placeholders::_1, t1.min_t)))
        throw std::logic_error("Prekoracen  dozvoljeni  opseg  temperatura");
    std::transform(t.max.begin(), t.max.end(), t1.min.begin(), std::bind(std::minus<int>(), std::placeholders::_1, x));
    if(std::any_of(t1.max.begin(), t1.max.end(), std::bind(std::greater<int>(), std::placeholders::_1, t1.max_t)))
        throw std::logic_error("Prekoracen  dozvoljeni  opseg  temperatura");
    return t1;
}


Temperature operator +(int b, const Temperature& p)
{
    return p + b;
}

Temperature& Temperature::operator-=(int x)
{
   std::transform(min.begin(), min.end(), min.begin(), std::bind(std::minus<int>(),std::placeholders::_1, x));
   if(std::any_of(min.begin(), min.end(), std::bind(std::less<int>(), std::placeholders::_1, min_t)))
        throw std::logic_error("Prekoracen  dozvoljeni  opseg  temperatura");
    std::transform(max.begin(), max.end(), max.begin(), std::bind(std::minus<int>(), std::placeholders::_1, x));
    return *this;
}

Temperature Temperature::operator -(int br) const
{
   auto p = *this;
   p -= br;
    return p;
}


Temperature& Temperature::operator+=(int x)
{
   std::transform(max.begin(), max.end(), max.begin(), std::bind(std::plus<int>(), std::placeholders::_1, x));
   if(std::any_of(max.begin(), max.end(), std::bind(std::greater<int>(), std::placeholders::_1, max_t)))
        throw std::logic_error("Prekoracen  dozvoljeni  opseg  temperatura");
    std::transform(min.begin(), min.end(), min.begin(), std::bind(std::plus<int>(), std::placeholders::_1, x));
    return *this;
}


Temperature Temperature::operator +(int br) const
{
   auto p = *this;
    p += br;
    return p;
}

std::pair<int, int> Temperature::operator[] (int i) const
{
    if( i < 1 || i > max.size())
        throw std::range_error("Neispravan indeks");
    auto it1 = min.begin();
    std::advance(it1, i - 1);
    auto it2 = max.begin();
    std::advance(it2, i - 1);
    return std::make_pair(*it1, *it2);
}

std::vector<int> Temperature::operator-() const
{
    std::vector<int> v (max.size());
    std::transform(min.begin(), min.end(),v.begin(), std::bind(std::minus<int>(), std::placeholders::_1, min_t) );
    return v;
}

std::vector<int> Temperature::operator+() const
{
    std::vector<int> v (max.size());
    std::transform(max.begin(), max.end(),v.begin(), std::bind(std::minus<int>(), max_t, std::placeholders::_1) );
    return v;
}

std::vector<int> Temperature::operator*() const
{
    std::vector<int> v (max.size());
    std::transform(max.begin(), max.end(), min.begin(),v.begin(), std::minus<int>());
    return v;
}

Temperature Temperature::operator--(int)
{
    Temperature p(*this);
    --p;
    return p;
}

Temperature Temperature::operator++(int)
{
    Temperature p(*this);
    ++p;
    return p;
}

Temperature& Temperature::operator--()
{
    std::transform(max.begin(), max.end(), max.begin(), std::bind(std::minus<int>(), std::placeholders::_1, 1));
    std::vector<int> v (max.size());
    std::transform(max.begin(), max.end(), min.begin(),v.begin(), std::less<int>());
    if(std::find(v.begin(), v.end(), 1) != v.end())
        throw std::logic_error("Ilegalna operacija");
    return *this;
}

Temperature& Temperature::operator++()
{
    std::transform(min.begin(), min.end(), min.begin(), std::bind(std::plus<int>(), std::placeholders::_1, 1));
    std::vector<int> v (min.size());
    std::transform(min.begin(), min.end(), max.begin(),v.begin(), std::greater<int>());
    if(std::find(v.begin(), v.end(), 1) != v.end())
        throw std::logic_error("Ilegalna operacija");
    return *this;
}

void Temperature::BrisiNegativneTemperature()
{
    static auto it1 = min.begin();
    static auto it2 = max.begin();
    
    if(it1 == min.end()){
        it1 = min.begin();
        it2 = max.begin();
        return;
    }
    if(*it1  < 0 && *it2 < 0)
    {
        it1 = min.erase(it1);
        it2 = max.erase(it2);
        BrisiNegativneTemperature();
    }
    else
    {
        it1++;
        it2++;
        BrisiNegativneTemperature();
    }

}

void Temperature::RegistrirajTemperature(const std::pair<int, int>& t)
{
    if(t.first < min_t || t.first > max_t || t.first > t.second)
        throw std::range_error("Nekorektne temperature");
        
    if(t.second < min_t || t.second > max_t)
        throw std::range_error("Nekorektne temperature");
    
    min.push_back(t.first);
    max.push_back(t.second);
    
}

int main ()
{
   
  try {
    Temperature t(-30, 30);
    t.RegistrirajTemperature(std::make_pair(0, 10));
    t.RegistrirajTemperature(std::make_pair(2, 10));
    t.RegistrirajTemperature(std::make_pair(1, 10));
    t.RegistrirajTemperature(std::make_pair(-5, 15));
    t.RegistrirajTemperature(std::make_pair(-4, 14));
    t.RegistrirajTemperature(std::make_pair(1, 12));
    t.RegistrirajTemperature(std::make_pair(2, 10));
    t.RegistrirajTemperature(std::make_pair(0, 7));
    t.RegistrirajTemperature(std::make_pair(2, 7));

    std::cout <<  t.DajBrojRegistriranihTemperatura() << std::endl;
    std::cout <<  t.DajMinimalnuTemperaturu() << std::endl;
    std::cout <<  t.DajMaksimalnuTemperaturu() << std::endl;
    std::cout <<  t.DajBrojTeperaturaVecihOd(10) << std::endl;
    std::cout <<  t.DajBrojTeperaturaManjihOd(2) << std::endl;
    std::cout << "Temperature: " << std::endl;
    std::cout << t;
    t++;
    ++t;
    std::cout << std::endl << std::endl;
    std::cout << "Temperature poslije t++ i ++t: " << std::endl;
    std::cout << t;
    --t;
    t--;
    std::cout << std::endl << std::endl;
    std::cout << "Temperature poslijee t-- i --t: " << std::endl;
    std::cout << t;
    std::cout << std::endl << "Razlika izmedu minimalnih i maximalnih temperatura: " << std::endl;
    for(auto x : *t)
      std::cout << x << " ";
    std::cout << std::endl << std::endl << "Razlika izmedji minilanih i dozvoljene minimalne temperature: " << std::endl;
    for(auto x : -t)
      std::cout << x << " ";
    std::cout << std::endl << std::endl << "Razlika izmedji maximalnih i dozvoljene maximalne temperature: " << std::endl;
    for(auto x : +t)
      std::cout << x << " ";
    Temperature novi = t + 3;
    std::cout << "\n\n" << novi << std::endl << std::endl;
    std::cout << "Da li su t1 i novi razliciti: " << (t != novi) << std::endl;
    novi = novi - 3;
    std::cout << "Da li su t1 i novi isti nakon -3: " << (t == novi) << std::endl;
    novi.BrisiSve();
    std::cout << !novi << std::endl << std::endl;
    std::cout << t << std::endl;
    Temperature t1 = -10 - t;
    std::cout << t1;
    t1 += 3;
    std::cout << std::endl << t1;
    auto p = t1[5];
    std::cout << std::endl << "Peta temperatura je: " << p.first << " " << p.second;
  }

  catch(std::logic_error e) {
    std::cout << e.what();
  }
  return 0;
}