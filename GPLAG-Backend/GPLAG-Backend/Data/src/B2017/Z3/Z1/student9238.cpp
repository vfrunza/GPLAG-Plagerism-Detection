/B2017/2018: Zadaća 3, Zadatak 1
#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <stdexcept>
#include <functional>
#include <cmath>
#define epsilon 0.00001

bool JeLiJednako(double a, double b) {
    return std::abs(a-b)<epsilon;
}

std::function<double (double)> LinearnaInterpolacija(std::vector<std::pair<double,double>> vektor) {
    
    std::sort(vektor.begin(),vektor.end(),[](std::pair<double,double> a,std::pair<double,double> b) {
        return a.first<b.first;
    });
    
    for(int i=0; i<vektor.size(); i++)
        for(int j=i+1; j<vektor.size(); j++){
           
            if(JeLiJednako(vektor[i].first,vektor[j].first)) throw std::domain_error("Neispravni cvorovi");
        }
        if(vektor.size()==0)throw std::domain_error("Neispravni cvorovi");
        
        return [vektor](double x) {
       
                double minx,maxx;
                minx=vektor[0].first;
                maxx=vektor[vektor.size()-1].first;
                double rezultat=0;
                if(x>=minx && x<=maxx) {
                   auto p=std::find_if(vektor.begin(),vektor.end(),[x](std::pair<double,double> a) {
                        return x<a.first || JeLiJednako(x,a.first);
                    });
                    std::pair<double,double> a,b;
                    
                    b=*p;
                    
                    p--;
                    a=*p;
                    rezultat=a.second+((b.second-a.second)/(b.first-a.first))*(x-a.first);
                    
                } else throw std::range_error("Argument izvan opsega");
                return rezultat;
                
        };
}


std::function<double (double)> LinearnaInterpolacija(std::function<double(double)> funkcija,double xmin,double xmax,double deltax){
    std::vector<std::pair<double,double>> vektor;
    for(double i=xmin; i<=xmax; i+=deltax)
        vektor.push_back(std::make_pair(i,funkcija(i)));
        return LinearnaInterpolacija(vektor);
}

int main () {
    int opcija(0);
    double x;
    double xmin, xmax, deltax;
    std::cout << "Odaberite opciju (1 - unos cvorova, 2 - aproksimacija): ";
    std::cin >> opcija;
    if(opcija==1) {
        std::cout<< "Unesite broj cvorova: ";
        int broj_cvorova(0);
        std::cin >> broj_cvorova;
        std::cout << "Unesite cvorove kao parove x y: ";
        std::pair<double,double> a;
        std::vector<std::pair<double,double>> vektor;
        for(int i=0; i<broj_cvorova; i++) {
            std::cin>>a.first>>a.second;
            vektor.push_back(a);
       }
       
       do {
           std::cout<< "Unesite argument (ili \"kraj\" za kraj): ";
           std::cin >> x;
           if(!std::cin)return 0;
           try{
                std::cout << "f(" << x <<") = " << LinearnaInterpolacija(vektor)(x)<<std::endl;
           }catch(std::domain_error a){
               std::cout<<a.what()<<std::endl;
               return 0;
           }catch(std::range_error b){
               std::cout<<b.what()<<std::endl;
              return 0;
           }
       } while( x>=0 && x<=9);
    }else if(opcija==2) {
        std::cout<<"Unesite krajeve intervala i korak: ";
        std::cin >> xmin >> xmax >> deltax;
        if(deltax<0){std::cout<<"greksa"; return 0;}
        do {
            std::cout<< "Unesite argument (ili \"kraj\" za kraj): ";
            std::cin>>x;
            if(!std::cin)return 0;
            
            try{
                double r(0);
               
                r= LinearnaInterpolacija([](double x){return x*x+sin(x);},xmin,xmax,deltax)(x);
                std::cout<<"f("<<x<<") = "<<x*x+sin(x);
                std::cout <<" fapprox(" << x <<") = " <<r<<std::endl;
            }catch(std::domain_error a){
               std::cout<<a.what()<<std::endl;
           }catch(std::range_error b){
               std::cout<<b.what()<<std::endl;
              
           }
                
            } while(x>=0 && x<=9);
    }
	return 0;
}
