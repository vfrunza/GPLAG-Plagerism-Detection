/B2016/2017: Zadaća 3, Zadatak 2


#include <iostream>
#include <map>
#include <string>
#include <set>
#include <stdexcept>
#include <vector>

std::map<std::string, std::set<int>> KreirajIndeksPojmova(std::string tekst)
{
    std::map<std::string, std::set<int>> nova_mapa;
    int i(0), br_el = tekst.size();
    bool razmak(true);
    
    for(int j = 0; j < tekst.length(); ++j)
        if(tekst.at(j) >= 'A' && tekst.at(j) <= 'Z')
           tekst.at(j) += 32;
    std::string rijec;
    int pozicija;
    while(i < br_el)
    {
        if(!((tekst.at(i) >= 'a' && tekst.at(i) <= 'z') || (tekst.at(i) >= 'A' && tekst.at(i) <= 'Z') || (tekst.at(i) >= '0' && tekst.at(i) <= '9')))
              razmak = true;
        else if(razmak)  
        {
            razmak = false;
            pozicija = i;

            while(pozicija < br_el && ((tekst[pozicija] >= 'a' && tekst[pozicija] <= 'z') || (tekst[pozicija] >= 'A' && tekst[pozicija] <= 'Z') || (tekst[pozicija] >= '0' && tekst[pozicija] <= '9')))
                pozicija++;
            
            rijec = tekst.substr(i, pozicija - i);
            nova_mapa[rijec].insert(i);
        }
        i++;
        
    }
    
    
    return nova_mapa;
}

std::set<int> PretraziIndeksPojmova(std::string rijec, std::map<std::string, std::set<int>> mapa)
{
    std::set<int> pozicije;
    
    if(!mapa.count(rijec))
       throw std::logic_error("Unesena rijec nije nadjena!");
    
    for(auto it = mapa.begin(); it != mapa.end(); ++it)
        if(rijec == (it->first))
           pozicije = it->second;
       
    return pozicije;
}

void IspisiIndeksPojmova(std::map<std::string, std::set<int>> mapa)
{
    auto it = mapa.begin();
    while(it != mapa.end())
    {
        std::cout << it->first << ": ";
        auto iter = (it->second).begin();
        int a(0);
        for(auto it1 = (it->second).begin(); it1 != (it->second).end(); it1++)
           {
               a++;
              iter++;
              if(a == (it->second).size())
                 std::cout << *it1;
              else
                 std::cout << *it1 << ",";
           }
        std::cout << std::endl;   
        it++;
    }
}
int main ()
{
    std::cout << "Unesite tekst: ";
    std::string tekst;
    std::getline(std::cin, tekst);
    std::map<std::string, std::set<int>> mapa = KreirajIndeksPojmova(tekst);
    IspisiIndeksPojmova(mapa);
    
    for(;;)
    {
        std::cout << "Unesite rijec: ";
        std::string rijec, tacka(".");
        std::getline(std::cin, rijec);
        if(rijec == tacka)
           break;
        try
        {
            std::set<int> poz = PretraziIndeksPojmova(rijec,mapa);
            for(auto i = poz.begin(); i != poz.end(); i++)
                std::cout << *i << " ";

            std::cout << std::endl;
        }
        catch(std::logic_error iz)
        {
            std::cout << iz.what() << std::endl;
        }
    }
    
	return 0;
}