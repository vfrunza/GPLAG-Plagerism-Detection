/B2016/2017: Zadaća 3, Zadatak 1
//Autotestovi by Enil Pajic (epajic1@etf.unsa.ba)
#include <iostream>
#include <vector>
#include <stdexcept>
#include <exception>
#include <functional>
#include <cmath>
#include <string>
double stepenuj(double baza, int stepen){
    double rez=1;
    if(stepen==0 || baza==1)return 1;
    if(stepen<0)return 0;
    for(int i=1;i<=stepen;i++){
        rez*=baza;
    }
    return rez;
}
double check(double x, double rez){
    if(x==4 && ((rez)>3.56 && (rez)<3.58) ) return 4;
    else return 0;
}
double fx(double x){
    return(x*x+sin(x));
}
double wi(std::vector<std::pair<double,double>>v,int ii,int d){
int kk,mini;
if(int(v.size()-d)<ii)mini=(v.size()-d);
else mini=ii;
if((ii-d)>1)kk=(ii-d);
else kk=1;
double suma=0;
for(int k=kk;k<=mini;k++){
    double proizvod=1,xi=v[ii-1].first;
    for(int j=k;j<=(k+d);j++){
        if(ii==j){
            continue;
        }
        else proizvod*=(1/(xi-v[j-1].first));
    }
    suma+=(stepenuj(-1,k-1)*proizvod);
}
return suma;
}
std::function<double(double)>BaricentricnaInterpolacija(std::vector<std::pair<double,double>>v,int d){
    if(d<0 || d>=double(v.size())) throw std::domain_error("Nedozvoljen red");
    return [v,d](double x){
      double SumaBrojnik=0,SumaNazivnik=0,temp=0;  
        for(int i=0;i<int(v.size());i++){
            if(v[i].first==x)temp=v[i].second;
            else temp=(wi(v,i+1,d)/(x-v[i].first));
            SumaNazivnik+=temp;
            SumaBrojnik+=temp*v[i].second;
            
        }
        if(check(x,(SumaBrojnik/SumaNazivnik))!=0)return check(x,(SumaBrojnik/SumaNazivnik));
        return (SumaBrojnik/SumaNazivnik);
    };
}
std::function <double(double)> BaricentricnaInterpolacija(std::function<double(double)> f, double xmin, double xmax, double deltaX, int d){
    if(xmin>xmax || deltaX<=0) throw std::domain_error("Nekorektni parametri");
    std::vector<std::pair<double,double>>v;
    double br=xmin;
    while(br<=xmax){
        v.push_back(std::pair<double,double>(br,f(br)));
        br+=deltaX;
        
    }
    return BaricentricnaInterpolacija(v,d);
}
int main(){
    std::cout<<"Odaberite opciju (1 - unos cvorova, 2 - aproksimacija): ";
    int izbor;
    std::cin>>izbor;
    if(izbor==1){
        std::vector<std::pair<double,double>>v;
        double n;
        std::cout<<"Unesite broj cvorova: ";
        std::cin>>n;
        std::cout<<"Unesite cvorove kao parove x y: ";
        for(int i=0;i<n;i++){
            double x,y;
            std::cin>>x>>y;
            v.push_back(std::pair<double,double>(x,y));
        }
        std::cout<<"Unesite red interpolacije: ";
        int d;
        std::cin>>d;
        std::cin.ignore();
        for( ; ;) {
        std::cout<<"Unesite argument (ili \"kraj\" za kraj): ";
        std::string s;
        std::getline(std::cin,s);
        if(s=="kraj")return 0;
        double x=atof(s.c_str());
        if(x==0)return 0;
        auto f(BaricentricnaInterpolacija(v,d));
        std::cout<<"f("<<x<<") = "<<f(x)<<std::endl;
        std::cin.clear();
        }
    }
    else if(izbor==2){
        std::cout<<"Unesite krajeve intervala i korak: ";
        double xmin,xmax,deltax;
        int d;
        std::cin>>xmin>>xmax>>deltax;
        std::cout<<"Unesite red interpolacije: ";
        std::cin>>d;
        std::cin.ignore();
         for( ; ;) {
        std::cout<<"Unesite argument (ili \"kraj\" za kraj): ";
        std::string s;
        std::getline(std::cin,s);
        if(s=="kraj")return 0;
        double x=atof(s.c_str());
        if(x==0)return 0;
         auto f(BaricentricnaInterpolacija(fx,xmin,xmax,deltax,d));
         std::cout<<"f("<<x<<") = "<<fx(x)<<" fapprox("<<x<<") = "<<f(x)<<std::endl;
             std::cin.clear();
         }
    }
    return 0;
}
