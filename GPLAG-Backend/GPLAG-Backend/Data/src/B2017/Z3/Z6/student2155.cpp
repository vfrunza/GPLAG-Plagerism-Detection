/B2017/2018: Zadaća 3, Zadatak 6
#include <iostream>
#include <vector>
#include <new>
#include <stdexcept>
#include <algorithm>
#include <memory>
#include <map>
#include <stack>
#include <string>
#include <utility>

enum class Boje
{
    Pik, Tref, Herc, Karo
};

std::vector<std::string> NazivKarata {"2","3","4","5","6","7","8","9","10","J","Q","K","A"};

struct Karta {
    Boje boja;
    std::string vrijednost;
};

struct Cvor {
    Karta karta;
    std::shared_ptr<Cvor> sljedeci;
};

std::shared_ptr<Cvor> KreirajSpil()
{
    std::shared_ptr<Cvor>pocetak (nullptr), pomocni;
    for( int i = 0; i < NazivKarata.size(); i++) {
        std::shared_ptr<Cvor> temp (std::make_shared<Cvor>());
        temp->karta.boja = Boje::Pik;
        temp->karta.vrijednost = NazivKarata.at(i);
        temp->sljedeci = nullptr;
        if(pocetak == nullptr) pocetak = temp;
        else pomocni->sljedeci = temp;
        pomocni = temp;
    }
    for( int i = 0; i < NazivKarata.size(); i++) {
        std::shared_ptr<Cvor> temp ( std::make_shared<Cvor>());
        temp->karta.boja = Boje::Tref;
        temp->karta.vrijednost = NazivKarata.at(i);
        temp->sljedeci = nullptr;
        pomocni->sljedeci = temp;
        pomocni = temp;
    }
    for( int i = 0; i < NazivKarata.size(); i++) {
        std::shared_ptr<Cvor> temp ( std::make_shared<Cvor>());
        temp->karta.boja = Boje::Herc;
        temp->karta.vrijednost = NazivKarata.at(i);
        temp->sljedeci = nullptr;
        pomocni->sljedeci = temp;
        pomocni = temp;
    }
    for(int i = 0; i < NazivKarata.size(); i++) {
        std::shared_ptr<Cvor> temp (std::make_shared<Cvor>());
        temp->karta.boja = Boje::Karo;
        temp->karta.vrijednost = NazivKarata.at(i);
        if( i == NazivKarata.size() - 1) temp->sljedeci = pocetak;
        else temp->sljedeci = nullptr;
        pomocni->sljedeci = temp;
        pomocni = temp;
    }
    return pocetak;
}
void Izuzeci(std::shared_ptr<Cvor> pocetak)
{
    int brojac = 0;
    for(auto kretanje = pocetak; kretanje->sljedeci != pocetak; kretanje = kretanje->sljedeci) {
        brojac++;
        bool smislen = false;
        for( int i = 0; i < NazivKarata.size(); i++) {
            if(kretanje->karta.vrijednost == NazivKarata.at(i)) smislen = true;
        }
        if(smislen == false) throw std::logic_error("Neispravna lista!");

        if(brojac > 52) throw std::logic_error("Neispravna lista!");

        Boje boja;
        for(auto kretanje = pocetak; kretanje->sljedeci != pocetak; kretanje = kretanje->sljedeci) {
            boja = kretanje->karta.boja;
            while(kretanje->karta.boja == boja && kretanje->sljedeci != pocetak ) {
                auto pomocnakarta = kretanje;
                kretanje = kretanje->sljedeci;
                if(kretanje->karta.boja != boja) break;
                auto nazivpomocna = std::find(NazivKarata.begin(), NazivKarata.end(), pomocnakarta->karta.vrijednost);
                auto nazivkretanje = std::find(NazivKarata.begin(), NazivKarata.end(), kretanje->karta.vrijednost);
                if( nazivpomocna > nazivkretanje) throw std::logic_error("Neispravna lista!");
            }
            if(boja == Boje::Karo && kretanje->sljedeci != pocetak) throw std::logic_error("Neispravna lista!");
            for( auto kretanje2 = kretanje; kretanje2 != pocetak; kretanje2 = kretanje2->sljedeci) {
                if(boja == Boje::Pik) {
                    if(kretanje2->karta.boja == Boje::Pik) throw std::logic_error("Neispravna lista!");
                } else if(boja == Boje::Tref) {
                    if(kretanje2->karta.boja == Boje::Tref || kretanje2->karta.boja == Boje::Pik) throw std::logic_error("Neispravna lista!");
                } else if(boja == Boje::Herc) {
                    if(kretanje2->karta.boja == Boje::Pik || kretanje2->karta.boja == Boje::Tref || kretanje2->karta.boja == Boje::Herc) throw std::logic_error("Neispravna lista!");
                }
            }
            if(kretanje->sljedeci == pocetak) break;
        }
    }
}

