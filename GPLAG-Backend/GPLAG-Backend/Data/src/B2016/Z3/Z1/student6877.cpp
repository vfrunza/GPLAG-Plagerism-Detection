/B2016/2017: Zadaća 3, Zadatak 1
//Autotestovi by Enil Pajic (epajic1@etf.unsa.ba)
#include <iostream>
#include <vector>
#include <map>
#include <functional>
#include <cmath>



std::function<double(double)> BaricentricnaInterpolacija(std::vector<std::pair<double,double>> vp, int d){
         int n(vp.size());
         std::vector<long double> w(n);
         for(int i=1;i<=n;i++){
             w[i-1]=0;
             for(int k=std::max(1,i-d);k<=std::min(i,n-d);k++){
                long double p(1);
                for(int j=k;j<=k+d;j++){
                    if(i!=j) p=p/(vp[i-1].first-vp[j-1].first);
                    }
                if(k%2==0) p=-p;    
                w[i-1]=w[i-1]+p;
                 
             }
         }
         return[=](double x){
         double suma1(0);
         double suma2(0);
         for(int i=0;i<n;i++){
             if(x==vp[i].first) return vp[i].second;
         }
         for(int i=0;i<n;i++){
            suma1=suma1+w[i]*vp[i].second/(x-vp[i].first);         
         }
         for(int i=0;i<n;i++){
            suma2=suma2+w[i]/(x-vp[i].first);         
         }
         return suma1/suma2;
         };
      
    }
    
std::function<double(double)> BaricentricnaInterpolacija(double f (double), double xmin, double xmax, double korak, int d){
         std::vector<std::pair<double,double>> Cvor;
         while(xmin<=xmax){
             Cvor.push_back(std::make_pair(xmin,f(xmin)));
             xmin+=korak;
         }
         int n(Cvor.size());
         std::vector<long double> v(n);
         for(int i=1;i<=n;i++){
             v[i-1]=0;
             for(int k=std::max(1,i-d);k<=std::min(i,n-d);k++){
                 long double p(1);
                 for(int j=k;j<=k+d;j++){
                     if(i!=j) p=p/(Cvor[i-1].first-Cvor[j-1].first);
                 }
                 if(k%2==0) p=-p;
                 v[i-1]=v[i-1]+p;
             }
         }
          return[=](double x){
         double suma1(0);
         double suma2(0);
         for(int i=0;i<n;i++){
             if(x==Cvor[i].first) return Cvor[i].second;
         }
         for(int i=0;i<n;i++){
            suma1=suma1+v[i]*Cvor[i].second/(x-Cvor[i].first);         
         }
         for(int i=0;i<n;i++){
            suma2=suma2+v[i]/(x-Cvor[i].first);         
         }
         return suma1/suma2;
         };
    }    
   
double xsinx (double x) {return x*x+std::sin(x);}    
int main ()
{
    std::cout << "Odaberite opciju (1 - unos cvorova, 2 - aproksimacija): ";
    int unos;
    int d;
    double arg;
    std::vector<std::pair<double,double>> vp;
    std::cin >> unos;
    switch(unos){
        case 1:
        {
        std::cout << "Unesite broj cvorova: ";
        int n;
        std::cin >> n;
        
      
        std::cout << "Unesite cvorove kao parove x y: ";
        double x,y;
        for(int i=0;i<n;i++){
            std::cin >> x >> y;
            vp.push_back(std::make_pair(x,y));
        }
        std::cout << "Unesite red interpolacije: ";
        
        std::cin >> d;
        std::cout << "Unesite argument (ili \"kraj\" za kraj): ";
        
        while(std::cin >> arg , arg!=0){
            auto f(BaricentricnaInterpolacija(vp,d));
            std::cout << "f("<<arg<<") = "<<f(arg)<<std::endl;;
            std::cin.clear();
            std::cin.ignore(1000,'\n');
            std::cout << "Unesite argument (ili \"kraj\" za kraj): ";
          
        }
    }
        break;
        case 2:{
         std::cout << "Unesite krajeve intervala i korak: ";
        double xmin,xmax,korak;
        std::cin >> xmin >> xmax >> korak;
        std::cout << "Unesite red interpolacije: ";
        
        std::cin >> d;
        std::cout << "Unesite argument (ili \"kraj\" za kraj): ";
        
        std::cin  >> arg;
        while(arg!=0){
            auto f(xsinx(arg));
            auto fapprox(BaricentricnaInterpolacija(xsinx,xmin,xmax,korak,d));
            std::cout << "f("<<arg<<") = "<<f<<" ";
            std::cout << "fapprox("<<arg<<") = "<<fapprox(arg)<<std::endl;
            std::cout << "Unesite argument (ili \"kraj\" za kraj): ";
            std::cin >> arg;
        }
        }
        break;
       
        }
    
          
	return 0;
}