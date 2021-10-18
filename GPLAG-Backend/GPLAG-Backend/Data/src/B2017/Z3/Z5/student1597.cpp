/B2017/2018: Zadaća 3, Zadatak 5
#include <iostream>
#include <string>
#include <map>
#include <utility>
#include <vector>
#include <stack>
#include <algorithm>
#include <new>

enum class Boje {
    Pik, Tref, Herc, Karo
};

std::vector<std::string> imena_boja{"Pik", "Tref", "Herc", "Karo"};
std::vector<std::string> imena_karata{"2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K", "A"};

struct Karta {
    Boje boja;
    std::string vrijednost;
};

struct Cvor {
    Karta karta;
    Cvor* sljedeci;
};

bool KriterijZaProvjeru(Karta prva, Karta druga) {
    return (prva.boja<druga.boja 
    || prva.boja==druga.boja && std::find(imena_karata.begin(), imena_karata.end(), prva.vrijednost)
    <std::find(imena_karata.begin(), imena_karata.end(), druga.vrijednost));
}

Cvor* KreirajSpil() {
    Cvor* spil_karata(nullptr), *prethodni;
    for (int i=0; i<4; i++) {
        for (int j=0; j<13; j++) {
            Cvor* novi_cvor(new Cvor{{Boje(i), imena_karata.at(j)}, nullptr});
            if (spil_karata==nullptr) spil_karata=novi_cvor;
            else prethodni->sljedeci=novi_cvor;
            prethodni=novi_cvor;
        }
    }
    prethodni->sljedeci=spil_karata;
    return spil_karata;
}

void IzbaciKarte(Cvor* &spil_karata, std::multimap<Boje, std::string> &multi) {
    int broj_koraka(0);
    for (Cvor* klizeci=spil_karata;; klizeci=klizeci->sljedeci) {
        if (broj_koraka>0 && broj_koraka<52 && klizeci==spil_karata) break;
        if (broj_koraka==52 && klizeci!=spil_karata) throw std::logic_error("Neispravna lista!");
        else if (broj_koraka==52) break;
        broj_koraka++;
    }
    int velicina(0);
    for (Cvor* klizeci=spil_karata; (velicina==0 || klizeci!=spil_karata); klizeci=klizeci->sljedeci) velicina++;
    broj_koraka=0;
    for (Cvor* klizeci=spil_karata; broj_koraka<velicina; klizeci=klizeci->sljedeci) {
        if (klizeci->sljedeci==nullptr) throw std::logic_error("Neispravna lista!");
        broj_koraka++;
    }
    bool besmisleni(false);
    broj_koraka=0;
    for (Cvor* klizeci=spil_karata; (broj_koraka==0 || klizeci!=spil_karata); klizeci=klizeci->sljedeci) {
        if (((klizeci->karta).boja!=Boje::Pik && (klizeci->karta).boja!=Boje::Tref 
        && (klizeci->karta).boja!=Boje::Herc && (klizeci->karta).boja!=Boje::Karo) 
        || (std::find(imena_karata.begin(), imena_karata.end(), (klizeci->karta).vrijednost)==imena_karata.end())) {
            besmisleni=true;
            break;
        }
        broj_koraka++;
    }
    if (besmisleni) throw std::logic_error("Neispravna lista!");
    bool sortirana(true);
    broj_koraka=0;
    Cvor* kraj=spil_karata;
    for (int i=0; i<velicina-2; i++) kraj=kraj->sljedeci;
    for (Cvor* pok=spil_karata; pok!=kraj; pok=pok->sljedeci) {
        Cvor* sljedeci_pok(pok->sljedeci);
        if (!KriterijZaProvjeru(pok->karta, sljedeci_pok->karta)) {
            sortirana=false;
            break;
        }
    }
    if (!sortirana) throw std::logic_error("Neispravna lista!");
    Cvor* prethodni_pok(spil_karata);
    while ((prethodni_pok->sljedeci)!=spil_karata) prethodni_pok=prethodni_pok->sljedeci;
    for (Cvor* klizeci=spil_karata; (broj_koraka==0 || klizeci!=spil_karata); klizeci=klizeci->sljedeci) {
        bool u_oba_kontejnera(false);
        std::multimap<Boje, std::string>::iterator it_map;
        for (it_map=multi.begin(); it_map!=multi.end(); it_map++) {
            if ((klizeci->karta).boja==it_map->first && (klizeci->karta).vrijednost==it_map->second) {
                u_oba_kontejnera=true;
                break;
            }
        }
        bool izbaceno(false);
        if (u_oba_kontejnera) {
            it_map=multi.erase(it_map);
            if (klizeci==spil_karata) spil_karata=spil_karata->sljedeci;
            prethodni_pok->sljedeci=klizeci->sljedeci;
            delete klizeci;
            klizeci=prethodni_pok;
            velicina--;
            if (velicina==0) {
                spil_karata=nullptr;
                return;
            }
            izbaceno=true;
        }
        broj_koraka++;
        if (!izbaceno) prethodni_pok=prethodni_pok->sljedeci;
    }
}

