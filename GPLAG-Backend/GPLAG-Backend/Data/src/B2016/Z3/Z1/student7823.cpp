/B2016/2017: Zadaća 3, Zadatak 1
//Autotestovi by Enil Pajic (epajic1@etf.unsa.ba)
#include <iostream>
#include <functional>
#include <map>
#include <vector>
#include <algorithm>
#include <stdexcept>
#include <cmath>
#include <utility>

template<typename TIP>
bool JednakiRacionalni(TIP a, TIP b, double Eps=1e-10){
    return (std::fabs(a-b) <= Eps * (std::fabs(a) + std::fabs(b)));
}
double mojafunkcija(double x){
    return x*x + std::sin(x);
}

//Prva veryija funkcije
std::function<double(double)> BaricentricnaInterpolacija(std::vector<std::pair<double, double>> cvor, int d){
    int n(cvor.size());
    std::vector<long double> rezultat;

//Izuzetci    
    if(d<0 || d>n) throw std::domain_error("Nedozvoljen red");
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(i==j) continue;
            if(JednakiRacionalni(cvor[i].first, cvor[j].first)) throw std::domain_error("Nedozvoljen red");
        }
    }
    
    for(int i=1;i<=n;i++){
        long double wi{};
        for(int k=std::max(1,i-d); k<=std::min(i,n-d); k++){
            long double proizvod=1;
            for(int j=k; j<=k+d; j++){
                if(i-1==j-1) continue;
                proizvod=proizvod/(cvor[i-1].first - cvor[j-1].first);
            }
            if(k%2==0) proizvod=-proizvod;
            wi+=proizvod;
        }
        rezultat.push_back(wi);
    }
    
    return [=](double x){
        double suma1{}, suma2{};
        for(int i=0;i<n;i++){
                if(JednakiRacionalni(x, cvor[i].first)){
                return cvor[i].second;
            }    
            suma1 += (rezultat[i]/(x-cvor[i].first)) * cvor[i].second;
            suma2 += (rezultat[i]/(x-cvor[i].first));
        }
        return suma1/suma2;
    };
}
//Druga veryija funkcije
template<typename TIP>
std::function<double(double)> BaricentricnaInterpolacija(TIP f, double xmin, double xmax, double delta ,int d){
//Izuzetci
    if(xmin>xmax || delta<=0) throw std::domain_error("Nekorektni parametri");
    std::vector<std::pair<double, double>> cvorovi;
    
    for(double i=xmin; i<=xmax; i=i+delta){
        std::pair<double, double> tacke;
        tacke = std::make_pair(i, f(i));
        cvorovi.push_back(tacke);
    }
    return BaricentricnaInterpolacija(cvorovi, d);
}

int main (){
    std::cout<<"Odaberite opciju (1 - unos cvorova, 2 - aproksimacija): ";
    int odabir;
    std::cin>>odabir;
    
    
    switch(odabir){
        case 1: {
            std::cout<<"Unesite broj cvorova: ";
            int br_cv;
            std::cin>>br_cv;
            
            std::cout<<"Unesite cvorove kao parove x y: ";
            std::vector<std::pair<double, double>> cvorovi;
            for(int i=0; i<br_cv;i++){
                double x, y;
                std::cin>>x>>y;
                std::pair<double, double> tacke;
                tacke = std::make_pair(x, y);
                cvorovi.push_back(tacke);
            }
            
            std::cout<<"Unesite red interpolacije: ";
            int d;
            std::cin>>d;
            
            do{
                std::cout<<"Unesite argument (ili \"kraj\" za kraj): ";
                double argument;
                std::cin>>argument;
                if(!std::cin) break;
                
                try{
                    auto fun(BaricentricnaInterpolacija(cvorovi,d));
                    std::cout<<"f("<<argument<<") = "<< fun(argument)<<std::endl;
                }catch(std::domain_error izuzetak){
                    std::cout<<izuzetak.what()<<std::endl;
                    break;
                }
            }while(1);
            break;
        }
        
        
        case 2: {
            std::cout<<"Unesite krajeve intervala i korak: ";
            double xmin, xmax, korak;
            std::cin>>xmin>>xmax>>korak;
            
            std::cout<<"Unesite red interpolacije: ";
            int d;
            std::cin>>d;
            
            do{
                std::cout<<"Unesite argument (ili \"kraj\" za kraj): ";
                double argument;
                std::cin>>argument;
                if(!std::cin) break;
                
                try{
                    auto fun(BaricentricnaInterpolacija(mojafunkcija, xmin, xmax, korak, d));
                    std::cout<<"f("<<argument<<") = "<< mojafunkcija(argument)<<" fapprox("<<argument<<") = "<<fun(argument) <<std::endl;
                }catch(std::domain_error izuzetak){
                    std::cout<<izuzetak.what()<<std::endl;
                    break;
                }
            }while(1);
            break;
        }
    }    
	return 0;
}