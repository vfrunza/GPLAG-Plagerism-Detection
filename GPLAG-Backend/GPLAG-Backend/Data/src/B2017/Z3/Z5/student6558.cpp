/B2017/2018: Zadaća 3, Zadatak 5
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <stack>
typedef std::stack<std::pair<std::string, std::string>> Deck;
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
    Cvor* sljedeci;
};
Cvor *KreirajSpil()
{
    Cvor *pocetak(nullptr),*prethodni;
    std::vector<std::string> imena({"2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K", "A"});
    for(int i(0); i<4; i++) {
        for(int j(0); j<imena.size(); j++) {
            Cvor *novi(new Cvor {{Boje(i), imena.at(j)}, pocetak});
            if(!pocetak) pocetak=novi;
            else prethodni->sljedeci=novi;
            prethodni=novi;
        }
    }
    return pocetak;
}
void IzbaciKarte(Cvor* &pocetak, std::multimap<Boje, std::string> &mapa)
{
    void ProvjeriSpil(Cvor* pocetak);
    ProvjeriSpil(pocetak);
    auto it(mapa.begin());
    while(it!=mapa.end()) {
        auto p=pocetak;
        for(int i=0; i<52; i++) {
            if(p->karta.boja==it->first && p->karta.vrijednost==it->second) {
                auto x=*it;
                auto pok=it;
                do {
                    pok=mapa.erase(pok);
                    pok=std::find(mapa.begin(), mapa.end(), x);
                } while(pok!=mapa.end());
                it=mapa.begin();
                auto poc=p;
                auto prethodni=p;
                poc=poc->sljedeci;
                while(poc->sljedeci!=p) {
                    poc=poc->sljedeci;
                }
                poc->sljedeci=p->sljedeci;
                if(prethodni==pocetak) pocetak=pocetak->sljedeci;
                p=p->sljedeci;
                delete prethodni;
            }
            p=p->sljedeci;
        }
        it++;
    }
}
Deck IzbaciKarteRazbrajanjem (Cvor* &pocetak, const short int &r, const int &b)
{
    void ProvjeriSpil(Cvor* pocetak);
    int PrebrojiKarte(Cvor*);
    ProvjeriSpil(pocetak);
    if(!(r>=1 && r<=52) || (b<1)) throw std::logic_error("Neispravni elementi za izbacivanje!");
    Deck outcast;
    int provjera=PrebrojiKarte(pocetak);
    std::vector<std::string> vrsta({"Pik", "Tref", "Herc", "Karo"});
    int i(1);
    auto p=pocetak;
    while(i<=b) {
        int j(1);
        while(j<r) {
            p=p->sljedeci;
            j++;
        }
        outcast.push(std::make_pair(vrsta.at(int(p->karta.boja)), p->karta.vrijednost));
        auto poc=p;
        auto prethodni=p;
        while(poc->sljedeci!=p) {
            poc=poc->sljedeci;
        }
        poc->sljedeci=p->sljedeci;
        if(prethodni==pocetak) pocetak=pocetak->sljedeci;
        p=p->sljedeci;
        delete prethodni;
        i++;
    }
    if(provjera==b) pocetak=nullptr;
    return outcast;
}
void VratiPosljednjihNKarata(Cvor* &pocetak, Deck &stek, int n)
{
    int PrebrojiKarte(Cvor* );
    if(!(n>=0 && n<=52)) throw std::domain_error("Broj n je besmislen!");
    if(stek.size()<n) throw std::range_error("Nedovoljno karata u steku!");
    void ProvjeriSpil(Cvor* pocetak);
    ProvjeriSpil(pocetak);
    std::vector<std::string> boje= {"Pik", "Tref", "Herc", "Karo"};
    std::vector<std::string> imena= {"2","3","4","5","6","7","8","9","10","J","Q","K","A"};

    int i(0);

    while(i<n && !(stek.empty())) {
        auto x=stek.top().first;
        auto pok=std::find(boje.begin(), boje.end(), x);
        int poz=std::distance(boje.begin(), pok);
        auto y=std::make_pair(Boje(poz), stek.top().second);
        auto p=pocetak;
        for(;;) {
            if(!pocetak) {
                pocetak=new Cvor {{Boje(poz), y.second}, pocetak};
                break;
            } else {
                auto lokacija1=std::find(imena.begin(), imena.end(), y.second);
                auto udaljenost1=std::distance(imena.begin(), lokacija1);
                auto lokacija2=std::find(imena.begin(), imena.end(), p->karta.vrijednost);
                auto udaljenost2=std::distance(imena.begin(), lokacija2);
                auto lokacija3=std::find(imena.begin(), imena.end(), pocetak->karta.vrijednost);
                auto udaljenost3=std::distance(imena.begin(), lokacija3);
                if(y.second=="A") {

                    while(p->karta.boja<y.first) p=p->sljedeci;
                    while(p->karta.boja==y.first) p=p->sljedeci;
                    Cvor *novi(new Cvor {{Boje(poz), y.second}, p});
                    auto prethodni=p;
                    while(prethodni->sljedeci!=p) {
                        prethodni=prethodni->sljedeci;
                    }
                    prethodni->sljedeci=novi;
                    if(novi->karta.boja<=pocetak->karta.boja && lokacija1<lokacija3) pocetak=novi;
                    break;
                } else if(y.first==p->karta.boja && udaljenost1<udaljenost2) {
                    Cvor *novi(new Cvor {{Boje(poz), y.second}, p});
                    auto prethodni=p;
                    while(prethodni->sljedeci!=p) {
                        prethodni=prethodni->sljedeci;
                    }
                    prethodni->sljedeci=novi;
                    if(novi->karta.boja<=pocetak->karta.boja && udaljenost1<udaljenost3) pocetak=novi;
                    break;
                }
                p=p->sljedeci;
            }
        }

        stek.pop();
        i++;
    }
}
int PrebrojiKarte(Cvor *pocetak)
{
    int broj_el(0);
    
    if(pocetak) {
        for(auto p=pocetak; ; ) {
            broj_el++;
            if(p->sljedeci==pocetak) break;
            p=p->sljedeci;
        }
    }
    return broj_el;
}
void IspisiSpil(Cvor *pocetak)
{
    auto p=pocetak;
    if(pocetak) {
        std::vector<std::string> imena= {"Pik", "Tref", "Herc", "Karo"};
        std::cout<<std::endl<<imena.at(int(p->karta.boja))<<": ";
        for(;;) {
            std::cout<<p->karta.vrijednost;
            if(p->karta.vrijednost!="A") std::cout<<" ";
            if(p->sljedeci==pocetak) break;
            if(p->sljedeci->karta.boja!=p->karta.boja) std::cout<<std::endl<<imena.at(int(p->sljedeci->karta.boja))<<": ";
            p=p->sljedeci;
        }
    }
}
void ProvjeriSpil(Cvor *pocetak)
{
    void UnistiSpil(Cvor* );
    if(pocetak) {
        int broj_el=PrebrojiKarte(pocetak);
        if(!(broj_el>=0 && broj_el<=52)) throw std::logic_error ("Neispravna lista!");
        auto SavrsenSpil(KreirajSpil());
        auto pok=pocetak;
        for(;;) {
            auto p=SavrsenSpil;
            bool ima(false);
            int i(0);
            while(i<52) {
                if(pok->karta.boja==p->karta.boja && pok->karta.vrijednost==p->karta.vrijednost) {
                    ima=true;
                    break;
                }
                p=p->sljedeci;
                i++;
            }
            if(!ima) {
                UnistiSpil(SavrsenSpil);
                throw std::logic_error ("Neispravna lista!");
            }
            pok=pok->sljedeci;
            if(pok->sljedeci==pocetak) break;
        }
        UnistiSpil(SavrsenSpil);
    }
}
void UnistiSpil(Cvor *pocetak)
{
    auto p=pocetak;
    if(pocetak) {
        p=p->sljedeci;
        for(auto poc=p; poc!=pocetak; ) {
            auto pomocna(poc);
            poc=poc->sljedeci;
            delete pomocna;
        }
    }
    delete pocetak;
    pocetak=nullptr;
}
int main ()
{
    Cvor *lista(KreirajSpil());
    try {
        std::cout<<"Unesite korak razbrajanja: ";
        int r;
        std::cin >> r;
        std::cout<<"Unesite broj karata koje zelite izbaciti: ";
        int b;
        std::cin >> b;
        auto stek=IzbaciKarteRazbrajanjem(lista,r,b);
        std::cout<<"U spilu trenutno ima "<<PrebrojiKarte(lista)<<" karata, i to: ";
        IspisiSpil(lista);
        std::cout<<std::endl<<"Unesite broj karata koje zelite vratiti u spil: ";
        int a;
        std::cin>>a;
        try {
            VratiPosljednjihNKarata(lista, stek, a);
            std::cout<<"U spilu trenutno ima "<<PrebrojiKarte(lista)<<" karata, i to: ";
            IspisiSpil(lista);
            UnistiSpil(lista);
        } catch(std::exception &e) {
            UnistiSpil(lista);
            std::cout<<"Izuzetak: "<<e.what();
        }
    } catch(std::exception &e) {
        UnistiSpil(lista);
        std::cout<<"Izuzetak: "<<e.what();
    }

    return 0;
}
