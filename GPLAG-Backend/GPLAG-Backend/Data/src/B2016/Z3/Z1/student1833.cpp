/B2016/2017: Zadaća 3, Zadatak 1
//Autotestovi by Enil Pajic (epajic1@etf.unsa.ba)
#include <iostream>
#include<vector>
#include<utility>
#include<stdexcept>
#include<functional>
#include <cmath> 
std::function<double(double)> BaricentricnaInterpolacija(std::vector<std::pair<double,double>> cvorovi, int redInterpolacije)
{
    //provjera da li je red interpolacije u opsegu
    if(redInterpolacije<0 || redInterpolacije>cvorovi.size()) throw std::domain_error("Nedozvoljen red");
    //provjera da li postoje iste x koordinate
    for(int i=0;i<cvorovi.size();i++)
    {
        for(int j=0;j<cvorovi.size();j++)
        {
            if(i!=j)
            {
                if(cvorovi[i].first==cvorovi[j].first) throw std::domain_error("Neispravni cvorovi");
            }
        }
    }
    return [cvorovi,redInterpolacije](double x)
    {
        //ovdje provjeri da li je x zapravo jedna od tačaka
        for(int i=0;i<cvorovi.size();i++)
        if(x==cvorovi[i].first) return cvorovi[i].second;
        double rezultat=0;
        double brojnik=0;
        double nazivnik=0;
        for(int i=0;i<cvorovi.size();i++)
        {
            //racunaj tezinu wi
            double wi=0;
            int donja=0,gornja=i;
            if(donja<(i-redInterpolacije))
            donja=i-redInterpolacije;
            if(gornja>(cvorovi.size()-redInterpolacije-1))
            gornja=cvorovi.size()-redInterpolacije-1;
            for(int k=donja;k<=gornja;k++)
            {
                double koef=1.0;
                double pom=1.0;
                if(k%2==1) koef=-1.0;
                for(int j=k;j<=(k+redInterpolacije);j++)
                {
                    if(j==i) continue;
                    pom=pom/(cvorovi[i].first-cvorovi[j].first);
                    
                }
                wi=wi+koef*pom;
            }
            
        //izracunata tezina
            //sad racunaj brojnik i nazivnik
            brojnik=brojnik+wi*cvorovi[i].second/(x-cvorovi[i].first);
            nazivnik=nazivnik+wi/(x-cvorovi[i].first);
        }
        rezultat=brojnik/nazivnik;
        return rezultat;
    };
    
}


std::function<double(double)> BaricentricnaInterpolacija(std::function<double(double)> funkcija, double xmin, double xmax, double deltax,int korak)
{
    if(xmin>xmax) throw std::domain_error("Nekorektni parametri");
    std::vector<std::pair<double,double>> cvorovi;
    while(xmin<=xmax)
    {
        std::pair <double,double> par (xmin,funkcija(xmin));
        xmin+=deltax;
        cvorovi.push_back(par);
    }
    return BaricentricnaInterpolacija(cvorovi,korak);
}
double xsin(double x)
{
    return x*x+sin(x);
}
int main ()
{
    
    std::cout<<"Odaberite opciju (1 - unos cvorova, 2 - aproksimacija): ";
    int n;
    std::cin>>n;
    std::vector<std::pair<double,double>> cvorovi;
    if(n==1)
    {
     
     std::cout<<"Unesite broj cvorova: ";
     int m;
     std::cin>>m;
     std::cout<<"Unesite cvorove kao parove x y: ";
     for(int i=0;i<m;i++)
     {
         double x,y;
         std::cin>>x;
         std::cin>>y;
         std::pair<double,double> pom(x,y);
         cvorovi.push_back(pom);
     }
     std::cout<<"Unesite red interpolacije: ";
     int red;
     std::cin>>red;
     auto f=BaricentricnaInterpolacija(cvorovi,red);
     while(true)
     {
         std::cout<<"Unesite argument (ili \"kraj\" za kraj): ";
         double arg;
         std::cin>>arg;
         if(std::cin.fail()) break;
         std::cout<<"f("<<arg<<") = "<<f(arg)<<std::endl;
     }
    }
    else if(n==2)
    {
     
     std::cout<<"Unesite krajeve intervala i korak: ";
     double xmin,xmax,deltax;
     std::cin>>xmin;
     std::cin>>xmax;
     std::cin>>deltax;
     std::cout<<"Unesite red interpolacije: ";
     int red;
     std::cin>>red;
     auto f=BaricentricnaInterpolacija([](double x)->double{return x*x+sin(x*3.14159/180);},xmin,xmax,deltax,red);
     while(true)
     {
         std::cout<<"Unesite argument (ili \"kraj\" za kraj): ";
         double arg;
         std::cin>>arg;
         if(std::cin.fail()) break;
         std::cout<<"f("<<arg<<") = "<<xsin(arg)<<" ";
         std::cout<<"fapprox("<<arg<<") = "<<f(arg)<<std::endl;
     }
    }
    
    
    
	return 0;
}
