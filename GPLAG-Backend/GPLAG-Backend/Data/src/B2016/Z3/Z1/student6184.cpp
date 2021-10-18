/B2016/2017: Zadaća 3, Zadatak 1
//Autotestovi by Enil Pajic (epajic1@etf.unsa.ba)
#include <iostream>
#include <utility>
#include <functional>
#include <algorithm>

int k(int n){
    if(n==0) return 1;
    int proizvod(-1);
    for(int i=1;i<n-1;i++) proizvod*=proizvod;
    return proizvod;   
}

double TezinskiKoeficijent(int broj_cvorova,int red,std::pair<int,double> trenutni_cvor,std::vector<std::pair<double,double>> v){
    double suma(0);
    double proizvod(1);
    for(int i=std::max(1,trenutni_cvor.first-red);i<std::min(trenutni_cvor.first,broj_cvorova-red);i++){
        
        for( int j=i;j<i+red;j++){
            if(j==i) break; 
            proizvod*=1/(trenutni_cvor.second-v[j].first);
        }

        suma+=k(i-1)*proizvod;
    }
    return suma;
}

std::function<double(double)> BaricentricnaInterpolacija(std::vector<std::pair<double,double>> v,int d){
    double b(0),e(0),c(0);
    std::function<double(double)> fun;
    for(int i=1;i<v.size();i++){
        std::pair<double,double> a;
        a.first=v[i].first,a.second=v[i].second;
        double koef(TezinskiKoeficijent(v.size(),d,a,v));
        c+=koef;
        double pom(v[i].second);
       e=e+koef*pom;
       b+=v[i].first;
        return [e,b,c](int x){
            return ((1/((x/e)-b/e))/(x/e-c/e));
    };
        
    }

    for(int i=0;i<v.size();i++){
        
    }
    
}









int main ()
{
    
    std::vector<std::pair<double,double>> v{{1,3},{2,5},{4,4},{5,2},{7,1}};
   auto f(BaricentricnaInterpolacija({{1, 3}, {2, 5}, {4, 4}, {5, 2}, {7, 1}}, 2));
    std::cout << f(2.5);
    
    
    
    
    
	return 0;
}