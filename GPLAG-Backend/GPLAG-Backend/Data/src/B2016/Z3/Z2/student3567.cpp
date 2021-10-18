/B2016/2017: Zadaća 3, Zadatak 2
#include <iostream>
#include <string>
#include <map>
#include <set>
#include <iterator>
#include <cctype>

std::map<std::string, std::set<int>> KreirajIndeksPojmova(std::string pojmovi)
{
    std::string pomocni;
    std::map<std::string, std::set<int>> povratni;
    int pos;

    for(int i = 0; i < pojmovi.length(); i++)
    {
        pomocni.clear();
        
        while (!std::isalnum(pojmovi[i]) && i < pojmovi.length())
            i++;

        pos = i;

        while(std::isalnum(pojmovi[i]) && i < pojmovi.length())
            i++;

        pomocni = pojmovi.substr(pos, i-pos);
        
        // Pretvori u mala slova
        for (int j = 0; j < pomocni.length(); j++)
            pomocni[j] = std::tolower(pomocni[j]);
        
        povratni[pomocni].insert(pos);
    }
    
    // Pretvori u mala slova
    for (int j = 0; j < pomocni.length(); j++)
        pomocni[j] = std::tolower(pomocni[j]);
    
    if (pomocni.length() > 0) {
        povratni[pomocni].insert(pos);
    }

    return povratni;
}

std::set<int> PretraziIndeksPojmova(std::string rijec, std::map<std::string, std::set<int>> pojmovi)
{
    std::map<std::string, std::set<int>>::iterator it(pojmovi.find(rijec));

    if(it == pojmovi.end())
        throw std::logic_error("Pojam nije nadjen");

    return it->second;
}

void IspisiIndeksPojmova(std::map<std::string, std::set<int>> pojmovi)
{
    std::map<std::string, std::set<int>>::iterator it;
    std::set<int>::iterator it2, it3;
    for(it = pojmovi.begin(); it != pojmovi.end(); it++)
    {
        std::cout << it->first << ": ";
        it3 = it->second.end();
        it3--;
        for(it2 = it->second.begin(); it2 != it->second.end(); it2++)
        {
            if(it2 == it3)
                std::cout << *it2;
            else
                std::cout << *it2 << ",";
        }
        std::cout << std::endl;
    }
}

int main ()
{
    std::string tekst;
    std::cout << "Unesite tekst: ";
    std::getline(std::cin, tekst);
    std::map<std::string, std::set<int>> pojmovi = KreirajIndeksPojmova(tekst);
    IspisiIndeksPojmova(pojmovi);
    while(1)
    {
        std::cout << "Unesite rijec: ";
        std::getline(std::cin, tekst);
        if(tekst == ".")
            return 0;
        try
        {
            std::set<int> setic = PretraziIndeksPojmova(tekst, pojmovi);
            for(std::set<int>::iterator it = setic.begin(); it != setic.end(); it++)
                std::cout << *it << " ";
            std::cout << std::endl;
        }
        catch(...)
        {
            std::cout << "Unesena rijec nije nadjena!" << std::endl;
        }
    }
	return 0;
}