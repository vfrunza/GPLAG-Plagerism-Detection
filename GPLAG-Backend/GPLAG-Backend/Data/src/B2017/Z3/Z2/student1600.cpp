/B2017/2018: Zadaća 3, Zadatak 2
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <utility>
#include <stdexcept>
#include <algorithm>

typedef std::map<std::string, std::vector<std::string>> Knjiga;

bool JeLiSlovo_Cifra (char znak)
{
    if((znak>='a' && znak<='z') || (znak>='A' && znak<='Z') || (znak>='0' && znak <='9'))
        return true;
    else return false;
}

std::vector<std::string> PovadiRijeci (std::string recenica)
{
    std::vector<std::string> rijeci;

    if(recenica.size()==0)
        return rijeci;

    std::string pom;

    for(int i=0; i<recenica.size(); i++) {

        if(JeLiSlovo_Cifra(recenica.at(i)))
            pom+=recenica.at(i);

        else {

            if(pom.size()>0) {

                auto it=std::find(rijeci.begin(), rijeci.end(), pom);

                if(it==rijeci.end())
                    rijeci.push_back(pom);
            }
            pom="";
        }
    }
    if(pom.size()>0) {

        auto it=std::find(rijeci.begin(), rijeci.end(), pom);
        if(it==rijeci.end())
            rijeci.push_back(pom);
    }
    return rijeci;
}

std::map<std::string, std::set<std::tuple<std::string, int, int>>> KreirajIndeksPojmova (Knjiga novaknjiga)
{

    for(auto it=novaknjiga.begin(); it!=novaknjiga.end(); it++) {
        for(int i=0; i<(it->second).size(); i++) {
            for(int j=0; j<((it->second)[i]).size(); j++)
                if(((it->second)[i])[j]>='A' && ((it->second)[i])[j]<='Z') ((it->second)[i])[j]+=32;
        }
    }
    std::map<std::string, std::set<std::tuple<std::string, int, int>>> za_vratiti;

    for(auto par: novaknjiga) {
        int brojac=1;

        for(auto stranica: par.second) {
            auto v=PovadiRijeci(stranica);

            for(int i=0; i<v.size(); i++) {

                for(int j=0; j<=stranica.size()-v.at(i).size(); j++) {

                    std::string pom;
                    pom=stranica.substr(j, v.at(i).size());

                    if(pom==v.at(i)) {

                        std::tuple<std::string, int, int> za_ubaciti;
                        za_ubaciti=std::make_tuple(par.first, brojac, j);
                        za_vratiti[pom].insert(za_ubaciti);
                    }
                }
            }
            brojac++;
        }
    }
    return za_vratiti;
}

void IspisiIndeksPojmova (std::map<std::string, std::set<std::tuple<std::string, int, int>>> mapa)
{
    std::cout<<std::endl<<"Kreirani indeks pojmova: "<<std::endl;

    for (auto iter=mapa.begin(); iter!=mapa.end(); iter++) {

        std::cout<<iter->first<<": ";

        int brojac(iter->second.size());

        for(auto x: iter->second) {
            if(brojac!=1)
                std::cout<<std::get<0>(x)<<"/"<<std::get<1>(x)<<"/"<<std::get<2>(x)<<", ";
            else
                std::cout<<std::get<0>(x)<<"/"<<std::get<1>(x)<<"/"<<std::get<2>(x);
            brojac--;
        }
        std::cout<<std::endl;
    }
}

std::set<std::tuple<std::string, int, int>> PretraziIndeksPojmova (std::string rijec, std::map<std::string, std::set<std::tuple<std::string, int, int>>> mapa)
{
    for(int i=0; i < rijec.length(); i++)
        if(rijec[i] >= 'A' && rijec[i] <= 'Z') rijec[i]+=32;

    auto iter(mapa.find(rijec));

    if(iter==mapa.end())
        throw std::logic_error ("Unesena rijec nije nadjena!");
    else
        return iter->second;
}


int main ()
{
    Knjiga novaknjiga;
    for(;;) {
        std::cout<<"Unesite naziv poglavlja: ";
        std::string uneseno_poglavlje;
        std::getline(std::cin, uneseno_poglavlje);
        if(uneseno_poglavlje==".")
            break;
        novaknjiga[uneseno_poglavlje];

        std::vector<std::string> stranice;
        int brojac=1;
        for(;;) {
            std::cout<<"Unesite sadrzaj stranice "<<brojac<<": ";
            std::string unesena_stranica;
            std::getline(std::cin, unesena_stranica);
            if(unesena_stranica==".")
                break;
            stranice.push_back(unesena_stranica);
            brojac++;
        }
        novaknjiga[uneseno_poglavlje]=stranice;
    }

    auto indeksi=KreirajIndeksPojmova(novaknjiga);
    IspisiIndeksPojmova(indeksi);
    for(;;) {
        std::cout<<"Unesite rijec: ";
        std::string unos;
        std::cin>>unos;
        if(unos==".")
            break;
        try {
            auto skup=PretraziIndeksPojmova (unos, indeksi);
            for(auto x: skup) {
                std::cout<<std::get<0>(x)<<"/"<<std::get<1>(x)<<"/"<<std::get<2>(x)<<" ";
            }
            std::cout<<std::endl;
        } catch (std::logic_error e) {
            std::cout<<e.what()<<std::endl;
        }
    }


    return 0;
}
