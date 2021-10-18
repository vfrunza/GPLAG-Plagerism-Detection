/B2017/2018: Zadaća 5, Zadatak 6
#include <iostream>
#include <vector>
#include <stdexcept>
#include <algorithm>
#include <functional>

class Berza{
    std::vector<int> CijDio;
    int Min,Max;
    public:
    Berza(int min,int max){
        if(max<0 or min<0) throw std::range_error("Ilegalne granicne cijene");
        Max=max;
        Min=min;
    };
    Berza(int max){
        Max=max;
        Min=0;
    };
    void RegistrirajCijenu(int x){
        if(x<Min or x>Max)throw std::range_error("Ilegalna cijena");
        CijDio.push_back(x);
    };
    int DajBrojRegistriranihCijena(){
        return CijDio.size();
    };
    void BrisiSve(){
        CijDio.resize(0);
    };
    int DajMinimalnuCijenu() const;
    int DajMaksimalnuCijenu() const;
    bool operator !();
    int DajBrojCijenaVecihOd(int broj) const;
    void Ispisi() const;
    int operator [](int tmp);
    friend Berza operator ++(Berza x);
    friend Berza operator ++(Berza x,int y);
    friend Berza operator --(Berza x);
    friend Berza operator --(Berza x,int y);
    friend Berza operator -(Berza x);
    friend Berza operator -(Berza x,int y);
    friend Berza operator -(Berza x,Berza y);
    friend Berza operator -(int y,Berza x);
    friend Berza operator +(Berza x,int y);
    friend Berza operator +(Berza x,Berza y);
    friend Berza operator +(int y,Berza x);
    friend Berza &operator -=(Berza &x,Berza y);
    friend Berza &operator -=(Berza &x,int y);
    friend Berza &operator -=(int,Berza &x);
    friend Berza &operator +=(Berza &x,Berza y);
    friend Berza &operator +=(Berza &x,int y);
    friend Berza &operator +=(int,Berza &x);
    friend bool operator ==(Berza x,Berza y);
    friend bool operator !=(Berza x,Berza y);
    
};
int Berza::DajMinimalnuCijenu()const{
    if(CijDio.size()==0) throw std::range_error("Nema registriranih cijena");
    return *std::min_element(CijDio.begin(),CijDio.end());
    
}
int Berza::DajMaksimalnuCijenu()const{
    if(CijDio.size()==0) throw std::range_error("Nema registriranih cijena");
    return *std::max_element(CijDio.begin(),CijDio.end());
}

bool Berza::operator !(){
    if(CijDio.size()==0)return true;
    else return false;
}

int Berza::DajBrojCijenaVecihOd(int x)const{
    if(CijDio.size()==0)throw std::range_error("Nema registriranih cijena");
    return std::count_if(CijDio.begin(),CijDio.end(),std::bind(std::greater<int>(),std::placeholders::_1,x));
}

void Berza::Ispisi()const{
    if(CijDio.size()==0)throw std::range_error("Nema registriranih cijena");
    std::vector<int>tmp=CijDio;
    std::sort(tmp.begin(),tmp.end(),std::greater<int>());
    for(int i=0;i<tmp.size();i++){
        std::cout<<tmp[i]/100<<".";
        if(tmp[i]%100<10) std::cout<<"0"<<tmp[i]%100<<std::endl;
        else std::cout<<tmp[i]%100<<std::endl;
    }
}

int Berza::operator [](int x){
    if(x<1 or x>CijDio.size())throw std::range_error("Neispravan indeks");
    return int(CijDio[x-1]);
}

Berza operator ++(Berza x){
    std::for_each(x.CijDio.begin(),x.CijDio.end(),std::bind(std::plus<int>(),std::placeholders::_1,100));
    int tmp;
    tmp=std::count_if(x.CijDio.begin(),x.CijDio.end(),std::bind(std::greater<int>(),std::placeholders::_1,x.DajMaksimalnuCijenu()));
    if(tmp>0)throw std::range_error("Prekoracen dozvoljeni opseg cijena");
    return x;
}

