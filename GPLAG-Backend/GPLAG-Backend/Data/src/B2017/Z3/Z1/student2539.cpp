#include <iostream>
#include <utility>
#include <vector>
#include <stdexcept>
#include <functional>
#include <algorithm>
#include <cmath>

std::function<double(double)> LinearnaInterpolacija(std::vector<std::pair<double,double>> &v){
    for(int i = 0; i < v.size() - 1; i++){
        for(int j = i + 1; j < v.size(); j++){
            if(v.at(i).first == v.at(j).first){
                throw std::domain_error("Neispravni cvorovi");
            }
        }
    }
    std::sort(v.begin(),v.end(),[](std::pair<double,double> p1,std::pair<double,double> p2){return (p1.first < p2.first);});
    return [v](double x){ 
        if(x < v.at(0).first || x > v.at(v.size() - 1).first){
            throw std::range_error("Argument izvan opsega");
        }
        auto pozicija = lower_bound(v.begin(),v.end(),std::make_pair(x,0.));
        int n = pozicija - v.begin();
        double koeff = (v.at(n - 1).second - v.at(n).second) / (v.at(n - 1).first - v.at(n).first);
        return v.at(n - 1).second + koeff * (x - v.at(n - 1).first);
    };
}

std::function<double(double)> LinearnaInterpolacija(double funkcija(double), double xmin, double xmax, double deltax){
    if(xmin > xmax || deltax <= 0) throw std::domain_error("Nekorektni parametri");
    std::vector<std::pair<double,double>> v;
    for(;;){
        v.push_back(std::make_pair(xmin,funkcija(xmin)));
        xmin += deltax;
        if(xmin > xmax) break;
    }
    return LinearnaInterpolacija(v);
}

int main ()
{
    try{
        int izbor;
        std::vector<std::pair<double,double>> v;
        std::cout << "Odaberite opciju (1 - unos cvorova, 2 - aproksimacija): ";
        std::cin >> izbor;
        if(izbor == 1){
            std::cout << "Unesite broj cvorova: ";
            int cvorovi;
            std::cin >> cvorovi;
            std::cout << "Unesite cvorove kao parove x y: ";
            for(int i = 0; i < cvorovi; i++){
                int x,y;
                std::cin >> x >> y;
                v.push_back(std::make_pair(x,y));
            }
            double x;
            auto f = LinearnaInterpolacija(v);
            for(;;){
                std::cout << "Unesite argument (ili \"kraj\" za kraj): ";
                std::cin >> x;
                if(std::cin){
                    try{
                        std::cout << "f(" << x << ") = " << f(x) << std::endl;
                    }
                    catch(std::exception &e){
                        std::cout << e.what() << std::endl;
                    }
                }
                else {
                    std::cin.clear();
                    break;
                }
            }
            
        }
        else if(izbor == 2){
            double xmin, xmax, deltax;
            std::cout << "Unesite krajeve intervala i korak: ";
            std::cin >> xmin >> xmax >> deltax;
            double x;
            auto f = LinearnaInterpolacija([](double x){return x*x + std::sin(x);},xmin,xmax,deltax);
            for(;;){
                std::cout << "Unesite argument (ili \"kraj\" za kraj): ";
                std::cin >> x;
                if(std::cin){
                    try{
                        double rezultat = f(x);
                        std::cout << "f(" << x << ") = " << x*x + std::sin(x) << " ";
                        std::cout << "fapprox(" << x << ") = " << rezultat << std::endl;
                    }
                    catch(std::exception &e){
                        std::cout << e.what() << std::endl;
                    }
                }
                else {
                    std::cin.clear();
                    break;
                }
            }
        }
    }
    catch(std::exception &e){
        std::cout << e.what() << std::endl;
    }
	return 0;
}