#include<iostream>
#include<vector>
#include<string>
#include<map>
#include<stdexcept>
#include<utility>
#include<memory>
#include<stack>
enum class Boja {Pik,Tref,Herc,Karo};
struct Karta {
    Boja boja;
    std::string vrijednost;
};
struct Cvor {
    Karta karta;
    std::shared_ptr<Cvor> sljedeci;
};
std::shared_ptr<Cvor> KreirajSpil(){
    std::vector<std::string> nazivi {"2","3","4","5","6","7","8","9","10","J","Q","K","A"};
    int j(0);
    std::shared_ptr<Cvor> pocetak(nullptr), prethodni;
    for(int i=0; i<52; i++) {
        std::shared_ptr<Cvor> novi(std::make_shared<Cvor>());
        if(i<13) novi->karta.boja=Boja::Pik;
        else if(i>=13 && i<26) novi->karta.boja=Boja::Tref;
        else if(i>=26 && i<39) novi->karta.boja=Boja::Herc;
        else novi->karta.boja=Boja::Karo;
        novi->karta.vrijednost=nazivi[j];
        novi->sljedeci=nullptr;
        if(!pocetak) pocetak=novi;
        else prethodni->sljedeci=novi;
        prethodni=novi;
        if(i==12 || i==25 || i==38) j=-1;
        j++;
    }
    prethodni->sljedeci=pocetak;
    return pocetak;
}
bool DaLiJeSpilSortiran(std::shared_ptr<Cvor> pocetak) {
    std::shared_ptr<Cvor> prethodni(pocetak),kraj(pocetak);
    pocetak=pocetak->sljedeci;
    for(auto p=pocetak; p!=kraj; p=p->sljedeci) {
        if(prethodni->karta.boja>p->karta.boja) return false;
        prethodni=p;
    }
    return true;
}
bool DaLiJeIspravnaVelicina(std::shared_ptr<Cvor> pocetak) {
    std::shared_ptr<Cvor> kraj(pocetak);
    pocetak=pocetak->sljedeci;
    int brojac(1);
    for(auto p=pocetak; p!=kraj; p=p->sljedeci) brojac++;
    if(brojac>52) return false;
    return true;
}
bool ImaDUplih(std::shared_ptr<Cvor> pocetak) {
    std::shared_ptr<Cvor> prethodni(pocetak),kraj(pocetak);
    pocetak=pocetak->sljedeci;
    for(auto p=pocetak; p!=kraj; p=p->sljedeci) {
        if(prethodni->karta.boja==p->karta.boja && prethodni->karta.vrijednost==p->karta.vrijednost) return true;
        prethodni=p;
    }
    return false;
}
bool DaLiSuIspravniNazivi(std::shared_ptr<Cvor> pocetak) {
    std::shared_ptr<Cvor> kraj(pocetak),pp(pocetak);
    pp=pp->sljedeci;
    auto tmp(pocetak->karta);
    if(tmp.vrijednost!="2" && tmp.vrijednost!="3" && tmp.vrijednost!="4" && tmp.vrijednost!="5" && tmp.vrijednost!="6" && tmp.vrijednost!="7" && tmp.vrijednost!="8" && tmp.vrijednost!="9" && tmp.vrijednost!="10" && tmp.vrijednost!="J" && tmp.vrijednost!="Q" && tmp.vrijednost!="K" && tmp.vrijednost!="A") return false;
    for(auto p=pp; p!=kraj; p=p->sljedeci) {
        tmp=p->karta;
        if(tmp.vrijednost!="2" && tmp.vrijednost!="3" && tmp.vrijednost!="4" && tmp.vrijednost!="5" && tmp.vrijednost!="6" && tmp.vrijednost!="7" && tmp.vrijednost!="8" && tmp.vrijednost!="9" && tmp.vrijednost!="10" && tmp.vrijednost!="J" && tmp.vrijednost!="Q" && tmp.vrijednost!="K" && tmp.vrijednost!="A") return false;
    }
    return true;
}
void IzbaciKarte(std::shared_ptr<Cvor> &pocetak, std::multimap<Boja,std::string> &mapa) {
    if(!DaLiJeIspravnaVelicina(pocetak) || ImaDUplih(pocetak) || !DaLiJeSpilSortiran(pocetak) || !DaLiSuIspravniNazivi(pocetak)) throw std::logic_error("Neispravna lista!");
    std::shared_ptr<Cvor> kraj(pocetak);
    for(auto it=mapa.begin(); it!=mapa.end(); it++) {
        auto par(*it);
        auto pret(pocetak), poc(pocetak);
        poc=poc->sljedeci;
        for(auto i=poc; i!=kraj; i=i->sljedeci) {
            if(it->first==par.first && it->second==par.second) {
                auto brisi(i);
                i=i->sljedeci;
                pret->sljedeci=i;
                if(brisi==kraj) kraj=i;
                break;
            }
            pret=i;
        }
    }
    pocetak=kraj;
}
int BrojKarataUSpilu(std::shared_ptr<Cvor> pocetak) {
    int vel(1);
    std::shared_ptr<Cvor> kraj(pocetak);
    pocetak=pocetak->sljedeci;
    for(auto p=pocetak; p!=kraj; p=p->sljedeci) vel++;
    return vel;
}
std::stack<std::pair<std::string,std::string>> IzbaciKarteRazbrajanjem(std::shared_ptr<Cvor> &pocetak, const short int &r, const int &b) {
    if(r<1|| r>52 || b<1) throw std::logic_error("Neispravni elementi za izbacivanje!");
    if(!DaLiJeIspravnaVelicina(pocetak) || ImaDUplih(pocetak) || !DaLiJeSpilSortiran(pocetak)|| !DaLiSuIspravniNazivi(pocetak)) throw std::logic_error("Neispravna lista!");
    int vel(BrojKarataUSpilu(pocetak));
    int brojk(b);
    std::shared_ptr<Cvor> prethodni,poc(pocetak),kraj(pocetak);
    prethodni=pocetak;
    poc=poc->sljedeci;
    for(auto p=poc; p!=kraj; p=p->sljedeci) prethodni=p;
    std::stack<std::pair<std::string,std::string>> izbaceni;
    while(brojk!=0) {
        short int korak(r);
        while(korak!=1) {
            prethodni=pocetak;
            pocetak=pocetak->sljedeci;
            korak--;
        }
        auto par(pocetak->karta);
        std::string bojaa;
        if(par.boja==Boja::Pik) bojaa="Pik";
        else if(par.boja==Boja::Tref) bojaa="Tref";
        else if(par.boja==Boja::Herc) bojaa="Herc";
        else bojaa="Karo";
        izbaceni.push(std::make_pair(bojaa,par.vrijednost));
        auto brisi(pocetak);
        pocetak=pocetak->sljedeci;
        prethodni->sljedeci=pocetak;
        if(brisi==kraj) kraj=pocetak;
        brojk--;
        vel--;
        if(vel==0) break;
    }
    pocetak=kraj;
    return izbaceni;
}
bool KriterijSortiranja(std::string s1, std::string s2) {
    std::vector<std::string> nazivi{"2","3","4","5","6","7","8","9","10","J","Q","K","A"};
    int prvi(0),drugi(0);
    for(int i=0; i<nazivi.size(); i++) {
        if(s1==nazivi[i]) prvi=i;
        if(s2==nazivi[i]) drugi=i;
    }
    return prvi<drugi;
}
bool DaLiSuIspravniPodaci(std::stack<std::pair<std::string,std::string>> s) {
    while(!s.empty()) {
        auto par(s.top());
        if(par.first!="Tref" && par.first!="Pik" && par.first!="Herc" && par.first!="Karo") return false;
        if(par.second!="2" && par.second!="3" && par.second!="4" && par.second!="5" && par.second!="6" && par.second!="7" && par.second!="8" && par.second!="9" && par.second!="10" && par.second!="J" && par.second!="Q" && par.second!="K" && par.second!="A") return false;
        s.pop();
    }
    return true;
}
void VratPosljednjihNKarata(std::shared_ptr<Cvor>&pocetak, std::stack<std::pair<std::string,std::string>> izbaceni, int n) {
    if(n>int(izbaceni.size())) throw std::range_error("Nedovoljno karata u redu!");
    if(n<0) throw std::domain_error("Broj n je besmislen!");
    if(!(DaLiSuIspravniPodaci(izbaceni))) throw std::logic_error("Neispravne karte!");
    std::shared_ptr<Cvor> kraj(pocetak);
    while(n!=0) {
        auto par(izbaceni.top());
        Boja b;
        if(par.first=="Tref") b=Boja::Tref;
        else if(par.first=="Pik") b=Boja::Pik;
        else if(par.first=="Herc") b=Boja::Herc;
        else b=Boja::Karo;
        std::shared_ptr<Cvor> ima(nullptr),poc(pocetak),prethodni;
        poc=poc->sljedeci;
        for(auto p=poc; p!=kraj; p=p->sljedeci) prethodni=p;
        if(pocetak->karta.boja==b && pocetak->karta.vrijednost==par.second) ima=pocetak;
        for(auto p=poc; p!=kraj; p=p->sljedeci) {
            if(p->karta.boja==b && p->karta.vrijednost==par.second) {
                ima=p;
                break;
            }
        }
        if(!ima) {
            std::shared_ptr<Cvor> novi(std::make_shared<Cvor>());
            novi->karta.boja=b;
            novi->karta.vrijednost=par.second;
            novi->sljedeci=nullptr;
            std::shared_ptr<Cvor> nadji(pocetak);
            while(nadji->karta.boja<b) {
                prethodni=nadji;
                nadji=nadji->sljedeci;
            }
            while(!KriterijSortiranja(par.second,nadji->karta.vrijednost)) {
                prethodni=nadji;
                nadji=nadji->sljedeci;
                if(nadji==kraj) break;
            }
            prethodni->sljedeci=novi;
            novi->sljedeci=nadji;
            if(nadji==pocetak) kraj=novi;
        }
        n--;
        izbaceni.pop();
    }
}
void IspsiSpil(std::shared_ptr<Cvor> pocetak) {
    if(pocetak->karta.boja==Boja::Pik) {
        std::cout<<"Pik: ";
        while(pocetak->karta.boja==Boja::Pik) {
            std::cout<<pocetak->karta.vrijednost<<" ";
            pocetak=pocetak->sljedeci;
        }
        std::cout<<std::endl;
    }
    if(pocetak->karta.boja==Boja::Tref) {
        std::cout<<"Tref: ";
        while(pocetak->karta.boja==Boja::Tref) {
            std::cout<<pocetak->karta.vrijednost<<" ";
            pocetak=pocetak->sljedeci;
        }
        std::cout<<std::endl;
    }
    if(pocetak->karta.boja==Boja::Herc) {
        std::cout<<"Herc: ";
        while(pocetak->karta.boja==Boja::Herc) {
            std::cout<<pocetak->karta.vrijednost<<" ";
            pocetak=pocetak->sljedeci;
        }
        std::cout<<std::endl;
    }
    if(pocetak->karta.boja==Boja::Karo) {
        std::cout<<"Karo: ";
        while(pocetak->karta.boja==Boja::Karo) {
            std::cout<<pocetak->karta.vrijednost<<" ";
            pocetak=pocetak->sljedeci;
        }
        std::cout<<std::endl;
    }
}
int main () {
    std::shared_ptr<Cvor> pocetak(nullptr);
    try {
        pocetak=KreirajSpil();
        short int korak;
        std::cout<<"Unesite korak razbrajanja: ";
        std::cin>>korak;
        int brojk;
        std::cout<<"Unesite broj karata koje zelite izbaciti: ";
        std::cin>>brojk;
        std::stack<std::pair<std::string,std::string>> izbaceni(IzbaciKarteRazbrajanjem(pocetak,korak,brojk));
        std::cout<<"U spilu trenutno ima "<<BrojKarataUSpilu(pocetak)<<" karata, i to: "<<std::endl;
        IspsiSpil(pocetak);
        int broj;
        std::cout<<"Unesite broj karata koje zelite vratiti u spil: ";
        std::cin>>broj;
        VratPosljednjihNKarata(pocetak,izbaceni,broj);
        std::cout<<"U spilu trenutno ima "<<BrojKarataUSpilu(pocetak)<<" karata, i to: "<<std::endl;
        IspsiSpil(pocetak);
    }
    catch(std::domain_error izuz) {
        std::cout<<"Izuzetak: "<<izuz.what()<<std::endl;
    }
    catch(std::logic_error izuz) {
        std::cout<<"Izuzetak: "<<izuz.what()<<std::endl;
    }
    catch(std::range_error izuz) {
        std::cout<<"Izuzetak: "<<izuz.what()<<std::endl;
    }
    std::shared_ptr<Cvor> pret(pocetak),kraj(pocetak);
    pocetak=pocetak->sljedeci;
    for(auto p=pocetak; p!=kraj; p=p->sljedeci) pret=p;
    pret->sljedeci=nullptr;
    return 0;
}
