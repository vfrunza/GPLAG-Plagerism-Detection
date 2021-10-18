/B2017/2018: Zadaća 3, Zadatak 6
#include <iostream>
#include <utility>
#include <map>
#include <string>
#include <vector> 
#include <stdexcept>
#include <stack>
#include <memory>

typedef std::stack<std::pair<std::string, std::string>> Stek_parova;

enum class Boje{Pik, Tref, Herc, Karo};
std::vector<std::string> karte_vrijednosti{"2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K", "A"};
std::vector<Boje> boje_vrijednosti{Boje::Pik, Boje::Tref, Boje::Herc, Boje::Karo};

struct Karta {
    Boje boja;
    std::string vrijednost;
};

struct Cvor {
    Karta karta;
    std::shared_ptr<Cvor> sljedeci;
};

std::string PretvoriUString(Boje b);

std::shared_ptr<Cvor> KreirajSpil() {
    std::shared_ptr<Cvor> prvi;
    std::shared_ptr<Cvor> prethodni;
    for(int i=0; i<4; i++) {
        for(int j=0; j<13; j++) {
            auto novi(std::make_shared<Cvor>());
            if(i==0) novi->karta.boja=Boje::Pik;
            else if(i==1) novi->karta.boja=Boje::Tref;
            else if(i==2) novi->karta.boja=Boje::Herc;
            else novi->karta.boja=Boje::Karo;
            
            novi->karta.vrijednost=karte_vrijednosti[j];

            //novi->sljedeci=nullptr;
            if(i==3 && j==12) {
                novi->sljedeci=prvi;
                prethodni->sljedeci=novi;
                break;
            }
            if(!prvi) prvi=novi;
            else prethodni->sljedeci=novi;
            prethodni=novi;
        }
    }
    return prvi;
}

int BrojKarti(std::shared_ptr<Cvor> p);

bool TestirajListu(std::shared_ptr<Cvor> pocetak) {
    bool ispravna=false;
    if(!pocetak) return 0;
    int broj_karti(0);
    auto p=pocetak;
    for(;;) {
        if(broj_karti==BrojKarti(pocetak) && p==pocetak) break;
        broj_karti++;
        for(int i=0; i<4; i++) {
            if( p->karta.boja==boje_vrijednosti[i]) {
                ispravna=true;
                break;
            }
        }
        for(int i=0; i<karte_vrijednosti.size(); i++) {
            if((p!=nullptr) && p->karta.vrijednost==karte_vrijednosti[i]) {
                ispravna=true;
                break;
            }
        }
       if(p!=nullptr) p=p->sljedeci;
    }
    if(broj_karti>52) return 0;
    return ispravna;
}

void IzbaciKarte(std::shared_ptr<Cvor>& pocetak, std::multimap<Boje, std::string> &izbaci) {
    if(!TestirajListu(pocetak)) {
      
        throw std::logic_error("Neispravna lista");
    }
    if(!pocetak) return;
    std::shared_ptr<Cvor> p(pocetak);
    int brojac(0);
    for(;;) {
        brojac++;
        if(brojac==BrojKarti(pocetak) && p==pocetak) break;
        auto prethodni=p;
        if(p!=pocetak) prethodni=prethodni->sljedeci;
        for(auto it=izbaci.begin(); it!=izbaci.end(); it++) {
            if(p->karta.boja==it->first && p->karta.vrijednost==it->second) {
                if(p==pocetak) pocetak=p->sljedeci;
                prethodni->sljedeci=p->sljedeci;
                izbaci.erase(it);
            }
        }
        p=prethodni->sljedeci;
    } 
}  

int BrojKarti(std::shared_ptr<Cvor> pocetak) {
    if(!pocetak) return 0;
    int broj(1);
    std::shared_ptr<Cvor> p=pocetak;
    p=p->sljedeci;
    int brojac(0);
    for(;;) {
        if(p==pocetak) break;
        brojac++;
        p=p->sljedeci;
        broj++;
    
    }

    return broj;
}

