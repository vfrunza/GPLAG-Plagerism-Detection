/B2016/2017: Zadaća 3, Zadatak 1
//Autotestovi by Enil Pajic (epajic1@etf.unsa.ba)
#include <iostream>
#include <functional>
#include <vector>
#include <cmath>
#include <stdexcept>

using namespace std;

double xsinx (double x) {return x * x + sin(x);}

double DablWe(vector<pair<double,double>> v,int d,int indeks)
{
    double suma=0;
    int donja=1;
    int gornja=indeks;
    
    if(v.size()-d<indeks) gornja=v.size()-d;
    if(indeks-d>1) donja=indeks-d;
    
    for(int k=donja;k<=gornja;k++)
    {
        int a=pow(-1,k-1);
        double proizvod=1;
        for(int j=k;j<=k+d;j++)
            if(j!=indeks) proizvod*=(double)1/(v[indeks-1].first-v[j-1].first);
            
        suma+=a*proizvod;
    }
    return suma;
}


function<double(double)> BaricentricnaInterpolacija(vector<pair<double,double>> v,int d)
{
   if(d<0 || d>v.size()) throw domain_error("Nedozvoljen red");
   for(int i=0;i<v.size();i++)
   {
       for(int j=i+1;j<v.size()-1;j++)
        if(v[i].first==v[j].first) throw domain_error("Neispravni cvorovi");
   }
   
   
   function<double(double)> f1=[](double x){return 0;};
   function<double(double)> f2=[](double x){return 0;};
   
   for(int i=0;i<v.size();i++)
   {  
       double w=DablWe(v,d,i+1);
       f1=[f1,w,v,i](double x){ return f1(x)+(w*v[i].second)/(x-v[i].first); }; 
       f2=[f2,w,v,i](double x){ return f2(x)+w/(x-v[i].first);};

   }
    
   return [f1,f2,v](double x){
       for(int i=0;i<v.size();i++)
       {
           if(x-v[i].first==0)
            return v[i].second;
           
       }     
       
       return f1(x)/f2(x);};
}
template <typename t>
function<double(double)> BaricentricnaInterpolacija(t f,double xmin,double xmax,double delta,int d)
{   
    if(xmin>xmax || delta<=0) throw domain_error("Nekorektni parametri");
    vector<pair<double,double>> v;

    for(int i=0;xmin+i*delta<=xmax;i++){
        v.push_back(make_pair(xmin+i*delta,f(xmin+i*delta)));
    }

    return BaricentricnaInterpolacija(v,d);
}


int main ()
{   
    try{
    int n;
    while(1)
    {
        cout<<"Odaberite opciju (1 - unos cvorova, 2 - aproksimacija): ";
        cin>>n;
    
    
            
        if(n==1)
        {   
            int br;
            cout<<"Unesite broj cvorova: ";
            cin>>br;
            vector<pair<double,double>> v(br);
            cout<<"Unesite cvorove kao parove x y: "; 
            for(int i=0;i<br;i++)
                cin>>v[i].first>>v[i].second;
            
            int r;
            cout<<"Unesite red interpolacije: ";
            cin>>r;
            auto f=BaricentricnaInterpolacija(v,r);
            cout<<"Unesite argument (ili \"kraj\" za kraj): ";
            double arg;
            cin>>arg;
            while(cin)
            {
               cout<<"f("<<arg<<") = "<<f(arg)<<endl;
               cout<<"Unesite argument (ili \"kraj\" za kraj): ";
               cin>>arg;
            }
        
        }
        else if(n==2)
        {
            double xmin,xmax;double delta;
            cout<<"Unesite krajeve intervala i korak: ";
            cin>>xmin>>xmax>>delta;
            int d;
            cout<<"Unesite red interpolacije: ";
            cin>>d;
            
            
            auto f1=BaricentricnaInterpolacija(xsinx,xmin,xmax,delta,d);
            cout<<"Unesite argument (ili \"kraj\" za kraj): ";
            double arg;
            cin>>arg;
            while(cin)
            {
               cout<<"f("<<arg<<") = "<<xsinx(arg);
               cout<<" fapprox("<<arg<<") = "<<f1(arg)<<endl;
               
               cout<<"Unesite argument (ili \"kraj\" za kraj): ";
               cin>>arg;
            }
        }
        break;
    }  
    }catch(domain_error e){cout<<e.what();}
    
    
    
    return 0;
}