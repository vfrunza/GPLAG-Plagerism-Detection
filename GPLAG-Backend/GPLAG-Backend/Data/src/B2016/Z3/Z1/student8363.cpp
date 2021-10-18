/B2016/2017: Zadaća 3, Zadatak 1
//Autotestovi by Enil Pajic (epajic1@etf.unsa.ba)
#include <iostream>
#include <utility>
#include <cmath>
#include <vector>
#include <functional>
#include <exception>

using std::function;
using std::vector;
using std::pair;
using std::cout;
using std::cin;
using std::endl;
using std::string;

int max(int a,int b){
    if(a>b)return a;
    return b;
}
int min(int a,int b){
    if(a<b)return a;
    return b;
}
int _1na(int k){
    if(!k)return 1;
    return -1 * _1na(k-1);
}
function<double(double)> BaricentricnaInterpolacija(vector<pair<double,double>> cvorovi, int d){
    const int n = cvorovi.size();
    if(d>=n || d<0)
        throw std::domain_error("Nedozvoljen red");
    for (int i = 0; i < n; i++)
        for(int j=i+1; j < n; j++)
            if(cvorovi[i].first==cvorovi[j].first)
                throw std::domain_error("Neispravni cvorovi");
    vector<double> w(n,double(0));
    for (int i = 0; i < n; i++) {
        double suma = 0;
        for(int k=max(0,i-d); k<=min(i,n-d-1);k++){
            double produkt= 1;
            for(int j=k; j<=k+d; j++){
                if(j!=i){
                    produkt*=1/(cvorovi[i].first-cvorovi[j].first);
                }
            }
            suma+=_1na(k) * produkt;
        }
        w[i]=suma;
    }
    return [cvorovi,w](double x){
        double s1=0,s2=0;
        for(int i=0; i<cvorovi.size(); i++){
            if(x==cvorovi[i].first)return cvorovi[i].second;
            s1+=w[i]*cvorovi[i].second/(x-cvorovi[i].first);
            s2+=w[i]/(x-cvorovi[i].first);
        }
        return s1/s2;
    };
}
function<double(double)> BaricentricnaInterpolacija(double (*fun)(double),double a,double b,double d,int red_interpolacije){
    //ne moze step bit nula !(d=0)
    if(b<a || d<=0)
        throw std::domain_error("Nekorektni paramateri");
    vector<pair<double,double>> cvorovi;
    for (double i = a; i <= b; i+=d) {
        cvorovi.push_back({i,fun(i)});
    }
    return BaricentricnaInterpolacija(cvorovi,red_interpolacije);
}
bool neispravanUnos(string a){
    int broj_tacaka = 0;
    int broj_minusa = 0;
    for (int i = 0; i < a.size(); i++) {
        if((a[i]<'0' || a[i]>'9' || broj_tacaka>1)&&a[i]!='-' && a[i]!='.')return true;
        if(a[i]=='.')broj_tacaka++;
        if(a[i]=='-')broj_minusa++;
    }
    if(broj_tacaka>1 || broj_minusa>1)return true;
    return false;
}
int main ()
{
    vector<pair<double,double>> a ;
        a.resize(0);
        int r;
        int n;
        cout<<"Odaberite opciju (1 - unos cvorova, 2 - aproksimacija): ";
        cin>>n;
        try{
            function<double(double)> fun;
            double (*f)(double) = [](double a){return a*a+std::sin(a);};
            if(n==1){
                int d;
                cout<<"Unesite broj cvorova: ";
                cin>>d;
                cout<<"Unesite cvorove kao parove x y: ";
                double c,b;
                for (int i = 0; i < d; i++) {
                    cin>>c;
                    cin>>b;
                    a.push_back({c,b});
                }
                cout<<"Unesite red interpolacije: ";
                cin>>r;
                fun = BaricentricnaInterpolacija(a,r);
            }
            else if(n==2){
                cout<<"Unesite krajeve intervala i korak: ";
                double q,w,e;
                cin>>q>>w>>e;
                cout<<"Unesite red interpolacije: ";
                cin>>r;
                fun = BaricentricnaInterpolacija(f,q,w,e,r);
            }
            else return 0;
            while (true) {
                string s;
                cout<<"Unesite argument (ili \"kraj\" za kraj):";
                cin>>s;
                if(s=="kraj")return 0;
                if(neispravanUnos(s))return 0;
                std::string::size_type sz;
                double arg = stod(s,&sz);
                if(n==2)cout<<" f("<<arg<<") = "<<f(arg);
                cout<<" f";
                if(n==2)cout<<"approx";
                cout<<"("<<arg<<") = "<<fun(arg)<<endl;
            }
        }catch(std::domain_error e){
            cout<<e.what();
        }
	return 0;
}