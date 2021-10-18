/B2016/2017: Zadaća 3, Zadatak 2
#include <iostream>
#include <string>
#include <map>
#include <set>
#include <stdexcept>
typedef std::map<std::string, std::set<int>> Mapa;

Mapa KreirajIndeksPojmova (std::string p){
    std::string s=p;
    Mapa mapa;
    for(int i=0; i<s.length(); i++){
        if(s[i]<=90 && s[i]>=65) s[i]+=32;
        if(s[i]<48 || (s[i]>57 && s[i]<65) || (s[i]>90 && s[i]<97) || s[i]>122) s[i]=46;
    }
    int j(0);
    for(int i=j; i<(int)s.length(); i++){
        std::string rijec;
        while (s[j]==46 && j<s.length()) j++;
        while (s[j]!=46 && j<s.length()) rijec.push_back(s[j]), j++;
        auto it (mapa.find(rijec));
        //std::cout << j-(int)rijec.length() << std::endl;
        if(it!=mapa.end()) it->second.insert(j-(int)rijec.length());
        else {
            std::set<int> skup;
            skup.insert(j-(int)rijec.length());
            auto par = std::make_pair(rijec,skup) ;
            if(rijec.length()!=0)
            mapa.insert(par);
        }
        if(j==(int)s.length()) break;
    }
    return mapa;
}

void IspisiIndeksPojmova (const Mapa &mapa){
    auto it = mapa.begin();
    
    while ( it != mapa.end()) {
        std::cout << it->first <<": " ;
        auto skup_it(it->second.begin());
        
        for(int i=0; i<it->second.size(); i++) {
            std::cout << *skup_it ;
            skup_it++;
            if(i!=it->second.size()-1) std::cout << ",";
        }
        std::cout << std::endl;
        it++;
    }
}

std::set<int> PretraziIndeksPojmova(std::string s, const Mapa &m){
    for(int i=0; i<s.length(); i++){
        if(s[i]<=90 && s[i]>=65) s[i]+=32;
    }
    auto it(m.find(s));
    if(it==m.end()) throw std::logic_error ("Pojam nije nadjen");
    return it->second;
}

int main ()
{
    std::string recenica;
    std::cout << "Unesite tekst: ";
    std::getline(std::cin, recenica);
    auto m(KreirajIndeksPojmova(recenica));
    IspisiIndeksPojmova(m);
    std::string rijec;
    
    while (1) {
        std::cout << "Unesite rijec: " ;
        std::getline(std::cin, rijec);
        if(rijec==".") break;
        try{
            std::set<int> s(PretraziIndeksPojmova(rijec, m));
            auto skup_it=s.begin();
            for(int i=0; i<s.size(); i++) {
                std::cout << *skup_it ;
                skup_it++;
                if(i!=s.size()-1) std::cout << " ";
            }
            std::cout << std::endl;
        }
        catch(std::logic_error e){
            std::cout << "Unesena rijec nije nadjena!" << std::endl;
        }
    }

    return 0;
}