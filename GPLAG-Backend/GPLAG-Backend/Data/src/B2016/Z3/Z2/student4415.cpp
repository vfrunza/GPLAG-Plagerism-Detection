/B2016/2017: Zadaća 3, Zadatak 2
#include <iostream>
#include <string>
#include <map>
#include <set>
#include <stdexcept>

bool Test(char s) {
    if ((s >= 'a' and s <= 'z') or (s >= 'A' and s <= 'Z') or (s >= '0' and s <= '9'))
        return true;
    return false;
}
std::string pretvori_u_mala(std::string s)
{
    for (int i = 0; i < s.size(); i++) {
        if (s[i] >= 'A' and s[i] <= 'Z') s[i] += 32;
    }
    return s;
}


std::map<std::string,std::set<int>> KreirajIndeksPojmova(std::string s)
{
    int pocetak(0);
    bool flag(true);
    std::map<std::string,std::set<int>> mapa;
    for (int i = 0; i < s.size(); i++) {
        
        flag = true;
        std::string rijec{};
        while (Test(s[i])) {
            if (flag) {
                pocetak = i;
                flag = false;
            }
            rijec.push_back(s[i]);
            i++;
        }
        rijec = pretvori_u_mala(rijec);
        if(mapa.count(rijec) == 0 and flag == false) {
            mapa.insert(std::pair<std::string,std::set<int>>(rijec,{pocetak}));
            i--;
        } else if (mapa.count(rijec) == 1 and flag == false) {
            auto it(mapa.find(rijec));
            it->second.insert(pocetak);
            i--;
        }
        
    }
    return mapa;
}

std::set<int> PretraziIndeksPojmova (std::string rijec, std::map<std::string,std::set<int>> mapa)
{
    for (auto i = mapa.begin(); i != mapa.end(); i++) {
        if (rijec == i->first) return i -> second;
    }
    throw std::logic_error("Pojam nije nadjen");
}

void IspisiIndeksPojmova (std::map<std::string,std::set<int>> mapa)
{
    for (auto i = mapa.begin(); i != mapa.end(); i++) {
        std::cout << i->first << ": ";
        for (auto j = i->second.begin(); j != i->second.end(); j++) {
            if (*j == *i->second.rbegin()) std::cout << *j;
            else std::cout << *j << ",";
        }
        std::cout   << std::endl;
    }
}

int main ()
{
    
    std::cout << "Unesite tekst: ";
    std::string s;
    std::getline(std::cin,s);
    auto mapa(KreirajIndeksPojmova(s));
    IspisiIndeksPojmova(mapa);
    while (1) {
        std::cout << "Unesite rijec: ";
        std::string rijec;
        std::cin >> rijec;
        if (rijec == ".") break;
        try {
            auto s(PretraziIndeksPojmova(rijec,mapa));
            for (auto i : s) {
                std::cout << i << " ";
            }
            std::cout  << std::endl;
        }
        catch (...) {
            std::cout <<"Unesena rijec nije nadjena!" << std::endl;
        }
        
    }
    
	return 0;
}