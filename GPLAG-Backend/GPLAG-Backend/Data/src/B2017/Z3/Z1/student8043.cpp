/B2017/2018: Zadaća 3, Zadatak 1
#include <iostream>
#include <vector>
#include <utility>
#include <functional>
#include <algorithm>
#include <stdexcept>
#include <limits>
#include <cmath>

double fun(double x)
{
    return x*x+sin(x);
}

typedef std::vector<std::pair<double,double>> VektorParova;

double Aproksimacija(VektorParova v,double x)
{
    std::vector<double> pomocni;
    for(int i(0); i<v.size(); i++) {
        pomocni.push_back(v.at(i).first);
    }
    if(x<pomocni.at(0) || x>pomocni.at(int(pomocni.size())-1)) throw std::range_error("Argument izvan opsega");
    auto it1(std::lower_bound(pomocni.begin(),pomocni.end(),x));
    int centralni(it1-pomocni.begin());
    int lijevi(centralni),desni(centralni);
    if(v.at(centralni).first>x) {
        lijevi--;
    } else {
        if(desni+1<pomocni.size()) {
            desni++;
        } else {
            lijevi--;
        }
    }
    return v.at(lijevi).second+(v.at(desni).second-v.at(lijevi).second)*(x-v.at(lijevi).first)/(v.at(desni).first-v.at(lijevi).first);
}

std::function<double(double)> LinearnaInterpolacija (VektorParova &v)
{
    std::sort(v.begin(),v.end()); // sortiranje za svaki slucaj
    for(int i(0); i<int(v.size())-1; i++) { // ima li istih x
        if(v.at(i).first<v.at(i+1).first) {
            continue;
        } else {
            throw std::domain_error("Neispravni cvorovi");
        }
    }
    return [&v](double x) {
        return Aproksimacija(v,x);
    };
}

std::function<double(double)> LinearnaInterpolacija(double fun(double),double Xmin,double Xmax,double dX)
{
    if(Xmin>Xmax || !(dX>0)) throw std::domain_error("Nekorektni parametri");
    VektorParova v;
    int i(0);
    while(Xmin+i*dX<Xmax) {
        v.push_back({Xmin+i*dX,fun(Xmin+i*dX)});
        i++;
    }
    v.push_back({Xmax,fun(Xmax)});
    return [v] (double x) {
        return Aproksimacija(v,x);
    };
}

double UnosArgumenta()
{
    char znak('"');
    std::cout << "Unesite argument (ili " << znak << "kraj" << znak << " za kraj): ";
    double argument(0);
    std::cin >> argument;
    if(!(std::cin) || std::cin.get()!='\n') {
        std::cin.clear();
        std::cin.ignore(10000,'\n');
        throw std::invalid_argument("Kraj.");
    }
    return argument;
}

int main ()
{

    std::cout << "Odaberite opciju (1 - unos cvorova, 2 - aproksimacija): ";
    int opcija(0);
    std::cin >> opcija;
    switch (opcija) {
    case 1: {
        std::cout << "Unesite broj cvorova: ";
        int br_cvr(0);
        std::cin >> br_cvr;
        VektorParova v(br_cvr);
        std::cout << "Unesite cvorove kao parove x y: ";
        for(auto &a:v) {
            std::cin >> a.first >> a.second;
        }
        try {
            auto f(LinearnaInterpolacija(v));
            for(;;) {
                double argument(0);
                try {
                    argument=(UnosArgumenta());
                } catch(std::invalid_argument) {
                    return 0;
                }

                try {
                    std::cout << "f(" << argument << ") = " << f(argument) << std::endl;
                } catch(std::range_error iz) {
                    std::cout << iz.what() << std::endl;
                }
            }
        }

        catch(std::domain_error iz) {
            std::cout << iz.what() << std::endl;
        }
        break;
    }
    case 2: {
        std::cout << "Unesite krajeve intervala i korak: ";
        double Xmin(0),Xmax(0),dX(0);
        std::cin >> Xmin >> Xmax >> dX;
        try {
            auto f(LinearnaInterpolacija(fun,Xmin,Xmax,dX));
            for(;;) {
                double argument(0);
                try {
                    argument=UnosArgumenta();
                } catch(std::invalid_argument) {
                    return 0;
                }
                try {
                    double y(f(argument));
                    std::cout << "f(" << argument << ") = " << fun(argument);
                    std::cout << " fapprox(" << argument << ") = " << y << std::endl;
                } catch(std::range_error iz) {
                    std::cout << iz.what() << std::endl;
                }
            }
        } catch(std::domain_error iz) {
            std::cout << iz.what() << std::endl;
        }
        break;
    }
    default: {
        std::cout << "Pogresna opcija!";
        return 0;
    }
    }
    return 0;
}