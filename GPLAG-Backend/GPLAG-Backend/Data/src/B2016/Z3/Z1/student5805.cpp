/B2016/2017: Zadaća 3, Zadatak 1
//Autotestovi by Enil Pajic (epajic1@etf.unsa.ba)
#include <iostream>
#include <vector>
#include <utility>
int main ()
{
    std::cout<<"Odaberite opciju (1 - unos cvorova, 2 - aproksimacija): ";
    int opcija;
    std::cin>>opcija;
    std::vector<std::pair<double,double>> par;
    if(opcija==1)
    {
        std::cout<<"Unesite broj cvorova: ";
        int n;
        std::cin>>n;
        std::cout<<"Unesite cvorove kao parove x y: ";
        for(int i=0;i<n;i++){
            double x,y;
            std::cin>>x>>y;
            par.push_back(std::pair<double,double>(x,y));
        }
    }
        std::cout<<"Unesite red interpolacije: ";
        int d;
        std::cin>>d;
    
    //while();
	return 0;
}