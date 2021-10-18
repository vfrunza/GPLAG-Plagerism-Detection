/B2017/2018: Zadaća 3, Zadatak 5
#include <iostream>
#include <string>
#include <vector>
#include <stdexcept>
#include <map>                      //  NEKE FUNKCIJE SU KOPIRANE
#include <vector>                   //  IZ PRETHODNOG ZADATKA
#include <stack>
using std::vector;
using std::string;
using std::cout;
using std::cin;
enum class Boje
{
    Pik, Tref, Herc, Karo
};
typedef std::multimap<Boje,string> MAPA;
typedef std::stack<std::pair<string,string>> STEK;

struct Karta {
    Boje boja;
    string vrijednost;
};

struct Cvor {
    Karta karta;
    Cvor *sljedeci;
};

Cvor *KreirajSpil()
{
    std::vector<string> vec {"2","3","4","5","6","7","8","9","10","J","Q","K","A"};
    Cvor *pocetni(nullptr),*prethodni;
    try {
        for(int i(0); i<13; i++) {
            Cvor *novi(new Cvor {{Boje::Pik,vec[i]},nullptr});
            if(!pocetni) pocetni=novi;
            else prethodni->sljedeci=novi;
            prethodni=novi;
        }
        for(int i(0); i<13; i++) {
            Cvor *novi(new Cvor {{Boje::Tref,vec[i]},nullptr});
            if(!pocetni) pocetni=novi;
            else prethodni->sljedeci=novi;
            prethodni=novi;
        }
        for(int i(0); i<13; i++) {
            Cvor *novi(new Cvor {{Boje::Herc,vec[i]},nullptr});
            if(!pocetni) pocetni=novi;
            else prethodni->sljedeci=novi;
            prethodni=novi;
        }
        for(int i(0); i<13; i++) {
            Cvor *novi(new Cvor {{Boje::Karo,vec[i]},nullptr});
            if(!pocetni) pocetni=novi;
            else prethodni->sljedeci=novi;
            prethodni=novi;
        }
        prethodni->sljedeci=pocetni;
    } catch(...) {
        for(;;) {
            auto it1(pocetni);
            if(pocetni->sljedeci==nullptr || pocetni==nullptr) {
                delete it1;
                break;
            }
            pocetni=pocetni->sljedeci;
            delete it1;
        }
        throw;
    }
    return pocetni;
}

int BrojEl(Cvor *pocetni)
{
    if(pocetni==nullptr) return 0;
    auto it(pocetni);
    int brojac(1);
    while(it->sljedeci!=pocetni) {
        brojac++;
        it=it->sljedeci;
    }
    return brojac;
}

bool PoBojama(Boje boja1,Boje boja2)
{
    if(boja1==boja2) return true;
    if(boja1==Boje::Pik) return true;
    if(boja1==Boje::Tref && (boja2==Boje::Herc || boja2==Boje::Karo)) return true;
    if(boja1==Boje::Herc && boja2==Boje::Karo) return true;
    return false;
}

bool TestKarte(Boje &boja,string &s)
{
    if(!(boja==Boje::Pik || boja==Boje::Tref || boja==Boje::Herc || boja==Boje::Karo)) return true;
    if(s!="2" && s!="3" && s!="4" && s!="5" && s!="6" && s!="7" && s!="8"
            && s!="9" && s!="10" && s!="J" && s!="Q" && s!="K" && s!="A") return true;
    return false;
}

bool PoVelicini(string s1,string s2)
{
    vector<string> vec {"2","3","4","5","6","7","8","9","10","J","Q","K","A"};
    int a(0),b(0);
    for(int i(0); i<vec.size(); i++) {
        if(s1==vec[i]) a=i;
        if(s2==vec[i]) b=i;
    }
    return a<=b;
}

void Zamijeni(Cvor *(&pok1),Cvor *(&pok2))
{
    if(pok1==pok2) return;
    Cvor *it1(pok1),*it2(pok2),*it3(nullptr);
    while(it1->sljedeci!=pok1) it1=it1->sljedeci;
    while(it2->sljedeci!=pok2) it2=it2->sljedeci;
    if(pok1->sljedeci==pok2) {
        it1->sljedeci=pok2;
        pok1->sljedeci=pok2->sljedeci;
        pok2->sljedeci=pok1;
    } else if(pok2->sljedeci==pok1) {
        it2->sljedeci=pok1;
        pok2->sljedeci=pok1->sljedeci;
        pok1->sljedeci=pok2;
    } else {
        it3=pok2->sljedeci;
        pok2->sljedeci=pok1->sljedeci;
        it2->sljedeci=pok1;
        pok1->sljedeci=it3;
        it1->sljedeci=pok2;
    }
    it3=pok1;
    pok1=pok2;
    pok2=it3;
}

