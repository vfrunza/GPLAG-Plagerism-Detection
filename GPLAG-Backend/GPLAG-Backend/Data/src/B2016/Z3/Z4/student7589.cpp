#include <iostream>
#include <vector>
#include <string>
#include <list>
#include <set>
#include <stdexcept>
#include <iterator>
int BrojSlovaUImenu(std::string s) {
   int i = 0;
   int broj = 0;
   while(i < s.length()) {
       if((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z') || (s[i] >= '0' && s[i] <= '9')) broj++;
       i++;
   }
   
   return broj;
}

void Clanovi(std::vector<int> &clanovi, int broj_djece) {
    int prvih = broj_djece % clanovi.size();
    for(int i = 0; i < prvih; i++) {
        clanovi[i] = broj_djece/clanovi.size() + 1;
    }
    
    for(int i = prvih; i < clanovi.size(); i++) {
        clanovi[i] = broj_djece/clanovi.size();
    }
}

std::vector<std::set<std::string>> Razvrstavanje(std::vector<std::string> baza, int broj_timova) {
    if(broj_timova < 1 || broj_timova > baza.size()) throw std::logic_error("Razvrstavanje nemoguce");
    std::vector<std::set<std::string>> timovi(broj_timova);
    std::list<std::string> lista;
    for(int i = 0; i < baza.size(); i++) {
        lista.push_back(baza[i]);
    }
    
    std::vector<int> broj_clanova(broj_timova);
    Clanovi(broj_clanova, lista.size());
    auto it = lista.begin();
    for(int i = 0; i < broj_timova; i++) {
        if(i < broj_timova - 1) { 
            while(timovi[i].size() < broj_clanova[i]) {
                
                timovi[i].insert(*it);
                int brojac = BrojSlovaUImenu(*it) - 1;
                it = lista.erase(it);
                if(it == lista.end()) it = lista.begin();
                if(std::distance(it, lista.end()) <= brojac) {
                    while(brojac >= std::distance(it, lista.end())) {
                        brojac -= std::distance(it, lista.end());
                        it = lista.begin();
                    }
                   
                }
                std::advance(it,brojac);
                if(it == lista.end()) it = lista.begin();
            }
        }
        else {
            auto it1 = lista.begin();
            for(int j = 0; j < broj_clanova[i]; j++) {
                timovi[i].insert(*it1);
                it1 = lista.erase(it1);
            }
        }
    }
    
    return timovi;
}


int main ()
{
    std::vector<std::string> baza;
    int djeca, br_tim;
    
    std::cout << "Unesite broj djece: ";
    std::cin >> djeca;
    std::cout << "Unesite imena djece: ";
    std::cin.ignore(1000, '\n');
    for(int i = 0; i < djeca; i++) {
        std::string rijec;
        std::getline(std::cin, rijec);
        baza.push_back(rijec);
        
    }
    
    std::cout << std::endl << "Unesite broj timova: ";
    std::cin >> br_tim;
    std::vector<std::set<std::string>> timovi;
    try {
       timovi = Razvrstavanje(baza,br_tim); 
       for(int i = 0; i < br_tim; i++) {
           std::cout << "Tim " << i+1 << ": ";
           int velicina = timovi[i].size();
           auto p = timovi[i].begin();
           for(int j = 0; j < velicina - 1; j++) {
               std::cout << *p << ", ";
               p++;
           }
           std::cout << *p << std::endl;
       }
    }
    catch(std::logic_error e) {
        std::cout << "Izuzetak: " << e.what();
    }
    
	return 0;
}