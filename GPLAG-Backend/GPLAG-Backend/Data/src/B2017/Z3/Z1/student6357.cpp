#include <iostream>
#include <vector>
#include <utility>
#include <functional>
#include <stdexcept>
#include <algorithm>
#include <limits>
#include <cmath>
using namespace std;
function<double(double)> LinearnaInterpolacija(vector<pair<double,double>> v)
{
    bool sortiranje=false;
    for(int i=0; i<v.size(); i++) {
        for(int j=i+1; j<=v.size()-1; j++) {
            if(v[i].first==v[j].first) throw domain_error("Neispravni cvorovi");
            if(v[i].first>v[j].first) sortiranje=true;
        }
    }
    if(sortiranje)
        sort(v.begin(),v.end());
    return [v](double x) {
        if(x<v[0].first || x>v[v.size()-1].first) throw range_error("Argument izvan opsega");
        if(x==v[v.size()-1].first) return v[int(v.size()-1)].second;
        auto donja=upper_bound(v.begin(),v.end(),make_pair(x,numeric_limits<double>::max()));
        auto gornja=lower_bound(v.begin(),v.end(),make_pair(x,numeric_limits<double>::min()));
        --donja;
        if(gornja->first==x && gornja-v.begin()!=v.size()) gornja++;
        return ((gornja->second-donja->second)*(x-donja->first))/(gornja->first-donja->first)+donja->second;
    };
}
function<double(double)> LinearnaInterpolacija(function<double (double)> f,double xmin,double xmax,double deltax)
{
    if(xmin>xmax || deltax<=0) throw domain_error("Nekorektni parametri");
    vector<pair<double,double>> v;
    for(;;) {
        if(xmin>xmax) break;
        v.push_back(make_pair(xmin,f(xmin)));
        xmin+=deltax;
    }
    return LinearnaInterpolacija(v);
}
int main ()
{
    cout<<"Odaberite opciju (1 - unos cvorova, 2 - aproksimacija): ";
    int unos;
    cin>>unos;
    if(unos==1) {
        cout<<"Unesite broj cvorova: ";
        int broj;
        cin>>broj;
        cout<<"Unesite cvorove kao parove x y: ";
        vector<pair<double,double>> v;
        for(int i=0; i<broj; i++) {
            pair<double,double> cvor;
            cin>>cvor.first>>cvor.second;
            v.push_back(cvor);
        }
        try {
            auto f(LinearnaInterpolacija(v));
            for(;;) {
                cout<<"Unesite argument (ili \"kraj\" za kraj): ";
                double x;
                if(!(cin>>x)) break;
                cout<<"f("<<x<<") = "<<LinearnaInterpolacija(v)(x)<<endl;
            }
        } catch(range_error e) {
            cout<<e.what();
        } catch(domain_error a) {
            cout<<a.what();
        }
    }
    if(unos==2) {
        cout<<"Unesite krajeve intervala i korak: ";
        double xmin,xmax,deltax;
        cin>>xmin>>xmax>>deltax;
        for(;;) {
            try {
                cout<<"Unesite argument (ili \"kraj\" za kraj): ";
                double x;
                if(!(cin>>x)) break;
                cout<<"f("<<x<<") = "<<x*x+sin(x)<<" fapprox("<<x<<") = "<<LinearnaInterpolacija([](double x) {
                    return x*x+sin(x);
                },xmin,xmax,deltax)(x)<<endl;
            } catch(range_error e) {
                cout<<e.what()<<endl;
            } catch(domain_error a) {
                cout<<a.what();
            }
        }
    }
    return 0;
}
