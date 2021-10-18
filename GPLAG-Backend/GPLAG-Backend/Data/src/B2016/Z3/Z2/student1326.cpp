/B2016/2017: Zadaća 3, Zadatak 2
#include <iostream>
#include <string>
#include <map>
#include <set>
#include <utility>
#include <stdexcept>


std::map<std::string, std::set<int>> KreirajIndeksPojmova (std::string s) {
    
    std::map<std::string, std::set<int>> mapa;
    for (int i=0; i<s.length(); i++) {
        if ((s[i]<'0' || s[i]>'9') && (s[i]<'a' || s[i]>'z') && (s[i]<'A' || s[i]>'Z') ) continue;
        std::string s1;
        int pozicija(i);
        for (int j=i; j<s.length(); j++) {
            if (s[j]==' ') break;
            s1+=s[j];
            i++;
        }
        for (int k=0; k<s1.length(); k++) {
            if (s1[k]>='A' && s1[k]<='Z') s1[k]-='A'-'a';
        }
        std::set<int> skup;
        skup.insert(pozicija);
        auto it(mapa.find(s1));
        if (it==mapa.end())
            mapa.insert(std::make_pair(s1, skup));
        else {
            (it->second).insert(pozicija); // it->second čitav skup
        
        }
    
    }
    return mapa;
}
 
std::set<int> PretraziIndeksPojmova(std::string rijec, std::map<std::string, std::set<int>> mapa) {
    std::string s1(rijec);
    for (int k=0; k<s1.length(); k++) {
        if (s1[k]>='A' && s1[k]<='Z') s1[k]-='A'-'a';
    }
    //std::cout << s1;
    auto it(mapa.find(s1));
    if (it==mapa.end()) throw std::logic_error ("Pojam nije nadjen");
    return it->second;
}

void IspisiIndeksPojmova (std::map<std::string, std::set<int>> mapa) {
    for (auto it=mapa.begin(); it!=mapa.end(); it++) {
    std::cout<<it->first<<": ";
    for (auto i=(it->second).begin(); i!=(it->second).end(); i++) {
        auto pom(i);
        pom++;
        if (pom==(it->second).end()) std::cout<<*i;
        else std::cout<<*i<<",";
    }
    std::cout<<std::endl;
    }  
    
}

int main () {
    
    std::cout<<"Unesite tekst: ";
    std::string s;
    std::getline(std::cin,s);
     
    auto mapa(KreirajIndeksPojmova(s));
    IspisiIndeksPojmova(mapa);
    
    for(;;) {
        std::string rijec;
        std::cout<<"Unesite rijec: ";
        std::getline(std::cin, rijec);
        if (rijec==".") break;
        try {
        auto skup(PretraziIndeksPojmova(rijec, mapa));
        for (auto x:skup) {
            std::cout<<x<<" ";
        }
        std::cout<<std::endl;
    }
    catch (std::logic_error) { std::cout<<"Unesena rijec nije nadjena!"<<std::endl;
        
    }
}
   
   
   /* std::string s="abc qwe stsda abc abc dhi qwe hrkw dhi";
    auto mapa(KreirajIndeksPojmova(s));
    
    IspisiIndeksPojmova(mapa); */
	return 0;
}