/B2017/2018: Zadaća 5, Zadatak 4
#include <iostream>
#include <initializer_list>
#include <functional>
#include <stdexcept>
#include <cmath>
#include <utility>

using std::initializer_list;
using std::function;
using std::pair;

typedef function<double(int)> funkit;
typedef function<double(double)> funkd;

//Const
constexpr double pi = 4 * std::atan(1);

class FourierovRed{
    int stepen;
    double period;
    double *ak, *bk;
    
    double* Alloc(int n){
        return new double[n]{};
    }
    void DeAlloc(double* &tod){
        delete[] tod;
        tod = nullptr;
    }
    void IzracunajKoef(double *koefi, int n, double p, double q, funkd f, int M, double periodicna(double));
public:
    FourierovRed(double T, initializer_list<double> a, initializer_list<double> b);
    FourierovRed(int n, double T, funkit f1, funkit f2);
    FourierovRed(int N, double p, double q, funkd f, int M);
    ~FourierovRed();
    
    FourierovRed(const FourierovRed &fred);
    FourierovRed(FourierovRed &&fred);
    FourierovRed& operator =(const FourierovRed &fred);
    FourierovRed& operator =(FourierovRed &&fred);
    
    double operator ()(double x);
    pair<double&, double&> operator [](int k);
    pair<double, double> operator [](int k) const;
};

FourierovRed::FourierovRed(double T, initializer_list<double> a, initializer_list<double> b){
    //Ttreba ovo +1, jer vjrv u init_listi prvi clan nije nula
    int max_size = std::max(a.size(), b.size()+1);
    
    ak = Alloc(max_size);
    bk = Alloc(max_size);
    
    std::copy(a.begin(), a.end(), ak);
    //Da li je bk[0] == 0?
    std::copy(b.begin(), b.end(), bk+1);
    
    stepen = max_size-1;
    period = T;
}

FourierovRed::FourierovRed(int n, double T, funkit f1, funkit f2){
    if(n <= 0)
        throw std::domain_error("Stepen mora biti pozitivan");
    
    //Iako je nulti stepen, ima slobodni clan!
    ak = Alloc(n+1);
    bk = Alloc(n+1);
    
    stepen = n;
    period = T;
    
    for(int k = 0; k <= n; k++)
        ak[k] = f1(k);
    //Da li je bk[0] == 0?
    for(int k = 1; k <= n; k++)
        bk[k] = f2(k);
}

FourierovRed::FourierovRed(int n, double p, double q, funkd f, int M){
    if(n <= 0)
        throw std::domain_error("Stepen mora biti pozitivan");
    if(M <= 0)
        throw std::domain_error("Broj podintervala mora biti pozitivan");
    if(p >= q)
        throw std::range_error("Neispravan interval");
    
    ak = Alloc(n+1);
    bk = Alloc(n+1);
    
    stepen = n;
    period = q - p;
    
    IzracunajKoef(ak, n, p, q, f, M, std::cos);
    //Da li je bk[0] == 0?
    IzracunajKoef(bk, n, p, q, f, M, std::sin);
}

void FourierovRed::IzracunajKoef(double *koefi, int n, double p, double q, funkd f, int M, double periodicna(double)){
    double period = p - q;
    
    for(int k = 0; k <= n; k++){
        double sum = 0;
        
        for(int i = 1; i < M; i++){
            sum += f(p + (i*period)/M) * periodicna(2 * k * pi * (p/period + (i*1.)/M));
        }
        
        koefi[k] = ((f(p) + f(q)) / M) * periodicna((2 * k * pi * p)/period) + 2*sum/M;
    }
}

double FourierovRed::operator ()(double x){
    double fourier = ak[0]/2;
    
    for(int k = 1; k <= stepen; k++){
        fourier += ak[k] * std::cos((2*k*pi*x)/period) + bk[k] * std::sin((2*k*pi*x)/period);
    }
    
    return fourier;
}

pair<double&, double&> FourierovRed::operator [](int k){
    if(k < 0 || k > stepen)
        throw std::range_error("Neispravan indeks");
    
    return {ak[k], (k>0)? bk[k] : (bk[0] = 0)};
}

pair<double, double> FourierovRed::operator [](int k) const {
    if(k < 0 || k > stepen)
        throw std::range_error("Neispravan indeks");
    
    return std::make_pair(ak[k], (k>0)? bk[k] : 0);
}

FourierovRed::FourierovRed(const FourierovRed &fred) : stepen(fred.stepen), period(fred.period) {
    ak = Alloc(stepen+1);
    bk = Alloc(stepen+1);
    std::copy(fred.ak, fred.ak+stepen+1, ak);
    std::copy(fred.bk, fred.bk+stepen+1, bk);
}

FourierovRed::FourierovRed(FourierovRed &&fred) : stepen(fred.stepen), period(fred.period), ak(fred.ak), bk(fred.bk) {
    fred.ak = fred.bk = nullptr;
}

FourierovRed& FourierovRed::operator =(const FourierovRed &fred) {
    if(&fred == this) return *this;
    
    if(fred.stepen != stepen){
        DeAlloc(ak);
        DeAlloc(bk);
        ak = Alloc(fred.stepen+1);
        bk = Alloc(fred.stepen+1);
    }
    stepen = fred.stepen;
    period = fred.period;
    
    std::copy(fred.ak, fred.ak+stepen+1, ak);
    std::copy(fred.bk, fred.bk+stepen+1, bk);
    
    return *this;
}

FourierovRed& FourierovRed::operator =(FourierovRed &&fred) {
    if(&fred == this) return *this;
    
    DeAlloc(ak);
    DeAlloc(bk);
    ak = fred.ak;
    bk = fred.bk;
    period = fred.period;
    stepen = fred.stepen;
    fred.ak = fred.bk = nullptr;
    
    return *this;
}

FourierovRed::~FourierovRed(){
    DeAlloc(ak);
    DeAlloc(bk);
}

int main () {
    
    // int n = 50, m = 1000;
    // double p = 0, q = 2 * pi;
    
    // funkd f = [](double x){
    //     return x * x;
    // };
    // funkit a = [](int k){
    //     return (k == 0)? 8/3 * pi * pi : 4/(k*k);
    // };
    // funkit b = [](int k){
    //     return (k == 0)? 0 : -4 * pi / k;
    // };
    
    // FourierovRed fred(n, 2 * pi, a, b);
    // FourierovRed fred_aprox(n, p, q, f, m);
    
    auto k1=[](int k) { return (k == 0) ? 8 * pi * pi / 3 : 4. / (k * k); };
    auto k2=[](int k) { return -4 * pi / k; };
    auto f=[](double x) { return x * x; };
    FourierovRed f1(50, 2*pi, k1, k2);
    FourierovRed f2(50, 0, 2*pi, f, 1000);
    
    std::cout << "FourierovRed: " << f1(3) << std::endl;
    std::cout << "FourierovRed approx: " << f2(3) << std::endl;
    
	return 0;
}
