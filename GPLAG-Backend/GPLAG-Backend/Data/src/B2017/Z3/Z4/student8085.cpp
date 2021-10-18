/B2017/2018: Zadaća 3, Zadatak 4
#include <iostream>
#include <list>
#include <vector>
#include <queue>
#include <stdexcept>
#include <algorithm>

using namespace std;

enum class Boje {Pik, Tref, Herc, Karo};

void Ispisi(list<pair<Boje, string>> spil) {
    cout << "U spilu trenutno ima " << spil.size() << " karata, i to:" << endl;
    for(int i=0; i < 4; i++) {
        switch(i) {
            case 0:
                cout << "Pik: ";
                break;
            case 1:
                cout << "Tref: ";
                break;
            case 2:
                cout << "Herc: ";
                break;
            case 3:
                cout << "Karo: ";
                break;
        }
        for(auto it = spil.begin(); it != spil.end(); it++) {
            if((int)(*it).first == i) cout << (*it).second << " "; 
        }
        cout << endl;
    }
}

string DajBoju(Boje boja) {
    if(boja == Boje::Pik) return "Pik";
    else if(boja == Boje::Tref) return "Tref";
    else if(boja == Boje::Herc) return "Herc";
    else return "Karo";
}

Boje DajBojuBoju(string boja) {
    if(boja == "Pik") return Boje::Pik;
    else if(boja == "Tref") return Boje::Tref;
    else if(boja == "Herc") return Boje::Herc;
    else return Boje::Karo;
}

int RankKarte(string karta) {
    vector<pair<string, int>> Karte = { make_pair("2", 2), make_pair("3", 3), make_pair("4", 4), make_pair("5", 5), make_pair("6", 6), 
        make_pair("7", 7), make_pair("8", 8), make_pair("9", 9), make_pair("10", 10), make_pair("J", 11), make_pair("Q", 12), make_pair("K", 13),
        make_pair("A", 14) };
    
    int rank;    
    for(int i = 0; i < Karte.size(); i++) 
        if(Karte[i].first == karta) rank = Karte[i].second;
    
    return rank;
}

bool ProvjeriKartu(list<pair<Boje, string>> spil) {
    for(auto it = spil.begin(); it != spil.end(); it++) {
        if((*it).first == Boje::Pik || (*it).first == Boje::Tref 
            || (*it).first == Boje::Herc || (*it).first == Boje::Karo
            || RankKarte((*it).second) < 2 || RankKarte((*it).second) > 14) {
                return true;    
            }
    }
    return false;
}

list<pair<Boje, string>> KreirajSpil() {
    list<pair<Boje, string>> spil;
    vector<string> Karte = { "2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K", "A" };
    
    for(int i=0; i < 4; i++) {
        for(int j=0; j < Karte.size(); j++) {
            spil.push_back(make_pair((Boje)i, Karte[j]));
        }
        
    }
    
    return spil;
}

queue<pair<string, string>> IzbaciKarteRazbrajanjem(list<pair<Boje, string>> &spil, short int const &r, int const &b) {
     queue<pair<string, string>> izbaceneKarte;
     if(r < 1 || r > 52 || b < 1) throw logic_error("Neispravni elementi za izbacivanje!");
     if(spil.size() > 52 ) throw logic_error("Neispravna lista!");
     
     int brKarata = b;
     short int korak = r - 1; 
     int brojac = 0;
     while(true) {
         for(auto it = spil.begin(); it != spil.end(); it++) {
            
            if(brojac == korak) {
                izbaceneKarte.push(make_pair(DajBoju((*it).first), (*it).second));
                spil.erase(it++);
                brojac = 0;
                brKarata--;
            }
            brojac++;
            if(brKarata == 0) break;
         }
         if(brKarata == 0) break;
     }
     
     return izbaceneKarte;
}

void VratiPrvihNKarata(list<pair<Boje, string>> &spil, queue<pair<string, string>> &red, int n) {
    if(n < 0 || n > 52) throw domain_error("Broj n je besmislen!");
    if(n > red.size()) throw range_error("Nedovoljno karata u redu!");
    if(spil.size() > 52) throw logic_error("Neispravna lista!");
    while(true) {
        for(auto it = spil.begin(); it != spil.end(); it++) {
            if(red.front().first == DajBoju((*it).first) && RankKarte(red.front().second) < RankKarte((*it).second)
                || red.front().first != DajBoju((*it).first) && RankKarte(red.front().second) == 14) {
                spil.insert(it, make_pair(DajBojuBoju(red.front().first), red.front().second));
                red.pop();
                n--;
            }
            if(n == 0) break;
        }
        if(n == 0) break;
    }
}

int main () //treba uraditi još 1 fju
{
    auto spil = KreirajSpil();
    short int korak;
    int brKarata;
    try {
        cout << "Unesite korak razbrajanja: ";
        cin >> korak;
        cout << "Unesite broj karata koje zelite izbaciti: ";
        cin >> brKarata;
        auto izbaceneKarte = IzbaciKarteRazbrajanjem(spil, korak, brKarata);
        Ispisi(spil);
        cout << "Unesite broj karata koje zelite vratiti u spil: ";
        cin >> brKarata;
        VratiPrvihNKarata(spil, izbaceneKarte, brKarata);
        Ispisi(spil);    
    } catch(domain_error d) {
        cout << "Izuzetak: " << d.what();
    } catch(logic_error l) {
        cout << "Izuzetak: " << l.what();
    } catch(range_error r) {
        cout << "Izuzetak: " << r.what();
    }
    
    
	return 0;
}
