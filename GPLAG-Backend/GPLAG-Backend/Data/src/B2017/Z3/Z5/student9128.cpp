#include <iostream>
#include <string>
#include <map>
#include <stack>
#include <vector>
#include <stdexcept>
#include <cstring>

using std::cout;
using std::cin;

enum class Boje {Pik, Tref, Herc, Karo};

struct Karta {
    Boje boja;
    std::string vrijednost;
};

struct Cvor {
    Karta karta;
    Cvor *sljedeci;
};

void PostaviNaKraj(Cvor *pocetak, Cvor *(&kraj)) {
    if(pocetak==nullptr) return;
    auto p(pocetak);
    for(;;) {
        if(p->sljedeci==pocetak) kraj=p;
        p=p->sljedeci;
        if(p==pocetak) break;
    }
}

int VelicinaSpila(Cvor *pocetak) {
    auto p(pocetak);
    if(p==nullptr) return 0;
    int velicina(0);
    for(;;) {
        p=p->sljedeci;
        velicina++;
        if(p==pocetak) break;
    }
    return velicina;
}

int PorediKarte(Karta card1, Karta card2) {
    if(int(card1.boja)>int(card2.boja)) return 1;
    else if(int(card1.boja)<int(card2.boja)) return 2;
    
    int pomocna1, pomocna2;
    if(card1.vrijednost=="J") pomocna1=11; 
    else if(card1.vrijednost=="Q") pomocna1=12;
    else if(card1.vrijednost=="K") pomocna1=13;
    else if(card1.vrijednost=="A") pomocna1=14;
    else pomocna1=std::stoi(card1.vrijednost);
    
    if(card2.vrijednost=="J") pomocna2=11; 
    else if(card2.vrijednost=="Q") pomocna2=12;
    else if(card2.vrijednost=="K") pomocna2=13;
    else if(card2.vrijednost=="A") pomocna2=14;
    else pomocna2=std::stoi(card2.vrijednost);
    
    if(pomocna1>pomocna2) return 1;
    else if(pomocna1<pomocna2) return 2;
    
    return 3;
}

bool JeLiSortiran(Cvor *pocetak) {
    if(pocetak==nullptr) return true;
    auto p(pocetak);
    for(;;) {
        if(p->sljedeci==pocetak) break;
        if(PorediKarte(p->karta, p->sljedeci->karta)==1) return false;
        p=p->sljedeci;
    }
    return true;
}

bool TestirajKruznost(Cvor *pocetak) {
    if(pocetak==nullptr) return true;
    auto p(pocetak);
    for(int i=0; i<52; i++) {
        p=p->sljedeci;
        if(p==pocetak) return true;
    }
    return false;
}

bool JednakeKarte(Karta card1, Karta card2) {
    return card1.boja==card2.boja && card1.vrijednost==card2.vrijednost;
}

bool RegularnostKarte(Karta karta) {
    if(karta.boja!=Boje::Pik && karta.boja!=Boje::Tref && karta.boja!=Boje::Herc && karta.boja!=Boje::Karo) return false;
    if(karta.vrijednost=="J" || karta.vrijednost=="Q" || karta.vrijednost=="A" || karta.vrijednost=="K") return true;
    
    for(int i=0; i<10; i++) {
        if(std::to_string(i+1)==karta.vrijednost) return true;
    }
    return false;
}
Cvor* KreirajSpil() {
    Cvor *pocetak(nullptr), *prethodni;
    int boja(0);
    for(int i=1; i<14; i++) {
        Karta pomocna;
        pomocna.boja=Boje(boja);
        if(i<10) pomocna.vrijednost=std::to_string(i+1);
        else {
            if(i==10) pomocna.vrijednost="J";
            if(i==11) pomocna.vrijednost="Q";
            if(i==12) pomocna.vrijednost="K";
            if(i==13) pomocna.vrijednost="A";
        }
        Cvor *novi(new Cvor{pomocna, nullptr});
        if(!pocetak) pocetak=novi;
        else prethodni->sljedeci = novi;
        prethodni=novi;
        if(boja==3 && i==13) novi->sljedeci=pocetak;
        if(i==13) {
            boja++;
            if(boja==4) break;
            else i=0;
        }
    }
    return pocetak;
}

