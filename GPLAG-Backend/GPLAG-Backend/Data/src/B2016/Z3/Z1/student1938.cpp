#include <iostream>
#include <functional>
#include <vector>
#include <utility>
#include <stdexcept>
#include <cmath>

double test(double x){
    return x * x + std::sin(x);
}
int max(int a, int b){
    if(a>b) return a; return b;
}
int min(int a, int b){
    if(a<b) return a; return b;
}
std::function<double(double)> BaricentricnaInterpolacija(std::vector<std::pair<double,double>> v, int d){
    std::vector<double> vekW;
    int n(v.size());
    if(d < 0 || d >= n) throw std::domain_error("Nedozvoljen red");
    for(int i = 0; i < n; i++)
        for(int j = i+1; j < n; j++)
            if(v[i].first == v[j].first) throw std::domain_error("Neispravni cvorovi");
    for(int i = 1; i <= n; i++){
        double w(0);
        for(int k = max(1,i-d); k <= min(i,n-d); k++){
            int sgn(1); if(k%2 == 0) sgn = -1;
            double prod(sgn);
            for(int j = k; j <= k+d; j++) 
                if(j != i) prod *= 1/(v[i-1].first - v[j-1].first);
            w += prod;
        }
        vekW.push_back(w);
    }
    return [vekW, v,n](double x){
        double sum1(0), sum2(0);
        for(int i = 0; i < n; i++) if(x == v[i].first) return v[i].second;
        for(int i = 1; i <= n; i++) sum1 += (vekW[i-1] * v[i-1].second)/(x - v[i-1].first);
        for(int i = 1; i <= n; i++) sum2 += vekW[i-1]/(x - v[i-1].first);
        return sum1/sum2;
    };
}
std::function<double(double)> BaricentricnaInterpolacija(std::function<double(double)> f, double xMin, double xMax, double dx, int d){
    std::vector<std::pair<double,double>> v;
    if(xMin > xMax || dx <= 0) throw std::domain_error("Nekorektni parametri");
    for(double x = xMin; x <= xMax; x += dx) 
        v.push_back(std::make_pair(x, f(x)));
    return BaricentricnaInterpolacija(v,d);
}
int main () {
    std::cout << "Odaberite opciju (1 - unos cvorova, 2 - aproksimacija): ";
    int opt;
    try{
        std::cin >> opt;
        if(opt == 1){
            std::cout << "Unesite broj cvorova: ";
            int n,x,y; 
            std::cin >> n;
            std::cout << "Unesite cvorove kao parove x y: ";
            std::vector<std::pair<double,double>> v;
            for(int i = 0; i < n; i++){
                std::cin >> x >> y;
                v.push_back(std::make_pair<double,double>(x,y));
            }
            std::cout << "Unesite red interpolacije: ";
            int d; std::cin >> d;
            auto f = BaricentricnaInterpolacija(v,d);
            for(;;){
                std::cout << "Unesite argument (ili \"kraj\" za kraj): ";
                double arg; std::cin >> arg;
                if(!std::cin || std::cin.peek() != '\n') break;
                std::cout << "f(" << arg << ") = " << f(arg) << std::endl;
            }
        }
        else if(opt == 2){
            std::cout << "Unesite krajeve intervala i korak: ";
            double xMin, xMax, dx;
            std::cin >> xMin >> xMax >> dx;
            std::cout << "Unesite red interpolacije: ";
            int d; std::cin >> d;
            auto f = BaricentricnaInterpolacija(test,xMin,xMax,dx,d);
            for(;;){
                std::cout << "Unesite argument (ili \"kraj\" za kraj): ";
                double arg; std::cin >> arg;
                if(!std::cin || std::cin.peek() != '\n') break;
                std::cout << "f(" << arg << ") = " << test(arg) << " fapprox(" << arg << ") = " << f(arg) << std::endl;
            }
        }
    }catch(std::domain_error err){
        std::cout << err.what();
    }
	return 0;
}