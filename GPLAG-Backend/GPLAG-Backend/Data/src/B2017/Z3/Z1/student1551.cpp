/B2017/2018: Zadaća 3, Zadatak 1
#include <iostream>
#include <vector>
#include <utility>
#include <cmath>
#include <functional>
#include <stdexcept>
#include <algorithm>
#include <tuple>


std::function <double (double)> LinearnaInterpolacija (std::vector <std::pair<double,double>> v){
    std::sort(v.begin(),v.end());
    
    for(int i=0; i<v.size(); i++){              //provjera jesu li x[i] isti
        for (int j=0; j<v.size(); j++){
            if (i==j) continue;
            if (v.at(i).first==v.at(j).first){
             throw std::domain_error("Neispravni cvorovi");
            }
        }
    }
    
    return [v] (double x){
        
        if (v.size()==0) throw  std::range_error ("Argument izvan opsega");
        if (x<v.at(0).first || x>v.at(v.size()-1).first) throw std::range_error ("Argument izvan opsega");
        if (x==v.at(v.size()-1).first) return v.at(v.size()-1).second;
       std::pair<double , double> test {x , 0};
        
        auto prije = upper_bound (v.begin(), v.end(), test);
        auto poslije=prije;
        poslije++;
        if (x!=prije->first) prije--, poslije--;
        return (prije->second+((poslije->second-prije->second)/(poslije->first-prije->first))*(x-prije->first));
    };
}

std::function <double (double)> LinearnaInterpolacija (std::function <double (double)> f, double xmin, double xmax, double deltax){
    
    if(xmin>xmax || deltax<=0) throw std::domain_error("Nekorektni parametri");
    
    std::vector<std::pair<double, double>> v;
    
   for (int i=0; (xmin+i*deltax)<xmax; i++){
        v.push_back(std::make_pair(xmin+i*deltax,f(xmin+i*deltax)));
    }
    
    return LinearnaInterpolacija(v);
}

int main ()
{
    std::cout << "Odaberite opciju (1 - unos cvorova, 2 - aproksimacija): ";
    int opcija;
    std::cin >> opcija;

    std::vector<std::pair<double,double>> v;
    if (opcija==1){
        std::cout << "Unesite broj cvorova: ";
        int n;
        std::cin >> n;
        std::cout << "Unesite cvorove kao parove x y: ";
        
        for (int i=0; i<n; i++){
            double prvi,drugi;
            std::pair<double,double> par;
            std::cin >> prvi >> drugi;
            par={prvi,drugi};
            v.push_back(par);
        }
        try {
        auto fja=LinearnaInterpolacija(v);
        while (1){
            std::cout << "Unesite argument (ili \"kraj\" za kraj): ";
            double arg;
            std::cin >> arg;
                if (!std::cin || std::cin.peek()!='\n'){
                std::cin.clear();
                std::cin.ignore(1000, '\n');
                break;
            }
            
            try {
                auto vr=fja(arg);
                std::cout << "f(" << arg <<") = " << vr << std::endl;
            }
            catch (std::domain_error a){
                std::cout << a.what() << std::endl;
            }
            catch (std::range_error a) {
                std::cout << a.what() << std::endl;
            }
        }
    }       
    catch (std::domain_error a){
        std::cout << a.what() << std::endl;
    }
     catch (std::range_error a) {
        std::cout << a.what() << std::endl;
    }
} else {
    std::cout << "Unesite krajeve intervala i korak: ";
        double min,max,deltax;
        std::cin >> min >> max >> deltax;
        try {
        auto g=LinearnaInterpolacija([](double x){ return (pow(x,2)+sin(x));}, min,max,deltax);
        while (1){
            std::cout << "Unesite argument (ili \"kraj\" za kraj): ";
            double arg;
            std::cin >> arg;
                if (!std::cin || std::cin.peek()!='\n'){
                std::cin.clear();
                std::cin.ignore(1000, '\n');
                break;
            }
            try {
                auto vr=g(arg);
                std::cout << "f(" << arg <<") = " << pow(arg,2)+sin(arg) << " fapprox(" << arg << ") = " << vr << std::endl;
            }
            catch (std::domain_error a){
                std::cout << a.what() << std::endl;
            }
            catch (std::range_error a) {
                std::cout << a.what() << std::endl;
            }
        }
    }       
            
    catch (std::domain_error a){
        std::cout << a.what() << std::endl;
    }
     catch (std::range_error a) {
        std::cout << a.what() << std::endl;
    }
    
}
 return 0;
}
