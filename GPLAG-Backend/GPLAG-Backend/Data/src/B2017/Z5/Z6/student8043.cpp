/B2017/2018: Zadaća 5, Zadatak 6
#include <iostream>
#include <functional>
#include <algorithm>
#include <vector>
#include <stdexcept>

//za ekonomiju

class Berza {
  int max_cijena;
  int min_cijena;
  
  void TestIndeksa(int indeks)const{ if(indeks<1 || indeks>cijene.size()) throw std::range_error("Neispravan indeks"); }
  friend void TestCijena(const Berza &b);
  friend void TestBerzi(const Berza &b1,const Berza &b2);
  std::vector<int> cijene;
  
  public:
  Berza(int min,int max);
  explicit Berza(int max);
  void RegistrirajCijenu(int cijena);
  int DajBrojRegistriranihCijena() const { return cijene.size(); };
  void BrisiSve() { cijene.resize(0); };
  int DajMinimalnuCijenu() const;
  int DajMaksimalnuCijenu() const ;
  bool operator !() { return this->DajBrojRegistriranihCijena()==0; }
  
  int DajBrojCijenaVecihOd(int cijena) const;
  int operator [](int indeks) { TestIndeksa(indeks); return cijene[indeks-1]; }
  friend Berza &operator ++(Berza &b);
  friend Berza operator ++(Berza &b,int);
  friend Berza &operator --(Berza &b);
  friend Berza operator --(Berza &b,int);
  
  friend Berza operator +(Berza b,int y);
  friend Berza operator -(Berza b,int y);
  friend Berza &operator+=(Berza &b1,const Berza &b2);
  friend Berza &operator-=(Berza &b1,const Berza &b2);
  friend Berza operator+(const Berza &b1,const Berza &b2);
  friend Berza operator-(const Berza &b1,const Berza &b2);
  
  friend bool operator ==(const Berza &b1,const Berza &b2);
  friend bool operator !=(const Berza &b1,const Berza &b2);
  friend Berza &operator-(Berza &b); //
  void Ispisi();//
};
/*
void Berza::Ispisi(){
    std::for_each(cijene.begin(),cijene.end(),bind(std::function<void(int x)>{std::cout << x;},std::placeholders::_1)
}
*/
bool operator ==(const Berza &b1,const Berza &b2){
    if(b1.DajBrojRegistriranihCijena()!=b2.DajBrojRegistriranihCijena()) return false;
    return std::equal(b1.cijene.begin(),b1.cijene.end(),b2.cijene.begin(),
    bind(std::equal_to<int>(),std::placeholders::_1,std::placeholders::_2));
}

bool operator !=(const Berza &b1,const Berza &b2){
    return !(b1==b2);
}

Berza operator+(const Berza &b1,const Berza &b2){
    Berza b(b1);
    b+=b2;
    return b;
}

Berza operator-(const Berza &b1,const Berza &b2){
    Berza b(b1);
    b-=b2;
    return b;
}

void TestBerzi(const Berza &b1, const Berza &b2){
    if(b1.max_cijena!=b2.max_cijena
    || b1.min_cijena!=b2.min_cijena
    || b1.DajBrojRegistriranihCijena() != b2.DajBrojRegistriranihCijena()){
        throw std::domain_error("Nesaglasni operandi");
    }
}

Berza &operator +=(Berza &b1,const Berza &b2)
{
    TestBerzi(b1,b2);
    try {
        std::transform(b1.cijene.begin(),b1.cijene.end(),b2.cijene.begin(),b1.cijene.begin(),
                   bind(std::plus<int>(),std::placeholders::_1,std::placeholders::_2));
        TestCijena(b1);
    }
    catch(...){
        std::transform(b1.cijene.begin(),b1.cijene.end(),b2.cijene.begin(),b1.cijene.begin(),
                   bind(std::minus<int>(),std::placeholders::_1,std::placeholders::_2));
        throw;
    }
    
    return b1;
}

Berza &operator -=(Berza &b1,const Berza &b2)
{
    TestBerzi(b1,b2);
    try {
        std::transform(b1.cijene.begin(),b1.cijene.end(),b2.cijene.begin(),b1.cijene.begin(),
                   bind(std::minus<int>(),std::placeholders::_1,std::placeholders::_2));
        TestCijena(b1);
    }
    catch(...){
        std::transform(b1.cijene.begin(),b1.cijene.end(),b2.cijene.begin(),b1.cijene.begin(),
                   bind(std::plus<int>(),std::placeholders::_1,std::placeholders::_2));
        throw;
    }
    
    return b1;
}

