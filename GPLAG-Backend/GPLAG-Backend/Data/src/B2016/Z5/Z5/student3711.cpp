#include <iostream>
#include <algorithm>
#include <iomanip>
#include <iterator>
#include <list>

class Temperature {
private:
    int minimalna, maksimalna;
    std::list<int> temperature_lista;
        
public:
    // radi
    Temperature(int x, int y) {
        if (x > y) throw std::range_error("Nekorektne temperature");
        else {
            minimalna = x;
            maksimalna = y; 
        }
    }
    
    // radi -> PREPRAVITI: pair !!!!
    void RegistrirajTemperature(std::pair<int,int> temp_za_upis) {
        if (temp_za_upis.first>temp_za_upis.second){
            throw std::range_error("“Nekorektne temperature");
        } else{
            temperature_lista.push_back(temp_za_upis.first);
            temperature_lista.push_back(temp_za_upis.second);
        } 
    }
    
    // radi
    int DajBrojRegistriranihTemperatura() const {
        return temperature_lista.size();
    }
    
    // radi
    void BrisiSve() {
        temperature_lista.resize(0);
    }
    
    // radi
    int DajMinimalnuTemperaturu() const {
        if (temperature_lista.size() == 0) throw std::range_error("Nema registriranih temperatura");
        return *(std::min_element(temperature_lista.begin(), temperature_lista.end(), std::less<int>()));
    }
    
    // radi
    int DajMaksimalnuTemperaturu() const {
        if (temperature_lista.size() == 0) throw std::range_error("Nema registriranih temperatura");
        return *(std::max_element(temperature_lista.begin(), temperature_lista.end(), std::less<int>()));
    }
    
    int DajBrojTemperaturaVecihOd (int x) const {
        if (temperature_lista.size() == 0) throw std::range_error("Nema registriranih temperatura");
        return std::count_if(temperature_lista.begin(), temperature_lista.end(), std::bind(std::greater<int>(), std::placeholders::_1, x));
    }
    
    // OSTALE Fcije:
    bool operator !() const;
    int operator [](int n) const;
    Temperature &operator += (int x);
    Temperature &operator -= (int x);
    Temperature &operator -= (const Temperature &x);
    friend bool operator == (const Temperature &x, const Temperature &y);
    friend bool operator != (const Temperature &x, const Temperature &y);
    friend Temperature operator - (const Temperature &x, const Temperature &y);
    friend Temperature operator + (const Temperature &x, int y);
    friend Temperature operator - (const Temperature &x, int y);
    friend Temperature operator + (int x, const Temperature &y);
    friend Temperature operator - (int x, const Temperature &y);
    friend Temperature operator - (const Temperature &x);
    friend Temperature operator ++ (Temperature &x, int);
    friend Temperature operator -- (Temperature &x, int);
    friend Temperature &operator ++ (Temperature &x);
    friend Temperature &operator -- (Temperature &x);
};

bool Temperature::operator !()  const{
    if (temperature_lista.size() == 0) return true;
    else return false;
}

int Temperature::operator [](int n) const {
    std::list<int>::iterator it;
    if (n > temperature_lista.size() || n < 0) throw std::range_error("Neispravan indeks");
    for(int i=0; i<n; i++){
        it++;
    }
    return *it;
}

Temperature &Temperature::operator += (int x) {
    *this = *this + x;
    return *this;
}

Temperature &Temperature::operator -= (int x) {
    *this = *this - x;
    return *this;
}

Temperature &Temperature::operator -= (const Temperature &x) {
    Temperature pom = *this;
    if (x.temperature_lista.size() == temperature_lista.size()) {
        std::transform(pom.temperature_lista.begin(), pom.temperature_lista.end(), x.temperature_lista.begin(), pom.temperature_lista.begin(), std::bind(std::minus<int>(), std::placeholders::_1, std::placeholders::_2));
        int h = std::count_if(pom.temperature_lista.begin(), pom.temperature_lista.end(), std::bind(std::greater<int>(), std::placeholders::_1, this->maksimalna));
        int j = std::count_if(pom.temperature_lista.begin(), pom.temperature_lista.end(), std::bind(std::less<int>(), std::placeholders::_1, this->minimalna));
        if (h > 0 || j > 0) throw std::domain_error ("Prekoracen dozvoljeni opseg temperatura");
        else *this = pom;
    }   
    return *this;
}

