/B2017/2018: Zadaća 5, Zadatak 6
#include <iostream>
#include <vector>
#include <stdexcept>
#include <algorithm>
#include <functional>
#include <iomanip>
class Berza{
    std::vector<int> v;
    int minimalna, maksimalna;
    public:
    Berza(int minimalna, int maksimalna);
    Berza(int maksimalna);
    void RegistrirajCijenu(int cijena_dionice);
    int DajBrojRegistriranihCijena()const;
    void BrisiSve();
    int DajMinimalnuCijenu()const;
    int DajMaksimalnuCijenu()const;
    bool operator !();
    int DajBrojCijenaVecihOd(int vrijednost)const;
    void Ispisi()const;
    int operator [](int x);
    friend Berza &operator++ (Berza &berza);
    friend Berza &operator-- (Berza &berza);
    friend Berza operator++ (Berza &berza, int);
    friend Berza operator-- (Berza &berza, int);
    friend Berza operator -(Berza &berza);
    friend Berza operator +(Berza &berza, int broj);
    friend Berza operator -(Berza &berza, int broj);
    friend Berza operator +(const Berza &berza1,const  Berza &berza2);
    friend Berza operator -(const Berza &berza1,const  Berza &berza2);
    friend Berza &operator +=(Berza &berza1, const Berza &berza2);
    friend Berza &operator -=(Berza &berza1, const Berza &berza2);
    friend bool operator ==(const Berza &berza1, const Berza &berza2);
    friend bool operator !=(const Berza &berza1, const Berza &berza2);
};
    Berza::Berza(int minimalna, int maksimalna){
        if(minimalna < 0 || maksimalna < 0 || maksimalna < minimalna) throw std::range_error("Ilegalne granicne cijene");
        Berza::minimalna=minimalna;
        Berza::maksimalna=maksimalna;
    }
    Berza::Berza(int maksimalna){
        if(maksimalna < 0) throw std::range_error("Ilegalne granicne cijene");
        Berza::maksimalna=maksimalna;
        Berza::minimalna=0;
    }
    void Berza::RegistrirajCijenu(int cijena_dionice){
        if(cijena_dionice < minimalna || cijena_dionice > maksimalna) throw std::range_error("Ilegalna cijena");
        v.push_back(cijena_dionice);
    }
    int Berza::DajBrojRegistriranihCijena()const{
        return v.size();
    }
    void Berza::BrisiSve(){
        v.resize(0);
    }
    int Berza::DajMinimalnuCijenu()const{
        if(v.size()==0) std::range_error("Nema registriranih cijena");
        return *std::min_element(v.begin(),v.end());
    }
    int Berza::DajMaksimalnuCijenu()const{
        if(v.size()==0) std::range_error("Nema registriranih cijena");
        return *std::max_element(v.begin(),v.end());
    }
    bool Berza::operator !(){
        return !v.size();
    }
    int Berza::DajBrojCijenaVecihOd(int vrijednost)const{
        if(v.size()==0) throw std::range_error("Nema registriranih cijena");
        return std::count_if(v.begin(),v.end(),std::bind(std::greater<int>(), std::placeholders::_1, vrijednost));
    }
    void Berza::Ispisi()const{
        std::vector<double> v1; 
        for(auto &x : v) v1.push_back(double(x));
        std::sort(v1.begin(),v1.end(), std::greater<double>());
        for(auto &x : v1){
            std::cout<<std::fixed<<std::setprecision(2)<<x/100;
            std::cout<<std::endl;
        }
    }
    int Berza::operator [](int x){
        if(x < 1 || x > v.size()) throw std::range_error("Neispravan indeks");
        return v.at(x-1);
    }
    Berza &operator++ (Berza &berza){
        std::transform(berza.v.begin(), berza.v.end(), berza.v.begin(), std::bind(std::plus<int>(),std::placeholders::_1, 100));
        if(std::count_if(berza.v.begin(),berza.v.end(),std::bind(std::greater<int>(), std::placeholders::_1, berza.maksimalna)) != 0) throw std::range_error("Prekoracen dozvoljeni opseg cijena");
        return berza;
    }
    Berza &operator-- (Berza &berza){
        std::transform(berza.v.begin(), berza.v.end(), berza.v.begin(), std::bind(std::minus<int>(),std::placeholders::_1, 100));
        if(std::count_if(berza.v.begin(),berza.v.end(),std::bind(std::greater<int>(), berza.minimalna, std::placeholders::_1)) != 0) throw std::range_error("Prekoracen dozvoljeni opseg cijena");
        return berza;
    }
    Berza operator++ (Berza &berza, int){
        auto pomocni(berza);
        ++berza;
        //std::transform(berza.v.begin(), berza.v.end(), berza.v.begin(), std::bind(std::plus<int>(),std::placeholders::_1, 100));
        if(std::count_if(berza.v.begin(),berza.v.end(),std::bind(std::greater<int>(), std::placeholders::_1, berza.maksimalna)) != 0) throw std::range_error("Prekoracen dozvoljeni opseg cijena");
        return pomocni;
    }
    Berza operator-- (Berza &berza, int){
        auto pomocni(berza);
        --berza;
        //std::transform(berza.v.begin(), berza.v.end(), berza.v.begin(), std::bind(std::minus<int>(),std::placeholders::_1, 100));
        if(std::count_if(berza.v.begin(),berza.v.end(),std::bind(std::greater<int>(), berza.minimalna, std::placeholders::_1)) != 0) throw std::range_error("Prekoracen dozvoljeni opseg cijena");
        return pomocni;
    }
    Berza operator -(Berza &berza){
        std::transform(berza.v.begin(), berza.v.end(), berza.v.begin(), std::bind(std::minus<int>(),berza.maksimalna+berza.minimalna,std::placeholders::_1));
        return berza;
    }
    Berza operator +(Berza &berza, int broj){
        std::transform(berza.v.begin(), berza.v.end(), berza.v.begin(), std::bind(std::plus<int>(),std::placeholders::_1, broj));
        if(std::count_if(berza.v.begin(),berza.v.end(),std::bind(std::greater<int>(), std::placeholders::_1, berza.maksimalna)) != 0) throw std::domain_error("Prekoracen dozvoljeni opseg cijena");
        return berza;
    }
    Berza operator -(Berza &berza, int broj){
        std::transform(berza.v.begin(), berza.v.end(), berza.v.begin(), std::bind(std::minus<int>(),std::placeholders::_1, broj));
        if(std::count_if(berza.v.begin(),berza.v.end(),std::bind(std::greater<int>(), berza.minimalna, std::placeholders::_1)) != 0) throw std::domain_error("Prekoracen dozvoljeni opseg cijena");
        return berza;
    }
    Berza operator +(const Berza &berza1,const  Berza &berza2){
        if(berza1.v.size()!=berza2.v.size() || berza1.maksimalna!=berza2.maksimalna || berza1.minimalna!=berza2.minimalna) throw std::domain_error("Nesaglasni operandi");
        Berza berza(berza1.maksimalna, berza2.minimalna);
        std::transform(berza1.v.begin(), berza1.v.end(),berza2.v.begin(), berza.v.begin(), std::bind(std::plus<int>(), std::placeholders::_1, std::placeholders::_2));
        if(std::count_if(berza.v.begin(),berza.v.end(),std::bind(std::greater<int>(), std::placeholders::_1, berza.maksimalna)) != 0) throw std::domain_error("Prekoracen dozvoljeni opseg cijena");
        return berza;
    }
    Berza operator -(const Berza &berza1,const  Berza &berza2){
        if(berza1.v.size()!=berza2.v.size() || berza1.maksimalna!=berza2.maksimalna || berza1.minimalna!=berza2.minimalna) throw std::domain_error("Nesaglasni operandi");
        Berza berza(berza1.maksimalna, berza2.minimalna);
        std::transform(berza1.v.begin(), berza1.v.end(),berza2.v.begin(), berza.v.begin(), std::bind(std::minus<int>(), std::placeholders::_1, std::placeholders::_2));
        if(std::count_if(berza.v.begin(),berza.v.end(),std::bind(std::greater<int>(), berza.minimalna, std::placeholders::_1)) != 0) throw std::domain_error("Prekoracen dozvoljeni opseg cijena");
        return berza;
    }
    Berza &operator +=(Berza &berza1, const Berza &berza2){
        return berza1=berza1+berza2;
    }
    Berza &operator -=(Berza &berza1, const Berza &berza2){
        return berza1=berza1-berza2;
    }
    bool operator ==(const Berza &berza1, const Berza &berza2){
        if(berza1.v.size()!=berza2.v.size()) return false;
        Berza berza(berza1.maksimalna, berza2.minimalna);
        std::transform(berza1.v.begin(), berza1.v.end(),berza2.v.begin(), berza.v.begin(), std::bind(std::equal_to<int>(), std::placeholders::_1, std::placeholders::_2));
        if(berza1.v.size()==berza.v.size()) return true;
        return false;
        
    }
    bool operator !=(const Berza &berza1, const Berza &berza2){
        if(berza1.v.size()!=berza2.v.size()) return true;
        Berza berza(berza1.maksimalna, berza2.minimalna);
        std::transform(berza1.v.begin(), berza1.v.end(),berza2.v.begin(), berza.v.begin(), std::bind(std::equal_to<int>(), std::placeholders::_1, std::placeholders::_2));
        if(berza1.v.size()==berza.v.size()) return false;
        return true;
        
    }
