/B2017/2018: Zadaća 3, Zadatak 2
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <tuple>
#include <stdexcept>

typedef std::map<std::string,std::vector<std::string>> Knjiga;
typedef std::map<std::string,std::set<std::tuple<std::string, int, int>>> IndeksPojmova;
bool DaLiJeSlovo(char k)
{
    if((k >= 'a' && k <= 'z') || (k >= 'A' && k <= 'Z') || (k>= '0' && k<'9')) return true;
    return false;
}
std::string PretvoriUMala(std::string s){
    auto k (s);
    std::transform(k.begin(),k.end(),k.begin(), ::tolower);
    return k;
}
IndeksPojmova KreirajIndeksPojmova(Knjiga parametar){
    IndeksPojmova vrati;
    std::vector<std::string> rijeci;
    int pocetak;
    for(auto it = parametar.begin(); it != parametar.end(); it++) {
        for(int i = 0; i < it->second.size(); i++) {
            for(int j = 0; j < it->second.at(i).size(); j++) {
                std::tuple<std::string,int,int> aha;
                std::set<std::tuple<std::string,int,int>> skup;

                pocetak = 0;
                std::string rijec;
                if(DaLiJeSlovo(it->second.at(i).at(j))) {
                    pocetak = j;
                    while(DaLiJeSlovo(it->second.at(i).at(j)) && j<it->second.at(i).size()-1) {
                        rijec.push_back(it->second.at(i).at(j));
                        j++;
                    }
                    if(j==it->second.at(i).size()-1) rijec.push_back(it->second.at(i).at(j));
                } else {
                    while(!DaLiJeSlovo(it->second.at(i).at(j)) && j < it-> second.at(i).size()-1) j++;
                    if (j == it->second.at(i).size()-1 && DaLiJeSlovo(it->second.at(i).at(j))) j++;
                }
                std::get<0>(aha) = it->first;
                std::get<1>(aha) = i+1;
                std::get<2>(aha) = pocetak;
                auto it1(vrati.find(rijec));
                if(it1 == vrati.end()) {
                    skup.insert(aha);
                    vrati.insert({rijec,skup});
                } else it1->second.insert(aha);
            }
        }
    }
    return vrati;
}
std::set<std::tuple<std::string, int, int>> PretraziIndeksPojmova(std::string pojam, IndeksPojmova indekspojmova){
    if(!indekspojmova.count(pojam)) throw std::logic_error("Pojam nije nadjen");
    for(auto it = indekspojmova.begin();it != indekspojmova.end();it++){
        if(it->first == pojam)
            return it->second;
    }
    return {};
}
void IspisiIndeksPojmova(IndeksPojmova mapa){
    for(auto x : mapa){
        std::cout<<x.first<<": ";
        int brojac(0);
        for(auto y : x.second){
            if(brojac!=x.second.size()-1)
                std::cout<<std::get<0>(y)<<"/"<<std::get<1>(y)<<"/"<<std::get<2>(y)<<", ";
            else std::cout<<std::get<0>(y)<<"/"<<std::get<1>(y)<<"/"<<std::get<2>(y)<<std::endl;
            brojac++;
        }
    }
}
int main ()
{
    Knjiga a;
    int i(1);
    for(;;){
        std::cout<<"Unesite naziv poglavlja: ";
        std::string poglavlje;
        std::vector<std::string> stranice;
        std::getline(std::cin,poglavlje);
        if(poglavlje==".") break;
        else
        for(;;){
            std::cout<<"Unesite sadrzaj stranice "<<i++<<": ";
            std::string stranica;
            std::getline(std::cin,stranica);
            if(stranica!=".") stranice.push_back(PretvoriUMala(stranica));
            else break;
            
        }
        a.insert({poglavlje,stranice});
    }
    auto indekspojmova(KreirajIndeksPojmova(a));
    std::cout<<std::endl<<"Kreirani indeks pojmova:"<<std::endl;
    IspisiIndeksPojmova(indekspojmova);
    for(;;)
    {
        try {
    
            std::cout<<"Unesite rijec: ";
            std::string rijec;
            std::getline(std::cin,rijec);
            if(rijec==".") break;
            auto skup(PretraziIndeksPojmova(rijec,indekspojmova));
            //std::cout<<skup.size()<<std::endl;
            if(skup.size()==0) {
                std::cout<<"Unesena rijec nije nadjena!"<<std::endl;
                continue;
            }
            for(auto it = skup.begin(); it!=skup.end(); it++)
                std::cout<<std::get<0>(*it)<<"/"<<std::get<1>(*it)<<"/"<<std::get<2>(*it)<<" ";
            std::cout<<std::endl;
    
        } catch(std::logic_error izuzetak) {
            std::cout<<"Unesena rijec nije nadjena!"<<std::endl;
        }
    }
    
    return 0;
}
