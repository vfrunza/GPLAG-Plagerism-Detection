/B2017/2018: Zadaća 3, Zadatak 4
#include <iostream>
#include <list>
#include <utility>
#include <string>
#include <queue>
#include <map>
#include <stdexcept>

enum class Boje {Pik, Tref, Herc, Karo};

std::list<std::pair<Boje, std::string>> KreirajSpil() {
    std::list<std::pair<Boje, std::string>> Spil;
    
    const char* karte[13]{"2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K", "A"};
    
    for (int i=0; i<4; i++) {
        for (int j=0; j<13; j++) {
            Spil.push_back(std::make_pair(Boje(i), karte[j]));
        }
    }
    return Spil;
}

bool Prije(std::string s1, std::string s2) {
    
    const char* karte[13]{"2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K", "A"};
    bool ima_prvog(false);
    for (int i=0; i<13; i++) {
        if (s1==karte[i]) ima_prvog=true;
        if (s2==karte[i] && ima_prvog) return true;
    }
    return false;
}


bool Sortirani (std::list<std::pair<Boje, std::string>> &spil) {
    
    for (auto it=spil.begin(); it!=spil.end(); it++) {
        auto sljedeci(it); sljedeci++;
        if (sljedeci!=spil.end()) {
            if ((*it).first==(*sljedeci).first && (*it).second==(*sljedeci).second) return false;
            if (!(((*it).first==(*sljedeci).first && Prije((*it).second, (*sljedeci).second)) || int((*it).first)<int((*sljedeci).first))) return false;
        }
    }
    return true;
}

bool Besmisleni (std::string s1, std::string s2) {
    
    const char* karte[13]{"2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K", "A"};
    const char* boje[4]{"Pik", "Tref", "Herc", "Karo"};
    
    for (int i=0; i<4; i++) {
        for (int j=0; j<13; j++) {
            if (s1==boje[i] && s2==karte[j]) return false;
        }
    }
    return true;
}

bool Neispravna (std::list<std::pair<Boje, std::string>> &spil) {
    const char* boje[4]{"Pik", "Tref", "Herc", "Karo"};
    if (spil.size()>52) return true;
    if (!Sortirani(spil)) return true;
    for (auto it=spil.begin(); it!=spil.end(); it++) if (Besmisleni(boje[int((*it).first)], (*it).second)) return true;
    return false;
}

void IzbaciKarte(std::list<std::pair<Boje, std::string>> &spil, std::multimap<Boje, std::string> &multimapa) {
    
    if (Neispravna(spil)) throw std::logic_error("Neispravna lista!");
    
    for (auto it1=spil.begin(); it1!=spil.end(); it1++) {
        for (auto it2=multimapa.begin(); it2!=multimapa.end(); it2++) {
            
            if ((*it1).first==(*it2).first && (*it1).second==(*it2).second) {
                it1=spil.erase(it1);
                it2=multimapa.erase(it2);
                it1--;
                break;
            }
        }
    }
    return;
}

std::queue<std::pair<std::string, std::string>> IzbaciKarteRazbrajanjem (std::list<std::pair<Boje, std::string>> &spil, const short int &korak_razbrajanja, int &broj_karata) {
    
    if (korak_razbrajanja<1 || korak_razbrajanja>52 || broj_karata<1) throw std::logic_error("Neispravni elementi za izbacivanje!");
    if (Neispravna(spil)) throw std::logic_error("Neispravna lista!");
    
    const char* boje[4]{"Pik", "Tref", "Herc", "Karo"};
    
    std::queue<std::pair<std::string, std::string>> red;
    
    int brojac(1), br_karata(broj_karata);
    while (br_karata && spil.size()) {
    for (auto it=spil.begin(); it!=spil.end(); it++) {
        
        while (brojac!=korak_razbrajanja && it!=spil.end()) {
            brojac++;
            it++;
            if (it==spil.end() && brojac==korak_razbrajanja) { it=spil.begin(); }
            if (it==spil.end()) { it=spil.begin(); }
        }
        red.push(std::make_pair(boje[int((*it).first)], (*it).second));
        it=spil.erase(it); it--;
        if (spil.size()==0) break;
        br_karata--;
        if (br_karata==0) break;
        brojac=1;
    }
    }
    return red;
}

