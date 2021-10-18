/B2016/2017: Zadaća 3, Zadatak 2
#include <iostream>
#include <map>
#include <string>
#include <set>
#include <stdexcept>
typedef std::map<std::string, std::set<int>> Map;
bool Znak(char a)
{
    return ((a<'A' || (a>'Z' && a<'a') || a>'z') && (a<'0' || a>'9'));
}
bool VelikoSlovo(char a)
{
    return(a>='A' && a<='Z');
}
Map KreirajIndeksPojmova(std::string tekst)
{
    Map indeksi;
    for(int i=0; i<tekst.size(); i++)
    {
        if((i==0 || Znak(tekst[i-1])) && !Znak(tekst[i]))
        {
            int poc(i);
            while(i!=tekst.size() && !Znak(tekst[i]))
            {
                if(VelikoSlovo(tekst[i])) tekst[i]+=32;
                i++;
            }
            auto rijec(tekst.substr(poc,i-poc));
            std::set<int> skup;
            skup.insert(poc);
            if(!indeksi.count(rijec)) indeksi.insert(std::make_pair(rijec, skup));
            else indeksi[rijec].insert(poc);
        }
        if(i==tekst.size()) break;
    }
    return indeksi;
    
}
std::set<int> PretraziIndeksPojmova(std::string rijec, Map indeksi)
{
    for(int i=0; i<rijec.length(); i++)
        if(VelikoSlovo(rijec[i])) rijec[i]+=32;
    if(!indeksi.count(rijec))   throw std::logic_error("Pojam nije nadjen");
    else return indeksi[rijec];
}
void IspisiIndeksPojmova(Map indeksi)
{
    for(auto it=indeksi.begin(); it!=indeksi.end(); it++)
    {
        std::cout<<it->first<<": ";
        for(auto it2=(it->second).begin(); it2!=(it->second).end(); it2++)
            if(it2==--(it->second).end())  std::cout<<*it2<<std::endl;
            else std::cout<<*it2<<",";
    }
}
int main ()
{
	std::string tekst;
	std::cout<<"Unesite tekst: ";
	std::getline(std::cin, tekst);
	auto indeksi(KreirajIndeksPojmova(tekst));
	IspisiIndeksPojmova(indeksi);
	for(;;)
	{
	    std::string s;
	    std::cout<<"Unesite rijec: ";
	    std::getline(std::cin, s);
	    if(s==".")  return 0;
	    else 
	    {
	        try
	        {
	            auto set(PretraziIndeksPojmova(s,indeksi));
	            for(auto it=set.begin(); it!=set.end(); it++)   std::cout<<*it<<" ";
	            std::cout<<std::endl;
	        }
	        catch(...)
	        {
	            std::cout<<"Unesena rijec nije nadjena!"<<std::endl;
	        }
	    
	    }
	}
}