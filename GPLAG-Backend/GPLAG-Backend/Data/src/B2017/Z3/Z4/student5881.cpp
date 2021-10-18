/B2017/2018: Zadaća 3, Zadatak 4
#include <iostream>
#include <string>
#include <utility>
#include <list>
#include <map>
#include <stdexcept>
#include <queue>

enum class Boje
{
    Pik, Tref, Herc, Karo
};

const std::string imena[13] = {"2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K", "A"};

std::list<std::pair<Boje, std::string>> KreirajSpil()
{
    std::list<std::pair<Boje, std::string>> spil(52);
    int br(0);
    auto it(spil.begin());
    for (int i = 0; i < 4; i++) {
        Boje boja;
        if (i==0)
            boja=Boje::Pik;
        else if (i==1)
            boja=Boje::Tref;
        else if (i==2)
            boja=Boje::Herc;
        else
            boja=Boje::Karo;
        for (; br!=13; it++) {
            it->first=boja;
            it->second=imena[br];
            br++;
        }
        br=0;

    }
    return spil;
}

bool SpilValja(const std::list<std::pair<Boje, std::string>> &spil)
{
    if (spil.size()>52)
        return false;
    auto it(spil.begin());
    for (; it!=spil.end(); it++) {
        if (it->first!=Boje::Pik && it->first!=Boje::Tref && it->first!=Boje::Herc && it->first!=Boje::Karo)
            return false;
        int i(0);
        for (; i < 13; i++)
            if (it->second==imena[i])
                break;
        if (i==13)
            return false;
    }
    if (spil.size()<=1)
        return true;
    it=spil.begin();
    auto prethodni(it);
    Boje pocetna_boja(it->first);
    Boje sljedeca_boja(Boje::Karo);
    if (pocetna_boja==Boje::Pik)
        sljedeca_boja=Boje::Tref;
    else if (pocetna_boja==Boje::Tref)
        sljedeca_boja=Boje::Herc;
    else if (pocetna_boja==Boje::Herc)
        sljedeca_boja=Boje::Karo;
    int pocetni_indeks(0);
    for (int i = 0; i < 13; i++) {
        if (prethodni->second==imena[i]) {
            pocetni_indeks=i;
            break;
        }
    }
    it++;
    for (; it!=spil.end(); it++) {
        if (it->first!=prethodni->first) {
            if (it->first!=sljedeca_boja)
                return false;
            pocetna_boja=it->first;
            sljedeca_boja=Boje::Karo;
            if (pocetna_boja==Boje::Pik)
                sljedeca_boja=Boje::Tref;
            else if (pocetna_boja==Boje::Tref)
                sljedeca_boja=Boje::Herc;
            else if (pocetna_boja==Boje::Herc)
                sljedeca_boja=Boje::Karo;
            pocetni_indeks=0;
        } else {
            int sljedeci_indeks(0);
            for (int i = 0; i < 13; i++) {
                if (it->second==imena[i]) {
                    sljedeci_indeks=i;
                    break;
                }
            }
            if (pocetni_indeks>=sljedeci_indeks)
                return false;
            pocetni_indeks=sljedeci_indeks;
        }
        prethodni++;
    }

    return true;
}

void IzbaciKarte(std::list<std::pair<Boje, std::string>> &spil, std::multimap<Boje, std::string> &karte)
{
    if (!SpilValja(spil))
        throw std::logic_error("Neispravna lista!");
    for (auto it(spil.begin()); it != spil.end();) {
        bool preskoci(false);
        for (auto it2(karte.begin()); it2 != karte.end(); it2++) {
            if (*it==make_pair(it2->first, it2->second)) {
                it=spil.erase(it);
                if (it==spil.begin())
                    preskoci=true;
                else
                    it--;
                it2=karte.erase(it2);
                if (it2==karte.begin())
                    break;
            }
        }
        if (!preskoci)
            it++;
    }
}

std::queue<std::pair<std::string, std::string>> IzbaciKarteRazbrajanjem(std::list<std::pair<Boje, std::string>> &spil, short int &r, const int &b)
{
    std::queue<std::pair<std::string, std::string>> rez;
    if (r<1 || r>52 || b<1)
        throw std::logic_error("Neispravni elementi za izbacivanje!");
    if (!SpilValja(spil))
        throw std::logic_error("Neispravna lista!");
    int br(1), br_izbacenih(0);
    for (auto it(spil.begin()); ; it++) {
        if (spil.size()==0)
            break;
        if (it==spil.end() && br_izbacenih!=b)
            it=spil.begin();
        if (br==r) {
            switch (it->first) {
            case Boje::Pik :
                rez.push(std::make_pair("Pik", it->second));
                break;
            case Boje::Tref :
                rez.push(std::make_pair("Tref", it->second));
                break;
            case Boje::Herc :
                rez.push(std::make_pair("Herc", it->second));
                break;
            case Boje::Karo :
                rez.push(std::make_pair("Karo", it->second));
                break;
            }
            it = spil.erase(it);
            it--;
            br_izbacenih++;
            if (br_izbacenih==b || spil.size()==0)
                break;
            br=0;
        }
        br++;
    }
    return rez;
}

