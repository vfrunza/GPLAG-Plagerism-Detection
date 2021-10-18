#include <iostream>
#include <utility>
#include <functional>
#include <cmath>
#include <vector>
#include <stdexcept>
#include <cmath>

constexpr double EPSILON = 0.000000000001;

using namespace std;

typedef vector<pair<double,double>> UredParovi;

int max(int a, int b){
    if(a>b) return a;
    return b;
}

int min(int a, int b){
    if(a<b) return a;
    return b;
}

double TezinskiKoeficijenti(const UredParovi &parovi, int i, int n, int d){
    double suma(0);
    for(int k=max(1,i-d); k<=min(i,n-d); k++){ //Suma
        double proizvod(1);
        for(int j=k; j<=k+d; j++){ //Proizvod
            if(j==i) continue;
            proizvod*=1/(parovi.at(i-1).first-parovi.at(j-1).first); //-1 jer ovdje pocinje i od 0 a ne od 1
        }
        suma+=pow(-1,k-1)*proizvod;
    }
    return suma;
}

function<double(double)> BaricentricnaInterpolacija(const UredParovi &parovi, int d){
    if(d<0 or d>parovi.size()) throw domain_error("Nedozvoljen red");
    return [parovi,d](double x){
        for(int i=0; i<parovi.size(); i++){ //U slucaju da je x = xi, vrati yi
            if(fabs(parovi.at(i).first-x)<EPSILON) 
                return parovi.at(i).second;  
        }  
        
        double brojnik(0); double nazivnik(0);
        for(int i=1; i<=parovi.size(); i++){
            double koeficijent = TezinskiKoeficijenti(parovi,i,parovi.size(),d);
            brojnik+=( (koeficijent / (x-parovi.at(i-1).first)) * parovi.at(i-1).second );
            nazivnik+=( koeficijent/(x-parovi.at(i-1).first) );
        }
        return brojnik/nazivnik;
    };
}

function<double(double)> BaricentricnaInterpolacija(function<double(double)> f, double x_min, double x_max, double delta_x, int d){
    if(x_min>x_max or delta_x<=0) throw domain_error("Nekorektni parametri");
    UredParovi parovi;
    while(x_min<=x_max){ //Kreirajmo cvorove interpolacije
        pair<double,double> par;
        par.first=x_min;
        par.second=f(x_min);
        x_min+=delta_x;
        parovi.push_back(par);
    }
    return BaricentricnaInterpolacija(parovi,d);
}

double funkcija(double x){
    return x*x + sin(x);
}

int main ()
{
    int opcija;
    int *druga;
    druga=0;
    cout<<"Odaberite opciju (1 - unos cvorova, 2 - aproksimacija): ";
    cin>>opcija;
    cout << *druga;
    switch(opcija){
        case 1:
        {
            try{
                int n;
                cout<<"Unesite broj cvorova: ";
                cin>>n;
                UredParovi parovi(n);
                cout<<"Unesite cvorove kao parove x y: ";
                for(int i=0; i<n; i++){ //Unos parova
                    cin>>parovi.at(i).first;
                    cin>>parovi.at(i).second;
                }
                cout<<"Unesite red interpolacije: ";
                int d; 
                cin>>d;
                auto f(BaricentricnaInterpolacija(parovi,d));
                do{
                    cout<<"Unesite argument (ili \"kraj\" za kraj): ";
                    double x;
                    cin>>x;
                    if(!cin) break;
                    cout<<"f("<<x<<") = "<<f(x)<<endl;
                }while(1);
            }
            catch(domain_error e){
                cout<<e.what()<<endl;
            }
            break;
        }
        case 2:
        {
            try{
                cout<<"Unesite krajeve intervala i korak: ";
                double x_min,x_max,delta_x;
                cin>>x_min; cin>>x_max; cin>>delta_x;
                cout<<"Unesite red interpolacije: ";
                int d;
                cin>>d;
                auto f(BaricentricnaInterpolacija(funkcija,x_min,x_max,delta_x,d));
                do{
                    cout<<"Unesite argument (ili \"kraj\" za kraj): ";
                    double x;
                    cin>>x;
                    if(!cin) break;
                    cout<<"f("<<x<<") = "<<funkcija(x)<<" ";
                    cout<<"fapprox("<<x<<") = "<<f(x)<<endl;
                }while(1);
            }
            catch(domain_error e){
                cout<<e.what()<<endl;
            }
            break;
            
        }
        default:
            break;
    }
	return 0;
}