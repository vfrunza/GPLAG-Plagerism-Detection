/B16/17 (Zadaća 5, Zadatak 5)
//Autotestovi by Berina Cocalic (mail: bcocalic1@etf.unsa.ba)
//Za autotestove se obracati *iskljucivo* osobi koja ih pise
#include <iostream>
#include <list>
#include <stdexcept>
#include <utility>
#include <vector>
#include <algorithm>
#include <functional>
#include <iterator>

class Temperature {
    int min_dozvoljena_temp, max_dozvoljena_temp;
    std::list<int> maksimalne_temperature;
    std::list<int> minimalne_temperature;
public:
    Temperature(int min_dozvoljena_temp, int max_dozvoljena_temp);
    void RegistrirajTemperature(std::pair<int,int> temperature);
    void BrisiSve();
    void BrisiNegativneTemperature();
    int DajBrojRegistriranihTemperatura() const;
    int DajMaksimalnuTemperaturu() const;
    int DajMinimalnuTemperaturu() const;
    int DajBrojTemperaturaVecihOd(int temperatura) const;
    int DajBrojTemperaturaManjihOd(int temperatura) const;
    friend bool operator !(const Temperature &t);
    friend Temperature &operator ++(Temperature &t);
    friend Temperature operator ++(Temperature &t,int);
    friend Temperature &operator --(Temperature &t);
    friend Temperature operator --(Temperature &t,int);
    friend std::vector<int> operator *(const Temperature &t);
    friend std::vector<int> operator -(const Temperature &t);
    friend std::vector<int> operator +(const Temperature &t);
    std::pair<int,int> operator [](int indeks);
    friend Temperature operator +(const Temperature &t,int y);
    friend Temperature operator +(int y,const Temperature &t);
    friend Temperature operator -(const Temperature &t,int y);
    friend Temperature operator -(int y,const Temperature &t);
    friend Temperature &operator +=(Temperature &t1,int y);
    friend Temperature &operator -=(Temperature &t1,int y);
    friend bool operator ==(const Temperature &t1,const Temperature &t2);
    friend bool operator !=(const Temperature &t1,const Temperature &t2);
    friend std::ostream &operator <<(std::ostream &tok, const Temperature &t);
};

Temperature::Temperature(int min_dozvoljena_temp, int max_dozvoljena_temp) {
    std::less<int> manji;
    if (manji(max_dozvoljena_temp,min_dozvoljena_temp))
        throw std::range_error("Nekorektne temperature");
    this->min_dozvoljena_temp=min_dozvoljena_temp;
    this->max_dozvoljena_temp=max_dozvoljena_temp;
}

void Temperature::RegistrirajTemperature(std::pair<int,int> temperature) {
    std::less<int> manji;
    if (manji(temperature.second,temperature.first))
        throw std::range_error("Nekorektne temperature");
    if (manji(max_dozvoljena_temp,temperature.second))
        throw std::range_error("Nekorektne temperature");
    if (manji(temperature.first,min_dozvoljena_temp))
        throw std::range_error("Nekorektne temperature");
    maksimalne_temperature.push_back(temperature.second);
    minimalne_temperature.push_back(temperature.first);
} 

void Temperature::BrisiSve() {
    if (maksimalne_temperature.size()==0 || minimalne_temperature.size()==0)
        throw std::logic_error("Nema registriranih temperatura");
    maksimalne_temperature.erase(maksimalne_temperature.begin(),maksimalne_temperature.end());
    minimalne_temperature.erase(minimalne_temperature.begin(),minimalne_temperature.end());
} 

void Temperature::BrisiNegativneTemperature() {
    auto it1=std::find_if(maksimalne_temperature.begin(),maksimalne_temperature.end(),std::bind(std::less<int>(),std::placeholders::_1,0));
    if (it1==maksimalne_temperature.end()) return;
    else {
        auto it2=minimalne_temperature.begin();
        int pozicija=std::distance(maksimalne_temperature.begin(),it1);
        std::advance(it2,pozicija);
        maksimalne_temperature.erase(it1);
        minimalne_temperature.erase(it2);
    }
    BrisiNegativneTemperature();
}

