/B2017/2018: Zadaća 5, Zadatak 6
#include <iostream>
#include <vector>
#include <stdexcept>
#include <functional>
#include <algorithm>
#include <iterator>
#include <iomanip>
#include <ostream>

class Berza{
    std::vector<int> dionice;
    int min,maks;
    void TestIndeksa(int  indeks){
        if(indeks<1 || indeks>dionice.size()) throw std::range_error("Neispravan indeks");
    }
    public:
    Berza(int min, int maks){
        if(min<=0 || maks<=0) throw std::range_error("Ilegalne granicne cijene");
        Berza::min=min;
        Berza::maks=maks;
    }
    explicit Berza(int maks){
        if(maks<=0)  throw std::range_error("Ilegalne granicne cijene");
        Berza::min=0;
        Berza::maks=maks;
         }
    void RegistrirajCijenu(int cijena){
        if(cijena>maks || cijena<min) throw std::range_error("Ilegalne granicne cijene");
        dionice.push_back(cijena);
    }    
    int DajBrojRegistriranihCijena () const { return dionice.size();}
    void BrisiSve() {
        dionice.resize(0);}
    //provjeriti je l to znaci postaviti vektor na prazan
    int DajMinimalnuCijenu() const {
        if(!dionice.size()) throw std::range_error("Nema registriranih cijena");
        return *(std::min_element( dionice.begin(),  dionice.end(), [](int a, int b){return a<b;}));
    }
    int DajMaksimalnuCijenu() const {
        if(!dionice.size()) throw std::range_error("Nema registriranih cijena");
        return *(std::max_element( dionice.begin(),  dionice.end(), [](int a, int b){return a<b;}));
    }
     bool operator!(){
        return !dionice.size();
    }
    int DajBrojCijenaVecihOd(int p) const;
    void Ispisi() const;
    int operator[](int indeks);
    void operator++();
    void operator ++(int);
    void operator--();
    void operator --(int);
    void operator -();
    friend Berza operator +(Berza x, int y);
    friend Berza operator +(Berza x, Berza y);
    friend Berza operator -(Berza x, int y);
    friend Berza operator -(Berza x, Berza y);
   Berza operator+=(Berza y);
     Berza operator +=(int y);
      Berza operator-=(Berza y);
     Berza operator -=(int y);
     friend bool operator ==(Berza x, Berza y);
    
   
        
};
 int Berza::DajBrojCijenaVecihOd(int p) const{
    if(!dionice.size()) throw std::range_error("Nema registriranih cijena");
   return std::count_if(dionice.begin(), dionice.end(), std::bind(std::greater<int>(), std::placeholders::_1, p));}
    void Berza::Ispisi() const {
        std::vector<double> a;
        std::copy(dionice.begin(), dionice.end(), std::back_inserter(a));
        std::sort(a.begin(), a.end(), std::greater<int>());
        std::transform(a.begin(), a.end(),a.begin(), std::bind(std::divides<double>(),std::placeholders::_1, 100 ));
       // std::for_each(a.begin(), a.end(),  std::ostream_iterator<double>(std::cout,"\n"));
      
       std::remove_copy(a.begin(), a.end(),std::ostream_iterator<double>(std::cout<<std::fixed<<std::setprecision(2), "\n"), -1);
        
    }
    int Berza::operator [](int indeks){
        TestIndeksa(indeks);
        return dionice[indeks-1];
    }
    void Berza::operator ++(){
        std::transform(dionice.begin(), dionice.end(), dionice.begin(), std::bind(std::plus<int>(), std::placeholders::_1, 1));
        if(DajBrojCijenaVecihOd(maks)>0) {
        std::transform(dionice.begin(), dionice.end(), dionice.begin(), std::bind(std::minus<int>(), std::placeholders::_1, 1));
        throw std::range_error("Prekoracen dozvoljeni opseg cijena");
    }
    
    }
    void Berza::operator ++(int){
        ++(*this);
    }
    void Berza::operator --(){
        std::transform(dionice.begin(), dionice.end(), dionice.begin(), std::bind(std::minus<int>(), std::placeholders::_1, 1));
        if(std::count_if(dionice.begin(), dionice.end(), std::bind(std::less<int>(), std::placeholders::_1, min))) {
        std::transform(dionice.begin(), dionice.end(), dionice.begin(), std::bind(std::plus<int>(), std::placeholders::_1, 1));
        throw std::range_error("Prekoracen dozvoljeni opseg cijena");
    }
    
    }
    void Berza::operator --(int){
        --(*this);
    }
    void Berza::operator-(){
        std::transform(dionice.begin(), dionice.end(), dionice.begin(), std::bind(std::minus<int>(),maks+min, std::placeholders::_1));
    }
    Berza operator +(Berza x, int y){
        std::transform(x.dionice.begin(), x.dionice.end(), x.dionice.begin(), std::bind(std::plus<int>(), std::placeholders::_1, y));
        if(x.DajBrojCijenaVecihOd(x.maks)>0) {
        std::transform(x.dionice.begin(), x.dionice.end(),x.dionice.begin(), std::bind(std::minus<int>(), std::placeholders::_1, y));
        throw std::domain_error("Prekoracen dozvoljeni opseg cijena");
    }
     return x;   
    }
    Berza operator +(Berza x, Berza y){
        if(x.dionice.size()!=y.dionice.size()) throw std::domain_error("Nesaglasni operandi");
        std::transform(x.dionice.begin(), x.dionice.end(),y.dionice.begin(), x.dionice.begin(), std::plus<int>());
        if(x.DajBrojCijenaVecihOd(x.maks)>0) {
        std::transform(x.dionice.begin(), x.dionice.end(),y.dionice.begin(), x.dionice.begin(), std::minus<int>());
        throw std::domain_error("Prekoracen dozvoljeni opseg cijena");
    }
     return x;   
    }
    
     Berza operator -(Berza x, int y){
        std::transform(x.dionice.begin(), x.dionice.end(), x.dionice.begin(), std::bind(std::minus<int>(), std::placeholders::_1, y));
        if(std::count_if(x.dionice.begin(), x.dionice.end(), std::bind(std::less<int>(), std::placeholders::_1, x.min))) {
        std::transform(x.dionice.begin(), x.dionice.end(), x.dionice.begin(), std::bind(std::plus<int>(), std::placeholders::_1, y));
        throw std::domain_error("Prekoracen dozvoljeni opseg cijena");
    }
 return x;
    }
    Berza operator -(Berza x, Berza y){
        if(x.dionice.size()!=y.dionice.size() || x.maks!=y.maks || x.min!=y.min) throw std::domain_error("Nesaglasni operandi");
        std::transform(x.dionice.begin(), x.dionice.end(), y.dionice.begin(),x.dionice.begin(), std::minus<int>());
        if(std::count_if(x.dionice.begin(), x.dionice.end(), std::bind(std::less<int>(), std::placeholders::_1,x.min))) {
        std::transform(x.dionice.begin(), x.dionice.end(),y.dionice.begin(), x.dionice.begin(), std::plus<int>());
        throw std::domain_error("Prekoracen dozvoljeni opseg cijena");
    }
    return x;
    }
    Berza Berza:: operator +=(Berza y){
        *this=*this+y;
        return *this;
    }
    Berza Berza:: operator -=(Berza y){
        *this=*this-y;
        return *this;
    }
    Berza Berza:: operator +=(int y){
        *this=*this+y;
        return *this;
    }
    Berza Berza:: operator -=(int y){
        *this=*this-y;
        return *this;
    }
    bool operator==(Berza x, Berza y){
        if(x.dionice.size()!=y.dionice.size() || x.maks!=y.maks || x.min!=y.min) return false;
        return std::equal(x.dionice.begin(), x.dionice.end(), y.dionice.begin());
        
    }
    bool operator!=(Berza x, Berza y){
        return !(x==y);
    }
     
    

