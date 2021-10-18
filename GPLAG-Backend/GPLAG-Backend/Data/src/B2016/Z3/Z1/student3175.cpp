/B2016/2017: Zadaća 3, Zadatak 1
//Autotestovi by Enil Pajic (epajic1@etf.unsa.ba)
#include <iostream>
#include <functional>
#include <vector>
#include <cmath>
#include <stdexcept>
#include <algorithm>
using namespace std;

double wi(vector<pair<double,double>> x, int d, int i, int n)
{
    double w=0;
    for(int k=max(1,i-d); k<=min(i, n-d); k++)
    {
        double p=1;
        for(int j=k; j<=k+d; j++)
        {
            if(j==i) continue;
            else p*=1./(x[i-1].first-x[j-1].first);
        }
        double kec=pow(-1,k-1);
        w=w+p*kec;
    }
    return w;
}

bool test(int d, int n)
{
    return (d>n||d<0); 
}

bool okej(vector<pair<double,double>> x)
{
    for(int i=0; i<x.size()-1; i++)
        for(int j=i+1; j<x.size(); j++)
            if(x[i].first==x[j].first) return false;
    return true;
}

function<double(double)> BaricentricnaInterpolacija(vector<pair<double,double>> x, int d)
{
    if(!okej(x)) throw domain_error("Neispravni cvorovi");
    if(test(d,x.size())) throw domain_error("Nedozvoljen red");
    function<double(double)> f,pom;
    for(int i=0; i<x.size(); i++)
    {
        auto w=wi(x,d,i+1,x.size());
        auto p=x[i].first, dr=x[i].second;
        if(i==0)
        {
            f=[p,dr,w](double a) { return (w*dr)/(a-p);};
            pom=[p,w](double a) { return w/(a-p); };
        }
        else
        {
            f=[f,p,dr,w](double a) { return f(a)+(w*dr)/(a-p);};
            pom=[pom,p,w](double a) { return pom(a)+w/(a-p); };
        }
    }
    return [x,f,pom](double a)
    {
        for(int i=0; i<x.size(); i++)
            if(a==x[i].first) return x[i].second;
        return f(a)/pom(a);
    };
    
}

template<typename funtip>
function<double(double)> BaricentricnaInterpolacija(funtip fu, double mini, double maks, double D, int d)
{
    if(mini>maks) throw domain_error("Nekorektni parametri");
    if(D<=0) throw domain_error("Nekorektni parametri");
    vector<pair<double,double>> x;
    for(;;)
    {
        if(mini>maks) break;
        pair<double,double> pa=make_pair(mini, fu(mini));
        x.push_back(pa);
        mini+=D;
    }
    function<double(double)> f,pom;
    for(int i=0; i<x.size(); i++)
    {
        auto w=wi(x,d,i+1,x.size());
        auto p=x[i].first, dr=x[i].second;
        if(i==0)
        {
            f=[p,dr,w](double a) { return (w*dr)/(a-p);};
            pom=[p,w](double a) { return w/(a-p); };
        }
        else
        {
            f=[f,p,dr,w](double a) { return f(a)+(w*dr)/(a-p);};
            pom=[pom,p,w](double a) { return pom(a)+w/(a-p); };
        }
    }
    return [x,f,pom](double a)
    {
        for(int i=0; i<x.size(); i++)
            if(a==x[i].first) return x[i].second;
        return f(a)/pom(a);
    };
}

int main ()
{
	cout<<"Odaberite opciju (1 - unos cvorova, 2 - aproksimacija): ";
	int a;
	cin>>a;
	if(a==1)
	{
	    cout<<"Unesite broj cvorova: ";
	    int n;
	    cin>>n;
	    cout<<"Unesite cvorove kao parove x y: ";
	    vector<pair<double,double>> x;
	    for(int i=0; i<n; i++)
	    {
	        double p, dr; cin>>p>>dr;
	        pair<double,double> pa=make_pair(p,dr);
	        x.push_back(pa);
	    }
	    int d;
	    cout<<"Unesite red interpolacije: ";
	    cin>>d;
	    for(;;)
	    {
	        double b;
	        cout<<"Unesite argument (ili "<<"\"kraj\""<<" za kraj): ";
	        cin>>b;
	        if(!cin) break;
	        else
	        {
	            try
	            {
	                cout<<"f("<<b<<") = "<<BaricentricnaInterpolacija(x,d)(b)<<endl;
	            } catch(domain_error e) {  cout<<e.what();}
	        }
	    }
	    
	}
	else
	{
	    double mini, maks, D;
	    cout<<"Unesite krajeve intervala i korak: ";
	    cin>>mini>>maks>>D;
	    int d;
	    cout<<"Unesite red interpolacije: ";
	    cin>>d;
	    for(;;)
	    {
	        double b;
	        cout<<"Unesite argument (ili "<<"\"kraj\""<<" za kraj): ";
	        cin>>b;
	        if(!cin) break;
	        else
	        {
	            try
	            {
	                cout<<"f("<<b<<") = "<<b*b+sin(b)<<" fapprox("<<b<<") = "<<BaricentricnaInterpolacija([](double x){return x*x+sin(x);},mini,maks,D,d)(b)<<endl;
	            }
	            catch(domain_error e) { cout<<e.what();
	        }
	        }
	    }
	}
	return 0;
}