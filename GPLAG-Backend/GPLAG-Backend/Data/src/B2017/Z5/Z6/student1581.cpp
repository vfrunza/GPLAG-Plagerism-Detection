/B2017/2018: Zadaća 5, Zadatak 6
#include <iostream>
#include <vector>
#include <stdexcept>
#include <algorithm>
#include <functional>
#include <iomanip>

using std::vector;

class Berza{
    vector<int> cijene;
    int min, max;
    
    void Overflow(int change){
        if( (change >= 0 && (DajMaksimalnuCijenu() + change > max)) || (change <= 0 && (DajMinimalnuCijenu() + change < min)) )
            throw std::range_error("Prekoracen dozvoljeni opseg cijena");
    }
public:
    Berza(int min, int max);
    explicit Berza(int max);
    
    void RegistrirajCijenu(int cijena);
    int DajBrojRegistriranihCijena() const { return cijene.size(); }
    void BrisiSve() { cijene.clear(); }
    int DajMinimalnuCijenu() const;
    int DajMaksimalnuCijenu() const;
    bool operator !() const { return cijene.empty(); }
    int DajBrojCijenaVecihOd(int cijena) const;
    void Ispisi() const;
    
    int&& operator [](int i);
    Berza& operator ++ ();
    Berza operator ++ (int temp);
    Berza& operator -- ();
    Berza operator -- (int temp);
    Berza operator -();
    Berza& operator +=(int i);
    Berza& operator -=(int i);
    Berza& operator -=(Berza& b);
    bool operator ==(const Berza& b);
    bool operator !=(const Berza& b);
    friend Berza operator -(Berza b1, Berza& b2);
    Berza operator +(int i);
    Berza operator -(int i);
    friend Berza operator +(int i, Berza& b);
    friend Berza operator -(int i, Berza& b);
};

Berza::Berza(int min, int max) : min(min), max(max) {
    if(min < 0 || max < 0)
        throw std::range_error("Ilegalne granice cijene");
}

Berza::Berza(int max) : min(0), max(max) {
    if(max < 0)
        throw std::range_error("Ilegalne granice cijene");
}

void Berza::RegistrirajCijenu(int cijena){
    if(cijena < min || cijena > max)
        throw std::range_error("Ilegalna cijena");
    
    cijene.push_back(cijena);
}

int Berza::DajMinimalnuCijenu() const {
    if(cijene.empty())
        throw std::range_error("Nema registriranih cijena");
    return *std::min_element(cijene.begin(), cijene.end());
}

int Berza::DajMaksimalnuCijenu() const {
    if(cijene.empty())
        throw std::range_error("Nema registriranih cijena");
    return *std::max_element(cijene.begin(), cijene.end());
}

int Berza::DajBrojCijenaVecihOd(int cijena) const {
    if(cijene.empty())
        throw std::range_error("Nema registriranih cijena");
    
    return std::count_if(cijene.begin(), cijene.end(), std::bind(std::greater<int>(), std::placeholders::_1, cijena));
}

void Berza::Ispisi() const {
    vector<int> temp = cijene;
    
    std::sort(temp.begin(), temp.end(), std::greater<int>());
    
    for(int i = 0; i < temp.size(); i++)
        std::cout << std::fixed << std::setprecision(2) << temp[i]/100. << std::endl;
}

int&& Berza::operator [](int i){
    if(i <= 0 || i > DajBrojRegistriranihCijena())
        throw std::range_error("Neispravan indeks");
    return std::move(cijene[i-1]);
}

Berza& Berza::operator ++ (){
    Overflow(100);
    std::transform(cijene.begin(), cijene.end(), cijene.begin(), std::bind(std::plus<int>(), std::placeholders::_1, 100));
    return *this;
}

Berza Berza::operator ++ (int i){
    Overflow(100);
    Berza temp(*this);
    std::transform(cijene.begin(), cijene.end(), cijene.begin(), std::bind(std::plus<int>(), std::placeholders::_1, 100));
    return temp;
}

Berza& Berza::operator -- (){
    Overflow(-100);
    std::transform(cijene.begin(), cijene.end(), cijene.begin(), std::bind(std::plus<int>(), std::placeholders::_1, -100));
    return *this;
}

Berza Berza::operator -- (int i){
    Overflow(-100);
    Berza temp(*this);
    std::transform(cijene.begin(), cijene.end(), cijene.begin(), std::bind(std::plus<int>(), std::placeholders::_1, -100));
    return temp;
}

Berza Berza::operator -(){
    Berza temp(*this);
    std::transform(temp.cijene.begin(), temp.cijene.end(), temp.cijene.begin(), std::bind(std::minus<int>(), max+min, std::placeholders::_1 ));
    return temp;
}

Berza& Berza::operator +=(int i){
    Overflow(i);
    std::transform(cijene.begin(), cijene.end(), cijene.begin(), std::bind(std::plus<int>(), std::placeholders::_1, i));
    return *this;
}

Berza& Berza::operator -=(int i){
    Overflow(-i);
    std::transform(cijene.begin(), cijene.end(), cijene.begin(), std::bind(std::plus<int>(), std::placeholders::_1, -i));
    return *this;
}

Berza& Berza::operator -=(Berza& b){
    if(*this != b)
        throw std::domain_error("Nesaglasni operandi");
    
    std::transform(cijene.begin(), cijene.end(), b.cijene.begin(), cijene.begin(), std::minus<int>());
    
    Overflow(0);
    return *this;
}

Berza operator -(Berza b1, Berza& b2){
    return b1-=b2;
}

bool Berza::operator ==(const Berza& b){
    return cijene == b.cijene;
}

bool Berza::operator !=(const Berza& b){
    return !(*this == b);
}

Berza Berza::operator +(int i){
    return (*this) += i;
}

Berza Berza::operator -(int i){
    return (*this) -= i;
}

Berza operator +(int i, Berza& b){
    Berza temp(b);
    std::transform(b.cijene.begin(), b.cijene.end(), temp.cijene.begin(), std::bind(std::plus<int>(), i, std::placeholders::_1 ));
    temp.Overflow(0);
    return temp;
}

Berza operator -(int i, Berza& b){
    Berza temp(b);
    std::transform(b.cijene.begin(), b.cijene.end(), temp.cijene.begin(), std::bind(std::minus<int>(), i, std::placeholders::_1 ));
    temp.Overflow(0);
    return temp;
}


int main () {
    
    Berza berza1(1000);
    Berza berza2(1000);
    
    berza1.RegistrirajCijenu(100);
    berza1.RegistrirajCijenu(75);
    berza1.RegistrirajCijenu(10);
    berza1.RegistrirajCijenu(45);
    berza1.RegistrirajCijenu(30);
    
    berza2.RegistrirajCijenu(120);
    berza2.RegistrirajCijenu(80);
    berza2.RegistrirajCijenu(20);
    berza2.RegistrirajCijenu(64);
    berza2.RegistrirajCijenu(37);
    
    try{
        berza1.Ispisi();
        std::cout << std::endl;
        berza2.Ispisi();
        std::cout << std::endl;
        
        berza2 = -berza1;
        berza2.Ispisi();
        
    }catch(std::exception &err){
        std::cout << "Izuzetak: " << err.what();
        return 0;
    }
    
    
	return 0;
}
