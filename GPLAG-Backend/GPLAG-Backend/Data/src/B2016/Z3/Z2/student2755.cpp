/B2016/2017: Zadaća 3, Zadatak 2
#include <iostream>
#include <map>
#include <string>
#include <set>
#include <iterator>
#include <stdexcept>

bool Ponavljanje(std::map<std::string, std::set<int>> mapa, std::string s) {
    auto it(mapa.find(s));
    if(it==mapa.end()) return false;
    return true;
}


std::map<std::string, std::set<int>> KreirajIndeksPojmova(std::string s){
    std::map<std::string, std::set<int>> mapa;
    std::string pom;
    int brojac(0), pozicija(0);
    for(int i(0); i<s.length(); i++) {
        if(s[i]!=' ') {
            brojac++;
            int j(i);
            while(s[j]!=' ' && j<s.length()) j++;
            if(brojac>0) {
                pozicija+=i;
                pom=s.substr(i, j-i);
                if(!Ponavljanje(mapa, pom)){
                    std::set<int> skup;
                    skup.insert(pozicija);
                    mapa.insert(std::make_pair(pom, skup));
                }
                else{
                    auto it(mapa.find(pom));
                    it->second.insert(pozicija);
                }
                i=j;
                pozicija=0;
            }
        }
    }
    return mapa;
}

std::set<int> PretraziIndeksPojmova(std::string s, std::map<std::string, std::set<int>> mapa) {
    auto it(mapa.find(s));
    if(it==mapa.end()) throw std::logic_error("Unesena rijec nije nadjena!");
    return it->second;
}

void IspisiSkup(std::set<int> skup) {
    for(auto it(skup.begin()); it!=skup.end(); it++) {
        auto test(it);
        test++;
        if(test==skup.end()) std::cout << *it;
        else std::cout << *it << ",";
    }
}

void IspisiIndeksPojmova(std::map<std::string, std::set<int>> mapa) {
    for(auto it(mapa.begin()); it!=mapa.end(); it++) {
        std::cout << it->first << ": ";
        IspisiSkup(it->second);
        std::cout << std::endl;
    }
}

int main (){
    std::map<std::string, std::set<int>> mapa;
    std::string tekst;
    std::cout << "Unesite tekst: ";
    std::getline(std::cin, tekst);
    mapa=KreirajIndeksPojmova(tekst);
    IspisiIndeksPojmova(mapa);
    
    while(1) {
        std::string rijec;
        std::cout << "Unesite rijec: ";
        std::getline(std::cin, rijec);
        if(rijec==".") return 0;
        else {
            try{
                for(auto x : PretraziIndeksPojmova(rijec, mapa)) std::cout << x << " ";
                std::cout << std::endl;
            }
            catch(std::logic_error e) {
                std::cout << e.what() << std::endl;
            }
        }
    }
	return 0;
}