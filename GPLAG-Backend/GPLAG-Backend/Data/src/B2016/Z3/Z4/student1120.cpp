/B2016/2017: Zadaća 3, Zadatak 4
#include <iostream>
#include <set>
#include <string>
#include <stdexcept>
#include <vector>
#include <list>

std::vector<std::set<std::string>> Razvrstavanje(std::vector<std::string> djeca, int br_timova) {
    std::list<std::string> lista;
    
    for (auto ime : djeca) {
        lista.push_back(ime);
    }

    std::vector<std::set<std::string>> timovi;
    
    int duzina_imena(1), br(djeca.size() % br_timova);
    auto it = lista.begin();
    
    while (timovi.size() < br_timova) {
        if (it == lista.end()) {
            it = lista.begin();
        }

        int br_clanova = (djeca.size() / br_timova);

        if (timovi.size() < br) {
            br_clanova++;
        }
        
        int trenutno(1);
        std::set<std::string> tim;

        while (tim.size() != br_clanova) {
            if (trenutno == duzina_imena) {
                duzina_imena = it->length();
                trenutno = 1;
                tim.insert(*it);
                it = lista.erase(it);
            } else {
                trenutno++;
                it++;
            }
            
            if (it == lista.end()) {
                it = lista.begin();
            }
        }
        
        timovi.push_back(tim);
    }
    
    return timovi;
}

int main()
{
    std::vector<std::string> djeca();
    auto timovi(Razvrstavanje(djeca, 3));
    
    std::cout<<"Unesite broj djece: "<<"Unesite imena djece: "<<std::endl;
    std::cout<<"Unesite broj timova: ";
    
    
    
    for (int i = 0; i < timovi.size(); i++) {
        std::cout << "Tim " << i + 1 << ": ";
        
        int j(0);
        for (auto ime : timovi[i]) {
            std::cout << ime;
            
            if (j++ < timovi[i].size() - 1) {
                std::cout << ", ";
            }
        }
        
        std::cout << "\n";
    }
	return 0;
}