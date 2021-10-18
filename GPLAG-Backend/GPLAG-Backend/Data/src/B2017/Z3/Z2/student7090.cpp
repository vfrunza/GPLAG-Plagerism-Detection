/B2017/2018: Zadaća 3, Zadatak 2
#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <tuple>
#include <set>
#include <stdexcept>

typedef std::map<std::string, std::vector<std::string>> Knjiga;

std::map<std::string, std::set<std::tuple<std::string, int, int>>> KreirajIndeksPojmova(Knjiga k)
{
    std::map<std::string, std::set<std::tuple<std::string, int, int>>> indeks_pojmova;
    //iterator koji se krece kroz mapu Knjiga
    for(auto it=k.begin(); it!=k.end(); it++) {
        std::string poglavlje(it->first);
        std::vector<std::string> vs(it->second);
        //petlja koja se krece kroz vektor stringova
        for(int j=0; j<vs.size(); j++) {
            int br_stranice(j+1);
            std::string s(vs[j]);
            //petlja koja se krece kroz string
            for(int i=0; i<s.size(); i++) {
                std::string rijec;
                if(((s[i]>='A' && s[i]<='Z') || (s[i]>='a' && s[i]<='z') || (s[i]>='0' && s[i]<='9')) && i<s.size()) {
                    int pozicija(i);
                    while (((s[i]>='A' && s[i]<='Z') || (s[i]>='a' && s[i]<='z') || (s[i]>='0' && s[i]<='9')) && i<s.size()) {
                        if(s[i]>='A' && s[i]<='Z') rijec.push_back(s[i]+('a'-'A'));
                        else rijec.push_back(s[i]);
                        i++;
                    }
                    auto t(std::tie(poglavlje, br_stranice, pozicija));
                    std::set<std::tuple<std::string, int, int>> *skup(&indeks_pojmova[rijec]);
                    skup->insert(t);
                }
            }
        }
    }
    return indeks_pojmova;
}

std::set<std::tuple<std::string, int, int>> PretraziIndeksPojmova(std::string s, std::map<std::string, std::set<std::tuple<std::string, int, int>>> mapa)
{
    auto it(mapa.find(s));
    if(it==mapa.end()) throw std::logic_error ("Pojam nije nadjen");
    return it->second;
}

void IspisiIndeksPojmova(std::map<std::string, std::set<std::tuple<std::string, int, int>>> mapa)
{
    for(auto it=mapa.begin(); it!=mapa.end(); it++) {
        std::cout<<it->first<<":";
        for(auto t=it->second.begin(); t!=it->second.end(); t++) {
            auto pom(t);
            pom++;
            if(pom==it->second.end()) std::cout<<" "<<std::get<0>(*t)<<"/"<<std::get<1>(*t)<<"/"<<std::get<2>(*t)<<std::endl;
            else std::cout<<" "<<std::get<0>(*t)<<"/"<<std::get<1>(*t)<<"/"<<std::get<2>(*t)<<",";
        }
    }
}

int main ()
{
    Knjiga k;
    for(;;) {
        std::string poglavlje;
        std::cout<<"Unesite naziv poglavlja: ";
        std::getline(std::cin, poglavlje);
        if(poglavlje==".") break;
        k[poglavlje];
        int br_stranice(1);
        for(;;) {
            std::string stranica;
            std::cout<<"Unesite sadrzaj stranice "<<br_stranice<<": ";
            std::getline(std::cin, stranica);
            if(stranica==".") break;
            k[poglavlje].push_back(stranica);
            br_stranice++;
        }
    }
    auto mapa(KreirajIndeksPojmova(k));
    std::cout<<std::endl<<"Kreirani indeks pojmova: "<<std::endl;
    IspisiIndeksPojmova(mapa);
    std::string rijec;
    for(;;) {
        std::cout<<"Unesite rijec: ";
        std::getline(std::cin, rijec);
        if(rijec==".") break;
        try {
            auto skup(PretraziIndeksPojmova(rijec, mapa));
            for(auto t : skup) std::cout<<std::get<0>(t)<<"/"<<std::get<1>(t)<<"/"<<std::get<2>(t)<<" ";
            std::cout<<std::endl;
        } catch(std::logic_error izz) {
            std::cout<<"Unesena rijec nije nadjena!"<<std::endl;
        }
    }
    return 0;
}