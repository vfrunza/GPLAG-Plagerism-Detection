/B2016/2017: Zadaća 3, Zadatak 1
//Autotestovi by Enil Pajic (epajic1@etf.unsa.ba)
#include <iostream>
#include <vector>
#include <functional>
#include <utility>
#include <stdexcept>
#include <cmath> 
#include <algorithm>

const double Eps(1e-7);

bool PorediDecimalne(double a, double b){
    return (fabs(a-b) <= Eps * (fabs(a)+fabs(b)));
}

std::function<double(double)> BaricentricnaInterpolacija(std::vector<std::pair<double, double>> v, int d){
	if(d >= v.size() || d < 0) throw std::domain_error ("Nedozvoljen red");
	int n(v.size());
	
	for(int i = 0; i < n; i++){
		for(int j = i + 1; j < n; j++){
			if(PorediDecimalne(v[i].first,v[j].first)) throw std::domain_error ("Neispravni cvorovi");
		}
	}
	
	std::vector<double> w(n);
	int min(0), max(0);
	
	std::sort(v.begin(), v.end());

	for(int i = 1; i <= n; i++){
		if(1 > i-d) max = 1; else max = i-d;
		if(i < n-d) min = i; else min = n-d;
		
		for(int k = max; k <= min; k++){
			double proizvod = 1;
			for(int j = k; j <= k + d; j++){
				if(j == i) continue;
				proizvod *= 1./(v[i-1].first - v[j-1].first);
			}
			w[i-1] += pow(-1, k-1) * proizvod;
		}
	}
	
	return [w, n, v] (double a){
		double brojnik(0), nazivnik(0);
		for(int i = 1; i <= n; i++){
			if(PorediDecimalne(v[i-1].first, a)) return v[i-1].second;
			brojnik += (w[i-1] * v[i-1].second ) / (a - v[i-1].first);
			nazivnik += w[i-1] / (a - v[i-1].first);
		}
		return brojnik/nazivnik;
	};
}

std::function<double(double)> BaricentricnaInterpolacija (std::function<double(double)> fun, double min, double max, double delta, int d){
	if(min > max || delta <= 0) throw std::domain_error ("Nekorektni parametri");
	
	std::vector<std::pair<double, double>> v;
	double x (min);
	while (x <= max){
		v.push_back(std::make_pair(x, fun(x)));
		x += delta;
	}
	return BaricentricnaInterpolacija(v,d);
}

double fun (double x){
	return x*x + std::sin(x);
}


int main ()
{
	std::vector<std::pair<double, double>> v;
	int n(0), opcija(0), d(0);
	double arg(0);
	
	std::cout << "Odaberite opciju (1 - unos cvorova, 2 - aproksimacija): ";
	std::cin >> opcija;
	
	if(opcija == 1){
		std::cout << "Unesite broj cvorova: ";
		std::cin >> n;
		v.resize(n);
		std::cout << "Unesite cvorove kao parove x y: ";
		for(int i = 0; i < n; i++) std::cin >> v[i].first >> v[i].second;
	
		std::cout << "Unesite red interpolacije: ";
		std::cin >> d;
		while(1){
			std::cout << "Unesite argument (ili \"kraj\" za kraj): ";
			std::cin >> arg;
			if(!std::cin) break;
			else{
				try{
					auto f(BaricentricnaInterpolacija(v,d));
					std::cout << "f(" << arg << ") = " << f(arg) << std::endl;
				}
				catch(std::domain_error e){
					std::cout << e.what();
					return 0;
				}
			}
		}
	}
	
	if(opcija == 2){
			double min(0), max(0), delta(0);
			std::cout << "Unesite krajeve intervala i korak: ";
			std::cin >> min >> max >> delta;
			std::cout << "Unesite red interpolacije: ";
			std::cin >> d;
			while(1){
				std::cout << "Unesite argument (ili \"kraj\" za kraj): ";
				std::cin >> arg;
				if(!std::cin) break;
				try{
					auto f(BaricentricnaInterpolacija(fun, min, max, delta, d));
					std::cout << "f(" << arg << ") = " << fun(arg) << " " << "fapprox" << "(" << arg << ") = " << f(arg) << std::endl;
				}
				catch(std::domain_error e){
					std::cout << e.what();
					return 0;
				}
			}
	}
	return 0;
}

