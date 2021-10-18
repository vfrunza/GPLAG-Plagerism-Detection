/B16/17 (Zadaća 5, Zadatak 5)
//Autotestovi by Berina Cocalic (mail: bcocalic1@etf.unsa.ba)
//Za autotestove se obracati *iskljucivo* osobi koja ih pise
#include <iostream>
#include <list>
#include <algorithm>
#include <functional>
#include <stdexcept>
#include <utility>
#include <vector>
#include <iterator>

class Temperature{
    std::list<int> minimalna_temp, maksimalna_temp;
    int maksimalna_dozvoljena, minimalna_dozvoljena;
    public:
    Temperature(int min, int max){
        if(min>max) throw std::range_error("Nekorektne temperature");
        minimalna_dozvoljena=min; maksimalna_dozvoljena=max;
    }
    void RegistrirajTemperature(std::pair<int,int> a);
    void BrisiSve();
   void BrisiNegativneTemperature(std::list<int>::iterator it1=std::list<int>::iterator(), std::list<int>::iterator it2=std::list<int>::iterator());
   int DajBrojRegistriranihTemperatura() const { return minimalna_temp.size(); }
   int DajMinimalnuTemperaturu() const;
   int DajMaksimalnuTeperaturu() const;
   int DajBrojTeperaturaVecihOd(int n) const;
   int DajBrojTeperaturaManjihOd(int n) const;
   bool operator !();
   Temperature &operator ++();
   Temperature &operator --();
   Temperature operator ++(int);
   Temperature operator --(int);
   std::vector<int> operator *();
   std::vector<int> operator -();
   std::vector<int> operator +();
   std::pair<int,int> operator [](int indeks) const;
   bool operator ==(const Temperature &a); 
   bool operator !=(const Temperature &a);
   Temperature &operator +=(int broj);
   Temperature &operator -=(int broj);
   friend Temperature operator +(const Temperature &a, int broj);
   friend Temperature operator +(int broj, const Temperature &a);
   friend Temperature operator -(const Temperature &a, int broj);
   friend Temperature operator -(int broj, const Temperature &a);
   friend std::ostream &operator << (std::ostream &tok, const Temperature &a);
};

std::ostream &operator << (std::ostream &tok, const Temperature &a){
    std::ostream_iterator<int> it(tok," ");
    std::copy((a.minimalna_temp).begin(),(a.minimalna_temp).end(),it);
    tok << std::endl;
    std::copy((a.maksimalna_temp).begin(),(a.maksimalna_temp).end(),it);
    tok << std::endl;
    return tok;
}

inline bool Temperature::operator !=(const Temperature &a){
    return !(*this==a);
}

bool Temperature::operator ==(const Temperature &a){
    if(maksimalna_dozvoljena!=a.maksimalna_dozvoljena || minimalna_dozvoljena!=a.minimalna_dozvoljena || this->DajBrojRegistriranihTemperatura()!=a.DajBrojRegistriranihTemperatura())
        return false;
    bool l1=std::equal(maksimalna_temp.begin(),maksimalna_temp.end(),(a.maksimalna_temp).begin(),std::equal_to<int>());
    bool l2=std::equal(minimalna_temp.begin(),minimalna_temp.end(),(a.minimalna_temp).begin(),std::equal_to<int>());
    return (l1 && l2);
}

