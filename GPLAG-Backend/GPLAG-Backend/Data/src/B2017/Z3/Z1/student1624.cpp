/B2017/2018: Zadaća 3, Zadatak 1
#include <iostream>
#include <vector>
#include <utility>
#include <functional>
#include <algorithm>
#include <cmath>
#include <iterator>
#include <string>

bool JesuLiJednaki(double x, double y, double Eps = 1e-10)
{
    return std::fabs(x - y) <= Eps * (std::fabs(x) + std::fabs(y));
}

double Funckija(double x)
{
    return x*x + std::sin(x);
}

std::vector<std::pair<double, double>>UnosCvorova()
{
    std::vector<std::pair<double, double>> v;
    int n;
    std::cout << "Unesite broj cvorova: ";
    std::cin >> n;
    std::cin.ignore(10000, '\n');

    std::cout << "Unesite cvorove kao parove x y: ";

    for(int i=1; i<=n; i++) {
        int x, y;
        std::cin >> x >> y;
        std::cin.ignore(10000, '\n');

        v.push_back(std::pair<double, double>(x,y));
    }
    return v;
}

std::function<double (double)>LinearnaInterpolacija(std::vector<std::pair<double, double>> v)
{
    std::sort(v.begin(), v.end(), [](std::pair<double, double> a, std::pair<double, double> b) {
        return a.first<b.first;
    });

    if(!(adjacent_find(v.begin(), v.end(),[](std::pair<double, double> a, std::pair<double, double> b) {
    return JesuLiJednaki(a.first, b.first);
    }) == v.end())) throw std::domain_error("Neispravni cvorovi");

    return [v](double x) {
        auto n = std::find_if(v.begin(), v.end(), [x](std::pair<double, double> a) {
            return a.first>=x;
        });

        if(x<v[0].first || n==v.end())
            throw std::range_error("Argument izvan opsega");
        if(JesuLiJednaki(n->first,x))
            return n->second;

        n--;

        double x1 = n->first;
        double x2 = (n+1)->first;

        double y1 = n->second;
        double y2 = (n+1)->second;

        return y1 + ((y2 - y1)/(x2 - x1))*(x - x1);
    };
}

std::function<double (double)> LinearnaInterpolacija(std::function<double (double)> f, double xmin, double xmax, double dx)
{
    std::vector<std::pair<double, double>> v;
    double k = 0;
    double n = 0;

    while(n<xmax) {
        n = xmin+k*dx;
        k++;
        v.push_back(std::pair<double, double>(n, f(n)));
    }
    return LinearnaInterpolacija(v);
}

int main ()
{
    int n;
    std::cout << "Odaberite opciju (1 - unos cvorova, 2 - aproksimacija): ";
    std::cin >> n;
    std::cin.ignore(10000, '\n');
    bool select = n==1;

    std::function<double (double)> f;

    if(select) {
        auto v = UnosCvorova();
        try {
            f=LinearnaInterpolacija(v);
        } catch(std::domain_error izuzetak) {
            std::cout << izuzetak.what();
            return 0;
        } catch(std::range_error izuzetak) {
            std::cout << izuzetak.what();
        }
    } else {
        std::cout << "Unesite krajeve intervala i korak: ";
        double a, b, c;

        std::cin >> a >> b >> c;
        std::cin.ignore(10000, '\n');
        try {
            f=LinearnaInterpolacija(Funckija, a, b, c);
        } catch(std::domain_error izuzetak) {
            std::cout << izuzetak.what();
        } catch(std::range_error izuzetak) {
            std::cout << izuzetak.what();
        }

    }

    while(true) {
        std::cout << "Unesite argument (ili \"kraj\" za kraj): ";

        std::string s;
        std::getline(std::cin, s);

        if(s != "kraj") {
            double n = std::stod(s);
            try {
                if(select) {
                    std::cout << "f(" << n << ") = " << f(n);
                } else {
                    std::cout << "f(" << n << ") = " << Funckija(n) << " fapprox(" << n << ") = " << f(n);
                }
                std::cout << std::endl;
            } catch(std::domain_error izuzetak) {
                std::cout << izuzetak.what() << std::endl;
            } catch(std::range_error izuzetak) {
                std::cout << izuzetak.what() << std::endl;
            }
        } else break;
    }

    return 0;
}