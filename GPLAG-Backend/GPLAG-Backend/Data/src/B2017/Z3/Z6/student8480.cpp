/B2017/2018: Zadaća 3, Zadatak 6
#include <iostream>
#include <vector>
#include <list>
#include <map>
#include <algorithm>
#include <string>
#include <stack>
#include <memory>

enum class Boje
{
    Pik, Tref, Herc, Karo
};

struct Karta {
    Boje boja;
    std::string vrijednost;
};

struct Cvor {
    Karta karta;
    std::shared_ptr<Cvor> sljedeci;
};

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

std::shared_ptr<Cvor> KreirajSpil()
{
    std::vector<Boje> boje = {Boje::Pik, Boje::Tref, Boje::Herc, Boje::Karo};
    std::shared_ptr<Cvor> prvi(std::make_shared<Cvor>());
    prvi->karta = Karta {Boje::Pik,"2"};
    std::shared_ptr<Cvor> zadnji = prvi;

    for(int i=0; i<4; i++) {
        for(int j=0; j<13; j++) {
            if(i==0 && j==0) continue;
            zadnji->sljedeci = std::make_shared<Cvor>();

            zadnji->sljedeci->karta = Karta {boje[i], vrijednosti[j]};
            zadnji=zadnji->sljedeci;
        }
    }
    zadnji->sljedeci = prvi;

    return prvi;
}

int VelicinaSpila(std::shared_ptr<Cvor> prvi)
{
    int k=0;
    std::shared_ptr<Cvor> p(prvi);

    do {
        k++;
        p = p->sljedeci;
    } while (p!=prvi);

    return k;
}

void IspisiSpil(std::shared_ptr<Cvor> prvi)
{
    std::shared_ptr<Cvor> p(prvi);

    std::cout << "U spilu trenutno ima " << VelicinaSpila(prvi) << " karata, i to:" << std::endl;

    std::cout << "Pik: ";
    do {
        if(BojaUString(p->karta.boja)=="pik")
            std::cout << p->karta.vrijednost << " ";

        p = p->sljedeci;
    } while (p!=prvi);
    std::cout << std::endl;
    std::cout << "Tref: ";
    do {
        if(BojaUString(p->karta.boja)=="tref")
            std::cout << p->karta.vrijednost << " ";

        p = p->sljedeci;
    } while (p!=prvi);
    std::cout << std::endl;
    std::cout << "Herc: ";
    do {
        if(BojaUString(p->karta.boja)=="herc")
            std::cout << p->karta.vrijednost << " ";

        p = p->sljedeci;
    } while (p!=prvi);
    std::cout << std::endl;
    std::cout << "Karo: ";
    do {
        if(BojaUString(p->karta.boja)=="karo")
            std::cout << p->karta.vrijednost << " ";

        p = p->sljedeci;
    } while (p!=prvi);
    std::cout << std::endl;
}

std::shared_ptr<Cvor> NadjiKartu(std::shared_ptr<Cvor> prvi, Karta karta)
{
    std::shared_ptr<Cvor> p(prvi);

    while(p->sljedeci!=prvi) {
        if(p->sljedeci->karta.boja == karta.boja && p->sljedeci->karta.vrijednost == karta.vrijednost)
            return p;

        p=p->sljedeci;
    }
    return nullptr;
}

bool KartaComp(Karta a, Karta b)
{
    if (int(a.boja) == int(b.boja)) {
        if(a.vrijednost == b.vrijednost) return false;
        return std::find(vrijednosti.begin(), vrijednosti.end(), a.vrijednost)<std::find(vrijednosti.begin(), vrijednosti.end(), b.vrijednost);
    };
    return int(a.boja) < int(b.boja);
}

std::shared_ptr<Cvor> NadjiManjuKartu(std::shared_ptr<Cvor> prvi, Karta karta)
{
    std::shared_ptr<Cvor> p(prvi);

    while(p->sljedeci!=prvi) {
        if(!KartaComp(p->sljedeci->karta, karta))
            return p;

        p=p->sljedeci;
    }
    return p;
}

void IzbaciKartu(std::shared_ptr<Cvor> prvi)
{
    auto temp = prvi->sljedeci;
    prvi->sljedeci = temp->sljedeci;
}

void UbaciKartu(std::shared_ptr<Cvor> prvi, Karta karta)
{
    auto temp = prvi->sljedeci;

    prvi->sljedeci = std::make_shared<Cvor>();
    prvi->sljedeci->karta = karta;
    prvi->sljedeci->sljedeci = temp;
}

