/B2017/2018: Zadaća 3, Zadatak 1
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <functional>
#include <cmath>
#include <utility>
#include <stdexcept>
#include <vector>

std::function<double(double)> LinearnaInterpolacija (std::vector<std::pair<double,double>> v)
{
    std::sort(std::begin(v),std::end(v));
   
    
    for(int i=0;i<v.size()-1;i++){
        
        
        if(v.at(i).first == v.at(i+1).first) throw std::domain_error("Neispravni cvorovi");
    }
    
    return [v](double x) {
                            
                  
                                
                          if(x < v.at(0).first || x > v.at(v.size()-1).first) throw std::range_error("Argument izvan opsega");
                            
                          

                            
                            
                          if( x == v.at(v.size()-1).first)  return v.at(v.size()-1).second;
                        
                          std::pair<double,double> par;
                          par.first=x;
                          par.second=0;
                          
                          auto it =  std::lower_bound(v.begin(), v.end(), par);
                          double x1, x2, y1, y2;
                          
                          x2 = it->first;
                          y2 = it->second;
                          it--;
                          x1 = it->first;
                          y1 = it->second;
                            
                          return (y1 + ((y2-y1)/(x2-x1))*(x-x1));
                          
                         
                        };
    
    
    
}



std::function<double(double)> LinearnaInterpolacija( double  f(double),  double xmin, double xmax, double dx)
{
    
    if((xmin > xmax ) || (dx<=0)) throw std::domain_error ("Nekorektni parametri");
    
    std::vector<std::pair<double,double>> v2 ;
    for(double x=xmin; x<=xmax; x=x+dx){
        
        
        v2.push_back(std::make_pair(x,f(x)));
    }
    
    return LinearnaInterpolacija(v2);
}
    
    

int main ()
{
    
  std::vector<std::pair<double,double>> vek;
  double argument;
  int opcija;
  double arg1;
  
  int cvorovi;
  double xmin;
  double xmax;
  double dx;
  
  
  std::cout<<"Odaberite opciju (1 - unos cvorova, 2 - aproksimacija): ";
  std::cin>>opcija;
    
  if (opcija==1) {
        
        
    std::cout<<"Unesite broj cvorova: ";    
    std::cin>>cvorovi;
    
    std::cout<<"Unesite cvorove kao parove x y: ";
    
    for(int i=0;i<cvorovi;i++){
        double x,y;
        std::cin>>x;
        std::cin>>y;
        vek.push_back(std::make_pair(x,y));
    }
     
    
    try {
        auto f=(LinearnaInterpolacija(vek));
        
        do {
            std::cout<<"Unesite argument (ili \"kraj\" za kraj): ";
            std::cin>>arg1;
    
            
            if(!std::cin || std::cin.peek()!='\n') {
                
                std::cin.clear();
                std::cin.ignore(10000,'\n');
                break;
            }
            
            try {
                auto rez=f(arg1);
            
                std::cout<<"f("<<arg1<<") = "<<rez<<std::endl;
            
            }
        
            catch(std::domain_error izuzetak111) {
               std::cout<<izuzetak111.what()<<std::endl;
            }
            catch(std::range_error izuzetak222) {
               std::cout<<izuzetak222.what()<<std::endl;
            } 
        
        } while(1);
        
    }
        
    catch(std::domain_error izuzetak11) {
        std::cout<<izuzetak11.what()<<std::endl;
    }
    catch(std::range_error izuzetak22) {
        std::cout<<izuzetak22.what()<<std::endl;
    }

  }
        
  else if (opcija==2) {
        
    std::cout<<"Unesite krajeve intervala i korak: ";
        
    std::cin>>xmin;
    std::cin>>xmax;
    std::cin>>dx;
        
        
    try{
        
        auto g=LinearnaInterpolacija([](double x) {return x*x + sin(x);},xmin,xmax,dx);
        
        do {
            std::cout<<"Unesite argument (ili \"kraj\" za kraj): ";
            std::cin>>argument;
    
            
            if(!std::cin || std::cin.peek()!='\n') {
                
                std::cin.clear();
                std::cin.ignore(10000,'\n');
                break;
            }
            
            try {
            
               double   fja = argument*argument + sin(argument);
               std::cout<<"f("<<argument<<") = "<<fja<<" "<<"fapprox("<<argument<<") = "<<g(argument)<<std::endl;
            }
        
            catch(std::domain_error izuzetak1) {
                std::cout<<izuzetak1.what()<<std::endl;
            }
            catch(std::range_error izuzetak2) {
                std::cout<<izuzetak2.what()<<std::endl;
            } 
        
        } while(1);
        
    }    
          
        catch(std::domain_error izuzetak3) {
            std::cout<<izuzetak3.what()<<std::endl;
        }
        catch(std::range_error izuzetak4) {
            std::cout<<izuzetak4.what()<<std::endl;
        }
        
  }    
        
  return 0;
}