bool RedValja(std::queue<std::pair<std::string, std::string>> red)
{
    while(!red.empty()) {
        if (red.front().first!="Pik" && red.front().first!="Tref" && red.front().first!="Herc" && red.front().first!="Karo")
            return false;
        int i(0);
        for (; i < 13; i++)
            if (red.front().second==imena[i])
                break;
        if (i==13)
            return false;
        red.pop();
    }
    return true;
}

void IspisiSpil(const std::list<std::pair<Boje, std::string>> &spil)
{
    std::cout << "U spilu trenutno ima " << spil.size() << " karata, i to: " << std::endl;
    for (int i = 0; i < 4; i++) {
        bool sljedeci(false);
        auto it(spil.begin());
        Boje boja;
        if (i==0) {
            std::cout << "Pik:";
            boja=Boje::Pik;
        } else if (i==1) {
            std::cout << "Tref:";
            boja=Boje::Tref;
        } else if (i==2) {
            std::cout << "Herc:";
            boja=Boje::Herc;
        } else {
            std::cout << "Karo:";
            boja=Boje::Karo;
        }
        for (; it!=spil.end(); it++) {
            if (it->first==boja) {
                std::cout << " " << it->second;
                sljedeci=true;
            } else if (sljedeci)
                break;
        }
        std::cout << std::endl;
    }
}

void VratiPrvihNKarata(std::list<std::pair<Boje, std::string>> &spil, std::queue<std::pair<std::string, std::string>> &red, int n)
{
    if (n<0)
        throw std::domain_error("Broj n je besmislen!");
    if (n>red.size())
        throw std::range_error("Nedovoljno karata u redu!");
    if (!RedValja(red))
        throw std::logic_error("Neispravne karte!");
    if (!SpilValja(spil))
        throw std::logic_error("Neispravna lista!");
    while(n!=0) {
        Boje b(Boje::Pik);
        if (red.front().first=="Tref")
            b=Boje::Tref;
        else if (red.front().first=="Herc")
            b=Boje::Herc;
        else if (red.front().first=="Karo")
            b=Boje::Karo;
        auto it(spil.begin());
        while (it!=spil.end() && it->first!=b)
            it++;
        if (it==spil.end() && b==Boje::Pik)
            it = spil.begin();
        else if (it==spil.end()) {
            if (b==Boje::Tref) {
                it=spil.begin();
                while (it!=spil.end() && it->first==Boje::Pik)
                    it++;
                if (it==spil.end())
                    it=spil.begin();
            } else if (b==Boje::Herc) {
                it=spil.begin();
                while (it!=spil.end() && (it->first==Boje::Tref || it->first==Boje::Pik))
                    it++;
                if (it==spil.end())
                    it=spil.begin();
            } else if (b==Boje::Karo) {
                it=spil.begin();
                while (it!=spil.end() && (it->first==Boje::Herc || it->first==Boje::Tref || it->first==Boje::Pik))
                    it++;
                if (it==spil.end())
                    it=spil.begin();
            }
        }
        int j(0), k(0);
        for (; j < 13; j++)
            if (red.front().second==imena[j])
                break;
        do {
            if (spil.size()==0) {
                spil.insert(it, std::make_pair(b, red.front().second));
                break;
            }
            for (; k < 13; k++)
                if (it->second==imena[k])
                    break;
            if (k>=j) {
                if (it->first==b && it->second==red.front().second)
                    break;
                spil.insert(it, std::make_pair(b, red.front().second));
                break;
            }
            it++;
            if (spil.size()==1 || it->first!=b) {
                spil.insert(it, std::make_pair(b, red.front().second));
                break;
            }
        } while (true);
        red.pop();
        n--;
    }
}

int main ()
{
    auto spil(KreirajSpil());
    short int r;
    int b;
    std::cout << "Unesite korak razbrajanja: ";
    std::cin >> r;
    std::cout << "Unesite broj karata koje zelite izbaciti: ";
    std::cin >> b;
    std::queue<std::pair<std::string, std::string>> red;
    try {
        red=IzbaciKarteRazbrajanjem(spil, r ,b);
    } catch (const std::exception &greska) {
        std::cout << "Izuzetak: " << greska.what();
        return 0;
    }

    IspisiSpil(spil);
    int n;
    std::cout << "Unesite broj karata koje zelite vratiti u spil: ";
    std::cin >> n;
    try {
        VratiPrvihNKarata(spil, red, n);
    } catch (const std::exception &greska) {
        std::cout << "Izuzetak: " << greska.what();
        return 0;
    }
    IspisiSpil(spil);

    return 0;
}
