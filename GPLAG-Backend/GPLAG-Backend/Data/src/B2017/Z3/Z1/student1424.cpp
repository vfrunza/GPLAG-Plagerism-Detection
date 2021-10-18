#include <iostream>
#include <algorithm>
#include <utility>
#include <vector>
#include <functional>
#include <cmath>

 const double eps(1e-10);
bool kriterij(std::pair<double,double> p1, std::pair<double,double> p2)
{
    return p1.first<p2.first;
}
std::function<double(double)>LinearnaInterpolacija(std::vector<std::pair<double,double>> cvorovi)
{
    std::sort(cvorovi.begin(), cvorovi.end(), kriterij);
    if(std::unique(cvorovi.begin(), cvorovi.end(), [](std::pair<double, double> p1, std::pair<double,double> p2) {
    return std::fabs(p1.first-p2.first)<eps;
})!=cvorovi.end())
    throw std::domain_error("Neispravni cvorovi");
    return [cvorovi](double x) {
        if(std::fabs(x-cvorovi[cvorovi.size()-1].first)<eps) return cvorovi[cvorovi.size()-1].second;
        auto it(std::upper_bound(cvorovi.begin(), cvorovi.end(), std::make_pair(x,0), kriterij));
        if(it==cvorovi.end() || it==cvorovi.begin()) throw std::range_error("Argument izvan opsega");
        return (*(it-1)).second+((*it).second-(*(it-1)).second)/((*it).first-(*(it-1)).first)*(x-(*(it-1)).first);
    };
}

std::function<double(double)>LinearnaInterpolacija (std::function<double(double)> fun, double x_min, double x_max, double delta)
{
    if(x_min>x_max || delta<=0) throw std::domain_error("Nekorektni parametri");
    std::vector<std::pair<double,double>> cvorovi;
   
    double korak(x_min);
    for(;;) {
        cvorovi.push_back({korak, fun(korak)});
        if(std::fabs(korak-x_max)<eps) break;
        korak+=delta;
    }
    return LinearnaInterpolacija(cvorovi);
}
int main ()
{
    int opcija;
    std::cout<<"Odaberite opciju (1 - unos cvorova, 2 - aproksimacija): ";
    std::cin>>opcija;
    try{
    if(opcija==1 || opcija==2) {
 std::function<double(double)> fun,approx;

        if(opcija==1) {
            std::cout<<"Unesite broj cvorova: ";
            int n;
            std::cin>>n;
            std::vector<std::pair<double, double>> cvorovi(n) ;
            std::cout<<"Unesite cvorove kao parove x y: ";
            double x,y;
            for(int i=0; i<n; i++) {   std::cin>>x; std::cin>>y;
                cvorovi[i]=std::make_pair(x,y);
            }
            fun=LinearnaInterpolacija(cvorovi);
        }
        if(opcija==2) {
            std::cout<<"Unesite krajeve intervala i korak: ";
            double x_min, x_max, korak;
           fun=([](double x) { return x*x+std::sin(x);});
            std::cin>>x_min; std::cin>>x_max; std::cin>>korak;
      approx=LinearnaInterpolacija(fun, x_min, x_max, korak);}
        for(;;) {
            std::cout<<"Unesite argument (ili \"kraj\" za kraj): ";
            double x,t;
            std::cin>>x;
            if(!std::cin || (std::cin.peek()!=' ' && std::cin.peek()!='\n' )) break;
                  try{ if(opcija==2) t=approx(x);  std::cout<<"f("<<x<<") = "<<fun(x);
                  if(opcija==2) std::cout<<" "<<"fapprox("<<x<<") = "<<t; std::cout<<std::endl;} 
                  catch(std::range_error izuzetak){ std::cout<<izuzetak.what()<<std::endl;}
catch(std::domain_error izuzetak){std::cout<<izuzetak.what()<<std::endl;}
                  
        }
} }catch(std::range_error izuzetak){ std::cout<<izuzetak.what();}
catch(std::domain_error izuzetak){std::cout<<izuzetak.what();}

return 0;
}
