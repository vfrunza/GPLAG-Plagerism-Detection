#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#include <stdexcept>
#include <functional>
#include <cmath>

std::function<double(double)> LinearnaInterpolacija (std::vector<std::pair<double, double>> v)
{
    for(int i=0; i<v.size(); i++) {
        for(int j=i+1; j<v.size(); j++) {
            if(v[i].first==v[j].first) {
                throw std::domain_error ("Neispravni cvorovi");
            }
        }
    }
    std::sort (v.begin(), v.end(), [] (std::pair<double, double> prvi, std::pair<double, double> drugi) {
        return prvi.first<drugi.first;
    });

    return [v](double x) {

        if(x<v[0].first || x>v[v.size()-1].first)
            throw std::range_error ("Argument izvan opsega");

        if(x==v[v.size()-1].first)
            return v[v.size()-1].second;

        std::pair<double, double> p=std::make_pair(x,0);

        auto x2=lower_bound (v.begin(), v.end(), p, [](std::pair<double, double> prvi, std::pair<double, double> drugi) {
            return prvi.first<drugi.first;
        });

        return  (x2-1)->second + ( (x2->second-(x2-1)->second) / (x2->first-(x2-1)->first) )*(x-(x2-1)->first);
    };
}

std::function<double (double)> LinearnaInterpolacija (double fun(double), double x_min, double x_max, double delta)
{
    if(x_min>x_max || delta<=0)
        throw std::domain_error ("Nekorektni parametri");

    std::vector<std::pair<double, double>> cvorovi;

    for (double i=x_min; i<=x_max; i+=delta) {

        std::pair<double, double> cvor;
        cvor.first=i;
        cvor.second=fun(i);
        cvorovi.push_back(cvor);
    }
    return LinearnaInterpolacija(cvorovi);
}

double sinus (double x)
{
    return x*x+std::sin(x);
}

int main ()
{
    std::cout<<"Odaberite opciju (1 - unos cvorova, 2 - aproksimacija): ";
    int odabir;
    std::cin>>odabir;

    if(odabir==1) {

        std::cout<<"Unesite broj cvorova: ";
        int broj_cvorova;
        std::cin>>broj_cvorova;

        std::cout<<"Unesite cvorove kao parove x y: ";
        std::vector<std::pair<double, double>> v;

        for (int i=0; i<broj_cvorova; i++) {
            double x,y;
            std::cin>>x>>y;
            std::pair<double, double> par=std::make_pair(x,y);
            v.push_back(par);
        }

        std::function<double(double)> funkcija;

        try {
            funkcija = LinearnaInterpolacija (v);
        } catch (std::domain_error e) {
            std::cout << e.what();
            return 0;
        }

        for(;;) {

            std::cout<<"Unesite argument (ili \"kraj\" za kraj): ";
            double unos;
            std::cin>>unos;
            if(!std::cin) break;

            try {
                std::cout<<"f("<<unos<<") = "<<funkcija(unos) << std::endl;
            } catch(std::domain_error izuzetak_1) {
                std::cout<<izuzetak_1.what()<<std::endl;
            } catch(std::range_error izuzetak_2) {
                std::cout<<izuzetak_2.what()<<std::endl;
            } catch(...) {

            }
        }
    }

    if(odabir==2) {
        std::cout<<"Unesite krajeve intervala i korak: ";
        double x_min, x_max, delta;
        std::cin>>x_min>>x_max>>delta;

        std::function<double(double)> fun;

        try {
            fun=LinearnaInterpolacija (sinus, x_min, x_max, delta);
        } catch (const std::exception &e) {
            std::cout<<e.what()<<std::endl;
            return 0;
        }

        for(;;) {
            std::cout<<"Unesite argument (ili \"kraj\" za kraj): ";
            double unos;
            std::cin>>unos;
            if(!std::cin) break;

            try {
                auto rez1=fun(unos);
                auto rez2=sinus(unos);
                std::cout<<"f("<<unos<<") = "<<rez2<<" fapprox("<<unos<<") = "<<rez1<<std::endl;

            } catch(std::domain_error izuzetak_3) {
                std::cout<<izuzetak_3.what()<<std::endl;
            } catch(std::range_error izuzetak_4) {
                std::cout<<izuzetak_4.what()<<std::endl;
            } catch(...) {

            }
        }

    }

    return 0;
}
