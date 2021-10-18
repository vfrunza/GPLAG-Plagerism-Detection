/B2017/2018: Zadaća 3, Zadatak 5
#include <iostream>
#include <string>
#include <stdexcept>
#include <map>
#include <stack>

enum class Boje{ Pik, Tref, Herc, Karo };

struct Karta{
    Boje boja;
    std::string vrijednost;
};

struct Cvor{
    Karta karta;
    Cvor *sljedeci;
};

Cvor *KreirajSpil() {
    Cvor *posljedni, *prvi{nullptr};
    try{
    for(int i=1; i<=4; i++) {
        for(int j=0; j<13; j++) {
            Karta ubaci;
            if(i==1) ubaci.boja=Boje::Pik;
            else if(i==2) ubaci.boja=Boje::Tref;
            else if(i==3) ubaci.boja=Boje::Herc;
            else ubaci.boja=Boje::Karo;
            if(j<9) ubaci.vrijednost=std::to_string(j+2);
            else if(j==9) ubaci.vrijednost="J";
            else if(j==10) ubaci.vrijednost="Q";
            else if(j==11) ubaci.vrijednost="K";
            else ubaci.vrijednost="A";
            
            Cvor *novi(new Cvor{ubaci, nullptr});
            if(!prvi) prvi=novi;
            else posljedni->sljedeci=novi;
            posljedni=novi;
        }
    }
    posljedni->sljedeci=prvi;
    }
    catch(...) {
        for(Cvor *p=prvi; p!=nullptr; p=p->sljedeci) delete p;
        throw;
    }
    return prvi;
}

int Vrijednost(std::string it) {
    int vrij{0};
    if(it == "2") vrij=1;
    else if(it == "3") vrij=2;
    else if(it == "4") vrij=3;
    else if(it == "5") vrij=4;
    else if(it == "6") vrij=5;
    else if(it == "7") vrij=6;
    else if(it == "8") vrij=7;
    else if(it == "9") vrij=8;
    else if(it == "10") vrij=9;
    else if(it == "J") vrij=10;
    else if(it == "Q") vrij=11;
    else if(it == "K") vrij=12;
    else if(it == "A") vrij=13;
   return vrij;
}

void Provjera(Cvor *cv) {
    Cvor *prelet{cv};
    int br{0};
    while(prelet != cv) {
        br++;
         if(prelet->sljedeci != cv && (prelet->karta).boja > ((prelet->sljedeci)->karta).boja ) throw std::logic_error("Neispravna lista!");
            if((prelet->karta).boja == ((prelet->sljedeci)->karta).boja) {
                if(( (prelet->karta).vrijednost == "2" || (prelet->karta).vrijednost == "3" || (prelet->karta).vrijednost == "4" || 
                     (prelet->karta).vrijednost == "5" || (prelet->karta).vrijednost == "6" || (prelet->karta).vrijednost == "7" || 
                     (prelet->karta).vrijednost == "8" || (prelet->karta).vrijednost == "9" || (prelet->karta).vrijednost == "10" ||
                     (prelet->karta).vrijednost == "J" || (prelet->karta).vrijednost == "Q" || (prelet->karta).vrijednost == "K" || 
                     (prelet->karta).vrijednost == "A") && 
                    (((prelet->sljedeci)->karta).vrijednost == "2" || ((prelet->sljedeci)->karta).vrijednost == "3" || ((prelet->sljedeci)->karta).vrijednost == "4" ||
                     ((prelet->sljedeci)->karta).vrijednost == "5" || ((prelet->sljedeci)->karta).vrijednost == "6" || ((prelet->sljedeci)->karta).vrijednost == "7" ||
                     ((prelet->sljedeci)->karta).vrijednost == "8" || ((prelet->sljedeci)->karta).vrijednost == "9" || ((prelet->sljedeci)->karta).vrijednost == "10" ||
                     ((prelet->sljedeci)->karta).vrijednost == "J" || ((prelet->sljedeci)->karta).vrijednost == "Q" || ((prelet->sljedeci)->karta).vrijednost == "K" ||
                     ((prelet->sljedeci)->karta).vrijednost == "A")) {
                        int vrij{ Vrijednost((prelet->karta).vrijednost) }, vrij2{ Vrijednost(((prelet->sljedeci)->karta).vrijednost) };
                        if(vrij > vrij2) throw std::logic_error("Neispravna lista!");
                }
                else throw std::logic_error("Neispravna lista!");
            }
        prelet=prelet->sljedeci;
    }
    if(br > 52) throw std::logic_error("Neispravna lista!");
}

