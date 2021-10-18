/B2017/2018: Zadaća 3, Zadatak 1
#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#include <cmath>
#include <functional>
#include <iterator>
#include <cmath>
using namespace std;

double fja(double x)
{
    return x*x+sin(x);
}
function<double(double)>LinearnaInterpolacija(vector<pair<double,double>> v)
{

    sort(v.begin(), v.end());
    for(int i=0; i<v.size(); i++) {
        if(i==v.size()-1) break;
        if(v.at(i).first==v.at(i+1).first) throw domain_error("Neispravni cvorovi");
    }
    return [v] (double x) {
        pair<double,double> par(x,0);
        auto it=lower_bound(v.begin(), v.end(), par);
        pair<double,double>prvi(*it);
        it--;
        pair<double,double>drugi(*it);
        if(x<v[0].first|| x>v[v.size()-1].first) throw range_error("Argument izvan opsega");
        x=prvi.second+((drugi.second-prvi.second)/(drugi.first-prvi.first))*(x-prvi.first);
        return x;
    };
}
function<double(double)>LinearnaInterpolacija(double(double), double xmin, double xmax, double deltax)
{
    vector<pair<double, double>> v1 {};
    pair<double,double> nekipar(0,0);
    for(int i=0;;) {
        if(nekipar.first>xmax) break;
        nekipar=make_pair(xmin+i*deltax, fja(xmin+i*deltax));
        v1.push_back(nekipar);
        i++;
    }
    return [v1] (double x) {

        pair<double,double> par(x,0);
        auto it=lower_bound(v1.begin(), v1.end(), par);
        pair<double,double>prvi(*it);
        it--;
        pair<double,double>drugi(*it);
        x=prvi.second+((drugi.second-prvi.second)/(drugi.first-prvi.first))*(x-prvi.first);
        return x;
    };
}
int main ()
{
        vector<pair<double, double>> vektor;
        cout<<"Odaberite opciju (1 - unos cvorova, 2 - aproksimacija): ";
        int opcija;
        cin>>opcija;
        if(opcija==1) {
            cout<<"Unesite broj cvorova: ";
            int broj_cvorova;
            cin>>broj_cvorova;
            double x,y;
            cout<<"Unesite cvorove kao parove x y: ";
            for(int i=0; i<broj_cvorova; i++) {
                cin>>x;
                cin>>y;
                vektor.push_back(make_pair(x,y));
            }
            try {
                auto f(LinearnaInterpolacija(vektor));
            } catch(domain_error izuzetak) {
                cout<<izuzetak.what();
                return 0;
            }
            double arg;
            for(;;) {
                cout<<"Unesite argument (ili \"kraj\" za kraj): ";
                cin>>arg;
                if(cin) {
                        
                    auto f(LinearnaInterpolacija(vektor));
                    cout<<"f("<<arg<<") = "<<f(arg)<<endl;
                    cout<<endl;
                } else {
                    break;
                }
            }
        }
        double kraj1,kraj2, korak;
        if(opcija==2) {
            cout<<"Unesite krajeve intervala i korak: ";
            cin>>kraj1;
            cin>>kraj2;
            cin>>korak;
            double arg;
            while(cin) {
                cout<<"Unesite argument (ili \"kraj\" za kraj): ";
                do {
                cin>>arg;
                if(!cin) {
           cin.ignore(10000, '\n');
                break;
                }
                if(arg<kraj1 || arg>=kraj2) {
                    cout<<"Argument izvan opsega"<<endl;
                    break;
                }
                    auto f(LinearnaInterpolacija(vektor));
                    auto fapprox(LinearnaInterpolacija(fja,kraj1,kraj2,korak));
                    cout<<"f("<<arg<<") = "<<fja(arg)<<" fapprox("<<arg<<") = "<<fapprox(arg);
                }while(arg<kraj1 || arg>kraj2);
                cout<<endl;
            }
        }
        return 0;
    }