int Temperature::DajBrojRegistriranihTemperatura() const {
    return maksimalne_temperature.size();
} 

int Temperature::DajMaksimalnuTemperaturu() const {
    if (maksimalne_temperature.size()==0)
        throw std::logic_error("Nema registriranih temperatura");
    return *std::max_element(maksimalne_temperature.begin(),maksimalne_temperature.end());
} 

int Temperature::DajMinimalnuTemperaturu() const {
    if (maksimalne_temperature.size()==0)
        throw std::logic_error("Nema registriranih temperatura");
    return *std::min_element(minimalne_temperature.begin(),minimalne_temperature.end());
} 

int Temperature::DajBrojTemperaturaVecihOd(int temperatura) const {
    return std::count_if(maksimalne_temperature.begin(),maksimalne_temperature.end(),std::bind(std::greater<int>(),std::placeholders::_1,temperatura));
} 

int Temperature::DajBrojTemperaturaManjihOd(int temperatura) const {
    return std::count_if(minimalne_temperature.begin(),minimalne_temperature.end(),std::bind(std::less<int>(),std::placeholders::_1,temperatura));
} 

bool operator!(const Temperature &t) {
    if (t.DajBrojRegistriranihTemperatura()==0) return true;
    return false;
} 

Temperature &operator ++(Temperature &t) {
    std::transform(t.minimalne_temperature.begin(),t.minimalne_temperature.end(),t.minimalne_temperature.begin(),std::bind(std::plus<int>(),std::placeholders::_1,1));
    if (!(std::equal(t.minimalne_temperature.begin(),t.minimalne_temperature.end(),t.maksimalne_temperature.begin(),
        std::bind(std::less_equal<int>(),std::placeholders::_1,std::placeholders::_2)))) 
        throw std::logic_error("Ilegalna operacija");
    return t;
}  

Temperature operator ++(Temperature &t,int) {
    Temperature pomocni(t);
    ++t;
    return pomocni;
} 

Temperature &operator --(Temperature &t) {
    std::transform(t.maksimalne_temperature.begin(),t.maksimalne_temperature.end(),t.maksimalne_temperature.begin(),std::bind(std::minus<int>(),std::placeholders::_1,1));
    if (!(std::equal(t.maksimalne_temperature.begin(),t.maksimalne_temperature.end(),t.minimalne_temperature.begin(),
        std::bind(std::greater_equal<int>(),std::placeholders::_1,std::placeholders::_2))))
        throw std::logic_error("Ilegalana operacija");
    return t;
} 

Temperature operator --(Temperature &t,int) {
    Temperature pomocni(t);
    --t;
    return pomocni;
} 

std::vector<int> operator *(const Temperature &t) {
    std::vector<int> razlike(t.DajBrojRegistriranihTemperatura());
    std::transform(t.maksimalne_temperature.begin(),t.maksimalne_temperature.end(),t.minimalne_temperature.begin(),
        razlike.begin(),std::bind(std::minus<int>(),std::placeholders::_1,std::placeholders::_2));
    return razlike;
} 

std::vector<int> operator -(const Temperature &t) {
    std::vector<int> razlike(t.DajBrojRegistriranihTemperatura());
    std::transform(t.minimalne_temperature.begin(),t.minimalne_temperature.end(),razlike.begin(),
        std::bind(std::minus<int>(),std::placeholders::_1,t.min_dozvoljena_temp));
    return razlike;
} 

std::vector<int> operator +(const Temperature &t) {
    std::vector<int> razlike(t.DajBrojRegistriranihTemperatura());
    std::transform(t.maksimalne_temperature.begin(),t.maksimalne_temperature.end(),razlike.begin(),
        std::bind(std::minus<int>(),t.max_dozvoljena_temp,std::placeholders::_1));
    return razlike;
} 

std::pair<int,int> Temperature::operator [](int indeks) {
    if (indeks<=0 || indeks>DajBrojRegistriranihTemperatura())
        throw std::range_error("Neispravan indeks");
    auto it1=minimalne_temperature.begin();
    std::advance(it1,indeks-1);
    auto it2=maksimalne_temperature.begin();
    std::advance(it2,indeks-1);
    return std::make_pair(*it1,*it2);
} 

