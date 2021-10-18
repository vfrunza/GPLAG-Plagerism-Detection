/B2017/2018: Zadaća 3, Zadatak 1
#include <iostream>
#include <stdexcept>
#include <functional>
#include <vector>
#include <algorithm>
#include <utility>
#include <cmath>
using namespace std;

bool Jednaki(double a,double b)
{
    return fabs(a-b)<0.0000001;
}

function<double(double)>LinearnaInterpolacija(vector<pair<double,double>>cvorovi)
{
    if(!(is_sorted(cvorovi.begin(),cvorovi.end()))) {
        sort(cvorovi.begin(),cvorovi.end(),[] (pair<double,double>p1,pair<double,double>p2) {
            return p1.first<p2.first;
        });
    }
    for(int i=0; i<cvorovi.size()-1; i++) {
        if(Jednaki(cvorovi[i].first,cvorovi[i+1].first)) throw domain_error("Neispravni cvorovi");
    }
    return[=](double x)->double {
        vector<pair<double,double>>v=cvorovi;
        if(x<v[0].first || x>v[v.size()-1].first) {
            throw range_error("Argument izvan opsega");

        }
        vector<pair<double,double>>pomocni=cvorovi;
        vector<pair<double,double>>::iterator g_granica=upper_bound(pomocni.begin(),pomocni.end(),x,[] (double broj,const pair<double, double>&p) {
            return broj<=p.first;
        });
        vector<pair<double,double>>::iterator d_granica {(--g_granica)++};
        double brojnik(0),nazivnik(0);
        brojnik+=((g_granica->second-d_granica->second)*(x-d_granica->first));
        nazivnik+=g_granica->first-d_granica->first;
        return d_granica->second+(brojnik/nazivnik);
    };
}

function<double(double)>LinearnaInterpolacija(function<double(double)>f,double x_min,double x_max,double x_delta)
{
    if(x_min>x_max || x_delta<=0) throw domain_error("Nekorektni parametri");
    vector<pair<double,double>>cvorovi;
    while(x_min<=x_max) {
        cvorovi.push_back(make_pair(x_min,f(x_min)));
        x_min+=x_delta;
    }
    return LinearnaInterpolacija(cvorovi);
}

int main ()
{
    int n;
    cout<<"Odaberite opciju (1 - unos cvorova, 2 - aproksimacija): ";
    cin>>n;
    if(n==1) {
        cout<<"Unesite broj cvorova: ";
        cin>>n;
        vector<pair<double,double>>cvorovi(n);
        cout<<"Unesite cvorove kao parove x y: ";
        for(int i=0; i<n; i++) {
            int x,y;
            cin>>x>>y;
            cvorovi[i]=make_pair(x,y);
        }
        try {
            auto f(LinearnaInterpolacija(cvorovi));
        } catch(domain_error x) {
            cout<<x.what()<<endl;
            return 0;
        }
        while(cout<<"Unesite argument (ili \"kraj\" za kraj): ") {
            try {
                double x;
                cin>>x;
                if(!cin) {
                    cin.ignore(10000,'\n');
                    cin.clear();
                    break;
                }
                auto f=LinearnaInterpolacija(cvorovi);
                cout<<"f("<<x<<") = "<<f(x)<<endl;
            }  catch(range_error d) {
                cout<<d.what()<<endl;
                continue;
            }
        }
    }
    if(n==2) {
        cout<<"Unesite krajeve intervala i korak: ";
        double x_min,x_max,x_delta;
        cin>>x_min>>x_max>>x_delta;
        try {
            auto k=LinearnaInterpolacija([] (double x) {
                return x*x+sin(x);
            },x_min,x_max,x_delta);
        } catch(domain_error x) {
            cout<<x.what()<<endl;
            return 0;
        }
        while(cout<<"Unesite argument (ili \"kraj\" za kraj): ") {
            try {
                double x;
                cin>>x;
                if(!cin) {
                    cin.ignore(10000,'\n');
                    cin.clear();
                    break;
                }
                auto k=LinearnaInterpolacija([] (double x) {
                    return x*x+sin(x);
                },x_min,x_max,x_delta);
                cout<<"f("<<x<<") = "<<x*x+sin(x)<<" fapprox("<<x<<") = "<<k(x)<<endl;
            } catch(range_error d) {
                cout<<d.what()<<endl;
                continue;
            }
        }
    }
    return 0;
}