/B2017/2018: Zadaća 3, Zadatak 4
#include <iostream>
#include <list>
#include <map>
#include <stdexcept>
#include <queue>
#include <utility>
#include <algorithm>

enum class Boje
{
    Pik, Tref, Herc, Karo
};

typedef std::list<std::pair<Boje, std::string>> Spil;

Spil KreirajSpil()
{
    Spil Karte;

    for(int i=0; i<4; i++) {
        for(int j=2; j<15; j++) {
            if(j==11) Karte.push_back(std::make_pair(Boje(i),"J"));
            else if(j==12) Karte.push_back(std::make_pair(Boje(i),"Q"));
            else if(j==13) Karte.push_back(std::make_pair(Boje(i),"K"));
            else if(j==14) Karte.push_back(std::make_pair(Boje(i),"A"));
            else Karte.push_back(std::make_pair(Boje(i),std::to_string(j)));
        }
    }

    return Karte;
}

void Test(Spil karte)
{
    if(karte.size()>52) throw std::logic_error("Nesipravna lista!");
    for(auto it(karte.begin()); it!=karte.end(); it++) {
        if(it->first != Boje(0) && it->first != Boje(1) && it->first != Boje(2) && it->first != Boje(3)) {
            throw std::logic_error("Nesipravna lista!");
        }
        if(it->second != "J" && it->second != "Q" && it->second != "K" && it->second != "A") {
            int pr=std::stoi(it->second);
            if(!(pr>=2 && pr<=10)) {
                throw std::logic_error("Neispravna lista!");
            }
        }
    }
}

void IzbaciKarte(Spil &karte, std::multimap<Boje, std::string> &mapa)
{
    Test(karte);
    for(auto it(karte.begin()); it!=karte.end(); it++) {
        bool ima_element(false);
        for(auto it1(mapa.begin()); it1!=mapa.end(); it1++) {
            if(it->first == it1->first && it ->second == it1-> second) {
                mapa.erase(it1);
                ima_element=true;
                it1--;
            }
        }
        if(ima_element) {
            it=karte.erase(it);
            it--;
        }
    }
}

std::queue<std::pair<std::string, std::string>> IzbaciKarteRazbrajanjem(Spil &karte, short int &r, int &b)
{
    if(r<1 || r>52) throw std::logic_error("Neispravni elementi za izbacivanje!");
    if(b<1) throw std::logic_error("Neispravni elementi za izbacivanje!");
    Test(karte);
    std::queue<std::pair<std::string, std::string>> Red;
    int brojac(1), br_karata(0);
    auto it(karte.begin());
    while(br_karata!=b) {
        if(brojac==r) {
            std::string Novi;
            if((int)it->first == 0) Novi= {"Pik"};
            else if((int)it->first == 1) Novi= {"Tref"};
            else if((int)it->first == 2) Novi= {"Herc"};
            else Novi= {"Karo"};
            Red.push(std::pair<std::string, std::string> {Novi,it->second});
            it=karte.erase(it);
            br_karata++;
            brojac=1;
        } else {
            it++;
            if(it==karte.end()) it=karte.begin();
            brojac++;
        }
        if(br_karata==b) break;
    }
    return Red;
}

void KriterijSortiranja(Spil &karte)
{
    for(auto it1(karte.begin()); it1!=karte.end(); it1++) {
        for(auto it2(it1); it2!=karte.end(); it2++) {
            bool prekid(false);
            for(int i=0; i<4; i++) {
                if(int(it1->first)==i) {
                    for(int j=0; j<4; j++) {
                        if(int(it2->first)==j) {
                            if(i>j) {
                                auto p=*it1;
                                *it1=*it2;
                                *it2=p;
                            }
                            break;
                            prekid=true;
                        }
                    }
                    if(prekid==true) break;
                }
            }
        }
    }

    std::string niz[]= {"2","3","4","5","6","7","8","9","10","J","Q","K","A"};
    for(auto it1(karte.begin()); it1!=karte.end(); it1++) {
        for(auto it2(it1); it2!=karte.end(); it2++) {
            bool prekid(false);
            if(it1->first==it2->first) {
                for(int i=0; i<13; i++) {
                    if(it1->second==niz[i]) {
                        for(int j=0; j<13; j++) {
                            if(it2->second==niz[j]) {
                                if(i>j) {
                                    auto p=*it1;
                                    *it1=*it2;
                                    *it2=p;
                                }
                                break;
                                prekid=true;
                            }
                        }
                        if(prekid==true) break;
                    }
                }
            }
        }
    }
}

