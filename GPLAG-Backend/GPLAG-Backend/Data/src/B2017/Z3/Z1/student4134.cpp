/B2017/2018: Zadaća 3, Zadatak 1
#include <iostream>
#include <vector>
#include <functional>
#include <stdexcept>
#include <algorithm>
#include <utility>
#include <cmath>


 double fapprox (double x) {
            return x*x+sin(x);
        }
        
std::function < double (double) > LinearnaInterpolacija (std::vector < std::pair<double,double> > V ) {
    
    for(int i = 0; i<V.size() ; i++) {
        for(int j=i+1 ; j<V.size() ; j++) {
            if(V.at(i).first == V.at(j).first) {
                throw std::domain_error ("Neispravni cvorovi");
                
            }
        } 
    }
        
        std::sort(V.begin(), V.end(), [] (std::pair<double,double> x, std::pair<double,double> y) {
            return x.first < y.first ;
        } );
        
        return [V] (double X) -> double {
            if(V.size() == 0 ) return 0;
            double Xmin(V[0].first);
            double Xmax(V[V.size() - 1].first);
            
            if(X < Xmin || X>Xmax ) throw std::range_error ("Argument izvan opsega");
            
            if( X==Xmax ) return V[V.size() - 1].second;
            
            /*int k(0);
            for(int i = 0; i<V.size() - 1 ; i++) {
                
                
                if(X>=V.at(i).first && X<V[i+1].first) {
                    k=i;
                    break;
                }
            
        
                return V[k].second + ((V[k+1].second - V[k].second) / (V[k+1].first - V[k].first)) * (X - V[k].first);
                
            };*/
            std::pair<double,double> par;
            par.first = X;
            par.second = 0;
            auto k=std::upper_bound(V.begin(),V.end(),par, [] (std::pair<double,double> par1,std::pair<double,double> par2){return par1.first<par2.first;});
            return (k-1)->second + ((k->second - (k-1)->second)/(k->first - (k-1)->first)) * (X-(k-1)->first);
};
}
        
        
        
std::function < double (double) > LinearnaInterpolacija ( double f(double) , double Xmin, double Xmax, double DeltaX) {
    
    if(Xmin>Xmax) throw std::domain_error ("Nekorektni parametri");
    
    std::vector<std::pair<double,double>> V ;
    std::pair<double,double> Par;
    
    while (Xmin<=Xmax) {
        Par = std::make_pair(Xmin, f(Xmin));
        Xmin=Xmin+DeltaX;
        V.push_back(Par);
    }
    
    
     return [V] (double X) -> double {
            if(V.size() == 0 ) return 0;
            double Xmin(V[0].first);
            double Xmax(V[V.size() - 1].first);
            
            
           
            if(X < Xmin || X>Xmax ) throw std::range_error ("Argument izvan opsega");
            
            if( X==Xmax ) return V[V.size() - 1].second;
            
            /*int k(0);
            for(int i = 0; i<V.size() - 1 ; i++) {
               
                
                if(X>=V.at(i).first && X<V[i+1].first) {
                    k=i;
                    break;
                }
            }
                
                return V[k].second + ((V[k+1].second - V[k].second) / (V[k+1].first - V[k].first)) * (X - V[k].first);
                
            };*/
            std::pair<double,double> par;
            par.first = X;
            par.second = 0;
            auto k=std::upper_bound(V.begin(),V.end(),par, [] (std::pair<double,double> par1,std::pair<double,double> par2){return par1.first<par2.first;});
            return (k-1)->second + ((k->second - (k-1)->second)/(k->first - (k-1)->first)) * (X-(k-1)->first);
};

            
            
}
    


int main ()
{
 
    std::cout<<"Odaberite opciju (1 - unos cvorova, 2 - aproksimacija): ";
    int a;
    std::cin>>a;
    
    if(a==1) {
        std::vector<std::pair<double,double>> V;
        std::cout<<"Unesite broj cvorova: ";
        int b;
        std::cin>>b;
        std::cout<<"Unesite cvorove kao parove x y: ";
        for(int i = 0 ; i < b ; i++) {
            std::pair<double,double> par;
            double c,d;
            std::cin>>c>>d;
            par.first=c;
            par.second=d;
            V.push_back(par);
        }
           double Br;
        try{
            auto f(LinearnaInterpolacija(V));
        while (true) {
            
        std::cout<<"Unesite argument (ili ";
        std::cout<<"\"kraj\"";
        std::cout<<" za kraj): ";
     
        std::cin>>Br;
        if(!(std::cin)) {
            std::cin.clear();
            std::cin.ignore(1000,'\n');
            return 0;
        }
    
        
        std::cout<< "f(" <<Br<< ") = " <<f(Br)<<std::endl;
         }}  catch(std::domain_error izuzetak) {
        std::cout<<izuzetak.what()<<std::endl;
         } 
    catch (std::range_error izuzetak) {
        std::cout<<izuzetak.what()<<std::endl;
     } 
     }else {
        std::cout<<"Unesite krajeve intervala i korak: ";
        double Xmin,Xmax,DeltaX;
        std::cin>>Xmin;
        std::cin>>Xmax;
        std::cin>>DeltaX;
        
        while(true) {
        std::cout<<"Unesite argument (ili ";
        std::cout<<"\"kraj\"" ;
        std::cout<<" za kraj): ";
        double Br;
        std::cin>>Br;
        if(!(std::cin)) {
            std::cin.clear();
            std::cin.ignore(1000,'\n');
            return 0;
        }
        
       try {
        auto f(LinearnaInterpolacija(fapprox, Xmin, Xmax, DeltaX));
       
        std::cout<< "f(" <<Br<< ") = " <<fapprox(Br)<<" fapprox(" <<Br<< ") = " << f(Br)<<std::endl;
        
       } catch(std::domain_error izuzetak) {
        std::cout<<izuzetak.what()<<std::endl;
        
            
        } 
    catch (std::range_error izuzetak) {
        std::cout<<izuzetak.what()<<std::endl;
    }
    } 
    }
 
	return 0;
}
