/B2016/2017: Zadaća 3, Zadatak 2
#include <iostream>
#include <map>
#include <string>
#include <set>
#include <stdexcept>
#include <utility>
#include <iterator>

std::map<std::string, std::set<int>> KreirajIndeksPojmova (std::string s)
{
    std::map<std::string, std::set<int>> mapa;
    int brojac(0);
    int zapamtiI(0);
    
    for(int i=0; i<s.length(); i++)
    {
        std::set<int>skup;
        std::string rijec;
        
        while(s[i]<48 || (s[i]>57 && s[i]<65) || (s[i]>90 && s[i]<97) || s[i]>122) i++;
        rijec="";
        if(i!=s.length()) {
            brojac=i;
            while(((s[i]>=48 && s[i]<=57) || (s[i]>=65 && s[i]<=90) || (s[i]>=97 && s[i]<=122)) && i!=s.length())
            {
                if(s[i]>=65 && s[i]<=90) s[i]+=32;
                rijec.push_back(s[i]);
                i++;
            }
        }
        
        mapa.insert(std::make_pair(rijec,skup));
        
        for(auto it=mapa.begin(); it!=mapa.end(); it++)
        {
            if(rijec==(*it).first) (*it).second.insert(brojac);
        }
        
    }
    
    return mapa;
    
}

std::set<int> PretraziIndeksPojmova (std::string rijec, std::map<std::string, std::set<int>> mapa)
{
    for(int i=0; i<rijec.length(); i++) if(rijec[i]>=65 && rijec[i]<=90) rijec[i]+=32;
    std::set<int>skup;
    auto it(mapa.find(rijec));
    if(it==mapa.end()) throw std::logic_error("Unesena rijec nije nadjena!");
    
    for(auto it1=mapa.begin(); it1!=mapa.end(); it1++)
    {
        if(rijec==(*it1).first) skup=(*it1).second;
    }
    
    return skup;
}

void IspisiIndeksPojmova (std::map<std::string, std::set<int>> mapa)
{
    for(auto it=mapa.begin(); it!=mapa.end(); it++)
    {
        std::cout<<it->first<<": ";
        std::set<int> skupovi=it->second;
        
        for(auto x=skupovi.begin(); x!=skupovi.end(); x++)
        {
            if(x!=(--(skupovi.end())))
            std::cout<<*x<<",";
            else std::cout<<*x;
        }
        std::cout<<"\n";
    }
}
int main ()
{
    std::string recenica;
    
    std::cout<<"Unesite tekst: ";
    std::getline(std::cin, recenica);
    
    std::map<std::string, std::set<int>>mapa;
    
    mapa=KreirajIndeksPojmova(recenica);
    IspisiIndeksPojmova(mapa);
    
    for(;;)
    {
        std::cout<<"Unesite rijec: ";
        std::string rijec;
        std::getline(std::cin, rijec);
        if(rijec==".") break;
        
        try
        {
            auto skup=PretraziIndeksPojmova(rijec,mapa);
            for(auto broj : skup) std::cout<< broj << " ";
            std::cout<<std::endl;
        }
        
        catch(std::logic_error k)
        {
            std::cout<<k.what()<<std::endl;
        }
    }
    
	return 0;
}