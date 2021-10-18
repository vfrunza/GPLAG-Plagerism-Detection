#include <utility>
#include <iostream>
#include <functional>
#include <vector>
#include <stdexcept>
#include <cmath>
#include <algorithm>
std::function <double(double)> BaricentricnaInterpolacija(std::vector<std::pair<double,double>> v, int n){
    int duz =v.size();
    if(n>duz || n<0){
        throw std::domain_error("Nedozvoljen red");
        }
        for(int i=0;i<duz-1;i++){
            for(int j=i+1;j<duz;j++){
                if(fabs(v[i].first-v[j].first)<0.0001)
                throw std::domain_error("Neispravni cvorovi");
            }
        }
    return [=](double x){
          double y(0),pr(0),dr(0);
          for(int i=1;i<=duz;i++){
          double wi(0);
          if(fabs(x-v[i-1].first)<0.0001){
              return v[i-1].second;
          }
          for(int j(std::max(1,i-n));j<=std::min(i,duz-n);j++){
              double umn(1);
              for(int k=j;k<=n+j;k++){
                  if(i!=k){
                      umn=umn*(1/(v[i-1].first-v[k-1].first));
                  }
              }
              wi=wi+pow(-1,j-1)*umn;
          }
          pr+=(wi*v[i-1].second)/(x-v[i-1].first);
          dr+=wi/(x-v[i-1].first);
          }
          y=pr/dr;
          return y;
          };
}
std::function <double(double)> BaricentricnaInterpolacija (std::function <double(double)> f,double xmin,double xmax,double dx,int n){
    std::vector<std::pair<double,double>> v;
    if(xmin>xmax || dx<=0)
    throw std::domain_error("Nekorektni parametri");
    for(double i(xmin);i<=xmax;i=i+dx){
        double y(f(i));
        v.push_back(std::make_pair(i,y));
    }
    auto f1(BaricentricnaInterpolacija(v,n));
    return f1;
}

int main(){
    try{
       auto funkc([](double x){return pow(x,2)+sin(x);});
       int n;
       std::cout << "Odaberite opciju (1 - unos cvorova, 2 - aproksimacija): ";
       std::cin >> n;
        if(n==1){
               int cv;
               std::cout << "Unesite broj cvorova: ";
               std::cin >> cv;
               std::cout << "Unesite cvorove kao parove x y: ";
               std::vector<std::pair<double,double>> v;
               for(int i=0;i<cv;i++){
                   double x,y;
                   std::cin >> x >>y;
                   v.push_back(std::make_pair(x,y));
               }
               std::cout << "Unesite red interpolacije: ";
               int red;
               std::cin >> red;
               std::function<double(double)> BI;
               try{
                BI=(BaricentricnaInterpolacija(v,red));
               }
               catch(std::domain_error d){
                   throw;
               }
               for(;;){
               std::cout << "Unesite argument (ili "<<'"'<< "kraj"<<'"'<<" za kraj): ";
               double arg;
               std::cin >> arg;
               if(!std::cin)
               break;
               std::cout << "f("<<arg<<")"<<" = " <<BI(arg) << std::endl;
                   }
           }
           if(n==2){
               double xmin,xmax,dx;
               std::cout << "Unesite krajeve intervala i korak: ";
               std::cin >> xmin>>xmax>>dx;
               std::cout << "Unesite red interpolacije: ";
               int red;
               std::cin >> red;
               std::function<double(double)> BI2 ;
               try{
                   BI2=BaricentricnaInterpolacija(funkc,xmin,xmax,dx,red);
               }
               catch(std::domain_error d){
                   throw;
               }
               for(;;){
                     std::cout << "Unesite argument (ili "<<'"'<< "kraj"<<'"'<<" za kraj): ";
                     double arg; 
                     std::cin >> arg;
                     if(!std::cin)
                     break;
                     else
                     std::cout << "f("<<arg<<") = "<<funkc(arg)<<" fapprox("<<arg<<") = "<<BI2(arg) << std::endl;
               }
           }
    }
    catch(std::domain_error d){
        std::cout << d.what();
    }
       
    return 0;
}