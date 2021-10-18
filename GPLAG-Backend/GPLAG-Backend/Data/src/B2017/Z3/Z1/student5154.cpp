/B2017/2018: Zadaća 3, Zadatak 1
#include <iostream>
#include <vector>
#include <stdexcept>
#include <utility>
#include <functional>
#include <algorithm>
#include <cmath>

using namespace std;

function<double(double)> LinearnaInterpolacija(std::vector<pair<double,double>> cvor) {

    sort(cvor.begin(),cvor.end(), [](pair<double,double> a, pair<double,double> b) {
        return a.first<b.first;
    });
    
    return [cvor](double x) {
        double f(0);
        if(x<cvor[0].first or x>cvor[cvor.size()-1].first) throw range_error("Argument izvan opsega");
        for(int i(0);i<cvor.size()-1;i++) {
            if(x==cvor[cvor.size()-1].first) {
                return cvor[cvor.size()-1].second;
            }
            if(x>=cvor[i].first and x<cvor[i+1].first) {
                double xi=cvor[i].first;
                double yi=cvor[i].second;
                double xii=cvor[i+1].first;
                double yii=cvor[i+1].second;
                f=yi+((yii-yi)/(xii-xi))*(x-xi);
                return f;
            }  
        }
        return f;
    };
}

function<double(double)> LinearnaInterpolacija(double f(double), double xmin, double xmax, double xx) {
    if(xmin>xmax or xx<=0) throw domain_error("Nekorektni parametri");
    std::vector<pair<double,double>> vp;
    int j(0);
    for(double i(xmin);i<=xmax;i=i+j*xx) {
        vp.push_back(make_pair(i,f(i)));
        j++;
    }
    return [f,vp,xx] (double x) {
        double fun(0);
        if(x<vp[0].first or x>vp[vp.size()-1].first) throw range_error("Argument izvan opsega");
        if(x==vp[vp.size()-1].first) {
            return vp[vp.size()-1].second;
        }
        for(int i(0);i<vp.size();i++) {
            if(i+1<=vp.size()-1){
            auto it(lower_bound(vp.begin(),vp.end(),x, [] (const pair<double,double> &a, const double &b) {
                return a.first<b;
            }));
            double xi=it->first;
            double yi=f(xi);
            double xii=it->first-xx;
            double yii=f(xii);
            fun=yi+((yii-yi)/(xii-xi))*(x-xi);
            return fun;
            }
        }
        return fun;
    };
}

int main ()
{
    int op;
    cout<<"Odaberite opciju (1 - unos cvorova, 2 - aproksimacija): ";
    cin>>op;
    if(op==1) {
        int bc;
        cout<<"Unesite broj cvorova: ";
        cin>>bc;
        cin.ignore(1000,'\n');
        std::vector<pair<double,double>> vp;
        pair<double,double> p;
        double x, y;
        try {
        cout<<"Unesite cvorove kao parove x y: ";
        for(int i(0);i<bc;i++) {
            cin>>x>>y;
            p=make_pair(x,y);
            vp.push_back(p);
        }
        for(int i(0);i<vp.size();i++) {
        double prvi(vp[i].first);
        for(int j(0);j<vp.size();j++) {
            if(i!=j) {
            if(prvi==vp[j].first) throw domain_error("Neispravni cvorovi");   
            }
        }
        }
        double xx;
        for(;;) {
            cout<<"Unesite argument (ili \"kraj\" za kraj): ";
            cin>>xx;
            if(!cin) return 0;
                auto f(LinearnaInterpolacija(vp));
                cout<<"f("<<xx<<") = "<<f(xx)<<endl;
        }
        }
        catch (domain_error a) {
            cout<<a.what()<<endl;
        }
        catch (range_error b) {
            cout<<b.what()<<endl;
        }
        
    }
    else if(op==2) {
        double xmin,xmax,xx;
        cout<<"Unesite krajeve intervala i korak: ";
        cin>>xmin>>xmax>>xx;
        cin.ignore(1000,'\n');
        double x;
        for(;;) {
             cout<<"Unesite argument (ili \"kraj\" za kraj): ";
             cin>>x;
             if(!cin) return 0;
             try {
                 auto f(LinearnaInterpolacija([](double x) {return x*x+sin(x);},xmin,xmax,xx));
                 cout<<"f("<<x<<") = "<<x*x+sin(x)<<" fapprox("<<x<<") = "<<f(x)<<endl;
             }
             catch (domain_error a) {
                cout<<a.what()<<endl;
             }
             catch (range_error b) {
                cout<<b.what()<<endl;
             }
        }
    }
	return 0;
}
