/B2016/2017: Zadaća 3, Zadatak 4
#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <list>

std::vector<std::set<std::string>> Razvrstavanje(std::vector<std::string> imena, int n) {
    std::vector<std::set<std::string>> timovi;
    std::list<std::string> lista;
    int brojac(0);
    for(int i=0; i<imena.size(); i++) lista.push_back(imena[i]);
    std::list<std::string>::iterator it(lista.begin());
    while(lista.size()>0) {
        timovi.push_back
        it++;
        if(it==lista.end()) it=lista.begin()
    }
}

int main ()
{   
	return 0;
}