/B2017/2018: Zadaća 5, Zadatak 6
#include <iostream>
#include <vector>
#include <stdexcept>
#include <algorithm>
#include <functional>
#include <iomanip>


class Berza{
    std::vector<int> cijene;
    int minimalna, maksimalna;
public:
    Berza(int minimalna, int maksimalna);
    explicit Berza(int maksimalna);
    void RegistrirajCijenu(int cijena);
    int DajBrojRegistriranihCijena() const;
    void BrisiSve();
    int DajMinimalnuCijenu() const;
    int DajMaksimalnuCijenu() const;
    bool operator !(){ if((*this).cijene.size() == 0) return true; else return false; }
    int DajBrojCijenaVecihOd(int cijena) const;
    void Ispisi() const;
    int &operator [](int indeks);
    friend Berza &operator ++(Berza &prvo);
    friend Berza &operator ++(Berza &prvo, int);
    friend Berza &operator --(Berza &prvo);
    friend Berza &operator --(Berza &prvo, int);
    Berza &operator -();
    friend Berza operator +(const Berza &prvo, const int &zakoliko);
    friend Berza operator +(const int &zakoliko, const Berza &prvo);
    friend Berza operator -(const Berza &prvo, const int &zakoliko);
    friend Berza operator -(const int &zakoliko, const Berza &prvo);
    friend Berza operator +(const Berza &prvo, const Berza &drugo);
    friend Berza operator -(const Berza &prvo, const Berza &drugo);
    friend Berza &operator +=(Berza &prvo, const int &zakoliko);
    friend Berza &operator +=(Berza &prvo, const Berza &drugo);
    friend Berza &operator -=(Berza &prvo, const int &zakoliko);
    friend Berza &operator -=(Berza &prvo, const Berza &drugo);
    friend bool operator ==(const Berza &prvo, const Berza &drugo);
    friend bool operator !=(const Berza &prvo, const Berza &drugo);
};

Berza::Berza(int minimalna, int maksimalna){
    if(minimalna < 0 || maksimalna < 0 || minimalna > maksimalna) throw std::range_error("Ilegalne granicne cijene");
    Berza::minimalna = minimalna; Berza::maksimalna = maksimalna;
}

Berza::Berza(int maksimalna) : minimalna(0){
    if(maksimalna < 0) throw std::range_error("Ilegalne granicne cijene");
    Berza::maksimalna = maksimalna;
}

void Berza::RegistrirajCijenu(int cijena){
    if(cijena > maksimalna || cijena < minimalna) throw std::range_error("Ilegalna cijena");
    (*this).cijene.push_back(cijena);
}

int Berza::DajBrojRegistriranihCijena() const{
    return (*this).cijene.size();
}

void Berza::BrisiSve(){
    (*this).cijene.clear();
}

int Berza::DajMinimalnuCijenu() const{
    return (*std::min_element((*this).cijene.begin(), (*this).cijene.end()));
}

int Berza::DajMaksimalnuCijenu() const{
    return (*std::max_element((*this).cijene.begin(), (*this).cijene.end()));
}

int Berza::DajBrojCijenaVecihOd(int cijena) const{
    if((*this).cijene.size() == 0) throw std::range_error("Nema registriranih cijena");
    int broj = std::count_if((*this).cijene.begin(), (*this).cijene.end(), std::bind(std::less<int> (), cijena, std::placeholders::_1));
    return broj;
}

void Berza::Ispisi() const{
    Berza novo = (*this);
    std::sort(novo.cijene.begin(), novo.cijene.end(), std::greater<int>());
    for(auto &i : novo.cijene){
        std::cout << std::fixed;
        std::cout << std::setprecision(2);
        std::cout << i/100. << std::endl;
    }
}

int &Berza::operator [](int indeks){
    if(indeks < 0 || indeks > (*this).cijene.size()) throw std::range_error("Neispravan indeks");
    return cijene[indeks];
}

Berza &operator ++(Berza &prvo){
    Berza novo(prvo);
    std::transform(novo.cijene.begin(), novo.cijene.end(), novo.cijene.begin(), std::bind(std::plus<int>(), 100, std::placeholders::_1));
    int brojac = std::count_if(novo.cijene.begin(), novo.cijene.end(), std::bind(std::greater<int>(), std::placeholders::_1, novo.maksimalna));
    if(brojac != 0) throw std::range_error("Prekoracen dozvoljeni opseg cijena");
    prvo = novo;
    return prvo;
}

