#include <iostream>
#include <utility>
#include <vector>
#include <functional>
#include <cmath>

std::function<double(double)> BaricentricnaInterpolacija (std::vector<std::pair<double,double>>Par,int d){
    int n=Par.size();
    if(d<0 || d>n){
        throw std::domain_error ("Nedozvoljen red");
    }
    for(int i=0;i<n-1;i++){
        for( int j=i+1;j<n;j++){
              if(fabs(Par[i].first-Par[j].first) < 0.0001){
        throw std::domain_error ("Neispravni cvorovi");
    }
        }
    }
    return [n,d,Par] (double x){
    double p=0;
    double q=0;
    for(int i=1;i<=n;i++){
        double w(0);
        if(fabs(x-Par[i-1].first) < 0.0001){
        return Par[i-1].second;
    }
    for(int k=std::max(1,i-d);k<=std::min(i,n-d);k++){
        double p=1;
    for(int j=k;j<=k+d;j++){
        if(j!=i){
            p*=1/(Par[i-1].first-Par[j-1].first);
        }
    }
        w=w+p*pow(-1,k-1);
    }
   
    double u=w/(x-Par[i-1].first);
    p=p+u*Par[i-1].second;
    q=q+u;
    }
    return p/q;
};
}
  std::function<double(double)>BaricentricnaInterpolacija(std::function<double(double)> f,double a,double b,double k,int d){
      std::vector<std::pair<double,double>>Parovi;
      if(b<a || k<=0){
          throw std::domain_error("Nekorektni parametri");
      }
      for(double i=a;i<=b;i=i+k){
          double x=i;
        double y=f(x);
        Parovi.push_back(std::make_pair(x,y));
      }
      return BaricentricnaInterpolacija(Parovi,d);
  }
  
int main ()
{ 
    int a;
    std::cout<<"Odaberite opciju (1 - unos cvorova, 2 - aproksimacija): ";
    std::cin>>a;
    if (a==1){
        try{
        int n,d;
        double x,y,m;
        std::vector<std::pair<double,double>> p;
        std::cout<<"Unesite broj cvorova: ";
        std::cin>>n;
        std::cout<<"Unesite cvorove kao parove x y: ";
        for(int i=0;i<n;i++){
            std::cin>>x>>y;
            p.push_back(std::make_pair(x,y));
        }
        std::cout<<"Unesite red interpolacije: ";
        std::cin>>d;
        for(;;){
             std::cout<<"Unesite argument (ili \"kraj\" za kraj): ";
             std::cin>>m;
              if(!std::cin){
           break; 
        }
            auto f(BaricentricnaInterpolacija(p,d));
            std::cout<<"f("<<m<<") = "<<f(m)<<std::endl;
       
        }
    }
          catch (std::domain_error Greska) {
        std::cout<<Greska.what();
    }
    }
    if(a==2){
     try{
         double a,b,c,m;
         int d;
         std::cout<<"Unesite krajeve intervala i korak: ";
         std::cin>>a>>b>>c;
         std::cout<<"Unesite red interpolacije: ";
         std::cin>>d;
          for(;;){
             std::cout<<"Unesite argument (ili \"kraj\" za kraj): ";
             std::cin>>m;
              if(!std::cin){
           break; 
        }
        auto f(BaricentricnaInterpolacija([](double x){ return x*x+sin(x);},a,b,c,d));
            std::cout<<"f("<<m<<") = "<<m*m+sin(m)<<" fapprox("<<m<<") = "<<f(m)<<std::endl;
     }   
    }
    catch(std::domain_error Greska2){
        std::cout<<Greska2.what();
    }
    }
	return 0;
}