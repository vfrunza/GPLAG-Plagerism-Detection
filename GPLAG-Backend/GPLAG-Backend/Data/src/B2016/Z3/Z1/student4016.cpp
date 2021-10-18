/B2016/2017: Zadaća 3, Zadatak 1
//Autotestovi by Enil Pajic (epajic1@etf.unsa.ba)
#include <iostream>
#include <utility>
#include <vector>
#include <stdexcept>
#include <cmath>
#include <functional>
#include <algorithm>
using namespace std;


function < double (double) > BaricentricnaInterpolacija ( vector< pair< double, double > >v, int d)
{
    for( int i=0; i<int(v.size()); i++)
{
    int br = count_if( v.begin(), v.end(), [v, i](pair< double, double> a)
    {
        return a.first==v[i].first;
    });
    if(br>1)
    throw domain_error("Nesipravni cvorovi");
}
if(d<0 || d>int(v.size()))
{
    throw domain_error("Nedozvoljen red");
}
std::vector<double> vec; vec.push_back(0);
for(int i=1;i<int(v.size())+1; i++)
{
    
    double a=0;
    for(int k = max(1,i-d);k<=min(i,int(v.size())-d); k++)
    {
        double g=1;
        for(int j=k; j<=k+d;j++) if(j!=i) g= g*1/(v[i-1].first-v[j-1].first);
        a=a+g*pow(-1,k-1);
    }
    vec.push_back(a);
    
}


return [v, d,vec](double promjenjiva)
{
    for(pair<double, double> par: v)
{
    if(par.first==promjenjiva)
    return par.second;
}

double br2(0); 
double x = 0;
for( int i=1; i<int(v.size())+1; i++)
{
    br2= br2+vec[i]*v[i-1].second/(promjenjiva-v[i-1].first);
}
for(int i=1; i<int(v.size())+1;i++)
{
    x=x+vec[i]/(promjenjiva-v[i-1].first);
}
return br2/x;
};
}

function <double (double)> BaricentricnaInterpolacija(double f(double), double poc, double kraj, double korak, int d)
{
    if(poc>kraj) throw domain_error ("Nekorektni parametri");
    else if(korak <=0) throw domain_error ("Nekorektni parametri");
    double drugipoc=poc;
    int brojac(0);
    while (drugipoc<= kraj)
    {
        drugipoc= drugipoc+korak;
        brojac++;
    }
    vector <pair <double, double> > v(brojac);
    for (int i=0; i<brojac; i++)
    {
        v[i].first =poc;
        v[i].second = f(poc);
        poc =poc +korak;
    }
    vector<double> vec; vec.push_back(0);
    for(int i=1;i<int(v.size())+1;i++)
    {
     double a=0;
     for(int k=max(1,i-d);k<=min(i,int(v.size())-d);k++)
     {
         double g=1;
         for(int j=k; j<=k+d; j++) if(j!=i) g=g*1/(v[i-1].first-v[j-1].first);
         a=a+g*pow(-1,k-1);
     }
     vec.push_back(a);
    }
    
    return [v, d,vec] (double promjenjiva)
    {
    for (pair<double, double> par: v)
    {
        if(par.first==promjenjiva) return par.second;
    }
    double br2(0),x(0);
    for (int i=1; i<int(v.size())+1; i++)
    {
        br2=br2+vec[i]*v[i-1].second/(promjenjiva-v[i-1].first);
    }
    for(int i=1; i<int(v.size())+1; i++)
    {
        x=x+vec[i]/(promjenjiva-v[i-1].first);
    }
    return br2/x;
};
}
double f(double prom)
{
    double vrijednost = pow(prom, 2)+sin(prom);
    return vrijednost;
}
int main ()
{
    int n;
    int  d;
    double prom;
    double poc, kraj, korak;
    vector <pair<double, double>> v;
    cout <<"Odaberite opciju (1 - unos cvorova, 2 - aproksimacija): ";
    int b;
    cin>>b;
    switch(b)
    {
        case 1:
        cout <<"Unesite broj cvorova: ";
        cin >>n;
        v.resize(n);
        cout <<"Unesite cvorove kao parove x y: ";
        for (int i=0; i<int(v.size()); i++)
        {
            int x, y;
            cin >>x>>y;
            v[i].first=x;
            v[i].second=y;
        }
        cout <<"Unesite red interpolacije: ";
        cin >>d;
        for (;;)
        {
            cout <<"Unesite argument (ili \"kraj\" za kraj): ";
            cin >>prom;
            if(!cin)
            {
                break;
            }
            else 
            {
                cout <<"f("<<prom<<") = "<<BaricentricnaInterpolacija(v, d)(prom)<<endl;
            }
        }
        break;
        case 2:
        cout <<"Unesite krajeve intervala i korak: ";
        cin >>poc;
        cin >>kraj;
        cin >>korak;
        cout <<"Unesite red interpolacije: ";
        cin >>d;
        for (;;){
            cout <<"Unesite argument (ili \"kraj\" za kraj): ";
            cin >>prom;
            double vrijednostFunkc=f(prom);
            if(!cin)
        {
            break;
        }
        else
        {
            cout <<"f("<<prom<<") = "<<vrijednostFunkc<<" fapprox("<<prom<<") = "<<BaricentricnaInterpolacija(f, poc, kraj, korak, d)(prom)<<endl;
        }
        }
        break;
    }
	return 0;
}