/B2017/2018: Zadaća 3, Zadatak 2
#include <iostream>
#include <map>
#include <string>
#include <vector> 
#include <tuple>
#include <set>
#include <stdexcept>

typedef std::map<std::string, std::vector<std:: string>> Knjiga;

void PretvoriUMala(std::string &string) {
    for (int i=0; i<string.size(); i++) {
        if (string.at(i)>='A' && string.at(i)<='Z') string.at(i)+=32;
    }
}

bool DaLiJeSlovo (char s) {
    if ((s>='A' && s<='Z') || (s>='a' && s<='z') || (s>='0' && s<='9')) return true;
    else return false;
}


std::map<std::string, std::set<std::tuple<std::string, int, int>>> KreirajIndeksPojmova(Knjiga K) {
    std::map<std::string, std::set<std::tuple<std::string, int, int>>> pojmovi;
    std::string recenica("");
    for (auto i=K.begin(); i!=K.end(); i++) {
        for (int j=0; j<i->second.size(); j++) {
            recenica="";
            for (int k=0; k<i->second.at(j).size(); k++) { 
                int indeks(k);
                if (DaLiJeSlovo(i->second.at(j).at(k))) {
                    while (DaLiJeSlovo(i->second.at(j).at(k)) && (k<i->second.at(j).size())) {
                    recenica+=i->second.at(j).at(k);
                    k++;
                    }
                } 
            PretvoriUMala(recenica);
            auto it(pojmovi.find(recenica));
            if (it==pojmovi.end()) {
                auto pomocni=std::make_tuple(i->first,j+1,indeks);
                std::set<std::tuple<std::string, int, int>> ZaPojmove;
                ZaPojmove.insert(pomocni);
                pojmovi[recenica]=ZaPojmove;
            }
            else {
                auto it(pojmovi.find(recenica));
                auto pomocni=std::make_tuple(i->first, j+1, indeks);
                it->second.insert(pomocni);
                }
            }
        }
    }
    return pojmovi;
}

std::set<std::tuple<std::string, int, int>> PretraziIndeksPojmova(std::string string, std::map<std::string, std::set<std::tuple<std::string, int, int>>> mapa) {
    PretvoriUMala(string);
    auto PretraziMapu(mapa.find(string));
    if (PretraziMapu==mapa.end()) throw std::logic_error("Pojam nije nadjen");
    return PretraziMapu->second;
}

void IspisiIndeksPojmova(std::map<std::string, std::set<std::tuple<std::string, int, int>>> mapa) {
    
}


int main ()
{
    Knjiga knjiga;
    std::string s;
    while (1) {
        std::cout<<"Unesite naziv poglavlja: ";
        std::getline(std::cin, s);
        if (s==".") break;
        std::string str;
        std::vector<std::string> v;
        int br_str(1);
        while (1) {
            std::cout<<"Unesite sadrzaj stranice "<<br_str<<": ";
            std::getline(std::cin, str);
            if (str==".") break;
            v.push_back(str);
            br_str++;
        }
        knjiga[s]=v;
    }
    
    
    std::cout<<std::endl<<"Kreirani indeks pojmova:"<<std::endl;
    
    auto indeks_pojmova(KreirajIndeksPojmova(knjiga));
    
    IspisiIndeksPojmova(indeks_pojmova);
    
    while (1) {
        std::string trazena;
        std::cout<<"Unesite rijec: ";
        std::getline(std::cin, trazena);
        if (trazena==".") break;
        try {
            auto rijec(PretraziIndeksPojmova(trazena,indeks_pojmova));
            auto it(rijec.begin());
            while (1) {
                if (it==rijec.end()) break;
                std::cout<<std::get<0>(*it)<<"/"<<std::get<1>(*it)<<"/"<<std::get<2>(*it);
                it++;
            }
            std::cout<<std::endl;
        }
        catch (std::logic_error e) {
            std::cout<<"Unesena rijec nije nadjena!"<<std::endl;
        }
    }
    
	return 0;
}






