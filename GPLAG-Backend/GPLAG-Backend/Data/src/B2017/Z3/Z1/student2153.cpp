/B2017/2018: Zadaća 3, Zadatak 1
#include <iostream>
#include <vector>
#include <utility>
#include <functional>
#include <stdexcept>
#include <cmath>
#include <algorithm>
using namespace std;
typedef vector<pair<double, double>> VekPar;
function<double(double)>LinearnaInterpolacija(VekPar v){
    
    sort(v.begin(), v.end(), [](pair<double, double> a, pair<double, double> b) {return a.first<b.first;});
    //for(int i=0; i<v.size(); i++) cout<<v[i].first;
     for(int i=1; i<v.size(); i++) {
        if(v[i].first==v[i-1].first) {throw domain_error ("Neispravni cvorovi");}
    }
    return [v](double x){
        if(x>v[v.size()-1].first || x<v[0].first) throw range_error ("Argument izvan opsega");
        double pola=(v.size()/2);
        double pocetak=0;
        double kraj=v.size()-1;
        double x1, x2, y1, y2;
        for (;;) {
            if(x<=v[pola].first){
                if(v[pola].first==x) return v[pola].second;
                if(v[pola].first>x && v[pola-1].first<=x){
                    x1=v[pola-1].first;
                    x2=v[pola].first;
                    y1=v[pola-1].second;
                    y2=v[pola].second;
                    break;
                }
                kraj=pola;
                pola=(kraj-pocetak)/2+pocetak;
            }
            else {
                if(v[pola].first==x) return v[pola].second;
                if(v[pola].first>x && v[pola-1].first<=x){
                    x1=v[pola-1].first;
                    x2=v[pola].first;
                    y1=v[pola-1].second;
                    y2=v[pola].second;
                    break;
                }
                pocetak=pola;
                pola=(kraj-pocetak)/2+pocetak;
            }
        }
        
        return y1+((y2-y1)/(x2-x1))*(x-x1);
    };
}

function<double(double)>LinearnaInterpolacija(function<double(double)> f, double xmin, double xmax, double deltax){
    if(deltax<=0 || xmin>xmax) throw domain_error ("Nekorektni parametri");
    VekPar cvorovi;
    double i(xmin);
    for(;;){
        pair<double, double> pom(make_pair(i, f(i)));
        cvorovi.push_back(pom);
        i+=deltax;
        if(i>xmax) break;
    }
    return LinearnaInterpolacija(cvorovi);
}

double fun(double x){
    return x*x+sin(x);
}

int main ()
{
    
    int opcija;
    cout<<"Odaberite opciju (1 - unos cvorova, 2 - aproksimacija): ";
    cin>>opcija;
    if(opcija==1){
        cout<<"Unesite broj cvorova: ";
        int br_cvorova;
        cin>>br_cvorova;
        VekPar cvorovi;
        cout<<"Unesite cvorove kao parove x y: ";
        try{
        for(int i=0; i<br_cvorova; i++){
            double a, b;
            cin>>a>>b;
            pair<double, double>pom(make_pair(a,b));
            cvorovi.push_back(pom);
            
        }
        //sort(cvorovi.begin(), cvorovi.end(), [](pair<double, double> a, pair<double, double> b){return a.first<b.first;});
            //for(int i=1; i<cvorovi.size(); i++) {
        //if(cvorovi[i].first==cvorovi[i-1].first) {throw domain_error ("Neispravni cvorovi");}
    //}
    try{
    auto f(LinearnaInterpolacija(cvorovi));
    }
    catch(domain_error greskica){
        cout<<greskica.what()<<endl;
        return 0;
    }
        }
        catch(domain_error greska1){
            cout<<greska1.what();
            return 0;
        }
        
        for(;;){
            try{
            cout<<"Unesite argument (ili \"kraj\" za kraj): ";
            double c;
            cin>>c;
            if(!cin) break;
            
            auto f(LinearnaInterpolacija(cvorovi));
            
            
            cout<<"f("<<c<<") = "<<f(c)<<endl;
            
        }
        catch(range_error izuzetak1){
            cout<<izuzetak1.what()<<endl;
        }
        catch(domain_error greska){
            cout<<greska.what();
        }

    }
    }
    
    if(opcija==2) {
        double xmin, xmax, deltax;
        //try{
        cout<<"Unesite krajeve intervala i korak: ";
        //double xmin, xmax, deltax;
        cin>>xmin>>xmax>>deltax;
        //}
        
        for(;;){
            try{
            cout<<"Unesite argument (ili \"kraj\" za kraj): ";
            double c;
            cin>>c;
            if(!cin) break;
            
            auto f(LinearnaInterpolacija(fun, xmin, xmax, deltax));
            cout<<"f("<<c<<") = "<<fun(c)<<" fapprox("<<c<<") = "<<f(c)<<endl;
        }
        catch(range_error izuzetak1){
            cout<<izuzetak1.what()<<endl;
        }
         catch(domain_error greska1){
             cout<<greska1.what();
             return 0;
         }   
        
        }

    }

	return 0;
}
