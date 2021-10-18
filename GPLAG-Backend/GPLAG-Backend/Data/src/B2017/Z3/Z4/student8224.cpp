#include <iostream>
#include <map>
#include <list>
#include <queue>
#include <stdexcept>
#include <utility>
#include <string>
#include <algorithm>
#include <iterator>

enum class Boje {Pik, Tref, Herc, Karo};

typedef std::list<std::pair<Boje,std::string>> karte;

karte KreirajSpil(){
    std::list<std::pair<Boje,std::string>>spil{std::make_pair(Boje::Pik,"2"),std::make_pair(Boje::Pik,"3"),
    std::make_pair(Boje::Pik,"4"),std::make_pair(Boje::Pik,"5"),std::make_pair(Boje::Pik,"6"),std::make_pair(Boje::Pik,"7"),
    std::make_pair(Boje::Pik,"8"),std::make_pair(Boje::Pik,"9"),std::make_pair(Boje::Pik,"10"),std::make_pair(Boje::Pik,"J"),
    std::make_pair(Boje::Pik,"Q"),std::make_pair(Boje::Pik,"K"),std::make_pair(Boje::Pik,"A"),
    std::make_pair(Boje::Tref,"2"),std::make_pair(Boje::Tref,"3"),std::make_pair(Boje::Tref,"4"),
    std::make_pair(Boje::Tref,"5"),std::make_pair(Boje::Tref,"6"),
    std::make_pair(Boje::Tref,"7"),std::make_pair(Boje::Tref,"8"),std::make_pair(Boje::Tref,"9"),
    std::make_pair(Boje::Tref,"10"),std::make_pair(Boje::Tref,"J"),std::make_pair(Boje::Tref,"Q"),
    std::make_pair(Boje::Tref,"K"),std::make_pair(Boje::Tref,"A"),std::make_pair(Boje::Herc,"2"),
    std::make_pair(Boje::Herc,"3"),std::make_pair(Boje::Herc,"4"),std::make_pair(Boje::Herc,"5"),
    std::make_pair(Boje::Herc,"6"),std::make_pair(Boje::Herc,"7"),std::make_pair(Boje::Herc,"8"),
    std::make_pair(Boje::Herc,"9"),std::make_pair(Boje::Herc,"10"),std::make_pair(Boje::Herc,"J"),
    std::make_pair(Boje::Herc,"Q"),std::make_pair(Boje::Herc,"K"),std::make_pair(Boje::Herc,"A"),
    std::make_pair(Boje::Karo,"2"),std::make_pair(Boje::Karo,"3"),std::make_pair(Boje::Karo,"4"),
    std::make_pair(Boje::Karo,"5"),std::make_pair(Boje::Karo,"6"),std::make_pair(Boje::Karo,"7"),
    std::make_pair(Boje::Karo,"8"),std::make_pair(Boje::Karo,"9"),std::make_pair(Boje::Karo,"10"),
    std::make_pair(Boje::Karo,"J"),std::make_pair(Boje::Karo,"Q"),std::make_pair(Boje::Karo,"K"),
    std::make_pair(Boje::Karo,"A")};
    return spil;
}

void IzbaciKarte(karte&spil, std::multimap<Boje,std::string>&mapa){
    if(std::distance(spil.begin(),spil.end())>52) throw std::logic_error("Neispravna lista!");
    for(auto its=spil.begin(); its!=spil.end(); its++){
        for(auto itm=mapa.begin(); itm!=mapa.end(); itm++){
            if(its->first==itm->first && its->second==itm->second){
                spil.erase(its);
                mapa.erase(itm);
            }
        }
    }
}

karte IzbaciKarteRazbrajanjem(karte&spil, const short int &r, const int &b){
    if(r<1 || r>52 || b<1) throw std::logic_error("Neispravni elementi za izbacivanje!");
    if(std::distance(spil.begin(),spil.end())>52) throw std::logic_error("Neispravna lista!");
    karte red;
    /*while(b>0){
        auto it(spil.begin());
        for(int j=0; j<rr; j++) it++;
        red.push_back(*it);
        spil.erase(it);
        rr*=2;
        if(rr>52) rr-=52;
    }*/
    return red;
} 

std::string Pretvori(Boje boja){
    if(boja==Boje::Pik) return "Pik";
    if(boja==Boje::Tref) return "Tref";
    if(boja==Boje::Herc) return "Herc";
    return "Karo";
}

int main ()
{
    int b(0),r(0);
    karte spil(KreirajSpil());
    std::cout<<"Unesite korak razbrajanja: ";
    std::cin>>r;
    std::cout<<"Unesite broj karata koje zelite izbaciti: ";
    std::cin>>b;
    try{
        auto novi(IzbaciKarteRazbrajanjem(spil,r,b));
    std::cout<<"U spilu trenutno ima "<<52-b<<" karata, i to: "<<std::endl;
    std::cout<<"Pik: ";
    for(auto it=novi.begin(); it!=novi.end(); it++){
        std::cout<<it->second;
    }
    }catch(std::logic_error izuzetak){
        std::cout<<"Izuzetak: "<<izuzetak.what();
        return 1;
    }
    try{
        
    }catch(std::logic_error izuzetak){
        std::cout<<"Izuzetak: "<<izuzetak.what();
        return 2;
    }
    std::cout<<"Unesite broj karata koje zelite vratiti u spil: ";
    /*try{
        
    }catch(){
        
    }*/
	return 0;
}
