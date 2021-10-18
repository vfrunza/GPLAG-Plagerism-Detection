/B2016/2017: Zadaća 3, Zadatak 1
//Autotestovi by Enil Pajic (epajic1@etf.unsa.ba)
#include <iostream>
#include <vector>
#include <utility>
#include <functional>
#include <algorithm>
#include <cmath>
#include <stdexcept>
std::function<double(double)> BaricentricnaInterpolacija(std::vector<std::pair<double,double>>cvorovi, int d)
{
    int n=cvorovi.size();
    if(d<0 || d>=n) throw std::domain_error("Nedozvoljen red");
    bool neispravni_cvorovi(0);
    for(int i=0; i<n; i++)
    for(int j=i+1; j<n; j++)
    if(cvorovi[i].first-cvorovi[j].first==0.) neispravni_cvorovi=1;
    if(neispravni_cvorovi) throw std::domain_error("Neispravni cvorovi");
    std::vector<double> w(n);
    int i(1);
    while(i<=n)                                                                 //i=1, i<=5
    {
        
        for(int k=std::max(1,i-d); k<=std::min(i, n-d); k++)                    //k=1, k<=min(i, 3)=1
        {
            double proizvod(1);
            bool nije_usla_u_petlju(1);
            for(int j=k; j<=k+d; j++)                                   //j=1, j<=k+2
                {
                    if(j!=i)
                    {
                        proizvod*=1./(cvorovi[i-1].first-cvorovi[j-1].first); 
                        nije_usla_u_petlju=0;
                    }
                    else
                     continue;
                }
                
            if(!nije_usla_u_petlju)
            w[i-1]+=proizvod*std::pow(-1,k-1);
        }
        i++;
    }
    
    return [w, cvorovi](double x) {
        double suma1(0), suma2(0);
        for(int i=0; i<cvorovi.size(); i++)
        if(x-cvorovi[i].first==0.) {return cvorovi[i].second;}
        for(int i=0; i<cvorovi.size(); i++)
        {
            suma1+=w[i]*cvorovi[i].second/(x-cvorovi[i].first);
            suma2+=w[i]/(x-cvorovi[i].first);
        }
        return suma1/suma2;
        
    };
    
}
std::function<double(double)> BaricentricnaInterpolacija(std::function<double(double)> f, double x_min, double x_max, double deltax, int d)
{
    if(x_min>x_max || deltax<=0) throw std::domain_error("Nekorektni parametri");
    std::vector<std::pair<double,double>>cvorovi;
    for(double i=x_min; i<=x_max; i+=deltax)
    cvorovi.push_back(std::make_pair(i,f(i)));
    try{return BaricentricnaInterpolacija(cvorovi, d);}
    catch(...) {throw;}
    
}

int main ()
{ 
    
    std::cout<<"Odaberite opciju (1 - unos cvorova, 2 - aproksimacija): ";
    int unos;
    std::cin>>unos;
    
    if(unos==1)
    {
        int broj_cvorova;
        std::cout<<"Unesite broj cvorova: ";
        std::cin>>broj_cvorova;
        std::vector<std::pair<double,double>>cvorovi(broj_cvorova);
        std::cout<<"Unesite cvorove kao parove x y: ";
        for(int i=0; i<broj_cvorova; i++)
        std::cin>>cvorovi[i].first>>cvorovi[i].second;
        int d;
        std::cout<<"Unesite red interpolacije: ";
        std::cin>>d;
        for(;;)
        {
            std::cout<<"Unesite argument (ili \"kraj\" za kraj): ";
            double arg;
            std::cin>>arg;
            if(!std::cin) break;
            else
            {
                try{
                    BaricentricnaInterpolacija(cvorovi,d)(arg);
                    std::cout<<"f("<<arg<<") = "<<BaricentricnaInterpolacija(cvorovi,d)(arg)<<"\n";
                }
                catch(std::domain_error poruka) {std::cout<<"Izuzetak: "<<poruka.what(); break;return 0;}
            }
        }
    }
        
    else if(unos==2)
    {
        std::cout<<"Unesite krajeve intervala i korak: ";
        double xmin, xmax, korak;
        std::cin>>xmin>>xmax>>korak;
        std::cout<<"Unesite red interpolacije: ";
        int d;
        std::cin>>d;
        for(;;)
        {
            std::cout<<"Unesite argument (ili \"kraj\" za kraj): ";
            double arg;
            std::cin>>arg;
            if(!std::cin) break;
            else
            {
                try{
                    BaricentricnaInterpolacija([](double x){return x*x+std::sin(x);},xmin,xmax,korak,d)(arg);
                    std::cout<<"f("<<arg<<") = "<<[](double x){return x*x+std::sin(x);}(arg)<<" "<<"fapprox("<<arg<<") = "<<BaricentricnaInterpolacija([](double x){return x*x+std::sin(x);},xmin,xmax,korak,d)(arg)<<"\n";
                }
                catch(std::domain_error greska) {std::cout<<"Izuzetak: "<<greska.what(); return 0;}  
            
            }
            
        }
       
    }
   
	return 0;
}