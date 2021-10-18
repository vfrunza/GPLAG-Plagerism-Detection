/B2017/2018: Zadaća 5, Zadatak 6
#include <iostream>
#include <cmath>

int main ()
{
    int n=99999;
    double suma=0;
    for (int i=1; i<=n; i++) {
        double clan=(std::pow(-1, i-1))/((4.*i*i)-1);
        suma+=clan;
    }
    std::cout << suma << std::endl;
    std::cout << std::fabs(2*std::sqrt(2)-4*std::atan(1.))/(4*std::sqrt(2));
	return 0;
}
