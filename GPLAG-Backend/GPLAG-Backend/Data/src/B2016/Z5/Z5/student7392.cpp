/B16/17 (Zadaća 5, Zadatak 5)
//Autotestovi by Berina Cocalic (mail: bcocalic1@etf.unsa.ba)
//Za autotestove se obracati *iskljucivo* osobi koja ih pise
#include <iostream>
#include <list>
#include <algorithm>
#include <functional>
#include <vector>
#include <limits>
#include <iterator>

class Temperature{
    std::list<int> minimalne;
    std::list<int> maximalne;
    int maxmoze;
    int minmoze;
public:
    Temperature(int manja, int veca);
    void RegistrirajTemperature(std::pair<int, int> p);
    void BrisiSve();
    void BrisiNegativneTemperature();
    int DajBrojRegistriranihTemperatura() const;
    int DajMinimalnuTemperaturu() const;
    int DajMaksimalnuTemperaturu() const;
    int DajBrojTemperaturaVecihOd(int x) const;
    int DajBrojTemperaturaManjihOd(int x) const;
    bool operator !() const;
    Temperature& operator ++();
    Temperature operator ++(int);
    Temperature& operator --();
    Temperature operator --(int);
    std::vector<int> operator *() const;
    std::vector<int> operator +() const;
    std::vector<int> operator -() const;
    const std::pair<int, int> operator [](int x) const;
    Temperature operator +(int x) const;
    Temperature operator -(int x) const;
    friend std::ostream& operator <<(std::ostream& fout, const Temperature &t1);
    friend Temperature operator +(int x, const Temperature &t1);
    friend Temperature operator -(int x, const Temperature &t1);
    Temperature& operator +=(int x);
    Temperature& operator -=(int x);
    bool operator ==(const Temperature &t1) const;
    bool operator !=(const Temperature &t1) const;
};

