#include <iostream>
#include <vector>
#include <stdexcept>
#include <algorithm>
#include <functional>

class Berza{
     std::vector<int> dionice;
     int maxi, mini;
     public:
     Berza(int max, int min);
     Berza(int max);
     void RegistrirajCijenu(int dionica);
     int DajBrojRegistriranihCijena() const{return dionice.size();}
     void BrisiSve() { dionice.resize(0);}
     int DajMinimalnuCijenu() const;
     int DajMaksimalnuCijenu() const;
     bool operator !();
     int DajBrojCijenaVecihOd(int broj) const;
     void Ispisi() const;
     int operator[] (int i);
     friend Berza operator++(Berza b);
     friend Berza operator++(Berza b, int);
     friend Berza operator--(Berza b);
     friend Berza operator--(Berza b, int);
     friend Berza operator-(Berza b);
     friend Berza operator+(Berza b);
     friend Berza operator-(Berza b, int br);
     friend Berza operator+(Berza b, int br);
     friend Berza operator-(int br, Berza b);
     friend Berza operator+(int br, Berza b);
     friend Berza operator-(Berza b1, Berza b2);
     friend Berza operator+(Berza b1, Berza b2);
     friend Berza &operator-=(Berza &b1, Berza &b2){return b1=b1-b2;}
     friend Berza &operator+=(Berza &b1, Berza &b2){return b1=b1+b2;}
     friend Berza &operator-=(Berza &b, int br){return b=b-br;}
     friend Berza &operator+=(Berza &b, int br){return b=b+br;}
     friend Berza &operator-=(int br, Berza &b){return b=b-br;}
     friend Berza &operator+=(int br, Berza &b){return b=b+br;}
     friend bool operator ==(Berza b1, Berza b2);
     friend bool operator !=(Berza b1, Berza b2);
};

Berza::Berza(int max, int min){
     if(max<0 || min<0) throw std::range_error("Ilegalne granicne cijene");
     maxi=max;
     mini=min;
}

Berza::Berza(int max){
     if(max<0) throw std::range_error("Ilegalne granicne cijene");
     mini=0;
     maxi=max;
}

void Berza::RegistrirajCijenu(int dionica){
     dionice.push_back(dionica);
}

int Berza::DajMinimalnuCijenu() const{
     if(dionice.size()==0) throw std::range_error("Nema registriranih cijena");
     return *std::min_element(dionice.begin(), dionice.end());
}

int Berza::DajMaksimalnuCijenu() const{
     if(dionice.size()==0) throw std::range_error("Nema registriranih cijena");
     return *max_element(dionice.begin(), dionice.end());
}

bool Berza::operator!(){
     if(dionice.size()==0) return true;
     return false;
}

int Berza::DajBrojCijenaVecihOd(int broj) const{
     if(dionice.size()==0) throw std::range_error("Nema registriranih cijena");
     return std::count_if(dionice.begin(), dionice.end(), std::bind(std::greater<int>(), std::placeholders::_1, broj));
}

void Berza::Ispisi() const{
     if(dionice.size()==0) throw std::range_error("Nema registriranih cijena");
     std::vector<int> v(dionice);
     std::sort(v.begin(), v.end(), std::greater<int>());
     for(int i=0; i<v.size(); i++){
          std::cout<<v[i]/100<<".";
          if(v[i]%100<10) std::cout<<"0"<<v[i]%100<<std::endl;
          else std::cout<<v[i]%100<<std::endl;
     }
}

int Berza::operator [](int i){
     if(i<1 || i>dionice.size()) throw std::range_error("Neispravan indeks");
     return int{dionice[i-1]};
}

Berza operator++(Berza b){
     std::for_each(b.dionice.begin(), b.dionice.end(), std::bind(std::plus<int>(), std::placeholders::_1, 100));
     int br=0;
     br=std::count_if(b.dionice.begin(), b.dionice.end(), std::bind(std::greater<int>(), std::placeholders::_1, b.DajMaksimalnuCijenu()));
     if(br>0) throw std::range_error("Prekoracen dozvoljeni opseg cijena");
     return b;
}

