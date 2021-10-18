/B2016/2017: Zadaća 3, Zadatak 2
#include <iostream>
#include <string>
#include <utility>
#include <set>
#include <stdexcept>
#include <map>

std::map<std::string,std::set<int>> KreirajIndeksPojmova(std::string tekst) {
    std::map<std::string,std::set<int>> mapa;
    for(int i(0);i<tekst.length();i++) {
        std::string rijec;
        int slova(0);
        if((tekst[i]>='0' && tekst[i]<='9') || (tekst[i]>='A' && tekst[i]<='Z') || (tekst[i]>='a' && tekst[i]<='z')) {
            if(tekst[i]>='A' && tekst[i]<='Z') rijec.push_back(tekst[i]+32);
            else rijec.push_back(tekst[i]);
            i++;
            slova++;
            while(i!=tekst.length() && ((tekst[i]>='0' && tekst[i]<='9') || (tekst[i]>='A' && tekst[i]<='Z') || (tekst[i]>='a' && tekst[i]<='z'))) {
                if(tekst[i]>='A' && tekst[i]<='Z') rijec.push_back(tekst[i]+32);
                else rijec.push_back(tekst[i]);
                i++;
                slova++;
            }
            mapa[rijec].insert(i-slova);
        }
    }
    return mapa;
}

std::set<int> PretraziIndeksPojmova(std::string rijec, std::map<std::string,std::set<int>> pojmovi) {
    if(!pojmovi.count(rijec)) throw std::logic_error ("Pojam nije nadjen");
    else return pojmovi[rijec];
}

void IspisiIndeksPojmova(std::map<std::string,std::set<int>> pojmovi) {
    for(auto it=pojmovi.begin();it!=pojmovi.end();it++) {
        std::cout<<it->first<<": ";
        int i(0);
        for(const auto &x : it->second) {
            if(i!=it->second.size()-1) {
                std::cout<<x<<",";
                i++;
            }
            else std::cout<<x;
        }
        std::cout<<std::endl;
    }
}
int main ()
{
    std::cout<<"Unesite tekst: ";
    std::string tekst;
    std::getline(std::cin,tekst);
    std::map<std::string,std::set<int>> pojmovi=KreirajIndeksPojmova(tekst);
    IspisiIndeksPojmova(pojmovi);
    for(;;) {
        std::cout<<"Unesite rijec: ";
        std::string rijec;
        std::getline(std::cin,rijec);
        if(rijec==".") break;
        try {
            std::set<int> pozicije=PretraziIndeksPojmova(rijec,pojmovi);
            for(auto x : pozicije) std::cout<<x<<" ";
            std::cout<<std::endl;
        }
        catch(...) {
            std::cout<<"Unesena rijec nije nadjena!"<<std::endl;
        }
    }
	return 0;
}