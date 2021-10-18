/B2016/2017: Zadaća 3, Zadatak 1
//Autotestovi by Enil Pajic (epajic1@etf.unsa.ba)
#include <iostream>
#include <functional>
#include <vector>
#include <utility>
#include <stdexcept>
#include <algorithm>
#include <cmath>
#define eps 1e-6

double Proizvod(int j1, int j2,std::vector<std::pair<double,double>> v, int i){
    double p=1.;
    for(int j=j1;j<=j2;j++){
        if(i!=j) p=p*(1./(v[i-1].first-v[j-1].first));
    }
    return p;
}

std::vector<double> wi(std::vector<std::pair<double,double>> v, int d){
    int n=v.size();
    std::vector<double> l;
    for(int i=1;i<=n;i++){
        double w=0;
        for(int k=std::max(1,i-d);k<=std::min(i,n-d);k++){
           w=w+(( std::pow(-1,k-1)) *Proizvod(k,k+d,v,i));
        }
        l.push_back(w);
    }
    return l;
}
double brojnik (double x,std::vector<std::pair<double,double>> v,std::vector<double> w){
    double suma=0.;
    for(int i=1;i<=v.size();i++){
        suma+=((w[i-1]*v[i-1].second)/(x-v[i-1].first));
    }
    return suma;
}

double nazivnik(double x,std::vector<std::pair<double,double>> v,std::vector<double> w){
    double suma=0.;
    for(int i=1;i<=v.size();i++){
        suma+=(w[i-1]/(x-v[i-1].first));
    }
    return suma;
}

std::function <double(double)> BaricentricnaInterpolacija(std::vector<std::pair<double,double>> v, int d){
    if(d<0 || d>=v.size()) throw std::domain_error("Nedozvoljen red");
    for(int i=0;i<v.size()-1;i++){
        for(int j=i+1;j<v.size();j++){
            if(std::abs(v[i].first-v[j].first)<eps) throw std::domain_error("Neispravni cvorovi");
        }
    }
    std::vector<double> w=wi(v,d);
    return [v,w] (double x) {
        for(int i=0;i<v.size();i++)
            if(std::abs(v[i].first-x)<eps) return v[i].second;
        return brojnik(x,v,w)/nazivnik(x,v,w);
    };
    
}
std::function<double(double)> BaricentricnaInterpolacija(std::function<double(double)> f, double xmin, double xmax, double deltax, int d){
    if((deltax<0 || std::abs(deltax)<eps) || (xmin>xmax || std::abs(xmin-xmax)<eps)) throw std::domain_error("“Nekorektni parametri");
    int i=0;
    std::vector<std::pair<double,double>> v;
    for(;;){
        if((xmin+deltax*i)>xmax) break;
        std::pair<double,double> par;
        par=std::make_pair(xmin+deltax*i, f(xmin+deltax*i));
        v.push_back(par);
        i++;
    }
    return BaricentricnaInterpolacija(v,d);
}

double NekaFunkcija(double x){
    return x*x+std::sin(x);
}

int main ()
{
   try{
       std::cout << "Odaberite opciju (1 - unos cvorova, 2 - aproksimacija): ";
       int broj;
       std::cin >> broj;
       if(broj==1){
           std::cout << "Unesite broj cvorova: ";
           int x;
           std::cin >> x;
           std::cout << "Unesite cvorove kao parove x y: ";
           std::vector<std::pair<double,double>> v;
           for(int i=0;i<x;i++){
               double a,b;
               std::pair<double,double> par;
               std::cin >> a >> b;
               par.first=a;
               par.second=b;
               v.push_back(par);
           }
           std::cout << "Unesite red interpolacije: ";
           int d;
           std::cin >> d;
           for(;;){
                std::cout << "Unesite argument (ili \"kraj\" za kraj): " ;
                double c;
                std::cin >> c;
                if(!std::cin) return 0;
                std::cout << "f(" << c << ") = " << BaricentricnaInterpolacija(v,d)(c) << std::endl;
           }
       }else if(broj==2){
           std::cout << "Unesite krajeve intervala i korak: ";
           double a,b,e;
           std::cin >> a >> b >> e;
            std::cout << "Unesite red interpolacije: ";
           int d;
           std::cin >> d;
           for(;;){
                std::cout << "Unesite argument (ili \"kraj\" za kraj): " ;
                double c;
                std::cin >> c;
                if(!std::cin) return 0;
                double o=c*c+std::sin(c);
                std::cout << "f(" << c << ") = " << o ;
                std::cout << " fapprox(" << c << ") = ";
                std::cout << BaricentricnaInterpolacija(NekaFunkcija,a,b,e,d)(c) << std::endl;
           }
       }
   }catch(std::domain_error e){
       std::cout << e.what() << std::endl;
   }
	return 0;
}