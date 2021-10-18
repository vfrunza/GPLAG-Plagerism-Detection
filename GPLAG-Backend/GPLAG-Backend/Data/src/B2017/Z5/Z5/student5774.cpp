#include <iostream>
#include <initializer_list>
#include <cmath>
#include <functional>
#include <stdexcept>
#include <utility>
#include <algorithm>
#include <vector>
using std::vector;

double _PI_(std::atan(1) * 4);

class FourierovRed
{
    vector<double> a, b;
    double T;
    int n;
    double Ak(int k, std::function<double(double)> f, double p, double q, int M);
    double Bk(int k, std::function<double(double)> f, double p, double q, int M);
public:
    FourierovRed(double T, std::initializer_list<double> a, std::initializer_list<double> b);
    FourierovRed(int N, double T, std::function<double(int)> f, std::function<double(int)> g);
    FourierovRed(int N, double p, double q, std::function<double(double)> f, int M);
    ~FourierovRed() = default;
    FourierovRed(const FourierovRed &f);
    FourierovRed(FourierovRed &&f) { std::swap(a, f.a); std::swap(b, f.b); T = f.T; n = f.n; }
    FourierovRed &operator =(FourierovRed f) { std::swap(a, f.a); std::swap(b, f.b); T = f.T; n = f.n; return *this; }
    double operator ()(double) const;
    std::pair<double&, double&> operator[](int);
    std::pair<double, double> operator[](int) const;
};

double FourierovRed::Ak(int k, std::function<double(double)> f, double p, double q, int M)
{
    double ak(0), T(q-p);
    for (int i(1); i < M; ++i)
        ak += f(p + i*T/M) * std::cos(2*k*_PI_*(p/T + double(i)/M));
    ak *= 2. / M;
    ak += (f(p) + f(q)) / M * std::cos(2 * k * _PI_*p / T);
    return ak;
}
double FourierovRed::Bk(int k, std::function<double(double)> f, double p, double q, int M)
{
    double bk(0);
    for (int i(1); i < M; ++i)
        bk += f(p + i*T/M) * std::sin(2*k*_PI_*(p/T + double(i)/M));
    bk *= 2. / M;
    bk += (f(p) + f(q)) / M * std::sin(2 * k * _PI_*p / T);
    return bk;
}

FourierovRed::FourierovRed(double T, std::initializer_list<double> _a, std::initializer_list<double> _b)
: T(T)
{
    n = std::max(int(_a.size()) - 1, int(_b.size()));
    a.resize(n+1); b.resize(n+1);
    int i(0);
    for (auto it(_a.begin()); it != _a.end(); ++it, ++i)
        a[i] = *it;
    i = 1;
    for (auto it(_b.begin()); it != _b.end(); ++it, ++i)
        b[i] = *it;
    //?Izuzetak za T<=0?
}
FourierovRed::FourierovRed(int N, double T, std::function<double(int)> f, std::function<double(int)> g)
: T(T)
{
    if (N <= 0) throw std::domain_error("Stepen mora biti pozitivan");
    n = N;
    a.resize(n+1); b.resize(n+1);
    for (int i(0); i <= n; ++i)
    {
        a[i] = f(i);
        if (i > 0) b[i] = g(i);
    }
}
FourierovRed::FourierovRed(int N, double p, double q, std::function<double(double)> f, int M)
{
    if (N <= 0) throw std::domain_error("Stepen mora biti pozitivan");
    if (M <= 0) throw std::domain_error("Broj podintervala mora biti pozitivan");
    if (q <= p) throw std::range_error("Neispravan interval");
    n = N;
    a.resize(n+1); b.resize(n+1);
    T = q - p;
    for (int i(0); i <= n; ++i)
    {
        a[i] = Ak(i, f, p, q, M);
        if (i > 0) b[i] = Bk(i, f, p, q, M);
    }
}
FourierovRed::FourierovRed(const FourierovRed &f)
{
    if (&f == this) return;
    auto _a(f.a), _b(f.b);
    a = std::move(_a); b = std::move(_b);
    n = f.n; T = f.T;
}

double FourierovRed::operator ()(double x) const
{
    double r(a[0] / 2);
    for (int k(1); k <= n; ++k)
        r += a[k] * std::cos(2*k*_PI_*x / T) + b[k] * std::sin(2*k*_PI_*x / T);
    return r;
}
std::pair<double&, double&> FourierovRed::operator[](int k)
{
    if (k < 0 || k > n) throw std::range_error("Neispravan indeks");
    b[0] = 0;
    return std::pair<double&, double&>(a[k], b[k]);
}
std::pair<double, double> FourierovRed::operator[](int k) const
{
    if (k < 0 || k > n) throw std::range_error("Neispravan indeks");
    return std::make_pair(a[k], k == 0 ? 0. : b[k]);
}

int main()
{
    double x;
    int M;
    FourierovRed f1(100, 2*_PI_, [](int i) { return i == 0 ? 8*_PI_*_PI_ / 3 : 4. / (i*i); }, [](int i) { return -4*_PI_ / i; });
    while ((std::cout << "x=", std::cin >> x) && (std::cout << "M=", std::cin >> M))
    {
        FourierovRed f2(100, 0, 2*_PI_, [](double x) { return x*x; }, M);
        std::cout << "delta=" << f2(x) - f1(x) << '\n';
    }
    std::cin.clear(); std::cin.ignore(10000, '\n');
    std::cout << "-----------------------------------";
    for (int i(1); i <= 101; i += 20)
    {
        FourierovRed f2(i, 0, 2*_PI_, [](double x) { return x*x; }, 2000);
        std::cout << "\nN=" << i << " delta=" << f2(3) - f1(3);
    }
	return 0;
}