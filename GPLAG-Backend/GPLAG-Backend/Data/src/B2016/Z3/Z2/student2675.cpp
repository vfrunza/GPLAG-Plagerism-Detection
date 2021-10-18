/B2016/2017: Zadaća 3, Zadatak 2
#include <iostream>
#include <string>
#include <stdexcept>
#include <map>
#include <set>
#include <algorithm>

std::map<std::string,std::set<int>> KreirajIndeksPojmova(std::string tekst)
{
    std::map<std::string,std::set<int>> mapa;
    for(char &c:tekst) c=tolower(c);
    std::string rijec;
    for(int i=0;i<tekst.length();)
    {
        while(i!=tekst.length()&&!((tekst[i]>='A'&&tekst[i]<='Z')||(tekst[i]>='a'&&tekst[i]<='z')||(tekst[i]>='0'&&tekst[i]<='9'))) i++;
        if(i==tekst.length()) break;
        int n=i;
        while(i!=tekst.length()&&((tekst[i]>='A'&&tekst[i]<='Z')||(tekst[i]>='a'&&tekst[i]<='z')||(tekst[i]>='0'&&tekst[i]<='9')))
            rijec.push_back(tekst[i++]);
        mapa[rijec].insert(n);
        rijec={};
    }
    return mapa;
}

std::set<int> PretraziIndeksPojmova(std::string trazeni,std::map<std::string,std::set<int>> mapa)
{
    for(char &c:trazeni) c=tolower(c);
    if(!mapa.count(trazeni)) throw std::logic_error("Pojam nije nadjen");
    return mapa[trazeni];
}

void IspisiIndeksPojmova(std::map<std::string,std::set<int>> mapa)
{
    for(auto it=mapa.begin();it!=mapa.end();it++)
    {
        std::cout << it->first << ": ";
        for(auto it2=(it->second).begin();it2!=(it->second).end();it2++)
        {
            if(it2!=(it->second).begin()) std::cout << ",";
            std::cout << *it2;
        }
        std::cout << "\n";
    }
}

int main ()
{
    std::cout << "Unesite tekst: ";
    std::string tekst;
    std::getline(std::cin, tekst);
    std::map<std::string,std::set<int>> mapa = KreirajIndeksPojmova(tekst);
    IspisiIndeksPojmova(mapa);
    while(std::cout << "Unesite rijec: ",std::getline(std::cin, tekst),tekst!=".")
    {
        try
        {
            std::set<int> pom=PretraziIndeksPojmova(tekst,mapa);
            for(auto it=pom.begin();it!=pom.end();it++) std::cout << *it <<" ";
            std::cout << "\n";
        }
        catch(std::logic_error)
        {
            std::cout << "Unesena rijec nije nadjena!\n";
        }
    }
	return 0;
}