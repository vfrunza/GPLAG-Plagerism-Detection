/B2017/2018: Zadaća 5, Zadatak 6
#include <iostream>
#include <vector>
#include <algorithm>
#include <stdexcept>
#include <functional>
#include <iomanip>

class Berza {
    std::vector<int> dionice;
    int minimalna, maksimalna;
    Berza()=default;
    public:
    Berza(int min, int max) {
        if(min<0 || max<0) throw std::range_error("Ilegalne granicne cijene");
        minimalna=min; maksimalna=max;
    }
    explicit Berza(int max) {
        if(max<0) throw std::range_error("Ilegalne granicne cijene");
        minimalna=0; maksimalna=max;
    }
    void RegistrirajCijenu(int cijena);
    int DajBrojRegistriranihCijena() const;
    void BrisiSve();
    int DajMinimalnuCijenu() const;
    int DajMaksimalnuCijenu() const;
    bool operator! ();
    int DajBrojVecihOd(int x) const;
    void Ispisi() const;
    int operator[] (int indeks) const;
    Berza &operator ++();
    Berza operator ++(int=0);
    Berza &operator --();
    Berza operator --(int=0);
    Berza operator -();
    Berza operator + (int x);
    Berza operator - (int x);
  //  Berza operator - (int x, Berza b);
 //   Berza operator + (Berza b1, Berza b2);
    Berza operator - (Berza b2);
    Berza operator +=(int x);
    Berza operator -=(int x);
    bool operator == (Berza b);
    bool operator !=(Berza b);
};

