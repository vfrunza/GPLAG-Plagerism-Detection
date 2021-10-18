/B2016/2017: Zadaća 3, Zadatak 4
#include <iostream>
#include <list>
#include <string>
#include <vector>
#include <set>
#include <iterator>

    std::vector<std::set<std::string>> Razvrstavanje(std::vector<std::string>imena; int n){
        std::vector<std::set<std::string>>djeca;
        std::set<std::string>skup;
        /*int k(imena.size());
        int broj_timovasanajviseigraca(k%n);
        k/n+1;*/
        std::list<std::string>lista;
        for(auto it = imena.begin(); it != imena.end(); it++)
            lista.insert(*it);
        for(auto it = lista.begin(); it != lista.end(); it++){
            if(it == lista.begin()){
                skup.insert(*it);
                int korak_iteracije = (*it).length();
                it = lista.erase(it);
            }
        }
    }
int main ()
{
	return 0;
}