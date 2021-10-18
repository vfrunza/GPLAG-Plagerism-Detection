/B16/17 (Zadaća 5, Zadatak 5)
//Autotestovi by Berina Cocalic (mail: bcocalic1@etf.unsa.ba)
//Za autotestove se obracati *iskljucivo* osobi koja ih pise
#include <iostream>
#include <list>
#include <stdexcept>
#include <algorithm>
#include <functional>
#include <iterator>

class Temperature {
    std::list<int>max_temp;
    std::list<int>min_temp;
    public:
    Temperature(int minimalna_temp,int maksimalna_temp);
    void RegistrirajTemperature(std::pair<int,int>temperature);
    void BrisiSve();
    void BrisiNegativneTemperature(); //ovo
    int DajBrojRegistriranihTemperatura() const; 
    int DajMinimalnuTemperaturu() const;
    int DajMaksimalnuTemperaturu() const;
    int DajBrojTeperaturaVecihOd(int zadana) const; //ovo
    int DajBrojTeperaturaManjihOd(int zadana) const; //ovo
    friend bool operator!(Temperature t) {
        if(t.max_temp.size()==1) {
            return true;
        }
        return false;
    }
    friend Temperature &operator++(Temperature &t);
    friend Temperature operator++(Temperature &t,int);
    friend Temperature &operator--(Temperature &t);
    friend Temperature operator--(Temperature &t,int);
    std::pair<int,int> operator[] (int indeks) const;
    friend bool operator==(const Temperature &t1, const Temperature &t2);
    friend bool operator!=(const Temperature &t1, const Temperature &t2);
    friend Temperature operator+(const Temperature &t, int x);
    friend Temperature operator+(int x, const Temperature &t) { return t+x; }
    friend Temperature operator+(const Temperature &t1, const Temperature &t2);
    friend Temperature operator-(const Temperature &t, int x);
    friend Temperature operator-(int x, const Temperature &t) { return t-x; }
    friend Temperature operator-(const Temperature &t1, const Temperature &t2);
    Temperature &operator+=(const Temperature &t);
    Temperature &operator+=(int x);
    Temperature &operator-=(const Temperature &t);
    Temperature &operator-=(int x);
    friend std::ostream &operator<<(std::ostream &tok,const Temperature &t );
    
    
    
    
    
    
    
};
Temperature::Temperature(int minimalna_temp,int maksimalna_temp) {
    if(minimalna_temp>maksimalna_temp) {
        throw std::range_error("Nekorektne temperature");
    }
     max_temp.push_back(maksimalna_temp);
    min_temp.push_back(minimalna_temp);
}
void Temperature::RegistrirajTemperature(std::pair<int,int>temperature) {
    auto it1=max_temp.begin();
    auto it2=min_temp.begin();
    if(temperature.first<*it2) {
        throw std::range_error("Nekorektne temperature");
    }
    if(temperature.second>*it1) {
        throw std::range_error("Nekorektne temperature");
    }
    if(temperature.first>temperature.second) {
        throw std::range_error("Nekorektne temperature");
    }
    max_temp.push_back(temperature.second);
    min_temp.push_back(temperature.first);
}
int Temperature::DajMinimalnuTemperaturu() const {
    if(min_temp.size()==1) {
        throw std::logic_error("Nema registriranih temperatura");
    }
    auto it1=++min_temp.begin();
    auto it2=min_temp.end();
    return *std::min_element(it1,it2);
}
int Temperature::DajMaksimalnuTemperaturu() const {
    if(max_temp.size()==1) {
        throw std::logic_error("Nema registriranih temperatura");
    }
    auto it1=++max_temp.begin();
    auto it2=max_temp.end();
    return *std::max_element(it1,it2);
}
int Temperature::DajBrojRegistriranihTemperatura() const {
    return max_temp.size()-1;
}
void Temperature::BrisiSve() {
    max_temp.clear();
    min_temp.clear();
}
Temperature &operator++(Temperature &t) {
    auto it=t.min_temp.begin();
    it++;
    std::transform(it,t.min_temp.end(),it,std::bind(std::plus<int>(),std::placeholders::_1,1));
    auto it1=t.max_temp.begin();
    if(std::count_if(it,t.min_temp.end(),std::bind(std::less<int>(),std::placeholders::_1,0))<*it1++) {
        throw std::logic_error("Ilegalna operacija");
        
    }
    return t;
}
Temperature operator++(Temperature &t,int) {
    Temperature pomocni(t);
     auto it=pomocni.min_temp.begin();
     it++;
     std::transform(it,pomocni.min_temp.end(),it,std::bind(std::plus<int>(),std::placeholders::_1,1));
     auto it1=pomocni.max_temp.begin();
      if(std::count_if(it,pomocni.min_temp.end(),std::bind(std::less<int>(),std::placeholders::_1,0))>*it1++) {
        throw std::logic_error("Ilegalna operacija");
        
    }
     return pomocni;
}
Temperature &operator--(Temperature &t) {
    auto it=t.max_temp.begin();
    it++;
    std::transform(it,t.max_temp.end(),it,std::bind(std::minus<int>(),std::placeholders::_1,1));
    auto it1=t.min_temp.begin();
    if(std::count_if(it,t.max_temp.end(),std::bind(std::less<int>(),std::placeholders::_1,0))<*it1++) {
        throw std::logic_error("Ilegalna operacija");
        
    }
    return t;
}
Temperature operator--(Temperature &t,int) {
    Temperature pomocni(t);
    auto it=pomocni.max_temp.begin();
    it++;
     std::transform(it,t.max_temp.end(),it,std::bind(std::minus<int>(),std::placeholders::_1,1));
     auto it1=pomocni.min_temp.begin();
      /*if(std::count_if(pomocni.max_temp.begin(),pomocni.max_temp.end(),std::bind(std::less<int>(),std::placeholders::_1,0))<*it++) {
        throw std::logic_error("Ilegalna operacija");
        
    }*/
     return pomocni;
}
/*std::pair<int,int> operator[] (int indeks) const {
     if(indeks<1 || indeks>max_temp.size()) {
         throw std::range_error("Neispravan indeks");
     }
     std::pair<int,int>par;
     auto it1=max_temp.begin();
     auto it2=min_temp.begin();
 }*/
