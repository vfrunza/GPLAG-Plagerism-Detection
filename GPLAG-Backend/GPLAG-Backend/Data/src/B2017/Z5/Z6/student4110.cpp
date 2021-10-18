/B2017/2018: Zadaća 5, Zadatak 6
#include <iostream>
#include <vector>
#include <stdexcept>
#include <algorithm>
#include <functional>
#include <iterator>
#include <iomanip>
class Berza
{
    std::vector<int> cijene;
    int max,min;
public:
    Berza(int a, int b) {
        if(a<0||b<0)throw std::range_error("Ilegalne granice cijene");
        min=a;
        max=b;
    }
     Berza(int a) {
        if(a<0)throw std::range_error("Ilegalne granice cijene");
        min=0;
        max=a;
    }
    void RegistrirajCijenu(int a) {
        if(a<min || a>max)throw std::range_error("Ilegalna cijena");
        cijene.push_back(a);
    }
    int DajBrojRegistriranihCijena()const {
        return cijene.size();
    }
    
    int DajMin()const{return min;}
    int DajMax()const{return max;}
    void BrisiSve() {
        cijene.resize(0);
    }
    int DajMinimalnuCijenu()const;
    int DajMaksimalnuCijenu()const;
    friend bool operator!(const Berza&a);
    int operator[](int a) {
        if(a<1||a>cijene.size())throw std::range_error("Neispravan indeks");
        return cijene[a-1];
    }
    int DajBrojCijenaVecihOd(int a) {
        if(cijene.size()==0)throw std::range_error("Nema registriranih cijena");
        return std::count_if(cijene.begin(),cijene.end(),std::bind(std::greater<int>(),std::placeholders::_1,a));

    }
    void Ispisi()const;
    Berza &operator++();
    Berza &operator--();
    Berza operator ++(int);
    Berza operator --(int);
    Berza& operator +=( Berza &a);
    Berza& operator -=( Berza &a);
    Berza operator -();
    friend bool operator ==(const Berza&a, const Berza&b);
    friend bool operator !=(const Berza&a, const Berza&b);
    
 
    
};


 Berza& Berza::operator +=(Berza &a){
     for(int i=0;i<this->DajBrojRegistriranihCijena();i++) cijene[i]+=a[i+1];
     if(std::count_if(cijene.begin(),cijene.end(),std::bind(std::greater<int>(),std::placeholders::_1,max)))
        throw std::range_error("Prekoracen dozvoljeni opseg cijena");
        return *this;
 }
 Berza& Berza::operator -=(Berza &a){
     for(int i=0;i<this->DajBrojRegistriranihCijena();i++) cijene[i]-=a[i+1];
     if(std::count_if(cijene.begin(),cijene.end(),std::bind(std::greater<int>(),std::placeholders::_1,max)))
        throw std::range_error("Prekoracen dozvoljeni opseg cijena");
        return *this;
 }


Berza& Berza::operator++()
{
    std::transform(cijene.begin(),cijene.end(),cijene.begin(),std::bind(std::plus<int>(),std::placeholders::_1,100));
    if(std::count_if(cijene.begin(),cijene.end(),std::bind(std::greater<int>(),std::placeholders::_1,max)))
        throw std::range_error("Prekoracen dozvoljeni opseg cijena");
    return *this;
}
Berza& Berza::operator--()
{
    std::transform(cijene.begin(),cijene.end(),cijene.begin(),std::bind(std::minus<int>(),std::placeholders::_1,100));
    if(std::count_if(cijene.begin(),cijene.end(),std::bind(std::less<int>(),std::placeholders::_1,min)))
        throw std::range_error("Prekoracen dozvoljeni opseg cijena");
    return *this;
}

Berza Berza::operator ++(int)
{
    Berza pomocna(*this);
    std::transform(cijene.begin(),cijene.end(),cijene.begin(),std::bind(std::plus<int>(),std::placeholders::_1,100));
    if(std::count_if(cijene.begin(),cijene.end(),std::bind(std::greater<int>(),std::placeholders::_1,max)))
        throw std::range_error("Prekoracen dozvoljeni opseg cijena");
    return pomocna;
}

Berza Berza::operator --(int)
{
    Berza pomocna(*this);
    std::transform(cijene.begin(),cijene.end(),cijene.begin(),std::bind(std::minus<int>(),std::placeholders::_1,100));
    if(std::count_if(cijene.begin(),cijene.end(),std::bind(std::less<int>(),std::placeholders::_1,min)))
        throw std::range_error("Prekoracen dozvoljeni opseg cijena");
    return pomocna;
}


bool operator!(const Berza&a)
{
    return !a.DajBrojRegistriranihCijena();
}

void Berza::Ispisi()const
{
    std::vector<int>pomocni(cijene);
    std::sort(pomocni.begin(),pomocni.end(),std::greater<int>());
    std::transform(pomocni.begin(),pomocni.end(),std::ostream_iterator<double>(std::cout<<std::fixed<<std::setprecision(2),"\n"),std::bind(std::divides<double>(),std::placeholders::_1,100.));
}


int Berza::DajMinimalnuCijenu()const
{
    if(cijene.size()==0)throw std::range_error("Nema registriranih cijena");
    return *std::min_element(cijene.begin(),cijene.end());
}

int Berza::DajMaksimalnuCijenu()const
{
    if(cijene.size()==0)throw std::range_error("Nema registriranih cijena");
    return *std::max_element(cijene.begin(),cijene.end());
}

int main ()
{
  
    return 0;
}
