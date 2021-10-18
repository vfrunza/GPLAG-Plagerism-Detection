/B2016/2017: Zadaća 3, Zadatak 4
#include <iostream>
#include <list>
#include <vector>
#include <string>
#include <set>

std::vector<std::set<std::string>> Razvrstavanje(std::vector<std::string> vs, int broj_tim){
    std::vector<std::set<std::string>> pov;
    std::list<std::string> Imena;
    for(int i=0;i<vs.size();i++){
        Imena.push_back(vs[i]);
    }
}

int main ()
{
    std::cout << "Unesite broj djece: ";
    int n;
    std::cin >> n;
    std::cout << "Unesite imena djece: ";
    std::vector<std::string> vs;
    std::string ime;
    for(int i=0;i<n;i++){
        std::cin >> ime;
        vs.push_back(ime);
    }
    std::cout << "Unesite broj timova: ";
    int k;
    std::cin >> k;
    for(int i=0;i<k;i++){
        std::cout << "Tim" <<i+1<<" ";
    }
	return 0;
}