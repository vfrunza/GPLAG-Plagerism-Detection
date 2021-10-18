#include <iostream>
#include <vector>
#include <string>
#include <list>
#include <set>
#include <stdexcept>

struct Dijete {
    std::string ime;
    Dijete* sljedeci;
};

int LegalniZnakovi(const std::string &s) {
    
    int broj_znakova(0);
    
    for(int i = 0; i < s.size(); i++) {
        if((toupper(s[i]) >= 'A' && toupper(s[i]) <= 'Z') || (s[i] >= '0' && s[i] <= '9')) broj_znakova++;
    }
    
    return broj_znakova;
}

Dijete* KreirajListu(std::vector<std::string> Djeca) {
    Dijete *pocetak(nullptr), *prethodni; 
    for(int i = 0; i < Djeca.size(); i++) {
        Dijete *novi(new Dijete);
        novi->ime = Djeca[i]; novi->sljedeci = nullptr;
        if(!pocetak) pocetak = novi;
        else prethodni->sljedeci = novi;
        prethodni = novi;
        if(i == Djeca.size() - 1) novi->sljedeci = pocetak;
    }
    return pocetak;
}

std::vector<std::set<std::string>> Razvrstavanje(std::vector<std::string> Djeca, int BrojTimova) {
    
    if(BrojTimova < 1 || BrojTimova > Djeca.size()) throw std::logic_error("Razvrstavanje nemoguce");
    
    Dijete* pocetak(KreirajListu(Djeca));
    std::vector<std::set<std::string>> Timovi(BrojTimova);
    
    std::vector<std::string> Djecica;
    
    auto p(pocetak);
    int BrojKretanja;
    while(p->sljedeci != p) {
        BrojKretanja = LegalniZnakovi(p->ime);
        Djecica.push_back(p->ime);
        auto izbaceni(p);
        p = p->sljedeci;
        auto prije_izbacenog(izbaceni);
        while(prije_izbacenog->sljedeci != izbaceni) prije_izbacenog = prije_izbacenog->sljedeci;
        prije_izbacenog->sljedeci = izbaceni->sljedeci;
        delete izbaceni;
        for(int i = 0; i < BrojKretanja - 1; i++) p = p->sljedeci;
    }
    
    if(p) {
        Djecica.push_back(p->ime);
        delete p;
    }
    
    int VelicinaTimova(Djeca.size() / BrojTimova);
    int VeciTimovi(Djeca.size() % BrojTimova);
    
    auto it1(Djecica.begin());
    
    for(int i = 0; i < Timovi.size(); i++) {
        int brojac(VelicinaTimova);
        while(brojac != 0) {
            Timovi[i].insert(*it1++);
            brojac--;
        }
        if(VeciTimovi != 0) {
            Timovi[i].insert(*it1++);
            VeciTimovi--;
        }
    }
    
    return Timovi;
}


int main() {
    
    std::cout << "Unesite broj djece: ";
    int n;
    std::cin >> n;
    
    std::cin.ignore(10000, '\n');
    
    std::cout << "Unesite imena djece: " << std::endl;
    std::vector<std::string> Djeca(n);
    for(int i = 0; i < Djeca.size(); i++) std::getline(std::cin, Djeca[i]);
    
    std::cout << "Unesite broj timova: ";
    std::cin >> n;
    
    try {
       auto Timovi(Razvrstavanje(Djeca, n));
       for(int i = 0; i < Timovi.size(); i++) {
           std::cout << "Tim " << i + 1 << ": ";
           for(auto x : Timovi[i]) {
               if(x == *Timovi[i].rbegin()) std::cout << x;
               else std::cout << x << ", ";
           }
           std::cout << std::endl;
       }
    } catch(std::logic_error izuzetak) { std::cout << "Izuzetak: " << izuzetak.what(); }
    
    return 0;
}