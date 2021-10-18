/B2017/2018: Zadaća 3, Zadatak 4
#include <iostream>
#include <iomanip>
#include <stdexcept>
#include <string>
#include <new>
#include <map>
#include <queue>
#include <utility>
#include <list>
#include <cstddef>
#include <algorithm>


enum class Boje {Pik, Tref, Herc, Karo};

std::list<std::pair<Boje, std::string>> KreirajSpil() {
    
    std::list<std::pair<Boje, std::string>> spil;
    
    for (int i = 0; i < 4; i++) {
        if (i == 0) {
            for (std::size_t i = 2; i <=10; i++) {
                spil.push_back(std::make_pair(Boje::Pik, std::to_string(i)));
            }
            spil.push_back(std::make_pair(Boje::Pik, "J"));
            spil.push_back(std::make_pair(Boje::Pik, "Q"));
            spil.push_back(std::make_pair(Boje::Pik, "K"));
            spil.push_back(std::make_pair(Boje::Pik, "A"));
        }
        else if (i == 1) {
            for (std::size_t i = 2; i <= 10; i++) {
                spil.push_back(std::make_pair(Boje::Tref, std::to_string(i)));
            }
            spil.push_back(std::make_pair(Boje::Tref, "J"));
            spil.push_back(std::make_pair(Boje::Tref, "Q"));
            spil.push_back(std::make_pair(Boje::Tref, "K"));
            spil.push_back(std::make_pair(Boje::Tref, "A"));
        }
        else if (i == 2) {
            for (std::size_t i = 2; i <= 10; i++) {
                spil.push_back(std::make_pair(Boje::Herc, std::to_string(i)));
            }
            spil.push_back(std::make_pair(Boje::Herc, "J"));
            spil.push_back(std::make_pair(Boje::Herc, "Q"));
            spil.push_back(std::make_pair(Boje::Herc, "K"));
            spil.push_back(std::make_pair(Boje::Herc, "A"));
        }
        else if (i == 3) {
            for (std::size_t i = 2; i <= 10; i++) {
                spil.push_back(std::make_pair(Boje::Karo, std::to_string(i)));   
            }
                spil.push_back(std::make_pair(Boje::Karo, "J"));
                spil.push_back(std::make_pair(Boje::Karo, "Q"));
                spil.push_back(std::make_pair(Boje::Karo, "K"));
                spil.push_back(std::make_pair(Boje::Karo, "A"));
        }
    }
    return spil;
}

void IzbaciKarte(std::list <std::pair<Boje, std::string>> &lista, std::multimap<Boje, std::string> &mapa) {
    
    if(lista.size() > 52) throw std::logic_error ("Neispravna lista!");
    //
    for (auto item = mapa.begin(); item != mapa.end(); item++) {
        if ((std::find(lista.begin(), lista.end(), item) != lista.end())) {
            lista.remove(*item);
            mapa.erase(item);
        }
    }
}

std::string PretvoriUString(Boje boja) {
    if (boja == Boje::Karo) return "Karo";
    else if (boja == Boje::Tref) return "Tref";
    else if (boja == Boje::Herc) return "Herc";
    else if (boja == Boje::Pik) return "Pik";
}

std::queue<std::pair<Boje, std::string>> IzbaciKarteRazbrajanjem (std::list<std::pair<Boje, std::string>> & lista, const short int korakRazbrajanja, const int brojKarata) {
    if (korakRazbrajanja < 1 || korakRazbrajanja > 52) throw std::logic_error ("Neispravni elementi za izbacivanje!");
    if (brojKarata < 1) throw std::logic_error("Neispravni elementi za izbacivanje!");
    //
    std::queue<std::pair<Boje, std::string>> red;
    
    int i(0);
    auto it = lista.begin();
    while (i < brojKarata && !lista.empty()) {
        for (int i = 0; i < korakRazbrajanja; i++) {
            it++;
            if (it == lista.end()) it = lista.begin();
        }
        i++;
        red.push(std::make_pair((*it).first, (*it).second));
        lista.remove(*it);
    }
    return red;
}

int main ()
{
	return 0;
}
