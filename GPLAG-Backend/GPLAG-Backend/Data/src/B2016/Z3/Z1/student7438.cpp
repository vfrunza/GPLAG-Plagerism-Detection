/B2016/2017: Zadaća 3, Zadatak 1
//Autotestovi by Enil Pajic (epajic1@etf.unsa.ba)
#include <iostream>
#include <stdexcept>
#include <vector>
#include <algorithm>
#include <functional>
#include <cmath>
#include <set>
using std::cout;
using std::cin;
using std::vector;
using std::pair;
using std::function;
using std::set;
using std::max;
using std::min;
double fun(double x)
{
    return x*x+std::sin(x);
}
function<double(double)> BaricentricnaInterpolacija(vector<pair<double,double>> v,int d)
{
    if(d<0 || d>=v.size())
    throw std::domain_error("Nedozvoljen red");
    set<double> s;
    for(int i=0;i<v.size();i++)
    s.insert(v[i].first);
    if(v.size()!=s.size())
    throw std::domain_error("Neispravni cvorovi");
    vector<double> w(v.size());
    for(int i=1;i<=v.size();i++)
    {
        double suma(0);
        for(int j=max(1,i-d);j<=min(i,int(v.size())-d);j++)
        {
            double p(1);
            for(int k=j;k<=j+d;k++)
            {
                if(k-1!=i-1)
                p*=(1/(v[i-1].first-v[k-1].first));
            }
            p*=pow(-1,j-1);
            suma+=p;
        }
        w[i-1]=suma;
    }
    return [v,w] (double x)
    {
       for(int i=0;i<v.size();i++)
       {
           if(x==v[i].first)
           return v[i].second;
       }
       double suma1(0),suma2(0);
       for(int i=0;i<v.size();i++)
       {
           suma1+=((w[i]*v[i].second)/(x-v[i].first));
           suma2+=(w[i]/(x-v[i].first));
       }
       return (suma1/suma2);
    };
}
function<double(double)> BaricentricnaInterpolacija(function<double(double)> fun,double mn,double mx,double delta,int d)
{
    if((mn>mx) || delta<=0)
    throw std::domain_error("Nekorektni parametri");
    vector<pair<double,double>> v;
    while(mn<=mx)
    {
        v.push_back({mn,fun(mn)});
        mn+=delta;
    }
    try
    {
        return BaricentricnaInterpolacija(v,d);
    }
    catch(std::domain_error)
    {
        throw;
    }
}
int main ()
{
    cout<<"Odaberite opciju (1 - unos cvorova, 2 - aproksimacija): ";
    int a;
    cin>>a;
    if(a==1)
    {
        cout<<"Unesite broj cvorova: ";
        int b;
        cin>>b;
        vector<pair<double,double>> v;
        double c,e;
        cout<<"Unesite cvorove kao parove x y: ";
        for(int i=0;i<b;i++)
        {
            cin>>c>>e;
            v.push_back({c,e});
        }
        cout<<"Unesite red interpolacije: ";
        int d;
        cin>>d;
        for(;;)
        {
            cout<<"Unesite argument (ili \"kraj\" za kraj): ";
            double x;
            cin>>x;
            if(cin)
            {
                try
                {
                    cout<<"f("<<x<<") = "<<BaricentricnaInterpolacija(v,d)(x)<<"\n";
                }
                catch(std::domain_error izuzetak)
                {
                    cout<<izuzetak.what();
                    return 0;
                }
            }
            else
            return 0;
        }
    }
    else
    {
        cout<<"Unesite krajeve intervala i korak: ";
        double mn,mx,delta;
        cin>>mn>>mx>>delta;
        cout<<"Unesite red interpolacije: ";
        int d;
        cin>>d;
        for(;;)
        {
            cout<<"Unesite argument (ili \"kraj\" za kraj): ";
            double x;
            cin>>x;
            if(cin)
            {
                try
                {
                    cout<<"f("<<x<<") = "<<fun(x)<<" fapprox("<<x<<") = "<<BaricentricnaInterpolacija(fun,mn,mx,delta,d)(x)<<"\n";
                }
                catch(std::domain_error izuzetak)
                {
                    cout<<izuzetak.what();
                    return 0;
                }
            }
            else
            return 0;
        }
    }
	return 0;
}