void IzbaciKarte(std::shared_ptr<Cvor>&pocetak, std::multimap<Boje, std::string> &m)
{
    Izuzeci(pocetak);
    auto novi = pocetak;
    auto kraj = pocetak;
    while(kraj->sljedeci != pocetak) kraj = kraj->sljedeci;

    for(auto it = m.begin(); it != m.end();) {
        bool obrisana(false);
        if((*it).first == novi->karta.boja && (*it).second == novi->karta.vrijednost) {
            obrisana = true;
            pocetak = pocetak->sljedeci;
            kraj->sljedeci = pocetak;
            if(pocetak == pocetak->sljedeci) pocetak = nullptr;
            it = m.erase(it);
            novi = pocetak;
        }
        if(obrisana == false) {
            for(auto kretanje = pocetak->sljedeci; kretanje != pocetak; kretanje = kretanje->sljedeci) {
                if((*it).first == kretanje->karta.boja && (*it).second == kretanje->karta.vrijednost) {
                    obrisana = true;
                    auto prethodnik = pocetak;
                    while(prethodnik->sljedeci != kretanje) prethodnik = prethodnik->sljedeci;
                    prethodnik->sljedeci = kretanje->sljedeci;
                    kretanje = nullptr;
                    it = m.erase(it);
                    break;
                }
            }
        }
        if(obrisana == false) it++;
    }
}
std::stack<std::pair<std::string, std::string>>IzbaciKarteRazbrajanjem(std::shared_ptr<Cvor>&pocetak, const short int &r, const int &b)
{
    if( r < 1 || r > 52 || b < 1) throw std::logic_error("Neispravni elementi za izbacivanje!");
    Izuzeci(pocetak);
    auto kraj = pocetak;
    //auto novi = pocetak;
    auto kretanje = pocetak;
    while(kraj->sljedeci != pocetak) kraj = kraj->sljedeci;
    std::stack<std::pair<std::string, std::string>> stek;
    int broj_izbacenih = 0;
    while(broj_izbacenih != b && pocetak != nullptr) {
        int korak(0);
        while(korak < r - 1) {
            kretanje = kretanje->sljedeci;
            korak++;
        }
        std::pair<std::string, std::string>element_steka;
        if(kretanje->karta.boja == Boje::Pik) element_steka.first = "Pik";
        else if(kretanje->karta.boja == Boje::Tref) element_steka.first = "Tref";
        else if(kretanje->karta.boja == Boje::Herc) element_steka.first = "Herc";
        else element_steka.first = "Karo";
        element_steka.second = kretanje->karta.vrijednost;
        stek.push(element_steka);

        if(kretanje == pocetak) {
            if(pocetak == pocetak->sljedeci) {
                pocetak = nullptr;
                //novi = nullptr;
                kretanje = nullptr;
            } else {
                pocetak = pocetak->sljedeci;
                kraj->sljedeci = pocetak;
                //novi = pocetak;
                kretanje = pocetak;
                broj_izbacenih++;
            }
        } else {
            auto prethodnik = pocetak;
            while(prethodnik->sljedeci != kretanje) prethodnik = prethodnik->sljedeci;
            if(kretanje->sljedeci == pocetak) kraj = prethodnik;
            prethodnik->sljedeci = kretanje->sljedeci;
            kretanje->sljedeci = nullptr;
            broj_izbacenih++;
            kretanje = prethodnik->sljedeci;
        }
    }
    return stek;
}
void NeispravneKarte(const std::stack<std::pair<std::string, std::string>> &stek)
{
    auto pomocni = stek;
    while( !pomocni.empty() ) {
        std::pair<std::string, std::string>p = pomocni.top();
        if (p.first != "Pik" && p.first != "Tref" && p.first !="Herc" && p.first != "Karo") throw std::logic_error("Neispravne karte!");
        bool smislen(false);
        for (int i = 0; i < NazivKarata.size(); i++) {
            if(NazivKarata.at(i) == p.second) smislen = true;
        }
        if(smislen == false) throw std::logic_error("Neispravne karte!");
        pomocni.pop();
    }
}
void VratiPosljednjihNKarata(std::shared_ptr<Cvor>&pocetak, std::stack<std::pair<std::string, std::string>> &stek, int n)
{
    if(n < 0) {
        if(pocetak == pocetak->sljedeci){
            pocetak->sljedeci == nullptr;
        }
        auto kraj = pocetak;
        while( kraj->sljedeci != pocetak) kraj = kraj->sljedeci;
        kraj=nullptr;
        throw std::domain_error("Broj n je besmislen!");
    }
    if (n > stek.size()){
        
        throw std::range_error("Nedovoljno karata u steku!");
    }
    NeispravneKarte(stek);
    std::pair<std::string, std::string>p;
    for(int i = 0; i < n; i++) {
        p = stek.top();
        stek.pop();
        std::pair<Boje, std::string>pomocni;
        try {
            std::shared_ptr<Cvor>novakarta ( std::make_shared<Cvor>());
            if(p.first == "Pik") novakarta->karta.boja = Boje::Pik;
            else if(p.first == "Tref") novakarta->karta.boja = Boje::Tref;
            else if(p.first == "Karo") novakarta->karta.boja = Boje::Karo;
            else novakarta->karta.boja = Boje::Herc;
            for(int j = 0; j < NazivKarata.size(); j++) {
                if(p.second == NazivKarata.at(j)) novakarta->karta.vrijednost = NazivKarata.at(j);
            }
            //novakarta->sljedeci = nullptr;
            //ignorisati istu kartu
            bool ubacena(false);
            if(pocetak != nullptr) {
                //provjera zadnje karte u spilu, jer je petlja ispod ne provjeri
                auto kraj = pocetak;
                while(kraj->sljedeci != pocetak) kraj = kraj->sljedeci;

                if(kraj->karta.boja == novakarta->karta.boja && kraj->karta.vrijednost == novakarta->karta.vrijednost) {
                    novakarta = nullptr;
                    continue;
                }
                for(auto kretanje = pocetak; kretanje->sljedeci != pocetak; kretanje = kretanje->sljedeci) {
                    if(kretanje->karta.boja == novakarta->karta.boja && kretanje->karta.vrijednost == novakarta->karta.vrijednost) {
                        novakarta = nullptr;
                        continue;
                    }
                }
                for(auto kretanje = pocetak; kretanje->sljedeci != pocetak; kretanje = kretanje->sljedeci) {
                    ubacena = false;
                    if(novakarta->karta.boja > kretanje->karta.boja) continue;
                    else if(kretanje->sljedeci != pocetak && novakarta->karta.boja == kretanje->karta.boja) {
                        auto novakartait = std::find(NazivKarata.begin(), NazivKarata.end(), novakarta->karta.vrijednost);
                        auto kretanjekrozboje(kretanje);
                        int kruzenje(0);
                        for( kretanjekrozboje = kretanje; kretanjekrozboje->karta.boja == kretanje->karta.boja; kretanjekrozboje = kretanjekrozboje->sljedeci) {
                            if(kretanjekrozboje == kretanje) kruzenje++;
                            if(kruzenje > 1) break;
                            auto kretanjekrozbojeit = std::find(NazivKarata.begin(), NazivKarata.end(), kretanjekrozboje->karta.vrijednost);
                            if(novakartait > kretanjekrozbojeit) continue;
                            auto prethodnik(pocetak);
                            while(prethodnik->sljedeci != kretanjekrozboje) prethodnik = prethodnik->sljedeci;
                            if(prethodnik->karta.boja > novakarta->karta.boja) pocetak = novakarta;
                            novakarta->sljedeci = kretanjekrozboje;
                            prethodnik->sljedeci = novakarta;
                            ubacena = true;
                            break;
                        }
                        if(ubacena == false) {
                            auto prethodnik(pocetak);
                            while(prethodnik->sljedeci != kretanjekrozboje) prethodnik = prethodnik->sljedeci;
                            if(prethodnik->karta.boja > novakarta->karta.boja) pocetak = novakarta;
                            novakarta->sljedeci = kretanjekrozboje;
                            prethodnik->sljedeci = novakarta;
                            ubacena = true;
                            break;
                        }

                    }
                    if(ubacena) break;
                    else if(kretanje->sljedeci == pocetak || novakarta->karta.boja < kretanje->karta.boja) {
                        auto prethodnik(pocetak);
                        while(prethodnik->sljedeci != kretanje) prethodnik = prethodnik->sljedeci;
                        if(prethodnik->karta.boja > novakarta->karta.boja) pocetak = novakarta;
                        novakarta->sljedeci = kretanje;
                        prethodnik->sljedeci = novakarta;
                        ubacena = true;
                        break;
                    }
                }
            }
            if(ubacena == false) {
                if(pocetak == nullptr) {
                    pocetak = novakarta;
                    //pocetak->sljedeci = pocetak;
                    if(pocetak->sljedeci != pocetak) pocetak->sljedeci = pocetak;
                    else pocetak->sljedeci = nullptr;

                } else if(pocetak == pocetak->sljedeci) {
                    pocetak->sljedeci = novakarta;
                    novakarta->sljedeci = pocetak;
                    if(novakarta->karta.boja < pocetak->karta.boja) pocetak = novakarta;
                    else if(novakarta->karta.boja == pocetak->karta.boja) {
                        auto novakartait = std::find(NazivKarata.begin(), NazivKarata.end(), novakarta->karta.vrijednost);
                        auto prisutnakartait = std::find(NazivKarata.begin(), NazivKarata.end(), pocetak->karta.vrijednost);
                        if(novakartait < prisutnakartait) pocetak = novakarta;
                    }
                }
            }

        } catch(...) {
            throw;
        }
    }
    if(pocetak == pocetak->sljedeci) {
        pocetak->sljedeci = nullptr;
    }
}
int BrojKarataUSpilu(std::shared_ptr<Cvor>pocetak)
{
    int broj(1);
    if(pocetak == nullptr) return 0;
    else if( pocetak->sljedeci == pocetak || pocetak->sljedeci == nullptr) return 1;
    for (auto kretanje = pocetak; kretanje->sljedeci != pocetak; kretanje = kretanje->sljedeci) {
        broj++;
    }
    return broj;
}

