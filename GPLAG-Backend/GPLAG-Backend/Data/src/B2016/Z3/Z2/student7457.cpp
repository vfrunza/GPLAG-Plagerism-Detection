/B2016/2017: Zadaća 3, Zadatak 2
#include <iostream>
#include <string>
#include <map>
#include <set>

std::map<std::string, std::set<int>> KreirajIndeksPojmova (std::string rijeci);
std::set<int> PretraziIndeksPojmova (std::string rijeci, std::map<std::string, std::set<int>> indexPojmova);
void IspisiIndeksPojmova (std::map<std::string, std::set<int>> indexPojmova);

int main () {
    std::string rijeci;
    std::cout << "Unesite tekst: ";
    // IspisiIndeksPojmova(indexPojmova);
    for(;;) {
        try {
            std::string trazenaRijec;
            std::cout << "Unesite rijec: ";
            std::cin >> trazenaRijec;
            if(trazenaRijec == ".") break;
            //ispis gdje nadjena rijec
        } catch(...) {
            std::cout << "Unesena rijec nije nadjena!";
        }
    }
    return 0;
}

void IspisiIndeksPojmova (std::map<std::string, std::set<int>> indexPojmova) {
    for(auto x : indexPojmova) {
        std::cout << x.first << ": ";
        for(auto y = x.second.begin(); y != x.second.end(); y++) {
            std::cout << *y;
            if(y+1 != x.second.end())
                std::cout << ",";
        }
        std::cout << "\n";
    }
}