/B2017/2018: Zadaća 3, Zadatak 6
#include <iostream>
#include <stdexcept>
#include <stack>
#include <utility>
#include <map>
#include <memory>

enum class Boje {Pik, Tref, Herc, Karo};
typedef std::stack<std::pair<std::string, std::string>> StekKarti;

std::string NaziviKarata[]{"2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K", "A"};
std::string BojeKarata[]{"Pik", "Tref", "Herc", "Karo"};

struct Karta{
    Boje boja;
    std::string vrijednost;
};

struct Cvor{
    Karta karta;
    std::shared_ptr<Cvor> sljedeci;
};

std::shared_ptr<Cvor> KreirajSpil(){
    std::shared_ptr<Cvor> pocetak(nullptr), prethodni;
    for(int i(0); i<52; i++){
        Karta nova_karta;
        nova_karta.boja=Boje(i/13);
        nova_karta.vrijednost=NaziviKarata[i%13];
        std::shared_ptr<Cvor> novi_cvor(std::make_shared<Cvor>());
        *novi_cvor={nova_karta, pocetak};
        if(i==0)  pocetak=novi_cvor;
        else prethodni->sljedeci=novi_cvor;
        prethodni=novi_cvor;
    }
    return pocetak;
}

int BrojKartiUSpilu(std::shared_ptr<Cvor> pocetak){
    if(!pocetak) return 0;
    int broj_karti(0);
    for(auto p(pocetak); p->sljedeci!=pocetak; p=p->sljedeci) broj_karti++;
    return broj_karti+1;
}

void ObrisiKartu(std::shared_ptr<Cvor> &karta, std::shared_ptr<Cvor> &prethodna, std::shared_ptr<Cvor> &naredna){
    if(karta==naredna){
        naredna=nullptr;
        karta=nullptr;
        return;
    }
    if(!prethodna){
        auto p(karta);
        for(p=karta; p->sljedeci!=karta; p=p->sljedeci);
        prethodna=p;
    }
    prethodna->sljedeci=karta->sljedeci;
    karta=naredna;
    naredna=karta->sljedeci;
}

void UnistiSpil(std::shared_ptr<Cvor> pocetak){
    if(!pocetak) return;
    pocetak->sljedeci=nullptr;
    pocetak=nullptr;
}

void IspravnostListe(std::shared_ptr<Cvor> pocetak){
    if(!pocetak) return;
    int broj_karti(0);
    auto p1(pocetak);
    for(p1=pocetak; p1->sljedeci!=pocetak; p1=p1->sljedeci) {
        if((++broj_karti)+1>52) throw std::logic_error("Neispravna lista!");
        if(p1->sljedeci==nullptr) throw std::logic_error("Neispravna lista!");
        bool ispravan_element(false);
        int karta1;
        for(int i(0); i<13; i++) {
            if(p1->karta.vrijednost==NaziviKarata[i]) {
                ispravan_element=true;
                karta1=i;
                break;
            }
        }
        if(ispravan_element) {
            if(p1==pocetak) continue;
            auto p2(pocetak);
            for(p2=pocetak; p2->sljedeci!=p1; p2=p2->sljedeci) {
                if(p2->karta.boja>p1->karta.boja) throw std::logic_error("Neispravna lista!");
                else if(p2->karta.boja==p1->karta.boja) {
                    int karta2;
                    for(int i(0); i<13; i++) {
                        if(p2->karta.vrijednost==NaziviKarata[i]) {
                            karta2=i;
                            break;
                        }
                    }
                    if(karta2>=karta1) throw std::logic_error("Neispravna lista!");
                }
            }
            if(p2->karta.boja>p1->karta.boja) throw std::logic_error("Neispravna lista!");
                else if(p2->karta.boja==p1->karta.boja) {
                int karta2;
                for(int i(0); i<13; i++) {
                    if(p2->karta.vrijednost==NaziviKarata[i]) {
                        karta2=i;
                    }
                }
                if(karta2>=karta1) throw std::logic_error("Neispravna lista!");
            }
        } else throw std::logic_error("Neispravna lista!");
    }
    bool ispravan_element(false);
        int karta1;
        for(int i(0); i<13; i++) {
            if(p1->karta.vrijednost==NaziviKarata[i]) {
                ispravan_element=true;
                karta1=i;
                break;
            }
        }
        if(ispravan_element) {
            if(p1==pocetak) return;
            auto p2(pocetak);
            for(p2=pocetak; p2->sljedeci!=p1; p2=p2->sljedeci) {
                if(p2->karta.boja>p1->karta.boja) throw std::logic_error("Neispravna lista!");
                else if(p2->karta.boja==p1->karta.boja) {
                    int karta2;
                    for(int i(0); i<13; i++) {
                        if(p2->karta.vrijednost==NaziviKarata[i]) {
                            karta2=i;
                            break;
                        }
                    }
                    if(karta2>=karta1) throw std::logic_error("Neispravna lista!");
                }
            }
            if(p2->karta.boja>p1->karta.boja) throw std::logic_error("Neispravna lista!");
                else if(p2->karta.boja==p1->karta.boja) {
                int karta2;
                for(int i(0); i<13; i++) {
                    if(p2->karta.vrijednost==NaziviKarata[i]) {
                        karta2=i;
                    }
                }
                if(karta2>=karta1) throw std::logic_error("Neispravna lista!");
            }
        } else throw std::logic_error("Neispravna lista!");
}

