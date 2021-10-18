/B2017/2018: Zadaća 3, Zadatak 4
#include <iostream>
#include <list>
#include <utility>
#include <string>

enum class Boje {Pik, Tref, Herc, Karo};

std::list<std::pair<Boje, std::string>>KreirajSpil() {
    std::list<std::pair<Boje, std::string>> spil;
    std::pair<Boje, std::string> karta;
    Boje boja_karte;
    for(int i(0); i < 4; i++) {
        if(i == 0) karta.first = Boje::Pik;
        if(i == 1) karta.first = Boje::Tref;
        if(i == 2) karta.first = Boje::Herc;
        else karta.first = Boje::Karo;
        for(int j(0); j < 13; j++) {
            if(j < 9)   karta.second = j + 2;
            if(j == 10) karta.second = "J";
            if(j == 11) karta.second = 'Q';
            if(j == 12) karta.second = 'K';
            else karta.second = 'A';
            spil.push_back(karta);
        }
    }
    return spil;
}
    

int main ()
{
	return 0;
}
