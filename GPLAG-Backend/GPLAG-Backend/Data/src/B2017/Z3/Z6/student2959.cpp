/B2017/2018: Zadaća 3, Zadatak 6
#include <iostream>
#include <iterator>
#include <stdexcept>
#include <string>
#include <new>
#include <stack>
#include <vector>
#include <memory>
#include <map>
#include <utility>

std::vector<std::string> ime_karte {"2","3","4","5","6","7","8","9","10","J","Q","K","A"};

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
    std::shared_ptr<Cvor> sljedeci;
};

typedef std::shared_ptr<Cvor> pok;

bool JeLiKruzna(pok pocetak)
{
    if(pocetak==nullptr) return true;
    auto temp=pocetak->sljedeci;
    for(int i=0; i<52; i++) {
        if(temp==nullptr) return false;
        if(temp==pocetak) return true;
        temp=temp->sljedeci;
    }
    return false;
}

int BrojKarata(pok pocetak)
{
    if(pocetak==nullptr) return 0;
    int brojac(0);
    auto temp=pocetak;
    do {
        brojac++;
        temp=temp->sljedeci;
    } while(temp!=pocetak);
    return brojac;
}

bool ValjanostKarti(pok pocetak)
{
    if(pocetak==nullptr) return true;
    auto temp=pocetak;
    do {
        auto b=temp->karta.boja;
        if(b!=Boje::Pik && b!=Boje::Herc && b!=Boje::Tref && b!=Boje::Karo) return false;
        auto d=temp->karta.vrijednost;
        bool ima(false);
        for(int i=0; i<13; i++) {
            if(d==ime_karte[i]) {
                ima=true;
                break;
            }
        }
        if(!ima) return false;
        temp=temp->sljedeci;
    } while(temp!=pocetak);
    return true;
}

bool ValjanostSteka(std::stack<std::pair<std::string,std::string>> stek)
{
    while(!stek.empty()) {
        auto prvi=stek.top().first;
        if(prvi!="Pik" && prvi!="Herc" && prvi!="Karo" && prvi!="Tref") return false;
        bool ima(false);
        for(int i=0; i<13; i++) {
            if(ime_karte[i]==stek.top().second) {
                ima=true;
                break;
            }
        }
        if(!ima) return false;
        stek.pop();
    }
    return true;
}

void IspravnostSpila(pok pocetak)
{
    if(!JeLiKruzna(pocetak)) throw std::logic_error("Neispravna lista!");
    if(pocetak==nullptr) return;
    int br_karata=BrojKarata(pocetak);
    if(br_karata>52) throw std::logic_error("Neispravna lista!");
    if(!ValjanostKarti(pocetak)) throw std::logic_error("Neispravna lista!");
    auto temp=pocetak->sljedeci;
    auto prethodni=pocetak;
    do {
        int i,j;
        for(i=0; i<13; i++) if(ime_karte[i]==prethodni->karta.vrijednost) break;
        for(j=0; j<13; j++) if(ime_karte[j]==temp->karta.vrijednost) break;
        if(prethodni->karta.boja>temp->karta.boja) throw std::logic_error("Neispravna lista!");
        if(prethodni->karta.boja==temp->karta.boja && i>j)  throw std::logic_error("Neispravna lista!");
        temp=temp->sljedeci;
    } while(temp!=pocetak);
}

pok KreirajSpil()
{
    pok pocetak(nullptr), prethodni;
    for(int i=0; i<13; i++) {
        pok novi=std::make_shared<Cvor>();
        novi->karta= {Boje::Pik,ime_karte[i]};
        novi->sljedeci=nullptr;
        if(!pocetak) pocetak=novi;
        else prethodni->sljedeci=novi;
        prethodni=novi;
    }
    for(int i=0; i<13; i++) {
        pok novi=std::make_shared<Cvor>();
        novi->karta= {Boje::Tref,ime_karte[i]};
        novi->sljedeci=nullptr;
        prethodni->sljedeci=novi;
        prethodni=novi;
    }
    for(int i=0; i<13; i++) {
        pok novi=std::make_shared<Cvor>();
        novi->karta= {Boje::Herc,ime_karte[i]};
        novi->sljedeci=nullptr;
        prethodni->sljedeci=novi;
        prethodni=novi;
    }
    for(int i=0; i<13; i++) {
        pok novi=std::make_shared<Cvor>();
        novi->karta= {Boje::Karo,ime_karte[i]};
        novi->sljedeci=nullptr;
        prethodni->sljedeci=novi;
        prethodni=novi;
        if(i==12) prethodni->sljedeci=pocetak;
    }
    return pocetak;
}

