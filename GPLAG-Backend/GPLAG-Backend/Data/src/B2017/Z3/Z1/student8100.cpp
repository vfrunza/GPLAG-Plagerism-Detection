#include <iostream>
#include <vector>
#include <utility>
#include <functional>
#include <algorithm>
#include <stdexcept>
#include <cmath>

using namespace std;

function<double(double)> LinearnaInterpolacija(vector<pair<double, double>> v)
{
    if(v.size()==0)
        return [](double x) {
        throw range_error("Argument izvan opsega");
        return x;
    };

    sort(v.begin(), v.end());
    for(auto it=v.begin(); it!=v.end(); it++)
        for(auto it2=it+1; it2!=v.end(); it2++)
            if(it->first==it2->first)
                throw domain_error("Neispravni cvorovi");


    return [=](double x) {
        if(x<v.begin()->first || x>(v.end()-1)->first) throw range_error("Argument izvan opsega");
        if(v.size()==1) return v.begin()->second;
        if(x==v.begin()->first) return v.begin()->second;
        auto it=lower_bound(v.begin(), v.end(), pair<double, double>(x, 0));
        auto it2=it;
        if(it!=v.begin())
            it2--;
        return (it2->second+((it->second-it2->second)/(it->first-it2->first))*(x-it2->first));
    };
}

function<double(double)> LinearnaInterpolacija(function<double(double)> f, double xmin, double xmax, double deltax)
{
    if(xmin>xmax || deltax<=0)
        throw domain_error("Nekorektni parametri");

    vector<pair<double, double>> v;
    while(xmin<=xmax) {
        auto p=make_pair(xmin, f(xmin));
        v.push_back(p);
        xmin=xmin+deltax;
    }
    auto fun=LinearnaInterpolacija(v);
    return fun;
}

int main ()
{
    int broj;

    cout<<"Odaberite opciju (1 - unos cvorova, 2 - aproksimacija): ";
    cin>>broj;
    if(broj==1) {
        vector<pair<double, double>> v;
        int broj_cvorova;
        cout<<"Unesite broj cvorova: ";
        cin>>broj_cvorova;
        cout<<"Unesite cvorove kao parove x y: ";
        for(int i=0; i<broj_cvorova; i++) {
            double a, b;
            cin>>a>>b;
            v.push_back(make_pair(a, b));
        }
        double argument;
        try {
            auto f=LinearnaInterpolacija(v);
            cout<<"Unesite argument (ili \"kraj\" za kraj): ";
            while(cin>>argument) {
                try {
                    f(argument);
                } catch(range_error e) {
                    cout<<e.what();
                    cout<<"\nUnesite argument (ili \"kraj\" za kraj): ";
                    continue;
                }
                cout<<"f("<<argument<<") = "<<f(argument);
                cout<<"\nUnesite argument (ili \"kraj\" za kraj): ";
            }
        } catch(domain_error e) {
            cout<<e.what();
            return 2;
        }
    } else if(broj==2) {
        double xmin, xmax, deltax, noviarg;
        cout<<"Unesite krajeve intervala i korak: ";
        cin>>xmin>>xmax>>deltax;
        try {
            auto f=LinearnaInterpolacija([](double x) {
                return x*x+sin(x);
            }, xmin, xmax, deltax);
            cout<<"Unesite argument (ili \"kraj\" za kraj): ";
            while(cin>>noviarg) {
                try {
                    f(noviarg);
                } catch(range_error &e) {
                    cout<<e.what();
                    cout<<"\nUnesite argument (ili \"kraj\" za kraj): ";
                    continue;
                }
                cout<<"f("<<noviarg<<") = "<<noviarg*noviarg+sin(noviarg)<<" fapprox("<<noviarg<<") = "<<f(noviarg);
                cout<<"\nUnesite argument (ili \"kraj\" za kraj): ";
            }
        } catch(domain_error &e) {
            cout<<e.what();
            return 1;
        }
    }
    return 0;
}
