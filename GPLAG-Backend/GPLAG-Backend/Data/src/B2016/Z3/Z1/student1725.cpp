#include <iostream>
#include <vector>
#include <cmath>
#include <stdexcept>
#include <functional>

double W(std::vector<std::pair<double,double>> parovi , int d , int i) {
    double suma{0};
    
    int k{i-d}; if(k<=0) k=1;
    
    int min;  min=parovi.size()-d; if(i<min) min=i; 
    
  
    for(int x=k;x<=min;x++) 
    {
        double koeficijent{pow(-1,x-1)};
        double proizvod{1};
        for(int y=x;y<=(x+d);y++)
        {
            if(parovi[i-1].first==parovi[y-1].first && i-1!=y-1) throw std::domain_error("Neispravni cvorovi");
            if((i-1)!=(y-1)) proizvod*=(1./(parovi[i-1].first-parovi[y-1].first));
        }    
            suma+=(koeficijent*proizvod); 
    }
    
    return suma;
}

//PRVA VERZIJA
    
std::function<double (double)> BaricentricnaInterpolacija(std::vector<std::pair<double,double>> parovi, int d) {
    if(d<0 || d>parovi.size()) throw std::domain_error("Nedozvoljen red");
    
    return [parovi,d](double a) {
        double brojnik{0},nazivnik{0};
        
        for(int i=1;i<=parovi.size();i++) 
        {
            if(parovi[i-1].first!=a) 
            {
                brojnik+=(W(parovi,d,i)/(a-parovi[i-1].first))*parovi[i-1].second;
                nazivnik+=(W(parovi,d,i)/(a-parovi[i-1].first));
            }
            else return parovi[i-1].second;
        }
        return brojnik/nazivnik; 
    };
}


//DRUGA VERZIJA


std::function<double (double)> BaricentricnaInterpolacija(std::function<double(double)> fun,double xmin,double xmax,double delta,int d) {
    if(xmin>xmax || delta<=0) throw std::domain_error("Nekorektni parametri");
    std::vector<std::pair<double,double>> cvorovi;
    while(1) 
    {
        cvorovi.push_back(std::make_pair(xmax,fun(xmin)));
        xmin+=delta;
        if(xmin>xmax) break;
    }
    
    if(d<0 ||d>cvorovi.size())throw std::domain_error("Nedozvoljen red");
    return [cvorovi,d,fun](double a) {
        double brojnik{0},nazivnik{0};
        
        for(int i=1;i<=cvorovi.size();i++) 
        {
            if(cvorovi[i-1].first!=a) 
            {
                brojnik+=(W(cvorovi,d,i)/(a-cvorovi[i-1].first))*cvorovi[i-1].second;
                nazivnik+=(W(cvorovi,d,i)/(a-cvorovi[i-1].first));
            }
            else return fun(a);
        }
            return brojnik/nazivnik;
        
    };
    }
    
double sinus(double x) {
    return x*x+std::sin(x);
}
    
int main ()
{
    //std::cout<<"Ispravno!";
    
    std::cout<<"Odaberite opciju (1 - unos cvorova, 2 - aproksimacija): ";
    int n; std::cin>>n;
    
    if(n==1) 
    {
        std::cout<<"Unesite broj cvorova: ";
        int brojcvorova; std::cin>>brojcvorova;
        std::cout<<"Unesite cvorove kao parove x y: ";
        
        std::vector<std::pair<double,double>> parovi;
        
        for(int i=0;i<brojcvorova;i++)
        {
            double x,y;
            std::cin>>x>>y;
            std::pair<double,double> par{std::make_pair(x,y)};
            parovi.push_back(par);
        }
        std::cout<<"Unesite red interpolacije: ";
        int d; std::cin>>d;
        
        while(1) {
            std::cout<<"Unesite argument (ili \"kraj\" za kraj): ";
            double argument; std::cin>>argument;
            if(!std::cin) break;
            try 
            {
                std::function<double (double)> f{BaricentricnaInterpolacija(parovi,d)};
                double ispis{f(argument)};
                std::cout<<"f("<<argument<<") = "<<ispis<<std::endl;
            }
            catch(std::domain_error izuzetak) {
                std::cout<<izuzetak.what()<<std::endl;
            }
        }
        
    }
    else 
    {
        std::cout<<"Unesite krajeve intervala i korake: ";
        double xmin,xmax,delta;  std::cin>>xmin>>xmax>>delta;
        
        std::cout<<"Unesite red interpolacije: ";
        int d; std::cin>>d;
        
        while(1) {
            std::cout<<"Unesite argument (ili \"kraj\" za kraj): ";
            double argument; std::cin>>argument;
            
            if(!std::cin) break;
            
            try
            {
                std::function<double (double)> f{BaricentricnaInterpolacija(sinus,xmin,xmax,delta,d)};
                double ispis{f(argument)};
                std::cout<<"f("<<argument<<") = "<<argument*argument+std::sin(argument)<<" fapprox("<<argument<<") = "<<ispis<<std::endl;
            }
            catch(std::domain_error izuzetak)
            {
                std::cout<<izuzetak.what()<<std::endl;
            }
        }
        
    }
	return 0;
}