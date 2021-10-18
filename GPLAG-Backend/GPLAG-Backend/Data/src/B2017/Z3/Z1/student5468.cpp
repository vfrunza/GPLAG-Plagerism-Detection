/B2017/2018: Zadaća 3, Zadatak 1
#include <iostream>
#include <functional>
#include <stdexcept>
#include <utility>
#include <vector>
#include <cmath>
#include <algorithm>
#define eps 0.0001

typedef std::vector<std::pair<double, double>> VekPar;
typedef std::function<double(double)> Fun;

bool NeispravniCvorovi(const VekPar &v){
    for(int i=0; i<v.size(); i++)
        for(int j=i; j<v.size(); j++)
            if(i!=j && std::abs(v.at(i).first-v.at(j).first)<eps)
                return true;
    return false;
}

Fun LinearnaInterpolacija(VekPar cvorovi){
    if(NeispravniCvorovi(cvorovi))
        throw std::domain_error("Neispravni cvorovi");
    std::sort(cvorovi.begin(), cvorovi.end(), 
             [](std::pair<double, double> p1, std::pair<double, double> p2){
                 return p1<p2;
             });
    return [cvorovi](double x){
        if(x<cvorovi.at(0).first || x>cvorovi.at(cvorovi.size()-1).first)
            throw std::range_error("Argument izvan opsega");
        else{
            auto it(std::find_if(cvorovi.begin(), cvorovi.end(), 
                 [x](std::pair<double, double> p){ return (p.first>=x);}));    
            if(x<cvorovi.at(cvorovi.size()-1).first){
                auto yi2(it->second); auto xi2(it->first); it--;
                auto yi(it->second); auto xi(it->first);
                return (yi+((yi2-yi)/(xi2-xi))*(x-xi));
            }
            else return cvorovi.at(cvorovi.size()-1).second;
        }   
    };
}

Fun LinearnaInterpolacija(Fun f, double xmin, double xmax, double deltax){
    if(xmin>xmax || deltax<=0)
        throw std::domain_error("Nekorektni parametri");
    VekPar cvorovi;
    double a(xmin);
    while(a<=xmax){
        cvorovi.push_back({a, f(a)});
        a+=deltax;
    }
    if(NeispravniCvorovi(cvorovi))
        throw std::domain_error("Neispravni cvorovi");
    std::sort(cvorovi.begin(), cvorovi.end(), 
             [](std::pair<double, double> p1, std::pair<double, double> p2){
                 return p1<p2;
             });
    return [cvorovi](double x){
        if(x<cvorovi.at(0).first || x>cvorovi.at(cvorovi.size()-1).first)
            throw std::range_error("Argument izvan opsega");
        else{
            auto it(std::find_if(cvorovi.begin(), cvorovi.end(), 
                 [x](std::pair<double, double> p){ return (p.first>=x);}));    
            if(x<cvorovi.at(cvorovi.size()-1).first){
                auto yi2(it->second); auto xi2(it->first); it--;
                auto yi(it->second); auto xi(it->first);
                return (yi+((yi2-yi)/(xi2-xi))*(x-xi));
            }
            else return cvorovi.at(cvorovi.size()-1).second;
        }   
    };
}

int main(){
    std::cout << "Odaberite opciju (1 - unos cvorova, 2 - aproksimacija): ";
    int opcija;
    std::cin >> opcija;
    try{
    switch(opcija){
        case 1:
        {std::cout << "Unesite broj cvorova: ";
        int br_cvorova;
        std::cin >> br_cvorova;
        std::cout << "Unesite cvorove kao parove x y: ";
        VekPar v;
        for(int i=0; i<br_cvorova; i++){
            double x, y;
            std::cin >> x >> y;
            v.push_back({x, y});
        }
        Fun f(LinearnaInterpolacija(v));
        do{
        try{    
            std::cout << "Unesite argument (ili \"kraj\" za kraj): ";
            double x;
            std::cin >> x;
            if(!std::cin)
                break;
            std::cout << "f(" << x << ") = " << f(x) << std::endl;
        }
        catch(std::domain_error izuzetak){
            std::cout << izuzetak.what() << std::endl;
        }
        catch(std::range_error izuzetak){
            std::cout << izuzetak.what() << std::endl;
        }
        } while(std::cin);}
        break;
        case 2:
        std::cout << "Unesite krajeve intervala i korak: ";
        double xmin, xmax, deltax;
        std::cin >> xmin >> xmax >> deltax;
        Fun fun([](double x){
            return x*x+std::sin(x);
            });
        Fun fapprox(LinearnaInterpolacija(fun, xmin, xmax, deltax));
        do{
            try{
            std::cout << "Unesite argument (ili \"kraj\" za kraj): ";
            double x;
            std::cin >> x;
            if(!std::cin)
                break;
            std::cout << "f(" << x << ") = " << fun(x) 
            << " fapprox(" << x << ") = " << fapprox(x) << std::endl;
            }
            catch(std::domain_error izuzetak){
                std::cout << izuzetak.what() << std::endl;;
            }
            catch(std::range_error izuzetak){
                std::cout << izuzetak.what() << std::endl;;
            }
        } while(std::cin);
    } 
    }
    catch(std::domain_error izuzetak){
        std::cout << izuzetak.what();
    }
    catch(std::range_error izuzetak){
        std::cout << izuzetak.what();
    }
    
    return 0;
}

