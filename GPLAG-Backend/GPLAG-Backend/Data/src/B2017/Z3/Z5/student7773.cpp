/B2017/2018: Zadaća 3, Zadatak 5
#include <iostream>
#include <string>
#include <map> // multimap
#include <stack>
#include <utility> // pair

using namespace std;

enum class Boje { Pik = 0, Tref, Herc, Karo };
Boje SVE_BOJE[] = { Boje::Pik, Boje::Tref, Boje::Herc, Boje::Karo };
string SVE_BOJE_STR[] = { "Pik", "Tref", "Herc", "Karo" };
string SVE_VRIJEDNOSTI[] = { "2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K", "A" };

struct Karta {
    Boje boja;
    string vrijednost;
};

struct Cvor {
    Karta karta;
    Cvor* sljedeci;
};

bool KomparatorKarti(const Karta& karta1, const Karta& karta2) {
    if (karta1.boja != karta2.boja) 
        return karta1.boja < karta2.boja;
        
    string vrijednosti[] = { "2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K", "A" };
    int poz1(-1), poz2(-1);
    
    for (int i = 0; i < 13; i++) {
        if (vrijednosti[i] == karta1.vrijednost)
            poz1 = i;
        if (vrijednosti[i] == karta2.vrijednost)
            poz2 = i;
    }
    
    if (poz1 < 0 || poz2 < 0)
        throw "AAAAAA";
    
    return poz1 < poz2;
}

bool SmislenaKarta(const Karta& karta) {
    int i;
    for (i = 0; i < 13; i++)
        if (karta.vrijednost == SVE_VRIJEDNOSTI[i]) break;
        
    return i < 13;
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

Karta KartaIzPara(pair<string, string>& par) {
    Karta karta;
    for (int i = 0; i < 4; i++)
        if (par.first == SVE_BOJE_STR[i])
            karta.boja = SVE_BOJE[i];
            
    karta.vrijednost = par.second;
    
    return karta;
}

Karta KreirajKartu(Boje boja, string vrijednost) {
    Karta karta;
    karta.boja = boja;
    karta.vrijednost = vrijednost;
    
    return karta;
}

Cvor* KreirajSpil();
void IzbaciKarte(Cvor*&, multimap<Boje, string>&);
stack<pair<string, string>> IzbaciKarteRazbrajanjem(Cvor*&, const short int&, const int&);
void VratiPosljednjihNKarata(Cvor*&, stack<pair<string, string>>&, int);
void UnistiSpil(Cvor*&);

void PrintSpilInfo(Cvor*& cvor) {
    Cvor* temp = cvor;
    while (KomparatorKarti(temp->karta, temp->sljedeci->karta))
        temp = temp->sljedeci;
    
    Cvor* prvi = temp;
    int i = 0;
    do {
        temp = temp->sljedeci;
        i++;
    } while (temp != prvi);
    
    cout << "U spilu trenutno ima " << i << " karata, i to:\n";
    
    for (int i = 0; i < 4; i++) {
        cout << SVE_BOJE_STR[i] << ": ";
        
        while (temp->karta.boja != SVE_BOJE[i])
            temp = temp->sljedeci;
        
        while (temp->karta.boja == SVE_BOJE[i]) {
            cout << temp->karta.vrijednost << " ";
            
            temp = temp->sljedeci;
        }
        cout << "\n";
    }
}

int main () {
    Cvor* spil = KreirajSpil();
    stack<pair<string, string>> izbaceno;
    int r, b, n;
    
    cout << "Unesite korak razbrajanja: ";
    cin >> r;
    cout << "Unesite broj karata koje zelite izbaciti: ";
    cin >> b;
    
    try {
        izbaceno = IzbaciKarteRazbrajanjem(spil, r, b);
    } catch(const exception& e) {
        cout << "Izuzetak: " << e.what() << "\n";
        UnistiSpil(spil);
        return 0;
    }
    
    PrintSpilInfo(spil);
    cout << "Unesite broj karata koje zelite vratiti u spil: ";
    cin >> n;
    
    try {
        VratiPosljednjihNKarata(spil, izbaceno, n);
    } catch(const exception& e) {
        cout << "Izuzetak: " << e.what() << "\n";
        UnistiSpil(spil);
        return 0;
    }
    
    PrintSpilInfo(spil);
    
    UnistiSpil(spil);
	return 0;
}

Cvor* KreirajSpil() {
    Cvor* pocetak = new Cvor;
    Cvor* cvor = pocetak;
    
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 13; j++) {
            cvor->karta.boja = SVE_BOJE[i];
            cvor->karta.vrijednost = SVE_VRIJEDNOSTI[j];
            
            if (i == 3 && j == 12)
                cvor->sljedeci = pocetak;
            else
                cvor->sljedeci = new Cvor;
                
            cvor = cvor->sljedeci;
        }
    }
    
    return pocetak;
}

