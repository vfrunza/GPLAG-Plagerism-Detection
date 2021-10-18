/B2016/2017: Zadaća 3, Zadatak 1
//Autotestovi by Enil Pajic (epajic1@etf.unsa.ba)
#include <iostream>
#include <utility>
#include <vector>
#include <cmath>
#include <functional>
#include <stdexcept>

double Proizvod(std::vector<std::pair<double, double>> x, int k, int d, int i){
    double proizvod(1);
    for(int j=k; j<=k+d; j++){
    if(j==i) continue;
    proizvod*=1./(x[i-1].first-x[j-1].first);
    }
    return proizvod;
}


double TezinskiKoeficijenti(int i, int n, int d,std::vector<std::pair<double, double>> x){
    double suma(0), proizvod(1);
    int k, min;
    if(i<=n-d) min=i; else min=n-d;
    if(1>=i-d) k=1; else k=i-d;
    for(int j=k; j<=min; j++){
        proizvod=Proizvod(x, j, d, i);
        suma+=pow(-1, j-1)*proizvod;
    }
    return suma;
}

std::function<double(double)> BaricentricnaInterpolacija(std::vector<std::pair<double, double>> v, int d){
    int n(v.size());
    if(d<0 || d>=n) throw std::domain_error("Nedozvoljen red");
    for(int i=0; i<v.size(); i++)
        for(int j=i+1; j<v.size(); j++)
            if(v[j].first==v[i].first) throw std::domain_error("Neispravni cvorovi");
    std::vector<double> w(n);
    for(int i=1; i<=n; i++)
       w[i-1]=TezinskiKoeficijenti(i, n, d, v);
 
    return [=](double x){ double brojnik(0), nazivnik(0);for(int i=1; i<=n; i++){ 
        if(x==v[i-1].first){ return v[i-1].second;
        }
        else brojnik+=((w[i-1]*v[i-1].second)/(x-v[i-1].first));
        nazivnik+=(w[i-1])/(x-v[i-1].first);
    }
        return brojnik/nazivnik;};
    }
    
std::function<double(double)> BaricentricnaInterpolacija(std::function<double(double)> f, double x_min, double x_max, double delta_x, int d){
        if(x_min>x_max || delta_x<=0) throw std::domain_error("Nekorektni parametri");
        std::vector<std::pair<double, double>> v;
        double c(x_min);
        while(c<=x_max){
            v.push_back(std::make_pair(c, f(c)));
            c+=delta_x;
        }
        auto funkcija(BaricentricnaInterpolacija(v, d));
        return funkcija;
    }
int main ()
{
    try{
    int a;
    std::vector<std::pair<double, double>> v;
    std::cout << "Odaberite opciju (1 - unos cvorova, 2 - aproksimacija): ";
    std::cin >> a;
    if(a==1){
        int n;
        std::cout << "Unesite broj cvorova: ";
        std::cin >> n;
         v.resize(n);
        std::cout << "Unesite cvorove kao parove x y: ";
        for(int i=0; i<n; i++){
            std::cin >> v[i].first >> v[i].second;
        }
        std::cout << "Unesite red interpolacije: ";
        int d;
        std::cin >> d;
        BaricentricnaInterpolacija(v, d);
        do{
            double x;
        std::cout << "Unesite argument (ili \"kraj\" za kraj): ";
        std::cin >> x;
        if(!std::cin || std::cin.peek()!='\n') break;
        auto f(BaricentricnaInterpolacija(v, d));
        std::cout << "f(" << x << ") = " << f(x) << std::endl; 
        }while(std::cin);
        
        std::cin.clear();
        std::cin.ignore(10000,'\n');
    }
    if(a==2){
        std::cout << "Unesite krajeve intervala i korak: ";
        double x_min, x_max, delta_x;
        std::cin >> x_min >> x_max >> delta_x;
        std::cout << "Unesite red interpolacije: ";
        int d;
        std::cin >> d;
        auto fapprox(BaricentricnaInterpolacija([] (double x) { return x*x + std::sin(x);}, x_min, x_max, delta_x, d));
        do{
            double x;
            std::cout << "Unesite argument (ili \"kraj\" za kraj): ";
            std::cin >> x;
            if(!std::cin || std::cin.peek()!='\n') break;
            std::cout << "f(" << x << ") = " << x*x+std::sin(x) << " fapprox(" << x << ") = " << fapprox(x) << std::endl;
            
    } while(std::cin);    
    }
    }
    catch(std::domain_error izuzetak){
        std::cout << izuzetak.what();
    }
        return 0;
}
        