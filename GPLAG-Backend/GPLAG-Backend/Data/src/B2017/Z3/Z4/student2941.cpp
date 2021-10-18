/B2017/2018: Zadaća 3, Zadatak 4
#include <iostream>
#include <list>
#include <utility>
#include <map>
#include <vector>
#include <queue>
#include <iterator>
#include <algorithm>

enum class Boje {
    Pik, Tref, Herc, Karo
};

std::vector<std::string> imena_boja{"Pik", "Tref", "Herc", "Karo"};
std::vector<std::string> imena_karata{"2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K", "A"};

bool KriterijZaProvjeru(std::pair<Boje, std::string> prvi, std::pair<Boje, std::string> drugi) {
        return (prvi.first<drugi.first 
        || prvi.first==drugi.first && std::find(imena_karata.begin(), imena_karata.end(), prvi.second)
        <std::find(imena_karata.begin(), imena_karata.end(), drugi.second));
    }

std::list<std::pair<Boje, std::string>> KreirajSpil() {
    std::list<std::pair<Boje, std::string>> spil_karata;
    for (int i=0; i<4; i++) {
        for (std::string ime_karte : imena_karata) {
            spil_karata.push_back(std::make_pair(Boje(i), ime_karte));
        }
    }
    return spil_karata;
}

void IzbaciKarte
(std::list<std::pair<Boje, std::string>> &spil_karata, std::multimap<Boje, std::string> &multi) {
    if (spil_karata.size()>52) throw std::logic_error("Neispravna lista!");
    bool besmisleni(false);
    for (auto it=spil_karata.begin(); it!=spil_karata.end(); it++) {
        if ((it->first!=Boje::Pik && it->first!=Boje::Tref && it->first!=Boje::Herc && it->first!=Boje::Karo) 
        || (std::find(imena_karata.begin(), imena_karata.end(), it->second)==imena_karata.end())) {
            besmisleni=true;
            break;
        }
    }
    if (besmisleni) throw std::logic_error("Neispravna lista!");
    bool sortirana(true);
    auto kraj=spil_karata.end();
    kraj--;
    for (auto it=spil_karata.begin(); it!=kraj; it++) {
        it++;
        auto sljedeci=it;
        it--;
        if (!KriterijZaProvjeru(*it, *sljedeci)) {
            sortirana=false;
            break;
        }
    }
    if (!sortirana) throw std::logic_error("Neispravna lista!");
    for (auto it=spil_karata.begin(); it!=spil_karata.end(); it++) {
        bool u_oba_kontejnera(false);
        std::multimap<Boje, std::string>::iterator it_map;
        for (it_map=multi.begin(); it_map!=multi.end(); it_map++) {
            if (*it==std::make_pair(it_map->first, it_map->second)) {
                u_oba_kontejnera=true;
                break;
            }
        }
        if (u_oba_kontejnera) {
            it_map=multi.erase(it_map);
            it=spil_karata.erase(it);
            it--;
        }
    }
}

std::queue<std::pair<std::string, std::string>> IzbaciKarteRazbrajanjem
(std::list<std::pair<Boje, std::string>> &spil_karata, const short int &korak_raz, const int &cijeli) {
    if (korak_raz<1 || korak_raz>52) throw std::logic_error("Neispravni elementi za izbacivanje!");
    if (cijeli<1) throw std::logic_error("Neispravni elementi za izbacivanje!");
    if (spil_karata.size()>52) throw std::logic_error("Neispravna lista!");
    bool besmisleni(false);
    for (auto it=spil_karata.begin(); it!=spil_karata.end(); it++) {
        if ((it->first!=Boje::Pik && it->first!=Boje::Tref && it->first!=Boje::Herc && it->first!=Boje::Karo) 
        || (std::find(imena_karata.begin(), imena_karata.end(), it->second)==imena_karata.end())) {
            besmisleni=true;
            break;
        }
    }
    if (besmisleni) throw std::logic_error("Neispravna lista!");
    bool sortirana(true);
    auto kraj=spil_karata.end();
    kraj--;
    for (auto it=spil_karata.begin(); it!=kraj; it++) {
        it++;
        auto sljedeci=it;
        it--;
        if (!KriterijZaProvjeru(*it, *sljedeci)) {
            sortirana=false;
            break;
        }
    }
    if (!sortirana) throw std::logic_error("Neispravna lista!");
    std::queue<std::pair<std::string, std::string>> red;
    std::list<std::pair<Boje, std::string>>::iterator it;
    it=spil_karata.begin();
    int duzina(spil_karata.size());
    short int mjesto(-1);
    int broj_puta(0);
    for (int i=0; i<cijeli; i++) {
        mjesto+=korak_raz;
        if (mjesto>=duzina) {
            std::advance(it, korak_raz-1-duzina+broj_puta);
            mjesto-=duzina;
        }
        else std::advance(it, korak_raz-1);
        red.push(std::make_pair(imena_boja.at(int(it->first)), it->second));
        it=spil_karata.erase(it);
        broj_puta++;
        if (spil_karata.size()==0) break;
    }
    return red;
}