Berza operator++(Berza b, int){
     std::for_each(b.dionice.begin(), b.dionice.end(), std::bind(std::plus<int>(), std::placeholders::_1, 100));
     int br=0;
     br=std::count_if(b.dionice.begin(), b.dionice.end(), std::bind(std::greater<int>(), std::placeholders::_1, b.DajMaksimalnuCijenu()));
     if(br>0) throw std::range_error("Prekoracen dozvoljeni opseg cijena");
     return b;
}

Berza operator--(Berza b){
     std::for_each(b.dionice.begin(), b.dionice.end(), std::bind(std::minus<int>(), std::placeholders::_1, 100));
     int br=0;
     br=std::count_if(b.dionice.begin(), b.dionice.end(), std::bind(std::greater<int>(),b.DajMaksimalnuCijenu(),std::placeholders::_1));
     if(br>0) throw std::range_error("Prekoracen dozvoljeni opseg cijena");
     return b;
}

Berza operator--(Berza b, int){
     std::for_each(b.dionice.begin(), b.dionice.end(), std::bind(std::minus<int>(), std::placeholders::_1, 100));
     int br=0;
     br=std::count_if(b.dionice.begin(), b.dionice.end(), std::bind(std::greater<int>(),b.DajMaksimalnuCijenu(),std::placeholders::_1));
     if(br>0) throw std::range_error("Prekoracen dozvoljeni opseg cijena");
     return b;
}

Berza operator-(Berza b){
     std::for_each(b.dionice.begin(), b.dionice.end(), std::bind(std::minus<int>(),b.DajMaksimalnuCijenu()+b.DajMinimalnuCijenu(), std::placeholders::_1));
     return b;
}

Berza operator+(Berza b, int br){
     std::for_each(b.dionice.begin(), b.dionice.end(), std::bind(std::plus<int>(), std::placeholders::_1, br));
     int broj=0;
     broj=std::count_if(b.dionice.begin(), b.dionice.end(), std::bind(std::greater<int>(), std::placeholders::_1, b.DajMaksimalnuCijenu()));
     if(broj>0) throw std::domain_error("Prekoracen dozvoljeni opseg cijena");
     return b;
}

Berza operator-(Berza b, int br){
     std::for_each(b.dionice.begin(), b.dionice.end(), std::bind(std::minus<int>(), std::placeholders::_1, br));
     int broj=0;
     broj=std::count_if(b.dionice.begin(), b.dionice.end(), std::bind(std::greater<int>(),b.DajMaksimalnuCijenu(), std::placeholders::_1));
     if(broj>0) throw std::domain_error("Prekoracen dozvoljeni opseg cijena");
     return b;
}

Berza operator+(int br, Berza b){
     std::for_each(b.dionice.begin(), b.dionice.end(), std::bind(std::plus<int>(), std::placeholders::_1, br));
     int broj=0;
     broj=std::count_if(b.dionice.begin(), b.dionice.end(), std::bind(std::greater<int>(), std::placeholders::_1, b.DajMaksimalnuCijenu()));
     if(broj>0) throw std::domain_error("Prekoracen dozvoljeni opseg cijena");
     return b;
}

Berza operator-(int br, Berza b){
     std::for_each(b.dionice.begin(), b.dionice.end(), std::bind(std::minus<int>(), std::placeholders::_1, br));
     int broj=0;
     broj=std::count_if(b.dionice.begin(), b.dionice.end(), std::bind(std::greater<int>(),b.DajMaksimalnuCijenu(), std::placeholders::_1));
     if(broj>0) throw std::domain_error("Prekoracen dozvoljeni opseg cijena");
     return b;
}

