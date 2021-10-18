/B16/17 (Zadaća 5, Zadatak 5)
//Autotestovi by Berina Cocalic (mail: bcocalic1@etf.unsa.ba)
//Za autotestove se obracati *iskljucivo* osobi koja ih pise
#include <iostream>
#include <list>
#include <utility>
#include <stdexcept>
#include <algorithm>
#include <functional>
#include <vector>
#include <iterator>

class Temperature {
    int MinDozvoljena, MaxDozvoljena;
    std::list<int> MinTemp, MaxTemp;
    void ProvjeriIste();
public:
    Temperature(int min, int max);
    void RegistrirajTemperature(std::pair<int,int> DnevneTemp);
    void BrisiSve();
    void BrisiNegativneTemperature();
    int DajBrojRegistriranihTemperatura() const;
    int DajMaksimalnuTemperaturu() const;
    int DajMinimalnuTemperaturu() const;
    int DajBrojTemperaturaVecihOd(int x) const;
    int DajBrojTemperaturaManjihOd(int x) const;
    bool operator !();
    Temperature& operator ++();
    Temperature operator ++(int);
    Temperature& operator --();
    Temperature operator --(int);
    std::vector<int> operator *() const;
    std::vector<int> operator -() const;
    std::vector<int> operator +() const;
    std::pair<int,int> operator [](int i) const;
    Temperature operator +(int x) const;
    Temperature operator -(int x) const;
    Temperature operator +(const Temperature &t2) const;
    Temperature operator -(const Temperature &t2) const;
    Temperature& operator +=(int x);
    Temperature& operator +=(const Temperature &t2);
    Temperature& operator -=(int x);
    Temperature& operator -=(const Temperature &t2);
    bool operator == (const Temperature &t) const;
    bool operator != (const Temperature &t) const;
    friend std::ostream& operator << (std::ostream& tok, const Temperature &t);
};
void Temperature::ProvjeriIste() {
    std::vector<bool> pomocni;
    std::transform(MinTemp.begin(), MinTemp.end(), MaxTemp.begin(), std::back_inserter(pomocni), std::equal_to<int>());
    if(std::count(pomocni.begin(), pomocni.end(), true)) throw std::logic_error("Ilegalna operacija");
}
Temperature::Temperature(int min, int max) {
    if(min > max) throw std::logic_error("Nekorektne temperature");
    MaxDozvoljena = max;
    MinDozvoljena = min;
}
void Temperature::RegistrirajTemperature(std::pair<int,int>DnevneTemp) {
    if(DnevneTemp.first > DnevneTemp.second || DnevneTemp.first < MinDozvoljena || DnevneTemp.second > MaxDozvoljena) throw std::logic_error("Nekorektne temperature");
    MinTemp.push_back(DnevneTemp.first);
    MaxTemp.push_back(DnevneTemp.second);
}
void Temperature::BrisiSve() {
    MinTemp.clear();
    MaxTemp.clear();
}
void Temperature::BrisiNegativneTemperature() {
    auto it2 = std::find_if(MaxTemp.begin(), MaxTemp.end(), std::bind(std::less<int>(), std::placeholders::_1, 0));
    if(it2 != MaxTemp.end()) {
        auto it1(MinTemp.begin());
        std::advance(it1, std::distance(MaxTemp.begin(), it2));
        MinTemp.erase(it1);
        MaxTemp.erase(it2);
        BrisiNegativneTemperature();
    }
}
int Temperature::DajBrojRegistriranihTemperatura() const {
    return MinTemp.size();
}
int Temperature::DajMaksimalnuTemperaturu() const {
    if(MaxTemp.size() == 0) throw std::logic_error("Nema registriranih temperatura");
    return *std::max_element(MaxTemp.begin(), MaxTemp.end());
}
int Temperature::DajMinimalnuTemperaturu() const {
    if(MinTemp.size() == 0) throw std::logic_error("Nema registriranih temperatura");
    return *std::min_element(MinTemp.begin(), MinTemp.end());
}
int Temperature::DajBrojTemperaturaVecihOd(int x) const {
    if(MaxTemp.size() == 0) throw std::logic_error("Nema registriranih temperatura");
    return std::count_if(MaxTemp.begin(), MaxTemp.end(), std::bind(std::greater<int>(), std::placeholders::_1, x));
}
int Temperature::DajBrojTemperaturaManjihOd(int x) const {
    if(MinTemp.size() == 0) throw std::logic_error("Nema registriranih temperatura");
    return std::count_if(MinTemp.begin(), MaxTemp.end(), std::bind(std::less<int>(), std::placeholders::_1, x));
}
bool Temperature::operator !() {
    return (!MinTemp.size());
}
Temperature& Temperature::operator ++ () {
    ProvjeriIste();
    std::for_each(MinTemp.begin(), MinTemp.end(), std::bind(std::plus<int>(), std::placeholders::_1, 1));
    return *this;
}
Temperature Temperature::operator ++(int) {
    ProvjeriIste();
    Temperature tmp(*this);
    std::for_each(MinTemp.begin(), MinTemp.end(), std::bind(std::plus<int>(), std::placeholders::_1, 1));
    return tmp;
}
Temperature& Temperature::operator --() {
    ProvjeriIste();
    std::for_each(MaxTemp.begin(), MaxTemp.end(), std::bind(std::minus<int>(), std::placeholders::_1, 1));
    return *this;
}
Temperature Temperature::operator --(int) {
    ProvjeriIste();
    Temperature tmp(*this);
    std::for_each(MaxTemp.begin(), MaxTemp.end(), std::bind(std::minus<int>(), std::placeholders::_1, 1));
    return tmp;
}
std::vector<int> Temperature::operator *() const{
    std::vector<int> v(MaxTemp.size());
    std::transform(MaxTemp.begin(), MaxTemp.end(), MinTemp.begin(), v.begin(), std::minus<int>());
    return v;
}
std::vector<int> Temperature::operator -() const{
    std::vector<int> v(MinTemp.size());
    std::transform(MinTemp.begin(), MinTemp.end(), v.begin(), std::bind(std::minus<int>(), MinDozvoljena, std::placeholders::_1));
    return v;
}
std::vector<int> Temperature::operator +() const{
    std::vector<int> v(MaxTemp.size());
    std::transform(MaxTemp.begin(), MaxTemp.end(), v.begin(), std::bind(std::minus<int>(), MaxDozvoljena, std::placeholders::_1));
    return v;
}
std::pair<int,int> Temperature::operator [] (int i) const{
    if (i < 1 || i > MaxTemp.size()) throw std::range_error("Neispravan indeks");
    auto it1(MinTemp.begin());
    auto it2(MaxTemp.begin());
    std::advance(it1, i-1);
    std::advance(it2, i-1);
    return std::make_pair(*it1, *it2);
}
Temperature Temperature::operator +(int x) const{
    Temperature t(*this);
    std::transform(MinTemp.begin(), MinTemp.end(), t.MinTemp.begin(), std::bind(std::plus<int>(), std::placeholders::_1, x));
    std::transform(MaxTemp.begin(), MaxTemp.end(), t.MaxTemp.begin(), std::bind(std::plus<int>(), std::placeholders::_1, x));
    if(std::count_if(t.MinTemp.begin(), t.MinTemp.end(), std::bind(std::less<int>(), std::placeholders::_1, MinDozvoljena)) || std::count_if(t.MaxTemp.begin(), t.MaxTemp.end(), std::bind(std::greater<int>(), std::placeholders::_1, MaxDozvoljena)))
        throw std::logic_error("Prekoracen dozvoljeni opseg temperatura");
    return t;
}
Temperature Temperature::operator -(int x) const {
    return *this + (-x);
}
Temperature Temperature::operator +(const Temperature &t2) const {
    Temperature t(*this);
    std::transform(MinTemp.begin(), MinTemp.end(), t2.MinTemp.begin(), t.MinTemp.begin(), std::plus<int>());
    std::transform(MaxTemp.begin(), MaxTemp.end(), t2.MaxTemp.begin(), t.MaxTemp.begin(), std::plus<int>());
    if(std::count_if(t.MinTemp.begin(), t.MinTemp.end(), std::bind(std::less<int>(),std::placeholders::_1, MinDozvoljena)) || std::count_if(t.MaxTemp.begin(), t.MaxTemp.end(), std::bind(std::greater<int>(), std::placeholders::_1, MaxDozvoljena)))
        throw std::logic_error("Prekoracen dozvoljeni opseg temperatura");
    return t;
}
Temperature Temperature::operator -(const Temperature &t2) const {
    Temperature t(*this);
    std::transform(t2.MinTemp.begin(), t2.MinTemp.end(), MinTemp.begin(), t.MaxTemp.begin(), std::minus<int>());
    std::transform(t2.MaxTemp.begin(), t2.MaxTemp.end(), MaxTemp.begin(), t.MinTemp.begin(), std::minus<int>());
    if(std::count_if(t2.MinTemp.begin(), t2.MinTemp.end(), std::bind(std::less<int>(), std::placeholders::_1, MinDozvoljena)) || std::count_if(t2.MaxTemp.begin(), t2.MaxTemp.end(), std::bind(std::greater<int>(), std::placeholders::_1, MaxDozvoljena)))
        throw std::logic_error("Prekoracen dozvoljeni opseg temperatura");
    return t;
}
Temperature& Temperature::operator +=(int x) {
    *this = *this + x;
    return *this;
}
Temperature& Temperature::operator +=(const Temperature &t2) {
    *this = *this + t2;
    return *this;
}
Temperature& Temperature::operator -=(int x) {
    *this = *this - x;
    return *this;
}
Temperature& Temperature::operator -=(const Temperature &t2) {
    *this = *this - t2;
    return *this;
}
bool Temperature::operator == (const Temperature &t)const {
    return (MaxDozvoljena == t.MaxDozvoljena && MinDozvoljena == t.MinDozvoljena && MaxTemp.size() == t.MaxTemp.size() && std::equal(MaxTemp.begin(), MaxTemp.end(), t.MaxTemp.begin()) && std::equal(MinTemp.begin(), MinTemp.end(), t.MinTemp.begin()));
}
bool Temperature::operator != (const Temperature &t) const {
    return !(*this == t);
}
std::ostream& operator << (std::ostream& tok, const Temperature &t) {
    std::copy(t.MinTemp.begin(), t.MinTemp.end(), std::ostream_iterator<int>(tok, " "));
    tok<<"\n";
    std::copy(t.MaxTemp.begin(), t.MaxTemp.end(), std::ostream_iterator<int>(tok, " "));
    return tok;
}
int main ()
{
    try{
    Temperature t(-5, 5);
    t.RegistrirajTemperature(std::make_pair(3,3));
    t.RegistrirajTemperature(std::make_pair(-3,4));
    t.RegistrirajTemperature(std::make_pair(1, 5));
    t.RegistrirajTemperature(std::make_pair(-3,-1));
    t.RegistrirajTemperature(std::make_pair(-3,-3));
    t.BrisiNegativneTemperature();
    std::cout << t;
    }
    catch(...) {
        std::cout << "!";
    }
	return 0;
}