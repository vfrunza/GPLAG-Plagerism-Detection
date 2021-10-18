/B2017/2018: Zadaća 3, Zadatak 1
#include <iostream>
#include <vector>
#include <utility>
#include <functional>
#include <algorithm>
#include <stdexcept>
#include <cmath>

const double E(0.0000001);

double funk(double x)
{
	return x*x+std::sin(x);
}

bool Unos(double &argument)
{
	char z('"');
	std::cout<<"Unesite argument (ili "<<z<<"kraj"<<z<<" za kraj): ";
	std::cin>>argument;
	if(!std::cin) {
		std::cin.clear();
		return false;
	}
	return true;
}

bool ProvjeraCvorova(std::vector<std::pair<double, double>> v)
{
	for(int i=0; i<v.size(); i++) {
		for(int j=i+1; j<v.size(); j++) if(std::fabs(v[i].first-v[j].first)<E) throw std::domain_error("Neispravni cvorovi");
	}
	return true;
}

std::function<double(double)> LinearnaInterpolacija(std::vector<std::pair<double, double>> v)
{
	int vel(v.size());
	ProvjeraCvorova(v);
	std::sort(v.begin(), v.end(), [](std::pair<double, double> p1, std::pair<double, double> p2) {
		return p1.first<p2.first;
	});
	return [v, vel](double x)->double {
		if(v.size()==0 || x<v[0].first || x>v[vel-1].first) throw std::range_error("Argument izvan opsega");
		if(std::fabs(x-v[vel-1].first)<E) return v[vel-1].second;
		if(std::fabs(x-v[0].first)<E) return v[0].second;
		std::pair<double, double> px(x, 0), m, n;
		auto t=std::lower_bound(v.begin(), v.end(), px,
		[](std::pair<double, double> p1, std::pair<double, double> p2) {
			return p1.first<p2.first;
		});
		m=*t;
		t--;
		n=*t;
		return n.second+(m.second-n.second)/(m.first-n.first)*(x-n.first);
	};
}

std::function<double(double)> LinearnaInterpolacija(double f(double), double xmin, double xmax, double korak)
{
	if(xmin>xmax || korak<=0) throw std::domain_error("Nekorektni parametri");
	std::vector<std::pair<double, double>> v;
	for(double i=xmin; i<=xmax; i+=korak) {
		double a(i), b(f(i));
		v.push_back(std::make_pair(a, b));
	}
	return LinearnaInterpolacija(v);
}

int main ()
{
	int opcija;
	std::cout<<"Odaberite opciju (1 - unos cvorova, 2 - aproksimacija): ";
	std::cin>>opcija;
	if(opcija==1) {
		int br_cvorova;
		std::cout<<"Unesite broj cvorova: ";
		std::cin>>br_cvorova;
		std::vector<std::pair<double, double>> v(br_cvorova);
		std::cout<<"Unesite cvorove kao parove x y: ";
		for(int i=0; i<br_cvorova; i++) {
			double a, b;
			std::cin>>a>>b;
			v[i]=std::make_pair(a, b);
		}
		try {
			LinearnaInterpolacija(v);
		} catch(std::domain_error izz) {
			std::cout<<izz.what()<<std::endl;
			return 0;
		}
		for(;;) {
			double argument;
			if(Unos(argument)) {
				try {
					auto f(LinearnaInterpolacija(v));
					std::cout<<"f("<<argument<<") = "<<f(argument)<<std::endl;
				} catch(std::range_error izz) {
					std::cout<<izz.what()<<std::endl;
				}
			} else return 0;
		}
	}
	if(opcija==2) {
		double poc_intervala, kraj_intervala, korak;
		std::cout<<"Unesite krajeve intervala i korak: ";
		std::cin>>poc_intervala>>kraj_intervala>>korak;
		try {
			auto f(LinearnaInterpolacija(funk, poc_intervala, kraj_intervala, korak));
		} catch(std::domain_error izz) {
			std::cout<<izz.what()<<std::endl;
			return 0;
		}
		for(;;) {
			double argument;
			if(Unos(argument)) {
				try {
					auto f(LinearnaInterpolacija(funk, poc_intervala, kraj_intervala, korak));
					std::cout<<"f("<<argument<<") = "<<funk(argument)<<" fapprox("<<argument<<") = "<<f(argument)<<std::endl;
				} catch(std::range_error izz) {
					std::cout<<izz.what()<<std::endl;
				}
			} else return 0;
		}
	}
	return 0;
}