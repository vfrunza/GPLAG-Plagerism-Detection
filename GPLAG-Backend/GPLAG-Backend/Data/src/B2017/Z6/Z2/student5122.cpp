/B2018/2019: Zadaća 3, Zadatak 1
#include <iostream>
#include <vector>
#include <utility>
#include <functional>
#include <stdexcept>
#include <cmath>

double f(double x)
{
    return x * x + sin(x);
}

double Max(double broj1, double broj2)
{
    if(broj1 < broj2) return broj2;
    return broj1;
}

double Min(double broj1, double broj2)
{
    if(broj1 > broj2) return broj2;
    return broj1;
}

double TezinskiKoeficijent(int i, int d, const std::vector<std::pair<double, double>> &cvorovi)
{
    double w(0);
    for(int k(Max(1, i - d)); k <= Min(i, cvorovi.size() - d); k++) {
        double p(pow(-1, k - 1));
        for(int j(k); j <= k + d; j++) {
            if(j != i) {
                p *=  1/(cvorovi.at(i - 1).first - cvorovi.at(j - 1).first);
            }
        }
        w += p;
    }
    return w;
}


std::function<double (double)> BaricentricnaInterpolacija(const std::vector<std::pair<double, double>> &cvorovi, int d)
{
    if(d < 0 || d >= cvorovi.size()) throw std::domain_error("Nedozvoljen red");
    for(int i(0); i < cvorovi.size(); i++)
        for(int j(i + 1); j < cvorovi.size(); j++)
            if(cvorovi.at(i).first == cvorovi.at(j).first) throw std::domain_error("Neispravni cvorovi");
    std::vector<double> w;
    for(int i(1); i <= cvorovi.size(); i++)
        w.push_back(TezinskiKoeficijent(i, d, cvorovi));

    return [=](double x) {
        double suma1(0), suma2(0);
        for(int i(1); i <= cvorovi.size(); i++) {
            if(x == cvorovi.at(i - 1).first) return cvorovi.at(i - 1).second;
            suma1 += w.at(i - 1)/(x - cvorovi.at(i - 1).first) * cvorovi.at(i - 1).second;
            suma2 += w.at(i - 1)/(x - cvorovi.at(i - 1).first);
        }
        return suma1/suma2;
    };
}

std::function<double(double)> BaricentricnaInterpolacija(std::function<double(double)> f, double xmin, double xmax, double dx, int d)
{
    if(xmin > xmax || dx <= 0) throw std::domain_error("Nekorektni parametri");
    std::vector<std::pair<double, double>> cvorovi;
    for(double i(xmin); i <= xmax; i += dx) cvorovi.push_back(std::make_pair(i, f(i)));
    return BaricentricnaInterpolacija(cvorovi, d);
}


int main ()
{
    std::cout << "Odaberite opciju (1 - unos cvorova, 2 - aproksimacija): ";
    int opcija, n;
    double xmin, xmax, dx;
    std::cin >> opcija;
    std::vector<std::pair<double, double>> cvorovi;
    if(opcija == 1) {
        std::cout << "Unesite broj cvorova: ";
        std::cin >> n;
        std::cout << "Unesite cvorove kao parove x y: ";
        cvorovi.resize(n);
        for(int i(0); i < cvorovi.size(); i++) {
            std::cin >> cvorovi.at(i).first >> cvorovi.at(i).second;
        }
    } else if(opcija == 2) {
        std::cout << "Unesite krajeve intervala i korak: ";
        std::cin >> xmin >> xmax >> dx;
    }

    std::cout << "Unesite red interpolacije: ";
    int d;
    std::cin >> d;
    std::function<double(double)> inteprolacija;
    if(opcija == 1) inteprolacija = BaricentricnaInterpolacija(cvorovi, d);
    else if(opcija == 2) inteprolacija = BaricentricnaInterpolacija(f, xmin, xmax, dx, d);
    while(true) {
        std::cout << "Unesite argument (ili \"kraj\" za kraj): ";
        double x;
        std::cin >> x;
        if(!std::cin) break;
        std::cout << "f(" << x << ") = ";
        if(opcija == 1) std::cout << inteprolacija(x) << std::endl;
        else if(opcija == 2) std::cout << f(x) << " fapprox(" << x << ") = " << inteprolacija(x) << std::endl;
    }

    return 0;
}
