/B2017/2018: Zadaća 3, Zadatak 4
#include <iostream>
#include <list>
#include <map>
#include <string>
#include <utility>
#include <vector>

enum class Boje {Pik, Tref, Herc, Karo};
std::vector<std::string> Vrijednost {"2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K", "A"};

typedef std::list<std::pair<Boje, std::string>> Spil;

Spil KreirajSpil(){
    Spil spil;
    for (int i = 0; i < 13; i++) spil.push_back({Boje::Pik, Vrijednost.at(i)});
    for (int i = 0; i < 13; i++) spil.push_back({Boje::Tref, Vrijednost.at(i)});
    for (int i = 0; i < 13; i++) spil.push_back({Boje::Herc, Vrijednost.at(i)});
    for (int i = 0; i < 13; i++) spil.push_back({Boje::Karo, Vrijednost.at(i)});
    return spil;
}

void IzbaciKarte (Spil &spil, std::multimap<Boje, std::string> &m){
    for(auto it = m.begin(); it != m.end(); it++){
        for(auto it1 = spil.begin(); it1 != spil.end(); it1++){
            if ((*it).first == *i) {
            }
        }
    }
}

int main ()
{
    Spil s;
	return 0;
}
