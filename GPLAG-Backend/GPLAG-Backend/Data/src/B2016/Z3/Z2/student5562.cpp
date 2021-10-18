/B2016/2017: Zadaća 3, Zadatak 2
#include <iostream>
#include <string>
#include <map>
#include <set>
#include <utility>

void PretvoriUMala(std::string &rijec)
{
    for (int i = 0; i < rijec.length(); i++)
        if (rijec[i] >= 'A' && rijec[i] <= 'Z')
            rijec[i] += 'a' - 'A';
}

typedef std::map<std::string, std::set<int>> Index;

Index KreirajIndeksPojmova (const std::string &tekst)
{
    Index indeks;
    bool space(true);
    for (int i = 0; i < tekst.length(); i++)
    {
        if (tekst[i] < '0' || (tekst[i] > '9' && tekst[i] < 'A') || (tekst[i] > 'Z' && tekst[i] < 'a') || tekst[i] > 'z')
            space = true;
        else if (space)
        {
            space = false;
            int p(i);
            while (!(tekst[p] < '0' || (tekst[p] > '9' && tekst[p] < 'A') || (tekst[p] > 'Z' && tekst[p] < 'a') || tekst[p] > 'z' ) && p != tekst.length())
                p++;
            std::string rijec(tekst.substr(i, p - i));
            PretvoriUMala(rijec);
            if (!indeks.count(rijec)) indeks.insert(std::make_pair(rijec, std::set<int>{i}));
            else indeks[rijec].insert(i);
        }
    }
    return indeks;
}

std::set<int> PretraziIndeksPojmova(std::string rijec, Index indeks)
{
    PretvoriUMala(rijec);
    for (Index::iterator it = indeks.begin(); it != indeks.end(); it++)
        if (it->first == rijec) return it->second;
    throw std::logic_error("Pojam nije nadjen");
}

void IspisiIndeksPojmova(Index indeks)
{
    for (Index::iterator it1 = indeks.begin(); it1 != indeks.end(); it1++)
    {
        std::cout << it1->first << ": ";
        std::set<int>::iterator it2(it1->second.begin());
        for (int i = 0; i < int(it1->second.size()) - 1; i++){ 
            std::cout << *it2++ << ",";
        }
        std::cout << *it2 << "\n";
    }
}

int main () 
{
    std::string tekst;
    std::cout << "Unesite tekst: ";
    std::getline(std::cin, tekst);
    Index indeks(KreirajIndeksPojmova(tekst));
    IspisiIndeksPojmova(indeks);
    for(;;)
    {   
        std::string rijec;
        std::cout << "Unesite rijec: ";
        std::getline(std::cin, rijec);
        if (rijec == ".") break;
        try
        {
            std::set<int> pozicije(PretraziIndeksPojmova(rijec, indeks));
            for (std::set<int>::iterator it = pozicije.begin(); it != pozicije.end(); it++)
                std::cout << *it << " ";
        }
        catch (std::logic_error)
        {
            std::cout << "Unesena rijec nije nadjena!";
        }
        std::cout << "\n";
    }
    
	return 0;
}