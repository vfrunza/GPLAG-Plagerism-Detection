/B2016/2017: Zadaća 3, Zadatak 1
//Autotestovi by Enil Pajic (epajic1@etf.unsa.ba)
#include <iostream>
#include <functional>
#include <vector>
#include <utility>
#include <cmath>
#include <cstdlib>
#include <stdexcept>
using namespace std;
function<double(double)> BaricentricnaInterpolacija(vector<pair<double,double>> cvorovi,int d){
    int n=cvorovi.size();
    if(d<0 || d>n) throw std::domain_error("Nedozvoljen red");
    for(int i=0;i<cvorovi.size();i++){
        for(int j=i+1;j<cvorovi.size();j++){
            if(cvorovi[i].first==cvorovi[j].first)throw std::domain_error("Nedozvoljen red");
        }
    }
vector<double> tezinski(n);
for(int i=1;i<=n;i++){
    tezinski[i-1]=0;
    int a=1,b=cvorovi.size()-d;
    if(i-d>a){ a=i-d;}
    if(i<b) b=i;
    for(int k=a;k<=b;k++){
        double proizvod(1);
        for(int j=k;j<=k+d;j++){
            if(i==j) continue;
            proizvod*=1./(cvorovi[i-1].first-cvorovi[j-1].first);
        }
        proizvod*=pow(-1,k-1);
        tezinski[i-1]+=proizvod;
    }
}
return[tezinski,cvorovi](double x)
{
    double brojnik=0,nazivnik=0;
    for(int i=1;i<=cvorovi.size();i++){
        
    if(x-cvorovi[i-1].first==0) {return cvorovi[i-1].second;}
    
    brojnik+=tezinski[i-1]*cvorovi[i-1].second/(x-cvorovi[i-1].first);
    nazivnik+=tezinski[i-1]/(x-cvorovi[i-1].first);}
    return brojnik/nazivnik;};
}
function<double(double)> BaricentricnaInterpolacija(double f(double),double xmin,double xmax,double dx,int d){
    if(xmin>xmax || dx<=0) throw std::domain_error("Nekorektni parametri");
    double pocetak=xmin;
    vector<double> prvi;
    while(pocetak<=xmax){
        prvi.push_back(pocetak);
        pocetak+=dx;
    }
    vector<pair<double,double>> cvorovi(prvi.size());
    for(int i=0;i<prvi.size();i++){
        cvorovi[i].first=prvi[i];
        cvorovi[i].second=f(prvi[i]);
    }
    return BaricentricnaInterpolacija(cvorovi,d);
}
double funkcija(double x){
    return x*x+sin(x);}
int main ()
{
    
    cout<<"Odaberite opciju (1 - unos cvorova, 2 - aproksimacija): ";
    int a;
    cin>>a;
    if(a==1){
        int n;
        cout<<"Unesite broj cvorova: ";
        cin>>n;
        vector<pair<double,double>> cvorovi(n);
        cout<<"Unesite cvorove kao parove x y: ";
        for(int i=0;i<n;i++){ 
        cin>>cvorovi[i].first;
                cin>>cvorovi[i].second;
        }
        cout<<"Unesite red interpolacije: ";
        int d;
        cin>>d;
        try{
        auto f(BaricentricnaInterpolacija(cvorovi,d));
        for(;;){
            cout<<"Unesite argument (ili \"kraj\" za kraj): ";
            double broj;
            cin>>broj;
            if(!std::cin) break;
            cout<<"f("<<broj<<") = "<<f(broj);
            cout<<endl;
        }}
        catch(std::domain_error izuzetak){cout<<izuzetak.what();}
    }
    else 
    if(a==2){    
     cout<<"Unesite krajeve intervala i korak: ";   
        double xmin,xmax,dx;
        cin>>xmin>>xmax>>dx;
        cout<<"Unesite red interpolacije: ";
        int d;
        cin>>d;
        try{
         auto f2(BaricentricnaInterpolacija(funkcija,xmin,xmax,dx,d));
        for(;;){
            cout<<"Unesite argument (ili \"kraj\" za kraj): ";
            double broj;
            cin>>broj;
            if(!std::cin) break;
            cout<<"f("<<broj<<") = "<<funkcija(broj)<<" fapprox("<<broj<<") = "<<f2(broj);
            cout<<endl;
        }}
         catch(std::domain_error izuzetak){cout<<izuzetak.what();}
        }
	return 0;
}