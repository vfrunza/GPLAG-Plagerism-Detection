/B2017/2018: Zadaća 3, Zadatak 4
#include <iostream>
#include <list>
#include <utility>
#include <map>
#include <stdexcept>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>

enum class Boje
{
    Pik, Tref, Herc, Karo
};

typedef std::pair<Boje, std::string> par;
std::vector<std::string> NazivKarata {"2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K", "A"};

std::list<par> KreirajSpil ()
{
    std::list<par> spil;
    par p;
    Boje boja;
    boja = Boje::Pik;
    for(auto a : NazivKarata) {
        p = std::make_pair (boja, a);
        spil.push_back (p);
    }
    boja = Boje::Tref;
    for(auto a : NazivKarata) {
        p = std::make_pair (boja, a);
        spil.push_back (p);
    }
    boja = Boje::Herc;
    for(auto a : NazivKarata) {
        p = std::make_pair (boja, a);
        spil.push_back (p);
    }
    boja = Boje::Karo;
    for(auto a : NazivKarata) {
        p = std::make_pair (boja, a);
        spil.push_back (p);
    }
    return spil;
}
void NeispravneKarte (const std::queue<std::pair<std::string, std::string>> &red)
{
    std::queue<std::pair<std::string, std::string>> pomocni = red;
    while ( !pomocni.empty() ) {
        std::pair<std::string, std::string> p = pomocni.front();
        if (p.first != "Pik" && p.first != "Tref" && p.first != "Karo" && p.first != "Herc") throw std::logic_error("Neispravne karte!");
        bool a = false;
        for (int i = 0; i< NazivKarata.size(); i++) {
            if (NazivKarata.at(i) == p.second) a = true;
        }
        if (a == false) throw std::logic_error ("Neispravne karte!");
        pomocni.pop();
    }
}
void Izuzeci(const std::list<par> &spil)
{
    if(spil.size() > 52) throw std::logic_error("Neispravna lista!");
    for(auto x : spil) {
        bool smislen = false;
        for(int i = 0; i < NazivKarata.size(); i++) {
            if(x.second == NazivKarata.at(i)) smislen = true;
        }
        if(smislen == false) throw std::logic_error("Neispravna lista!");
    }
    Boje boja;
    for(auto it = spil.begin(); it != spil.end(); it++) {
        boja = (*it).first;
        while(it != spil.end() && (*it).first == boja) {
            auto pomocni = it;
            it++;
            if(it == spil.end() || (*it).first != boja) break;
            auto nazivPomocni(std::find(NazivKarata.begin(), NazivKarata.end(), (*pomocni).second)), nazivIt(std::find(NazivKarata.begin(), NazivKarata.end(), (*it).second));
            if(nazivPomocni >= nazivIt) throw std::logic_error("Neispravna lista!");
        }
        if(boja == Boje::Karo && it != spil.end()) throw std::logic_error("Neispravna lista!");
        for(auto it2 = it; it2 != spil.end(); it2++) {
            if(boja == Boje::Pik) {
                if((*it2).first == Boje::Pik) throw std::logic_error("Neispravna lista!");
            } else if(boja == Boje::Tref) {
                if((*it2).first == Boje::Pik || (*it2).first == Boje::Tref) throw std::logic_error("Neispravna lista!");
            } else if(boja == Boje::Herc) {
                if((*it2).first == Boje::Pik || (*it2).first == Boje::Tref || (*it2).first == Boje::Herc) throw std::logic_error("Neispravna lista!");
            }
        }
        if(it == spil.end()) break;
    }
}

void IzbaciKarte(std::list<par> &spil, std::multimap<Boje, std::string> &m)
{
    Izuzeci(spil);
    for(auto it = m.begin(); it != m.end();) {
        bool pronadjena(false);
        for (auto iter = spil.begin(); iter != spil.end();) {
            if ((*it).first == (*iter).first && (*it).second == (*iter).second) {
                iter = spil.erase(iter);
                it = m.erase(it);
                pronadjena = true;
                break;
            }
            else {
                iter++;
            }
        }
        if(pronadjena == false) it++;
    }
}

std::queue<std::pair<std::string, std::string>> IzbaciKarteRazbrajanjem (std::list<par> &spil, const short int &r, const int &b)
{
    if (r < 1 || r > 52 || b < 1) throw std::logic_error ("Neispravni elementi za izbacivanje!");
    Izuzeci(spil);
    std::queue<std::pair<std::string, std::string>> red;
    int broj_izbacenih = 0;
    std::list<par>::iterator it(spil.begin());
    while(broj_izbacenih != b && spil.size() != 0) {
        for(int i(0); i < r - 1; i++) {
            it++;
            if(it == spil.end()) it = spil.begin();
        }
        std::pair<std::string, std::string> element_reda;
        if((*it).first == Boje::Pik) element_reda.first = "Pik";
        else if((*it).first == Boje::Tref) element_reda.first = "Tref";
        else if((*it).first == Boje::Herc) element_reda.first = "Herc";
        else element_reda.first = "Karo";
        element_reda.second = (*it).second;
        red.push(element_reda);
        it = spil.erase(it);
        if(it == spil.end()) it = spil.begin();
        broj_izbacenih++;
    }
    return red;
}

