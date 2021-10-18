/B2016/2017: Zadaća 3, Zadatak 1
//Autotestovi by Enil Pajic (epajic1@etf.unsa.ba)
#include <iostream>
#include <vector>
#include <utility>
#include <functional>
#include <algorithm>
#include <stdexcept>
#include <cmath>
#include <limits>
double postavka (double x) {return x * x + std::sin(x);}
std::function<double(double)> BaricentricnaInterpolacija(std::vector<std::pair<double, double>> cvorovi, int d ){
    if(!(d>=0 && d<=cvorovi.size())) throw std::domain_error("Nedozvoljen red");
    for(int i=0;i<cvorovi.size()-1;i++){
        for(int j=i+1;j<cvorovi.size();j++) 
        if(std::fabs(cvorovi[i].first -cvorovi[j].first)<10E-7) throw std::domain_error("Neispravni cvorovi");
    }
//napraviti vektor wi.
std::sort(cvorovi.begin(),cvorovi.end(),[](std::pair<double,double> prvi, std::pair<double,double> drugi){return (prvi.first<drugi.first);});
std::vector<double> wi;
// red == d;
//sumiranje za dobijanje jednog elementa wi;
for(int i=1;i<=cvorovi.size();i++){
    long double trenutwi(0);
    int donja,gornja;
    if(1>(i-d)) donja=1; else donja=i-d; //donja = max{1, i-d}
    if(i<(cvorovi.size()-d)) gornja=i; else gornja=cvorovi.size()-d; //gornja = min{i, n-d}
    
    for(int k=donja; k<=gornja;k++){
        long double p(1); //glavni proizvod
        for(int j=k;j<=(k+d);j++){
            if(i-1 == j-1) continue;
            p/=(cvorovi[i-1].first - cvorovi[j-1].first);
        }
        if((k-1) % 2 != 0) p*=(-1);
        trenutwi+=p;
    }
    wi.push_back(trenutwi);
}
    return [wi,cvorovi](double x)->double{
        double rezultat(0); bool nasao=false;
for(int i=0;i<cvorovi.size();i++) if(std::fabs(x -cvorovi[i].first)<10E-7){nasao = true; rezultat=cvorovi[i].second; break;}
        if(nasao) return rezultat;//
        double suma1(0),suma2(0);
        for(int i(0);i<cvorovi.size();i++){
            suma1+=(wi[i]/(x-cvorovi[i].first))*cvorovi[i].second;
            suma2+=(wi[i]/(x-cvorovi[i].first));
        }
        return (double)(suma1/suma2);
    };
}
std::function<double(double)> BaricentricnaInterpolacija(std::function<double(double)> fja, double xmin, double xmax, double dx, int d);
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