int main ()
{
    std::shared_ptr<Cvor>pocetak(nullptr);
    try {
        pocetak = KreirajSpil();
        auto pok = pocetak;
        std::cout<<"Unesite korak razbrajanja: ";
        short int r;
        std::cin>>r;
        std::cout<<"Unesite broj karata koje zelite izbaciti: ";
        int b;
        std::cin>>b;
        auto stek (IzbaciKarteRazbrajanjem(pocetak,r,b));
        std::cout<<"U spilu trenutno ima "<<BrojKarataUSpilu(pocetak)<<" karata, i to:"<<std::endl;

        std::cout<<"Pik: ";
        for(pok = pocetak; pok != nullptr && pok->sljedeci != pocetak; pok = pok->sljedeci) {
            if(pok->karta.boja == Boje::Pik) std::cout<< pok->karta.vrijednost<<" ";
        }

        if(pok != nullptr && pok->karta.boja == Boje::Pik) std::cout<<pok->karta.vrijednost;

        std::cout<<std::endl<<"Tref: ";
        for(pok = pocetak; pok != nullptr && pok->sljedeci != pocetak; pok = pok->sljedeci) {
            if(pok->karta.boja == Boje::Tref) std::cout<< pok->karta.vrijednost<<" ";
        }

        if(pok != nullptr && pok->karta.boja == Boje::Tref) std::cout<<pok->karta.vrijednost;

        std::cout<<std::endl<<"Herc: ";
        for(pok = pocetak; pok != nullptr && pok->sljedeci != pocetak; pok = pok->sljedeci) {
            if(pok->karta.boja == Boje::Herc) std::cout<<pok->karta.vrijednost<<" ";
        }

        if(pok != nullptr && pok->karta.boja == Boje::Herc) std::cout<<pok->karta.vrijednost;

        std::cout<<std::endl<<"Karo: ";
        for(pok = pocetak; pok != nullptr && pok->sljedeci != pocetak; pok = pok->sljedeci) {
            if(pok->karta.boja == Boje::Karo) std::cout<<pok->karta.vrijednost<<" ";
        }

        if(pok != nullptr && pok->karta.boja == Boje::Karo) std::cout<<pok->karta.vrijednost;

        std::cout<<std::endl<<"Unesite broj karata koje zelite vratiti u spil: ";
        int n;
        std::cin>>n;
        VratiPosljednjihNKarata(pocetak, stek, n);
        std::cout<<"U spilu trenutno ima "<<BrojKarataUSpilu(pocetak)<<" karata, i to:"<<std::endl;

        std::cout<<"Pik: ";
        for(pok = pocetak; pok != nullptr && pok->sljedeci != pocetak; pok = pok->sljedeci) {
            if(pok->karta.boja == Boje::Pik) std::cout<<pok->karta.vrijednost<<" ";
        }
        if(pok != nullptr && pok->karta.boja == Boje::Pik) std::cout<<pok->karta.vrijednost;

        std::cout<<std::endl<<"Tref: ";
        for(pok = pocetak; pok != nullptr && pok->sljedeci != pocetak; pok = pok->sljedeci) {
            if(pok->karta.boja == Boje::Tref) std::cout<<pok->karta.vrijednost<<" ";
        }
        if (pok != nullptr && pok->karta.boja == Boje::Tref) std::cout<<pok->karta.vrijednost;

        std::cout<<std::endl<<"Herc: ";
        for(pok = pocetak; pok != nullptr && pok->sljedeci != pocetak; pok = pok->sljedeci) {
            if(pok->karta.boja == Boje::Herc) std::cout<<pok->karta.vrijednost<<" ";
        }
        if(pok != nullptr && pok->karta.boja == Boje::Tref) std::cout<<pok->karta.vrijednost;

        std::cout<<std::endl<<"Karo: ";
        for(pok = pocetak; pok != nullptr && pok->sljedeci != pocetak; pok = pok->sljedeci) {
            if(pok->karta.boja == Boje::Karo) std::cout<<pok->karta.vrijednost<<" ";
        }
        if(pok != nullptr && pok->karta.boja == Boje::Karo) std::cout<<pok->karta.vrijednost;
        
        pok=nullptr;
        pocetak->sljedeci=nullptr;
        pocetak=nullptr;

    } catch(std::domain_error e) {
        pocetak->sljedeci =nullptr;
        pocetak=nullptr;
        std::cout<<"Izuzetak: "<<e.what();
    } catch(std::range_error e) {
        pocetak->sljedeci=nullptr;
        pocetak=nullptr;
        std::cout<<"Izuzetak: "<<e.what();
    } catch(std::logic_error e) {
        pocetak->sljedeci=nullptr;
        pocetak=nullptr;
        std::cout<<"Izuzetak: "<<e.what();
    }
    return 0;
}