void IspravnostSteka(StekKarti stek){
    while(!stek.empty()){
        if(stek.top().first=="Pik" || stek.top().first=="Tref" || stek.top().first=="Herc" || stek.top().first=="Karo"){
            bool ispravan_element(false);
            for(int i(0); i<13; i++){
                if(stek.top().second==NaziviKarata[i]) ispravan_element=true;
            }
            if(!ispravan_element) throw std::logic_error("Neispravne karte!");
        }
        else throw std::logic_error("Neispravne karte!");
        stek.pop();
    }            
}

void IzbaciKarte(std::shared_ptr<Cvor> &pocetak, std::multimap<Boje, std::string> &karte)
{
    if(!pocetak) return;
    IspravnostListe(pocetak);
    std::shared_ptr<Cvor> trenutni(pocetak), prethodni, naredni;
    if(trenutni->sljedeci==pocetak){
        for(auto it(karte.begin()); it!=karte.end(); it++){
            if(it->first==trenutni->karta.boja && it->second==trenutni->karta.vrijednost){
                trenutni->sljedeci=nullptr;
                pocetak=nullptr;
                karte.erase(it);
                return;
            }
        }
    }
    naredni=trenutni->sljedeci;
    for(prethodni=pocetak; prethodni->sljedeci!=pocetak; prethodni=prethodni->sljedeci);
    for(trenutni=pocetak; trenutni->sljedeci!=pocetak; trenutni=trenutni->sljedeci){
        bool prva(false);
        for(auto it(karte.begin()); it!=karte.end(); it++)
            if(it->first==trenutni->karta.boja && it->second==trenutni->karta.vrijednost) {
                if(trenutni==pocetak) prva=true;
                ObrisiKartu(trenutni, prethodni, naredni);
                if(prva) pocetak=trenutni;
                karte.erase(it);
                break;
            }
        prethodni=prethodni->sljedeci;
        naredni=naredni->sljedeci;
    }
    for(auto it(karte.begin()); it!=karte.end(); it++){
        if(it->first==trenutni->karta.boja && it->second==trenutni->karta.vrijednost){
            ObrisiKartu(trenutni, prethodni, naredni);
            karte.erase(it);
            return;
        }
    }
}


