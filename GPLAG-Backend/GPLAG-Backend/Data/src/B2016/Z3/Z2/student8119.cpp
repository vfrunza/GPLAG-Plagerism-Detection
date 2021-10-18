/B2016/2017: Zadaća 3, Zadatak 2
#include <iostream>
#include <string>
#include <set>
#include <map>
#include <utility>
#include <stdexcept>
#include <iterator>
#include <algorithm>

std::map<std::string, std::set<int>> KreirajIndeksPojmova(std::string s) {
    
    int brojac(0);
    int pozicija(0);
    std::map<std::string, std::set<int>> mapa;
    for(int i=0; i<s.length(); i++) {
        std::string novis;
       // std::set<int> skup;
        if((s[i]>='0' && s[i]<='9') || (s[i]>='A' && s[i]<='Z') || (s[i]>='a' && s[i]<='z') ) brojac++;
        if(i!=0 && (s[i-1]<=47 || (s[i-1]>=58 && s[i-1]<=64) || (s[i-1]>=91 && s[i-1]<=96) || s[i-1]>123)) pozicija=i;
        if(s[i]<=47 || (s[i]>=58 && s[i]<=64) || (s[i]>=91 && s[i]<=96) || s[i]>123 || i==s.length()-1) {
            novis=s.substr(pozicija,brojac);
            for(int i=0; i<s.length(); i++) if(s[i]>=65 && s[i]<=90) s[i]+=32;
        
           brojac=0;
           
           if(novis!="") mapa[novis].insert(pozicija);
    }
  
    }
    
    return mapa;
}

std::set<int> PretraziIndeksPojmova(std::string s, std::map<std::string, std::set<int>> mapa) {
    for(int i=0; i<s.length(); i++) if(s[i]>=65 && s[i]<=90) s[i]+=32;
    auto it(mapa.find(s));
    if(it==mapa.end()) throw std::logic_error("Unesena rijec nije nadjena!");
    std::set<int> skup;
    skup=(*it).second;
    //for(auto x:skup) std::cout<<x<<" ";
    return skup;
    
}

void IspisiIndeksPojmova(std::map<std::string,std::set<int>> mapa) {
     for(auto it=mapa.begin(); it!=mapa.end(); it++)
    {
        std::cout<<(*it).first<<": ";
        auto skup=(*it).second;
        for(auto x=skup.begin(); x!=skup.end(); x++) {
            std::cout<<*x;
            if(x!=(--skup.end())) std::cout<<",";
        }
        std::cout<<std::endl;
    }
}
int main ()
{
    std::string s;
    std::cout<<"Unesite tekst: ";
    std::getline(std::cin,s);
    
    std::map<std::string, std::set<int>> mapa=KreirajIndeksPojmova(s);
    IspisiIndeksPojmova(mapa);

        for(;;) {
            std::cout<<"Unesite rijec: ";
            std::string rijec;
            std::cin>>rijec;
            if(rijec==".") break;
            try{
            auto skup=PretraziIndeksPojmova(rijec,mapa);
            for(auto it: skup) std::cout<<it<<" ";
            std::cout<<std::endl;
        }
    
    catch(std::logic_error greska) {
        std::cout<<greska.what()<<std::endl;
    }
        }
    
	return 0;
}