/B2017/2018: Zadaća 3, Zadatak 1
#include <iostream>
#include <functional>
#include <vector>
#include <algorithm>
#include <stdexcept>
#include <cmath>
#define epsilon 0.001
std::function<double(double)> LinearnaInterpolacija(std::vector<std::pair<double, double>> parovi){
    
    std::sort(parovi.begin(), parovi.end(), [](std::pair<double,double> x, std::pair<double,double> y){return x.first<y.first;});
    return [parovi](double x){
        for(int i=0; i<parovi.size(); i++){
            for(int j=i+1; j<parovi.size(); j++){
                if(fabs(parovi[j].first-parovi[i].first)<epsilon) throw std::domain_error("Neispravni cvorovi");
            } 
        }
        if(x<parovi[0].first || x>parovi[parovi.size()-1].first) throw std::range_error("Argument izvan opsega");
        for(int it=0; it<parovi.size()-1; it++){
            if(fabs(x-parovi[parovi.size()-1].first)<epsilon) return parovi[parovi.size()-1].second;
            if(x>=parovi[it].first && x<parovi[it+1].first){
                return (parovi[it].second+((parovi[it+1].second-parovi[it].second)/(parovi[it+1].first-parovi[it].first))*(x-parovi[it].first));
            }
        }
        return 0.0;
    };
    
}
std::function<double(double)> LinearnaInterpolacija(double fun(double), double min, double max, double delta_x){
    if(delta_x <= 0 || min> max) throw std::domain_error("Nekorektni parametri");
    int k(0);
    std::vector<std::pair<double,double>> parovi;
    for(double i(min); i<=max; i+=k*delta_x){
        parovi.push_back(std::make_pair(i,fun(i)));
        k++;
    }
    return[fun,parovi,delta_x](double x){
        if(x<parovi[0].first || x>parovi[parovi.size()-1].first) throw std::range_error("Argument izvan opsega");
        if(fabs(x-parovi[parovi.size()-1].first)<epsilon) return parovi[parovi.size()-1].second;
        
        for(int i=1; i<parovi.size(); i++){
            auto it=std::lower_bound(parovi.begin(),parovi.end(),x,[](const std::pair<double,double> &y, const double &z){return y.first<z;});
            return fun(it->first)+((fun(it->first-delta_x)-fun(it->first))/(it->first-delta_x-it->first))*(x-it->first);
        }
        return 0.0;
    };
}
int main ()
{
        int unos(0);
        std::vector<std::pair<double,double>> parovi;
        std::cout<<"Odaberite opciju (1 - unos cvorova, 2 - aproksimacija): ";
        std::cin>>unos;
        if(unos==1){
            try{
            int broj;
            std::cout<<"Unesite broj cvorova: ";
            std::cin>>broj;
            parovi.resize(broj);
            std::cout<<"Unesite cvorove kao parove x y: ";
            for(int i=0; i<broj; i++) std::cin>>parovi[i].first>>parovi[i].second;
            std::function<double(double)> fun(LinearnaInterpolacija(parovi));
            fun(parovi[0].first);
            for(;;){
                double unos1;
                std::cout<<"Unesite argument (ili \"kraj\" za kraj): ";
                std::cin>>unos1;
                if(!std::cin) break;
                
                std::cout<<"f("<<unos1<<") = "<<fun(unos1)<<std::endl;
            }
            }catch(std::range_error Izuzetak){
                  std::cout<<Izuzetak.what()<<std::endl;
            }catch(std::domain_error Izuzetak1){
                   std::cout<<Izuzetak1.what()<<std::endl;
            }
        }
        else if(unos==2){
                double min,max,korak;
                std::cout<<"Unesite krajeve intervala i korak: ";
                std::cin>>min>>max>>korak;
                std::cin.ignore(1000,'\n');
                for(;;){
                    double unos1;
                    std::cout<<"Unesite argument (ili \"kraj\" za kraj): ";
                    std::cin>>unos1;
                    if(!std::cin) break;
                    try{
                    auto fun(LinearnaInterpolacija([](double x){return x*x+sin(x);},min,max,korak));
                    std::cout<<"f("<<unos1<<") = "<<unos1*unos1+sin(unos1)<<" fapprox("<<unos1<<") = "<<fun(unos1)<<std::endl;
                    }catch(std::range_error Izuzetak){
                     std::cout<<Izuzetak.what()<<std::endl;
                    }catch(std::domain_error Izuzetak1){
                    std::cout<<Izuzetak1.what()<<std::endl;
                    }
                }
        }
    
	return 0;
}