StekKarti IzbaciKarteRazbrajanjem(std::shared_ptr<Cvor> &pocetak, const short int &r, const int &b){
    if(r<1 || r>52 || b<1) throw std::logic_error("Neispravni elementi za izbacivanje!");
    IspravnostListe(pocetak);
    StekKarti izbacene_karte;
    if(!pocetak) return izbacene_karte;
    std::shared_ptr<Cvor> prethodni(nullptr), trenutni(pocetak), naredni(pocetak->sljedeci);
    int broj_karti(BrojKartiUSpilu(trenutni));
    for(int i=0; i<b && broj_karti>0; i++){
        bool prva(false);
        for(int j=1; j<r; j++){
            prethodni=trenutni;
            trenutni=trenutni->sljedeci; 
            naredni=trenutni->sljedeci;
        } 
        switch(trenutni->karta.boja){
            case Boje::Pik: izbacene_karte.push({"Pik", trenutni->karta.vrijednost}); break;
            case Boje::Tref: izbacene_karte.push({"Tref", trenutni->karta.vrijednost}); break;
            case Boje::Herc: izbacene_karte.push({"Herc", trenutni->karta.vrijednost}); break;
            case Boje::Karo: izbacene_karte.push({"Karo", trenutni->karta.vrijednost}); break;
        }
        if(trenutni==pocetak) prva=true;
        ObrisiKartu(trenutni, prethodni, naredni);
        if(prva) pocetak=trenutni;
        broj_karti--;
    }
    return izbacene_karte;
}

void VratiKartuUSpil(std::shared_ptr<Cvor> &pocetak, std::shared_ptr<Cvor> &prethodni, std::shared_ptr<Cvor> &naredni, StekKarti &izbacene_karte, Boje boja_karte, int pozicija, int pozicija_prethodnog){
    Karta nova_karta;
    nova_karta.boja=boja_karte;
    nova_karta.vrijednost=izbacene_karte.top().second;
    std::shared_ptr<Cvor> novi_cvor(std::make_shared<Cvor>());
    *novi_cvor={nova_karta, naredni};
    prethodni->sljedeci=novi_cvor;
    prethodni=novi_cvor;
    if(pozicija_prethodnog>pozicija) pocetak=prethodni;
    izbacene_karte.pop();
}

void VratiPosljednjihNKarata(std::shared_ptr<Cvor> &pocetak, StekKarti izbacene_karte, int n){
    if(n<0) throw std::domain_error("Broj n je besmislen!");
    if(n>izbacene_karte.size()) throw std::range_error("Nedovoljno karata u redu!");
    IspravnostSteka(izbacene_karte); IspravnostListe(pocetak);
    std::shared_ptr<Cvor> prethodni(pocetak), naredni;
    if(pocetak) naredni=pocetak->sljedeci;
    if(!pocetak && n>0 && izbacene_karte.size()>0){
        Boje boja_karte;
        if(izbacene_karte.top().first=="Pik") boja_karte=Boje::Pik;
        else if(izbacene_karte.top().first=="Tref") boja_karte=Boje::Tref;
        else if(izbacene_karte.top().first=="Herc") boja_karte=Boje::Herc;
        else if(izbacene_karte.top().first=="Karo") boja_karte=Boje::Karo;
        Karta nova_karta;
        nova_karta.boja=boja_karte;
        nova_karta.vrijednost=izbacene_karte.top().second;
        std::shared_ptr<Cvor> novi_cvor(std::make_shared<Cvor>());
        *novi_cvor={nova_karta, pocetak};
        pocetak=novi_cvor;
        pocetak->sljedeci=pocetak;
        prethodni=novi_cvor;
        naredni=pocetak->sljedeci;
        izbacene_karte.pop();
        n--;
        if(n>1 && izbacene_karte.size()>1){
            if(izbacene_karte.top().first=="Pik") boja_karte=Boje::Pik;
            else if(izbacene_karte.top().first=="Tref") boja_karte=Boje::Tref;
            else if(izbacene_karte.top().first=="Herc") boja_karte=Boje::Herc;
            else if(izbacene_karte.top().first=="Karo") boja_karte=Boje::Karo;
            nova_karta.boja=boja_karte;
            nova_karta.vrijednost=izbacene_karte.top().second;
            std::shared_ptr<Cvor> novi_cvor(std::make_shared<Cvor>());
            *novi_cvor={nova_karta, pocetak};
            prethodni->sljedeci=novi_cvor;
            prethodni=novi_cvor;
            naredni=prethodni->sljedeci;
            izbacene_karte.pop();
            n--;
        }
    }
    for(int i(0); i<n; i++){
        Boje boja_karte;
        if(izbacene_karte.top().first=="Pik") boja_karte=Boje::Pik;
        else if(izbacene_karte.top().first=="Tref") boja_karte=Boje::Tref;
        else if(izbacene_karte.top().first=="Herc") boja_karte=Boje::Herc;
        else if(izbacene_karte.top().first=="Karo") boja_karte=Boje::Karo;
        int pozicija;
        for(int j(0); j<13; j++) if(izbacene_karte.top().second==NaziviKarata[j]) pozicija=j+13*int(boja_karte);
        for(;;){
            int pozicija_prethodnog(-1), pozicija_narednog(-1);
            for(int j(0); j<13; j++){ 
                if(prethodni->karta.vrijednost==NaziviKarata[j]) pozicija_prethodnog=j+13*int(prethodni->karta.boja);
                if(naredni->karta.vrijednost==NaziviKarata[j]) pozicija_narednog=j+13*int(naredni->karta.boja);
                if(pozicija_prethodnog>-1 && pozicija_narednog>-1) break;
            }
            if(pozicija_prethodnog==pozicija || pozicija==pozicija_narednog){
                i--;
                izbacene_karte.pop();
                break;
            }
            else if((pozicija_prethodnog<pozicija && pozicija_narednog>pozicija) || (pozicija<pozicija_prethodnog && pozicija<pozicija_narednog && pozicija_narednog<pozicija_prethodnog) || (pozicija>pozicija_prethodnog && pozicija>pozicija_narednog && pozicija_prethodnog>pozicija_narednog)){
                VratiKartuUSpil(pocetak, prethodni, naredni, izbacene_karte, boja_karte, pozicija, pozicija_prethodnog);
                break;
            }
            prethodni=naredni;
            naredni=naredni->sljedeci;
        }
    }

}