void IzbaciKarte(Cvor *&prva, std::multimap<Boje, std::string> &M) {
    Provjera(prva);
    auto itmap(M.begin());
    while(itmap != M.end()) {
        Cvor *potraga{prva};
        do{
            if((potraga->karta).boja == itmap->first && (potraga->karta).vrijednost == itmap->second) {
                if(potraga == potraga->sljedeci) {
                    delete potraga;
                    potraga=nullptr;
                    prva=nullptr;
                    itmap=M.erase(itmap);
                    break;
                }
                Cvor *prije{prva};
                while(prije->sljedeci != potraga) prije=prije->sljedeci;
                if(potraga == prva) prva = prva->sljedeci;
                prije->sljedeci=potraga->sljedeci;
                delete potraga;
                potraga=prije;
                itmap=M.erase(itmap);
            }
            potraga=potraga->sljedeci;
        } while(potraga == prva);
        itmap++;
    }
}

std::stack<std::pair<std::string, std::string>> IzbaciKarteRazbrajanjem(Cvor *&prva, const short int &r, const int &b) {
    if(r < 1 || r > 52 || b < 1) throw std::logic_error("Neispravni elementi za izbacivanje!");
    Provjera(prva);
    std::stack<std::pair<std::string, std::string>> vrati;
    int brojac{1}, jelb{0};
    Cvor *pomocna{prva};
    for(;;) {
        if(brojac >= r && brojac%r == 0) {
            std::string upisBoje;
            if((pomocna->karta).boja == Boje::Pik) upisBoje="Pik";
            else if((pomocna->karta).boja == Boje::Tref) upisBoje="Tref";
            else if((pomocna->karta).boja == Boje::Herc) upisBoje="Herc";
            else if((pomocna->karta).boja == Boje::Karo) upisBoje="Karo";
            vrati.push(std::pair<std::string, std::string>(upisBoje, (pomocna->karta).vrijednost));
            if(pomocna == pomocna->sljedeci) {
                delete pomocna;
                pomocna=nullptr;
                prva=nullptr;
                jelb++;
                break;
            }
            Cvor *prije{prva};
            while(prije->sljedeci != pomocna) prije=prije->sljedeci;
            if(pomocna == prva) prva = prva->sljedeci;
            prije->sljedeci=pomocna->sljedeci;
            delete pomocna;
            pomocna=prije->sljedeci;
            jelb++;
            if(jelb == b) break;
        }
        else pomocna=pomocna->sljedeci;
        brojac++;
    }
    return vrati;
}

void VratiPosljednjihNKarata(Cvor *&prva, std::stack<std::pair<std::string, std::string>> &Stek, int n) {
    Provjera(prva);
    if(n < 0) throw std::domain_error("Broj n je besmislen!");
    if(n > Stek.size()) throw std::range_error("Nedovoljno karata u steku!");
    for(int i=0; i<n; i++) {
        Boje bojko;
        if((Stek.top()).first == "Pik") bojko=Boje::Pik;
        else if((Stek.top()).first == "Tref") bojko=Boje::Tref;
        else if((Stek.top()).first == "Herc") bojko=Boje::Herc;
        else if((Stek.top()).first == "Karo") bojko=Boje::Karo;
        else throw std::logic_error("Neispravne karte!");
        if((Stek.top()).second=="2"||(Stek.top()).second=="3"||(Stek.top()).second=="4"||(Stek.top()).second=="5"||(Stek.top()).second=="6"||(Stek.top()).second=="7"||
           (Stek.top()).second=="8"||(Stek.top()).second=="9"||(Stek.top()).second=="10"||(Stek.top()).second=="J"||(Stek.top()).second=="Q"||(Stek.top()).second=="K"||
           (Stek.top()).second=="A") {
            if(prva == nullptr) {
                prva=new Cvor{{bojko, (Stek.top()).second}, prva};
            }
            Cvor *pom{prva};
            bool ImalGa{false};
            do{
                if((pom->karta).boja == bojko && (pom->karta).vrijednost == (Stek.top()).second)  ImalGa=true;
                pom=pom->sljedeci;
            }while(pom!=prva && !ImalGa);
            if(!ImalGa) {
                pom=prva;
                for(;;) {
                    if((pom->karta).boja == bojko || ((pom->sljedeci)->karta).boja == bojko) {
                        Cvor *pompom{pom->sljedeci};
                        Karta UBACI{bojko, (Stek.top()).second};
                        if((Vrijednost((Stek.top()).second) > Vrijednost((pom->karta).vrijednost) && (pom->sljedeci == prva || ((pom->sljedeci)->karta).boja != bojko ||
                          Vrijednost((pompom->karta).vrijednost) > Vrijednost((Stek.top()).second))) || ((pom->karta).boja != bojko && Vrijednost((pompom->karta).vrijednost) >
                            Vrijednost((Stek.top()).second)) ) {
                            Cvor *Novi(new Cvor{UBACI, pompom});
                            pom->sljedeci=Novi;
                            Novi->sljedeci=pompom;
                            break;
                        }
                    }
                    pom=pom->sljedeci;
                    if(pom == prva) break;
                }
            }
        }
        else throw std::logic_error("Neispravne karte!");
        Stek.pop();
    }
}

