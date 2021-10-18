/B16/17 (Zadaća 5, Zadatak 5)
//Autotestovi by Berina Cocalic (mail: bcocalic1@etf.unsa.ba)
//Za autotestove se obracati *iskljucivo* osobi koja ih pise
#include <iostream>
#include <list>
#include <stdexcept>
#include <algorithm>
#include <functional>
#include <vector>
class Temperature{
    int m;
    int M;
    std::list<int>min,max;
    public:
    Temperature(int mi,int ma){
        if(mi>ma)throw std::range_error("Nekorektne temperature");
    Temperature::m=mi;
    Temperature::M=ma;
    min.push_back(mi);
    max.push_back(ma);
    }
    void RegistrirajTemperature(std::pair<int,int> t);
    void BrisiSve();
    void BrisiNegativneTemperature();
    int DajBrojRegistriranihTemperatura()const{
        return min.size();
    }
    int DajMinimalnuTemperaturu();
    int DajMaksimalnuTemperaturu();
    int DajBrojTemperaturaVecihOd(int t)const;
    int DajBrojTemperaturaManjihOd(int t)const;
    friend bool operator !(Temperature &t){
        return t.min.size()==0;
    }
    Temperature &operator ++ () { 
         std::transform(min.begin(), min.end(),min.begin(), std::bind(std::plus<int>(), 1, std::placeholders::_1)); 
         if(std::count_if(min.begin(),min.end(),std::bind(std::greater<int>(),std::placeholders::_1,Temperature::M))>0)
         throw std::logic_error("Ilegalna operacija");
        return *this;
    }
    Temperature &operator --();
    Temperature operator ++(int);
    Temperature operator --(int);
    friend std::vector<int> operator *(const Temperature &t);
    friend std::vector<int> operator -(const Temperature &t);
    friend std::vector<int> operator +(const Temperature &t);
    std::pair<int,int> operator [](int i)const;
    friend Temperature operator +(const Temperature &x,int y);
    friend Temperature operator -(const Temperature &x,int y);
    friend Temperature operator +(int y,const Temperature &x);
    friend Temperature operator -(int y,const Temperature &x);
    Temperature &operator +=(int y);
    Temperature &operator -=(int y);
    friend bool operator ==(const Temperature &t1,const Temperature &t2);
    friend bool operator !=(const Temperature &t1,const Temperature &t2);
    friend std::ostream &operator <<(std::ostream &cout,const Temperature &t);
};
void Temperature::RegistrirajTemperature(std::pair<int,int> t){
    if(t.first>t.second || t.first<Temperature::m || t.second<Temperature::m || t.first>Temperature::M || t.second>Temperature::M )throw std::range_error("Nekorektne temperature");
    min.push_back(t.first);
    max.push_back(t.second);
}
void Temperature::BrisiSve(){
    min.clear();
    max.clear();
}
void Temperature::BrisiNegativneTemperature(){
    
}
int Temperature::DajMinimalnuTemperaturu(){
    if(min.size()==0)throw std::logic_error("Nema registriranih temperatura");
    return *min_element(min.begin(),min.end());
}
int Temperature::DajMaksimalnuTemperaturu(){
    if(max.size()==0)throw std::logic_error("Nema registriranih temperatura");
    return *max_element(max.begin(),max.end());
}
int Temperature::DajBrojTemperaturaVecihOd(int t)const{
    if(min.size()==0)throw std::logic_error("Nema registriranih temperatura");
    return std::count_if(min.begin(),min.end(),std::bind(std::less<int>(),t,std::placeholders::_1));
}
int Temperature::DajBrojTemperaturaManjihOd(int t)const{
    if(max.size()==0)throw std::logic_error("Nema registriranih temperatura");
    return std::count_if(max.begin(),max.end(),std::bind(std::less<int>(),std::placeholders::_1,t));
}
Temperature &Temperature::operator --(){
    std::transform(max.begin(), max.end(),max.begin(), std::bind(std::plus<int>(), -1, std::placeholders::_1)); 
         if(std::count_if(max.begin(),max.end(),std::bind(std::greater<int>(),Temperature::m,std::placeholders::_1))>0)
         throw std::logic_error("Ilegalna operacija");
        return *this;
}
Temperature Temperature::operator ++(int){
    Temperature pom(*this);
    std::transform(min.begin(), min.end(),min.begin(), std::bind(std::plus<int>(), 1, std::placeholders::_1)); 
         if(std::count_if(min.begin(),min.end(),std::bind(std::greater<int>(),std::placeholders::_1,Temperature::M))>0)
         throw std::logic_error("Ilegalna operacija");
        return *this;
        return pom;
}
Temperature Temperature::operator --(int){
    Temperature pom(*this);
    std::transform(max.begin(), max.end(),max.begin(), std::bind(std::plus<int>(), -1, std::placeholders::_1)); 
         if(std::count_if(max.begin(),max.end(),std::bind(std::greater<int>(),Temperature::m,std::placeholders::_1))>0)
         throw std::logic_error("Ilegalna operacija");
        return *this;
        return pom;
}
std::vector<int> operator *(const Temperature &t){
    std::vector<int> v(t.DajBrojRegistriranihTemperatura());
    std::transform(t.max.begin(),t.max.end(),t.min.begin(),v.begin(),std::bind(std::minus<int>(),std::placeholders::_1,std::placeholders::_2));
    return v;
}
std::vector<int> operator -(const Temperature &t){
    std::vector<int> v(t.DajBrojRegistriranihTemperatura());
    std::transform(t.min.begin(),t.min.end(),v.begin(),std::bind(std::minus<int>(),std::placeholders::_1,t.m));
    return v;
}
std::vector<int> operator +(const Temperature &t){
    std::vector<int> v(t.DajBrojRegistriranihTemperatura());
    std::transform(t.max.begin(),t.max.end(),v.begin(),std::bind(std::minus<int>(),t.M,std::placeholders::_1));
    return v;
}
std::pair<int,int> Temperature::operator [](int i)const{
    if(i>DajBrojRegistriranihTemperatura())throw std::range_error("Neispravan indeks");
    auto a=this->min.begin();
    auto b=this->max.begin();
    std::advance(a,i-1);
    std::advance(b,i-1);
    return std::make_pair(*a,*b);
    
}
Temperature operator +(const Temperature &x,int y){
    Temperature t=x;
    std::transform(t.min.begin(), t.min.end(),t.min.begin(), std::bind(std::plus<int>(), y, std::placeholders::_1)); 
         if(std::count_if(t.min.begin(),t.min.end(),std::bind(std::greater<int>(),std::placeholders::_1,x.M))>0)
         throw std::logic_error("Prekoracen dozvoljeni opseg temperatura");
         std::transform(t.max.begin(), t.max.end(),t.max.begin(), std::bind(std::plus<int>(), y, std::placeholders::_1)); 
         if(std::count_if(t.max.begin(),t.max.end(),std::bind(std::greater<int>(),std::placeholders::_1,x.M))>0)
         throw std::logic_error("Prekoracen dozvoljeni opseg temperatura");
        return t;
}
Temperature operator -(const Temperature &x,int y){
    Temperature t=x;
    std::transform(t.min.begin(), t.min.end(),t.min.begin(), std::bind(std::minus<int>(), std::placeholders::_1,y)); 
         if(std::count_if(t.min.begin(),t.min.end(),std::bind(std::greater<int>(),std::placeholders::_1,x.m))>0)
         throw std::logic_error("Prekoracen dozvoljeni opseg temperatura");
         std::transform(t.max.begin(), t.max.end(),t.max.begin(), std::bind(std::minus<int>(), y, std::placeholders::_1)); 
         if(std::count_if(t.max.begin(),t.max.end(),std::bind(std::greater<int>(),std::placeholders::_1,x.m))>0)
         throw std::logic_error("Prekoracen dozvoljeni opseg temperatura");
        return t;
}
Temperature operator +(int y,const Temperature &x){
    return x+y;
}
Temperature operator -(int y,const Temperature &x){
    Temperature t=x;
    std::transform(x.min.begin(), x.min.end(),t.max.begin(), std::bind(std::minus<int>(),y, std::placeholders::_1)); 
    if(std::count_if(t.min.begin(),t.min.end(),std::bind(std::greater<int>(),std::placeholders::_1,x.m))>0)
         throw std::logic_error("Prekoracen dozvoljeni opseg temperatura");
    std::transform(x.max.begin(), x.max.end(),t.min.begin(), std::bind(std::minus<int>(), y, std::placeholders::_1));
    if(std::count_if(t.max.begin(),t.max.end(),std::bind(std::greater<int>(),std::placeholders::_1,x.m))>0)
         throw std::logic_error("Prekoracen dozvoljeni opseg temperatura");
    return t;
}
Temperature &Temperature::operator +=(int y){
    std::transform(this->min.begin(), this->min.end(),this->min.begin(), std::bind(std::plus<int>(), y, std::placeholders::_1)); 
         if(std::count_if(this->min.begin(),this->min.end(),std::bind(std::greater<int>(),std::placeholders::_1,this->M))>0)
         throw std::logic_error("Prekoracen dozvoljeni opseg temperatura");
         std::transform(this->max.begin(), this->max.end(),this->max.begin(), std::bind(std::plus<int>(), y, std::placeholders::_1)); 
         if(std::count_if(this->max.begin(),this->max.end(),std::bind(std::greater<int>(),std::placeholders::_1,this->M))>0)
         throw std::logic_error("Prekoracen dozvoljeni opseg temperatura");
         return *this;
}
Temperature &Temperature::operator -=(int y){
    std::transform(this->min.begin(), this->min.end(),this->min.begin(), std::bind(std::minus<int>(), std::placeholders::_1,y)); 
         if(std::count_if(this->min.begin(),this->min.end(),std::bind(std::greater<int>(),std::placeholders::_1,this->m))>0)
         throw std::logic_error("Prekoracen dozvoljeni opseg temperatura");
         std::transform(this->max.begin(), this->max.end(),this->max.begin(), std::bind(std::minus<int>(), y, std::placeholders::_1)); 
         if(std::count_if(this->max.begin(),this->max.end(),std::bind(std::greater<int>(),std::placeholders::_1,this->m))>0)
         throw std::logic_error("Prekoracen dozvoljeni opseg temperatura");
        return *this;
}
bool operator ==(const Temperature &t1,const Temperature &t2){
    if(t1.DajBrojRegistriranihTemperatura()!=t2.DajBrojRegistriranihTemperatura() || t1.m!=t2.m || t1.M!=t2.M )return false;
    return std::equal(t1.min.begin(),t1.min.end(),t2.min.begin()) && std::equal(t1.max.begin(),t1.max.end(),t2.max.begin());
    
}
bool operator !=(const Temperature &t1,const Temperature &t2){
    if(t1.DajBrojRegistriranihTemperatura()==t2.DajBrojRegistriranihTemperatura() && t1.m==t2.m && t1.M==t2.M && std::equal(t1.min.begin(),t1.min.end(),t2.min.begin()) && std::equal(t1.max.begin(),t1.max.end(),t2.max.begin()) )return false;
    return true;
}
std::ostream &operator <<(std::ostream &cout,const Temperature &t){
    std::for_each(t.min.begin(),t.min.end(),[&cout](int a){cout<<a<<" ";});
    cout<<std::endl;
    std::for_each(t.max.begin(),t.max.end(),[&cout](int a){cout<<a<<" ";});
    return cout;
}
int main ()
{
    Temperature t(-10,10);
    t.RegistrirajTemperature({5,8});
    //--t;
    std::cout<<t;
    t.BrisiNegativneTemperature();
    std::cout<<t;
    /*std::cout<<std::endl<<t.DajBrojRegistriranihTemperatura()<<std::endl;
    std::cout<<"minimalna "<<t.DajMinimalnuTemperaturu()<<std::endl;
    std::cout<<"maximalna "<<t.DajMaksimalnuTeperaturu()<<std::endl;
    std::cout<<"da vidimo "<<t.DajBrojTeperaturaVecihOd(1)<<std::endl;
    //t.BrisiSve();
    //t.Ispisi();
    std::cout<<!t;
    std::cout<<std::endl<<t.DajBrojRegistriranihTemperatura()<<std::endl;
    std::vector<int>v (+t);
    for(int x:v)std::cout<<x<<" ";
    std::cout<<std::endl;
    std::pair<int,int>po=t[2];
    std::cout<<po.first<<" "<<po.second;*/
	return 0;
}