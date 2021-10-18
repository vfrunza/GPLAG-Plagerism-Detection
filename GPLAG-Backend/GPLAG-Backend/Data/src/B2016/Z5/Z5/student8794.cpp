/B16/17 (Zadaća 5, Zadatak 5)
//Autotestovi by Berina Cocalic (mail: bcocalic1@etf.unsa.ba)
//Za autotestove se obracati *iskljucivo* osobi koja ih pise
#include <iostream>
#include <algorithm>
#include <list>
#include <utility>
#include <functional>
#include <iterator>
#include <vector>

using namespace std::placeholders;

class Temperatura
{
    int min,max;
    std::list<int> temp_min;
    std::list<int> temp_max;
    std::vector<bool> temp_jednaki;
    void Test_jed () {
        temp_jednaki.resize(temp_max.size());
        std::transform(temp_min.begin(),temp_min.end(),temp_max.begin(),temp_jednaki.begin(),[](int t1,int t2) {
            return t1 >= t2;
        });
    }
public:
    Temperatura (int min, int max) {
        if ( min > max) throw std::range_error ("Nekorektne temperature");
        Temperatura::min = min;
        Temperatura::max = max;
    }
    void RegistrirajTemperature(std::pair<int,int> temp) {
        if (temp.first > temp.second or temp.first < min or temp.second > max)
            throw std::range_error ("Nekorektne temperature");
        temp_max.push_back(temp.second);
        temp_min.push_back(temp.first);
    }
    void BrisiSve () {
        temp_max.clear();
        temp_min.clear();
    }
    void BrisiNegativneTemperature ();
    int DajBrojRegistriranihTemperatura () const {
        return temp_max.size();
    }
    int DajMinimalnuTemperaturu() const{
        if (temp_max.empty()) throw std::logic_error ("Nema registriranih temperatura");
        return *std::min_element(temp_min.begin(),temp_min.end(),std::less<int>());
    }
    int DajMaksimalnuTeperaturu() const{
        if (temp_max.empty()) throw std::logic_error ("Nema registriranih temperatura");
        return *std::max_element(temp_max.begin(),temp_max.end(),std::greater<int>());
    }
    int DajBrojTeperaturaManjihOd (int t) const{
        if (temp_max.empty()) throw std::logic_error ("Nema registriranih temperatura");
        return std::count_if (temp_min.begin(),temp_min.end(),std::bind(std::less<int>(),t,_1));
    }
    int DajBrojTeperaturaVecihOd (int t) const{
        if (temp_max.empty()) throw std::logic_error ("Nema registriranih temperatura");
        return std::count_if (temp_max.begin(),temp_max.end(),std::bind(std::greater<int>(),t,_1));
    }
    bool operator ! () const{
        return temp_max.empty();
    }
    Temperatura &operator ++ ();
    Temperatura operator ++ (int);
    Temperatura operator -- (int);
    Temperatura &operator -- () ;
    friend std::vector<int> operator * (const Temperatura &t);
    std::vector<int> operator - () const;
    std::vector<int> operator + () const;
    const std::pair<int,int> operator [] (int index) const;
    friend Temperatura operator + (const Temperatura &t,int broj);
    friend Temperatura operator + (int broj, const Temperatura &t);
    friend Temperatura operator - (const Temperatura &t,int broj);
    friend Temperatura operator - (int broj, const Temperatura &t);
    Temperatura &operator += (int broj) {
        return *this = *this + broj;
    }
    Temperatura &operator -= (int broj) {
        return *this = *this - broj;
    }
    friend bool operator == (const Temperatura &t1,const Temperatura &t2);
    friend bool operator != (const Temperatura &t1,const Temperatura &t2);
    friend std::ostream &operator << (std::ostream &tok,const Temperatura &t);
};
Temperatura &Temperatura::operator ++ () {
        Test_jed();
        if(std::find(temp_jednaki.begin(),temp_jednaki.end(),true) != temp_jednaki.end())
            throw std::logic_error("Ilegalna operacija");
        std::transform(temp_min.begin(),temp_min.end(),temp_min.begin(),std::bind(std::plus<int>(),1,_1));
        return *this;
    }