inline Temperature operator -(int broj, const Temperature &a){
    std::vector<int>mini(a.minimalna_temp.size(),broj);
    std::vector<int>maxi(a.minimalna_temp.size(),broj);
    std::transform(mini.begin(),mini.end(),a.maksimalna_temp.begin(),mini.begin(),std::minus<int>());
    int brojac=std::count_if(mini.begin(),mini.end(),std::bind(std::less<int>(),std::placeholders::_1,a.minimalna_dozvoljena));
    if(brojac>0) throw std::logic_error("Prekoracen dozvoljeni opseg temperatura");
    std::transform(maxi.begin(),maxi.end(),a.minimalna_temp.begin(),maxi.begin(),std::minus<int>());
    brojac=std::count_if(maxi.begin(),maxi.end(),std::bind(std::greater<int>(),std::placeholders::_1,a.maksimalna_dozvoljena));
    if(brojac>0) throw std::logic_error("Prekoracen dozvoljeni opseg temperatura");
    Temperature pomocna(a.minimalna_dozvoljena,a.maksimalna_dozvoljena);
    (pomocna.maksimalna_temp).resize((a.maksimalna_temp).size()); (pomocna.minimalna_temp).resize((a.minimalna_temp).size());
    std::copy(maxi.begin(),maxi.end(),(pomocna.maksimalna_temp).begin());
    std::copy(mini.begin(),mini.end(),(pomocna.minimalna_temp).begin());
    return pomocna;
    
}

inline Temperature operator -(const Temperature &a, int broj){
    Temperature pomocna(a.minimalna_dozvoljena,a.maksimalna_dozvoljena);
    (pomocna.maksimalna_temp).resize((a.maksimalna_temp).size()); (pomocna.minimalna_temp).resize((a.minimalna_temp).size());
    std::copy((a.maksimalna_temp).begin(),(a.maksimalna_temp).end(),(pomocna.maksimalna_temp).begin());
    std::copy((a.minimalna_temp).begin(),(a.minimalna_temp).end(),(pomocna.minimalna_temp).begin());
    pomocna-=broj;
    return pomocna;
}

inline Temperature operator +(int broj, const Temperature &a){
    return a+broj;
}

inline Temperature operator +(const Temperature &a, int broj){
    Temperature pomocna(a.minimalna_dozvoljena,a.maksimalna_dozvoljena);
    (pomocna.maksimalna_temp).resize((a.maksimalna_temp).size()); (pomocna.minimalna_temp).resize((a.minimalna_temp).size());
    std::copy((a.maksimalna_temp).begin(),(a.maksimalna_temp).end(),(pomocna.maksimalna_temp).begin());
    std::copy((a.minimalna_temp).begin(),(a.minimalna_temp).end(),(pomocna.minimalna_temp).begin());
    pomocna+=broj;
    return pomocna;
}

Temperature &Temperature::operator -= (int broj){
    if(broj >=0){
        int brojac=std::count_if(minimalna_temp.begin(),minimalna_temp.end(),std::bind(std::less<int>(),std::placeholders::_1,minimalna_dozvoljena+broj));
        if(brojac>0) throw std::logic_error("Prekoracen dozvoljeni opseg temperatura");
    }else if(broj<0){
        int brojac=std::count_if(maksimalna_temp.begin(),maksimalna_temp.end(),std::bind(std::greater<int>(),std::placeholders::_1,maksimalna_dozvoljena+broj));
        if(brojac>0) throw std::logic_error("Prekoracen dozvoljeni opseg temperatura");
    }
    std::transform(maksimalna_temp.begin(),maksimalna_temp.end(),maksimalna_temp.begin(),std::bind(std::minus<int>(),std::placeholders::_1,broj));
    std::transform(minimalna_temp.begin(),minimalna_temp.end(),minimalna_temp.begin(),std::bind(std::minus<int>(),std::placeholders::_1,broj));
    return *this;
}

Temperature &Temperature::operator += (int broj){
    if(broj>=0){
        int brojac=std::count_if(maksimalna_temp.begin(),maksimalna_temp.end(),std::bind(std::greater<int>(),std::placeholders::_1,maksimalna_dozvoljena-broj));
        if(brojac>0) throw std::logic_error("Prekoracen dozvoljeni opseg temperatura");
    }else if(broj<0){
        int brojac=std::count_if(minimalna_temp.begin(),minimalna_temp.end(),std::bind(std::less<int>(),std::placeholders::_1,minimalna_dozvoljena-broj));
        if(brojac>0) throw std::logic_error("Prekoracen dozvoljeni opseg temperatura");
    }
    std::transform(maksimalna_temp.begin(),maksimalna_temp.end(),maksimalna_temp.begin(),std::bind(std::plus<int>(),std::placeholders::_1,broj));
    std::transform(minimalna_temp.begin(),minimalna_temp.end(),minimalna_temp.begin(),std::bind(std::plus<int>(),std::placeholders::_1,broj));
    return *this;
}