Berza operator +(Berza b1, Berza b2){
    if(b1.dionice.size() != b2.dionice.size() || b1.DajMaksimalnuCijenu() != b2.DajMaksimalnuCijenu()
    || b1.DajMinimalnuCijenu() != b2.DajMinimalnuCijenu()) throw std::domain_error("Nesaglasni operandi");

    Berza b(b1.DajMaksimalnuCijenu(), b2.DajMinimalnuCijenu());
    std::transform(b1.dionice.begin(), b1.dionice.end(), b2.dionice.begin(), b.dionice.begin(),
    std::bind(std::plus<int>(), std::placeholders::_1, std::placeholders::_2));

    int broj(0);
    broj = std::count_if(b.dionice.begin(), b.dionice.end(), std::bind(std::greater<int>(), std::placeholders::_1, b.DajMaksimalnuCijenu()));
    if (broj > 0) throw std::domain_error("Prekoracen dozvoljeni opseg cijena");
    return b;
}

Berza operator -(Berza b1, Berza b2){
    if(b1.dionice.size() != b2.dionice.size() || b1.DajMaksimalnuCijenu() != b2.DajMaksimalnuCijenu()
    || b1.DajMinimalnuCijenu() != b2.DajMinimalnuCijenu()) throw std::domain_error("Nesaglasni operandi");

    Berza b(b1.DajMaksimalnuCijenu(), b2.DajMinimalnuCijenu());
    std::transform(b1.dionice.begin(), b1.dionice.end(), b2.dionice.begin(), b.dionice.begin(),
    std::bind(std::minus<int>(), std::placeholders::_1, std::placeholders::_2));

    int broj(0);
    broj = std::count_if(b.dionice.begin(), b.dionice.end(), std::bind(std::greater<int>(), b.DajMaksimalnuCijenu(), std::placeholders::_1));
    if (broj > 0) throw std::domain_error("Prekoracen dozvoljeni opseg cijena");
    return b;
}


bool operator==(Berza b1, Berza b2){
     if(b1.dionice.size()!=b2.dionice.size() || b1.DajMaksimalnuCijenu()!=b2.DajMaksimalnuCijenu() || b1.DajMinimalnuCijenu()!= b2.DajMinimalnuCijenu()) return false;
     Berza b(b1.DajMaksimalnuCijenu(), b2.DajMinimalnuCijenu());
     std::transform(b1.dionice.begin(), b1.dionice.end(), b2.dionice.begin(), b.dionice.begin(),std::bind(std::equal_to<int>(), std::placeholders::_1, std::placeholders::_2));
     if(b.dionice.size()!=b1.dionice.size()) return false;
     return true;
}

bool operator!=(Berza b1, Berza b2){
     if(b1.dionice.size()!=b2.dionice.size() || b1.DajMaksimalnuCijenu()!=b2.DajMaksimalnuCijenu() || b1.DajMinimalnuCijenu()!= b2.DajMinimalnuCijenu()) return true;
     Berza b(b1.DajMaksimalnuCijenu(), b2.DajMinimalnuCijenu());
     std::transform(b1.dionice.begin(), b1.dionice.end(), b2.dionice.begin(), b.dionice.begin(),std::bind(std::equal_to<int>(), std::placeholders::_1, std::placeholders::_2));
     if(b.dionice.size()!=b1.dionice.size()) return true;
     return false;
}

int main(){ 
     try{ 
           Berza b1 = Berza(1000,4000);
    b1.RegistrirajCijenu(3000);
    b1.RegistrirajCijenu(1500);
    std::cout << "Minimalna cijena: " << b1.DajMinimalnuCijenu() << std::endl;
    std::cout << "Maksimalna cijena: " << b1.DajMaksimalnuCijenu();
}
     catch(std::range_error e){
          std::cout<<e.what();
     }
     catch(std::domain_error d){
          std::cout<<d.what();
     }
     return 0;
}