void VratiPrvihNKarata ( std::list<par> &spil, std::queue<std::pair<std::string, std::string>> &red, int n)
{
    if (n < 0 ) throw std::domain_error ("Broj n je besmislen!");
    if ( n > red.size()) throw std::range_error ("Nedovoljno karata u redu!");
    Izuzeci(spil);
    NeispravneKarte(red);

    std::pair<std::string, std::string> p;
    par p1;
    for( int i = 0; i < n; i++) {
        p = red.front();
        red.pop();
        if(p.first == "Pik") p1.first = Boje::Pik;
        else if(p.first == "Tref") p1.first = Boje::Tref;
        else if(p.first == "Karo") p1.first = Boje::Karo;
        else p1.first = Boje::Herc;
        for( int j = 0; j < NazivKarata.size(); j++) {
            if ( p.second == NazivKarata.at(j)) p1.second = NazivKarata.at(j);
        }
        auto iter = std::find(spil.begin(), spil.end(), p1);
        if ( iter != spil.end()) {
            continue;
        }
        auto it = spil.begin();
        bool ubacena(false);
        for (it = spil.begin(); it != spil.end(); it++) {
            if(it != spil.end() && p1.first > (*it).first ) continue;

            else if ( it != spil.end() && p1.first == (*it).first ) {
                auto p1it = std::find(NazivKarata.begin(), NazivKarata.end(), p1.second);
                ubacena = false;
                auto itkrozboje(it);
                for(itkrozboje = it; (*itkrozboje).first == (*it).first; itkrozboje++) {
                    auto itit = std::find(NazivKarata.begin(), NazivKarata.end(), (*itkrozboje).second);
                    if(p1it > itit) continue;
                    spil.insert(itkrozboje, p1);
                    ubacena = true;
                    break;
                }
                if(ubacena == false) spil.insert(itkrozboje, p1);
                break;
            } 
            else if (p1.first < (*it).first) {
                it = spil.insert(it,p1);
                break;
            }
        }
        if(it == spil.end() && ubacena == false) {
            it = spil.insert(it, p1);
        }
        if(spil.size() == 0) {
            it = spil.insert(spil.begin(), p1);
        }
    }
}

int main ()
{
    try {
        auto spil = KreirajSpil();
        std::cout<<"Unesite korak razbrajanja: ";
        int r;
        std::cin>>r;
        std::cout<<"Unesite broj karata koje zelite izbaciti: ";
        int b;
        std::cin>>b;
        std::queue<std::pair<std::string, std::string>>red;
        red = IzbaciKarteRazbrajanjem(spil, r, b);
        std::cout<<"U spilu trenutno ima "<<spil.size()<<" karata, i to:"<<std::endl;
        std::cout << "Pik: ";
        for(auto element : spil ) {
            if(element.first == Boje::Pik)
                std::cout<<element.second << " ";
        }
        std::cout<<std::endl;
        std::cout << "Tref: ";
        for(auto element :spil) {
            if(element.first == Boje::Tref)
                std::cout<<element.second << " ";
        }
        std::cout<<std::endl;
        std::cout << "Herc: ";
        for(auto element :spil) {
            if(element.first == Boje::Herc)
                std::cout<<element.second << " ";
        }
        std::cout<<std::endl;
        std::cout << "Karo: ";
        for(auto element : spil)
            if(element.first == Boje::Karo)
                std::cout<<element.second << " ";
        std::cout<<std::endl;
        std::cout<<"Unesite broj karata koje zelite vratiti u spil: ";
        int n;
        std::cin>>n;
        VratiPrvihNKarata(spil, red, n);
        std::cout<<"U spilu trenutno ima "<<spil.size()<<" karata, i to:"<<std::endl;
        std::cout << "Pik: ";
        for(auto element : spil ) {
            if(element.first == Boje::Pik)
                std::cout<<element.second << " ";
        }
        std::cout<<std::endl;
        std::cout << "Tref: ";
        for(auto element :spil) {
            if(element.first == Boje::Tref)
                std::cout<<element.second << " ";
        }
        std::cout<<std::endl;
        std::cout << "Herc: ";
        for(auto element :spil) {
            if(element.first == Boje::Herc)
                std::cout<<element.second << " ";
        }
        std::cout<<std::endl;
        std::cout << "Karo: ";
        for(auto element : spil)
            if(element.first == Boje::Karo)
                std::cout<<element.second << " ";
        std::cout<<std::endl;

    } catch(std::logic_error e) {
        std::cout<<"Izuzetak: "<<e.what()<<std::endl;
    } catch(std::range_error e) {
        std::cout<<"Izuzetak: "<<e.what()<<std::endl;
    }
    return 0;
}
