#include <iostream>
#include <string>
#include <map>
#include <set>
#include <stdexcept>

std::string ToMala(std::string s) {
    std::string mala;
    for(int i = 0; i < s.size(); i++) mala.push_back(tolower(s[i]));
    return mala;
}

std::map<std::string, std::set<int>> KreirajIndeksPojmova(std::string s) {
    std::map<std::string, std::set<int>> IndeksPojmova;
    
    for(int i = 0; i < s.size(); i++) {
        if((toupper(s[i]) >= 'A' && toupper(s[i]) <= 'Z') || (s[i] >= '0' && s[i] <= '9')) {
            std::string rijec;
            int pozicija(i);
            while(((toupper(s[i]) >= 'A' && toupper(s[i]) <= 'Z') || (s[i] >= '0' && s[i] <= '9')) && i < s.size()) {
                rijec.push_back(tolower(s[i]));
                i++;
            }
            IndeksPojmova[rijec].insert(pozicija);
        }
    }
    
    return IndeksPojmova;
}

std::set<int> PretraziIndeksPojmova(std::string rijec, std::map<std::string, std::set<int>> a) {
    for(auto it = a.begin(); it != a.end(); it++) {
        if(ToMala(it->first) == ToMala(rijec)) return it->second;
    }
    throw std::logic_error("Unesena rijec nije nadjena!");
}

void IspisiIndeksPojmova(const std::map<std::string, std::set<int>> &IndeksPojmova) {
    for(auto it = IndeksPojmova.begin(); it != IndeksPojmova.end(); it++) {
        std::cout << it->first << ": ";
        for(auto x : it->second) {
            if(x == *((it->second).rbegin())) std::cout << x;
            else std::cout << x << ",";
        }
        std::cout << std::endl;
    }
}

int main() {
    
    std::cout << "Unesite tekst: ";
    std::string s;
    std::getline(std::cin, s);
    
    auto IndeksPojmova(KreirajIndeksPojmova(s));
    IspisiIndeksPojmova(IndeksPojmova);
    
    while(1) {
        std::cout << "Unesite rijec: ";
        std::string rijec;
        std::getline(std::cin, rijec);
        
        if(rijec == ".") break;
        try {
            for(auto x : PretraziIndeksPojmova(rijec, IndeksPojmova)) std::cout << x << " ";
        }
        catch(std::logic_error izuzetak) { std::cout << izuzetak.what(); }
        std::cout << std::endl;
    }
    
    return 0;
}