/B2016/2017: Zadaća 3, Zadatak 1
//Autotestovi by Enil Pajic (epajic1@etf.unsa.ba)
#include <iostream>
#include <functional>
#include <utility>
#include <vector>
#include <stdexcept>
#include <algorithm>
#include <cmath>
#include <string>
#include <sstream>

using std::cin;
using std::cout;
using std::endl;
using std::pair;
using std::function;
using std::domain_error;
using std::max_element;
using std::min_element;
using std::pow;
using std::make_pair;
using std::string;
using std::vector;
using std::sin;

int ZaMax(int a, int b ){
    if(a>b)return a;
    return b;
}

int ZaMin(int a, int b){
    if(a<b)return a;
    return b;
}

function<double(double)> BaricentricnaInterpolacija(vector<pair<double,double>> v, int d ){
    
    if(d<0 || d>v.size())throw domain_error("Nedozvoljen red");
    for(int i=0; i<v.size(); i++){
        for(int j=i+1; j<v.size()-1; j++){
            
            if(v[i].first == v[j].first)throw domain_error("Neispravni cvorovi");
        }
    }
    
    
    
    int n = v.size(); //n broj cvorova interpolacije
    
    //dobijanje cvorova interp
    vector<double> w;
    
    for(int i = 1; i<=n; i++){
        
        
        
     double suma = 0;
        for(int k = ZaMax(1,i-d); k<=ZaMin(i,n-d); k++ ){
            
            double proizvod = 1;
            for(int j = k; j<=k+d; j++){
                if(j==i)continue;
                proizvod = proizvod * (1./(v[i-1].first-v[j-1].first));
            }
            
            suma = suma + pow(-1,k-1)*proizvod;
        }
        
        w.push_back(suma);
        
    }
    
    return [=](double x)->double{
        
        for(int i=0; i<v.size(); i++){
            if(v[i].first == x)return v[i].second;
        }
        double sumabrojnika = 0;
        double sumanazivnika = 0;
        double suma;
        for(int i=1; i<=n; i++){
            
            sumabrojnika = sumabrojnika + (w[i-1]*v[i-1].second)/(x-v[i-1].first);
            
            sumanazivnika = sumanazivnika + w[i-1]/(x-v[i-1].first);
             suma = sumabrojnika/sumanazivnika;
            
            
        }
        
        return suma;
    };
    
}


function<double(double)> BaricentricnaInterpolacija(function <double(double)> f, double xmin, double xmax, double deltax, int d){
    
    if(xmin>xmax || deltax<=0 )throw domain_error("Nekorektni parametri");
    
    
    
    int broj_cvorova = 0;
    for(double t = xmin; t<=xmax; t=t+deltax){
        broj_cvorova++;
    }
    
    vector<pair<double,double>> v(broj_cvorova);
    
    for(int i=0; i<broj_cvorova; i++){
        v[i].first = xmin;
        v[i].second = f(xmin);
        xmin = xmin +deltax;
    }
    
     
     return BaricentricnaInterpolacija(v,d);
}

double fun(double x){
    return x*x+sin(x);
}


int main ()
{
    try{
        
        
            cout<<"Odaberite opciju (1 - unos cvorova, 2 - aproksimacija): ";
            int izbor;
            cin>>izbor;
            
                if(izbor == 1){
            
                    cout<<"Unesite broj cvorova: ";
                    int broj_cvorova;
                    cin>>broj_cvorova;
                    
                    cout<<"Unesite cvorove kao parove x y: ";
                    
                    vector<pair<double,double>> v(broj_cvorova);
                    
                    for(int i=0; i<broj_cvorova; i++){
                        double x,y;
                        cin>>x>>y;
                        v[i] = make_pair(x,y);
                    }
                    
                    cout<<"Unesite red interpolacije: ";
                    int d;
                    cin>>d;
                    
                    
                    while(1){
                       cout<<"Unesite argument (ili \"kraj\" za kraj): ";
                        double argument;
                        cin>>argument;
                        
                        if(!cin)break;
                        
                        auto f(BaricentricnaInterpolacija(v,d));
                        
                        cout<<"f("<<argument<<") = "<<f(argument)<<endl;
                        
                    }
                    
                }
                else{
                    cout<<"Unesite krajeve intervala i korak: ";
                    double xmin,xmax,deltax;
                    cin>>xmin>>xmax>>deltax;
                    
                    cout<<"Unesite red interpolacije: ";
                    int d;
                    cin>>d;
                    
                    while(1){
                        
                        cout<<"Unesite argument (ili \"kraj\" za kraj): ";
                        double argument;
                        cin>>argument;
                        if(!cin)break;
                        
                        auto fapprox(BaricentricnaInterpolacija(fun, xmin, xmax, deltax, d));
                        
                        cout<<"f("<<argument<<") = "<<fun(argument)<<" ";
                        
                        cout<<"fapprox("<<argument<<") = "<<fapprox(argument)<<endl;
                        
                    }
                }
          
    }
    catch(domain_error i){
        i.what();
    }
        
    	return 0;
}