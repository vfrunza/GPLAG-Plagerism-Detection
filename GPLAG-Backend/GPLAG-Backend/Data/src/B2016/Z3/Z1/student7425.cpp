/B2016/2017: Zadaća 3, Zadatak 1
//Autotestovi by Enil Pajic (epajic1@etf.unsa.ba)
#include <iostream>
#include <vector>
#include <functional>
#include <cmath>
#include <stdexcept>
using namespace std;

void test(int d,vector<pair<double,double>> v)
{
    if(d<0) throw domain_error("Nedozvoljen red");
    if(d>v.size()) throw domain_error("Nedozvoljen red");
}

double w(int d, int i, vector<pair<double,double>> cvorovi, int n)
{
    int m=max(1,i-d);
    int m1=min(i, n-d);
    double o=0, pr=1;
    for(int k=m; k<=m1; k++)
    {
        pr=1;
        for(int j=k; j<=k+d; j++)
        {
            if(i==j) continue;
            else pr*=1./(cvorovi[i-1].first-cvorovi[j-1].first);
        }
        o+=pow(-1,k-1)*pr;
    }
    return o;
}

void test(vector<pair<double,double>> v)
{
    for(int i=0; i<v.size()-1; i++)
        for(int j=i+1; j<v.size(); j++)
            if(v[i].first==v[j].first) throw domain_error("Neispravni cvorovi");
}

template<typename tip>
function<double(double)> BaricentricnaInterpolacija(tip g, double mali, double veliki, double del, int d)
{
    if(del<=0) throw domain_error("Nekorektni parametri");
    vector<pair<double,double>> v;
    if(veliki<mali) throw domain_error("Nekorektni parametri");
    while(veliki>=mali)
    {
        auto p=make_pair(mali,g(mali));
        v.push_back(p);
        mali+=del;
    }
    function<double(double)> gore,dolje;
    for(int i=1; i<=v.size(); i++)
    {
        if(i-1!=0)
        {
            double drugi=v[i-1].second;
            double om=w(d,i,v,v.size());
            double prvi=v[i-1].first;
            dolje=[dolje,om,prvi](double x) { return om/(x-prvi)+dolje(x);};
            gore=[gore,drugi,om,prvi](double x) { return om*drugi/(x-prvi)+gore(x); };
        }
        else
        {
            double drugi=v[i-1].second;
            double om=w(d,i,v,v.size());
            double prvi=v[i-1].first;
            dolje=[om,prvi](double x) { return om/(x-prvi);};
            gore=[drugi,om,prvi](double x) { return om*drugi/(x-prvi); };
        }
    }
    return [gore,v,dolje](double x) {
        double a=9999999;
        for(int i=0; i<v.size(); i++)
            if(v[i].first==x) a=v[i].second;
        if(a==9999999) return gore(x)/dolje(x);
        else return a;
    };
}

function<double(double)> BaricentricnaInterpolacija(vector<pair<double,double>> v, int d)
{
    test(d,v);
    test(v);
    function<double(double)> gore,dolje;
    for(int i=1; i<=v.size(); i++)
    {
        if(i-1!=0)
        {
            double drugi=v[i-1].second;
            double om=w(d,i,v,v.size());
            double prvi=v[i-1].first;
            dolje=[dolje,om,prvi](double x) { return om/(x-prvi)+dolje(x);};
            gore=[gore,drugi,om,prvi](double x) { return om*drugi/(x-prvi)+gore(x); };
        }
        else
        {
            double drugi=v[i-1].second;
            double om=w(d,i,v,v.size());
            double prvi=v[i-1].first;
            dolje=[om,prvi](double x) { return om/(x-prvi);};
            gore=[drugi,om,prvi](double x) { return om*drugi/(x-prvi); };
        }
    }
    return [gore,v,dolje](double x) {
        double a=9999999;
        for(int i=0; i<v.size(); i++)
            if(v[i].first==x) a=v[i].second;
        if(a==9999999) return gore(x)/dolje(x);
        else return a;
    };
}

int main ()
{
	
	cout<<"Odaberite opciju (1 - unos cvorova, 2 - aproksimacija): ";
	int opcija; cin>>opcija;
	try
	{
	    switch(opcija)
	    {
	        case 1:
	            {int cv;
	            cout<<"Unesite broj cvorova: ";
	            cin>>cv;
	            cout<<"Unesite cvorove kao parove x y: ";
	            vector<pair<double,double>> v;
	            for(int i=0; i<cv; i++)
	            {
	                double a,b; cin>>a>>b; v.push_back(make_pair(a,b));
	            }
	            cout<<"Unesite red interpolacije: ";
	            int d; 
	            cin>>d;
	            while(1)
	            {
	               double x;
	               cout<<"Unesite argument (ili "<<"\"kraj\""<<" za kraj): ";
	               cin>>x;
	               if(cin)
	                try{
	                    cout<<"f("<<x<<") = "<<BaricentricnaInterpolacija(v,d)(x)<<endl;
	                } catch(domain_error r) { throw domain_error(r.what()); }
	                else break;
	            }
	            break; }
	        case 2:
	           { cout<<"Unesite krajeve intervala i korak: ";
	            double mali,veliki,del;
	            cin>>mali>>veliki>>del;
	            cout<<"Unesite red interpolacije: ";
	            int d;
	            cin>>d;
	            while(1)
	            {
	                double x;
	                cout<<"Unesite argument (ili "<<"\"kraj\""<<" za kraj): ";
	                cin>>x;
	                if(cin)
	                    try
	                    {
	                        cout<<"f("<<x<<") = "<<x*x+sin(x)<<" fapprox("<<x<<") = "<<BaricentricnaInterpolacija([](double x){return x*x+sin(x);},mali,veliki,del,d)(x)<<endl;
	                    } catch(domain_error r) { throw domain_error(r.what()); }
	               else break;
	            }
	            break; }
	       default: opcija+=10;
	    }
	} catch(domain_error c) { cout<<c.what();}
	return 0;
}