Temperature::Temperature(int manja, int veca){
    if(veca<manja)throw std::range_error("Nekorektne temperature");
    maxmoze=veca;
    minmoze=manja;
}
void Temperature::RegistrirajTemperature(std::pair<int, int> p){
    if(p.second<p.first || p.first<minmoze || p.second>maxmoze)throw std::range_error("Nekorektne temperature");
    minimalne.push_back(p.first);
    maximalne.push_back(p.second);
}
void Temperature::BrisiSve(){
    minimalne.clear();
    maximalne.clear();
}
void Temperature::BrisiNegativneTemperature(){
    std::list<int> minimalne1;
    std::list<int> maximalne1;
}
int Temperature::DajBrojRegistriranihTemperatura() const{
    return std::count_if(minimalne.begin(),minimalne.end(),std::bind2nd(std::greater_equal<int>(),std::numeric_limits<int>::lowest()));
}
int Temperature::DajMinimalnuTemperaturu() const{
    if(DajBrojRegistriranihTemperatura()==0)throw std::logic_error("Nema registriranih temperatura");
    return *std::min_element(minimalne.begin(),minimalne.end(),std::less<int>());
}
int Temperature::DajMaksimalnuTemperaturu() const{
    if(DajBrojRegistriranihTemperatura()==0)throw std::logic_error("Nema registriranih temperatura");
    return *std::max_element(maximalne.begin(),maximalne.end(),std::less<int>());
}
int Temperature::DajBrojTemperaturaVecihOd(int x) const{
    if(DajBrojRegistriranihTemperatura()==0)throw std::logic_error("Nema registriranih temperatura");
    return std::count_if(minimalne.begin(), minimalne.end(), std::bind(std::greater<int>(),std::placeholders::_1,x))+
           std::count_if(maximalne.begin(), maximalne.end(), std::bind(std::greater<int>(),std::placeholders::_1,x));
}
int Temperature::DajBrojTemperaturaManjihOd(int x) const{
    if(DajBrojRegistriranihTemperatura()==0)throw std::logic_error("Nema registriranih temperatura");
    return std::count_if(minimalne.begin(), minimalne.end(), std::bind(std::less<int>(),std::placeholders::_1,x))+
           std::count_if(maximalne.begin(), maximalne.end(), std::bind(std::less<int>(),std::placeholders::_1,x));
}
bool Temperature::operator !() const{
    if(DajBrojRegistriranihTemperatura()==0)return true;
    return false;
}
Temperature& Temperature::operator ++(){
    std::list<int> temp=minimalne;
    std::transform(maximalne.begin(),maximalne.end(),temp.begin(),temp.begin(),std::minus<int>());
    if(std::count_if(temp.begin(),temp.end(),std::bind(std::equal_to<int>(), std::placeholders::_1, 0))!=0)throw std::logic_error("Ilegalna operacija");
    std::transform(minimalne.begin(), minimalne.end(), minimalne.begin(), std::bind(std::plus<int>(),std::placeholders::_1, 1));
    return *this;
}
Temperature Temperature::operator ++(int){
    Temperature pomocna=*this;
    ++*this;
    return pomocna;
}
Temperature& Temperature::operator --(){
    std::list<int> temp=minimalne;
    std::transform(maximalne.begin(),maximalne.end(),temp.begin(),temp.begin(),std::minus<int>());
    if(std::count_if(temp.begin(),temp.end(),std::bind(std::equal_to<int>(), std::placeholders::_1, 0))!=0)throw std::logic_error("Ilegalna operacija");
    std::transform(maximalne.begin(), maximalne.end(), maximalne.begin(), std::bind(std::minus<int>(),std::placeholders::_1, 1));
    return *this;
}
Temperature Temperature::operator --(int){
    Temperature pomocna=*this;
    --*this;
    return pomocna;
}
std::vector<int> Temperature::operator *() const{
    std::vector<int> v;
    std::transform(maximalne.begin(), maximalne.end(),minimalne.begin(),std::back_inserter(v),std::minus<int>());
    return v;
}
std::vector<int> Temperature::operator +() const{
    std::vector<int> v;
    std::transform(maximalne.begin(), maximalne.end(),std::back_inserter(v), std::bind(std::minus<int>(), maxmoze, std::placeholders::_1));
    return v;
}
std::vector<int> Temperature::operator -() const{
    std::vector<int> v;
    std::transform(minimalne.begin(), minimalne.end(),std::back_inserter(v), std::bind(std::minus<int>(), std::placeholders::_1, minmoze));
    return v;
}
const std::pair<int, int> Temperature::operator [](int x) const{
    if(x<1 || x>DajBrojRegistriranihTemperatura())throw std::range_error("Neispravan indeks");
    std::vector<int> v;
    std::copy(minimalne.begin(),minimalne.end(),std::back_inserter(v));
    std::vector<int> v2;
    std::copy(maximalne.begin(),maximalne.end(),std::back_inserter(v2));
    return {v[x-1], v2[x-1]};
}
Temperature Temperature::operator +(int x) const{
    Temperature pomocna=*this;
    std::transform(minimalne.begin(), minimalne.end(), pomocna.minimalne.begin(), std::bind(std::plus<int>(), std::placeholders::_1, x));
    std::transform(maximalne.begin(), maximalne.end(), pomocna.maximalne.begin(), std::bind(std::plus<int>(), std::placeholders::_1, x));
    if(std::count_if(pomocna.minimalne.begin(), pomocna.minimalne.end(), std::bind(std::less<int>(), std::placeholders::_1, minmoze))!=0)throw std::logic_error("Prekoracen dozvoljeni opseg temperatura");
    if(std::count_if(pomocna.maximalne.begin(), pomocna.maximalne.end(), std::bind(std::greater<int>(), std::placeholders::_1, maxmoze))!=0)throw std::logic_error("Prekoracen dozvoljeni opseg temperatura");
    return pomocna;
}
Temperature Temperature::operator -(int x) const{
    Temperature pomocna=*this;
    std::transform(minimalne.begin(), minimalne.end(), pomocna.minimalne.begin(), std::bind(std::minus<int>(), std::placeholders::_1, x));
    std::transform(maximalne.begin(), maximalne.end(), pomocna.maximalne.begin(), std::bind(std::minus<int>(), std::placeholders::_1, x));
    if(std::count_if(pomocna.minimalne.begin(), pomocna.minimalne.end(), std::bind(std::less<int>(), std::placeholders::_1, minmoze))!=0)throw std::logic_error("Prekoracen dozvoljeni opseg temperatura");
    if(std::count_if(pomocna.maximalne.begin(), pomocna.maximalne.end(), std::bind(std::greater<int>(), std::placeholders::_1, maxmoze))!=0)throw std::logic_error("Prekoracen dozvoljeni opseg temperatura");
    return pomocna;
}
Temperature operator +(int x, const Temperature &t1){
    return t1+x;
}
Temperature operator -(int x, const Temperature &t1){
    Temperature pomocna=t1;
    std::transform(t1.minimalne.begin(), t1.minimalne.end(), pomocna.maximalne.begin(), std::bind(std::minus<int>(), x, std::placeholders::_1));
    std::transform(t1.maximalne.begin(), t1.maximalne.end(), pomocna.minimalne.begin(), std::bind(std::minus<int>(), x, std::placeholders::_1));
    if(std::count_if(pomocna.minimalne.begin(), pomocna.minimalne.end(), std::bind(std::less<int>(), std::placeholders::_1, t1.minmoze))!=0)throw std::logic_error("Prekoracen dozvoljeni opseg temperatura");
    if(std::count_if(pomocna.maximalne.begin(), pomocna.maximalne.end(), std::bind(std::greater<int>(), std::placeholders::_1, t1.maxmoze))!=0)throw std::logic_error("Prekoracen dozvoljeni opseg temperatura");
    return pomocna;
}
Temperature& Temperature::operator +=(int x){
    *this=*this+x;
    return *this;
}
Temperature& Temperature::operator -=(int x){
    *this=*this-x;
    return *this;
}
bool Temperature::operator ==(const Temperature &t1) const{
    if(maxmoze!=t1.maxmoze || minmoze!=t1.minmoze || DajBrojRegistriranihTemperatura()!=t1.DajBrojRegistriranihTemperatura())return false;
    if(!std::equal(minimalne.begin(), minimalne.end(), t1.minimalne.begin()))return false;
    if(!std::equal(maximalne.begin(), maximalne.end(), t1.maximalne.begin()))return false;
    return true;
}
bool Temperature::operator !=(const Temperature &t1) const{
    return !(*this==t1);
}
std::ostream& operator <<(std::ostream& fout, const Temperature &t1){
    std::ostream_iterator<int> oi(fout," ");
    std::copy(t1.minimalne.begin(), t1.minimalne.end(), oi);
    fout<<"\n";
    std::copy(t1.maximalne.begin(), t1.maximalne.end(), oi);
    return fout;
}

int main ()
{
    Temperature a(-4,7);
    a.RegistrirajTemperature({1,3});
    a.RegistrirajTemperature({0,4});
    std::vector<int> v;
    v=*a;
    for(auto i:v){
        std::cout<<i<<" ";
    }
    std::cout<<"\n";
    v=+a;
    for(auto i:v){
        std::cout<<i<<" ";
    }
    std::cout<<"\n";
    v=-a;
	for(auto i:v){
        std::cout<<i<<" ";
    }
    std::cout<<"\n";
    std::cout<<a++<<"\n";
    std::cout<<--a<<"\n";
    Temperature b(1,5);
    std::cout<<!b<<(a==b)<<(a!=b)<<"\n";
    auto c=a[1];
    std::cout<<c.first<<" "<<c.second<<"\n";
    std::cout<<a+2<<2+a<<2-a<<"\n";
    a-=2;
    std::cout<<a<<'\n';
	return 0;
}