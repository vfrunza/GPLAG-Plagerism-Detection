/B2017/2018: Zadaća 3, Zadatak 4
#include <iostream>
#include <utility>
#include <list>
#include <map>
#include <queue>

enum class Boje {Pik, Tref, Herc, Karo};
std::string vrijednosti[13] {"2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K", "A"};
std::list<std::pair<Boje, std::string>> KreirajSpil () {
    std::list<std::pair<Boje, std::string>> spil;
    
    for (int i = 0; i < 13; i++) {
        spil.push_back(std::make_pair(Boje::Pik, vrijednosti[i]));
    }
    for (int i = 0; i < 13; i++) {
        spil.push_back(std::make_pair(Boje::Tref, vrijednosti[i]));
    }
    for (int i = 0; i < 13; i++) {
        spil.push_back(std::make_pair(Boje::Herc, vrijednosti[i]));
    }
    for (int i = 0; i < 13; i++) {
        spil.push_back(std::make_pair(Boje::Karo, vrijednosti[i]));
    }
    
    return spil;
} 

void IzbaciKarte (std::list<std::pair<Boje, std::string>>& spil, std::multimap<Boje, std::string> mapa) {
    if (spil.size() > 52) {
        throw std::logic_error("Neispravna lista");
    }
    for (auto it1(mapa.begin()); it1 != mapa.end(); it1++) {
        for (auto it2(spil.begin()); it2 != spil.end(); it2++) {
            if (it1->first == it2->first && it1->second == it2->second) {
                spil.erase(it2);
                mapa.erase(it1);
            }
        }
    }
}

std::queue<std::pair<Boje, std::string>> IzbaciKarteRazbrojavanjem (std::list<std::pair<Boje, std::string>>& spil, const short int &r, const int &b) {
    if (r < 1 || r > 52 || b < 1) {
        throw std::logic_error ("Neispravni elementi za izbacivanje!");
    }
    
    std::queue<std::pair<Boje, std::string>> izbaceno;
    
    return izbaceno;
}

int main ()
{
	return 0;
}
