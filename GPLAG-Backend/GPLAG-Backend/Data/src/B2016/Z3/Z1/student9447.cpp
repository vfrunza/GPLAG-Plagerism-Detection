/B2016/2017: Zadaća 3, Zadatak 1
//Autotestovi by Enil Pajic (epajic1@etf.unsa.ba)
#include <iostream>
#include <vector>
#include <utility>
#include <stdexcept>
#include <functional>

std::function<double(double)> BaricentricnaInterpolacija(std::vector<std::pair<double,double>> v, int d) {  // vektor uredjenih parova; parovi su cvorovi interpolacije
    if(d < 0 || d > v.size()) throw std::domain_error("Nedozvoljen red");
    
    for(int i = 0; i < v.size(); i++) {
        for(int j = i + 1; j < v.size(); j++) {
            if(v[i].first == v[j].first) throw std::domain_error("Neispravni cvorovi");
        }
    }
}

std::function<double(double)> BaricentricnaInterpolacija(std::function<double(double)> fun, double xmin, double xmax, double xdel, int d) {
    if(xmin > xmax || xdel <= 0) throw std::domain_error("Nekorektni parametri");
    
}

int main ()
{
    std::cout << "Odaberite opciju (1 - unos cvorova, 2 - aproksimacija): ";
    int a;
    std::cin >> a;
    if(a == 1) {
    std::cout << "Unesite broj cvorova: ";
    int n;
    std::cin >> n;
    std::cout << "Unesite cvorove kao parove: ";
    std::vector<std::pair<double,double>> v(n);
    
    
    std::cout << "Unesite red interpolacije: ";
    int d;
    std::cin >> d;
    
    auto f(BaricentricnaInterpolacija({{1,3}, {2,5}, {4,4}, {5,2}, {7,1}}, 2)); // f ce biti funkcija dobijena baricentr. interpol. reda d=2
    std::cout << f(2.5) << std::endl;
    }
    
    else if(a == 2) {
        
    }
	return 0;
}