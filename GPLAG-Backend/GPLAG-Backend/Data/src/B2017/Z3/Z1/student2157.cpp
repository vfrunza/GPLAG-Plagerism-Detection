/B2017/2018: Zadaća 3, Zadatak 1
#include <iostream>
#include <algorithm>
#include <utility>
#include <stdexcept>
#include <functional>
#include <cmath>
#include <vector>

std::function<double(double)> LinearnaInterpolacija(std::vector<std::pair<double, double>> cvorovi){
    
    std::sort(cvorovi.begin(), cvorovi.end(), [](std::pair<double, double> a, std::pair<double, double> b){return a.first<b.first;});
    
    for(int i = 0; i < cvorovi.size(); i++){
        for(int j = i+1; j < cvorovi.size(); j++){
            if(fabs(cvorovi[i].first - cvorovi[j].first) == 0) throw std::domain_error("Neispravni cvorovi");
        }
    }
    
    return [cvorovi](double x){
        for(int i = 0; i < cvorovi.size()-1; i++){
            if(cvorovi[i].first <= x && cvorovi[i+1].first >= x){
                return (cvorovi[i].second + ((cvorovi[i + 1].second - cvorovi[i].second)/(cvorovi[i+1].first - cvorovi[i].first))*(x - cvorovi[i].first));
            }
        }
        throw std::range_error("Argument izvan opsega");
    };
}

double g(double x){
    return x*x + sin(x);
}

std::function<double(double)> LinearnaInterpolacija(double g(double), double a, double b, double c){
    if(a > b || c <= 0) throw std::domain_error("Nekorektni parametri");
    std::vector<std::pair<double, double>> cvorovi;
    for(double i = a; i < b; i+=c){
        cvorovi.push_back(std::make_pair(i, g(i)));
    }
    return [cvorovi](double x){
        for(int i = 0; i < cvorovi.size()-1; i++){
            if(cvorovi[i].first <= x && cvorovi[i+1].first >= x){
                return (cvorovi[i].second + ((cvorovi[i + 1].second - cvorovi[i].second)/(cvorovi[i+1].first - cvorovi[i].first))*(x - cvorovi[i].first));
            }
        }
        throw std::range_error("Argument izvan opsega");
    };
}
int main (){
    try{
        int p;
        std::vector<std::pair<double, double>> cvorovi;
        bool k = false;
        for(;;){
            if(k) break;
            std::cout<<"Odaberite opciju (1 - unos cvorova, 2 - aproksimacija): ";
            std::cin>>p;
            if(p == 1){
                int broj_cvorova;
                std::cout<<"Unesite broj cvorova: ";
                std::cin>>broj_cvorova;
                std::cout<<"Unesite cvorove kao parove x y: ";
                for(int i = 0; i < broj_cvorova; i++){
                    double a, b;
                    std::cin>>a>>b;
                    cvorovi.push_back(std::make_pair(a, b));
                }
                auto f(LinearnaInterpolacija(cvorovi));
                for(;;){
                    std::cin.clear();
                    std::cin.ignore(1000000, '\n');
                    std::cout<<"Unesite argument (ili "<<'"'<<"kraj"<<'"'<<" za kraj): ";
                    double x;
                    std::cin>>x;
                    if(!std::cin.fail()){
                        std::cout<<"f("<<x<<") = "<<f(x)<<std::endl;
                    }
                    else{
                        k = true;
                        break;
                    }
                }
                break;
            }
        
       else if(p == 2){
            std::cout<<"Unesite krajeve intervala i korak: ";
            double a, b, c;
            std::cin>>a>>b>>c;
            auto f1(LinearnaInterpolacija(g, a, b, c));
            for(;;){
                std::cin.clear();
                std::cin.ignore(1000000, '\n');
                std::cout<<"Unesite argument (ili "<<'"'<<"kraj"<<'"'<<" za kraj): ";
                double x;
                std::cin>>x;
                if(!std::cin.fail()){
                    try{
                    std::cout<<"f("<<x<<") = "<<g(x)<<" fapprox("<<x<<") = "<<f1(x)<<std::endl;     
                    }catch(std::range_error e){
                        std::cout<<e.what()<<std::endl;
                    }
                }
                else{
                    k = true;
                    break;
                }
            }
        }
    else break;
    }
    }catch(std::domain_error e){
        std::cout<<e.what();
    }catch(std::range_error e){
        std::cout<<e.what();
    }
	return 0;
}