void IzbaciKarte(Cvor *(&pocetak), std::multimap<Boje, std::string> izbaci) {
    if(VelicinaSpila(pocetak)>52) throw std::logic_error("Neispravna lista!");
    if(!JeLiSortiran(pocetak)) throw std::logic_error("Neispravna lista!");
    auto it(izbaci.begin());
    
    while(it!=izbaci.end()) {
        Karta pomocna{it->first, it->second};
        
        auto p(pocetak);
        Cvor *p_before;
        PostaviNaKraj(pocetak, p_before);
        
        if(!TestirajKruznost(pocetak)) throw std::domain_error("Neispravna lista");
        for(int i=0; i<52; i++) {
            if(!RegularnostKarte(p->karta)) throw std::logic_error("Neispravna lista");
            
            if(JednakeKarte(pomocna, p->karta)) {
                Cvor *pomocni(p->sljedeci);
                if(p==pocetak) pocetak=pomocni;
                if(p==p->sljedeci) {
                    delete p;
                    pocetak=nullptr;
                } else {
                    delete p;
                    p=pomocni;
                    p_before->sljedeci=p;
                }
            }
            if(p->sljedeci==pocetak) break;
            if(p==nullptr) break;
            p_before=p_before->sljedeci;
            p=p->sljedeci;
        }
        it++;
    }
}

std::stack<std::pair<std::string, std::string>> IzbaciKarteRazbrajanjem(Cvor *(&pocetak), const short int &korak, const int &koliko_karata) {
    if(korak<1 || korak>52 || koliko_karata<1) throw std::logic_error("Neispravni elementi za izbacivanje!");
    if(VelicinaSpila(pocetak)>52) throw std::logic_error("Neispravna lista!");
    if(!JeLiSortiran(pocetak)) throw std::logic_error("Neispravna lista!");
    auto bezvezni(pocetak);
    for(int i=0; i<52; i++) {
        if(!RegularnostKarte(bezvezni->karta)) throw std::logic_error("Neispravna lista!");
        bezvezni=bezvezni->sljedeci;
        if(bezvezni==pocetak) break;
    }
    
    std::stack<std::pair<std::string, std::string>> povratni;
    std::vector<std::string> v {"Pik", "Tref", "Herc", "Karo"};
    
    int brojac(0);
    Cvor *p_before;
    PostaviNaKraj(pocetak, p_before);
    auto p(pocetak);
    
    if(!TestirajKruznost(pocetak)) throw std::domain_error("Neispravna lista");
    
    while(brojac!=koliko_karata && pocetak!=nullptr) {
        
        for(int i=1; i<korak; i++) {
            p=p->sljedeci;
            p_before=p_before->sljedeci;
        }
        
        std::pair<std::string, std::string> pomocni(v.at(int(p->karta.boja)), p->karta.vrijednost);
        povratni.push(pomocni);
        
        Cvor *help(p->sljedeci);
        if(p==pocetak) pocetak=help;
        if(p==p->sljedeci) {
            delete p;
            pocetak=nullptr;
        } else {
            delete p;
            p=help;
            p_before->sljedeci=p;
        }
        brojac++;
    }
    return povratni;
}

