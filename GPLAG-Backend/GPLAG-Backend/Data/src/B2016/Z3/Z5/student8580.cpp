#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <stdexcept>
#include <iterator>

struct Dijete {
    std::string ime;
    Dijete * sljedeci = nullptr;
};

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
    if(broj_timova < 1 || broj_timova > baza.size()) throw std::domain_error("Razvrstavanje nemoguce");
    try {
        Dijete *prvo = nullptr;
        Dijete *prethodno = nullptr;
        for(int i = 0; i < baza.size(); i++) {
            Dijete *novo = new Dijete;
            novo -> ime = baza[i];
        novo     -> sljedeci = nullptr;
            if(!prvo) prvo = novo;
            else prethodno -> sljedeci = novo;
            prethodno = novo;
        }
        prethodno -> sljedeci = prvo;
        std::vector<int> broj_clanova(broj_timova);
        Clanovi(broj_clanova, baza.size());
    
        std::vector<std::set<std::string>> timovi(broj_timova);
        for(int i = 0; i < broj_timova; i++) {
            int brojac;
                for(int j = 0; j < broj_clanova[i]; j++) {
                    timovi[i].insert(prvo -> ime);
                    brojac = BrojSlovaUImenu(prvo -> ime);
                    if(prvo == prvo -> sljedeci) {
                        delete prvo;
                        prvo = nullptr;
                        break;
                    }
                    prethodno -> sljedeci = prvo -> sljedeci;
                    delete prvo;
                    prvo = prethodno -> sljedeci;
                    
                    for(int k = 0; k < brojac-1; k++) {
                        prvo = prvo -> sljedeci;
                        prethodno = prethodno -> sljedeci;
                    }
                }
        }
    
        return timovi;
    }
    catch(std::bad_alloc) {
        throw;
    }
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
    catch(...) {
        std::cout << "Problemi sa memorijom";
    }
    
	return 0;
}
