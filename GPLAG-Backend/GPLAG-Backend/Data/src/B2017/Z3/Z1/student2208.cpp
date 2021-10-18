/B2017/2018: Zadaća 3, Zadatak 1
#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <functional>
#include <stdexcept>
#include <cmath>

double g (double x)
{
    return (x*x + sin(x));
}

std::function <double(double)> LinearnaInterpolacija (std::vector<std::pair<double, double>> v)
{
    if (v.size()==0) throw std::range_error ("Argument izvan opsega");
    for (int i(0); i<v.size()-1; i++) {
        for (int j(i+1); j<v.size(); j++) {
            if (v.at(i).first == v.at(j).first) throw std::domain_error ("Neispravni cvorovi");
        }
    }
    for (int i(0); i<v.size()-1; i++) {
        for (int j(i); j<v.size(); j++) {
            if (v.at(i).first > v.at(j).first) swap(v.at(i), v.at(j));
        }
    }
    return   ([=] (double x) -> double {
        if(v.begin() == v.end()-1) {
            throw std::range_error ("Argument izvan opsega");
        } else {
            auto prvi = v.begin();
            auto zadnji = (v.end()-1);
            if (x<(prvi->first) || x>(zadnji->first)) throw std::range_error ("Argument izvan opsega");
        }
        std::pair<double, double> a;
        a = std::make_pair(x, 0);
        auto it_manji = upper_bound (v.begin(),v.end(), a);
        it_manji--;
        auto it_veci = lower_bound (v.begin(), v.end(), a);
        return (it_manji->second+(((it_veci->second)-(it_manji->second))/((it_veci->first)-(it_manji->first)))*(x-(it_manji->first)));

    }
             );


}

std::function<double(double)> LinearnaInterpolacija (std::function<double(double)> f, double x_min, double x_max, double delta_x)
{
    if (x_min>x_max) throw std::domain_error ("Nekorektni parametri");
    if (delta_x<=0) throw std::domain_error ("Nekorektni parametri");
    std::vector<std::pair<double, double>> v;
    for (double i=x_min; i<=x_max; i += delta_x) {
        std::pair<double, double> a;
        a = std::make_pair(i,f(i));
        v.push_back(a);
    }

    return ([=] (double x) -> double {
        auto prvi = v.begin();
        auto zadnji = v.end()-1;
        if (x<(prvi->first) || x>(zadnji->first)) throw std::range_error ("Argument izvan opsega");
        std::pair<double, double> a;
        a = std::make_pair(x, 0);
        auto it_manji = upper_bound (v.begin(), v.end(), a);
        it_manji--;
        auto it_veci = lower_bound (v.begin(), v.end(), a);
        return (it_manji->second+(((it_veci->second)-(it_manji->second))/((it_veci->first)-(it_manji->first)))*(x-(it_manji->first)));
    }

           );

}


int main ()
{
    std::cout<<"Odaberite opciju (1 - unos cvorova, 2 - aproksimacija): ";
    int opcija;
    std::cin>>opcija;
    if (opcija==1) {
        std::cout<<"Unesite broj cvorova: ";
        int broj_cvorova;
        std::cin >> broj_cvorova;
        std::cout<<"Unesite cvorove kao parove x y: ";
        std::vector<std::pair<double, double>> v;
        for (int i(0); i<broj_cvorova; i++) {
            double prvi, drugi;
            std::cin >> prvi >> drugi;
            v.push_back(std::make_pair(prvi, drugi));
        }

        try {
            auto f = LinearnaInterpolacija(v);
        }

        catch (std::domain_error greska) {
            std::cout << greska.what() << std::endl;
            return 0;
        }

        for(;;) {
            std::cout << "Unesite argument (ili \"kraj\" za kraj): ";
            double argument;
            std::cin >> argument;
            if (!std::cin) break;

            try {
                auto f = LinearnaInterpolacija(v);
                std::cout << "f(" << argument<<") = " << f(argument)<< std::endl;
            } catch (std::range_error greska) {
                std::cout << greska.what() << std::endl;
            }
        }

    }

    if (opcija==2) {
        std::cout<<"Unesite krajeve intervala i korak: ";
        double int_jedan, int_dva, korak;
        std::cin >> int_jedan >> int_dva >> korak;
        try {
            auto f = LinearnaInterpolacija (g, int_jedan, int_dva, korak);
        }
        
        catch (std::domain_error greska){
            std::cout << greska.what() << std::endl;
            return 0;
        }
        for (;;) {
            std::cout << "Unesite argument (ili \"kraj\" za kraj): ";
            double argument;
            std::cin >> argument;
            if(!std::cin) break;
            try {
                auto f = LinearnaInterpolacija(g,int_jedan, int_dva, korak);
                std::cout << "f(" << argument << ") = " << argument*argument + sin(argument) << " fapprox("<< argument<<") = " <<f(argument) << std::endl;
            }

            catch (std::range_error greska) {
                std::cout<<greska.what() << std::endl;
            }
        }
    }

    return 0;
}
