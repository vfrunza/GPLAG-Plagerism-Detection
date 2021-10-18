/B2016/2017: Zadaća 3, Zadatak 4
#include <iostream>
#include <vector>
#include <list>
#include <string>
#include <set>

std::vector<std::set<std::string>> Razvrstavanje(std::vector<std::string> imena_djece, int broj_timova) {
    std::list<std::string> lista_imena_djece;
    for(int i = 0; i < imena_djece.size(); ++i) {
        lista_imena_djece.push_back(imena_djece.at(i));
    }
    
    int prvi_timovi = imena_djece.size() % broj_timova;
    int broj_clanova = imena_djece.size() / broj_timova;
    
    std::vector<std::set<std::string>> Timovi;
    Timovi.resize(broj_timova);
    
    
    for(auto i = lista_imena_djece.begin(); i != lista_imena_djece.end(); ++i) {
        
    }
}

int main () {
    
	return 0;
}