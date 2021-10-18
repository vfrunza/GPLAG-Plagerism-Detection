/B2016/2017: Zadaća 3, Zadatak 1
//Autotestovi by Enil Pajic (epajic1@etf.unsa.ba)
#include <iostream>
#include <vector>
#include <utility>
#include <functional>
#include <stdexcept>


std::function<double(double)> BaricentricnaInterpolacija(std::vector<std::pair<double,double>> v, int d)
{
    if(d<=0 && d>=v.size()) throw std::domain_error ("Nedozvoljen red");
    return 0;
    
}
int main ()
{
    
    try
    {
        auto f(BaricentricnaInterpolacija({{1, 3}, {2, 5}, {4, 4}, {5, 2}, {7, 1}}, -2));
    }
    catch(std::domain_error e)
    {
        std::cout<<e.what();
    }
return 0;
}