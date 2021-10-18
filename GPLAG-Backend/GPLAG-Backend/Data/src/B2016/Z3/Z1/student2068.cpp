/B2016/2017: Zadaća 3, Zadatak 1.
//Autotestovi by Enil Pajic (epajic1@etf.unsa.ba) 
#include <iostream>
#include <vector>
#include <utility>
#include <stdexcept>
#include <cmath>
#include <functional>

// AUTOTEST NE PROLAZI ZA EPS ALI ZATO RADI ZA == // GJ

#define eps (10e-7)

int maks(int x, int y) { if(x>y) return x; return y; }
int mini(int x, int y) { if(x<y) return x; return y; }

std::function<double (double)> BaricentricnaInterpolacija(std::vector<std::pair<double, double>>v, int d) {
    if(d<0 || d>=v.size()) throw std::domain_error("Nedozvoljen red");
    for(auto i=v.begin(); i!=v.end(); i++) {
        for(auto j=i+1; j!=v.end(); j++) {
            if(i->first==j->first) throw std::domain_error("Nekorektni parametri");
        }
    }
    
    //
    
    std::vector<double>omega(v.size());
    
    for(int i=1; i<=omega.size(); i++) {
        omega[i-1]=0;
        for(int k=maks(1, i-d); k<=mini(i, v.size()-d); k++) {
            double umnozak=1;
            for(int j=k; j<=k+d; j++) {
                if(i==j) continue;
                umnozak*=1./(v[i-1].first - v[j-1].first);
            }
            if(k%2==0) umnozak*=-1;
            omega[i-1]+=umnozak;
        }
    }
    
    
    return [v, omega](double x) {
        for(auto i : v) if(i.first==x) return i.second;
        double prva_suma=0, druga_suma=0;
        
        for(int i=1; i<=v.size(); i++) {
            
            prva_suma+= ( omega[i-1] * v[i-1].second ) / ( x - v[i-1].first );
            
            druga_suma+= omega[i-1] / ( x - v[i-1].first );
            
        }
        
        return prva_suma/druga_suma;
        
    };
}

template <typename Tip>
std::function<double(double)> BaricentricnaInterpolacija(Tip F, double xmin, double xmax, double deltax, int d) {
    if(xmin>xmax || deltax<=0) throw std::domain_error("Nekorektni parametri");
    
    std::vector<std::pair<double, double>>v;
    
    while(xmin <= xmax) {
        v.push_back({xmin, F(xmin)});
        xmin+=deltax;
    }
    
    return BaricentricnaInterpolacija(v, d);
    
}

int main () {
	    
    std::cout << "Odaberite opciju (1 - unos cvorova, 2 - aproksimacija): ";
    int opcija; std::cin >> opcija;
	    
    if(opcija==1) {
      std::cout << "Unesite broj cvorova: ";
    	int broj_cv; std::cin >> broj_cv;
    	std::vector<std::pair<double, double>>v;
    	std::cout << "Unesite cvorove kao parove x y: ";
    	for(int i=0; i<broj_cv; i++) {
    	    double a, b; std::cin >> a >> b;
         v.push_back({a, b});
    	}
    	std::cout << "Unesite red interpolacije: ";
    	int red; std::cin >> red;
    	        
    	for(;;) {
    	    std::cout << "Unesite argument (ili \"kraj\" za kraj): ";
    	    double arg; std::cin >> arg;
            if(!std::cin || std::cin.peek()!='\n') return 0;
	        try { 
	            auto Funkcija=BaricentricnaInterpolacija(v, red);
	            std::cout << "f(" << arg << ") = " << Funkcija(arg) << "\n"; 
	        }
	        catch(std::domain_error izuzetak) { std::cout << izuzetak.what(); return 0; }
	    }
	        
    }
	    
    else if(opcija==2) {
        std::cout << "Unesite krajeve intervala i korak: ";
    	double xmin, xmax, deltax;
        std::cin >> xmin >> xmax >> deltax;
        std::cout << "Unesite red interpolacije: ";
        int red; std::cin >> red;
        for(;;) {
	        std::cout << "Unesite argument (ili \"kraj\" za kraj): ";
	        double arg; std::cin >> arg;
	        if(!std::cin || std::cin.peek()!='\n') return 0;
	        try {
	            auto Funkcija=BaricentricnaInterpolacija([](double x) {
                    return x*x+std::sin(x);
	            }, xmin, xmax, deltax, red);
	        
                std::cout << "f(" << arg << ") = " << arg*arg+std::sin(arg) << " fapprox(" << arg << ") = " << Funkcija(arg) << "\n"; 
	        }
	        catch(std::domain_error izuzetak) { std::cout << izuzetak.what(); return 0; }
	    }
    }
    return 0;
}