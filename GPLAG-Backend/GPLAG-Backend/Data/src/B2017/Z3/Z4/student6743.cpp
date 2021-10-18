/B2017/2018: Zadaća 3, Zadatak 4
#include <iostream>
#include <list>
#include <utility>
#include <string>
enum class Boje {Pik, Tref, Herc, Karo};
std::vector<std::string> vK{"2","3","4","5","6","7","8","9","10","J","Q","K","A"};

std::list<std::pair< Boje, std::string>> KreirajSpil(){
    std::list<std::pair< Boje, std::string>> lista;
    for(int j=0;j<13;j++) lista.push_back(std::make_pair(Boje::Pik,vK[j]));
    for(int j=0;j<13;j++) lista.push_back(std::make_pair(Boje::Tref,vK[j]));
    for(int j=0;j<13;j++) lista.push_back(std::make_pair(Boje::Herc,vK[j]));
    for(int j=0;j<13;j++) lista.push_back(std::make_pair(Boje::Karo, vK[j]));
    return lista;
}

IzbaciKarte(std::list<std::pair<Boje,std::string>> &spil,std::multimap<Boje, std::string> &mapa){
    if(spil.size()>52) throw std::logic_error("Neispravna lista!");
    int brkarata=spil.size();
    
}

std::std::queue<std::pair<std::string, std::string>> IzbaciKarteRazbrajanjem(std::list<std::pair<Boje,std::string>> &spil,const short int &razbrajanje, const int &br){
    if(razbrajanje<1 || razbrajanje>52 || br<1) throw std::logic_error "Neispravni elementi za izbacivanje!";
    std::std::queue<std::pair<std::string, std::string>> povratni;
    int brkarata=spil.size();
    std::list<std::pair<Boje,std::string>> *lista=spil;
    if(brkarata==PrebrojiKarte(lista)){
        auto pom=spil;
        for(int i=0;i<brkarata;i++){
            auto x=pom->first;
            std::string t;
            if(x==Boje(0)) t="Herc";
            if(x==Boje(1)) t="Karo";
            if(x==Boje(2)) t="Pik";
            if(x==Boje(3)) t=="Tref";
            std::pair<std::string,std::string> par(std::make_pair(t,t))
        }
    }
}
int main ()
{
	return 0;
}
