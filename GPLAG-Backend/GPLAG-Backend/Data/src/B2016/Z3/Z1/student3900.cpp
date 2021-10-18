/B2016/2017: Zadaća 3, Zadatak 1
//Autotestovi by Enil Pajic (epajic1@etf.unsa.ba)
#include <iostream>
#include <functional>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

function<double(double)>BaricentricnaInterpolacija(vector<pair<double, double>>v, int d){
    if(d<=0 || d>=v.size()) throw domain_error("Nedozvoljen red");
    vector<double>v2;
    int n=v.size();
    double proizvod=1;
    for(int i=1; i<=v.size(); i++){
        double suma=0;
        for(int k=max(1, i-d); k<=min(i,n-d); k++){
            proizvod=1;
            for(int j=k; j<=k+d; j++)
                if(j!=i)
                   proizvod*=1/(v[i-1].first-v[j-1].first);
                suma+=pow(-1,(k-1))*proizvod;
                    
                
            }
        
            v2.push_back(suma);
        }
    return[v2, v, d](double x){ 
        double rez1=0, rez2=0;
        
        for(int i=1; i<=v.size(); i++){
            if(x==v[i-1].first) return v[i-1].second;
            rez1+=(v2[i-1]/(x-v[i-1].first))*v[i-1].second;
            rez2+=(v2[i-1]/(x-v[i-1].first));
        }
        double rez3=rez1/rez2;
        return rez3;
    };
}

function<double(double)>BaricentricnaInterpolacija(function<double(double)>f, double xmin, double xmax, double dx, int d){
    if(xmin>xmax || dx<=0) throw domain_error("Nekorektni parametri");
    vector<pair<double, double>>v;
    for(auto i=xmin; i<xmax; i+=dx){
        v.push_back(make_pair(i, f(i)));
    }
    return BaricentricnaInterpolacija(v, d);
    
}

int main ()
{
   int a, brc;
    double arg;
    vector<pair<double, double>>v;
    cout<<"Odaberite opciju (1 - unos cvorova, 2 - aproksimacija): ";
    cin>>a;
    pair<double, double>m;
    int red;
    if(a==1){
        cout<<"Unesite broj cvorova: ";
        cin>>brc;
        cout<<"Unesite cvorove kao parove x y: ";
        for(int i=0; i<brc; i++){
            cin>>m.first>>m.second;
            v.push_back(m);
        }
        cout<<"Unesite red interpolacije: ";
        cin>>red;
        try{
        for(;;){
        cout<<"Unesite argument (ili \"kraj\" za kraj): ";
        cin>>arg;
        if(!cin) return 0;
        else{
            auto f(BaricentricnaInterpolacija(v,red));
            cout<<"f("<<arg<<") = ";
            cout<<f(arg)<<endl;
        }
        }
    }
    catch(domain_error poruka){
        cout<<poruka.what()<<endl;
    }
    }
    double min, max, korak;
    if(a==2){
        cout<<"Unesite krajeve intervala i korak: ";
        cin>>min>>max>>korak;
        try{
        cout<<"Unesite red interpolacije: ";
        cin>>red;
        for(;;){
        cout<<"Unesite argument (ili \"kraj\" za kraj): ";
        cin>>arg;
        if(!cin) return 0;
        else{
            auto fja(BaricentricnaInterpolacija([](double x){return x*x+sin(x);}, min, max, korak, red));
            cout<<"f("<<arg<<") = "<<[](double x){return x*x+sin(x);}(arg);
            cout<<" fapprox("<<arg<<") = "<<fja(arg)<<endl;
        }
    }
    }
    catch(domain_error pp){
        cout<<pp.what()<<endl;
    }
    }
	return 0;
}