void IzbaciKarte(pok &pocetak, std::multimap<Boje,std::string> &izbaci)
{
    try {
        IspravnostSpila(pocetak);
    } catch(std::logic_error izuzetak) {
        throw;
    }
    for(auto it=izbaci.begin(); it!=izbaci.end();) {
        bool nasao(false);
        pok temp=pocetak, prethodni(nullptr);
        do {
            if(temp->karta.boja==it->first && temp->karta.vrijednost==it->second) {
                if(pocetak->sljedeci==pocetak && prethodni==nullptr) { 
                    pocetak->sljedeci=nullptr;
                    pocetak=nullptr;
                    return;
                } else if(temp==pocetak) {
                    prethodni=pocetak;
                    while(prethodni->sljedeci!=pocetak) prethodni=prethodni->sljedeci;
                    pocetak=temp->sljedeci;
                    prethodni->sljedeci=pocetak;
                } else {
                    prethodni->sljedeci=temp->sljedeci;
                }
                it=izbaci.erase(it);
                nasao=true;
                break;
            }
            prethodni=temp;
            temp=temp->sljedeci;
        } while(temp!=pocetak);
        if(!nasao) it++;
    }
}

std::stack<std::pair<std::string,std::string>> IzbaciKarteRazbrajanjem(pok &pocetak, const short int &r, const int &b)
{
    if(r<1 || r>52 || b<1) throw std::logic_error("Neispravni elementi za izbacivanje!");
    try {
        IspravnostSpila(pocetak);
    } catch(std::logic_error izuzetak) {
        throw;
    }
    std::stack<std::pair<std::string,std::string>> stek;
    int izbaceno(0);
    pok temp=pocetak, prethodni(nullptr);
    while(izbaceno!=b) {
        if(pocetak==nullptr) return stek;
        for(int i=0; i<r-1; i++) {
            prethodni=temp;
            temp=temp->sljedeci;
        }
        std::string s;
        Boje b=temp->karta.boja;
        if(b==Boje::Pik) s="Pik";
        else if(b==Boje::Tref) s="Tref";
        else if(b==Boje::Herc) s="Herc";
        else s="Karo";
        stek.push({s,temp->karta.vrijednost});
        if(pocetak->sljedeci==pocetak) {
            pocetak->sljedeci=nullptr;
            pocetak=nullptr;
            return stek;
        } else if(temp==pocetak) {
            prethodni=pocetak;
            while(prethodni->sljedeci!=pocetak) prethodni=prethodni->sljedeci;
            pocetak=temp->sljedeci;
            prethodni->sljedeci=pocetak;
            prethodni=nullptr;
            temp=temp->sljedeci;
        } else {
            prethodni->sljedeci=temp->sljedeci;
            temp=temp->sljedeci;
        }
        izbaceno++;
    }
    return stek;
}

