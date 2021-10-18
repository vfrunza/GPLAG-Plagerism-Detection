#include <functional>
#include <utility>
#include <vector>
#include <stdexcept>
#include <cmath>
#include <iostream>
int max(int a, int b){
    if(a>b) return a;
    return b;
}
int min(int a, int b){
    if(a<b) return a;
    return b;
}
std::function<double(double)> BaricentricnaInterpolacija(std::vector<std::pair<double,double>> cvorovi, int d){
    if(d<0 || d>=cvorovi.size()) throw std::domain_error("Nedozvoljen red");
    for(int i=0; i<cvorovi.size(); i++){
        for(int j=i+1; j<cvorovi.size(); j++){
            if(cvorovi[i].first==cvorovi[j].first) throw std::domain_error("Neispravni cvorovi");
        }
    }
    int n=cvorovi.size();
    return [cvorovi,d,n] (double x){
         double f(0);
         double predznak(1);
     for(int i=1; i<=n; i++ ){
         double w(0);
         double proizvod(1);
         int k;
        for(k=max(1,i-d); k<=min(i,n-d); k++){
            predznak=pow(-1,k-1);
            for(int j=k; j<=k+d ; j++){
                if(j!=i){
        proizvod*=(1./(cvorovi[i-1].first-cvorovi[j].second));
                }
                }
            w+=double(predznak*proizvod);
        }
        f+=double(((w/(x-cvorovi[i-1].first))*cvorovi[i-1].second)/(w/(x-cvorovi[i-1].first)));
     }
     return f;
    };
}
int main ()
{
    auto f(BaricentricnaInterpolacija({{1, 3}, {2, 5}, {4, 4}, {5, 2}, {7, 1}}, 2));
    std::cout << f(2.5);
	return 0;
}