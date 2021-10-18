/B16/17 (Zadaća 5, Zadatak 5)
//Autotestovi by Berina Cocalic (mail: bcocalic1@etf.unsa.ba)
//Za autotestove se obracati *iskljucivo* osobi koja ih pise
#include <iostream>
#include <stdexcept>
#include <list>
#include <utility>
#include <algorithm>
#include <functional>
#include <iterator>
#include <vector>
class Temperature{
    int MinLimit;
    int MaxLimit;
    std::list<int> MinT;
    std::list<int> MaxT;
    public:
    Temperature(int Tmin,int Tmax);
    void RegistrirajTemperature(std::pair<int,int> temp);
    void BrisiSve();
    int DajBrojRegistriranih()const{return MinT.size();}
    void BrisiNegativneTemperature();
    int DajMinimalnuTemperaturu()const;
    int DajMaximalnuTemperaturu()const;
    int DajBrojTemperaturaVecihOd(int x)const;
    int DajBrojTemperaturaManjihOd(int x)const;
    friend bool operator !(const Temperature &T);
    friend Temperature &operator++(Temperature &T);
    friend Temperature operator++(Temperature &T,int);
    friend Temperature &operator--(Temperature &T);
    friend Temperature operator--(Temperature &T,int);
    friend std::vector<int> operator*(Temperature t1);
    friend std::vector<int> operator-(Temperature t1);
    friend std::vector<int> operator+(Temperature t1);
    friend Temperature operator+(Temperature t1,int n);
    friend Temperature operator+(int n,Temperature t1){
    try{return t1+n;}catch(std::logic_error x){throw x;}}
    friend Temperature operator-(Temperature t1,int n);
    friend Temperature operator-(int n,Temperature t1);
    std::pair<int,int> operator()(int i);
    friend Temperature &operator+=(Temperature &t1,int n);
    friend Temperature &operator-=(Temperature &t1,int n);
    friend std::ostream &operator<<(std::ostream& izlaz,Temperature &t);
    friend bool operator==(const Temperature &t1,const Temperature &t2);
    friend bool operator!=(const Temperature &t1,const Temperature &t2);
};
Temperature::Temperature(int Tmin,int Tmax){
    if(Tmin>Tmax)throw std::range_error("Nekorektne temperature");
    MinLimit=Tmin;
    MaxLimit=Tmax;
}
void Temperature::RegistrirajTemperature(std::pair<int,int> temp){
    if(temp.first<MinLimit || temp.second>MaxLimit || temp.first>temp.second)
    throw std::range_error("Nekorektne temperature");
    MinT.push_back(temp.first);MaxT.push_back(temp.second);
}
void Temperature::BrisiSve(){
      MinT.resize(0);
      MaxT.resize(0);
}
void Temperature::BrisiNegativneTemperature(){
    std::vector<int> pomocni;
    auto a=MaxT.begin();
    auto b=pomocni.begin();
    std::copy(MinT.begin(),MinT.end(),pomocni.begin());
    std::remove_if(MinT.begin(),MinT.end(),std::bind(std::greater<int>(),*(a++),std::placeholders::_1));
    std::remove_if(MaxT.begin(),MaxT.end(),std::bind(std::greater<int>(),*(b++),std::placeholders::_1));
}
int Temperature::DajMinimalnuTemperaturu()const{
    if(MinT.size()==0 || MaxT.size()==0)throw std::logic_error("Nema registriranih temperatura");
    int a=*std::min_element(MinT.begin(),MinT.end());
    int b=*std::min_element(MaxT.begin(),MaxT.end());
    if(a<b)return a;
    return b;
}
int Temperature::DajMaximalnuTemperaturu()const{
    if(MinT.size()==0 || MaxT.size()==0)throw std::logic_error("Nema registriranih temperatura");
    int a=*std::max_element(MinT.begin(),MinT.end());
    int b=*std::max_element(MaxT.begin(),MaxT.end());
    if(a>b)return a;
    return b;
}
int Temperature::DajBrojTemperaturaVecihOd(int x)const{
    if(MinT.size()==0 || MaxT.size()==0)throw std::logic_error("Nema registriranih temperatura");
    return (std::count_if(MaxT.begin(),MaxT.end(),std::bind(std::less<int>(),x,std::placeholders::_1))+
    std::count_if(MinT.begin(),MinT.end(),std::bind(std::less<int>(),x,std::placeholders::_1)));
}
int Temperature::DajBrojTemperaturaManjihOd(int x)const{
    if(MinT.size()==0 || MaxT.size()==0)throw std::logic_error("Nema registriranih temperatura");
    return (std::count_if(MaxT.begin(),MaxT.end(),std::bind(std::greater<int>(),x,std::placeholders::_1))+
    std::count_if(MinT.begin(),MinT.end(),std::bind(std::greater<int>(),x,std::placeholders::_1)));

}
bool operator !(const Temperature &T){
    if(T.MinT.size()==0 || T.MaxT.size())return false;
    return true;
}
Temperature &operator++(Temperature &T){
    std::transform(T.MinT.begin(),T.MinT.end(),T.MinT.begin(),std::bind(std::plus<int>(),1,std::placeholders::_1));
    int a=std::count_if(T.MinT.begin(),T.MinT.end(),std::bind(std::less_equal<int>(),T.MinLimit,std::placeholders::_1));
    if(a!=T.MinT.size())throw std::logic_error("Ilegalna operacija");
    return T;
}
Temperature operator++(Temperature &T,int){
    auto vrati=T;
    std::transform(T.MinT.begin(),T.MinT.end(),T.MinT.begin(),std::bind(std::plus<int>(),1,std::placeholders::_1));
    int a=std::count_if(T.MinT.begin(),T.MinT.end(),std::bind(std::less_equal<int>(),T.MinLimit,std::placeholders::_1));
    if(a!=T.MinT.size())throw std::logic_error("Ilegalna operacija");
    return vrati;
}
Temperature &operator--(Temperature &T){
    std::transform(T.MaxT.begin(),T.MaxT.end(),T.MaxT.begin(),std::bind(std::minus<int>(),std::placeholders::_1,1));
    int b=std::count_if(T.MaxT.begin(),T.MaxT.end(),std::bind(std::greater_equal<int>(),T.MaxLimit,std::placeholders::_1));
    if(b!=T.MaxT.size())throw std::logic_error("Ilegalna operacija");
    return T;
}
Temperature operator--(Temperature &T,int){
    auto vrati=T;
    std::transform(T.MaxT.begin(),T.MaxT.end(),T.MaxT.begin(),std::bind(std::minus<int>(),std::placeholders::_1,1));
    int b=std::count_if(T.MaxT.begin(),T.MaxT.end(),std::bind(std::greater_equal<int>(),T.MaxLimit,std::placeholders::_1));
    if(b!=T.MaxT.size())throw std::logic_error("Ilegalna operacija");
    return vrati;
}
std::vector<int> operator*(Temperature t1){
    std::vector<int> vrati;vrati.resize(t1.MaxT.size());
    std::transform(t1.MaxT.begin(),t1.MaxT.end(),t1.MinT.begin(),vrati.begin(),std::minus<int>());
    return vrati;
}
std::vector<int> operator-(Temperature t1){
    std::vector<int> vrati;vrati.resize(t1.MinT.size());
    std::transform(t1.MinT.begin(),t1.MinT.end(),vrati.begin(),std::bind(std::minus<int>(),std::placeholders::_1,t1.MinLimit));
    return vrati;
}
std::vector<int> operator+(Temperature t1){
    std::vector<int> vrati;vrati.resize(t1.MaxT.size());
    std::transform(t1.MaxT.begin(),t1.MaxT.end(),vrati.begin(),std::bind(std::minus<int>(),std::placeholders::_1,t1.MaxLimit));
    return vrati;
}
std::pair<int,int> Temperature::operator()(int i){
    if(i<1 || i>MinT.size())throw std::range_error("Neispravan indeks");
    std::vector<int> a;a.resize(MinT.size());
    std::vector<int> b;b.resize(MaxT.size());
    std::copy(MinT.begin(),MinT.end(),a.begin());
    std::copy(MaxT.begin(),MaxT.end(),b.begin());
    return std::make_pair(a[i-1],b[i-1]);
}
Temperature operator+(Temperature t1,int n){
    Temperature vrati=t1;
    std::transform(t1.MinT.begin(),t1.MinT.end(),vrati.MinT.begin(),std::bind(std::plus<int>(),n,std::placeholders::_1));
    std::transform(t1.MaxT.begin(),t1.MaxT.end(),vrati.MaxT.begin(),std::bind(std::plus<int>(),n,std::placeholders::_1));
    int a=std::count_if(t1.MinT.begin(),t1.MinT.end(),std::bind(std::less_equal<int>(),t1.MinLimit,std::placeholders::_1));
    if(a!=t1.MinT.size())throw std::logic_error("Prekoracen dozvoljeni opseg temperatura");
    int b=std::count_if(t1.MaxT.begin(),t1.MaxT.end(),std::bind(std::greater_equal<int>(),t1.MaxLimit,std::placeholders::_1));
    if(b!=t1.MaxT.size())throw std::logic_error("Prekoracen dozvoljeni opseg temperatura");
    return vrati;
}
Temperature operator-(Temperature t1,int n){
    Temperature vrati=t1;
    std::transform(t1.MinT.begin(),t1.MinT.end(),vrati.MinT.begin(),std::bind(std::minus<int>(),std::placeholders::_1,n));
    std::transform(t1.MaxT.begin(),t1.MaxT.end(),vrati.MaxT.begin(),std::bind(std::minus<int>(),std::placeholders::_1,n));
    int a=std::count_if(t1.MinT.begin(),t1.MinT.end(),std::bind(std::less_equal<int>(),t1.MinLimit,std::placeholders::_1));
    if(a!=t1.MinT.size())throw std::logic_error("Prekoracen dozvoljeni opseg temperatura");
    int b=std::count_if(t1.MaxT.begin(),t1.MaxT.end(),std::bind(std::greater_equal<int>(),t1.MaxLimit,std::placeholders::_1));
    if(b!=t1.MaxT.size())throw std::logic_error("Prekoracen dozvoljeni opseg temperatura");
    return vrati;
}
Temperature operator-(int n,Temperature t1){
    Temperature vrati=t1;
    std::transform(vrati.MinT.begin(),vrati.MinT.end(),vrati.MinT.begin(),std::bind(std::minus<int>(),n,std::placeholders::_1));
    std::transform(vrati.MaxT.begin(),vrati.MaxT.end(),vrati.MaxT.begin(),std::bind(std::minus<int>(),n,std::placeholders::_1));
    int a=std::count_if(vrati.MinT.begin(),vrati.MinT.end(),std::bind(std::less_equal<int>(),t1.MinLimit,std::placeholders::_1));
    if(a!=vrati.MinT.size())throw std::logic_error("Prekoracen dozvoljeni opseg temperatura");
    int b=std::count_if(t1.MaxT.begin(),t1.MaxT.end(),std::bind(std::greater_equal<int>(),t1.MaxLimit,std::placeholders::_1));
    if(b!=vrati.MaxT.size())throw std::logic_error("Prekoracen dozvoljeni opseg temperatura");
    return vrati;
}
//operator ,==,!= i funkcija koja izbacuje neg temp;
Temperature &operator+=(Temperature &t1,int n){
    return t1=t1+n;
}
Temperature &operator-=(Temperature &t1,int n){
    return t1=t1-n;
}
bool operator==(const Temperature &t1,const Temperature &t2){
    if(t1.MaxT.size()!=t2.MaxT.size())return false;
    if(t1.MinT.size()!=t2.MinT.size())return false;
    auto testmax=t1.MaxT;
    auto testmin=t2.MinT;
    std::transform(t1.MaxT.begin(),t1.MaxT.end(),t2.MaxT.begin(),testmax.begin(),std::minus<int>());
    std::transform(t1.MinT.begin(),t1.MinT.end(),t2.MinT.begin(),testmin.begin(),std::minus<int>());
    int a=std::count(testmax.begin(),testmax.end(),0);
    int b=std::count(testmin.begin(),testmin.end(),0);
    if(a!=testmax.size() || b!=testmin.size())return false;
    return true;
}
bool operator!=(const Temperature &t1,const Temperature &t2){
    if(t1==t2)return false;
    return true;
}
std::ostream &operator<<(std::ostream &izlaz,Temperature &t){
    std::copy(t.MinT.begin(),t.MinT.end(),std::ostream_iterator<int>(izlaz," "));
        izlaz<<"\n";
    std::copy(t.MaxT.begin(), t.MaxT.end(),std::ostream_iterator<int>(izlaz," ")); // nasao na stranici cplusplus.com

    return izlaz;
}
int main ()
{
    Temperature T(-20,30);
    T.RegistrirajTemperature(std::make_pair(-1,1));
    T.RegistrirajTemperature(std::make_pair(-5,13));
    T.RegistrirajTemperature(std::make_pair(12,17));
    T.RegistrirajTemperature(std::make_pair(-11,-1));
    try{
    T.RegistrirajTemperature(std::make_pair(-20,25));
    }catch(std::range_error x){std::cout<<x.what();}
    std::cout<<T<<"\n";
    std::cout<<T.DajMaximalnuTemperaturu()<<" maximalna t \n";
    std::cout<<T.DajMinimalnuTemperaturu()<<" minimalna t \n";
    std::cout<<T.DajBrojRegistriranih()<<" br registriranih \n";
    std::cout<<T.DajBrojTemperaturaVecihOd(0)<<" br vecih od 0 \n";
    std::cout<<T.DajBrojTemperaturaManjihOd(20)<<" br manjih od 20 \n";
    std::cout<<"OPerator ++T :";
    T++;
    T--;
    std::cout<<++T<<"\n Operator -- :";
    std::cout<<--T<<"\n";
    std::cout<<"OPAA T+=3 i T-=3 \n";
    T+=3;
    std::cout<<T<<"\n";
    T-=3;
    std::cout<<T;
    auto c=T;
    c+=1;
    c+=1;
    std::cout<<"DA LI SU ISTI :  "<<int(c==T);
    
	return 0;
}