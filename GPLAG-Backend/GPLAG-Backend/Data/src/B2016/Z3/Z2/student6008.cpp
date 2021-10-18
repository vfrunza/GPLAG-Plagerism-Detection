/B2016/2017: Zadaća 3, Zadatak 2
#include <iostream>
#include <string>
#include <map>
#include <set>
#include <algorithm>
#include <stdexcept>

bool okZnak(char c) {
    return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9');
}

std::string prilagodi(std::string rijec) {
    std::transform(rijec.begin(), rijec.end(), rijec.begin(), tolower);
    return rijec;
}

std::map<std::string, std::set<int>> KreirajIndeksPojmova (std::string tekst) {
    int n(tekst.length()), x;
    std::map<std::string, std::set<int>> pojmovi;
    
    for (int i = 0; i < n; i++) {
        std::string rijec("");
        x = i;
        while (i < n && okZnak(tekst[i])) {
            rijec += tekst[i++];
        }
        if (rijec != "") {
            pojmovi[prilagodi(rijec)].insert(x);
        }
    }
    
    return pojmovi;
}

std::set<int> PretraziIndeksPojmova (std::string rijec, std::map<std::string, std::set<int>> pojmovi) {
    if (pojmovi.find(prilagodi(rijec)) == pojmovi.end()) {
        throw std::logic_error ("Pojam nije nadjen");
    } 
    return pojmovi.at(prilagodi(rijec));
}

void IspisiIndeksPojmova (std::map<std::string, std::set<int>> pojmovi) {
    std::string ispis;
    for (auto x : pojmovi) {
        ispis = x.first + ": ";
        for (auto y : x.second) {
            ispis += std::to_string(y) + ",";
        }
        std::cout << ispis.substr(0, ispis.length()-1) << std::endl;
    }
}

int main () {
    std::string tekst, rijec;
    std::cout << "Unesite tekst: ";
    getline(std::cin, tekst);
    std::map<std::string, std::set<int>> pojmovi(KreirajIndeksPojmova(tekst));
    IspisiIndeksPojmova(pojmovi);
    while (true) {
        std::cout << "Unesite rijec: ";
        std::cin >> rijec;
        if (rijec == ".") {
            break;
        }
        try {
            std::set<int> indeksi(PretraziIndeksPojmova(rijec, pojmovi));
            for (auto x : indeksi) {
                std::cout << x << " ";
            }
            std::cout << std::endl;
        } catch(std::logic_error) {
            std::cout << "Unesena rijec nije nadjena!" << std::endl;
        }
    }
	return 0;
}
