/B2016/2017: Zadaća 3, Zadatak 2
#include <iostream>
#include <string>
#include <stdexcept>
#include <map>
#include <set>

std::map<std::string,std::set<int>> KreirajIndeksPojmova(std::string ulaz)
{
    for(int e=0;e<ulaz.size();e++)
    {
        if(ulaz[e]<='Z' && ulaz[e]>='A')
        ulaz[e]+=32;
    }
    
    std::map<std::string,std::set<int>> izlaz;
    for(int i=0;i<ulaz.size();i++)
    {
        if(!(  (ulaz[i]<='z' && ulaz[i]>='a') || (ulaz[i]<='Z' && ulaz[i]>='A') || (ulaz[i]<='9' && ulaz[i]>='0') ))
        continue;
        int j(i);
        while(i<ulaz.size() && ((ulaz[i]<='z' && ulaz[i]>='a') || (ulaz[i]<='Z' && ulaz[i]>='A') || (ulaz[i]<='9' && ulaz[i]>='0') || (ulaz[i]<='9' && ulaz[i]>='0')))
        {
            i++;
        }
        std::string konacni=ulaz.substr(j,i-j);
        izlaz[ulaz.substr(j,i-j)];
        izlaz[ulaz.substr(j,i-j)].insert(j);
    }
    return izlaz;
}

std::set<int> PretraziIndeksPojmova(std::string rijec,std::map<std::string,std::set<int>> mapa)
{
    if(mapa.count(rijec)) 
    return mapa[rijec];
    else
    throw std::logic_error("Pojam nije nadjen");
}

void IspisiIndeksPojmova(std::map<std::string,std::set<int>> mapa)
{
    for(std::pair<std::string,std::set<int>> i:mapa)
    {
        std::cout<<i.first<<": ";
        int a(0);
        for(int j:i.second)
        {
            if(!a++)
            {
            std::cout<<j;
            continue;
            }
            else
            std::cout<<","<<j;
        }
        std::cout<<std::endl;
    }
}

int main ()
{
	std::cout<<"Unesite tekst: ";
	std::string budalastina;
	std::getline(std::cin,budalastina);
	std::map<std::string,std::set<int>> mapa;
	mapa=KreirajIndeksPojmova(budalastina);
	IspisiIndeksPojmova(mapa);
	for(;;)
	{
	    std::cout<<"Unesite rijec: ";
	    std::string temp;
	    std::getline(std::cin,temp);
	    if(temp==".")
	    return 0;
	    if(mapa.count(temp))
	    {
	        for(int i:mapa[temp])
	        std::cout<<i<<" ";
	        std::cout<<std::endl;
	    }
	    else
	    std::cout<<"Unesena rijec nije nadjena!"<<std::endl;
	 }
	    return 0;

}



