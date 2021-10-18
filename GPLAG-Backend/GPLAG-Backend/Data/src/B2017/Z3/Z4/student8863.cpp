#include <iostream>
#include <string>
#include <stdexcept>
#include <list>
#include <utility>
#include <map>
#include <algorithm>
#include <queue>

enum class Boje {Pik, Tref, Herc, Karo};

typedef std::list<std::pair<Boje, std::string>> Spil;
typedef std::queue<std::pair<Boje, std::string>> Red;

int VrijednostKarte(const std::string &karta) {
    if (karta == "2") return 1;
    else if (karta == "3") return 2;
    else if (karta == "4") return 3;
    else if (karta == "5") return 4;
    else if (karta == "6") return 5;
    else if (karta == "7") return 6;
    else if (karta == "8") return 7;
    else if (karta == "9") return 8;
    else if (karta == "10") return 9;
    else if (karta == "J") return 10;
    else if (karta == "Q") return 11;
    else if (karta == "K") return 12;
    else if (karta == "A") return 13;
    return 0;
}

Spil KreirajSpil() {
    Spil karte;
    const std::string vrijednost[13] {"2", "3", "4", "5", "6", "7", "8", "9",
        "10", "J", "Q", "K", "A"};
    for (int i = 0; i < 4; i++) 
        for (int j = 0; j < 13; j++) {
            if (i == 0) 
                karte.push_back(std::make_pair(Boje::Pik, vrijednost[j]));
            else if (i == 1)
                karte.push_back(std::make_pair(Boje::Tref, vrijednost[j]));
            else if (i == 2)
                karte.push_back(std::make_pair(Boje::Herc, vrijednost[j]));
            else 
                karte.push_back(std::make_pair(Boje::Karo, vrijednost[j]));
        }
    return karte;
}

template <typename Karte>
bool ProvjeraSpila(const Karte &spil) {
    if (spil.size() > 52) return false;
    bool ispravno(true);
    for_each(spil.begin(), spil.end(), [&ispravno](std::pair<Boje, std::string> karta) {
        if (!VrijednostKarte(karta.second)) ispravno = false;
    });
    if (!ispravno) return false;
    for (auto it1 = spil.begin(); it1 != spil.end(); it1++) 
        for (auto it2 = it1; it2 != spil.end(); it2++) 
            if (it1->first > it2->first 
            || (it1 != it2 && it1->first == it2->first 
            && VrijednostKarte(it1->second) >= VrijednostKarte(it2->second)))
                return false;
    return true;
}

void IzbaciKarte(Spil &spil, std::multimap<Boje, std::string> karte) {
    if (!ProvjeraSpila(spil)) throw std::logic_error("Neispravna lista!");
    for (auto it = karte.begin(); it != karte.end(); it++) {
        auto karta(std::find_if(spil.begin(), spil.end(), 
        [it] (std::pair<Boje, std::string> a) {
            return it->first == a.first && it->second == a.second;
        }));
        if (karta != spil.end()) {
            spil.erase(karta);
            karte.erase(it--);
        }
    }
}

Red IzbaciKarteRazbrajanjem(Spil &spil, short int r, int b) {
    if (!ProvjeraSpila(spil) || r < 1 || r > 52 || b < 1)
        throw std::logic_error("Neispravni elementi za izbacivanje!");
    Red izbacene;
    if (!spil.size()) return izbacene;
    auto karta(spil.begin());
    for (int br_izbacenih = 0; br_izbacenih < b; br_izbacenih++) {
        for (short int korak = 1; korak < r; korak++) {
            if (karta == spil.end()) karta = spil.begin();
            karta++;
        }
        izbacene.push(*karta);
        auto obrisi(karta);
        karta++;
        spil.erase(obrisi);
    }
    return izbacene;
}

void VratiPrvihNKarata(Spil &spil, Red &red, int n) {
    if (n < 0) throw std::domain_error("Broj n je besmislen!");
    if (n > red.size()) throw std::range_error("Nedovoljno karata u redu!");
    for (int i = 0; i < red.size(); i++) {
        if (!VrijednostKarte(red.front().second))
            throw std::logic_error("Neispravne karte!");
        red.push(red.front()); red.pop();
    }
    ProvjeraSpila(spil);
    int vel(red.size()), br_izbacenih(0);
    for (int i = 0; i < vel; i++) {
        if (br_izbacenih == n) break;
        if (!std::binary_search(spil.begin(), spil.end(), red.front())) {
            spil.push_back(red.front());
            red.pop(); br_izbacenih++;
        }
    }
    spil.sort([](std::pair<Boje, std::string> a, std::pair<Boje, std::string> b) {
        if (a.first == b.first) 
            return VrijednostKarte(a.second) < VrijednostKarte(b.second);
        return a.first < b.first;
    });
}

void IspisiZaBoju(const Spil &spil, Boje b) {
    for (auto it = spil.begin(); it != spil.end(); it++)
        if (it->first == b) std::cout << it->second << " ";
    std::cout << std::endl;
}

void IspisiSpil(const Spil &spil) {
    std::cout << "Pik: "; IspisiZaBoju(spil, Boje::Pik);
    std::cout << "Tref: "; IspisiZaBoju(spil, Boje::Tref);
    std::cout << "Herc: "; IspisiZaBoju(spil, Boje::Herc);
    std::cout << "Karo: "; IspisiZaBoju(spil, Boje::Karo);
}

int main ()
{
    short int r;
    std::cout << "Unesite korak razbrajanja: ";
    std::cin >> r;
    int b;
    std::cout << "Unesite broj karata koje zelite izbaciti: ";
    std::cin >> b;
    try {
        auto spil(KreirajSpil());
        auto izbacene(IzbaciKarteRazbrajanjem(spil, r, b));
        std::cout << "U spilu trenutno ima " << spil.size() << " karata, i to:" 
            << std::endl;
        IspisiSpil(spil);
        int n;
        std::cout << "Unesite broj karata koje zelite vratiti u spil: ";
        std::cin >> n;
        VratiPrvihNKarata(spil, izbacene, n);
        std::cout << "U spilu trenutno ima " << spil.size() << " karata, i to:"
            << std::endl;
        IspisiSpil(spil);
    }
    catch (std::domain_error e) {
        std::cout << "Izuzetak: " << e.what();
    }
    catch (std::range_error e) {
        std::cout << "Izuzetak: " << e.what();
    }
    catch (std::logic_error e) {
        std::cout << "Izuzetak: " << e.what();
    }
    catch (...) {}
	return 0;
}
