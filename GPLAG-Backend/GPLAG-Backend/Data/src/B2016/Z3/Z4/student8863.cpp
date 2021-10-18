#include <iostream>
#include <vector>
#include <stdexcept>
#include <set>
#include <list>
#include <string>

using std::cin;
using std::cout;

std::vector<std::set<std::string>> Razvrstavanje(std::vector<std::string> vektor_djece, int broj_timova){
    if(broj_timova < 1 || broj_timova > vektor_djece.size()) throw std::logic_error("Razvrstavanje nemoguce");
    std::list<std::string> lista_djece;
    for(auto ime : vektor_djece) lista_djece.push_back(ime);
    std::vector<std::set<std::string>> konacni_timovi(broj_timova);
    auto it(lista_djece.begin());
    if(vektor_djece.size() % broj_timova == 0){
        int i(0), j(0);
        auto it(lista_djece.begin());
        for(;;){
            int duzina_imena(0);
            if(i == vektor_djece.size() / broj_timova){
                i = 0;
                j++;
            }
            if(lista_djece.size() == 0) return konacni_timovi;
            konacni_timovi[i].insert(*it);
            for(int k = 0; k < (*it).size(); k++)
            if(((*it)[k] >= '0' && (*it)[k] <= '9') || ((*it)[k] >= 'A' && (*it)[k] <= 'Z') || ((*it)[k] >= 'a' && (*it)[k] <= 'z')) duzina_imena++;
            it = lista_djece.erase(it);
            if(std::distance(it, lista_djece.end()) < duzina_imena - 1) it++;
            std::advance(it, duzina_imena - 1);
            i++;    
        }                
    }
    int i(0), j(0);
    auto it(lista_djece.begin());
    for(;;){
        int broj_vise = vektor_djece.size() % broj_timova;
        int duzina_imena(0);
        if(i == vektor_djece.size() / broj_timova){
            i = 0;
            j++;
        }
        if(lista_djece.size() == 0) return konacni_timovi;
        konacni_timovi[i].insert(*it);
        for(int k = 0; k < (*it).size(); k++)
        if(((*it)[k] >= '0' && (*it)[k] <= '9') || ((*it)[k] >= 'A' && (*it)[k] <= 'Z') || ((*it)[k] >= 'a' && (*it)[k] <= 'z')) duzina_imena++;
        it = lista_djece.erase(it);
        if(std::distance(it, lista_djece.end()) < duzina_imena - 1) it++;
        std::advance(it, duzina_imena - 1);
        i++;    
    }
}
int main ()
{
	return 0;
}