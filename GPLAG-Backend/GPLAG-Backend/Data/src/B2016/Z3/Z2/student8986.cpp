/B2016/2017: Zadaća 3, Zadatak 2
#include <iostream>
#include <string>
#include <set>
#include <map>
#include <utility>
#include <stdexcept>

typedef std::map<std::string, std::set<int>> Mapa;

void PretvoriUMala(std::string &s) {
    
    for(int i=0; i<s.length(); i++) {
        if(s[i]>='A' && s[i]<='Z') s[i]=s[i]+32;
    }
    return;
}

Mapa KreirajIndeksPojmova (std::string s) {
    Mapa indeks_pojmova;
    
    for(int i=0; i<s.length(); i++) {
        std::string rijec;
        int pozicija(i);
        while( (s[i]>='A' && s[i]<='Z') || (s[i]>='a' && s[i]<='z') || (s[i]>='0' && s[i]<='9') ) {
            rijec.push_back(s[i]);
            i++;
        }
        if(rijec.length()==0) continue;
        PretvoriUMala(rijec);
        auto it(indeks_pojmova.find(rijec));
        if(it==indeks_pojmova.end()) {
            std::set<int> skup;
            skup.insert(pozicija);
            indeks_pojmova.insert(std::make_pair(rijec,skup));
        }
        else {
            (it->second).insert(pozicija);
        }
    }
    return indeks_pojmova;
}

std::set<int> PretraziIndeksPojmova(std::string rijec, Mapa indeks_pojmova) {
    auto it(indeks_pojmova.find(rijec));
    if(it==indeks_pojmova.end())
        throw std::logic_error ("Pojam nije nadjen");
    else {
        return it->second;
    }
}

void IspisiIndeksPojmova(Mapa indeks_pojmova) {
    auto it(indeks_pojmova.begin());
    
    while(it!=indeks_pojmova.end()) {
        std::cout<<it->first<<": ";
        auto poc((it->second).begin());
        while(poc!=(it->second).end()) {
            if( (++poc)-- == (it->second).end() )
                std::cout<<*poc;
            else
                std::cout<<*poc<<",";
            poc++;
        }
        std::cout<<std::endl;
        it++;
    }
}

int main ()
{
    
    std::string tekst;
    std::cout<<"Unesite tekst: ";
    std::getline(std::cin, tekst);
    Mapa indeks_pojmova(KreirajIndeksPojmova(tekst));
    IspisiIndeksPojmova(indeks_pojmova);
    for(;;) {
        std::string rijec;
        std::cout<<"Unesite rijec: ";
        std::getline(std::cin, rijec);
        if(rijec==".") return 0;
        try {
            std::set<int> skup(PretraziIndeksPojmova(rijec, indeks_pojmova));
            for(auto x : skup) std::cout<<x<<" ";
        }
        catch(...) {
            std::cout<<"Unesena rijec nije nadjena!";
        }
        std::cout<<std::endl;
    }
	return 0;
}