std::pair<int,int> Temperature::operator [](int indeks) const {
    if(indeks<1 || indeks>maksimalna_temp.size()) throw std::range_error("Neispravan indeks");
    std::vector<int> v1(maksimalna_temp.size());  std::vector<int> v2(minimalna_temp.size());
    std::copy(minimalna_temp.begin(),minimalna_temp.end(),v1.begin());
    std::copy(maksimalna_temp.begin(),maksimalna_temp.end(),v2.begin());
    auto p=std::make_pair(v1[indeks-1],v2[indeks-1]);
    return p;
}

std::vector<int> Temperature::operator +(){
    std::vector<int> v(maksimalna_temp.size());
    std::fill(v.begin(),v.end(),maksimalna_dozvoljena);
    std::transform(v.begin(),v.end(),maksimalna_temp.begin(),v.begin(),std::minus<int>());
    return v;
}

std::vector<int> Temperature::operator -(){
    std::vector<int > v(minimalna_temp.size());
    std::transform(minimalna_temp.begin(),minimalna_temp.end(),v.begin(),std::bind(std::minus<int>(),std::placeholders::_1,minimalna_dozvoljena));
    return v;
}

std::vector<int> Temperature::operator *(){
    std::vector<int> v(maksimalna_temp.size());
    std::transform(maksimalna_temp.begin(),maksimalna_temp.end(),minimalna_temp.begin(),v.begin(),std::minus<int>());
    return v;
}

Temperature Temperature:: operator --(int){
    int brojac=std::count_if(maksimalna_temp.begin(),maksimalna_temp.end(),std::bind(std::less<int>(),std::placeholders::_1,minimalna_dozvoljena+1));
    if(brojac>0) throw std::logic_error("Ilegalna operacija");
    std::vector<int>v(minimalna_temp.size());
    std::transform(minimalna_temp.begin(),minimalna_temp.end(),maksimalna_temp.begin(),v.begin(),std::minus<int>());
    brojac=std::count(v.begin(),v.end(),0);
    if(brojac>0) throw std::logic_error("Ilegalna operacija");
    Temperature pomocna(minimalna_dozvoljena,maksimalna_dozvoljena);
    (pomocna.maksimalna_temp).resize(maksimalna_temp.size());  (pomocna.minimalna_temp).resize(minimalna_temp.size());
    std::copy(maksimalna_temp.begin(),maksimalna_temp.end(),(pomocna.maksimalna_temp).begin());
    std::copy(minimalna_temp.begin(),minimalna_temp.end(),(pomocna.minimalna_temp).begin());
    std::transform(maksimalna_temp.begin(),maksimalna_temp.end(),maksimalna_temp.begin(),std::bind(std::minus<int>(),std::placeholders::_1,1));
    return pomocna;
}

