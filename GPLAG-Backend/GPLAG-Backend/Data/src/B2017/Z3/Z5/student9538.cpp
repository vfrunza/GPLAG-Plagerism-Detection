/B2017/2018: Zadaća 3, Zadatak 5
#include <iostream>
#include <string>
#include <stdexcept>
#include <stack>
#include <map>

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
    Cvor *sljedeci;
};

Cvor *KreirajSpil()
{
    std::string vrijednost_karte[13] {"2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K", "A"};
    Cvor *prvi(nullptr), *prethodni;
    for(int i=0; i<4; i++) {
        for(int j=0; j<13; j++) {
            Cvor *novi(new Cvor {{Boje(i), vrijednost_karte[j]}, nullptr});
            if(!prvi) prvi=novi;
            else prethodni->sljedeci=novi;
            prethodni=novi;
        }
    }
    prethodni->sljedeci=prvi;
    return prvi;
}

bool PrijeUStingu_i_PostojiUStringu(std::string s1, std::string s2);
bool DobroSortirano(Cvor *prvi);

int BrojKarataUSpilu(Cvor *prvi)
{
    int br_karata(0);
    Cvor *next(nullptr);
    for(Cvor *pok=prvi; next!=prvi; pok=pok->sljedeci) {
        next=pok->sljedeci;
        br_karata++;
    }
    return br_karata;
}

void IspisiKarte(Cvor *prvi)
{
    std::string nazivi_boja[4] {"Pik", "Tref", "Herc", "Karo"};
    std::cout<<"U spilu trenutno ima "<<BrojKarataUSpilu(prvi)<<" karata, i to:"<<std::endl;
    Cvor *next(nullptr), *pok(prvi);
    for(int i=0; i<4; i++) {
        std::cout<<nazivi_boja[i]<<":";
        auto boja=Boje(i);
        while(boja==pok->karta.boja && next!=prvi) {
            std::cout<<" "<<pok->karta.vrijednost;
            pok=pok->sljedeci;
            next=pok;
        }
        std::cout<<std::endl;
    }
}

void IzbaciKarte(Cvor *&prvi, std::multimap<Boje, std::string> &mapa)
{
    if(BrojKarataUSpilu(prvi)>52 || !DobroSortirano(prvi)) throw std::logic_error("Neispravna lista!");
    for(auto it_mapa=mapa.begin(); it_mapa!=mapa.end(); it_mapa++) {
        Cvor *next(nullptr);
        for(Cvor *pok=prvi; next!=prvi; pok=pok->sljedeci) {
            next=pok->sljedeci;
            if(it_mapa->first==next->karta.boja && it_mapa->second==next->karta.vrijednost) {
                auto pom(next->sljedeci);
                pok->sljedeci=pom;
                if(next==prvi) prvi=prvi->sljedeci;
                delete next;
                mapa.erase(it_mapa);
            }
            next=pok->sljedeci;
            if(pok==pok->sljedeci) {
                prvi=nullptr;
                return;
            }
        }
    }
}

std::stack<std::pair<std::string, std::string>> IzbaciKarteRazbrajanjem(Cvor *&prvi, const short int &r, const int &b)
{
    if(r<1 || r>52 || b<1) throw std::logic_error("Neispravni elementi za izbacivanje!");
    if(BrojKarataUSpilu(prvi)>52 || !DobroSortirano(prvi)) throw std::logic_error("Neispravna lista!");
    int br_karata(0);
    std::string nazivi_boja[4] {"Pik", "Tref", "Herc", "Karo"};
    std::stack<std::pair<std::string, std::string>> stek;
    Cvor *pok(prvi), *prethodni(nullptr);
    while(br_karata<b) {
        int i=0;
        while(i<r-1) {
            prethodni=pok;
            pok=pok->sljedeci;
            i++;
        }
        std::string pom(nazivi_boja[int(pok->karta.boja)]); //ubacivanje u stek
        std::pair<std::string, std::string> par {pom, pok->karta.vrijednost};
        stek.push(par);
        br_karata++;
        //brisanje
        if(pok==prvi) {
            Cvor *kraj(nullptr), *pom(prvi->sljedeci);
            while(pom!=prvi) {
                kraj=pom;
                pom=pom->sljedeci;
            }
            prvi=pok->sljedeci;
            kraj->sljedeci=prvi;
            delete pok;
            pok=prvi;
        } else {
            auto next(pok->sljedeci);
            prethodni->sljedeci=next;
            if(pok==prvi) prvi=prvi->sljedeci;
            delete pok;
            pok=next;
        }
    }
    return stek;
}

bool NesipravneKarte(std::pair<std::string, std::string> par)
{
    std::string nazivi_boja[4] {"Pik", "Tref", "Herc", "Karo"};
    std::string vrijednost_karte[] {"2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K", "A"};
    for(int i=0; i<4; i++)
        for(int j=0; j<13; j++)
            if(par.first==nazivi_boja[i] && par.second==vrijednost_karte[j]) return false;
    return true;
}

