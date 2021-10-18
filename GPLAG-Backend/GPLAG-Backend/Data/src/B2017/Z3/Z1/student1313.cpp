/B2017/2018: Zadaća 3, Zadatak 1
#include <iostream>
#include <stdexcept>
#include <functional>
#include <utility>
#include <vector>
#include <algorithm>
#include <cmath>

std::function<double (double)> LinearnaInterpolacija (std::vector<std::pair<double, double>>v) {
  
    std::sort (v.begin(), v.end(), [] (std::pair <double, double> par1, std::pair<double, double> par2) {
        return par1.first<par2.first;
    });
    
   
    return [v] (double x) {
        auto pom_x=std::make_pair(x,0);
        
        auto min=v[0].first; auto max=v[v.size()-1].first;
        if (x<min || x>max) throw std::range_error ("Argument izvan opsega");
        
        
        if (x==v[v.size()-1].first) 
        return v[v.size()-1].second;
        
        if (x==v[0].first)
        return v[0].second;
        
         
        auto p1=v.begin();
        auto p2=v.end();
        
        auto p3 = lower_bound (p1,p2,pom_x, 
        [] (std::pair<double, double> par1, std::pair<double, double> par2) { 
            return par1.first<par2.first; } );
        auto p4=p3-1;
        double fx = p4->second + ((p3->second-p4->second)/(p3->first-p4->first) * (pom_x.first-p4->first));
        return fx;
    };
    
}

std::function<double (double)> LinearnaInterpolacija (double f(double), double xmin, double xmax, double dx) {
    if (xmin>xmax || dx<=0) throw std::domain_error ("Nekorektni parametri");
    std::vector<std::pair<double,double>> v;
    for (double i=xmin; i<xmax; i+=dx) {
        double fr(i), sc(f(i));
        auto par=std::make_pair(fr,sc);
        v.push_back(par);
    }
    return LinearnaInterpolacija (v);
}

double fja (double x) {
    return x*x+sin(x);
}

int main ()
{
    int opcija;
    std::cout << "Odaberite opciju (1 - unos cvorova, 2 - aproksimacija): ";
    std::cin >> opcija;
    try {
        if (opcija==1) {
            
            int br;
            std::cout << "Unesite broj cvorova: ";
            std::cin >> br;
            
            std::cout << "Unesite cvorove kao parove x y: ";
            std::vector<std::pair<double, double>> v(br);
            for (int i=0; i<br; i++) {
                double fr, sc;
                std::cin >> fr >> sc;
                v[i]=std::make_pair(fr,sc);
            }
            
            for (int i=0; i<v.size(); i++) {
                for (int j=i+1; j<v.size(); j++) {
                    if (v[i].first==v[j].first) throw std::domain_error ("Neispravni cvorovi");
                }
            }
            double x;
            while (std::cin) {
             try {
               std::cout << "Unesite argument (ili \"kraj\" za kraj): ";
               std::cin >> x;
               if (!std::cin) break;
               auto fx (LinearnaInterpolacija(v));
              
               std::cout << "f(" << x << ") = " << fx(x) << std::endl;
              
            }
            catch (std::range_error iz) {
                std::cout << iz.what() << std::endl;
            }
            }
            
        }
        
        if (opcija==2) {
            
            std::cout << "Unesite krajeve intervala i korak: ";
            double xmin, xmax, dx;
            std::cin >> xmin >> xmax >> dx;
            double x;
            while (std::cin) {
             try {    
                std::cout << "Unesite argument (ili \"kraj\" za kraj): ";
                std::cin >> x;
                if (!std::cin) break;
                auto fx (LinearnaInterpolacija(fja,xmin,xmax,dx));
               
                std::cout << "f(" << x << ") = " << fja(x) << " fapprox(" << x << ") = " << fx(x) << std::endl;
               
            }
        
        
        catch (std::range_error izuzetak) {
            std::cout << izuzetak.what()<< std::endl;
        }
        }
        }
    }
    
    catch (std::domain_error izuzetak) {
        std::cout << izuzetak.what();
        return 0;
    }
    
    
    
	return 0;
}
