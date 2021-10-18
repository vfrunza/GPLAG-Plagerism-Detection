/B2016/2017: Zadaća 3, Zadatak 2
#include <iostream>
#include <stdexcept>
#include <string>
#include <map>
#include <set>

typedef std::map<std::string, std::set<int>> TipMapa;

void PretvoriUMala(std::string &s) {
    for(auto &x : s) {
        if(x >= 'A' && x <='Z') {
            x += 32;
        }
    }
}
TipMapa KreirajIndeksPojmova(std::string s) {
    TipMapa mapa;
    
    int pocetak = 0, duzina = 0, pozicija = 0;
    std::set<std::string> set_kljuc;
    PretvoriUMala(s);
    
    for(int i = 0; i < s.length(); i++) {
        if(!((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= '0' && s[i] <= '9'))) continue;
        duzina = 0;
        pocetak = i;
        
        while(i < s.length() && ((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= '0' && s[i] <= '9'))) {
            duzina++;
            i++;
        }
        set_kljuc.insert(s.substr(pocetak, duzina));
    }
    
    for(auto i = set_kljuc.begin(); i != set_kljuc.end(); i++) {
        std::string temp = *i;
        std::set<int> set_pozicija;
        
        for(int j = 0; j < s.length(); j++) {
            int k = 0;
            if(j != 0) k = j-1;
            
            if(temp[0] == s[j] && (j == 0 || !((s[k] >= 'a' && s[k] <= 'z') || (s[k] >= '0' && s[k] <= '9')))) {
                pozicija = j;
                duzina = 0;
                
                while((s[j] >= 'a' && s[j] <= 'z') || (s[j] >= '0' && s[j] <= '9')) {
                    duzina++;
                    j++;
                }
                if(s.substr(pozicija, duzina) == temp) {
                    set_pozicija.insert(pozicija);
                }
            }
        }
        mapa.insert(std::make_pair(temp, set_pozicija));
    }
    return mapa;
}
std::set<int> PretraziIndeksPojmova(std::string s, TipMapa mapa) {
    for(auto it = mapa.begin(); it != mapa.end(); it++) {
        if(it->first == s) {
            return it->second;
        }
    }
    throw std::logic_error("Unesena rijec nije nadjena!");
}
void IspisiIndeksPojmova(TipMapa mapa) {
    for(auto it1 = mapa.begin(); it1 != mapa.end(); it1++) {
        std::cout << it1->first << ": ";
        auto kraj = (*it1).second.end();
        kraj--;
        for(auto it2 = (*it1).second.begin(); it2 != kraj; it2++) {
            std::cout << *it2 << ",";
        }
        std::cout << *kraj;
        std::cout << std::endl;
    }
}

int main () {
    std::cout << "Unesite tekst: ";
    std::string s;
    std::getline(std::cin, s);
    auto mapa = KreirajIndeksPojmova(s);
    IspisiIndeksPojmova(mapa);
    
    std::string temp;
    
    while(true) {
        std::cout << "Unesite rijec: ";
        std::getline(std::cin, temp);
        if(temp == ".") return 0;
        
        try {
            auto sk = PretraziIndeksPojmova(temp, mapa);
            for(auto x : sk) {
                std::cout << x << " ";
            }
            std::cout << std::endl;
        }
        catch(std::logic_error izuzetak) {
            std::cout << izuzetak.what() << std::endl;
        }
    }
}