bool BesmislenRed (std::queue<std::pair<std::string, std::string>> red) {
    while (!red.empty()) {
        if (Besmisleni(red.front().first, red.front().second)) return true;
        red.pop();
    }
    return false;
}

void VratiPrvihNKarata (std::list<std::pair<Boje, std::string>> &spil, std::queue<std::pair<std::string, std::string>> &red, int n) {
    
    if (n>int(red.size())) throw std::range_error("Nedovoljno karata u redu!");
    if (n<0) throw std::domain_error("Broj n je besmislen!");
    if (Neispravna(spil)) throw std::logic_error("Neispravna lista!");
    if (BesmislenRed(red)) throw std::logic_error("Neispravne karte!");
    if (n==0 || red.empty()) return;
    
    const char* boje[4]{"Pik", "Tref", "Herc", "Karo"};
    int prvi_dio(0);
    
    std::pair<std::string, std::string> karta(red.front());
    for (int i=0; i<4; i++) if (karta.first==boje[i]) prvi_dio=i;
    
    if (!spil.size()) {
        spil.insert(spil.begin(), std::make_pair(Boje(prvi_dio), karta.second));
        n--;
    }
    
    while (n && !red.empty()) {
        
        karta=red.front();
        for (int i=0; i<4; i++) if (karta.first==boje[i]) prvi_dio=i;
        
        for (auto it=spil.begin(); it!=spil.end(); it++) {
            auto sljedeca(it); sljedeca++;
            
            if ((boje[int((*it).first)]==karta.first && (*it).second==karta.second)) {
                red.pop();
                break;
            }
            if (!((int((*it).first)==prvi_dio && Prije((*it).second, karta.second)) || int((*it).first)<prvi_dio) || sljedeca==spil.end()) {
                if (sljedeca==spil.end()) spil.insert(sljedeca, std::make_pair(Boje(prvi_dio), karta.second));
                else spil.insert(it, std::make_pair(Boje(prvi_dio), karta.second));
                red.pop();
                n--;
                it=spil.end(); it--;
            }
        }
    }
    return;
}

void Ispisi (std::list<std::pair<Boje, std::string>> &spil) {
    const char* boje[4]{"Pik", "Tref", "Herc", "Karo"};
    
    for (int i=0; i<4; i++) {
        std::cout << boje[i] << ": ";
        for (auto it=spil.begin(); it!=spil.end(); it++) {
            if (int((*it).first)==i) std::cout << (*it).second << " ";
        }
        std::cout << std::endl;
    }
    return;
} 

int main ()
{
    int n, b;
    short int r;
    std::cout << "Unesite korak razbrajanja: ";
    std::cin >> r;
    std::cout << "Unesite broj karata koje zelite izbaciti: ";
    std::cin >> b;
    
    try {
        auto spil(KreirajSpil());
        std::queue<std::pair<std::string, std::string>> red(IzbaciKarteRazbrajanjem(spil, r, b)); 
        std::cout << "U spilu trenutno ima " << spil.size() << " karata, i to:" << std::endl;
        Ispisi(spil);
        std::cout << "Unesite broj karata koje zelite vratiti u spil: ";
        std::cin >> n;
        VratiPrvihNKarata(spil, red, n);
        std::cout << "U spilu trenutno ima " << spil.size() << " karata, i to:" << std::endl;
        Ispisi(spil);
    }
    catch(std::exception &izuzetak) {
        std::cout << "Izuzetak: " << izuzetak.what();
    }
    
	return 0;
}