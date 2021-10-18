/B2017/2018: Zadaća 3, Zadatak 4
#include <iostream>
#include <list>
#include <string>
#include <utility>

enum class Boje {Pik, Tref, Herc, Karo};

std::list<std::pair<Boje,std::string>>KreirajSpil(){
    std::list<std::pair<Boje,std::string>>spil;
    for(int i=0; i<13; i++) {
        spil.push_back(std::set<Boje>{Boje(0), Boje(1), Boje(2), Boje(3)});
    }
    return spil;
}


int main ()
{
	return 0;
}
