/B2017/2018: Zadaća 5, Zadatak 5
#include <iostream>
#include <iomanip>
#include <vector>
#include <initializer_list>
#include <functional>
#include <cmath>
#include <utility>
#include <memory>

const double pi = 4. * atan(1);


class FourierovRed{
    std::vector<double> a;
    std::vector<double> b;
    int N;
    double T;
public:
    FourierovRed(double T, std::initializer_list<double> lista1, std::initializer_list<double> lista2) : T(T){
        //for(auto i : lista1) std::cout << i << " ";
        if(lista1.size()<=lista2.size()) FourierovRed::N = lista2.size() + 1;
        else FourierovRed::N = lista1.size();
        int brojac(0);
        if(N <= 0) std::domain_error("Stepen mora biti pozitivan");
        a.resize(N);
        b.resize(N);
        for(auto i : lista1){ a[brojac] = i; brojac++; }
        brojac = 1;
        for(auto i : lista2){ b[brojac] = i; brojac++; }
    }
    template <typename prvi,typename drugi>
    FourierovRed(int N, double T, prvi funkcija1, drugi funkcija2){
        if(N <= 0) throw std::domain_error("Stepen mora biti pozitivan");
        FourierovRed::N = N;
        FourierovRed::T = T;
        a.resize(N);
        b.resize(N);
        for(int i = 0; i < N; i++){
            a[i] = funkcija1(i);
            if(i != 0) b[i] = funkcija2(i);
        }
    }
    template <typename prvi>
    FourierovRed(int N, double p, double q, prvi funkcija1, int M){
        if(N <= 0) throw std::domain_error("Stepen mora biti pozitivan");
        if(M <= 0) throw std::domain_error("Broj podintervala mora biti pozitivan");
        if(p >= q) throw std::range_error("Neispravan interval");
        FourierovRed::T = q-p;
        FourierovRed::N = N;
        a.resize(N);
        b.resize(N);
        for(int i = 0; i < N; i++){
            double pomocna1(0);
            for(int j = 1; j <= M - 1; j++){
                pomocna1 += funkcija1(p + double(j) * T / M) * cos(2 * double(i) * pi * (p / T + double(j) / M));
            }
            a[i] = (funkcija1(p) + funkcija1(q)) / M * cos(2 * double(i) * pi * p / T) + 2. / M * pomocna1;
            pomocna1 = 0;
            for(int j = 1; j <= M - 1; j++){
                pomocna1 += funkcija1(p + double(j) * T / M) * sin(2 * double(i) * pi * (p / T + double(j) / M));
            }
            b[i] = (funkcija1(p) + funkcija1(q)) / M * sin(2 * double(i) * pi * p / T) + 2. / M * pomocna1;
            pomocna1 = 0;
        }
    }
    
    FourierovRed(const FourierovRed& staro){
        (*this).N = staro.N;
        (*this).T = staro.T;
        (*this).a = staro.a;
        (*this).b = staro.a;
        for(int i = 0; i < N; i++){
            (*this).a[i] = (staro.a[i]);
            (*this).b[i] = (staro.b[i]);
        }
    }
    FourierovRed(FourierovRed&& staro){
        (*this).N = staro.N;
        (*this).T = staro.T;
        (*this).a = staro.a;
        (*this).b = staro.b;
        for(int i = 0; i < N; i++){
            (*this).a[i] = staro.a[i];
            (*this).b[i] = staro.b[i];
        }
    }
    FourierovRed &operator =(const FourierovRed& staro){
        (*this).N = staro.N;
        (*this).T = staro.T;
        (*this).a = staro.a;
        (*this).b = staro.b;
        for(int i = 0; i < N; i++){
            (*this).a[i] = staro.a[i];
            (*this).b[i] = staro.b[i];
        }
        return *this;
    }
    FourierovRed &operator =(FourierovRed &&staro){
        std::swap((*this).a, staro.a); std::swap((*this).b, staro.b);
        return *this;
    }
    
    double operator ()(double x){
        double vrijednost = (*this).a[0] / 2.;
        double pomocna(0);
        for(int i = 1; i < (*this).N; i++){
            pomocna += a[i] * cos(2 * double(i) * pi * x / (*this).T) + b[i] * sin(2 * double(i) * pi * x / (*this).T);
        }
        return (vrijednost + pomocna);
    }
    std::pair<double, double> operator [](int k){
        if(k < 0 || k + 1> (*this).N) throw std::range_error("Neispravan indeks");
        if(k == 0){ std::shared_ptr<std::pair<double, double>> par; par = std::make_shared<std::pair<double, double>>(std::make_pair((*this).a[k], 0.)); return *par; } 
        std::shared_ptr<std::pair<double, double>> par; par = std::make_shared<std::pair<double, double>>(std::make_pair((*this).a[k], (*this).b[k])); return *par;
    }
};

int main ()
{
    double L = 2;
    FourierovRed f3(2*L, {2*L}, {-1.27324, 0.63662, -0.42441, 0.31831, -0.25465, 0.21221, -0.18189, 0.15915, -0.14147, 0.12732});
    //FourierovRed novi(3, {34,2,1,5}, {2,1,2,3,4,5});
    //std::cout << novi(9990);
    auto k1=[](int k) { return (k == 0) ? 8 * pi * pi / 3 : 4. / (k * k); };
    auto k2=[](int k) { return -4 * pi / k; };
    auto f=[](double x) { return x * x; };
    FourierovRed f1(50, 2*pi, k1, k2);
    FourierovRed f2(50, 0, 2*pi, f, 1000);
    std::cout << f1(3) << " " << f2(3);
    for(int i = 0; i <= 10; i++){
        std::cout << f1[i].first << " " << f1[i].second << std::endl;
    }

	return 0;
}