/B2016/2017: Zadaća 3, Zadatak 1
//Autotestovi by Enil Pajic (epajic1@etf.unsa.ba)

#include <iostream>
#include <vector>
#include <utility>
#include <stdexcept>
#include <functional>
#include <cmath>

int min(int n1, int n2)
{
   /* int minim(n1);
    for(int i = n1; i <= n2; i++)
    {
        if(i < minim)
           minim = i;
    }
    return minim;*/
    if(n1 < n2)
       return n1;
    else
       return n2;
}
int max(int n1, int n2)
{
    /*int maxim(n1);
    for(int i = n1; i <= n2; i++)
    {
        if(i > maxim)
           maxim = i;
    }
    return maxim;*/
    if(n1 > n2)
       return n1;
    else 
       return n2;
}

std::function<double(double)> BaricentricnaInterpolacija(std::vector<std::pair<double,double>> cvorovi,int d)
{
    if(d < 0 || d >= cvorovi.size())
       throw std::domain_error("Nedozvoljen red");
    
    for(int i = 0; i < cvorovi.size()-1; i++)
        for(int j = i+1; j < cvorovi.size(); j++)
           //if(fabs(cvorovi.at(i).first - cvorovi.at(j).first) > 0.0000001)
           if(cvorovi[i].first == cvorovi[j].first)
              throw std::domain_error("Neispravni cvorovi");
    
    std::vector<double> wi(cvorovi.size());
    
    /*for(int i = 1; i <= cvorovi.size(); i++)
    {
       double formula;
       for(int k = max(1, i - d); k <= min(i, cvorovi.size() - d); k++)
       {
           formula = pow(-1, k-1); 
           double proizvod(1);
           for(int j = k; j < k + d; j++)
           {
               proizvod *= 1/(cvorovi.at(i-1).first - cvorovi.at(j-1).first);
               formula *= proizvod;  
           }
       }
       wi.at(i-1) += formula;
    }*/
    for(int i = 1; i <= cvorovi.size(); i++)
    {
        double p;
        for(int k = max(1, i - d); k <= min(i, cvorovi.size() - d); k++)
        {
            p = 1.0;
            for(int j = k; j <= k + d; j++)
            {
                if(j != i)
                   p *= p/(cvorovi.at(i - 1).first - cvorovi.at(j - 1).first);
            }
        }
        wi.at(i - 1) += p;
    }
    int n = cvorovi.size();
    return [cvorovi, &wi](double x){
        double suma1(0),suma2(0);
        for(int i = 1; i <= cvorovi.size(); i++)
        {
            if(fabs(x - cvorovi.at(i-1).first) > 0.000001)
              return cvorovi.at(i-1).second;
            suma1 += (wi.at(i-1) * cvorovi.at(i-1).second)/(x - cvorovi.at(i-1).first);
            suma2 += (wi.at(i-1))/(x - cvorovi.at(i-1).first);

        }
        return double(suma1/suma2);

    };
}

std::function<double(double)> BaricentricnaInterpolacija(std::function<double(double)> fun, double x_min, double x_max, double delta_x, int d)
{
    if(x_min > x_max || delta_x <= 0)
       throw std::domain_error("Nekorektni parametri");
    std::vector<std::pair<double,double>> cvorovi;
    for(double i = x_min; i < x_max; i += delta_x)
    {
    
        cvorovi.push_back(std::make_pair(i,fun(i)));
    }
/*
    return [cvorovi, &d](double x){
        return BaricentricnaInterpolacija(cvorovi, d)(x);
   };*/
   
       return BaricentricnaInterpolacija(cvorovi, d);
}
double f(double x)
{
    double vrijednost;
    vrijednost = x*x + std::sin(x);
    return vrijednost;
}

#include <iostream>
int main ()
{
    std::cout << "Odaberite opciju (1 - unos cvorova, 2 - aproksimacija): ";
    int opcija;
    std::cin >> opcija;
    if(opcija == 1)
    {
        int broj_cvorova;
        std::cout << "Unesite broj cvorova: ";
        std::cin >> broj_cvorova;
        std::cout << "Unesite cvorove kao parove x y: ";
        std::vector<std::pair<double,double>> cvorovi(broj_cvorova);
        
        for(int i = 0; i < broj_cvorova; i++)
        {
            double x,y;
            std::cin >> x >> y;
            cvorovi.at(i) = std::make_pair(x, y);
        }
        
        int red_int;
        std::cout << "Unesite red interpolacije: ";
        std::cin >> red_int;
        
        try
        {
                auto f = BaricentricnaInterpolacija(cvorovi, red_int);
                for(;;)
                {
                    double arg;
                    std::string s("kraj");
                    std::cout << "\nUnesite argument (ili " << s << " za kraj): ";
                    std::cin >> arg;
                    if(!std::cin)
                        break;
                    std::cout << "f(" << arg << ") = " <<f(arg);
            
                }
        }
        catch(std::domain_error iz)
        {
            std::cout << iz.what() << std::endl;
            return 0;
        }
        
    }
    else if(opcija == 2)
    {
        std::cout << "Unesite krajeve intervala i korak: ";
        int x_max, x_min;
        double delta;
        std::cin >> x_min >> x_max >> delta;
        int d;
        std::cout << "Unesite red interpolacije: ";
        std::cin >> d;
        
        for(;;)
        {
            
            try
            {
                double arg;
                std::string s("kraj");
                std::cout << "Unesite argument (ili " << s << " za kraj): ";
                std::cin >> arg;
                if(!std::cin)
                   break;
   
                std::cout << "f(" << arg << ") = " <<f(arg);
                auto fun = BaricentricnaInterpolacija(f, x_min, x_max, delta, d);
                std::cout << " fapprox(" << arg << ") = " << fun(arg) << std::endl;
            }
            catch(std::domain_error iz)
            {
                std::cout << iz.what() << std::endl;
                return 0;
            }
            
        }
    }
	return 0;
}