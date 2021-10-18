/B2016/2017: Zadaća 3, Zadatak 4
#include <iostream>
#include <string>
#include <vector>
#include <stdexcept>
#include <list>
#include <algorithm>
#include <set>

std::vector<std::set<std::string>> Razvrstavanje(std::vector<std::string> v, int n) {
    
    if(n<1 || n>v.size()) throw std::logic_error("Razvrstavanje nemoguce");
    
    std::list<std::string> lista;
    std::vector<std::set<std::string>> rezultat;
    
    for(int i(0); i<v.size(); i++) {
        lista.push_back(v[i]);
    }
    
    int broj_timova(n);
    auto it(lista.begin());
    while(!lista.empty()) {
        if(it==lista.end()) 
        it=lista.begin();
        
    if(broj_timova==n) {
        rezultat.at(broj_timova).insert(*it);
        it=lista.erase(it);
        broj_timova=0;
    }
    else 
        it++;
        broj_timova++;
    }
    return rezultat;
}

int main ()
{
    try {
        int n;
        std::cout << "Unesite broj djece: ";
        std::cin >> n;
        std::cout << "Unesite imena djece: " << std::endl;
        std::string ime;
        for(int i(0); i<n; i++) {
            std::cin >> ime;
        }
        int m;
        std::cout << "Unesite broj timova: ";
        std::cin >> m;
    }
    
    
    catch(std::logic_error e) {
        std::cout << e.what() << std::endl;
    }
	return 0;
}