/B2017/2018: Zadaća 3, Zadatak 5
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
#include <stack>

/*const std::vector<std::string> vrijednost_k =
{"2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K", "A"};

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
    Cvor *sljedeci=nullptr;
};

//bool BacanjeIzuzetka(const Spil &s);

Cvor *KreirajSpil ()
{
    Cvor* pocetak(nullptr), *prethodni;
    int brojac(0), brojac_boja(0), ukupno(0);
    for(;;) {
        if(brojac>12) {
            brojac=0;
            brojac_boja++;
        }
        Cvor *novi(new Cvor);
        if(brojac_boja==0) novi->karta.boja=Boje::Pik;
        else if(brojac_boja==1) novi->karta.boja=Boje::Tref;
        else if(brojac_boja==2) novi->karta.boja=Boje::Herc;
        else novi->karta.boja=Boje::Karo;
        novi->karta.vrijednost=vrijednost_k[brojac];
        novi->sljedeci=nullptr;
        if(!pocetak) pocetak=novi;
        else prethodni->sljedeci=novi;
        prethodni=novi;
        brojac++;
        ukupno++;
        if(ukupno==52) {
            prethodni->sljedeci=pocetak;
            delete novi; //???
            break;
        }
    }
    return pocetak;
}

void IzbaciKarte (Cvor *&pocetak, std::multimap<Boje, std::string> &mapa)
{
    int vel_mape(mapa.size());
    /*if(BacanjeIzuzetka(s) || broj_karata>52)
        throw std::logic_error("Neispravna lista!");*/
    auto it(mapa.begin());
    Cvor *prethodni, *p(pocetak);
    for(int i=0; i<vel_mape; i++) {
        bool a(false);
        p=pocetak;
        auto karta(*it);
        while(p->sljedeci!=pocetak) {
            if(p->sljedeci->karta.boja==karta.first && 
            p->sljedeci->karta.vrijednost==karta.second) {
                break; a=true;
            }
            p=p->sljedeci;
        }
        if(a==false) {//???
        auto temp=p->sljedeci; //pr
        p->sljedeci=temp->sljedeci;
        delete temp;
        it=mapa.erase(it);
        continue;
        }
        
        it++;
    
    
}
}

/*bool BacanjeIzuzetka (const Spil &s)
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
}*/

/*std::stack<std::pair<std::string, std::string>> IzbaciKarteRazbrajanjem (Cvor *&pocetak, const short int &r, const int &b)
{
    if(r<1 || r>52 || b<1)
        throw std::logic_error("Neispravni elementi za izbacivanje!");

    //if(BacanjeIzuzetka(s)) throw std::logic_error("Neispravna lista!");         //sada je provjera za bacanje izuzetaka gotova

    std::stack<std::pair<std::string, std::string>> stek_ik;
    std::multimap<Boje, std::string> mapa_k;
    bool veci(false);
    Cvor *pok(pocetak);
    for(int i=0; i<b; i++) {
        //if(s.size()==0) break;
        veci=false;
        for(int j=0; j<r-1; j++) {
            if(pok->sljedeci==pocetak) veci=true;
            pok=pok->sljedeci;
        }
        mapa_k.insert(std::pair<Boje, std::string>(pok->karta.boja, pok->karta.vrijednost));
        std::pair<std::string, std::string> izbacena_k;                         //par(izbacena karta) koji cu smjestiti u red
        if(pok->karta.boja==Boje::Pik) izbacena_k.first="Pik";
        else if(pok->karta.boja==Boje::Tref) izbacena_k.first="Tref";
        else if(pok->karta.boja==Boje::Herc) izbacena_k.first="Herc";
        else izbacena_k.first="Karo";
        izbacena_k.second=pok->karta.vrijednost;
        stek_ik.push(izbacena_k);
        if(veci) pok=pok->sljedeci;
        pok=pok->sljedeci;
    }
    try {
        IzbaciKarte(pocetak, mapa_k);
    } catch (...) {
        throw;
    }
    return stek_ik;
}

void VratiPrvihNKarata (Cvor *&pocetak, std::stack<std::pair<std::string, std::string>> &stek, int n)
{
    if(n<0)
        throw std::domain_error("Broj n je besmislen!");
    if(n>stek.size())
        throw std::range_error("Nedovoljno karata u redu!");
    //if(BacanjeIzuzetka(s)) throw std::logic_error("Neispravna lista!");

    for(int i=0; i<n; i++) {
        //if(red.size()==0) break;
        auto element(stek.top());                                               //uzimam element s vrha steka
        stek.pop();                                                             //brisem taj isti element
        std::pair<Boje, std::string> ubacena_k;
        if(element.first=="Pik") ubacena_k.first=Boje::Pik;
        else if(element.first=="Tref") ubacena_k.first=Boje::Tref;
        else if(element.first=="Herc") ubacena_k.first=Boje::Herc;
        else ubacena_k.first=Boje::Karo;
        ubacena_k.second=element.second;
        /*Spil provjera_izuzetak;                                                 //Kreiram spil jer fja za provjeru prima spil karata
        provjera_izuzetak.push_back(ubacena_k);
        if(BacanjeIzuzetka(provjera_izuzetak)) throw std::logic_error("Neispravne karte!");*/
        Cvor *za_ubacivanje(nullptr);
        za_ubacivanje=new Cvor;
        za_ubacivanje->karta.boja=ubacena_k.first;
        za_ubacivanje->karta.vrijednost=ubacena_k.second;
        Cvor *pok(pocetak->sljedeci);
        pocetak->sljedeci=pok->sljedeci;
        delete pok;
        
        
        
        
        /*auto it(std::find_if(s.begin(), s.end(), [ubacena_k] (const std::pair<Boje, std::string> &p1) {
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
        }*/
    }
}

