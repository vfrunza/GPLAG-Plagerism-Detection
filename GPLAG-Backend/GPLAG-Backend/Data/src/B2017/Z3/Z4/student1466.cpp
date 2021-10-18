/B2017/2018: Zadaća 3, Zadatak 4
#include <iostream>
#include <list>
#include <map>
#include <utility>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
#include <stdexcept>
#include <iterator>
enum class Boje
{
    Pik=0, Tref, Herc, Karo
};
typedef std::list<std::pair<Boje,std::string>> Spil;
typedef std::queue<std::pair<std::string, std::string>> Deck;
Spil KreirajSpil ()
{
    Spil karte;
    std::vector<std::string> brojevi;
    brojevi= {"2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K", "A"};
    for(int i=0; i<4; i++) {
        for(int j=0; j<brojevi.size(); j++) {
            karte.push_back(std::make_pair(Boje(i), brojevi[j]));

        }
    }
    return karte;
}
void IzbaciKarte (Spil &karte, std::multimap<Boje, std::string> &mapa)
{
    if(karte.size()>52) throw std::logic_error ("Neispravna lista!");
    auto savrsen_spil(KreirajSpil());
    auto poc(karte.begin());
    while(poc!=karte.end()) {
        auto provjera(std::find(savrsen_spil.begin(), savrsen_spil.end(), *poc));
        if(provjera==savrsen_spil.end()) throw std::logic_error ("Neispravna lista!");
        poc++;
    }

    auto it=mapa.begin();
    while(it!=mapa.end()) {
        auto pok=karte.begin();
        while(pok!=karte.end()) {
            if(pok->first==it->first && pok->second==it->second) {
                auto x=*it;
                auto poc(it);
                do{
                    poc=mapa.erase(poc);
                    poc=std::find(mapa.begin(), mapa.end(), x);
                }while (poc!=mapa.end());
                pok=karte.erase(pok);
                it=mapa.begin();
            }
            pok++;
        }
        it++;
    }
}
void IspisSpila(Spil &karte)
{
    auto it=karte.begin();
    it++;
    auto prije=karte.begin();
    std::vector<std::string> ispis ({"Pik", "Tref", "Herc", "Karo"});
    while(prije!=karte.end()) {
        bool preskoci(false);
        if((prije==std::begin(karte) || (it!=karte.end() && prije->first<it->first))) {
            if(prije!=karte.begin())
                std::cout<<prije->second<<" ";

            if(prije!=karte.begin()) {
                preskoci=true;
                it++;
                prije++;
            }
            std::cout<<std::endl<<ispis.at(int(prije->first))<<": ";
        }
        if(preskoci) continue;
        std::cout<<prije->second<<" ";
        it++;
        prije++;
    }
}
Deck IzbaciKarteRazbrajanjem(Spil &karte, const short int &r, const int &b)
{
    if(!(r>=1 && r<=52) || b<1) throw std::logic_error ("Neispravni elementi za izbacivanje!");
    if(karte.size()>52) throw std::logic_error ("Neispravna lista!");
    auto savrsen_spil(KreirajSpil());
    auto poc(karte.begin());
    while(poc!=karte.end()) {
        auto provjera(std::find(savrsen_spil.begin(), savrsen_spil.end(), *poc));
        if(provjera==savrsen_spil.end()) throw std::logic_error ("Neispravna lista!");
        poc++;
    }
    std::vector<std::string> vrsta ({"Pik", "Tref", "Herc", "Karo"});
    Deck outcast;
    auto it(karte.begin());
    int i(0);
    while(it!=karte.end() && i<b) {
        int j(1);
        auto kraj(karte.end());
        kraj--;
        while(it!=karte.end() && j<r) {
            it++;
            j++;
            if(it==karte.end()) it=karte.begin();
        }
        outcast.push(std::make_pair(vrsta[int(it->first)], it->second));
        it=karte.erase(it);
        if(it==karte.end()) it=karte.begin();
        i++;
    }
    return outcast;
}
void VratiPrvihNKarata (Spil &karte, Deck &red, int n)
{
    if(!(n>=0 && n<=52)) throw std::domain_error ("Broj n je besmislen!");
    if(n>red.size()) throw std::range_error ("Nedovoljno karata u redu!");
    if(karte.size()>52) throw std::logic_error ("Neispravna lista!");
    auto savrsen_spil(KreirajSpil());
    auto poc(karte.begin());
    while(poc!=karte.end()) {
        auto provjera(std::find(savrsen_spil.begin(), savrsen_spil.end(), *poc));
        if(provjera==savrsen_spil.end()) throw std::logic_error ("Neispravna lista!");
        poc++;
    }
    std::vector<std::string> imena({"Pik", "Tref", "Herc", "Karo"});
    std::vector<std::string> brojevi({"2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K", "A"});
    int i(0);
    while(!(red.empty()) && i<n) {
        auto x=red.front();
        auto pok(std::find(imena.begin(), imena.end(), x.first));
        if(pok==imena.end()) throw std::logic_error ("Neispravne karte!");
        int udaljenost(std::distance(std::begin(imena), pok));
        pok=std::find(brojevi.begin(), brojevi.end(), x.second);
        if(pok==brojevi.end()) throw std::logic_error ("Neispravne karte!");
        auto y=std::make_pair(Boje(udaljenost), x.second);
        
        auto it(karte.begin());
        if(karte.size()==0) karte.insert(it, y);
        while(it!=karte.end()) {
            if(y.first<=it->first) {
                if(y.second=="A") {
                    if(karte.size()!=0)
                        while(it->first==y.first) it++;
                    karte.insert(it, y);
                    break;
                }
                else if(y.second>="10" && y.second<="Z" && it->second>="10" && it->second<="Z") {
                    auto pok1(std::find(brojevi.begin(), brojevi.end(), x.second));
                    int udaljenost1(std::distance(std::begin(brojevi), pok1));
                    auto pok2(std::find(brojevi.begin(), brojevi.end(), it->second));
                    int udaljenost2(std::distance(std::begin(brojevi), pok2));
                    if(udaljenost1<=udaljenost2) {
                        karte.insert(it, y);
                        break;
                    }
                } else if(y.second<it->second) {
                    karte.insert(it, y);
                    break;
                }
            }
            it++;
        }
        red.pop();
        i++;
    }


}
int main ()
{
    Spil karte(KreirajSpil());
    std::cout<<"Unesite korak razbrajanja: ";
    short int a;
    std::cin>>a;
    std::cout <<"Unesite broj karata koje zelite izbaciti: ";
    int b;
    std::cin>>b;
    try {
        Deck qvi(IzbaciKarteRazbrajanjem(karte,a,b));
        std::cout<<"U spilu trenutno ima "<<karte.size()<<" karata, i to:";
        IspisSpila(karte);
        std::cout<<std::endl<<"Unesite broj karata koje zelite vratiti u spil: ";
        int n;
        std::cin>>n;
        try {
            VratiPrvihNKarata(karte, qvi, n);
            std::cout<<"U spilu trenutno ima "<<karte.size()<<" karata, i to:";
            IspisSpila(karte);
        } catch (std::exception& izuzetak) {
            std::cout<<"Izuzetak: "<<izuzetak.what();
        }
        
    } catch(std::exception& izuzetak) {
        std::cout<<"Izuzetak: "<<izuzetak.what();
    }

    return 0;
}
