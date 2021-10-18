/B2017/2018: Zadaća 3, Zadatak 2
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
#include <stdexcept>

typedef std::map<std::string,std::vector<std::string>> Knjiga;

std::map<std::string,std::set<std::tuple<std::string,int,int>>> KreirajIndeksPojmova (Knjiga knjiga){
    std::map<std::string,std::set<std::tuple<std::string,int,int>>> finalni;
    for (auto x  : knjiga) {
        for (int  i = 0;i<x.second.size();i++) {
            int razmak=1;
            std::string::iterator it=x.second[i].begin();
            while (it<x.second[i].end()) {
                if(*it < '0'  ||  *it > '9'  &&  *it < 'A' || *it > 'Z'  &&  *it <'a' ||  *it>'z'){
                    razmak=1;
                    it++;
                }
                else if(razmak==1){
                    std::string::iterator it2=it;
                    while (it <x.second[i].end() &&  ((*it>='0' &&  *it <= '9') || (*it >= 'A'&& *it <= 'Z') ||  (*it >= 'a'&& *it <= 'z'))) it++;
                    std::string s(x.second[i].substr(it2-x.second[i].begin(),it-it2));
                    for (char & j : s) {
                        j=std::tolower(j);
                    }
                    finalni[s];
                    finalni[s].insert(std::make_tuple(x.first,i+1,int(it2-x.second[i].begin())));
                    razmak=0;
                }
            }
        }
    }
    return finalni;
}

std::set<std::tuple<std::string,int,int>> PretraziIndeksPojmova(std::string rijec, std::map<std::string,std::set<std::tuple<std::string,int,int>>> mapaa){
   for (int i = 0; i < rijec.size(); i++) {
       rijec[i]=std::tolower(rijec[i]);
   }
    if(!mapaa.count(rijec))
        throw std::logic_error("Unesena rijec nije nadjena!");
    else 
        return((*mapaa.lower_bound(rijec)).second);
}
void IspisiIndeksPojmova(std::map<std::string,std::set<std::tuple<std::string,int,int>>> mapaa){
    for (auto i : mapaa ) {
        std::cout << i.first <<":";
        auto it = i.second.begin();
        for (int j=0; j < i.second.size(); j++) {
            if(j<i.second.size()-1)
                std::cout << " "<<std::get<0>(*it)<<"/"<<std::get<1>(*it)<<"/"<<std::get<2>(*it)<<"," ;
            else
                std::cout << " "<<std::get<0>(*it)<<"/"<<std::get<1>(*it)<<"/"<<std::get<2>(*it) << std::endl;
            it++;
        }   
    }
}
int main ()
{
    Knjiga knjiga;
    while (1) {
        std::cout << "Unesite naziv poglavlja: ";
        std::string s;
        std::getline(std::cin,s);
        if(s[0]=='.')
            break;
        std::vector<std::string> vs;
        for (int i = 0;; i++) {
            std::string recenica;
            std::cout << "Unesite sadrzaj stranice "<<i+1<<": ";
            std::getline(std::cin,recenica);
            if(recenica[0]=='.')
            break;
            vs.push_back(recenica);
        }
        knjiga.insert(std::make_pair(s,vs));
    }
    std::map<std::string,std::set<std::tuple<std::string,int,int>>> indekspojmova=KreirajIndeksPojmova(knjiga);
    std::cout<<std::endl << "Kreirani indeks pojmova:" << std::endl;
    IspisiIndeksPojmova(indekspojmova);
    while (true) {
        std::cout << "Unesite rijec: ";
        std::string s;
        std::getline(std::cin,s);
        if(s[0]=='.')
            break;
        std::set<std::tuple<std::string,int,int>> skup;
        try {
            skup=PretraziIndeksPojmova(s,indekspojmova);
            auto it=skup.begin();
            for (int i = 0; i < skup.size(); i++) {
                std::cout <<std::get<0>(*it)<<"/"<<std::get<1>(*it)<<"/"<<std::get<2>(*it)<<" " ;
                it++;
            }
            std::cout << std::endl;
        }
        catch (std::logic_error error) {
            std::cout << error.what() << std::endl;
        }
        
    }
	return 0;
}
