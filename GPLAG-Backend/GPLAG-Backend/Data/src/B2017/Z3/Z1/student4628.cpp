/B2017/2018: Zadaća 3, Zadatak 1
#include <iostream>
#include <utility>
#include <vector>
#include <functional>
#include <algorithm>
#include <cmath>
#include <stdexcept>

using std::cin;
using std::cout;

std::function<double(double)> LinearnaInterpolacija(std::vector<std::pair<double, double>> cvorovi) {
    std::sort(cvorovi.begin(), cvorovi.end(), [] (std::pair<double, double> x, std::pair<double, double> y) { 
        return (x.first<=y.first); });
    const double epsilon(0.0000000001);
    for(auto i=0; i<cvorovi.size(); i++) {
        for(auto j=i; j<cvorovi.size(); j++) {
            if(i==j) continue;
            if(fabs(cvorovi[j].first-cvorovi[i].first)<epsilon) 
            throw std::domain_error("Neispravni cvorovi\n");
        }
    }
    return [cvorovi, epsilon] (double x) {
        if(cvorovi.size()<1 || x<cvorovi[0].first || x>cvorovi[cvorovi.size()-1].first) throw std::range_error("Argument izvan opsega\n");
        double vrijednost(0);
        if(fabs(cvorovi[cvorovi.size()-1].first-x)<epsilon) return cvorovi[cvorovi.size()-1].second;
        

        auto indeks(std::upper_bound(cvorovi.begin(), cvorovi.end(), x, [] (double x, std::pair<double,double> y) {
            return(x<=y.first);
        } ));
        
        auto indeks_sljedeceg(indeks);
        indeks--;
       vrijednost=(indeks->second)+((indeks_sljedeceg->second-indeks->second)/(indeks_sljedeceg->first-indeks->first))*(x-indeks->first);
        return vrijednost;
    };
}

std::function<double(double)> LinearnaInterpolacija(std::function<double(double)> funkcija, double min, double max, double delta){
    if(min>max || delta<=0) throw std::domain_error("Nekorektni parametri\n");
    std::vector<std::pair<double,double>> novi_cvorovi;
    if(min==max){
        auto par1=std::make_pair(min,max);
        novi_cvorovi.push_back(par1);
    }
    else{
    for(auto i=min; i<max; i+=delta) {
        std::pair<double, double> par;
        par=std::make_pair(i, funkcija(i));
        novi_cvorovi.push_back(par);
    }
    }
    return LinearnaInterpolacija(novi_cvorovi);
  
}

double funkcija(double x) {
    return x*x+std::sin(x);
}

int main ()
{
    cout<<"Odaberite opciju (1 - unos cvorova, 2 - aproksimacija): ";
    int opcija(0);
    cin>>opcija;
    try {
    if(opcija==1) {
        cout<<"Unesite broj cvorova: ";
        int broj(0);
        cin>>broj;
        const double epsilon(0.0000000001);
        cout<<"Unesite cvorove kao parove x y: ";
        std::vector<std::pair<double, double>> parovi;
        for(int i=0; i<broj; i++) {
            double x,y;
            cin>>x>>y;
            std::pair<double, double>brojevi;
            brojevi.first=x;
            brojevi.second=y;
            parovi.push_back(brojevi);
        }
        for(int i=0; i<parovi.size(); i++) {
            for(int j=i; j<parovi.size(); j++) {
                if(i==j) continue;
                if(fabs(parovi[i].first-parovi[j].first)<epsilon) throw std::domain_error("Neispravni cvorovi\n");
            }
        }
        while(1) {
        cout<<"Unesite argument (ili \"kraj\" za kraj): ";
        double x;
        cin>>x;
        if(!cin) break;
            try {
                auto rezultat(LinearnaInterpolacija(parovi)(x));
                cout<<"f("<<x<<") = "<<rezultat;
            std::cout << std::endl;
            }
            catch(std::domain_error izuzetak) {
            cout<<izuzetak.what();
            }
            catch(std::range_error izuzetak2) {
            cout<<izuzetak2.what();
            }
        }
    }
    
    else if(opcija==2) {
    cout<<"Unesite krajeve intervala i korak: ";
    double min, max, delta;
    cin>>min>>max>>delta;
    while(1) {
        cout<<"Unesite argument (ili \"kraj\" za kraj): ";
        double x;
        cin>>x;
        if(!cin) break;
            try {
                auto rezultat(LinearnaInterpolacija(funkcija, min, max, delta)(x));
                cout<<"f("<<x<<") = "<<funkcija(x)<<" fapprox("<<x<<") = "<<rezultat;
                std::cout << std::endl;
            }
            catch(std::domain_error izuzetak) {
            cout<<izuzetak.what();
            }
            catch(std::range_error izuzetak2) {
            cout<<izuzetak2.what();
            }
        }
    }
    }
    catch(std::domain_error izuzetak) {
        std::cout << izuzetak.what() << std::endl;
    }
    
	return 0;
}
