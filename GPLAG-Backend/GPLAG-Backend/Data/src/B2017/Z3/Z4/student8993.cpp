/B2017/2018: Zadaća 3, Zadatak 4
#include <iostream>
#include <list>
#include <string>
#include <set>

enum class Boje {Pik, Tref, Herc, Karo};


std::list<std::set<Boje>>KreirajSpil() {
    int i(0);
    std::list<std::set<Boje>>KreirajSpil() spil_karata;
    while (i<13) {
        spil_karata.push_back(std::set<Boje>{Boje(0), Boje(1), Boje(2), Boje(3)});
        i++;
    }
    return spil_karata;
}

void IzbaciKarte(std::list<std::set<Boje>> &spil_karata, std::multimap<Boje, std::string> &multimapa) {
    if (spil_karata.size()>52) throw std::logic_error ("Neispravna lista!");
     (int i=0; i<spil_karata.size(); i++) {
        if (spil_karata[i]==multimapa[i])
    }
}


int main () {
    try {
        int korak;
        std::cout<<"Unesite korak razbrajanja: ";
        std::cin>>korak
        std::cin.ignore(10000,'\n');
        int broj_karata;
        std::cout<<"Unesite broj karata koje zelite izbaciti: ";
        std::cin>>broj_karata;
        std::cin.ignore(10000,'\n');
        std::pair<int, int> par(korak, broj_karata);
        std::list<std::set<Boje>> lista(KreirajSpil());
        
    
    
	return 0;
}
