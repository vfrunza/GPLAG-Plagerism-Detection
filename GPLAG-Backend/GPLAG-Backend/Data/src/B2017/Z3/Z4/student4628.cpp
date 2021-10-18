/B2017/2018: Zadaća 3, Zadatak 4
#include <iostream>
#include <list>
#include <utility>
#include <queue>
#include <stdexcept>
#include <string>
#include <map>
#include <vector>

enum class Boje {Pik, Tref, Herc, Karo};
std::string karte_vrijednost[13]{"2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K", "A"};
std::string boje_vrijednosti[]{"Pik", "Tref", "Herc", "Karo"};

typedef std::list<std::pair<Boje, std::string>> Spil;

Spil KreirajSpil() {
    Spil spil_karata;
    for(int i=0; i<4; i++) {
        for(int j=0; j<13; j++) {
            std::pair<Boje, std::string> parovi;
            if(i==0) parovi.first=Boje::Pik;
            else if(i==1) parovi.first=Boje::Tref;
            else if(i==2) parovi.first=Boje::Herc;
            else parovi.first=Boje::Karo;
            parovi.second=karte_vrijednost[j];
            spil_karata.push_back(parovi);    
        }
    }
    return spil_karata;
}


bool TestirajKarte(Spil &karte) {
    if(karte.size()==0) return true;
    else {
    bool ispravan=false;
    for(auto it=karte.begin(); it!=karte.end(); it++) {
        if((it->first)==Boje::Pik || it->first==Boje::Tref || it->first==Boje::Herc || it->first==Boje::Karo) {
        ispravan=true;
        }
        if(!ispravan) return false;
        
        for(int i=0; i<13; i++) {
            if(it->second==karte_vrijednost[i]) {
                ispravan=true;
                break;
            }
        }  
        if(!ispravan) return false;
    }
    return ispravan;
    }
}


bool TestirajRed(std::queue<std::pair<std::string, std::string>> red){
    bool ispravan=false;
    while(!red.empty()) {
    auto pom=red.front();
    if(pom.first=="Pik" || pom.first=="Tref" ||pom.first=="Herc" || pom.first=="Karo" ) ispravan=true;
    if(!ispravan) return false;
    for(int i=0; i<13; i++) {
        if(pom.second==karte_vrijednost[i]){
             ispravan=true;
             break;
        }
    }
    if(!ispravan) return false;
    red.pop();
    }
    return ispravan;
}

void IzbaciKarte(Spil &karte, std::multimap<Boje, std::string> &izbaci) {
    if(!TestirajKarte(karte) || karte.size()>52) throw std::logic_error("Neispravna lista!");
    for(auto it1=karte.begin(); it1!=karte.end(); it1++) {
        for(auto it2=izbaci.begin(); it2!=izbaci.end(); it2++) {
            if(it1->first==it2->first && it1->second==it2->second) {
                izbaci.erase(it2);
                it1=karte.erase(it1);
            }
        }
    }
}


std::string PretvoriUString(Boje b) {
    if(b==Boje::Pik) return boje_vrijednosti[0];
    else if(b==Boje::Tref) return boje_vrijednosti[1];
    else if(b==Boje::Herc) return boje_vrijednosti[2];
    else return boje_vrijednosti[3];
}

std::queue<std::pair<std::string, std::string>> IzbaciKarteRazbrajanjem(Spil &karte, const short int &delta, const int &broj) {
    std::queue<std::pair<std::string, std::string>> povratni;
    if(!TestirajKarte(karte) || karte.size()>52) throw std::logic_error("Neispravna lista!");
    if(delta<1 || delta>52 || broj<1) throw std::logic_error("Neispravni elementi za izbacivanje!");
    short int brojac(1);
    int broj_izbacenih(0);
    auto it=karte.begin();
    while(1) {
        if(karte.empty()) break;
        if(broj_izbacenih==broj) break;
        if(brojac==delta) {
            if(it==karte.end()) it=karte.begin();
            std::pair<std::string, std::string> par;
            auto pom=PretvoriUString(it->first);
            par.first=pom; 
            par.second=it->second;
            povratni.push(par);
            broj_izbacenih++;
            it=karte.erase(it);
            
            brojac=1;
        }
        if(it==karte.end()) it=karte.begin();
        it++;
        brojac++;
    }
return povratni;
}

