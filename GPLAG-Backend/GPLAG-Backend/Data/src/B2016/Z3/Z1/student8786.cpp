/B2016/2017: Zadaća 3, Zadatak 1
//Autotestovi by Enil Pajic (epajic1@etf.unsa.ba)
#include <iostream>
#include <stdexcept>
#include <functional>
#include <vector>
#include <cmath>
using namespace std;

double omega(int i, int n, int d, vector<pair<double,double>> v)
{
    int z;
    if(i-d>1) z=i-d;
    else z=1;
    int a;
    if(n-d>i) a=i;
    else a=n-d;
    double suma=0;
    for(int k=z; k<=a; k++)
    {
        //double jedinica=pow(-1, k-1);
        double pr=1;
        for(int j=k; j<=k+d; j++)
            if(j!=i) pr*=1./(v[i-1].first-v[j-1].first);
        suma+=pr*pow(-1,k-1);
    }
    return suma;
}

function<double(double)>BaricentricnaInterpolacija(vector<pair<double,double>> v, int d)
{
    if(d<0 || d>v.size()) throw domain_error("Nedozvoljen red");
    for(int i=0; i<v.size()-1; i++)
    {
        for(int j=i+1; j<v.size(); j++)
        {
            if(v[i].first==v[j].first) throw domain_error("Neispravni cvorovi");
        }
    }
    double o1=omega(1,v.size(), d, v);
    double a=v[0].first, b=v[0].second;
    function<double(double)> f1=[o1, a, b](double x) { return (o1*b)/(x-a);};
    function<double(double)> f2=[o1,a](double x) { return o1/(x-a);};
    for(int i=2; i<=v.size(); i++)
    {
        a=v[i-1].first; b=v[i-1].second;
        double o=omega(i,v.size(), d, v);
        f1=[f1,o,a,b](double x){ return f1(x)+(o*b)/(x-a); };
        f2=[f2,o,a](double x){ return f2(x)+o/(x-a); };
    }
    f1=[f1,f2,v](double x) {
        for(int i=0; i<v.size(); i++) if(v[i].first==x ) return v[i].second;
        return f1(x)/f2(x); };
    return f1;
}

template<typename tf>
function<double(double)> BaricentricnaInterpolacija(tf f, double xmin, double xmax, double delta, int d)
{
    if(delta<=0 || xmin>xmax) throw domain_error("Nekorektni parametri");
    vector<pair<double,double>> v;
    while(xmin<=xmax)
    {
        v.push_back(make_pair(xmin,f(xmin)));
        xmin+=delta;
    }
    function<double(double)> f1=BaricentricnaInterpolacija(v,d);
    return f1;
}

int main ()
{
	int z=1;
	try{
	    cout<<"Odaberite opciju (1 - unos cvorova, 2 - aproksimacija): ";
	while(1)
	{
	    int n; cin>>n;
	    if(n==1)
	    {
	        cout<<"Unesite broj cvorova: ";
	        int a; cin>>a;
	        vector<pair<double,double>> v; v.resize(a);
	        cout<<"Unesite cvorove kao parove x y: ";
	        for(int i=0; i<v.size(); i++)
	        {
	            double b,c; cin>>b>>c; v[i]=make_pair(b,c);
	        }
	        cout<<"Unesite red interpolacije: ";
	        int d; cin>>d;
	        while(0==0)
	        {
	            cout<<"Unesite argument (ili "<<"\"kraj\""<<" za kraj): ";
	            double x; cin>>x;
	            if(!cin) { cin.ignore(100000, '\n'); cin.clear(); break; }
	            else
	            {
	                try
	                {
	                    auto f=BaricentricnaInterpolacija(v,d);
	                    cout<<"f("<<x<<") = "<<f(x)<<endl;
	                } 
	                catch(domain_error e) { cout<<e.what(); throw; }
	            }
	        }
	    }
	    else if(n==2)
	    {
	        cout<<"Unesite krajeve intervala i korak: ";
	        double mi, ma, del; cin>>mi>>ma>>del;
	        cout<<"Unesite red interpolacije: "; 
	        int d; cin>>d;
	        while(0==0)
	        {
	            cout<<"Unesite argument (ili "<<"\"kraj\""<<" za kraj): ";
	            double x; cin>>x;
	            if(!cin) { cin.ignore(100000, '\n'); cin.clear(); break; }
	            else
	            {
	                try
	                {
	                    auto f=BaricentricnaInterpolacija([](double x){return x*x+sin(x);},mi,ma,del,d);
	                    cout<<"f("<<x<<") = "<<x*x+sin(x)<<" fapprox("<<x<<") = "<<f(x)<<endl;
	                } catch(domain_error e) { cout<<e.what(); throw;}
	            }
	        }
	    }
	    else break;
	}
	return 0;
	} catch(...) {z++;}
}