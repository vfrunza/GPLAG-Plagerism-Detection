/B2016/2017: Zadaća 3, Zadatak 2
#include <iostream>
#include <string>
#include <map>
#include <set>
#include <stdexcept>
#include <vector>
#include <algorithm>

void IspisiSkup (std::set<int> skup) {
    std::vector<int> pomocni;
    for(auto x : skup) {
        pomocni.push_back(x);
    }
    for(int i=0;i<pomocni.size();i++) {
        if(i==pomocni.size()-1) std::cout << pomocni[i];
        else std::cout << pomocni[i] << ",";
    }
}

std::map<std::string, std::set<int>> KreirajIndeksPojmova (std::string recenica) {
    std::map<std::string, std::set<int>> mapa;
    for(int i=0;i<recenica.length();i++) {
        while(recenica[i]==' ') i++;
        std::string rijec;
        std::set<int> skup;
        int indeks(i);
        if((recenica[indeks]>='A' && recenica[indeks]<='Z') || (recenica[indeks]>='a' && recenica[indeks]<='z') || (recenica[indeks]>='0' && recenica[indeks]<='9') && (indeks!=recenica.length())) {
        while((recenica[indeks]>='A' && recenica[indeks]<='Z') || (recenica[indeks]>='a' && recenica[indeks]<='z') || (recenica[indeks]>='0' && recenica[indeks]<='9') && (indeks!=recenica.length())) {
            rijec.push_back(recenica[indeks]);
            indeks++;
        }
        std::transform(rijec.begin(),rijec.end(),rijec.begin(),tolower);
        auto it(mapa.find(rijec));
        if(it!=mapa.end()) {
            it->second.insert(i);
            i=indeks-1;
            continue;
        }
        else {
            skup.insert(i);
            i=indeks;
            mapa[rijec]=skup;
        }
        }
    }
    return mapa;
}

std::set<int> PretraziIndeksPojmova (std::string rijec, std::map<std::string,std::set<int>> mapa) {
    auto it=mapa.find(rijec);
    if(it==mapa.end()) throw std::logic_error("Pojam nije nadjen");
    std::set<int> skup(it->second);
    return skup;
}

void IspisiIndeksPojmova (std::map<std::string, std::set<int>> mapa) {
    for(auto it=mapa.begin(); it!=mapa.end(); it++) {
        std::cout << it->first << ": ";
        IspisiSkup(it->second);
        std::cout << std::endl;
    }
}

int main ()
{
    std::string recenica;
    std::cout << "Unesite tekst: ";
    std::getline(std::cin,recenica);
    std::map<std::string, std::set<int>> mapa=KreirajIndeksPojmova(recenica);
    IspisiIndeksPojmova(mapa);
    std::string rijec;
    for(;;) {
        std::cout << "Unesite rijec: ";
        std::getline(std::cin,rijec);
        if(rijec==".") return 0;
        try {
            std::set<int> skup(PretraziIndeksPojmova(rijec,mapa));
            for(int x : skup) {
             std::cout << x << " ";
            }
        }
        catch(std::logic_error izuzetak) {
            std::cout << "Unesena rijec nije nadjena!" << std::endl;
            continue;
        }
        std::cout << std::endl;
    }
	return 0;
}