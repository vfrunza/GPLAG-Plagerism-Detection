/B2016/2017: Zadaća 3, Zadatak 1
//Autotestovi by Enil Pajic (epajic1@etf.unsa.ba)
#include <iostream>
#include <vector> 
#include <utility>


using std::cout;
using std::cin;


std::function<double(double)> BaricentricnaInterpolacija(std::vector<std::vector<int,int> vektor_parova,int red_interpolacije){
    return 
} 

int main ()
{   
    int opcija;
    cout<<"Odaberite opciju (1 - unos cvorova, 2 - aproksimacija): ";
    cin>>opcija;
    if(opcija==1){
        std::vector<std::pair<int,int>> vektor_parova;
        int broj_cvorova;
        cout<<"Unesite broj cvorova: ";
        cin>> broj_cvorova;
        for(int i=0;i<broj_cvorova;i++){
            std::pair<int,int> par;
            cin>>par.first;
            cin>>par.second;
            vektor_parova.push_back(par);
        }
       int red_interpolacije;
       cout<<"Unesite red interpolacije: "; 
       cin>> red_interpolacije;
       
    }
	return 0;
}