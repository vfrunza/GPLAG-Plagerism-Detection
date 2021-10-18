/B2017/2018: Zadaća 3, Zadatak 4
#include <iostream>
#include <list>
#include <utility>
#include <string>
#include <map>
#include <stdexcept>
#include <queue>

enum class Boje { Pik, Tref, Herc, Karo };

std::list<std::pair<Boje, std::string>> KreirajSpil() {
    std::list<std::pair<Boje, std::string>> Spil(52);
    auto it(Spil.begin());
    int i{1};
    while(it != Spil.end() && i <=4) {
        if(i == 1) {
            for(int j=0; j<13; j++) {
                it->first = Boje::Pik;
                if(j<9) it->second = std::to_string(j+2);
                else if(j == 9) (*it).second = 'J';
                else if(j == 10) (*it).second = 'Q';
                else if(j == 11) (*it).second = 'K';
                else if(j == 12) (*it).second = 'A';
                it++;
            }
        }
        if(i == 2) {
            for(int j=0; j<13; j++) {
                (*it).first = Boje::Tref;
                if(j<9) (*it).second = std::to_string(j+2);
                else if(j == 9) (*it).second = 'J';
                else if(j == 10) (*it).second = 'Q';
                else if(j == 11) (*it).second = 'K';
                else if(j == 12) (*it).second = 'A';
                it++;
            }
        }
        if(i == 3) {
            for(int j=0; j<13; j++) {
                (*it).first = Boje::Herc;
                if(j<9) (*it).second = std::to_string(j+2);
                else if(j == 9) (*it).second = 'J';
                else if(j == 10) (*it).second = 'Q';
                else if(j == 11) (*it).second = 'K';
                else if(j == 12) (*it).second = 'A';
                it++;
            }
        }
        if(i == 4) {
            for(int j=0; j<13; j++) {;
                it->first = Boje::Karo;
                if(j<9) it->second = std::to_string(j+2);
                else if(j == 9) it->second = 'J';
                else if(j == 10) it->second = 'Q';
                else if(j == 11) it->second = 'K';
                else if(j == 12) it->second = 'A';
                it++;
            }
        }
        i++;
    }
    return Spil;
}

void Vrijednost(int &vrij, int &vrij2, std::string it, std::string R) {
    if(it == "2") vrij=1;
    else if(it == "3") vrij=2;
    else if(it == "4") vrij=3;
    else if(it == "5") vrij=4;
    else if(it == "6") vrij=5;
    else if(it == "7") vrij=6;
    else if(it == "8") vrij=7;
    else if(it == "9") vrij=8;
    else if(it == "10") vrij=9;
    else if(it == "J") vrij=10;
    else if(it == "Q") vrij=11;
    else if(it == "K") vrij=12;
    else if(it == "A") vrij=13;
                
    if(R == "2") vrij2=1;
    else if(R == "3") vrij2=2;
    else if(R == "4") vrij2=3;
    else if(R == "5") vrij2=4;
    else if(R == "6") vrij2=5;
    else if(R == "7") vrij2=6;
    else if(R == "8") vrij2=7;
    else if(R == "9") vrij2=8;
    else if(R == "10") vrij2=9;
    else if(R == "J") vrij2=10;
    else if(R == "Q") vrij2=11;
    else if(R == "K") vrij2=12;
    else if(R == "A") vrij2=13;
}

void Provjera(std::list<std::pair<Boje, std::string>> S) {
    if(S.size() > 52) throw std::logic_error("Neispravna lista!");
    auto it(S.begin());
    while(it != S.end()) {
        auto it2(it);
        while(it2 != S.end()) {
            if(it->first > it2->first) throw std::logic_error("Neispravna lista!");
            if(it->first == it2->first) {
                if(( it->second == "2" || it->second == "3" || it->second == "4" || it->second == "5" || it->second == "6" || it->second == "7" || it->second == "8" ||
                   it->second == "9" || it->second == "10" || it->second == "J" || it->second == "Q" || it->second == "K" || it->second == "A") && 
                    (it2->second == "2" || it2->second == "3" || it2->second == "4" || it2->second == "5" || it2->second == "6" || it2->second == "7" || it2->second == "8" ||
                     it2->second == "9" || it2->second == "10" || it2->second == "J" || it2->second == "Q" || it2->second == "K" || it2->second == "A")) {
                        int vrij{0}, vrij2{0};
                        Vrijednost(vrij, vrij2, it->second, it2->second);
                        if(vrij > vrij2) throw std::logic_error("Neispravna lista!");
                }
                else throw std::logic_error("Neispravna lista!");
            }
            it2++;
        }
        it++;
    }
}

void IzbaciKarte(std::list<std::pair<Boje, std::string>> &S, std::multimap<Boje, std::string> &M) {
    Provjera(S);
    auto itmap(M.begin());
    auto it(S.begin());
    while(itmap != M.end()) {
        while(it != S.end()) {
            if(itmap->first == it->first && itmap->second == it->second) {
                itmap=M.erase(itmap);
                it=S.erase(it);
                it=S.begin();
            }
            else it++;
        }
        itmap++;
    }
    
}

