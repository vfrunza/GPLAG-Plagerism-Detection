/B2017/2018: Zadaća 3, Zadatak 1
#include <iostream>
#include <vector>
#include <utility>
#include <functional>
#include <algorithm>
#include <stdexcept>
#include <cmath>
const double e(0.000001);

bool Kriterij(std::pair<double,double> a, std::pair<double,double> b){
    if(std::abs(a.first-b.first)<e)throw std::domain_error("Neispravni cvorovi");
    return(a.first<b.first);
}
std::function<double(double)>LinearnaInterpolacija(std::vector<std::pair<double,double>> cvorovi){
    try{
    std::sort(cvorovi.begin(),cvorovi.end(),Kriterij);
    }
    catch(...){
        throw std::domain_error("Neispravni cvorovi");
    }
    return [cvorovi](double x){
        if(x<cvorovi[0].first||x>cvorovi[cvorovi.size()-1].first) throw std::range_error("Argument izvan opsega\n");
        auto it(std::lower_bound(cvorovi.begin(),cvorovi.end(),std::make_pair(x,0.)));
        auto it1(it-1);
        if(std::abs(x-cvorovi[cvorovi.size()-1].first)<e) return cvorovi[cvorovi.size()-1].second;
        return it1->second+((it->second-it1->second)/(it->first-it1->first))*(x-it1->first);
    };
}

std::function<double(double)>LinearnaInterpolacija(std::function<double(double)> f, double Xmin, double Xmax, double deltaX){
    if(Xmin>Xmax||deltaX<=0) throw std::domain_error("Nekorektni parametri");
    std::vector<std::pair<double,double>> cvorovi;
    int br{0};
    while(Xmin+br*deltaX<=Xmax){
        cvorovi.push_back(std::make_pair(Xmin+br*deltaX,f(Xmin+br*deltaX)));
        br++;
    }
    std::sort(cvorovi.begin(),cvorovi.end(),Kriterij);
    return(LinearnaInterpolacija(cvorovi));
}


int main ()
{
    try{
        std::cout<<"Odaberite opciju (1 - unos cvorova, 2 - aproksimacija): ";
        int opcija;
        std::cin>>opcija;
        if(opcija==1){
            std::cout<<"Unesite broj cvorova: ";
            int broj;
            std::cin>>broj;
            std::cout<<"Unesite cvorove kao parove x y: ";
            std::vector<std::pair<double,double>> cvorovi;
            for(int i=0;i<broj;i++){
            double x,y;
            std::cin>>x>>y;
            cvorovi.push_back(std::make_pair(x,y));
            }
            for(;;){
                try{
                auto f(LinearnaInterpolacija(cvorovi));
                std::cout<<"Unesite argument (ili \"kraj\" za kraj): ";
                double argument;
                std::cin>>argument;
                if(!std::cin) break;
                std::cout<<"f("<<argument<<") = "<<f(argument)<<std::endl;}
        catch(std::range_error e){
        std::cout<<e.what();
        return 0;
    }
       catch(std::domain_error e){
        std::cout<<e.what();
        return 0;
    }
            }
            
        }
        else{
            std::cout<<"Unesite krajeve intervala i korak: ";
            double x,y,z;
            std::cin>>x>>y>>z;
            for(;;){
                try{
                std::cout<<"Unesite argument (ili \"kraj\" za kraj): ";
                double argument;
                std::cin>>argument;
                if(!std::cin) break;
                std::cout<<"f("<<argument<<") = "<<argument*argument+std::sin(argument)<<" fapprox("<<argument<<") = "
                <<LinearnaInterpolacija([](double x){return x*x+std::sin(x);},x,y,z)(argument)<<std::endl;}
                  catch(std::range_error e){
        std::cout<<e.what();
    }
            }
            
        } 
    }
    catch(std::domain_error e){
        std::cout<<e.what();
    }
	return 0;
}