Temperature Temperature::operator ++(int){
    int brojac=std::count_if(minimalna_temp.begin(),minimalna_temp.end(),std::bind(std::greater<int>(),std::placeholders::_1,maksimalna_dozvoljena-1));
    if(brojac>0) throw std::logic_error("Ilegalna operacija");
    std::vector<int>v(minimalna_temp.size());
    std::transform(minimalna_temp.begin(),minimalna_temp.end(),maksimalna_temp.begin(),v.begin(),std::minus<int>());
    brojac=std::count(v.begin(),v.end(),0);
    if(brojac>0) throw std::logic_error("Ilegalna operacija");
    Temperature pomocna(minimalna_dozvoljena,maksimalna_dozvoljena);
    (pomocna.maksimalna_temp).resize(maksimalna_temp.size());  (pomocna.minimalna_temp).resize(minimalna_temp.size());
    std::copy(maksimalna_temp.begin(),maksimalna_temp.end(),(pomocna.maksimalna_temp).begin());
    std::copy(minimalna_temp.begin(),minimalna_temp.end(),(pomocna.minimalna_temp).begin());
    std::transform(minimalna_temp.begin(),minimalna_temp.end(),minimalna_temp.begin(),std::bind(std::plus<int>(),std::placeholders::_1,1));
    return pomocna;
}

Temperature &Temperature::operator --(){
    int brojac=std::count_if(maksimalna_temp.begin(),maksimalna_temp.end(),std::bind(std::less<int>(),std::placeholders::_1,minimalna_dozvoljena+1));
    if(brojac>0) throw std::logic_error("Ilegalna operacija");
    std::vector<int>v(minimalna_temp.size());
    std::transform(minimalna_temp.begin(),minimalna_temp.end(),maksimalna_temp.begin(),v.begin(),std::minus<int>());
    brojac=std::count(v.begin(),v.end(),0);
    if(brojac>0) throw std::logic_error("Ilegalna operacija");
    std::transform(maksimalna_temp.begin(),maksimalna_temp.end(),maksimalna_temp.begin(),std::bind(std::minus<int>(),std::placeholders::_1,1));
    return *this;
}

Temperature &Temperature::operator ++(){
    int brojac=std::count_if(minimalna_temp.begin(),minimalna_temp.end(),std::bind(std::greater<int>(),std::placeholders::_1,maksimalna_dozvoljena-1));
    if(brojac>0) throw std::logic_error("Ilegalna operacija");
    std::vector<int>v(minimalna_temp.size());
    std::transform(minimalna_temp.begin(),minimalna_temp.end(),maksimalna_temp.begin(),v.begin(),std::minus<int>());
    brojac=std::count(v.begin(),v.end(),0);
    if(brojac>0) throw std::logic_error("Ilegalna operacija");
    std::transform(minimalna_temp.begin(),minimalna_temp.end(),minimalna_temp.begin(),std::bind(std::plus<int>(),std::placeholders::_1,1));
    return *this;
}

bool Temperature::operator!(){
    return (minimalna_temp.empty());
}

int Temperature::DajBrojTeperaturaManjihOd(int n) const{
    if(maksimalna_temp.empty()) throw std::logic_error("Nema registriranih temperatura");
    int brojac1=std::count_if(minimalna_temp.begin(),minimalna_temp.end(),std::bind(std::less<int>(),std::placeholders::_1,n));
    int brojac2=std::count_if(maksimalna_temp.begin(),maksimalna_temp.end(),std::bind(std::less<int>(),std::placeholders::_1,n));
    return brojac2+brojac1;
}

int Temperature::DajBrojTeperaturaVecihOd(int n) const{
    if(maksimalna_temp.empty()) throw std::logic_error("Nema registriranih temperatura");
    int brojac1=std::count_if(minimalna_temp.begin(),minimalna_temp.end(),std::bind(std::greater<int>(),std::placeholders::_1,n));
    int brojac2=std::count_if(maksimalna_temp.begin(),maksimalna_temp.end(),std::bind(std::greater<int>(),std::placeholders::_1,n));
    return brojac2+brojac1;
}

int Temperature::DajMaksimalnuTeperaturu() const{
    if(maksimalna_temp.empty()) throw std::logic_error("Nema registriranih temperatura");
    auto it=std::max_element(maksimalna_temp.begin(),maksimalna_temp.end(),std::less<int>());
    return *it;
}

int Temperature::DajMinimalnuTemperaturu() const {
    if(minimalna_temp.empty()) throw std::logic_error("Nema registriranih temperatura");
    auto it=std::min_element(minimalna_temp.begin(),minimalna_temp.end(),std::less<int>());
    return *it;
}

