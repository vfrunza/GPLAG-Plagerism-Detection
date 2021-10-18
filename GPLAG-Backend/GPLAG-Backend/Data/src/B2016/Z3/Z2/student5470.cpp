/B2016/2017: Zadaća 3, Zadatak 2
#include <iostream>
#include <string>
#include <map>
#include <set>
#include <stdexcept>

std::map<std::string, std::set<int>> KreirajIndeksPojmova (std::string tekst) {
    std::map <std::string, std::set<int>> mapa;
    for (int i=0; i<tekst.length(); i++) {
        if ((tekst[i]>='a' && tekst[i]<='z') || (tekst[i]>='A' && tekst[i]<='Z') || (tekst[i]>='0' && tekst[i]<='9')) {
           std::string pom;
            while ((tekst[i]>='a' && tekst[i]<='z') || (tekst[i]>='A' && tekst[i]<='Z') || (tekst[i]>='0' && tekst[i]<='9')) {
                if(tekst[i]>='A' && tekst[i]<='Z') tekst[i]+=('a'-'A');
                pom.push_back(tekst[i]);
                i++;
            }
            auto it(mapa.begin());
            for (it=mapa.begin(); it!=mapa.end(); it++) {
                if(it->first==pom) {
                    it->second.insert(i-int(pom.length()));
                    break;
                }
            }
            if (it==mapa.end()) {
                mapa[pom]={i-int(pom.length())};
            }
        }
    }
    return mapa;
}

std::set<int> PretraziIndeksPojmova (std::string rijec, std::map<std::string, std::set<int>> mapa) {
    bool b(false);
    std::set<int> skup;
    for (auto it=mapa.begin(); it!=mapa.end(); it++) {
        if(it->first==rijec) {
            skup=it->second;
            b=true;
        }
    }
    if(!b) throw std::logic_error("Pojam nije nadjen");
    return skup;
}

void IspisiIndeksPojmova (std::map<std::string, std::set<int>> mapa) {
    for (auto it=mapa.begin(); it!=mapa.end(); it++) {
        std::cout<<it->first<<": ";
        auto it1(it->second.begin());
        for (int i=0; i<it->second.size()-1; i++) {
            std::cout<<*it1<<",";
            it1++;
        }
        std::cout<<*it1;
        std::cout<<std::endl;
    }
}

int main ()
{   std::cout<<"Unesite tekst: ";
    std::string tekst;
    std::getline(std::cin, tekst);
    auto mapa(KreirajIndeksPojmova(tekst));
    IspisiIndeksPojmova(mapa);
    for (;;) {
        std::cout<<"Unesite rijec: ";
        std::string rijec;
        std::cin>>rijec;
        if(rijec==".") break;
        try {
            auto skup(PretraziIndeksPojmova(rijec,mapa));
            for (auto x : skup) std::cout<<x<<" ";
        }
        catch(...) {
            std::cout<<"Unesena rijec nije nadjena!";
        }
        std::cout<<std::endl;
        std::cin.ignore(10000, '\n');
    }
	return 0;
}
