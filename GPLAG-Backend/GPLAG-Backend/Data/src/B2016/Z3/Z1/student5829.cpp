/B2016/2017: Zadaća 3, Zadatak 1
//Autotestovi by Enil Pajic (epajic1@etf.unsa.ba)
#include <iostream>
#include <vector>
#include <utility>
#include <functional>
#include <stdexcept>
#include <algorithm>
#include <cmath>

int max(int x, int y){
    if(x>=y) return x;
    
    else return y;
}

int min(int x, int y){
    if(x<=y) return x;
    else return y;
}


std::function<double(double)> BaricentricnaInterpolacija(std::vector<std::pair<double, double>> v, int d){
    if(d<0 || d>=v.size()) throw std::domain_error("Nedozvoljen red");
    for(int i=0; i<v.size(); i++){
        for(int j=0; j<v.size(); j++){
            if(i==j) continue;
            if(v[i].first==v[j].first) throw std::domain_error("Neispravni cvorovi");
        }
    }
    
    int n(v.size());
   
    
    
    std::function<double(double)> finalna=[n,v,d] (double x){
    double suma_brojnika(0);
    double suma_nazivnika(0);
    
    std::function<double(int)> w=[n,d,v] (int i) {
        double suma(0);
        
        double finalni_proiz(1);
        
        for(int k=max(i, i-d); k<min(i, n-d); k++){
            suma=suma+pow(-1, k-1);
            double proiz(1);
            for(int j=k; j<k+d; j++){
                
                if(j==i) continue;
                proiz=proiz*(1/(v[i].first-v[j].first));
                
            }
        
        finalni_proiz=proiz*suma;
            
        }
        
        return finalni_proiz;
        
    };
    
    for (int i=0; i<n; i++){
        
        
        
        
        if(x!=v[i].first){
        suma_brojnika=suma_brojnika+(w(i+1)*v[i].second)/(x-v[i].first);}
        else continue;
        
        if(x!=v[i].first){
        suma_nazivnika=suma_nazivnika+(w(i+1)/(x-v[i].first));}
        else continue;
       
    }
    
    return suma_brojnika/suma_nazivnika;
    };
    return finalna;
    
}

std::function<double(double)> BaricentricnaInterpolacija(std::function<double(double)> f, double x_min, double x_max, double delta_x, int d){
    if(x_min>x_max || delta_x<=0) throw std::domain_error("Nekorektni parametri");
    std::vector<std::pair<double, double>> v;
    int br(1);
    for(;;){
        v.push_back(std::make_pair(x_min, f(x_min)));
        x_min=x_min+br*delta_x;
        br++;
        if(x_min>x_max) break;
        
    }
    
    std::function<double(double)> finalna(BaricentricnaInterpolacija(v,d));
    
    return finalna;
    
    
}
int main ()
{
    std::function<double(double)> funkcija=[](double x){
        return x*x+sin(x);
    };
    int opcija;
    std::cout<<"Odaberite opciju (1 - unos cvorova, 2 - aproksimacija): ";
    std::cin>>opcija;
    if(opcija==1){
        int n;
        std::cout<< "Unesite broj cvorova: ";
        std::cin>> n;
        std::vector<std::pair<double, double>> v(n);
        std::cout<<"Unesite cvorove kao parove x y: ";
        for(int i=0; i<n; i++){
            double x,y;
            std::cin>>x>>y;
            v[i]=std::make_pair(x,y);
            
        }
        std::cout<<"Unesite red interpolacije: ";
        int d;
        std::cin>>d;
        double argument;
        
        do{
            std::cout<< "Unesite argument (ili \"kraj\" za kraj): ";
            std::cin>>argument;
            if(!argument) break;
            else {
                
                std::cout<<"f("<<argument<<") = "<<BaricentricnaInterpolacija(v,d)(argument);

            }
        }
        
        while(argument);
        
        
    }
    
    
    
    
	return 0;
}