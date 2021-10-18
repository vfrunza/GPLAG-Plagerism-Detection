/B2017/2018: Zadaća 3, Zadatak 1
#include <iostream>
#include <algorithm>
#include <stdexcept>
#include <functional>
#include <vector>
#include <cmath>
#include <utility>

// Funkcija pomocu koje provjeravamo da li su dva realna broja jednaka
// Iz dodatka predavanju: "Sokantna prica o realnoj aritmetici"
template<typename Tip>
bool JesuLiJednaki(Tip x, Tip y, double eps=1e-10) {
    if ((x<0 && y>0) || (x>0 && y<0)) return false;
    return std::fabs(x-y)<=eps*(std::fabs(x)+std::fabs(y));
}

std::function<double(double)> LinearnaInterpolacija(std::vector<std::pair<double, double>>cvorovi) {
    for (int i=0; i<cvorovi.size(); i++) {
        for (int j=i+1; j<cvorovi.size(); j++) {
            if (JesuLiJednaki(cvorovi.at(i).first, cvorovi.at(j).first)) {
                throw std::domain_error ("Neispravni cvorovi");
            }
        }
    }
    
    std::sort(cvorovi.begin(), cvorovi.end(), [](std::pair<double, double> parametar1, std::pair<double, double> parametar2){ return (parametar1.first<parametar2.first); });
    
    auto povratna_fun=[cvorovi](double x) {
        if ((x<cvorovi.at(0).first) || (x>cvorovi.at(cvorovi.size()-1).first)) {
            throw std::range_error("Argument izvan opsega");
        }
        std::pair<double, double> par;
        par.first=x; par.second=0;
        if (JesuLiJednaki(x, cvorovi.at(cvorovi.size()-1).first)) return cvorovi.at(cvorovi.size()-1).second;
        if (JesuLiJednaki(x, cvorovi.at(0).first)) return cvorovi.at(0).second;
        
        auto p1(upper_bound(cvorovi.begin(), cvorovi.end(), par, [](std::pair<double, double> parametar1, std::pair<double, double> parametar2) { return (parametar1.first<parametar2.first); }));
        
        auto p2(p1-1);
        auto brojnik(p1->second-p2->second);
        auto nazivnik(p1->first-p2->first);
        return (p2->second+(brojnik/nazivnik)*(x-p2->first));
    };
    return povratna_fun;
}

std::function<double(double)> LinearnaInterpolacija(std::function<double(double)>fun, double Xmin, double Xmax, double Deltax) {
    if ((Xmin>Xmax) || (Deltax<=0)) throw std::domain_error ("Nekorektni parametri");
    std::vector<std::pair<double, double>>pomocni;
    while (Xmin<Xmax) {
        std::pair<double, double>par;
        par.first=Xmin; par.second=fun(Xmin);
        pomocni.push_back(par);
        Xmin+=Deltax;
    }
    return LinearnaInterpolacija(pomocni);
}


int main () {
    try {
        int unos;
        std::cout<<"Odaberite opciju (1 - unos cvorova, 2 - aproksimacija): ";
        std::cin>>unos;
        
        if (unos==1) {
            int broj_cvorova;
            std::cout<<"Unesite broj cvorova: ";
            std::cin>>broj_cvorova;
            std::cout<<"Unesite cvorove kao parove x y: ";
            std::vector<std::pair<double, double>>cvorovi;
            for (int i=0; i<broj_cvorova; i++) {
                double prvi_clan, drugi_clan;
                std::cin>>prvi_clan;
                std::cin>>drugi_clan;
                cvorovi.push_back(std::make_pair(prvi_clan, drugi_clan));
                
                for (int i=0; i<cvorovi.size(); i++) {
                    for (int j=i+1; j<cvorovi.size(); j++) {
                        if (JesuLiJednaki(cvorovi.at(i).first, cvorovi.at(j).first)) {
                            throw std::domain_error ("Neispravni cvorovi");
                        }
                    }
                }
                
            }   
            for(;;) {
                try {
                    double argument;
                    std::cout<<"Unesite argument (ili \"kraj\" za kraj): ";
                    std::cin>>argument;
                    if (!std::cin) break;
                    auto fun(LinearnaInterpolacija(cvorovi));
                    std::cout<<"f("<<argument<<") = "<<fun(argument)<<std::endl;
                } catch (std::range_error izuzetak) {
                    std::cout<<izuzetak.what()<<std::endl;
                }
            }   
        }
    
        else if (unos==2) {
            std::cout<<"Unesite krajeve intervala i korak: ";
            double pocetak, kraj, korak;
            std::cin>>pocetak;
            std::cin>>kraj;
            std::cin>>korak;
        
            for(;;) {
                try {
                    double argument;
                    std::cout<<"Unesite argument (ili \"kraj\" za kraj): ";
                    std::cin>>argument;
                    if (!std::cin) break;
                    auto fun(LinearnaInterpolacija([](double argument) { return argument*argument+std::sin(argument); },pocetak, kraj, korak));
                    std::cout<<"f("<<argument<<") = "<<argument*argument+std::sin(argument)<<" fapprox("<<argument<<") = "<<fun(argument)<<std::endl;
                
                } catch(std::range_error izuzetak1) {
                    std::cout<<izuzetak1.what()<<std::endl;
                }
            }
        }
        else {
            return 0;
        }
    } catch (std::domain_error izuzetak2) {
        std::cout<<izuzetak2.what()<<std::endl;
    }
    
	return 0;
}
