#include <iostream>
#include <vector>
#include <functional>
#include <algorithm>
#include <cmath>

int Max(int i, int d){
    if((i-d) >= 1) return i-d;
    return 1;
}

int Min(int i, int n, int d){
    if((n-d) >= i) return i;
    return n-d;
}

double sinus(double x){
    return x*x + sin(x);
}

double W(std::vector<std::pair<double,double>> v, int d, int i){
    auto max(Max(i,d));
    auto min(Min(i,v.size(),d));
    double suma(0);
    for(auto k=max; k<=min; k++){
        double w = pow(-1,k-1);
        double proizvod(1);
        for(auto j=k; j<=k+d; j++){
            if(v[i-1].first==v[j-1].first && i-1 != j-1) throw std::domain_error ("Neispravni cvorovi");
            if(i-1 != j-1)
                proizvod *= (1./(v[i-1].first - v[j-1].first));
        }
        suma += (w*proizvod);
        proizvod=1;
    }
    return suma;
}

std::function<double (double)> BaricentricnaInterpolacija(std::vector<std::pair<double, double>> v, int d){
    if(d<0 || d>v.size()) throw std::domain_error("Nedozvoljen red");
    auto vel(v.size());
    return[v,vel,d](double x){
        double brojnik(0), nazivnik(0);
        for(auto i=1; i<=v.size(); i++){
        if(x==v[i-1].first) return v[i-1].second;
        brojnik += (W(v,d,i)/(x-v[i-1].first))*v[i-1].second;
        nazivnik += (W(v,d,i)/(x-v[i-1].first));
        }
        double funkcija(brojnik/nazivnik);
        return funkcija;
    };
}

std::function<double(double)> BaricentricnaInterpolacija(std::function<double(double)> f, double xmin, double xmax, double dx, int d){
    if(xmin > xmax || dx <= 0) throw std::domain_error("Nekorektni parametri");
    std::vector<std::pair<double,double>> v;
    for(double i=xmin; i<=xmax; i+=dx) v.push_back(std::make_pair(i,f(i)));
    if(d<0 || d>v.size()) throw std::domain_error("Nedozvoljen red");
    auto vel(v.size());
    return[v,vel,d,f](double x){
        double brojnik(0), nazivnik(0);
        for(auto i=1; i<=v.size(); i++){
        if(x==v[i-1].first) return f(x);
        brojnik += (W(v,d,i)/(x-v[i-1].first))*v[i-1].second;
        nazivnik += (W(v,d,i)/(x-v[i-1].first));
        }
        double funkcija(brojnik/nazivnik);
        return funkcija;
    };
}

int main ()
{
    std::vector<std::pair<double,double>> v;
    int opcija;
    std::cout << "Odaberite opciju (1 - unos cvorova, 2 - aproksimacija): " ;
    std::cin >> opcija;
    if(opcija==1){
        int broj_cvorova;
        std::cout << "Unesite broj cvorova: ";
        std::cin >> broj_cvorova;
        std::cout << "Unesite cvorove kao parove x y: ";
        for(int i=0; i<broj_cvorova; i++){
            int prvi, drugi;
            std::cin >> prvi >> drugi;
            v.push_back(std::make_pair(prvi,drugi));
        }
        int red_interpolacije;
        std::cout << "Unesite red interpolacije: " ;
        std::cin >> red_interpolacije;
        for(;;){
            double arg;
            std::cout << "Unesite argument (ili \"kraj\" za kraj): ";
            std::cin >> arg;
            if(!std::cin) break;
            try{
                auto rez(BaricentricnaInterpolacija(v,red_interpolacije));
                std::cout << "f(" << arg << ") = " << rez(arg) << std::endl;
            }
            catch(std::domain_error e){
                std::cout << e.what() << std::endl;
            }
        }
    }
    else if(opcija==2){
        double xmin,xmax, dx;
        std::cout << "Unesite krajeve intervala i korak: ";
        std::cin >> xmin >> xmax >> dx;
        int red_interpolacije;
        std::cout << "Unesite red interpolacije: ";
        std::cin >> red_interpolacije;
        for(;;){
            std::cout << "Unesite argument (ili \"kraj\" za kraj): ";
            double arg;
            std::cin >> arg;
            if(!std::cin) break;
            try{
                auto rez(BaricentricnaInterpolacija(sinus,xmin,xmax,dx,red_interpolacije));
                std::cout << "f(" << arg << ") = " << sinus(arg) << " fapprox(" << arg << ") = " << rez(arg) << std::endl;
            }
            catch(std::domain_error e){
                std::cout << e.what() << std::endl;
            }
        }
    }
	return 0;
}