#include <iostream>
#include <set>
#include <map>
#include <string>
#include <stdexcept>

bool UslovZaRijec(char s) {
    return ((s >= 'A' && s <= 'Z') || (s >= 'a' && s <= 'z') || (s >= '0' && s <= '9'));
}

void PrebaciUMala(std::string &s) {
    for(int i = 0; i < s.length(); i++) {
        if(s[i] >= 'A' && s[i] <= 'Z') s[i] += 32;
    }
}

std::map<std::string, std::set<int>> KreirajIndeksPojmova(std::string s) {
    std::map<std::string, std::set<int>> mapa;
    int i = 0;
    while(i < s.length()) {
        //preskace znakove interpunkcije i razmake
        if(!UslovZaRijec(s[i])) {
            while(!UslovZaRijec(s[i]) && i < s.length()) {
                i++;
            }
        }
        
        if(i == s.length()) break;
        std::string rijec;
        int j = i;
        while(j < s.length() && UslovZaRijec(s[j])) {
            rijec.push_back(s[j]);
            j++;
        }
        
        PrebaciUMala(rijec);
        
        mapa[rijec].insert(i);
        i = j - 1;
        i++;
    }
    
    return mapa;
}

void IspisiIndeksPojmova(std::map<std::string, std::set<int>> mapa) {
    auto it = mapa.begin();
    while(it != mapa.end()) {
        std::cout << it -> first << ": ";
        
        auto p = (it->second).begin();
        auto k = (it->second).end();
        while(p != k) {
            auto pomocni = p;
            pomocni++;
            if(pomocni == k) { std::cout << *p; break; }
            std::cout << *p << ",";
            p++;
        }
        std::cout << std::endl;
        it++;
    }
}

std::set<int> PretraziIndeksPojmova(std::string s, std::map<std::string, std::set<int>> mapa) {
    PrebaciUMala(s);
    auto it = mapa.find(s);
    if(it == mapa.end()) throw std::logic_error("Pojam nije nadjen");
    else return it->second;
}


int main ()
{
    std::string recenica;
    std::cout << "Unesite tekst: ";
    std::getline(std::cin, recenica);
    std::map<std::string, std::set<int>> mapa = KreirajIndeksPojmova(recenica);
    IspisiIndeksPojmova(mapa);
    std::string pomocni = ".";
    for(;;) {
        std::cout << "Unesite rijec: ";
        std::string rijec;
        std::getline(std::cin, rijec);
        if(rijec == pomocni) break;
        try {
            std::set<int> skup = PretraziIndeksPojmova(rijec, mapa);
            for(auto x : skup) std::cout << x << " ";
        }
        catch(std::logic_error) {
            std::cout << "Unesena rijec nije nadjena!";
        }
        std::cout << std::endl;
    }
    
	return 0;
}