Berza operator ++(Berza x,int y){
    std::for_each(x.CijDio.begin(),x.CijDio.end(),std::bind(std::plus<int>(),std::placeholders::_1,100));
    int tmp;
    tmp=std::count_if(x.CijDio.begin(),x.CijDio.end(),std::bind(std::greater<int>(),std::placeholders::_1,x.DajMaksimalnuCijenu()));
    if(tmp>0)throw std::range_error("Prekoracen dozvoljeni opseg cijena");
    return x;
}

Berza operator --(Berza x){
    std::for_each(x.CijDio.begin(),x.CijDio.end(),std::bind(std::minus<int>(),std::placeholders::_1,100));
    int tmp;
    tmp=std::count_if(x.CijDio.begin(),x.CijDio.end(),std::bind(std::greater<int>(),x.DajMinimalnuCijenu(),std::placeholders::_1));
    if(tmp>0)throw std::range_error("Prekoracen dozvoljeni opseg cijena");
    return x;
}
Berza operator --(Berza x,int y){
    std::for_each(x.CijDio.begin(),x.CijDio.end(),std::bind(std::minus<int>(),std::placeholders::_1,100));
    int tmp;
    tmp=std::count_if(x.CijDio.begin(),x.CijDio.end(),std::bind(std::greater<int>(),x.DajMinimalnuCijenu(),std::placeholders::_1));
    if(tmp>0)throw std::range_error("Prekoracen dozvoljeni opseg cijena");
    return x;
}
Berza operator -(Berza x){
    std::for_each(x.CijDio.begin(),x.CijDio.end(),std::bind(std::minus<int>(),x.DajMinimalnuCijenu()+x.DajMaksimalnuCijenu(),std::placeholders::_1));
    return x;
}
Berza operator -(Berza x,int y){
    std::for_each(x.CijDio.begin(),x.CijDio.end(),std::bind(std::minus<int>(),std::placeholders::_1,y));
    int tmp=0;
    tmp=std::count_if(x.CijDio.begin(),x.CijDio.end(),std::bind(std::greater<int>(),x.DajMinimalnuCijenu(),std::placeholders::_1));
    if(tmp>0)throw std::domain_error("Prekoracen dozvoljeni opseg cijena");
    return x;
}
Berza operator +(Berza x,int y){
    std::for_each(x.CijDio.begin(),x.CijDio.end(),std::bind(std::plus<int>(),std::placeholders::_1,y));
    int tmp=0;
    tmp=std::count_if(x.CijDio.begin(),x.CijDio.end(),std::bind(std::greater<int>(),std::placeholders::_1,x.DajMaksimalnuCijenu()));
    if(tmp>0)throw std::domain_error("Prekoracen dozvoljeni opseg cijena");
    return x;
}
Berza operator -(int y,Berza x){
    std::for_each(x.CijDio.begin(),x.CijDio.end(),std::bind(std::minus<int>(),y,std::placeholders::_1));
    int tmp=0;
    tmp=std::count_if(x.CijDio.begin(),x.CijDio.end(),std::bind(std::greater<int>(),x.DajMinimalnuCijenu(),std::placeholders::_1));
    if(tmp>0)throw std::domain_error("Prekoracen dozvoljeni opseg cijena");
    return x;
}
Berza operator +(int y,Berza x){
    std::for_each(x.CijDio.begin(),x.CijDio.end(),std::bind(std::plus<int>(),std::placeholders::_1,y));
    int tmp=0;
    tmp=std::count_if(x.CijDio.begin(),x.CijDio.end(),std::bind(std::greater<int>(),x.DajMinimalnuCijenu(),std::placeholders::_1));
    if(tmp>0)throw std::domain_error("Prekoracen dozvoljeni opseg cijena");
    return x;
}
Berza operator -(Berza x,Berza y){
    if(x.CijDio.size() != y.CijDio.size() or x.DajMaksimalnuCijenu() != y.DajMaksimalnuCijenu() or x.DajMinimalnuCijenu()!=y.DajMinimalnuCijenu()){
        throw std::domain_error("Nesaglasni operandi");
    }
    Berza tmp(x.DajMinimalnuCijenu(),y.DajMaksimalnuCijenu());
    std::transform(x.CijDio.begin(),x.CijDio.end(),y.CijDio.begin(),y.CijDio.end(),std::bind(std::minus<int>(),std::placeholders::_1,std::placeholders::_2));

    int tmp2=0;
    tmp2=std::count_if(tmp.CijDio.begin(),tmp.CijDio.end(),std::bind(std::greater<int>(),tmp.DajMinimalnuCijenu(),std::placeholders::_1));
    if(tmp2>0)throw std::domain_error("Prekoracen dozvoljeni opseg cijena");
    return tmp;
}
Berza operator +(Berza x,Berza y){
    if(x.CijDio.size() != y.CijDio.size() or x.DajMaksimalnuCijenu() != y.DajMaksimalnuCijenu() or x.DajMinimalnuCijenu()!=y.DajMinimalnuCijenu()){
        throw std::domain_error("Nesaglasni operandi");
    }
    Berza tmp(x.DajMinimalnuCijenu(),y.DajMaksimalnuCijenu());
    std::transform(x.CijDio.begin(),x.CijDio.end(),y.CijDio.begin(),y.CijDio.end(),std::bind(std::plus<int>(),std::placeholders::_1,std::placeholders::_2));

    int tmp2=0;
    tmp2=std::count_if(tmp.CijDio.begin(),tmp.CijDio.end(),std::bind(std::greater<int>(),std::placeholders::_1,tmp.DajMaksimalnuCijenu()));
    if(tmp2>0)throw std::domain_error("Prekoracen dozvoljeni opseg cijena");
    return tmp;
}

