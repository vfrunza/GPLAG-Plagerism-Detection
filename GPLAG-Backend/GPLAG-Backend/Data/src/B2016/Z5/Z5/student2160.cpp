/B16/17 (Zadaća 5, Zadatak 5)
//Autotestovi by Berina Cocalic (mail: bcocalic1@etf.unsa.ba)
//Za autotestove se obracati *iskljucivo* osobi koja ih pise
#include <iostream>
#include <algorithm>
#include <stdexcept>
#include <list>
#include <utility>
#include <functional>
#include <iterator>
#include <vector>
class Temperature
{
    std::list<int> min, max;
    int MIN, MAX;
public:
    explicit Temperature(int mini, int maxi) : MIN(mini), MAX(maxi)
    { 
        if(mini > maxi) 
            throw std::range_error("Nekorektne temperature");
    }
    //M E T O D E
    void RegistrirajTemperature(std::pair<int, int> dnevne);
    void BrisiSve() { min.clear(); max.clear(); }
    void BrisiNegativneTemperature();
    int DajBrojRegistriranihTemperatura();
    int DajMinimalnuTemperaturu() { return MIN; }
    int DajMaksimalnuTemperaturu() { return MAX; }
    int DajBrojTemperaturaVecihOd(int a) { return std::count_if(max.begin(), max.end(), std::bind(std::greater<int>(), std::placeholders::_1, a)); }
    int DajBrojTemperaturaManjihOd(int a) { return std::count_if(min.begin(), min.end(), std::bind(std::less<int>(),  std::placeholders::_1,a)); }
    //O P E R A T O R I
    bool operator ! () { if(min.size() == 0 && max.size() == 0) return true; return false; }
    Temperature &operator ++ () { std::transform(min.begin(), min.end(), min.begin(), std::bind(std::plus<int>(), 1, std::placeholders::_1)); return *this; }
    Temperature operator ++ (int) { return ++*this; }
    Temperature &operator -- ()  { std::transform(max.begin(), max.end(), max.begin(), std::bind(std::minus<int>(), 1, std::placeholders::_1)); return *this;}
    Temperature operator -- (int) { return --*this; }
    friend std::vector<int> operator * (const Temperature &t);
    friend std::vector<int> operator + (const Temperature &t);
    friend std::vector<int> operator - (const Temperature &t);
    std::pair<int, int> operator [] (int i) const;
    Temperature operator + (int x) 
    {
        std::transform(min.begin(), min.end(), min.begin(), std::bind(std::plus<int>(), x, std::placeholders::_1));
        std::transform(max.begin(), max.end(), max.begin(), std::bind(std::plus<int>(), x, std::placeholders::_1));
        return *this;
    }
    Temperature operator - (int x)
    {
        std::transform(min.begin(), min.end(), min.begin(), std::bind(std::minus<int>(), std::placeholders::_1, x));
        std::transform(max.begin(), max.end(), max.begin(), std::bind(std::minus<int>(), std::placeholders::_1, x));
        return *this;
    }
    friend Temperature operator + (int x, Temperature &t) { return t + x; }
    friend Temperature operator - (int x, Temperature t);
    friend Temperature operator += (Temperature &t, int x)
    {
        t = t + x;
        return t;
    }
    friend Temperature operator -= (Temperature &t, int x)
    {
        t = t - x;
        return t;
    }
    friend bool operator == (const Temperature &t1, const Temperature &t2)
    {
        if(t1.min.size() != t2.min.size() || t1.max.size() != t2.max.size() || t1.MIN != t2.MIN 
            || t1.MAX != t2.MAX)
            return false;
            
        return (std::equal(t1.min.begin(), t1.min.end(), t2.min.begin()) && std::equal(t1.max.begin(), t1.max.end(), t2.max.begin()));
    }
    friend bool operator != (const Temperature &t1, const Temperature &t2)
    {
        return !(t1 == t2);
    }
    friend std::ostream &operator << (std::ostream &tok, const Temperature &t);
};
void Temperature::RegistrirajTemperature(std::pair<int, int> dnevne)
{
    if(dnevne.first < MIN || dnevne.second > MAX || dnevne.first > dnevne.second)
        throw std::range_error("Nekorektne temperature");
        
    min.push_back(dnevne.first);
    max.push_back(dnevne.second);
}
void Temperature::BrisiNegativneTemperature()
{
    auto i1 = std::find_if(min.begin(), min.end(), std::bind(std::less<int>(), 0, std::placeholders::_1));
    if(i1 == min.end())
        return;
    auto i2 = std::find_if(max.begin(), max.end(), std::bind(std::less<int>(), 0, std::placeholders::_1));
    if(i2 == max.end())
        return;
    int a = std::distance(min.begin(), i1);
    int b = std::distance(max.begin(), i2);
    
    if(a == b)
    {
        min.erase(i1);
        max.erase(i2);
    }
    
    auto i3 = std::find_if(min.begin(), min.end(), std::bind(std::less<int>(), 0, std::placeholders::_1));
    if(i3 == min.end()) return;
    auto i4 = std::find_if(max.begin(), max.end(), std::bind(std::less<int>(), 0, std::placeholders::_1));
    if(i4 == max.end()) return;
    
    BrisiNegativneTemperature();
}
int Temperature::DajBrojRegistriranihTemperatura()
{
    if(min.size() == 0 && max.size() == 0)
        throw std::logic_error("Nema registriranih temperatura");
        
    return min.size();
}
std::vector<int> operator * (const Temperature &t)
{
    std::vector<int> vek(t.min.size());
    std::transform(t.max.begin(), t.max.end(), t.min.begin(), vek.begin(), std::minus<int>());
    return vek;
}
std::vector<int> operator - (const Temperature &t)
{
    std::vector<int> vek(t.min.size());
    std::transform(t.min.begin(), t.min.end(), vek.begin(), std::bind(std::minus<int>(), t.MIN, std::placeholders::_1));
    return vek;
}
std::vector<int> operator + (const Temperature &t)
{
    std::vector<int> vek(t.max.size());
    std::transform(t.max.begin(), t.max.end(), vek.begin(), std::bind(std::minus<int>(), t.MAX, std::placeholders::_1));
    return vek;
}
Temperature operator - (int x, Temperature t) 
{
    std::list<int> l1 = t.min;
    std::list<int> l2 = t.max;
    std::transform(t.min.begin(), t.min.end(), t.min.begin(), std::bind(std::minus<int>(), x, std::placeholders::_1));
    std::transform(t.max.begin(), t.max.end(), t.max.begin(), std::bind(std::minus<int>(), x, std::placeholders::_1));
    std::swap(t.min, t.max);
    int a = t.DajBrojTemperaturaManjihOd(t.MIN);
    int b = t.DajBrojTemperaturaVecihOd(t.MAX);
    if(a != 0 || b != 0)
    {
        t.min = l1;
        t.max = l2;
        std::swap(t.max, t.min);
        throw std::logic_error("Prekoracen dozvoljeni opseg temperatura");
    }
    return t;
}
std::pair<int, int> Temperature :: operator [] (int i) const
{
    if(i <= 0 || i > min.size())
        throw std::range_error("Neispravan indeks");
    std::pair<int, int> temp;
    std::vector<int> v1(min.size()), v2(max.size());
    std::copy(min.begin(), min.end(), v1.begin());
    std::copy(max.begin(), max.end(), v2.begin());
    temp.first = v1.at(i - 1);
    temp.second = v2.at(i - 1);
    return temp;
}
std::ostream &operator << (std::ostream &tok, const Temperature &t)
{
    std::copy(t.min.begin(), t.min.end(), std::ostream_iterator<int>(tok, " "));
    tok << "\n";
    std::copy(t.max.begin(), t.max.end(), std::ostream_iterator<int>(tok, " "));
    return tok;
}
int main ()
{
	return 0;
}