Berza &operator ++(Berza &prvo, int){
    Berza novo(prvo);
    std::transform(novo.cijene.begin(), novo.cijene.end(), novo.cijene.begin(), std::bind(std::plus<int>(), 100, std::placeholders::_1));
    int brojac = std::count_if(novo.cijene.begin(), novo.cijene.end(), std::bind(std::greater<int>(), std::placeholders::_1, novo.maksimalna));
    if(brojac != 0) throw std::range_error("Prekoracen dozvoljeni opseg cijena");
    prvo = novo;
    return prvo;
}

Berza &operator --(Berza &prvo){
    Berza novo(prvo);
    std::transform(novo.cijene.begin(), novo.cijene.end(), novo.cijene.begin(), std::bind(std::minus<int>(), std::placeholders::_1, 100));
    int brojac = std::count_if(novo.cijene.begin(), novo.cijene.end(), std::bind(std::less<int>(), std::placeholders::_1, novo.minimalna));
    if(brojac != 0) throw std::range_error("Prekoracen dozvoljeni opseg cijena");
    prvo = novo;
    return prvo;
}

Berza &operator --(Berza &prvo, int){
    Berza novo(prvo);
    std::transform(novo.cijene.begin(), novo.cijene.end(), novo.cijene.begin(), std::bind(std::minus<int>(), std::placeholders::_1, 100));
    int brojac = std::count_if(novo.cijene.begin(), novo.cijene.end(), std::bind(std::less<int>(), std::placeholders::_1, novo.minimalna));
    if(brojac != 0) throw std::range_error("Prekoracen dozvoljeni opseg cijena");
    prvo = novo;
    return prvo;
}

Berza &Berza::operator -(){
    std::transform((*this).cijene.begin(), (*this).cijene.end(), (*this).cijene.begin(), std::bind(std::minus<int>(), (*this).maksimalna + (*this).minimalna, std::placeholders::_1));
    return *this;
}

Berza operator +(const Berza &prvo, const int &zakoliko){
    Berza novi(prvo);
    std::transform(novi.cijene.begin(), novi.cijene.end(), novi.cijene.begin(), std::bind(std::plus<int>(), zakoliko, std::placeholders::_1));
    int brojac = std::count_if(novi.cijene.begin(), novi.cijene.end(), std::bind(std::greater<int>(), std::placeholders::_1, novi.maksimalna));
    if(brojac != 0) throw std::domain_error("Prekoracen dozvoljeni opseg cijena");
    return novi;
}

Berza operator +(const int &zakoliko, const Berza &prvo){
    Berza novi(prvo);
    std::transform(novi.cijene.begin(), novi.cijene.end(), novi.cijene.begin(), std::bind(std::plus<int>(), zakoliko, std::placeholders::_1));
    int brojac = std::count_if(novi.cijene.begin(), novi.cijene.end(), std::bind(std::greater<int>(), std::placeholders::_1, novi.maksimalna));
    if(brojac != 0) throw std::domain_error("Prekoracen dozvoljeni opseg cijena");
    return novi;
}

Berza operator -(const Berza &prvo, const int &zakoliko){
    Berza novi(prvo);
    std::transform(novi.cijene.begin(), novi.cijene.end(), novi.cijene.begin(), std::bind(std::minus<int>(), std::placeholders::_1, zakoliko));
    int brojac = std::count_if(novi.cijene.begin(), novi.cijene.end(), std::bind(std::less<int>(), std::placeholders::_1, novi.minimalna));
    if(brojac != 0) throw std::domain_error("Prekoracen dozvoljeni opseg cijena");
    return novi;
}

Berza operator -(const int &zakoliko, const Berza &prvo){
    Berza novi(prvo);
    std::transform(novi.cijene.begin(), novi.cijene.end(), novi.cijene.begin(), std::bind(std::minus<int>(), std::placeholders::_1, zakoliko));
    int brojac = std::count_if(novi.cijene.begin(), novi.cijene.end(), std::bind(std::less<int>(), std::placeholders::_1, novi.minimalna));
    if(brojac != 0) throw std::domain_error("Prekoracen dozvoljeni opseg cijena");
    return novi;
}

