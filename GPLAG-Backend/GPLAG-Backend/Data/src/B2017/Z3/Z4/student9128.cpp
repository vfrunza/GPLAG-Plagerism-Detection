#include <iostream>
#include <list>
#include <utility>
#include <string>
#include <map>
#include <stdexcept>
#include <queue>
#include <vector>
#include <algorithm>
#include <iterator>
#include <cstring>

using std::cout;
using std::cin;

enum class Boje {Pik, Tref, Herc, Karo};

typedef std::list<std::pair<Boje, std::string>> Karte;

void SortirajSpil(Karte &spil) {
    spil.sort([](std::pair<Boje, std::string> karta1, std::pair<Boje, std::string> karta2)->bool {
        return int(karta1.first)<int(karta2.first);
    });
    
    auto it(spil.begin());
    for(int i=0; i<4; i++) {
        while(it!=spil.end() && it->first==Boje(i)) {
            auto min(it);
            auto it2(it);
            it2++;
            while(it2!=spil.end() && it2->first==Boje(i)) {
                int pomocna1, pomocna2;
                if(it2->second=="J") pomocna1=11; else if(it2->second=="Q") pomocna1=12; else if(it2->second=="K") pomocna1=13; else if(it2->second=="A") pomocna1=14;
                else pomocna1=std::stoi(it2->second);
            
                if(min->second=="J") pomocna2=11; else if(min->second=="Q") pomocna2=12; else if(min->second=="K") pomocna2=13; else if(min->second=="A") pomocna2=14;
                else pomocna2=std::stoi(min->second);
            
                if(pomocna1<pomocna2) min=it2;
                it2++;
            }
            auto temp(*min);
            *min=*it;
            *it=temp;
        
            it++;
        }
    }
}

int PorediKarte(std::pair<Boje, std::string> card1, std::pair<Boje, std::string> card2) {
    if(int(card1.first)>int(card2.first)) return 1;
    else if(int(card1.first)<int(card2.first)) return 2;
    
    int pomocna1, pomocna2;
    if(card1.second=="J") pomocna1=11;
    else if(card1.second=="Q") pomocna1=12;
    else if(card1.second=="K") pomocna1=13;
    else if(card1.second=="A") pomocna1=14;
    else pomocna1=std::stoi(card1.second);
    
    if(card2.second=="J") pomocna2=11;
    else if(card2.second=="Q") pomocna2=12;
    else if(card2.second=="K") pomocna2=13;
    else if(card2.second=="A") pomocna2=14;
    else pomocna2=std::stoi(card2.second);
    
    if(pomocna1>pomocna2) return 1;
    else if(pomocna1<pomocna2) return 2;
    
    return 3;
}

bool JeLiSortiran(const Karte &spil) {
    auto it(spil.begin());
    auto it2(spil.begin());
    it2++;
    
    while(it!=spil.end() && it2!=spil.end()) {
        if(PorediKarte((*it), (*it2))==1) return false;
        it++;
        it2++;
    }
    return true;
}

void IspisSpila(const Karte &spil) {
    cout<<"U spilu trenutno ima "<<spil.size()<<" karata, i to:\n";
    
    std::vector<std::string> v {"Pik", "Tref", "Herc", "Karo"};
    auto it(spil.begin());
    for(int i=0; i<4; i++) {
        cout<<v[i]<<": ";
        while(it!=spil.end() && it->first==Boje(i)) {
            cout<<it->second<<" ";
            it++;
        }
        cout<<"\n";
    }
}

bool RegularnostKarte(std::pair<Boje, std::string> karta) {
    if(karta.first!=Boje::Pik && karta.first!=Boje::Tref && karta.first!=Boje::Herc && karta.first!=Boje::Karo) return false;
    if(karta.second=="J" || karta.second=="Q" || karta.second=="A" || karta.second=="K") return true;
    
    for(int i=1; i<10; i++) {
        if(std::to_string(i+1)==karta.second) return true;
    }
    return false;
}

bool RegularnostPara(std::pair<std::string, std::string> par) {
    if(par.first!="Pik" && par.first!="Tref" && par.first!="Herc" && par.first!="Karo") return false;
    if(par.second=="J" || par.second=="Q" || par.second=="A" || par.second=="K") return true;
    
    for(int i=1; i<10; i++) {
        if(std::to_string(i+1)==par.second) return true;
    }
    return false;
}

Karte KreirajSpil () {
    Karte povratne;
    povratne.resize(52);
    
    auto it(povratne.begin());
    int i(1);
    while(it!=povratne.end() && i!=14) {
        if(i<10) {
            *it=std::make_pair(Boje::Pik, std::to_string(i+1));
        } else {
            if(i==10) *it=std::make_pair(Boje::Pik, "J");
            if(i==11) *it=std::make_pair(Boje::Pik, "Q");
            if(i==12) *it=std::make_pair(Boje::Pik, "K");
            if(i==13) *it=std::make_pair(Boje::Pik, "A");
        }
        it++;
        i++;
    }

    i=1;
    
    while(it!=povratne.end() && i!=14) {
        if(i<10) {
            *it=std::make_pair(Boje::Tref, std::to_string(i+1));
        } else {
            if(i==10) *it=std::make_pair(Boje::Tref, "J");
            if(i==11) *it=std::make_pair(Boje::Tref, "Q");
            if(i==12) *it=std::make_pair(Boje::Tref, "K");
            if(i==13) *it=std::make_pair(Boje::Tref, "A");
        }
        it++;
        i++;
    }
    
    i=1;
    
    while(it!=povratne.end() && i!=14) {
        if(i<10) {
            *it=std::make_pair(Boje::Herc, std::to_string(i+1));
        } else {
            if(i==10) *it=std::make_pair(Boje::Herc, "J");
            if(i==11) *it=std::make_pair(Boje::Herc, "Q");
            if(i==12) *it=std::make_pair(Boje::Herc, "K");
            if(i==13) *it=std::make_pair(Boje::Herc, "A");
        }
        it++;
        i++;
    }

    i=1;
    
    while(it!=povratne.end() && i!=14) {
        if(i<10) {
            *it=std::make_pair(Boje::Karo, std::to_string(i+1));
        } else {
            if(i==10) *it=std::make_pair(Boje::Karo, "J");
            if(i==11) *it=std::make_pair(Boje::Karo, "Q");
            if(i==12) *it=std::make_pair(Boje::Karo, "K");
            if(i==13) *it=std::make_pair(Boje::Karo, "A");
        }
        it++;
        i++;
    }
    return povratne;
}

