/B2017/2018: Zadaća 3, Zadatak 4
#include <iostream>
#include <list>
#include <stdexcept>
#include <utility>
#include <map>
#include <string>
#include <vector>
#include <algorithm>

enum class Boje {Pik, Tref, Herc, Karo};
std::vector<std::string> nazivi{"2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K", "A"};

std::list<std::pair<Boje, std::string>> KreirajSpil() {
    std::list<std::pair<Boje, std::string>> spil;
    for(std::string x : nazivi) {
        spil.push_back(std::make_pair(Boje::Pik, x));
    }
    for(std::string x : nazivi) {
        spil.push_back(std::make_pair(Boje::Tref, x));
    }
    for(std::string x : nazivi) {
        spil.push_back(std::make_pair(Boje::Herc, x));
    }
    for(std::string x : nazivi) {
        spil.push_back(std::make_pair(Boje::Karo, x));
    }
    return spil;
}

bool Kriterij(const std::pair<Boje, std::string> &prvi, const std::pair<Boje, std::string> &drugi) {
    if(prvi.first > drugi.first) return false;
    if(prvi.first == drugi.first) {
        int indeksPrvi, indeksDrugi;
        for(int i(0); i < nazivi.size(); i++) {
            if(nazivi.at(i) == prvi.second) indeksPrvi = i;
            if(nazivi.at(i) == drugi.second) indeksDrugi = i;
        }
        if(indeksPrvi > indeksDrugi) return false;
    }
    return true;
}

bool ProvjeriSpil(const std::list<std::pair<Boje, std::string>> &spil) {
    if(spil.size() > 52) return false;
    for(std::pair<Boje, std::string> par : spil) {
        bool ok(false);
        for(auto naziv : nazivi) {
            if(par.second == naziv) ok = true;
        }
        if(ok == false) return false;
    }
    std::list<std::pair<Boje, std::string>> spil2 = spil;
    spil2.sort(Kriterij);
    auto it2 = spil2.begin();
    for(auto it(spil.begin()); it != spil.end(); it++) {
        if(it->first != it2->first && it->second != it2->second) return false;
        it2++;
    }
    return true;
}

void IzbaciKarte(std::list<std::pair<Boje, std::string>> &spil, std::multimap<Boje, std::string> &mapa) {
    if(ProvjeriSpil(spil) == false) throw std::logic_error("Neispravna lista!");
    for(auto it(mapa.begin()); it != mapa.end();) {
        std::pair<Boje, std::string> karta = *it;
        auto itSpil = std::find_if(spil.begin(), spil.end(), [karta] (const std::pair<Boje, std::string> &par) { if(karta.first == par.first && karta.second == par.second) return true; return false; });
        if(itSpil == spil.end()) it++;
        else {
            spil.erase(itSpil);
            it = mapa.erase(it);
        }
    }
}

int main () {
	return 0;
}
