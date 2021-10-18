/B2017/2018: Zadaća 3, Zadatak 1
#include <iostream>
#include <functional>
#include <vector>
#include <algorithm>
#include <cmath>
#include <stdexcept>

using namespace std;

bool Sortiraj(pair<double,double> x,pair<double,double> y)
{
    return x.first<y.first;
}


function<double(double)> LinearnaInterpolacija(vector<pair<double,double>> Cvorovi)
{   
    
    sort(Cvorovi.begin(),Cvorovi.end(),Sortiraj);
    for(int i=0; i<Cvorovi.size()-1; i++)
        if(Cvorovi[i].first==Cvorovi[i+1].first) throw domain_error("Neispravni cvorovi");
    return [Cvorovi](double x)
    {   
        if(x<Cvorovi[0].first || x>Cvorovi[Cvorovi.size()-1].first) throw range_error("Argument izvan opsega");
        pair<double,double> pom(make_pair(x,x));
        
        
        //if(binary_search(Cvorovi.begin(),Cvorovi.end(),NadjiKoeficijentGornji)
      
       auto d=upper_bound(Cvorovi.begin(),Cvorovi.end(),pom);
       //d++; 
       auto g=lower_bound(d,Cvorovi.end(),pom);
       
       
       if(g==Cvorovi.end())  return Cvorovi[Cvorovi.size()-1].second;
       if(g->first==x)
                g++;
       else 
           d--;
       
       
       
     // cout<<d->first<<" "<<g->first<<endl;
      
     // if(g==Cvorovi.end()) g--;
     // if(d==Cvorovi.end()) d--;
      
          if(d->first<=x && g->first>x)
            return d->second+((g->second-d->second)/(g->first-d->first))*(x-d->first);
          
        return Cvorovi[Cvorovi.size()-1].second;
    };
}

function<double(double)> LinearnaInterpolacija(function<double(double)>f,double xmin,double xmax,double dx)
{
    vector<pair<double,double>> Cvorovi;
    if(xmin>xmax || dx<=0) throw domain_error("Nekorektni parametri");
    for(double i=xmin;i<xmax;i+=dx)
        Cvorovi.push_back(make_pair(i,f(i)));
     //  for(auto a:Cvorovi) cout<<a.first<<","<<a.second<<endl; 
    return LinearnaInterpolacija(Cvorovi);
}

int main ()
{    
    try{
        cout<<"Odaberite opciju (1 - unos cvorova, 2 - aproksimacija): ";
        int n;
        cin>>n;
        
        if(n==1)
        {
            cout<<"Unesite broj cvorova: ";
            int k;cin>>k;vector<pair<double,double>> Cvorovi;
            cout<<"Unesite cvorove kao parove x y: ";
            for(int i=0;i<k;i++)
            {
                double x,y;cin>>x>>y;
                Cvorovi.push_back(make_pair(x,y));
            }
            
            do
            {   
                
                double arg;
                function<double(double)>f=LinearnaInterpolacija(Cvorovi);
                cout<<"Unesite argument (ili \"kraj\" za kraj): ";
                cin>>arg;
                if(!cin) break;
                try{
                cout<<"f("<<arg<<") = "<<f(arg)<<endl;
                }
                catch(range_error e)
                {
                    cout<<e.what()<<endl;
                }
            }while(cin);
        }
        else if(n==2)
        {   
            
            cout<<"Unesite krajeve intervala i korak: ";
            double xmin,xmax,dx;
            cin>>xmin>>xmax>>dx;
            function<double(double)> f1=[](double x){return x*x+sin(x);};
            
            function<double(double)> f=LinearnaInterpolacija(f1,xmin,xmax,dx);
           
            do
            {
                double arg;
                cout<<"Unesite argument (ili \"kraj\" za kraj): ";
                cin>>arg;
                if(!cin) break;
                try{
                cout<<"f("<<arg<<") = "<<[](double x){return x*x+sin(x);}(arg)<<" fapprox("<<arg<<") = "<<f(arg)<<endl;
                }
                catch(range_error e)
                {
                cout<<e.what()<<endl;
                }    
            }while(cin);
            
            
            
        }
    }
    catch(domain_error e){
        cout<<e.what();
    }
    return 0;
}