std::stack<std::pair<std::string, std::string>> IzbaciKarteRazbrajanjem
(Cvor* &spil_karata, const short int &korak_raz, const int &cijeli) {
    if (korak_raz<1 || korak_raz>52) throw std::logic_error("Neispravni elementi za izbacivanje!");
    if (cijeli<1) throw std::logic_error("Neispravni elementi za izbacivanje!");
    int broj_koraka(0);
    for (Cvor* klizeci=spil_karata;; klizeci=klizeci->sljedeci) {
        if (broj_koraka>0 && broj_koraka<52 && klizeci==spil_karata) break;
        if (broj_koraka==52 && klizeci!=spil_karata) throw std::logic_error("Neispravna lista!");
        else if (broj_koraka==52) break;
        broj_koraka++;
    }
    int duzina(0);
    for (Cvor* klizeci=spil_karata; (duzina==0 || klizeci!=spil_karata); klizeci=klizeci->sljedeci) duzina++;
    broj_koraka=0;
    for (Cvor* klizeci=spil_karata; broj_koraka<duzina; klizeci=klizeci->sljedeci) {
        if (klizeci->sljedeci==nullptr) throw std::logic_error("Neispravna lista!");
        broj_koraka++;
    }
    bool besmisleni(false);
    broj_koraka=0;
    for (Cvor* klizeci=spil_karata; (broj_koraka==0 || klizeci!=spil_karata); klizeci=klizeci->sljedeci) {
        if (((klizeci->karta).boja!=Boje::Pik && (klizeci->karta).boja!=Boje::Tref 
        && (klizeci->karta).boja!=Boje::Herc && (klizeci->karta).boja!=Boje::Karo) 
        || (std::find(imena_karata.begin(), imena_karata.end(), (klizeci->karta).vrijednost)==imena_karata.end())) {
            besmisleni=true;
            break;
        }
        broj_koraka++;
    }
    if (besmisleni) throw std::logic_error("Neispravna lista!");
    bool sortirana(true);
    broj_koraka=0;
    Cvor* kraj=spil_karata;
    for (int i=0; i<duzina-2; i++) kraj=kraj->sljedeci;
    for (Cvor* pok=spil_karata; pok!=kraj; pok=pok->sljedeci) {
        Cvor* sljedeci_pok(pok->sljedeci);
        if (!KriterijZaProvjeru(pok->karta, sljedeci_pok->karta)) {
            sortirana=false;
            break;
        }
    }
    if (!sortirana) throw std::logic_error("Neispravna lista!");
    std::stack<std::pair<std::string, std::string>> stek;
    Cvor* prethodni_pok(spil_karata);
    while ((prethodni_pok->sljedeci)!=spil_karata) prethodni_pok=prethodni_pok->sljedeci;
    Cvor* klizeci(spil_karata);
    for (int i=0; i<cijeli; i++) {
        for (int i=0; i<korak_raz-1; i++) {
            prethodni_pok=prethodni_pok->sljedeci;
            klizeci=klizeci->sljedeci;
        }
        if (klizeci==spil_karata) spil_karata=spil_karata->sljedeci;
        stek.push(std::make_pair(imena_boja.at(int((klizeci->karta).boja)), (klizeci->karta).vrijednost));
        prethodni_pok->sljedeci=klizeci->sljedeci;
        Cvor* iza(klizeci->sljedeci);
        delete klizeci;
        klizeci=iza;
        duzina--;
        if (duzina==0) {
            spil_karata=nullptr;
            break;
        }
    }
    return stek;
}

