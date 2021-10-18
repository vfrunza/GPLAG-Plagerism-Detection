/B2016/2017: Zadaća 3, Zadatak 1
//Autotestovi by Enil Pajic (epajic1@etf.unsa.ba)
#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#include <functional>
#include <cmath>
#include <stdexcept>

std::function<double(double)>BaricentricnaInterpolacija (std::vector<std::pair<double,double>> cvorovi, int d) {
    
    int n(cvorovi.size());
    
    if (d>n || d<0) throw std::domain_error ("Nedozvoljen red");
    
    for (int i=0; i<n-1; i++) {
        for (int j=i+1; j<n; j++) {
            if (std::abs(cvorovi[i].first-cvorovi[j].first)<0.00001) throw std::domain_error ("Neispravni cvorovi"); 
        }
    }

    return [=] (double x) {

    double suma1(0), suma2(0);
   for (int i=1; i<=n; i++) {
       double suma(0);
       
       if (std::abs(x-cvorovi[i-1].first)<0.00001) {
           return cvorovi[i-1].second; 
       }

       for (int k=std::max(1,i-d); k<=std::min(i,n-d); k++) {
          double proizvod(1);

          for (int j=k; j<=k+d; j++) {
              if (j!=i) proizvod*=(1/(cvorovi[i-1].first-cvorovi[j-1].first)); 
}
              suma+=(std::pow(-1,k-1)*proizvod);
      }
            suma1+=((suma*cvorovi[i-1].second)/(x-cvorovi[i-1].first)); 
            suma2+=suma/(x-cvorovi[i-1].first); 
   }
        
        return (suma1/suma2); 
    };
}

std::function<double(double)>BaricentricnaInterpolacija (std::function<double (double)> f, double a, double b, double c, int d) {
    
    std::vector<std::pair<double,double>> vektor;
    if (a>b || c<0) throw std::domain_error ("Nekorektni parametri");
    
    for (double i=a; i<=b; i=i+c) {
        double x(f(i)); 
        vektor.push_back(std::make_pair(i,x));
    }
    
    auto fun(BaricentricnaInterpolacija(vektor,d));
    return fun; 
}

int main ()
{
    try {
    std::cout << "Odaberite opciju (1 - unos cvorova, 2 - aproksimacija): "; 
    int n; 
    std::cin >> n; 
    
    if (n==1) {
        
        std::cout << "Unesite broj cvorova: "; 
        int broj; 
        std::cin >> broj; 
        
        std::cout << "Unesite cvorove kao parove x y: "; 
        std::vector<std::pair<double, double>> cvorovi(broj); 
        
        for (int i=0; i<broj; i++) {
            std::cin >> cvorovi[i].first >> cvorovi[i].second; 
        }
        
        std::cout << "Unesite red interpolacije: "; 
        int d; 
        std::cin >> d; 
        
        for (;;) {
            double broj1; 
            std::cout << "Unesite argument (ili " << '"' << "kraj" << '"' << " za kraj): "; 
            std::cin >> broj1; 
            
            if (!std::cin) {
            std::cin.clear(); 
            std::cin.ignore(10000, '\n');
            break; 
            }
            try {
            auto f(BaricentricnaInterpolacija(cvorovi, d)); 
            std::cout << "f(" << broj1 << ") = " << f(broj1) << std::endl; 
            }
            catch (std::domain_error) {
                throw; 
            }
        }
    }
    
    if (n==2) {
        std::cout << "Unesite krajeve intervala i korak: "; 
        double a,b,c; 
        std::cin >> a >> b >> c; 
        
        std::cout << "Unesite red interpolacije: "; 
        int d; 
        std::cin >> d; 
        
        for (;;) {
            double broj; 
            std::cout << "Unesite argument (ili " << '"' << "kraj" << '"' << " za kraj): "; 
            std::cin >> broj; 
            
            if (!std::cin) {
                std::cin.clear(); 
                std::cin.ignore(10000, '\n'); 
                break; 
            }
            try {
              auto fun([](double x) {
             return (std::pow(x,2) + std::sin(x));
             });
             
            auto f(BaricentricnaInterpolacija(fun, a, b, c, d)); 
            std::cout << "f(" << broj << ") = " << fun(broj) << " fapprox(" << broj << ") = " << f(broj) << std::endl; 
            }
            catch (std::domain_error) {
                throw; 
            }
        }
    }
    }
    catch(std::domain_error e) {
        std::cout << e.what() << std::endl; 
    }
    
  
	return 0;
}