Temperatura Temperatura::operator ++ (int) {
        Test_jed();
        if(std::find(temp_jednaki.begin(),temp_jednaki.end(),true) != temp_jednaki.end())
            throw std::logic_error("Ilegalna operacija");
        auto t(*this);
        std::transform(temp_min.begin(),temp_min.end(),temp_min.begin(),std::bind(std::plus<int>(),1,_1));
        return t;
    }
Temperatura Temperatura::operator -- (int) {
        Test_jed();
        if(std::find(temp_jednaki.begin(),temp_jednaki.end(),true) != temp_jednaki.end())
            throw std::logic_error("Ilegalna operacija");
        auto t(*this);
        std::transform(temp_max.begin(),temp_max.end(),temp_max.begin(),std::bind(std::minus<int>(),_1,1));
        return t;
    }
Temperatura &Temperatura::operator -- () {
        Test_jed();
        if(std::find(temp_jednaki.begin(),temp_jednaki.end(),true) != temp_jednaki.end())
            throw std::logic_error("Ilegalna operacija");
        std::transform(temp_max.begin(),temp_max.end(),temp_max.begin(),std::bind(std::minus<int>(),_1,1));
        return *this;
    }
std::vector<int> Temperatura::operator - () const{
        std::vector<int> v1(temp_max.size());
        std::transform(temp_min.begin(),temp_min.end(),v1.begin(),std::bind(std::minus<int>(),_1,min));
        return v1;
    }

std::vector<int> Temperatura::operator + () const{
        std::vector<int> v1(temp_max.size());
        std::transform(temp_max.begin(),temp_max.end(),v1.begin(),std::bind(std::minus<int>(),max,_1));
        return v1;
    }
const std::pair<int,int> Temperatura::operator [] (int index) const{
        if (index < 1 or index > temp_max.size()) throw std::range_error ("Neispravan index");
        auto it(temp_min.begin());
        auto it2(temp_max.begin());
        std::advance(it,index-1);
        std::advance(it2,index-1);
        return std::make_pair(*it,*it2);
    }
void Temperatura::BrisiNegativneTemperature () {
        std::vector<bool> temp_jednaki;
        temp_jednaki.resize(temp_max.size());
        std::transform(temp_jednaki.begin(),temp_jednaki.end(),temp_max.begin(),temp_jednaki.begin(),[](int t1,int t2) {
            if (t1 < 0 and t2 < 0) return true;
            return false;
        });
        auto it = std::find(temp_jednaki.begin(),temp_jednaki.end(),true);
        if (it == temp_jednaki.end()) return;
        else {
            auto it_min(temp_min.begin());
            std::advance(it_min,std::distance(temp_jednaki.begin(),it));
            auto it_max(temp_max.begin());
            std::advance(it_max,std::distance(temp_jednaki.begin(),it));
            temp_max.erase(it_max);
            temp_min.erase(it_min);
            BrisiNegativneTemperature();
        }
    }

std::vector<int> operator *(const Temperatura &t)
{
    std::vector<int> v1(t.temp_max.size());
    std::transform(t.temp_max.begin(),t.temp_max.end(),t.temp_min.begin(),v1.begin(),std::minus<int>());
    return v1;
}

Temperatura operator + (const Temperatura &t,int broj)
{
    Temperatura t2(t.min,t.max);
    t2.temp_max.resize(t.temp_max.size());
    std::transform(t.temp_max.begin(),t.temp_max.end(),t2.temp_max.begin(),std::bind(std::plus<int>(),broj,_1));
    t2.temp_min.resize(t.temp_max.size());
    std::transform(t.temp_min.begin(),t.temp_min.end(),t2.temp_min.begin(),std::bind(std::plus<int>(),broj,_1));
    t2.Test_jed();
    if(std::find(t2.temp_jednaki.begin(),t2.temp_jednaki.end(),true) != t2.temp_jednaki.end())
        throw std::logic_error("Ilegalna operacija");
    return t2;
}
Temperatura operator + (int broj,const Temperatura &t)
{
    Temperatura t2(t.min,t.max);
    t2.temp_max.resize(t.temp_max.size());
    std::transform(t.temp_max.begin(),t.temp_max.end(),t2.temp_max.begin(),std::bind(std::plus<int>(),broj,_1));
    t2.temp_min.resize(t.temp_max.size());
    std::transform(t.temp_min.begin(),t.temp_min.end(),t2.temp_min.begin(),std::bind(std::plus<int>(),broj,_1));
    t2.Test_jed();
    if(std::find(t2.temp_jednaki.begin(),t2.temp_jednaki.end(),true) != t2.temp_jednaki.end())
        throw std::logic_error("Ilegalna operacija");
    return t2;
}