void UnistiSpil(Cvor *cv) {
    if(cv != nullptr){
        for(;;) {
            Cvor *obrisi{cv};
            obrisi=obrisi->sljedeci;
            if(cv == obrisi) {
                cv->sljedeci=obrisi->sljedeci;
                delete obrisi;
                break;
            }
            cv->sljedeci=obrisi->sljedeci;
            delete obrisi;
        }
    }
}

void ISPISI(Cvor *ispisi) {
    int br{0};
    Cvor *hoda{ispisi};
    if(hoda != nullptr) {
        hoda=ispisi->sljedeci;
        br++;
        while(hoda!=ispisi) {
            hoda=hoda->sljedeci;
            br++;
        }
    }
    std::cout << "U spilu trenutno ima " << br << " karata, i to:" << std::endl;
    hoda=ispisi;
    std::cout << "Pik: ";
    for(;;) {
        if(hoda == nullptr || (hoda->karta).boja != Boje::Pik) break;
        std::cout << (hoda->karta).vrijednost << " ";
        hoda=hoda->sljedeci;
        if(hoda == ispisi || (hoda->karta).boja != Boje::Pik) break;
    }
    std::cout << std::endl << "Tref: ";
    for(;;) {
        if(hoda == nullptr || (hoda->karta).boja != Boje::Tref) break;
        std::cout << (hoda->karta).vrijednost << " ";
        hoda=hoda->sljedeci;
        if(hoda == ispisi || (hoda->karta).boja != Boje::Tref) break;
    }
    std::cout << std::endl << "Herc: ";
    for(;;) {
        if(hoda == nullptr || (hoda->karta).boja != Boje::Herc) break;
        std::cout << (hoda->karta).vrijednost << " ";
        hoda=hoda->sljedeci;
        if(hoda == ispisi || (hoda->karta).boja != Boje::Herc) break;
    }
    std::cout << std::endl << "Karo: ";
    for(;;) {
        if(hoda == nullptr || (hoda->karta).boja != Boje::Karo) break;
        std::cout << (hoda->karta).vrijednost << " ";
        hoda=hoda->sljedeci;
        if(hoda == ispisi || (hoda->karta).boja != Boje::Karo) break;
    }
    std::cout << std::endl;
}

int main (){
    std::cout << "Unesite korak razbrajanja: ";
    short int r;
    std::cin >> r;
    std::cout << "Unesite broj karata koje zelite izbaciti: ";
    int n;
    std::cin >> n;
    Cvor *prvi;
    try {
    prvi=KreirajSpil();
    std::stack<std::pair<std::string, std::string>> STEK;
    STEK=IzbaciKarteRazbrajanjem(prvi, r, n);
    ISPISI(prvi);
    std::cout << "Unesite broj karata koje zelite vratiti u spil: ";
    std::cin >> n;
    VratiPosljednjihNKarata(prvi, STEK, n);
    ISPISI(prvi);
    }
    catch(std::logic_error izuzetak) {
        std::cout << "Izuzetak: " << izuzetak.what();
    }
    catch(std::range_error izuzetak) {
        std::cout << "Izuzetak: " << izuzetak.what();
    }
    UnistiSpil(prvi);
	return 0;
}
