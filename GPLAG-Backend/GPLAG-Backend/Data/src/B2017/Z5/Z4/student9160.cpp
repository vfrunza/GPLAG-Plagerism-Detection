/B2017/2018: Zadaća 5, Zadatak 4
#include <iostream>
#include <functional>
#include <cmath>
#include <initializer_list>
const double PI = 4*std::atan(1);

class FourierovRed {
    double t;
    double *ak;
    double *bk;
    double n;
    
    public: 
    
    FourierovRed(double T, std::initializer_list<double> a, std::initializer_list<double> b);
    FourierovRed(int N, double T,std::function<double(int)> a, std::function<double(int)> b);
    FourierovRed(int N, double p, double q, std::function<double(double)> f, int M);
    
    
    
};
int main ()
{
	return 0;
}
