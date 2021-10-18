/B2017/2018: Zadaća 3, Zadatak 4
#include <iostream>
#include <list>
#include <utility>
#include <string>
#include <map>
enum class Boje{Pik, Tref, Herc, Karo};
 
typedef std::list<std::pair<Boje, std::string>> Tip;

Tip KreirajSpil(){
    std::list<std::pair<Boje, std::string>> lista_koju_vraca;
    std::string niz[13]{"2","3","4","5","6","7","8","9","10", "J", "Q", "K", "A"};
     Boje niz1[4]{ Boje::Pik, Boje::Tref, Boje::Herc, Boje::Karo};
        for(int i=0; i<4; i++){
            for(int j=0; j<13; j++){
                std::pair<Boje, std::string> pomocna;
                pomocna=std::make_pair(niz1[i], niz[j]);
                lista_koju_vraca.insert(pomocna);
            }
        }
    return lista_koju_vraca;
}

void IzbaciKarte(Tip &spil, std::multimap<Boje, std::string> &drugi_p){
     for(auto it=drugi_p.begin(); it!=drugi_p.end(); it++){
         if(spil.count(it->first, it->second)){
             spil.erase(it->first);
         }
     }
}
int main ()
{
	return 0;
}
