/B2017/2018: Zadaća 3, Zadatak 1
#include <iostream>
#include <vector>
#include <functional>
#include <algorithm>
#include <stdexcept>
#include <cmath>

constexpr double eps = 0.000000001;

using namespace std;

std::function<double(double)>LinearnaInterpolacija(std::vector<std::pair<double,double>> cvorovi)
{

    std::sort(cvorovi.begin(),cvorovi.end(),[](std::pair<double,double> a, std::pair<double,double> b) {
        return a.first<b.first;
    });
    for(int i(0); i < cvorovi.size()-1; i++) {
        for(int j=i+1; j<cvorovi.size(); j++) {
            if(fabs(cvorovi.at(i).first - cvorovi.at(j).first) < eps) {
                throw std::domain_error("Neispravni cvorovi");
            }
        }
    }

    return [cvorovi](double x) {
        if(x < cvorovi.at(0).first || x > cvorovi.at(cvorovi.size()-1).first)
            throw std::range_error("Argument izvan opsega");


        /*int n = cvorovi.size();*/

        for(auto p : cvorovi) {
            if(fabs(p.first-x)<eps)
                return p.second;
        }


        auto iterator(std::upper_bound(cvorovi.begin(),cvorovi.end(),x,[]( double x,std::pair<double,double>par) {
            return par.first>x;
        }));




        int indeks(iterator - cvorovi.begin() - 1);




        double brojnik(cvorovi.at(indeks + 1).second - cvorovi.at(indeks).second);

        double nazivnik(cvorovi.at(indeks+1).first - cvorovi.at(indeks).first);

        return cvorovi.at(indeks).second + (brojnik / nazivnik)*(x - cvorovi.at(indeks).first);
    };
}


std::function<double(double)>LinearnaInterpolacija(std::function<double(double)>f , double xmin, double xmax, double deltax)
{
    if(xmin > xmax || deltax <= 0)
        throw std::domain_error("Nekorektni parametri");

    std::vector<std::pair<double,double>>cvorovi;
    while(xmin < xmax) {
        double t_x,t_y;
        t_x = xmin;
        t_y = f(t_x);
        cvorovi.push_back(std::make_pair(t_x,t_y));
        xmin +=deltax;
    }

    return LinearnaInterpolacija(cvorovi);
}

double funkcija(double x)
{
    return x*x + sin(x);
}

int main ()
{
    std::cout<<"Odaberite opciju (1 - unos cvorova, 2 - aproksimacija): ";
    int opcija(0);
    std::cin>>opcija;




    if(opcija==1) {
        std::cout<<"Unesite broj cvorova: ";
        int broj_cvorova;
        std::cin>>broj_cvorova;
        std::cout<<"Unesite cvorove kao parove x y: ";
        double x,y;
        std::vector<std::pair<double,double>>cvorovi;
        for(int i(0); i < broj_cvorova; i++) {
            std::cin>>x>>y;
            cvorovi.push_back(std::make_pair(x,y));
        }

        std::function<double(double)> f;
        try {
            f = LinearnaInterpolacija(cvorovi);
        }

        catch(std::domain_error e) {
            std::cout<<e.what()<<std::endl;
            return 0;
            
        }


        for(; ;) {

            try {

                std::cout<<"Unesite argument (ili \"kraj\" za kraj): ";
                double argument;
                std::cin>>argument;
                if(!cin) break;
                std::cout<<"f("<<argument<<") = "<<f(argument)<<std::endl;

            }


            catch(std::domain_error e) {
                std::cout<<e.what()<<std::endl;
            } catch(std::range_error e) {
                std::cout<<e.what()<<std::endl;
            }


        }
    }

    else if(opcija == 2) {
        std::cout<<"Unesite krajeve intervala i korak: ";
        double xmin,xmax,deltax;
        std::cin>>xmin;
        std::cin>>xmax;
        std::cin>>deltax;

        std::function<double(double)> f;

        try {
            f = LinearnaInterpolacija(funkcija,xmin,xmax,deltax);
        }

        catch(std::domain_error e) {
            std::cout<<e.what()<<std::endl;
            return 0;

        }

        for(; ;) {
            try {

                std::cout<<"Unesite argument (ili \"kraj\" za kraj): ";
                double argument;
                std::cin>>argument;
                if(!cin) break;
                std::cout<<"f("<<argument<<") = "<<funkcija(argument)<<" fapprox("<<argument<<") = "<<f(argument)<<std::endl;


            }

            catch(std::domain_error e) {
                std::cout<<e.what()<<std::endl;
            } catch(std::range_error e) {
                std::cout<<e.what()<<std::endl;
            }


        }
    }


    return 0 ;
}
