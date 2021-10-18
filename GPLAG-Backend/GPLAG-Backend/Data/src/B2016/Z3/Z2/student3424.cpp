/B2016/2017: Zadaća 3, Zadatak 2
#include <iostream>
#include <string>
#include <map>
#include <set>
#include <stdexcept>

std::map<std::string, std::set<int>> KreirajIndeksPojmova(const std::string &s)
{
    std::map<std::string, std::set<int>> indeks;
    int pocetni_index(0);
    
    for(int i(0); i < s.length(); i++)
    {
        if((s[i] >= 'A' && s[i] <= 'z') || (s[i] >= '0' && s[i] <= '9'))
        {
            pocetni_index = i;
            while(i < s.length() && ((s[i] >= 'A' && s[i] <= 'z') || (s[i] >= '0' && s[i] <= '9')))
              i++;
            
            std::string pojam(s.substr(pocetni_index, i - pocetni_index));
            for(auto &x : pojam) x = tolower(x);
            indeks[pojam].insert(pocetni_index);
        }
    }
    return indeks;
}

std::set<int> PretraziIndeksPojmova(const std::string &s, const std::map<std::string, std::set<int>> &indeks)
{
    auto it(indeks.find(s));
    if(it != indeks.end())
    {
        std::set<int> rez;
        for(auto it2(it->second.begin()); it2 != it->second.end(); it2++)
          rez.insert(*it2);
        return rez;
    }
    throw std::logic_error("Unesena rijec nije nadjena!");
}

void IspisiIndeksPojmova(std::map<std::string, std::set<int>> indeks)
{
    for(auto it(indeks.begin()); it != indeks.end(); it++)
    {
        std::cout << it->first << ": ";
        int i(0);
        for(auto it2(it->second.begin()); it2 != it->second.end(); it2++)
        {
            if(i == (it->second.size() - 1))
              std::cout << *it2 << std::endl;
            else
            {
                std::cout<< *it2 << ",";
                i++;
            }
        }
    }
}


int main ()
{
    std::string tekst;
    std::cout << "Unesite tekst: ";
    std::getline(std::cin, tekst);
    
    auto indeks(KreirajIndeksPojmova(tekst));
    IspisiIndeksPojmova(indeks);
    
    std::string rijec;
    std::cout << "Unesite rijec: ";
    while(std::getline(std::cin, rijec), rijec != ".")
    {
        try
        {
            auto rez(PretraziIndeksPojmova(rijec, indeks));
            for(int n : rez) std::cout << n << " ";
            std::cout << std::endl;
        }
        catch(std::logic_error e)
        {
            std::cout << e.what() << std::endl;
        }
        std::cout << "Unesite rijec: ";
    }
	return 0;
}