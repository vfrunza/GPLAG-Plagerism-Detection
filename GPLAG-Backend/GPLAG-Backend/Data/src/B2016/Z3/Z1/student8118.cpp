/B2016/2017: Zadaća 3, Zadatak 1
//Autotestovi by Enil Pajic (epajic1@etf.unsa.ba)
#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <list>
//std::vector<std::set<std::string>>//
void Razvrstavanje (std::vector<std::string> v, int n) {
    int broj, ostatak;
    broj=v.size()/n;
    ostatak=v.size()%n;
    //std::cout<<broj<<" "<<ostatak;
    std::list<std::string>lista;
    auto it(lista.begin());
    std::list<std::string>::iterator pomocni(lista.begin());
    for (int i=0; i<v.size(); i++) {
        lista.insert(pomocni, v[i]);
        std::cout<<*pomocni;
        pomocni++;
        
    }
    while (it!=lista.end()) {
        std::cout<<*it<<"grg";
        it++;
    }
}
int main ()
{
    std::vector<std::string>djeca(5);
    for (int i=0; i<5; i++) {
        std::cin>>djeca[i];
    }
    int n(3);
    (Razvrstavanje(djeca,n));
    
    
    
	return 0;
}