void VratiPosljednjihNKarata(pok &pocetak,std::stack<std::pair<std::string,std::string>> &stek, int n)
{
    int velicina_steka=stek.size();
    if(n>velicina_steka) throw std::range_error("Nedovoljno karata u redu!");
    if(n<0) throw std::domain_error("Broj n je besmislen!");
    if(!ValjanostSteka(stek)) throw std::logic_error("Neispravne karte!");
    for(int i=0; i<n ; i++) {
        std::string s=stek.top().first;
        Boje b;
        if(s=="Pik") b=Boje::Pik;
        else if(s=="Tref") b=Boje::Tref;
        else if(s=="Herc") b=Boje::Herc;
        else b=Boje::Karo;
        pok temp(pocetak),prethodni(nullptr);
        bool uspjesno(false);
        bool duplikat(false);
        do {
            if(pocetak==nullptr) {
                pok novi=std::make_shared<Cvor>();
                novi->karta= {b,stek.top().second};
                novi->sljedeci=nullptr;
                pocetak=novi;
                novi->sljedeci=pocetak;
                temp=pocetak;
                uspjesno=true;
                break;
            }
            if(temp->karta.boja<b) {
                prethodni=temp;
                temp=temp->sljedeci;
                continue;
            }
            int i,j;
            for(i=0; i<13; i++) if(ime_karte[i]==temp->karta.vrijednost) break;
            for(j=0; j<13; j++) if(ime_karte[j]==stek.top().second) break;
            if(temp->karta.boja==b && i<j) {
                prethodni=temp;
                temp=temp->sljedeci;
                continue;
            }
            if(temp->karta.boja==b && i==j) {
                duplikat=true;
                break;
            }
            if(temp==pocetak) {
                pok novi=std::make_shared<Cvor>();
                novi->karta= {b,stek.top().second};
                novi->sljedeci=nullptr;
                while(temp->sljedeci!=pocetak)temp=temp->sljedeci;
                temp->sljedeci=novi;
                novi->sljedeci=pocetak;
                pocetak=novi;
                uspjesno=true;
                break;
            }

            pok novi=std::make_shared<Cvor>();
            novi->karta= {b,stek.top().second};
            novi->sljedeci=nullptr;
            prethodni->sljedeci=novi;
            novi->sljedeci=temp;
            prethodni=temp;
            temp=temp->sljedeci;
            uspjesno=true;
            break;
        } while(temp!=pocetak);
        if(!duplikat && !uspjesno) {
            pok novi=std::make_shared<Cvor>();
            novi->karta= {b,stek.top().second};
            novi->sljedeci=nullptr;
            prethodni->sljedeci=novi;
            novi->sljedeci=pocetak;
        }
        stek.pop();
    }
}

void IspisiSpil(pok pocetak)
{
    pok temp=pocetak;
    int velicina=BrojKarata(pocetak);
    std::cout<<"U spilu trenutno ima "<<velicina<<" karata, i to:"<<std::endl;
    temp=pocetak;
    std::cout<<"Pik: ";
    if(pocetak!=nullptr && temp->karta.boja==Boje::Pik) {
        do {
            std::cout<<temp->karta.vrijednost<<" ";
            temp=temp->sljedeci;
        } while(temp!=pocetak && temp->karta.boja==Boje::Pik);
    }
    std::cout<<std::endl;
    std::cout<<"Tref: ";
    if(pocetak!=nullptr && temp->karta.boja==Boje::Tref) {
        do {
            std::cout<<temp->karta.vrijednost<<" ";
            temp=temp->sljedeci;
        } while(temp!=pocetak && temp->karta.boja==Boje::Tref);
    }
    std::cout<<std::endl;
    std::cout<<"Herc: ";
    if(pocetak!=nullptr && temp->karta.boja==Boje::Herc) {
        do {
            std::cout<<temp->karta.vrijednost<<" ";
            temp=temp->sljedeci;
        } while(temp!=pocetak && temp->karta.boja==Boje::Herc);
    }
    std::cout<<std::endl;
    std::cout<<"Karo: ";
    if(pocetak!=nullptr && temp->karta.boja==Boje::Karo) {
        do {
            std::cout<<temp->karta.vrijednost<<" ";
            temp=temp->sljedeci;
        } while(temp!=pocetak && temp->karta.boja==Boje::Karo);
    }
    std::cout<<std::endl;
}

void Prekini(pok pocetak)
{
    if(pocetak==nullptr) return;
    auto temp=pocetak;
    auto a=temp;
    if(temp!=nullptr) {
        do {
            temp=temp->sljedeci;
            a=temp->sljedeci;
        } while(a!=pocetak);
        temp->sljedeci=nullptr;
    }
}

int main ()
{
    pok spil(nullptr);
    try {
        spil=KreirajSpil();
        std::cout<<"Unesite korak razbrajanja: ";
        short int r;
        std::cin>>r;
        std::cout<<"Unesite broj karata koje zelite izbaciti: ";
        int b;
        std::cin>>b;
        auto stek=IzbaciKarteRazbrajanjem(spil, r,b);
        IspisiSpil(spil);
        std::cout<<"Unesite broj karata koje zelite vratiti u spil: ";
        int n;
        std::cin>>n;
        VratiPosljednjihNKarata(spil,stek,n);
        IspisiSpil(spil);
        Prekini(spil);
    } catch(std::logic_error e) {
        std::cout<<"Izuzetak: "<<e.what();
        Prekini(spil);
    } catch(std::range_error e) {
        std::cout<<"Izuzetak: "<<e.what();
        Prekini(spil);
    }
    return 0;
}