void VratiPosljednjihNKarata(Cvor* &spil_karata, std::stack<std::pair<std::string, std::string>> &stek, int n) {
    if (n<0) throw std::domain_error("Broj n je besmislen!");
    if (n>stek.size()) throw std::range_error("Nedovoljno karata u steku!");
    int broj_koraka(0);
    for (Cvor* klizeci=spil_karata;; klizeci=klizeci->sljedeci) {
        if (broj_koraka>0 && broj_koraka<52 && klizeci==spil_karata) break;
        if (broj_koraka==52 && klizeci!=spil_karata) throw std::logic_error("Neispravna lista!");
        else if (broj_koraka==52) break;
        broj_koraka++;
    }
    broj_koraka=0;
    for (Cvor* klizeci=spil_karata; broj_koraka<52; klizeci=klizeci->sljedeci) {
        if (klizeci->sljedeci==nullptr) throw std::logic_error("Neispravna lista!");
        broj_koraka++;
    }
    bool besmisleni(false);
    broj_koraka=0;
    for (Cvor* klizeci=spil_karata; (broj_koraka==0 || klizeci!=spil_karata); klizeci=klizeci->sljedeci) {
        if (((klizeci->karta).boja!=Boje::Pik && (klizeci->karta).boja!=Boje::Tref 
        && (klizeci->karta).boja!=Boje::Herc && (klizeci->karta).boja!=Boje::Karo) 
        || (std::find(imena_karata.begin(), imena_karata.end(), (klizeci->karta).vrijednost)==imena_karata.end())) {
            besmisleni=true;
            break;
        }
        broj_koraka++;
    }
    if (besmisleni) throw std::logic_error("Neispravna lista!");
    bool sortirana(true);
    broj_koraka=0;
    Cvor* kraj=spil_karata;
    for (int i=0; i<50; i++) kraj=kraj->sljedeci;
    for (Cvor* pok=spil_karata; pok!=kraj; pok=pok->sljedeci) {
        Cvor* sljedeci_pok(pok->sljedeci);
        if (!KriterijZaProvjeru(pok->karta, sljedeci_pok->karta)) {
            sortirana=false;
            break;
        }
    }
    if (!sortirana) throw std::logic_error("Neispravna lista!");
    int redni_broj(0);
    for (int i=0; i<n; i++) {
        if (std::find(imena_boja.begin(), imena_boja.end(), stek.top().first)==imena_boja.end()) {
            throw std::logic_error("Neispravne karte!");
        }
        if (std::find(imena_karata.begin(), imena_karata.end(), stek.top().second)==imena_karata.end()) {
            throw std::logic_error("Neispravne karte!");
        }
        for (int i=0; i<imena_boja.size(); i++) {
            if (stek.top().first==imena_boja.at(i)) {
                redni_broj=i;
                break;
            }
        }
        bool pronadjena(false);
        for (Cvor* pok=spil_karata; (broj_koraka==0 || pok!=spil_karata); pok=pok->sljedeci) {
            if ((pok->karta).boja==Boje(redni_broj) && (pok->karta).vrijednost==stek.top().second) {
                pronadjena=true;
                break;
            }
            broj_koraka++;
        }
        broj_koraka=0;
        if (pronadjena) stek.pop();
        else {
            Cvor* prethodni_pok(spil_karata);
            while ((prethodni_pok->sljedeci)!=spil_karata) prethodni_pok=prethodni_pok->sljedeci;
            Cvor* sadasnji(spil_karata);
            while ((broj_koraka==0 || sadasnji!=spil_karata) 
            && ((sadasnji->karta).boja<Boje(redni_broj) 
            || (sadasnji->karta).boja==Boje(redni_broj) && std::find(imena_karata.begin(), imena_karata.end(), (sadasnji->karta).vrijednost)
            <std::find(imena_karata.begin(), imena_karata.end(), stek.top().second))) {
                sadasnji=sadasnji->sljedeci;
                prethodni_pok=prethodni_pok->sljedeci;
                broj_koraka++;
            }
            Cvor* novi(new Cvor{{Boje(redni_broj), stek.top().second}, nullptr});
            prethodni_pok->sljedeci=novi;
            novi->sljedeci=sadasnji;
            stek.pop();
        }
    }
}

