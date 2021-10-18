/B2016/2017: Zadaća 3, Zadatak 2.


#include <iostream>
#include <string>
#include <set>
#include <map>
#include <utility>
#include <stdexcept>

bool slovo(char a)
{
    if(a >= 48 && a <= 57) return true;
    if(a >= 65 && a <= 90) return true;
    if(a >= 97 && a <= 122) return true;
    return false;
}

std::map<std::string, std::set<int>> KreirajIndeksPojmova(std::string tekst)
{
    std::map<std::string, std::set<int>> mapa;
    std::string rijec;
    int duzina = 0;
    int pocetak = 0;
    for(int i=0; i<tekst.length(); i++)
    {
        if(slovo(tekst.at(i)))
        {
            duzina++;
            if(tekst.at(i) >= 65 && tekst.at(i) <= 90)
            {
                rijec += tekst.at(i) + 32;
            }
            else rijec += tekst.at(i);
        }
        else
        {
            if(duzina > 0)
            {
                auto it = mapa.find(rijec);
                if(it == mapa.end())
                {
                    std::set<int> sett{pocetak};
                    mapa.insert(std::make_pair(rijec, sett));
                    
                }
                else
                {
                    it->second.insert(pocetak);
                }
                rijec.resize(0);
            }
            pocetak = i+1;
            duzina = 0;
        }
        if(i == tekst.length() - 1)
        {
            if(duzina > 0)
            {
                auto it = mapa.find(rijec);
                if(it == mapa.end())
                {
                    std::set<int> sett{pocetak};
                    mapa.insert(std::make_pair(rijec, sett));
                }
                else it -> second.insert(pocetak);
            }
            break;
        }
    }
    return mapa;
}

std::set<int> PretraziIndeksPojmova(std::string rijec, std::map<std::string, std::set<int>> mapa)
{
    auto it = mapa.find(rijec);
    if(it == mapa.end()) throw std::logic_error("Pojam nije nadjen");
    return it->second;
}

void IspisiIndeksPojmova(std::map<std::string, std::set<int>> mapa)
{
    for(auto x : mapa)
    {
        std::cout << x.first << ": ";
        int v = x.second.size();
        int br = 1;
        for(auto y : x.second)
        {
            if(br == v) std::cout << y;
            else std::cout << y << ",";
            br++;
        }
        std::cout << std::endl;
    }
}


int main ()
{
    try
    {
        std::cout << "Unesite tekst: ";
        std::string tekst;
        std::getline(std::cin, tekst);
        auto mapa = KreirajIndeksPojmova(tekst);
        IspisiIndeksPojmova(mapa);
        for(;;)
        {
            std::cout << "Unesite rijec: ";
            std::string rijec;
            std::getline(std::cin, rijec);
            if(rijec == ".") break;
            try
            {
                auto sett = PretraziIndeksPojmova(rijec, mapa);
                for(auto x : sett)
                {
                    std::cout << x << " ";
                }
                std::cout << std::endl;
            }
            catch(std::logic_error e)
            {
                std::cout << "Unesena rijec nije nadjena!\n";
            }
        }
    }
    catch(...)
    {
        return 0;
    }
	return 0;
}