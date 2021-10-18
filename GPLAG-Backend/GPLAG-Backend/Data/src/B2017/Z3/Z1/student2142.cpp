/B2017/2018: Zadaća 3, Zadatak 1
#include <iostream>
#include <functional>
#include <algorithm>
#include <vector>
#include <cmath>
#include <iomanip>

using namespace std;



function<double(double)> LinearnaInterpolacija(vector<pair<double,double>> v)
{
    sort(v.begin(),v.end(),[](pair<double,double> x,pair<double,double> y){return x.first<y.first;});
    for(int i=0; i<v.size()-1; i++) 
          if(v.at(i).first==v.at(i+1).first)  throw domain_error("Neispravni cvorovi");
    return [v](double x)
    {
        //find_if (myvector.begin(), myvector.end(), IsOdd);
        //binary_search (v.begin(), v.end(), 6, myfunction)
        
        /*//find_if (myvector.begin(), myvector.end(), IsOdd);
        //binary_search (v.begin(), v.end(), 6, myfunction)
        
        pair<double,double>p(make_pair(x,x));
        
        pair<double,double> manji=v[v.size()-1];
        pair<double,double> veci=v[0];
        
          if(binary_search(v.begin(),v.end(),p,[&manji,&veci,x](pair<double,double> i,pair<double,double> j)
                                               {        cout<<i.first<<" "<<j.first<<endl;
                                                        
                                                        if( manji.first>=x) manji=j;
                                                        if(veci.first<=x)   veci=i;
                                    
                                                         return (manji.first<x && veci.first>x);
                                                   
                                               }));
         */
         if(x<v.at(0).first || x>v.at(v.size()-1).first)throw range_error("Argument izvan opsega");
        /*for(int i=0;i<v.size()-1;i++)
        {
            if(v[i].first<=x && v[i+1].first>x)
            {   
                return v[i].second+((v[i+1].second-v[i].second)/(v[i+1].first-v[i].first))*(x-v[i].first);
            }
        }*/
        pair<double,double> par(x,x);
        auto a=upper_bound(v.begin(),v.end(),par);
        auto b=lower_bound(a,v.end(),par);
        
        if(b==v.end() || a==v.end()) return  v[v.size()-1].second;
       
        if(a->first==x)
        	b++;
        else 
          a--;
        
       	if(a->first<=x && b->first>x)
        		return a->second+((b->second-a->second)/(b->first-a->first))*(x-a->first);
        return v[v.size()-1].second;
    };
}

function<double(double)> LinearnaInterpolacija(function<double(double)> fun,double xmin,double xmax,double dx)
{   
    vector<pair<double,double>> v;
    int k=0;
    if(xmin>xmax || dx<0) throw domain_error("Nekorektni parametri");
    while(xmin<=xmax)
    {   
        v.push_back(make_pair(xmin,fun(xmin)));
        xmin+=dx;
        
    }
    return LinearnaInterpolacija(v);
}

int main ()
{   
    int n;
    try{
    cout<<"Odaberite opciju (1 - unos cvorova, 2 - aproksimacija): ";
	cin>>n;
	
	switch(n)
	{   
	    case 1:
	    {
	        cout<<"Unesite broj cvorova: ";
	        int br;cin>>br;
	        cout<<"Unesite cvorove kao parove x y: ";
	        vector<pair<double,double>>v(br);
	        for(int i=0;i<v.size();i++)
	        {   
	            double p,q;
	            cin>>p>>q;
	            v[i]=make_pair(p,q);
	        }
	        
	        
	        do
	        {   
	            auto f=LinearnaInterpolacija(v);
	            cout<<"Unesite argument (ili \"kraj\" za kraj): ";
	            double b;
	            cin>>b;
	            if(!cin) break;
	            try{
	            cout<<"f("<<b<<") = "<<f(b)<<endl;
	            }
	            catch(range_error e)
	            {
	            	cout<<e.what()<<endl;
	            }
	        }while(cin);
	        
	        break;
	   }     
	   case 2:
	   {
	        double a,b,c;
	        cout<<"Unesite krajeve intervala i korak: ";
	        cin>>a>>b>>c;
	        auto fun=[](double x){return x*x+sin(x);};
	        auto f=LinearnaInterpolacija(fun,a,b,c);
	        do
	        {   
	            cout<<"Unesite argument (ili \"kraj\" za kraj): ";
	            double b;
	            cin>>b;
	            if(!cin) break;
	            try{
	            cout<<"f("<<b<<") = "<<fun(b)<<" fapprox("<<b<<") = "<<f(b)<<endl;
	    		 }
	            catch(range_error e)
	            {
	            	cout<<e.what()<<endl;
	            }
	        }while(cin);
	         break;
	   }
	}
    	
    }
    catch(domain_error e) { cout<<e.what();}
    catch(range_error e) {cout<<e.what();}
	return 0;
}