void Berza::RegistrirajCijenu(int cijena) {
    if(cijena<minimalna || cijena>maksimalna) throw std::range_error("Ilegalna cijena");
    dionice.push_back(cijena);
}
int Berza::DajBrojRegistriranihCijena() const {
    return dionice.size();
}
void Berza::BrisiSve() {
    dionice.clear();
}
int Berza::DajMinimalnuCijenu()const {
    if(dionice.empty()) throw std::range_error("Nema registriranih cijena");
    return *(std::min_element(dionice.begin(), dionice.end()));
}
int Berza::DajMaksimalnuCijenu() const {
    if(dionice.empty()) throw std::range_error("Nema registriranih cijena");
    return *(std::max_element(dionice.begin(), dionice.end()));
}
bool Berza::operator! () {
    return dionice.empty();
}
int Berza::DajBrojVecihOd(int x) const {
    if(dionice.empty()) throw std::range_error("Nema registriranih cijena");
    return std::count_if(dionice.begin(), dionice.end(), std::bind(std::greater<int>(), std::placeholders::_1, x));
}
void Berza::Ispisi() const {
    std::vector<int> pom;
    pom=this->dionice;
    std::sort(pom.begin(), pom.end(),  std::bind(std::greater<int>(), std::placeholders::_1, std::placeholders::_2));
    for(int i=0; i<pom.size(); i++) {
        double marke(pom[i]/100.);
        std::cout<<std::fixed<<std::setprecision(2)<<marke<<std::endl;
    }
}
int Berza::operator[] (int indeks) const {
    if(indeks<=0 || indeks>dionice.size()) throw std::range_error("Neispravan indeks");
    return dionice[indeks-1];
}
Berza &Berza::operator ++() {
    if(std::find_if(dionice.begin(), dionice.end(), std::bind(std::greater<int>(), std::placeholders::_1, maksimalna-100))!=dionice.end())
    throw std::range_error("Prekoracen dozvoljeni opseg cijena");
    else
    std::transform(dionice.begin(), dionice.end(), dionice.begin(), std::bind(std::plus<int>(), std::placeholders::_1, 100));
    return *this;
}
Berza Berza::operator ++(int=0) {
    auto povratni(*this);
    povratni.dionice=dionice;
    if(std::find(dionice.begin(), dionice.end(), maksimalna-100)!=dionice.end())
    throw std::range_error("Prekoracen dozvoljeni opseg cijena");
    else
    std::for_each(dionice.begin(), dionice.end(), std::bind(std::plus<int>(), std::placeholders::_1, 100));
    return povratni;
}
Berza &Berza::operator --() {
    if(std::find_if(dionice.begin(), dionice.end(),std::bind(std::less<int>(), std::placeholders::_1, minimalna+100))!=dionice.end())
    throw std::range_error("Prekoracen dozvoljeni opseg cijena");
    else
    std::transform(dionice.begin(), dionice.end(), dionice.begin(), std::bind(std::minus<int>(), std::placeholders::_1, 100));
    return *this;
}
Berza Berza::operator --(int=0) {
    auto povratni(*this);
    if(std::find_if(dionice.begin(), dionice.end(),std::bind(std::less<int>(), std::placeholders::_1, minimalna+100))!=dionice.end())
    throw std::range_error("Prekoracen dozvoljeni opseg cijena");
    else
    std::for_each(dionice.begin(), dionice.end(), std::bind(std::minus<int>(), std::placeholders::_1, 100));    
    return povratni;
}
Berza Berza::operator -() {
    Berza povratni;
    int cijena(maksimalna+minimalna);
    povratni.dionice=dionice;
    std::transform(povratni.dionice.begin(), povratni.dionice.end(), povratni.dionice.begin(), std::bind(std::minus<int>(), cijena, std::placeholders::_1));
    return povratni;
}
Berza Berza::operator + (int x) {
    Berza povratni;
    povratni.dionice=dionice;
    if(std::find_if(povratni.dionice.begin(),povratni.dionice.end(), std::bind(std::greater<int>(), std::placeholders::_1, maksimalna-x))!=povratni.dionice.end())
    throw std::domain_error("Prekoracen dozvoljeni opseg cijena");
    std::transform(povratni.dionice.begin(), povratni.dionice.end(),povratni.dionice.begin(), std::bind(std::plus<int>(), std::placeholders::_1, x));
    return povratni;
}/*
Berza Berza::operator + (int x, Berza b) {
    auto povratni(b+x);
}*/
Berza Berza::operator - (int x) {
    Berza povratni;
    povratni.dionice=dionice;
    if(std::find_if(povratni.dionice.begin(),povratni.dionice.end(), std::bind(std::less<int>(), std::placeholders::_1, minimalna+x))!=povratni.dionice.end())
    throw std::domain_error("Prekoracen dozvoljeni opseg cijena");
    else
    std::transform(povratni.dionice.begin(),povratni.dionice.end(), povratni.dionice.begin(), std::bind(std::minus<int>(), std::placeholders::_1, x));
    return povratni;
}
/*Berza Berza::operator -(int x, Berza b) {
    Berza povratni;
    povratni.dionice=b.dionice;
    if(std::find_if(povratni.dionice.begin(),povratni.dionice.end(), std::bind(std::less<int>(), x-minimalna, std::placeholders::_1))!=povratni.dionice.end())
    throw std::domain_error("Prekoracen dozvoljeni opseg cijena");
    else
    std::for_each(povratni.dionice.begin(),povratni.dionice.end(), std::bind(std::minus<int>(), x, std::placeholders::_1));
    return povratni; 
}*/
Berza Berza::operator - (Berza b2) {
    if(minimalna!=b2.minimalna || maksimalna!=b2.maksimalna || dionice.size()!=b2.dionice.size()) 
    throw std::domain_error("Nesaglasni operandi");
    Berza povratni;
    for(int i=0; i<dionice.size(); i++) povratni.dionice[i]=0;
   // std::for_each(povratni.dionice.begin(),povratni.dionice.end(), std::bind(std::plus<int>(), , std::placeholders::_1));
    return povratni; 
}
bool Berza::operator == (Berza b) {
    if(b.dionice.size()!=dionice.size()) return false;
    else {
        return std::equal(b.dionice.begin(), b.dionice.end(), dionice.end());
    }
}
bool Berza::operator !=(Berza b) {
     if(b.dionice.size()!=dionice.size()) return true;
    else {
        return !(std::equal(b.dionice.begin(), b.dionice.end(), dionice.end()));
    }
}
Berza Berza::operator +=(int x) {
    *this=*this+x;
    return *this;
}
Berza Berza::operator -=(int x) {
    *this=*this-x;
    return *this;
}  

int main ()
{
    try {
    Berza b1(100, 10000);
    b1.RegistrirajCijenu(1500);
    b1.RegistrirajCijenu(2000); b1.RegistrirajCijenu(3000); b1.RegistrirajCijenu(6500);
    std::cout<<b1.DajBrojVecihOd(50)<<std::endl;
    b1.Ispisi(); std::cout<<std::endl;
    std::cout<<b1[2];
    auto poma(b1+150);
    poma.Ispisi();
    ++poma;
    poma.Ispisi();
    }
    catch(std::exception &ex) {
        std::cout<<ex.what();
    }
	return 0;
}
