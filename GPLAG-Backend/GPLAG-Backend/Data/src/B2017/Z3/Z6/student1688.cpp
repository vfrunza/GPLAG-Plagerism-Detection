#include <iostream>
#include <list>
#include <stack>
#include <utility>
#include <set>
#include <vector>
#include <stdexcept>

enum class Boje {Herc, Karo, Pik, Tref};
std::vector<std::string> Boja {"Herc", "Karo", "Pik", "Tref"};
std::vector<std::string> NaziviKarata {"2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K", "A"};

std::list<std::set<Boje>> KreirajSpil(){
    std::list<std::set<Boje>> spil;
    for(int i(0); i < 13; i++){
        std::set<Boje> skup {Boje::Herc, Boje::Karo, Boje::Pik, Boje::Tref};
        spil.push_back(skup);
    }
    return spil;
}
std::stack<std::pair<std::string, std::string>> IzbaciKarte(std::list<std::set<Boje>> &spil, const std::pair<int,int> &par){
    if (par.first < 1 || par.first > 52 || par.second < 1) throw std::logic_error("Neispravni elementi za izbacivanje!");
    if(spil.size() != 13) throw std::logic_error("Neispravna lista!");
    std::stack<std::pair<std::string, std::string>> izbaceneKarte;
    int brojKarata(0);
    auto it = spil.begin();
    for(; it != spil.end(); it++)
        if((*it).empty() == false) break;
    if(it == spil.end()) return izbaceneKarte;
    it = spil.begin();
    int prolaz(0), karta(0);
    for(int i(1);; i++, it++, karta++){
        auto it1 = spil.begin();
        for(; it1 != spil.end(); it1++)
            if((*it1).empty() == false) break;
        if(it1 == spil.end()) return izbaceneKarte;
        
        if(it == spil.end()){
            it = spil.begin();
            karta = 0;
            prolaz++;
            if(prolaz == 4) prolaz = 0;
        }
        if(prolaz == 0 && (*it).count(Boje::Herc) == 0){
            i--;
        }
        else if(prolaz == 1 && (*it).count(Boje::Karo) == 0){
            i--;
        }
        else if(prolaz == 2 && (*it).count(Boje::Pik) == 0){
            i--;
        }
        else if(prolaz == 3 && (*it).count(Boje::Tref) == 0){
            i--;
        }
        if(i == par.first){
            if(prolaz == 0){
                if((*it).count(Boje::Herc) == 1){
                    izbaceneKarte.push(std::make_pair(Boja[0], NaziviKarata[karta]));
                    (*it).erase(Boje::Herc);
                    brojKarata++;
                }
            }
            else if(prolaz == 1){
                if((*it).count(Boje::Karo) == 1){
                    izbaceneKarte.push(std::make_pair(Boja[1], NaziviKarata[karta]));
                    (*it).erase(Boje::Karo);
                    brojKarata++;
                }
            }
            else if(prolaz == 2){
                if((*it).count(Boje::Pik) == 1){
                    izbaceneKarte.push(std::make_pair(Boja[2], NaziviKarata[karta]));
                    (*it).erase(Boje::Pik);
                    brojKarata++;
                }
            }
            else if(prolaz == 3){
                if((*it).count(Boje::Tref) == 1){
                    izbaceneKarte.push(std::make_pair(Boja[3], NaziviKarata[karta]));
                    (*it).erase(Boje::Tref);
                    brojKarata++;
                }
            }
            i = 0;
        }
        if(brojKarata == par.second) break;
    }
    return izbaceneKarte;
}
void VratiPosljednjihNKarata(std::list<std::set<Boje>> &spil, std::stack<std::pair<std::string, std::string>> &karte, int n){
    if(n > karte.size()) throw std::range_error("Nedovoljno karata u steku!");
    if(spil.size() != 13) throw std::logic_error("Neispravna lista!");
    while(n > 0){
        int brojac1(0), brojac2(0);
        if(karte.top().first == "Herc") brojac1 = 0; else if(karte.top().first == "Karo") brojac1 = 1;
        else if(karte.top().first == "Pik") brojac1 = 2; else if(karte.top().first == "Tref") brojac1 = 3;
        else throw std::logic_error("Neispravne karte!");
        
        if(karte.top().second == "2") brojac2 = 0; else if(karte.top().second == "3") brojac2 = 1;
        else if(karte.top().second == "4") brojac2 = 2; else if(karte.top().second == "5") brojac2 = 3;
        else if(karte.top().second == "6") brojac2 = 4; else if(karte.top().second == "7") brojac2 = 5;
        else if(karte.top().second == "8") brojac2 = 6; else if(karte.top().second == "9") brojac2 = 7;
        else if(karte.top().second == "10") brojac2 = 8; else if(karte.top().second == "J") brojac2 = 9;
        else if(karte.top().second == "Q") brojac2 = 10; else if(karte.top().second == "K") brojac2 = 11;
        else if(karte.top().second == "A") brojac2 = 12; else throw std::logic_error("Neispravne karte!");
        
        auto it = spil.begin();
        for(int i(0); i <= brojac2; i++, it++){
            if(i == brojac2){
                if(brojac1 == 0) {
                    if((*it).count(Boje::Herc) == 0) (*it).insert(Boje::Herc); }
                else if(brojac1 == 1) {
                    if((*it).count(Boje::Karo) == 0) (*it).insert(Boje::Karo); }
                else if(brojac1 == 2) {
                    if((*it).count(Boje::Pik) == 0) (*it).insert(Boje::Pik); }
                else if(brojac1 == 3) {
                    if((*it).count(Boje::Tref) == 0) (*it).insert(Boje::Tref); }
            }
        }
        karte.pop();
        n--;
    }
}
int PrebrojiKarte(const std::list<std::set<Boje>> &spil) {
    if(spil.size() != 13) throw std::logic_error("Neispravna lista!");
    int brojac(0);
    for(auto it = spil.begin(); it != spil.end(); it++)
        brojac += (*it).size();
    return 52 - brojac;
}

