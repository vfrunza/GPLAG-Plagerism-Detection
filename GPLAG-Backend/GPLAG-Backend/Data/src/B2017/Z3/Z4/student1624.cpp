/B2017/2018: Zadaća 3, Zadatak 4
#include <iostream>
#include <vector>
#include <list>
#include <map>
#include <algorithm>
#include <string>
#include <queue>

enum class Boje
{
    Pik, Tref, Herc, Karo
};
typedef std::list<std::pair<Boje, std::string>> Spil;
typedef std::pair<Boje, std::string> Karta;

const std::vector<std::string> vrijednosti = {"2","3","4","5","6","7","8","9","10","J","Q","K","A"};

Boje StringUBoju(std::string s)
{
    if(s=="pik") return Boje::Pik;
    else if(s=="tref") return Boje::Tref;
    else if(s=="herc") return Boje::Herc;
    else return Boje::Karo;
}

std::string BojaUString(Boje boja)
{
    if(boja == Boje::Pik) return "pik";
    else if(boja == Boje::Tref) return "tref";
    else if(boja == Boje::Herc) return "herc";
    else return "karo";
}

Spil KreirajSpil()
{
    Spil s;

    std::vector<Boje> boje = {Boje::Pik, Boje::Tref, Boje::Herc, Boje::Karo};

    for(auto boja : boje)
        for(auto vrijednost : vrijednosti)
            s.push_back(Karta(boja,vrijednost));

    return s;
}

void IspisiSpil(Spil spil)
{
    std::cout << "U spilu trenutno ima " << spil.size() << " karata, i to:" << std::endl;

    std::cout << "Pik: ";
    for(auto karta : spil) {
        if(BojaUString(karta.first)=="pik")
            std::cout << karta.second << " ";
    }
    std::cout << std::endl;
    std::cout << "Tref: ";
    for(auto karta : spil) {
        if(BojaUString(karta.first)=="tref")
            std::cout << karta.second << " ";
    }
    std::cout << std::endl;
    std::cout << "Herc: ";
    for(auto karta : spil) {
        if(BojaUString(karta.first)=="herc")
            std::cout << karta.second << " ";
    }
    std::cout << std::endl;
    std::cout << "Karo: ";
    for(auto karta : spil) {
        if(BojaUString(karta.first)=="karo")
            std::cout << karta.second << " ";
    }
    std::cout << std::endl;
}

bool KartaComp(Karta a, Karta b)
{
    if (int(a.first) == int(b.first)) {
        if(a.second == b.second) return false;
        return std::find(vrijednosti.begin(), vrijednosti.end(), a.second)<std::find(vrijednosti.begin(), vrijednosti.end(), b.second);
    };
    return int(a.first) < int(b.first);
}

bool IspravnaKarta(Karta karta)
{
    return std::find(vrijednosti.begin(), vrijednosti.end(), karta.second)!=vrijednosti.end();
}

bool IspravanSpil(Spil spil)
{
    for(auto karta : spil) {
        if(!IspravnaKarta(karta)) return false;
    }
    return spil.size()<=52 && std::is_sorted(spil.begin(), spil.end(), KartaComp) && std::adjacent_find(spil.begin(), spil.end())==spil.end();
}

void IzbaciKarte(Spil &spil, std::multimap<Boje, std::string> karte)
{
    if(!IspravanSpil(spil)) throw std::logic_error("Neispravna lista!");

    auto it = karte.begin();

    while(it != karte.end() && spil.size()>0) {
        if(std::find_if(spil.begin(), spil.end(), [it](Karta k) {
        return int(k.first) == int(it->first) && k.second == it->second;
        })!=spil.end()) {
            spil.remove(*it);
            it=karte.erase(it);
            continue;
        }
        it++;
    }
    return;
}

std::queue<std::pair<std::string, std::string>>IzbaciKarteRazbrajanjem(Spil &spil, const short int &r, const int &b)
{
    if(!IspravanSpil(spil)) throw std::logic_error("Neispravna lista!");
    if(r<1 || r>52 || b<1) throw std::logic_error("Neispravni elementi za izbacivanje!");

    std::queue<std::pair<std::string, std::string>> red;
    std::multimap<Boje, std::string> karte;

    int i=0;
    auto it = spil.begin();

    while(i<b && red.size()<spil.size()) {
        bool wrap = false;
        for(int j=1; j<r; j++) {
            if(it==spil.end()) {
                it=spil.begin();
                it++;
                wrap=true;
            } else it++;
        }
        if(it==spil.end()) {
            it=spil.begin();
            it++;
            wrap=true;
        }

        karte.insert(*it);
        red.push(std::pair<std::string, std::string>(BojaUString(it->first), it->second));
        i++;
        if(wrap) it++;
        it++;
    }

    try {
        IzbaciKarte(spil, karte);
    } catch(...) {
        throw;
    }
    return red;
}

void VratiPrvihNKarata(Spil &spil, std::queue<std::pair<std::string, std::string>> &red, int n)
{
    if(n<0) throw std::domain_error("Broj n je besmislen!");
    if(n>red.size()) throw std::range_error("Nedovoljno karata u redu!");
    if(!IspravanSpil(spil)) throw std::logic_error("Neispravna lista!");

    std::vector<std::string> boje = {"Pik", "Tref", "Herc", "Karo"};

    while(red.size()>0 && n>0) {
        auto karta = Karta(StringUBoju(red.front().first), red.front().second);
        if(!IspravnaKarta(karta)) throw std::logic_error("Neispravne karte!");

        if(std::find_if(spil.begin(), spil.end(), [&](Karta k) {
        return int(k.first) == int(karta.first) && k.second == karta.second;
        })==spil.end()) {
            spil.insert(std::upper_bound(spil.begin(), spil.end(), karta, KartaComp), karta);
            n--;
        }
        red.pop();
    }
}

int main ()
{
    Spil spil = KreirajSpil();

    int r, b;
    std::cout << "Unesite korak razbrajanja: ";
    std::cin >> r;
    std::cout << "Unesite broj karata koje zelite izbaciti: ";
    std::cin >> b;

    try {
        auto red = IzbaciKarteRazbrajanjem(spil, r, b);
        IspisiSpil(spil);

        std::cout << "Unesite broj karata koje zelite vratiti u spil: ";
        std::cin >> r;

        VratiPrvihNKarata(spil, red, r);
        IspisiSpil(spil);

    } catch(std::logic_error izuzetak) {
        std::cout << "Izuzetak: " << izuzetak.what() << std::endl;
    } catch(std::range_error izuzetak) {
        std::cout << "Izuzetak: " << izuzetak.what() << std::endl;
    }

    return 0;
}