Temperature operator - (const Temperature &x) {
    Temperature pom = x;
    std::transform(pom.temperature_lista.begin(), pom.temperature_lista.end(), pom.temperature_lista.begin(), std::bind(std::minus<int>(), pom.maksimalna + pom.minimalna, std::placeholders::_1));
    return pom;
}

Temperature operator + (const Temperature &x, int y) {
    Temperature pom = x;
    int h = std::count_if(x.temperature_lista.begin(), x.temperature_lista.end(), std::bind(std::greater<int>(), std::bind(std::plus<int>(), std::placeholders::_1 , y), x.maksimalna));
    int j = std::count_if(x.temperature_lista.begin(), x.temperature_lista.end(), std::bind(std::less<int>(), std::bind(std::plus<int>(), std::placeholders::_1 , y), x.minimalna));
    if (h > 0 || j > 0) throw std::domain_error ("Prekoracen dozvoljeni opseg temperatura");
    std::transform(pom.temperature_lista.begin(), pom.temperature_lista.end(), pom.temperature_lista.begin(), std::bind(std::plus<int>(), std::placeholders::_1, y));
    return pom;
}

Temperature operator - (const Temperature &x, int y) {
    Temperature pom = x;
    int h = std::count_if(x.temperature_lista.begin(), x.temperature_lista.end(), std::bind(std::greater<int>(), std::bind(std::minus<int>(), std::placeholders::_1 , y), x.maksimalna));
    int j = std::count_if(x.temperature_lista.begin(), x.temperature_lista.end(), std::bind(std::less<int>(), std::bind(std::minus<int>(), std::placeholders::_1 , y), x.minimalna));
    if (h > 0 || j > 0) throw std::domain_error ("Prekoracen dozvoljeni opseg temperatura");
    std::transform(pom.temperature_lista.begin(), pom.temperature_lista.end(), pom.temperature_lista.begin(), std::bind(std::minus<int>(), std::placeholders::_1, y));
    return pom;

}

Temperature operator + (int x, const Temperature &y) {
    return y + x;
}

Temperature operator - (int x, const Temperature &y) {
    Temperature pom = y;
    int h = std::count_if(y.temperature_lista.begin(), y.temperature_lista.end(), std::bind(std::greater<int>(), std::bind(std::minus<int>(), x, std::placeholders::_1), y.maksimalna));
    int j = std::count_if(y.temperature_lista.begin(), y.temperature_lista.end(), std::bind(std::less<int>(), std::bind(std::minus<int>(), x, std::placeholders::_1), y.minimalna));
    if (h > 0 || j > 0) throw std::domain_error ("Prekoracen dozvoljeni opseg cijena");
    std::transform(pom.temperature_lista.begin(), pom.temperature_lista.end(), pom.temperature_lista.begin(), std::bind(std::minus<int>(), x, std::placeholders::_1));
    return pom;
}

Temperature operator - (const Temperature &x, const Temperature &y) {
    if (x.temperature_lista.size() == y.temperature_lista.size() || x.maksimalna == y.maksimalna || y.minimalna == y.minimalna)
        throw std::domain_error("Nesaglasni operandi");
        auto pom = x;
        pom -= y;
        return pom;
}

bool operator == (const Temperature &x, const Temperature &y) {
    if (x.temperature_lista.size() != y.temperature_lista.size()) return false;
    bool brojac = std::equal(x.temperature_lista.begin(), x.temperature_lista.end(), y.temperature_lista.begin(), std::bind(std::equal_to<int>(), std::placeholders::_1, std::placeholders::_2));
    if (brojac) return true;
    else return false;
}

bool operator != (const Temperature &x, const Temperature &y) {
    if (x == y) return false;
    else return true;
}

Temperature &operator ++(Temperature &x) {
    try {
        x = x + 100.;
        return x;
    }
    catch(std::domain_error) {
        throw std::range_error ("Prekoracen dozvoljeni opseg cijena");
    }
}

Temperature &operator --(Temperature &x) {
    try {
        x = x - 100.;
        return x;
    }
    catch(std::domain_error) {
        throw std::range_error ("Prekoracen dozvoljeni opseg cijena");
    }
}

Temperature operator ++(Temperature &x, int) {
    Temperature pomocni = x;
    ++x;
    return pomocni;
}

Temperature operator --(Temperature &x, int) {
    Temperature pomocni = x;
    --x;
    return pomocni;
}
    
// GLAVNA FCIJA    
int main() {
    try {
        std::cout << "Kompajlira se!";
        Temperature(10, 20);
    } catch (std::range_error Izuzetak){
        std::cout << Izuzetak.what();
    }
    return 0;
}