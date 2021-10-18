/B2016/2017: Zadaća 3, Zadatak 1
//Autotestovi by Enil Pajic (epajic1@etf.unsa.ba)
#include <iostream>
#include <stdexcept>
#include <vector>
#include <utility>
#include <functional>
#include <cmath>
#include <cstdio>
#include <cstdlib>

#define eps 0.1

using namespace std;

int maks(int jedan,int drugi  ){
   if(jedan>drugi) return jedan;
   return drugi;
}

int mini(int i, int j){
    if(i<j) return i;
    return j;
}

double wi(int i, vector<double> koeficijenti){
return koeficijenti[i];    
}

double f(double x){
   
    return (x*x + sin(x));

}

function<double(double)> BaricentricnaInterpolacija(vector<pair<double,double>> parovi, int d){
    if(d<0 ) throw domain_error("Nedozvoljen red");
    if(d>parovi.size()) throw domain_error("Nedozvoljen red");
    
    for(int i=0;i<parovi.size();i++){
        for(int j=i+1;j<parovi.size();j++){
        if(parovi[i].first==parovi[j].first)  throw domain_error("Neispravni cvorovi");   
        }
    }
    vector<double> koeficijenti;
    int n=parovi.size();
    for(int i=1;i<n+1;i++){
        
        int k;
        k=maks(1,i-d);
        int dd;
        dd=mini(i,n-d);
        double suma=0;
        for(int j=k;j<=dd;j++){
           double proizvod=1;
           for(int l=j;l<=j+d;l++){
               if(i==l) continue;
               proizvod*=(1./(parovi[i-1].first - parovi[l-1].first));
           }   
            
            suma+=(pow(-1,(j-1)) *proizvod); 
        }
       koeficijenti.push_back(suma); 
    }
    
    
    return [parovi,d,koeficijenti](double x){
        double novasuma1=0;
        double novasuma2=0;
        
        for(int i=0;i<parovi.size();i++){
            
            if((x-parovi[i].first)==0) return parovi[i].second;
            novasuma1+=(wi(i,koeficijenti)/(x-parovi[i].first)) * parovi[i].second;
            novasuma2+=wi(i,koeficijenti)/(x-parovi[i].first); 
        }
        return novasuma1/novasuma2;
    };
}

template <typename Tip>
function<double(double)> BaricentricnaInterpolacija(Tip f(double), double xmin, double xmax, double deltax, int d){
    if(xmin-xmax>eps) throw domain_error("Nekorektni parametri"); 
    if(deltax<=0.00) throw domain_error("Nekorektni parametri");
   
    
    vector<pair<double,double>> cvorovi;
    for(double i=xmin;i<=xmax;i+=deltax){
       
       cvorovi.push_back(make_pair(i,f(i)));
     
    }
    return BaricentricnaInterpolacija(cvorovi, d);

    
    
}


int main ()
{
    try{
    cout<<"Odaberite opciju (1 - unos cvorova, 2 - aproksimacija): ";
    int n;
    cin>>n;
    
    if(n==1){
        
        cout<<"Unesite broj cvorova: ";
        int brojcvorova;
        vector<pair<double,double>> mojvektor;
        cin>>brojcvorova;
        cout<<"Unesite cvorove kao parove x y: ";
        for(int i=0;i<brojcvorova;i++){
            int x,y;
            cin>>x>>y;
            mojvektor.push_back(make_pair(x,y));
          
        }
        cout<<"Unesite red interpolacije: ";
        int d; cin>>d;
        
        for(;;){
            cout<<"Unesite argument (ili \"kraj\" za kraj): ";
            double brojj;
            cin>>brojj;
            if(!(cin)) break;
            cout<<"f("<<brojj<<") = "<<BaricentricnaInterpolacija(mojvektor,d)(brojj)<<endl;
        }
    
    }
    
    if(n==2){
        cout<<"Unesite krajeve intervala i korak: ";
        double xmin,xmax,deltax;
        cin>>xmin;
        cin>>xmax;
        cin>>deltax;
        cout<<"Unesite red interpolacije: ";
        int redintera;
        cin>>redintera;
        auto funkcija2(BaricentricnaInterpolacija(f,xmin,xmax,deltax,redintera));
        for(;;){
            cout<<"Unesite argument (ili \"kraj\" za kraj): ";
            double brojjj;
            cin>>brojjj;
            if(!(cin)) break;
            double funkcija;
            funkcija=f(brojjj);
            
            cout<<"f("<<brojjj<<") = "<<funkcija;
            cout<<" fapprox("<<brojjj <<") = "<<funkcija2(brojjj)<<endl;
            
        }
    }
   
    
    }catch(domain_error izuzetak){cout<<izuzetak.what();}
	return 0;
}