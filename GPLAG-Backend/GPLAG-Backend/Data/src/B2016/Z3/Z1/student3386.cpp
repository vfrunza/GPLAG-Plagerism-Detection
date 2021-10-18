/B2016/2017: Zadaća 3, Zadatak 1
//Autotestovi by Enil Pajic (epajic1@etf.unsa.ba)
#include <iostream>
#include <vector>
#include <utility>
#include <functional>
#include <stdexcept>
#include <algorithm>
#include <cmath>

using std::cin;
using std::cout;
using std::function;
using std::pair;
using std::vector;

function<double(double)> BaricentricnaInterpolacija(const vector<pair<double,double>> &v,int d)
{
    if(d<0 or d>=v.size())
        throw std::domain_error("Nedozvoljen red");
    for(int i=0;i<v.size();i++)
        for(int j=i+1;j<v.size();j++)
            if(v[i].first==v[j].first)
                throw std::domain_error("Neispravni cvorovi");
    vector<double> dab;
    for(int i=1;i<=v.size();i++)
    {
        int pocetak=std::max(1,i-d);
        int kraj=std::min(i,int(v.size())-d);
        double suma(0);
        for(int k=pocetak;k<=kraj;k++)
        {
            double broj(1);
            for(int j=1;j<=k-1;j++)
                broj*=(-1);
            double broj2(1);
            for(int j=k;j<=k+d;j++)
            {
                if(j==i)
                    continue;
                broj2*=1./(v[i-1].first-v[j-1].first);
            }
            suma+=broj*broj2;
        }
        dab.push_back(suma);
    }
    return [dab,v](double x)
    {
        double suma1(0),suma2(0);
        for(int i=1;i<=v.size();i++)
        {
            if(x==v[i-1].first)
                return v[i-1].second;
            double pomoc=dab[i-1]/(x-v[i-1].first);
            suma1+=pomoc*v[i-1].second;
            suma2+=pomoc;
        }
        return suma1/suma2;
    };
}
double Probna(double x)
{
    return x*x+sin(x);
}
function<double(double)> BaricentricnaInterpolacija(function<double(double)> f,double x_min,double x_max,double x_delta,int d)
{
    if(x_min>x_max or x_delta<=0)
        throw std::domain_error("Nekorektni parametri");
    vector<pair<double,double>> v;
    for(double i=x_min;i<=x_max;i+=x_delta)
        v.push_back({i,f(i)});
    return BaricentricnaInterpolacija(v,d);
}
int main ()
{
    int opcija;
    cout<<"Odaberite opciju (1 - unos cvorova, 2 - aproksimacija): ";
    cin>>opcija;
    try{
    if(opcija==1)
    {
        cout<<"Unesite broj cvorova: ";
        int n;
        cin>>n;
        cout<<"Unesite cvorove kao parove x y: ";
        vector<pair<double,double>> v(n);
        for(int i=0;i<v.size();i++)
            cin>>v[i].first>>v[i].second;
        cout<<"Unesite red interpolacije: ";
        int d;
        cin>>d;
        auto f(BaricentricnaInterpolacija(v,d));
        for(;;)
        {
            cout<<"Unesite argument (ili \"kraj\" za kraj): ";
            double arg;
            cin>>arg;
            if(!cin)
                break;
            cout<<"f("<<arg<<") = "<<f(arg)<<"\n";
        }
    }
    else if(opcija==2)
    {
        cout<<"Unesite krajeve intervala i korak: ";
        double x_min,x_max,x_delta;
        cin>>x_min>>x_max>>x_delta;
        cout<<"Unesite red interpolacije: ";
        int d;
        cin>>d;
        auto fapprox(BaricentricnaInterpolacija(Probna,x_min,x_max,x_delta,d));
        for(;;)
        {
            cout<<"Unesite argument (ili \"kraj\" za kraj): ";
            double arg;    
            cin>>arg;
            if(!cin)
                break;
            cout<<"f("<<arg<<") = "<<Probna(arg)<<" fapprox("<<arg<<") = "<<fapprox(arg)<<"\n";
        }
    }
    }
    catch(std::domain_error e)
    {
        cout<<e.what();
    }
    catch(std::bad_alloc)
    {
        cout<<"Problemi sa memorijom!\n";
    }
	return 0;
}