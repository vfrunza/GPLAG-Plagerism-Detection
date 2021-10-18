/B2017/2018: Zadaća 5, Zadatak 6
#include <iostream>
#include <vector>
#include <stdexcept>
#include <algorithm>
#include <functional>
#include <iomanip>

class Berza {
    std::vector<int> cijene;
    int min_cijena, max_cijena;
    bool IspravanIndeks(int indeks) const {
        return indeks>=1 && indeks<=cijene.size();
    }
public:
    Berza(int min_cijena, int max_cijena) : 
    min_cijena(min_cijena), max_cijena(max_cijena) {
        if (min_cijena<=0 || max_cijena<=0)
            throw std::range_error("Ilegalne granicne cijene");
    }
    explicit Berza(int max_cijena) : 
    min_cijena(0), max_cijena(max_cijena) {
        if (max_cijena<=0)
            throw std::range_error("Ilegalne granicne cijene");
    }
    void RegistrirajCijenu(int cijena);
    int DajBrojRegistriranihCijena() const {
        return cijene.size();
    }
    void BrisiSve() {
        cijene.resize(0);
    }
    int DajMinimalnuCijenu() const;
    int DajMaksimalnuCijenu() const;
    bool operator !() const;
    int DajBrojCijenaVecihOd(int cijena) const;
    void Ispisi() const;
    int operator [](int indeks) const;
    Berza operator -() const;
    Berza &operator ++();
    Berza operator ++(int);
    Berza &operator --();
    Berza operator --(int);
    Berza &operator +=(int broj);
    Berza &operator -=(int broj);
    Berza &operator -=(const Berza &b);
    friend Berza operator +(const Berza &b, int broj);
    friend Berza operator -(const Berza &b, int broj);
    friend Berza operator +(int broj, const Berza &b);
    friend Berza operator -(int broj, const Berza &b);
    friend Berza operator -(const Berza &b1, const Berza &b2);
    friend bool operator ==(const Berza &b1, const Berza &b2);
    friend bool operator !=(const Berza &b1, const Berza &b2);
};

Berza &Berza::operator +=(int broj) {
    std::vector<int> vektor_cijena;
    vektor_cijena.resize(cijene.size());
    std::copy(cijene.begin(), cijene.end(), vektor_cijena.begin());
    std::transform(vektor_cijena.begin(), vektor_cijena.end(), vektor_cijena.begin(), 
     std::bind(std::plus<int>(), std::placeholders::_1, broj));
    auto iter=std::find_if(vektor_cijena.begin(), vektor_cijena.end(), 
     std::bind(std::greater<int>(), std::placeholders::_1, max_cijena));
    if (iter!=vektor_cijena.end()) throw std::range_error("Prekoracen dozvoljeni opseg cijena");
    std::copy(vektor_cijena.begin(), vektor_cijena.end(), cijene.begin());
    return *this;
}

Berza &Berza::operator -=(int broj) {
    std::vector<int> vektor_cijena;
    vektor_cijena.resize(cijene.size());
    std::copy(cijene.begin(), cijene.end(), vektor_cijena.begin());
    std::transform(vektor_cijena.begin(), vektor_cijena.end(), vektor_cijena.begin(), 
     std::bind(std::minus<int>(), std::placeholders::_1, broj));
    auto iter=std::find_if(vektor_cijena.begin(), vektor_cijena.end(), 
     std::bind(std::less<int>(), std::placeholders::_1, min_cijena));
    if (iter!=vektor_cijena.end()) throw std::range_error("Prekoracen dozvoljeni opseg cijena");
    std::copy(vektor_cijena.begin(), vektor_cijena.end(), cijene.begin());
    return *this;
}

Berza &Berza::operator -=(const Berza &b) {
    if (DajBrojRegistriranihCijena()!=b.DajBrojRegistriranihCijena())
        throw std::domain_error("Nesaglasni operandi");
    if (min_cijena!=b.min_cijena || max_cijena!=b.max_cijena)
        throw std::domain_error("Nesaglasni operandi");
    std::vector<int> vektor_cijena;
    vektor_cijena.resize(cijene.size());
    std::copy(cijene.begin(), cijene.end(), vektor_cijena.begin());
    std::transform(vektor_cijena.begin(), vektor_cijena.end(), b.cijene.begin(), 
     vektor_cijena.begin(), std::minus<int>());
    auto iter=std::find_if(vektor_cijena.begin(), vektor_cijena.end(), 
     std::bind(std::less<int>(), std::placeholders::_1, min_cijena));
    if (iter!=vektor_cijena.end()) throw std::range_error("Prekoracen dozvoljeni opseg cijena");
    std::copy(vektor_cijena.begin(), vektor_cijena.end(), cijene.begin());
    return *this;
}

Berza operator +(const Berza &b, int broj) {
    Berza berza(b);
    berza+=broj;
    return berza;
}

Berza operator -(const Berza &b, int broj) {
    Berza berza(b);
    berza-=broj;
    return berza;
}

Berza operator +(int broj, const Berza &b) {
    return b+broj;
}

