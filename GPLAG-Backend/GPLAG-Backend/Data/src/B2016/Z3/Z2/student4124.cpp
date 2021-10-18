#include <iostream>
#include <map>
#include <string>
#include <set>
#include <iterator>
#include <algorithm>
#include <utility>
#include <stdexcept>

std::map<std::string, std::set<int>> KreirajIndeksPojmova(std::string s) {
    std::map<std::string, std::set<int>> mapa;
    for(int i(0); i<s.length(); i++) {
        while(s[i]==' ' or s[i]<'0' or (s[i]>'9' and s[i]<'A') or (s[i]>'Z' and s[i]<'a') or s[i]>'z')
            if(i<s.length()) i++;
            else break;
        if(i==s.length()) break;
        int temp(i), broj(0);
        while(!(s[i]==' ' or s[i]<'0' or (s[i]>'9' and s[i]<'A') or (s[i]>'Z' and s[i]<'a') or s[i]>'z')) {
            if(i==s.length()) break;
            i++, broj++;
        }
        std::string rijec = s.substr(temp, broj);
        for(char &x : rijec) if(x>='A' and x<='Z') x+='a'-'A';
        auto it(mapa.find(rijec));
        if(it == mapa.end()) mapa[rijec]={temp};
        else it->second.insert(temp);
    }
    return mapa;
}

std::set<int> PretraziIndeksPojmova(std::string s, std::map<std::string, std::set<int>> mapa) {
    for(int i(0); i<s.length(); i++) {
        if(s[i]>='A' and s[i]<='Z') s[i]+='a'-'A';
    }
    
    auto it(mapa.find(s));
    if(it==mapa.end()) throw std::logic_error("Pojam nije nadjen");
    else return it->second;
}

void IspisiIndeksPojmova(std::map<std::string, std::set<int>> mapa) {
    for(auto x : mapa) {
        std::cout << x.first << ": ";
        for(auto it(x.second.begin());;it++) {
            if(*it==*(x.second.rbegin())) {
                std::cout << *it;
                break;
            }
            std::cout << *it << ",";
        }
        std::cout << std::endl;
    }
}

int main ()
{
    std::cout << "Unesite tekst: ";
    std::string s;
    std::getline(std::cin, s);
    auto mapa(KreirajIndeksPojmova(s));
    IspisiIndeksPojmova(mapa);
    while(1) {
        std::set<int> skup;
        std::string s2;
        std::cout << "Unesite rijec: ";
        std::getline(std::cin, s2);
        if(s2 == ".") break;
        try {
            skup = PretraziIndeksPojmova(s2, mapa);
            for(auto x : skup) std::cout << x << " ";
            std::cout << std::endl;
        }
        catch(std::logic_error) {
            std::cout << "Unesena rijec nije nadjena!" << std::endl;
        }
    }
	return 0;
}