void VratiPrvihNKarata
(std::list<std::pair<Boje, std::string>> &spil_karata, std::queue<std::pair<std::string, std::string>> &red, int n) {
    if (n<0) throw std::domain_error("Broj n je besmislen!");
    if (n>red.size()) throw std::range_error("Nedovoljno karata u redu!");
    bool besmislene_karte(false);
    for (int i=0; i<red.size(); i++) {
        if (std::find(imena_boja.begin(), imena_boja.end(), red.front().first)==imena_boja.end()) {
            besmislene_karte=true;
            break;
        }
        if (std::find(imena_karata.begin(), imena_karata.end(), red.front().second)==imena_karata.end()) {
            besmislene_karte=true;
            break;
        }
        red.push(red.front());
        red.pop();
    }
    if (besmislene_karte) throw std::logic_error("Neispravne karte!");
    if (spil_karata.size()>52) throw std::logic_error("Neispravna lista!");
    bool besmisleni(false);
    for (auto it=spil_karata.begin(); it!=spil_karata.end(); it++) {
        if ((it->first!=Boje::Pik && it->first!=Boje::Tref && it->first!=Boje::Herc && it->first!=Boje::Karo) 
        || (std::find(imena_karata.begin(), imena_karata.end(), it->second)==imena_karata.end())) {
            besmisleni=true;
            break;
        }
    }
    if (besmisleni) throw std::logic_error("Neispravna lista!");
    bool sortirana(true);
    auto kraj=spil_karata.end();
    kraj--;
    for (auto it=spil_karata.begin(); it!=kraj; it++) {
        it++;
        auto sljedeci=it;
        it--;
        if (!KriterijZaProvjeru(*it, *sljedeci)) {
            sortirana=false;
            break;
        }
    }
    if (!sortirana) throw std::logic_error("Neispravna lista!");
    int redni_broj(0);
    for (int i=0; i<n; i++) {
        for (int i=0; i<imena_boja.size(); i++) {
            if (red.front().first==imena_boja.at(i)) {
                redni_broj=i;
                break;
            }
        }
        bool pronadjena(false);
        for (auto it=spil_karata.begin(); it!=spil_karata.end(); it++) {
            if (*it==std::make_pair(Boje(redni_broj), red.front().second)) {
                pronadjena=true;
                break;
            }
        }
        if (pronadjena) red.pop();
        else {
            spil_karata.push_back(std::make_pair(Boje(redni_broj), red.front().second));
            red.pop();
        }
    }
    spil_karata.sort([imena_karata](std::pair<Boje, std::string> prvi, std::pair<Boje, std::string> drugi) {
        return (prvi.first<drugi.first 
        || prvi.first==drugi.first && std::find(imena_karata.begin(), imena_karata.end(), prvi.second)
        <std::find(imena_karata.begin(), imena_karata.end(), drugi.second));
    });
}

int main ()
{
    try {
        short int korak_razbrajanja;
        int broj_za_izbaciti, trenutni(52), broj_za_vratiti;
        std::list<std::pair<Boje, std::string>> aktuelni_spil;
        aktuelni_spil=KreirajSpil();
        std::cout << "Unesite korak razbrajanja: ";
        std::cin >> korak_razbrajanja;
        std::cout << "Unesite broj karata koje zelite izbaciti: ";
        std::cin >> broj_za_izbaciti;
        std::queue<std::pair<std::string, std::string>> red;
        red=IzbaciKarteRazbrajanjem(aktuelni_spil, korak_razbrajanja, broj_za_izbaciti);
        trenutni-=broj_za_izbaciti;
        std::cout << "U spilu trenutno ima " << trenutni << " karata, i to:" << std::endl;
        std::list<std::pair<Boje, std::string>>::iterator it(aktuelni_spil.begin());
        std::cout << "Pik: ";
        while ((it->first)==Boje::Pik) std::cout << (it++)->second << " ";
        std::cout << std::endl;
        std::cout << "Tref: ";
        while ((it->first)==Boje::Tref) std::cout << (it++)->second << " ";
        std::cout << std::endl;
        std::cout << "Herc: ";
        while ((it->first)==Boje::Herc) std::cout << (it++)->second << " ";
        std::cout << std::endl;
        std::cout << "Karo: ";
        while ((it->first)==Boje::Karo) std::cout << (it++)->second << " ";
        std::cout << std::endl;
        std::cout << "Unesite broj karata koje zelite vratiti u spil: ";
        std::cin >> broj_za_vratiti;
        VratiPrvihNKarata(aktuelni_spil, red, broj_za_vratiti);
        trenutni+=broj_za_vratiti;
        std::cout << "U spilu trenutno ima " << trenutni << " karata, i to:" << std::endl;
        std::list<std::pair<Boje, std::string>>::iterator iterat(aktuelni_spil.begin());
        std::cout << "Pik: ";
        while ((iterat->first)==Boje::Pik) std::cout << (iterat++)->second << " ";
        std::cout << std::endl;
        std::cout << "Tref: ";
        while ((iterat->first)==Boje::Tref) std::cout << (iterat++)->second << " ";
        std::cout << std::endl;
        std::cout << "Herc: ";
        while ((iterat->first)==Boje::Herc) std::cout << (iterat++)->second << " ";
        std::cout << std::endl;
        std::cout << "Karo: ";
        while ((iterat->first)==Boje::Karo) std::cout << (iterat++)->second << " ";
    }
    catch(std::logic_error greska) {
        std::cout << "Izuzetak: " << greska.what();
    }
    catch(std::range_error greska) {
        std::cout << "Izuzetak: " << greska.what();
    }
    catch(std::domain_error greska) {
        std::cout << "Izuzetak: " << greska.what();
    }
	return 0;
}
