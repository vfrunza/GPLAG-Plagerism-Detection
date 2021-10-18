/B2016/2017: Zadaća 3, Zadatak 2
#include <iostream>
#include <string>
#include <stdexcept>
#include <utility>
#include <set>
#include <map>

typedef std::map<std::string, std::set<int>> mapa;

bool ImaRijec(std::string rijec, mapa m){
    if(m.count(rijec) > 0) return true;
    return false;
}

bool Dozvoljeno(char c){
    return ((c >= '0' && c <= '9') || (c >= 'a' && c <= 'z'));
}

void PretvoriUMala(std::string &s){
    for(int i=0;i<s.length();i++)
        if(s[i] >= 'A' && s[i] <= 'Z')
            s[i] = s[i] + 32;
}

std::set<int> NadjiIndexe(std::string tekst, std::string rijec){
    std::set<int> skup;
    for(int i=0; i<tekst.length(); i++){
    std::string rijec1{};
    while(!Dozvoljeno(tekst[i]) && i<tekst.length())i++;   //Preskakanje znakova
    int index(i);
    while(Dozvoljeno(tekst[i]) && i<tekst.length()){
        rijec1.push_back(tekst[i]);
        i++;
        }
    if(rijec1 == rijec) skup.insert(index);
    }
    return skup;
}

mapa KreirajIndeksPojmova(std::string tekst){
    mapa m;
    for(int i=0; i<tekst.length(); i++){
    std::string rijec{};
    while(!Dozvoljeno(tekst[i]) && i<tekst.length()) i++;   //Preskakanje znakova
    while(Dozvoljeno(tekst[i]) && i<tekst.length()){
        rijec.push_back(tekst[i]);
        i++;
        }
    if(rijec == "") continue;               
    if(!ImaRijec(rijec, m)) m.insert({rijec, NadjiIndexe(tekst, rijec)});
    }
   return m; 
}

std::set<int> PretraziIndeksPojmova(std::string rijec, mapa m){
    if(!ImaRijec(rijec, m)) throw std::logic_error("Pojam nije nadjen");
    return m[rijec];
}

int MaxSkupa(std::set<int> skup){
    int max(0);
    for(auto x : skup)
        if(x > max)
            max = x;
    return max;
}

void IspisiIndeksPojmova(mapa m){
    for(auto it = m.begin(); it != m.end(); it++){
        std::cout << it->first << ": ";
        int max(MaxSkupa(it->second));
        for(auto x : it->second){
           if(x != max) std::cout << x << ",";
           else std::cout << x;
        }
        std::cout << std::endl;
    }
}

int main ()
{
    std::string tekst{};
    std::cout << "Unesite tekst: ";
    std::cin.clear();
    std::getline(std::cin, tekst);
    PretvoriUMala(tekst);
    mapa m(KreirajIndeksPojmova(tekst));
    IspisiIndeksPojmova(m);
    std::string rijec{};
    for(;;){
        std::cout << "Unesite rijec: ";
        std::cin.clear();
        std::getline(std::cin, rijec);
        PretvoriUMala(rijec);
        if(rijec == ".")break;
        try{
        std::set<int> skup(PretraziIndeksPojmova(rijec, m));
        for(auto x : skup)
            std::cout << x << " ";
        std::cout << std::endl;
        }catch(std::logic_error cigla){
            std::cout << "Unesena rijec nije nadjena!" << std::endl;
        }
    }
	return 0;
}