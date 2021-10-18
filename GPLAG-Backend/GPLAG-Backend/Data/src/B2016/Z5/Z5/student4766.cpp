#include <iostream>
#include <list>
#include <stdexcept>
#include <utility>
#include <algorithm>
#include <functional>
#include <vector>

class Temperature{
    std::list<int> min,max;
    int rMin, rMax;
    public:
        Temperature(int min, int max);
        void RegistrirajTemperature(std::pair<int,int> temp);
        void BrisiSve(){ min.resize(0);  max.resize(0); }
        void BrisiNegativneTemperature();
        int DajBrojRegistriranihTemperatura()const{ return min.size(); }
        int DajMinimalnuTemperaturu()const;
        int DajMaksimalnuTemperaturu()const;
        int DajBrojTemperaturaVecihOd(int n)const;
        int DajBrojTemperaturaManjihOd(int n)const;
        bool operator!()const{ return !min.size(); }
        Temperature &operator++();
        Temperature &operator--();
        Temperature operator++(int);
        Temperature operator--(int);
        std::vector<int> operator*()const;
        std::vector<int> operator-()const;
        std::vector<int> operator+()const;
        std::pair<int,int> operator[](int x)const;
        Temperature operator+(int x)const;
        Temperature operator-(int x)const;
        bool operator==( Temperature t)const;
        bool operator!=(const Temperature &t)const{ return !(*this == t); }
        friend std::ostream &operator<<(std::ostream &tok, const Temperature &t);
    private:
        bool validOp(int x)const;
        
};
std::ostream &operator<<(std::ostream &tok, const Temperature &t){
    static bool meh = false;
    std::list<int>::const_iterator i = t.min.begin();
    std::list<int>::const_iterator j = t.max.begin();
    if(meh){ i = t.min.begin(); j = t.max.begin(); }
    meh = false;
    if(i != t.min.end()){
        tok << *i << " "; i++;
        return tok << t;
    }
    if(j == t.max.begin()) tok << "\n";
    if(j != t.max.end()){
        tok << *j << " "; j++;
        return tok << t;
    }
    meh = true;
    return tok;
}
bool Temperature::operator==(Temperature t)const{
    bool same(true);
    static bool meh = false;
    if(min.size() != t.min.size() || max.size() || t.max.size() ||
    rMin != t.rMin || rMax != t.rMax){ return false; meh = true; }
    static std::list<int>::const_iterator i1 = min.begin();
    static std::list<int>::iterator i2 = t.min.begin();
    static std::list<int>::const_iterator j1 = max.begin();
    static std::list<int>::iterator j2 = t.max.begin();
    if(meh){
        i1 = min.begin(); i2 = t.min.begin(); j1 = max.begin(), j2 = t.max.begin(); 
        meh = false;
    }
    if(i1 == min.end()){ return true; meh = true; }
    if(*i1 != *i2 || *j1 != *j2){ return false; meh = true; }
    i1++; i2++; j1++; j2++;
    return *this == t;
}
Temperature Temperature::operator-(int x)const{
    return *this + (-x);
}
Temperature Temperature::operator+(int x)const{
    if(!validOp(x)) throw std::logic_error("Prekoracen dozvoljeni opseg temperatura");
    Temperature ret(*this);
    std::transform(min.begin(), min.end(), ret.min.begin(),
    std::bind(std::plus<int>(),std::placeholders::_1,x));
    std::transform(max.begin(),max.end(),ret.max.begin(),
    std::bind(std::plus<int>(),std::placeholders::_1,x));
    return ret;
}
std::pair<int,int> Temperature::operator[](int x)const{
    if(x > min.size()) throw std::range_error("Neispravan indeks");
    static  std::list<int>::const_iterator i = min.begin();
    static  std::list<int>::const_iterator j = max.begin();
    if(x == 1){
        return std::make_pair<int,int>(*i+0, *j + 0);
    }
    i++; j++;
    return (*this)[x-1];
}
std::vector<int> Temperature::operator+()const{
    std::vector<int> v(max.size(),rMax);
    std::transform(v.begin(),v.end(),max.begin(), v.begin(), std::minus<int>());
    return v;
}
std::vector<int> Temperature::operator-()const{
    std::vector<int> v(min.size(),rMin);
    std::transform(min.begin(),min.end(),v.begin(),v.begin(),std::minus<int>());
    return v;
}
std::vector<int> Temperature::operator*()const{
    std::vector<int> v(min.size());
    std::transform(max.begin(),max.end(),min.begin(),v.begin(),std::minus<int>());
    return v;
}
Temperature Temperature::operator--(int){
    Temperature ret(*this);
    --(*this);
    return ret;
}
Temperature &Temperature::operator--(){
    if(!validOp(-1)) throw std::logic_error("Ilegalna operacija");
    std::transform(min.begin(), min.end(), min.begin(),
    std::bind(std::plus<int>(),std::placeholders::_1,-1));
    std::transform(max.begin(),max.end(), max.begin(),
    std::bind(std::plus<int>(),std::placeholders::_1,-1));
    return *this;
}
Temperature &Temperature::operator++(){
    if(!validOp(1)) throw std::logic_error("Ilegalna operacija");
    std::transform(min.begin(), min.end(), min.begin(),
    std::bind(std::plus<int>(),std::placeholders::_1,1));
    std::transform(max.begin(), max.end(), max.begin(),
    std::bind(std::plus<int>(),std::placeholders::_1,1));
    return *this;
}
Temperature Temperature::operator++(int){
    Temperature ret(*this);
    ++(*this);
    return ret;
}
bool Temperature::validOp(int x)const{
    return (DajMinimalnuTemperaturu() + x > rMin &&
    DajMaksimalnuTemperaturu() + x < rMax);
}
int Temperature::DajBrojTemperaturaVecihOd(int n)const{
    if(!max.size()) throw std::logic_error("Nema registriranih temperatura");
    return std::count_if(max.begin(), max.end(),
    std::bind(std::greater<int>(),std::placeholders::_1, n));
}
int Temperature::DajBrojTemperaturaManjihOd(int n)const{
    if(min.size() == 0) throw std::logic_error("Nema registriranih temperatura");
    return std::count_if(min.begin(), min.end(),
    std::bind(std::less<int>(),std::placeholders::_1, n));
}
int Temperature::DajMaksimalnuTemperaturu()const{
    if(max.size() == 0) throw std::logic_error("Nema registriranih temperatura");
    return *std::max_element(max.begin(), max.end(), std::greater<int>());
}
int Temperature::DajMinimalnuTemperaturu()const{
    if(min.size() == 0) throw std::logic_error("Nema registriranih temperatura");
    return *std::min_element(min.begin(), min.end(), std::less<int>());
}

void Temperature::BrisiNegativneTemperature(){
    static std::list<int>::iterator i = max.begin();
    static std::list<int>::iterator j = min.begin();
    static bool meh = false;
    if(meh){ i = max.begin(); j = min.begin(); }
    meh = false;
    if(i == max.end()){ meh = true; return; }
    if(*i < 0 && *j < 0) {
        i = max.erase(i); j = min.erase(j);
        BrisiNegativneTemperature();
    }
    i++;
    j++;
    BrisiNegativneTemperature();
}

void Temperature::RegistrirajTemperature(std::pair<int,int> temp){
    if(temp.first > temp.second || temp.second > rMax || temp.first < rMin)
        throw std::range_error("Nekorektne temperature");
    min.push_back(temp.first); max.push_back(temp.second);
}
Temperature::Temperature(int rMin, int rMax){
    if(rMin > rMax) throw std::range_error("Nekorektne temperature");    
    this->rMin = rMin; this->rMax = rMax;
}
int main () {
    
	return 0;
}