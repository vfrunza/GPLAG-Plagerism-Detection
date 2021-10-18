/B2017/2018: Zadaća 3, Zadatak 1
#include <iostream>
#include <stdexcept>
#include <vector>
#include <algorithm>
#include <utility>
#include <functional>
#include <cmath>

bool JesuLiJednaki (double x, double y, double Eps = 1e-10) {
    return std::fabs(x-y) <= Eps * (std::fabs(x) + std::fabs(y));
}
bool JeLiManji (double x, double y) {
    return x<y && !JesuLiJednaki(x,y);
}


typedef std::pair<double, double> par; 
std::function <double(double)> LinearnaInterpolacija (std::vector<par> v){
    std::sort(std::begin(v), std::end(v), [](par x, par y) {return x.first<y.first; });
    for (int i=0; i<int(v.size())-1; i++) {
        for (int j=i+1; j<v.size(); j++){
            if (JesuLiJednaki(v.at(i).first,v.at(j).first)) throw std::domain_error ("Neispravni cvorovi"); 
        }
    }
        std::vector<double> vx, vy;
        for (auto k : v) {
            vx.push_back(k.first);
            vy.push_back(k.second);
        }
        
        
    return [vx, vy] (double x){
        if (JeLiManji(x, vx.at(0)) || JeLiManji(vx.at(vx.size()-1), x )) throw std::range_error ("Argument izvan opsega"); 
        if (JesuLiJednaki(x, vx.at(vx.size()-1)) ) return vy.at(vy.size()-1);   
        auto gornjixi (std::lower_bound(std::begin(vx), std::end(vx), x ));
        auto donjixi (std::upper_bound(std::begin(vx), std::end(vx), x)-1 );
        auto gornjix (*gornjixi); 
        auto donjix (*donjixi);
        int razlikag,razlikad;
        razlikag = gornjixi-std::begin(vx);
        razlikad = donjixi-std::begin(vx);
        auto gornjiy  (*( std::begin(vy) + razlikag  ));
        auto donjiy (*( std::begin(vy) + razlikad  ));
        return donjiy + (gornjiy-donjiy)/(gornjix-donjix)*(x-donjix); 
    };
}
std::function <double(double)> LinearnaInterpolacija (std::function<double(double)> f, double xmin, double xmax, double dx ){
std::vector<double> vx,vy; 
int i (0);
if (JeLiManji(xmax, xmin) || JeLiManji(dx, 0) || JesuLiJednaki(dx,0)) throw std::domain_error("Nekonkretni parametri");

for (; ;) {
    if (!JeLiManji(xmin+dx*i, xmax) && !JesuLiJednaki(xmin+dx*i, xmax)) break;
    vx.push_back (xmin+dx*i);
    vy.push_back (f(xmin+dx*i));
    i++;
}


 return [vx, vy, f] (double x){
        if (JeLiManji(x, vx.at(0)) || JeLiManji(vx.at(vx.size()-1), x )) throw std::range_error ("Argument izvan opsega"); 
        if (JesuLiJednaki(x, vx.at(vx.size()-1)) ) return vy.at(vy.size()-1);   
        auto  gornjix (*std::lower_bound(std::begin(vx), std::end(vx), x ));
        auto  donjix (*(std::upper_bound(std::begin(vx), std::end(vx), x)-1 ));
        auto  gornjiy (f(gornjix) );
        auto  donjiy (f(donjix) );
        return donjiy + (gornjiy-donjiy)/(gornjix-donjix)*(x-donjix); 
    };

    
}
int main ()
{
    std::cout<<"Odaberite opciju (1 - unos cvorova, 2 - aproksimacija): ";
    int o;
    std::cin>>o; 
    if (o == 1) {
        std::cout<<"Unesite broj cvorova: ";
        int n;
        std::cin>>n;
        std::vector<par> v;
        std::cout<<"Unesite cvorove kao parove x y: ";
        double x,y;
        for (int i=0; i<n; i++){
            std::cin>>x>>y;
            par p{x,y};
            v.push_back(p);
        } try {
        LinearnaInterpolacija ( v) ; }
        catch (...) {
            
            std::cout<<"Neispravni cvorovi"; 
            return 0; 
            
        }
    for (;;){
        double a;
        std::cout<<"Unesite argument (ili \"kraj\" za kraj): ";
        std::cin>>a; 
        if (!std::cin) break;  try {
        std::cout<<"f("<<a<<") = "<<LinearnaInterpolacija(v)(a)<<"\n"; }
        catch (std::domain_error e){
            std::cout<<e.what()<<"\n";
        }
        catch (std::range_error e){
            std::cout<<e.what()<<"\n";
        }
        
    }
    }
    if (o == 2) {
        std::cout<<"Unesite krajeve intervala i korak: ";
        double xmin, xmax, dx,a;
        std::cin>>xmin>>xmax>>dx;
        for (; ;){
        std::cout<<"Unesite argument (ili \"kraj\" za kraj): ";
        std::cin>>a; 
        if (!std::cin) break; try {
        std::cout<<"f("<<a<<") = "<<a*a+std::sin(a)<<" fapprox("<<a<<") = " << LinearnaInterpolacija([](double x){return x*x+std::sin(x);}, xmin, xmax,dx)(a)<<"\n"; }
        catch (std::domain_error e){
            std::cout<<e.what()<<"\n";
        }
        catch (std::range_error e){
            std::cout<<e.what()<<"\n";
        }
        }
    }
    
	return 0;
}
