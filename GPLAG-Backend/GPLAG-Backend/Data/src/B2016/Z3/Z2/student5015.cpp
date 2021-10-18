/B2016/2017: Zadaća 3, Zadatak 2
#include <iostream>
#include <string>
#include <map>
#include <set>
#include <stdexcept>

bool Slovo_Broj(char znak) { return ((znak>='a' and znak<='z') or (znak>='A' and znak<='Z') or (znak>='0' and znak<='9')); }

std::string PretvoriUMala(std::string rijec)
{
    std::string pomocni;
    for (int i=0; i<rijec.length(); i++)
    {
        if (rijec[i]>='A' and rijec[i]<='Z') pomocni.push_back(tolower(rijec[i]));
        else pomocni.push_back(rijec[i]);
    }
    return pomocni;
}

std::map<std::string, std::set<int>> KreirajIndeksPojmova(std::string tekst)
{
    int poc, kraj;
    std::map<std::string, std::set<int>> indeks_pojmova;
    for (int i=0; i<tekst.length(); i++)
    {
        if (Slovo_Broj(tekst[i])) 
        {
            poc=i;
            while (i<tekst.length() and Slovo_Broj(tekst[i])) i++;
            kraj=i;
            std::string rijec=tekst.substr(poc, kraj-poc);
            rijec=PretvoriUMala(rijec);
            indeks_pojmova[rijec].insert(poc);
        }
    }
    return indeks_pojmova;
}

std::set<int> PretraziIndeksPojmova(std::string rijec, std::map<std::string, std::set<int>> indeks_pojmova)
{
    rijec=PretvoriUMala(rijec);
    if (!(indeks_pojmova.count(rijec))) throw std::logic_error("Pojam nije nadjen");
    else return indeks_pojmova[rijec];
}

void IspisiIndeksPojmova(std::map<std::string, std::set<int>> mapa)
{
    for (auto it=mapa.begin(); it!=mapa.end(); it++)
    {
        std::cout << it->first << ": ";
        for (auto i=it->second.begin(); i!=it->second.end(); i++)
        {
            i++;
            auto pomocni=i;
            i--;
            if (pomocni==it->second.end()) std::cout << *i << std::endl;
            else std::cout << *i << ",";
        }
    }
}

int main ()
{
    std::cout << "Unesite tekst: ";
    std::string tekst;
    std::getline(std::cin, tekst);
    std::map<std::string, std::set<int>> mapa;
    mapa=KreirajIndeksPojmova(tekst);
    IspisiIndeksPojmova(mapa);
    for (;;)
    {
        std::cout << "Unesite rijec: ";
        std::string rijec;
        std::getline(std::cin, rijec);
        std::string tackica;
        tackica.push_back('.');
        if (rijec==tackica) break;
        else 
        {
            try 
            {
                std::set<int> skup=PretraziIndeksPojmova(rijec, mapa);
                for (auto x: skup) std::cout << x << " ";
                std::cout << std::endl;
            }
            catch(std::logic_error)
            {
                std::cout << "Unesena rijec nije nadjena!" << std::endl;
            }
        }
    } 
	return 0;
}