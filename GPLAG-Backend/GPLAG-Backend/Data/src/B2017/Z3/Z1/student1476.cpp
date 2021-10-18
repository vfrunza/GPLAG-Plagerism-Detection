/B2017/2018: Zadaća 3, Zadatak 1
#include <iostream>
#include <functional>
#include <vector>
#include <stdexcept>
#include <map>
#include <utility>
#include <algorithm>
#include <cmath>
double funkcija(double x){
    return x*x+sin(x);
}


std::function<double(double)>LinearnaInterpolacija(std::vector<std::pair<double,double>> cvorovi ){
    std::map<double,double> cv;
    int velicina=cvorovi.size();
    while (cvorovi.size()!=0) {
        cv.insert(cvorovi[0]);
        cvorovi.erase(cvorovi.begin());
    }
    if(velicina!=cv.size() || cv.size()==0)
        throw std::domain_error("Neispravni cvorovi");
    return [cv](double x)->double{
        auto zadnji=cv.end();
        zadnji--;
        if(x<(*cv.begin()).first or x>zadnji->first or cv.size()==0)
            throw std::range_error("Argument izvan opsega");
        if(zadnji->first==x)
            return zadnji->second;
        auto it=cv.upper_bound(x);
        auto a=*it;
        auto b=*(--it);
        return (b.second+(a.second-b.second)*(x-b.first)/(a.first-b.first));
    };
}
std::function<double(double)>LinearnaInterpolacija(std::function<double(double)> f,double xmin, double xmax,double dx ){
    if(xmin>xmax or dx<=0)
        throw std::domain_error("Nekorektni parametri");
    std::map<double,double> cv;
    for (int i = 0; xmin+i*dx<xmax; i++) {
        cv.insert(std::make_pair(xmin+i*dx,f(xmin+i*dx)));
    }
    cv.insert(std::make_pair(xmax,f(xmax)));
    return [cv](double x)->double{
        auto zadnji=cv.end();
        zadnji--;
        if(x<(*cv.begin()).first or x>zadnji->first or cv.size()==0)
            throw std::range_error("Argument izvan opsega");
        if(zadnji->first==x)
            return zadnji->second;
        auto it=cv.upper_bound(x);
        auto a=*it;
        auto b=*(--it);
        return (b.second+(a.second-b.second)*(x-b.first)/(a.first-b.first));
    };
}
int main ()
{
   std::cout << "Odaberite opciju (1 - unos cvorova, 2 - aproksimacija): " ;
   int o,n;
   std::cin >> o;
   if(o==1){
   std::cout << "Unesite broj cvorova: " ;
   std::cin >>  n;
   std::cout << "Unesite cvorove kao parove x y: " ;
   std::vector<std::pair<double,double>> cvorovi  ;
   for (int i = 0; i < n; i++) {
       double a,b;
       std::cin >> a>>b;
       cvorovi.push_back(std::make_pair(a,b));
   }
   try{
       auto f(LinearnaInterpolacija(cvorovi));
   while (1) {
    std::cout << "Unesite argument (ili \"kraj\" za kraj): ";
    double a;
    std::cin >> a;
    if(!std::cin) break;
    char s(std::cin.peek());
    if(s!='\n' && s!=' ' && s!='\t' )
        break;
    try{
    double rezultat(f(a));
    std::cout << "f("<<a<<") = "<<rezultat << std::endl;
    }catch(std::range_error izuzetak){
        std::cout << izuzetak.what() << std::endl;
    }
   }
       
   }
    catch(std::domain_error izuzetak){
        std::cout << izuzetak.what() <<std::endl;
        return 0;
    }
   }else{
       std::cout << "Unesite krajeve intervala i korak: " ;
       double a,b,c;
       std::cin >> a>>b>>c;
       try{
                auto f(LinearnaInterpolacija(funkcija,a,b,c));
       while (1) {
            std::cout << "Unesite argument (ili \"kraj\" za kraj): ";
            double u;
            std::cin >> u;
            if(!std::cin) break;
            char s(std::cin.peek());
            if(s!='\n' && s!=' ' && s!='\t' )
                break;
                try{
                    double rezultat(f(u));
                    std::cout << "f("<<u<<") = "<<funkcija(u)<<" "<<"fapprox("<<u<<") = " <<rezultat << std::endl;
                }catch(std::range_error izuzetak){
                    std::cout << izuzetak.what() << std::endl;
                }
       }
       }
            catch(std::domain_error izuzetak){
                std::cout << izuzetak.what() <<std::endl;
                return 0;
            }
   }
           
  
	return 0;
}
