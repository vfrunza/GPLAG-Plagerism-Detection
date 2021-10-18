#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <tuple>
#include <set>
#include <stdexcept>

typedef std::map<std::string, std::vector<std:: string>> Knjiga;
typedef std::map<std::string, std::set<std::tuple<std::string, int, int>>> IndeksPojmova;

void Indeksi(IndeksPojmova &mapa, const std::vector<std::string> &rijeci, std::string &pojmovi, const std::string &poglavlje, int stranica)
{
    for(int i=0; i<pojmovi.length();)
    {
        std::string rijec="";
        while((pojmovi[i]<'a' || pojmovi[i]>'z')&&(pojmovi[i]<'0' || pojmovi[i]>'9')&&(pojmovi[i]<'A' || pojmovi[i]>'Z')&&i<pojmovi.length())
        {
            i++;
        }
        while(((pojmovi[i]>='a' && pojmovi[i]<='z')||(pojmovi[i]>='0' && pojmovi[i]<='9')||(pojmovi[i]>='A' && pojmovi[i]<='Z'))&&i<pojmovi.length())
        {
            rijec+=pojmovi[i];
            i++;
        }
        for(int k=0; k<rijec.length(); k++)
        {
            if(rijec[k]>='A' && rijec[k]<='Z') rijec[k]+=('a'-'A');
        }
        auto it(mapa.find(rijec));
        if(it == mapa.end())
        {
            std::set<std::tuple<std::string, int, int>> skup;
            skup.insert(std::make_tuple(poglavlje, stranica, i-rijec.length()));
            mapa.insert(std::make_pair(rijec, skup));
        }
        else
        {
            it->second.insert(std::make_tuple(poglavlje, stranica, i-rijec.length()));
        }
    }
}

void IzdvojiRijeci(std::vector<std::string> &rijeci, const std::string &pojmovi)
{
    for(int i=0; i<pojmovi.length();)
    {
        bool test(false);
        std::string rijec="";
        while((pojmovi[i]<'a' || pojmovi[i]>'z')&&(pojmovi[i]<'0' || pojmovi[i]>'9')&&(pojmovi[i]<'A' || pojmovi[i]>'Z')&&i<pojmovi.length())
        {
            i++;
        }
        while(((pojmovi[i]>='a' && pojmovi[i]<='z')||(pojmovi[i]>='0' && pojmovi[i]<='9')||(pojmovi[i]>='A' && pojmovi[i]<='Z'))&&i<pojmovi.length())
        {
            rijec+=pojmovi[i];
            i++;
        }
        for(int j=0; j<rijeci.size(); j++)
        {
            if(rijeci[j]==rijec) test=true;
        }
        if(!test) rijeci.push_back(rijec);
    }
}

IndeksPojmova KreirajIndeksPojmova(Knjiga knjiga)
{
    IndeksPojmova mapa;
    std::vector<std::string> rijeci;
    for(auto it=knjiga.begin(); it!=knjiga.end(); it++)
    {
        std::vector<std::string> stranice=it->second;
        for(int i=0; i<stranice.size(); i++)
        {
            std::string pojmovi=stranice[i];
            IzdvojiRijeci(rijeci, pojmovi);
        }
    }
    for(int i=0; i<rijeci.size(); i++)
    {
        for(int k=0; k<rijeci[i].length(); k++)
        {
            if(rijeci[i][k]>='A' && rijeci[i][k]<='Z') rijeci[i][k]+=('a'-'A');
        }
    }
    for(auto it=knjiga.begin(); it!=knjiga.end(); it++)
    {
        std::vector<std::string> stranice=it->second;
        for(int i=0; i<stranice.size(); i++)
        {
            std::string pojmovi=stranice[i];
            Indeksi(mapa, rijeci, pojmovi, it->first, i+1);
        }
    }
    return mapa;
}

void IspisiIndeksPojmova(const IndeksPojmova &mapa)
{
    std::cout << "Kreirani indeks pojmova:" << std::endl;
    for(auto it=mapa.begin(); it!=mapa.end(); it++)
    {
        std::cout << it->first << ": ";
        for(auto it2=it->second.begin(); it2!=it->second.end(); it2++)
        {
            std::cout << std::get<0>(*it2) << "/" << std::get<1>(*it2) << "/" << std::get<2>(*it2);
            auto itpom=it2;
            if((++itpom)!=it->second.end() && it->second.size()!=1) std::cout << ", ";
        }
        std::cout << std::endl;
    }
}

std::set<std::tuple<std::string, int, int>> PretraziIndeksPojmova(const std::string &rijec, const IndeksPojmova &mapa)
{
    auto it=mapa.find(rijec);
    if(it==mapa.end())
    {
        throw std::logic_error("Pojam nije nadjen");
    }
    else
    {
        return it->second;
    }
}

int main()
{
    Knjiga knjiga;
    for(;;)
    {
        std::string poglavlje;
        std::cout << "Unesite naziv poglavlja: ";
        std::vector<std::string> stranice;
        std::getline(std::cin, poglavlje);
        if(poglavlje==".") break;
        int i=1;
        for(;;)
        {
            std::cout << "Unesite sadrzaj stranice " << i << ": ";
            std::string unos;
            std::getline(std::cin, unos);
            if(unos==".") break;
            stranice.push_back(unos);
            i++;
        }
        knjiga.insert(std::make_pair(poglavlje, stranice));
    }
    IndeksPojmova mapa=KreirajIndeksPojmova(knjiga);
    std::cout << std::endl;
    IspisiIndeksPojmova(mapa);
    for(;;)
    {
        try
        {
            std::string unos;
            std::cout << "Unesite rijec: ";
            std::getline(std::cin, unos);
            if(unos==".") break;
            std::set<std::tuple<std::string, int, int>> skup=PretraziIndeksPojmova(unos, mapa);
            for(auto it=skup.begin(); it!=skup.end(); it++)
            {
                std::cout << std::get<0>(*it) << "/" << std::get<1>(*it) << "/" << std::get<2>(*it);
                auto itpom=it;
                if((itpom++)!=skup.end()) std::cout << " ";
            }
            std::cout << std::endl;
        }
        catch(std::logic_error e)
        {
            std::cout << "Unesena rijec nije nadjena!" << std::endl;
        }
    }
    return 0;
}
