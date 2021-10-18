/B2016/2017: Zadaća 3, Zadatak 2
#include <iostream>
#include <string>
#include <map>
#include <set>
#include <vector>
#include <stdexcept>

std::map<std::string, std::set<int>> KreirajIndeksPojmova(std::string s)
{
    std::map<std::string, std::set<int>> map;
    char* pok(&s[0]);
    std::vector<std::string> vek;
    std::vector<std::set<int>> set;
    int broj(0), trbroj(0);
    while(pok != &s[s.size()])
    {
        std::string str1, str2;
        while((*pok < 'a' || *pok > 'z') && (*pok < '0' || *pok > '9') && (*pok < 'A' || *pok > 'Z'))
        {
            pok++;
            broj++;
        }
        trbroj = broj;
        while(((*pok >= 'a' && *pok <= 'z') || (*pok >= 'A' && *pok <= 'Z') || (*pok >= '0' && *pok <= '9')) && pok != &s[s.size()])
        {
            str1 = *pok;
            if(str1[0] >= 'A' && str1[0] <= 'Z')
                str1[0] += 32;
            str2 += str1;
            pok++;
            broj++;
        }
        bool postoji(false);
        for(int i = 0; i < vek.size(); i++)
            if(str2 == vek[i])
            {
                postoji = true;
                set[i].insert(trbroj);
                break;
            }
        if(!postoji)
        {
            vek.push_back(str2);
            set.resize(vek.size());
            set[vek.size()-1].insert(trbroj);
        }
    }
    for(int i = 0; i < vek.size(); i++)
        map.insert(std::make_pair(vek[i], set[i]));
    return map;
}

std::set<int> PretraziIndeksPojmova(std::string s, std::map<std::string, std::set<int>> map)
{
    for(auto i = map.begin(); i != map.end(); i++)
        if(i->first == s)
            return i->second;
    throw std::logic_error("Unesena rijec nije nadjena!");
}

void IspisiIndeksPojmova(std::map<std::string, std::set<int>> map)
{
    for(auto i = map.begin(); i != map.end(); i++)
    {
        std::set<int> set1(i->second);
        std::cout<<i->first<<": ";
        int vel(set1.size()), trvel(1);
        for(int x : set1)
        {
            if(trvel == vel)
                std::cout<<x;
            else
            {
                std::cout<<x<<",";
                trvel++;
            }
        }
        std::cout<<std::endl;
    }
}

int main ()
{
    std::cout<<"Unesite tekst: ";
    std::string s;
    std::getline(std::cin, s);
    std::map<std::string, std::set<int>> map(KreirajIndeksPojmova(s));
    IspisiIndeksPojmova(map);
    std::string str;
    do
    {
        try{
        std::cout<<"Unesite rijec: ";
        std::getline(std::cin, str);
        if(str == ".")
            break;
        std::set<int> set(PretraziIndeksPojmova(str, map));
        for(int x : set)
        {
           std::cout<<x<<" ";
        }
        std::cout<<std::endl;
        }
        catch(std::logic_error x)
        {
            std::cout<<x.what()<<std::endl;
        }
    }
    while(str != ".");
	return 0;
}