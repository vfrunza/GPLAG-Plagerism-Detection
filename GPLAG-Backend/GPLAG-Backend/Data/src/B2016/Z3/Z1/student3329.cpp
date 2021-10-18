#include <iostream>
#include <functional>
#include <stdexcept>
#include <vector>
#include <algorithm>
#include <cmath>

double probna(double x){
    return std::pow(x,2)+std::sin(x);
}
std::function<double(double)> BaricentricnaInterpolacija(std::vector<std::pair<double, double>> cvorici, int d){
    if(d<0 || d>=cvorici.size()) throw std::domain_error("Nedozvoljen red");
    for(int i=0; i<cvorici.size(); i++){
        for(int j=i+1; j<cvorici.size(); j++){
            if(cvorici[i].first==cvorici[j].first)
            throw std::domain_error("Neispravni cvorovi");
        }
    }
    std::vector<double> w(cvorici.size(), 0);
    int zamin(cvorici.size()-d);
        
    for(int i=1; i<=cvorici.size(); i++){
        for(int k=std::max(1, i-d); k<=std::min(i, zamin); k++){
            double proizvod(1);
            for(int j=k; j<=k+d; j++){
                if(j==i){continue;}
                proizvod*=1/(cvorici[i-1].first-cvorici[j-1].first);
            }
            w[i-1]+=std::pow(-1, k-1)*proizvod;
        }
    }
    return [cvorici, w, d](double x){
        for(auto y : cvorici) if(x==y.first) return y.second; double brojnik(0), nazivnik(0);
        for(int i=1; i<=cvorici.size(); i++){
            brojnik+=w[i-1]/(x-cvorici[i-1].first)*cvorici[i-1].second; nazivnik+=w[i-1]/(x-cvorici[i-1].first);
        }
        return brojnik/nazivnik;
    };
}
std::function<double(double)> BaricentricnaInterpolacija(double fun(double), double xmin, double xmax, double dx, int d){
    if(xmin>xmax || dx<=0) std::domain_error("Nekorektni parametri");
    std::vector<std::pair<double, double>> cvorici;
    for(int i=0; xmin<=xmax; i++){
        cvorici.push_back({xmin, fun(xmin)});
        xmin+=dx;
    }
    return BaricentricnaInterpolacija(cvorici, d);
}

int main (){
    std::cout<<"Odaberite opciju (1 - unos cvorova, 2 - aproksimacija): ";
    int opcija; std::cin>>opcija;
    
    try{
        if(opcija==1){
            int broj_cvorova;
            std::cout<<"Unesite broj cvorova: ";
            std::cin>>broj_cvorova;
            std::cout<<"Unesite cvorove kao parove x y: ";
            std::vector<std::pair<double, double>> cvorici;
            double x, y;
            for(int i=0; i<broj_cvorova; i++){
                std::cin>>x>>y;
                cvorici.push_back({x,y});
            }
            std::cout<<"Unesite red interpolacije: ";
            int red; std::cin>>red;
            auto f(BaricentricnaInterpolacija(cvorici, red));
            double arg;
            std::cout<<"Unesite argument (ili \"kraj\" za kraj): ";
            while(std::cin>>arg){
                std::cout<<"f("<<arg<<") = "<<f(arg)<<std::endl;
                std::cout<<"Unesite argument (ili \"kraj\" za kraj): ";
            }
        }else if(opcija==2){
            std::cout<<"Unesite krajeve intervala i korak: ";
            double xmin, xmax, dx;
            std::cin>>xmin>>xmax>>dx;
            std::cout<<"Unesite red interpolacije: ";
            int red; std::cin>>red;
            auto f(BaricentricnaInterpolacija(probna, xmin, xmax, dx, red));
            double arg;
            std::cout<<"Unesite argument (ili \"kraj\" za kraj): ";
            while(std::cin>>arg){
                std::cout<<"f("<<arg<<") = "<<std::pow(arg, 2)+std::sin(arg)<<" fapprox("<<arg<<") = "<<f(arg)<<std::endl;
                std::cout<<"Unesite argument (ili \"kraj\" za kraj): ";
            }
        }
    }catch(std::domain_error izuzetak){
        std::cout<<izuzetak.what();
    }
	return 0;
}