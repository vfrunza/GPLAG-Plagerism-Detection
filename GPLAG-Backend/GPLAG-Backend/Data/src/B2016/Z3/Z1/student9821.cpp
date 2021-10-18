/B2016/2017: Zadaća 3, Zadatak 1
//Autotestovi by Enil Pajic (epajic1@etf.unsa.ba)
#include <iostream>
#include <vector>
#include <utility>
#include <functional>
#include <stdexcept>
#include <cmath>
#define EPSILON 0.00001

int MAX(int x, int y){
    if(x>y) return x;
    return y;
}
int MIN(int x, int y){
    if(x<y) return x;
    return y;
}
double fun(double x){
    return x*x + std::sin(x);
}
void Baci_izuzetak(const std::vector<std::pair<double,double>> &v,const int &d){
    if(d<0 || d>v.size()) throw std::domain_error("Nedozvoljen red");
        for(int i=0; i<v.size()-1; i++){
            for(int j=i+1; j<v.size(); j++){
                if(abs(v[i].first-v[j].first)<EPSILON) 
                throw std::domain_error("Neispravni cvorovi");
            }
        }
}

std::function<double(double x)> BaricentricnaInterpolacija(std::vector<std::pair<double,double>> v, int d){
        
        return [=](double x){
        //wi
        int n;
        double predznak(1),wi(0),proizvod(1);
        double suma1(0),suma2(0);
        n=v.size();
        
        for(int i=1; i<=n; i++){
            wi=0;
            if(x == v[i-1].first) return v[i-1].second;
            for(int k=MAX(1,i-d); k<=MIN(i,n-d); k++){
                predznak=pow(-1,k-1);
                proizvod = 1;
                for(int j=k; j<=k+d; j++){
                    if(i-1!=j-1){
                    proizvod *= 1/(v[i-1].first-v[j-1].first);
                }
                }
                wi += (predznak*proizvod);
            }
            suma1 +=((wi*v[i-1].second)/(x-v[i-1].first));
            suma2 += (wi/(x-v[i-1].first));
        }
            return suma1/suma2;
        };
}
std::function<double(double)> BaricentricnaInterpolacija(double fun(double),double x_min,double x_max,double delta_x, int d){
    if(x_min>x_max || delta_x<=0) throw std::domain_error("Nekorektni parametri");
    //prvo formirati cvorove, zatim iskoristiti cvorove za vektor cvorova, 
    std::vector<std::pair<double,double>>novi_cvorovi;
    double x1=x_min,x2;
    int brojac(0);
    while(x1<=x_max){
            x2=fun(x1);
            novi_cvorovi.push_back(std::make_pair(x1,x2));
            x1+=delta_x;
        }
    return [=](double x){
      return  BaricentricnaInterpolacija(novi_cvorovi,d)(x);
    };
}
int main (){
    int opcija;
    std::cout<<"Odaberite opciju (1 - unos cvorova, 2 - aproksimacija): ";
    std::cin>>opcija;
    
    if(opcija==1){ 
        
        int br_cvorova;
        std::cout<<"Unesite broj cvorova: ";
        std::cin>>br_cvorova;
        
        std::vector<std::pair<double,double>>v;
        std::pair<double,double>cvorovi;
        
        int par1,par2;
        std::cout<<"Unesite cvorove kao parove x y: ";
        for(int i=0; i<br_cvorova; i++){
        std::cin>>par1>>par2;
        cvorovi.first=par1;
        cvorovi.second=par2;
        v.push_back(cvorovi);
        }
        int d;
        double broj;
        std::cout<<"Unesite red interpolacije: ";
        std::cin>>d;
        do{
            std::cout<<"Unesite argument (ili \"kraj\" za kraj): ";
            std::cin>>broj;
            if(!std::cin) break;
            double f1;
            Baci_izuzetak(v,d);
            f1=BaricentricnaInterpolacija(v,d)(broj);
            std::cout<<"f("<<broj<<") = "<<f1<<std::endl;
        }while(std::cin);
    }
    else if(opcija==2){
        double x_min,x_max, korak,f2;
        std::cout<<"Unesite krajeve intervala i korak: ";
        std::cin>>x_min>>x_max>>korak;
        int d;
        double argument;
        std::cout<<"Unesite red interpolacije: ";
        std::cin>>d;
        do{
            std::cout<<"Unesite argument (ili \"kraj\" za kraj): ";
            std::cin>>argument;
            if(!std::cin) break;
            f2=BaricentricnaInterpolacija(fun,x_min,x_max,korak,d)(argument);
            std::cout<<"f("<<argument<<") = "<<fun(argument)<<" "<<"fapprox("<<argument<<") = "<<f2<<std::endl;
        }while(std::cin);
        
    }
    
	return 0;
}