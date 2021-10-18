/B2016/2017: Zadaća 3, Zadatak 1
//Autotestovi by Enil Pajic (epajic1@etf.unsa.ba)
#include <iostream>
#include <vector>
#include <cmath>
#include <functional>
#include <stdexcept>

int Maxi(int a, int b) {return (a > b) ? a : b;}

int Mini(int a, int b) {return (a > b) ? b : a;}

double Fx(double x){ return pow(x, 2) + sin(x);}

// 2 parametra
std::function<double(double)> BaricentricnaInterpolacija(const std::vector<std::pair<double, double>> &cvor, int d)
{
    if(d < 0 || d > cvor.size()) throw std::domain_error("Nedozvoljen red");
    
    for(int i(0); i < cvor.size(); i++)
    {
        for(int j(i + 1); j < cvor.size(); j++)
        {
            if(cvor[i].first == cvor[j].first)
              throw std::domain_error("Neispravni cvorovi");
        }
    }
    
    std::vector<double> W;

    for(int i(1); i <= cvor.size(); i++)
    {
        double suma(0);
        for(int j(Maxi(1, i - d)); j <= Mini(i, cvor.size() - d); j++)
        {
            double suma1(1);
            for(int k(j); k <= j + d; k++)
            {
                if(i - 1 == k - 1) continue;
                suma1 *= (1 / (cvor[i - 1].first - cvor[k - 1].first));
            }
            suma += pow(-1, j - 1) * suma1;
        }
        W.push_back(suma);
    }

    return [cvor, d, W](double x)
                    {
                        double suma_x(0), suma_y(0);
                        for(int i(0); i < cvor.size(); i++)
                        {
                            if(x == cvor[i].first) return cvor[i].second;
                            
                            suma_x += (W[i] / (x - cvor[i].first)) * cvor[i].second;
                            suma_y += (W[i] / (x - cvor[i].first));
                        }
                        return (suma_x / suma_y);
                    };
}

// 5 parametara
std::function<double(double)> BaricentricnaInterpolacija(double f (double), double x_min, double x_max, double x_d, int d)
{
    if(x_min > x_max || x_d <= 0) throw std::domain_error("Nekorektni parametri");
    
    std::vector<std::pair<double, double>> cvor;
    while(69 == 69)
    {
        if(x_min > x_max) break;
        cvor.push_back(std::make_pair(x_min, f(x_min)));
        x_min += x_d;
    }
    return BaricentricnaInterpolacija(cvor, d);
}


int main ()
{
    int opcija;
    std::cout << "Odaberite opciju (1 - unos cvorova, 2 - aproksimacija): ";
    std::cin >> opcija;
        
    if(opcija == 1)
    {
        int vel;
        std::cout << "Unesite broj cvorova: ";
        std::cin >> vel;
        
        std::vector<std::pair<double, double>> cvor(vel);
        std::cout << "Unesite cvorove kao parove x y: ";
        for(int i(0); i < vel; i++)
        {
            double x, y;
            std::cin >> x >> y;
            cvor[i] = std::make_pair(x, y);
        }
        int d;
        std::cout << "Unesite red interpolacije: ";
        std::cin >> d;
            
        try
        {
            auto f(BaricentricnaInterpolacija(cvor, d));
            while(69 == 69)
            {
                double arg;
                std::cout << "Unesite argument (ili \"kraj\" za kraj): ";
                std::cin >> arg;
                
                if(!std::cin || std::cin.peek() != '\n') 
                {
                    std::cout << std::endl;
                    std::cin.clear();
                    std::cin.ignore(10000, '\n');
                    break;
                }
                std::cout << "f(" << arg << ") = " << f(arg) << std::endl;
            }
        }
        catch(std::domain_error e)
        {
            std::cout << e.what();
            return 0;
        }
    }
    else if(opcija == 2)
    {
        double x_min, x_max, x_d;
        std::cout << "Unesite krajeve intervala i korak: ";
        std::cin >> x_min >> x_max >> x_d;
        int d;
        std::cout << "Unesite red interpolacije: ";
        std::cin >> d;
        try
        {
            auto f(BaricentricnaInterpolacija(Fx, x_min, x_max, x_d, d));
            while(69 == 69)
            {
                double arg;
                std::cout << "Unesite argument (ili \"kraj\" za kraj): ";
                std::cin >> arg;
            
                if(!std::cin || std::cin.peek() != '\n') 
                {
                   std::cout << std::endl;
                   break;
                }
                std::cout << "f(" << arg << ") = " << Fx(arg) << " " 
                          << "fapprox(" << arg << ") = " << f(arg) << std::endl;
            }    
        }
        catch(std::domain_error e)
        {
            std::cout << e.what();
        }
        
    }
	return 0;
}