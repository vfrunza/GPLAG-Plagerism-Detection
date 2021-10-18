/B2016/2017: Zadaća 3, Zadatak 1
//Autotestovi by Enil Pajic (epajic1@etf.unsa.ba)
#include <iostream>
#include <vector>
#include <stdexcept>
#include <utility>
#include <functional>

std::function<double (double)>BaricentricnaInterpolacija (std::vector<std::pair<double,double>> cvorovi, int d) {
    if(d<0 || d>=cvorovi.size()) throw std::domain_error ("Nedozvoljen red");
    for(int i(1);i<cvorovi.size()-1;i++) {
        if(cvorovi[i-1].first==cvorovi[i].first) throw std::domain_error ("Neispravni cvorovi");
    }
    return [] () { return }
    
}

BaricentricnaInterpolacija (double fun(double),double x_min,double x_max,double delta_x, int d) {
    if(x_min>x_max || delta_x<=0) throw std::domain_error ("Nekorektni parametri");
}
int main ()
{
    std::cout<<"Odaberite opciju (1 - unos cvorova, 2 - aproksimacija) : ";
    int n;
    std::cin>>n;
    switch(n) {
        case 1:
            std::cout<<"Unesite broj cvorova: ";
            int br;
            std::cin>>br;
            std::cout<<"Unesite cvorove kao parove x y: ";
            std::vector<std::pair<double, double>> cvorovi(br);
            for(int i(0);i<br;i++) {
                std::cin>>cvorovi[i].first>>cvorovi[i].second;
            }
            std::cout<<"Unesite red interpolacije: ";
            int d;
            std::cin>>d;
        case 2:
            std::cout<<"Unesite krajeve intervala i korak: ";
            int poc,kraj,kor;
            std::cin>>poc>>kraj>>kor;
            std::cout<<"Unesite red interpolacije: ";
            int d;
            std::cin>>d;
            
    }
	return 0;
}