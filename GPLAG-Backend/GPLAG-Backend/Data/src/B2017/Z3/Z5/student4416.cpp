/B2017/2018: Zadaća 3, Zadatak 5
#include <iostream>
#include <string>
#include <utility>
#include <algorithm>
#include <stdexcept>
#include <map>
#include <stack>


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

void IspisiSpil(Cvor* spil)
{
    int broj_karata(1);
    Cvor *prva(spil);
    if(spil==nullptr) broj_karata=0;
    else {
        for(auto i(spil->sljedeci); i!=prva; i=i->sljedeci) broj_karata++;
    }
    std::cout << "U spilu trenutno ima " << broj_karata << " karata, i to:\n";
    Cvor *pom(prva);
    int broj(0);
    int niz[4];
    for(int i(0); i<4; i++) {
        int broj1(0);
        for(; broj<broj_karata;) {
            if(pom->karta.boja==Boje(i)) broj1++;
            if(pom->karta.boja!=Boje(i)) break;
            pom=pom->sljedeci;
            broj++;
        }
        niz[i]=broj1;
    }
    broj=0;
    for(int i(0); i<4; i++) {
        if(i==0) std::cout << "Pik: ";
        if(i==1) std::cout << "Tref: ";
        if(i==2) std::cout << "Herc: ";
        if(i==3) std::cout << "Karo: ";
        int broj1(0);
        for(; broj<broj_karata;) {
            if(pom->karta.boja==Boje(i)) {
                std::cout << pom->karta.vrijednost;
                broj1++;
                if(broj1<niz[i]) std::cout << " ";
            }
            if(pom->karta.boja!=Boje(i)) break;
            pom=pom->sljedeci;
            broj++;
        }
        std::cout << std::endl;
    }
}

Cvor* KreirajSpil()
{
    Cvor spil;
    Cvor *prva(nullptr), *prethodna;
    int j(2), k(0);
    for(int i(0); i<52; i++) {
        std::string broj;
        broj=" ";
        broj.at(0)=char(j+'0');
        if(j==10) broj="10";
        if(j==11) broj="J";
        if(j==12) broj="Q";
        if(j==13) broj="K";
        if(j==14) broj="A";
        Cvor *nova(new Cvor);
        nova->karta.boja=Boje(k);
        nova->karta.vrijednost=broj;
        nova->sljedeci=nullptr;
        if(!prva) prva=nova;
        else prethodna->sljedeci=nova;
        prethodna=nova;
        j++;
        if(j==15) {
            k++;
            j=2;
        }
    }
    prethodna->sljedeci=prva;
    return prva;
}

void IspisiN(Cvor *spil, int n)
{
    for(int i(0); i<n-1; i++) {
        spil=spil->sljedeci;
    }
    std::string a="pik";
    if(spil->karta.boja==Boje::Tref) a="tref";
    if(spil->karta.boja==Boje::Herc) a="herc";
    if(spil->karta.boja==Boje::Karo) a="karo";
    std::cout << n << ". karta je " << a << " " << spil->karta.vrijednost << ".\n";
}

int StringUBroj(std::string a)
{
    int broj(0);
    broj+=a.at(0)-'0';
    if(a=="10") broj=10;
    if(a=="J") broj=11;
    if(a=="Q") broj=12;
    if(a=="K") broj=13;
    if(a=="A") broj=14;
    return broj;
}

std::string BojaUString(Boje boja)
{
    if(boja==Boje::Pik) return "Pik";
    if(boja==Boje::Tref) return "Tref";
    if(boja==Boje::Herc) return "Herc";
    return "Karo";
}

bool ManjaBoja(Boje a, Boje b)
{
    if((a==Boje::Pik && b!=Boje::Pik) || (a==Boje::Tref && (b==Boje::Herc || b==Boje::Karo)) || (a==Boje::Herc &&  b==Boje::Karo)) return true;
    return false;
}

bool IstaBoja(Boje a, Boje b)
{
    if((a==Boje::Pik && b==Boje::Pik) || (a==Boje::Tref && b==Boje::Tref) || (a==Boje::Herc && b==Boje::Herc)
            || (a==Boje::Karo && b==Boje::Karo)) return true;
    return false;
}

