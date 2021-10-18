#include <utility>
#include <iostream>
#include <functional>
#include <stdexcept>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>
#include <limits>
bool jednaki(double a,double b){
    if(a==b) return true;
   // if(std::fabs(a-b)< 0.000000001) return true;
    return false;
}
std::function< double( double)> BaricentricnaInterpolacija(std::vector<std::pair<double,double>> v,int d){
    if(d<0||d>=v.size()) throw std::domain_error("Nedozvoljen red");
    for(int i=0;i<v.size();i++) for(int j=i+1;j<v.size();j++) if(jednaki(v[i].first,v[j].first)) throw std::domain_error("Neispravni cvorovi");
    std::sort(v.begin(),v.end(),[](std::pair<double,double> p1, std::pair<double,double>p2){
        return p1.first<p2.first;
    });
     std::vector< double> Wi;
     for(int i=0;i<v.size();i++){
             double wi{};
            int k=0; if(i-d>0) k=i-d;
            int kraj=i; if(v.size()-d-1<i) kraj=v.size()-d-1;
            for(int j=k;j<=kraj;j++){               
                 double proizvod=1;
                for(int z=j;z<=j+d;z++){
                    if(i!=z){
                        proizvod/=(v[i].first-v[z].first); 
                    } 
                }

                if((j-1)%2!=0) proizvod*=-1;
                wi+=proizvod;
            }
            Wi.push_back(wi);
     }
     
    return [v,Wi]( double x)-> double{
         double vrijednost1{},vrijednost2{};
        for(int i=0;i<v.size();i++) if(jednaki(x,v[i].first)) return v[i].second;
        for(int i=0;i<v.size();i++){
            vrijednost1+=(Wi[i]/(x-v[i].first))*v[i].second;
            vrijednost2+=Wi[i]/(x-v[i].first);
        }
        return vrijednost1/vrijednost2;
        };
}
template <typename F> 
std::function< double( double)> BaricentricnaInterpolacija(F f,double xmin,double xmax,double deltax,int d){
    if(xmin>xmax||deltax<=0) throw std::domain_error("Nekorektni parametri");
    
    std::vector<std::pair< double,double>> cvorovi;
    while(xmin<=xmax){
            cvorovi.push_back(std::make_pair(xmin,f(xmin)));
            xmin+=deltax;
    }
    return BaricentricnaInterpolacija(cvorovi,d);
}
double ff( double x){
        return (x*x+std::sin(x));
}
/*
int main ()
{
    int zlj;
    std::cout<<"Odaberite opciju (1 - unos cvorova, 2 - aproksimacija): ";
    std::cin>>zlj;
    if(zlj==1){
        std::cout<<"Unesite broj cvorova: ";
        int n; std::cin>>n;
        std::vector<std::pair<double,double>> v(n);
        std::cout<<"Unesite cvorove kao parove x y: ";
        for(int i=0;i<n;i++) std::cin>>v[i].first>>v[i].second;
        std::cout<<"Unesite red interpolacije: "; int d;
        std::cin>>d;
          std::cin.ignore(1000,'\n');
        try{
        auto f=BaricentricnaInterpolacija(v,d);
        while(true){
            std::cout<<"Unesite argument (ili \"kraj\" za kraj): ";
             double x;
            if(!(std::cin>>x)) break;
                std::cout<<"f("<<x<<") = "<<f(x)<<std::endl;
            
        }
        } catch(std::domain_error e){
            std::cout<<e.what(); return 1;
        }
        
    }
    if(zlj==2){
        std::cout<<"Unesite krajeve intervala i korak: ";
        double xmin,xmax,deltax;
        std::cin>>xmin>>xmax>>deltax;
        std::cout<<"Unesite red interpolacije: ";
        int d; std::cin>>d;
          std::cin.ignore(1000,'\n');
        try{
        auto f=BaricentricnaInterpolacija(ff,xmin,xmax,deltax,d);
        while(true){
            std::cout<<"Unesite argument (ili \"kraj\" za kraj): ";
             double x;
            if(!(std::cin>>x)) break;
            std::cout<<"f("<<x<<") = "<<ff(x)<<" fapprox("<<x<<") = "<<f(x)<<std::endl;
                
            }
        }
        catch(std::domain_error e){
            std::cout<<e.what(); return 1;
        }
    }

	return 0;
}  
*/
int main(){
    auto fun = BaricentricnaInterpolacija([](double x){return 1 / x;}, 0.5, 0.5, 0.1, 0);
    for (double i = 0.3; i < 0.7; i += 0.1)
        std::cout << "fun (" << i << ") = " << fun (i) << std::endl;
    return 0;
}
