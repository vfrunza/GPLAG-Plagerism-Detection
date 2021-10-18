/B2016/2017: Zadaća 3, Zadatak 1
//Autotestovi by Enil Pajic (epajic1@etf.unsa.ba)
#include <iostream>
#include <string>
#include <cmath>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <utility>
#include <functional>
#include <stdexcept>
#include <cmath>
#define ep 0.000000001
typedef std::vector<std::pair<double, double>> VektoriParoviDoubleova;

double racunamo (VektoriParoviDoubleova v, int d, int i){
    int velicina = v.size(), k, a = i-d, mini, stepen, c;
    double suma = 0, proizvod = 1;
    int b = velicina - d;
    
    if(a>0)
        k = a;
    else 
        k = 1;
    if(b<i)
        mini = b;   
    else
        mini = i;
   for(int f=k;f<=mini;f++){
            stepen=pow(-1,f-1);
            c=f+d;
            for(int j = f; j < c+1; ++j){
             if(j-1!=i-1) 
                proizvod=proizvod*(1./(v[i-1].first-v[j-1].first));
            }
            suma=suma+(stepen*proizvod);
            proizvod=1;
        }
    
return suma;
}
bool dozvola (double a, double b){
    if(fabs(a-b)<ep)
        return true;
return false;
}
std::function<double (double)> BaricentricnaInterpolacija(VektoriParoviDoubleova v, int d){
    int n = v.size();
    
    if(d<0 || d>=n)
        throw std::domain_error ("Nedozvoljen red");
    
    for(int i = 0; i < n; i++)
        for(int j = i + 1; j < n; j++)
            if(dozvola(v[i].first,v[j].first))
                throw std::domain_error("Neispravni cvorovi");
    
    return [v, d, n](double x){
        double brojnik = 0, nazivnik = 0, f;
        for(int i = 1; i<=n; i++){
            if((fabs(v[i-1].first-x)>ep)){
                brojnik=brojnik+(racunamo(v,d,i)/(x-v[i-1].first))*v[i-1].second;
                nazivnik=nazivnik+(racunamo(v,d,i)/(x-v[i-1].first));}
                else{
                    return v[i-1].second;
                }
            }
            f=brojnik/nazivnik;
        return f;
    };
}

double funkcija_sinusa (double x){
    double vracam;
    vracam = x*x+std::sin(x);
    return vracam;
}

std::function<double(double)> BaricentricnaInterpolacija(std::function<double(double)> funkcija_sinusa, double m1, double m, double delta, int d){
    VektoriParoviDoubleova v;
    if(m1>m || delta<=0){
        throw std::domain_error ("Nekorektni parametri");
        return 0;
    }
    for(auto i = m1; i<=m; i=i+delta){
        std::pair<double,double> parovi;
        parovi = std::make_pair(i, funkcija_sinusa(i));
        v.push_back(parovi);
    }
    return BaricentricnaInterpolacija(v, d);
}

int main (){
    int unosim; 
    std::cout<<"Odaberite opciju (1 - unos cvorova, 2 - aproksimacija): ";
    std::cin>>unosim;
    VektoriParoviDoubleova vek;
    int n, red;
    if(unosim==1){
        std::cout<<"Unesite broj cvorova: ";
        std::cin>>n;
        std::cout<<"Unesite cvorove kao parove x y: ";
        for(auto i = 0; i<n; ++i){
            double x, y;
            std::pair<double, double> p;
            std::cin>>x;
            std::cin>>y;
            p = std::make_pair(x, y);
            vek.push_back(p);
        }
        std::cout<<"Unesite red interpolacije: ";
        std::cin>>red;
        double ok, vrednost;
        
        try{
            auto funkcija = BaricentricnaInterpolacija(vek, red);
        for(;;){
        vrednost = 0;
        std::cout<<"Unesite argument (ili \"kraj\" za kraj): ";
        std::cin>>ok;
        if(!std::cin) 
            break;
        vrednost = funkcija(ok);
        std::cout << "f(" << ok << ") = " << vrednost << std::endl;
        }
    }
    catch(std::domain_error izuzetak){
        std::cout<<izuzetak.what();
    }
    }
    if(unosim==2){
        double pocetak, kraj, delta, ok;
        int red;
        double vrednost1,vrednost2;
        std::cout<<"Unesite krajeve intervala i korak: ";
        std::cin>>pocetak>>kraj>>delta;
        std::cout<<"Unesite red interpolacije: ";
        std::cin>>red;
        try{
            auto funkcija1 = BaricentricnaInterpolacija(funkcija_sinusa, pocetak, kraj, delta, red);
            for(;;){
                 std::cout << "Unesite argument (ili \"kraj\" za kraj): ";
                 std::cin>>ok;
                 if(!std::cin)break;
                vrednost1 = funkcija_sinusa(ok);
                vrednost2 = funkcija1(ok);
                std::cout << "f(" << ok << ") = " << vrednost1 << " fapprox(" << ok << ") = " << vrednost2 << std::endl;
            }
        }
        catch(std::domain_error izuzetak){
            std::cout<<izuzetak.what();
            return 0;
        }
    }
	return 0;
}