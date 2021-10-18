/B2016/2017: Zadaća 3, Zadatak 2
#include <iostream>
#include <map>
#include <string>
#include <utility>
#include <algorithm>
#include <set>

typedef std::map<std::string, int> Pojmovi;

Pojmovi KreirajIndeksPojmova (std::string s)
{
    Pojmovi mapa;
    int skup;
    //std::string novi;
    
    // for (int i(0); i<s.length(); i++)
    // {
    //     novi = s;
    //     for (;;)
    //     {
    //         int x;
    //         skup.insert(x);
    //     }
    //     mapa.insert(std::make_pair(s,skup));
    // }
    mapa.insert(std::make_pair(s,skup));
    return mapa;
}

bool PretraziIndeksPojmova (std::string s, Pojmovi mapa)
{
    bool pojam(false);
    std::string novi;
    int pocetak(0), kraj(s.size());
    while (pocetak<kraj)
    {
        while (pocetak<kraj && s.at(pocetak) == ' ') novi+=s.at(pocetak++);
        std::string index;
        while (pocetak<kraj && s.at(pocetak) != ' ') index+=s.at(pocetak++);
        auto it = mapa.find(index);
        if (it != mapa.end())
        {
            novi += it->second;
            pojam = true;
        }
        //else novi+=index;
    }
    return pojam;
}
void IspisiIndeksPojmova (Pojmovi mapa)
{
    std::string s;
    mapa = KreirajIndeksPojmova(s);
    for (auto it = mapa.begin(); it != mapa.end(); it++)
        {
            std::cout << it->first << ": " << it->second << std::endl;
        }
}

int main ()
{
    std::cout << "Unesite tekst: ";
    std::string s;
    std::getline (std::cin, s);
    
    Pojmovi kreiraj = KreirajIndeksPojmova(s);
    
    IspisiIndeksPojmova(KreirajIndeksPojmova(s));
    
    std::string rijec;
    do
    {
        std::cout << "Unesite rijec: ";
        std::getline (std::cin, rijec);
        std::cout << std::endl;
    }while (rijec != ".");
    
    if (PretraziIndeksPojmova(s, kreiraj)) 
    {
        for (auto it = kreiraj.begin(); it != kreiraj.end(); it++)
        {
            std::cout << it->second << std::endl;
        }
    }
    else 
    {
        std::cout << "Unesena rijec nije nadjena!";
    }
    
	return 0;
}