std::pair<Boje, std::string> PretvoriUEnum(std::pair<std::string, std::string> par) {
    std::pair<Boje, std::string> povratni;
    if(par.first=="Pik") povratni.first=Boje::Pik;
    else if(par.first=="Tref") povratni.first=Boje::Tref;
    else if(par.first=="Herc") povratni.first=Boje::Herc;
    else povratni.first=Boje::Karo;
    povratni.second=par.second;
    return povratni;
} 

int VelicinaReda(std::queue<std::pair<std::string, std::string>> red) {
    int vel(0);
    while(!red.empty()) {
        vel++;
        red.pop();
    }
    return vel;
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
        if(par.second==karte_vrijednost[i])
            povratni.second=karte_vrijednost[i-1];
        }
    }
    return povratni;
}

void VratiPrvihNKarata(Spil &karte, std::queue<std::pair<std::string, std::string>> &red, int n) {
    if(!TestirajKarte(karte) || karte.size()>52) throw std::logic_error("Neispravna lista!");
    if(n<0) throw std::domain_error("Broj n je besmislen!");
    if( n>VelicinaReda(red)) throw std::range_error("Nedovoljno karata u redu!");
    if(!TestirajRed(red)) throw std::logic_error("Neispravne karte");
    int broj_ubacenih(0);
    auto it(karte.begin());
    while(broj_ubacenih<n) {
                 auto pom=red.front();
                auto par=VratiPrethodni(pom);
                auto boje=PretvoriUString(it->first);
                if(par.first==boje && par.second==it->second) {
                    if(it==karte.end()) it=karte.begin();
                    it++;
                    auto ubaci(PretvoriUEnum(pom));
                    karte.insert(it,ubaci);
                    broj_ubacenih++;
                    if(!red.empty()) red.pop();
                    if(broj_ubacenih==n) break;
                    if(red.empty()) break;
                }
       if(it==karte.end()) it=karte.begin();
       it++;
    }
}


void IspisiSpil(Spil &karte) {
    if(karte.size()==0) {
        std::cout << "Pik: " << std::endl;
        std::cout << "Tref: " << std::endl;
        std::cout << "Herc: " << std::endl;
        std::cout << "Karo: " << std::endl;
    }
    else {
    for(auto it=karte.begin(); ;) {
        std::cout<<"Pik: ";
        while(PretvoriUString(it->first)=="Pik" && it!=karte.end()) {
            std::cout<<it->second<<" ";
            it++;

        }
        if(it==karte.end()) break;
        std::cout<<std::endl;
        std::cout<<"Tref: ";
        while(PretvoriUString(it->first)=="Tref" && it!=karte.end()) {
            std::cout << it->second<<" ";
            it++;

        }
        if(it==karte.end()) break;
        std::cout<<std::endl;
        std::cout<<"Herc: ";
        while (PretvoriUString(it->first)=="Herc" && it!=karte.end()) {
            std::cout<<it->second<<" ";
            it++;
           
        }
        if(it==karte.end()) break;
        std::cout << std::endl;
        std::cout<<"Karo: ";
        while (PretvoriUString(it->first)=="Karo" && it!=karte.end()) {
            std::cout << it->second<<" ";
             it++;
             if(it==karte.end()) break;
            }
            std::cout << std::endl;
            if(it==karte.end()) break;
       }
    }
}


int main ()
{
    try {
    auto spil(KreirajSpil());
    short int korak(0);
    std::cout<<"Unesite korak razbrajanja: ";
    std::cin>>korak;
    int broj(0);
    std::cout<<"Unesite broj karata koje zelite izbaciti: ";
    std::cin>>broj;
    auto red(IzbaciKarteRazbrajanjem(spil, korak, broj));
    std::cout<<"U spilu trenutno ima "<<spil.size()<<" karata, i to:"<<std::endl;
    IspisiSpil(spil);
    std::cout<<"Unesite broj karata koje zelite vratiti u spil: ";
    int vracaj;
    std::cin>>vracaj;
    VratiPrvihNKarata(spil, red, vracaj);
    std::cout<<"U spilu trenutno ima "<<spil.size()<<" karata, i to: "<<std::endl;
    IspisiSpil(spil);
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
