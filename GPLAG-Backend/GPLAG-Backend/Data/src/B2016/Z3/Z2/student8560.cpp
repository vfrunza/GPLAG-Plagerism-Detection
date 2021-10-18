#include <iostream>
#include <string>
#include <map>
#include <set>

std::string Little(std::string s) {
    std::string novi = s;
    for(int i = 0; i < novi.length(); i++) {
        if(novi[i] >= 'A' && novi[i] <= 'Z') novi[i] += 32;
    }
    
    return novi;
}

std::map<std::string, std::set<int>> KreirajIndeksPojmova (std::string s) {
    std::map<std::string, std::set<int>> mapa;
    s = Little(s);
    int i(0);
    while(i < s.length()) {
        if(!((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= '0' && s[i] <= '9'))) { i++; continue; }
        if(i >= s.length()) break;
        std::string rijec;
        int brojac(i);
        while(((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= '0' && s[i] <= '9')) && i < s.length()) {
            rijec.push_back(s[i]);
            i++;
        }
        
        auto trazi = mapa.find(rijec);
        if(trazi == mapa.end())  mapa[rijec].insert(brojac); 
        else  (trazi -> second).insert(brojac); 
        i++;
    }
    
    return mapa;
}

std::set<int> PretraziIndeksPojmova(std::string rijec, std::map<std::string, std::set<int>> mapa) {
    std::set<int> vrati;
    std::string pomocni = rijec;
    rijec = Little(pomocni);
    auto ite = mapa.find(rijec);
    if(ite == mapa.end()) throw std::logic_error("Pojam nije nadjen");
    vrati = ite -> second;
    return vrati;
}

void IspisiIndeksPojmova(std::map<std::string, std::set<int>> mapa) {
    auto it = mapa.begin();
    for(int i = 0; i < mapa.size(); i++) {
        std::string rijec = it -> first;
        std::cout << rijec << ": ";
        auto j = (it->second).begin();
        for(j; j != (it -> second).end(); j++) {
            auto pomoc = j;
            if(++pomoc == (it->second).end()) break;
            std::cout << *j << ",";
        }
        std::cout << *j << std::endl;
        it++;
    }
}

int main () {
    std::cout << "Unesite tekst: ";
    std::string s;
    std::getline(std::cin, s);
    std::map<std::string, std::set<int>> mapa;
    mapa = KreirajIndeksPojmova(s);
    IspisiIndeksPojmova(mapa);
    std::set<int> skup;
    while(1) {
        std::cout << "Unesite rijec: ";
        std::string r;
        std::getline(std::cin, r);
        std::string::iterator i = r.begin();
        if(r.length() == 1 && *i == '.') break;
        try {
            skup = PretraziIndeksPojmova(r, mapa);
            for(auto j(skup.begin()); j != skup.end(); j++) {
                std::cout << *j << " ";
            }
        }
        catch(std::logic_error) {
            std::cout << "Unesena rijec nije nadjena!";
        }
        std::cout << std::endl;
    }
    
	return 0;
}