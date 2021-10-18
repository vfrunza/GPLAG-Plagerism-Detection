/B2016/2017: Zadaća 3, Zadatak 2
#include <iostream>
#include <map>
#include <string>
#include <algorithm>
#include <stdexcept>
#include <set>
#include <utility>

std::map<std::string, std::set<int>> KreirajIndeksPojmova (std::string s) //pridruzena vrijednost su skupovi cijelih brojeva
{
    std::string novi;
    std::map<std::string, std::set<int>> ip;
    std::set<int> prvi{};
    
    for (int i=0; i<s.length(); i++) {
        std::string temp = std::string();
        while (s[i]==' ' && i!=s.length()) {
            i++;
        }
        int pom = i;
        while (s[i]!=' ' && i!=s.length()) {
            temp = temp + s[i];
            i++;
        }
        if (!ip.count(temp)) ip.insert(make_pair(temp,prvi));
        ip[temp].insert(pom);
    }
    return ip;
}

std::set<int> PretraziIndeksPojmova (std::string s, std::map<std::string, std::set<int>> m) //vraca skup pozicija
{
    if (!m.count(s)) throw std::logic_error ("Unesena rijec nije nadjena!");
    
    return m[s];
}

void IspisiIndeksPojmova (std::map<std::string, std::set<int>> m) //prima mapu koja predstavlja indeks pojmova
{
    for (auto k : m) {
        std::cout << k.first << ": ";
        int br{0};
        int vel = distance(k.second.begin(), k.second.end());
        for (auto l : k.second) {
            br++;
            if (br == vel) std::cout << l;
            else std::cout << l << ",";
            
        }
        std::cout << std::endl;
    }
}

int main() 
{
    std::string tekst;
    std::cout << "Unesite tekst: ";
    std::getline (std::cin, tekst);
    IspisiIndeksPojmova(KreirajIndeksPojmova(tekst));
    
    while (1) {
        std::string rijec;
        std::cout << "Unesite rijec: ";
        try {
            std::getline(std::cin, rijec);
            if (rijec == ".") break;
            
            std::set<int> skup = PretraziIndeksPojmova(rijec, KreirajIndeksPojmova(tekst));
            
            for (auto x : skup) {
                std::cout << x << " ";
            }
            std::cout << std::endl;
        }
        catch(std::logic_error izuzetak) {
            std::cout << izuzetak.what() << std::endl;
        }
    }
    return 0;
}