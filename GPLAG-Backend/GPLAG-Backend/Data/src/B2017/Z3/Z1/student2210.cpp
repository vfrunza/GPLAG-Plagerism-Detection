/B2017/2018: Zadaća 3, Zadatak 1
#include <iostream>
#include <vector>
#include <utility>
#include <functional>
#include<algorithm>
#include <cmath>

int Uporedi (std::vector<std::pair<double,double>> V)
{
    for(int i=0; i<V.size()-1; i++) {
        for(int j=i+1; j<V.size(); j++) {
            if(V[i].first==V[j].first)
                return 1;
        }
    }
    return 0;
}

std::function<double(double)>  LinearnaInterpolacija(std::vector<std::pair<double,double>> vector)
{
    //Sortiranje vektora parova:
    std::sort(vector.begin(),vector.end());

    //Provjera da li ima istih first iz parova
    if(Uporedi(vector))
        throw std::domain_error("Neispravni cvorovi");

//vracanje funkcije koja racuna formulu...
    return ([vector](double argument) {

        if(argument<vector[0].first || argument>vector[vector.size()-1].first)
            throw std::range_error("Argument izvan opsega");
        //sve uslove ispitat ako radi sve udure ide ovo:
        auto pocNaParXiYi(std::lower_bound(vector.begin(),vector.end(),argument,
        [](std::pair<double,double> x, double argument ) {
            return x.first<argument;
        }));

        return((*(pocNaParXiYi-1)).second+(((*pocNaParXiYi).second-(*(pocNaParXiYi-1)).second)/((*pocNaParXiYi).first-(*(pocNaParXiYi-1)).first))*((argument-(*(pocNaParXiYi-1)).first)));

    });
}
std::function<double(double)> LinearnaInterpolacija(double f(double),double Xmin,double Xmax,double deltaX)
{
    if(Xmin>Xmax || deltaX<=0)
        throw std::domain_error("Nekorektni parametri");
    std::vector<std::pair<double,double>> vector;
    std::pair<double,double> P;
    double i=1;
    double a=Xmin;

//kreiranje vektora parova
    while(a<Xmax) {
        double clan=Xmin+i*deltaX;
        P.first=clan;
        P.second=f(clan);

        vector.push_back(P);

        a+=deltaX;
        i++;
    }

//vracanje funkcije koja racuna formulu...
    return ([vector](double argument) {

        if(argument<vector[0].first || argument>vector[vector.size()-1].first)
            throw std::range_error("Argument izvan opsega");
        //sve uslove ispitat ako radi sve udure ide ovo:
        auto pocNaParXiYi(std::lower_bound(vector.begin(),vector.end(),argument,
        [](std::pair<double,double> x, double argument ) {
            return x.first<argument;
        }));

        return((*(pocNaParXiYi-1)).second+(((*pocNaParXiYi).second-(*(pocNaParXiYi-1)).second)/((*pocNaParXiYi).first-(*(pocNaParXiYi-1)).first))*((argument-(*(pocNaParXiYi-1)).first)));

    });
}
double funkcija(double x)
{
    return(x*x+sin(x));

}
int main ()
{

    int br;
    std::  cout<<"Odaberite opciju (1 - unos cvorova, 2 - aproksimacija): ";
    std::cin>>br;
    if(br==1) {
        int brCvorova;
        std::cout<<"Unesite broj cvorova: ";
        std::cin>>brCvorova;
        std::vector<std::pair<double,double>> V;
        std::pair<double,double> PAR;
        std::cout<<"Unesite cvorove kao parove x y: ";
        for(int i=0; i<brCvorova; i++) {
            double x,y;
            std::cin>>x>>y;
            PAR.first=x;
            PAR.second=y;
            V.push_back(PAR);

        }

        double arg;
        while(1<2) {
            try {
                auto f=LinearnaInterpolacija(V);
                std::cout<<"Unesite argument (ili \"kraj\" za kraj): ";
                std::cin>>arg;
                if(!arg)
                    return 0;
                else {
                    try {
                        auto f=LinearnaInterpolacija(V);
                        std::cout<<"f("<<arg<<") = "<<f(arg)<<std::endl;
                    } catch(std::range_error r) {
                        std::cout<<r.what()<<std::endl;
                        continue;
                    }


                }
            } catch(std::domain_error r) {
                std::cout<<r.what();
                return 0;
            }
        }
    }

    else if(br==2) {
        int poc,kraj;
        double korak,arg;
        std::cout<<"Unesite krajeve intervala i korak: ",
                 std::cin>>poc>>kraj>>korak;
        while(1<2) {
            std::cout<<"Unesite argument (ili \"kraj\" za kraj): ";
            std::cin>>arg;
            if(!arg)
                return 0;
            else {
                try {
                    auto f=LinearnaInterpolacija(funkcija,poc,kraj,korak);
                    std::cout<<"f("<<arg<<") = "<<funkcija(arg)<<" fapprox("<<arg<<") = "<< f(arg)<<std::endl;
                } catch(std::domain_error r) {
                    std::cout<<r.what()<<std::endl;
                    continue;
                } catch(std::range_error r) {
                    std::cout<<r.what()<<std::endl;
                    continue;
                }

            }
        }
    }


    return 0;

}
