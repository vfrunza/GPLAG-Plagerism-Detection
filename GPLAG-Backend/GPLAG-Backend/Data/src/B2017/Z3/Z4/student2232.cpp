/B2017/2018: Zadaća 3, Zadatak 4
#include <iostream>
#include <list>
#include <map>
#include <stdexcept>
#include <string>
#include <utility>
#include <vector>
#include <queue>
#include <iterator>

enum class Boje{Pik, Tref, Herc, Karo};
typedef std::list<std::pair<Boje, std::string>> Spil;
typedef std::queue<std::pair<std::string, std::string>> RedKarti;

std::vector<std::string> NaziviKarata {"2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K", "A"};

Spil KreirajSpil()
{
    Spil spil(52);
    int boje(0);
    for(auto it(spil.begin()); it!=spil.end(); it++) {
        for(int i(0); i<int(NaziviKarata.size()); i++) {
            it->first=Boje(boje);
            it->second=NaziviKarata.at(i);
            it++;
        }
        it--;
        boje++;
    }
    return spil;
}


void IspravnostListe(const Spil &spil)
{
    if(spil.size()>52) throw std::logic_error("Neispravna lista!");
    for(auto it1(spil.begin()); it1!=spil.end(); it1++) {
        bool ispravan_element(false);
        int karta1;
        for(int i(0); i<int(NaziviKarata.size()); i++) {
            if(it1->second==NaziviKarata.at(i)) {
                ispravan_element=true;
                karta1=i;
            }
        }
        if(ispravan_element) {
            for(auto it2(spil.begin()); it2!=it1; it2++) {
                if(it2->first>it1->first) throw std::logic_error("Neispravna lista!");
                else if(it2->first==it1->first) {
                    int karta2;
                    for(int i(0); i<int(NaziviKarata.size()); i++) {
                        if(it2->second==NaziviKarata.at(i)) {
                            karta2=i;
                        }
                    }
                    if(karta2>=karta1) throw std::logic_error("Neispravna lista!");
                }
            }
        } else throw std::logic_error("Neispravna lista!");
    }
}

void IspravnostReda(RedKarti red)
{
    while(!red.empty()) {
        if(red.front().first=="Pik" || red.front().first=="Tref" || red.front().first=="Herc" || red.front().first=="Karo") {
            bool ispravan_element(false);
            for(int i(0); i<int(NaziviKarata.size()); i++) {
                if(red.front().second==NaziviKarata.at(i)) ispravan_element=true;
            }
            if(!ispravan_element) throw std::logic_error("Neispravne karte!");
        } else throw std::logic_error("Neispravne karte!");
        red.pop();
    }
}


void IzbaciKarte(Spil &spil, std::multimap<Boje, std::string> &karte)
{
    IspravnostListe(spil);
    for(auto it1(spil.begin()); it1!=spil.end(); it1++)
        for(auto it2(karte.begin()); it2!=karte.end(); it2++)
            if(it2->first==it1->first && it2->second==it1->second) {
                it1=spil.erase(it1);
                it1--;
                karte.erase(it2);
                break;
            }
}

RedKarti IzbaciKarteRazbrajanjem (Spil &spil, const short int &r, const int &b)
{
    if(r<1 || r>52 || b<1) throw std::logic_error("Neispravni elementi za izbacivanje!");
    IspravnostListe(spil);
    RedKarti izbacene_karte;
    auto it(spil.begin());
    for(int i=0; i<b && spil.size()>0; i++) {
        for(int j=1; j<r; j++) {
            if(it==spil.end()) it=spil.begin();
            it++;
        }
        if(it==spil.end()) it=spil.begin();
        switch(it->first) {
        case Boje::Pik:
            izbacene_karte.push({"Pik",it->second});
            break;
        case Boje::Tref:
            izbacene_karte.push({"Tref",it->second});
            break;
        case Boje::Herc:
            izbacene_karte.push({"Herc",it->second});
            break;
        case Boje::Karo:
            izbacene_karte.push({"Karo",it->second});
            break;
        }
        it=spil.erase(it);
    }
    return izbacene_karte;
}

