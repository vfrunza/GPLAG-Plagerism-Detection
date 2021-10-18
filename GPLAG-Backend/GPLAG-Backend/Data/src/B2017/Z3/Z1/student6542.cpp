/B2017/2018: Zadaća 3, Zadatak 1
#include <iostream>
#include <functional>
#include <vector>
#include<utility>
#include <algorithm>
#include <stdexcept>
#include <cmath>


double funkcija (double x)
{
    return sin(x)+x*x;
}


void Sortiraj (std::vector<std::pair<double,double>> vektor)
{
    std::pair<double,double> tmp;
    for(int i=0; i<vektor.size()-1; i++) {
        for(int j=i+1; j<vektor.size(); j++) {
            if(vektor.at(i).first>vektor.at(j).first) {
                tmp=vektor.at(i);
                vektor.at(i)=vektor.at(j);
                vektor.at(j)=tmp;
            }
        }
    }
}
std::function<double(double)> LinearnaInterpolacija(std::vector<std::pair<double,double>> &vektor)
{
    for(int i=0; i<vektor.size()-1; i++) {
        double prvi,poslednji;
        if(i==0) prvi=vektor.at(i).first;
        if(i==vektor.size()-1) poslednji=vektor.at(i).first;
        for(int j=i+1; j<vektor.size(); j++) {

            if(vektor.at(i).first==vektor.at(j).first )  throw std::domain_error("Neispravni cvorovi");

        }
    }
    return [vektor] (double x) {
        double y;


        Sortiraj(vektor);
        double prvi(vektor.at(0).first),poslednji(vektor.at(vektor.size()-1).first);


        if(x<prvi || x>poslednji) throw std::range_error("Argument izvan opsega");
        double x1,x2,y1,y2;
        for(int i=0; i<vektor.size(); i++) {
            if(x==vektor.at(i).first) return vektor.at(i).second;
        }
        for(int i=0; i<vektor.size()-1; i++) {
            std::pair<double,double> par;
            par.first=x;
            par.second=x;
            auto it1=lower_bound(vektor.begin(),vektor.end(),par) ;
            auto it2=upper_bound(vektor.begin(),vektor.end(),par);
            it1--;
            x1=it1->first;
            x2=it2->first;
            y1=it1->second;
            y2=it2->second;
            break;

        }

        y=y1+((y2-y1)/(x2-x1))*(x-x1);

        return y;

    };
}

std::function<double(double)> LinearnaInterpolacija(std::function<double(double)> f,double min, double max, double delta)
{
    std::vector<std::pair<double,double>> cvorovi;
    double cvor(min);
    std::pair<double,double>par;
    do {
        par.first=cvor;
        par.second=f(cvor);
        cvorovi.push_back(par);
        cvor=cvor+delta;
    } while(cvor<=max);
    return LinearnaInterpolacija(cvorovi);  
}



int main ()
{
    try {
        std::cout<<"Odaberite opciju (1 - unos cvorova, 2 - aproksimacija): ";
        int opcija;
        std::cin>>opcija;
        if(opcija==1) {
            std::cout<<"Unesite broj cvorova: ";
            int n;
            std::cin>>n;
            std::cout<<"Unesite cvorove kao parove x y: ";
            double a,b;
            std::pair<double,double> par;
            std::vector<std::pair<double,double>> vektor;
            for(int i=0; i<n; i++) {
                std::cin>>a;
                std::cin>>b;
                par.first=a;
                par.second=b;
                vektor.push_back(par);
            }

            double x;
            do {
                try{
                    auto f(LinearnaInterpolacija(vektor));
                     std::cout<<"Unesite argument (ili \"kraj\" za kraj): ";
                    std::cin>>x;
                    if(!std::cin) break;
                     std::cout<<"f("<<x<<") = "<<f(x)<<std::endl;
                } 
                catch(std::range_error izuzetak) {
                    std::cout<<izuzetak.what()<<std::endl;
                }
            } while(std::cin);
        }
        else {
            std::cout<<"Unesite krajeve intervala i korak: ";
            double min,max,delta;
            std::cin>>min;
            std::cin>>max;
            std::cin>>delta;
            double x;

            do {
                try {
                    auto f=LinearnaInterpolacija(funkcija,min,max,delta);
                    std::cout<<"Unesite argument (ili \"kraj\" za kraj): ";
                    std::cin>>x;
                    if(!std::cin) break;
                    std::cout<<"f("<<x<<") = "<<funkcija(x)<<" fapprox("<<x<<") = "<<f(x)<<std::endl;
                }
                catch(std::range_error izuzetak) {
                    std::cout<<izuzetak.what()<<std::endl;
                }
            } while(std::cin);
        }
    } 
    catch (std::domain_error izuzetak) {
        std::cout<<izuzetak.what();
    }
    catch(std::range_error izuzetak) {
        std::cout<<izuzetak.what();
    }

    return 0;
}
