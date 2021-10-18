#include <iostream>
#include <functional>
#include <utility>
#include <vector>
#include <stdexcept>
#include <cmath>

typedef std::vector<std::pair<double,double>> VektorPar;

bool ImaIstihParova(VektorPar &parovi){
    for(int i = 0; i < parovi.size() - 1; i++){
        for(int j = i + 1; j < parovi.size(); j++){
            double razlika = std::abs(parovi[i].first-parovi[j].first);
            if(razlika < 0.00000001) return true;
        }
    }
    return false;
}

std::function<double(double)> BaricentricnaInterpolacija(VektorPar parovi, int d){
    int n = parovi.size();
    if(d <= 0 || d > n) throw std::domain_error("Nedozvoljen red");
    if(ImaIstihParova(parovi)) throw std::domain_error("Neispravni cvorovi");
    std::vector<double> w(n);
    int od_suma, do_suma, od_pr, do_pr;
    double clan_pr, suma;
    for(int i = 1; i <= n; i++){
        if(i - d >= 1) od_suma = i - d;
        else od_suma = 1;
        if(n - d <= i) do_suma = n - d;
        else do_suma = i;
        suma = 0;
        for(int k = od_suma; k <= do_suma; k++){
            clan_pr = 1;
            od_pr = k;
            do_pr = k + d;
            for(int j = od_pr; j <= do_pr; j++){
                if(i != j) clan_pr *= (1./(parovi[i-1].first - parovi[j-1].first));
            }
            if((k-1)%2 == 0) suma += clan_pr;
            else suma -= clan_pr;
        }
        w[i-1] = suma;
    }
    return [parovi,w](double x){
        for(int i = 0; i < parovi.size(); i++){
            double razlika = std::abs(parovi[i].first-x);
            if(razlika < 0.00000001) return parovi[i].second;
        }
        double suma_1(0),suma_2(0);
        for(int i = 1; i <= parovi.size(); i++){
            suma_1 += ((w[i-1]/(x-parovi[i-1].first))*parovi[i-1].second);
            suma_2 += (w[i-1]/(x-parovi[i-1].first));
        }
        return suma_1/suma_2;
    };
}

std::function<double(double)> BaricentricnaInterpolacija(double fun(double), double x_min, double x_max, double dx, int d){
    if(x_min > x_max || dx <= 0) throw std::domain_error("Nekorektni parametri");
    VektorPar v;
    int i = 0;
    while(x_min + i * dx <= x_max){
        std::pair<double,double> p;
        p.first = x_min + i * dx;
        p.second = fun(p.first);
        v.push_back(p);
        i++;
    }
    return BaricentricnaInterpolacija(v,d);
}

int main ()
{
    try{
        int izbor;
        double par1,par2,x;
        std::cout << "Odaberite opciju (1 - unos cvorova, 2 - aproksimacija): ";
        std::cin >> izbor;
        if(izbor == 1){
            int n,d;
            std::cout << "Unesite broj cvorova: ";
            std::cin >> n;
            VektorPar v(n);
            std::cout << "Unesite cvorove kao parove x y: ";
            for(int i = 0; i < n; i++){
                std::pair<double,double> p;
                std::cin >> par1 >> par2;
                p.first = par1;
                p.second = par2;
                v[i] = p;
            }
            std::cout << "Unesite red interpolacije: ";
            std::cin >> d;
            auto f(BaricentricnaInterpolacija(v, d));
            while(true){
                std::cout << "Unesite argument (ili \"kraj\" za kraj): ";
                std::cin >> x;
                if(!std::cin){
                    std::cin.clear();
                    break;
                }
                std::cout << "f(" << x << ") = " << f(x) << std::endl;
            }
        }
        if(izbor == 2){
            double x_min, x_max, dx;
            int d;
            std::cout << "Unesite krajeve intervala i korak: ";
            std::cin >> x_min >> x_max >> dx;
            std::cout << "Unesite red interpolacije: ";
            std::cin >> d;
            auto f(BaricentricnaInterpolacija([](double x) {return x * x + std::sin(x); }, x_min, x_max, dx, d));
            while(true){
                std::cout << "Unesite argument (ili \"kraj\" za kraj): ";
                std::cin >> x;
                if(!std::cin){
                    std::cin.clear();
                    break;
                }
                std::cout << "f(" << x << ") = " << x * x + std::sin(x);
                std::cout << " fapprox(" << x << ") = " << f(x) << std::endl;
            }
        }
    }
    catch (std::exception &e){
        std::cout << e.what();
    }
	return 0;
}