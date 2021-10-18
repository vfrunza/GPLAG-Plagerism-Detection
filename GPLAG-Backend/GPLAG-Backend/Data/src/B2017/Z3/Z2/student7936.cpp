#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <set>
#include <tuple>

typedef std::map<std::string, std::vector<std:: string>> Knjiga;

std::map<std::string,std::set<std::tuple<std::string,int,int>>> KreirajIndeksPojmova (Knjiga tekst)
{
    std::map<std::string,std::set<std::tuple<std::string,int,int>>> skup;
    auto it(tekst.begin());
    int stranica(0);
    while (it!=tekst.end()) {
        auto it2((*it).second);
        for (int i=0; i<it2.size(); i++) {
            for (int j=0; j<(it2).at(stranica).size(); j++) {
                while (!(std::isalnum(it2.at(stranica).at(j))) && j<it2.at(stranica).size()) i++;
                int polozaj(j);
                std::set<std::tuple<std::string,int,int>> pomocna {std::make_tuple((*it).first,stranica+1,polozaj)};
                std::string gr;
                while (std::isalnum((it2).at(stranica).at(j)) && j<it2.at(stranica).size()) {
                    gr.push_back(it2.at(stranica).at(j));
                    j++;
                    if (j==it2.at(stranica).size()) break;
                }
                auto trazi(skup.find(gr));
                if (trazi==skup.end()) skup.insert({gr,pomocna});
                else skup[gr].insert({std::make_tuple((*it).first,stranica+1,polozaj)});
            }
            stranica++;
        }
        it++;
        stranica=0;
    }

    return skup;
}

std::set<std::tuple<std::string,int,int>> PretraziIndeksPojmova (std::string rijec, std::map<std::string,std::set<std::tuple<std::string,int,int>>> indeks)
{
    std::set<std::tuple<std::string,int,int>> pozicija;
    auto it(indeks.find(rijec));
    if (it==indeks.end()) throw std::logic_error ("Unesena rijec nije nadjena!");
    else pozicija=indeks[rijec];
    return pozicija;
}

void IspisiIndeksPojmova (std::map<std::string,std::set<std::tuple<std::string,int,int>>> indeks)
{
    auto it(indeks.begin());
    while (it!=indeks.end()) {
        std::cout<<(*it).first<<": ";
        auto it2((*it).second);
        for (auto pom=it2.begin(); pom!=--it2.end(); ++pom) std::cout<<std::get<0>(*pom)<<"/"<<std::get<1>(*pom)<<"/"<<std::get<2>(*pom)<<", ";
        auto pom=--it2.end();
        std::cout<<std::get<0>(*pom)<<"/"<<std::get<1>(*pom)<<"/"<<std::get<2>(*pom);
        it++;
        std::cout<<std::endl;
    }
}

int main ()
{
    Knjiga knjiga;
    auto it(knjiga.begin());
    for (;;) {
        std::cout<<"Unesite naziv poglavlja: ";
        std::string poglavlje;
        std::getline(std::cin,poglavlje);
        if (poglavlje==".") break;
        int i(1);
        std::vector<std::string> pomocni;
        for (;;) {
            std::cout<<"Unesite sadrzaj stranice "<<i<<": ";
            std::string stranica;
            std::getline(std::cin,stranica);
            if (stranica==".") break;
            for(int i = 0; i<stranica.size(); i++) {
                stranica.at(i) = tolower(stranica.at(i));
            }
            pomocni.push_back(stranica);
            i++;
        }
        knjiga.insert({poglavlje,pomocni});
    }
    std::cout<<std::endl;
    std::map<std::string,std::set<std::tuple<std::string,int,int>>> skup;
    skup=KreirajIndeksPojmova(knjiga);
    std::cout<<"Kreirani indeks pojmova:"<<std::endl;
    IspisiIndeksPojmova(skup);
    for (;;) {
        try {
            std::cout<<"Unesite rijec: ";
            std::string rijec;
            std::getline(std::cin,rijec);
            if (rijec==".") break;
            auto pozicija(PretraziIndeksPojmova(rijec,skup));
            for (auto x:pozicija) std::cout<<std::get<0>(x)<<"/"<<std::get<1>(x)<<"/"<<std::get<2>(x)<<" ";
            std::cout<<std::endl;
        } catch (std::logic_error l) {
            std::cout<<l.what()<<std::endl;
        }
    }
    return 0;
}