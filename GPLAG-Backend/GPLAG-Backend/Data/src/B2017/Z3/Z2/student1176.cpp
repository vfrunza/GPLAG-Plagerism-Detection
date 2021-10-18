/B2017/2018: Zadaća 3, Zadatak 2
#include <iostream>
#include <string>
#include <map>
#include <set>
#include <vector>

typedef std::map<std::string, std::vector<std::string>> Knjiga;


std::map<> KreirajIndeksPojmova
{
    
}

std::set<int> PretraziIndeksPojmova (atd::string rijec, std::map <std::string, std::set<int>> indeks_pojmova)
{
    for(int i=0; i<rijec.length(); i++)
        if(rijeci[i] >= 'A' && rijeci[i] <= 'Z') rijec[i]+=32;
        
    auto it(indeks_pojmova.find(rijec));
    if(it != indeks_pojmova.end()) return indeks_pojmova[rijec];
    else throw std::logic_error ("Pojam nije nadjen");
}

int main ()
{
	return 0;
}
