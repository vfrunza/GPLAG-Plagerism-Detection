#include <iostream>
#include <vector>
#include <stdexcept>
#include <algorithm>
#include <functional>
#include <cmath>
using namespace std;

bool cmp(int br, pair<int, int> const& p)
{
    return (p.first < br);
}

bool cmp1(const pair<double,double> &l,const pair<double,double> &r)
{

    return l.first<r.first;
}
bool cmp2(const pair<double,double> &l,const pair<double,double> &r)
{

    return l.first>r.first;
}
template<typename t>
void uslov(double x, t &prvi){
    if(prvi->first!=x) prvi--;
}

double fun(const vector<pair<double,double>> &v, double a){
    return a;
}

double funkcija(const vector<pair<double,double>> &koef, double x)
{
    auto prvi=koef.begin();
    prvi=lower_bound(koef.begin(), koef.end(), x,[](std::pair<double, double> const & x, double br){ return x.first < br; });
    uslov(x,prvi);
    auto drugi=koef.begin();
    drugi=upper_bound(koef.begin(), koef.end(),pair<double,double> (x,0),[](pair<double,double> l, pair<double,double> br){return l.first<br.first;});
    return drugi->second + (x-drugi->first)*( (prvi->second-drugi->second)/(prvi->first-drugi->first) );
}

function<double(double)>LinearnaInterpolacija(vector<pair<double,double>> v)
{
    sort(v.begin(), v.end(), [](pair<double,double> a, pair<double,double> b){ return a.first<b.first; });
    for(int i=0; i<v.size()-1; i++) {
        if(v.at(i).first==v.at(i+1).first) throw domain_error("Neispravni cvorovi");
    }
    
    function<double(double)> linterp;
    linterp=[v](double x){
        if(x<v.at(0).first || x>v.at(v.size()-1).first) throw range_error("Argument izvan opsega");
        if(x==v.at(v.size()-1).first) return fun(v,v.at(v.size()-1).second);
        else return funkcija(v,x);
    };
    return linterp;
}

void unos1(double &x){
    cout<<"Unesite argument (ili \"kraj\" za kraj): ";
               
                    cin>>x;
}

function<double(double)>LinearnaInterpolacija( double f(double), double manji, double veci, double D){
    if(D<=0 || manji>veci) throw domain_error("Nekorektni parametri");
    vector<pair<double,double>> v;
    do{
        pair<double,double> sawe;
        v.push_back(make_pair(manji, f(manji)));
        sawe.first=manji;
        sawe.second=veci;
        manji+=D;
    } while(manji<veci);
    auto linterp= LinearnaInterpolacija(v);
    return linterp;
}



int main ()
{


    try{
            int br;
            cout<<"Odaberite opciju (1 - unos cvorova, 2 - aproksimacija): ";
            cin>>br;
            if(br==1)
            {
                int n;
                cout<<"Unesite broj cvorova: "; cin>>n;
                cout<<"Unesite cvorove kao parove x y: ";
                vector<pair<double,double>> koef(n);
                for(int i=0; i<n; i++) {
                    cin>>koef.at(i).first; cin>>koef.at(i).second;
                }
                auto inter=LinearnaInterpolacija(koef);
                do {
                    cout<<"Unesite argument (ili \"kraj\" za kraj): ";
                    double x;
                    cin>>x;
                    if(cin){
                        try{
                            cout<<"f("<<x<<") = "<<inter(x)<<endl; 
                        } catch(range_error r) { cout<<r.what()<<endl; }
                    }
                    else break;
                }while(1);
            }
            else 
            {
                cout<<"Unesite krajeve intervala i korak: ";
                double m1,m2,del;
                cin>>m1>>m2>>del;
                auto inter=LinearnaInterpolacija([](double x){return sin(x)+x*x;},m1,m2,del);
                double x;
                do {
                    unos1(x);
                    if(cin){
                        try{
                            cout<<"f("<<x<<") = "<<sin(x)+x*x<<" fapprox("<<x<<") = "<<inter(x)<<endl; 
                        } catch(range_error r) { cout<<r.what()<<endl; }
                    }
                    else break;
                }while(1);
            }
    }
    catch(domain_error d) { cout<<d.what()<<endl;} 
    catch(...) {}
	return 0;
}
