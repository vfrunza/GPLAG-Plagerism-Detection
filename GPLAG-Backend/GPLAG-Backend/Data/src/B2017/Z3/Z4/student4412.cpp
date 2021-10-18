/B2017/2018: Zadaća 3, Zadatak 4
#include <iostream>
#include <list>
#include <queue>
#include <string>
#include <vector>
#include <stdexcept>
#include <map>
#include <queue>
#include <memory>
#include <algorithm>

const std::vector<std::string> vrijednost_k =
    {"2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K", "A"};

enum class Boje
{
    Pik, Tref, Herc, Karo
};

typedef std::list<std::pair<Boje, std::string>> Spil;
typedef std::pair<Boje, std::string> Karta;
bool BacanjeIzuzetka(const Spil &s);

Spil KreirajSpil ()
{
    Spil novi_spil(52);
    //bilo je moguce i napraviti vektor boja, ili uraditi spil preko dvije rangovske for petlje
    auto it(novi_spil.begin());
    int brojac(0), brojac_boja(0);
    while(it!=novi_spil.end()) {
        if(brojac>12) {
            brojac=0;
            brojac_boja++;
        }
        if(brojac_boja==0) it->first=Boje::Pik;
        else if(brojac_boja==1) it->first=Boje::Tref;
        else if(brojac_boja==2) it->first=Boje::Herc;
        else it->first=Boje::Karo;
        it->second=vrijednost_k[brojac];
        it++;
        brojac++;
    }
    return novi_spil;
}

void IzbaciKarte (Spil &s, std::multimap<Boje, std::string> &mapa)
{
    int broj_karata(s.size());
    int vel_mape(mapa.size());
    if(BacanjeIzuzetka(s) || broj_karata>52)
        throw std::logic_error("Neispravna lista!");
    auto it_m(mapa.begin());
    bool pronadjen(false);
    for(int i=0; i<vel_mape; i++) {                                             //krecem se kroz mapu karata koje treba izbaciti
        pronadjen=false;
        broj_karata=s.size();
        auto it_s(s.begin());
        for(int j=0; j<broj_karata; j++) {                                      //krecem se kroz spil
            if(it_s->first==it_m->first && it_s->second==it_m->second) {
                it_s=s.erase(it_s);
                it_m=mapa.erase(it_m);
                pronadjen=true;
                i--;
                break;
            }
            it_s++;
        }
        vel_mape=mapa.size();
        if(pronadjen==false) it_m++;
    }
}

bool BacanjeIzuzetka (const Spil &s)
{
    bool izuzetak(false);
    if(s.size()>52) izuzetak=true;
    auto it(s.begin());
    while(it!=s.end()) {
        if(it->first!=Boje::Pik && it->first!=Boje::Tref && it->first!=Boje::Herc && it->first!=Boje::Karo)
            izuzetak=true;                                                      //provjera da li je boje karte smislena
        if(std::find(vrijednost_k.begin(), vrijednost_k.end(), it->second)==vrijednost_k.end())
            izuzetak=true;                                                      //provjera vrijednosti
        it++;
    }
    if(!std::is_sorted(s.begin(), s.end(), [] (Karta k1, Karta k2) {            //provjera da li je spil sortiran
    if(int(k1.first)!=int(k2.first)) return int(k1.first)<int(k2.first);
        else {                                                                  //nakon boje, uporedjuje se vrijednost karata
            if(k1.second==k2.second) return false;                              //ako su karte iste
            return std::find(vrijednost_k.begin(), vrijednost_k.end(), k1.second)
                   <std::find(vrijednost_k.begin(), vrijednost_k.end(), k2.second);
        }
    })) izuzetak=false;
    return izuzetak;
}

std::queue<std::pair<std::string, std::string>> IzbaciKarteRazbrajanjem (Spil &s, const short int &r, const int &b)
{
    if(r<1 || r>52 || b<1)
        throw std::logic_error("Neispravni elementi za izbacivanje!");

    if(BacanjeIzuzetka(s)) throw std::logic_error("Neispravna lista!");         //sada je provjera za bacanje izuzetaka gotova

    std::queue<std::pair<std::string, std::string>> red_ik;
    std::multimap<Boje, std::string> mapa_k;
    bool veci(false);
    auto it(s.begin());
    for(int i=0; i<b; i++) {
        if(s.size()==0) break;
        bool veci(false);
        for(int j=0; j<r-1; j++) {
            if(it==s.end()) {
                it=s.begin();
                veci=true;
            }
            it++;
        }
        if(it==s.end())  {
            it=++s.begin();
            veci=true; //ili =begin(), pa it++
        }
        mapa_k.insert(*it);
        std::pair<std::string, std::string> izbacena_k;                         //par(izbacena karta) koji cu smjestiti u red
        if(it->first==Boje::Pik) izbacena_k.first="Pik";
        else if(it->first==Boje::Tref) izbacena_k.first="Tref";
        else if(it->first==Boje::Herc) izbacena_k.first="Herc";
        else izbacena_k.first="Karo";
        izbacena_k.second=it->second;
        red_ik.push(izbacena_k);
        if(veci) it++;
        it++;
    }
    try {
        IzbaciKarte(s, mapa_k);
    } catch (...) {
        throw;
    }
    return red_ik;
}

