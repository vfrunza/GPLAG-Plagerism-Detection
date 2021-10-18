/B2016/2017: Zadaća 3, Zadatak 1
//Autotestovi by Enil Pajic (epajic1@etf.unsa.ba)
#include <iostream>
#include <vector>
#include <stdexcept>
#include <cmath>
#include <functional>
#include <algorithm>

typedef std::vector<std::pair<double, double >> veki;
typedef std::function <double(double)>function
template <typename T>

double TezinskiKoeficijent(veki v, T d, T i){
    double suma = 0;
    int maxi = std:: max(1, (i-d)), mini = std::min(i,int(v.size()-d));
    for(int k = std::max(1,(i-d)); k<=std::min(i,int(v.size()-d));k++){
        double proizvod = 1;
        for(int j = k; j <= (k+d); j++)
            if(i!=j)
                proizvod *= (1/(v[i-1].first));
                
            suma += pow(-1, k-1)*proizvod;
    }
    return suma;
}
int main ()
{
	return 0;
}