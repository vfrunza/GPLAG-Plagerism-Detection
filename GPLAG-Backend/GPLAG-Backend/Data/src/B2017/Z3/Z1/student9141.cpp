/B2017/2018: Zadaća 3, Zadatak 1
#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#include <stdexcept>
#include <string>
#include <iterator>
#include <functional>
#include <cmath>

std::function<double(double)> LinearnaInterpolacija(std::vector<std::pair<double, double>> a){
    // prvo vektor sortiram po x koordinatama u rastucem poretku
    std::sort(a.begin(), a.end(), [](std::pair<double, double> x1, std::pair<double, double> x2){return x1.first<x2.first;});
    // ako ima dva para s istim x koordinatama baca izuzetak
    for(int i=0; i<a.size(); i++){
        for(int j=i+1; j<a.size(); j++){
            if((a[i]).first==(a[j]).first)throw std::domain_error("Neispravni cvorovi");
        }   
    }
    return [a](double x){ 
        if (a.size()==0 || x<a[0].first || x>a[a.size()-1].first)throw std::range_error("Argument izvan opsega");
        double x_i, y_i, x_ip1, y_ip1;        
        //auto p1 (lower_bound(a.begin(), a.end(), std::make_pair(x,x)));
        auto p2 (upper_bound(a.begin(), a.end(), std::make_pair(x,0.)));
        //x_i=(*(--p1)).first; // vidjet ovo ovde dal ako je *p1=x da ostane to a ne da je --p1
        //y_i=(*p1).second;
        auto p1(p2);
        p1--;
        x_i=(*p1).first;
        y_i=(*p1).second;
        x_ip1=p2->first;
        y_ip1=(*p2).second;
        //std::cout << "___ x_i=" << x_i << "   aa y_i=" << y_i << "   aaa x_ip1=" << x_ip1 << "    aa y_ip1=" << y_ip1 << "\n";
        return (y_i + ( (y_ip1-y_i)*(x-x_i)/(x_ip1-x_i) ));  
    };
}

std::function<double(double)> LinearnaInterpolacija (std::function<double(double)> f, double x_min, double x_max, double delta_x){
    if(x_min>x_max || delta_x<=0)throw std::domain_error("Nekorektni parametri");
    std::vector<std::pair<double, double>> a;
    int pomocna(0);
    while(x_min+delta_x*pomocna<=x_max){
        //std::cout << "\n1) " << f(double(x_min+delta_x*pomocna)) << " __pomocna=" << pomocna << " F(100)=" << f(100) << f(42) << "\n";
        a.push_back(std::make_pair(x_min+delta_x*pomocna, f(x_min+delta_x*pomocna)));
        pomocna++;
    }
    
    /*std::cout << "\nCvorovi: \n";
    for(int i=0; i<a.size(); i++){
        std::cout << a[i].first << "  " << a[i].second << "\n";
    }*/
    return LinearnaInterpolacija(a);
    
    /*return [a](double x){
        if(a.size()==0 || x<a[0].first || x>a[a.size()-1].first)throw std::range_error("Argument izvan opsega");
        double x_i, y_i, x_ip1, y_ip1;
        auto p2(upper_bound(a.begin(), a.end(), std::make_pair(x,0.)));
        auto p1(p2);
        p1--;
        x_i=(*p1).first;
        y_i=(*p1).second;
        x_ip1=p2->first;
        y_ip1=(*p2).second;
        std::cout << "\nx_i=" << x_i << " y_i=" << y_i << " x_ip1=" << x_ip1 << " y_ip1=" << y_ip1 << "\n";
        return (y_i + ( (y_ip1-y_i)*(x-x_i)/(x_ip1-x_i) ));
    };*/
}

int main ()
{
    int opcija, broj_cvorova;
    std::cout << "Odaberite opciju (1 - unos cvorova, 2 - aproksimacija): ";
    std::cin >> opcija;
    if(opcija==1){
        std::cout << "Unesite broj cvorova: ";
        std::cin >> broj_cvorova;
        std::vector<std::pair<double, double>> cvorovi;
        std::cout << "Unesite cvorove kao parove x y: ";
        for(int i=0; i<broj_cvorova; i++){
            double x,y;
            std::cin >> x >> y;
            cvorovi.push_back(std::make_pair(x,y));
        }
        
        try{
            auto f(LinearnaInterpolacija(cvorovi));
        
            std::cin.ignore(10000, '\n');
            for(;;){
                std::cout << "Unesite argument (ili \"kraj\" za kraj): ";
                std::string unos;
                std::getline(std::cin, unos);
                if(unos=="kraj")return 0;
                double argument(std::stod(unos));
            
                try{
                    std::cout << "f(" << argument << ") = " << f(argument) << "\n";
                }
                catch(std::range_error &e){
                    std::cout << e.what() << "\n";
                }
            }
        }
        catch(std::domain_error &e){
            std::cout << e.what();
            return 0;
        }
    }

    else if(opcija==2){
        double x_min, x_max, delta_x;
        std::cout << "Unesite krajeve intervala i korak: ";
        std::cin >> x_min >> x_max >> delta_x;
        
        try{
            //auto f(LinearnaInterpolacija([](double){return x*x+std::sin(x); };) );
            
            std::cin.ignore(10000, '\n');
            for(;;){
                std::cout << "Unesite argument (ili \"kraj\" za kraj): ";
                std::string unos;
                std::getline(std::cin, unos);
                if(unos=="kraj")return 0;
                double argument(std::stod(unos));
                auto f(LinearnaInterpolacija( [](double x){ 
                    return double(x*x+std::sin(x));
                    }
                    , x_min, x_max, delta_x) );
            
                try{
                    std::cout << "f(" << argument << ") = " << argument*argument+std::sin(argument) << " fapprox(" << argument << ") = " << f(argument) << "\n"; 
                }
                catch(std::range_error &e){
                    std::cout << e.what() << "\n";
                }
            }
        }
        catch(std::domain_error &e){
            std::cout << e.what();
            return 0;        
        }
    }
    
	return 0;
}
