/B2016/2017: Zadaća 3, Zadatak 2
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <algorithm>
#include <stdexcept>

bool jest_broj(char c)
{
    if(c>='0' && c<='9') return true;
    return false;
}
bool jest_malo_slovo( char c)
{
    if(c>='a' && c<='z') return true;
    return false;
}
bool jest_veliko_slovo(char c)
{
    if(c>='A' && c<='Z') return true;
    return false;
}

std::string pretvori_u_mala(std::string s)
{
    for(int i(0); i<s.size(); i++) {
        if(s[i]>='A' && s[i]<='Z') s[i]+='a'-'A';
    }
    return s;
}
bool nije_nas_znak(char c){
    if(!jest_broj(c) && !jest_malo_slovo(c) && !jest_veliko_slovo(c) ) return true;
    return false;
}

std::map<std::string, std::set<int>> KreirajIndeksPojmova(std::string indeks)
{
    std::map<std::string, std::set<int>> mapa;
    std::string s(pretvori_u_mala(indeks));
    for(int i(0); i<s.size(); i++){
        std::string rijec;
        std::set<int> skup;
        int brojac(0);
        while(i<s.size() && nije_nas_znak(s[i])) i++;
        while(i<s.size() && (jest_broj(s[i])  || jest_malo_slovo(s[i]) || jest_veliko_slovo(s[i]))){
            rijec+=s[i];
            brojac++;
            i++;
        }
        if(!mapa.count(rijec)) mapa.insert(std::make_pair(rijec, skup));
        mapa[rijec].insert(i-brojac);
    }
    return mapa;
}
std::set<int>PretraziIndeksPojmova(std::string s, std::map<std::string, std::set<int>> &mapa)
{

    auto it1(mapa.begin());
    auto it2(mapa.end());
    while(it1!=it2) {
        if((it1->first) == s) return it1->second;
        it1++;
    }
    throw std::logic_error("Pojam nije nadjen");
}

void IspisiIndeksPojmova(std::map<std::string, std::set<int>> mapa)
{
    auto it1(mapa.begin());
    auto it2(mapa.end());
    while(it1!=it2) {
        auto it3(it1->second.begin());
        std::cout<<it1->first<<": ";
        for(int i(0); i<it1->second.size(); i++) {
            if(i==it1->second.size()-1) std::cout<<*it3;
            else std::cout<<*it3<<",";
            it3++;
        }
        it1++;
        std::cout<<std::endl;
    }
}


int main()
{
    std::string s;
    std::cout<<"Unesite tekst: ";
    std::getline(std::cin, s);
    std::map<std::string, std::set<int>> mapa(KreirajIndeksPojmova(s));
    IspisiIndeksPojmova(mapa);

    for(;;) {
        std::cout<<"Unesite rijec: ";
        std::string temp;
        std::getline(std::cin, temp);
        if(temp==".") return 0;
        try {
            std::set<int> skup(PretraziIndeksPojmova(temp, mapa));
            auto it(skup.begin());
            for(int i(0); i<skup.size(); i++) {
                if(i==skup.size()-1) std::cout<<*it;
                else std::cout<<*it++<<" ";
            }
        }
        catch(...){
            std::cout<<"Unesena rijec nije nadjena!";
        }
        std::cout<<std::endl;
    }

    return 0;
}