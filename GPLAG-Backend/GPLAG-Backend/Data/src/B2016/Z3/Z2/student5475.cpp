#include <iostream>
#include <string>
#include <map>
#include <set>
#include <algorithm>
#include <stdexcept>

typedef std::map<std::string, std::set<int>> Mapa;

bool OkZnak(char c) {
    return (c >= 'a' && c <= 'z') || (c >= '0' && c <= '9');
}
std::string Tlwr(std::string s) {
    for(int i=0; i<s.size(); i++)
        s[i] = std::tolower(s[i]);
    return s;
}
Mapa KreirajIndeksPojmova(std::string tekst) {
    Mapa m;
    std::string s(Tlwr(tekst));
    for(int i=0; i<s.size(); i++) {
        std::string pojam;
        int indeks;
        if(OkZnak(s[i])) {
            indeks = i;
            while(i < s.size() && OkZnak(s[i])) {
                pojam.push_back(s[i]);
                i++;
            }
            auto it(m.find(pojam));
            if(it != m.end()) it->second.insert(indeks);
            else m[pojam] = std::set<int> {indeks};
        }
    }
    return m;
}
std::set<int> PretraziIndeksPojmova(std::string pojam, Mapa m) {
    if(!m.count(pojam)) throw std::logic_error("Pojam nije nadjen");
    auto it(m.find(pojam));
    return it->second;
}
void IspisiIndekse(std::set<int> s) {
    for(int x : s) {
        if(x == *s.rbegin()) std::cout << x;
        else std::cout << x << ",";
    }
}
void IspisiIndeksPojmova(Mapa m) {
    if(m.empty()) return;
    for(auto it = m.begin(); it != m.end(); it++) {
        std::cout << it->first << ": ";
        IspisiIndekse(it->second);
        std::cout << std::endl;
    }
}
int main ()
{
    std::string tekst;
    std::cout << "Unesite tekst: ";
    std::getline(std::cin, tekst);
    Mapa m(KreirajIndeksPojmova(tekst));
    IspisiIndeksPojmova(m);
    for(;;) {
        std::string rijec;
        try {
            std::cout << "Unesite rijec: ";
            std::getline(std::cin, rijec);
            if(rijec == ".") break;
            std::set<int> s(PretraziIndeksPojmova(rijec, m));
            for(int x : s) 
                std::cout << x << " ";
            std::cout << std::endl;
        }
        catch(...) {
            std::cout << "Unesena rijec nije nadjena!" << std::endl;
        }
    }
	return 0;
}