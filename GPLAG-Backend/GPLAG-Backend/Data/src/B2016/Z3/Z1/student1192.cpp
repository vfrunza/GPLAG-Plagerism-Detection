/B2016/2017: Zadaća 3, Zadatak 1
//Autotestovi by Enil Pajic (epajic1@etf.unsa.ba)
#include <iostream>
#include<utility>
#include <vector>
#include <functional>
#include <cmath>
#include <stdexcept>
using std:: cin;
using std:: cout;
using std:: vector;
using std:: function;

    

function<double(double) >BaricentricnaInterpolacija(vector<std:: pair<double,double>>v, int d){
    if(d<0 || d>v.size()) throw std:: domain_error("Nedozvoljen red");
    for(int i=0; i<v.size(); i++){
        for(int j=i+1; j<v.size(); j++){
            if(std:: fabs(v[i].first-v[j].first)<0.000001) throw std:: domain_error ("Neispravni cvorovi");
        }
    }
    vector<double> w(v.size(),0);
    for (int i=0; i<v.size(); i++){
        int min(1); if(i+1-d>min) min=i+1-d;
        int max(i+1); if(v.size()-d<max) max=v.size()-d;
        for(int k=min; k<=max; k++){
            double p(std:: pow(-1,k-1));
            for(int j=k; j<=k+d; j++){
                if(j-1==i) continue;
                p*=1./(v[i].first-v[j-1].first);
            }
            w[i]+=p;
        }
       
    }
    return [v, w](double x){
         double nazivnik(0), brojnik(0);
        for(int i=0; i<v.size(); i++){
            if(std:: fabs(v[i].first-x)<0.0000001){
                return v[i].second;
            }
            brojnik+=((w[i]*v[i].second)/(x -v[i].first));
            nazivnik+=(w[i]/(x -v[i].first));
        }
      return brojnik/nazivnik;
    
    };
}
std::function<double(double)>BaricentricnaInterpolacija(double f(double), double xmin, double xmax, double deltax, int d){
    if(xmin>xmax || deltax<0) throw std:: domain_error("Nekorektni parametri");
    vector<std:: pair<double, double>> v;
    while(xmin<xmax){
        v.push_back(std:: make_pair(xmin, f(xmin)));
        xmin= xmin+deltax;
    }
    
    return BaricentricnaInterpolacija(v,d);
}
int main ()

{
    try{
    cout << "Odaberite opciju (1 - unos cvorova, 2 - aproksimacija): ";
    int o; 
    cin >> o;
    if(o==1){
        cout << "Unesite broj cvorova: ";
        int brc;
        cin>> brc;
        vector<std:: pair<double,double>> v;
        cout << "Unesite cvorove kao parove x y: ";
        for(int i=0; i<brc; i++){
            double x, y;
            cin >>x>>y;
            v.push_back(std:: make_pair(x,y));
        }
        cout << "Unesite red interpolacije: ";
        int d;
        cin>>d;
        auto f(BaricentricnaInterpolacija(v,d));
        cout << "Unesite argument (ili \"kraj\" za kraj): ";
        double a;
        while(cin>> a){
            cout << "f("<< a << ") = "<< f(a) << std:: endl;
            cout << "Unesite argument (ili \"kraj\" za kraj): ";
        }
    }
    if(o==2){
        cout << "Unesite krajeve intervala i korak: ";
        double xmin, xmax, deltax;
        cin >> xmin>> xmax>> deltax; 
        cout << "Unesite red interpolacije: ";
        int d;
        cin>>d;
        auto fun([] (double x) {return x * x + std::sin(x);});
        auto f(BaricentricnaInterpolacija(fun, xmin, xmax, deltax, d));
        cout << "Unesite argument (ili \"kraj\" za kraj): ";
        double a;
        while(cin>> a){
            cout << "f("<< a << ") = "<< fun(a) <<  " fapprox(" << a << ") = "<< f(a) <<std:: endl;
            cout << "Unesite argument (ili \"kraj\" za kraj): ";
        }
        
        
    }
    }
   catch(std:: domain_error e) {
       cout << e.what();
        
    }
   

	return 0;
}