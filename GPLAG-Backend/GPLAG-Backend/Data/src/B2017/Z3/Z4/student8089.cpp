/B2017/2018: Zadaća 3, Zadatak 4
#include <iostream>
#include <list>
#include <map>
#include <string>
#include <utility>
#include <vector>
#include <algorithm>

enum class Boje {Pik, Tref, Herc, Karo};
typedef std::list<std::pair<Boje,std::string>> Lista;
typedef std::multimap<Boje,std::string> M_mapa;

bool DaLiJeKarta (std::string karta) {
    if (karta=="2") return true;
    return false;
}

Lista KreirajSpil() {
    
    Lista Spil;
    std::vector<std::string> Karte{"2","3","4","5","6","7","8","9","10","J","Q","K","A"};
    
    for(int i=0;i<4;i++) {
        for(int j(0);j<13;j++) {
            std::pair<Boje,std::string> Par;
            
            if(i==0) Par=std::make_pair(Boje::Pik,Karte[j]);
            if(i==1) Par=std::make_pair(Boje::Tref,Karte[j]);
            if(i==2) Par=std::make_pair(Boje::Herc,Karte[j]);
            if(i==3) Par=std::make_pair(Boje::Karo,Karte[j]);
 
            Lista::iterator it(Spil.begin());
            while(it!=Spil.end()) it++;
            Spil.insert(it,Par);
        }
        
    }
    
  //  for(auto x: Spil) std::cout<<static_cast<std::underlying_type<Boje>::type>(x.first)<<" "<<x.second<<std::endl;
    
    return Spil;
}

bool DaLiJeIspravnaLista (Lista Spil) {
    
    Lista Ispravna_lista(KreirajSpil());
    
    if(Spil.size()>52) return false;
    if(Spil.size()!=Ispravna_lista.size()) 
        return false;

    return(std::equal(Spil.begin(),Spil.end(),Ispravna_lista.begin()));
}

void IzbaciKarte(Lista &Spil,M_mapa mapa) {
    if(!DaLiJeIspravnaLista(Spil)) throw std::logic_error("Neispravna lista!");
    
    auto it=mapa.begin();
    
    while(it!=mapa.end()) {
        
    }
    
}

int main () {
    
    try{
        Lista Spil(KreirajSpil());
      //  for(auto x: Spil) std::cout<<static_cast<std::underlying_type<Boje>::type>(x.first)<<" "<<x.second<<std::endl;
        
        M_mapa mapa;

       
    }
    catch(std::logic_error izuzetak) {
        std::cout<<"Izuzetak: "<<izuzetak.what();
    }
    
	return 0;
}
