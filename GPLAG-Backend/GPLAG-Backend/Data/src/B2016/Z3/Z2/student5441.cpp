/B2016/2017: Zadaća 3, Zadatak 2

#include <iostream>
#include <map>
#include <string>
#include <set>
#include <utility>
#include <stdexcept>

std::map<std::string,std::set<int>> KreirajIndeksPojmova(std::string s)
{
    std::map<std::string,std::set<int>> mapa;
    
   int i(0);
    while(i!=s.length())
    {
        if(s[i]>='A' && s[i]<='Z') s[i]+=('a'-'A');
        i++;
    }
    i=0;
    while(i<s.length())
    {
        if(s[i]>='a' && s[i]<='z')
        {
            std::string rijec; std::set<int>skup; int pozicija(i);
            while((s[i]>='A' && s[i]<='Z') || (s[i]>='a' && s[i]<='z'))
            {rijec+=s[i]; i++;}
            auto it(mapa.find(rijec));
            if(it==mapa.end())
            {
                skup.insert(pozicija);
                mapa.insert(std::make_pair(rijec,skup));
            }
            else{
                mapa[rijec].insert(pozicija);
            }
        }
        i++;
    }
    return mapa;
}
std::set<int> PretraziIndeksPojmova(std::string s, std::map<std::string,std::set<int>> mapa)
{
    auto it(mapa.find(s));
    if(it==mapa.end()) throw std::logic_error("Unesena rijec nije nadjena!");
    else return it->second;
}

void IspisiIndeksPojmova(std::map<std::string,std::set<int>> mapa)
{
    for(auto it=mapa.begin(); it!=mapa.end(); it++)
    {
        std::cout<<it->first<<": ";
    for(auto it1(it->second.begin()); it1!=(it->second.end()); it1++) 
    {
        auto itpomoc(it1);
        if(++itpomoc==it->second.end()) std::cout<<*it1;
        else std::cout<<*it1<<",";
    }
    std::cout<<"\n";
    }
}
int main ()
{
    std::string s;
    std::cout<<"Unesite tekst: ";
    std::getline(std::cin, s);
    std::map<std::string,std::set<int>>mapa(KreirajIndeksPojmova(s));
    IspisiIndeksPojmova(mapa);
    std::string rijec;
    for(;;){
    try{
        std::cout<<"Unesite rijec: ";
        std::getline(std::cin, rijec);
        if(rijec==".") return 0;
        std::set<int>skup_za_rijec(PretraziIndeksPojmova(rijec, mapa));
        for(auto x : mapa[rijec]) std::cout<<x<<" ";
        std::cout<<"\n";
    }
    catch(std::logic_error poruka) {std::cout<<poruka.what()<<"\n";}
    }
	return 0;
}