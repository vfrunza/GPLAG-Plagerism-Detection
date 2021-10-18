#include <iostream>
#include <iomanip>
#include <string>
#include <new>
#include <vector>
#include <functional>
#include <cmath>
#include <stdexcept>
#include <utility>

const double eps(1e-7);
std::function<double(double)> BaricentricnaInterpolacija(std::vector<std::pair<double,double>> v,int d) {
    std::vector<double> a;
    if(d<0 || d>v.size()) throw std::domain_error("Nedozvoljen red");
    for(int i=0;i<v.size();i++) {
        for(int j=0;j<v.size();j++) {
            if(i!=j) {
                if(fabs(v[i].first-v[j].first)<eps) 
                throw std::domain_error("Neispravni cvorovi");
            }
        }
    }
    int n(0),s(0);
    double proizvod(1),w(0);
    for(int i=0;i<v.size();i++) {
        n=i-d;
        int k(0);
        if(n>1) 
            k=n;
        else 
        k=1;
        if(i>(v.size()-d)) 
        s=v.size()-d-1;
        else 
        s=i;
        w=0;
        for(;k<s;k++) {
            proizvod=1.;
                for(int j=k;j<k+d;j++) {
                    proizvod*=1./(v[i].first-v[j].first);
                    i++;
                }
                if(k%2==0) {
                    w-=proizvod;
                }
                else {
              w+=proizvod;
        }
      }
      a.push_back(w);
    }
    return [v,d,a] (double x) {
        double f(0),g(0);
        for(int z=0;z<a.size();z++) {
            if(fabs(x-v[z].first)<eps)
            return v[z].second;
            else {
                if(z<v.size()) {
            f+=a[z]/(x-v[z].first)*v[z].second;
            g+=a[z]/(x-v[z].first);
                }
            }
        }
         return f/g;
      };
}
std::function<double(double)> BaricentricnaInterpolacija(std::function<double(double)> fun,double x_min,double x_max,double delta_x,int d) {
    if(x_min>x_max || delta_x<=0) {
        throw std::domain_error("Nekorektni parametri");
    }
    
    std::vector<std::pair<double,double>> pomocni;
    for(double x=x_min;x<x_max;x+=delta_x) {
        pomocni.push_back(std::make_pair(x,x+delta_x));
    }
  return BaricentricnaInterpolacija(pomocni,d);
}
double f(double x) {
    return x*x+std::sin(x);
}
int main ()
{
    do {
    std::cout<<"Odaberite opciju (1 - unos cvorova, 2 - aproksimacija): ";
    int n(0);
    std::cin>>n;
    std::vector<std::pair<double,double>> v;
    int s(5);
    switch(n) {
        case 1:
        {
            std::cout<<"Unesite broj cvorova: ";
            std::cin>>s;
            v.resize(s);
            std::cout<<"Unesite cvorove kao parove x i y: ";
        for(int i=0;i<s;i++) {
            double r,t;
            std::cin>>r>>t;
            v[i].first=r;
            v[i].second=t;
        }
        int d;
        std::cout<<"Unesite red interpolacija: ";
        std::cin>>d;
        while(std::cin) {
        std::cout<<"Unesite argument (ili kraj za kraj): ";
        double c;
        std::cin>>c;
        try {
            if(std::cin)
        std::cout<<"f("<<c<<") = "<<std::setprecision(5)<<std::fixed<<BaricentricnaInterpolacija(v,d)(c)<<std::endl;
        else
        break;
        }
        catch(std::domain_error e) {
        std::cout<<e.what()<<std::endl;
        }
        }
        break;
    }
    case 2: 
    {
        v.resize(s);
    std::cout<<"Unesite krajeve intervala i korak: ";
    double x_min,x_max,delta_x;
    std::cin>>x_min>>x_max>>delta_x;
    std::cout<<"Unesite red interpolacije: ";
    int r;
    std::cin>>r;
      while(std::cin) {
        std::cout<<"Unesite argument (ili kraj za kraj): ";
        double c;
        std::cin>>c;
        try {
            if(std::cin)
        std::cout<<"f("<<c<<") = "<<BaricentricnaInterpolacija(v,r)(c)<<"fapprox("<<c<<") = "<<BaricentricnaInterpolacija(BaricentricnaInterpolacija(v,r),x_min,x_max,delta_x,r)(c)<<std::endl;
         else 
         break;
            }
        catch(std::domain_error s) {
            std::cout<<s.what()<<std::endl;
        }
      }
        break;
    }
    break;
    }
    }while(!std::cin);
	return 0;
}