typedef std::pair<std::string, std::string> Par_stringova;

std::string PretvoriUString(Boje b) {
    if(b==Boje::Pik) return "Pik";
    else if(b==Boje::Tref) return "Tref";
    else if(b==Boje::Herc) return "Herc";
    else return "Karo";
}

Stek_parova IzbaciKarteRazbrajanjem(std::shared_ptr<Cvor> &pocetak, const short int &delta, const int &broj) {
    if(!TestirajListu(pocetak)) {

        throw std::logic_error("Neispravna lista!");
    }
    if(delta<1 || delta>52 || broj<1) {
     
        throw std::logic_error("Neispravni elementi za izbacivanje!");
    }
    Stek_parova povratni;
    int brojac(1), broj_izbacenih(0);
    
    auto p(pocetak);
    auto prethodni(p);
    while(broj_izbacenih<broj) {
        if(!pocetak) break;
        Par_stringova par;
        while(brojac<delta) {
           if(!p) break;
           p=p->sljedeci;
            brojac++;
        }
        if(brojac==delta) {
            auto pom(PretvoriUString(p->karta.boja));
            par.first=pom; 
            par.second=p->karta.vrijednost;
            povratni.push(par);
            for(;prethodni->sljedeci!=p; prethodni=prethodni->sljedeci);
             if(p==pocetak) pocetak=p->sljedeci;
                prethodni->sljedeci=p->sljedeci;
                broj_izbacenih++;
                brojac=1;
        }
        
        p=prethodni->sljedeci;
    } 
    return povratni;
}

int VelicinaSteka(Stek_parova stek) {
    int broj(0);
    while(!stek.empty()) {
        auto pom(stek.top());
        broj++;
        stek.pop();
    }
    return broj;
}

bool TestirajStek(Stek_parova s) {
    bool ispravan=false;
    while(!s.empty()) {
    auto pom=s.top();
    if(pom.first=="Pik" || pom.first=="Tref" ||pom.first=="Herc" || pom.first=="Karo" ) ispravan=true;
    if(!ispravan) return false;
    for(int i=0; i<13; i++) {
        if(pom.second==karte_vrijednosti[i]){
             ispravan=true;
             break;
        }
    }
    if(!ispravan) return false;
    s.pop();
    }
    return ispravan;
}

std::pair<std::string, std::string> VratiPrethodni(std::pair<std::string, std::string> par) {
    std::pair<std::string, std::string> povratni;
    if(par.second=="2") {
        if(par.first!="Pik") povratni.second="A";

       if(par.first=="Pik") povratni.first="Pik";
       else if(par.first=="Tref") povratni.first="Pik";
       else if(par.first=="Herc") povratni.first="Tref";
       else povratni.first="Herc";
    }
    else {
        povratni.first=par.first;
        for(int i=0; i<13; i++) {
        if(par.second==karte_vrijednosti[i])
            povratni.second=karte_vrijednosti[i-1];
        }
    }
    return povratni;
}

Boje PretvoriUEnum(std::string s) {
    Boje povratni;
    if(s=="Pik") povratni=Boje::Pik;
    else if(s=="Tref") povratni=Boje::Tref;
    else if(s=="Herc") povratni=Boje::Herc;
    else povratni=Boje::Karo;
    return povratni;
}