Berza operator +(Berza b,int y){
    try {
        std::transform(b.cijene.begin(),b.cijene.end(),b.cijene.begin(),bind(std::plus<int>(),std::placeholders::_1,y));
        TestCijena(b);
    }
    catch(...){
        std::transform(b.cijene.begin(),b.cijene.end(),b.cijene.begin(),bind(std::minus<int>(),std::placeholders::_1,y));
        throw;
    }
    
    return b;
}

Berza operator -(Berza b,int y){
    try {
       std::transform(b.cijene.begin(),b.cijene.end(),b.cijene.begin(),bind(std::minus<int>(),std::placeholders::_1,y));
       TestCijena(b);
    }
    catch(...){
        std::transform(b.cijene.begin(),b.cijene.end(),b.cijene.begin(),bind(std::plus<int>(),std::placeholders::_1,y));
        throw;
    }
    
    return b;
}

void TestCijena(const Berza &b){
    if(std::count_if(b.cijene.begin(),b.cijene.end(),bind(std::greater<int>(),std::placeholders::_1,b.max_cijena))!=0
    || std::count_if(b.cijene.begin(),b.cijene.end(),bind(std::less<int>(),std::placeholders::_1,b.min_cijena))!=0){
        throw std::range_error("Prekoracen dozvoljeni opseg cijena");
    }
}


Berza::Berza(int min,int max){
    if(min<0 || max<0 || max<min) throw std::range_error("Ilegalne granicne cijene");
    max_cijena=max; min_cijena=min;
}

Berza::Berza(int max){
    if(max<0) throw std::range_error("Ilegalne granicne cijene");
    max_cijena=max; min_cijena=0;
}

void Berza::RegistrirajCijenu(int cijena){
    if(cijena>max_cijena || cijena<min_cijena) throw std::range_error("Ilegalna cijena");
    cijene.push_back(cijena);
}

int Berza::DajMinimalnuCijenu() const {
    if(this->DajBrojRegistriranihCijena()==0) throw std::range_error("Nema registriranih cijena");
    auto min(std::min_element(cijene.begin(),cijene.end()));
    return *min;
}

int Berza::DajMaksimalnuCijenu() const {
    if(this->DajBrojRegistriranihCijena()==0) throw std::range_error("Nema registriranih cijena");
    auto max(std::max_element(cijene.begin(),cijene.end()));
    return *max;
}

int Berza::DajBrojCijenaVecihOd(int cijena) const {
    if(this->DajBrojRegistriranihCijena()==0) throw std::range_error("Nema registriranih cijena");
    return std::count_if(cijene.begin(),cijene.end(),bind(std::greater<int>(),std::placeholders::_1,cijena));
}

Berza &operator++(Berza &b){ //prefiksni
    try{
        std::transform(b.cijene.begin(),b.cijene.end(),b.cijene.begin(),bind(std::plus<int>(),std::placeholders::_1,100));
        TestCijena(b);
    }
    catch(...){
        std::transform(b.cijene.begin(),b.cijene.end(),b.cijene.begin(),bind(std::minus<int>(),std::placeholders::_1,100));
        throw;
    }
    return b;
}

Berza operator++(Berza &b,int){ //postfiksni
    Berza pomocna(b);
    ++b;
    return pomocna;
}

Berza &operator--(Berza &b){ //prefiksni
    try{
        std::transform(b.cijene.begin(),b.cijene.end(),b.cijene.begin(),bind(std::minus<int>(),std::placeholders::_1,100));
        TestCijena(b);
    }
    catch(...){
        std::transform(b.cijene.begin(),b.cijene.end(),b.cijene.begin(),bind(std::plus<int>(),std::placeholders::_1,100));
        throw;
    }
    return b;
}

Berza operator--(Berza &b,int){ //postfiksni
    Berza pomocna(b);
    --b;
    return pomocna;
}





int main ()
{
    try {
    Berza b1(10000);
    Berza b2(10000);
    b1.RegistrirajCijenu(40);
    b1.RegistrirajCijenu(23);
    b2.RegistrirajCijenu(40);
    b2.RegistrirajCijenu(23);
    if(b1!=b2){
        std::cout << "raz";
    }
    else{
        std::cout << "isto";
    }
    }
    catch(std::range_error iz){
        std::cout << iz.what();
    }
    catch(std::domain_error iz){
        std::cout << iz.what();
    }
	return 0;
}
