#include <iostream>
#include <stdexcept>
#include <cmath>
#include <cstdio>
#include <vector>
#include <deque>
#include <type_traits>
#include <string>
#include <iomanip>
#include <functional>
#include <set>
#include <map>

std::map<std::string, std::set<int>> KreirajIndeksPojmova(std::string s){
    std::map<std::string, std::set<int>> popis;
    for(int i(0); i < s.length(); i++){
        int j = i;
        std::string rijec;
        if((s[i] >= 'A' && s[i] <= 'K') || (s[i] >= 'a' && s[i] <= 'z') || (s[i] >= '0' && s[i] <= '9' && j < s.length())){
            while((s[j] >= 'A' && s[j] <= 'K') || (s[j] >= 'a' && s[j] <= 'z') || (s[j] >= '0' && s[j] <= '9' && j < s.length())) {
                if(s[j] >= 'a' && s[j] <= 'z') rijec.push_back(s[j]);
                else if(s[j] >= 'A' && s[j] <= 'Z') rijec.push_back(s[j] + ('a' - 'A'));
                else rijec.push_back(s[j]);
                j++;
            }
            popis[rijec].insert(i);
            i = j;
        }
            
    }
    return popis;
}

void pretvoriUMala(std::string &s){
    for(auto &c: s){
        if(c >= 'A' && c <= 'Z') c += 'a'-'A';
    }
}

std::set<int> PretraziIndeksPojmova(std::string rijec, std::map<std::string, std::set<int>> index_pojmova){
    pretvoriUMala(rijec);
    if(!index_pojmova.count(rijec)) throw std::logic_error("Unesena rijec nije nadjena!");
    std::set<int> pozicije;
    for(auto x: index_pojmova[rijec]){
        pozicije.insert(x);
    }
    return pozicije;
}

void IspisiIndeksPojmova(std::map<std::string, std::set<int>> index_pojmova){
    for(auto it = index_pojmova.begin(); it != index_pojmova.end(); it++){
        std::cout << it->first << ": ";
        for(auto k = (it->second).begin(); k != (it->second).end(); k++){
            std::cout << *k;
            auto p(k);
            p++;
            if(p != (it->second).end()) std::cout << ",";
        }
        std::cout << std::endl;
    }
}

int main (){
    std::cout << "Unesite tekst: ";
    std::string tekst;
    std::getline(std::cin, tekst);
    auto index_pojmova(KreirajIndeksPojmova(tekst));
    IspisiIndeksPojmova(index_pojmova);
    while(true){
        std::string unos;
        std::cout << "Unesite rijec: ";
        std::getline(std::cin, unos);
        if(unos == ".") break;
        try{
            auto pozicije = PretraziIndeksPojmova(unos, index_pojmova);
            for(int x: pozicije){
                std::cout << x << " ";
            }
        }
        catch(std::logic_error izuzetak){
            std::cout << izuzetak.what();
        }
        std::cout << std::endl;
    }
	return 0;
}







