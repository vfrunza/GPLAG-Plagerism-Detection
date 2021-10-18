/B2016/2017: Zadaća 3, Zadatak 2
#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <set>
#include <stdexcept>

std::string UMalaSlova(std::string recenica){
    for(int i=0; i<recenica.length(); i++){
        if(recenica[i]>='A' && recenica[i]<='Z') recenica[i]+='a'-'A';
    }
    return recenica;
}

bool JelMozeURijec(char a){
    return (a>='0' && a<='9') || (a>='A' && a<='Z') || (a>='a' && a<='z');
}

std::map<std::string, std::set<int>> KreirajIndeksPojmova (std::string recenica){
    recenica=UMalaSlova(recenica);
    std::map<std::string, std::set<int>> mapa;
    for(int i=0; i<recenica.length(); i++){
        std::string pomocni;
        int j=0;
        if(!JelMozeURijec(recenica[i])) continue;
        while(JelMozeURijec(recenica[i])){
            j++;
            i++;
        }
        pomocni=recenica.substr(i-j,j);
        if(mapa.count(pomocni)) {
            mapa[pomocni].insert(i-j); 
            continue;
        }
        std::set<int> pomocniskup;
        pomocniskup.insert(i-j);
        mapa.insert(std::pair<std::string, std::set<int>>(pomocni, pomocniskup));
    }
    return mapa;
}

std::set<int> PretraziIndeksPojmova (std::string rijec, std::map<std::string, std::set<int>> mapa){
    std::set<int> skup;
    if(mapa.count(rijec)) skup=mapa[rijec];
    else throw std::logic_error ("Unesena rijec nije nadjena!");
    return skup;
}

    
void IspisiIndeksPojmova(std::map<std::string,std::set<int>> Mapa){
    for(auto it = Mapa.begin(); it!= Mapa.end(); it++){
        auto ispisskup = it->second.begin();
        std::cout<<it->first<<": ";
        int i=0;
        while(ispisskup != it->second.end()){
            i++;
            std::cout<<*ispisskup;
            if(i != Mapa[it->first].size()) std::cout<<",";
            ispisskup++;
        }
        std::cout<<std::endl;
    }
}

int main(){
    std::string recenica;
    std::cout<<"Unesite tekst: ";
    getline(std::cin, recenica);
    std::map<std::string, std::set<int>> Mapa;
    Mapa=KreirajIndeksPojmova(recenica);
    IspisiIndeksPojmova(Mapa);
    for(;;){
        std::cout<<"Unesite rijec: ";
        std::string rijec;
        getline(std::cin, rijec);
        if(rijec==".") break;
        std::set<int> skup;
        try{
            skup=PretraziIndeksPojmova(rijec, Mapa);
            for(auto it=skup.begin(); it!=skup.end(); it++){
                std::cout<<*it<<" ";
            }
        }
        catch(std::logic_error e){
            std::cout<<e.what();
        }
        std::cout<<std::endl;
    }
	return 0;
}