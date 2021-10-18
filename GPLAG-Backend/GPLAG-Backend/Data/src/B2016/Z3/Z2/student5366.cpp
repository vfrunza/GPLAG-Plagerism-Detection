B2016/2017: Zadaća 3, Zadatak 2
#include <iostream>
#include <string>
#include <map>
#include <set>
#include <algorithm>
#include <stdexcept>

std::map<std::string, std::set<int>> KreirajIndeksPojmova(std::string s){
    std::map<std::string, std::set<int>> mapa;
    for(int i=0; i<s.length(); i++) if(s[i]>='A' && s[i]<='Z') s[i] += 'a'-'A';
    for(int i=0; i<s.length(); i++){
        std::string rijec;
        if((s[i]>='a' && s[i]<='z')||(s[i]>='0' && s[i]<='9')){
            auto pocetak(i);
            while(((s[i]>='a' && s[i]<='z')||(s[i]>='0' && s[i]<='9')) && i<s.length()){
                i++;
                rijec = s.substr(pocetak, i-pocetak);
            }
           mapa[rijec].insert(pocetak);
        }
    }
    return mapa;
}

std::set<int> PretraziIndeksPojmova(std::string pojam, std::map<std::string, std::set<int>> IndexPojmova){
    auto it(IndexPojmova.find(pojam));
    if(it == IndexPojmova.end()) throw std::logic_error("Pojam nije nadjen");
    else return it->second;
}

void IspisiIndeksPojmova(std::map<std::string, std::set<int>> IndexPojmova){
    for(auto it=IndexPojmova.begin(); it!=IndexPojmova.end(); it++){
        std::cout<<it->first<<": ";
        int i((it->second).size());
        for(auto x : it->second){
            i--;
            if(i>0)
            std::cout<<x<<",";
            else 
            std::cout<<x;
        }
    std::cout<<std::endl;
    }
}

int main ()
{
    std::string recenica;
    std::cout<<"Unesite tekst: ";
    std::getline(std::cin, recenica);
    std::map<std::string, std::set<int>> IndexPojmova = KreirajIndeksPojmova(recenica);
    IspisiIndeksPojmova(IndexPojmova);
    for(;;){
        std::string rijec;
        std::cout<<"Unesite rijec: ";
        std::getline(std::cin, rijec);
        if(rijec==".") break;
        else{
            try{
                for(auto x : PretraziIndeksPojmova(rijec, IndexPojmova)) std::cout<<x<<" ";
            }
            catch(std::logic_error){
                std::cout<<"Unesena rijec nije nadjena!"<<std::endl;
            }
        }
        std::cout<<std::endl;
    }
	return 0;
}