Temperature operator +(const Temperature &t,int y) {
    Temperature rezultat(t.min_dozvoljena_temp,t.max_dozvoljena_temp);
    rezultat.maksimalne_temperature.resize(t.DajBrojRegistriranihTemperatura());
    rezultat.minimalne_temperature.resize(t.DajBrojRegistriranihTemperatura());
    std::copy(t.minimalne_temperature.begin(),t.minimalne_temperature.end(),rezultat.minimalne_temperature.begin());
    std::copy(t.maksimalne_temperature.begin(),t.maksimalne_temperature.end(),rezultat.maksimalne_temperature.begin());
    std::transform(rezultat.minimalne_temperature.begin(),rezultat.minimalne_temperature.end(),rezultat.minimalne_temperature.begin(),
        std::bind(std::plus<int>(),std::placeholders::_1,y));
    std::transform(rezultat.maksimalne_temperature.begin(),rezultat.maksimalne_temperature.end(),rezultat.maksimalne_temperature.begin(),
        std::bind(std::plus<int>(),std::placeholders::_1,y));
    auto tmp1=std::find_if(rezultat.maksimalne_temperature.begin(),rezultat.maksimalne_temperature.end(),
        std::bind(std::greater<int>(),std::placeholders::_1,t.max_dozvoljena_temp));
    if (tmp1!=rezultat.maksimalne_temperature.end()) throw std::logic_error("Prekoracen dozvoljeni opseg temperatura");
    auto tmp2=std::find_if(rezultat.minimalne_temperature.begin(),rezultat.minimalne_temperature.end(),
        std::bind(std::less<int>(),std::placeholders::_1,t.min_dozvoljena_temp));
    if (tmp2!=rezultat.minimalne_temperature.end()) throw std::logic_error("Prekoracen dozvoljeni opseg temperatura");
    return rezultat;
} 

Temperature operator +(int y,const Temperature &t) {
    auto rezultat=t+y;
    return rezultat;
} 

Temperature operator -(const Temperature &t,int y) {
    Temperature rezultat(t.min_dozvoljena_temp,t.max_dozvoljena_temp);
    rezultat.maksimalne_temperature.resize(t.DajBrojRegistriranihTemperatura());
    rezultat.minimalne_temperature.resize(t.DajBrojRegistriranihTemperatura());
    auto it1_1=rezultat.minimalne_temperature.begin(); it1_1++;
    auto it2_1=rezultat.maksimalne_temperature.begin(); it2_1++;
    std::copy(t.minimalne_temperature.begin(),t.minimalne_temperature.end(),rezultat.minimalne_temperature.begin());
    std::copy(t.maksimalne_temperature.begin(),t.maksimalne_temperature.end(),rezultat.maksimalne_temperature.begin());
    std::transform(rezultat.minimalne_temperature.begin(),rezultat.minimalne_temperature.end(),
        rezultat.minimalne_temperature.begin(),std::bind(std::minus<int>(),std::placeholders::_1,y));
    std::transform(rezultat.maksimalne_temperature.begin(),rezultat.maksimalne_temperature.end(),
        rezultat.maksimalne_temperature.begin(),std::bind(std::minus<int>(),std::placeholders::_1,y));
    auto tmp1=std::find_if(rezultat.minimalne_temperature.begin(),rezultat.minimalne_temperature.end(),
        std::bind(std::less<int>(),std::placeholders::_1,t.min_dozvoljena_temp));
    if (tmp1!=rezultat.minimalne_temperature.end()) throw std::logic_error("Prekoracen dozvoljeni opseg temperatura");
    auto tmp2=std::find_if(rezultat.maksimalne_temperature.begin(),rezultat.maksimalne_temperature.end(),
        std::bind(std::greater<int>(),std::placeholders::_1,t.max_dozvoljena_temp));
    if (tmp2!=rezultat.maksimalne_temperature.end()) throw std::logic_error("Prekoracen dozvoljeni opseg temperatura");
    return rezultat;
} 

