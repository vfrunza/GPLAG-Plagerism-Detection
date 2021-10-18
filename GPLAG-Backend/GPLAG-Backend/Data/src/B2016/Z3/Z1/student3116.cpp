/B2016/2017: Zadaća 3, Zadatak 1
//Autotestovi by Enil Pajic (epajic1@etf.unsa.ba)
#include <iostream>
#include <functional>
#include <cmath>
#include <vector>
#include <stdexcept>

using namespace std;


double Koeficijent(vector<pair<double,double>> v,int d,int i)
{
    double suma=0;
    pair<int,int>granice=make_pair(1,i);
    
    if(i-d>granice.first) granice.first=i-d;
    if(v.size()-d<granice.second) granice.second=v.size()-d;
    
    for(int j=granice.first;j<=granice.second;j++)
    {
        double pro(1);int k=j;
            while(k<=j+d){
                if(k!=i) pro*=1./(v[i-1].first-v[k-1].first);
                k++;
            }
        suma+=pow(-1,j-1)*pro;
    }
    return suma; 
}

function<double(double)> f1(double kof,pair<double,double>v)
{
    return [kof,v](double x){return (kof*v.second)/(x-v.first);};
}

function<double(double)> f2(double kof,pair<double,double>v)
{
    return [kof,v](double x){return kof/(x-v.first);};
}

function<double(double)> BaricentricnaInterpolacija(vector<pair<double,double>>v,int d)
{       
        double eps=0.000000001;
        if(d>v.size()) throw domain_error("Nedozvoljen red");
             
        function<double(double)> a=[](double x){return 0;};
        function<double(double)> b=[](double x){return 0;};
        for(int i=1;i<=v.size();i++)
        {
            double kof=Koeficijent(v,d,i);
            a=[a,kof,v,i](double x) {return a(x)+f1(kof,v[i-1])(x);};
            b=[b,kof,v,i](double x) {return b(x)+f2(kof,v[i-1])(x);};
        }
        
        return [a,b,v,eps](double x){
            
            for(int i=0;i<v.size();i++)
            {
                if(fabs(x-v[i].first)<eps) return v[i].second;
            }
            
            return a(x)/b(x);
        };
}

vector<pair<double,double>> DajParove(double f(double),double &xmin,double xmax,double deltaX,vector<pair<double,double>> v)
{  
    
    if(xmin<=xmax)
    {
        v.push_back(make_pair(xmin,f(xmin)));
        xmin+=deltaX;
        v=DajParove(f,xmin,xmax,deltaX,v);
    }
    return v;
}

function<double(double)> BaricentricnaInterpolacija(double f(double),double xmin,double xmax,double deltaX,int d)
{   
    if(xmin>xmax || deltaX<=0) throw domain_error("Nekorektni parametri");
    vector<pair<double,double>> v;
    v=DajParove(f,xmin,xmax,deltaX,v);
    return BaricentricnaInterpolacija(v,d);
}

int main ()
{     
        cout<<"Odaberite opciju (1 - unos cvorova, 2 - aproksimacija): ";
        int opcija;
        cin>>opcija;
        try{
        switch (opcija)
        {
        
            case 1:{
                cout<<"Unesite broj cvorova: ";
                int br;cin>>br;
                cout<<"Unesite cvorove kao parove x y: ";
                vector<pair<double,double>> v(br);
                for(int i=0;i<br;i++)
                    cin>>v[i].first>>v[i].second;
                cout<<"Unesite red interpolacije: ";
                int d;cin>>d;
                auto f=BaricentricnaInterpolacija(v,d);
                do
                {   
                    cout<<"Unesite argument (ili \"kraj\" za kraj): ";
                    double arg;
                    cin>>arg;
                    if(!cin) break;
                    cout<<"f("<<arg<<") = "<<f(arg)<<endl; 
                }while (cin);
                break;
            }
            case 2:{
                cout<<"Unesite krajeve intervala i korak: ";
                double xmin,xmax,DeltaX;
                cin>>xmin>>xmax>>DeltaX;
                cout<<"Unesite red interpolacije: ";
                int d;cin>>d;
                auto f=[](double x){return x*x+sin(x);};       
                auto f1=BaricentricnaInterpolacija(f,xmin,xmax,DeltaX,d);
                do
                {
                    cout<<"Unesite argument (ili \"kraj\" za kraj): ";
                    double arg;
                    cin>>arg;
                    if(!cin) break;
                    cout<<"f("<<arg<<") = "<<f(arg); 
                    cout<<" fapprox("<<arg<<") = "<<f1(arg)<<endl;    
                }while(cin);
                break;
            }
        
        }
        }catch(domain_error e){cout<<e.what();}
     
	
	return 0;
}