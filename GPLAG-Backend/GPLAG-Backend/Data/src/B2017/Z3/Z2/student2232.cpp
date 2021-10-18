/B2017/2018: Zadaća 3, Zadatak 2
#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <set>
#include <tuple>
#include <iterator>

typedef std::map<std::string, std::vector<std::string>> Knjiga;
typedef std::set<std::tuple<std::string, int, int>> LokacijePojma;
typedef std::map<std::string, LokacijePojma> Pojmovi;


Pojmovi KreirajIndeksPojmova(Knjiga knjiga)
{
    Pojmovi indeks_pojmova;
    for(auto it(knjiga.begin()); it!=knjiga.end(); it++) {
        for(int i(0); i<it->second.size(); i++) {
            for(int j(0); j<it->second.at(i).size(); j++) {
                while(j<it->second.at(i).size() && !(std::isalnum(it->second.at(i).at(j))) ) j++;
                int pozicija(j);
                std::string rijec;
                while(j<it->second.at(i).size() && std::isalnum(it->second.at(i).at(j))) {
                    rijec.push_back(it->second.at(i).at(j));
                    j++;
                }
                for(int k(0); k<int(rijec.length()); k++) rijec.at(k)=std::tolower(rijec.at(k));
                if(std::distance(indeks_pojmova.begin(),indeks_pojmova.end())==0) indeks_pojmova.insert({rijec, {std::make_tuple(it->first, i+1, pozicija)}});
                else {
                    auto it_pojmovi(indeks_pojmova.begin());
                    bool postoji_rijec(false);
                    for(it_pojmovi=indeks_pojmova.begin(); it_pojmovi!=indeks_pojmova.end(); it_pojmovi++)
                        if(it_pojmovi->first==rijec) {
                            postoji_rijec=true;
                            break;
                        }
                    if(postoji_rijec) it_pojmovi->second.insert(std::make_tuple(it->first, i+1, pozicija));
                    else indeks_pojmova.insert({rijec, {std::make_tuple(it->first, i+1, pozicija)}});
                }
            }
        }
    }
    return indeks_pojmova;
}

LokacijePojma PretraziIndeksPojmova(std::string rijec, Pojmovi indeks_pojmova)
{
    auto it(indeks_pojmova.find(rijec));
    if(it==indeks_pojmova.end()) throw std::logic_error("Unesena rijec nije nadjena!");
    return it->second;
}

void IspisiIndeksPojmova(Pojmovi indeks_pojmova)
{
    std::cout << "\nKreirani indeks pojmova:\n";
    for(auto i(indeks_pojmova.begin()); i!=indeks_pojmova.end(); i++) {
        std::cout << i->first << ":";
        for(auto j(i->second.begin()); j!=i->second.end(); j++) {
            if(j!=i->second.begin()) std::cout << ",";
            std::cout<< " " << std::get<0>(*j) << "/" << std::get<1>(*j) << "/" << std::get<2>(*j);
        }
        std::cout << std::endl;
    }
}

void NapraviKnjigu(Knjiga &knjiga)
{
    for(;;) {
        std::cout << "Unesite naziv poglavlja: ";
        std::string naziv_poglavlja;
        std::getline(std::cin, naziv_poglavlja);
        if(naziv_poglavlja==".") break;
        std::vector<std::string> tekst;
        for(int i(1); i>0; i++) {
            std::string stranica;
            std::cout << "Unesite sadrzaj stranice " << i << ": ";
            std::getline(std::cin, stranica);
            if(stranica==".") break;
            tekst.push_back(stranica);
        }
        knjiga.insert({naziv_poglavlja,tekst});
    }
}

void UnosRijeciZaPretragu(Pojmovi indeks_pojmova){
    for(;;){
        try{
            std::string rijec;
            std::cout << "Unesite rijec: "; 
            std::getline(std::cin, rijec);
            if(rijec==".") break;
            LokacijePojma lokacije(PretraziIndeksPojmova(rijec, indeks_pojmova));
            for(auto i(lokacije.begin()); i!=lokacije.end(); i++)
                std::cout << std::get<0>(*i) << "/" << std::get<1>(*i) << "/" << std::get<2>(*i) << " ";
            std::cout << std::endl;
        }
        catch(std::logic_error e){
            std::cout << e.what() << std::endl;
        }
    }
}

int main(){
    Knjiga knjiga;
    NapraviKnjigu(knjiga);
    Pojmovi indeks_pojmova(KreirajIndeksPojmova(knjiga));
    IspisiIndeksPojmova(indeks_pojmova);
    UnosRijeciZaPretragu(indeks_pojmova);
    return 0;
}