void IspisiKarte(std::shared_ptr<Cvor> pocetak){
    IspravnostListe(pocetak);
    int broj_karti(BrojKartiUSpilu(pocetak));
    std::cout << "U spilu trenutno ima " << broj_karti << " karata, i to:";
    auto p(pocetak);
    std::cout << "\nPik:";
    if(pocetak) while(p->karta.boja==Boje::Pik && p->sljedeci!=pocetak){ std::cout << " " << p->karta.vrijednost; p=p->sljedeci;}
    std::cout << "\nTref:";
    if(pocetak) while(p->karta.boja==Boje::Tref && p->sljedeci!=pocetak){ std::cout << " " << p->karta.vrijednost; p=p->sljedeci;}
    std::cout << "\nHerc:";
    if(pocetak) while(p->karta.boja==Boje::Herc && p->sljedeci!=pocetak){ std::cout << " " << p->karta.vrijednost; p=p->sljedeci;}
    std::cout << "\nKaro:";
    if(pocetak) while(p->karta.boja==Boje::Karo && p->sljedeci!=pocetak){ std::cout << " " << p->karta.vrijednost; p=p->sljedeci;}
    if(pocetak) std::cout << " " << p->karta.vrijednost;
    
}

int main ()
{
    std::shared_ptr<Cvor> pocetak_spila(KreirajSpil());
    std::cout << "Unesite korak razbrajanja: ";
    short int r;
    std::cin >> r;
    std::cout << "Unesite broj karata koje zelite izbaciti: ";
    int b;
    std::cin >> b;
    try{
        StekKarti izbacene_karte(IzbaciKarteRazbrajanjem(pocetak_spila, r, b));
        IspisiKarte(pocetak_spila);
        std::cout << "\nUnesite broj karata koje zelite vratiti u spil: ";
        int n;
        std::cin >> n;
        VratiPosljednjihNKarata(pocetak_spila, izbacene_karte, n);
        IspisiKarte(pocetak_spila);
    }
    catch(std::range_error e){
        std::cout << "Izuzetak: "<< e.what() << std::endl;
    }
    catch(std::domain_error e){
        std::cout << "Izuzetak: "<< e.what() << std::endl;
    }
    catch(std::logic_error e){
        std::cout << "Izuzetak: "<< e.what() << std::endl;
    }
    UnistiSpil(pocetak_spila);
	return 0;
}