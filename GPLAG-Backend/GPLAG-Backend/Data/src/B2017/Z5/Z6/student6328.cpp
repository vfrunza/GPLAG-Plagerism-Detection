/B2017/2018: Zadaća 5, Zadatak 6
#include <iostream>
#include <vector>
#include <functional>
#include <cmath>
#include <stdexcept>
#include <algorithm>

class Berza
{
    int max,min;
    std::vector<int>dionice;
public:
    Berza(int mm,int mx);
    Berza(int mx);
    void RegistrirajCijenu(int cijena);
    int DajBrojRegistriranihCijena() const {
        return dionice.size();
    }
    void BrisiSve() {
        dionice.resize(0);
    }
    int DajMinimalnuCijenu() const;
    int DajMaksimalnuCijenu() const;
    bool operator !();
    int DajBrojCijenaVecihOd(int broj) const;
    void Ispisi()const;
    int operator [](int br);
    friend Berza operator ++(Berza b);
    friend Berza operator ++(Berza b,int);
    friend Berza operator --(Berza b);
    friend Berza operator --(Berza b, int);
    friend Berza operator -(Berza b);
    friend Berza operator +(Berza b, int broj);
    friend Berza operator +(int broj, Berza b);
    friend Berza operator -(Berza b, int broj);
    friend Berza operator -(int broj, Berza b);
    friend Berza operator +(Berza b1, Berza b2);
    friend Berza operator -(Berza b1, Berza b2);
    friend Berza &operator +=(Berza &b1, Berza b2);
    friend Berza &operator -=(Berza &b1, Berza b2);
    friend Berza &operator +=(Berza &b1, int broj);
    friend Berza &operator +=(int broj, Berza &b);
    friend Berza &operator -=(Berza &b1, int broj) ;
    friend Berza &operator -=(int broj, Berza &b);
    friend bool operator ==(Berza b1, Berza b2);
    friend bool operator !=(Berza b1, Berza b2);
};

Berza::Berza(int mm, int mx)
{
    if(mx<0 || mm<0) throw std::range_error("Ilegalne granicne cijene");
    min=mm;
    max=mx;
}
Berza::Berza(int mx)
{
    if(mx<0) throw std::range_error("Ilegalne granicne cijene");
    max=mx;
    min=0;
}

void Berza::RegistrirajCijenu(int cijena)
{
    if(cijena<min || cijena>max) throw std::range_error("Ilegalna cijena");
    dionice.push_back(cijena);
}

int Berza::DajMinimalnuCijenu()const
{
    if(dionice.size()==0) throw std::range_error("Nema registriranih cijena");
    return *std::min_element(dionice.begin(),dionice.end());
}

int Berza::DajMaksimalnuCijenu()const
{
    if(dionice.size()==0) throw std::range_error("Nema registriranih cijena");
    return *std::max_element(dionice.begin(),dionice.end());
}

bool Berza::operator !()
{
    if(dionice.size()==0) return true;
    return false;
}
int Berza::DajBrojCijenaVecihOd(int broj)const
{
    if(dionice.size()==0) throw std::range_error("Nema registriranih cijena");
    return std::count_if(dionice.begin(),dionice.end(),std::bind(std::greater<int>(), std::placeholders::_1,broj));
}

void Berza::Ispisi()const
{
    if(dionice.size()==0) throw std::range_error("Nema registriranih cijena");
    std::vector<int> v(dionice);
    std::sort(v.begin(),v.end(),std::greater<int>());
    for(int i(0); i<v.size(); i++) {
        std::cout<<v[i]/100<<".";
        if(v[i]%100<10) std::cout<<"0"<<v[i]%100<<std::endl;
        else std::cout<<v[i]%100<<std::endl;

    }
}

