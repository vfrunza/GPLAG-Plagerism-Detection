#include <iostream>
#include <stdexcept>
#include <utility>
#include <cmath>
#include <functional>
#include <initializer_list>


typedef std::initializer_list<double> Lista;
typedef std::function<double(double)> Fun;

class FourierovRed {
    int N;
    double T;
    double *ai, *bi;
    const double PI = 4*atan(1);
public:
    FourierovRed(double T, Lista l1, Lista l2);
    FourierovRed(int N, double T, Fun f1, Fun f2);
    FourierovRed(int N, double p, double q, Fun f, int M);
    FourierovRed(const FourierovRed &red);
    FourierovRed(FourierovRed &&red);
    FourierovRed &operator = (const FourierovRed &red);
    FourierovRed &operator = (FourierovRed &&red);
    ~FourierovRed() { delete [] ai; delete [] bi; }
    double operator () (double x) const;
    std::pair<double &, double &> operator [] (int k);
};

FourierovRed::FourierovRed(double T, Lista l1, Lista l2) : T(T) {
    N = l1.size() * (l1.size() >= l2.size()) + l2.size() * (l2.size() > l1.size()),
    ai = new double[N+1]{}; 
    try {
        bi = new double[N+1]{};
    }
    catch(...) {
        delete [] ai; throw;
    }
    auto it1(l1.begin()), it2(l2.begin());
    for (int i = 0; i <= N; i++) {
        if (it1 != l1.end()) ai[i] = *it1++;
    //    else ai[i] = 0;
        if (it2 != l2.end()) bi[i] = *it2++;
    //    else bi[i] = 0;
    }
}

FourierovRed::FourierovRed(int N, double T, Fun f1, Fun f2) : N(N), T(T) {
    if (N < 1) throw std::domain_error("Stepen mora biti pozitivan");
    ai = new double[N+1]{};
    try { bi = new double[N+1]{}; }
    catch(...) { delete [] ai; throw; }
    for (int i = 0; i <= N; i++) {
        ai[i] = f1(i); bi[i] = f2(i);
    }
}

FourierovRed::FourierovRed(int N, double p, double q, Fun f, int M) : N(N), T(q-p) {
    if (N < 1) throw std::domain_error("Stepen mora biti pozitivan");
    if (M < 1) throw std::domain_error("Broj podintervala mora biti pozitivan");
    if (!(p<q)) throw std::range_error("Neispravan interval");
    ai = new double[N+1]{};
    try { bi = new double[N+1]{}; }
    catch (...) { delete [] ai; throw; }
    for (int k = 0; k <= N; k++) {
        for (int i = 1; i <= M-1; i++) {
            ai[k] += f(p + i*T/M)*cos(2*k*PI*(p/T + i/M));
            bi[k] += f(p + i*T/M)*sin(2*k*PI*(p/T + i/M));
        }
        ai[k] = 2*ai[k]/M + (f(p) + f(q))*cos(2*k*PI*p/T)/M;
        bi[k] = 2*bi[k]/M + (f(p) + f(q))*sin(2*k*PI*p/T)/M;
    }
}

FourierovRed::FourierovRed(const FourierovRed &red) : N(red.N), T(red.T) {
    ai = new double[N]{};
    try { bi = new double[N]{}; }
    catch (...) { delete [] ai; throw; }
    for (int i = 0; i < N; i++) {
        ai[i] = red.ai[i]; bi[i] = red.bi[i];
    }
}

double FourierovRed::operator() (double x) const {
    double rez(ai[0]/2);
    for (int i = 0; i <= N; i++) 
        rez += ai[i]*cos(2*i*PI*x/T) + bi[i]*sin(2*i*PI*x/T);
    return rez;
}

std::pair<double &, double &> FourierovRed::operator [] (int k) {
    if (k < 0 || k > N) throw std::range_error("Neispravan indeks");
    if (k == 0) return {ai[0], bi[0] = 0};
    return {ai[k], bi[k]};
}



int main ()
{
    FourierovRed f(4, 4, [](int k) { if (k == 0) return 1.; return 1./k; }, [](int k) { return k-1; });
    auto x(f[2]);
    std::cout << x.first;
	return 0;
}
