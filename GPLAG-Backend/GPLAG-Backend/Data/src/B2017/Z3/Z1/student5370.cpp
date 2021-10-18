/B2017/2018: Zadaća 3, Zadatak 1
#include <iostream>
#include <utility>
#include <vector>
#include <algorithm>
#include <functional>
#include <cmath>
double f (double broj){
    return broj*broj+sin(broj);
}
int LinearnaInterpolacija (std::vector<std::pair<double,double>>& parovi){
    try{
    std::sort(parovi.begin(),parovi.end());
    for (int i=0;i<parovi.size();i++){
        for (int j=i+1;j<parovi.size();j++){
            if (parovi[i].first==parovi[j].first) throw std::domain_error ("Neispravni cvorovi");
        }
    }
    return 5;
    }
    catch (std::domain_error e){
        std::cout<<e.what();
        throw;
    }
}
void Unesi (std::pair<double,double>& parovi){
    std::cin>>parovi.first>>parovi.second;
}
int main ()
{
    try{
    std::cout<<"Odaberite opciju (1 - unos cvorova, 2 - aproksimacija): ";
    int a;
    std::cin>>a;
    std::vector<std::pair<double,double>> parovi;
    if (a==1){
    int x;
    std::cout<<"Unesite broj cvorova: ";
    std::cin>>x;
    parovi.resize(x);
    std::cout<<"Unesite cvorove kao parove x y: "; 
    for (int i=0;i<x;i++) Unesi(parovi[i]);
    LinearnaInterpolacija(parovi);
    }
    }catch (...) {return 1;}
	return 0;
}
