#include <iostream>
#include <vector>
#include <utility>
#include <stdexcept>
#include <string>
#include <algorithm>
#include <cmath>

template<typename NekiTip, typename Tip>

NekiTip BaricentricnaInterpolacija(const std::vector<std::pair<double, double>> &vek, int d){
    int n(0); //Broj cvorova
    Tip x;
    for(int i=0; i<vek.size(); i++){
        n++;
    }
    
    if(d<0 || d>n) throw std::domain_error("Nedozvoljen red");
    
    for(int i=0; i<vek.size(); i++){
        for(int j=1; j<vek.size(); j++){
            if(vek[i]==vek[j]) throw std::domain_error("Neispravni cvorovi");
            break;
        }
    }
    
    NekiTip f, nazivnik, brojnik;
    
    for(int i=1; i<n; i++){
        double w(0), prvidio, drugidio;
        for(int k=std::max(1, n-d); k<std::min(i, i-d); k++){
            prvidio=std::pow(-1, k-1);
            if(i!=k) 
                drugidio=1/(vek[i].first-vek[k].first);
            
            w+=prvidio*drugidio;
        }
        auto pomocna(vek[i].second);
        nazivnik+=w/(x-vek[i].first);
        brojnik+=(w*pomocna)/(x-vek[i].first);
    }
    
    f=nazivnik/brojnik;
    return f;
}

/*template<typename NekiTip>

NekiTip BaricentricnaInterpolacija(double f(double), xmin, xmax, xdelta, int d){
    if(xmin>xmax || xdelta<=0) throw std::domain_error("Nekorektni parametri");
    
}*/

int main ()
{
    std::vector<std::pair<double, double>> v;
    int odabir;
    int d;
    std::cout<<"Odaberite opciju (1 - unos cvorova, 2 - aproksimacija): ";
    std::cin>>odabir;
    
    if(odabir==1){
        int BrCvorova;
        std::cout<<"Unesite broj cvorova: ";
        std::cin>>BrCvorova;
        std::cout<<"Unesite broj cvorova kao parove x y: ";
        double KoorPrva, KoorDruga;
        v.resize(BrCvorova);
        
        for(int i=0; i<BrCvorova; i++){
            std::cin>>KoorPrva>>KoorDruga;
            auto Par(std::make_pair(KoorPrva, KoorDruga));
            v[i]=Par;
        }
        
       
        std::cout<<"Unesite red interpolacije: ";
        std::cin>>d;
        double argument;
        
        auto PovF(BaricentricnaInterpolacija(v, d));
        
        for(;;){
        std::cout<<"Unesite argumente (ili 'kraj' za kraj): ";
        std::cin>>argument;
        std::cout<<"f("<<argument<<")"<<" = "<<PovF(argument);
        
        
        if(!std::cin) {
            std::cin.ignore(1000, '\n');
            break;
        }
        }
    }
    else if(odabir==2){
        
    }
        
    
	return 0;
}