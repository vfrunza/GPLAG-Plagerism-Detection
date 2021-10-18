/B2017/2018: Zadaća 3, Zadatak 1
#include <iostream>
#include <vector>
#include <utility>
#include <functional>
#include <algorithm>
#include <stdexcept>
#include <cmath>

using std::vector;
using std::pair;

void IspravnostCvorova(vector<pair<double,double>> cvorovi) {
    for(int i=0;i<cvorovi.size();i++) {
        for(int j=i+1;j<cvorovi.size();j++) 
            if(fabs(cvorovi.at(j).first - cvorovi.at(i).first)<=1e-10)
                throw std::domain_error("Neispravni cvorovi");
    }
}

std::function<double(double)> LinearnaInterpolacija(vector<pair<double,double>> cvorovi) {
    IspravnostCvorova(cvorovi);
    std::sort(cvorovi.begin(),cvorovi.end());
    return [cvorovi](double x) {
        if(fabs(x-cvorovi.front().first)<=1e-10) 
            return cvorovi.front().second;
        if(fabs(x-cvorovi.back().first)<=1e-10) 
            return cvorovi.back().second;
        if(x<cvorovi.front().first || x>cvorovi.back().first)
            throw std::range_error("Argument izvan opsega");
        pair<double,double> test = {x,0}; // {x,0} stavljeno samo jer lower_bound ocekuje par double-ova kao treci parametar a ne double.
        auto it2 = std::lower_bound(cvorovi.begin(),cvorovi.end(),test);
        auto it1 = it2-1;
        // Zbog preglednosti deklarisao sam posebno varijable 
        auto x1 = it1->first;
        auto y1 = it1->second;
        auto x2 = it2->first;
        auto y2 = it2->second;
        return y1 + ((y2-y1)/(x2-x1))*(x-x1);
    };
}

std::function<double(double)> LinearnaInterpolacija(std::function<double(double)> f , double xmin , double xmax , double deltax) {
    if(xmin>xmax || deltax <=0 )
        throw std::domain_error("Nekorektni parametri");
    vector<pair<double,double>> cvorovi;
    for(double i=xmin;i<=xmax+1e-15;i+=deltax) {
        cvorovi.push_back({i,f(i)});
    }
    return LinearnaInterpolacija(cvorovi);
}

double testFunkcija(double x) {
    return x*x + std::sin(x);
}

int main ()
{
    try {
        std::cout<<"Odaberite opciju (1 - unos cvorova, 2 - aproksimacija): ";
        int izbor;
        std::cin>>izbor;
        if(izbor==1) {
            std::cout<<"Unesite broj cvorova: ";
            int n;
            std::cin>>n;
            std::cout<<"Unesite cvorove kao parove x y: ";
            vector<pair<double,double>> cvorovi(n);
            for(int i=0;i<n;i++)
                std::cin>>cvorovi.at(i).first>>cvorovi.at(i).second;
            
            auto f = LinearnaInterpolacija(cvorovi);
            while(true) {
                std::cout<<"Unesite argument (ili \"kraj\" za kraj): ";
                double arg;
                std::cin>>arg;
                if(!std::cin) break;
                try {
                    std::cout<<"f("<<arg<<") = "<<f(arg)<<"\n";
                }
                catch(std::range_error e) {
                    std::cout<<e.what()<<"\n";
                }
            }
        }
        else if(izbor == 2) {
            std::cout<<"Unesite krajeve intervala i korak: ";
            double poc,kraj,korak;
            std::cin>>poc>>kraj>>korak;
            auto g = LinearnaInterpolacija(testFunkcija,poc,kraj,korak);
            while(true) {
                std::cout<<"Unesite argument (ili \"kraj\" za kraj): ";
                double arg;
                std::cin>>arg;
                if(!std::cin) break;
                try {
                    std::cout<<"f("<<arg<<") = "<<testFunkcija(arg)<<" fapprox("<<arg<<") = "<<g(arg)<<"\n";
                }
                catch(std::range_error e) {
                    std::cout<<e.what()<<"\n";
                }
            }
        }
    }
    catch(std::domain_error e) {
        std::cout<<e.what();
    }
    catch(std::range_error e) {
        std::cout<<e.what();
    }
	return 0;
}
