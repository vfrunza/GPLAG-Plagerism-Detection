/B2016/2017: Zadaća 3, Zadatak 2
#include <iostream>
#include<string>
#include<map>
#include<set>
#include<stdexcept>
#include<utility>
#include<algorithm>

std::map<std::string, std::set<int>> KreirajIndeksPojmova (std::string recenica) {
    std::map<std::string, std::set<int>> m;
    for(int i=0; i<recenica.length(); i++) {
        if((recenica[i]>='a' && recenica[i]<='z') || (recenica[i]>='A' && recenica[i]<='Z') || (recenica[i]>='0' && recenica[i]<='9')) {
            int pom = i;
            std::string rijec;
            while(i<recenica.length() && ((recenica[i]>='a' && recenica[i]<='z') || (recenica[i]>='A' && recenica[i]<='Z') || (recenica[i]>='0' && recenica[i]<='9')))
                rijec.push_back(recenica[i++]);
            std::transform(rijec.begin(), rijec.end(), rijec.begin(), tolower);
            auto it(m.find(rijec));
            if(it == m.end()) m.insert(std::pair<std::string, std::set<int>>(rijec, {pom}));
            else (it->second).insert(pom);
        }
    }
    return m;
}

std::set<int> PretraziIndeksPojmova (std::string rijec, std::map<std::string, std::set<int>> m) {
    std::transform(rijec.begin(), rijec.end(), rijec.begin(), tolower);
    auto it(m.find(rijec));
    if(it == m.end()) throw std::logic_error("Unesena rijec nije nadjena!");
    else return it->second;
}

void IspisiIndeksPojmova (std::map<std::string, std::set<int>> m) {
    for(auto x : m) {
        std::cout << x.first << ": ";
        auto it2 = (x.second).end();
        it2--;
        for(auto it = (x.second).begin(); it != it2; it++)
            std::cout << *it << ",";
        std::cout << *it2 << std::endl;
    }
}

int main () {
    std::string recenica;
    std::cout << "Unesite tekst: ";
    std::getline(std::cin, recenica);
    auto m = KreirajIndeksPojmova(recenica);
    IspisiIndeksPojmova(m);
    for(;;) {
        std::cout << "Unesite rijec: ";
        std::string rijec;
        std::getline(std::cin, rijec);
        if(rijec == ".") break;
        try{
            std::set<int> skup = PretraziIndeksPojmova(rijec,m);
            for(int x : skup) std::cout << x << " ";
            std::cout << std::endl;
        } catch (std::logic_error e) {
            std::cout << e.what() << std::endl;
        }
    }
    return 0;
}