void UnistiSpil(Cvor* &spil_karata) {
    if (spil_karata==nullptr) return;
    int velicina(0);
    for (Cvor* pok=spil_karata; (velicina==0 || pok!=spil_karata); pok=pok->sljedeci) velicina++;
    IzbaciKarteRazbrajanjem(spil_karata, 1, velicina);
}

int main ()
{
    Cvor* aktuelni_spil(nullptr);
    try {
        short int korak_razbrajanja;
        int broj_za_izbaciti, trenutni(52), broj_za_vratiti;
        aktuelni_spil=KreirajSpil();
        std::cout << "Unesite korak razbrajanja: ";
        std::cin >> korak_razbrajanja;
        std::cout << "Unesite broj karata koje zelite izbaciti: ";
        std::cin >> broj_za_izbaciti;
        std::stack<std::pair<std::string, std::string>> stek;
        stek=IzbaciKarteRazbrajanjem(aktuelni_spil, korak_razbrajanja, broj_za_izbaciti);
        trenutni-=broj_za_izbaciti;
        std::cout << "U spilu trenutno ima " << trenutni << " karata, i to:" << std::endl;
        Cvor* pok(aktuelni_spil);
        std::cout << "Pik: ";
        while ((pok->karta).boja==Boje::Pik) {
            std::cout << (pok->karta).vrijednost << " ";
            pok=pok->sljedeci;
        }
        std::cout << std::endl;
        std::cout << "Tref: ";
        while ((pok->karta).boja==Boje::Tref) {
            std::cout << (pok->karta).vrijednost << " ";
            pok=pok->sljedeci;
        }
        std::cout << std::endl;
        std::cout << "Herc: ";
        while ((pok->karta).boja==Boje::Herc) {
            std::cout << (pok->karta).vrijednost << " ";
            pok=pok->sljedeci;
        }
        std::cout << std::endl;
        std::cout << "Karo: ";
        while ((pok->karta).boja==Boje::Karo) {
            std::cout << (pok->karta).vrijednost << " ";
            pok=pok->sljedeci;
        }
        std::cout << std::endl;
        std::cout << "Unesite broj karata koje zelite vratiti u spil: ";
        std::cin >> broj_za_vratiti;
        VratiPosljednjihNKarata(aktuelni_spil, stek, broj_za_vratiti);
        trenutni+=broj_za_vratiti;
        std::cout << "U spilu trenutno ima " << trenutni << " karata, i to:" << std::endl;
        pok=aktuelni_spil;
        std::cout << "Pik: ";
        while ((pok->karta).boja==Boje::Pik) {
            std::cout << (pok->karta).vrijednost << " ";
            pok=pok->sljedeci;
        }
        std::cout << std::endl;
        std::cout << "Tref: ";
        while ((pok->karta).boja==Boje::Tref) {
            std::cout << (pok->karta).vrijednost << " ";
            pok=pok->sljedeci;
        }
        std::cout << std::endl;
        std::cout << "Herc: ";
        while ((pok->karta).boja==Boje::Herc) {
            std::cout << (pok->karta).vrijednost << " ";
            pok=pok->sljedeci;
        }
        std::cout << std::endl;
        std::cout << "Karo: ";
        while ((pok->karta).boja==Boje::Karo) {
            std::cout << (pok->karta).vrijednost << " ";
            pok=pok->sljedeci;
        }
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
    UnistiSpil(aktuelni_spil);
	return 0;
}
