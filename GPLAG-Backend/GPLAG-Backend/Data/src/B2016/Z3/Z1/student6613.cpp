/B2016/2017: Zadaća 3, Zadatak 1
//Autotestovi by Enil Pajic (epajic1@etf.unsa.ba)
#include <iostream>
#include<vector>
#include<utility>
#include<functional> 
#include<cmath>
#include<stdexcept>
using std::cin;
using std::cout;
using std::endl;
using std::function;
using std::vector;
using std::pair;
double f(double x){
    return (x*x+ std::sin(x));
}
vector<double>Omega(vector<pair<double, double>>v, int d){
    vector<double>w;
    double suma(0), produkt(1);
    for(int i=1; i<=v.size(); i++){
        int maks(1), mini(i);
        if(maks<(i-d)) maks=i-d;
        if(mini>v.size()-d) mini=v.size()-d;
        for(int k=maks-1; k<=mini-1; k++){
            for(int j=k; j<=k+d; j++){
                if(j==i-1) continue;
                produkt*=1./(v[i-1].first-v[j].first);
            }
            suma+=(produkt*pow((-1),k-1));
            produkt=1;
        }
        w.push_back(suma);
        suma=0;
        produkt=1;
    }
 
    return w;
}
function<double(double)> Brojnik(vector<pair<double,double>>v, vector<double>w){
    return [v,w](double x)->double{
        double suma(0);
        for(int i=1; i<=v.size(); i++){
        //    if(x==v[i-1].first) return v[i-1].second;
            suma+=((w[i-1]/(x-v[i-1].first))*v[i-1].second);
        }
        return suma;
    };
}
function<double(double)> Nazivnik(vector<pair<double,double>>v, vector<double>w){
    return [v,w](double x)->double{
        double suma(0);
        for(int i=1; i<=v.size(); i++){
         //   if(x==v[i-1].first) return v[i-1].second;
            suma+=((w[i-1]/(x-v[i-1].first)));
        }
        return suma;
    };
}
function<double(double)> BaricentricnaInterpolacija(vector<pair<double,double>>v, int d){
    if(d<0 || d>=v.size()) throw std::domain_error("Nedozvoljen red");
    for(int i=0; i<v.size(); i++)
        for(int j=i+1; j<v.size(); j++)
            if(v[i].first==v[j].first) throw std::domain_error("Neispravni cvorovi");
    auto w=Omega(v,d);
    auto brojnik=Brojnik(v,w);
    auto nazivnik=Nazivnik(v,w);
    return [brojnik, nazivnik, v](double x)->double{ for(int i=1; i<=v.size(); i++) if(x==v[i-1].first) return v[i-1].second;  return brojnik(x)/nazivnik(x);};
}
function<double(double)>BaricentricnaInterpolacija(function<double(double)>fun, double x_min, double x_max, double delta, int d){
    if(x_min>x_max || delta<=0) throw std::domain_error("Nekorektni parametri");
    vector<pair<double, double>>v;
    double y;
    for(double x=x_min; x<=x_max; x+=delta){
        y=fun(x);
        v.push_back(std::make_pair(x,y));
    }
    return BaricentricnaInterpolacija(v,d);
}
int main ()
{
    vector<pair<double,double>>v;
    double unos1, unos2, unos3;
    int unos;
    cout<<"Odaberite opciju (1 - unos cvorova, 2 - aproksimacija): ";
    cin>>unos;
    try{
    if(unos==1){
        cout<<"Unesite broj cvorova: ";
        cin>>unos;
        cout<<"Unesite cvorove kao parove x y: ";
        for(int i=0; i<unos; i++){
            cin>>unos1>>unos2;
            v.push_back(std::make_pair(unos1, unos2));
        }
        cout<<"Unesite red interpolacije: ";
        cin>>unos;
        auto fun=BaricentricnaInterpolacija(v,unos);
        while(1){
        cout<<"Unesite argument (ili \"kraj\" za kraj): ";
        cin>>unos1;
        if(!cin) return 0;
        cout<<"f("<<unos1<<") = "<<fun(unos1)<<endl;
        }
    }
    else if(unos==2){
        cout<<"Unesite krajeve intervala i korak: ";
        cin>>unos1>>unos2>>unos3;
        cout<<"Unesite red interpolacije: ";
        cin>>unos;
        auto fun(BaricentricnaInterpolacija(f, unos1, unos2, unos3, unos));
        while(1){
            cout<<"Unesite argument (ili \"kraj\" za kraj): ";
            cin>>unos1;
            if(!cin) return 0;
            cout<<"f("<<unos1<<") = "<<f(unos1)<<" fapprox("<<unos1<<") = "<<fun(unos1)<<endl;
        }
    }
    }
    catch(std::domain_error izuzetak){
        cout<<izuzetak.what()<<endl;
    }
	return 0;
}