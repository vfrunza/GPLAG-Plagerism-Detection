/B2017/2018: Zadaća 3, Zadatak 2
#include <iostream>
#include <string>
#include <set>
#include <map>
#include <vector>
#include <iterator>
#include <utility>
#include <tuple> 

typedef std::map<std::string,std::vector<std::string>>Knjiga;

std::map<std::string,std::set<int>>KreirajIndeksPojmova(typedef Knjiga) {
    std::map<std::string,std::set<std::tuple<std::string,int, int>>> mapa; //prva kord poglavlje, druga stranica, treca pozicij

    for(int i=0; i<Knjiga.size(); i++) { 
        if(Knjiga.at(i)>='A' && Knjiga.at(i)<='Z')
            Knjiga.at(i)+=('a'-'A');
    }
    for(int i=0; i<Knjiga.size(); i++) {
        if((Knjiga.at(i)>='a' && Knjiga.at(i)<='z') || (Knjiga.at(i)>='0' && Knjiga.at(i)<='9')) {
            int index(i);
            std::string pom;
            while((Knjiga.at(i)>='a' && Knjiga.at(i)<='z') || (Knjiga.at(i)>='0' && Knjiga.at(i)<='9')) {
                pom.push_back(Knjiga.at(i));
                i++;
            }
            auto it(mapa.find(pom));
            if(it==mapa.end()) {
                mapa.insert(std::tuple<std::string,std::set<int>,std::set<int>>(pom, {index}));
            } else {
                (it->second).insert(index);
            }
        }
    }
    return mapa;
}

std::set<int>PretraziIndeksPojmova(std::string s, std::map<std::string,std::set<int>>ipojmova) {
    std::set<int>skup;
    auto it(ipojmova.find(s));
    if(it==ipojmova.end()) {
        throw std::logic_error("Pojam nije nadjen");
    } else {
        skup=it->second;
    }
    return skup;
}


void IspisiIndeksPojmova (std::map<std::string,std::set<int>> map) {
    for(auto it=map.begin(); it!=map.end(); it++) {
        std::cout << it-> first << ": ";
        for(auto x=(it->second).begin(); x!=(it->second).end(); x++) {
            if(x==--(it->second).end())
                std::cout << *x << " ";
            else std::cout << *x << "/";
        }
        std::cout << std::endl;
    }
}



int main () {
    try {
        while(1) {
        char poglavlje;
        std::cout << "Unesite naziv poglavlja: ";
        std::cin << poglavlje;
        std::string tekst;
        std::cout << "Unesite sadrzaj stranice %d: ";
        std::getline(std::cin, tekst);
        }
        

        auto m(KreirajIndeksPojmova(tekst));

        IspisiIndeksPojmova(m);

        while(true) {
            try {
                std::cout << "Unesite rijec: ";
                std::string rijec;
                std::getline(std::cin, rijec);
                if(rijec==".") break;

                auto skup=PretraziIndeksPojmova(rijec,m);

                for(auto x:skup) std::cout << x << " ";
                std::cout << std::endl;
            } catch(std::logic_error e) {
                std::cout << "Unesena rijec nije nadjena!"<<std::endl;
            }
        }
    } catch(std::logic_error el) {
        std::cout << el.what() << std::endl;
    }
    return 0;

}