int main ()
{
    std::cout<<"Unesite minimalnu i maksimalnu cijenu: ";
    int m,n;
    std::cin>>m>>n;
    Berza a(m,n);int opcija;
    do{
        
        std::cout<<"Unesite opciju: "<<std::endl
        <<"1: RegistrirajCijenu"<<std::endl
        <<"2: Saberi sa cijelim brojem"<<std::endl
        <<"3: Oduzmi od maksimalne i minimalne "<<std::endl
        <<"4: Oduzmi za neki iznos"<<std::endl
        <<"5: Prikazi Minimalnu cijenu: "<<std::endl
        <<"6: Prikazi broj cijena vecih od zeljene"<<std::endl
        <<"7: Ispisi cijene"<<std::endl
        <<"8: Zavrsi"<<std::endl;
    std::cin>>opcija;
    switch (opcija){
        case 8: break;
        case 1:
        while(true){
        try{
            std::cout<<"Unesite cijenu: ";
            int cijena;
            std::cin>>cijena;
            a.RegistrirajCijenu(cijena);
            break;
        
        
    } catch(std::range_error iz){
        std::cout<<iz.what()<<" Unesite ponovo!"<<std::endl;
    }}
    break;
    case 2: try{
            std::cout<<"Unesite broj: ";
            int cijena1;
            std::cin>>cijena1;
           a+=cijena1;
            break;
        
        
    } catch(std::range_error iz){
        std::cout<<iz.what();}
        break;
        case 3: 
        
           -a;
            break;
            case 4: 
             try{
            std::cout<<"Unesite broj: ";
            int cijena2;
            std::cin>>cijena2;
           a-=cijena2;
            break;
        
        
    } catch(std::range_error iz){
        std::cout<<iz.what();}
        break;
        case 5: std::cout<<a.DajMinimalnuCijenu();break;
        case 6: 
        std::cout<<"Unesite broj: ";
            int cijena3;
            std::cin>>cijena3;
            std::cout<<"Broj cijena vecih od zeljene: "<<a.DajBrojCijenaVecihOd(cijena3);
            case 7:
            a.Ispisi();
            break;
    }}while(opcija!=8) ;
    
	return 0;
}
