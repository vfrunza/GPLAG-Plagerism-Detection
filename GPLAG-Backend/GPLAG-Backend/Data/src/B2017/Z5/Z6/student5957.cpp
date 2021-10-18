/B2017/2018: Zadaća 5, Zadatak 6
#include <iostream>
#include <iomanip>
#include <stdexcept>
#include <functional>
#include <vector>
#include <algorithm>
using std::vector;
using std::cout;
using std::cin;

class Berza{
    int min,max;
    mutable vector<int> v;
    public:
    Berza(int min,int max){
        if(min<0 || max<0) throw std::range_error("Ilegalne granicne cijene");
        Berza::min=min; Berza::max=max;
    }
    explicit Berza(int max){
        if(min<0 || max<0) throw std::range_error("Ilegalne granicne cijene");
        Berza::min=0; Berza::max=max;
    }
    void RegistrirajCijenu(int n);
    int DajBrojRegistriranihCijena() const{ return v.size(); }
    void BrisiSve(){ v.resize(0); }
    int DajMinimalnuCijenu() const;
    int DajMaksimalnuCijenu() const;
    friend bool operator!(const Berza &b){ return b.DajBrojRegistriranihCijena()==0; }
    int DajBrojCijenaVecihOd(int n) const;
    void Ispisi() const;
    int operator[](int n) const;
    friend Berza &operator++(Berza &b);
    friend Berza &operator--(Berza &b);
    friend Berza operator++(Berza &b,int);
    friend Berza operator--(Berza &b,int);
    friend Berza operator-(Berza &b);
    friend Berza operator-(Berza &b,int n);
    friend Berza operator+(Berza &b,int n);
    friend Berza operator+(int n,Berza &b);
    friend Berza operator-(int n,Berza &b);
    friend Berza operator+(Berza &b1,Berza &b2);
    friend bool operator==(Berza &b1,Berza &b2);
    friend bool operator!=(Berza &b1,Berza &b2);
    friend Berza &operator+=(Berza &b1,Berza &b2);
    friend Berza &operator-=(Berza &b,int n);
    friend Berza &operator+=(Berza &b,int n);
};
void Berza::RegistrirajCijenu(int n){
    if(n<min || n>max) throw std::range_error("Ilegalna cijena");
    v.push_back(n);
}
int Berza::DajMinimalnuCijenu() const{
    if(v.size()==0) throw std::range_error("Nema registriranih cijena");
    return *std::min_element(v.begin(),v.end());
}
int Berza::DajMaksimalnuCijenu() const{
    if(v.size()==0) throw std::range_error("Nema registriranih cijena");
    return *std::max_element(v.begin(),v.end());
}
int Berza::DajBrojCijenaVecihOd(int n) const{
    if(v.size()==0) throw std::range_error("Nema registriranih cijena");
    return std::count_if(v.begin(),v.end(),std::bind(std::greater<int>(), std::placeholders::_1, n));
}
void Berza::Ispisi() const{
    std::sort(v.begin(),v.end(),std::greater<int>());
    for(auto x : v) cout<<std::fixed<<std::setprecision(2)<<x/100.<<std::endl;
}
int Berza::operator[](int n) const{
    if(n<0 || n>v.size()) throw std::range_error("Neispravan indeks");
    return v[n-1];
}
Berza &operator++(Berza &b){
    if(*std::max_element(b.v.begin(),b.v.end())+100>b.max) throw std::range_error("Prekoracen dozvoljeni opseg cijena");
    std::transform(b.v.begin(),b.v.end(),b.v.begin(),std::bind(std::plus<int>(),std::placeholders::_1,100));
    return b;
}
Berza &operator--(Berza &b){
    if(*std::min_element(b.v.begin(),b.v.end())-100<b.min) throw std::range_error("Prekoracen dozvoljeni opseg cijena");
    std::transform(b.v.begin(),b.v.end(),b.v.begin(),std::bind(std::minus<int>(),std::placeholders::_1,100));
    return b;
}
Berza operator++(Berza &b,int){
    if(*std::max_element(b.v.begin(),b.v.end())+100>b.max) throw std::range_error("Prekoracen dozvoljeni opseg cijena");
    Berza pom(b);
    ++b;
    return pom;
}
Berza operator--(Berza &b,int){
    if(*std::min_element(b.v.begin(),b.v.end())-100<b.min) throw std::range_error("Prekoracen dozvoljeni opseg cijena");
    Berza pom(b);
    --b;
    return pom;
}
Berza operator-(Berza &b){
    Berza pom(b);
    std::transform(pom.v.begin(),pom.v.end(),pom.v.begin(),std::bind(std::minus<int>(),std::placeholders::_1,pom.min+pom.max));
    std::transform(pom.v.begin(),pom.v.end(),pom.v.begin(),std::bind(std::multiplies<int>(),std::placeholders::_1,-1));
    return pom;
}
Berza operator-(Berza &b,int n){
    Berza pom(b);
    if(n>=0){
         if(*std::max_element(b.v.begin(),b.v.end())+n>b.max) throw std::domain_error("Prekoracen dozvoljeni opseg cijena");
         std::transform(pom.v.begin(),pom.v.end(),pom.v.begin(),std::bind(std::minus<int>(),std::placeholders::_1,n));
    }
    else{
        if(*std::min_element(b.v.begin(),b.v.end())-n<b.min) throw std::domain_error("Prekoracen dozvoljeni opseg cijena");
         std::transform(pom.v.begin(),pom.v.end(),pom.v.begin(),std::bind(std::plus<int>(),std::placeholders::_1,n));
    }
    return pom;
}
Berza operator+(Berza &b,int n){
    Berza pom(b);
    if(n>=0){
         if(*std::max_element(b.v.begin(),b.v.end())+n>b.max) throw std::domain_error("Prekoracen dozvoljeni opseg cijena");
         std::transform(pom.v.begin(),pom.v.end(),pom.v.begin(),std::bind(std::plus<int>(),std::placeholders::_1,n));
    }
    else{
        if(*std::min_element(b.v.begin(),b.v.end())-n<b.min) throw std::domain_error("Prekoracen dozvoljeni opseg cijena");
         std::transform(pom.v.begin(),pom.v.end(),pom.v.begin(),std::bind(std::minus<int>(),std::placeholders::_1,n));
    }
    return pom;
}
Berza operator+(int n,Berza &b){
    try{ Berza pom(b+n); return pom; }
    catch(...){ throw std::domain_error("Prekoracen dozvoljeni opseg cijena"); }
}
Berza operator-(int n,Berza &b){
    int min(*std::min_element(b.v.begin(),b.v.end())),max(*std::max_element(b.v.begin(),b.v.end()));
    min=n-min; max=n-max;
    if(!(max<=b.max && max>=b.min && min<=b.max && min>=b.min)) throw std::domain_error("Prekoracen dozvoljeni opseg cijena");
    Berza pom(b);
    std::transform(pom.v.begin(),pom.v.end(),pom.v.begin(),std::bind(std::multiplies<int>(),std::placeholders::_1,-1));
    std::transform(pom.v.begin(),pom.v.end(),pom.v.begin(),std::bind(std::plus<int>(),std::placeholders::_1,n));
    return pom;
}
Berza operator+(Berza &b1,Berza &b2){
    if(b1.v.size()!=b2.v.size() || b1.min!=b2.min || b1.max!=b2.max) throw std::domain_error("Nesaglasni operandi");
    if(*std::max_element(b1.v.begin(),b1.v.end())+*std::max_element(b2.v.begin(),b2.v.end())>b1.max)
        throw std::domain_error("Prekoracen dozvoljeni opseg cijena");
    Berza pom(b1);
    std::transform(pom.v.begin(),pom.v.end(),b2.v.begin(),pom.v.begin(),std::plus<int>());
    return pom;
}
bool operator==(Berza &b1,Berza &b2){
    if(b1.v.size()!=b2.v.size()) return false;
    return std::equal(b1.v.begin(),b1.v.end(),b2.v.begin(),std::equal_to<int>());
}
bool operator!=(Berza &b1,Berza &b2){
    return !(b1==b2);
}
Berza &operator+=(Berza &b1,Berza &b2){
    b1=b1+b2;
    return b1;
}
Berza &operator-=(Berza &b,int n){
    b=b-n;
    return b;
}
Berza &operator+=(Berza &b,int n){
    b=b+n;
    return b;
}

int main ()
{
    int min1(0),max1(0),min2(0),max2(0),dim(0);
    cout<<"Unesi min i max cijenu prve berze: ";
    cin>>min1>>max1;
    cout<<"Unesi min i max cijenu druge berze: ";
    cin>>min2>>max2;
    cout<<"Unesi broj registriranih cijena berzi: ";
    cin>>dim;
    Berza b1(min1,max1),b2(min2,max2);
    try{
        cout<<"Unesi cijene prve berze: ";
        for(int i(0);i<dim;i++){
        int n(0);
        cin>>n;
        b1.RegistrirajCijenu(n);
    }
        cout<<"Unesi cijene druge berze: ";
        for(int i(0);i<dim;i++){
        int n(0);
        cin>>n;
        b2.RegistrirajCijenu(n);
    }
        Berza b3(b1+b2);
        cout<<"Zbir ove dvije berze je :";
        b3.Ispisi();
    }
    catch(std::domain_error izuzetak){
        cout<<izuzetak.what();
    }
    catch(std::range_error izuzetak){
        cout<<izuzetak.what();
    }
    
	return 0;
}
