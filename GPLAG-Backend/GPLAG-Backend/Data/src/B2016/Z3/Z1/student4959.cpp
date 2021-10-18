/B2016/2017: Zadaća 3, Zadatak 1
//Autotestovi by Enil Pajic (epajic1@etf.unsa.ba)
#include <iostream>
#include <vector>
#include <utility>
#include <stdexcept>
#include <functional>
#include <cmath>
double funkcija(double x){
    return (x*x+std::sin(x));
}
int maxi(int x, int y){
    if(x>y) return x;
    else return y;}
int mini(int x, int y){
    if(x<y) return x;
    else return y;}
std::function <double(double)> BaricentricnaInterpolacija(std::vector<std::pair<double,double>> v,int d){
    int n=v.size();
     const double epsilon=pow(10,-7);
    std::vector<double> wi;
    if(d<0 || d==v.size()) throw std::domain_error("Nedozvoljen red");
    for(int i=0;i<v.size();i++){
        for(int j=i+1;j<v.size();j++){
            
            if(fabs(v[i].first-v[j].first)<epsilon) throw std::domain_error("Neispravni cvorovi");
        }}
       double p=1;
       for(int i=1;i<=n;i++){
           int max=maxi(1,i-d);
           int min=mini(i,n-d);
           double suma=0;
            
           for(int k=max;k<=min;k++){
              p=1;
           for(int j=k;j<=(k+d);j++){
          if(j==i) continue;
           p*=(1/(v[i-1].first-v[j-1].first));}
          
             suma+=pow(-1,k-1)*p;
           
            
           }
           wi.push_back(suma);
           suma=0;
            }
           
      return [wi,v](double x){ double suma1=0,suma2=0;
      const double epsilon=pow(10,-7);
           for(int i=1;i<=v.size();i++){
               if(fabs(x-v[i-1].first)<epsilon) return v[i-1].second;
           suma1+=(wi[i-1]*v[i-1].second/(x-v[i-1].first));
           suma2+=(wi[i-1]/(x-v[i-1].first));}
           
              
           
           return (suma1/suma2);  }
        ;}
       std::function <double(double)> BaricentricnaInterpolacija(double f (double), double x_min, double x_max, double d_x, int d){
          if(x_min>x_max || d_x<=0) throw std::domain_error("Nekorektni parametri");
            std::vector<std::pair<double,double>> v;
           
            double h=x_min;
             while(h<=x_max){
               if(h>x_max) break;
               v.push_back(std::make_pair(h,f(h)));
                h+=d_x;
                
            }
               
               return [v,d](double p){
                   return BaricentricnaInterpolacija(v,d)(p);
               };
                
            
       }
            
        
int main ()
{
int n,a,d;
double x,y,broj;
int e;

double d_x,t;
std::vector<std::pair<double,double>> v;
    std::cout<<"Odaberite opciju (1 - unos cvorova, 2 - aproksimacija): ";
    std::cin>>n;
    if(n==1){ 
        std::cout<<"Unesite broj cvorova: ";
        std::cin>>a;
     std::cout<<"Unesite cvorove kao parove x y: ";
      try{ for (int i=0;i<a;i++){
        std::cin>>x;
        std::cin>>y;
        v.push_back(std::make_pair(x,y));
         }
        std::cout<<"Unesite red interpolacije: ";
        std::cin>>d;
    
  
    for(;;){
        std::cout<<"Unesite argument (ili \"kraj\" za kraj): ";
        
        std::cin>>broj;
        if(!(std::cin)) break;
        std::cout<<"f("<<broj<<") = "<<BaricentricnaInterpolacija(v,d)(broj);
        std::cout<<std::endl;
    }}
    catch(std::domain_error izuzetak){
        std::cout<<izuzetak.what();
       
    }
    }
    double x_min,x_max;
    if(n==2){try{ std::cout<<"Unesite krajeve intervala i korak: ";
    std::cin>>x_min>>x_max>>d_x;
    std::cout<<"Unesite red interpolacije: ";
    std::cin>>e;
   
   for(;;){
        std::cout<<"Unesite argument (ili \"kraj\" za kraj): ";
        std::cin>>t;
        if(!(std::cin)) break;
        auto gf=BaricentricnaInterpolacija([](double x){return (x*x+std::sin(x));},x_min,x_max,d_x,e);
        std::cout<<"f("<<t<<") = "<<funkcija(t)<<" fapprox("<<t<<") = "<<gf(t);
        std::cout<<std::endl;
    }}
    catch(std::domain_error izuzetak){
        std::cout<<izuzetak.what();
        
    }}
    
	return 0;
}