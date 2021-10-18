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
    std::list<int> min_temp;
    std::list<int> max_temp;
    int min, max;
    void JeLiPrazan() const{
        if(min_temp.size()==0) throw std::logic_error("Nema registriranih temperatura");
    }
    public:
    Temperature(int min1, int max1){
        if(min1>max1) throw std::range_error("Nekorektne temperature");
        min=min1, max=max1;
    }
    void RegistrirajTemperature(std::pair<int,int> temp){
        if(temp.first<min || temp.second<min || temp.first>max || temp.second>max || min>max) throw std::range_error("Nekorektne temperature");
        min_temp.push_back(temp.first);
        min_temp.push_back(temp.second);
    }
    void BrisiSve(){
        min_temp.clear();
        max_temp.clear();
    }
    void BrisiNegativneTemperature(){
        std::remove_if(min_temp.begin(), min_temp.end(), std::bind(std::less<int>(), std::placeholders::_1, 0));
    }
    int DajBrojRegistriranihTemperatura() const{ return min_temp.size();}
    int DajMinimalnuTemperaturu() const{
        if(min_temp.size()==0) throw std::logic_error("Nema registriranih temperatura");
        return *(std::min_element(min_temp.begin(), min_temp.end()));
    }
    int DajMaksimalnuTemperaturu() const{
        JeLiPrazan();
        return *(std::max_element(max_temp.begin(), max_temp.end()));
    }
    int DajBrojTemperaturaManjihOd(int tempica) const{
        JeLiPrazan();
        return std::count_if(max_temp.begin(), max_temp.end(), std::bind(std::less<int>(), std::placeholders::_1, tempica))+std::count_if(min_temp.begin(), min_temp.end(), std::bind(std::less<int>(), std::placeholders::_1, tempica));
    }
    
    int DajBrojTempraturaVecihOd(int temp) const{
        JeLiPrazan();
        return std::count_if(max_temp.begin(), max_temp.end(), std::bind(std::greater<int>(), std::placeholders::_1, temp)) + std::count_if(min_temp.begin(), min_temp.end(), std::bind(std::greater<int>(), std::placeholders::_1, temp));
    }
    friend bool operator !(const Temperature &t){
        return !t.DajBrojRegistriranihTemperatura();
    }
    friend Temperature &operator ++ (Temperature &t);
    friend Temperature operator ++ (Temperature &v, int);
    friend Temperature &operator --(Temperature &t);
    friend Temperature operator --(Temperature &t, int);
    friend std::vector<int> operator *(const Temperature &t);
    friend std::vector<int> operator -(const Temperature &t);
    friend std::vector<int> operator +(const Temperature &t);
     std::pair<int,int> operator [] (int n);
};

Temperature &operator ++(Temperature &t){
    //Kasno sam se sjetila funkcije for_each, tako da je ostala ova ruzna konstrukcija sa transform
    std::transform(t.min_temp.begin(), t.min_temp.end(), t.min_temp.begin(), std::bind(std::plus<int>(), std::placeholders::_1, 1));
    //std::transform(t.max_temp.begin(), t.max_temp.end(), t.max_temp.begin(), std::bind(std::plus<int>(), std::placeholders::_1, 1));
    auto it=t.max_temp.begin();
    int s;
    s=std::count_if(t.min_temp.begin(), t.min_temp.end(), std::bind(std::greater<int>(), std::placeholders::_1, *it++));
    if(s) std::transform(t.min_temp.begin(), t.min_temp.end(), t.min_temp.begin(), std::bind(std::minus<int>(), std::placeholders::_1, 1));
    if(s) throw std::logic_error("Ilegalna operacija");
    return t;
}

Temperature operator ++(Temperature &v, int){
    Temperature pomocni(v);
    ++v;
    return pomocni;
}

Temperature &operator --(Temperature &t){
    std::transform(t.max_temp.begin(), t.max_temp.end(), t.max_temp.begin(), std::bind(std::minus<int>(), std::placeholders::_1, 1));
    auto it=t.min_temp.begin();
    int s;
    s=std::count_if(t.min_temp.begin(), t.min_temp.end(), std::bind(std::greater<int>(), std::placeholders::_1, *it++));
    if(s) std::transform(t.max_temp.begin(), t.max_temp.end(), t.max_temp.begin(), std::bind(std::plus<int>(), std::placeholders::_1, 1));
    if(s) throw std::logic_error("Ilegalna operacija");
    return t;
}

Temperature operator --(Temperature &t, int){
    Temperature pomocna(t);
    ++t;
    return pomocna;
}

std::vector<int> operator *(const Temperature &t){
    std::vector<int> v(t.min_temp.size());
    std::transform(t.max_temp.begin(), t.max_temp.end(), t.min_temp.begin(), v.begin(), std::minus<int>());
    return v;
}

std::vector<int> operator - (const Temperature &t){
    std::vector<int> v(t.min_temp.size());
    std::transform(t.min_temp.begin(), t.min_temp.end(), v.begin(), std::bind(std::minus<int>(), std::placeholders::_1, t.min));

    return v;
}

std::vector<int> operator + (const Temperature &t){
    std::vector<int> v(t.min_temp.size());
    std::transform(t.max_temp.begin(), t.max_temp.end(), v.begin(), std::bind(std::minus<int>(), t.max, std::placeholders::_1));
    return v;
}

std::pair<int,int> Temperature::operator []( int n){
    if(n<1 || n>min_temp.size()) throw std::range_error("Neispravan indeks");
    auto it(std::find(min_temp.begin(), min_temp.end(), std::bind()))
}
int main ()
{
	return 0;
}