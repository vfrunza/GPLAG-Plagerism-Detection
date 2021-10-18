/B2017/2018: Zadaća 3, Zadatak 1
#include <iostream>
#include <utility>
#include <vector>
#include <string>
#include <algorithm>
#include <stdexcept>
#include <cmath>
#include <functional>

const double EPSILON(0.0001);
double MojaFunkcija(double x)
{
    return x*x+std::sin(x);
}

std::pair<double, double> VratiXY(std::vector<std::pair<double, double>> vek, double x)
{
    auto it(std::upper_bound(vek.begin(),vek.end(),std::make_pair(x,0.)));
    it--;
    return *it;
}
std::pair<double, double> VratiX1Y1(std::vector<std::pair<double, double>> vek, double x)
{
    auto it(std::lower_bound(vek.begin(),vek.end(), std::make_pair(x,0.)));
    return *it;
}
std::function<double(double)> LinearnaInterpolacija(std::vector<std::pair<double,double>> vek)
{
    std::sort(vek.begin(), vek.end());
    for(int i(0); i<vek.size()-1; i++)
        if(std::fabs(double(vek.at(i).first)-double(vek.at(i+1).first))<EPSILON)
            throw std::domain_error("Neispravni cvorovi");
    return [vek] (double x) {
        if(x<vek.at(0).first || x>vek.at(vek.size()-1).first) throw std::range_error("Argument izvan opsega");
        std::pair<double,double> parXiYi(VratiXY(vek,x)), parXi1Yi1(VratiX1Y1(vek,x));
        return parXiYi.second+((parXi1Yi1.second-parXiYi.second)/(parXi1Yi1.first-parXiYi.first))*(x-parXiYi.first);
    };
}
std::function<double(double)> LinearnaInterpolacija(std::function<double(double)> funkcija, double xmin, double xmax, double deltax)
{
    if(xmin>xmax || deltax<=0) throw std::domain_error("Nekorektni parametri");
    std::vector<std::pair<double,double>> vektor_parova;
    double pomocni(xmin);
    do {
        vektor_parova.push_back(std::make_pair(pomocni,MojaFunkcija(pomocni)));
        pomocni+=deltax;
    } while(pomocni<=xmax);
    return [vektor_parova] (double x) {
        if(x<vektor_parova.at(0).first || x>vektor_parova.at(vektor_parova.size()-1).first) throw std::range_error("Argument izvan opsega");
        std::pair<double,double> parXiYi(VratiXY(vektor_parova,x)), parXi1Yi1(VratiX1Y1(vektor_parova,x));
        return parXiYi.second+((parXi1Yi1.second-parXiYi.second)/(parXi1Yi1.first-parXiYi.first))*(x-parXiYi.first);
    };
}
int main ()
{
    int opcija;
    std::cout<<"Odaberite opciju (1 - unos cvorova, 2 - aproksimacija): ";
    std::cin>>opcija;
    if(opcija==1) {
        int n;
        std::cout<<"Unesite broj cvorova: ";
        std::cin>>n;
        std::vector<std::pair<double, double>> vektor_parova(n);
        std::cout<<"Unesite cvorove kao parove x y: ";
        for(int i(0); i<n; i++) std::cin>>vektor_parova.at(i).first >>vektor_parova.at(i).second;
        try {
            LinearnaInterpolacija(vektor_parova);
            for(;;) {
                std::cout<<"Unesite argument (ili \"kraj\" za kraj): ";
                double x;
                if(!(std::cin>>x)) {
                    std::cin.clear();
                    std::cin.ignore(10000,'\n');
                    break;
                }
                try {
                    auto f(LinearnaInterpolacija(vektor_parova));
                } catch(std::domain_error domena) {
                    std::cout<< domena.what();
                }
                try {
                    std::cout<<"f("<<x<<") = "<<LinearnaInterpolacija(vektor_parova)(x)<<"\n";
                } catch(std::range_error rang) {
                    std::cout<< rang.what()<<"\n";
                }
            }
        } catch(std::domain_error domena2) {
            std::cout<<domena2.what();
        }
    } else if(opcija==2) {
        std::cout<<"Unesite krajeve intervala i korak: ";
        double xmin,xmax,deltax;
        std::cin>>xmin>>xmax>>deltax;
        try {
            LinearnaInterpolacija(MojaFunkcija, xmin, xmax, deltax);
            for(;;) {
                std::cout<<"Unesite argument (ili \"kraj\" za kraj): ";
                double x;
                if(!(std::cin>>x)) {
                    std::cin.clear();
                    std::cin.ignore(10000, '\n');
                    break;
                }
                try {
                    auto f2(LinearnaInterpolacija(MojaFunkcija, xmin, xmax,deltax));
                    try {
                        std::cout<<"f("<<x<<") = "<<MojaFunkcija(x)<<" fapprox("<<x<<") = "<<f2(x)<<"\n";
                    } catch(std::range_error rang2) {
                        std::cout<<rang2.what()<<"\n";
                    }
                } catch(std::domain_error domena2) {
                    std::cout<<domena2.what()<<"\n";
                }
            }
        } catch(std::domain_error domena12) {
            std::cout<<domena12.what();
        }
    }
    return 0;
}
