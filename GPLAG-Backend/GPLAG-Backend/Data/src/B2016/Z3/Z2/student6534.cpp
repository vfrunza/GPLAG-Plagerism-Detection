/B2016/2017: Zadaća 3, Zadatak 2
#include <iostream>
#include <string>
#include <map>
#include <set>
#include <stdexcept>
#include <cctype>
#include <algorithm>

std::map<std::string,std::set<int>> KreirajIndeksPojmova(std::string s){
    std::map<std::string,std::set<int>> glavna_mapa;
    
    // pretvori u mala slova string
    std::transform (s.begin(), s.end(), s.begin(), std::ptr_fun(tolower));
    auto p(&s[0]);
    for(int i=0;i<s.length();i++){
        if (*p==' ' || *p<'0' || (*p>'9' && *p<'A') || (*p>'Z'&& *p<'a') || *p>'z'){
            p++;
            continue;
        }
        int br(0);
        std::string rijec;
        bool imarijec(false);
        while( p!=(s.length()+&s[0]) and ((*p>='0'&& *p<='9') || (*p>='A'&& *p<='Z') || (*p>='a'&& *p<='z'))){
            p++;
            br++;
            imarijec=true;
        }
        if(imarijec){
        rijec=s.substr(i,br);
        //std::cout << rijec << std::endl;
        if(!glavna_mapa.count(rijec)) 
            glavna_mapa[rijec].insert(i);
        else glavna_mapa[rijec].insert(i);
        }
        i=i+br-1;
    }
    return glavna_mapa;
}

std::set<int> PretraziIndeksPojmova(std::string s, std::map<std::string,std::set<int>> mapa){
    if(!mapa.count(s))
    throw std::logic_error("Unesena rijec nije nadjena!");
    else return mapa[s];
}

void IspisiIndeksPojmova(std::map<std::string, std::set<int>> glavna){
    for(auto it=glavna.begin(); it!=glavna.end(); it++){
        std::cout<<it->first<<": ";
        int brojac(0);
        for(int x:it->second){
           if(brojac==it->second.size()-1)  
                std::cout<<x;
            else{
            std::cout<<x<<",";
            brojac++;
            }
        } 
        std::cout<<std::endl;
    }
}

int main ()
{   std::cout << "Unesite tekst: ";
    std::string tekst;
    std::getline(std::cin,tekst);
    std::map<std::string, std::set<int>> rjesenje(KreirajIndeksPojmova(tekst));
    //ispis rjecnika
    IspisiIndeksPojmova(rjesenje);
    std::string rijec;
    std::string kraj(".");
    do {
        std::cout << "\nUnesite rijec: " ;
        std::getline(std::cin,rijec);
        if(rijec==kraj) break;
        //ispis za tu rijec
        try{
            std::set<int> skup;
           skup=PretraziIndeksPojmova(rijec, rjesenje); 
           for(int x:skup) std::cout<<x<<" ";
        }
        catch (std::logic_error err){
            std::cout << err.what() ;
        }
    }
    while(rijec!=kraj);
	return 0;
}