bool ManjaKarta(Karta a, Karta b)
{
    if(ManjaBoja(a.boja, b.boja)) return true;
    if(IstaBoja(a.boja, b.boja)) return StringUBroj(a.vrijednost)<StringUBroj(b.vrijednost);
    return false;
}

void IzbaciKarte(Cvor* &prva, std::multimap<Boje, std::string> mapa)
{
    int broj_karata(1);
    Cvor *pom(prva->sljedeci);
    for(; pom!=prva; pom=pom->sljedeci) broj_karata++;
    bool dobro_sortirana(true);
    pom=prva;
    for(; pom->sljedeci!=prva; pom=pom->sljedeci) {
        if(ManjaKarta(pom->sljedeci->karta, pom->karta)) {
            dobro_sortirana=false;
            break;
        }
    }
    if(broj_karata>52 || !dobro_sortirana) throw std::logic_error("Neispravna lista!");
    auto it(mapa.begin());
    while(it!=mapa.end()) {
        if(prva==nullptr) break;
        Karta karta1;
        karta1.boja=it->first;
        karta1.vrijednost=it->second;
        pom=prva;
        int broj(1);
        for(; pom!=nullptr && broj<=broj_karata; pom=pom->sljedeci) {
            if(pom->karta.boja==karta1.boja && pom->karta.vrijednost==karta1.vrijednost) {
                Cvor *pok(pom);
                for(; pok->sljedeci!=pom; pok=pok->sljedeci);
                if(broj_karata==1) {
                    delete prva;
                    prva=nullptr;
                    pom=nullptr;
                } else {
                    pok->sljedeci=pom->sljedeci;
                    if(pom==prva) prva=pom->sljedeci;
                    delete pom;
                    pom=pok->sljedeci;
                }
                if(pom!=nullptr) {
                    pok=pom;
                    for(; pok->sljedeci!=pom; pok=pok->sljedeci);
                    pom=pok;
                }
                broj_karata--;
                break;
            }
            broj++;
        }
        it=mapa.erase(it);
    }
}

std::stack<std::pair<std::string, std::string>> IzbaciKarteRazbiranjem(Cvor* &prva, const short int &korak_razbrajanja, const int &broj_karata)
{
    if(korak_razbrajanja<1 || korak_razbrajanja>52 || broj_karata<1) throw std::logic_error("Neispravni elementi za izbacivanje!");
    int broj(1);
    Cvor *pom(prva->sljedeci);
    if(prva==nullptr) broj=0;
    else {
        for(; pom!=prva; pom=pom->sljedeci) broj++;
    }
    bool dobro_sortirana(true);
    pom=prva;
    for(; pom->sljedeci!=prva; pom=pom->sljedeci) {
        if(ManjaKarta(pom->sljedeci->karta, pom->karta)) {
            dobro_sortirana=false;
            break;
        }
    }
    if(broj>52 || !dobro_sortirana) throw std::logic_error("Neispravna lista!");
    std::stack<std::pair<std::string, std::string>> stek_karata;
    if(prva==nullptr) return stek_karata;
    pom=prva;
    for(; pom->sljedeci!=prva; pom=pom->sljedeci);
    for(int i(0); i<broj_karata && prva!=nullptr; i++) {
        int broj1=korak_razbrajanja;
        while(broj1>broj) broj1-=broj;
        for(int j(0); j<broj1; j++) {
            pom=pom->sljedeci;
        }
        std::pair<std::string, std::string> karta(std::make_pair(BojaUString(pom->karta.boja), pom->karta.vrijednost));
        stek_karata.push(karta);
        Cvor *pok(pom);
        for(; pok->sljedeci!=pom; pok=pok->sljedeci);
        if(broj==1) {
            delete prva;
            prva=nullptr;
            pom=nullptr;
        } else {
            pok->sljedeci=pom->sljedeci;
            if(pom==prva) prva=pom->sljedeci;
            delete pom;
            pom=pok->sljedeci;
        }
        if(pom!=nullptr) {
            pok=pom;
            for(; pok->sljedeci!=pom; pok=pok->sljedeci);
            pom=pok;
        }
        broj--;
    }
    return stek_karata;
}

