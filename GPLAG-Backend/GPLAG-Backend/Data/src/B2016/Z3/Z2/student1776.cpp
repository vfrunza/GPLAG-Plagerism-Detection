/B2016/2017: Zadaća 3, Zadatak 2
#include <iostream>
#include <map>
#include <set>
#include <string>
#include <algorithm>

bool RijecBrojProvjera (char s) {
    if ((s >= 'A' && s <= 'Z') || (s >= 'a' && s <= 'z') || (s >= '0' && s <= '9')) return true;
    return false;
}

std::map<std::string, std::set<int>> KreirajIndeksPojmova(std::string s) {
    std::map<std::string, std::set<int>> mapa;
    std::transform(s.begin(), s.end(), s.begin(), ::tolower);
    std::set<int> indexi;
    for (int i = 0; i < s.length(); i++) {
        if (RijecBrojProvjera(s[i])) {
            int j(i);
            while(RijecBrojProvjera(s[j])) {
                j++;
            }
            std::string s2 = s.substr(i, j-i);
            auto it(mapa.find(s2));
            if (it != mapa.end()) {
                i += s2.length();
                continue;
            }
            index = i;
            indexi.insert(i);
            for (int k = j; k < s.length(); k++) {
                if (s.substr(k, s2.length()) == s2 && !RijecBrojProvjera(s[k-1]) && !RijecBrojProvjera(s[k+s2.length()]))
                    indexi.insert(k);
            }
            mapa[s2] = indexi;
            indexi.erase(indexi.begin(),indexi.end());
            i += s2.length();
        }
    }
    return mapa;
}

std::set<int> PretraziIndeksPojmova (std::string s, std::map<std::string, std::set<int>> mapa) {
    std::set<int> skup;
    auto it = mapa.begin();
    for (it = mapa.begin(); it != mapa.end(); it++) {
        if ((*it).first == s) {
            skup = it->second;
            break;
        }
    }
    if (it == mapa.end()) throw std::logic_error ("Unesena rijec nije nadjena!");
    return skup;
}

void IspisiIndeksPojmova (std::map<std::string, std::set<int>> mapa) {
    for (auto it = mapa.begin(); it != mapa.end(); it++) {
        std::cout << it->first << ": ";
        auto set_it = it->second.begin();
        for (int i = 0; i < it->second.size()-1; i++) {
            std::cout << *set_it << ",";
            set_it++;
        }
        std::cout << *set_it;
        std::cout << std::endl;
    }   
}

int main ()
{
    std::cout << "Unesite tekst: ";
    std::string s;
    std::getline(std::cin, s);
    std::map<std::string, std::set<int>> mapa(KreirajIndeksPojmova(s));
    IspisiIndeksPojmova(mapa);
    std::string s2;
    for (;;) {
        std::cout << "Unesite rijec: ";
        std::getline(std::cin, s2);
        if (s2 == ".")
            break;
        try {
            std::set<int> skup = PretraziIndeksPojmova(s2, mapa);
            for (auto x : skup)
                std::cout << x << " ";
            
        }
        catch(std::logic_error e) {
            std::cout << e.what();
        }
        std::cout << std::endl;
    }
	return 0;
}