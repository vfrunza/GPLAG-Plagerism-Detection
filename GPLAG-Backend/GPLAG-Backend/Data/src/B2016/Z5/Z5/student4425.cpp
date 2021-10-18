#include <iostream>
#include <list>
#include <stdexcept> 
#include <functional>
#include <algorithm> 
#include <vector>  
//radi ponovo... -.- BEZ PETLJI BEZ user-defined functions
class Temperature {   
    std::list<int> minimalne, maksimalne;   
    int MIN, MAX;    
public: 
    Temperature (int min, int max) {
        if (MIN > MAX) throw std::range_error("Nekorektne temperature"); 
        MIN = min; MAX = max;
    } 
    void RegistrirajTemperature(std::pair<int, int> minmax);  
    void BrisiSve() {minimalne.clear(); maksimalne.clear();}
    void BrisiNegativneTemperature();
    int DajBrojRegistriranihTemperatura() const;  
    int DajMinimalnuTemperaturu() const;
    int DajMaksimalnuTemperaturu() const; 
    int DajBrojTemberaturaVecihOd (int ref) const;
    int DajBrojTemberaturaManjihOd (int ref) const; 
    
    bool operator !(); 
    Temperature &operator ++(); 
    Temperature operator ++(int);   //done
    Temperature &operator --();
    Temperature operator --(int);   //done
    std::vector<int> operator *();  
    std::vector<int> operator +();
    std::vector<int> operator -();
    std::pair<int, int> operator [](int i) const;   //done
    
    // dodati binarni +,-,+=,-= ///////////////////////////////////////////////////
    friend bool operator ==(const Temperature &t1, const Temperature &t2);  //done
    friend bool operator !=(const Temperature &t1, const Temperature &t2);  //done
    friend std::ostream &operator <<(std::ostream &tok, const Temperature &t);
};

std::ostream &operator <<(std::ostream &tok, const Temperature &t) {
    
}

bool operator !=(const Temperature &t1, const Temperature &t2) {
    return (!(t1 == t2));
}

bool operator ==(const Temperature &t1, const Temperature &t2) {
    bool a(std::equal(t1.minimalne.begin(), t1.minimalne.end(), t2.minimalne.begin()));
    bool b(std::equal(t1.maksimalne.begin(), t1.maksimalne.end(), t2.maksimalne.begin()));
    bool c(t1.minimalne.size() == t2.minimalne.size());
    bool d(t1.maksimalne.size() == t2.maksimalne.size());
    bool e(t1.MIN == t2.MIN && t1.MAX == t2.MAX);
    return a && b && c && d && e;
}


std::pair<int, int> Temperature::operator [](int i) const {
    auto itmin(minimalne.begin());
    auto itmax(maksimalne.begin());
    if (i < 1 || i > minimalne.size()) throw std::range_error("Neispravan indeks");
    std::advance(itmin, i-1);
    std::advance(itmax, i-1);
    return std::make_pair(*itmin, *itmax);
}

std::vector<int> Temperature::operator -() {    //prepravi da ne koristiš petlje!
    std::vector<int> v;
    auto it(minimalne.begin());
    while (it != minimalne.end()) v.push_back(*it - MIN), it++;
    return v;
}

std::vector<int> Temperature::operator +() {    //prepravi da ne koristiš petlje
    std::vector<int> v;
    auto it(maksimalne.begin());
    while (it != maksimalne.end()) v.push_back(MAX - *it), it++;
    return v;
}

std::vector<int> Temperature::operator *() {    //prepravi da ne koristiš petlje
    std::vector<int> razlike;
    auto itmin(minimalne.begin());
    auto itmax(maksimalne.begin());
    while (itmin != minimalne.end() || itmax != maksimalne.end()) {
        razlike.push_back(*itmax - *itmin);
        itmin++;
        itmax++;
    }
    return razlike;
}

Temperature Temperature::operator --(int) {
    Temperature tmp(*this);
    --(*this);
    return tmp;
}

Temperature &Temperature::operator --() {   //prepravi da ne koristiš petlje
    //dodaj check na ilegalnu operaciju? as in ++() //////////////////////////////////
    auto it(maksimalne.begin());
    while (it != maksimalne.end()) --(*it), it++;
    return *this;
}