std::queue<std::pair<std::string, std::string>> IzbaciKarteRazbrajanjem(std::list<std::pair<Boje, std::string>> &S, const short int &r, const int &b) {
    if(r < 1 || r > 52 || b < 1) throw std::logic_error("Neispravni elementi za izbacivanje!");
    Provjera(S);
    auto it(S.begin());
    int brojac{1}, jelb{0};
    std::queue<std::pair<std::string, std::string>> VRATI;
    while(it != S.end()) {
        if(brojac >= r && brojac%r == 0) {
            std::string upisBoje;
            if(it->first == Boje::Pik) upisBoje="Pik";
            else if(it->first == Boje::Tref) upisBoje="Tref";
            else if(it->first == Boje::Herc) upisBoje="Herc";
            else if(it->first == Boje::Karo) upisBoje="Karo";
            VRATI.push(std::pair<std::string, std::string>(upisBoje, it->second));
            it=S.erase(it);
            jelb++;
            if(jelb == b) break;
        }
        else it++;
        brojac++;
        if(it == S.end()) it=S.begin();
    }
    return VRATI;
}

void VratiPrvihNKarata(std::list<std::pair<Boje, std::string>> &S, std::queue<std::pair<std::string, std::string>> &R, int n) {
    Provjera(S);
    if(n < 0) throw std::domain_error("Broj n je besmislen!");
    if(n > R.size()) throw std::range_error("Nedovoljno karata u redu!");
    for(int i=0; i<n; i++) {
        Boje bojko;
        if((R.front()).first == "Pik") bojko=Boje::Pik;
        else if((R.front()).first == "Tref") bojko=Boje::Tref;
        else if((R.front()).first == "Herc") bojko=Boje::Herc;
        else if((R.front()).first == "Karo") bojko=Boje::Karo;
        else throw std::logic_error("Neispravne karte!");
        if((R.front()).second=="2"||(R.front()).second=="3"||(R.front()).second=="4"||(R.front()).second=="5"||(R.front()).second=="6"||(R.front()).second=="7"||(R.front()).second=="8"
           ||(R.front()).second=="9"||(R.front()).second=="10"||(R.front()).second=="J"||(R.front()).second=="Q"||(R.front()).second=="K"||(R.front()).second=="A") {
            auto it(S.begin());
            bool ImalGa{false};
            while(it != S.end() && !ImalGa) {
                if(it->first == bojko && it->second == (R.front()).second)  ImalGa=true;
                it++;
            }
            if(!ImalGa) {
                it=S.begin();
                bool PrijeManji{false};
                while(it != S.end()) {
                    if(it->first == bojko) {
                        int vrij{0}, vrij2{0};
                        Vrijednost(vrij, vrij2, it->second, (R.front()).second);
                        auto pomit(it);
                        pomit++;
                        if(vrij2 < vrij && !PrijeManji) {
                            PrijeManji=false;
                            S.insert(it, std::pair<Boje, std::string>(bojko, (R.front()).second));
                            break;
                        }
                        else if(vrij2 > vrij && PrijeManji && (pomit==S.end() || pomit->first!=bojko)) {
                            PrijeManji=false;
                            S.insert(pomit, std::pair<Boje, std::string>(bojko, (R.front()).second));
                            break;
                        }
                        else if(vrij2 < vrij && PrijeManji && it != S.begin()) {
                            S.insert(it, std::pair<Boje, std::string>(bojko, (R.front()).second));
                            PrijeManji=false;
                            break;
                        }
                        else if(vrij2 > vrij) PrijeManji=true;
                    }
                    it++;
                }
            }
        }
        else throw std::logic_error("Neispravne karte!");
        R.pop();
    }
}

void ISPISI(std::list<std::pair<Boje, std::string>> SPIL) {
    std::cout << "U spilu trenutno ima " << SPIL.size() << " karata, i to:" << std::endl;
    auto itspil(SPIL.begin());
    std::cout << "Pik: ";
    while(itspil != SPIL.end() && itspil->first == Boje::Pik) {
        std::cout << itspil->second << " ";
        itspil++;
    }
    std::cout << std::endl << "Tref: ";
    while(itspil != SPIL.end() && itspil->first == Boje::Tref) {
    std::cout << itspil->second << " ";
        itspil++;
    }
    std::cout << std::endl << "Herc: ";
    while(itspil != SPIL.end() && itspil->first == Boje::Herc) {
        std::cout << itspil->second << " ";
        itspil++;
    }
    std::cout << std::endl << "Karo: ";
    while(itspil != SPIL.end() && itspil->first == Boje::Karo) {
        std::cout << itspil->second << " ";
        itspil++;
    }
    std::cout << std::endl;
}

int main () {
    std::cout << "Unesite korak razbrajanja: ";
    short int r;
    std::cin >> r;
    std::cout << "Unesite broj karata koje zelite izbaciti: ";
    int n;
    std::cin >> n;
    try {
        std::list<std::pair<Boje, std::string>> SPIL{ KreirajSpil() };
        std::queue<std::pair<std::string, std::string>> RED;
        RED=IzbaciKarteRazbrajanjem(SPIL, r, n);
        ISPISI(SPIL);
        std::cout << "Unesite broj karata koje zelite vratiti u spil: ";
        std::cin >> n;
        VratiPrvihNKarata(SPIL, RED, n);
        ISPISI(SPIL);
    }
    catch(std::logic_error izuzetak) {
        std::cout << "Izuzetak: " << izuzetak.what();
    }
    catch(std::range_error izuzetak) {
        std::cout << "Izuzetak: " << izuzetak.what();
    }
	return 0;
}