void VratiPosljednjihNKarata(Cvor *&prvi, std::stack<std::pair<std::string, std::string>> &stek, int n)
{
    if(n<0) throw std::domain_error("Broj n je besmislen!");
    if(n>stek.size()) throw std::range_error("Nedovoljno karata u steku!");
    if(BrojKarataUSpilu(prvi)>52 || !DobroSortirano(prvi)) throw std::logic_error("Neispravna lista!");
    for(int i=0; i<n; i++) {
        std::pair<std::string, std::string> el_reda(stek.top());
        if(NesipravneKarte(el_reda))throw std::logic_error("Neispravne karte!");
        Boje boja;
        std::string nazivi_boja[4] {"Pik", "Tref", "Herc", "Karo"};
        for(int j=0; j<4; j++) {
            if(nazivi_boja[j]==el_reda.first) {
                boja=Boje(j);
                break;
            }
        }
        std::pair<Boje, std::string> par=std::make_pair(boja, el_reda.second); //napravili smo par koji se nalazi u steku
        Cvor *prethodni(prvi), *next(nullptr);
        for(Cvor *pok=prvi; next!=prvi; pok=pok->sljedeci) {
            next=pok->sljedeci;
            if(par.first==pok->karta.boja && par.second==pok->karta.vrijednost) break;
            else if(pok->karta.boja>par.first || (pok->karta.boja==par.first && PrijeUStingu_i_PostojiUStringu(par.second, pok->karta.vrijednost))) {
                if(pok==prvi) {
                    auto novi(new Cvor({{par.first, par.second}, pok}));
                    Cvor *kraj(nullptr), *pom(prvi->sljedeci);
                    while(pom!=prvi) {
                        kraj=pom;
                        pom=pom->sljedeci;
                    }
                    kraj->sljedeci=novi;
                    prvi=novi;
                    break;
                } else {
                    auto novi(new Cvor({{par.first, par.second}, pok}));
                    prethodni->sljedeci=novi;
                    break;
                }
            } else if(pok->karta.boja==par.first && PrijeUStingu_i_PostojiUStringu(pok->karta.vrijednost, par.second) && next==prvi) {
                auto novi(new Cvor({{par.first, par.second}, next}));
                pok->sljedeci=novi;
                break;
            }
            prethodni=pok;
        }
        stek.pop();
    }
}

void UnistiSpil(Cvor *prvi)
{
    if(!prvi) return;
    Cvor *next(nullptr), *pok(prvi);
    while(next!=prvi) {
        Cvor *obrisi(pok);
        pok=pok->sljedeci;
        next=pok;
        delete obrisi;
    }
}

int main ()
{
    auto spil(KreirajSpil());
    int b, br_karata;
    short int r;
    std::cout<<"Unesite korak razbrajanja: ";
    std::cin>>r;
    std::cout<<"Unesite broj karata koje zelite izbaciti: ";
    std::cin>>b;
    try {
        auto stek(IzbaciKarteRazbrajanjem(spil, r, b));
        IspisiKarte(spil);
        std::cout<<"Unesite broj karata koje zelite vratiti u spil: ";
        std::cin>>br_karata;
        VratiPosljednjihNKarata(spil, stek, br_karata);
        IspisiKarte(spil);
        UnistiSpil(spil);
    } catch(std::domain_error iz) {
        UnistiSpil(spil);
        std::cout<<"Izuzetak: "<<iz.what()<<std::endl;
    } catch(std::logic_error iz) {
        UnistiSpil(spil);
        std::cout<<"Izuzetak: "<<iz.what()<<std::endl;
    } catch(std::range_error iz) {
        UnistiSpil(spil);
        std::cout<<"Izuzetak: "<<iz.what()<<std::endl;
    } catch(...) {
        UnistiSpil(spil);
        std::cout<<"Neocekivani izuzetak!"<<std::endl;
    }
    return 0;
}

bool PrijeUStingu_i_PostojiUStringu(std::string s1, std::string s2)
{
    std::string vrijednost_karte[13] {"2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K", "A"};
    int mjesto_s1(-1), mjesto_s2(-1);
    for(int i=0; i<13; i++) {
        if(vrijednost_karte[i]==s1) mjesto_s1=i;
        if(vrijednost_karte[i]==s2) mjesto_s2=i;
    }
    if(mjesto_s2==-1 || mjesto_s1==-1) return false;
    return mjesto_s1<mjesto_s2;
}

bool DobroSortirano(Cvor *prvi)
{
    Cvor *prethodni(nullptr), *next(nullptr);
    for(auto pok=prvi; next!=prvi; pok=pok->sljedeci) {
        if(pok==prvi) {
            prethodni=pok;
            continue;
        } else {
            if(prethodni->karta.boja>pok->karta.boja) return false;
            if(prethodni->karta.boja==pok->karta.boja)
                if(!PrijeUStingu_i_PostojiUStringu(prethodni->karta.vrijednost, pok->karta.vrijednost)) return false;
            prethodni=pok;
        }
        next=pok->sljedeci;
    }
    return true;
}
