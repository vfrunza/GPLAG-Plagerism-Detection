/B2016/2017: Zadaća 3, Zadatak 2
#include <iostream>
#include <string>
#include <stdexcept>
#include <map>
#include <set>

std::map<std::string, std::set<int>> KreirajIndeksPojmova(std::string s) {
    std::map<std::string, std::set<int>> m;
    for(int i=0; i<s.length(); i++) {
        if(s[i]>='A' && s[i]<='Z') s[i]+=32;
    }
    for(int i=0; i<s.length(); i++) {
        while((s[i]<'0' || (s[i]>'9' && s[i]<'a') || s[i]>'z') && i<s.length()) i++;
        int j(i);
        while(((s[j]>='0' && s[j]<='9') || (s[j]>='a' && s[j]<='z')) && j<s.length()) j++;
        std::string pomocni(s.substr(i, j-i));
        std::set<int> skup;
        skup.insert(i);
        if(!m.count(pomocni)) m.insert(std::make_pair(pomocni, skup));
        else {
            m[pomocni].insert(i);
        }
        i=j;
    }
    return m;
}

std::set<int> PretraziIndeksPojmova(std::string s, std::map<std::string, std::set<int>> m) {
    if(m.count(s)) return m[s];
    else throw std::logic_error("Pojam nije nadjen");
}

void IspisiIndeksPojmova(const std::map<std::string, std::set<int>> &m) {
    for(auto &i : m) {
        std::cout << i.first << ": ";
        for(auto it=i.second.begin(); it!=i.second.end(); it++) {
            if(it!=i.second.begin()) std::cout << ",";
            std::cout << *it;
        }
        std::cout << std::endl;
    }
}

int main ()
{
    std::cout << "Unesite tekst: ";
    std::string s;
    std::getline(std::cin, s);
    std::map<std::string, std::set<int>> m(KreirajIndeksPojmova(s));
    IspisiIndeksPojmova(m);
    for(;;) {
        std::cout << "Unesite rijec: ";
        std::string rijec;
        std::getline(std::cin, rijec);
        if(rijec==".") break;
        try {
            std::set<int> s(PretraziIndeksPojmova(rijec, m));
            for(auto it=m[rijec].begin(); it!=m[rijec].end(); it++) std::cout << *it << " ";
            std::cout << std::endl;
        }
        catch(...) {
            std::cout << "Unesena rijec nije nadjena!" << std::endl;
        }
    }
	return 0;
}