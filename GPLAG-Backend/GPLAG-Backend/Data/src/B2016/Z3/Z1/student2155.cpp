#include <iostream>
#include <functional>
#include <vector>
#include <utility>
#include <stdexcept>
#include <cmath>
bool Jednaki(double x,double y){
    return std::fabs(x-y) < 10e-7*(std::fabs(x)+std::fabs(y));
}
bool IspravanCvor(const std::vector<std::pair<double,double>> &cvorovi){
    for(int i(0);i < cvorovi.size();i++){
        for(int j(i+1);j < cvorovi.size();j++){
            if((long double)cvorovi[i].first==(long double)cvorovi[j].first)return false;
        }
    }
    return true;
}
double DajTezinskiKoeficijent(const std::vector<std::pair<double,double>> &cvorovi,int i,int d,int n){
    int poc,granica;
    double w(0);
    if(1 >= i - d)poc=1;
    else poc = i - d;
    if(i <= n - d)granica = i;
    else granica = n - d;
    for(int k(poc);k <= granica;k++){
        double proizvod(std::pow(-1,k-1));
        for(int j(k);j <= k + d;j++){
            if(j==i)continue;
            proizvod*=1/(cvorovi[i-1].first-cvorovi[j-1].first);
        }
        w+=proizvod;
    }
    return w;
}
std::function<double(double)> BaricentricnaInterpolacija(const std::vector<std::pair<double,double>> &cvorovi,int d){
    if(!IspravanCvor(cvorovi))throw std::domain_error("Neispravni cvorovi");
    if(!(d >= 0 && d < cvorovi.size()))throw std::domain_error("Nedozvoljen red");
    std::vector<double> koeficijenti;
    for(int i(1);i <= cvorovi.size();i++)koeficijenti.push_back(DajTezinskiKoeficijent(cvorovi,i,d,cvorovi.size()));
    return [cvorovi,d,koeficijenti](double x){
        double suma1(0),suma2(0);
        for(int i(0);i < cvorovi.size();i++){
            if((long double)x == (long double)cvorovi[i].first)return cvorovi[i].second;
        }
        for(int i(1);i <= cvorovi.size();i++){
            suma1+=koeficijenti[i-1]*(cvorovi[i-1].second)/(x-cvorovi[i-1].first);
            suma2+=koeficijenti[i-1]/(x-cvorovi[i-1].first);
        }
        return suma1/suma2;
    };
}
std::function<double(double)> BaricentricnaInterpolacija(std::function<double(double)> f,double x_min,double x_max,double dx,int d){
    if((long double)x_min > (long double)x_max || dx <= 0)throw std::domain_error("Nekorektni parametri");
    std::vector<std::pair<double,double>> cvorovi;
    for(double i(x_min);i <= (long double)x_max;i+=dx)cvorovi.push_back({i,f(i)});
    return BaricentricnaInterpolacija(cvorovi,d);
}
int main ()
{
    std::vector<std::pair<double,double>> cvorovi;
    
        int unos,broj,d;
        std::cout << "Odaberite opciju (1 - unos cvorova, 2 - aproksimacija): ";
        std::cin >> unos;
        if(unos == 1){
            std::cout << "Unesite broj cvorova: ";
            std::cin >> broj;
            if(!std::cin)return 0;
            std::cout << "Unesite cvorove kao parove x y: ";
            for(int i(0);i < broj;i++){
                double x,y;
                std::cin >> x >> y;
                if(!std::cin)return 0;
                cvorovi.push_back({x,y});
            }
            std::cout << "Unesite red interpolacije: ";
            std::cin >> d;
            if(!std::cin)return 0;
            std::function<double(double)> f;
            try{
            f = BaricentricnaInterpolacija(cvorovi,d);
            }catch(std::domain_error izuzetak){
                std::cout << izuzetak.what();
                return 0;
            }
            for(;;){
                double x;
                std::cout << "Unesite argument (ili \"kraj\" za kraj): ";
                if(!std::cin)return 0;
                std::cin >> x;
                if(!std::cin)return 0;
                std::cout << "f(" << x << ") = " << f(x) << std::endl;
            }
        }else if(unos == 2){
            std::cout << "Unesite krajeve intervala i korak: ";
            double x_min,x_max,dx;
            std::cin >> x_min >> x_max >> dx;
            if(!std::cin)return 0;
            std::cout << "Unesite red interpolacije: ";
            std::cin >> d;
            if(!std::cin)return 0;
            std::function<double(double)> f;
            try{
            f = BaricentricnaInterpolacija([](double x){return x*x+sin(x);},x_min,x_max,dx,d);
            }catch(std::domain_error izuzetak){
                std::cout << izuzetak.what();
                return 0;
            }
            for(;;){
                double x;
                std::cout << "Unesite argument (ili \"kraj\" za kraj): ";
                std::cin >> x;
                if(!std::cin)return 0;
                std::cout << "f(" << x << ") = " << [](double x){return x*x + sin(x);}(x) << " fapprox(" << x << ") = " << f(x) << std::endl;
            }
        }
	return 0;
}