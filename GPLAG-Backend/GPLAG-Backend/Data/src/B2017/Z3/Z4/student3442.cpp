/B2017/2018: Zadaća 3, Zadatak 4
#include <iostream>
#include <list>
#include <string>
#include <vector> 

enum class Boje {Pik, Tref, Herc, Karo}; 
std::list<std::pair<std::Boje, std::string>KreirajSpil()
{
    std::vector<std::Boje> v{Boje::Pik, Boje::Tref, Boje::Herc, Boje::Karo};
    std::list<std::pair<std::Boje, std::string> lista;
    for(int i(0); i < 4; i++)
    {
        for(int j(0); j < 13; j++)
        {
            lista.push_back(std::make_pair(v[i], ))
        }
    }
}

int main ()
{
	return 0;
}
