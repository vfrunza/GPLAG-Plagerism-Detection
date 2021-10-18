#include <iostream>
#include <iterator>
#include <list>
#include <map>
#include <queue>
#include <stdexcept>
#include <string>
#include <utility>
#include <vector>

using namespace std;

enum class Boje {Pik, Tref, Herc, Karo}; // boje

typedef pair<Boje,string> karta; // tip elemenata špila

typedef pair<string,string> par; // tip elemenata reda

const vector<Boje> boje_karata{Boje::Pik, Boje::Tref, Boje::Herc, Boje::Karo}; // vektor sa svim bojama

const vector<string> imena_karata{"2","3","4","5","6","7","8","9","10","J","Q","K","A"}; // vektor sa svim imenima

/* FUNKCIJE */

list<karta> KreirajSpil() {
    list<karta> Spil;
    for(int k=0;k<boje_karata.size();k++) {
        for(int i=0;i<13;i++) Spil.push_back(make_pair(boje_karata.at(k),imena_karata.at(i)));
    }
    return Spil;
} // završena, radi

void ImaIzac(list<karta> &Spil) {
    if(Spil.size()>52) throw logic_error("Neispravna lista!");
    int pik(0),tref(0),herc(0),karo(0);
    for(auto a : Spil) {
        if(a.first==Boje::Pik) pik++;
        else if(a.first==Boje::Tref) tref++;
        else if(a.first==Boje::Herc) herc++;
        else if(a.first==Boje::Karo) karo++;
        else throw logic_error("Neispravna lista!");
        
    }
    for(auto a : Spil) {
        int i(0);
        if(a.first!=Boje::Pik) break;
        
        for(int j=0;j<imena_karata.size();j++) {
            if(a.second==)
        }
    }
} // završena, treba testirati

void IzbaciKarte(list<karta> &Spil, multimap<Boje,string> &mapa) {
    ImaIzac(Spil); 
    list<karta>::iterator it(Spil.begin());
    for(auto a : Spil) {
        for(auto b=mapa.begin();b!=mapa.end();b++) {
            if(a.first==b->first && a.second==b->second) {
                Spil.erase(it);
                mapa.erase(b);
                b--;
                it--;
                break;
            }
        }
        it++;
    }
} // završena, treba testirati

queue<par> IzbaciKarteRazbrajanjem(list<karta> &Spil, const short int r, const int b) {
    if(r<1 || r>52 || b<1) throw logic_error("Neispravni elementi za izbacivanje!");
    ImaIzac(Spil);
    queue<par> Izbacene;
    list<karta>::iterator it(Spil.begin());
    cout << it->second;
    for(int i=0;i<b;i++) {
        if(Spil.size()==0) break;
        for(int j=0;j<r;j++) {
            if(Spil.size()==0) break;
            if(it==Spil.end()) it=Spil.begin();
            else it++;
        }
        string pomocni;
        if(it->first==Boje::Pik) pomocni="Pik";
        if(it->first==Boje::Tref) pomocni="Tref";
        if(it->first==Boje::Herc) pomocni="Herc";
        if(it->first==Boje::Karo) pomocni="Karo";
        Izbacene.push(make_pair(pomocni,it->second));
        Spil.erase(it);
    }
    return Izbacene;
} // ne radi

void ImaIzacOpet(queue<par>) {
    // baca logic_error sa tekstom "Neispravne karte!"
} // nije završena, treba za funkciju VratiPrvihNKarata

void VratiPrvihNKarata(list<karta> &Spil, queue<par> &red, int n) {
    if(n>red.size()) throw range_error("Nedovoljno karata u redu!");
    if(n<1) throw domain_error("Broj n je besmislen!");
    ImaIzac(Spil);
    ImaIzacOpet(red);
} // ni započeta...

void Ispis(list<karta> &Spil) {
    cout << "U spilu trenutno ima " << Spil.size() <<  " karata, i to:";
    cout << "\nPik: ";
    for(auto a : Spil) {
        if(a.first==Boje::Pik) cout << a.second << " ";
    }
    cout << "\nTref: ";
    for(auto a : Spil) {
        if(a.first==Boje::Tref) cout << a.second << " ";
    }
    cout << "\nHerc: ";
    for(auto a : Spil) {
        if(a.first==Boje::Herc) cout << a.second << " ";
    }
    cout << "\nKaro: ";
    for(auto a : Spil) {
        if(a.first==Boje::Karo) cout << a.second << " ";
    }
} // završena, radi

int main() {
    try {
        cout << "Unesite korak razbrajanja: ";
        int r; cin >> r;
        cout << "Unesite broj karata koje zelite izbaciti: ";
        int b; cin >> b;
        list<karta> Spil(KreirajSpil());
        cout << " tuspas mene ";
        queue<par> red(IzbaciKarteRazbrajanjem(Spil,r,b));
        Ispis(Spil);
        cout << "Unesite broj karata koje zelite vratiti u spil: ";
        int n; cin >> n;
        VratiPrvihNKarata(Spil,red,n);
        Ispis(Spil);
    	return 0;
    }
    catch(domain_error izuzetak) {
        cout << "Izuzetak: " << izuzetak.what();
    }
    catch(logic_error izuzetak) {
        cout << "Izuzetak: " << izuzetak.what();
    }
    catch(range_error izuzetak) {
        cout << "Izuzetak: " << izuzetak.what();
    }
} // završen