/B2016/2017: Zadaća 3, Zadatak 1
//Autotestovi by Enil Pajic (epajic1@etf.unsa.ba)
#include <iostream>
#include<vector>
#include<utility>
#include<stdexcept>
#include<functional>
#include<cmath>
#include<map>
#include<algorithm>
using namespace std;
double fja(double x){
    return x*x+sin(x);
}
 function<double(double)>BaricentricnaInterpolacija(vector<pair<double,double>> cvorovi, int d){
     for(int i=0; i<cvorovi.size(); i++){
         for(int j=i+1; j<cvorovi.size(); j++){
             if(cvorovi[i].first==cvorovi[j].first)throw domain_error("Neispravni cvorovi ");
         }
     }
     if(d>=cvorovi.size() || d<0)throw domain_error("Nedozvoljen red");
    vector<double> wiovi(cvorovi.size());
    //indeksi wiova//
    for(int i=1; i<=cvorovi.size(); i++){
        //granice sume wi//
int max=0-cvorovi.size(), min=cvorovi.size();
if((cvorovi.size()-d)<i) max=cvorovi.size()-d;
else max=i;
if((i-d)>1)min=i-d;
else min=1;
double suma=0; 
//racunanje wi po datim granicama//
for(int k=min; k<=max; k++){ double proizvod=1;
    for(int m=k; m<=(k+d); m++)
        if((i-1)!=(m-1))proizvod/=(cvorovi[i-1].first - cvorovi[m-1].first);
         if((k-1)%2==1)proizvod=proizvod*(-1);
              suma+=proizvod;
        
}
    wiovi[i-1]=suma;
    }
 return [cvorovi,wiovi,d](double x){
     double nazivnik=0, brojnik=0;
     for(int i=0; i<cvorovi.size(); i++){ if(x==cvorovi[i].first) return cvorovi[i].second;}
     for(int i=1; i<=cvorovi.size(); i++){
         brojnik+=wiovi[i-1]*cvorovi[i-1].second/(x-cvorovi[i-1].first);
         nazivnik+=wiovi[i-1]/(x-cvorovi[i-1].first);
       
     }
     return (brojnik/nazivnik);
 };
}
template <typename tip>
 function<double(double)>BaricentricnaInterpolacija(tip f(tip), int min, int max, double deltax, int d){
    if(min>max || deltax<=0)throw domain_error("Nekorektni parametri!");
    //kreiramo cvorove//
    vector<pair<double, double>> cvorovi;
    for(double i=min; i<=max; i+=deltax){
       cvorovi.push_back(make_pair(i,f(i)));
    }
    //zovi i vrati interpolaciju//
   return BaricentricnaInterpolacija(cvorovi, d);
}
int main ()
{
    cout<<"Odaberite opciju (1 - unos cvorova, 2 - aproksimacija): ";
    int n;
    cin>>n;
    
    if(n==1){
    cout<<"Unesite broj cvorova: ";
    int m;
    cin>>m;
    vector<pair<double,double>>vektor(m);
    cout<<"Unesite cvorove kao parove x y: ";
    for(int i=0; i<m; i++){
        double prvi,drugi;
        cin>>prvi>>drugi;
        vektor[i]=make_pair(prvi,drugi);
    }
    cout<<"Unesite red interpolacije: ";
    int red;
    cin>>red;
    double x;
    try{
    auto fun=BaricentricnaInterpolacija(vektor, red);
    for(;;){
        cout<<"Unesite argument (ili \"kraj\" za kraj): ";
        cin>>x;
        if(!std::cin)break;
       else{
           cout<<"f("<<x<<") = "<<fun(x);} cout<<endl;
  }
    } catch (domain_error izuzetak){ cout<<izuzetak.what();} }
  
    if(n==2){
        cout<<"Unesite krajeve intervala i korak: ";
        double gornja, donja, deltax;
        cin>>donja>>gornja>>deltax;
        
 
        cout<<"Unesite red interpolacije: ";
        int red;
        cin>>red;
          try{
          auto fun=BaricentricnaInterpolacija(fja, donja, gornja, deltax, red);
         for(;;){
         double x; 
        cout<<"Unesite argument (ili \"kraj\" za kraj): ";
         cin>>x;
         if(!std::cin)break;
       else{ cout<<"f("<<x<<") = "<<fja(x);
           cout<<" fapprox("<<x<<") = "<<fun(x);
       }cout<<endl;
    }
    }catch (domain_error izuzetak){ cout<<izuzetak.what();}
    }
	return 0;
}