int Berza::operator [](int br)
{
    if(br<1 || br>dionice.size() ) throw std::range_error("Neispravan indeks");
    return int {dionice[br-1]};
}
Berza operator ++(Berza b)
{
    Berza pomocna(b);
    std::for_each(b.dionice.begin(),b.dionice.end(),std::bind(std::plus<int>(),std::placeholders::_1,100));
    int br(0);
    br=std::count_if(b.dionice.begin(),b.dionice.end(),std::bind(std::greater<int>(),std::placeholders::_1,b.DajMaksimalnuCijenu()));
    if(br<b.min || br>b.max) throw std::range_error("Prekoracen dozvoljeni opseg cijena");
    return pomocna;
}
Berza operator ++(Berza b,int)
{
    std::for_each(b.dionice.begin(),b.dionice.end(),std::bind(std::plus<int>(),std::placeholders::_1,100));
    int br(0);
    br=std::count_if(b.dionice.begin(),b.dionice.end(),std::bind(std::greater<int>(),std::placeholders::_1,b.DajMaksimalnuCijenu()));
    if(br<b.min || br>b.max) throw std::range_error("Prekoracen dozvoljeni opseg cijena");
    return b;
}
Berza operator --(Berza b)
{
    Berza pomocna(b);
    std::for_each(b.dionice.begin(),b.dionice.end(),std::bind(std::minus<int>(),std::placeholders::_1,100));
    int br(0);
    br=std::count_if(b.dionice.begin(),b.dionice.end(),std::bind(std::greater<int>(),b.DajMinimalnuCijenu(),std::placeholders::_1));
    if(br<b.min || br>b.max) throw std::range_error("Prekoracen dozvoljeni opseg cijena");
    return pomocna;
}
Berza operator --(Berza b,int)
{
    std::for_each(b.dionice.begin(),b.dionice.end(),std::bind(std::minus<int>(),std::placeholders::_1,100));
    int br(0);
    br=std::count_if(b.dionice.begin(),b.dionice.end(),std::bind(std::greater<int>(),b.DajMinimalnuCijenu(),std::placeholders::_1));
    if(br<b.min || br>b.max) throw std::range_error("Prekoracen dozvoljeni opseg cijena");
    return b;
}
Berza operator -(Berza b)
{
    std::for_each(b.dionice.begin(),b.dionice.end(),std::bind(std::minus<int>(),b.DajMaksimalnuCijenu()+b.DajMinimalnuCijenu(),std::placeholders::_1));
    return b;
}
Berza operator +(Berza b,int broj)
{
    std::for_each(b.dionice.begin(),b.dionice.end(),std::bind(std::plus<int>(),std::placeholders::_1,broj));
    int n(0);
    n=std::count_if(b.dionice.begin(),b.dionice.end(),std::bind(std::greater<int>(),std::placeholders::_1,b.DajMaksimalnuCijenu()));
    if(n<b.min || n>b.max) throw std::range_error("Prekoracen dozvoljeni opseg cijena");
    return b;
}
Berza operator -(Berza b,int broj)
{
    std::for_each(b.dionice.begin(),b.dionice.end(),std::bind(std::minus<int>(),std::placeholders::_1,broj));
    int br(0);
    br=std::count_if(b.dionice.begin(),b.dionice.end(),std::bind(std::greater<int>(),b.DajMinimalnuCijenu(),std::placeholders::_1));
    if(br<b.min || br>b.max) throw std::range_error("Prekoracen dozvoljeni opseg cijena");
    return b;
}
Berza operator +(int broj, Berza b)
{
    return b+broj;
}
Berza operator -(int broj, Berza b)
{
    return b-broj;
}
Berza operator +(Berza b1, Berza b2)
{
    if(b1.dionice.size()!=b2.dionice.size() || b1.DajMaksimalnuCijenu()!=b2.DajMaksimalnuCijenu() || b1.DajMinimalnuCijenu()!=b2.DajMinimalnuCijenu())
        throw std::domain_error("Nesaglasni operandi");

    Berza b(b1.DajMinimalnuCijenu(),b1.DajMaksimalnuCijenu());
    std::transform(b1.dionice.begin(),b1.dionice.end(),b2.dionice.begin(),b.dionice.begin(),std::bind(std::plus<int>(),std::placeholders::_1,std::placeholders::_2));
    int broj(0);
    broj=std::count_if(b.dionice.begin(),b.dionice.end(),std::bind(std::greater<int>(),std::placeholders::_1,b.DajMaksimalnuCijenu()));
    if(broj<b.min || broj>b.max) throw std::range_error("Prekoracen dozvoljeni opseg cijena");
    return b;
}
Berza operator -(Berza b1, Berza b2)
{
    if(b1.dionice.size()!=b2.dionice.size() || b1.DajMaksimalnuCijenu()!=b2.DajMaksimalnuCijenu() || b1.DajMinimalnuCijenu()!=b2.DajMinimalnuCijenu())
        throw std::domain_error("Nesaglasni operandi");

    Berza b(b1.DajMinimalnuCijenu(),b1.DajMaksimalnuCijenu());
    std::transform(b1.dionice.begin(),b1.dionice.end(),b2.dionice.begin(),b.dionice.begin(),std::bind(std::minus<int>(),std::placeholders::_1,std::placeholders::_2));
    int broj(0);
    broj=std::count_if(b.dionice.begin(),b.dionice.end(),std::bind(std::greater<int>(),b.DajMaksimalnuCijenu(),std::placeholders::_1));
    if(broj<b.min || broj>b.max) throw std::range_error("Prekoracen dozvoljeni opseg cijena");
    return b;
}

