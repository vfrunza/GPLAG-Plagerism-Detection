/B2016/2017: Zadaća 3, Zadatak 1
//Autotestovi by Enil Pajic (epajic1@etf.unsa.ba)
#include <iostream>
#include <functional>
#include <vector>
#include <utility>
#include <stdexcept>
#include <string>

std::function<double(double)> BaricentricnaInterpolacija(std::vector<std::pair<double, double>> v, int d) {
    if(d < 0 || d > v.size()) throw std::domain_error("Nedozvoljen red");
    for(int i = 0; i < v.size(); i++) {
        for(int j = i + 1; j < v.size(); j++) {
            if(v[i].first == v[j].first) throw std::domain_error("Neispravni cvorovi");
        }
    }
    
    
}



int main ()
{
    std::cout << "Odaberite opciju (1 - unos cvorova, 2 - aproksimacija): ";
    int opcija;
    std::cin >> opcija;
    if(opcija == 0) {
        
    }
    else {
        std::cout << "Unesite broj cvorova: ";
        int br_cvorova;
        std::cin >> br_cvorova;
        std::cout << "Unesite cvorove kao parove x y: ":
        std::pair<int, int> cvor;
        for(int i = 0; i < br_cvorova; i++) {
            int prvi, drugi;
            std::cin >> prvi;
            std::cin >> drugi;
            cvor = std::make_pair(prvi, drugi);
        }
        std::cout << "Unesite red interpolacije: ";
        int d;
        std::cin >> d;
        for(;;) {
            std::string pom;
            std::cout << "Unesite argument (ili ""kraj"" za kraj): ";
            std::cin >> pom;
            if(pom == "kraj") break;
            std::cout << "f(" << broj << ") = " << std::endl;
        }
    }
	return 0;
}