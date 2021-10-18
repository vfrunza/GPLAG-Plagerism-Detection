/B2017/2018: Zadaća 3, Zadatak 4
#include <iostream>
#include <list>
#include <string>
#include <utility>
#include <iterator>
enum class Boje {Pik, Tref, Herc, Karo};
typedef std::list<std::pair<Boje, std::string>> Spil;
Spil KreirajSpil(){
    Spil spil_karata;
    std::string vrijednosti[13]={"2","3","4","5","6","7","8","9","10","J","Q","K","A"};
    //ubacivanje Pik
    for(int i=0; i<13; i++){
        std::pair<Boje,std::string> karta;
        karta.first=Boje::Pik;
        karta.second=vrijednosti[i];
        spil_karata.push_back(karta);
    }
    //ubacivanje Tref
    for(int i=0; i<13; i++){
        std::pair<Boje, std::string> karta;
        karta.first=Boje::Tref;
        karta.second=vrijednosti[i];
        spil_karata.push_back(karta);
    }
    //ubacivanje Herc
    for(int i=0; i<13; i++){
        std::pair<Boje, std::string> karta;
        karta.first=Boje::Herc;
        karta.second=vrijednosti[i];
        spil_karata.push_back(karta);
    } 
    //ubacivanje Karo
    for(int i=0; i<13; i++){
        std::pair<Boje, std::string> karta;
        karta.first=Boje::Karo;
        karta.second=vrijednosti[i];
        spil_karata.push_back(karta);
    }
    return spil_karata;
}


int main ()
{
    Spil novi=KreirajSpil();
    std::list<std::pair<Boje,std::string>>::iterator it(novi.begin());
    
	return 0;
}
