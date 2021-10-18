/B2017/2018: Zadaća 3, Zadatak 1
#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#include <cmath>
#include <iterator>
#include <functional>
typedef std::vector<std::pair<double,double>> VektorUredjenihParova;

std::function<double(double)> LinearnaInterpolacija(VektorUredjenihParova Cvorovi)
{
    std::sort(Cvorovi.begin(),Cvorovi.end(),[](std::pair<double,double> x,std::pair<double,double> y) {

        return x.first<y.first;
    });

    for (int i = 0; i < Cvorovi.size()-1; i++) {
        if(Cvorovi.at(i).first==Cvorovi.at(i+1).first) throw std::domain_error("Neispravni cvorovi");
    }


    return [Cvorovi](double x) {
        if(Cvorovi.at(0).first>x || Cvorovi.at(Cvorovi.size()-1).first<x) throw std::range_error("Argument izvan opsega");
        if(x==Cvorovi.at(Cvorovi.size()-1).first) return Cvorovi.at(Cvorovi.size()-1).second;
        std::pair<double,double> par1,par2;



        for(int i=0; i<Cvorovi.size()-1; i++) {
            if(Cvorovi.at(i).first<=x && Cvorovi.at(i+1).first>x) {
                par1=Cvorovi.at(i);
                par2=Cvorovi.at(i+1);
                
            }
        }

        return par1.second+((par2.second-par1.second)/(par2.first-par1.first))*(x-par1.first);
    };
}

std::function<double(double)> LinearnaInterpolacija(double f(double),double xmin,double xmax,double delta)
{
    if(xmin>xmax || delta<=0) throw std::domain_error("Nekorektni parametri");
    VektorUredjenihParova Cvorovi;
    int povecaj(0);
    while(xmin+povecaj*delta<xmax) {
        Cvorovi.push_back(std::make_pair(xmin+povecaj*delta,f(xmin+povecaj*delta)));
        povecaj++;
    }
    return [Cvorovi](double x) {

        std::pair<double,double> par1,par2;

        if(Cvorovi.at(0).first>x || Cvorovi.at(Cvorovi.size()-1).first<x) throw std::range_error("Argument izvan opsega");

        for(int i=0; i<Cvorovi.size()-1; i++) {
            if(Cvorovi.at(i).first<=x && Cvorovi.at(i+1).first>x) {
                par1=Cvorovi.at(i);
                par2=Cvorovi.at(i+1);
            }
            
        return par1.second+((par2.second-par1.second)/(par2.first-par1.first))*(x-par1.first);
    };


}

double funk(double x)
{
    return x*x+std::sin(x);
}

int main ()
{

    std::cout<<"Odaberite opciju (1 - unos cvorova, 2 - aproksimacija): ";
    int UnosOpcije;
    std::cin>>UnosOpcije;
    if(UnosOpcije==1) {

        std::cout<<"Unesite broj cvorova: ";
        int BrojCvorova;
        std::cin>>BrojCvorova;
        std::cout<<"Unesite cvorove kao parove x y: ";
        VektorUredjenihParova v;
        double UnosX,UnosY;
        for (int i = 0; i < BrojCvorova; i++) {
            std::cin>>UnosX>>UnosY;
            std::cin.clear();
            std::cin.ignore(10000,'\n');
            v.push_back(std::make_pair(UnosX,UnosY));
        }



        while(1) {
            try {
                auto f(LinearnaInterpolacija(v));

                std::cout<<"Unesite argument (ili \"kraj\" za kraj): ";
                double Argument;
                try {
                    std::cin>>Argument;

                    if(!(std::cin)) return 0;

                    std::cout<<"f("<<Argument<<") = "<<f(Argument)<<std::endl;
                } catch(std::range_error e) {
                    std::cout<<e.what();
                }
            } catch(std::domain_error e) {
                std::cout<<e.what();
                return 0;
            }
        }

    } else {
        std::cout<<"Unesite krajeve intervala i korak: ";
        double min,max,delta;
        std::cin>>min;
        std::cin>>max;
        std::cin>>delta;



        while(1) {
            try {

                auto f(LinearnaInterpolacija(funk,min,max,delta));
                std::cout<<"Unesite argument (ili \"kraj\" za kraj): ";
                double Argument;

                try {
                    std::cin>>Argument;


                    if(!(std::cin)) return 0;
                    
                    std::cout<<"f("<<Argument<<") = "<<funk(Argument)<<" fapprox("<<Argument<<") = "<<f(Argument)<<std::endl;

                    
                } catch(std::range_error e) {
                    std::cout<<e.what()<<std::endl;
                }
            } catch(std::domain_error e) {
                std::cout<<e.what();
                return 0;
            }
        }
    }

    return 0;
}