Berza &operator -=(Berza &x,Berza y){
    return x=x-y;
}
Berza &operator -=(Berza &x,int y){
    return x=x-y;
}
Berza &operator -=(int y,Berza &x){
    return x=x-y;
}
Berza &operator +=(Berza &x,Berza y){
    return x=x+y;
}
Berza &operator +=(Berza &x,int y){
    return x=x+y;
}
Berza &operator +=(int y,Berza &x){
    return x=x+y;
}
bool operator ==(Berza x,Berza y){
    if(x.CijDio.size() != y.CijDio.size() or x.DajMaksimalnuCijenu() != y.DajMaksimalnuCijenu() or x.DajMinimalnuCijenu()!=y.DajMinimalnuCijenu()){
        return false;
    }
    Berza tmp(x.DajMinimalnuCijenu(),y.DajMaksimalnuCijenu());
    std::transform(x.CijDio.begin(),x.CijDio.end(),y.CijDio.begin(),y.CijDio.end(),std::bind(std::equal_to<int>(),std::placeholders::_1,std::placeholders::_2));
    if(tmp.CijDio.size()!=x.CijDio.size()) return false;
    return true;
}
bool operator !=(Berza x,Berza y){
    if(x.CijDio.size() != y.CijDio.size() or x.DajMaksimalnuCijenu() != y.DajMaksimalnuCijenu() or x.DajMinimalnuCijenu()!=y.DajMinimalnuCijenu()){
        return true;
    }
    Berza tmp(x.DajMinimalnuCijenu(),y.DajMaksimalnuCijenu());
    std::transform(x.CijDio.begin(),x.CijDio.end(),y.CijDio.begin(),y.CijDio.end(),std::bind(std::equal_to<int>(),std::placeholders::_1,std::placeholders::_2));
    if(tmp.CijDio.size()!=x.CijDio.size()) return true;
    return false;
}

int main ()
{
	return 0;
}