int main (){

    /*Odaberite opciju (1 - unos cvorova, 2 - aproksimacija): Unesite broj cvorova: Unesite cvorove kao parove x y: Unesite red interpolacije: Unesite argument (ili "kraj" za kraj): f(2.5) = 5.425
Unesite argument (ili "kraj" za kraj): f(4) = 4
Unesite argument (ili "kraj" za kraj): f(5.32) = 1.47372
Unesite argument (ili "kraj" za kraj): */
std::cout<<"Odaberite opciju (1 - unos cvorova, 2 - aproksimacija): ";
unsigned opcija;
std::cin>>opcija;
if(opcija == 1){
    //unos cvorova
    std::cout<<"Unesite broj cvorova: "; unsigned brojcvorova;
    std::cin>>brojcvorova;
    std::vector<std::pair<double,double>> cvorovi;
    std::cout<<"Unesite cvorove kao parove x y: ";
    {std::pair<double,double> unosnik;
    for(unsigned i=0;i<brojcvorova;i++){
        std::cin>>unosnik.first; //if(!std::cin) break;
        std::cin>>unosnik.second; //if(!std::cin) break;
        cvorovi.push_back(unosnik);
    }}
    
    std::cout<<"Unesite red interpolacije: ";
    int d; std::cin>>d;
//    std::vector<double> argumenti;
    {double tempjojeri;
    try{
auto fljas=BaricentricnaInterpolacija(cvorovi,d);
        while(std::cin){
        std::cout << "Unesite argument (ili \"kraj\" za kraj): ";
        std::cin>>tempjojeri; if(!std::cin)break;
        std::cout << "f(" << tempjojeri << ") = " << fljas (tempjojeri)<<std::endl;
//        argumenti.push_back(tempjojeri);
        }
    }catch(std::domain_error &gresky){std::cout<<gresky.what();return 0;}
    }
    
}
else if(opcija == 2){
    //aproksimacija
    /*Unesite krajeve intervala i korak: Unesite red interpolacije: Unesite argument (ili "kraj" za kraj): f(0.3) = 0.38552 fapprox(0.3) = 0.38552
Unesite argument (ili "kraj" za kraj): f(0.57) = 0.864532 fapprox(0.57) = 0.864515
Unesite argument (ili "kraj" za kraj): f(5) = 24.0411 fapprox(5) = 24.289
Unesite argument (ili "kraj" za kraj): */
    std::cout<<"Unesite krajeve intervala i korak: ";
    double xmin,xmax,dx;
    std::cin>>xmin>>xmax>>dx;
    std::cout<<"Unesite red interpolacije: "; int d; std::cin>>d;
    {double tempjojeri;
    try{
auto fljas=BaricentricnaInterpolacija(postavka,xmin,xmax,dx,d);
        while(std::cin){
        std::cout << "Unesite argument (ili \"kraj\" za kraj): ";
        std::cin>>tempjojeri; if(!std::cin)break;
        std::cout << "f(" << tempjojeri << ") = " << postavka(tempjojeri)<<" fapprox("<<tempjojeri<<") = "<<fljas (tempjojeri)<<std::endl;
//        argumenti.push_back(tempjojeri);
        }}catch(std::domain_error &gresky){std::cout<<gresky.what();return 0;}
    }
    
}
	return 0;
} 

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
std::function<double(double)> BaricentricnaInterpolacija(std::function<double(double)> fja, double xmin, double xmax, double dx, int d){
    if(xmin>xmax || dx <=0) throw std::domain_error("Nekorektni parametri");
    std::vector<std::pair<double,double>> cvorovi;
    double korak = xmin + dx;
    if(korak > xmax){ cvorovi.push_back(std::pair<double,double>(xmin,fja(xmin)));goto a;}
    for(double i=xmin;i<=xmax;i+=dx){
        if (i>xmax) break;
        cvorovi.push_back(std::pair<double,double>(i,fja(i)));
    }
    a:
    std::vector<double> wi;
// red == d;
//sumiranje za dobijanje jednog elementa wi;
for(int i=1;i<=cvorovi.size();i++){
    long double trenutwi(0);
    int donja,gornja;
    if(1>(i-d)) donja=1; else donja=i-d; //donja = max{1, i-d}
    if(i<(cvorovi.size()-d)) gornja=i; else gornja=cvorovi.size()-d; //gornja = min{i, n-d}
    
    for(int k=donja; k<=gornja;k++){
        long double p(1); //glavni proizvod
        for(int j=k;j<=(k+d);j++){
            if(i-1 == j-1) continue;
            p/=(cvorovi[i-1].first - cvorovi[j-1].first);
        }
        if((k-1) % 2 != 0) p*=(-1);
        trenutwi+=p;
    }
    wi.push_back(trenutwi);
}
    return [wi,cvorovi](double x)->double{
        double rezultat(0); bool nasao=false;
for(int i=0;i<cvorovi.size();i++) if(std::fabs(x -cvorovi[i].first)<10E-7){nasao = true; rezultat=cvorovi[i].second; break;}
        if(nasao) return rezultat;
        double suma1(0),suma2(0);
        for(int i(0);i<cvorovi.size();i++){
            suma1+=(wi[i]/(x-cvorovi[i].first))*cvorovi[i].second;
            suma2+=(wi[i]/(x-cvorovi[i].first));
        }return (double)(suma1/suma2);
    };
}