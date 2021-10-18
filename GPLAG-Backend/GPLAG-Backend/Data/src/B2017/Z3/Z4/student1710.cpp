#include <iostream>
#include <list>
#include <utility>
#include <string>
#include <map>
#include <stdexcept>
#include <queue>
#include <iterator>

enum class Boje {Pik, Tref, Herc, Karo};

std::list<std::pair<Boje, std::string> >KreirajSpil(){
    
    Boje boja(Boje::Pik);
    std::pair<Boje, std::string> Par;
    std::string vrijednost;
    std::list<std::pair<Boje, std::string>> vracena_lista;
    int brojac(2);
    for (int i = 1; i <=52; i++) {
        if (i>13) boja=Boje::Tref;
        if (i>26) boja=Boje::Herc;
        if (i>39) boja=Boje::Karo;
        
        if (i==14 || i==27 || i==40) brojac=2;
        
        vrijednost= std::to_string(brojac);
        if( i== 10 || i== 23 || i==36 || i==49) vrijednost= "J";
        if( i== 11 || i== 24 || i==37 || i==50) vrijednost= "Q";
        if( i== 12 || i== 25 || i==38 || i==51) vrijednost= "K";
        if( i== 13 || i== 26 || i==39 || i==52) vrijednost= "A";
        Par.first = boja;
        Par.second= (vrijednost);
        vracena_lista.push_back(Par);
        brojac++;
    }
    
    return vracena_lista;
}


void IzbaciKarte(std::list<std::pair<Boje, std::string>> &Spil, std::multimap<Boje, std::string> &Mapa){
    for (auto i = Spil.begin(); i != Spil.end(); i++) {
        for (auto j = Mapa.begin(); j != Mapa.end(); j++) {
            if ((i->first == j->first ) && (i->second == j->second)) {
                i=Spil.erase(i);
                //Mapa.erase(j);
            }
        }    
    }
    
}

std::queue<std::pair<Boje, std::string>> IzbaciKarteRazbrajanjem(std::list<std::pair<Boje, std::string>> &Spil, const short int R, const int B){
    auto it(Spil.begin());
    std::queue<std::pair<Boje, std::string>> vraceni_kju;
    int brojac(0);
    while (brojac!=B) {
        while (it!=Spil.end() && ) {
            
        }
        std::advance(it,R-1);
        vraceni_kju.push(*it);
        it=Spil.erase(it);
        brojac++;
        if (it->first==Boje::Karo)it++;
        
    }
    return vraceni_kju;
}

int main ()
{
    std::list<std::pair<Boje, std::string>> Spil;
    Spil = KreirajSpil();
    int R, B;
    std::cout<<"Unesite korak razbrajanja: ";
    std::cin>>R;
    std::cout << "Unesite broj karata koje zelite izbaciti: ";
    std::cin>>B;
    std::cout<<"U spilu trenutno ima "<<52-B<< " karata, i to: "<<std::endl; 
    auto nesto = IzbaciKarteRazbrajanjem(Spil, R, B);
    auto i = Spil.begin();
        if (i->first == Boje::Pik && i  != Spil.end()) std::cout << "Pik:";
        while (i->first==Boje::Pik && i  != Spil.end())  {
            std::cout<< " " << i->second;
            i++;
        }
        if (i->first == Boje::Tref && i != Spil.end()) std::cout << "\nTref:";
        while (i->first==Boje::Tref && i != Spil.end()) {
            std::cout << " "<< i->second;
            i++;
        }
        if (i->first == Boje::Herc && i != Spil.end()) std::cout << "\nHerc:";
        while (i->first == Boje::Herc && i != Spil.end()) {
            std::cout<< " "<<i->second;
            i++;
        }
        if (i->first == Boje::Karo && i != Spil.end()) std::cout << "\nKaro:";
        while (i->first==Boje::Karo && i != Spil.end()) {
            std::cout<<" " <<i->second;
            i++;
        }
	return 0;
}
