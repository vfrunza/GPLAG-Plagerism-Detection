/B2017/2018: Zadaća 3, Zadatak 2
#include <iostream>
#include <map>
#include <string>
#include <set>
#include <vector>
#include <algorithm>
#include <stdexcept>
#include <tuple>

typedef std::map<std::string, std::vector<std::string>> Knjiga;

bool dalijerijec(char a)
{
    return((a>='a' && a<='z') || (a>='A' && a<='Z') || (a>='0' && a<='9'));
    
}

std::string Pretvor(std::string s)
{
    std::string s2;
    for(int i(0);i<s.size();i++)
    {
        if(s.at(i)>='A' && s.at(i)<='Z')s2.push_back(tolower(s.at(i)));
        else s2.push_back(s.at(i));
    }
    return s2;
}

std::vector<std::string> rijeci(std::string s)
{
    s=Pretvor(s);
    std::vector<std::string> v;
    int j(0);
    for(int i(0);i<s.size();i++)
    {
        while(s.at(i)==' ' && i!=s.size()-1)i++;
        if(dalijerijec(s.at(i)))
        {
        v.resize(v.size()+1);
        while(dalijerijec(s.at(i)) && i!=s.size()-1)
        {
            
            v.at(j).push_back(s.at(i));
            i++;
            
        }
        if(dalijerijec(s.at(i)) && i==s.size()-1)v.at(j).push_back(s.at(i));
        j++;
        }
    } 
        for(int i(0);i<v.size()-1;i++)
        {
            for(int j(i+1);j<v.size();j++)
            {
                if(v.at(i)==v.at(j))v.erase(v.begin()+j);
            }
        }
    return v;
}
std::vector<int> Podstring(std::string podstring, std::string s)
{
    podstring=Pretvor(podstring);
    s=Pretvor(s);
    std::vector<int> podstringovi;
        for(int i(0);i<s.size();i++)
        {
            for(int j(0);j<podstring.size();j++)
            {
             while(i<s.size() && s.at(i)!=podstring.at(j))i++;
             int brojac(0);
             int k(i);
             while(i<s.size() && j<podstring.size() && s.at(i)==podstring.at(j))
             {
                 brojac++;
                 i++;
                 j++;
             }
             if(brojac==podstring.size() && (i==s.size() || s.at(i)==' ') && (k==0 || s.at(k-1)==' '))
             {
                 podstringovi.push_back(k);
             }
             else break;  
            }
            i--;
        }
        return podstringovi;
}

std::map<std::string, std::set<std::tuple<std::string, int, int>>> KreirajIndeksPojmova(Knjiga k){
    std::map<std::string, std::set<std::tuple<std::string, int, int>>> pojmovi;
    for(auto it=k.begin();it!=k.end();it++)
    {
        for(int i(0);i<it->second.size();i++)
        {
            auto v(rijeci(it->second[i]));
            for(int k(0);k<v.size();k++)
            {
                auto it1(pojmovi.find(v[k]));
                if(it1==pojmovi.end())
                {
                    std::set<std::tuple<std::string, int, int>> hehe;
                    std::tuple<std::string, int, int>hehee;
                    auto a(Podstring(v[k],it->second[i]));
                    for(int h(0);h<a.size();h++)
                    {
                    hehee=std::make_tuple(it->first, i+1, a[h]);
                    hehe.insert(hehee);
                    }
                    
                    pojmovi[v[k]]=hehe;
                }
                else
                {
                    std::tuple<std::string, int, int>hehee;
                    auto a(Podstring(v[k],it->second[i]));
                    for(int h(0);h<a.size();h++)
                    {
                    hehee=std::make_tuple(it->first, i+1, a[h]);
                    it1->second.insert(hehee);
                    }
                }
            }
            
        }
    }
    return pojmovi;
    
}

std::set<std::tuple<std::string, int, int>> PretraziIndeksPojmova(std::string s, std::map<std::string, std::set<std::tuple<std::string, int, int>>> knjigica)
{
    auto it(knjigica.find(s));
    if(it==knjigica.end())throw std::logic_error("Pojam nije nadjen");
    else return it->second;
}

void IspisiIndeksPojmova(std::map<std::string, std::set<std::tuple<std::string, int, int>>> knjigica)
{
    for(auto it(knjigica.begin());it!=knjigica.end();it++)
    {
        std::cout<<it->first<<": ";
        auto it2(it->second.begin());
        int i(0);
        while(i!=it->second.size()-1)
        {
            std::cout<<std::get<0>(*it2)<<"/"<<std::get<1>(*it2)<<"/"<<std::get<2>(*it2)<<", ";
            i++;
            it2++;
        }
        std::cout<<std::get<0>(*it2)<<"/"<<std::get<1>(*it2)<<"/"<<std::get<2>(*it2)<<std::endl;
    }
}

int main ()
{
   std::string poglavlje;
    Knjiga knjizurina;
    while(1)
    {
    std::cout<<"Unesite naziv poglavlja: ";
    std::getline(std::cin, poglavlje);
        if(poglavlje==".")break;
        std::string stranice;
        std::vector<std::string>pomocni;
        int i(1);
        while(1)
        {
            
            std::cout<<"Unesite sadrzaj stranice "<<i<<": ";
            std::getline(std::cin, stranice);
            if(stranice==".")break;
            pomocni.push_back(stranice);
            i++;
        }
        knjizurina[poglavlje]=pomocni;
    }
    std::cout<<std::endl;
    std::cout<<"Kreirani indeks pojmova:"<<std::endl;
    auto pojmovi(KreirajIndeksPojmova(knjizurina));
    IspisiIndeksPojmova(pojmovi);
    while(1)
    {
    std::cout<<"Unesite rijec: ";
    std::string rijec;
    std::getline(std::cin, rijec);
    if(rijec==".")break;
    try {
        auto pretrazivac(PretraziIndeksPojmova(rijec, pojmovi));
        auto it=pretrazivac.begin();
        while(it!=pretrazivac.end())
        {
            std::cout<<std::get<0>(*it)<<"/"<<std::get<1>(*it)<<"/"<<std::get<2>(*it)<<" ";
            it++;
        }
        std::cout<<std::endl;
    }
    catch (std::logic_error) {
        std::cout <<"Unesena rijec nije nadjena!"<<std::endl;
    }
    
    }
    return 0;
}