void VratiPrvihNKarata (Spil &s, std::queue<std::pair<std::string, std::string>> &red, int n)
{
    if(n<0)
        throw std::domain_error("Broj n je besmislen!");
    if(n>red.size())
        throw std::range_error("Nedovoljno karata u redu!");
    if(BacanjeIzuzetka(s)) throw std::logic_error("Neispravna lista!");

    for(int i=0; i<n; i++) {
        if(red.size()==0) break;
        auto element(red.front());
        red.pop();
        std::pair<Boje, std::string> ubacena_k;
        if(element.first=="Pik") ubacena_k.first=Boje::Pik;
        else if(element.first=="Tref") ubacena_k.first=Boje::Tref;
        else if(element.first=="Herc") ubacena_k.first=Boje::Herc;
        else ubacena_k.first=Boje::Karo;
        ubacena_k.second=element.second;
        Spil provjera_izuzetak;                                                 //Kreiram spil jer fja za provjeru prima spil karata
        provjera_izuzetak.push_back(ubacena_k);
        if(BacanjeIzuzetka(provjera_izuzetak)) throw std::logic_error("Neispravne karte!");
        auto it(std::find_if(s.begin(), s.end(), [ubacena_k] (const std::pair<Boje, std::string> &p1) {
            return int (p1.first)==int(ubacena_k.first) && p1.second==ubacena_k.second;
        }));
        if(it==s.end()) {                                                       //ukoliko nije pronadjena ista karta iz mape u spilu
            auto it1(std::upper_bound(s.begin(), s.end(), ubacena_k, []
                (const std::pair<Boje, std::string> &karta1,const std::pair<Boje, std::string> &karta2) {
                if(int(karta1.first)!=int(karta2.first))
                    return int(karta1.first)<int(karta2.first);
                else {
                    if(karta1.second==karta2.second) return false;
                    return std::find(vrijednost_k.begin(), vrijednost_k.end(), karta1.second)
                           <std::find(vrijednost_k.begin(), vrijednost_k.end(), karta2.second);
                }
            }));
            s.insert(it1, ubacena_k);
        }
    }
}

void IspisiSpil(const Spil &spil)
{
    std::cout<<"Pik: ";
    auto it(spil.begin());
    while(it!=spil.end()) {
        if(it->first==Boje::Pik) std::cout<<it->second<<" ";
        it++;
    }
    std::cout<<std::endl<<"Tref: ";
    it=spil.begin();
    while(it!=spil.end()) {
        if(it->first==Boje::Tref) std::cout<<it->second<<" ";
        it++;
    }
    std::cout<<std::endl<<"Herc: ";
    it=spil.begin();
    while(it!=spil.end()) {
        if(it->first==Boje::Herc) std::cout<<it->second<<" ";
        it++;
    }
    std::cout<<std::endl<<"Karo: ";
    it=spil.begin();
    while(it!=spil.end()) {
        if(it->first==Boje::Karo) std::cout<<it->second<<" ";
        it++;
    }
}

int main()
{
    try {
        auto spil(KreirajSpil());
        std::cout<<"Unesite korak razbrajanja: ";
        int r;
        std::cin>>r;
        std::cout<<"Unesite broj karata koje zelite izbaciti: ";
        int n;
        std::cin>>n;
        auto red_izbacenih(IzbaciKarteRazbrajanjem(spil, r, n));
        std::cout<<"U spilu trenutno ima "<<spil.size()<<" karata, i to: "<<std::endl;
        IspisiSpil(spil);
        std::cout<<std::endl<<"Unesite broj karata koje zelite vratiti u spil: ";
        int n1;
        std::cin>>n1;
        VratiPrvihNKarata(spil, red_izbacenih, n1);
        std::cout<<"U spilu trenutno ima "<<spil.size()<<" karata, i to:"<<std::endl;
        IspisiSpil(spil);
    } catch (std::logic_error izuzetak) {
        std::cout<<"Izuzetak: "<<izuzetak.what()<<std::endl;
    } catch (std::range_error izuzetak ) {
        std::cout<<"Izuzetak: "<<izuzetak.what()<<std::endl;
    } catch (std::domain_error izuzetak) {
        std::cout<<"Izuzetak: "<<izuzetak.what()<<std::endl;
    }
    return 0;
}
