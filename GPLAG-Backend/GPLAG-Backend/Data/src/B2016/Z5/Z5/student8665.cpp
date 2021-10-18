#include <iostream>
#include <list>
#include <stdexcept>
#include <vector>
#include <algorithm>
#include <iterator>
#include <utility>
#include <functional>

class Temperature{
    std::list<int>minimalne_temperature;
    std::list<int>maksimalne_temperature;
    int min_dozvoljena,max_dozvoljena; //da li ih koristim samo u konstruktoru
    public:
    explicit Temperature(int min, int max){
        if(min>max) std::range_error("Nekorektne temperature");
        min_dozvoljena=min; max_dozvoljena=max; //nije dobro, provjeriti...
    }

    void RegistrirajTemperature(std::pair<int,int>p);
    void BrisiSve();
    void BrisiTemperature(std::pair<int,int>p);
    int DajBrojRegistriranihTemperatura() const;//je li veličina liste br. parova
    int DajMinimalnuTemperaturu() const;//min u listi
    int DajMaksimalnuTeperaturu() const;//max u listi
    int DajBrojTeperaturaVecihOd(int max) const;//bind ?
    int DajBrojTeperaturaManjihOd(int min) const;//bind
    //OPERATORI
    bool operator !() const{//nema parametara?
        if(minimalne_temperature.size()==0 && maksimalne_temperature.size()==0) return true;
        return false;
    }
    Temperature &operator ++(){//prefiksni, pitati za uslov
        std::vector<int>pomocni;
        pomocni.resize(minimalne_temperature.size());
        std::transform(maksimalne_temperature.begin(),maksimalne_temperature.end(),minimalne_temperature.begin(),pomocni.begin(),std::minus<int>());
        std::transform(minimalne_temperature.begin(),minimalne_temperature.end(),minimalne_temperature.begin(),std::bind(std::plus<int>(),1,std::placeholders::_1));
        
        //IZUZETAK
        //if(std::count_if(minimalne_temperature.begin(),minimalne_temperature.end(),std::bind(std::greater<int>(),max_dozvoljena,std::placeholders::_1))==0)
        //throw std::logic_error("Ilegalna operacija");
        return *this;//je li ovo uredu?
    }
    Temperature &operator --(){//prefiksni
        std::transform(maksimalne_temperature.begin(),maksimalne_temperature.end(),maksimalne_temperature.end(),std::bind(std::minus<int>(),1,std::placeholders::_1));
        //IZUZETAK
        //if(std::count_if(maksimalne_temperature.begin(),maksimalne_temperature.end(),std::bind(std::greater<int>(),min_dozvoljena,std::placeholders::_1))==0)
        //throw std::logic_error("Ilegalna operacija");//provjeriti if
        //return *this;//koji placeholders ide 1 ili 2? dilema
    }
    Temperature operator ++(int){//postfiksni
        std::transform(minimalne_temperature.begin(),minimalne_temperature.end(),minimalne_temperature.begin(),std::bind(std::plus<int>(),1,std::placeholders::_1));
        //IZUZETAK
        //if(std::count_if(minimalne_temperature.begin(),minimalne_temperature.end(),std::bind(std::greater<int>(),max_dozvoljena,std::placeholders::_1))==0)
        //throw std::logic_error("Ilegalna operacija");
        //return *this;
    }
    Temperature operator --(int){//postfiksni
        std::transform(maksimalne_temperature.begin(),maksimalne_temperature.end(),maksimalne_temperature.begin(),std::bind(std::minus<int>(),1,std::placeholders::_1));
        //IZUZETAK
        //if(std::count_if(maksimalne_temperature.begin(),maksimalne_temperature.end(),std::bind(std::greater<int>(),min_dozvoljena,std::placeholders::_1))==0)
        //throw std::logic_error("Ilegalna operacija");//problem sa izuzetkom
        //return *this;
    }//ne pise da se traba baciti izuzetak za --  ???
    std::vector<int> operator *(){
        std::vector<int>v;
        v.resize(minimalne_temperature.size());
        std::transform(maksimalne_temperature.begin(),maksimalne_temperature.end(),minimalne_temperature.begin(),v.begin(),std::minus<int>());
        return v;
    }
    std::vector<int> operator -(){
        std::vector<int>v;
        v.resize(minimalne_temperature.size());
        std::transform(minimalne_temperature.begin(),minimalne_temperature.end(),v.begin(),std::bind(std::minus<int>(),std::placeholders::_1,min_dozvoljena));
        return v;
    }
    std::vector<int> operator +(){ 
        std::vector<int>v;
        v.resize(maksimalne_temperature.size());
        std::transform(maksimalne_temperature.begin(),maksimalne_temperature.end(),v.begin(),std::bind(std::minus<int>(),max_dozvoljena,std::placeholders::_1));
        return v;
    }
    
