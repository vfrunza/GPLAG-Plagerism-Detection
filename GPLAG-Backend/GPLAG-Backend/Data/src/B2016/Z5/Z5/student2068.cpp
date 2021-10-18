#include <iostream>
#include <list>
#include <stdexcept>
#include <utility>
#include <algorithm>
#include <functional>
#include <vector>

class Temperature {
    std::list<int> min_lista, max_lista;
    int min_temp, max_temp;
    static void NemaRegistriranih() { throw std::logic_error("Nema registriranih temperatura"); }
public:
    Temperature(int temp1, int temp2);
    void RegistrirajTemperature(const std::pair<int, int>&p);
    void BrisiSve() { min_lista.clear(); max_lista.clear(); }
    void BrisiNegativneTemperature();
    int DajBrojRegistriranihTemperatura() const { return min_lista.size(); }
    int DajMinimalnuTemperaturu() const { if(!min_lista.size()) NemaRegistriranih(); return *std::min_element(min_lista.begin(), min_lista.end()); }
    int DajMaksimalnuTeperaturu() const { if(!min_lista.size()) NemaRegistriranih(); return *std::max_element(max_lista.begin(), max_lista.end()); }
    int DajBrojTeperaturaVecihOd(int x) const;
    int DajBrojTeperaturaManjihOd(int x) const;
    
    bool operator !() { return min_lista.size(); }
    Temperature& operator ++();
    Temperature operator ++(int);
    Temperature& operator --();
    Temperature operator --(int);
    std::vector<int> operator *() const;
    std::vector<int> operator -() const;
    std::vector<int> operator +() const;
    std::pair<int, int> operator [](int x) const;
};

Temperature::Temperature(int temp1, int temp2) : min_temp(temp1), max_temp(temp2) {
    if(temp1>temp2) throw std::range_error("Nekorektne temperature");
}
void Temperature::RegistrirajTemperature(const std::pair<int, int>&p) {
    if(p.first>p.second || p.first<min_temp || p.second>max_temp) throw std::range_error("Nekorektne temperature");
    min_lista.push_back(p.first); max_lista.push_back(p.second);
}

void Temperature::BrisiNegativneTemperature() {
    
}

int Temperature::DajBrojTeperaturaVecihOd(int x) const { 
    if(!min_lista.size()) NemaRegistriranih();
    return std::count_if(max_lista.begin(), max_lista.end(), std::bind(std::greater<int>(), std::placeholders::_1, x));
}
int Temperature::DajBrojTeperaturaManjihOd(int x) const {
    if(!min_lista.size()) NemaRegistriranih();
    return std::count_if(min_lista.begin(), min_lista.end(), std::bind(std::less<int>(), std::placeholders::_1, x));
}

Temperature& Temperature::operator ++() {
    int a=std::count_if(min_lista.begin(), min_lista.end(), std::bind(std::equal_to<int>(), std::placeholders::_1, max_temp));
    if(a>0) throw std::logic_error("Ilegalna operacija");
    std::transform(min_lista.begin(), min_lista.end(), min_lista.begin(), std::bind(std::plus<int>(), std::placeholders::_1, 1));
    return *this;
}
Temperature Temperature::operator ++(int ) {
    auto pomocna(*this);
    int a=std::count_if(min_lista.begin(), min_lista.end(), std::bind(std::equal_to<int>(), std::placeholders::_1, max_temp));
    if(a>0) throw std::logic_error("Ilegalna operacija");
    std::transform(min_lista.begin(), min_lista.end(), min_lista.begin(), std::bind(std::plus<int>(), std::placeholders::_1, 1));
    return pomocna;
}
Temperature& Temperature::operator --() {
    int a=std::count_if(max_lista.begin(), max_lista.end(), std::bind(std::equal_to<int>(), std::placeholders::_1, min_temp));
    if(a>0) throw std::logic_error("Ilegalna operacija");
    std::transform(max_lista.begin(), max_lista.end(), max_lista.begin(), std::bind(std::minus<int>(), std::placeholders::_1, 1));
    return *this;
}
Temperature Temperature::operator --(int) {
    auto pomocna(*this);
    int a=std::count_if(max_lista.begin(), max_lista.end(), std::bind(std::equal_to<int>(), std::placeholders::_1, min_temp));
    if(a>0) throw std::logic_error("Ilegalna operacija");
    std::transform(max_lista.begin(), max_lista.end(), max_lista.begin(), std::bind(std::minus<int>(), std::placeholders::_1, 1));
    return pomocna;
}

std::vector<int> Temperature::operator *() const {
    std::vector<int>v(max_lista.size());
    std::transform(max_lista.begin(), max_lista.end(), min_lista.begin(), v.begin(), std::minus<int>());
    return v;
}

std::vector<int> Temperature::operator -() const {
    std::vector<int>v(max_lista.size());
    std::transform(min_lista.begin(), min_lista.end(), v.begin(), std::bind(std::minus<int>(), std::placeholders::_1, min_temp));
    return v;
}

std::vector<int> Temperature::operator +() const {
    std::vector<int>v(max_lista.size());
    std::transform(max_lista.begin(), max_lista.end(), v.begin(), std::bind(std::minus<int>(), max_temp, std::placeholders::_1));
    return v;
}

std::pair<int, int> Temperature::operator [](int x) const {
    std::pair<int, int>p; int i=0;
    if(x<1 || x>max_lista.size()) throw std::range_error("Neispravan indeks");
    //p.first=*std::find_if(std::equal_to<int>(std::bind(std::plus<int>(), i, 1)), x))
}

int main () {
    
}