void TestOperatora(Berza berza1, Berza berza2){
    
}

int main ()
{
    Berza berza1(1200);
    for(int i=5; i<25; i++) berza1.RegistrirajCijenu(i*25);
    std::cout<<"Sarajevska berza ima sljedeće vrijednosti dionica: "<<std::endl;
    berza1.Ispisi();
    std::cout<<std::endl;
    Berza berza2(150, 2000);
    for(int i=6; i<25; i++) berza2.RegistrirajCijenu(i*35);
    std::cout<<"Banjalučka berza ima sljedeće vrijednosti dionica: "<<std::endl;
    berza2.Ispisi();
    std::cout<<std::endl;
    Berza berza3(15, 20000);
    for(int i=6; i<30; i++) berza3.RegistrirajCijenu(i*12);
    std::cout<<"Zagrebačka berza ima sljedeće vrijednosti dionica: "<<std::endl;
    berza3.Ispisi();
    std::cout<<std::endl;
    std::cout<<"Izbrisimo Zagrebačku berzu";
    berza3.BrisiSve();
    std::cout<<std::endl;
    std::cout<<"Na Sarajevskoj berzi ima registriranih "<<berza1.DajBrojRegistriranihCijena()<<" cijena dionica, na Banjalučkoj berzi "<<berza2.DajBrojRegistriranihCijena()<<", a na Zagrebačkoj "<<berza3.DajBrojRegistriranihCijena();
    std::cout<<std::endl;
    std::cout<<"Na Sarajevskoj berzi minimalna vrijednost iznosi "<<berza1.DajMinimalnuCijenu()<<" a maksimalna vrijednost iznosi "<<berza1.DajMaksimalnuCijenu()<<std::endl;
    std::cout<<std::endl;
    TestOperatora(berza1, berza2);
	return 0;
}
