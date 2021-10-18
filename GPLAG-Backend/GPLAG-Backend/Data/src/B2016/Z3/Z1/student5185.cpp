#include <iostream>
#include <vector>
#include <cmath>
#include <functional>
#include <stdexcept>

double f(double x){
    return x*x + sin(x);
}

std::function<double(double)> BaricentricnaInterpolacija(const std::vector<std::pair< double,  double>> CvoroviInterpolacije, int d){
    
    if (d < 0 || d > CvoroviInterpolacije.size()) throw std::domain_error ("Nedozvoljen red"); 
    
    for (int i = 0; i < CvoroviInterpolacije.size(); i++) {
        for (int j = i+1; j < CvoroviInterpolacije.size(); j++) {
            if (CvoroviInterpolacije[i].first == CvoroviInterpolacije[j].first) {
                throw std::domain_error ("Neispravni cvorovi");
            }
        }
    }
    std::vector<std::pair<double, double>> testniVektor(CvoroviInterpolacije.size());
    
    
    for (int i(1); i <= CvoroviInterpolacije.size(); i++) {
        double suma(0);
        //U wi izrazu, donja granica sume se uzima kao max vr 1 ili i-d. Pa ako je i-d > 1, onda je to donji limit
        int donjiLimit(1);
        if (i-d > 1) donjiLimit = i-d;
        
        //U wi izrazu gornja granica je min vr od i i n-d. Po defaultu je i osim ako je n-d manje od i
        int gornjiLimit(i);
        if (CvoroviInterpolacije.size()-d < i) gornjiLimit = CvoroviInterpolacije.size()-d;
        
        //Petlja za sumu
        for (int k(donjiLimit); k <= gornjiLimit; k++) {
            double proizvod(1);
            for (int j(k); j <= k+d; j++){ //Petlja za produkt
                if (j == i) continue;
                proizvod *= (1/(CvoroviInterpolacije[i-1].first - CvoroviInterpolacije[j-1].first));
            }
    
            suma += pow(-1, k-1) * proizvod;
        }
      
        testniVektor[i-1].first = (suma * CvoroviInterpolacije[i-1].second);
        testniVektor[i-1].second = suma;
    }
    
    
    
    return [testniVektor, CvoroviInterpolacije] (double x)->double{
        for (int i = 0; i < CvoroviInterpolacije.size(); i++) {
            if (CvoroviInterpolacije[i].first==x) {
                return CvoroviInterpolacije[i].second;
            }
            
        }
        double wi(0), wi_yi(0);
        for (int i = 0; i < testniVektor.size(); i++) {
             wi_yi += testniVektor[i].first/(x - CvoroviInterpolacije[i].first);
             wi += testniVektor[i].second/(x - CvoroviInterpolacije[i].first);
        }
        
        return double (wi_yi/wi);
    };
}

std::function<double(double)> BaricentricnaInterpolacija(std::function<double(double)> f, double xMin, double xMax, double korak, int d){
    
    if (xMin > xMax || korak <= 0) {
        throw std::domain_error ("Nekorektni parametri");
    }
    
    double kop (xMin); int brojac(0);
    while(kop < xMax){
        brojac++;
        kop = kop + korak;
    }
    
    std::vector<std::pair<double, double>> CvoroviInterpolacije(brojac);
    
    brojac = 0;
    while(xMin < xMax){
        CvoroviInterpolacije[brojac].first = xMin; CvoroviInterpolacije[brojac++].second = f(xMin); 
        xMin += korak;
    }
    
    return BaricentricnaInterpolacija(CvoroviInterpolacije, d);
    
}


int main (){
    
    std::vector<std::pair<double, double>> CvoroviInterpolacije{{1,3}, {2,5}, {4,4}, {5,2}, {7,1}};
    
 
    std::cout << "Odaberite opciju (1 - unos cvorova, 2 - aproksimacija): "; int n; std::cin >> n;
    
    if (n == 1) {
        std::cout << "Unesite broj cvorova: "; int brCvorova; std::cin >> brCvorova;
            
        std::vector<std::pair<double, double>> CvoroviInterpolacije(brCvorova);
            
        std::cout << "Unesite cvorove kao parove x y: ";
            
        for (int i = 0; i < brCvorova; i++) {
            std::cin >> CvoroviInterpolacije[i].first; std::cin >> CvoroviInterpolacije[i].second;
        }
        
        std::cout << "Unesite red interpolacije: "; int d; std::cin >> d;
        
        double p;
        std::cout << "Unesite argument (ili \"kraj\" za kraj): "; std::cin >> p; 
        while(std::cin){
            
            auto funkcija(BaricentricnaInterpolacija(CvoroviInterpolacije, d));
            
            std::cout << "f(" <<p<< ") = " <<funkcija(p) << std::endl;
            std::cout << "Unesite argument (ili \"kraj\" za kraj): "; std::cin >> p; 
        }
      
        
    }
    
    else if (n == 2) {
        std::cout << "Unesite krajeve intervala i korak: "; double xMin, xMax, korak; std::cin >> xMin >> xMax >> korak;
        std::cout << "Unesite red interpolacije: "; int d; std::cin >> d;
        
        double p;
        std::cout << "Unesite argument (ili \"kraj\" za kraj): "; std::cin >> p; 
        while(std::cin){
            
            auto funkcija(BaricentricnaInterpolacija(f, xMin, xMax, korak, d));
            
            std::cout << "f(" <<p<< ") = " << f(p) << " fapprox(" <<p<< ") = " <<funkcija(p) << std::endl;
            std::cout << "Unesite argument (ili \"kraj\" za kraj): "; std::cin >> p; 
        }
        
    }
    else{
        std::cout << "Neispravan input" << std::endl;
    }
    

   
	return 0;
}

