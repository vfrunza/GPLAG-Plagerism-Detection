/B2016/2017: Zadaća 3, Zadatak 1
//Autotestovi by Enil Pajic (epajic1@etf.unsa.ba)

#include <iostream>
#include <vector>
#include <stdexcept>
#include <utility>
#include <functional>
#include <cmath>

using std::cout;
using std::cin;
using std::endl;
using std::pair;
using std::vector;
using std::function;
using std::pow;

int maximum(int i, int x) {
    if(i<x) return x;
    else return i; 
}
int minimum(int i, int x) {
    if(i>x) return x;
    else return i; 
}

double g(double x) {
    return x*x+sin(x);
}

function<double(double)>BaricentricnaInterpolacija (vector<pair<double,double>> v, int d) {
    if(d<0 || d>=v.size()) throw std::domain_error("Nedozvoljen red");
    for(int i=0; i<v.size(); i++) 
        for(int j=0; j<v.size(); j++)
            if(i!=j && v[i].first==v[j].first) throw std::domain_error("Neispravni cvorov");
        
    double suma(0),p;
    int n(v.size()),max,min;
    vector<double> w(n);
     
    for(int i=1; i<=n; i++) {
       
        max=maximum(1,i-d); 
        min=minimum(i,n-d); 
        
        suma=0; 
        for(int k=max-1; k<=min-1; k++) {
        p=1.;
        for(int j=k; j<=k+d; j++) {
        
           if(i-1!=j) p*=1./(v[i-1].first-v[j].first);
            
        }
        
        suma+=pow(-1,k-1)*p;
        
    }
    
    w[i-1]=suma;
 
    }
       
    return [v,w] (double x) {
        double suma1(0),suma2(0);
        for(int i=1; i<=v.size(); i++) {
            if(x==v[i-1].first) return v[i-1].second;
            else{
                
                suma2+=(w[i-1]/(x-v[i-1].first));
            }
            suma1+=(w[i-1]/(x-v[i-1].first))*v[i-1].second;
        }
       
            return suma1/suma2;
        };
    }
    



function<double(double)> BaricentricnaInterpolacija (function<double(double)> f,double xmin, double xmax, double deltax, int d) {
    if(xmin>xmax || deltax<=0) throw std::domain_error("Nekorektni parametri");
    
    vector<pair<double,double>> v(0);
    while(xmin<=xmax) {
        double y(f(xmin));
        pair<double,double> par(xmin,y);
        v.push_back(par);
        xmin+=deltax;
        
    }
    
    return BaricentricnaInterpolacija(v,d);
       
}

int main ()
{
   
    cout<<"Odaberite opciju (1 - unos cvorova, 2 - aproksimacija): ";
    int opcija;
    cin>>opcija;
     try{
    if(opcija==1) {
    cout<<"Unesite broj cvorova: ";
    int broj;
    cin>>broj;
    cout<<"Unesite cvorove kao parove x y: ";
   
    vector<pair<double,double>> v(0);
    
        for(int i=0; i<broj; i++) {
            double prvi,drugi;
            cin>>prvi>>drugi;
             pair<double,double> par(prvi,drugi);
            v.push_back(par);
            
        }
    
    cout<<"Unesite red interpolacije: ";
    int d;
    cin>>d;
    auto f(BaricentricnaInterpolacija(v,d));
    for(;;) {
        
        double argument;
         cout<<"Unesite argument (ili \"kraj\" za kraj): ";
        cin>>argument;
        if(!cin) break;
        cout<<"f("<<argument<<") = "<<f(argument) <<endl;
         
    }
    
    }
   

    if(opcija==2) {
        cout<<"Unesite krajeve intervala i korak: ";
        double pocetak,kraj,korak;
        cin>>pocetak>>kraj>>korak;
        
        cout<<"Unesite red interpolacije: ";
        int d;
        cin>>d;
        
        auto f(BaricentricnaInterpolacija(g ,pocetak,kraj,korak,d));
        
    for(;;) {
        double argument;
        cout<<"Unesite argument (ili \"kraj\" za kraj): ";
        cin>>argument;
        if(!cin) break;
        cout<<"f("<<argument<<") = "<<g(argument)<<" fapprox("<<argument<<") "<<"= "<<f(argument)<<endl;
    }
        
    }
    
    }
    catch(std::domain_error i) {
        cout<<i.what();
    }
    
    
    
	return 0;
}



