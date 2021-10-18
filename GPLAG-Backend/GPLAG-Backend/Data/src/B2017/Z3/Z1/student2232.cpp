/B2017/2018: Zadaća 3, Zadatak 1
#include <iostream>
#include <functional>
#include <vector>
#include <utility>
#include <stdexcept>
#include <cmath>
#include <algorithm>

const double eps(1e-7);
typedef std::vector<std::pair<double, double>> VektorCvorova;

double f(double x){return x*x+sin(x);}

std::function<double (double)> LinearnaInterpolacija(VektorCvorova cvorovi){
    for(int i(0); i<int(cvorovi.size()); i++)
        for(int j(0); j<i; j++)
            if(fabs(cvorovi.at(i).first-cvorovi.at(j).first)<eps) throw std::domain_error("Neispravni cvorovi");
    std::sort(cvorovi.begin(), cvorovi.end(), [](std::pair<double, double> cvor1, std::pair<double, double> cvor2){
       return cvor1.first-cvor2.first<eps;
    });
    return [=](double x){
        auto it(std::lower_bound(cvorovi.begin(), cvorovi.end(), std::make_pair(x,f(x))));
        if(it==cvorovi.begin() && fabs(x-it->first)>eps) throw std::range_error("Argument izvan opsega");
        else if(cvorovi.size()>0 && fabs(cvorovi.at(cvorovi.size()-1).first-x)<eps) return cvorovi.at(cvorovi.size()-1).second;
        else if(it!=cvorovi.end()){
            if(fabs(it->first-x)<eps) return it->second;
            return (*(it-1)).second+(x-(*(it-1)).first)*(it->second-(*(it-1)).second)/(it->first-(*(it-1)).first);
        }
        else throw std::range_error("Argument izvan opsega");
    };
}

std::function<double (double)> LinearnaInterpolacija(std::function<double (double)> f, double xmin, double xmax, double dx){
    if(xmin-xmax>eps || dx<eps) throw std::domain_error("Nekorektni parametri");
    VektorCvorova cvorovi;
    for(double i(xmin); xmax-i>-eps; i+=dx) cvorovi.push_back({i, f(i)});
    return LinearnaInterpolacija(cvorovi);
}

bool UnosArgumenta(double &x){
    std::cout << "Unesite argument (ili \"kraj\" za kraj): ";
    std::cin >> x;
    if(!std::cin || std::cin.peek()!='\n') return false;
    return true;
}

int main ()
{
    std::cout << "Odaberite opciju (1 - unos cvorova, 2 - aproksimacija): ";
    int opcija;
    std::cin >> opcija;
    if(opcija==1){
        std::cout << "Unesite broj cvorova: ";
        int broj_cvorova;
        std::cin >> broj_cvorova;
        VektorCvorova cvorovi;
        std::cout << "Unesite cvorove kao parove x y: ";
        for(int i(0); i<broj_cvorova; i++){
            double x,y;
            std::cin >> x >> y;
            cvorovi.push_back({x,y});
        }
        for(;;){
            try{
                auto funkcija(LinearnaInterpolacija(cvorovi));
                double x;
                if(!UnosArgumenta(x)) break;
                std::cout << "f(" << x  << ") = " << funkcija(x) << std::endl;
            }
            catch(std::range_error e){
                std::cout << e.what() << std::endl;
            }
            catch(std::domain_error e){
                std::cout << e.what() << std::endl;
                break;
            }
        }
        
    }
    else if(opcija==2){
        std::cout << "Unesite krajeve intervala i korak: ";
        double xmin, xmax, dx;
        std::cin >> xmin >> xmax >> dx;
        for(;;){
            try{
                auto funkcija(LinearnaInterpolacija(f, xmin, xmax, dx));
                double x;
                if(!UnosArgumenta(x)) break;    
                std::cout << "f(" << x << ") = " << f(x) << " fapprox(" << x << ") = " 
                    <<  funkcija(x) << std::endl;
            }
            catch(std::range_error e){
                std::cout << e.what() << std::endl;
            }
            catch(std::domain_error e){
                std::cout << e.what() << std::endl; break;
            }
        }
    }
	return 0;
}