    std::pair<int,int> operator [](int index) const {
        if(index<0 || index>maksimalne_temperature.size()) throw std::range_error("Neispravan indeks");
        std::pair<int,int>povratni;
        auto it1(minimalne_temperature.begin());
        auto it2(maksimalne_temperature.begin());
        std::advance(it1,index-1);//-1 može biti moguca greska
        std::advance(it2,index-1);
        povratni.first=*it1;
        povratni.second=*it2;
        return povratni;//moguce greske 
    }
    
    Temperature operator +(int y){
        //IZUZETAK
        std::transform(minimalne_temperature.begin(),minimalne_temperature.end(),minimalne_temperature.begin(),std::bind(std::plus<int>(),y,std::placeholders::_1));
        std::transform(maksimalne_temperature.begin(),maksimalne_temperature.end(),maksimalne_temperature.begin(),std::bind(std::plus<int>(),y,std::placeholders::_1));
        
        
        return *this;
    }
    
     Temperature operator -(int y){
         //IZUZETAK
        std::transform(minimalne_temperature.begin(),minimalne_temperature.end(),minimalne_temperature.begin(),std::bind(std::minus<int>(),y,std::placeholders::_1));
        std::transform(maksimalne_temperature.begin(),maksimalne_temperature.end(),maksimalne_temperature.begin(),std::bind(std::minus<int>(),y,std::placeholders::_1));
        return *this;
}
    Temperature operator +=(int y){
        return *this=*this+y;
    }
    Temperature operator -=(int y){
        return *this=*this-y;
    }    
    /*bool operator ==(Temperature &temp2){
        if(this->DajBrojRegistriranihTemperatura()==temp2.DajBrojRegistriranihTemperatura() && )
        
        //sa funkcijama provjeriti??
        
    }*/
    /*std::ostream &operator << (std::ostream &tok){
        std::for_each(minimalne_temperature.begin(),minimalne_temperature.end(),std::ostream_iterator<Temperature>it(tok,", "));
        tok<<std::endl;//greska pri ispisu, potraziti zamjenu.
        std::for_each(maksimalne_temperature.begin(),maksimalne_temperature.end(),std::ostream_iterator<Temperature>it1(tok));
        return tok;
    }*/
 };

    void Temperature::RegistrirajTemperature(std::pair<int,int>p){
        if(p.first<min_dozvoljena || p.second>max_dozvoljena || p.first>p.second) throw std::range_error("Nekorektne temperature");
        minimalne_temperature.push_back(p.first);
        maksimalne_temperature.push_back(p.second);
    }
    
    void Temperature::BrisiSve(){
        minimalne_temperature.clear();
        maksimalne_temperature.clear();
    }
    
    void Temperature::BrisiTemperature(std::pair<int,int>p){
        auto pomocni1(std::find(minimalne_temperature.begin(),minimalne_temperature.end(),p.first));
        auto pomocni2(std::find(maksimalne_temperature.begin(),maksimalne_temperature.end(),p.second));
        
        if(pomocni1==minimalne_temperature.end() && pomocni2==maksimalne_temperature.end()) throw std::logic_error("Takve temperature nisu registrirane");
        if(pomocni1!=minimalne_temperature.end()) minimalne_temperature.erase(pomocni1);
        if(pomocni2!=minimalne_temperature.end()) minimalne_temperature.erase(pomocni2);
    }
    
    int Temperature::DajBrojRegistriranihTemperatura() const{return minimalne_temperature.size();}
    int Temperature::DajMinimalnuTemperaturu() const{
        if(minimalne_temperature.size()==0) std::logic_error("Nema registriranih temperatura");
        int min=*(std::min_element(minimalne_temperature.begin(),minimalne_temperature.end()));
        return min;
    }
    int Temperature::DajMaksimalnuTeperaturu() const{
        if(maksimalne_temperature.size()==0) std::logic_error("Nema registriranih temperatura");
        int max=*(std::max_element(maksimalne_temperature.begin(),maksimalne_temperature.end()));
        return max; 
    }
    int Temperature::DajBrojTeperaturaVecihOd(int max) const{
        if(maksimalne_temperature.size()==0) std::logic_error("Nema registriranih temperatura");
        int broj_dana(0);
        broj_dana=std::count_if(maksimalne_temperature.begin(),maksimalne_temperature.end(),std::bind(std::greater<int>(),max,std::placeholders::_1));
        return broj_dana;
    }
    int Temperature::DajBrojTeperaturaManjihOd(int min) const{
        if(minimalne_temperature.size()==0) std::logic_error("Nema registriranih temperatura");
        int broj_dana(0);
        broj_dana=std::count_if(minimalne_temperature.begin(),minimalne_temperature.end(),std::bind(std::greater<int>(),min,std::placeholders::_1));
        return broj_dana;
    }





int main (){
    std::cout<<"KOMPAJLIRA SE.";
	return 0;
}