bool operator==(const Temperature &t1, const Temperature &t2) {
    if(t1.max_temp.size()!=t2.max_temp.size()) {
        return false;
    }
    if(std::equal(t1.max_temp.begin(),t1.max_temp.end(),t2.max_temp.begin())==true && std::equal(t1.min_temp.begin(),t1.min_temp.end(),t2.min_temp.begin())==true  && *t1.max_temp.begin()==*t2.max_temp.begin() && *t1.min_temp.begin()==*t2.min_temp.begin()) {
        return true;
    }
    return false;
}
bool operator!=(const Temperature &t1, const Temperature &t2) {
    if(t1.max_temp.size()!=t2.max_temp.size()) {
        return true;
    }
     if(std::equal(t1.max_temp.begin(),t1.max_temp.end(),t2.max_temp.begin())==false && std::equal(t1.min_temp.begin(),t1.min_temp.end(),t2.min_temp.begin())==false  && *t1.max_temp.begin()!=*t2.max_temp.begin() && *t1.min_temp.begin()!=*t2.min_temp.begin()) {
        return false;
    }
    return true;
}
Temperature operator+(const Temperature &t, int x) {
    Temperature t1(t);
    auto it1=t1.max_temp.begin();
    it1++;
    auto it2=t1.min_temp.begin();
    it2++;
    std::transform(it1,t1.max_temp.end(),it1,std::bind(std::plus<int>(),std::placeholders::_1,x));
    std::transform(it2,t1.min_temp.end(),it2,std::bind(std::plus<int>(),std::placeholders::_1,x));
    auto za_max=t1.max_temp.begin();
    if(std::count_if(za_max,t1.max_temp.end(),std::bind(std::less<int>(),std::placeholders::_1,0))>*za_max++) {
        throw std::logic_error("Prekoracen dozvoljeni opseg temperatura");
        
    }
    auto za_min=t1.min_temp.begin();
    if(std::count_if(za_min,t1.min_temp.end(),std::bind(std::less<int>(),std::placeholders::_1,0))<*za_min++) {
        throw std::logic_error("Prekoracen dozvoljeni opseg temperatura");
        
    }
    return t1;
}
Temperature operator-(const Temperature &t, int x) {
    Temperature t1(t);
    auto it1=t1.max_temp.begin();
    it1++;
    auto it2=t1.min_temp.begin();
    it2++;
    std::transform(it1,t1.max_temp.end(),it1,std::bind(std::minus<int>(),std::placeholders::_1,x));
    std::transform(it2,t1.min_temp.end(),it2,std::bind(std::minus<int>(),std::placeholders::_1,x));
    auto za_max=t1.max_temp.begin();
    if(std::count_if(za_max,t1.max_temp.end(),std::bind(std::less<int>(),std::placeholders::_1,0))>*za_max++) {
        throw std::logic_error("Prekoracen dozvoljeni opseg temperatura");
        
    }
    auto za_min=t1.min_temp.begin();
    if(std::count_if(za_min,t1.min_temp.end(),std::bind(std::less<int>(),std::placeholders::_1,0))<*za_min++) {
        throw std::logic_error("Prekoracen dozvoljeni opseg temperatura");
        
    }
    return t1;
}
Temperature operator+(const Temperature &t1, const Temperature &t2) {
    Temperature t3(t1);
    std::transform(t1.max_temp.begin(),t1.max_temp.end(),t2.max_temp.begin(),t3.max_temp.begin(),std::plus<int>());
    std::transform(t1.min_temp.begin(),t1.min_temp.end(),t2.min_temp.begin(),t3.min_temp.begin(),std::plus<int>());
    auto za_max=t3.max_temp.begin();
    if(std::count_if(za_max,t3.max_temp.end(),std::bind(std::less<int>(),std::placeholders::_1,0))>*za_max++) {
        throw std::logic_error("Prekoracen dozvoljeni opseg temperatura");
    }
     auto za_min=t3.min_temp.begin();
    if(std::count_if(za_min,t3.min_temp.end(),std::bind(std::less<int>(),std::placeholders::_1,0))<*za_min++) {
        throw std::logic_error("Prekoracen dozvoljeni opseg temperatura");
        
    }
    return t3;
    
    
}
Temperature operator-(const Temperature &t1, const Temperature &t2) {
    Temperature t3(t1);
    std::transform(t1.max_temp.begin(),t1.max_temp.end(),t2.max_temp.begin(),t3.max_temp.begin(),std::minus<int>());
    std::transform(t1.min_temp.begin(),t1.min_temp.end(),t2.min_temp.begin(),t3.min_temp.begin(),std::minus<int>());
    auto za_max=t3.max_temp.begin();
    if(std::count_if(za_max,t3.max_temp.end(),std::bind(std::less<int>(),std::placeholders::_1,0))>*za_max++) {
        throw std::logic_error("Prekoracen dozvoljeni opseg temperatura");
    }
     auto za_min=t3.min_temp.begin();
    if(std::count_if(za_min,t3.min_temp.end(),std::bind(std::less<int>(),std::placeholders::_1,0))<*za_min++) {
        throw std::logic_error("Prekoracen dozvoljeni opseg temperatura");
        
    }
    return t3;
}
Temperature &Temperature::operator+=(const Temperature &t) {
    std::transform(this->max_temp.begin(),this->max_temp.end(),t.max_temp.begin(),this->max_temp.begin(),std::plus<int>());
    std::transform(this->min_temp.begin(),this->min_temp.end(),t.min_temp.begin(),this->min_temp.begin(),std::plus<int>());

    return *this;
}
Temperature &Temperature::operator+=(int x) {
    std::transform(this->max_temp.begin(),this->max_temp.end(),this->max_temp.begin(),std::bind(std::plus<int>(),std::placeholders::_1,x));
    std::transform(this->min_temp.begin(),this->min_temp.end(),this->min_temp.begin(),std::bind(std::plus<int>(),std::placeholders::_1,x));
return *this;
}
Temperature &Temperature::operator-=(const Temperature &t) {
    std::transform(this->max_temp.begin(),this->max_temp.end(),t.max_temp.begin(),this->max_temp.begin(),std::minus<int>());
    std::transform(this->min_temp.begin(),this->min_temp.end(),t.min_temp.begin(),this->min_temp.begin(),std::minus<int>());

    return *this;
}
Temperature &Temperature::operator-=(int x) {
    std::transform(this->max_temp.begin(),this->max_temp.end(),this->max_temp.begin(),std::bind(std::minus<int>(),std::placeholders::_1,x));
    std::transform(this->min_temp.begin(),this->min_temp.end(),this->min_temp.begin(),std::bind(std::minus<int>(),std::placeholders::_1,x));
return *this;
}
/*int Temperature::DajBrojTeperaturaVecihOd(int zadana) const {
     if(min_temp.size()==1) {
        throw std::logic_error("Nema registriranih temperatura");
    }
    auto it=max_temp.begin();
    it++;
    int broj1=std::count_if(max_temp.begin(),max_temp.end(),std::bind(std::greater<int>(),std::placeholders::_1,zadana));
    
    
}*/
std::ostream &operator<<(std::ostream &tok,const Temperature &t ) {
    std::copy(t.max_temp.begin(),t.max_temp.end(),std::ostream_iterator<int>(tok," "));
    tok<<std::endl;
    std::copy(t.min_temp.begin(),t.min_temp.end(),std::ostream_iterator<int>(tok," "));
    return tok;
    
}
/*void Temperature::BrisiNegativneTemperature() {
   auto it1=max_temp.begin();
   it1++;
   auto it2=min_temp.begin();
   it2++;
} */




int main () {
    Temperature t(1,20);
    Temperature t1(1,20);
    std::cout<<"OK main";
    std::pair<int,int>par1(2,19);
    std::pair<int,int>par2(3,18);
    t.RegistrirajTemperature(par1);
    t.RegistrirajTemperature(par2);
     t1.RegistrirajTemperature(par1);
    t1.RegistrirajTemperature(par2);
    std::cout<<"Ovo je minimalna temperatura "<<t.DajMinimalnuTemperaturu()<<std::endl;
    std::cout<<"Ovo je maksimalna temperatura "<<t.DajMaksimalnuTemperaturu()<<std::endl;
    std::cout<<"Ovo je broj registriranih temperatura: "<<t.DajBrojRegistriranihTemperatura()<<std::endl;
    std::cout<<std::boolalpha<<!t;
    t++;
    std::cout<<"Ovdje sam "<<t.DajMinimalnuTemperaturu();
    //t--;
    std::cout<<t.DajMaksimalnuTemperaturu();
    if(t==t1) {
        std::cout<<"Da";
    }
    if(t!=t1)
    std::cout<<"da";
    else 
    std::cout<<"ne";
    std::cout<<t;
}