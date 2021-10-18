/B2016/2017: Zadaća 3, Zadatak 1
//Autotestovi by Enil Pajic (epajic1@etf.unsa.ba)
#include <iostream>
#include<vector>
#include<utility>
#include<functional>
#include<cmath>
using namespace std;
vector<double> TezinskiKoef(vector<pair<double,double>> v, int d)
{   
    int n=v.size();
    double proizvod=1, suma=0;
    vector<double> v1;
    for(int i=1; i<=n; i++) {
        int min=i, max=1;
        if(min>(n-d)) min=n-d;
        if((i-d)>max) max=i-d;
        
        suma=0;
        for(int k=max; k<=min;k++){
            proizvod=1;
            for(int j=k;j<=k+d;j++){
                if(j!=i) proizvod*=1/(v[i-1].first - v[j-1].first);
                else if(i==j) continue;
            }
            suma+=(pow(-1,k+1))*proizvod;
        }
        v1.push_back(suma);
    }
    return v1;

}


function<double(double)> BaricentricnaInterpolacija(vector<pair<double,double>> v, int d)
{
    if(d<0 || d>=v.size()) throw domain_error("Nedozvoljen red");

    int brojac=0;
    for(int i=0; i<v.size(); i++) {
        for(int j=i+1; j<v.size(); j++) {
            if(v[i].first==v[j].first) brojac++;
        }
    }
    if(brojac!=0) throw domain_error("Neispravni cvorovi");
    
    vector<double> v1(TezinskiKoef(v,d));
    
    return [=](double x){
        double s1=0,s2=0;
        
        for(int i=1;i<=v.size();i++) {
            if(x==v[i-1].first) return v[i-1].second;
            s1+=(v1[i-1]*v[i-1].second)/(x-v[i-1].first);
            s2+=(v1[i-1])/(x-v[i-1].first);
            
            
        }
            return s1/s2;
    };
    
}
function<double(double)> BaricentricnaInterpolacija(double fun(double), double xmin, double xmax, double deltax, int d){
    if(xmin>xmax || deltax<=0) throw domain_error("Nekorektni parametri");
    vector<pair<double,double>> v;
    for(double i=xmin;i<=xmax;i+=deltax){
        v.push_back(make_pair(i,fun(i)));
    }
   
   return BaricentricnaInterpolacija(v, d);
    
}

double f(double x){
    return x*x+sin(x);
}


int main ()
{
    int n=0;
    cout<<"Odaberite opciju (1 - unos cvorova, 2 - aproksimacija): ";
    cin>>n;
    if(n==1){
        int m;
        cout<<"Unesite broj cvorova: ";
        cin>>m;
        cout<<"Unesite cvorove kao parove x y: ";
        vector<pair<double,double>> v;
        for(int i=0;i<m;i++){
            pair<double, double> par;
            cin>>par.first>>par.second;
            v.push_back(par);
        }
        int d;
        cout<<"Unesite red interpolacije: ";
        cin>>d;
        double br;
        for(;;){
            try{
                auto h(BaricentricnaInterpolacija(v,d));
            
            cout<<"Unesite argument (ili \"kraj\" za kraj): ";
            cin>> br;
            if(!cin) break;
            
            cout<<"f("<<br<<") = "<<h(br)<<endl;
        }
        catch(domain_error izuzetak){
            cout<<izuzetak.what();
            return 0;
        }
        }
        
        
    }
    if(n==2){
        cout<<"Unesite krajeve intervala i korak: ";
        double x1, x2, x3;
        cin>>x1>>x2>>x3;
        cout<<"Unesite red interpolacije: ";
        int d;
        cin>>d;
        for(;;){
            try{
            auto m(BaricentricnaInterpolacija(f,x1,x2,x3,d));
            cout<<"Unesite argument (ili \"kraj\" za kraj): ";
            double br;
            cin>>br;
            if(!cin) break;
            
            cout<<"f("<<br<<") = "<<br*br + sin(br)<<" fapprox("<<br<<") = "<<m(br)<<endl;
            }
            catch(domain_error izuzetak){ 
                cout<<izuzetak.what(); 
                return 0;}
        }
    }
    return 0;
}