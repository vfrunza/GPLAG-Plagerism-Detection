    /B2016/2017: Zadaća 3, Zadatak 1
//Autotestovi by Enil Pajic (epajic1@etf.unsa.ba)
#include <iostream>
#include <vector>
#include <functional>
#include <utility>
#include <cmath>
#include <stdexcept>

using std::cin;
using std::cout;
using std::endl;
using std::vector;
using std::function;
using std::pair;
using std::make_pair;
using std::domain_error;

function<double (double)> BaricentricnaInterpolacija(vector<pair<double,double>> parovi,int d){
    if(d<0 || d>=parovi.size()){
        throw domain_error("Nedozvoljen red");
    }
    for(int i=1;i<parovi.size();i++){
        for(int j=i+1;j<=parovi.size();j++){
            if(parovi[i-1].first==parovi[j-1].first){
                throw domain_error("Neispravni cvorovi");
            }
        }
    }
    vector<double> tezinski_koeficijenti;
    for(int i=1;i<=parovi.size();i++){
        int k(1);
        if((i-d)>1){
            k=i-d;
        }
        int granica(i);
        if((parovi.size()-d)<granica){
            granica=parovi.size()-d;
        }
        double p(1);
        double suma(0);
        for(;k<=granica;k++){
            p=1;
            for(int j=k;j<=(k+d);j++){
                if(j!=i){
                    p=p*(1./(parovi[i-1].first-parovi[j-1].first));
                }
            }
            p=p*pow(-1,k-1);
            suma=suma+p;
        }
        tezinski_koeficijenti.push_back(suma);
    }
    return [parovi,tezinski_koeficijenti,d](double x){double brojnik(0);for(int i=1;i<=parovi.size();i++){
        if(x==parovi[i-1].first){
            return parovi[i-1].second;
        }
    }
        for(int i=1;i<=parovi.size();i++){
        brojnik=brojnik+(tezinski_koeficijenti[i-1]/(x-parovi[i-1].first))*(parovi[i-1].second);
    }
        double nazivnik(0);for(int i=1;i<=parovi.size();i++){
            nazivnik=nazivnik+tezinski_koeficijenti[i-1]/(x-parovi[i-1].first);
        }
        return brojnik/nazivnik;
    };
}

function<double (double)> BaricentricnaInterpolacija(function <double (double)> f,double x_min,double x_max,double delta_x,int d){
    if(x_min>x_max || delta_x<=0){
        throw domain_error("Nekorektni parametri");
    }
    vector<pair<double,double>> parovi;
    for(int i=0;;i++){
        auto korak(x_min+i*delta_x);
        if(korak>x_max){
            break;
        }
        parovi.push_back(std::make_pair(x_min+i*delta_x,f(x_min+i*delta_x)));
    }
    return BaricentricnaInterpolacija(parovi,d);
}

double SinusnaFunkcija(double argument){
    return argument*argument+sin(argument);
}

int main ()
{
    int opcija;
    cout<<"Odaberite opciju (1 - unos cvorova, 2 - aproksimacija): ";
    cin>>opcija;
    try{
        if(opcija==1){
            int n;
            cout<<"Unesite broj cvorova: ";
            cin>>n;
            vector<pair<double,double>> parovi;
            cout<<"Unesite cvorove kao parove x y: ";
            for(int i=0;i<n;i++){
                double x;
                cin>>x;
                double y;
                cin>>y;
                parovi.push_back(make_pair(x,y));
            }
            int d;
            cout<<"Unesite red interpolacije: ";
            cin>>d;
            auto f(BaricentricnaInterpolacija(parovi,d));
            for(;;){
                double argument;
                cout<<"Unesite argument (ili \"kraj\" za kraj): ";
                cin>>argument;
                if(!cin){
                    break;
                }
                cout<<"f("<<argument<<") = "<<f(argument)<<endl;
            }
        }
    }
    catch(domain_error izuzetak){
        cout<<izuzetak.what();
    }
    try{
            if(opcija==2){
            double x_min,x_max,delta_x;
            cout<<"Unesite krajeve intervala i korak: ";
            cin>>x_min>>x_max>>delta_x;
            int d;
            cout<<"Unesite red interpolacije: ";
            cin>>d;
            for(;;){
                double argument;
                cout<<"Unesite argument (ili \"kraj\" za kraj): ";
                cin>>argument;
                if(!cin){
                    break;
                }
                auto f1(BaricentricnaInterpolacija([](double argument){return argument*argument+sin(argument);},x_min,x_max,delta_x,d));
                cout<<"f("<<argument<<") = "<<SinusnaFunkcija(argument)<<" fapprox("<<argument<<") = "<<f1(argument)<<endl;
            }
        }
    }
    catch(domain_error izuzetak){
        cout<<izuzetak.what();
    }
	return 0;
}