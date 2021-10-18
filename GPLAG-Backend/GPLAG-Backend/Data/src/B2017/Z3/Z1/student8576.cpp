#include <iostream>
#include <utility>
#include <vector>
#include <functional>
#include <algorithm>
#include <stdexcept>
#include <cmath>
#define EPS 0.00001
using namespace std;
function<double(double)> LinearnaInterpolacija(vector<pair<double,double>> v)
{
    sort(v.begin(),v.end(),[](pair<double,double> p1, pair<double,double> p2) {
        return p1.first<p2.first;
    });
    int vel(v.size());
    for(int i=0; i<vel; i++) {
            for(int j=i;j<vel-1;j++){
                if(fabs(v.at(i).first-v.at(j+1).first)<EPS){
                    throw domain_error("Neispravni cvorovi");
                } 
            }
        }
    /*for(int i=0; i<v.size()-1; i++) {
        if(fabs(v.at(i).first-v.at(i+1).first)<EPS) throw domain_error("Neispravni cvorovi");
    }*/
    return [v](double x) {
        int vel(v.size());
        for(int i=0; i<vel-1; i++) {
            if(x>=v.at(i).first && x<v.at(i+1).first)
                return v.at(i).second + ((v.at(i+1).second-v.at(i).second)/(v.at(i+1).first-v.at(i).first))*(x-v.at(i).first);
            else if(fabs(x-v.at(v.size()-1).first)<EPS) return v.at(v.size()-1).second;
        }
        throw range_error("Argument izvan opsega");
    };
}
function<double(double)> LinearnaInterpolacija(function<double(double)> f, double x_min, double x_max, double delta_x)
{
    if(x_max<x_min || delta_x<=0) throw domain_error("Nekorektni parametri");
    vector<pair<double,double>> v;
    while(x_min<=x_max) {
        v.push_back({x_min,f(x_min)});
        x_min+=delta_x;
    }
    return LinearnaInterpolacija(v);
}
int main ()
{
    cout<<"Odaberite opciju (1 - unos cvorova, 2 - aproksimacija): ";
    int n;
    cin>>n;
    if(n==1) {
        cout<<"Unesite broj cvorova: ";
        int x;
        cin>>x;
        vector<pair<double,double>> v(x);
        cout<<"Unesite cvorove kao parove x y: ";
        for(int i=0; i<x; i++) {
            cin>>v.at(i).first>>v.at(i).second;
        }
        for(int i=0; i<v.size(); i++) {
            for(int j=i;j<v.size()-1;j++){
                if(fabs(v.at(i).first-v.at(j+1).first)<EPS){
                    cout<<"Neispravni cvorovi";
                    return 0;
                } 
            }
        }
        cout<<"Unesite argument (ili \"kraj\" za kraj): ";
        double arg;
        while(cin>>arg) {
            try {
                cout<<"f("<<arg<<") = "<<LinearnaInterpolacija(v)(arg)<<endl;
                cout<<"Unesite argument (ili \"kraj\" za kraj): ";
            } catch(domain_error izuzetak) {
                cout<<izuzetak.what()<<endl<<"Unesite argument (ili \"kraj\" za kraj): ";
            } catch(range_error izuzetak) {
                cout<<izuzetak.what()<<endl<<"Unesite argument (ili \"kraj\" za kraj): ";
            }
        }
    } else if(n==2) {
        cout<<"Unesite krajeve intervala i korak: ";
        double x_min,x_max,delta_x;
        cin>>x_min>>x_max>>delta_x;
        cout<<"Unesite argument (ili \"kraj\" za kraj): ";
        double arg;
        while(cin>>arg) {
            try {
                auto aproks(LinearnaInterpolacija([](double x) {
                    return x*x + sin(x);
                },x_min,x_max,delta_x)(arg));
                cout<<"f("<<arg<<") = "<<arg*arg + sin(arg)<<" ";
                cout<<"fapprox("<<arg<<") = "<<aproks<<endl;
                cout<<"Unesite argument (ili \"kraj\" za kraj): ";
            } catch(domain_error izuzetak) {
                cout<<izuzetak.what()<<endl<<"Unesite argument (ili \"kraj\" za kraj): ";
            } catch(range_error izuzetak) {
                cout<<izuzetak.what()<<endl<<"Unesite argument (ili \"kraj\" za kraj): ";
            }
        }

    }

    return 0;
}