/*void IspisiSpil(Cvor *pocetak)
{
    Cvor *pok(pocetak);
        std::cout<<"Pik: ";
        do  {
            if(pok->karta.boja==Boje::Pik) std::cout<<pok->karta.vrijednost<<" ";
            pok=pok->sljedeci;
        } while (pok!=pocetak);
        pok=pocetak;
        std::cout<<std::endl<<"Tref: ";
        do {
            if(pok->karta.boja==Boje::Tref) std::cout<<pok->karta.vrijednost<<" ";
            pok=pok->sljedeci;
        } while (pok!=pocetak);
        std::cout<<std::endl<<"Herc: ";
        pok=pocetak;
        do {
            if(pok->karta.boja==Boje::Herc) std::cout<<pok->karta.vrijednost<<" ";
            pok=pok->sljedeci;
        } while (pok!=pocetak);
        std::cout<<std::endl<<"Karo: ";
        pok=pocetak;
        do {
            if(pok->karta.boja==Boje::Karo) std::cout<<pok->karta.vrijednost<<" ";
            pok=pok->sljedeci;
        } while (pok!=pocetak);
}

void UnistiSpil(Cvor *pocetak) {
    Cvor *novi(pocetak->sljedeci);
    while(novi!=pocetak) {
        novi=pocetak->sljedeci;
        delete pocetak;
        pocetak=novi;
    }
    delete pocetak;
}

int main()
{
    auto spil(KreirajSpil());
    try {
        std::cout<<"Unesite korak razbrajanja: ";
        int r;
        std::cin>>r;
        std::cout<<"Unesite broj karata koje zelite izbaciti: ";
        int n;
        std::cin>>n;
        auto stek_izbacenih(IzbaciKarteRazbrajanjem(spil, r, n));
        /*std::cout<<"Stek je: ";
        while (!stek_izbacenih.empty()) {
            std::cout<<stek_izbacenih.top().second<<" ";
            stek_izbacenih.pop();
        }*/
        std::cout<<"U spilu trenutno ima "<<52-n<<" karata, i to: "<<std::endl;
        IspisiSpil(spil);
        std::cout<<std::endl<<"Unesite broj karata koje zelite vratiti u spil: ";
        int n1;
        std::cin>>n1;
        VratiPrvihNKarata(spil, stek_izbacenih, n1);
        std::cout<<"U spilu trenutno ima "<<52-n+n1<<" karata, i to:"<<std::endl;
        IspisiSpil(spil);
        UnistiSpil(spil);
    } catch (std::logic_error izuzetak) {
        UnistiSpil(spil);
        std::cout<<"Izuzetak: "<<izuzetak.what()<<std::endl;
    } catch (std::range_error izuzetak ) {
        UnistiSpil(spil);
        std::cout<<"Izuzetak: "<<izuzetak.what()<<std::endl;
    } /*catch (std::domain_error izuzetak) {
        std::cout<<"Izuzetak: "<<izuzetak.what()<<std::endl;*/
    
    return 0;
}*/
