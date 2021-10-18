/B2017/2018: Zadaća 3, Zadatak 4
#include <iostream>
#include <vector>
#include <string>
#include <list>
#include <utility>
#include <map>
#include <stdexcept>
#include <algorithm>
#include <queue>

enum class Boje
{
    Pik, Tref, Herc, Karo
} ;
const std::vector<std::string> imena {"2","3","4","5","6","7","8","9","10","J","Q","K","A"} ;
const std::vector<std::string> znakovi {"Pik","Tref","Herc","Karo"} ;

typedef std::list<std::pair<Boje, std::string>> spil_karata ;

spil_karata KreirajSpil()
{
    spil_karata lista;
    for(int i=0; i<4; i++) {
        for(int j=0; j<13; j++) {
            std::pair<Boje, std::string> par(Boje(i),imena[j]);
            lista.push_back(par);
        }
    }
    return lista;
}

void IspisiSpil(spil_karata const &spil)
{
    //  std::cout << std::endl;
    std::cout << "U spilu trenutno ima "<< spil.size()<<" karata, i to:" << std::endl;
    for(int i(0); i<4; i++) {
        std::cout << znakovi[i] <<": ";
        for(auto it(spil.begin()); it!=spil.end(); it++) {
            if(it->first==Boje(i)) std::cout << it->second <<" ";
        }
        std::cout << std::endl;
    }
}
void ProvjeriListu(spil_karata const &spil)
{
    if(spil.size()>52) throw std::logic_error("Neispravna lista!");
    for(auto it(spil.begin()); it!=spil.end(); it++) {
        int ok_broj (std::count(imena.begin(), imena.end(), it->second));
        bool ok_boja(false);
        for(int i=0; i<4; i++) if(it->first==Boje(i)) ok_boja=true;
        if(ok_broj==0 || ok_boja==false) throw std::logic_error("Neispravna lista!");
    }
    for(auto it(spil.begin()); it!=spil.end(); it++) {
        int pojavljivanje(std::count(spil.begin(), spil.end(), *it));
        if(pojavljivanje>1) throw std::logic_error("Neispravna lista!");
    }
    
    int velicina(spil.size());
    auto it(spil.begin()); 
    auto naredni(spil.begin());
    naredni++;
    for(int i(0);i<velicina-1;i++){
        if(it->first>naredni->first) throw std::logic_error("Neispravna lista!");
        else if(it->first==naredni->first){
            auto prvi(std::find(imena.begin(), imena.end(), it->second));
            auto drugi(std::find(imena.begin(), imena.end(), naredni->second));
            if(prvi>drugi) throw std::logic_error("Neispravna lista!");
        }
        it++; naredni++;
    }
   
}
void IzbaciKarte(spil_karata &spil, std::multimap<Boje, std::string> multim)
{
    ProvjeriListu(spil);
    if(spil.size()==0) throw std::logic_error("Neispravna lista!");
    for(auto it(multim.begin()); it!=multim.end(); it++) {
        std::pair<Boje, std::string> par;
        par.first=it->first;
        par.second=it->second;
        auto u_spilu(std::find(spil.begin(),spil.end(),par));
        if(u_spilu!=spil.end()) {
            it=multim.erase(it);
            u_spilu=spil.erase(u_spilu);
            it--;
        }
    }
}
std::queue<std::pair<Boje, std::string>> IzbaciKarteRazbrajanjem(spil_karata &spil, short int r, int b)
{
    if(r<1 || r>52 || b<1) throw std::logic_error("Neispravni elementi za izbacivanje!");
    ProvjeriListu(spil);
    if(spil.size()==0) throw std::logic_error("Neispravna lista!");

    std::queue<std::pair<Boje,std::string>> red ;
    auto it(spil.begin());
    int br(1);
    int bii(0);
    while(br!=r) {
        it++;
        br++;
    }
    while(spil.size()>0 && bii<b) {
        if(it==spil.end()) it=spil.begin();
        if(br%r==0) {
            red.push(*it);
            it=spil.erase(it);
            br++;
            bii++;
        } else {
            it++;
            br++;
        }
    }
    return red;
}

void ProvjeriRed(std::queue<std::pair<Boje, std::string>> red)
{
    while(!red.empty()) {
        auto clan=red.front();
        if(clan.first!=Boje::Tref && clan.first!=Boje::Herc && clan.first!=Boje::Pik && clan.first!=Boje::Karo) throw std::logic_error ("Neispravne karte!");
        bool ok(false);
        for(int i(0); i<imena.size(); i++) if(clan.second==imena[i]) ok=true;
        if(!ok) throw std::logic_error ("Neispravne karte!");
        red.pop();
    }
}

void VratiPrvihNKarata(spil_karata &spil, std::queue<std::pair<Boje, std::string>> &red, int n)
{
    if(n<0) throw std::domain_error ("Broj n je besmislen!");
    if(n>red.size()) throw std::range_error ("Nedovoljno karata u redu!");
    ProvjeriRed(red);
    for(int i(0); i<n; i++) {
        auto element(red.front());
        auto it(spil.begin());
        while(it->first<element.first) it++;
        auto tu(std::find(imena.begin(), imena.end(),element.second));
        while(std::find(imena.begin(), imena.end(),it->second)<tu) it++;
        spil.insert(it, element);
        red.pop();
    }
}

int main ()
{
    spil_karata spil(KreirajSpil());
    try {
        short int korak;
        int broj;
        std::cout << "Unesite korak razbrajanja: " ;
        std::cin >> korak;
        std::cout << "Unesite broj karata koje zelite izbaciti: ";
        std::cin >> broj;
        auto izbacene=IzbaciKarteRazbrajanjem(spil,korak,broj);
        IspisiSpil(spil);
        int vracaj;
        std::cout <<  "Unesite broj karata koje zelite vratiti u spil: ";
        std::cin >> vracaj;
        VratiPrvihNKarata(spil,izbacene,vracaj);
        IspisiSpil(spil);
    } catch(std::logic_error greska) {
        std::cout << "Izuzetak: " << greska.what() << std::endl;
    } catch(std::range_error greska) {
        std::cout << "Izuzetak: " << greska.what() << std::endl;
    }
    return 0;
}