Temperatura operator - (const Temperatura &t,int broj)
{
    Temperatura t2(t.min,t.max);
    t2.temp_max.resize(t.temp_max.size());
    std::transform(t.temp_max.begin(),t.temp_max.end(),t2.temp_max.begin(),std::bind(std::minus<int>(),_1,broj));
    t2.temp_min.resize(t.temp_max.size());
    std::transform(t.temp_min.begin(),t.temp_min.end(),t2.temp_min.begin(),std::bind(std::minus<int>(),_1,broj));
    t2.Test_jed();
    if(std::find(t2.temp_jednaki.begin(),t2.temp_jednaki.end(),true) != t2.temp_jednaki.end())
        throw std::logic_error("Ilegalna operacija");
    return t2;
}

Temperatura operator -(int broj,const Temperatura &t)
{
    Temperatura t2(t.min,t.max);
    t2.temp_max.resize(t.temp_max.size());
    t2.temp_min.resize(t.temp_max.size());
    std::transform(t.temp_max.begin(),t.temp_max.end(),t2.temp_min.begin(),std::bind(std::minus<int>(),broj,_1));
    std::transform(t.temp_min.begin(),t.temp_min.end(),t2.temp_max.begin(),std::bind(std::minus<int>(),broj,_1));
    t2.Test_jed();
    if(std::find(t2.temp_jednaki.begin(),t2.temp_jednaki.end(),true) != t2.temp_jednaki.end())
        throw std::logic_error("Ilegalna operacija");
    return t2;
}

bool operator == (const Temperatura &t1,const Temperatura &t2)
{
    if (t1.min != t2.min or t1.max != t2.max or t1.temp_max.size() != t2.temp_max.size()) return false;
    std::vector<bool> v1(t1.temp_max.size());
    std::transform(t1.temp_min.begin(),t1.temp_min.end(),t2.temp_min.begin(),v1.begin(),std::equal_to<int>());
    if(std::find(v1.begin(),v1.end(),false) != v1.end())
        return false;
    std::transform(t1.temp_max.begin(),t1.temp_max.end(),t2.temp_max.begin(),v1.begin(),std::equal_to<int>());
    if(std::find(v1.begin(),v1.end(),false) != v1.end())
        return false;
    return true;
}

std::ostream &operator << (std::ostream &tok,const Temperatura &t)
{
    if(t.temp_max.empty()) return tok;
    auto kraj1(t.temp_max.end());
    kraj1--;
    for_each(t.temp_max.begin(),kraj1,[&](int x) {
        tok << x << ",";
    });
    tok << *kraj1 << std::endl;
    auto kraj2(t.temp_min.end());
    kraj2--;
    for_each(t.temp_min.begin(),kraj2,[&](int x) {
        tok << x << ",";
    });
    tok << *kraj2 << std::endl;
    return tok;
}

int main ()
{
    Temperatura t(-20,20);
    t.RegistrirajTemperature(std::make_pair(-10,18));
    t.RegistrirajTemperature(std::make_pair(-9,-4));
    t.RegistrirajTemperature(std::make_pair(-12,11));
    t.RegistrirajTemperature(std::make_pair(-7,-2));
    t.RegistrirajTemperature(std::make_pair(-4,15));
    t.RegistrirajTemperature(std::make_pair(5,13));
    t.RegistrirajTemperature(std::make_pair(2,5));
    t.RegistrirajTemperature(std::make_pair(8,19));
    std::cout << t << std::endl;
    Temperatura t2(t);
    t2++;
    
    t2--;
    std::cout << t2 << std::endl;
    auto s = t[3];
    if (t2 == t) std::cout << "iste su" << std::endl;
    std::cout << s.first <<" " <<s.second << std::endl;
}