void VratiPosljednjihNKarata(std::shared_ptr<Cvor> &pocetak, Stek_parova &stek, int n) {
    if(!TestirajListu(pocetak)) throw std::logic_error("Neispravna lista!");
    if(n<0) throw std::domain_error("Broj n je besmislen!");
    if( n>VelicinaSteka(stek)) throw std::range_error("Nedovoljno karata u redu!");
    if(!TestirajStek(stek)) throw std::logic_error("Neispravne karte");
   
    int broj_ubacenih(0);
    auto p=pocetak;
    auto prethodni=p;
    while(broj_ubacenih<n) {
        if(!stek.empty()) {
           
            auto pom=stek.top();
            for(;;) {
                if(prethodni->sljedeci==p) break;
                prethodni=prethodni->sljedeci;
            }
            std::string boja(PretvoriUString(p->karta.boja));
            auto prosli(VratiPrethodni(pom));

            if(prosli.first==boja && prosli.second==p->karta.vrijednost) {
                auto pokazivac(std::make_shared<Cvor>());
                auto ubaci(PretvoriUEnum(pom.first));
                pokazivac->karta.boja=ubaci;
                pokazivac->karta.vrijednost=pom.second;
                pokazivac->sljedeci=p->sljedeci;
                prethodni=p;
                prethodni->sljedeci=pokazivac;
                broj_ubacenih++;
                stek.pop();
            }
            p=p->sljedeci;
        }
    }
}

void IspisiSpil(std::shared_ptr<Cvor> pocetak) {
    int vel(BrojKarti(pocetak));
    int broj(0);
    auto p=pocetak;
 
    for(;p->sljedeci!=pocetak; p=p->sljedeci) {
        if(broj==vel) break;
        broj++;
        std::cout <<"Pik: ";
        PretvoriUString(p->karta.boja);
        while( PretvoriUString(p->karta.boja)=="Pik") {
            std::cout <<p->karta.vrijednost<<" ";
            p=p->sljedeci;
           if(p==pocetak) break;
        }    
        std::cout<<std::endl;
        std::cout << "Tref: ";
        while( PretvoriUString(p->karta.boja)=="Tref"){
            std::cout <<p->karta.vrijednost<<" ";
            p=p->sljedeci;
           if(p==pocetak) break;
        }
        std::cout << std::endl;
        std::cout<<"Herc: ";
        while( PretvoriUString(p->karta.boja)=="Herc"){
            std::cout <<p->karta.vrijednost<<" ";
            p=p->sljedeci;
            if(p==pocetak) break;
        }
        std::cout << std::endl;
        std::cout << "Karo: ";
        while( PretvoriUString(p->karta.boja)=="Karo"){
            std::cout <<p->karta.vrijednost<<" ";
            p=p->sljedeci;
            if(p==pocetak) {
                break;
            }
                
        }
        std::cout<<std::endl;
        if(p==pocetak){
            p=nullptr;
            break;
        } 
    }
    pocetak=nullptr;
}


int main ()
{
    std::shared_ptr<Cvor> pok(nullptr);
      try {
    pok=KreirajSpil();
    short int korak(0);
    std::cout<<"Unesite korak razbrajanja: ";
    std::cin>>korak;
    int broj(0);
    std::cout<<"Unesite broj karata koje zelite izbaciti: ";
    std::cin>>broj;
    auto stek(IzbaciKarteRazbrajanjem(pok, korak, broj));
    std::cout<<"U spilu trenutno ima "<<BrojKarti(pok)<<" karata, i to:"<<std::endl;
    IspisiSpil(pok);
    std::cout<<"Unesite broj karata koje zelite vratiti u spil: ";
    int vracaj;
    std::cin>>vracaj;
    VratiPosljednjihNKarata(pok, stek, vracaj);
    std::cout<<"U spilu trenutno ima "<<BrojKarti(pok)<<" karata, i to:"<<std::endl;
    IspisiSpil(pok);
    pok=nullptr;
    }
    catch(std::domain_error izuzetak) {
        std::cout<<"Izuzetak: "<<izuzetak.what();
    }
    catch(std::range_error izuzetak2) {
        std::cout <<"Izuzetak: "<< izuzetak2.what();
    }
    catch(std::logic_error izuzetak3) {
         std::cout <<"Izuzetak: "<< izuzetak3.what();
    }
	return 0;
}