void VratiPrvihNKarata(Spil &karte, std::queue<std::pair<std::string, std::string>> &red, int n)
{
    std::string niz[]= {"Pik", "Tref", "Herc", "Karo"};
    std::string niz1[]= {"2","3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K", "A"};
    if(n<0) throw std::domain_error("Broj n je besmislen!");
    if(n>red.size()) throw std::range_error("Nedovoljno karata u redu!");
    int velicina(red.size());
    int broj_clanova(0);
    while(broj_clanova!=velicina) {
        if(red.front().first!=niz[0] && red.front().first!=niz[1] && red.front().first!=niz[2] && red.front().first!=niz[3]) {
            throw std::logic_error("Neispravne karte!");
        }
        for(int i=0; i<13; i++) {
            if(red.front().second==niz1[i]) {
                break;
            } else if(i==12) {
                throw std::logic_error("Neispravne karte!");
            }
        }
        broj_clanova++;
        red.push(red.front());
        red.pop();
        if(broj_clanova==velicina) break;
    }
    Test(karte);
    int broj_vracenih(0);
    while(broj_vracenih!=n) {
        auto zamjena(red.front());
        if(zamjena.first==niz[0]) {
            auto it(karte.begin());
            while(it!=karte.end()) {
                if(zamjena.second==it->second && int(it->first)==0) {
                    red.pop();
                    break;
                }
                it++;
                if(it==karte.end()) {
                    karte.push_back(std::make_pair(Boje(0),zamjena.second));
                    broj_vracenih++;
                    red.pop();
                    break;
                }
            }
        } else if (zamjena.first==niz[1]) {
            auto it(karte.begin());
            while(it!=karte.end()) {
                if(zamjena.second==it->second && int(it->first)==1) {
                    red.pop();
                    break;
                }
                it++;
                if(it==karte.end()) {
                    karte.push_back(std::make_pair(Boje(1), zamjena.second));
                    broj_vracenih++;
                    red.pop();
                    break;
                }
            }
        } else if(zamjena.first==niz[2]) {
            auto it(karte.begin());
            while(it!=karte.end()) {
                if(zamjena.second==it->second && int(it->first)==2) {
                    red.pop();
                    break;
                }
                it++;
                if(it==karte.end()) {
                    karte.push_back(std::make_pair(Boje(2), zamjena.second));
                    broj_vracenih++;
                    red.pop();
                    break;
                }
            }
        } else if(zamjena.first==niz[3]) {
            auto it(karte.begin());
            while(it!=karte.end()) {
                if(zamjena.second==it->second && int(it->first)==3) {
                    red.pop();
                    break;
                }
                it++;
                if(it==karte.end()) {
                    karte.push_back(std::make_pair(Boje(3), zamjena.second));
                    broj_vracenih++;
                    red.pop();
                    break;
                }
            }
        }
        if(broj_vracenih==n) break;
    }
    KriterijSortiranja(karte);
}

void IspisiSpil(Spil Novi_spil)
{
    for(auto it(Novi_spil.begin()); it!=Novi_spil.end(); it++) {
        if(it->first==Boje(0)) {
            std::cout << "Pik: ";
            while(it->first==Boje(0)) {
                std::cout << it->second << " ";
                it++;
            }
            it--;
            std::cout << std::endl;
        } else if(it->first==Boje(1)) {
            std::cout << "Tref: ";
            while(it->first==Boje(1)) {
                std::cout << it->second << " ";
                it++;
            }
            it--;
            std::cout << std::endl;
        } else if(it->first==Boje(2)) {
            std::cout << "Herc: ";
            while(it->first==Boje(2)) {
                std::cout << it->second << " ";
                it++;
            }
            it--;
            std::cout << std::endl;
        } else {
            std::cout << "Karo: ";
            while(it->first==Boje(3)) {
                std::cout << it->second << " ";
                it++;
            }
            it--;
            std::cout << std::endl;
        }
    }
}

int main()
{
    try {
        Spil Novi_spil(KreirajSpil());
        short int korak;
        std::cout << "Unesite korak razbrajanja: ";
        std::cin >> korak;
        int broj;
        std::cout << "Unesite broj karata koje zelite izbaciti: ";
        std::cin >> broj;
        std::queue<std::pair<std::string, std::string>> Red(IzbaciKarteRazbrajanjem(Novi_spil,korak,broj));
        std::cout << "U spilu trenutno ima " << Novi_spil.size() << " karata, i to:" << std::endl;
        IspisiSpil(Novi_spil);
        std::cout << "Unesite broj karata koje zelite vratiti u spil: ";
        int br_karata1;
        std::cin >> br_karata1;
        VratiPrvihNKarata(Novi_spil,Red,br_karata1);
        std::cout << "U spilu trenutno ima " << Novi_spil.size() << " karata, i to:" << std::endl;
        IspisiSpil(Novi_spil);
    } catch(std::domain_error izuzetak) {
        std::cout << "Izuzetak: " << izuzetak.what() << std::endl;
    } catch(std::range_error izuzetak) {
        std::cout << "Izuzetak: " << izuzetak.what() << std::endl;
    } catch(std::logic_error izuzetak) {
        std::cout << "Izuzetak: " << izuzetak.what() << std::endl;
    }
    return 0;
}