void IzbaciKarte(std::shared_ptr<Cvor> &prvi, std::multimap<Boje, std::string> karte)
{
    auto it = karte.begin();

    while(it != karte.end() && prvi) {
        Karta karta {it->first, it->second};
        auto pozicija = NadjiKartu(prvi, karta);
        if(pozicija) {
            IzbaciKartu(pozicija);
            it=karte.erase(it);
            continue;
        }
        it++;
    }
    return;
}

bool SortiranSpil(std::shared_ptr<Cvor> prvi)
{
    std::shared_ptr<Cvor> p(prvi);

    while(p->sljedeci!=prvi) {
        if(!KartaComp(p->karta, p->sljedeci->karta)) return false;
        p=p->sljedeci;
    }
    return true;
}

bool NemaDuplih(std::shared_ptr<Cvor> prvi)
{
    std::shared_ptr<Cvor> p(prvi);

    while(p->sljedeci!=prvi) {
        if(p->sljedeci->karta.boja == p->karta.boja && p->sljedeci->karta.vrijednost == p->karta.vrijednost) return false;

        p=p->sljedeci;
    }
    return true;
}

bool IspravnaKarta(Karta karta)
{
    return std::find(vrijednosti.begin(), vrijednosti.end(), karta.vrijednost)!=vrijednosti.end();
}


bool IspravanSpil(std::shared_ptr<Cvor> prvi)
{
    std::shared_ptr<Cvor> p(prvi);

    while(p->sljedeci!=prvi) {
        if(!IspravnaKarta(p->karta)) return false;

        p=p->sljedeci;
    }
    return VelicinaSpila(prvi)<=52 && SortiranSpil(prvi) && NemaDuplih(prvi);
}

std::stack<std::pair<std::string, std::string>>IzbaciKarteRazbrajanjem(std::shared_ptr<Cvor> &prvi, const short int &r, const int &b)
{
    if(!IspravanSpil(prvi)) throw std::logic_error("Neispravna lista!");
    if(r<1 || r>52 || b<1) throw std::logic_error("Neispravni elementi za izbacivanje!");

    std::stack<std::pair<std::string, std::string>> stek;
    std::multimap<Boje, std::string> karte;

    int i=0;
    std::shared_ptr<Cvor> p(prvi);
    int size = VelicinaSpila(prvi);

    while(i<b && size>0) {
        bool wrap = false;
        for(int j=1; j<r; j++) {
            if(p->sljedeci==prvi) wrap=true;
            p=p->sljedeci;
        }

        karte.insert(std::pair<Boje, std::string>(p->karta.boja, p->karta.vrijednost));
        stek.push(std::pair<std::string, std::string>(BojaUString(p->karta.boja), p->karta.vrijednost));
        i++;
        if(wrap)  p=p->sljedeci;
        p=p->sljedeci;
    }

    try {
        IzbaciKarte(prvi, karte);
    } catch(...) {
        throw;
    }
    return stek;
}

void VratiPosljednjihNKarata(std::shared_ptr<Cvor> &prvi, std::stack<std::pair<std::string, std::string>> &stek, int n)
{
    if(n<0) throw std::domain_error("Broj n je besmislen!");
    if(n>stek.size()) throw std::range_error("Nedovoljno karata u redu!");
    if(!IspravanSpil(prvi)) throw std::logic_error("Neispravna lista!");

    std::vector<std::string> boje = {"Pik", "Tref", "Herc", "Karo"};

    std::shared_ptr<Cvor> p(prvi);

    while(stek.size()>0 && n>0) {
        auto karta = Karta {StringUBoju(stek.top().first), stek.top().second};
        if(!IspravnaKarta(karta)) throw std::logic_error("Neispravne karte!");

        if(!NadjiKartu(p, karta)) {
            UbaciKartu(NadjiManjuKartu(prvi, karta), karta);
            n--;
        }
        stek.pop();
    }
}

int main ()
{
    auto spil = KreirajSpil();

    int r, b;
    std::cout << "Unesite korak razbrajanja: ";
    std::cin >> r;
    std::cout << "Unesite broj karata koje zelite izbaciti: ";
    std::cin >> b;

    try {
        auto stek = IzbaciKarteRazbrajanjem(spil, r, b);

        IspisiSpil(spil);

        std::cout << "Unesite broj karata koje zelite vratiti u spil: ";
        std::cin >> r;

        VratiPosljednjihNKarata(spil, stek, r);
        IspisiSpil(spil);

        spil->sljedeci = nullptr;

    } catch(std::logic_error izuzetak) {
        std::cout << "Izuzetak: " << izuzetak.what() << std::endl;
        spil->sljedeci = nullptr;
    } catch(std::range_error izuzetak) {
        std::cout << "Izuzetak: " << izuzetak.what() << std::endl;
        spil->sljedeci = nullptr;
    }

    return 0;
}
