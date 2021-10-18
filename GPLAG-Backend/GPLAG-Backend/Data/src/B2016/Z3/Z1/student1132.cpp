/B2016/2017: Zadaća 3, Zadatak 1
//Autotestovi by Enil Pajic (epajic1@etf.unsa.ba)
#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#include <stdexcept>
#include <functional>
#include <cmath>
double wi(const std::vector<std::pair<double,double> >& vp,int d, int ind)
{
    double rez = 0;
    for(int k=std::max(0,ind-d); k <= std::min(ind, int(vp.size())-1-d); k++)
    {
        double xd = (k%2 ? -1 : 1);
        for(int j = k; j <= k+d; j++) if(j != ind) xd *= 1/(vp[ind].first - vp[j].first);
        rez += xd;
    }
    return rez;
}
std::function<double(double)> BaricentricnaInterpolacija(std::vector<std::pair<double,double> > vp, int d)
{
    if( d >= vp.size() || d < 0 ) throw std::domain_error("Nedozvoljen red");
    std::sort(vp.begin(), vp.end());
    for(int i=1; i<vp.size(); i++) if(vp[i].first == vp[i-1].first) throw std::domain_error("Neispravni cvorovi");
    std::vector<double> w_i(vp.size());
    for(int i=0; i<vp.size(); i++) w_i[i] = wi(vp, d, i);
    std::function<double(double)> f = [d,vp,w_i](double x)->double{
        double nazivnik=0, brojnik=0;
        for(int i=0;i<vp.size();i++)
        {
            if(x == vp[i].first) return vp[i].second;
            double pom =  w_i[i] / (x - vp[i].first);
            nazivnik += pom;
            brojnik += pom * vp[i].second;
        }
        return brojnik / nazivnik;
    };
    return f;
}
template<typename T>
std::function<double(double)> BaricentricnaInterpolacija(T funk, double x_min, double x_max, double delta_x, int d)
{
    std::vector<std::pair<double,double> > vp;
    if(x_min > x_max || delta_x < 0) throw std::domain_error("Nekorektni parametri");
    while(x_min <= x_max ) 
    {
        vp.push_back({x_min, funk(x_min)});
        x_min += delta_x;
    }
    try
    {
        auto f = BaricentricnaInterpolacija(vp, d);
        return f;
    }
    catch(...) 
    {
        throw;
    }
}


int main ()
{
   
        std::cout<< "Odaberite opciju (1 - unos cvorova, 2 - aproksimacija): ";
        int opt;
        std::cin>> opt;
        if(opt == 1)
        {
            std::cout<< "Unesite broj cvorova: ";
            int brc;
            std::cin>> brc;
            std::vector<std::pair<double,double> > vp( brc );
            std::cout<<"Unesite cvorove kao parove x y: ";
            for(auto& e: vp) std::cin>> e.first>> e.second;
            std::cout<<"Unesite red interpolacije: ";
            int d;
            std::cin>> d;
            try
            {
                auto f(BaricentricnaInterpolacija(vp, d));
                for(;;)
                {
                    std::cout<< "Unesite argument (ili \"kraj\" za kraj): ";
                    double arg;
                    if(!(std::cin>> arg)) break;
                    std::string s;
                    std::getline(std::cin, s);
                    if(s.size() != std::count(s.begin(),s.end(), ' ')) break;
                    std::cout<< "f("<<arg<<") = "<<f(arg)<<"\n";
                }
            }
            catch(std::domain_error e)
            {
                std::cout<<e.what();
                return 0;
            }
        }
        else if(opt == 2)
        {
            std::cout<<"Unesite krajeve intervala i korak: ";
            double mn, mx, kk;
            std::cin>> mn>> mx>> kk;
             std::cout<<"Unesite red interpolacije: ";
            int d;
            std::cin>> d;
            auto funk = [](double x){return x*x+std::sin(x);};
            try
            {
                auto f(BaricentricnaInterpolacija(funk, mn, mx, kk, d));
                for(;;)
                {
                    std::cout<< "Unesite argument (ili \"kraj\" za kraj): ";
                    double arg;
                    if(!(std::cin>> arg)) break;
                    std::string s;
                    std::getline(std::cin, s);
                    if(s.size() != std::count(s.begin(),s.end(), ' ')) break;
                    std::cout<< "f("<<arg<<") = "<<funk(arg)<< " fapprox("<<arg<<") = "<<f(arg)<<"\n";
                }
            }
            catch(std::domain_error e)
            {
                std::cout<<e.what();
                return 0;
            }
        }
	return 0;
}