Berza operator +(const Berza &prvo, const Berza &drugo){
    if(prvo.cijene.size() != drugo.cijene.size() || prvo.minimalna != drugo.minimalna || prvo.maksimalna != drugo.maksimalna) throw std::domain_error("Nesaglasni operandi");
    Berza novo(prvo);
    std::transform(prvo.cijene.begin(), prvo.cijene.end(), drugo.cijene.begin(), novo.cijene.begin(), std::bind(std::plus<int>(), std::placeholders::_1, std::placeholders::_2));
    int brojac = std::count_if(novo.cijene.begin(), novo.cijene.end(), std::bind(std::greater<int>(), std::placeholders::_1, novo.maksimalna));
    if(brojac != 0) throw std::domain_error("Prekoracen dozvoljeni opseg cijena");
    return novo;
}

Berza operator -(const Berza &prvo, const Berza &drugo){
    if(prvo.cijene.size() != drugo.cijene.size() || prvo.minimalna != drugo.minimalna || prvo.maksimalna != drugo.maksimalna) throw std::domain_error("Nesaglasni operandi");
    Berza novo(prvo);
    std::transform(prvo.cijene.begin(), prvo.cijene.end(), drugo.cijene.begin(), novo.cijene.begin(), std::bind(std::minus<int>(), std::placeholders::_1, std::placeholders::_2));
    int brojac = std::count_if(novo.cijene.begin(), novo.cijene.end(), std::bind(std::less<int>(), std::placeholders::_1, novo.minimalna)); 
    if(brojac != 0) throw std::domain_error("Prekoracen dozvoljeni opseg cijena");
    return novo;
}

Berza &operator +=(Berza &prvo, const int &zakoliko){
    prvo = prvo + zakoliko;
    return prvo;
}

Berza &operator +=(Berza &prvo, const Berza &drugo){
    prvo = prvo + drugo;
    return prvo;
}

Berza &operator -=(Berza &prvo, const int &zakoliko){
    prvo = prvo - zakoliko;
    return prvo;
}

Berza &operator -=(Berza &prvo, const Berza &drugo){
    prvo = prvo - drugo;
    return prvo;
}

bool operator ==(const Berza &prvo, const Berza &drugo){
    bool tacno = std::equal(prvo.cijene.begin(), prvo.cijene.end(), drugo.cijene.begin());
    if(prvo.maksimalna != drugo.maksimalna || prvo.minimalna != drugo.minimalna) tacno = false;
    return tacno;
}

bool operator !=(const Berza &prvo, const Berza &drugo){
    bool tacno = std::equal(prvo.cijene.begin(), prvo.cijene.end(), drugo.cijene.begin());
    tacno = !tacno;
    if(prvo.maksimalna == drugo.maksimalna || prvo.minimalna == drugo.minimalna) tacno = true;
    return tacno;
}


int main ()
{
    
    Berza b1 = Berza(1000,4000);
    b1.RegistrirajCijenu(2700);
    b1.RegistrirajCijenu(2500);
    b1.RegistrirajCijenu(2400);
    Berza b2 = Berza(1000, 4000);
    b2.RegistrirajCijenu(1000);
    b2.RegistrirajCijenu(1200);
    b2.RegistrirajCijenu(1300);
    //b2.Ispisi();
    b1++;
    ++b1;
    b1--;
    --b1;
    //-b1;
    b1 = 100 + b1;
    b1 = b1 + 100;
    b1 = b1 - 100;
    b1 = 100 - b1;
    b1 = b1 - b2;
    b1 = b1 + b2;
    b1+= 100;
    b1-= 100;
    b1+= b2;
    b1-= b2;
    b1[1] = 1300;
    std::cout << b1.DajMinimalnuCijenu();
    
    std::cout << "Broj registrovanih cijena: " << b1.DajBrojRegistriranihCijena() << std::endl;
    b1.Ispisi();
    b1.BrisiSve();
    std::cout << "Broj registrovanih cijena: " << b1.DajBrojRegistriranihCijena();

    
    
	return 0;
}
