/B2016/2017: Zadaća 3, Zadatak 1
//Autotestovi by Enil Pajic (epajic1@etf.unsa.ba)
#include <iostream>
#include <algorithm>
#include <utility>
#include <vector>
#include <stdexcept>
#include <cmath>
#include <iomanip>
#include <functional>
double f(double x){     //  Funkcija koja je trazena u opisu zadatka.
    return x*x+std::sin(x);
}
std::vector<double> find_w(const std::vector<std::pair<double,double>> &v,  int d){     //  Pomocu ove funkcije pronalazimo sve vrijednosti w koja nam je potrebna u zadatku.
    std::vector<double> f;
    double p(1),s(0);
    for( int i=1;i<=v.size();i++)
    {
        s=0;
        p=1;
        
    for(int k=std::max(1,i-d);k<=std::min(i,static_cast<int>(v.size()-d));k++){
        p=1;
        for(int j=k;j<=k+d;j++)
        {
            if(j==i)    continue;
            p*=1/(v[i-1].first-v[j-1].first);
        }
        if(k%2==0)  
            s-=p;
        else
            s+=p;
    }
        f.push_back(s);
    }
    return f;
}
std::function<double(double)>BaricentricnaInterpolacija(std::vector<std::pair<double,double>> v,int d){
    auto w(find_w(v,d));
    if(d<0||d>=v.size()) throw std::domain_error("Nedozvoljen red");
    for(int i=0;i<v.size();i++)
        for(int j=i+1;j<v.size();j++)
            if(v[i].first==v[j].first)  throw std::domain_error("Neispravni cvorovi");
    return [w,v](double x){
    double s1(0),s2(0);
    for(int i=0;i<v.size();i++){
        if(x==v[i].first)
            return v[i].second;
        double pom(static_cast<double>(w[i]/(x-v[i].first)));       
        s2+=pom;
        s1+=pom*v[i].second;            //  s1 je brojnik, a s2 je nazivnik u formuli. Vracamo s1/s2.
    }
    return static_cast<double>(s1/s2);};
}
std::vector<std::pair<double,double>>find_v(double x1, double x2, double dx,double fun(double)){        //  Funkcija za pronalazenje parova xi i yi.
    double s(x1);
    std::vector<std::pair<double,double>> p;
    while(s<=x2){
        p.push_back(std::pair<double,double>(s,fun(s)));
        s+=dx;
    }
    return p;
}
std::function<double(double)>BaricentricnaInterpolacija(double fun(double),double x_min, double x_max, double dx,int d)     //  Verzija funkcije sa 5 parametara.
{
    if(x_max<x_min||dx<=0)    throw std::domain_error("Nekorektni parametri");
    auto v(find_v(x_min,x_max,dx,fun));             //  Nadjemo parove (xi i yi), pa onda vracamo funkciju koja se poziva sa 2 parametra.
    return BaricentricnaInterpolacija(v,d);
}
int main ()
{
    //  Obicni main za unos i ispis (malo rogobatan napisan...).    
    std::cout<<"Odaberite opciju (1 - unos cvorova, 2 - aproksimacija): ";
    int n;
    std::cin>>n;
    if(n==1)
    {
        std::cout<<"Unesite broj cvorova: ";
        std::cin>>n;
        std::vector<std::pair<double,double>> v;
        std::cout<<"Unesite cvorove kao parove x y: ";
        for(int i=0;i<n;i++){
            double x,y;
            std::cin>>x>>y;
            v.push_back(std::pair<double,double>(x,y));
        }
        std::cout<<"Unesite red interpolacije: ";
        int d;
        std::cin>>d;
        auto fun(BaricentricnaInterpolacija(v,d));
        while(1){
            double x;
            std::cout<<"Unesite argument (ili \"kraj\" za kraj): ";
            std::cin>>x;
            if(!std::cin) return 0;
            try{
            std::cout<<"f("<<x<<") = "<<fun(x)<<std::endl;
            }
            catch(std::domain_error izuzetak)
            {
                std::cout<<izuzetak.what()<<std::endl;
                return 0;
            }
        }
    }
    else if(n==2){
        std::cout<<"Unesite krajeve intervala i korak: ";
        double x1,x2,xd;
        std::cin>>x1>>x2>>xd;
        std::cout<<"Unesite red interpolacije: ";
        int d;
        std::cin>>d;
        auto fun(BaricentricnaInterpolacija(f,x1,x2,xd,d));
        while(1){
            std::cout<<"Unesite argument (ili \"kraj\" za kraj): ";
            double x;
            std::cin>>x;
            if(!std::cin)   return 0;
            try{
            std::cout<<"f("<<x<<") = "<<f(x)<<" fapprox("<<x<<") = "<<fun(x)<<std::endl;
            }
            catch(std::domain_error izuzetak){
                std::cout<<izuzetak.what()<<std::endl;
                return 0;
            }
        }
    }
	return 0;
}