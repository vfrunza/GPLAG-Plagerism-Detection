/B2017/2018: Zadaća 5, Zadatak 6
#include <iostream>
#include <vector>
#include <stdexcept>
#include <algorithm>
#include <functional>
#include <utility>
#include <iterator>
#include <iomanip>
#include <set>

using namespace std::placeholders;
using NumType = int;

class Berza {
public:
    Berza(NumType min_cijena, NumType max_cijena);
    Berza(NumType max_cijena);
  
    void RegistrirajCijenu(NumType cijena);
    int DajBrojRegistriranihCijena() const { return info.size(); }
    void BrisiSve() { return info.clear(); }
    NumType DajMinimalnuCijenu() const;
    NumType DajMaksimalnuCijenu() const;
    NumType DajBrojCijenaVecihOd(NumType value) const;
    void Ispisi() const;
    
    bool operator !() const { return info.empty(); };
    NumType operator [](int i) const;
    Berza& operator++();
    Berza& operator--();
    Berza operator++(int);
    Berza operator--(int);
    Berza operator-() const;
    
    Berza& operator+=(NumType);
    Berza& operator-=(NumType);
    Berza& operator-=(const Berza&);
    
    friend Berza operator +(const Berza &b, NumType y);
    friend Berza operator -(const Berza &b, NumType y);
    friend Berza operator +(NumType y, const Berza &b);
    friend Berza operator -(NumType y, const Berza &b);
    friend Berza operator -(const Berza &a, const Berza &b);
    
    friend bool operator==(const Berza&, const Berza&);
    friend bool operator!=(const Berza&, const Berza&);
private:
    enum IncreaseType { Uvecaj, Umanji };
    enum ThrowType { RangeError, DomainError };
    
    std::vector<NumType> info;
    NumType min_cijena, max_cijena;
    
    void checkIfEmpty() const {
        if(!*this) throw std::range_error("Nema registriranih cijena");
    }
    
    void SetNewValues(IncreaseType type, NumType value, ThrowType exept = RangeError) {
        bool check (false);
        if(type == Uvecaj) {
            check = std::any_of(info.begin(), info.end(), std::bind(std::greater<NumType>(), std::bind(std::plus<NumType>(), _1, std::abs(value)), max_cijena));
                    
            if(value != 0 && !check)
                std::transform(info.begin(), info.end(), info.begin(), std::bind(std::plus<NumType>(), _1, value));
        }
        else if(type == Umanji) {
            check = std::any_of(info.begin(), info.end(), std::bind(std::less<NumType>(), std::bind(std::minus<NumType>(), _1, std::abs(value)), min_cijena));
                    
            if(value != 0 && !check)
                std::transform(info.begin(), info.end(), info.begin(), std::bind(std::minus<NumType>(), _1, value));
        }
        
        if(check) {
            if(exept == RangeError) throw std::range_error("Prekoracen dozvoljeni opseg cijena");
            else if(exept == DomainError) throw std::domain_error("Prekoracen dozvoljeni opseg cijena");
        }
    }
};

////////////////////////
Berza::Berza(NumType min_cijena, NumType max_cijena) : min_cijena(min_cijena), max_cijena(max_cijena) {
    if(min_cijena < 0 || max_cijena < 0)
        throw std::range_error("Ilegalne granicne cijene");
}
Berza::Berza(NumType max_cijena) : min_cijena(0), max_cijena(max_cijena) {
    if(max_cijena < 0)
        throw std::range_error("Ilegalne granicne cijene");
}

void Berza::RegistrirajCijenu(NumType cijena) {
    if(cijena < min_cijena || cijena > max_cijena)
        throw std::range_error("Ilegalna cijena");
    info.push_back(cijena);
} 
NumType Berza::DajMinimalnuCijenu() const {
    checkIfEmpty();
    return *std::min_element(info.begin(), info.end());
}
NumType Berza::DajMaksimalnuCijenu() const {
    checkIfEmpty();
    return *std::max_element(info.begin(), info.end());
}
NumType Berza::DajBrojCijenaVecihOd(NumType value) const {
    checkIfEmpty();
    return std::count_if(info.begin(), info.end(), std::bind(std::greater<NumType>(), _1, value));
}