Temperature Temperature::operator ++(int) {
    Temperature tmp(*this);
    ++(*this);
    return tmp;
}

Temperature &Temperature::operator ++() {   //prepravi da ne koristiš petlje
    auto it(minimalne.begin());
    auto itmax(maksimalne.begin());
    while (it != minimalne.end()) {
        std::advance(itmax, std::distance(minimalne.begin(), it));
        if (*it + 1 > *itmax)
            throw std::logic_error("Ilegalna operacija");
        itmax = maksimalne.begin();
        it++;
    }
    it = minimalne.begin();
    while (it != minimalne.end()) ++(*it), it++;
    return *this;
}

bool Temperature::operator !() {
    if(!DajBrojRegistriranihTemperatura()) return true;
    return false;
} 

int Temperature::DajBrojTemberaturaManjihOd(int ref) const { 
    if (minimalne.empty() || maksimalne.empty()) throw std::logic_error("Nema registriranih temperatura");
    int count = std::count_if(minimalne.begin(), minimalne.end(), std::bind(std::less<int>(), std::placeholders::_1, ref));
    return count; 
}

int Temperature::DajBrojTemberaturaVecihOd(int ref) const {
    if (minimalne.empty() || maksimalne.empty()) throw std::logic_error("Nema registriranih temperatura");
    int count = std::count_if(maksimalne.begin(), maksimalne.end(), std::bind(std::greater<int>(), std::placeholders::_1, ref));
    return count;
}

int Temperature::DajMaksimalnuTemperaturu() const {
    if (minimalne.empty() || maksimalne.empty()) throw std::logic_error("Nema registriranih temperatura");
    int max = *std::max_element(maksimalne.begin(), maksimalne.end());
    return max;
}

int Temperature::DajMinimalnuTemperaturu() const {
    if(minimalne.empty() || maksimalne.empty()) throw std::logic_error("Nema registriranih temperatura");
    int min = *std::min_element(minimalne.begin(), minimalne.end());
    return min;
}

int Temperature::DajBrojRegistriranihTemperatura() const {
    if (minimalne.size() != maksimalne.size()) std::cout << "STH IS WRONG!!!";
    return minimalne.size();
}

void Temperature::RegistrirajTemperature(std::pair<int, int> minmax) {
    if (minmax.first < MIN || minmax.first > MAX || minmax.second < MIN || minmax.second > MAX)
        throw std::range_error("Nekorektne temperature");
    minimalne.push_back(minmax.first);
    maksimalne.push_back(minmax.second);
}

void Temperature::BrisiNegativneTemperature() { //prepravi da ne koristis petlje
    auto itmin(minimalne.begin());
    auto itmax(maksimalne.begin());
    while (itmin != minimalne.end() || itmax != maksimalne.end()) {
        if (*itmin < 0 && *itmax < 0) {
            itmin = minimalne.erase(itmin);
            itmax = maksimalne.erase(itmax);  
            continue;
        } 
        itmin++;
        itmax++; 
    }
}
 
int main () {
    Temperature temperature(-20,100);
    temperature.RegistrirajTemperature({-12,10});
    temperature.RegistrirajTemperature({2,15});
    temperature.RegistrirajTemperature({-16,2});
    std::cout << temperature.DajBrojRegistriranihTemperatura() << std::endl;
    try {
        std::cout << temperature.DajMinimalnuTemperaturu() << std::endl; 
        std::cout << temperature.DajMaksimalnuTemperaturu() << std::endl;
        std::cout << temperature.DajBrojTemberaturaVecihOd(10) << std::endl;
        std::cout << temperature.DajBrojTemberaturaManjihOd(5) << std::endl;
    } catch(std::logic_error err) {
        std::cout << err.what() << std::endl;
    }
    ++temperature;
    std::cout << temperature.DajMinimalnuTemperaturu() << std::endl;
    temperature.BrisiSve();
    std::cout << std::boolalpha << !temperature << std::endl;
    std::cout << temperature.DajBrojRegistriranihTemperatura();
	return 0;
}