void Temperature::BrisiNegativneTemperature(std::list<int>::iterator it1, std::list<int>::iterator it2){
    if(it1==std::list<int>::iterator() && it2==std::list<int>::iterator()){
        it1=maksimalna_temp.begin(); it2=minimalna_temp.begin();
    }
    if(it1!=maksimalna_temp.end()){
        if(*it1<0 && *it2<0) {
            it1=maksimalna_temp.erase(it1); it2=minimalna_temp.erase(it2);
            BrisiNegativneTemperature(it1,it2);
        }else{
            it1++;it2++;
            BrisiNegativneTemperature(it1,it2);
        }
    } 
}

void Temperature::BrisiSve(){
    minimalna_temp.clear(); maksimalna_temp.clear();
}

void Temperature::RegistrirajTemperature(std::pair<int,int>a){
    if(a.first>a.second || a.first<minimalna_dozvoljena || a.first>maksimalna_dozvoljena || a.second>maksimalna_dozvoljena || a.second<minimalna_dozvoljena) 
        throw std::range_error("Nekorektne temperature");
    minimalna_temp.push_back(a.first); maksimalna_temp.push_back(a.second);
}
    

int main ()
{
    try{
        Temperature a(-5,5);
        std::pair<int,int> b=std::make_pair(1,3), c=std::make_pair(-4,-1), d=std::make_pair(2,5),e=std::make_pair(-2,-1),f=std::make_pair(-2,1);
        a.RegistrirajTemperature(b);
        a.RegistrirajTemperature(c);
        a.RegistrirajTemperature(d);
        a.RegistrirajTemperature(e);
        a.RegistrirajTemperature(f);
        std::cout << a.DajBrojRegistriranihTemperatura()<< std::endl;
        std::cout << "MIN: " << a.DajMinimalnuTemperaturu() << " MAX: " << a.DajMaksimalnuTeperaturu() << std::endl;
        std::cout << a.DajBrojTeperaturaManjihOd(2) << "~" << a.DajBrojTeperaturaVecihOd(0) << std::endl;
        a.BrisiNegativneTemperature();
        std::cout << a.DajBrojRegistriranihTemperatura()<< std::endl;
        std::cout << a;
        a.BrisiSve();
        std::cout << a.DajBrojRegistriranihTemperatura();
        std::cout << "\n-----------------------------------\n";
        a.RegistrirajTemperature(b);
        a.RegistrirajTemperature(c);
        a.RegistrirajTemperature(d);
        a.RegistrirajTemperature(e);
        a.RegistrirajTemperature(f);
        std::cout << ++a; 
        std::cout << a ;
        std::cout << "\n-----------------------------------\n";
        std::cout << "MIN: " << a.DajMinimalnuTemperaturu() << " MAX: " << a.DajMaksimalnuTeperaturu() << std::endl;
        std::cout << !a << std::endl;
        /*std::vector<int> v=-a;
        std::for_each(v.begin(),v.end(),[](int x){std::cout << x << " ";});*/
        std::pair<int,int> par=a[1];
        std::cout << par.first << " " << par.second << std::endl;
        std::cout << a;
        std::cout << "\n-----------------------------------\n";
       Temperature k(-5,5);
        k.RegistrirajTemperature(b);
        k.RegistrirajTemperature(c);
        k.RegistrirajTemperature(d);
        k.RegistrirajTemperature(e);
        k.RegistrirajTemperature(f);
        std::cout << (k == a) <<std::endl;
        std::cout << (a-=2);
        std::cout << "\n-----------------------------------\n";
        a=-1-a;
        std::cout << a;
    }catch(std::range_error e){
        std::cout << e.what() << std::endl;
    }catch(std::logic_error e){
        std::cout << e.what() << std::endl;
    }
	return 0;
}