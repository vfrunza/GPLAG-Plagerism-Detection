/B16/17 (Zadaća 5, Zadatak 5)
//Autotestovi by Berina Cocalic (mail: bcocalic1@etf.unsa.ba)
//Za autotestove se obracati *iskljucivo* osobi koja ih pise
#include <iostream>
#include <list>
#include <utility>
#include <vector>
#include <stdexcept>
#include <algorithm>
#include <functional>

class Temperature{
    int min;
    int maks;
    std::list<int> minimalne;
    std::list<int> maksimalne;
    
    public:
    Temperature(int minimalna, int maksimalna);
    void RegistrirajTemperature(std::pair<int,int> temperature);
    void BrisiSve();
    void BrisiSveNegativne();
    int DajBrojRegistriranihParova()const;
    int DajMinimalnuTemperaturu()const;
    int DajMaksimalnuTemperaturu()const;
    int DajBrojTemperaturaVecihOd(int temperatura)const;
    int DajBrojTemperaturaManjihOd(int temperatura)const;
    bool operator!(Temperature &temp)const;
    Temperature &operator++(Temperature &temp);
    Temperature operator ++(Temperature &temp, int);
    Temperature &operator--(Temperature &temp);
    Temperature operator --(Temperature &temp, int);
    std::vector<int> *(Temperature &temp)const;
    std::vector<int> -(Temperature &temp)const;
    std::vector<int> +(Temperature &temp)const;
    std::pair<int,int> [](int indeks)const;
    
    
};

Temperature::Temperature(int minimalna, int maksimalna){
    if(minimalna>maksimalna) throw std::range_error ("Nekorektne temperature");
    min=minimalna; max=maksimalna;
}

void Temperature::RegistrirajTemperature(std::pair<int,int> temperature){
    if(temperature.first<min || temperature.second <min || temperature.first>maks || temperature.second>maks || temperature.first>temperature.second) 
                throw std::range_error("Nekorektne temperature");
    minimalne.push_back(temperature.first); maksimalne.push_back(temperature.second);
}

void Temperature::BrisiSve(){
    std::lista<int> pomocna;
    minimalna=pomocna; maksimalna=pomocna;
}

void Temperature::BrisiSveNegativne(){
    
}

int Temperature::DajBrojRegistriranihParova()const{
    return int(minimalne.size());
}

int Temperature::DajMinimalnuTemperaturu()const{
   auto it= std::min_element(minimalne.begin(), minimalne.end());
   return *it;
}

int Temperature::DajMaksimalnuTemperaturu()const{
    auto it=std::max_element(maksimalne.begin(), maksimalne.end());
    return *it;
}

int Temperature::DajBrojTemperaturaVecihOd(int temperatura)const{
    return std::count_if(maksimalne.begin(), maksimalne.end(),std::bind(std::greater<int>(), std::placeholders::_1,temperatura));
}

int Temperature::DajBroJTemperaturaManjiOd(int temperatura)const{
    return std::count_if(minimalne.begin(), minimalne.end(), std::bind(std::less<int>(), std::placeholders::_1, temperatura));
}

bool Temperature::operator!(Temperature !temp)const{
    if((maksimalne.size())==0 && int(minimalne.size())==0) return true;
    return false;
}

Temperature &Temperature::operator++(Temperature &temp){
    std::list<int> pomocna(temp.minimalne);
    std::transform(pomocna.begin(), pomocna.end(), pomocna.begin(),std::bind(std::plus<int>, std::placeholders::_1, 1));
    bool overflow=std::equal(pomocna.begin(), pomocna.end(), temp.maksimalne.begin(), std::les<int>()  );
    if(overflow==false) throw std::logic_error("Ilegalna operacija");
    temp.minimalne=pomocna;
    return temp;
}

Temperature Temperature::operator++(Temperature &temp, int){
    std::list<int> pomocna(temp.minimalne);
    std::transform(pomocna.begin(), pomocna.end(), pomocna.begin(), std::bind(std::plus<int>, std::placeholders::_1,1))M
    bool overlflow=std::equal(pomocna.begin(), pomocna.end(), temp.maksimalne.begin(), std::les<int>())M
    if(overflow==false)  throw std::logic_error("Ilegalna operacija");
    Temperature povratna(temp);
    temp.minimalne=pomocna;
    return povratna;
}

Temperature &Temperature::operator--(Temperature &temp){
    std::list<int> pomocna(temp.maksimalne);
    std::transform(pomocna.begin(), pomocna.end(), pomocna.begin(), std::bind(std::minus<int>, std::placeholders::_1,1));
    bool overflow=std::equal(temp.minimalne.begin(), temp.minimalne.end(), pomocna.begin(), std::les<int>());
    if(overflow==false) throw std::logic_error("Ilegalna operacija");
    temp.maksimalne=pomocna;
    return temp;
}

Temperature Temperature::operator--(Temperature &temp){
    std::list<int> pomocna(temp.maksimalne);
    std::transform(pomocna.begin(),pomocna.end(), pomocna.begin(), std::bind(std::minus<int>, std::placeholders::_1,1));
    bool overflow=std::equal(temp.minimalne.begin(), temp.minimalne.end(), pomocna.begin(), std::les<int>());
    if(overflow==false) throw std::logic_error("Ilegalna operacija");
    Temperature povratna(temp);
    temp.minimalne=pomocna;
    return povratna;
}

std::vector<int> Temperature::operator*(Temperature &temp) const{
    std::vector<int>povratni;
    povratni.resize(int(temp.minimalni.size()));
    std::transform(temp.maksimalni.begin(), temp.maksimalni.end(), temp.minimalni.begin(), povratni.begin(), std::minus<int>());
    return povratni;
}

std::vector<int> Temperature::operator-(Temperature &temp) const{
    std::vector<int>povratni;
    povratni.resize(int(temp.minimalni.size()));
    std::transform(temp.minimalni.begin(), temp.minimalni.end(), povratni.begin(), std::bind(std::minus<int>, std::placeholders::_1,temp.min));
    return povratni;
}

std::vector<int> Temperature::operator+(Temperature &temp) const{
    std::vector<int>povratni;
    povratni.resize(int(temp.maksimalni.size()));
    std::transform(temp.maksimalni.begin(), temp.maksimalni.end(), povratni.begin(), std::bind(std::minus<int>, temp.min,std::placeholders::_1));
    return povratni;
}

std::pair<int,int> Temperature::operator [](int indeks) const{
    if(indeks<0 || indeks>int(maksimalne.size())) throw std::range_error("Neispravan indeks");
    
}



int main ()
{
    std::cout<<".";
	return 0;
}