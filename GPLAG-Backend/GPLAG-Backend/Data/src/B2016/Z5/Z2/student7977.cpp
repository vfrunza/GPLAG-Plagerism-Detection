/B16/17 (Zadaća 5, Zadatak 2)
//Autotestovi by Eldar Kurtic (mail: ekurtic3@etf.unsa.ba)
//Za autotestove se obracati *iskljucivo* osobi koja ih pise
#include <iostream>
#include <map>
int main ()
{
    std::map<int,int> mapa;
    mapa.insert(std::make_pair(12, 24));
    mapa.insert(std::make_pair(13, 25));
    auto it(mapa.begin());
    mapa.erase(it);
    it = mapa.begin();
    std::cout << mapa.size() << " " << it->first << " " << it->second << std::endl;
	return 0;
}