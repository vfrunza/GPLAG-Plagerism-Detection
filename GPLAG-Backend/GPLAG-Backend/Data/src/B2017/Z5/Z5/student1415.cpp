/B2017/2018: Zadaća 5, Zadatak 4
#include <iostream>
#include <stdexcept>
#include<initializer_list>
#include <algorithm>
#include <iterator>
#include <functional>
#include <cmath>
#include <utility>
#include <tuple>
#include <vector>

static constexpr double PI = 3.141592653589793;

class FourierovRed
{

    double T;
    int N;
    std::vector<double> koeficijenti_a, koeficijenti_b;
    double ignorisi = 0;                                            // pomocna varijabla koja 'kupi' b koeficijent pri red[0] = std::make_pair...


public:
    FourierovRed(double T, std::initializer_list<double> lista_a, std::initializer_list<double> lista_b);
    FourierovRed(int N, double T, std::function<double(int)> f_1, std::function<double(int)> f_2 );
    FourierovRed(int N, double p, double q, std::function<double(double)> f, int M);
    FourierovRed(const FourierovRed &red)= default;
    FourierovRed &operator =(const FourierovRed &red) = default;
    FourierovRed(FourierovRed &&red) = default;
    FourierovRed &operator =(FourierovRed &&red) = default;

    double operator() (double x) const;
    std::pair<double, double> operator [](int x) const;
    std::pair<double &, double &> operator [](int x);

};

FourierovRed::FourierovRed(double T, std::initializer_list<double> lista_a,
                           std::initializer_list<double> lista_b) : T(T)
{

    int velicina(0);
    N = 0;
    for(auto it = lista_a.begin(); it != lista_a.end(); it++) N++;
    for(auto it = lista_b.begin(); it != lista_b.end(); it++) velicina++;

    velicina++;

    if(N < velicina) N = velicina;


    koeficijenti_a.resize(N);

    koeficijenti_b.resize(N);

    std::fill(koeficijenti_a.begin(), koeficijenti_a.end(), 0);
    std::fill(koeficijenti_b.begin(), koeficijenti_b.end(), 0);

    std::copy(lista_a.begin(), lista_a.end(), koeficijenti_a.begin());
    std::copy(lista_b.begin(), lista_b.end(), koeficijenti_b.begin() + 1);

}

FourierovRed::FourierovRed(int N, double T, std::function<double(int)> f_1, std::function <double(int)> f_2 )
{
    if(N <= 0) throw std::domain_error("Stepen mora biti pozitivan");
    FourierovRed::N = N;
    FourierovRed::T = T;

    for(int i = 0; i <= N; i++) {
        koeficijenti_a.emplace_back(i);
        koeficijenti_b.emplace_back(i);
    }

    std::transform(koeficijenti_a.begin(), koeficijenti_a.end(), koeficijenti_a.begin(), f_1);
    std::transform(koeficijenti_b.begin() + 1, koeficijenti_b.end(), koeficijenti_b.begin() + 1, f_2);
}

FourierovRed::FourierovRed(int N, double p, double q, std::function<double(double)> f, int M)
{

    if(N <= 0) throw std::domain_error("Stepen mora biti pozitivan");
    if(M <= 0) throw std::domain_error("Broj podintervala mora biti pozitivan");
    if(!(p < q)) throw std::range_error("Neispravan interval");

    T = q - p;
    FourierovRed::N = N;

    koeficijenti_a.resize(N + 1);
    koeficijenti_b.resize(N + 1);


    for(int i = 0; i <= N; i++) {
        koeficijenti_a[i] = i;
        koeficijenti_b[i] = i;
    }

    std::transform(koeficijenti_a.begin(), koeficijenti_a.end(), koeficijenti_a.begin(), [=](int k) {
        double red(0);
        for(int i = 0; i < M; i++)
            red += (f(p + i*T/M) * std::cos(2 * k * PI * (p/T + (double)i/M)));
        return ((red * 2. /M) + (((f(p) + f(q))/M )* std::cos((2 * k * PI * p )/ T)));
    });

    std::transform(koeficijenti_b.begin() + 1, koeficijenti_b.end(), koeficijenti_b.begin() + 1, [=](int k) {
        double red(0);
        for(int i = 0; i < M ; i++)
            red += (f(p + i*T/M) * std::sin(2* k *PI*(p/T + (double)i/M)));
        return ((red * 2. / M) + ((f(p) + f(q))/M ) * std::sin((2 * k * PI * p )/ T));
    });
}
double FourierovRed::operator() (double x) const
{

    double red(0);
    for(int i = 1; i <= N ; i++)
        red += (koeficijenti_a[i] * std::cos((2 * i * PI * x )/ T) + koeficijenti_b[i] * std::sin((2 * i * PI * x) /T));

    return koeficijenti_a[0]/2. + red;

}
std::pair<double, double> FourierovRed::operator [](int x) const
{
    if(x < 0 || x >= N) throw std::range_error("Neispravan indeks");
    if(x == 0) return std::make_pair(koeficijenti_a.at(0), 0);
    return std::make_pair(koeficijenti_a[x], koeficijenti_b[x]);
}
std::pair<double &, double &> FourierovRed::operator [](int x)
{
    if(x < 0 || x >= N) throw std::range_error("Neispravan indeks");


    if(x == 0) {
        auto novi = std::tie (koeficijenti_a[x], ignorisi);
        std::pair <double &, double& > povratni(std::get<0> (novi),std::get<1> (novi));
        return povratni;
    }
    auto novi = std::tie (koeficijenti_a[x], koeficijenti_b[x]);
    std::pair <double &, double &> povratni(std::get<0> (novi),std::get<1> (novi));
    return povratni;
}

int main ()
{
    FourierovRed aproksimacija(50, 0, 2 * PI, [](double x) {
        return x * x;
    }, 1000);

    FourierovRed tacni (50, 2 * PI, [] (int k) {
        return k == 0 ? 8 * PI * PI/ 3 : 4. / (k * k);
    }, [] (int k) {
        return -4 * PI/ k;
    });
    std::cout << "x * x za x = 2: " << std::endl;
    std::cout << aproksimacija(2) << std::endl;
    std::cout << tacni(2) << std::endl;


    return 0;
}
