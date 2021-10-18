/B2016/2017: Zadaća 3, Zadatak 1
//Autotestovi by Enil Pajic (epajic1@etf.unsa.ba)
#include <iostream>
#include<cmath>
#include<functional>
#include<stdexcept>
#include<utility>
#include<list>
#include<vector>
#include<iomanip>

std::function<double(double)> BaricentricnaInterpolacija(std::vector<std::pair<double,double>> cvoroviInterpolacije, double d)
{
    int brojCvorova=cvoroviInterpolacije.size();
    if(d>brojCvorova || d<0) throw std::domain_error("Nedozvoljen red");
    else 
    {
        for(int i=0;i<brojCvorova;i++)
        for(int j=0;j<brojCvorova;j++)
        if(j!=i && cvoroviInterpolacije[i]==cvoroviInterpolacije[j]) throw std::domain_error("Neispravni cvorovi");
    }
    return[d,cvoroviInterpolacije](double x)
    {
        
        std::vector<std::pair<double,double>> cvoroviInterpolacije1;
        cvoroviInterpolacije1.push_back(std::pair<double,double>(2.3,2.5));
        for(int i=0;i<cvoroviInterpolacije.size();i++)
        cvoroviInterpolacije1.push_back(cvoroviInterpolacije[i]);
        
        
        
        
        
        
        double donjaGranica,gornjaGranica;
        int brojCvorova=cvoroviInterpolacije.size();
        double rezultat=0;
         double brojnikRezultata=0,nazivnikRezultata=0,tezina;
        for(int i=0;i<brojCvorova;i++)
        if(x==cvoroviInterpolacije[i].first)
        {
            rezultat=cvoroviInterpolacije[i].second;
            return rezultat;
        }
        
        for(int i=1;i<=brojCvorova;i++)
        {
            tezina=0;
             donjaGranica=i-d;
             gornjaGranica=brojCvorova-d;
            if(gornjaGranica>i) gornjaGranica=i;
            if(donjaGranica<1) donjaGranica=1;
            for(int p=donjaGranica;p<=gornjaGranica;p++)
            {
                double rez=1.0;
                int gg=d+p;
                for(int k=p;k<=gg;k++)
                {
                    if(k!=i)
                    {
                        double pomocna1=(cvoroviInterpolacije1[i].first-cvoroviInterpolacije1[k].first);
                        rez=rez*1.0/pomocna1;
                    }
                }
                if(p%2==0)
                tezina= tezina-rez;
                else
                tezina=tezina+rez;
            }
              
            double pomc=x-cvoroviInterpolacije1[i].first;
            nazivnikRezultata+=tezina/pomc;
            brojnikRezultata+=tezina*cvoroviInterpolacije1[i].second/pomc;
            
        }
        return brojnikRezultata/nazivnikRezultata;
    };
    
}


std::function<double(double)> BaricentricnaInterpolacija(std::function<double(double)> f, double xmin, double xmax, double dx, double korak)
{
    if(xmax<xmin) throw std::domain_error("Nekorektni parametri");
    std::vector<std::pair<double,double>> cvoroviInterpolacije;
    while(xmin<=xmax)
    {
        std::pair <double,double> par (xmin,f(xmin));
        cvoroviInterpolacije.push_back(par);
        xmin+=dx;
    }
    return BaricentricnaInterpolacija(cvoroviInterpolacije,korak);
}


double xxs(double x)
{
    double kvadrat=x*x;
    double sinus=sin (x);
    double rez=kvadrat+sinus;
    return rez;
}


int main ()
{
    int opcija;
    std::cout<<"Odaberite opciju (1 - unos cvorova, 2 - aproksimacija): ";
	std::cin>>opcija;
	if(opcija==2)
	{
	    int d;
	    double xmin,xmax,dx;
	    std::cout<<"Unesite krajeve intervala i korak: ";
	    std::cin>>xmin;
	    std::cin>>xmax;
	    std::cin>>dx;
	    std::cout<<"Unesite red interpolacije: ";
	    std::cin>>d;
	    double argument;
	    std::function<double(double)> rezultat=BaricentricnaInterpolacija([](double x)->double{return x*x+sin(x*3.1415926535/180);},xmin,xmax,dx,d);
	    for(;;)
     {
         std::cout<<"Unesite argument (ili \"kraj\" za kraj): ";
         std::cin>>argument;
         if(std::cin.fail()) break;
         std::cout<<"f("<<argument<<") = "<<xxs(argument)<< " ";
         std::cout<<"fapprox("<<argument<<") = "<<rezultat(argument)<<std::endl;
     }
	}
	else
	{
	    int brojCvorova;
	    int d;
	    std::vector<std::pair<double,double>> cvoroviInterpolacije;
	    std::cout<<"Unesite broj cvorova: ";
	    std::cin>>brojCvorova;
	    std::cout<<"Unesite cvorove kao parove x y: ";
	    double a;
	    double b;
	    for(int i=0;i<brojCvorova;i++)
	    {
	        std::cin>>a;
	        std::cin>>b;
	        cvoroviInterpolacije.push_back(std::pair<double,double>(a,b));
	    }
	    std::cout<<"Unesite red interpolacije: ";
     std::cin>>d;
     std::function<double(double)> rezultat=BaricentricnaInterpolacija(cvoroviInterpolacije,d);
     double argument;
     for(;;)
     {
         std::cout<<"Unesite argument (ili \"kraj\" za kraj): ";
         std::cin>>argument;
         if(std::cin.fail()) break;
         std::cout<<"f("<<argument<<") = "<<rezultat(argument)<<std::endl;
     }
	}   
	return 0;
}