void IzbaciKarte(Karte &karte, std::multimap<Boje, std::string> izbaci) {
    if(karte.size()>52) throw std::logic_error("Neispravna lista!");
    
    if(!JeLiSortiran(karte)) throw std::logic_error("Neispravna lista!");
    
    auto it(izbaci.begin());
    bool pomjerio_se(false);
    
    while(it!=izbaci.end()) {
        pomjerio_se=false;
        std::pair<Boje, std::string> pomocna(std::make_pair((*it).first, (*it).second));
        auto it_karte(karte.begin());
        while(it_karte!=karte.end()) {
            if(!RegularnostKarte(*it_karte)) throw std::logic_error("Neispravna lista!");
            if(pomocna==*it_karte) {
                it_karte=karte.erase(it_karte);
                it=izbaci.erase(it);
                pomjerio_se=true;
            }
            it_karte++;
        }
        if(!pomjerio_se) it++;
    }
}

std::queue<std::pair<std::string, std::string>> IzbaciKarteRazbrajanjem(Karte &spil, const short int &korak, const int &koliko_karata) {
    if(korak<1 || korak>52 || koliko_karata<1) throw std::logic_error("Neispravni elementi za izbacivanje!");
    
    if(!JeLiSortiran(spil)) throw std::logic_error("Neispravna lista!");
    
    auto it1(spil.begin());
    while(it1!=spil.end()) {
        if(!RegularnostKarte((*it1))) throw std::logic_error("Neispravna lista!");
        it1++;
    }
    
    std::queue<std::pair<std::string, std::string>> povratni;
    std::vector<std::string> v {"Pik", "Tref", "Herc", "Karo"};
    
    auto it(spil.begin());
    int brojac(0);
    
    while(brojac!=koliko_karata && !spil.empty()) {
        int udaljenost(std::distance(it, spil.end()));
        if(udaljenost<korak) {
            it=spil.begin();
            std::advance(it, korak-udaljenost-1);
        } else if(udaljenost-1==korak) {
            it=spil.begin();
        } else {
            std::advance(it, korak-1);
        }
        std::pair<std::string, std::string> pomocni(v.at(int(it->first)), it->second);
        povratni.push(pomocni);
        it=spil.erase(it);
        brojac++;
    }
    return povratni;
}

void VratiPrvihNKarata(Karte &spil, std::queue<std::pair<std::string, std::string>> &red, int n) {
    if(n>int(red.size())) throw std::range_error("Nedovoljno karata u redu!");
    if(n<0) throw std::domain_error("Broj n je besmislen!");
    if(spil.size()>52) throw std::logic_error("Neispravne karte!");
    
    if(!JeLiSortiran(spil)) throw std::logic_error("Neispravna lista!");
    
    std::vector<std::string> v {"Pik", "Tref", "Herc", "Karo"};
    
    while(n!=0) {
        if(!RegularnostPara(red.front())) throw std::logic_error("Neispravne karte!");
        else {
            auto it(spil.end());
            std::pair<Boje, std::string> pomocni;
            for(int i=0; i<4; i++) {
                if(v[i]==red.front().first) pomocni.first=Boje(i);
            }
            pomocni.second=red.front().second;
            it=spil.insert(it, pomocni);
            red.pop();
        }
        n--;
    }
    SortirajSpil(spil);
}

int main ()
{
    auto karte(KreirajSpil());
    int korak, broj_karata;
    cout<<"Unesite korak razbrajanja: ";
    cin>>korak;
    cout<<"Unesite broj karata koje zelite izbaciti: ";
    cin>>broj_karata;
    std::queue<std::pair<std::string, std::string>> izbacene;
    
    try {
        izbacene=IzbaciKarteRazbrajanjem(karte, korak, broj_karata);
        IspisSpila(karte);
        try {
            int broj_vracenih;
            cout<<"Unesite broj karata koje zelite vratiti u spil: ";
            cin>>broj_vracenih;
            VratiPrvihNKarata(karte, izbacene, broj_vracenih);
            IspisSpila(karte);
        } catch(std::range_error izuzetak) {
            cout<<"Izuzetak: "<<izuzetak.what();
        } catch(std::domain_error izuzetak) {
            cout<<"Izuzetak: "<<izuzetak.what();
        } catch(std::logic_error izuzetak) {
            cout<<"Izuzetak: "<<izuzetak.what();
        }
    } catch(std::logic_error izuzetak) {
        cout<<"Izuzetak: "<<izuzetak.what();
    } 
    
    
	return 0;
}