void SortirajBoje(Cvor *(&pocetni))
{
    auto it1(pocetni),it2(pocetni);
    do {
        it2=it1;
        do {
            if(!PoBojama(it1->karta.boja,it2->karta.boja)) {
                if(it1==pocetni) pocetni=it2;
                Zamijeni(it1,it2);
            }
            it2=it2->sljedeci;
        } while(it2!=pocetni);
        it1=it1->sljedeci;
    } while(it1!=pocetni);
}

void SortirajSpil(Cvor *(&pocetni))
{
    if(BrojEl(pocetni)==1) return;
    SortirajBoje(pocetni);
    auto it(pocetni);
    do {
        auto it1(it);
        do {
            if(PoVelicini(it1->karta.vrijednost,it->karta.vrijednost)) {
                if(it==pocetni) pocetni=it1;
                Zamijeni(it,it1);
            }
            it1=it1->sljedeci;
        } while(it1!=pocetni && it1->karta.boja==Boje::Pik);
        it=it->sljedeci;
    } while(it!=pocetni && it->karta.boja==Boje::Pik);
    do {
        auto it1(it);
        do {
            if(PoVelicini(it1->karta.vrijednost,it->karta.vrijednost)) {
                if(it==pocetni) pocetni=it1;
                Zamijeni(it,it1);
            }
            it1=it1->sljedeci;
        } while(it1!=pocetni && it1->karta.boja==Boje::Tref);
        it=it->sljedeci;
    } while(it!=pocetni && it->karta.boja==Boje::Tref);
    do {
        auto it1(it);
        do {
            if(PoVelicini(it1->karta.vrijednost,it->karta.vrijednost)) {
                if(it==pocetni) pocetni=it1;
                Zamijeni(it,it1);
            }
            it1=it1->sljedeci;
        } while(it1!=pocetni && it1->karta.boja==Boje::Herc);
        it=it->sljedeci;
    } while(it!=pocetni && it->karta.boja==Boje::Herc);
    do {
        auto it1(it);
        do {
            if(PoVelicini(it1->karta.vrijednost,it->karta.vrijednost)) {
                if(it==pocetni) pocetni=it1;
                Zamijeni(it,it1);
            }
            it1=it1->sljedeci;
        } while(it1!=pocetni && it1->karta.boja==Boje::Karo);
        it=it->sljedeci;
    } while(it!=pocetni && it->karta.boja==Boje::Karo);
}

void TestirajSpil(Cvor *pocetni)
{
    int br_el(BrojEl(pocetni));
    if(br_el>52) throw std::logic_error("Neispravna lista!");
    if(br_el==1) return;
    auto it1(pocetni),it(pocetni);
    if(TestKarte(it1->karta.boja,it1->karta.vrijednost)) throw std::logic_error("Neispravna lista!");
    it1=it1->sljedeci;
    do {
        if(!PoBojama(it->karta.boja,it1->karta.boja))
            throw std::logic_error("Neispravna lista!");
        if(TestKarte(it1->karta.boja,it1->karta.vrijednost)) throw std::logic_error("Neispravna lista!");
        it=it->sljedeci;
        it1=it1->sljedeci;
    } while(it1!=pocetni);
    it1=pocetni;
    it1=it1->sljedeci;
    it=pocetni;
    do {
        if(!(PoVelicini(it->karta.vrijednost,it1->karta.vrijednost))) {
            if(!PoBojama(it->karta.boja,it1->karta.boja))
                throw std::logic_error("Neispravna lista!");
        } else if(it->karta.vrijednost==it1->karta.vrijednost && it->karta.boja==it1->karta.boja)
            throw std::logic_error("Neispravna lista!");
        it=it->sljedeci;
        it1=it1->sljedeci;
    } while(it1!=pocetni);
    it1=pocetni;
    do {
        auto it2(it1);
        it2=it2->sljedeci;
        if(it2==pocetni) return;
        do {
            if((it1->karta.boja==it2->karta.boja) && (it1->karta.vrijednost==it2->karta.vrijednost))
                throw std::logic_error("Neispravna lista!");
            it2=it2->sljedeci;
        } while(it2!=pocetni);
        it1=it1->sljedeci;
    } while(it1!=pocetni);
}

STEK IzbaciKarteRazbrajanjem(Cvor *(&pocetni),const short int r,const int b)
{
    if(r<1 || r>52 || b<1) throw std::logic_error("Neispravni elementi za izbacivanje!");
    TestirajSpil(pocetni);
    STEK stek;
    auto it(pocetni);
    for(int i(0); i<b && it!=nullptr; i++) {
        for(int j(0); j<r-1; j++) {
            it=it->sljedeci;
        }
        string pom;
        if(it->karta.boja==Boje::Pik) pom="Pik";
        if(it->karta.boja==Boje::Tref) pom="Tref";
        if(it->karta.boja==Boje::Herc) pom="Herc";
        if(it->karta.boja==Boje::Karo) pom="Karo";
        stek.push(std::make_pair(pom,it->karta.vrijednost));
        if(it->sljedeci==it) {
            delete it;
            it=nullptr;
            pocetni=nullptr;
            break;
        }
        auto pom_it(pocetni);
        while(pom_it->sljedeci!=it) pom_it=pom_it->sljedeci;
        pom_it->sljedeci=it->sljedeci;
        if(it==pocetni) pocetni=it->sljedeci;
        delete it;
        it=pom_it->sljedeci;
    }
    return stek;
}

