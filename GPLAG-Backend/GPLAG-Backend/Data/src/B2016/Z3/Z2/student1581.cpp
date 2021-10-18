/B2016/2017: Zadaća 3, Zadatak 2
#include <iostream>
#include <string>
#include <map>
#include <set>
#include <algorithm>
#include <utility>
#include <stdexcept>

std::map<std::string, std::set<int> > KreirajIndeksPojmova(std::string s) {
    std::map<std::string, std::set<int> > mapa;
    if (s.length()==0) return mapa;
    for (int i=0; i<s.length(); i++) {
         std::string pom;
         while ((s[i] >='a'  && s[i]<='z') || (s[i]>='A' && s[i]<='Z') || (s[i]>='0' && s[i]<='9') && i != s.length()) {
             pom.push_back(s[i]);
             i++;
         }
         
        std::transform(pom.begin(), pom.end(), pom.begin(), (int(*) (int))std::tolower);
       
        auto it(mapa.find(pom));
        
        if (mapa.count(pom) == 0) {
            if (pom.length() != 0)
            mapa.insert(std::pair<std::string, std::set<int> > (pom, {static_cast<int>(i-pom.length())}));
        }
        else {
            if (pom.length() != 0)
            (it->second).insert(i-pom.length());
        }
    } 
    return mapa; 
}

std::set<int> PretraziIndeksPojmova(std::string s, std::map<std::string, std::set<int> > mapa) {
    std::transform(s.begin(), s.end(), s.begin(), (int(*) (int))std::tolower);
    auto it(mapa.find(s));
    if (mapa.count(s) == 0) throw std::logic_error("Unesena rijec nije nadjena!");
    else return it->second;
}

void IspisiIndeksPojmova(std::map<std::string, std::set<int> > mapa) {
    for (auto it=mapa.begin(); it!=mapa.end(); it++) {
        std::cout<<it->first<<": ";
        for (auto x=(it->second).begin(); x!=(it->second).end(); x++) {
            if (x != (it->second).begin()) std::cout<<",";
            std::cout<<*x;
        }
        std::cout<<std::endl;
    }
}

int main ()
{
    std::string s=" ";
    std::cout<<"Unesite tekst: ";
    std::getline(std::cin, s);
    std::map<std::string, std::set<int> > mapa = KreirajIndeksPojmova(s);
    IspisiIndeksPojmova(mapa);
    std::string pom;
    do {
        try {
            std::cout<<"Unesite rijec: ";
            std::getline(std::cin, pom);
            if (pom == ".") break;
            std::set<int> x = PretraziIndeksPojmova(pom, mapa);
            for (auto a:x) std::cout<<a<<" ";
            std::cout<<std::endl;
        }
        catch(std::logic_error e) {
            std::cout<<e.what()<<std::endl;
        }
    }
    while (pom != ".");
	return 0;
}





