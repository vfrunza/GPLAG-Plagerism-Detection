/B2017/2018: Zadaća 3, Zadatak 1
#include <iostream>
#include <algorithm>
#include <utility>
#include <vector>
#include <stdexcept>
#include <functional>
#include <cmath>
const double eps=1e-5;
std::function<double(double)>funkcija()
{
    return[] (double y) {
        return y*y+sin(y);
    };
}
bool Sortiraj(std::pair<double,double>x , std::pair<double,double>y)
{
    if(x.first==y.first) throw std::domain_error("Neispravni cvorovi");
    return x<y;
}
std::function<double(double)> LinearnaInterpolacija(std::vector<std::pair<double,double>>niz_parova)
{
    try {
        std::sort(niz_parova.begin(),niz_parova.end(),Sortiraj);
    } catch(std::domain_error) {
        throw std::domain_error("Neispravni cvorovi");
    }
    return [niz_parova] (double x) {
        bool t=false;
        int index,index_1,j=1;
        for(int i(0); i<niz_parova.size()-1; i++) {
            if(niz_parova.at(i).first<=x&&niz_parova.at(j).first>=x) {
                index=i;
                index_1=j;
                t=true;
                break;
            }
            if(t) break;
            j++;
        }
        if(t) {
            return (niz_parova.at(index).second+(niz_parova.at(index_1).second-niz_parova[index].second)/(niz_parova[index_1].first-niz_parova[index].first)*(x-niz_parova[index].first)) ;
        } else throw std::range_error("Argument izvan opsega");

    };
}
std::function<double(double)>LinearnaInterpolacija(std::function<double(double)>fun,double x_min,double x_max,double delta)
{
    if(delta<=0||x_min>x_max) throw std::domain_error("Nekorektni parametri");
    int i(0);
    std::vector<std::pair<double,double>>parovi;
    std::pair<double,double>p;
    for(;;) {
        if(x_min+i*delta>x_max) break;
        auto rezultat=fun(x_min+i*delta);
        p=std::make_pair(x_min+i*delta,rezultat);
        parovi.push_back(p);
        i++;
    }
    try {
        auto nova_funkcija(LinearnaInterpolacija(parovi));
        return nova_funkcija;
    } catch(...) {
        throw std::domain_error("Argument izvan opsega") ;
    }

}
int main ()
{
    std::cout << "Odaberite opciju (1 - unos cvorova, 2 - aproksimacija): ";
    int izbor(0);
    char znak('"');
    std::cin >> izbor;
    if(izbor==1) {
        std::cout << "Unesite broj cvorova: ";
        int br_cvorova;
        std::cin >> br_cvorova;
        std::cout << "Unesite cvorove kao parove x y: ";
        std::pair<double, double>Parovi;
        std::vector<std::pair<double , double>>v ;
        double x,y;
        for(int i(0); i<br_cvorova; i++) {
            std::cin >> x>>y;
            Parovi=std::make_pair(x,y);
            v.push_back(Parovi);
        }
        try {
            std::sort(v.begin(),v.end(),Sortiraj);
            for(;;) {
                std::cout << "Unesite argument (ili \"kraj\" za kraj): ";
                std::cin >> x;
                if(!std::cin) break;
                try {
                    auto f(LinearnaInterpolacija(v));
                    std::cout <<"f("<<x<<") = " <<f(x) << std::endl;
                } catch(std::range_error &i) {
                    std::cout << i.what() << std::endl;
                }
            }
        } catch(std::domain_error iz) {
            std::cout << iz.what() << std::endl;
        }
    }
    if(izbor==2) {
        char znak('"');
        double x;
        std::cout << "Unesite krajeve intervala i korak: ";
        double x_min,x_max,delta;
        std::cin >> x_min>>x_max>>delta;
        for(;;) {
            std::cout << "Unesite argument (ili \"kraj\" za kraj): ";
            try {
                std::cin >> x;
                if(x>x_max) throw std::domain_error("Argument izvan opsega");
                if(!std::cin) break;
                std::function<double(double)> fun(funkcija());
                auto rez(x*x+sin(x));
                auto f=LinearnaInterpolacija(fun,x_min,x_max,delta);
                std::cout << "f("<<x<<") = "<<rez <<" fapprox("<<x<<") = "<<f(x)<< std::endl;
            } catch(std::domain_error izuzetak) {
                std::cout << izuzetak.what() << std::endl;
            }
        }
    }
    return 0;
}
