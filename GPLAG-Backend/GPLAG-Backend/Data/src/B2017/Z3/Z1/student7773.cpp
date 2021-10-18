/B2017/2018: Zadaća 3, Zadatak 1
#include <iostream>
#include <functional>
#include <utility>
#include <vector>
#include <algorithm>
#include <cmath>
#include <stdexcept>
#include <iterator>



typedef std::vector<std::pair<double,double>> VektorParova;

bool IspravniCvorovi(const VektorParova &cvorovi){
    for(int i=0;i<cvorovi.size();i++){
        for(int j=i+1;j<cvorovi.size();j++){
            if(cvorovi[i].first==cvorovi[j].first)
            return false;
        }
    }
    return true;
}
bool XKoordinata( std::pair<double,double> par, double v){
    if(par.first<v) return true;
    else return false;
}

std::function<double(double)>LinearnaInterpolacija(VektorParova cvorovi){
    std::sort(cvorovi.begin(),cvorovi.end());
    if(!IspravniCvorovi(cvorovi)) throw std::domain_error("Neispravni cvorovi");
    return [=](double x){
        if(x<cvorovi[0].first || x>cvorovi[cvorovi.size()-1].first) throw std::range_error ("Argument izvan opsega\n");
        
        
        auto it_indeks=std::lower_bound(cvorovi.begin(),cvorovi.end(),x,XKoordinata);
        std::size_t indeksi1 = std::distance(cvorovi.begin(), it_indeks);
        int indeksi=indeksi1-1;
        
        double brojnik=cvorovi[indeksi1].second-cvorovi[indeksi].second;
        double nazivnik=cvorovi[indeksi1].first-cvorovi[indeksi].first;
        return (cvorovi[indeksi].second+((brojnik/nazivnik)*(x-cvorovi[indeksi].first)));
    };
}


template <typename FunkTip>
std::function<double(double)> LinearnaInterpolacija(FunkTip f, double x_min, double x_max, double delta_x, int d) {
    VektorParova cvorovi;
    
    if(x_min>x_max || delta_x<=0)
        throw std::domain_error ("Nekorektni parametri");
            
    for(double i=x_min; i<=x_max; i+=delta_x) {
        cvorovi.push_back(std::make_pair(i,f(i)));
        
    }
   
    if(!IspravniCvorovi(cvorovi)) throw std::domain_error ("Neispravni cvorovi");
    return LinearnaInterpolacija(cvorovi);
}

double fun(double x) {
    return x*x+std::sin(x);
}



int main ()
{
    try{
    std::cout<<"Odaberite opciju (1 - unos cvorova, 2 - aproksimacija): ";
    int opcija;
    std::cin>>opcija;
    if(opcija==1){
    std::cout<<"Unesite broj cvorova: ";
    int n;
    std::cin>>n;
    std::cout<<"Unesite cvorove kao parove x y: ";
    VektorParova cvorovi;
    for(int i=0;i<n;i++){
      double x,y;
      std::cin>>x>>y;
      cvorovi.push_back(std::make_pair(x,y));
    }
     if(!IspravniCvorovi(cvorovi)) throw std::domain_error("Neispravni cvorovi");
    for(;;){
        std::cout<<"Unesite argument (ili "<<'"'<<"kraj"<<'"'<<" za kraj): ";
        double arg;
        std::cin>>arg;
        if(!std::cin) return 0;
        try{
        std::cout<<"f("<<arg<<") = "<<LinearnaInterpolacija(cvorovi)(arg)<<std::endl;
        }
        catch(std::domain_error greska){
        std::cout<<greska.what();
        }
        catch(std::range_error gresk){
        std::cout<<gresk.what();
        }
        
    }
    }
    else{
        double x_min, x_max, delta_x;
        int d;
        std::cout<<"Unesite krajeve intervala i korak: ";
        std::cin>>x_min>>x_max>>delta_x;
        if(x_min>x_max || delta_x<=0) throw std::domain_error ("Nekorektni parametri");
        for(;;) {
            std::cout<<"Unesite argument (ili "<<'"'<<"kraj"<<'"'<<" za kraj): ";
            double x;
            std::cin>>x;
            if(!std::cin) return 0;
            try{
            std::cout<<"f("<<x<<") = "<<fun(x)<<" fapprox("<<x<<") = "<<LinearnaInterpolacija(fun, x_min, x_max, delta_x, d)(x)<<std::endl;
        
            }
            catch(std::domain_error greska){
            std::cout<<greska.what();
            }
            catch(std::range_error gresk){
            std::cout<<gresk.what();
            }
        }
    }
    }
    catch(std::domain_error greska) {
        std::cout<<greska.what();
    }
    
    
   
	return 0;
}
