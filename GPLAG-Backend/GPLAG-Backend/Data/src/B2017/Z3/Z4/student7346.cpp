/B2017/2018: Zadaća 3, Zadatak 4
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <stdexcept>
#include <utility>
#include <iterator>
#include <queue>
#include <map>
#include <list>

using std::cin;
using std::cout;
using std::endl;
using std::vector;
using std::string;

static const vector<string> Karte {"2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K", "A"};
static const vector<string> boje {"Pik", "Tref", "Herc", "Karo"};
enum class Boje {Pik, Tref, Herc, Karo};
typedef std::list<std::pair<Boje, string>> Spil;
typedef std::pair<Boje, string> Karta;
typedef std::multimap<Boje, string> Dio;
typedef std::queue<std::pair<string, string>> Red ;

Spil KreirajSpil() {
    Spil full_spil;
    for (int i(0); i<4; i++) {
        for (int j(0); j<Karte.size(); j++) {
            full_spil.push_back(std::make_pair(static_cast<Boje>(i), Karte.at(j)));
        }
    }
    return full_spil;
}

bool IspravnostSpila (const Spil &nekispil) {
    bool IspravnostSortiranja (const Spil &nekispil);
    if(!IspravnostSortiranja(nekispil)) return false;
    for(auto klizeci(nekispil.begin()); klizeci!=nekispil.end(); klizeci++) 
        if((std::count(nekispil.begin(), nekispil.end(), *klizeci)>=2) || !(std::count(Karte.begin(), Karte.end(), klizeci->second))) return false;
    if (nekispil.size()>52) return false;
    
    return true;
}

bool IspravnostSortiranja (const Spil &nekispil) {
    auto prvi(nekispil.begin());
    auto drugi(nekispil.begin());
    drugi++;
    while(drugi!=nekispil.end()) {
        if((prvi->first == drugi->first && std::find(Karte.begin(), Karte.end(), prvi->second)>(std::find(Karte.begin(), Karte.end(), drugi->second))) || prvi->first>drugi->first) return false;
        prvi++;
        drugi++;
    }
    return true;
}

void IzbaciKarte (Spil &nekispil, Dio &kolekcija) {
    if(!IspravnostSpila(nekispil)) throw std::logic_error("Neispravna lista!");
    auto collit(kolekcija.begin());
    while(collit != kolekcija.end()) {
        bool treba_pomjeriti = true;
        if(std::find(nekispil.begin(), nekispil.end(), std::make_pair(collit->first, collit->second))!=nekispil.end()) {
            treba_pomjeriti = false;
            nekispil.erase(std::find(nekispil.begin(), nekispil.end(), std::make_pair(collit->first, collit->second)));
            collit = kolekcija.erase(collit);
        } 
        if(treba_pomjeriti) collit++;
    }
}

Red IzbaciKarteRazbrajanjem (Spil &nekispil, const short int &r, const int &b) {
    if (r>52 || r<1 || b<1) throw std::logic_error("Neispravni elementi za izbacivanje!");
    if (!IspravnostSpila(nekispil)) throw std::logic_error("Neispravna lista!");
    Red red;
    auto Klizac(nekispil.begin());
    for (int i(0); i<b; i++) {
        for (int j(1); j<r; j++) {
            if(Klizac==nekispil.end()) { 
                Klizac = nekispil.begin(); Klizac++;
            }
            else
                Klizac++;
        }
        if(nekispil.size()==0) break;
        red.push(std::make_pair(boje[static_cast<int>(Klizac->first)], Klizac->second));
        Klizac = nekispil.erase(Klizac);
    }
    return red;
}

void VratiJednuKartu (Spil &nekispil, Karta cti) {
    auto Klizac(nekispil.begin());
    while (Klizac!=nekispil.end() && ((static_cast<int>(cti.first))!=(static_cast<int>(Klizac->first))))
        Klizac++;
    while (Klizac!=nekispil.end() && (static_cast<int>(cti.first) == static_cast<int>(Klizac->first)) && (std::find(Karte.begin(), Karte.end(), cti.second) > std::find(Karte.begin(), Karte.end(), Klizac->second)))
        Klizac++;
    nekispil.insert(Klizac, cti);
}

bool ProvjeriIspravnostReda(const std::pair<string, string> &karta) {
    if (std::find(Karte.begin(), Karte.end(), karta.second) == Karte.end() || std::find(boje.begin(), boje.end(), karta.first) == boje.end())
        throw std::logic_error("Neispravne karte!");
    return true;
}

void IspisSpila (const Spil &nekispil) {
    auto Klizeci(nekispil.begin());
    cout << endl << "Pik: ";
    while(Klizeci->first == Boje::Pik && Klizeci!=nekispil.end()) {
        cout << Klizeci->second << " ";
        Klizeci++;
    }
    cout << endl << "Tref: ";
    while(Klizeci->first == Boje::Tref && Klizeci!=nekispil.end()) {
        cout << Klizeci->second << " ";
        Klizeci++;
    }
    cout << endl << "Herc: ";
    while(Klizeci->first == Boje::Herc && Klizeci!=nekispil.end()) {
        cout << Klizeci->second << " ";
        Klizeci++;
    }
    cout << endl << "Karo: ";
    while(Klizeci->first == Boje::Karo && Klizeci!=nekispil.end()) {
        cout << Klizeci->second << " ";
        Klizeci++;
    }
}

void VratiPrvihNKarata(Spil &nekispil, Red &za_vratiti, int n) {
    if(n<0) throw std::domain_error ("Broj n je besmislen!");
    if(n>za_vratiti.size()) throw std::range_error ("Nedovoljno karata u redu!");
    if(!IspravnostSpila(nekispil)) throw std::range_error("Neispravna lista!");
    
    for(int i(0); i<n; i++) {
        if(za_vratiti.size()==0) break;
        ProvjeriIspravnostReda(za_vratiti.front());
        Karta cti = std::make_pair(static_cast<Boje>(std::find(boje.begin(), boje.end(), za_vratiti.front().first)-boje.begin()), za_vratiti.front().second);
        if(std::find(nekispil.begin(), nekispil.end(), cti)!=nekispil.end()) { 
            continue;
        }
        VratiJednuKartu(nekispil, cti);
        za_vratiti.pop();
    }
}


int main ()
{
    cout << "Unesite korak razbrajanja: ";
    short int k;
    cin >> k;
    cout << "Unesite broj karata koje zelite izbaciti: ";
    int n;
    cin >> n;
    Spil full_spil = KreirajSpil();
    try
    {
        Red vratiti = IzbaciKarteRazbrajanjem(full_spil, k, n);
        cout << "U spilu trenutno ima " << full_spil.size() << " karata, i to: " ;
        IspisSpila(full_spil);
        cout << endl << "Unesite broj karata koje zelite vratiti u spil: ";
        int bkv;
        cin >> bkv;
        VratiPrvihNKarata(full_spil, vratiti, bkv);
        cout << "U spilu trenutno ima " << full_spil.size() << " karata, i to: " ;
        IspisSpila(full_spil);
    }
    catch(std::exception &poruka) {
        cout << "Izuzetak: " << poruka.what();
    }
	return 0;
}
