#include <iostream>
#include<functional>
#include<utility>
#include<vector>
#include<stdexcept>
#include<algorithm>
#include<cmath>
std::function<double(double)> LinearnaInterpolacija(std::vector<std::pair<double,double>> cvorovi) {
    std::sort(cvorovi.begin(),cvorovi.end());
    for(int i=0; i<cvorovi.size(); i++) {
        for(int j=i+1; j<cvorovi.size(); j++) {
            if(cvorovi[i].first==cvorovi[j].first) throw std::domain_error("Neispravni cvorovi");
        }
    }
    return [cvorovi] (double x) {
        if(x<cvorovi.at(0).first || x>cvorovi.at(cvorovi.size()-1).first) throw std::range_error("Argument izvan opsega");
        double rez;
        if(x==cvorovi[cvorovi.size()-1].first) rez=cvorovi[cvorovi.size()-1].second;
        else {
            std::pair<double,double> prvi,drugi;
            /*     auto it(std::upper_bound(cvorovi.begin(),cvorovi.end(),x,[](double br,std::pair<double,double> p){return p.first<br;}));
                 prvi=*it;
                 it++;
                 drugi=*it; */
            for(int i=0; i<cvorovi.size()-1; i++) {
                if(cvorovi[i].first<=x && cvorovi[i+1].first>x) {
                    prvi=cvorovi[i];
                    drugi=cvorovi[i+1];
                    break;
                }
            }
            rez=prvi.second+((drugi.second-prvi.second)/(drugi.first-prvi.first))*(x-prvi.first);
        }
        return rez;
    };
}
std::function<double(double)> LinearnaInterpolacija(std::function<double(double)> f, double x_min, double x_max, double delta_x) {
    if(x_min>x_max || delta_x<=0) throw std::domain_error("Nekorektni parametri");
    std::vector<std::pair<double,double>> novi;
    for(double x=x_min; x<x_max; x+=delta_x) {
        novi.push_back(std::make_pair(x,f(x)));
    }
    return LinearnaInterpolacija(novi);
}
int main () {
    try {
        int opcija;
        std::cout<<"Odaberite opciju (1 - unos cvorova, 2 - aproksimacija): ";
        std::cin>>opcija;
        if(opcija==1) {
            int broj_cvorova;
            std::cout<<"Unesite broj cvorova: ";
            std::cin>>broj_cvorova;
            std::vector<std::pair<double,double>> v(broj_cvorova);
            std::cout<<"Unesite cvorove kao parove x y: ";
            for(int i=0; i<v.size(); i++) {
                std::cin>>v[i].first>>v[i].second;
            }
            for(;;) {
                try {
                    auto f(LinearnaInterpolacija(v));
                    std::cout<<"Unesite argument (ili \"kraj\" za kraj): ";
                    double argument;
                    std::cin>>argument;
                    if(!std::cin) break;
                    std::cout<<"f("<<argument<<") = "<<f(argument)<<std::endl;
                } 
                catch(std::domain_error) {
                    throw;
                }
                catch(std::range_error izuzetak) {
                    std::cout<<izuzetak.what()<<std::endl;
                }
            }
        } 
        else if(opcija==2) {
            double pocetak, kraj, korak;
            std::cout<<"Unesite krajeve intervala i korak: ";
            std::cin>>pocetak>>kraj>>korak;
            auto funkcija([](double x) {return x*x+std::sin(x);});
            for(;;) {
                try {
                    auto f(LinearnaInterpolacija(funkcija,pocetak,kraj,korak));
                    std::cout<<"Unesite argument (ili \"kraj\" za kraj): ";
                    double argument;
                    std::cin>>argument;
                    if(!std::cin) break;
                    std::cout<<"f("<<argument<<") = "<<funkcija(argument)<<" fapprox("<<argument<<") = "<<f(argument)<<std::endl;
                } 
                catch(std::domain_error) {
                    throw;
                }
                catch(std::range_error izuzetak) {
                    std::cout<<izuzetak.what()<<std::endl;
                }
            }
        }
    } 
    catch(std::domain_error izuzetak) {
        std::cout<<izuzetak.what()<<std::endl;
    } 
    catch(std::range_error izuzetak) {
        std::cout<<izuzetak.what()<<std::endl;
    }
    return 0;
}