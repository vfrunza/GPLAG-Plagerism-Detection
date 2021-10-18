/B2017/2018: Zadaća 3, Zadatak 1
#include <iostream>
#include <utility>
#include <cmath>
#include <algorithm>
#include <stdexcept>
#include <cstdlib>
#include <vector>
#include <functional>


constexpr double EPSILON = 0.00000000001;

using namespace std;

bool kriterij( const pair<double,double> &p1, const pair<double,double> &p2)
{
    return p1.first<p2.first;
}

bool kriterij2(double x,const pair<double,double> &p1){
    return p1.first>x;
}



function<double(double)> LinearnaInterpolacija (vector<pair<double,double>> parovi)
{
    sort(parovi.begin(),parovi.end(),kriterij);
    for(int i=0; i<parovi.size()-1; i++)
        for(int j=i+1; j<parovi.size(); j++)
            if(parovi[i].first==parovi[j].first) throw domain_error("Neispravni cvorovi\n");


    
    return [parovi](double x) {
        if(x<parovi[0].first || x>parovi[int(parovi.size())-1].first) throw range_error("Argument izvan opsega\n");

        if(x==parovi.at(int(parovi.size())-1).first) return parovi.at(int(parovi.size())-1).second;

        int indeks = upper_bound(parovi.begin(),parovi.end(),x,kriterij2)-parovi.begin()-1;

        double razl(0);
        razl=parovi[indeks+1].second-parovi[indeks].second;
        razl/=parovi[indeks+1].first-parovi[indeks].first;
        double faktor(0);
        faktor=x-parovi[indeks].first;
        faktor*=razl;
        return parovi[indeks].second+faktor;
    };
}



function<double(double)> LinearnaInterpolacija(function<double(double)> f, double xmin, double xmax, double deltax)
{
    if(xmin>xmax || deltax<=0) throw domain_error("Nekorektni parametri");
    vector<pair<double,double>> cvorovi;
    double x(xmin);
    while(x<xmax) {
        cvorovi.push_back({x,f(x)});
        x+=deltax;
    }
    return LinearnaInterpolacija(cvorovi);
}




int main ()
{
    int opcija(-1),brc(0);
    double x,y,argument;
    vector<pair<double,double>> cvorovi;
    double p,k,delta;
    cout<<"Odaberite opciju (1 - unos cvorova, 2 - aproksimacija): ";
    cin>>opcija;
    if (opcija==1) {
        cout<<"Unesite broj cvorova: ";
        cin>> brc;
        cout<<"Unesite cvorove kao parove x y: ";
        for(int i=0; i<brc; i++) {
            cin>>x>>y;
            cvorovi.push_back({x,y});
        }
    } else {
        cout<<"Unesite krajeve intervala i korak: ";
        cin>>p>>k>>delta;
    }
    for(;;) {
        //cout<<"Unesite argument (ili \"kraj\" za kraj): ";
        //if(!(cin>>argument)) return 0;
        try {

            switch(opcija) {
                case 1: {
                    auto funkcija(LinearnaInterpolacija(cvorovi));
                    cout<<"Unesite argument (ili \"kraj\" za kraj): ";
                    if(!(cin>>argument)) return 0;
                    cout<<"f("<<argument<<") = "<<funkcija(argument)<<endl;
                    break;
    
                }
                case 2: {
                    auto funkcija(LinearnaInterpolacija([](double x) {
                        return x*x+sin(x);
                    },p,k,delta));
                    cout<<"Unesite argument (ili \"kraj\" za kraj): ";
                    if(!(cin>>argument)) return 0;
                    cout<<"f("<<argument<<") = "<<argument*argument+sin(argument)<<" "<< "fapprox("<<argument<<") = "<<funkcija(argument)<<endl;
                    break;
    
                }

            }

        } catch(domain_error e) {
            cout<<e.what();
            return 0;
        } catch(range_error e) {
            cout<<e.what();
        }

    }
    return 0;
}
