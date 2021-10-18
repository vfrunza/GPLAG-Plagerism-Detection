/B2017/2018: Zadaća 5, Zadatak 5
#include <iostream>
#include <initializer_list>
#include <functional>
#include <stdexcept>
#include <cmath>
#include <vector>
#include <iomanip>

const double PI = std::atan(1) * 4;

using std::vector;

class FourierovRed { 
    int stepen_polinoma;
    double period;
    vector<double> koeficijenti_a;
    vector<double> koeficijenti_b;
    double b_0;
public:
    FourierovRed(double, std::initializer_list<double>, std::initializer_list<double>);
    FourierovRed(int, double, std::function<double(int)>, std::function<double(int)>);
    FourierovRed(int, double, double, std::function<double(double)>, int);
    double operator ()(double) const;
    std::pair<double&, double&> operator [](int);
    const std::pair<double, double> operator[](int) const;
};

FourierovRed::FourierovRed(double T, std::initializer_list<double> a, std::initializer_list<double> b) {
    this -> period = T;
    int stepen_a = a.size() - 1;
    int stepen_b = b.size();
    int veci = (stepen_a >= stepen_b) ? stepen_a : stepen_b;
    veci += 1;
    
    int i = 0;
    for(auto it = a.begin(); it != a.end(); it++, i++) {
        koeficijenti_a.push_back(*it);
    }
    for(int j = i; j < veci; j++) {
        koeficijenti_a.push_back(0);
    }
    i = 1;
    koeficijenti_b.push_back(0);
    for(auto it = b.begin(); it != b.end(); it++, i++) {
        koeficijenti_b.push_back(*it);
    }
    for(int j = i; j < veci; j++) {
        koeficijenti_b.push_back(0);
    }
    
    this -> stepen_polinoma = veci - 1;
}

FourierovRed::FourierovRed(int N, double T, std::function<double(int)> f1, std::function<double(int)> f2) {
    if(N < 1)
        throw std::domain_error("Stepen mora biti pozitivan");
    this -> stepen_polinoma = N;
    this -> period = T;
    
    for(int i = 0; i < stepen_polinoma + 1; i++)
        koeficijenti_a.push_back(f1(i));
        
    koeficijenti_b.push_back(0);
    for(int i = 1; i < stepen_polinoma + 1; i++)
        koeficijenti_b.push_back(f2(i));
}

FourierovRed::FourierovRed(int N, double p, double q, std::function<double(double)> f, int M) {
    if(N < 1)
        throw std::domain_error("Stepen mora biti pozitivan");
    if(M < 1)
        throw std::domain_error("Broj podintervala mora biti pozitivan");
    if(p >= q)
        throw std::range_error("Neispravan interval");
    this -> stepen_polinoma = N;
    this -> period = q - p;
    
    for(int k = 0; k < stepen_polinoma + 1; k++) {
        double izraz = ((f(p) + f(q)) / M) * std::cos((2 * k * p * PI) / period);
        double suma = 0;
        for(int i = 1; i < M; i++) {
            suma += (f(p + ((period * i) / M)) * std::cos(2 * k * PI * (p / period + i / double(M))));
        }
        izraz += (2 / double(M)) * suma;
        koeficijenti_a.push_back(izraz);
    }
    
    koeficijenti_b.push_back(0);
    for(int k = 1; k < stepen_polinoma + 1; k++) {
        double izraz = ((f(p) + f(q)) / M) * std::sin((2 * k * p * PI) / period);
        double suma = 0;
        for(int i = 1; i < M; i++) {
            suma += (f(p + ((period * i) / M)) * std::sin(2 * k * PI * (p / period + i / double(M))));
        }
        izraz += (2 / double(M)) * suma;
        koeficijenti_b.push_back(izraz);
    }
}

double FourierovRed::operator ()(double x) const {
    double suma = 0;
    for(int k = 1; k < stepen_polinoma + 1; k++) {
        suma += koeficijenti_a[k] * std::cos((2 * k * PI * x) / period);
        suma += koeficijenti_b[k] * std::sin((2 * k * PI * x) / period);
    }
    return koeficijenti_a[0] / 2. + suma;
}

std::pair<double&, double&> FourierovRed::operator [](int i) {
    if(i < 0 || i > stepen_polinoma)
        throw std::range_error("Neispravan indeks");
    double& a_k = koeficijenti_a[i];
    b_0 = 0;
    double& b_k = (i == 0) ? b_0 : koeficijenti_b[i];
    std::pair<double&, double&> k(a_k, b_k);
    return k;
}

const std::pair<double, double> FourierovRed::operator [](int i) const {
    if(i < 0 || i > stepen_polinoma)
        throw std::range_error("Neispravan indeks");
    return std::make_pair(koeficijenti_a[i], koeficijenti_b[i]);
}

int main() {
    int stepen = 50;
    double period = 2 * PI;
    int M = 1000;
    
    FourierovRed f1(stepen, period, [](int k) { return (k == 0) ? 8*PI*PI/3 : 4./(k*k); }, [](int k) { return -4*PI/k; });
    FourierovRed f2(stepen, 0, period, [](double x) { return x*x; }, M);
    
    std::cout << "Aprox. koeficijenti vs stvarni koeficijenti: \n";
    for(int i = 0; i <= stepen; i++) {
        std::cout << f1[i].first << ", " << f1[i].second << "         " << f2[i].first << ", " << f2[i].second << "\n";
    }
    
    int x = 3;
    std::cout << "Vrijednost u tacki: " << x << ": " << f1(x) << "; " << f2(x) << "\n\n";
    
    //Ostale metode
    auto k1 = [](int k) { return (k == 0) ? 4 : 0; };
    auto k2 = [](int k) { return (k % 2 == 0) ? 4/(k*PI) : -4/(k*PI); };
    FourierovRed f3(50, 4, k1, k2);
    FourierovRed f4(7, {7, 7}, {7});
    f4 = std::move(f3); 
    //f4 = std::move(f4); 
    FourierovRed f5(std::move(f4)); 
    std::cout << std::fixed << std::setprecision(4); 
    for(int i = 0; i < 5; i++) {
        std::cout << f5[i].first << ", " << f5[i].second << "\n";
    }
    return 0;
}

