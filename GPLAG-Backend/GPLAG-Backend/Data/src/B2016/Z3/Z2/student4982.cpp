/B2016/2017: Zadaća 3, Zadatak 2
#include <iostream>
#include <string>
#include <set>
#include <map>
#include <stdexcept>
#include <utility>

void PretvoriuMala(std::string &s)
{
    for(int i=0;i<s.length();i++)
    {
        if(s[i]>='A' && s[i]<='Z') s[i]+='a' - 'A';
    }
}

bool Slovo(char c)
{
    if((c>'9' && c<'A') || c<'0' || (c>'Z' && c<'a') || c>'z') return false;
    else return true;
}

std::map<std::string, std::set<int>> KreirajIndeksPojmova(std::string s)
{
    std::map<std::string, std::set<int>> pojmovi;
    int poc=0, kraj=0;
    while(poc<s.length())
    {
        while(Slovo(s[poc])==false && poc<s.length()) poc++;
        if(poc==s.length()) break;
        kraj=poc;
        while(Slovo(s[kraj])==true && kraj<s.length()) kraj++;
        std::string temp=s.substr(poc,kraj-poc);
        PretvoriuMala(temp);
        auto ite=pojmovi.find(temp);
        if(ite==pojmovi.end()) pojmovi.insert(std::make_pair(temp,std::set<int>({poc})));
        else pojmovi.find(temp)->second.insert(poc);
        poc=kraj;
    }
    return pojmovi;
}

std::set<int> PretraziIndeksPojmova(std::string s, std::map<std::string, std::set<int>> mapa)
{
    PretvoriuMala(s);
    auto it=mapa.find(s);
    if(it==mapa.end()) throw std::logic_error("Pojam nije nadjen");
    else return mapa.find(s)->second;
}

void IspisiIndeksPojmova(std::map<std::string, std::set<int>> mapa)
{
    for(auto it=mapa.begin();it!=mapa.end();it++)
    {
        std::cout<<it->first<<": ";
        auto it2=it->second.begin(), ittemp=it2;
        while(ittemp!=it->second.end()) ittemp++;
        std::advance(ittemp,-1);
        while(it2!=ittemp)
        {
            std::cout<<*it2<<",";
            it2++;
        }
        std::cout<<*it2<<std::endl;
    }

}

int main ()
{
    std::cout<<"Unesite tekst: ";
    std::string s;
    std::getline(std::cin, s);
    std::map<std::string, std::set<int>> indexx=KreirajIndeksPojmova(s);
    IspisiIndeksPojmova(indexx);
    while (1)
    {
        std::cout<<"Unesite rijec: ";
        std::string s2;
        std::getline(std::cin,s2);
        if(s2==".") break;
        try
        {
            std::set<int> skupp=PretraziIndeksPojmova(s2,indexx);
            for(auto itee=skupp.begin();itee!=skupp.end();itee++) std::cout<<*itee<<" ";
            std::cout<<std::endl;
        }
        catch(std::logic_error e)
        {
            std::cout<<"Unesena rijec nije nadjena!"<<std::endl;
        }
        
    }
	return 0;
}