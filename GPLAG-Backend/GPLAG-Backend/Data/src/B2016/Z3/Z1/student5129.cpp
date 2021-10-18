/B2016/2017: Zadaća 3, Zadatak 1

#include <iostream>
#include <vector>
#include <utility>
#include <functional>
#include <stdexcept>
#include <cmath>

using std::vector;
using std::pair;
using std::function;
using std::cin;
using std::cout;

function<double(double)> BaricentricnaInterpolacija(vector<pair<double, double>> cvorovi, int d){
    // Bacanje izuzetka
    if(d<0 || d>cvorovi.size()) throw std::domain_error("Nedozvoljen red");
    for(int i=0; i<cvorovi.size(); i++){
        for(int j=i; j<cvorovi.size(); j++){
            if(cvorovi[i].first == cvorovi[j].first) throw std::domain_error("Neispravni cvorovi");
        }
    }
    
    // Funkcija koju vracamo, uz potrebne parametre unutar lambda zatvorenja
    return [cvorovi, d](double x){
        double brojnik(0), nazivnik(0);
        int vrh, k, n(cvorovi.size());
        for(int i=0; i<n; i++){
            // Racuna Max za tezinski koeficijent
            if(i-d > 1) k=i-d;
            else k=1;
            // Racuna Min za tezinski koeficijent
            if(n-d < i) vrh=n-d;
            else vrh=i;
            
            // Sumiranje tezinskog koeficijenta
            double tk(0);
            for(; k<=vrh; k++){
                double produkt(1);
                // Racuna produkt koji se sumira
                for(int j=k; j<k+d; j++){
                    // Uslov proizvoda tako da nazivnik ne bude nula
                    if(j==i) continue;
                    
                    produkt*= 1/(cvorovi[i].first - cvorovi[j].first);
                }
                
                // Jedinica ispred produkta koja ulazi u sumu
                int jedinica(1);
                if((k-1)%2) jedinica=-1;
                tk += jedinica*produkt;
            }
            
            nazivnik += tk/(x-cvorovi[i].first);
            brojnik += nazivnik * cvorovi[i].second;
        }
        return brojnik/nazivnik;
    };
    
}

function<double(double)> BaricentricnaInterpolacija(function<double(double)> f, double xmin, double xmax, double dx, int d){
    // Izuzetak
    if(xmin>xmax || dx<=0) throw std::domain_error("Nekorektni parametri");
    
    vector<pair<double, double>> cvorovi;
    pair<double, double> par;
    for(;;){
        // Formira par clana i vrijednosti funkcije za taj clan, i ubacuje ih u vektor
        par = std::make_pair(xmin, f(xmin));
        cvorovi.push_back(par);
        // Prekida petlju da ne prekoraci
        if(xmin+dx > xmax) break;
        // Povecava se za korak interpolacije DX
        xmin+=dx;
    }
    
    // Vraca aproksimativnu funkciju koja je ista kao i obicna, samo sto joj proslijedimo drugacije cvorove
    return BaricentricnaInterpolacija(cvorovi, d);
}

int main (){
    cout << "Odaberite opciju (1 - unos cvorova, 2 -aproksimacija): ";
    int opcija;
    cin >> opcija;
    
    if(opcija==1){
        try{
            cout << "Unesite broj cvorova: ";
            int n;
            cin >> n;
            
            cout << "Unesite cvorove kao parove x y: ";
            vector<pair<double, double>> cvorovi;
            for(int i=0; i<n; i++){
                double x, y;
                cin >> x >> y;
                auto par(std::make_pair(x, y));
                cvorovi.push_back(par);
            }
            
            cout << "Unesite red interpolacije";
            int d;
            cin >> d;
            
            for(;;){
                cout << "Unesite argument (ili \"kraj\" za kraj): ";
                double arg;
                cin >> arg;
                if(!cin) break;
                cout << "f(" << arg << ") = " << BaricentricnaInterpolacija(cvorovi, d)(arg);
            }
        } catch(std::domain_error greska){
            cout << greska.what();
        }
    }
    
    if(opcija==2){
        try{
            cout << "Unesite krajeve intervala i korak: ";
            int xmin, xmax, dx;
            cin >> xmin >> xmax >> dx;
            
            cout << "Unesite red interpolacije";
            int d;
            cin >> d;
            
            for(;;){
                cout << "Unesite argument (ili \"kraj\" za kraj): ";
                double arg;
                cin >> arg;
                if(!cin) break;
                auto fun(BaricentricnaInterpolacija([](double x){return x*x + sin(x);} ,xmin, xmax, dx, d));
                cout << "f(" << arg << ") = " << BaricentricnaInterpolacija(fun, xmin, xmax, dx, d)(arg);
                cout << "fapprox(" << arg << ") = " << fun(arg) << std::endl;
            }
        } catch(std::domain_error greska){
            cout << greska.what();
        }
    }
    
    
	return 0;
}