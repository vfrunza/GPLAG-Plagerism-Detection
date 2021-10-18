/B2017/2018: Zadaća 3, Zadatak 2
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <cctype>
#include <stdexcept>
#include <tuple>
#include <iterator>
#include <set>
 

typedef std::map<std::string, std::vector<std::string>> Knjiga;
typedef std::map<std::string, std::vector<std::tuple<std::string, int, int>>> Mapa;

bool JeLiZnakDobar(char c)
{
    if((std::tolower(c) >= 'a' && std::tolower(c) <= 'z') || (c >= '0' && c <= '9') || (std::tolower(c) >= 'A' && std::tolower(c) <= 'Z'))
        return true;
    return false;
}

Mapa KreirajIndeksPojmova(Knjiga tekst)
{
    Mapa m;
    for(auto it = tekst.begin(); it != tekst.end(); it++)
    {
        //std::cout << "knjiga" << std::endl;
        int pozicija;
            for(int i = 0; i < it->second.size(); i++)
            {
                for(int j = 0; j < it->second[i].length(); j++)
                {
                    //std::string pom;
                    if(JeLiZnakDobar(it->second[i][j]))
                    {
                        pozicija = j;
                        std::string pom;
                        while(j < it->second[i].length() && JeLiZnakDobar(it->second[i][j]))
                            pom.push_back(it->second[i][j++]);
                        //if(!m.count(pom))    
                            m[pom].push_back(std::make_tuple(it->first, i+1, pozicija));
                    }
                    //m[pom].push_back(std::make_tuple(it->first, i+1, pozicija));
                }
            }
    }
    return m;
}

std::set<int> PretraziIndeksPojmova(std::string s, Mapa m)
{
    std::set<int> skup;
    if(!m.count(s)) 
        throw std::logic_error("Pojam nije nadjen");
    auto vec = m[s];
    for(int i=0; i<vec.size(); i++)
        skup.insert(std::get<2>(vec[i]));
    return skup;
}

void IspisiIndeksPojmova(Mapa m)
{    
    for(auto it = m.begin(); it != m.end(); it++)
    {
        
        auto vel(it->second.size());
        std::cout << it->first << ": ";
        int brojac(0);
        for(auto it2 = it->second.begin(); it2 != it->second.end(); it2++)
        {
            if(brojac++ == vel-1)
                std::cout << std::get<0>(*it2) << "/" << std::get<1>(*it2) << "/" << std::get<2>(*it2);
            else std::cout << std::get<0>(*it2) << "/" << std::get<1>(*it2) << "/" << std::get<2>(*it2) << ", ";
        }
        std::cout << std::endl;
    }
}

int main()
{
    try
    {
        Knjiga t;
        std::string poglavlje;
            std::cout << "Unesite naziv poglavlja: ";
            std::getline(std::cin, poglavlje);
            int i(1);
            std::vector<std::string> vektorstringova;
            while(1)
            {   
               std::cout << "Unesite sadrzaj stranice " << i << ": ";
               std::string stranica;
               std::getline(std::cin, stranica);
               if(stranica == ".")
               {
                   t[poglavlje] = vektorstringova;
                   std::cout << "Unesite naziv poglavlja:\n";
                   std::getline(std::cin, poglavlje);
                   if(poglavlje == ".") {
                       vektorstringova.clear();
                       break;
                   }
               }
               vektorstringova.push_back(stranica);
                i++;
            }
        auto tekst = KreirajIndeksPojmova(t);
        std::cout << "Kreirani indeks pojmova:" << std::endl;
        IspisiIndeksPojmova(tekst);
        auto it = tekst.begin();
        while(1)
        {
            std::string s;
            std::cout << "Unesite rijec: ";
            std::getline(std::cin, s);
            if(s == ".") break;
            if(!tekst.count(it->first))
                std::cout << "Unesena rijec nije nadjena!" << std::endl;
            else
            {
                auto setic = PretraziIndeksPojmova(s, tekst);
                for(auto k : setic) std::cout << k << " ";
                std::cout << std::endl;
            }
            
        }
    }
    catch (std::logic_error e)
    {
        std::cout << e.what() << std::endl;
    }
    
    return 0;
}
