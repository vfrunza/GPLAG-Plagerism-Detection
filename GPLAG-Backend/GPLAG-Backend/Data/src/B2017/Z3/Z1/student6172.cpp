/B2017/2018: Zadaća 3, Zadatak 1
#include <iostream>
#include <vector>
#include <utility>
#include <stdexcept>
#include <algorithm>
#include <functional>
#include <cmath>
//const double epsilon(0.0000001);
const double epsilon(10e-7);
double f(double x)
{
    return x*x+sin(x);
}
//Rjednaki poredi da li su dva realna broja jednaka
bool RJednaki(double x,double y)
{

    return std::fabs(x-y)<epsilon;

}
//fja kriterija za binarnu pretragu sa upper_bound
bool Kriterij(std::pair<double,double> p,std::pair<double,double> m )
{
    if(RJednaki(p.first,m.first)) return false;
    return p.first<m.first;
}
std::vector<std::pair<double,double>> NapraviCvor(std::function<double(double)>f,double xmin,double xmax,double deltax)
{
    std::vector<std::pair<double,double>>v;
    if(deltax<0 || xmin>xmax  || deltax<epsilon ) throw std::domain_error("Nekorektni parametri");
    //VALJDA NEMA SMISLA NI KAD JE XMIN==XMAX
    if(RJednaki(xmin,xmax)) throw std::domain_error("Nekorektni parametri");
    double pom(xmin);
    while(pom<=xmax) {
        v.push_back({pom,f(pom)});
        pom+=deltax;
    }
    return v;
}
//fja kriterija za sortiranje vektora
bool ManjipoPrvoj(std::pair<double,double>x,std::pair<double,double>y)
{
    if(RJednaki(x.first,y.first)) throw std::domain_error("Neispravni cvorovi");
    return x.first<y.first;
}


std::function<double(double)> LinearnaInterpolacija( std::vector<std::pair<double,double>> v)
{

//ako dva elementa cvora imaju jednake koordinate baca se izuzetak
    for(int i=0; i<v.size(); i++) {
        for(int j=i+1; j<v.size(); j++) {
            //v.at(i) je tipa pair i "pair" podrzava poredjenje na jednakost
            if(v.at(i)==v.at(j)) throw std::domain_error("Neispravni cvorovi");
        }
    }
    std::sort(v.begin(),v.end(),ManjipoPrvoj);
    return [v](double x)->double {

        if(v.size()==0 || v.at(0).first>x || v.at(v.size()-1).first<x) throw std::range_error("Argument izvan opsega");
        if(v.size()==1 && !(RJednaki(x,v.at(0).first))) throw std::range_error("Argument izvan opsega");
        if(RJednaki(x,v.at(v.size()-1).first)) return v.at(v.size()-1).second;
        //potrebno je naci interval[xi,xi+1)tako da je xi<=x<xi+1
        std::pair<double,double>prvi,drugi;
        std::pair<double,double> m={x,0};
        //prvi=(xi,yi) drugi=(xi+1,yi+1)
        //posto upper_bound vraca pokazivac iza elementa koji je manji ili jednak elementu koji trazimo
        //ovom naredbom dobijamo gornju,tj drugi element
        auto idrugi=std::upper_bound(v.begin(),v.end(),m,Kriterij);
        auto iprvi=idrugi-1;
        drugi=*idrugi;
        prvi=*iprvi;
        return prvi.second+((drugi.second-prvi.second)/(drugi.first-prvi.first))*(x-prvi.first);

    };
}

std::function<double(double)> LinearnaInterpolacija(std::function<double(double)>f,double xmin,double xmax,double deltax)
{
    auto v(NapraviCvor(f,xmin,xmax,deltax));
    //Dobijemo sortiran vektor u kojem nema jednakih elemenata
    return LinearnaInterpolacija(v);
}

int main ()
{
    try {


        std::cout<<"Odaberite opciju (1 - unos cvorova, 2 - aproksimacija): ";
        int opcija;
        std::cin>>opcija;
        std::cin.ignore(10000,'\n');
        if(opcija==1) {
            std::cout<<"Unesite broj cvorova: ";
            int n;
            std::cin>>n;
            std::vector<std::pair<double,double>>v(n);
            std::cout<<"Unesite cvorove kao parove x y: ";
            for(int i=0; i<n; i++) {
                double x,y;
                std::cin>>x>>y;
                v.at(i)= {x,y};
            }
            try {
                auto f(LinearnaInterpolacija(v));
                double x;
                for(;;) {
                    std::cout<<"Unesite argument (ili \"kraj\" za kraj): ";
                    std::cin>>x;
                    if(std::cin.peek()!='\n') break;

                    try {

                        std::cout<<"f("<<x<<") = "<<f(x)<<std::endl;
                    } catch(std::range_error poruka) {
                        std::cout<<poruka.what()<<std::endl;
                    }

                }
            } catch(std::domain_error poruka) {
                std::cout<<poruka.what();
            }

        }
        if(opcija==2) {
            std::cout<<"Unesite krajeve intervala i korak: ";
            double xmin,xmax,deltax;
            std::cin>>xmin>>xmax>>deltax;
            std::cin.ignore(10000,'\n');
            try {
                auto v=NapraviCvor(f,xmin,xmax,deltax);

                auto fapprox=LinearnaInterpolacija(f,xmin,xmax,deltax);
                for(;;) {
                    std::cout<<"Unesite argument (ili \"kraj\" za kraj): ";
                    double x;
                    std::cin>>x;
                    if(std::cin.peek()!='\n') break;

                    try {

                        std::cout<<"f("<<x<<") = "<<f(x)<<" fapprox("<<x<<") = "<<fapprox(x)<<std::endl;

                    } catch(std::range_error poruka) {
                        std::cout<<poruka.what()<<std::endl;
                    }

                }

            } catch(std::domain_error poruka) {
                std::cout<<poruka.what();
            }
        }
    } catch(std::domain_error poruka) {
        std::cout<<poruka.what();
    }
    return 0;
}
