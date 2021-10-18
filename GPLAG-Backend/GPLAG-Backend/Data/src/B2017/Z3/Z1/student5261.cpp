#include <iostream>
#include <vector>
#include <utility>
#include <functional>
#include <algorithm>
#include <stdexcept>
#include <cmath>
//Provjereno, poslano
std::function<double(double)> LinearnaInterpolacija(std::vector<std::pair<double, double>> v)
{
    for (int i(0); i < v.size(); ++i)
        for (int j(i+1); j < v.size(); ++j)
            if (v.at(i).first == v.at(j).first) throw std::domain_error("Neispravni cvorovi");
    std::sort(v.begin(), v.end());
    return [v](double x)
    {
        if (v.empty() || x < v.at(0).first || x > v.at(v.size()-1).first) throw std::range_error("Argument izvan opsega");
        auto it(std::upper_bound(v.begin(), v.end(), std::pair<double, double>(x, 0), [](const std::pair<double, double> &a, const std::pair<double, double> &b) { return a.first < b.first; }));
        if (it == v.end() || (it-1)->first == x) return (it-1)->second;
        return (it-1)->second + (it->second - (it-1)->second) / (it->first - (it-1)->first) * (x - (it-1)->first);
    };
}
std::function<double(double)> LinearnaInterpolacija(std::function<double(double)> f, double xmin, double xmax, double dx)
{
    if (xmin > xmax || dx <= 0) throw std::domain_error("Nekorektni parametri");
    std::vector<std::pair<double, double>> v((xmax - xmin) / dx + 1);
    for (int i(0); i < v.size(); ++i) v.at(i) = { xmin + i * dx, f(xmin + i * dx) };
    return [v](double x)
    {
        if (v.empty() || x < v.at(0).first || x > v.at(v.size()-1).first) throw std::range_error("Argument izvan opsega");
        auto it(std::upper_bound(v.begin(), v.end(), std::pair<double, double>(x, 0), [](const std::pair<double, double> &a, const std::pair<double, double> &b) { return a.first < b.first; }));
        if (it == v.end() || (it-1)->first == x) return (it-1)->second;
        return (it-1)->second + (it->second - (it-1)->second) / (it->first - (it-1)->first) * (x - (it-1)->first);
    };
}
int main()
{
    int n, o;
    double a, b, c;
    std::vector<std::pair<double, double>> v;
    std::cout << "Odaberite opciju (1 - unos cvorova, 2 - aproksimacija): ";
    std::cin >> o;
    if (o == 1)
    {
        std::cout << "Unesite broj cvorova: ";
        v.resize((std::cin >> n, n));
        std::cout << "Unesite cvorove kao parove x y: ";
        for (auto &p : v) std::cin >> p.first >> p.second;
    }
    else if (o == 2)
    {
        std::cout << "Unesite krajeve intervala i korak: ";
        std::cin >> a >> b >> c;
    }
    else return 0;
    try
    {
        auto f(o == 1 ? LinearnaInterpolacija(v) : LinearnaInterpolacija([](double x) { return x*x + std::sin(x); }, a, b, c));
        while (std::cout << "Unesite argument (ili \"kraj\" za kraj): ", std::cin >> a)
            try
            {
                if (o == 1) std::cout << "f(" << a << ") = " << f(a) << '\n';
                else std::cout << "f(" << a << ") = " << a*a + std::sin(a) << " fapprox(" << a << ") = " << f(a) << '\n';
            }
            catch (const std::range_error &e) { std::cout << e.what() << '\n'; }
    }
    catch (const std::exception &e) { std::cout << e.what(); }
	return 0;
}