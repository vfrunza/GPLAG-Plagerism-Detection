/B2016/2017: Zadaća 3, Zadatak 2
#include <iostream>
#include <set>
#include <map>
#include <utility>

std::map<std::string, std::set<int>> KreirajIndeksPojmova(std::string s) {
    // Pretvaranje u mala slova
    for(int i(0); i < s.length(); i++)
        if(s[i] >= 'A' && s[i] <= 'Z') s[i] += 32;
    
    std::map<std::string, std::set<int>> indeks;
    int i(0);
    do {
        while((s[i] < '0' || (s[i] > '9' && s[i] < 'A') || (s[i] > 'Z' && s[i] < 'a') || s[i] > 'z') && i < s.length()) i++;
        if(i == s.length()) break;
        if((s[i] >= '0' && s[i] <= '9') || (s[i] >= 'A' && s[i] <= 'Z') || (s[i] >= 'a' && s[i] <= 'z')) {
            std::string rijec;
            while(((s[i] >= '0' && s[i] <= '9') || (s[i] >= 'A' && s[i] <= 'Z') || (s[i] >= 'a' && s[i] <= 'z')) && i < s.length()) {
                rijec.push_back(s[i]);
                i++;
            }
            auto it(indeks.find(rijec));
            std::set<int> set;
            set.insert(i - rijec.length());
            if(it == indeks.end()) indeks.insert(std::make_pair(rijec, set));
            else (it->second).insert(i - rijec.size());
        }
        i++;
    } while(i < s.length());
    return indeks;
}

std::set<int> PretraziIndeksPojmova(std::string rijec, std::map<std::string, std::set<int>> mapa) {
    auto it(mapa.find(rijec));
    if(it == mapa.end()) throw std::logic_error("Pojam nije nadjen");
    else return it->second;
}

void IspisiIndeksPojmova(std::map<std::string, std::set<int>> mapa) {
    for(auto x : mapa) {
        std::cout << x.first << ": ";
        int i(x.second.size() - 1);
        for(auto y : x.second) {
            if(i != 0) std::cout << y << ",";
            else std::cout << y;
            i--;
        }
        std::cout << std::endl;
    }
}

int main ()
{
    std::cout << "Unesite tekst: ";
    std::string tekst;
    std::getline(std::cin, tekst);
    std::map<std::string, std::set<int>> mapa(KreirajIndeksPojmova(tekst));
    IspisiIndeksPojmova(mapa);
    std::string rijec;
    for(;;) {
        try {
            std::cout << "Unesite rijec: ";
            std::cin >> rijec;
            if(rijec == ".") break;
            std::set<int> set(PretraziIndeksPojmova(rijec, mapa));
            for(auto x : set) std::cout << x << " ";
            std::cout << std::endl;
        }
        catch(std::logic_error izuzetak) {
            std::cout << "Unesena rijec nije nadjena!" << std::endl;
        }
        
    }
    
	return 0;
}