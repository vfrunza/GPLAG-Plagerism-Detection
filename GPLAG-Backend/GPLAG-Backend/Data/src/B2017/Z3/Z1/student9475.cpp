
/B2017/2018: Zadaća 3, Zadatak 1
#include <iostream>
#include <functional>
#include <vector>
#include <utility>
#include <stdexcept>
#include <algorithm>
#include <cmath>

double Funkcija(double x)
{
    return x*x+sin(x);
}

std::function<double(double)> LinearnaInterpolacija(std::vector<std::pair<double,double>> &cvor)
{
    //Provjeravamo ima li prvo onih sa istim prvim elementom
    for(int i=0; i<cvor.size(); i++) {
        double pom(cvor.at(i).first);
        if((count_if(cvor.begin(), cvor.end(), [pom](std::pair<double,double> par) {
        return par.first==pom;0
    }))>1) throw std::domain_error("Neispravni cvorovi");
    }
    std::sort(cvor.begin(), cvor.end());

    return[cvor] (double x) {
        if(x<cvor.at(0).first || x>cvor.at(cvor.size()-1).first) throw std::range_error("Argument izvan opsega");

        //Ako ima neki par koji ima isti prvi element kao "x" odmah vracamo njegovo f(x)
        auto pok(find_if(cvor.begin(), cvor.end(), [x](std::pair<double,double> par) {
            return par.first==x;
        }));
        if(pok!=cvor.end()) return pok->second;

        std::pair<double,double> par(x,0);
        auto gornja_granica(lower_bound(cvor.begin(), cvor.end(), par));
        auto donja_granica(upper_bound(cvor.begin(), cvor.end(), par));
        return (donja_granica-1)->second+((gornja_granica->second-(donja_granica-1)->second)/(gornja_granica->first-(donja_granica-1)->first))*(x-(donja_granica-1)->first);
    };
}

std::function<double(double)> LinearnaInterpolacija(std::function<double(double)> f, double x_min, double x_max, double korak)
{
    if(x_min>x_max || korak<=0) throw std::domain_error("Nekorektni parametri");
    std::vector<std::pair<double,double>> cvor(1);
    cvor.at(0)=std::make_pair(x_min,f(x_min));
    int i=1;
    while(x_min+i*korak<x_max) {
        cvor.resize(i+1);
        cvor.at(i)=std::make_pair(x_min+i*korak,f(x_min+i*korak));
        i++;
    }
    cvor.resize(i+1);
    cvor.at(i)=std::make_pair(x_max,f(x_max));

    return[cvor] (double x) {
        if(x<cvor.at(0).first || x>cvor.at(cvor.size()-1).first) throw std::range_error("Argument izvan opsega");

        //Ako ima neki par koji ima isti prvi element kao "x" odmah vracamo njegovo f(x)
        auto pok(find_if(cvor.begin(), cvor.end(), [x](std::pair<double,double> par) {
            return par.first==x;
        }));
        if(pok!=cvor.end()) return pok->second;

        std::pair<double,double> par(x,0);
        auto gornja_granica(lower_bound(cvor.begin(), cvor.end(), par));
        auto donja_granica(upper_bound(cvor.begin(), cvor.end(), par));
        return (donja_granica-1)->second+((gornja_granica->second-(donja_granica-1)->second)/(gornja_granica->first-(donja_granica-1)->first))*(x-(donja_granica-1)->first);
    };
}

int main ()
{
    try {
        int stanje;
        std::cout << "Odaberite opciju (1 - unos cvorova, 2 - aproksimacija): ";
        std::cin >> stanje;

        if(stanje==1) {
            int br_cvorova;
            std::cout << "Unesite broj cvorova: ";
            std::cin >> br_cvorova;

            std::cout << "Unesite cvorove kao parove x y: ";
            double x, y;
            std::vector<std::pair<double,double>> cvor(br_cvorova);
            for(int i=0; i<br_cvorova; i++) {
                std::cin >> x >> y;
                cvor.at(i)=std::make_pair(x,y);
            }
            auto fun(LinearnaInterpolacija(cvor));

            double argument;
            std::cout << "Unesite argument (ili \"kraj\" za kraj): ";
            while(std::cin >> argument) {
                try {
                    std::cout << "f(" << argument << ") = " << fun(argument) << std::endl;
                } catch(std::range_error izuzetak) {
                    std::cout << izuzetak.what() << std::endl;
                }
                std::cout << "Unesite argument (ili \"kraj\" za kraj): ";
            }
        } else if(stanje==2) {
            double x_min, x_max, korak;
            std::cout << "Unesite krajeve intervala i korak: ";
            std::cin >> x_min >> x_max >> korak;
            auto fun(LinearnaInterpolacija(Funkcija, x_min, x_max, korak));

            double argument;
            std::cout << "Unesite argument (ili \"kraj\" za kraj): ";
            while(std::cin >> argument) {
                try {
                    std::cout << "f(" << argument << ") = " << Funkcija(argument) << " fapprox("  << argument << ") = " << fun(argument) <<  std::endl;
                } catch (std::range_error izuzetak) {
                    std::cout << izuzetak.what() << std::endl;
                }
                std::cout << "Unesite argument (ili \"kraj\" za kraj): ";
            }
        }

    } catch(std::domain_error izuzetak) {
        std::cout << izuzetak.what()<< std::endl;
    }

    return 0;
}

