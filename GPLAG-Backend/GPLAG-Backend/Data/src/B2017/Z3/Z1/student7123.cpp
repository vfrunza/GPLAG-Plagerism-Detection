/B2017/2018: Zadaća 3, Zadatak 1
#include <iostream>
#include <vector>
#include <stdexcept>
#include <functional>
#include <algorithm>
#include <cmath>
#include <string>
using namespace std;
typedef pair<double,double> p;


double pomocna(double x, const vector<p> &k_interpl){
    p pom(x,0);
    auto k1=lower_bound(k_interpl.begin(), k_interpl.end(), x,[](std::pair<double, double> const & x, double br){ return x.first < br; });
    if(k1->first!=x) k1--;
    auto k2=upper_bound(k_interpl.begin(), k_interpl.end(),pom,[](p l, p br){return l.first<br.first;});
    return k2->second + (x-k2->first)*( (k1->second-k2->second)/(k1->first-k2->first) );
}


function<double(double)> LinearnaInterpolacija(vector<p> k_interpl)
{
    sort(k_interpl.begin(),k_interpl.end(),[](p a, p b){return a.first<b.first;});
    for(int i=0; i<k_interpl.size()-1; i++)
        if(k_interpl.at(i).first==k_interpl.at(i+1).first) throw domain_error("Neispravni cvorovi");
    auto y= [k_interpl](double x)
    {
        if(x==k_interpl.at(k_interpl.size()-1).first) return k_interpl.at(k_interpl.size()-1).second;
        else if(x<k_interpl.at(0).first || x>k_interpl.at(k_interpl.size()-1).first) throw range_error("Argument izvan opsega");
        else if(x!=k_interpl.at(k_interpl.size()-1).first)
        {
            return pomocna(x,k_interpl);
        }
    };
    return y;
}

void clev(int &n){
    try{
        cout<<"Unesite broj cvorova: ";
            cin>>n;
            cout<<"Unesite cvorove kao parove x y: ";
            vector<pair<double,double>> k_interpl(n);
            for(int i=0; i<n; i++){
                cin>>k_interpl.at(i).first; cin>>k_interpl.at(i).second;
            }
            auto f=LinearnaInterpolacija(k_interpl);
            for(;;){
                cout<<"Unesite argument (ili \"kraj\" za kraj): ";
                double x;
                cin>>x;
                if(cin){
                    try{
                        cout<<"f("<<x<<") = "<<f(x)<<endl; 
                    } catch(range_error er) {cout<<er.what()<<endl;}
                }
                else break;
            }
        
    }
    catch(domain_error er) {throw er;}
}

bool eh(double a, double b, double c){
    if(a>b) return false;
    if(c<0) return false;
    return true;
}

function<double(double)> LinearnaInterpolacija(double f(double), double xmin, double xmax, double dx)
{
    if(eh(xmin,xmax,dx)){
        vector<p> k_interpl;
        while(10==10)
        {
            if(xmin>xmax) break;
            k_interpl.push_back(make_pair(xmin,f(xmin)));
            xmin+=dx;
        }
        auto y= LinearnaInterpolacija(k_interpl);
        return y;
    }
    throw domain_error("Nekorektni parametri");
}



int main ()
{
    int n;
    try{
        cout<<"Odaberite opciju (1 - unos cvorova, 2 - aproksimacija): ";
        cin>>n;
        if(n==1)
        {
            clev(n);
        }
        if(n==2)
        {
            cout<<"Unesite krajeve intervala i korak: ";
            double x,y,z;
            cin>>x>>y;
            cin>>z;
            auto f=LinearnaInterpolacija([](double x){return sin(x)+x*x;},x,y,z);
            for(;;)
            {
                cout<<"Unesite argument (ili \"kraj\" za kraj): ";
                         cin>>x;
                         if(cin){
                         try{
                          cout<<"f("<<x<<") = "<<x*x+sin(x)<<" fapprox("<<x<<") = "<<f(x);
                          cout<<endl; 
                         }catch(range_error er) { cout<<er.what()<<endl; }
                         }
                         else {break;}
            }
        }
    } 
    catch(domain_error er) {cout<<er.what();}
	return 0;
}
