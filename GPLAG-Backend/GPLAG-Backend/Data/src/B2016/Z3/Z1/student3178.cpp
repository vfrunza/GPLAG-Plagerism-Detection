#include <memory>
#include <vector>
#include <string>
#include <cstring>
#include <iostream>
#include <utility>
#include <stdexcept>
#include <algorithm>
#include <cmath>
#include <functional>
//const double Eps(1e-10);

bool JesuLiJednaki(double x, double y, double Eps = 1e-10){
    return std::fabs(x-y) <= Eps*(std::fabs(x) + std::fabs(y));}
    
bool ImaJednakih(std::vector<std::pair<double, double>> v){
      for(int i{0}; i<v.size(); i++){
          double pomocna(v.at(i).first);
          for(int j=i+1; j<v.size(); j++){
              if(JesuLiJednaki(pomocna, v.at(j).first)) return true;
          }
      }
      return false;
  }
  
double fun(double x) {
    return x*x + std::sin(x);}
  
std::vector<double> IzracunajKoeficijent(std::vector<std::pair<double, double>> parovi, int d){
    std::vector<double> vektor_koef;
     int n(parovi.size());
    for(int i=1; i<=n; i++){
       double suma=0;
        for(int k=std::max(1,i-d); k<=std::min(i, n-d); k++){
            double proizvod=1;
            for(int j=k; j<=k+d; j++){
                if(j != i)
                proizvod *= 1/(parovi[i-1].first - parovi[j-1].first );
            }
            proizvod *= std::pow(-1,k-1);
            suma += proizvod;
        }
         vektor_koef.push_back(suma);
    }
    return vektor_koef;
}
  
std::function<double(double)> BaricentricnaInterpolacija(std::vector<std::pair<double, double>> parovi, int d){
    int n(parovi.size());
    if(d<0 || d>=n) throw std::domain_error ("Nedozvoljen red");
    
    if(ImaJednakih(parovi)) throw std::domain_error ("Neispravni cvorovi");
    std::vector<double> vektor_koef;
    
    vektor_koef=IzracunajKoeficijent(parovi,d); //pitanje:da li ovom funkcijom trebam racunati koeficijent po koeficijent, ili je i ovo okej, da mi vrati gotov vektor!
    
    return [=](double x){ 
        double p{0}; 
        double q{0}; 
        for(int i=1; i<=n; i++){
       if( JesuLiJednaki(x, parovi[i-1].first)) return parovi[i-1].second; 
        double u;
        u = vektor_koef.at(i-1) / (x - parovi[i-1].first) ;
        p = p + u*parovi[i-1].second;
        q= q+u;}
        return p/q;};
}


template <typename FTip>
std::function<double(double)> BaricentricnaInterpolacija(FTip fun, double x_min, double x_max, double korak, int d){
       if (x_min>x_max || korak <=0) throw std::domain_error ("Nekorektni parametri");
      
       std::vector<std::pair<double, double>> v;
       std::pair<double,double> par;
       for(double i = x_min; i<= x_max; i+=korak){
           par=std::make_pair(i,fun(i));
           v.push_back(par);  
       }
       if(d<0 || d>=v.size()) throw std::domain_error ("Nedozvoljen red");
    
       if(ImaJednakih(v)) throw std::domain_error ("Neispravni cvorovi");
    
 return (BaricentricnaInterpolacija(v,d));
}




int main ()
{ 
    try{
    int opcija{0};

    std::cout<< "Odaberite opciju (1 - unos cvorova, 2 - aproksimacija): ";
    std::cin >> opcija;
    
    if(opcija == 1){
        std::cout << "Unesite broj cvorova: ";
        int br_cvorova{0};
        std::cin >> br_cvorova;
        std::cin.ignore(10000, '\n');
        
        std::vector<std::pair<double, double>> vektor_cvorova;
        std::pair<double, double> par;
        double x,y;
        int i{0};
        std::cout << "Unesite cvorove kao parove x y: ";
      
        
        while( i <br_cvorova){
          std::cin >> x >> y;
          par = std::make_pair(x,y);
          vektor_cvorova.push_back(par); 
          std::cin.ignore(10000, '\n');
          i++; }
          
         
        if(ImaJednakih(vektor_cvorova)) throw std::domain_error ("Neispravni cvorovi");
        
      
        std::cout << "Unesite red interpolacije: ";
        int d;
        std::cin >> d;  
        if(d<0 || d>=vektor_cvorova.size()) throw std::domain_error ("Nedozvoljen red");
        std::cin.ignore(10000, '\n');
        
        
        for(;;){    
         std::cout << "Unesite argument (ili \"kraj\" za kraj): ";
         double argument;
         std::cin >> argument;
         if( !std::cin ) {
         std::cin.clear(); 
         std::cin.ignore(10000, '\n');
         break;}
         std::function<double(double)> f(BaricentricnaInterpolacija({{1,3}, {2,5}, {4,4}, {5,2}, {7,1}}, 2));
         std::cout << "f(" << argument <<") = " << f(argument) << std::endl;
         std::cin.ignore(10000, '\n');
         }        

    }
    
    else if(opcija==2){
        double a, b;
        double korak;
        std::cout << "Unesite krajeve intervala i korak: ";
        std::cin >> a >> b >> korak;
        if (a>b || korak <=0) throw std::domain_error ("Nekorektni parametri");
        std::cout << "Unesite red interpolacije: ";
        int d;
        std::cin >> d;
        if(d<0) throw std::domain_error ("Nedozvoljen red");
        std::cin.ignore(10000, '\n');
    
        
        for(;;){
         std::cout << "Unesite argument (ili \"kraj\" za kraj): ";
         double argument;
         std::cin >> argument;
         if( !std::cin ) {
         std::cin.clear();     
         std::cin.ignore(10000, '\n');
         break;}
         std::function<double(double)> g(BaricentricnaInterpolacija(fun, a, b, korak, d));
     
         std::cout <<  "f(" << argument <<") = " << fun(argument) << " " << "fapprox(" << argument <<") = " << g(argument) << std::endl;
        }
        
    }
  
   
    }
    catch(std::domain_error e){
    std::cout << e.what() << std::endl;}
  /*
    try{
        BaricentricnaInterpolacija({{1,1},{2,2},{3,3}},-2);
        std::cout << "Ne smije se ispisati 1" << std::endl;
} 
catch(const std::domain_error &r) { std::cout <<"E1: '" << r.what() <<"'";}
catch(...) {std::cout << "Ni oo se ne smije ispisati 1" <<std::endl;}
std::cout<< std::endl;

try{        BaricentricnaInterpolacija({{1,1},{2,2},{3,3}},5);
        std::cout << "Ne smije se ispisati 2" << std::endl;
} 
  catch(const std::domain_error &r) { std::cout <<"E2: '" << r.what() <<"'";}
catch(...) {std::cout << "Ni oo se ne smije ispisati 2" <<std::endl;}

*/
return 0;
}