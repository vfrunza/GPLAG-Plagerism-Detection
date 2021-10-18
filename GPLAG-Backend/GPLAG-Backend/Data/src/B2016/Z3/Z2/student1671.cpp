/B2016/2017: Zadaća 3, Zadatak 2
#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <set>
#include <cctype>
#include <stdexcept>

bool ValidanZnak(char c) {
    if ((std::tolower(c) >= 'a' && std::tolower(c) <= 'z') || (c >= '0' && c <= '9')) return true;
    return false;
}
typedef std::map<std::string, std::set<int>> Mapa;
Mapa KreirajIndeksPojmova(std::string s) {
    Mapa mapa;
    for (int i = 0; i < s.length(); i++) {
        int pozicija;
        if (ValidanZnak(s[i])) {
            std::string temp;
            pozicija = i;
            while (i < s.length() && ValidanZnak(s[i])) temp.push_back(tolower(s[i++]));
            if (!mapa.count(temp)) {
                std::set<int> skup{pozicija};
                mapa[temp] = skup;
            }
            else {
                mapa[temp].insert(pozicija);
            }
        }
    }
    return mapa;
}
std::set<int> PretraziIndeksPojmova(std::string s, Mapa mapa) {
    std::set<int> skup;
    if (!mapa.count(s)) throw std::logic_error ("Pojam nije nadjen");
    return mapa[s];
}

#include <iterator>
void IspisiIndeksPojmova(Mapa mapa) {
    for (auto it(mapa.begin()); it != mapa.end(); it++) {
        std::cout << it->first << ": ";
        auto velicina(it->second.size());
        int brojac(0);
        for (auto it2(it->second.begin()); it2 != it->second.end(); it2++) {
            if (brojac++ == velicina-1) std::cout << *it2 << std::endl;
            else std::cout << *it2 << ",";
        }
    }
}

int main ()
{
    try {
        std::string s;
        std::cout << "Unesite tekst: ";
        std::getline(std::cin, s);
        auto mapa(KreirajIndeksPojmova(s));
        IspisiIndeksPojmova(mapa);
        while (true) {
            std::cout << "Unesite rijec: ";
            std::string s;
            std::getline(std::cin, s);
            if (s == ".") break;
            if (!mapa.count(s)) std::cout << "Unesena rijec nije nadjena!" << std::endl;
            else {
                auto skup(PretraziIndeksPojmova(s, mapa));
                for (auto x : skup) std::cout << x << " ";
                std::cout << std::endl;
            }
        }
    }
    catch (std::logic_error tekst) {
        std::cout << tekst.what() << std::endl;
    }
	return 0;
}