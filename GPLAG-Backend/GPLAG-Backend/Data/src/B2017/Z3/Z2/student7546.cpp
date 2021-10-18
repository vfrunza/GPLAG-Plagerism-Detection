/B2017/2018: Zadaća 3, Zadatak 2
#include <iostream>
#include <tuple>
#include <string>
#include <map>
#include <vector>

typedef std::map<std::string, std::vector<std::string>> Knjiga;
typedef std::map<std::string, std::set<std::tuple<std::string, int, int>>> Mapa;

Mapa KreirajIndeksPojmova(Knjiga objekat) {
    Mapa trazeni_indeks_pojmova;
    for(auto it = objekat.begin(); it != objekat.end(); it++) { //prolazim kroz poglavlja
        
    }
    
   return Mapa; 
}

int main ()
{
	return 0;
}
