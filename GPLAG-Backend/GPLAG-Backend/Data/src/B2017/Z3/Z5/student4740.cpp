/B2017/2018: Zadaća 3, Zadatak 5
#include <iostream>
#include <vector>
#include <new>
#include <map>
#include <algorithm>
#include <utility>
#include<queue>
#include <stdexcept>
enum class Boje
{
    Pik, Tref, Herc, Karo
} ;
const std::vector<std::string> imena {"2","3","4","5","6","7","8","9","10","J","Q","K","A"} ;
const std::vector<std::string> znakovi {"Pik","Tref","Herc","Karo"} ;

//typedef std::list<std::pair<Boje, std::string>> spil_karata ;

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
    Cvor *poc(nullptr),*prethodni;
    for(int i=0; i<4; i++) {
        for(int j=0; j<13; j++) {
            Cvor *novi(nullptr);
            novi=new Cvor {{Boje(i), imena[j]}, nullptr};
            if(poc==nullptr) poc=novi;
            else prethodni->sljedeci=novi;
            prethodni=novi;
            if(i==3 && j==12) novi->sljedeci=poc;
        }
    }
    return poc;
}
int BrojElemenata(Cvor* const &pocetak)
{
    int br(0);
    if(pocetak==nullptr) return br;
    for(Cvor *p=pocetak;; p=p->sljedeci) {
        if(br!=0 && p==pocetak) break;
        br++;
    }
    return br;
}
void IspisiSpil(Cvor* const &pocetak)
{
    std::cout << "U spilu trenutno ima "<< BrojElemenata(pocetak) <<" karata, i to:" << std::endl;
    for(int i(0); i<4; i++) {
        std::cout << znakovi[i] <<": ";
        int br(0);
        for(Cvor *p=pocetak; ; p=p->sljedeci) {
            if(br!=0 && p==pocetak) break;
            if(p->karta.boja==Boje(i)) std::cout << p->karta.vrijednost <<" ";
            br++;
        }
        std::cout << std::endl;
    }
}
void IzbaciKarte(Cvor *pocetak, std::multimap<Boje, std::string> multim)
{
    if(BrojElemenata(pocetak)==0) throw std::logic_error("Neispravna lista!");
    for(auto it(multim.begin()); it!=multim.end(); it++) {
        //std::pair<Boje, std::string> par;
        auto first=it->first;
        auto second=it->second;
        //Karta test; test.boja=first; test.vrijednost=second;
        Cvor *trenutni(pocetak), *prethodni;
        bool nadjen(true);
        while(trenutni->karta.boja!=first && trenutni->karta.vrijednost!=second){
            if(trenutni->sljedeci==pocetak){ nadjen=false; break; }
            prethodni=trenutni;
            trenutni=trenutni->sljedeci;
        }
        if(!nadjen) continue;
        if(trenutni->sljedeci==pocetak){
            pocetak=nullptr; delete pocetak; 
            it=multim.erase(it); it--; continue;}
        if(trenutni==pocetak){
            for(prethodni=pocetak;prethodni->sljedeci!=pocetak;prethodni=prethodni->sljedeci);
            pocetak=trenutni->sljedeci;
            prethodni->sljedeci=pocetak;
            delete trenutni;
            it=multim.erase(it); it--; continue;
        }
        else if(trenutni->sljedeci==pocetak){
            prethodni->sljedeci=pocetak;
            delete trenutni;
            it=multim.erase(it); it--; continue;
        }else {
            prethodni->sljedeci=trenutni->sljedeci;
            delete trenutni;
            it=multim.erase(it); it--; continue;
        }

    }
    
}
std::queue<std::pair<Boje, std::string>> IzbaciKarteRazbrajanjem(Cvor* pocetak, short int r, int b)
{
    if(r<1 || r>52 || b<1) throw std::logic_error("Neispravni elementi za izbacivanje!");
    if(BrojElemenata(pocetak)==0) throw std::logic_error("Neispravna lista!");

    std::queue<std::pair<Boje,std::string>> red ;
    auto trenutni(pocetak);
    trenutni=trenutni->sljedeci;
    auto prethodni(pocetak);
    int br(1);
    int bii(0);
    while(br!=r) {
        trenutni=trenutni->sljedeci;
        prethodni=prethodni->sljedeci;
        br++;
    }
    while(BrojElemenata(pocetak)>0 && bii<b) {
        if(br%r==0) {
            std::pair<Boje, std::string> par;
            par.first=trenutni->karta.boja;
            par.second=trenutni->karta.vrijednost;
            red.push(par);
            prethodni=trenutni->sljedeci;
            delete trenutni;
            br++;
            bii++;
        } else {
            trenutni=trenutni->sljedeci;
            prethodni=prethodni->sljedeci;
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
void VratiPrvihNKarata(Cvor* pocetak, std::queue<std::pair<Boje, std::string>> &red, int n)
{
    if(n<0) throw std::domain_error ("Broj n je besmislen!");
    if(n>red.size()) throw std::range_error ("Nedovoljno karata u redu!");
    ProvjeriRed(red);
    for(int i(0); i<n; i++) {
        auto element(red.front());
        auto it(pocetak);
        while(it->karta.boja<element.first) it=it->sljedeci;
        auto tu(std::find(imena.begin(), imena.end(),element.second));
        while(std::find(imena.begin(), imena.end(),it->karta.vrijednost)<tu) it=it->sljedeci;
        auto q(it->sljedeci->sljedeci);
        Cvor *novi(nullptr);
        novi=new Cvor {{element.first, element.second}, nullptr};
        it=novi; novi->sljedeci=q;
        red.pop();
    }
}

void UnistiSpil(Cvor *pocetak){
    if(pocetak==nullptr) return;
    //int vel(BrojElemenata(pocetak));
    Cvor *p=pocetak;
    Cvor *naredni;
 
       int br(0);
    for(Cvor *q=pocetak;; q=q->sljedeci) {
        if(br!=0 && q->sljedeci==pocetak) {q=nullptr; break;}
        br++;
    }
       while(p!=nullptr){
        naredni=p->sljedeci;
        delete p;
        p=naredni;
    }
}
int main ()
{
   Cvor* spil(KreirajSpil());
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
    UnistiSpil(spil);
    return 0;
}