void Berza::Ispisi() const {
    std::vector<double> values;
    std::transform(info.begin(), info.end(), std::back_inserter(values), std::bind(std::divides<double>(), _1, 100.0));
    std::sort(values.begin(), values.end(), std::greater<double>());
    std::copy(values.begin(), values.end(), std::ostream_iterator<double>(std::cout << std::fixed << std::setprecision(2), "\n"));
}

Berza& Berza::operator++() {
    SetNewValues(IncreaseType::Uvecaj, 100);
    return *this;
}
Berza& Berza::operator--() {
    SetNewValues(IncreaseType::Umanji, 100);
    return *this;
}
Berza Berza::operator++(int) {
    Berza value(min_cijena, max_cijena);
    value.info = info;
    SetNewValues(IncreaseType::Uvecaj, 100);
    return value;
}
Berza Berza::operator--(int) {
    Berza value(min_cijena, max_cijena);
    value.info = info;
    SetNewValues(IncreaseType::Umanji, 100);
    return value;
}
Berza Berza::operator-() const {
    Berza val(this->min_cijena, this->max_cijena);
    val.info = info;
    std::transform(info.begin(), info.end(), val.info.begin(), std::bind(std::minus<NumType>(), std::bind(std::minus<NumType>(), max_cijena, min_cijena), _1));
    return val;
}

Berza operator +(const Berza &b, NumType y) {
    Berza result(b.min_cijena, b.max_cijena);
    result.info = b.info;
    if(y <= 0) result.SetNewValues(Berza::IncreaseType::Umanji, y, Berza::ThrowType::DomainError);
    else result.SetNewValues(Berza::IncreaseType::Uvecaj, y, Berza::ThrowType::DomainError);
    return result;
}
Berza operator -(const Berza &b, NumType y) {
    Berza result(b.min_cijena, b.max_cijena);
    result.info = b.info;
    if(y <= 0) result.SetNewValues(Berza::IncreaseType::Uvecaj, y, Berza::ThrowType::DomainError);
    else result.SetNewValues(Berza::IncreaseType::Umanji, y, Berza::ThrowType::DomainError);
    return result;
}
inline Berza operator +(NumType y, const Berza &b) {
    return b + y;
}
Berza operator -(NumType y, const Berza &b) {
    Berza result(b.min_cijena, b.max_cijena);
    std::transform(b.info.begin(), b.info.end(), std::back_inserter(result.info), std::bind(std::minus<NumType>(), y, _1));
    result.SetNewValues(Berza::IncreaseType::Uvecaj, 0, Berza::ThrowType::DomainError); /// will only perform check 
    result.SetNewValues(Berza::IncreaseType::Umanji, 0, Berza::ThrowType::DomainError); /// will only perform check
    return result;
}

Berza operator -(const Berza &a, const Berza &b) {
    if(a.info.size() != b.info.size() || a.min_cijena != b.min_cijena || a.max_cijena != b.max_cijena)
        throw std::domain_error("Nesaglasni operandi");
    Berza value(a.min_cijena, a.max_cijena);
    
    std::transform(a.info.begin(), a.info.end(), b.info.begin(), std::back_inserter(value.info), std::minus<NumType>());
    value.SetNewValues(Berza::IncreaseType::Uvecaj, 0, Berza::ThrowType::DomainError); /// will only perform check 
    value.SetNewValues(Berza::IncreaseType::Umanji, 0, Berza::ThrowType::DomainError); /// will only perform check
    
    return value;
}

Berza& Berza::operator+=(NumType value) {
    return *this = *this + value;
}
Berza& Berza::operator-=(NumType value) {
    return *this = *this - value;
}
Berza& Berza::operator-=(const Berza& b) {
    return *this = *this - b;
}

NumType Berza::operator [](int i) const {
    if(i < 0 || i >= info.size()) 
        throw std::range_error("Neispravan indeks");
    return info.at(i);
}

bool operator==(const Berza& b1, const Berza& b2) {
    std::set<bool> s;
    std::transform(b1.info.begin(), b1.info.end(), b2.info.begin(), std::inserter(s, s.begin()), std::equal_to<NumType>());
    return b1.info.size() == b2.info.size() && !std::any_of(s.begin(), s.end(), std::bind(std::equal_to<bool>(), _1, false) );
}
bool operator!=(const Berza& b1, const Berza& b2) {
    return b1.info.size() != b2.info.size() || !(b1 == b2);
}


int main () {
 
	return 0;
}
