/B2017/2018: Zadaća 5, Zadatak 6
#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <functional>
class Berza
{
    std::vector<int>v;
    int max,min;
public:
    Berza(int mini,int maxi) {
        if(mini<0||maxi<0) throw std::range_error("Ilegalne granice cijene");
        max=maxi;
        min=mini;
    }
    explicit Berza(int maxi) {
        if(maxi<0) throw std::range_error("Ilegalne granice cijene");
        max=maxi;
        min=0;
    }
    void RegistrirajCijenu(int cijena) {
        if(cijena<min||cijena>max) throw std::range_error("Ilegalna cijena");
        v.push_back(cijena);
    }
    int DajBrojRegistriranihCijena() const {
        return v.size();
    }
    void BrisiSve() {
        for(int i(0); i<v.size(); i++) v[i]=0;
        v.resize(0);
    }
    int DajMinimalnuCijenu() const {
        if(v.size()==0) throw std::range_error("Nema registriranih cijena");
        auto p(std::min_element(v.begin(),v.end()));
        return *p;
    }
    int DajMaksimalnuCijenu() const {
        if(v.size()==0) throw std::range_error("Nema registriranih cijena");
        auto p(std::max_element(v.begin(),v.end()));
        return *p;
    }
    bool operator ! () {
        if(v.size()==0) return true;
        return false;
    }
    int DajBrojCijenaVecihOd (int ref) const {
        int b(std::count_if(v.begin(),v.end(),std::bind(std::greater<int>(),std::placeholders::_1,ref)));//[ref](int x) {return x>ref; } ) );
        return b;
    }
    void Ispisi() const {
        std::vector<int>v1(v) ;
        std::sort(v1.begin(),v1.end(),std::greater<int>());
        for(int i(0); i<v1.size(); i++) {
            std::cout <<std::fixed<<std::setprecision(2)<<(v1.at(i)*(1./100))<< std::endl;
        }
    }
    int operator [] (int index) const {
        if(index<1||index>v.size()) throw std::range_error("Neispravan indeks");
        return v[index-1];
    }
    Berza operator ++(int) {
        Berza temp(*this);
        std::transform(v.begin(),v.end(),v.begin(),std::bind(std::plus<int>(),std::placeholders::_1,100));
        int broj_manjih(std::count_if(v.begin(),v.end(),std::bind(std::less<int>(),std::placeholders::_1,max)));
        if(broj_manjih!=v.size()-1)
            throw std::range_error("Prekoracen dozvoljeni opseg cijena");
        return temp;
    }
    Berza operator --(int) {
        Berza temp(*this);
        std::transform(v.begin(),v.end(),v.begin(),std::bind(std::minus<int>(),std::placeholders::_1,100));
        int broj_vecih(std::count_if(v.begin(),v.end(),std::bind(std::greater<int>(),std::placeholders::_1,min)));
        if(broj_vecih!=v.size()-1) throw std::range_error("Prekoracen dozvoljeni opseg");
        return temp;
    }
    Berza operator ++() {
        std::transform(v.begin(),v.end(),v.begin(),std::bind(std::plus<int>(),std::placeholders::_1,100));
        int broj_manjih(std::count_if(v.begin(),v.end(),std::bind(std::less<int>(),std::placeholders::_1,max)));
        if(broj_manjih!=v.size()-1) throw std::range_error("Prekoracen dozvoljeni opseg cijena");
        return *this;
    }
    Berza operator --() {
        std::transform(v.begin(),v.end(),v.begin(),std::bind(std::minus<int>(),std::placeholders::_1,100));
        int broj_vecih(std::count_if(v.begin(),v.end(),std::bind(std::greater<int>(),std::placeholders::_1,min)));
        if(broj_vecih!=v.size()-1) throw std::range_error("Prekoracen dozvoljeni opseg cijena");
        return *this;
    }
    Berza operator -() {
        int oduzeti(max-min);
        Berza temp(*this);
        std::transform(temp.v.begin(),temp.v.end(),temp.v.begin(),std::bind(std::minus<int>(),std::placeholders::_1,oduzeti));
        return temp;
    }
    Berza operator +(int x) {
        Berza temp(*this);
        std::transform(temp.v.begin(),temp.v.end(),temp.v.begin(),std::bind(std::plus<int>(),std::placeholders::_1,x));
        int broj_manjih(std::count_if(temp.v.begin(),temp.v.end(),std::bind(std::less<int>(),std::placeholders::_1,max)));
        if(broj_manjih!=v.size()-1) throw std::domain_error("Prekoracen dozvoljeni opseg cijena");
        return temp;
    }
    Berza operator -(int x) {
        Berza temp(*this);
        std::transform(temp.v.begin(),temp.v.end(),temp.v.begin(),std::bind(std::minus<int>(),std::placeholders::_1,x));
        int broj_vecih(std::count_if(temp.v.begin(),temp.v.end(),std::bind(std::greater<int>(),std::placeholders::_1,min)));
        if(broj_vecih!=v.size()-1) throw std::domain_error("Prekoracen dozvoljeni opseg cijena");
        return temp;
    }
    friend Berza operator +(int x, Berza b) {
        Berza temp(b+x);
        return temp;
    }
    friend Berza operator -(int x, Berza b) {

    }
    friend Berza operator +(Berza b1,Berza b2) {
        if(b1.max!=b2.max||b1.min!=b2.min||b1.v.size()!=b2.v.size())
            throw std::domain_error("Nesaglasni operandi");
        Berza temp(b1);
        std::transform(b1.v.begin(),b1.v.end(),b2.v.begin(),temp.v.begin(),std::bind(std::plus<int>(),std::placeholders::_1,std::placeholders::_2));
        int broj_manjih(std::count_if(temp.v.begin(),temp.v.end(),std::bind(std::less<int>(),std::placeholders::_1,b1.max)));
        if(broj_manjih!=temp.v.size()) throw std::domain_error("Prekoracen dozvoljeni opseg cijena");
        return temp;
    }
    friend Berza operator -(Berza b1,Berza b2) {
        if(b1.max!=b2.max||b1.min!=b2.min||b1.v.size()!=b2.v.size())
            throw std::domain_error("Nesaglasni operandi");
        Berza temp(b1);
        std::transform(b1.v.begin(),b1.v.end(),b2.v.begin(),temp.v.begin(),std::bind(std::minus<int>(),std::placeholders::_1,std::placeholders::_2));

        int broj_vecih(std::count_if(temp.v.begin(),temp.v.end(),std::bind(std::less<int>(),std::placeholders::_1,b1.min)));
        if(broj_vecih!=temp.v.size()) throw std::domain_error("Prekoracen dozvoljeni opseg cijena");
        return temp;
    }
    Berza &operator +=(const Berza &b) {
        std::transform(v.begin(),v.end(),b.v.begin(),v.begin(),std::bind(std::plus<int>(),std::placeholders::_1,std::placeholders::_2));
        int broj_manjih(std::count_if(v.begin(),v.end(),std::bind(std::less<int>(),std::placeholders::_1,max)));
        if(broj_manjih!=v.size()) throw std::domain_error("Prekoracen dozvoljeni opseg cijena");
        return *this;
    }
    Berza &operator -=(const Berza &b) {
        std::transform(v.begin(),v.end(),b.v.begin(),v.begin(),std::bind(std::minus<int>(),std::placeholders::_1,std::placeholders::_2));
        int broj_vecih(std::count_if(v.begin(),v.end(),std::bind(std::less<int>(),std::placeholders::_1,min)));
        if(broj_vecih!=v.size()) throw std::domain_error("Prekoracen dozvoljeni opseg cijena");        
        return *this;
    }
    friend bool operator == ( Berza b1, Berza b2)  {
        if(b1.v.size()!=b2.v.size()) return false;
        Berza tmp(b1);
        tmp.v.resize(0);
        std::transform(b1.v.begin(),b1.v.end(),b2.v.begin(),tmp.v.begin(),std::bind(std::equal_to<int>(),std::placeholders::_1,std::placeholders::_2));
        if(tmp.v.size()==b1.v.size()) return true;
        return false;
    }
    friend bool operator !=( Berza b1, Berza b2) {
        if(b1==b2) return false;
        return true;
    }
};

int main ()
{
    try {
        Berza b(6000,20000);
        b.RegistrirajCijenu(8000);
        b.RegistrirajCijenu(9000);
        b.RegistrirajCijenu(7000);
        Berza a(6000,20000);
        a.RegistrirajCijenu(8000);
        a.RegistrirajCijenu(9000);
        a.RegistrirajCijenu(7000);
        b.Ispisi();
        std::cout  << std::endl;
        a.Ispisi();
        std::cout  << std::endl;
        std::cout << (a==b) << std::endl;
    } catch (std::range_error i) {
        std::cout << i.what() << std::endl;
    }

    return 0;
}
