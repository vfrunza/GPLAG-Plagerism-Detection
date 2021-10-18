/B2017/2018: Zadaća 3, Zadatak 4
#include <iostream>
#include <list>
#include <map> // za multimap
#include <queue>
#include <string>
#include <utility> // za pair
#include <typeinfo>
#include <stdexcept>

using namespace std;

enum class Boje { Pik = 0, Tref, Herc, Karo };
Boje SVE_BOJE[] = { Boje::Pik, Boje::Tref, Boje::Herc, Boje::Karo };
string SVE_BOJE_STR[] = { "Pik", "Tref", "Herc", "Karo" };
string SVE_VRIJEDNOSTI[] = { "2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K", "A" };

bool KomparatorKarti(const pair<Boje, string>& karta1, const pair<Boje, string>& karta2) {
    if (karta1.first != karta2.first) 
        return karta1.first < karta2.first;
        
    string vrijednosti[] = { "2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K", "A" };
    int poz1(-1), poz2(-1);
    
    for (int i = 0; i < 13; i++) {
        if (vrijednosti[i] == karta1.second)
            poz1 = i;
        if (vrijednosti[i] == karta2.second)
            poz2 = i;
    }
    
    if (poz1 < 0 || poz2 < 0)
        throw "AAAAAA";
    
    return poz1 < poz2;
}

bool SmislenaKarta(const string& boja, const string& vrijednost) {
    int i;
    for (i = 0; i < 4; i++)
        if (boja == SVE_BOJE_STR[i]) break;
    
    if (i > 3)
        return false;
        
    for (i = 0; i < 13; i++)
        if (vrijednost == SVE_VRIJEDNOSTI[i]) break;
        
    return i < 13;
}

bool ValidnaLista(const list<pair<Boje, string>>& spil) {
    if (spil.size() > 52)
        return false;
        
    auto temp_spil = spil;
    temp_spil.sort(KomparatorKarti);
    
    if (temp_spil != spil)
        return false;
        
    for (auto it = spil.begin(); it != spil.end(); it++)
        if (!SmislenaKarta(SVE_BOJE_STR[int(it->first)], it->second)) return false;
        
    return true;
}

list<pair<Boje, string>> KreirajSpil();
void IzbaciKarte(list<pair<Boje, string>>&, multimap<Boje, string>&);
queue<pair<string, string>> IzbaciKarteRazbrajanjem(list<pair<Boje, string>>&, const short int&, const int&);
void VratiPrvihNKarata(list<pair<Boje, string>>&, queue<pair<string, string>>&, int);

void PrintSpilInfo(const list<pair<Boje, string>>& spil) {
    cout << "U spilu trenutno ima " << spil.size() << " karata, i to:\n";
    
    auto it = spil.begin();
    
    for (int i = 0; i < 4; i++) {
        cout << SVE_BOJE_STR[i] << ": ";
        
        while (it->first == SVE_BOJE[i]) {
            cout << it->second << " ";
            
            if (it == spil.end())
                break;
                
            it++;
        }
            
        cout << "\n";
    }
}

int main () {
    list<pair<Boje, string>> spil = KreirajSpil();
    queue<pair<string, string>> izbaceno;
    int r, b, n;
    
    cout << "Unesite korak razbrajanja: ";
    cin >> r;
    cout << "Unesite broj karata koje zelite izbaciti: ";
    cin >> b;
    
    try {
        izbaceno = IzbaciKarteRazbrajanjem(spil, r, b);
    } catch(const exception& e) {
        cout << "Izuzetak: " << e.what() << "\n";
        return 0;
    }
    
    PrintSpilInfo(spil);
    cout << "Unesite broj karata koje zelite vratiti u spil: ";
    cin >> n;
    
    try {
        VratiPrvihNKarata(spil, izbaceno, n);
    } catch(const exception& e) {
        cout << "Izuzetak: " << e.what() << "\n";
        return 0;
    }
    
    PrintSpilInfo(spil);
    
	return 0;
}

list<pair<Boje, string>> KreirajSpil() {
    list<pair<Boje, string>> spil;
    
    for (int i = 0; i < 4; i++)
        for (int j = 0; j < 13; j++)
            spil.push_back(pair<Boje, string>(SVE_BOJE[i], SVE_VRIJEDNOSTI[j]));

    return spil;
}

void IzbaciKarte(list<pair<Boje, string>>& spil, multimap<Boje, string>& za_izbaciti) {
    if (!ValidnaLista(spil))
        throw logic_error("Neispravna lista!");
    
    for (auto list_it = spil.begin(); list_it != spil.end(); list_it++) {
        auto razmak = za_izbaciti.equal_range(list_it->first);
        
        for (auto map_it = razmak.first; map_it != razmak.second; map_it++) {
            if (map_it->first == list_it->first && map_it->second == list_it->second) {
                map_it = za_izbaciti.erase(map_it);
                list_it = spil.erase(list_it);
                
                if (list_it != spil.begin())
                    --list_it;
                
                break;
            }
        }
    }
}

queue<pair<string, string>> IzbaciKarteRazbrajanjem(list<pair<Boje, string>>& spil, const short int& r, const int& b) {
    if (r < 1 || r > 52 || b < 1)
        throw logic_error("Neispravni elementi za izbacivanje!");
        
    if (!ValidnaLista(spil))
        throw logic_error("Neispravna lista!");
    
    queue<pair<string, string>> izbaceno;
    int _b = b;
    
    auto it = spil.begin();
    
    while (_b > 0) {
        if (spil.empty())
            break;
        
        for (int i = 1; i < r; i++) {
            if (it == spil.end())
                it = spil.begin();
                
            ++it;
        }

        izbaceno.push(pair<string, string>(SVE_BOJE_STR[int(it->first)], it->second));
        it = spil.erase(it);
        _b -= 1;
    }
    
    return izbaceno;
}

void VratiPrvihNKarata(list<pair<Boje, string>>& spil, queue<pair<string, string>>& red, int n) {
    if (!ValidnaLista(spil))
        throw logic_error("Neispravna lista!");
    
    if (n < 0)
        throw domain_error("Broj n je besmislen!");
    
    if (n > red.size())
        throw range_error("Nedovoljno karata u redu!");
    
    for (int i = 0; i < n; i++) {
        auto karta = red.front();
        
        if (!SmislenaKarta(karta.first, karta.second))
            throw logic_error("Neispravne karte!");
        
        Boje boja;
        
        switch (karta.first[0]) {
            case 'P': // pik
                boja = Boje::Pik;
                break;
            case 'T': // tref
                boja = Boje::Tref;
                break;
            case 'H': // herc
                boja = Boje::Herc;
                break;
            case 'K': // karo
                boja = Boje::Karo;
                break;
            default:
                throw logic_error("Neispravne karte!"); // ovo se ne bi trebalo izvrsiti
                break;
        }
        
        spil.push_back(pair<Boje, string>(boja, karta.second));
        
        red.pop();
    }
    
    spil.sort(KomparatorKarti);
}