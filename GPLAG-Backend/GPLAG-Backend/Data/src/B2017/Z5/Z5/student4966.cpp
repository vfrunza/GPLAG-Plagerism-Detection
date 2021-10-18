/B2017/2018: Zadaća 5, Zadatak 5
#include <iostream>
#include <cmath>
#include <vector>
#include <initializer_list>
#include <functional>
#include <utility>
#include <algorithm>
#include <stdexcept>

class FourierovRed {
	static constexpr double PI = 4*std::atan(1.);
	double period;
	std::vector<double> nizAk;
	std::vector<double> nizBk;
	int stepen;
public:
	FourierovRed(double t, std::initializer_list<double> ak, std::initializer_list<double> bk);
	FourierovRed(int n, double t, std::function<double(int)> f1, std::function<double(int)> f2);
	FourierovRed(int n, double p, double q, std::function<double(double)> f, int m);
	double operator()(double x) const;
	std::pair<double&, double&> operator [](int k);
	std::pair<double, double> operator [](int k) const;
	~FourierovRed();
	FourierovRed(const FourierovRed &fr);
	FourierovRed(FourierovRed &&fr);
	FourierovRed &operator =(const FourierovRed &fr);
	FourierovRed &operator =(FourierovRed &&fr);
};
int main()
{
	FourierovRed f(2 * 3.14159, { 2,3,4,5 }, { 3,4,5,6,7,8 });
	FourierovRed f2(f);
	FourierovRed f3(10, -3.14159, 3.14159, [](double x) { return x*x; }, 50);
	std::cout << f3(2);
    return 0;
}

// IMPLEMENTACIJA
	// FourierovRed::public

FourierovRed::~FourierovRed() {}
FourierovRed::FourierovRed(const FourierovRed &fr) : period(fr.period), stepen(fr.stepen){
	for (int i = 0; i <= stepen; i++) {
		nizAk.push_back(fr.nizAk[i]);
		nizBk.push_back(fr.nizBk[i]);
	}
}
FourierovRed::FourierovRed(FourierovRed &&fr) : period(fr.period), stepen(fr.stepen), nizAk(std::move(fr.nizAk)), nizBk(std::move(fr.nizBk)) {}
FourierovRed& FourierovRed::operator =(const FourierovRed &fr) {
	stepen=fr.stepen; period=fr.period; nizAk=fr.nizAk; nizBk=fr.nizBk;
	return *this;
}
FourierovRed& FourierovRed::operator =(FourierovRed &&fr) {
	std::swap(nizAk, fr.nizAk); std::swap(nizBk, fr.nizBk);
	std::swap(period, fr.period); std::swap(stepen, fr.stepen);
	return *this;
}
FourierovRed::FourierovRed(double t, std::initializer_list<double> ak, std::initializer_list<double> bk) {
	stepen = ak.size()+1 > bk.size() ? ak.size() - 1 : bk.size();
	period = t;
	auto it(ak.begin()), it2(bk.begin());
	for (int i = 0; i <= stepen; i++) {
		if (i < int(ak.size())) nizAk.push_back(*it);
		else nizAk.push_back(0);
			it++;
	}
	for (int i = 0; i <= stepen; i++) {
		if (i != 0 && i <= int(bk.size())) nizBk.push_back(*it2++);
			else nizBk.push_back(0);
	}
	
}
FourierovRed::FourierovRed(int n, double t, std::function<double(int)> f1, std::function<double(int)> f2) {
	if (n <= 0) throw std::domain_error("Stepen mora biti pozitivan");
	stepen = n;
	period = t;
	for (int i = 0; i <= stepen; i++) {
		nizAk.push_back(f1(i));
		if (i != 0) nizBk.push_back(f2(i));
		else nizBk.push_back(0);
	}

}
FourierovRed::FourierovRed(int n, double p, double q, std::function<double(double)> f, int m) {
	if (n < 0) throw std::domain_error("Stepen mora biti pozitivan");
	if (m <= 0) throw std::domain_error("Broj podintervala mora biti pozitivan");
	if (p >= q) throw std::range_error("Neispravan interval");
	stepen = n; period = q - p;
		for (int i = 0; i <= stepen; i++) {
			double suma1(0), suma2(0);
			for (int j = 1; j <= m - 1; j++) {
				suma1 += f(p + j*period / m)*std::cos(2 * i*PI*((p / period) + double(j / m)));
				suma2 += f(p + j*period / m)*std::sin(2 * i*PI*((p / period) + double(j / m)));
			}
			nizAk.push_back((f(p) + f(q))*std::cos(2 * i*PI*p / period) / m + 2 * suma1 / m);
			nizBk.push_back((f(p) + f(q))*std::sin(2 * i*PI*p / period) / m + 2 * suma2 / m);
		}
	
}
double FourierovRed::operator()(double x) const {
	double sumakosinusa(0), sumasinusa(0);
	for (int i = 1; i <= stepen; i++) {
		sumakosinusa += nizAk[i] * std::cos(2 * PI*i*x / period);
		sumasinusa += nizBk[i] * std::sin(2 * PI*i*x / period);
	}
	return (nizAk[0] / 2.) + sumakosinusa + sumasinusa;
}
std::pair<double&, double&> FourierovRed::operator [](int k) {
	if (k<0 || k>stepen) throw std::range_error("Neispravan indeks");
	return std::make_pair(std::ref(nizAk[k]), std::ref(nizBk[k]));
}
std::pair<double, double> FourierovRed::operator [](int k) const {
	if (k<0 || k>stepen) throw std::range_error("Neispravan indeks");
	return std::make_pair(nizAk[k], nizBk[k]);
}

