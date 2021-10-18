/B2017/2018: Zadaća 5, Zadatak 6
#include <iostream>
#include <vector>
#include <stdexcept>
#include <algorithm>
#include <functional>
#include <iomanip>
class Berza{
    std::vector<double> cijene;
    int min, max;
    void Test(const double &a){
       try{
       if(a<min || a>max) throw std::range_error("Prekoracen dozvoljeni opseg cijena");
       }catch(std::range_error e){
           throw;
       }
   }
   void Testiraj(const double &a){
       try{
       if(a<min || a>max) throw std::domain_error("Prekoracen dozvoljeni opseg cijena");
       }catch(std::range_error e){
           throw;
       }
   }
   public:
   Berza(int min, int max): min(min), max(max){
       try{
           if(min<0 || max<0) throw std::range_error("Ilegalne granicne cijene");
       }catch(std::range_error e){
           throw;
       }
   }
   explicit Berza(int max):min(0), max(max){
       try{
           if(max<0) throw std::range_error("Ilegalne granicne cijene");
       }catch(std::range_error e){
           throw;
       }
   }
   void RegistrirajCijenu(int cijena){
       try {
           if(cijena<min || cijena>max) throw std::range_error("Ilegalna cijena");
           cijene.push_back(cijena);
       }
       catch (std::range_error e) {
           throw;
       }
   }
   int DajBrojRegistriranihCijena()const{return cijene.size();}
   void BrisiSve(){cijene.resize(0);}
   int DajMinimalnuCijenu()const{
       try{
           if(cijene.size()==0) throw std::range_error("Nema registriranih cijena");
       return *std::min_element(cijene.begin(), cijene.end());
       }catch(std::range_error e){
           throw;
       }
   }
   int DajMaksimalnuCijenu()const{
       try{
           if(cijene.size()==0) throw std::range_error("Nema registriranih cijena");
       return *std::max_element(cijene.begin(), cijene.end());
       }catch(std::range_error e){
           throw;
       }
   }
   bool operator!(){
       if(cijene.size()==0) return true;
       else return false;
   }
   int DajBrojCijenaVecihOd(int broj){
       try {
           if(cijene.size()==0) throw std::range_error("Nema registriranih cijena");
           return std::count_if(cijene.begin(), cijene.end(), std::bind(std::less<double>(), broj, std::placeholders::_1));
       }
       catch (std::range_error e) {
           throw;
       }
       
   }
   void Ispisi(){
       std::sort(cijene.begin(), cijene.end(), std::greater<int>());
       std::transform(cijene.begin(), cijene.end(), cijene.begin(), std::bind(std::multiplies<double>(), (0.01), std::placeholders::_1));
       for(int i=0; i<cijene.size(); i++){
           std::cout<<std::fixed<<std::setprecision(2)<<cijene.at(i)<<std::endl;
       }
   }
   double operator [](int indeks)const{
       try {
           if(indeks<1 || indeks>cijene.size()) throw std::range_error("Neispravan indeks");
           return cijene.at(indeks-1);
       }
       catch (std::range_error e) {
           throw;
       }
   }
   double operator [](int indeks){
       try {
           if(indeks<1 || indeks>cijene.size()) throw std::range_error("Neispravan indeks");
           return cijene.at(indeks-1);
       }
       catch (std::range_error e) {
           throw;
       }
   }
   Berza &operator++(){
       try{
       std::transform(cijene.begin(), cijene.end(), cijene.begin(), std::bind(std::plus<double>(),std::placeholders::_1,100));
       std::for_each(cijene.begin(), cijene.end(), [this](double a){Test(a);});
       return *this;
       }catch(std::range_error e){
           throw;
       }
   }
   Berza operator ++(int a){
       Berza pomocni(*this);
       ++(*this);
       return pomocni;
   }
   Berza &operator--(){
       std::transform(cijene.begin(), cijene.end(), cijene.begin(), std::bind(std::minus<double>(),std::placeholders::_1,100));
       std::for_each(cijene.begin(), cijene.end(), [this](double a){Test(a);});
       return *this;
   }
   Berza operator --(int a){
       Berza pomocni(*this);
       --(*this);
       return pomocni;
   }
   Berza operator-(){
       Berza pomocni(*this), novi(*this);
       std::transform(cijene.begin(), cijene.end(), cijene.begin(), std::bind(std::minus<double>(), (min+max), std::placeholders::_1));
       novi=*this;
       *this=pomocni;
       return novi;
   }
   Berza operator +(int b){
       try{
       Berza pomocni(*this), novi(*this);
       std::transform(cijene.begin(), cijene.end(), cijene.begin(), std::bind(std::plus<double>(), std::placeholders::_1, b));
       std::for_each(cijene.begin(), cijene.end(), [this](double a){Testiraj(a);});
       novi=*this;
       *this=pomocni;
       return novi;
       }catch(std::range_error e){
           throw;
       }
   }
   Berza operator+(const Berza &b){
       try{
          // if(cijene.size()!=b.(cijene.begin())) throw std::domain_error("Nesaglasni operandi");
          
       Berza pomocna(*this), nova(*this);
       for(int i=0; i<cijene.size(); i++){
       std::transform(cijene.begin(), cijene.end(), cijene.begin(), std::bind(std::plus<double>(), std::placeholders::_1, cijene.at(i)));
       nova=*this;
       *this=pomocna;
       return nova;
       }
   }catch(std::domain_error e){
       throw;
   }
   }
   Berza operator -(int b){
       try{
       Berza pomocni(*this), novi(*this);
       std::transform(cijene.begin(), cijene.end(), cijene.begin(), std::bind(std::minus<double>(), std::placeholders::_1, b));
       std::for_each(cijene.begin(), cijene.end(), [this](double a){Testiraj(a);});
       novi=*this;
       *this=pomocni;
       return novi;
       }catch(std::range_error e){
           throw;
       }
   }
   bool operator==()
};


int main ()
{
    try{
    Berza b1 = Berza(1000,4000);
    b1.RegistrirajCijenu(1000);
    b1.RegistrirajCijenu(1500);
    b1.RegistrirajCijenu(2000);
    std::cout << "Broj registrovanih cijena: " << b1.DajBrojRegistriranihCijena() << std::endl;
    std::cout << "Broj vecih od: "<<b1.DajBrojCijenaVecihOd(1600)<<std::endl;
    std::cout <<"1. clan je: "<<b1[1]<<std::endl;
    b1++;
    b1++;
    b1--;
    b1--;
    Berza a=(-b1);
    a.Ispisi();
    Berza c=b1+1;
    std::cout<<"Uvecan: "<<b1[1]<<std::endl;
    b1.Ispisi();
    b1.BrisiSve();
    std::cout << "Broj registrovanih cijena: " << b1.DajBrojRegistriranihCijena();
    }catch(std::range_error e){
        std::cout<<e.what();
    }catch(std::domain_error e){
        std::cout<<e.what();
    }
    
	return 0;
}
