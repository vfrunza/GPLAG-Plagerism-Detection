#include <algorithm>
#include <utility>
#include <iostream>
#include <string>
#include <deque>
#include <vector>
#include <cmath>
#include <stdexcept>
#include <functional>

double f (double x) {
	return std::sin(x)+x*x;
}

std::function<double(double)> LinearnaInterpolacija (std::vector<std::pair<double, double>> v) {
	const double eps=pow(10, -10);
	int n=v.size();
	for (int i=0; i<n; i++) {
		for (int j=i+1; j<n; j++) {
			if (std::fabs(v.at(i).first-v.at(j).first)<eps*(std::fabs(v.at(i).first)+std::fabs(v.at(j).first))) {
				throw std::domain_error("Neispravni cvorovi");
			}
		}
	}
	std::sort(v.begin(), v.end());
	return  [v] (double t) {
		if (t<v.at(0).first or t>v.at(v.size()-1).first) throw std::range_error("Argument izvan opsega");
		for (int i=0; i<v.size(); i++) {
			if (t==v.at(i).first) return v.at(i).second;
		}
		auto it=std::lower_bound(v.begin(), v.end(), std::make_pair(t, 0), [] (std::pair<double, double> jedan, std::pair<double, double> dva) {return jedan.first<=dva.first;});
		int index=0;
		for (int i=0; i<v.size(); i++) {
			if (*it==v.at(i)) index=i-1;
		}
		return v.at(index).second+(((v.at(index+1).second-v.at(index).second)/(v.at(index+1).first-v.at(index).first))*(t-v.at(index).first));
	};
}

std::function<double(double)> LinearnaInterpolacija (std::function<double(double)> f, double xmin, double xmax, double dx) {
	if (xmin>xmax or dx<=0) throw std::domain_error("Nekorektni parametri");
	std::vector<std::pair<double, double>> p;
	auto temp=xmin;
	int brojac(0);
	while (temp<xmax) {
		brojac++;
		p.resize(brojac);
		p.at(brojac-1).first=temp;
		p.at(brojac-1).second=f(temp);
		temp+=dx;
	}
	return LinearnaInterpolacija(p);
}

int main ()
{
	try {
		const double eps=pow(10, -10);
	    int opcija(0);
    	std::vector<std::pair<double, double>> v (0);
	    std::cout << "Odaberite opciju (1 - unos cvorova, 2 - aproksimacija): ";
    	std::cin >> opcija;
		if (opcija==1) {
		    int n;
	    	std::cout << "Unesite broj cvorova: ";
		    std::cin >> n;
		    v.resize(n);
	    	std::cout << "Unesite cvorove kao parove x y: ";
		    double k, p;
		    for (int i=0; i<n; i++) {
	    	    std::cin >> k;
	        	std::cin >> p;
		        v.at(i).first=k;
		        v.at(i).second=p;
	    	}
	    	std::sort(v.begin(), v.end());
			double t;
		    while (1) {
		    	for (int i=0; i<v.size(); i++) {
		    		for (int j=i+1; j<v.size(); j++) {
		    			if (std::fabs(v.at(i).first-v.at(j).first)<eps*(std::fabs(v.at(i).first)+std::fabs(v.at(j).first))) {
		    				throw std::domain_error("Neispravni cvorovi");
		    			}
		    		}
		    	}
	    	    std::cout << "Unesite argument (ili " << '"' << "kraj" << '"' << " za kraj): ";
	        	std::cin >> t;
	        	if (!std::cin) break;
				try {
	        		std::cout << "f(" << t << ") = " << LinearnaInterpolacija(v)(t) << std::endl;
				}
				catch (std::range_error izuzetak) {
					std::cout << izuzetak.what() << std::endl;
				}
		    }
		}
		if (opcija==2) {
			double xmin, xmax, dx;
			std::cout << "Unesite krajeve intervala i korak: ";
			std::cin >> xmin >> xmax >> dx;
			double t;
			while (1) {
				if (xmin>xmax or dx<=0) throw std::domain_error("Nekorektni parametri");
				std::cout << "Unesite argument (ili " << '"' << "kraj" << '"' << " za kraj): ";
				std::cin >> t;
				if (!std::cin) break;
				try {
					std::cout << "f(" << t << ") = " << f(t) << " fapprox(" << t << ") = " <<  LinearnaInterpolacija(f, xmin, xmax, dx)(t) << std::endl;
				}
				catch (std::range_error izuzetak) {
					std::cout << izuzetak.what() << std::endl;
				}
			}
		}
	}
	catch (std::domain_error izuzetak1) {
		std::cout << izuzetak1.what() << std::endl;
	}
	return 0;
}