int main() {
    auto spil = KreirajSpil();
    int korak, brojKarataIzbaciti, brojKarataVratiti;
    std::cout << "Unesite korak razbrajanja: ";
    std::cin >> korak;
    std::cout << "Unesite broj karata koje zelite izbaciti: ";
    std::cin >> brojKarataIzbaciti;
    try {
        auto stek = IzbaciKarte(spil, std::make_pair(korak, brojKarataIzbaciti));
        std::cout << "U spilu trenutno ima: " << 52 - PrebrojiKarte(spil) << " karata, i to:\n";
        std::cout << "Herc:"; int brojac(0);
        for(auto it = spil.begin(); it != spil.end(); it++, brojac++)
            if((*it).count(Boje::Herc) == 1) std::cout << " " << NaziviKarata[brojac];
        std::cout << "\nKaro:"; brojac = 0;
        for(auto it = spil.begin(); it != spil.end(); it++, brojac++)
            if((*it).count(Boje::Karo) == 1) std::cout << " " << NaziviKarata[brojac];
        std::cout << "\nPik: "; brojac = 0;
        for(auto it = spil.begin(); it != spil.end(); it++, brojac++)
            if((*it).count(Boje::Pik) == 1) std::cout << " " << NaziviKarata[brojac];
        std::cout << "\nTref:"; brojac = 0;
        for(auto it = spil.begin(); it != spil.end(); it++, brojac++)
            if((*it).count(Boje::Tref) == 1) std::cout << " " << NaziviKarata[brojac];
        std::cout << "\nUnesite broj karata koje zelite vratiti u spil: ";
        std::cin >> brojKarataVratiti;
        VratiPosljednjihNKarata(spil, stek, brojKarataVratiti);
       // std::cout << "Broj karata u steku: " << stek.size() << std::endl;
      //  std::cout << "Trenutne karte u steku:\n";
        while(!stek.empty()){
            std::cout << stek.top().first << " " << stek.top().second << std::endl;
            stek.pop();
        }
    }
    catch(std::logic_error e) {
        std::cout << "Izuzetak: " << e.what();
    }
    catch(std::range_error e) {
        std::cout << "Izuzetak: " << e.what();
    }
    return 0;
}