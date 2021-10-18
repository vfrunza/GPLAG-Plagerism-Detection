#include <iostream>
#include <functional>
#include <vector>
#include <utility>
#include <algorithm>
#include <cmath>
using namespace std;

bool funkcijaKriterija(pair<double,double> prvi,pair<double,double> drugi)
{
    return prvi.first<drugi.first;
}

function<double(double)> LinearnaInterpolacija(vector<pair<double,double>> &vektorParova)
{
    sort(vektorParova.begin(),vektorParova.end(),funkcijaKriterija);
    return [vektorParova](double x) {
        for(int i(0); i<vektorParova.size(); i++)
            if(count_if(vektorParova.begin(),vektorParova.end(),[=](pair<double,double> prvi) {
            return prvi.first==vektorParova[i].first;
            })>1)throw domain_error("Neispravni cvorovi");
        if(x<vektorParova[0].first || x>vektorParova[vektorParova.size()-1].first)throw range_error("Argument izvan opsega");
        if(x==vektorParova[vektorParova.size()-1].first)return vektorParova[vektorParova.size()-1].second;//specijalni slucaj
        pair<double,double> par {x,0};
        auto xiplus1(upper_bound(vektorParova.begin(),vektorParova.end(),par,funkcijaKriterija));
        auto xi(xiplus1-1);
        return (xi->second)+( ((xiplus1->second)-(xi->second))/((xiplus1->first)-(xi->first)) )*(x-(xi->first));
    };
}

double f(double x)
{
    return x*x+sin(x);
}

function<double(double)> LinearnaInterpolacija(double funkcija(double),double xmax,double xmin,double xdelta)
{
    if(xmin>xmax || xdelta<=0)throw domain_error("Nekorektni parametri!");
    if(xdelta>xmax)throw range_error("Argument izvan opsega");
    vector<pair<double,double>> vp;
    for(int i(0); xmin<=xmax; xmin+=i*xdelta) {
        vp.resize(i+1);
        vp[i].first=xmin;
        vp[i].second=funkcija(xmin);
        i++;
    }
    return LinearnaInterpolacija(vp);
}

int main ()
{
    cout<<"Odaberite opciju (1 - unos cvorova, 2 - aproksimacija): ";
    int izbor;
    cin>>izbor;
    switch(izbor) {
    case 1:
        {cout<<"Unesite broj cvorova: ";
        int brCvorova;
        cin>>brCvorova;
        vector<pair<double,double>> parParova(brCvorova);
        cout<<"Unesite cvorove kao parove x y: ";
        for(int i(0); i<brCvorova; i++) {
            cin>>parParova[i].first>>parParova[i].second;
        }
        for(;;) {
            cout<<"Unesite argument (ili \"kraj\" za kraj): ";
            double var;
            cin>>var;
            if(!cin)break;
            try {
                function<double(double)> funkcija(LinearnaInterpolacija(parParova));
                cout<<"f("<<var<<")"<<" = "<<funkcija(var)<<endl;
            } catch(domain_error a) {
                cout<<a.what()<<endl;
            } catch(range_error b) {
                cout<<b.what()<<endl;
            }
        }}
        break;
    case 2:
        cout<<"Unesite krajeve intervala i korak: ";
        double var1,var2,korak;
        cin>>var1>>var2>>korak;
        for(;;) {
            cout<<"Unesite argument (ili \"kraj\" za kraj): ";
            double var;
            cin>>var;
            if(!cin)break;
            try {
                function<double(double)> funkcija(LinearnaInterpolacija(f,var2,var1,korak));
                cout<<"f("<<var<<")"<<" = "<<f(var)<<" fapprox(" <<var<<") = "<<funkcija(var)<<endl;
            } catch(domain_error a) {
                cout<<a.what()<<endl;
            } catch(range_error b) {
                cout<<b.what()<<endl;
            }
        }
        break;
    }
    return 0;
}