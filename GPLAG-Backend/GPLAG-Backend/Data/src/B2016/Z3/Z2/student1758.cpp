/B2016/2017: Zadaća 3, Zadatak 2
#include <iostream>
#include <string>
#include <map>
#include <set>
#include <utility>
#include <stdexcept>

void PrebaciUMalaSlova (std::string &rijec) {
    auto it(rijec.begin());
    while(it!=rijec.end()) {
        if(*it>='A' && *it<='Z') {
            *it+=32;
        }
        it++;
    }
}

std::map<std::string, std::set<int>> KreirajIndeksPojmova (std::string recenica) {
    std::map<std::string, std::set<int>> mapa_pojmova;
    for(int i(0); i<recenica.length(); i++) {
        while(!((recenica[i]>='A' && recenica[i]<='Z') || (recenica[i]>='a' && recenica[i]<='z') || (recenica[i]>='0' && recenica[i]<='9')) && i<recenica.length()) i++;
        if(i==recenica.length()) break;
        int j(i);
        std::string pomoc;
        while(((recenica[i]>='A' && recenica[i]<='Z') || (recenica[i]>='a' && recenica[i]<='z') || (recenica[i]>='0' && recenica[i]<='9')) && i<recenica.length()) {
            pomoc.push_back(recenica[i]);
            i++;
        }
        PrebaciUMalaSlova(pomoc);
        auto pronadji_u_mapi(mapa_pojmova.find(pomoc));
        if(pronadji_u_mapi==mapa_pojmova.end()) {
            mapa_pojmova[pomoc].insert(j);
        } else {
            mapa_pojmova[pomoc].insert(j);
        }
    }
    return mapa_pojmova;
}

std::set<int> PretraziIndeksPojmova (std::string rijec, std::map<std::string, std::set<int>> &mapa) {
    std::set<int> skup;
    PrebaciUMalaSlova(rijec);
    auto it(mapa.find(rijec));
    if(it==mapa.end()) throw std::logic_error("Pojam nije nadjen");
    else {
        skup=it->second;
    }
    return skup;
}

void IspisiIndeksPojmova (std::map<std::string, std::set<int>> mapa) {
    for(auto it(mapa.begin()); it!=mapa.end(); it++) {
        std::cout << it->first << ": ";
        int brojac(0);
        for(auto x: it->second) {
            if(brojac==0) std::cout << x;
            else std::cout << "," << x;
            brojac++;
        }
        std::cout << std::endl;
    }
}

int main () {
    std::cout << "Unesite tekst: ";
    std::string recenica;
    std::getline(std::cin, recenica);
    auto mapa(KreirajIndeksPojmova(recenica));
    IspisiIndeksPojmova(mapa);
    std::cout << std::endl;
    for(;;) {
        std::cout << "Unesite rijec: " ; 
        std::string rijec;
        std::getline(std::cin, rijec);
        if(rijec==".") break;
        try {
            auto skup(PretraziIndeksPojmova(rijec, mapa));
            for(auto x:skup) {
                std::cout << x << " ";
            }
            std::cout << std::endl;
        } catch(std::logic_error) {
            std::cout << "Unesena rijec nije nadjena!" << std::endl;
        }
    }
	return 0;
}