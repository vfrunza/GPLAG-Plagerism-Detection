/B2017/2018: Zadaća 3, Zadatak 2
#include <iostream>
#include <map>
#include <vector>
#include <string>

typedef std::map<std::string, std::vector<std::string>> Knjiga;

std::map<std::string, std::set<std::tuple<std::string, int, int>>> KreirajIndeksPojmova (Knjiga k)
{
    std::map<std::string, std::set<std::tuple<std::string, int, int>>> indeks_pojmova;
    for (auto it=k.begin(); it!=k.end(); it++) {
        auto ime_poglavlja = it->first;
        auto tekst = it->second;
        for(int i(0); i<tekst.size(); i++) {
            int brojac(0);
            for (int j(0); j<tekst.at(i).size(); j++) {
                //for (int l(0); l<tekst.at(i).at(j).size(); l++)
                    if (tekst.at(i).at(j)>='A' && tekst.at(i).at(j)<='Z') tekst.at(i).at(j)+=32;
                //j++;
                brojac++;
                if (brojac==0) {
                    i++;
                    continue;
                }
                bool da_li_ima = false;
                int br(0);
                std::string rijec;
                while (br!=tekst.size()) {
                    if (tekst.at(i) == tekst.at(i).substr(j-brojac, brojac)) da_li_ima = true;
                    rijec=tekst.at(i).substr(j-brojac, brojac);
                    br++;
                }

                if(da_li_ima) {
                    std::tuple<std::string, int, int> pom_tuple = std::make_tuple(ime_poglavlja,i+1, j);
                    std::set<std::tuple<std::string<std::string, int, int>>> skup;
                    skup.insert(pom_tuple);
                    indeks_pojmova.insert(std::make_pair(rijec, skup));

                }
            }
        }
    }
    return indeks_pojmova;
}

int main ()
{
    Knjiga knjiga;
    for (;;) {
        std::string ime_poglavlja;
        std::cout << "Unesite naziv poglavlja: ";
        std::getline(std::cin, ime_poglavlja);
        std::vector<std::string> sadrzaj;
        if (ime_poglavlja==".") break;
        for (;;) {
            std::string tekst;
            std::cout<<"Unesite sadrzaj stranice" << i<<": ";
            std::getline(std::cin, tekst);
            if(tekst==".") break;
            sadrzaj.push_back(tekst);
            i++;
        }
        auto par = std::make_pair(ime_poglavlja, sadrzaj);
        knjiga.insert(par);
    }
    std::cout << std::endl;
    std::cout << "Kreirani indeks pojmova:" << std::endl;
    auto indeks_pojmova = KreirajIndeksPojmova(knjiga);
    for (auto it=indeks_pojmova.begin(); it!=indeks_pojmova.end(); it++) {
        std::cout<<it->first<<": ";
        for (auto pok=(it->second).begin(); pok!=(it->second).end(); pok++;) {
            auto kraj=it->second.end();
            kraj--;
            if (pok!=kraj) std::cout << std::get<0>(*pok)<<std::get<1>(*pok)<<std::get<2>(*pok) << std::endl;
        }
    }
    return 0;
}