bool IspravnaKartaURedu(std::pair<std::string, std::string> karta)
{
    std::string a;
    a=karta.first;
    if(!(a=="Pik" || a=="Tref" || a=="Herc" || a=="Karo")) return false;
    a=karta.second;
    if(!(a=="2" || a=="3" || a=="4" || a=="5" || a=="6" || a=="7" || a=="8" || a=="9"
            || a=="10" || a=="J" || a=="Q" || a=="K" || a=="A")) return false;
    return true;
}

Karta KartaIzRedaUListu(std::pair<std::string, std::string> a)
{
    Karta karta;
    karta.boja=Boje::Pik;
    if(a.first=="Tref") karta.boja=Boje::Tref;
    if(a.first=="Karo") karta.boja=Boje::Karo;
    if(a.first=="Herc") karta.boja=Boje::Herc;
    karta.vrijednost=a.second;
    return karta;
}

void VratiPosljednjihNKarata(Cvor* &spil, std::stack<std::pair<std::string, std::string>> &stek_karata, int n)
{
    if(n<0) throw std::domain_error("Broj n je besmislen!");
    if(n>stek_karata.size()) throw std::range_error("Nedovoljno karata u steku!");
    bool ispravne_karte(true);
    for(int i(0); i<stek_karata.size(); i++) {
        std::pair<std::string, std::string> karta(stek_karata.top());
        stek_karata.pop();
        stek_karata.push(karta);
        if(!IspravnaKartaURedu(karta)) {
            ispravne_karte=false;
            break;
        }
    }
    if(!ispravne_karte) throw std::logic_error("Neispravne karte!");
    int broj_karata(1);
    if(spil==nullptr) broj_karata=0;
    else {
        Cvor *pomo(spil->sljedeci);
        for(; pomo!=spil; pomo=pomo->sljedeci) broj_karata++;
    }
    for(int i(0); i<n; i++) {
        std::pair<std::string, std::string> a(stek_karata.top());
        stek_karata.pop();
        Cvor *k(new Cvor);
        k->karta=KartaIzRedaUListu(a);
        Cvor *pom=spil;
        if(pom==nullptr) {
            pom->sljedeci=k;
            spil=pom;
        } else {
            for(; pom->sljedeci!=spil; pom=pom->sljedeci);
            int brojac(1);
            for(; brojac<=broj_karata && ManjaKarta(pom->sljedeci->karta, k->karta); pom=pom->sljedeci) brojac++;
            Cvor *pok(pom->sljedeci);
            pom->sljedeci=k;
            k->sljedeci=pok;
        }
    }
}

void UnistiSpil(Cvor* &spil)
{
    if(spil==nullptr) return;
    Cvor *pom(spil->sljedeci);
    int broj_karata(1);
    for(; pom->sljedeci!=spil; pom=pom->sljedeci) broj_karata++;
    if(broj_karata==1) {
        delete spil;
    } else {
        for(; pom->sljedeci!=spil; pom=pom->sljedeci);
        pom->sljedeci=nullptr;
        Cvor *prethodni;
        while(spil!=nullptr) {
            prethodni=spil;
            spil=spil->sljedeci;
            delete prethodni;
        }
    }
    spil=nullptr;
}

int main ()
{
    Cvor* spil=nullptr;
    try {
        spil=KreirajSpil();
        std::cout << "Unesite korak razbrajanja: ";
        int korak_razbrajanja;
        std::cin >> korak_razbrajanja;
        std::cout << "Unesite broj karata koje zelite izbaciti: ";
        int broj_karata;
        std::cin >> broj_karata;
        std::stack<std::pair<std::string, std::string>> stek_karata=IzbaciKarteRazbiranjem(spil, static_cast<short int>(korak_razbrajanja), broj_karata);
        IspisiSpil(spil);
        std::cout << "Unesite broj karata koje zelite vratiti u spil: ";
        std::cin >> broj_karata;
        VratiPosljednjihNKarata(spil, stek_karata, broj_karata);
        IspisiSpil(spil);
        UnistiSpil(spil);
    } catch(std::logic_error p) {
        std::cout << "Izuzetak: " << p.what() << std::endl;
        UnistiSpil(spil);
    } catch(std::range_error p) {
        std::cout << "Izuzetak: " << p.what() << std::endl;
        UnistiSpil(spil);
    } catch(std::domain_error p) {
        std::cout << "Izuzetak: " << p.what() << std::endl;
        UnistiSpil(spil);
    }
    return 0;
}
