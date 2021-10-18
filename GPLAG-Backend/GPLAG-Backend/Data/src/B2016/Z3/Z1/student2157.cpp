#include <iostream>
#include <utility>
#include <map>
#include <vector>
#include <cmath>
#include <functional>

std::function<double(double)> BaricentricnaInterpolacija(std::vector<std::pair<double, double>> Cvorovi, int d){
    
    std::vector<double> B;
    double w(0);
    double proizvod(1);
    int od, dok;
    for ( int i = 0; i < Cvorovi.size(); i++){
        if ( 1 > ( i - d ) )  {
            od = 1;
        }
        else {
            od = ( i - d );
        }
        if ( i < ( Cvorovi.size() - d ) ) {
            dok = i;
        }
        else{ 
            dok = ( Cvorovi.size() - d );
        }
            for(int k = od; k <= dok; k++){
                for(int j = k; j < (k + d) && j!=i; j++){
                    proizvod *= (1/(Cvorovi[i].first - Cvorovi[j].first));
                }    w += (pow(-1, k-1)*proizvod);
            }
            B.push_back(w);
        }
     
         return [B, Cvorovi](double x){
        double g(0), d(0);
        for ( int j = 0; j < B.size(); j++){
            g += ((B[j]  / (x - Cvorovi[j].first))*Cvorovi[j].second);
            d += (B[j] / (x - Cvorovi[j].first));
        }
        return g/d;
    };}


int main ()
{
    for(int i = 0 ; i < 1; i++){
    std::cout<<"Odaberite opciju (1 - unos cvorova, 2 - aproksimacija): ";
    int opcija;
    std::cin>>opcija;
    if(opcija == 1){
        std::cout<<"Unesite broj cvorova: ";
        int n;
        std::cin>>n;
        std::vector<std::pair<double,double>> Cvorovi;
        std::cout<<"Unesite cvorove kao parove x y: ";
        for(int i = 0; i < n; i++){
            double a, b;
            std::cin>>a>>b; 
            Cvorovi.push_back(std::make_pair(a,b));
        }
        std::cout<<"Unesite red interpolacije: ";
        int red;
        std::cin>>red;
        double argument;
        std::cout<<"\nUnesite argument ili ""kraj"" za kraj: ";
          while(std::cin>>argument){
    
          auto f(BaricentricnaInterpolacija(Cvorovi, red));
             
              std::cout<<"f("<<argument<<") = "<<f(argument);
            std::cout<<"\nUnesite argument ili ""kraj"" za kraj: ";
        }
    }
    if(opcija==2){
           
    }

}
return 0;}