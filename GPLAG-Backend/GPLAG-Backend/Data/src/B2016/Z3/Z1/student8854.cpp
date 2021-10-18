/B2016/2017: Zadaća 3, Zadatak 1
//Autotestovi by Enil Pajic (epajic1@etf.unsa.ba)
#include <iostream>
#include <algorithm>
#include <stdexcept>
#include <vector>
#include <functional>
#include <cmath>
std::function<double(double)> BaricentricnaInterpolacija(std::vector<std::pair<double,double>> vektor, int d)
{
    
    if(d<=0 || d>=vektor.size())
    throw std::domain_error("Nedozvoljen red");
    std::vector<std::pair<double,double>> vektor1=vektor;
    std::sort(vektor1.begin(),vektor1.end());
    for(int i=0;i<int(vektor.size())-1;i++)
    {
        if(vektor1[i].first==vektor1[i+1].first && vektor1[i].second==vektor1[i+1].second)
        throw std::domain_error("Neispravni cvorovi");
    }
    std::vector<double> koeficijenti;
    for(int i=1;i<=vektor.size();i++)
    {
        double a=0;
        for(int k=std::max(1,i-d);k<=std::min(i,int(vektor.size())-d);k++)
        {
            int znak=1;
            if((k-1)%2==1)
            znak=-1;
            double proizvod=1;
            for(int j=k;j<=k+d;j++)
            {
                if(j==i) continue;
                proizvod=proizvod/(vektor[i-1].first-vektor[j-1].first);
            }
            a+=znak*proizvod;
        }
        koeficijenti.push_back(a);
    }
    return [vektor,koeficijenti](double x)
    {
        for(int i=0;i<vektor.size();i++)
        {
            if(x==vektor[i].first) return vektor[i].second;
        }
        
        double a;
        double brojnik=0;
        double nazivnik=0;
        for(int i=1;i<=vektor.size();i++)
        {
            brojnik+=(koeficijenti[i-1]*vektor[i-1].second)/(x-vektor[i-1].first);
            nazivnik+=koeficijenti[i-1]/(x-vektor[i-1].first);
        }
        
        
        return brojnik/nazivnik;
    };
}   

std::function<double(double)> BaricentricnaInterpolacija(std::function<double(double)> fun,double xmin,double xmax,double deltax,int d)
{
    if(xmin>xmax || deltax<=0) throw std::domain_error("Nekorektni parametri");
    std::vector<std::pair<double,double>>vektor;
    for(double i=xmin;i<=xmax;i+=deltax)
    vektor.push_back({i,fun(i)});
    return BaricentricnaInterpolacija(vektor,d);
}



int main ()
{
    std::vector<std::pair<double,double>> vektor;
    std::cout<<"Odaberite opciju (1 - unos cvorova, 2 - aproksimacija): ";
	int a;
	std::cin>>a;
	if(a==1)
	{
	        std::cout<<"Unesite broj cvorova: ";
	        int n;
	        std::cin>>n;
	        std::cout<<"Unesite cvorove kao parove x y: ";
	        for(int i=0;i<n;i++)
	        {
	            int x,y;
	            std::cin>>x>>y;
	            vektor.push_back({x,y});
	        }
	        std::cout<<"Unesite red interpolacije: ";
	        int red;
	        std::cin>>red;
	        for(;;)
	        {
	            std::cout<<"Unesite argument (ili \"kraj\" za kraj): ";
	            double t;
	            std::cin>>t;
	            if(!std::cin || std::cin.get()!='\n')
	            {
	                /*std::cout<<"kraj";*/
	                return 0;
	            }
	            std::function<double(double)> funkc;
	            try{
	            funkc=BaricentricnaInterpolacija(vektor,red);
	            }
	            catch(std::domain_error e)
	            {
	            	std::cout<<"Izuzetak: "<<e.what()<<std::endl;
	            	return 0;
	            }
	            std::cout<<"f("<<t<<") = "<<funkc(t)<<std::endl;
	        }
	        return 0;
	 	}
	if(a==2)
	{
	    std::cout<<"Unesite krajeve intervala i korak: ";
	    double pocetak,kraj,delta;
	    std::cin>>pocetak>>kraj>>delta;
	    std::cout<<"Unesite red interpolacije: ";
	    int red;
	    std::cin>>red;
	   
	    for(;;)
	        {
	            std::cout<<"Unesite argument (ili \"kraj\" za kraj): ";
	            double t;
	            std::cin>>t;
	            if(!std::cin || std::cin.get()!='\n')
	            return 0;
	            std::function<double(double)> funkc;
	            try{
	            funkc=BaricentricnaInterpolacija([](double x){return x*x+std::sin(x);},pocetak,kraj,delta,red);
	            }
	            catch(std::domain_error e)
	            {
	            	std::cout<<e.what()<<std::endl;
	            }
	            std::cout<<"f("<<t<<") = "<<t*t+std::sin(t)<<" fapprox("<<t<<") = "<< funkc(t)<<std::endl;
	        }
	    return 0;
	}
	return 0;
}