Berza operator -(int broj, const Berza &b) {
    Berza berza(b);
    std::transform(berza.cijene.begin(), berza.cijene.end(), berza.cijene.begin(), 
     std::bind(std::minus<int>(), broj, std::placeholders::_1));
    auto iter=std::find_if(berza.cijene.begin(), berza.cijene.end(), 
     std::bind(std::less<int>(), std::placeholders::_1, b.min_cijena));
    if (iter!=berza.cijene.end())
        throw std::range_error("Prekoracen dozvoljeni opseg cijena");
    return berza;
}

Berza operator -(const Berza &b1, const Berza &b2) {
    Berza berza(b1);
    berza-=b2;
    return berza;
}

bool operator !=(const Berza &b1, const Berza &b2) {
    return !(b1==b2);
}

Berza &Berza::operator ++() {
    std::vector<int> vektor_cijena;
    vektor_cijena.resize(cijene.size());
    std::copy(cijene.begin(), cijene.end(), vektor_cijena.begin());
    std::transform(vektor_cijena.begin(), vektor_cijena.end(), vektor_cijena.begin(), 
     std::bind(std::plus<int>(), std::placeholders::_1, 100));
    auto iter=std::find_if(vektor_cijena.begin(), vektor_cijena.end(), 
     std::bind(std::greater<int>(), std::placeholders::_1, max_cijena));
    if (iter!=vektor_cijena.end())
        throw std::range_error("Prekoracen dozvoljeni opseg cijena");
    std::copy(vektor_cijena.begin(), vektor_cijena.end(), cijene.begin());
    return *this;
}

Berza Berza::operator ++(int) {
    Berza pomocna(*this);
    ++(*this);
    return pomocna;
}

Berza &Berza::operator --() {
    std::vector<int> vektor_cijena;
    vektor_cijena.resize(cijene.size());
    std::copy(cijene.begin(), cijene.end(), vektor_cijena.begin());
    std::transform(vektor_cijena.begin(), vektor_cijena.end(), vektor_cijena.begin(), 
     std::bind(std::minus<int>(), std::placeholders::_1, 100));
    auto iter=std::find_if(vektor_cijena.begin(), vektor_cijena.end(), 
     std::bind(std::less<int>(), std::placeholders::_1, min_cijena));
    if (iter!=vektor_cijena.end())
        throw std::range_error("Prekoracen dozvoljeni opseg cijena");
    std::copy(vektor_cijena.begin(), vektor_cijena.end(), cijene.begin());
    return *this;
}

Berza Berza::operator --(int) {
    Berza pomocna(*this);
    --(*this);
    return pomocna;
}

Berza Berza::operator -() const {
    Berza b(min_cijena, max_cijena);
    b.cijene.resize(cijene.size());
    std::copy(cijene.begin(), cijene.end(), b.cijene.begin());
    int suma_cijena(min_cijena+max_cijena);
    std::transform(b.cijene.begin(), b.cijene.end(), b.cijene.begin(), 
     std::bind(std::minus<int>(), suma_cijena, std::placeholders::_1));
    return b;
}

bool operator ==(const Berza &b1, const Berza &b2) {
    return b1.cijene.size()==b2.cijene.size() 
     && std::equal(b1.cijene.begin(), b1.cijene.end(), b2.cijene.begin(), std::equal_to<int>());
}

int Berza::operator [](int i) const {
    if (!IspravanIndeks(i)) throw std::range_error("Neispravan indeks");
    return cijene[i-1];
}

void Berza::Ispisi() const {
    std::vector<int> vektor_cijena;
    vektor_cijena.resize(cijene.size());
    std::copy(cijene.begin(), cijene.end(), vektor_cijena.begin());
    std::sort(vektor_cijena.begin(), vektor_cijena.end(), std::greater<int>());
    for (auto iter=vektor_cijena.begin(); iter!=vektor_cijena.end(); iter++) {
        std::cout << std::fixed << std::setprecision(2) << (*iter)/100.;
        std::cout << std::endl;
    }
}

int Berza::DajBrojCijenaVecihOd(int cijena) const {
    if (cijene.size()==0) throw std::range_error("Nema registriranih cijena");
    return std::count_if(cijene.begin(), cijene.end(), 
     std::bind(std::greater<int>(), std::placeholders::_1, cijena));
}

bool Berza::operator !() const {
    if (DajBrojRegistriranihCijena()==0) return true;
    return false;
}

void Berza::RegistrirajCijenu(int cijena) {
    if (cijena<min_cijena || cijena>max_cijena)
        throw std::range_error("Ilegalna cijena");
    cijene.push_back(cijena);
}

int Berza::DajMinimalnuCijenu() const {
    if (cijene.size()==0)
        throw std::range_error("Nema registriranih cijena");
    return *std::min_element(cijene.begin(), cijene.end(), std::less<int>());
}

int Berza::DajMaksimalnuCijenu() const {
    if (cijene.size()==0)
        throw std::range_error("Nema registriranih cijena");
    return *std::max_element(cijene.begin(), cijene.end(), std::less<int>());
}


int main ()
{
	return 0;
}
