/B2016/2017: Zadaća 3, Zadatak 1
//Autotestovi by Enil Pajic (epajic1@etf.unsa.ba)

#include <iostream>
#include <cmath>
#include <functional>
#include <stdexcept>
#include <utility>
#include <algorithm>
#include <vector>

int Min(int a, int b){
    if (a<b)
        return a;
    return b;
}

int Max(int a, int b){
    if (a>b)
        return a;
    return b;
}

double f(double x){
    return x*x+std::sin(x);
}

double TezinskiKoeficijent(std::vector<std::pair<double,double>> Cvorovi, int red, int cvor){
    
    double koeficijent(0);
    int n=Cvorovi.size();
    
    for(int i=Max(1, cvor+1-red)-1; i<=Min(cvor+1,n-red)-1;i++){
        double proizvod(1);
        for(int j=i; j<=i+red; j++){
            if(j==cvor){
                continue;
            }
            proizvod/=(Cvorovi[cvor].first-Cvorovi[j].first);
        }
        koeficijent+=(std::pow(-1,i-1) * proizvod);
    }
    return koeficijent;
}

double SumaBrojnika(std::vector<std::pair<double,double>> Cvorovi, int red, double argument, std::vector<double> w){
    
    double suma=0;

    for(int i=0; i<Cvorovi.size();i++){
        suma+=(w[i] * Cvorovi[i].second)/(argument-Cvorovi[i].first);
    }
    return suma;
}

double SumaNazivnika(std::vector<std::pair<double,double>> Cvorovi, int red, double argument, std::vector<double> w){
    
    double suma(0);
    
    for(int i=0; i<Cvorovi.size();i++){
        suma+=w[i]/(argument-Cvorovi[i].first);
    }    
    return suma;
}

std::function<double(double)> BaricentricnaInterpolacija (std::vector<std::pair<double,double>> Cvorovi, int red){
    
    if (red<0 || red>Cvorovi.size()){
        throw std::domain_error("Nedozvoljen red");
    }
    for (int i=0 ; i<Cvorovi.size() ; i++){
        for (int j=i+1 ; j<Cvorovi.size() ; j++){
            if (Cvorovi[i].first == Cvorovi[j].first){
                throw std::domain_error("Neispravni cvorovi");
            }
        }
    }
    
    std::sort(Cvorovi.begin(),Cvorovi.end(),[](std::pair<double,double> p1, std::pair<double,double> p2){return p1.first<p2.first;});
    
    std::vector<double> w;
    for(int i=0;i<Cvorovi.size();i++){
        w.push_back(TezinskiKoeficijent(Cvorovi,red,i));
    }
    
    return [red, Cvorovi,w](double argument){
        
      for (int i=0 ; i<Cvorovi.size() ; i++){
          if(argument == Cvorovi[i].first){
              return Cvorovi[i].second;
          }
      }
      return SumaBrojnika(Cvorovi,red,argument,w)/SumaNazivnika(Cvorovi,red,argument,w);}; 
}

std::function<double(double)> BaricentricnaInterpolacija (std::function<double(double)> f, double x_min, double x_max, double korak, int red){
    
    if(x_min>x_max || korak<=0){
        throw std::domain_error("Nekorektni parametri");
    }
    
    std::vector<std::pair<double,double>> cvorovi;
    double x=x_min;
    while(x<=x_max){
        cvorovi.push_back(std::make_pair(x,f(x)));
        x+=korak;
    }
        return BaricentricnaInterpolacija(cvorovi,red);
}

int main (){
    
    try{
        
        int opcija;
    std::cout<<"Odaberite opciju (1 - unos cvorova, 2 - aproksimacija): ";
    std::cin>>opcija;
    
    if(opcija==1){
        int n;
        std::cout<<"Unesite broj cvorova: ";
        std::cin>>n;
        std::vector<std::pair<double,double>> cvorovi;
        double x,y;
        std::cout<<"Unesite cvorove kao parove x y: ";
        for(int i=0;i<n;i++){
            std::cin>>x>>y;
            cvorovi.push_back(std::make_pair(x,y));
        }
        std::cout<<"Unesite red interpolacije: ";
        int d;
        std::cin>>d;
        auto f1=BaricentricnaInterpolacija(cvorovi,d);
        double vrijednost;
        for( ; ; ){
            std::cout<<"Unesite argument (ili \"kraj\" za kraj): ";
            std::cin>>vrijednost;
            if(!std::cin){
                std::cin.clear();
                std::cin.ignore(1000,'\n');
                break;
            }
            else {
                std::cout<<"f("<<vrijednost<<") = "<<f1(vrijednost)<<std::endl;
            }
        }
    }
    else if(opcija==2){
        
        double min,max,korak;
        int d;
        std::cout<<"Unesite krajeve intervala i korak: ";
        std::cin>>min>>max>>korak;
        std::cout<<"Unesite red interpolacije: ";
        std::cin>>d;
        
        auto f1=BaricentricnaInterpolacija(f,min,max,korak,d);
        
        double vrijednost;
        for( ; ; ){
            std::cout<<"Unesite argument (ili \"kraj\" za kraj): ";
            std::cin>>vrijednost;
            if(!std::cin){
                std::cin.clear();
                std::cin.ignore(1000,'\n');
                break;
            }
            else {
                std::cout<<"f("<<vrijednost<<") = "<<f(vrijednost)<<" fapprox("<<vrijednost<<") = "<<f1(vrijednost)<<std::endl;
            }
        }
        
    }
    }
    catch(std::domain_error izuzetak){
        std::cout<<izuzetak.what();
    }
	return 0;
}