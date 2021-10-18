/B2017/2018: Zadaća 3, Zadatak 1
#include <iostream>
#include <algorithm>
#include <functional>
#include <vector>
#include <utility>
#include <stdexcept>
#include <cmath>

typedef std::pair<double, double> DblPair;
typedef std::function<double(double)> Dbl2Dbl;

// PROTOTIPI
// Pomocne funkcije
bool cmpFirst(const DblPair&, const DblPair&);

Dbl2Dbl LinearnaInterpolacija(std::vector<DblPair>);
Dbl2Dbl LinearnaInterpolacija(Dbl2Dbl, double, double, double);

int main ()
{
    int option;
    std::cout << "Odaberite opciju (1 - unos cvorova, 2 - aproksimacija): ";
    std::cin >> option;
    
    if (option == 1)
    {
        int numNodes;
        std::cout << "Unesite broj cvorova: ";
        std::cin >> numNodes;
        
        std::vector<DblPair> fnValues(numNodes);
        std::cout << "Unesite cvorove kao parove x y: ";
        for (auto &vlPair : fnValues)
            std::cin >> vlPair.first >> vlPair.second;
        
        Dbl2Dbl interpolated;
        try {
            interpolated = LinearnaInterpolacija(fnValues);
        }
        catch (const std::exception &ex) {
            std::cout << ex.what() << std::endl;
            return 0;
        }
        
        for (;;)
        {
            double input;
            std::cout << "Unesite argument (ili \"kraj\" za kraj): ";
            std::cin >> input;
            
            if (!std::cin || (std::cin.peek() != '\n' && std::cin.peek() != EOF))
                break;
            
            try {
                double res = interpolated(input);
                std::cout << "f(" << input << ") = " << res << std::endl;
            }
            catch (const std::exception &ex) {
                std::cout << ex.what() << std::endl;
            }
        }
    }
    else if (option == 2)
    {
        double xMin, xMax, dx;
        std::cout << "Unesite krajeve intervala i korak: ";
        std::cin >> xMin >> xMax >> dx;
        
        auto f = [](double x) {
            return x * x + std::sin(x);
        };
        
        Dbl2Dbl interpolated;
        try {
            interpolated = LinearnaInterpolacija(f, xMin, xMax, dx);
        }
        catch (const std::exception &ex) {
            std::cout << ex.what() << std::endl;
            return 0;
        }
        
        for (;;)
        {
            double input;
            std::cout << "Unesite argument (ili \"kraj\" za kraj): ";
            std::cin >> input;
            
            if (!std::cin || (std::cin.peek() != '\n' && std::cin.peek() != EOF))
                break;
            
            try {
                double res = interpolated(input);
                std::cout << "f(" << input << ") = " << f(input) << " ";
                std::cout << "fapprox(" << input << ") = " << res << std::endl;
            }
            catch (const std::exception &ex) {
                std::cout << ex.what() << std::endl;
            }
        }
    }
    else
        std::cout << "Neispravna opcija!" << std::endl;
    
	return 0;
}

Dbl2Dbl LinearnaInterpolacija(std::vector<DblPair> fnValues)
{
    std::sort(fnValues.begin(), fnValues.end(), cmpFirst);
    
    for (int i = 0; i < fnValues.size() - 1; i++)
        if (std::fabs(fnValues.at(i).first - fnValues.at(i + 1).first) < 1e-6)
            throw std::domain_error("Neispravni cvorovi");
        
    return [fnValues](double x) {
        if (fnValues.size() == 0 || x < fnValues.begin()->first || x > fnValues.rbegin()->first)
            throw std::range_error("Argument izvan opsega");
            
        if (fnValues.size() == 1 || std::fabs(x - fnValues.begin()->first) < 1e-6)
            return fnValues.begin()->second;
        
        auto p_iIter(std::lower_bound(fnValues.begin(), fnValues.end(), DblPair(x, 0), cmpFirst));
        auto p_ipls1 = *p_iIter, p_i = *(p_iIter - 1);
        
        return p_i.second + (p_ipls1.second - p_i.second) / (p_ipls1.first - p_i.first) * (x - p_i.first);
    };
}

Dbl2Dbl LinearnaInterpolacija(Dbl2Dbl f, double xMin, double xMax, double dx)
{
    if (xMin > xMax || dx <= 0)
        throw std::domain_error("Nekorektni parametri");
        
    std::vector<DblPair> fnValues;
    for (double x = xMin; x <= xMax; x += dx)
        fnValues.push_back(DblPair(x, f(x)));
        
    return LinearnaInterpolacija(fnValues);
}

bool cmpFirst(const DblPair &p1, const DblPair &p2)
{
    return p1.first < p2.first;
}
