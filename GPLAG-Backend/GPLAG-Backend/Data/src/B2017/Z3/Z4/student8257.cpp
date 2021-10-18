/B2017/2018: Zadaća 3, Zadatak 4
#include <iostream>
#include <list>
#include <utility>
#include <vector>
#include <string>
#include <map>
#include <algorithm>
#include <stdexcept>
#include <queue>
#include <iterator>

using std::list;
using std::pair;
using std::vector;
using std::string;
using std::multimap;
using std::queue;

enum class Boje {Pik, Tref , Herc , Karo};

typedef list<pair<Boje,string>> Spil;

vector<string> nazivi {"Pik","Tref","Herc","Karo"};
vector<string> v {"2","3","4","5","6","7","8","9","10","J","Q","K","A"};

void IspisiKarte(const Spil &spil);

Spil KreirajSpil() {
    Spil karte;
    for(int i=0;i<nazivi.size();i++) {
        for(string s : v) {
            karte.push_back({Boje(i),s});
        }
    }
    return karte;
}

void IspravnostSpila(const Spil &spil) {
    if(spil.size()>52) throw std::logic_error("Neispravna lista!"); 
    for(auto it=spil.begin();it!=spil.end();it++) {
        auto it2 = it;
        it2++;
        if(it2==spil.end()) break;
        // Ako su podaci liste besmisleni (Program ce dozvoliti samo da vrijednost karte bude besmislena)
        if(std::count(v.begin(),v.end(),it->second)==0)
            throw std::logic_error("Neispravna lista!");
        // Ako nisu sortirani pravilno
        if(int(it->first) > int(it2->first) || (std::find(v.begin(),v.end(),it->second) > std::find(v.begin(),v.end(),it2->second) && int(it->first)==int(it2->first))) 
            throw std::logic_error("Neispravna lista!");
    }
        
}

void IzbaciKarte(Spil &spil, multimap<Boje,string> &m) {
    IspravnostSpila(spil);
    auto it1 = spil.begin();
    while(it1!=spil.end()) {
        bool postoji=false;
        auto it2=m.begin(); // Za svaku kartu iz spila , provjeri da li postoji u mapi
        while(it2!=m.end()) { 
            if(it2->first == it1->first && it2->second == it1->second) { // Ako postoji...
                it2 = m.erase(it2);     // Prvo je izbrisi u multimapi
                postoji = true;
            }
            else
                it2++;
        }
        if(postoji) it1 = spil.erase(it1);  // ..pa onda u spilu
        else it1++;
    }
}

queue<pair<string,string>> IzbaciKarteRazbrajanjem(Spil &spil, const short &r , const int &b) {
    if(r<1 || r>52 || b<1) throw std::logic_error("Neispravni elementi za izbacivanje!");
    IspravnostSpila(spil);
    queue<pair<string,string>> redKarata;
    
    // KRUZNO IZBACIVANJE KARATA 
    auto it=spil.begin();
    int brojac=0;
    while(brojac<b) {
        int korak=1;
        if(spil.size()==0) break; // Ako se isprazni spil
        while(korak<r) {           // r-1 zbog it = spil.erase(it);
            it++;
            if(it==spil.end())      // Ako dodje na kraj spila , vrati se na pocetak
                it=spil.begin();
            korak++;
        }
        redKarata.push({ nazivi.at(int(it->first)) , it->second});
        it=spil.erase(it);
        brojac++;
    }
    return redKarata;
}

void VratiPrvihNKarata(Spil &spil, queue<pair<string,string>> &red, int n) {
    /*Provjera ispravnosti spila i reda*/
    if(n<0) throw std::domain_error("Broj n je besmislen!");
    if(n>red.size()) throw std::range_error("Nedovoljno karata u redu!");
    for(int i=0;i<red.size();i++) {
        pair<string,string> par = red.front();
        if(std::count(nazivi.begin(),nazivi.end(),par.first)==0 || std::count(v.begin(),v.end(),par.second)==0)
            throw std::logic_error("Neispravne karte!");
        red.pop();
        red.push(par);
    }
    IspravnostSpila(spil);
    /**/
    
    // VRACANJE "n" KARATA IZ REDA u spil
    int brojac=0;
    auto it=spil.begin();
    for(int i=0;i<red.size();i++) {
        pair<string,string> par = red.front(); 
        
        int indeks = std::find(nazivi.begin(),nazivi.end(),par.first)-nazivi.begin();
        
        pair<Boje,string> karta = {Boje(indeks),par.second};                             //TRENUTNA KARTA KOJU ISPITUJEM
        if(std::count(spil.begin(),spil.end(),karta)==0 && brojac<n) {             // Ako karta iz reda ne postoji u spilu , vrati je u spil.
            it=spil.begin();
            // TRAZENJE PRAVOG MJESTA ZA UMETANJE KARTE
            while(it!=spil.end() && int(it->first) < indeks) it++;
            while(it!=spil.end() && (std::find(v.begin(),v.end(),par.second) > std::find(v.begin(),v.end(),it->second) && int(it->first)==indeks)) it++;
            spil.insert(it,karta);
            brojac++;
        }
        red.pop();
        red.push(par);
    }
}
void IspisiKarte(const Spil &spil) {
    auto it = spil.begin();
    int indeksNaziva = 0;
    while(indeksNaziva<nazivi.size()) {
        std::cout<<nazivi.at(indeksNaziva)<<": ";
        while(it!=spil.end() && nazivi.at(int(it->first)) == nazivi.at(indeksNaziva)) {
            std::cout<<it->second<<" ";
            it++;
        }
        indeksNaziva++;
        std::cout<<std::endl;
    }
}

int main ()
{
    try {
        //Spil spil = {{Boje::Pik,"2"},{Boje::Herc,"3"},{Boje::Karo,"K"}};
        Spil spil = KreirajSpil();
        std::cout<<"Unesite korak razbrajanja: ";
        short int r;
        std::cin>>r;
        std::cout<<"Unesite broj karata koje zelite izbaciti: ";
        int b;
        std::cin>>b;
        auto izbaceneKarte = IzbaciKarteRazbrajanjem(spil,r,b);
        std::cout<<"U spilu trenutno ima "<<spil.size()<<" karata, i to:\n";
        IspisiKarte(spil);
        std::cout<<"Unesite broj karata koje zelite vratiti u spil: ";
        int n;
        std::cin>>n;
        VratiPrvihNKarata(spil,izbaceneKarte,n);
        std::cout<<"U spilu trenutno ima "<<spil.size()<<" karata, i to:\n";
        IspisiKarte(spil);
        return 0;
    }
    catch(std::logic_error e1) {
        std::cout<<"Izuzetak: "<<e1.what();
    }
    catch(std::range_error e2) {
        std::cout<<"Izuzetak: "<<e2.what();
    }
}
