#include <iostream>
#include <vector>
#include <string>
#include <list>
#include <set>
#include <stdexcept>

int LegalniZnakovi(const std::string &s) {
    
    int broj_znakova(0);
    
    for(int i = 0; i < s.size(); i++) {
        if((toupper(s[i]) >= 'A' && toupper(s[i]) <= 'Z') || (s[i] >= '0' && s[i] <= '9')) broj_znakova++;
    }
    
    return broj_znakova;
}

std::vector<std::set<std::string>> Razvrstavanje(std::vector<std::string> Djeca, int BrojTimova) {
    
    if(BrojTimova < 1 || BrojTimova > Djeca.size()) throw std::logic_error("Razvrstavanje nemoguce");
    
    std::list<std::string> ImenaDjece(Djeca.begin(), Djeca.end());
    std::vector<std::set<std::string>> Timovi(BrojTimova);
    
    std::vector<std::string> Djecica;
    
    auto it = ImenaDjece.begin();
    int BrojKretanja;
    while(!ImenaDjece.empty()) {
        BrojKretanja = LegalniZnakovi(*it) - 1;
        Djecica.push_back(*it);
        it = ImenaDjece.erase(it);
        if(it == ImenaDjece.end()) it = ImenaDjece.begin();
        for(int i = 0; i < BrojKretanja; i++) {
            it++;
            if(it == ImenaDjece.end()) it = ImenaDjece.begin();
        }
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