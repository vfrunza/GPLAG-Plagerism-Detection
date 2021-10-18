#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <set>
#include <stdexcept>

std::string IzbaciSpace(std::string s) {
    std::string string=s+" "; return string;
}

std::vector<std::string> Rijeci(std::string s,std::vector<std::set<int>> &skup) {
    s=IzbaciSpace(s);
    auto iter1(s.begin());
    auto iter2(s.end());
    
    int brojac{0},a{0};
    std::vector<std::string> rijeci;
    while(iter1!=iter2) {
        if((*iter1>='a' && *iter1<='z') || (*iter1>='0' && *iter1<='9')) {
            if((iter1+1)==iter2) {
                std::string rijec=s.substr(a,brojac);
                rijeci.push_back(rijec);
            }
            brojac++;
        }
        else{
            std::string rijec=s.substr(a,brojac); 
            
            int b{0},nadjeno{0};
            if(rijec!="") {
                for(int i=0;i<rijeci.size();i++) {
                    if(rijec==rijeci[i]) {
                        nadjeno=1;
                        b=i; break;
                    }
                }
                std::set<int> temp;
                temp.insert(a);
                
                if(nadjeno==0) {
                    rijeci.push_back(rijec);
                    skup.push_back(temp);
                }
                else skup[b].insert(a);
            }
            a+=(brojac+1); brojac=0; nadjeno=0;
        }
        iter1++;
    }
    return rijeci;
}

std::map<std::string,std::set<int>> KreirajIndeksPojmova(std::string s) {
    for(auto &x:s) x=tolower(x);
    std::vector<std::string> rijeci; std::vector<std::set<int>> skup;
    rijeci=Rijeci(s,skup);
    std::map<std::string,std::set<int>> stranice;
    
    for(int i=0;i<rijeci.size();i++) stranice[rijeci[i]]=skup[i];
    
    return stranice;
}

std::set<int> PretraziIndexPojmova(std::string s,std::map<std::string,std::set<int>> stranice) {
    int nadjeno=0; std::set<int> skup;
    
    for(auto iter=stranice.begin();iter!=stranice.end();iter++) {
        if(s==(iter->first)) {
            skup=iter->second; nadjeno=1;
        }
    }
    if(nadjeno==0) throw std::logic_error("Unesena rijec nije nadjena!");
    return skup;
}

void IspisiIndeksPojmova(std::map<std::string,std::set<int>> stranice) {
    for(auto iter=stranice.begin();iter!=stranice.end();iter++) {
        auto iter3=(iter->second).begin();
        int brojac{0};
        std::cout<<iter->first<<": ";
        
        for(auto iter2=(iter->second).begin();iter2!=(iter->second).end();iter2++) {
            if(brojac==(iter->second).size()-1) std::cout<<*iter2;
            else std::cout<<*iter2<<",";
            iter3++; brojac++;
        }
        std::cout<<std::endl;
    }
}

int main() {
    std::cout<<"Unesite tekst: ";
    std::string s; std::getline(std::cin,s);
    
    std::map<std::string,std::set<int>> stranice;
    stranice=KreirajIndeksPojmova(s);
    IspisiIndeksPojmova(stranice);
    
    while(1) {
        std::cout<<"Unesite rijec: ";
        std::string rijec; std::getline(std::cin,rijec);
        
        if(rijec==".") break;
        std::set<int> brojstranica;
        
        try{
            brojstranica=PretraziIndexPojmova(rijec,stranice);
            
            for(auto iter=brojstranica.begin();iter!=brojstranica.end();iter++)
            std::cout<<*iter<<" ";
            
            std::cout<<std::endl;
        }
        catch(std::logic_error izuzetak) {
            std::cout<<izuzetak.what()<<std::endl;
        }
    }
    return 0;
}







