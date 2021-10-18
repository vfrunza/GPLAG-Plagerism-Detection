/B2016/2017: Zadaća 3, Zadatak 1
//Autotestovi by Enil Pajic (epajic1@etf.unsa.ba)
#include <iostream>
#include <utility>
#include <functional>
#include <vector>
#include <stdexcept>
#include <cmath>

bool IstiSu (double x, double y, double a = 1e-6){
    return std::abs(x-y)<a;
}


std::function<double (double)> BaricentricnaInterpolacija (std::vector<std::pair<double, double>> v, int d){
    if(d<0 || d>=v.size())
      throw std::domain_error ("Nedozvoljen red");
    for(int i=0; i<v.size(); i++)
      for(int j=0; j<v.size(); j++)
        if(j!=i && IstiSu(v[i].first,v[j].first))
          throw std::domain_error("Neispravni cvorovi");
    std::vector<double> w(v.size());
    double izraz4(0);
    for(int i=1; i<=v.size(); i++){
        izraz4 = 0;
        int maxi, mini;
        if(1 > i -d)
          maxi = 1;
        else
          maxi = i - d;
        if(i < v.size() - d)
          mini = i;
        else 
          mini = v.size() - d;
        double izraz3(1);
        for(int k = maxi; k<=mini; k++){
            izraz3 = 1;
            izraz3*=std::pow(-1, k -1);
            for(int j= k; j<=k+d; j++){
                if(j!=i)
                  izraz3*=(1./(v[i-1].first - v[j-1].first));
            }
            izraz4+=izraz3;
        }
        w[i-1] = izraz4;
    }
   return [v, d, w] (double x){
       for(auto a : v) if(IstiSu(a.first,x)) return a.second;
       
       double izraz1(0), izraz2(0);
       for(int i=1; i<=v.size(); i++){
           
           izraz1+=(w[i-1]*v[i - 1].second)/(x - v[i - 1].first);
           izraz2+=(w[i-1])/(x - v[i -1].first);
       }
       
       return izraz1/izraz2;
   };
}


template <typename funtip>
std::function <double (double)> BaricentricnaInterpolacija (funtip f, double xmin, double xmax, double dx, int d){
    if(xmin>xmax || dx<=0)
      throw std::domain_error("Nekorektni parametri");
    std::vector<std::pair<double, double>> v;
    for(double a = xmin; a<=xmax; a+=dx)
      v.push_back({a, f(a)} );
    std::vector<double> w(v.size());
    for(int i=1; i<=v.size(); i++){
        double maxi, mini;
        if(1>i-d)
          maxi = 1;
        else maxi = i-d;
        if(i>v.size() - d)
          mini = v.size() - d;
        else
          mini = i;
        double izraz3(1), izraz4(0);
        for(int k=maxi; k<=mini; k++){
            izraz3=1;
            izraz3*=std::pow(-1, k-1);
            for(int j=k; j<=k+d; j++){
                if(j!=i)
                  izraz3*=(1./(v[i-1].first - v[j-1].first));
                  
            }
            izraz4+=izraz3;
        }
        w[i-1] = izraz4;
    }
    return [v, d, w] (double x){
        for(auto a : v) if(IstiSu(a.first,x)) return a.second;
    double izraz1(0), izraz2(0);
     for(int i=1; i<=v.size(); i++){
         
            
            izraz1+=(w[i-1]*v[i-1].second)/(x - v[i-1].first);
            izraz2+=(w[i-1])/(x - v[i-1].first);
     }
        return izraz1/izraz2;
    };
}

double fun(double x){
    return x*x + std::sin(x);
}

int main ()
{
    std::cout<<"Odaberite opciju (1 - unos cvorova, 2 - aproksimacija): ";
    int k;
    std::cin>>k;
    if(k==1){
        std::vector<std::pair<double, double>> v;
        std::cout<<"Unesite broj cvorova: ";
        int l;
        std::cin>>l;
        v.resize(l);
        std::cout<<"Unesite cvorove kao parove x y: ";
        for(int i=0; i<l; i++)
          std::cin>>v[i].first>>v[i].second;
        std::cout<<"Unesite red interpolacije: ";
        int d;
        std::cin>>d;
        try{
          auto f(BaricentricnaInterpolacija(v, d));
          do{
              std::cout<<"Unesite argument (ili \"kraj\" za kraj): ";
              double s;
              std::cin>>s;
              if(!std::cin)
                return 0;
              std::cout<<"f("<<s<<") = "<<f(s)<<std::endl;
          }while(std::cin);
          return 0;
        }
        catch(std::domain_error e){
            std::cout<<e.what();
            
        }
       
    }
    if(k==2){
        std::cout<<"Unesite krajeve intervala i korak: ";
        double a, b, c;
        std::cin>>a>>b>>c;
        std::cout<<"Unesite red interpolacije: ";
        int d;
        std::cin>>d;
        try{
            auto f(BaricentricnaInterpolacija(fun, a, b, c, d));
            do{
                std::cout<<"Unesite argument (ili \"kraj\" za kraj): ";
                double s;
                std::cin>>s;
                if(!std::cin)
                  return 0;
                std::cout<<"f("<<s<<") = "<<fun(s)<<" fapprox("<<s<<") = "<<f(s)<<std::endl;;
            }while(std::cin);
            return 0;
        }
        catch(std::domain_error e){
            std::cout<<e.what();
        }
        
    }
	return 0;
}



