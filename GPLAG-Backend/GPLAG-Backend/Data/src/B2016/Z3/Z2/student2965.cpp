/B2016/2017: Zadaća 3, Zadatak 2
#include <iostream>
#include <map>
#include <set>
#include <string>
#include <iterator>
#include <stdexcept>
#include <utility>
std::map<std::string,std::set<int>> KreirajIndeksPojmova(std::string s) {
    std::map<std::string,std::set<int>> rjecnik;
    int indeks;
    for(int i=0;i<s.size();i++) {
        if(s[i]>='A' && s[i]<='Z') s[i]+=32;
    }
    for(int i=0;i<s.size();i++) {
        if(s[i]==' ') {
            if(i!=s.size()) i++;
        }
        indeks=i;
        std::string novi;
        while (s[i]!=' ' && i!=s.size()) {
            novi+=s[i];
            i++;
        }
        if(!rjecnik.count(novi)) {
            std::set<int> sk{indeks};
            rjecnik.insert(std::make_pair(novi,sk));
        }
        else {
            auto it=rjecnik.find(novi);
            it->second.insert(indeks);
        }
        novi.clear();
    }
    return rjecnik;
}
std::set<int> PretraziIndeksPojmova(std::string s, std::map<std::string,std::set<int>> rjecnik) {
    if(!rjecnik.count(s)) throw std::logic_error("Unesena rijec nije nadjena!\n");
    else {
        auto it=rjecnik.find(s);
        return it->second;
    }
}
void IspisiIndeksPojmova(std::map<std::string, std::set<int>> rjecnik) {
    for(auto it=rjecnik.begin();it!=rjecnik.end();it++) {
        std::cout<<it->first<<": ";
        int br(1);
        for(auto broj:it->second) {
            if(br<it->second.size()) {
                std::cout<<broj<<",";
                br++;
            }
            else {
                std::cout<<broj;
            }
        }
        std::cout<<std::endl;
    }
}
  
int main()  {
    std::string s;
    std::cout<<"Unesite tekst: ";
    std::getline(std::cin,s);
    std::map<std::string,std::set<int>> rjecnik;
    rjecnik=KreirajIndeksPojmova(s);
    IspisiIndeksPojmova(rjecnik);
    std::string neki_s;
    for(;;) {
        std::cout<<"Unesite rijec: ";
        std::getline(std::cin,neki_s);
        if(neki_s==".") break;
        try {
            std::set<int> skup;
            skup=PretraziIndeksPojmova(neki_s,rjecnik);
            for(auto broj:skup) {
                std::cout<<broj<<" ";
            }
            std::cout<<std::endl;
        }
        catch(std::logic_error izuzetak) {
            std::cout<<izuzetak.what();
        }
    }
	return 0;
}