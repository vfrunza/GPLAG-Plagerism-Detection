/B2016/2017: Zadaća 3, Zadatak 1
//Autotestovi by Enil Pajic (epajic1@etf.unsa.ba)
#include <iostream>
#include <utility>
#include <vector>
#include <functional>
#include <cmath>
#include <limits>
#include <stdexcept>

const double eps=std::numeric_limits<double>::epsilon();

double proizvod(int k, int d, std::vector<std::pair<double, double>> cvorovi, int i) {
    double p=1;
    for(int j(k-1); j<k+d; j++) {
        if(j!=i) p *= 1./(cvorovi[i].first-cvorovi[j].first);
    }
    return p;
}

double Izracunajdablve(std::vector<std::pair<double, double>> cvorovi, int d, int i) {
    double wi(0);
    int max,min;
    if(1>i-d) max=1;
    else max=i-d;
    if(i<cvorovi.size()-d)  min=i;
    else min=cvorovi.size()-d;
    for(int k(max); k<=min; k++) {
        wi+=std::pow(-1,k-1)*proizvod(k,d,cvorovi,i-1);
    }
    return wi;
}

double suma1(std::vector<std::pair<double, double>> cvorovi, int d, double x) {
    double suma(0);
    for(int i(0); i<cvorovi.size(); i++) {
       suma+=Izracunajdablve(cvorovi,d,i+1)*cvorovi[i].second/(x-cvorovi[i].first);
    }
    return suma;
}

double suma2(std::vector<std::pair<double, double>> cvorovi, int d, double x) {
    double suma(0);
    for(int i(0); i<cvorovi.size(); i++) {
        suma+=Izracunajdablve(cvorovi,d,i+1)/(x-cvorovi[i].first);
    }
    return suma;
}

std::function<double(double)> BaricentricnaInterpolacija(std::vector<std::pair<double, double>> cvorovi, int red) {
    if(red<0 || red>=cvorovi.size()) throw std::domain_error("Nedozvoljen red");
    for(int i(0);i<cvorovi.size();i++) {
        for(int j(i+1);j<cvorovi.size();j++) {
            if(std::fabs(cvorovi[i].first-cvorovi[j].first)<eps) throw std::domain_error("Neispravni cvorovi");
        }
    }
    return [cvorovi,red] (double x) { 
        for(int i(0);i<cvorovi.size();i++) {
            if(std::fabs(x-cvorovi[i].first)<eps) return cvorovi[i].second;
        }
        return suma1(cvorovi,red,x)/suma2(cvorovi,red,x);
    };
}

std::function<double(double)> BaricentricnaInterpolacija(std::function<double(double)> f,double xmin, double xmax, double deltax, int d) {
    if(xmin>xmax || deltax<=0) throw std::domain_error("Nekorektni parametri");
    std::vector<std::pair<double,double>> cvorovi;
    
    for(double i(xmin); i<=xmax; i+=deltax) {
        cvorovi.push_back(std::make_pair(i,f(i)));
    }
    return BaricentricnaInterpolacija(cvorovi,d);
}

int main ()
{
    int unos;
    std::cout<<"Odaberite opciju (1 - unos cvorova, 2 - aproksimacija): ";
    std::cin>>unos;
    if(unos==1) {
        int br;
        std::cout<<"Unesite broj cvorova: ";
        std::cin>>br;
        std::cout<<"Unesite cvorove kao parove x y: ";
        std::vector<std::pair<double, double>> par;
        for(int i(0); i<br; i++) {
            double x,y;
            std::pair<double, double> pom;
            std::cin>>x>>y;
            pom = std::make_pair(x,y);
            par.push_back(pom);
        }
        std::cout<<"Unesite red interpolacije: ";
        int red;
        std::cin>>red;
        try{
            auto f(BaricentricnaInterpolacija(par,red));
            double arg;
            char navodnici='"';
            while (true) {
                std::cout<<"Unesite argument (ili "<< navodnici << "kraj" << navodnici << " za kraj): ";
                std::cin>>arg;
                if(!std::cin) break;
                std::cout<<"f("<<arg<<") = "<<f(arg)<<std::endl;
            }
        }
        catch(std::domain_error e) {
            std::cout << e.what() << std::endl;
            return 1;
        }
    }
    if(unos==2) {
        double a,b,korak;
        std::cout<<"Unesite krajeve intervala i korak: ";
        std::cin>>a>>b>>korak;
        std::cout<<"Unesite red interpolacije: ";
        int red;
        std::cin>>red;
        try{
            auto fapprox(BaricentricnaInterpolacija([](double x) {return x*x+std::sin(x);},a,b,korak,red));
            double arg;
            char navodnici='"';
            while (true) {
                std::cout<<"Unesite argument (ili "<< navodnici << "kraj" << navodnici << " za kraj): ";
                std::cin>>arg;
                if(!std::cin) break;
                std::cout<<"f("<<arg<<") = "<<arg*arg+std::sin(arg)<<" fapprox("<<arg<<") = "<<fapprox(arg)<<std::endl;
            }
        }
        catch(std::domain_error e) {
            std::cout << e.what() << std::endl;
            return 1;
        }
    }
	return 0;
}