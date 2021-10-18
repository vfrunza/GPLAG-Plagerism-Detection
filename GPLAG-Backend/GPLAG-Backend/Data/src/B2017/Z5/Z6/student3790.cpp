/B2017/2018: Zadaća 5, Zadatak 6
#include <iostream>
#include<string>
#include<vector>
#include<stdexcept>
#include<map>
#include<algorithm>
#include<functional>
#include<iomanip>
class Berza
{
    int min,max;
    std::vector<int> v;
public:
    Berza(int min1,int max1) {
        if(min1<0 or max1<0) throw std::range_error("Ilegalne granicne cijene");
        min=min1;
        max=max1;
    }
    explicit Berza(int max1) {
        max=max1;
        min=0;
        if(max1<0) throw std::range_error("Ilegalne granicne cijene");
    }
    void RegistrirajCijenu(int c) {
        if(c>max or c<min) throw std::range_error("Ilegalna cijena");
        v.push_back(c);
    }
    int DajBrojRegistriranihCijena()const {
        return v.size();
    }
    void BrisiSve() {
        v.resize(0);
    }
    int DajMinimalnuCijenu()const {
        if(v.size()==0) throw std::range_error("Nema registriranih cijena");
        return (*std::min_element(v.begin(),v.end()));
    }
    int DajMaksimalnuCijenu()const {
        if(v.size()==0) throw std::range_error("Nema registriranih cijena");
        return (*std::max_element(v.begin(),v.end()));
    }
    bool operator!()const {
        return (v.size()==0);
    }
    int DajBrojCijenaVecihOd(int m)const {
        if(v.size()==0) throw std::range_error("Nema registriranih cijena");
        int n=std::count_if(v.begin(),v.end(),std::bind(std::greater<int>(),std::placeholders::_1,m));
        return n;
    }
    int operator[](int i)const {
        if(i<1 or i>(v.size()+1)) throw std::range_error("Neispravan indeks");
        return v[i];
    }
    void Ispisi()const {
        std::vector<int> r=v;
        std::sort(r.begin(),r.end(),std::bind(std::greater<int>(),std::placeholders::_1,std::placeholders::_2));
        for(int i=0; i<r.size(); i++) {
            double o=r[i]/100.0;
            std::cout<<std::fixed<<std::setprecision(2)<<o<<std::endl;
        }
    }
    Berza operator ++() {
        Berza zamjena(min,max);
        zamjena.v.resize(v.size());
        zamjena.v=v;
        std::transform(v.begin(),v.end(),v.begin(),std::bind(std::plus<int>(),std::placeholders::_1,100));
        int i=0;
        i=std::count_if(v.begin(),v.end(),std::bind(std::greater<int>(),std::placeholders::_1,max));
        if(i!=0) throw std::range_error("Prekoracen dozvoljeni opseg cijena");
        return zamjena;
    }
    void operator --() {
        std::transform(v.begin(),v.end(),v.begin(),std::bind(std::minus<int>(),std::placeholders::_1,100));
        int i=0;
        i=std::count_if(v.begin(),v.end(),std::bind(std::less<int>(),std::placeholders::_1,min));
        if(i!=0) throw std::range_error("Prekoracen dozvoljeni opseg cijena");
    }
    Berza operator-()const {
        Berza b(min,max);
        b.v.resize(v.size());
        int zbir=max+min;
        std::transform(v.begin(),v.end(),b.v.begin(),std::bind(std::minus<int>(),zbir,std::placeholders::_1));
        return b;
    }
    Berza operator -(int y)const {
        Berza b(min,max);
        std::transform(v.begin(),v.end(),b.v.begin(),std::bind(std::minus<int>(),std::placeholders::_1,y));
        return b;
    }
    Berza operator +(int y)const {
        Berza b(min,max);
        std::transform(v.begin(),v.end(),b.v.begin(),std::bind(std::plus<int>(),std::placeholders::_1,y));
        return b;
    }
    bool operator!=(Berza b)const {
        if(b.v.size()!=v.size()) return 1;
        std::vector<int>br(v.size()) ;
        std::transform(v.begin(),v.end(),b.v.begin(),br.begin(),std::bind(std::not_equal_to<int>(),std::placeholders::_1,std::placeholders::_2));
        int i=0;
        i=std::count_if(br.begin(),br.end(),std::bind(std::greater<int>(),std::placeholders::_1,0));
        return(i!=0);
    }
    
    bool operator==(Berza b)const {
        if(b.v.size()!=v.size()) return 0;
        std::vector<int>br(v.size()) ;
        std::transform(v.begin(),v.end(),b.v.begin(),br.begin(),std::bind(std::not_equal_to<int>(),std::placeholders::_1,std::placeholders::_2));
        int i=0;
        i=std::count_if(br.begin(),br.end(),std::bind(std::greater<int>(),std::placeholders::_1,0));
        return(i==0);
    }
    Berza operator+=(int y){
        return *this+y;
    }
    Berza operator-=(int y){
        return *this-y;
    }
    Berza operator -(Berza b)const{
        if(min!=b.min or max!=b.max) throw std::domain_error("Nesaglasni operandi");
        Berza a(min,max);
        a.v.resize(v.size());
        std::transform(v.begin(),v.end(),b.v.begin(),a.v.begin(),std::bind(std::minus<int>(),std::placeholders::_1,std::placeholders::_2));
       int i=0;
        i=std::count_if(a.v.begin(),a.v.end(),std::bind(std::less<int>(),std::placeholders::_1,min));
        if(i!=0) throw std::range_error("Prekoracen dozvoljeni opseg cijena");
      return a;
    }
friend Berza& operator++( Berza&b);
friend Berza operator-(int y,Berza b);
};
 Berza operator-(int y,Berza b){
     Berza a(b.min,b.max);
        std::transform(b.v.begin(),b.v.end(),a.v.begin(),std::bind(std::minus<int>(),y,std::placeholders::_1));
       int i=0;
        i=std::count_if(a.v.begin(),a.v.end(),std::bind(std::less<int>(),std::placeholders::_1,b.min));
        if(i!=0) throw std::range_error("Prekoracen dozvoljeni opseg cijena");
      return a;
 }
 Berza operator+(int y,Berza d){
     return d+y;
 }
 Berza& operator++( Berza&b){
       std::transform(b.v.begin(),b.v.end(),b.v.begin(),std::bind(std::plus<int>(),std::placeholders::_1,100));
        int i=0;
        i=std::count_if(b.v.begin(),b.v.end(),std::bind(std::greater<int>(),std::placeholders::_1,b.max));
        if(i!=0) throw std::range_error("Prekoracen dozvoljeni opseg cijena");
        return b;
 }

int main ()
{
    //AT 4 - [javni] konstruktor, metode RegistrirajCijenu, Ispisi, BrisiSve
    Berza b1 = Berza(1000,4000);
    b1.RegistrirajCijenu(3222);
    b1.RegistrirajCijenu(1500);
    b1.RegistrirajCijenu(2000);
    std::cout << "Broj registrovanih cijena: " << b1.DajBrojRegistriranihCijena() << std::endl;
    b1.Ispisi();
    std::cout<<b1.DajBrojCijenaVecihOd(1500);
    b1.BrisiSve();
    std::cout << "Broj registrovanih cijena: " << b1.DajBrojRegistriranihCijena();
    return 0;
}