void IzbaciKarte(Cvor*& cvor, multimap<Boje, string>& za_izbaciti) {
    Cvor* prvi = cvor;
    int i = 0;
    do {
        if (i > 51 || !KomparatorKarti(cvor->karta, cvor->sljedeci->karta) || !SmislenaKarta(cvor->karta))
            throw logic_error("Neispravna lista!");
            
        auto razmak = za_izbaciti.equal_range(cvor->karta.boja);
        
        for (auto map_it = razmak.first; map_it != razmak.second; map_it++) {
            if (map_it->first == cvor->karta.boja && map_it->second == cvor->karta.vrijednost) {
                za_izbaciti.erase(map_it);
                
                Cvor* temp = cvor;
                while (cvor->sljedeci != temp)
                    cvor = cvor->sljedeci;
                
                cvor->sljedeci = temp->sljedeci;
                delete temp;
                
                break;
            }
        }
        
        cvor = cvor->sljedeci;
        i++;
    } while (cvor != prvi);
}

stack<pair<string, string>> IzbaciKarteRazbrajanjem(Cvor*& cvor, const short int& r, const int& b) {
    if (r < 1 || r > 52 || b < 1)
        throw logic_error("Neispravni elementi za izbacivanje!");
        
    stack<pair<string, string>> stek;
    int _b = b;
    
    while (_b > 0 && cvor != nullptr) {
        for (int i = 1; i < r; i++) {
            if (!SmislenaKarta(cvor->karta))
                throw logic_error("Neispravna lista!");
                
            cvor = cvor->sljedeci;
        }
        
        stek.push(pair<string, string>(SVE_BOJE_STR[int(cvor->karta.boja)], cvor->karta.vrijednost));
        
        Cvor* temp = cvor;
        while (cvor->sljedeci != temp)
            cvor = cvor->sljedeci;
            
        cvor->sljedeci = temp->sljedeci;
        cvor = cvor->sljedeci;
        delete temp;
        
        _b--;
    }
    
    return stek;
}

void VratiPosljednjihNKarata(Cvor*& cvor, stack<pair<string, string>>& stek, int n) {
    if (n < 0)
        throw domain_error("Broj n je besmislen!");
    
    if (n > stek.size())
        throw range_error("Nedovoljno karata u steku!");
    
    for (int i = 0; i < n; i++) {
        while (KomparatorKarti(cvor->karta, cvor->sljedeci->karta))
            cvor = cvor->sljedeci;
        cvor = cvor->sljedeci;
        
        Karta karta = KartaIzPara(stek.top());
        stek.pop();
        
        Cvor* prvi = cvor;
        int j = 0;
        while (!(KomparatorKarti(cvor->karta, karta) && KomparatorKarti(karta, cvor->sljedeci->karta))) {
            if (j > 51 || !SmislenaKarta(cvor->karta))
                throw logic_error("Neispravna lista!");
            
            if (cvor->sljedeci == prvi)
                break;
                
            cvor = cvor->sljedeci;
            j++;
        }
        
        Cvor* temp = cvor->sljedeci;
        
        cvor->sljedeci = new Cvor;
        cvor->sljedeci->karta = karta;
        cvor->sljedeci->sljedeci = temp;
    }
}

void UnistiSpil(Cvor*& cvor) {
    while (cvor->sljedeci != cvor) {
        Cvor* temp = cvor->sljedeci;
        cvor->sljedeci = temp->sljedeci;
        delete temp;
    }
    
    cvor->sljedeci = nullptr;
    delete cvor;
}
