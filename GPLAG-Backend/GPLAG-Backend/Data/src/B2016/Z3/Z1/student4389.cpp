/B2016/2017: Zadaća 3, Zadatak 1
//Autotestovi by Enil Pajic (epajic1@etf.unsa.ba)
#include <iostream>
#include <cmath>
#include <algorithm>
#include <functional>
#include <utility>
#include <vector>
double TezinskiKoeficijent(std::vector<std::pair<int,int>> cvorovi, int d, int iteracija){
    int n(cvorovi.size());
    int k=std::max(1, iteracija-d);
    double tezinskikoeficijent(0);
    for(int i=k; i<std::min(iteracija, n-d); i++){
        double izraz(1);
        for(int j=k; j<k+d; j++){
            if(j == iteracija) continue;
            izraz*=1/(doublevb)(cvorovi.at(iteracija-1).first-cvorovi.at(j-1).first);
        }
        tezinskikoeficijent+=std::pow(-1, k-1) * izraz;
    }
    std::cout << tezinskikoeficijent << std::endl;
    return tezinskikoeficijent;
}
std::function<double(double)> BaricentricnaInterpolacija(std::vector<std::pair<int,int>> cvorovi, int red_inerpolacije){
    std::vector<double> tezinskikoeficijenti;
    for(int i=0; i<cvorovi.size(); i++){
        tezinskikoeficijenti.push_back(TezinskiKoeficijent(cvorovi, red_inerpolacije, i));
    }
    return [cvorovi, tezinskikoeficijenti] (double x){
        double izraz1(0), izraz2(0);
        for(int i=0; i<cvorovi.size(); i++){
            izraz2+=(tezinskikoeficijenti.at(i)/(x-cvorovi.at(i).first))*cvorovi.at(i).second;
            izraz1+=(tezinskikoeficijenti.at(i)/(x-cvorovi.at(i).first));
        }
        return izraz1/izraz2;
    };
}
int main ()
{
    auto fun = BaricentricnaInterpolacija({{1, 3}, {2, 5}, {4, 4}, {5, 2}, {7, 1}}, 2);
    std::cout << "fun (2.5) = " << fun (5.23);
	return 0;
}