bool operator ==(Berza b1, Berza b2)
{
    if(b1.dionice.size()!=b2.dionice.size() || b1.DajMaksimalnuCijenu()!=b2.DajMaksimalnuCijenu() || b1.DajMinimalnuCijenu()!=b2.DajMinimalnuCijenu())
        return false;
    Berza b(b1.DajMinimalnuCijenu(),b1.DajMaksimalnuCijenu());
    std::transform(b1.dionice.begin(),b1.dionice.end(),b2.dionice.begin(),b.dionice.begin(),std::bind(std::equal_to<int>(),std::placeholders::_1,std::placeholders::_2));
    if(b.dionice.size()!=b1.dionice.size()) return false;
    return true;
}
bool operator !=(Berza b1, Berza b2)
{
    return !(b1==b2);
}
Berza &operator +=(Berza &b1, Berza b2)
{
    return b1=b1+b2;
}
Berza &operator -=(Berza &b1, Berza b2)
{
    return b1=b1-b2;
}

Berza &operator +=(Berza &b1,int broj)
{
    return b1=b1+broj;
}

Berza &operator +=(int broj, Berza &b)
{
    return b=b+broj;
}
Berza &operator -=(Berza &b1, int broj)
{
    return b1=b1-broj;
}
Berza &operator -=(int broj, Berza &b)
{
    return b=b-broj;
}


int main ()
{
   /* Berza b1 = Berza(1000,4000);
    b1.RegistrirajCijenu(3000);
    b1.RegistrirajCijenu(1500);
    std::cout << "Minimalna cijena: " << b1.DajMinimalnuCijenu() << std::endl;
    std::cout << "Maksimalna cijena: " << b1.DajMaksimalnuCijenu()<<std::endl;
    std::cout<<b1.DajBrojCijenaVecihOd(1200)<<std::endl<<b1.DajBrojRegistriranihCijena();
     b1 = Berza(1000,4000);
    b1.RegistrirajCijenu(3000);
    b1.RegistrirajCijenu(1500);
    b1.RegistrirajCijenu(2000);
    std::cout << "Broj registrovanih cijena: " << b1.DajBrojRegistriranihCijena() << std::endl;
    b1.Ispisi();
    b1.BrisiSve();
    std::cout << "Broj registrovanih cijena: " << b1.DajBrojRegistriranihCijena();
    */
    return 0;
}
