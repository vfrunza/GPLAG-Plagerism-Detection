/B2016/2017: Zadaća 3, Zadatak 1
//Autotestovi by Enil Pajic (epajic1@etf.unsa.ba)
#include <iostream>
#include <vector>
#include <utility>
#include <cmath>
#include <functional>

double f(double x){
    return (x*x)+std::sin(x);
}

double w(std::vector<std::pair<double,double>>v,const int d,int i){
     double suma=0;
   int vel=v.size();
       for(int k=std::max(1,i-d);k<=std::min(i,(vel)-d);k++) {
           double broj=1;
           suma=suma+pow(-1,k-1);
           for(int j=k;j<=k+d;j++){
              if(j!=i && i<vel && j<vel && i>0 && j>0){
                   broj=broj*(1./(v[i-1].first-v[j-1].first));}
           }
           suma=suma*broj;
       }
     return suma;
}

std::function<double(double)> BaricentricnaInterpolacija(std::vector<std::pair<double,double>> v, int d){
   return[v,d](double arg){
       int vel=v.size();   
   double suma=0;
 
   for(int i=0;i<vel;i++)
   if(v[i].first==arg) return v[i].second;
   
   for(int i=1;i<=vel;i++){
    if(i-1<vel)
       suma=suma+(w(v,d,i)*v[i-1].second)/(arg-v[i-1].first);
   }
   
    double suma1=0;
   for(int i=1;i<=vel;i++){
   if(i-1<vel)
       suma1=suma1+(w(v,d,i)/(arg-v[i-1].first));
   } 
   return suma/suma1;};
}

std::function<double(double)> BaricentricnaInterpolacija(std::function<double(double)>f,double xmin, double  xmax, double dx, int d){
    std::vector<std::pair<double,double>> v;
    while(xmin<=xmax){
        v.push_back({xmin,f(xmin)});
        xmin=xmin+dx;
    }
    return BaricentricnaInterpolacija(v,d);
}

int main ()
{
    int x;
    std::cout<<"Odaberite opciju (1 - unos cvorova, 2 - aproksimacija): ";
    std::cin>>x;
    if(x==1){
    int n;
    std::cout<<"\nUnesite broj cvorova: ";
    std::cin>>n;
    
    std::cout<<"Unesite cvorove kao parove x y: ";
        
     std::vector<std::pair<double,double>> v(n);
    for(int i=0;i<n;i++){
        double a,b;
        std::cin>>a>>b;
        v[i].first=a;
        v[i].second=b;
    }

     int d;
    std::cout<<"\nUnesite red interpolacije: ";
    std::cin>>d;
    
 do{
    double arg;
    std::cout<<"\nUnesite argument (ili 'kraj' za kraj): ";
    std::cin>>arg;
    if(!std::cin) return 0;
  
    std::cout<<"f("<<arg<<") = "<<BaricentricnaInterpolacija(v,d)(arg)<<"\n";
    }while(std::cin);
    }
    
    else if(x==2){
        int a,b;
        double korak;
     std::cout<<"Unesite krajeve intervala i korak: ";
     std::cin>>a>>b>>korak;
     int red;
     std::cout<<"\nUnesite red interpolacije: ";
     std::cin>>red;
     double arg;
     std::cout<<"\nUnesite argument (ili 'kraj' za kraj): ";
     std::cin>>arg;
     
     std::cout<<"f("<<arg<<") = "<<f(arg)<<" fapprox("<<arg<<") = "<<BaricentricnaInterpolacija(f,a,b,korak,red)(arg);
    }
	return 0;
}