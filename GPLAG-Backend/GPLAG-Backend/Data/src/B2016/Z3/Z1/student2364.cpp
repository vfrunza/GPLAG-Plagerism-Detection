#include <iostream>
#include <vector>
#include <functional>
#include <cmath>
#include <stdexcept>


double VeciManji(std::pair<double, double> par, bool Maxmin){
    
    if(Maxmin){
        if(par.first > par.second) return par.first;
        return par.second;
    }
    
    if(par.first < par.second) return par.first;
    return par.second;
}

double Pomocna(std::vector<std::pair<double,double>> parovi,int i, int n, int d, double broj){
    
    double Suma{};
    
    for(int k = VeciManji({1,i-d}, 1); k <= VeciManji({i,n-d}, 0); k++){
        
        double proizvod(1);
        for(int j = k; j <= k+d; j++){
            if(j == i) continue;
            proizvod *= 1 / (double)(parovi[i-1].first - parovi[j-1].first);
        }
        double SaberiMe = std::pow(-1, k-1) * proizvod;
        
        Suma += SaberiMe;
    }
    return Suma;
}


std::function<double(double)> BaricentricnaInterpolacija(std::vector<std::pair<double, double>> parovi, int d){
    
    int n(0);
    for(int i(0); i < parovi.size(); i++) n++;
    
    if(d < 0 || d > n) throw std::domain_error("Nedozvoljen red");
    
    for(int i(0); i < n; i++)
        for(int j(0); j < n; j++)
            if(parovi[i].first == parovi[j].first && i != j) throw std::domain_error("Neispravni cvorovi");
    
    return [d,n,parovi](double x){
        double br{};
        
        bool DaLiJeNekiIsti(false);
        double Gore(0);
        for(int i(1); i <= n; i++){
            if(x != parovi[i-1].first)
            Gore += (Pomocna(parovi, i, n, d, x) / (x - parovi[i-1].first) * parovi[i-1].second);
            else{
                DaLiJeNekiIsti = true;
                br = parovi[i-1].second;
                break;
            }
        }
            
        double Dole(0);
        for(int i(1); i <= n; i++){
            if(x != parovi[i-1].first)
            Dole += (Pomocna(parovi, i, n, d, x) / (x - parovi[i-1].first));
            else{
                DaLiJeNekiIsti = true;
                break;
            }
        }
            double Konacna = br;
            if(!DaLiJeNekiIsti) Konacna = Gore / Dole;
            return Konacna;
    };
}

std::function<double(double)> BaricentricnaInterpolacija(std::function<double(double)> fun, double xmin, double xmax, double delta, int d){
    
    return [=](double x){
        
        std::vector<std::pair<double, double>> parovi;
        
        for(double i = xmin; i <= xmax; i+=delta){
            if(i > xmax || delta <= 0) throw std::domain_error("Nekorektni parametri");
            parovi.push_back({i, fun(i)});
        }
        
        auto funkcija = BaricentricnaInterpolacija(parovi, d);
        return funkcija(x);
    };
}

int main ()
{
    try{
    std::vector<std::pair<double, double>> parovi;
    std::cout << "Odaberite opciju (1 - unos cvorova, 2 - aproksimacija): ";
    int opcija;
    std::cin >> opcija;
    if(opcija == 1){
        
        std::cout << "Unesite broj cvorova: ";
        int br_cvorova;
        std::cin >> br_cvorova;
        std::cout << "Unesite cvorove kao parove x y: ";
        
        for(int j(0); j < br_cvorova; j++){
            double a, b;
            std::cin >> a >> b;
            parovi.push_back({a,b});
        }
        
        std::cout << "Unesite red interpolacije: ";
        int red_interpolacije;
        std::cin >> red_interpolacije;
        
        double argument;
        
        for(;;){
            std::cout << "Unesite argument (ili " << '"' << "kraj" << '"' << " za kraj): ";
            std::cin >> argument;
            if(!std::cin) break;
            
            std::cout << "f(" << argument << ") = " << BaricentricnaInterpolacija(parovi, red_interpolacije)(argument);
            std::cout << std::endl;
        }
    }
    
        else if(opcija == 2){
            std::cout << "Unesite krajeve intervala i korak: ";
            double xmin, xmax, delta;
            std::cin >> xmin >> xmax >> delta;
            
            std::cout << "Unesite red interpolacije: ";
            int red_interpolacije;
            std::cin >> red_interpolacije;
            for(;;){
                std::cout << "Unesite argument (ili " << '"' << "kraj" << '"' << " za kraj): ";
                double argument;
                std::cin >> argument;
                if(!std::cin) break;
                
                std::function<double(double)> f([](double x){
                    return x*x + std::sin(x);
                });
                
                double Novi = BaricentricnaInterpolacija(f, xmin, xmax, delta, red_interpolacije)(argument);
                std::cout << "f(" << argument << ") = " << argument * argument + std::sin(argument);
                std::cout << " fapprox(" << argument << ") = " << Novi;
                std::cout << std::endl;
            }
        }  
        
}
catch(std::domain_error izuzetak){
    std::cout << izuzetak.what() << std::endl;
}
	return 0;
	
}