/B2016/2017: Zadaća 3, Zadatak 1
//Autotestovi by Enil Pajic (epajic1@etf.unsa.ba)
#include <iostream>
#include<vector>
#include<functional>
#include<algorithm>
#include<cmath>
#include<stdexcept>

using namespace std;

#define eps 0.000000001

std::function<double(double)> BaricentricnaInterpolacija(std::vector<std::pair<double,double>>cvorovi){
    if(cvorovi.size()<1) throw domain_error("Neispravan broj cvorova");
    std::sort(cvorovi.begin(),cvorovi.end(), [](std::pair<double,double>a, std::pair<double,double> b){return a.first<b.first;});
    for(int i(0); i < cvorovi.size()-1; i++)
        if(fabs(cvorovi[i].first - cvorovi[i+1].first)<eps)
            throw std::domain_error("Neispravni cvorovi");
    return [=](double x)
    {
        if(x<cvorovi.at(0).first || x>cvorovi.at(int(cvorovi.size())-1).first)
            throw std::range_error("Argument izvan opsega");
        int n = cvorovi.size();
        for(auto p : cvorovi)
        {
            if(fabs(p.first - x) < eps)
                return p.second;
        }
        
        //u slucaju da bude izbacivoa neki cudni error, samo pogledaj treba li zamijenit mjesta par i x varijablama
        
        //u slucaju da ne bude tacan rezultat i bude cudan, probaj ovo <= u >= i tjt
        auto iterator(std::lower_bound(cvorovi.begin(),cvorovi.end(),x,[](std::pair<double,double> par, int x) { return par.first<=x;}));
        
        int indeks(iterator-cvorovi.begin()-1);
        
        
        double brojnik(cvorovi.at(indeks+1).second - cvorovi.at(indeks).second);
        double nazivnik(cvorovi.at(indeks+1).first - cvorovi.at(indeks).first);
        return cvorovi.at(indeks).second + (brojnik/nazivnik)*(x-cvorovi.at(indeks).first);
    };
}


//Ovo je ok samo treba promijeniti ime funkcije
std::function<double(double)> BaricentricnaInterpolacija(std::function<double(double)> f, double xmin, double xmax,double deltax){
    if(xmin > xmax || deltax <= 0)
        throw std::domain_error("Nekorektni parametri");
    std::vector<std::pair<double,double>>cvorovi;
    while(xmin <= xmax)
    {
        double t_x,t_y;
        t_x = xmin;
        t_y = f(t_x);
        cvorovi.push_back(std::make_pair(t_x,t_y));
        xmin += deltax;
    }
    return BaricentricnaInterpolacija(cvorovi);
}

double funkcija(double x) { return x*x + sin(x); }


int main ()
{
    
    int opcija;
    std::cout<<"Odaberite opciju (1 - unos cvorova, 2 - aproksimacija): ";
    std::cin>>opcija;
    if(opcija == 1)
    {
        std::cout<<"Unesite broj cvorova: ";
        int brojCvorova;
        std::cin>>brojCvorova;
        std::vector<std::pair<double,double>>cvorovi;
        std::cout<<"Unesite cvorove kao parove x y: ";
        double x,y;
        for(int i(0); i < brojCvorova; i++)
        {
            std::cin>>x>>y;
            cvorovi.push_back(std::make_pair(x,y));
        }
        std::cout<<"Unesite red interpolacije: ";
        int d;
        std::cin>>d;
        auto f(BaricentricnaInterpolacija(cvorovi,d));
        for(;;)
        {
            std::cout<<"Unesite argument (ili \"kraj\" za kraj): ";
            double arg;
            std::cin>>arg;
            if(!std::cin) break;
            std::cout<<"f("<<arg<<") = "<< f(arg) <<std::endl; 
        }
    }
    else if(opcija == 2)
    {
        std::cout<<"Unesite krajeve intervala i korak: ";
        double xmin,xmax,deltax;
        std::cin>>xmin>>xmax>>deltax;
        std::cout<<"Unesite red interpolacije: ";
        int d;
        auto f(BaricentricnaInterpolacija(funkcija,xmin,xmax,deltax,d));
        for(;;)
        {
            std::cout<<"Unesite argument (ili \"kraj\" za kraj: ";
            double arg;
            std::cin>>arg;
            if(!std::cin) break;
            std::cout<<"f("<<arg<<") = "<<funkcija(arg)<<"fapprox("<<arg<<") = "<<f(arg)<<std::endl;
            
        
        }
    }
    
    	return 0;
}