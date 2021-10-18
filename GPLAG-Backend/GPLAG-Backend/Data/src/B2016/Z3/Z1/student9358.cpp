/B2016/2017: Zadaća 3, Zadatak 1
//Autotestovi by Enil Pajic (epajic1@etf.unsa.ba)
#include <iostream>
#include <vector>
#include <stdexcept>
#include <cmath>
#include <functional>
#include <utility>
#include <iomanip>

int Mini(int a, int b){
    if (a<b) return a;
    return b;
}

int Maxi(int a, int b){
    if(a>b) return a;
    return b;
}

std::function<double(double)> BaricentricnaInterpolacija(std::vector<std::pair<double,double>> cvorovi, int red){
    if (red<0 || red>cvorovi.size()) throw std::domain_error("Nedozvoljen red");
    for(int i=0;i<cvorovi.size();i++){
        for(int j=i+1;j<cvorovi.size();j++){
            if(cvorovi[i].first==cvorovi[j].first) throw std::domain_error("Neispravni cvorovi");
        }
    }
    std::vector<double> vektor;
    double suma(0), pro(1);
    int n=cvorovi.size();
    for(int i=0;i<n;i++){
        suma=0;                                     //racunanje svakog od wi 
        int mini=Mini(i+1,n-red)-1;
        int k=Maxi(1,i+1-red)-1;
        for(int a=k;a<=mini;a++){
            pro=1;
            for(int j=a;j<=a+red;j++){
                if(j!=i) pro=pro*(1./(cvorovi[i].first-cvorovi[j].first));
            }
            pro=pro*(std::pow(-1,a-1));
            suma=suma+pro;
        }
        vektor.push_back(suma);                            //dodavanje svakog wi u vektor
    }
    return [cvorovi,vektor,n] (double x) {
                double suma1(0),suma2(0);
                for(int i=0;i<n;i++) {
                    if(x==cvorovi[i].first) return cvorovi[i].second;
                    else{
                        suma1=suma1+(vektor[i]*cvorovi[i].second)/(x-cvorovi[i].first);
                        suma2=suma2+(vektor[i])/(x-cvorovi[i].first);
                        }
                }
               return suma1/suma2;
    };
}


std::function<double(double)> BaricentricnaInterpolacija(double f(double), double xmin, double xmax, double deltax, int red){
    if(xmin>xmax || deltax<=0) throw std::domain_error("Nekorektni parametri");
    std::vector<std::pair<double,double>> cvorovi;
    for(double i=xmin;i<xmax;i=i+deltax){                     //pravljenje vektora cvorova
        double prvi,drugi;
        prvi=i;           
        drugi=f(i);
        auto par=std::make_pair(prvi,drugi);
        cvorovi.push_back(par);
    }    
    return  BaricentricnaInterpolacija(cvorovi,red);
}

double Pomocna(double x){
    return x*x+sin(x);
}

int main ()
{   
    int opc;
    std::cout<<"Odaberite opciju (1 - unos cvorova, 2 - aproksimacija): ";
    std::cin>>opc;
    try{
        if(opc==1){
            std::cout<<"Unesite broj cvorova: ";
            int n;
            std::cin>>n;
            std::cout<<"Unesite cvorove kao parove x y: ";
            std::vector<std::pair<double,double>> vektor(n);
            for(int i=0;i<n;i++){
                double prvi,drugi;
                std::cin>>prvi>>drugi;
                vektor[i]=std::make_pair(prvi,drugi);
            }
            std::cout<<"Unesite red interpolacije: ";
            int red;
            std::cin>>red;
            double x;
            while(std::cin){
                std::cout<<"Unesite argument (ili \"kraj\" za kraj): ";
                std::cin>>x;
                if(!std::cin) break;
                auto f(BaricentricnaInterpolacija(vektor, red));
                std::cout<<"f("<<x<<") = "<<f(x)<<std::endl;
            }
        }
       if(opc==2){
            std::cout<<"Unesite krajeve intervala i korak: ";
            double xmin, xmax, deltax;
            std::cin>>xmin>>xmax>>deltax;
            std::cout<<"Unesite red interpolacije: ";
            int red;
            std::cin>>red;
            double x;
            while(std::cin){
                std::cout<<"Unesite argument (ili \"kraj\" za kraj): ";
                std::cin>>x;
                if(!std::cin) break;
                auto f(BaricentricnaInterpolacija(Pomocna,xmin,xmax,deltax,red));
                std::cout<<"f("<<x<<") = "<<Pomocna(x)<<" fapprox("<<x<<") = "<<f(x)<<std::endl;
            }
        }
    }
    catch(std::domain_error izuzetak){
        std::cout<<izuzetak.what();
        return 0;
    }
	return 0;
}