/B2016/2017: Zadaća 3, Zadatak 1
//Autotestovi by Enil Pajic (epajic1@etf.unsa.ba)
#include <iostream>
#include <utility>
#include <vector>
#include <stdexcept>
#include <functional>
#include <cmath>

std::function<double(double)> BaricentricnaInterpolacija1(std::vector<std::pair<double,double>> v, int d){
    std::function<double(double)> f;
    //double suma_1(0),suma_2(0),suma_3(0),proizvod(1),wi;
  //  for(int i(1); i<n; i++){
    //    proizvod*=
   // }
    
    
    return f;
}

std::function<double(double)> BaricentricnaInterpolacija2(double f(double), double x_min, double x_max, double d_x, int d){
    std::function<double(double)> g(f);
    
    return g;
}
int main ()
{
    int opcija;
    std::cout<<"Odaberite opciju (1 - unos cvorova, 2 - aproksimacija): ";
    std::cin>>opcija;
    std::vector<std::pair<double,double>> parovi;
    try{
    if(opcija==1){
        int n;
        std::cout<<"Unesite broj cvorova: ";
        std::cin>>n;
        std::cout<<"Unesite cvorove kao parove: ";
        for(int i(0); i<n; i++){
            std::pair<double,double> p;
            double x,y;
            std::cin>>x>>y;
            p=std::make_pair(x,y);
            //std::cin>>p;
            parovi.push_back(p);
        }
        int d;
        std::cout<<"Unesite red interpolacije: "<<std::endl;
        std::cin>>d;
        if(d<0 || d>n) throw std::domain_error("Nedozvoljen red");
        for(int i(0); i<n; i++){
            for(int j(0); j<n; j++){
                if(parovi[i].first==parovi[j].first) throw std::domain_error("Neispravni cvorovi");
            }
        }
        for(;;){
            int x;
            std::cout<<"Unesite argument (ili 'kraj' za kraj): ";
            std::cin>>x;
            if(!std::cin) return 0;
            auto f(BaricentricnaInterpolacija1(parovi,d));
            std::cout<<"f("<<x<<") = "<<f(x);
            
        }
        
    }
    if(opcija==2){
        int kraj_1,kraj_2,korak;
        std::cout<<"Unesite krajeve intervala i korak: ";
        std::cin>>kraj_1>>kraj_2>>korak;
        if(kraj_1-kraj_2>0.0000000000001 || korak<=0) throw std::domain_error("Nekorektni parametri");
        int d;
        std::cout<<"Unesite red interpolacije: ";
        std::cin>>d;
        for(;;){
            int x;
            std::cout<<"Unesite argument (ili 'kraj' za kraj): ";
            std::cin>>x;
            if(!std::cin) return 0;
         //   auto f(BaricentricnaInterpolacija1(parovi,d));
            auto fapprox(BaricentricnaInterpolacija2([](double x){ return (pow(x,2)+std::sin(x)); },kraj_1,kraj_2,korak,d));
            std::cout<<"f("<<x<<") = "<<" fapprox("<<x<<") = "<<fapprox(x);
        }
    }
    }
    catch(std::domain_error e){
        std::cout<<e.what();
    }
	return 0;
}