void VratiPosljednjihNKarata(Cvor *(&pocetni),STEK &stek,int n)
{
    if(n<0) throw std::domain_error("Broj n je besmislen!");
    if(n>stek.size()) throw std::range_error("Nedovoljno karata u steku!");
    for(int i(0); i<n; i++) {
        Boje boje;
        if(stek.top().first=="Pik") boje=Boje::Pik;
        if(stek.top().first=="Tref") boje=Boje::Tref;
        if(stek.top().first=="Herc") boje=Boje::Herc;
        if(stek.top().first=="Karo") boje=Boje::Karo;
        if(TestKarte(boje,stek.top().second)) throw std::logic_error("Neispravne karte!");
        Cvor *novi(new Cvor {{boje,stek.top().second},nullptr});
        novi->sljedeci=pocetni->sljedeci;
        pocetni->sljedeci=novi;
        stek.pop();
    }
    SortirajSpil(pocetni);
    TestirajSpil(pocetni);
}

void IzbaciKarte(Cvor *(&pocetni),MAPA &mapa)
{
    TestirajSpil(pocetni);
    auto it2(pocetni);
    for(auto it1(mapa.begin()); it1!=mapa.end(); it1++) {
        do {
            if((it1->first==it2->karta.boja) && (it1->second==it2->karta.vrijednost)) {
                if(it2->sljedeci==it2) {
                    delete it2;
                    pocetni=nullptr;
                    return;
                }
                it1=mapa.erase(it1);
                auto pom1(pocetni);
                while(pom1->sljedeci!=it2) pom1=pom1->sljedeci;
                pom1->sljedeci=it2->sljedeci;
                delete it2;
                it2=pom1;
            }
            it2=it2->sljedeci;
        } while(it2!=pocetni && it2->sljedeci!=it2);
    }
}

void IspisiSpil(Cvor *pocetni)
{
    auto it(pocetni);
    cout<<"Pik: ";
    do {
        if(it->karta.boja==Boje::Pik) cout<<it->karta.vrijednost<<" ";
        it=it->sljedeci;
    } while(it!=pocetni);
    cout<<"\nTref: ";
    it=pocetni;
    do {
        if(it->karta.boja==Boje::Tref) cout<<it->karta.vrijednost<<" ";
        it=it->sljedeci;
    } while(it!=pocetni);
    cout<<"\nHerc: ";
    it=pocetni;
    do {
        if(it->karta.boja==Boje::Herc) cout<<it->karta.vrijednost<<" ";
        it=it->sljedeci;
    } while(it!=pocetni);
    cout<<"\nKaro: ";
    it=pocetni;
    do {
        if(it->karta.boja==Boje::Karo) cout<<it->karta.vrijednost<<" ";
        it=it->sljedeci;
    } while(it!=pocetni);
}

void UnistiSpil(Cvor *pocetni)
{
    auto it(pocetni);
    while(it->sljedeci!=pocetni) it=it->sljedeci;
    it->sljedeci=nullptr;
    while(pocetni!=nullptr) {
        auto it1(pocetni);
        pocetni=pocetni->sljedeci;
        delete it1;
    }
}

int main ()
{
    short int r(0);
    int b(0);
    Cvor *pocetni(nullptr);
    try {
        pocetni=KreirajSpil();
        cout<<"Unesite korak razbrajanja: ";
        cin>>r;
        cout<<"Unesite broj karata koje zelite izbaciti: ";
        cin>>b;
        auto stek(IzbaciKarteRazbrajanjem(pocetni,r,b));
        int br_el(BrojEl(pocetni));
        cout<<"U spilu trenutno ima "<<br_el<<" karata, i to:"<<std::endl;
        IspisiSpil(pocetni);
        int n(0);
        cout<<"\nUnesite broj karata koje zelite vratiti u spil: ";
        cin>>n;
        VratiPosljednjihNKarata(pocetni,stek,n);
        br_el=BrojEl(pocetni);
        cout<<"U spilu trenutno ima "<<br_el<<" karata, i to:"<<std::endl;
        IspisiSpil(pocetni);
    } catch(std::domain_error izuzetak) {
        cout<<"Izuzetak: "<<izuzetak.what();
    } catch(std::logic_error izuzetak) {
        cout<<"Izuzetak: "<<izuzetak.what();
    } catch(std::range_error izuzetak) {
        cout<<"Izuzetak: "<<izuzetak.what();
    } catch(std::bad_alloc) {
        cout<<"Izuzetak: Problemi sa memorijom!";
    }
    UnistiSpil(pocetni);

    return 0;
}