void VratiPrvihNKarata(Spil &spil, RedKarti izbacene_karte, int n)
{
    if(n<0) throw std::domain_error("Broj n je besmislen!");
    if(n>izbacene_karte.size()) throw std::range_error("Nedovoljno karata u redu!");
    IspravnostReda(izbacene_karte);
    IspravnostListe(spil);
    for(int i(0); i<n; i++) {
        Boje boja_karte;
        if(izbacene_karte.front().first=="Pik") boja_karte=Boje::Pik;
        else if(izbacene_karte.front().first=="Tref") boja_karte=Boje::Tref;
        else if(izbacene_karte.front().first=="Herc") boja_karte=Boje::Herc;
        else if(izbacene_karte.front().first=="Karo") boja_karte=Boje::Karo;
        int pozicija;
        for(int j(0); j<int(NaziviKarata.size()); j++) if(izbacene_karte.front().second==NaziviKarata.at(j)) pozicija=j+13*int(boja_karte);
        if(spil.size()==0) {
            spil.push_back({boja_karte, izbacene_karte.front().second});
            izbacene_karte.pop();
        }
        else {
            for(auto it(spil.begin()); it!=spil.end(); it++) {
                auto temp(it);
                temp++;
                if(temp==spil.end()) temp=spil.begin();
                int pozicija_prethodnog(-1), pozicija_narednog(-1);
                for(int j(0); j<int(NaziviKarata.size()); j++) {
                    if(it->second==NaziviKarata.at(j)) pozicija_prethodnog=j+13*int(it->first);
                    if(temp->second==NaziviKarata.at(j)) pozicija_narednog=j+13*int(temp->first);
                    if(pozicija_narednog>-1 && pozicija_prethodnog>-1) break;
                }
                if(temp==it){
                    if(pozicija_narednog<pozicija) spil.push_back({boja_karte, izbacene_karte.front().second});
                    else if(pozicija_narednog>pozicija) spil.insert(temp, {boja_karte, izbacene_karte.front().second});
                    else i--;
                    izbacene_karte.pop();
                    break;
                }
                else if(pozicija_prethodnog==pozicija || pozicija_narednog==pozicija) {
                    i--;
                    izbacene_karte.pop();
                    break;
                } else if((pozicija_prethodnog<pozicija && pozicija_narednog>pozicija) || (pozicija<pozicija_prethodnog && pozicija<pozicija_narednog && pozicija_narednog<pozicija_prethodnog)) {
                    spil.insert(temp, {boja_karte, izbacene_karte.front().second});
                    izbacene_karte.pop();
                    break;
                } else if(pozicija>pozicija_prethodnog && pozicija>pozicija_narednog && pozicija_prethodnog>pozicija_narednog) {
                    spil.push_back({boja_karte,izbacene_karte.front().second});
                    izbacene_karte.pop();
                    break;
                }
            }
        }
    }

}

void IspisiKarte(const Spil &spil)
{   
    IspravnostListe(spil);
    std::cout << "U spilu trenutno ima " << spil.size() << " karata, i to:";
    auto it(spil.begin());
    std::cout << "\nPik:";
    while(it!=spil.end() && it->first==Boje::Pik) { std::cout << " " << it->second; it++;}
    std::cout << "\nTref:";
    while(it!=spil.end() && it->first==Boje::Tref) { std::cout << " " << it->second; it++;}
    std::cout << "\nHerc:";
    while(it!=spil.end() && it->first==Boje::Herc) { std::cout << " " << it->second; it++;}
    std::cout << "\nKaro:";
    while(it!=spil.end() && it->first==Boje::Karo) { std::cout << " " << it->second; it++;}
}


int main ()
{
    Spil spil(KreirajSpil());
    std::cout << "Unesite korak razbrajanja: ";
    short int r;
    std::cin >> r;
    std::cout << "Unesite broj karata koje zelite izbaciti: ";
    int b;
    std::cin >> b;
    try {
        RedKarti izbacene_karte(IzbaciKarteRazbrajanjem(spil, r, b));
        IspisiKarte(spil);
        std::cout << "\nUnesite broj karata koje zelite vratiti u spil: ";
        int n;
        std::cin >> n;
        VratiPrvihNKarata(spil, izbacene_karte, n);
        IspisiKarte(spil);

    } catch(std::range_error e) {
        std::cout << "Izuzetak: "<< e.what() << std::endl;
    } catch(std::domain_error e) {
        std::cout << "Izuzetak: "<< e.what() << std::endl;
    } catch(std::logic_error e) {
        std::cout << "Izuzetak: "<< e.what() << std::endl;
    }
    return 0;
}
