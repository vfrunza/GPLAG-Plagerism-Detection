/B2016/2017: Zadaća 3, Zadatak 1
//Autotestovi by Enil Pajic (epajic1@etf.unsa.ba)
#include <iostream>
#include <functional>
#include <utility>
#include <vector>
#include <cmath>
#include <stdexcept>
using namespace std;




std::function<double( double)> BaricentricnaInterpolacija (std::vector<std::pair<double,double>> cvorovi, int d)
{
    if(d<0 ||d>cvorovi.size()) throw std::domain_error("Nedozvoljen red");
    for(int i=0; i<cvorovi.size()-1; i++)
    {
        for(int j=i+1; j<cvorovi.size(); j++)
        {
            if(cvorovi[i].first== cvorovi[j].first)
            {
                throw std::domain_error("Neispravni cvorovi");
            }
        }
    }
    return [cvorovi, d] (double x)
    {
        double suma_brojnika(0), suma_nazivnika(0);
       
        for(int i=1; i<=cvorovi.size(); i++)
        {
            if(x==cvorovi[i-1].first) return cvorovi[i-1].second;
            double omega(0);
            for( int k=std::max(1, i-d); k<=fmin(i, cvorovi.size()-d); k++)
            {
                double proizvod(1);
                for( int j=k; j<=k+d; j++)
                {   if(j!=i)
                    {
                        proizvod=proizvod/(cvorovi[i-1].first - cvorovi[j-1].first);
                    }
                }
                omega+=proizvod * (pow(-1,k-1));
            }
            double u=omega/(x-cvorovi[i-1].first);
           suma_brojnika+=u*cvorovi[i-1].second;
           suma_nazivnika+=u;
      
        }
        
        return suma_brojnika/suma_nazivnika;
    };
}
double funkcija( double x)
{
    return (x*x + std::sin(x));
}

//druga funkcija
std::function<double(double)> BaricentricnaInterpolacija( double f(double x), double x_min, double x_max, double x_delta, int d)
{
    if(x_delta<=0) throw std::domain_error("Nekorektni parametri");
    if(x_max<x_min) throw std::domain_error("Nekorektni parametri");
    std::vector<std::pair<double,double>> vektor;
    double i=x_min;
    while( i<=x_max )
    {
        std::pair<double,double> cvor=std::make_pair(i, f(i));
        vektor.push_back(cvor);
        i=i+x_delta;
        
    }
    std::function<double(double)> g(BaricentricnaInterpolacija(vektor, d));
    return g;
}





int main ()
{
    cout<<"Odaberite opciju (1 - unos cvorova, 2 - aproksimacija): ";
    int n;
    cin>>n;
    std::vector<std::pair<double,double>> cvorovi ;
   if(n==1){
        
            cout<<"Unesite broj cvorova: ";
            int k;
            cin>>k;
            cout<<"Unesite cvorove kao parove x y: ";
            for( int i=0; i<k ; i++)
            {
                std::pair<double,double> cvor;
                double prvi;
                cin>>prvi;
                double drugi;
                cin>>drugi;
                cvor.first=prvi;
                cvor.second=drugi;
                cvorovi.push_back(cvor);
                
            }
            cout<<"Unesite red interpolacije: ";
            int d;
            cin>>d;
            do{
            cout<<"Unesite argument (ili \"kraj\" za kraj): ";
            double x;
            cin>>x;
            if(!std::cin) break;
       
       try{     auto f(BaricentricnaInterpolacija(cvorovi, d)); 
            cout<<"f("<<x<<") = "<< f(x)<<endl;
            }
            catch(std::domain_error e)
            {
                cout<<e.what()<<endl;
            }
            }while(std::cin);
       
   }
   if(n==2)
   {
       cout<<"Unesite krajeve intervala i korak: ";
       double x_min;
       double x_max;
       double x_delta;
       cin>>x_min>>x_max>>x_delta;
       cout<<"Unesite red interpolacije: ";
            int d;
            cin>>d;
        do{
            cout<<"Unesite argument (ili \"kraj\" za kraj): ";
            double x;
            cin>>x;
            if(!std::cin) break;
            try{
                auto g(BaricentricnaInterpolacija(funkcija, x_min, x_max, x_delta,d));
                cout<<"f("<<x<<") = "<<funkcija(x)<<" fapprox("<<x<<") = "<<g(x)<<endl;
            }
            catch(std::domain_error e)
            {
                cout<<e.what()<<endl;
            }
        }while(std::cin);
       
   }
  
    
    
	return 0;
}