Temperature operator -(int y,const Temperature &t) {
    Temperature rezultat(t.min_dozvoljena_temp,t.max_dozvoljena_temp);
    rezultat.maksimalne_temperature.resize(t.DajBrojRegistriranihTemperatura());
    rezultat.minimalne_temperature.resize(t.DajBrojRegistriranihTemperatura());
    std::copy(t.minimalne_temperature.begin(),t.minimalne_temperature.end(),rezultat.maksimalne_temperature.begin());
    std::copy(t.maksimalne_temperature.begin(),t.maksimalne_temperature.end(),rezultat.minimalne_temperature.begin());
    std::transform(rezultat.minimalne_temperature.begin(),rezultat.minimalne_temperature.end(),
        rezultat.minimalne_temperature.begin(),std::bind(std::minus<int>(),y,std::placeholders::_1));
    auto tmp1=std::find_if(rezultat.minimalne_temperature.begin(),rezultat.minimalne_temperature.end(),
        std::bind(std::less<int>(),std::placeholders::_1,t.min_dozvoljena_temp));
    if (tmp1!=rezultat.minimalne_temperature.end()) throw std::logic_error("Prekoracen dozvoljeni opseg temperatura");
    std::transform(rezultat.maksimalne_temperature.begin(),rezultat.maksimalne_temperature.end(),
        rezultat.maksimalne_temperature.begin(),std::bind(std::minus<int>(),y,std::placeholders::_1));
    auto tmp2=std::find_if(rezultat.maksimalne_temperature.begin(),rezultat.maksimalne_temperature.end(),
        std::bind(std::greater<int>(),std::placeholders::_1,t.max_dozvoljena_temp));
    if (tmp2!=rezultat.maksimalne_temperature.end()) throw std::logic_error("Prekoracen dozvoljeni opseg temperatura");
    return rezultat;
} 

Temperature &operator +=(Temperature &t1,int y) {
    t1=t1+y;
    return t1;
} 

Temperature &operator -=(Temperature &t1,int y) {
    t1=t1-y;
    return t1;
} 

bool operator ==(const Temperature &t1,const Temperature &t2) {
    if (t1.DajBrojRegistriranihTemperatura()!=t2.DajBrojRegistriranihTemperatura() || t1.max_dozvoljena_temp!=t2.max_dozvoljena_temp ||
        t1.min_dozvoljena_temp!=t2.min_dozvoljena_temp) return false;
    else if (!std::equal(t1.minimalne_temperature.begin(),t1.minimalne_temperature.end(),t2.minimalne_temperature.begin())) return false;
    else if (!std::equal(t1.maksimalne_temperature.begin(),t1.maksimalne_temperature.end(),t2.maksimalne_temperature.begin())) return false;
    return true;
}

bool operator !=(const Temperature &t1,const Temperature &t2) {
    return !(t1==t2);
}

std::ostream &operator <<(std::ostream &tok, const Temperature &t) {
    std::ostream_iterator<int> izlaz(tok," ");
    std::copy(t.minimalne_temperature.begin(),t.minimalne_temperature.end(),izlaz);
    tok << std::endl;
    std::copy(t.maksimalne_temperature.begin(),t.maksimalne_temperature.end(),izlaz);
    return tok;
}

int main () {
    Temperature t(-35,35);
    t.RegistrirajTemperature({4,15});
    t.RegistrirajTemperature({-3,8});
    t.RegistrirajTemperature({-11,-3});
    t.RegistrirajTemperature({-7,14});
    t.RegistrirajTemperature({0,21});
    t.RegistrirajTemperature({5,27});
    t.RegistrirajTemperature({-13,-12});
    t.BrisiNegativneTemperature();
    std::cout << t << std::endl;
    t++; t--;
    std::cout << t << std::endl;
    ++t; --t;
    std::cout << t << std::endl;
    t+=3; t-=3;
    std::cout << t << std::endl;
    auto t1=0-t;
    std::cout << t1 << std::endl;
    auto t2=-0-t;
    std::cout << t2 << std::endl;
    if (t1==t2) {
        std::cout << t.DajBrojRegistriranihTemperatura() << " " << t.DajMaksimalnuTemperaturu() << " " << t.DajMinimalnuTemperaturu() << std::endl;
        t.BrisiSve();
        if (!t) std::cout << "Kraj" << std::endl;
    }
    else t.BrisiSve();
    return 0;
}