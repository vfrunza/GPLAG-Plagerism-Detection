/B2016/2017: Zadaća 3, Zadatak 1
//Autotestovi by Enil Pajic (epajic1@etf.unsa.ba)
#include <iostream>
#include <vector>
#include <utility>
#include <functional>
#include <cmath>
using namespace std; 
function<double(double)> BaricentricnaInterpolacija(vector<pair<double, double>> cvorovi, int d){
    double suma=0, produkt=1; 
    vector<double> w;
    if(d>=cvorovi.size() || d<0) throw domain_error ("Nedozvoljen red"); 
    int n=cvorovi.size(); 
    for(int i=1; i<=n; i++){
        suma=0; 
        int gore, dole; 
        if(i<n-d) gore=i; 
        else gore=n-d;
        if(1>i-d) dole=1; 
        else dole=i-d; 
        
        for(int k=dole; k<=gore; k++){
            produkt=1; 
            for(int j=k; j<=k+d; j++){
                if(j!=i){
                auto xi=cvorovi[i-1].first; 
                auto xj=cvorovi[j-1].first;
                produkt=produkt/(xi-xj); 
                }
            }
            produkt=produkt*pow(-1, k-1); 
            suma=suma+produkt; 
        }
        w.push_back(suma); 
    }
        return [w,cvorovi] (double x) -> double{
            double nazivnik=0, brojnik=0;
            for(int i=1; i<=cvorovi.size(); i++){
                if(x==cvorovi[i-1].first) return cvorovi[i-1].second; 
                brojnik+=(w[i-1]*cvorovi[i-1].second)/(x-cvorovi[i-1].first);
                nazivnik+=w[i-1]/(x-cvorovi[i-1].first); 
            }
            return brojnik/nazivnik; 
        };
}
function<double(double)> BaricentricnaInterpolacija (double funkcija(double), double xmin, double xmax, double korak, int d){
    if(xmin>xmax || korak<=0) throw domain_error ("Nekorektrni parametri");
    
    vector<pair<double, double>> cvorovi; 
    int j=0;
    for(double i=xmin; i<=xmax; i+=korak){
        cvorovi.push_back(make_pair(xmin+j*korak, funkcija(i)));
        j++;
    }
    auto f=BaricentricnaInterpolacija(cvorovi, d); 
    return f; 
    
}
int main ()
{
    int broj_cvorova; 
    double prvi, drugi; 
    int red_interpolacije; 
    vector<pair<double,double>> cvorovi;
    
    cout << "Odaberite opciju (1 - unos cvorova, 2 - aproksimacija): "; 
    int opcija; 
    cin >> opcija;

    if(opcija==1){
        cout << "Unesite broj cvorova: "; 
        cin >> broj_cvorova; 
        cvorovi.resize(broj_cvorova);
        cout << "Unesite cvorove kao parove x y: "; 
        for(int i=0; i<broj_cvorova; i++){
            cin >> prvi; 
            cin >> drugi; 
           cvorovi[i].first=prvi;
           cvorovi[i].second=drugi; 
        }
        cout << "Unesite red interpolacije: "; 
        cin >> red_interpolacije; 
        
        cout << "Unesite argument (ili \"kraj\" za kraj): ";
        double argument; 
        while(cin>>argument){
            try{
            auto funckija=BaricentricnaInterpolacija(cvorovi, red_interpolacije);
            cout << "f("<<argument<<") = " << funckija(argument) << endl; 
             cout << "Unesite argument (ili \"kraj\" za kraj): ";
            }
            catch(domain_error poruka){
                cout << poruka.what();
            }
        }
    }
    if(opcija==2){
        
        cout << "Unesite krajeve intervala i korak: "; 
        double pocetak, kraj; 
        double korak; 
        cin >> pocetak >> kraj >> korak; 
        cout << "Unesite red interpolacije: "; 
        cin >> red_interpolacije; 
        cout << "Unesite argument (ili \"kraj\" za kraj): "; 
        double argument; 
        while(cin >> argument){ 
            try{
                
        auto f1=BaricentricnaInterpolacija([](double x)-> double{
        return x*x+sin(x); 
        }, pocetak, kraj, korak, red_interpolacije); 
        
        auto f2=argument*argument+sin(argument); 
        
        cout << "f(" << argument << ") = " << f2 << " fapprox(" << argument << ") = " << f1(argument) << endl; 
        cout << "Unesite argument (ili \"kraj\" za kraj): ";
            }
            catch(domain_error poruka){
                cout << poruka.what(); 
            }
        }
    }
	return 0;
}