void VratiPosljednjihNKarata(Cvor *(&pocetak), std::stack<std::pair<std::string, std::string>> &stek, int n) {
    if(n>int(stek.size())) throw std::range_error("Nedovoljno karata u steku!");
    if(n<0) throw std::domain_error("Broj n je besmislen!");
    if(VelicinaSpila(pocetak)>52) throw std::logic_error("Neispravne karte!");
    if(!JeLiSortiran(pocetak)) throw std::logic_error("Neispravna lista!");
    
    std::vector<std::string> v {"Pik", "Tref", "Herc", "Karo"};
    
    while(n!=0) {
        Karta pomocna;
        for(int i=0; i<4; i++) 
            if(v[i]==stek.top().first) pomocna.boja=Boje(i);
        pomocna.vrijednost=stek.top().second;
        if(!RegularnostKarte(pomocna)) throw std::logic_error("Neispravne karte!");
        
        auto p(pocetak);
        Cvor *p_before;
        PostaviNaKraj(pocetak, p_before);
        if(pocetak==nullptr) {
            auto novi(new Cvor{pomocna});
            pocetak=novi;
            pocetak->sljedeci=pocetak;
        }
        else if(PorediKarte(p->karta, pomocna)==3 || PorediKarte(p_before->karta, pomocna)==3) {
            stek.pop();
            n--;
            continue;
        }
        else if(p==p->sljedeci) {
            if(PorediKarte(p->karta, pomocna)==1) {
                auto novi(new Cvor{pomocna});
                pocetak=novi;
                p=novi;
                p->sljedeci=p_before;
                p_before->sljedeci=p;
            } else if(PorediKarte(p->karta, pomocna)==2) {
                auto novi(new Cvor{pomocna});
                p_before=novi;
                p_before->sljedeci=p;
                p->sljedeci=p_before;
            }
        } else if(PorediKarte(pocetak->karta, pomocna)==1) {
            auto novi(new Cvor{pomocna});
            pocetak=novi;
            p_before->sljedeci=pocetak;
            pocetak->sljedeci=p;
        } else if(PorediKarte(p_before->karta, pomocna)==2) {
            auto novi(new Cvor{pomocna});
            p_before->sljedeci=novi;
            novi->sljedeci=pocetak;
        }
        
    else for(;;) {
            if(PorediKarte(p->karta, pomocna)==3 || PorediKarte(p_before->karta, pomocna)==3 || PorediKarte(p->sljedeci->karta, pomocna)==3) break;
            if(PorediKarte(p->karta, pomocna)==2 && PorediKarte(pomocna, p->sljedeci->karta)==2) {
                auto novi(new Cvor{pomocna});
                auto pomocni(p->sljedeci);
                p->sljedeci=novi;
                novi->sljedeci=pomocni;
            }
            p=p->sljedeci;
            p_before=p_before->sljedeci;
            if(p==pocetak) break;
        }
        stek.pop();
        n--;
    }
}

void IspisSpila(Cvor *pocetak) {
    int i(0);
    auto p(pocetak);
    if(pocetak==nullptr) i=0;
    for(i=0; i<52; i++) {
        if(pocetak==nullptr) { i=-1; break; };
        p=p->sljedeci;
        if(p==pocetak) break;
    }
    i++;
    
    std::cout<<"U spilu trenutno ima "<<i<<" karata, i to:\n";
    
    p=pocetak;
    std::vector<std::string> v {"Pik", "Tref", "Herc", "Karo"};
    for(int i=0; i<4; i++) {
        cout<<v[i]<<": ";
        while( p!=nullptr && p->karta.boja==Boje(i)) {
            std::cout<<p->karta.vrijednost<<" ";
            p=p->sljedeci;
            if(p==pocetak) break;
        }
        std::cout<<"\n";
    }
}

void UnistiSpil(Cvor *pocetak) {
    Cvor *pomocni;
    auto p(pocetak);
    for(int i=0; i<52; i++) {
        pomocni=p->sljedeci;
        delete p;
        p=pomocni;
        if(p==pocetak) break;
    }
}

int main ()
{
    auto lista(KreirajSpil());
    int korak, broj_karata;
    std::multimap<Boje, std::string> izbaci{{Boje::Herc, "J"}, {Boje::Pik, "2"}};
    IzbaciKarte(lista, izbaci);
    IspisSpila(lista);
    cout<<"Unesite korak razbrajanja: ";
    cin>>korak;
    cout<<"Unesite broj karata koje zelite izbaciti: ";
    cin>>broj_karata;
    std::stack<std::pair<std::string, std::string>> izbacene;
    
    try {
        izbacene=IzbaciKarteRazbrajanjem(lista, korak, broj_karata);
        IspisSpila(lista);
        try {
            int broj_vracenih;
            cout<<"Unesite broj karata koje zelite vratiti u spil: ";
            cin>>broj_vracenih;
            VratiPosljednjihNKarata(lista, izbacene, broj_vracenih);
            IspisSpila(lista);
        } catch(const std::exception &ex) {
            cout<<"Izuzetak: "<<ex.what();
        }
    } catch(std::logic_error izuzetak) {
        cout<<"Izuzetak: "<<izuzetak.what();
    }
    UnistiSpil(lista);
    return 0;
}
