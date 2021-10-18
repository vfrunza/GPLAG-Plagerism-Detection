/B2016/2017: Zadaća 3, Zadatak 1
//Autotestovi by Enil Pajic (epajic1@etf.unsa.ba)
#include <iostream>
#include <vector>
#include <map>
#include <utility>
#include <stdexcept>
#include <set>
#include <functional>
#include <cmath>

double kvadriraj(int koeficijent)
{
    if(koeficijent%2==0)
    return 1;
    return -1;
}

std::function<double(double)>BaricentricnaInterpolacija(std::vector<std::pair<double,double>>ulaz,int d)
{
    
    std::vector<std::pair<double,double>>v ;
    v.resize(ulaz.size()+1);
    for(int i=1;i<ulaz.size()+1;i++)
    {
        v[i]=ulaz[i-1];
    }
    
    
    for(int i=1;i<v.size();i++)
    {
        for(int j=i+1;j<v.size();j++)
        if(v[i].first==v[j].first)
        throw std::domain_error("Neispravni cvorovi");
    }
    if(d<0 || d>v.size()-1)
    throw std::domain_error("Nedozvoljen red");
    
    return [v,d](double x)
    {
       
        
        for(int i=1;i<v.size();i++)
        {
            if(v[i].first==x)
            return v[i].second;
        }
        int n=v.size()-1;
        double donja=0;
        double gornja=0;
        double vrati;
        for(int i=1;i<v.size();i++)
        {
            double wi=0;
            int widonja;
            int wi_gornja;
            widonja=i-d;
            if(widonja<=1)
            widonja=1;
            wi_gornja=n-d;
            if(wi_gornja>=i)
            wi_gornja=i;
            for(int k=widonja;k<=wi_gornja;k++)
            {
                double proizvod=1;
                for(int j=k;j<=k+d;j++)
                if(j!=i)
                proizvod=proizvod*(double)(1/(v[i].first-v[j].first));
                wi=wi+kvadriraj(k-1)*proizvod;
            }
            gornja=gornja+(  (wi*v[i].second)/(x-v[i].first));
            
        }
        
        for(int i=1;i<v.size();i++)
        {
            
            double wi=0;
            int widonja;
            int wi_gornja;
            widonja=i-d;
            if(widonja<=1)
            widonja=1;
            wi_gornja=n-d;
            if(wi_gornja>=i)
            wi_gornja=i;
            for(int k=widonja;k<=wi_gornja;k++)
            {
                double proizvod=1;
                for(int j=k;j<=k+d;j++)
                if(j!=i)
                proizvod=proizvod*(double)(1/(v[i].first-v[j].first));
                wi=wi+kvadriraj(k-1)*proizvod;
            }
            donja=donja+wi/(x-v[i].first);
        }
        vrati=gornja/donja;
        return vrati;
    };
    
}


std::function<double(double)>BaricentricnaInterpolacija(std::function<double(double)> ulaz,double xmin,double xmax,double deltax,int d)
{
    
    if(xmin>xmax || deltax<=0)
    throw std::domain_error("Nekorektni parametri");
    std::vector<double> xkordinate;
    while (xmin<=xmax) {
        xkordinate.push_back(xmin);
        xmin=xmin+deltax;
        
    }
    
    std::vector<std::pair<double,double>>vektor;
    vektor.resize(xkordinate.size());
    for(int i=0;i<xkordinate.size();i++)
    {
        vektor[i].first=xkordinate[i];
        vektor[i].second=ulaz(xkordinate[i]);
    }
    return BaricentricnaInterpolacija(vektor,d);
    
}

double funkcija(double x)
{
    return x*x+std::sin(x);
}



int main ()
{
    try{
    std::cout<<"Odaberite opciju (1 - unos cvorova, 2 - aproksimacija): ";
    int opcija;
    std::cin>>opcija;
    if(opcija==1)
    {
        std::cout<<"Unesite broj cvorova: ";
        int broj_cvorova;
        std::cin>>broj_cvorova;
        std::vector<std::pair<double,double>> cvorovi;
        cvorovi.resize(broj_cvorova);
        std::cout<<"Unesite cvorove kao parove x y: ";
        for(int i=0;i<broj_cvorova;i++)
        {
            double prvi;
            double drugi;
            std::cin>>prvi;
            std::cin>>drugi;
            cvorovi[i].first=prvi;
            cvorovi[i].second=drugi;
        }
        std::cout<<"Unesite red interpolacije: ";
        int red_interpolacije;
        std::cin>>red_interpolacije;
        std::cout<<"Unesite argument (ili \"kraj\" za kraj): ";
        double argument;
        auto f=BaricentricnaInterpolacija(cvorovi,red_interpolacije);
        while(1)
        {
            std::cin>>argument;
            if(std::cin.peek()!=10)
            return 0;
            std::cout<<"f("<<argument<<") = "<<f(argument);
            std::cout<<"\nUnesite argument (ili \"kraj\" za kraj): ";
            
        }
        
    }
    if(opcija==2)
    {
        
        double pocetak,kraj,deltax;
        std::cout<<"Unesite krajeve intervala i korak: ";
        std::cin>>pocetak;
        std::cin>>kraj;
        std::cin>>deltax;
        std::cout<<"Unesite red interpolacije: ";
        int red_interpolacije;
        std::cin>>red_interpolacije;
        std::cout<<"Unesite argument (ili \"kraj\" za kraj): ";
        double argument;
        auto f=BaricentricnaInterpolacija(funkcija,pocetak,kraj,deltax,red_interpolacije);
        while (1) {
            std::cin>>argument;
            if(std::cin.peek()!=10)
            return 0;
            std::cout<<"f("<<argument<<") = "<<funkcija(argument)<<" "<<"fapprox("<<argument<<") = "<<f(argument);
            std::cout<<"\nUnesite argument (ili \"kraj\" za kraj): ";
        }
        
    }
    }
    catch(std::domain_error izuzetak)
    {
        std::cout<<izuzetak.what();
    }
   
return 0;
}