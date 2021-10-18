/B2016/2017: Zadaća 3, Zadatak 2
#include <iostream>
#include <string>
#include <map>
#include <set>
#include <iomanip>
#include <utility>
#include <vector>

std::map<std::string, std::set<int>> KreirajIndeksPojmova(std::string tekst) {
    std::map<std::string, std::set<int>> mapa;
    std::set<int> skup, prazni;
   
    for(int i=0; i<tekst.length(); i++) {
        int a=i; std::string pomocni;
        while(((tekst[a]>='a' && tekst[a]<='z') || (tekst[a]>='A' && tekst[a]<='Z') || (tekst[a]>='0' && tekst[a]<='9')) && a!=tekst.length()) {
            if(tekst[a]>='A' && tekst[a]<='Z') tekst[a]=tekst[a]+32;
            pomocni.push_back(tekst[a]); a++;
        }
        //std::cout << "pomocni: " << pomocni << " <<< ";
        if(pomocni.length()>0) {
        auto it(mapa.find(pomocni));
        if(it==mapa.end()) {
            skup.insert(i);
            mapa.insert(std::make_pair(pomocni, skup));
            skup=prazni;
        }
        else {
            it->second.insert(i);
        }
        i=a;
    }
    }
    return mapa;
}

std::set<int> PretraziIndeksPojmova(std::string s, std::map<std::string, std::set<int>> mapa) {
   std::set<int> skup;
   
   auto it(mapa.find(s));
   if(it==mapa.end()) { throw std::logic_error("Unesena rijec nije nadjena!\n"); }
   else {
       skup=it->second;
   }
    return skup;
}

void IspisiIndeksPojmova(std::map<std::string, std::set<int>> mapa) {
    
    for(auto it=mapa.begin(); it!=mapa.end(); it++) {
        std::cout << it->first << ": ";
        int brojac(0), br(0);
        
        for(auto r=it->second.begin(); r!=it->second.end(); r++) brojac++;
        
        for(auto iter = it->second.begin(); iter!=it->second.end() ; iter++) {
            if(br==brojac-1) { std::cout << *iter << std::endl; break; }
            else { std::cout << *iter << ","; br++; }
        }
        //std::cout << it->second << " ";
    }
}

int main () {
    std::string tekst;
    std::cout << "Unesite tekst: ";
    getline(std::cin, tekst);
    
   std::map<std::string, std::set<int>> mapa = KreirajIndeksPojmova(tekst);
    IspisiIndeksPojmova(mapa);
    std::string rijec;
    do {
        std::cout << "Unesite rijec: ";
        getline(std::cin, rijec);
        std::set<int> skup;
        if(rijec==".") break;
        try{
            skup = PretraziIndeksPojmova(rijec, mapa);
            for(auto it: skup) 
             {
                 std::cout << it << " ";
             } std::cout << std::endl;
            
        }
        catch(std::logic_error s) {
            std::cout << s.what(); 
        }
        catch(...) {};
    } 
    while(rijec!=".");
    
	return 0;
} 







