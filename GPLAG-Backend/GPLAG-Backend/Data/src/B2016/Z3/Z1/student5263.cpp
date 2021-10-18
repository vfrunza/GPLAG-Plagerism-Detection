/B2016/2017: Zadaća 3, Zadatak 1
//Autotestovi by Enil Pajic (epajic1@etf.unsa.ba)
#include <iostream>
#include <functional>
#include <utility>
#include <vector>
#include <cmath>
#include <iomanip>
#include <stdexcept>
using std::cout;
using std::cin;
using std::endl;
using std::vector;
using std::pair;
using std::make_pair;
using std::pow;
using std::domain_error;
bool DaLiSuJednaki (double x, double y, double eps= 1e-10){
    return std::fabs(x-y) <=eps * (std::fabs(x) + std:: fabs(y));
}
std::function<double(double)> BaricentricnaInterpolacija (vector<pair<double,double>> parovi, double d){
    if (d<1 || d>parovi.size()) throw domain_error("Nedozvoljen red");
    for(int i=0;i<parovi.size()-1;i++){
        for(int j=i+1;j<parovi.size();j++){
            if(DaLiSuJednaki(parovi[i].first,parovi[j].first)) throw domain_error ("Neispravni cvorovi");
        }
    }
    vector<double> w;
    for(int i=0;i<parovi.size();i++){
        int poc(1);
        double clankoeficijent(0);
        if(1<(i+1-d)) poc=(i+1-d);
        poc--;
        int kraj(parovi.size()-d);
        if (i+1<(parovi.size()-d)) kraj=i+1;
        kraj--;
        for(int j=poc;j<=kraj;j++){
            double pr(1);
            double stepenminusa(pow(-1,j-1));
            for(int k=j;k<=(j+d);k++){
                if(k!=i) pr*=(1./(parovi[i].first-parovi[k].first));
            }
            clankoeficijent+=stepenminusa*pr;
        }w.push_back(clankoeficijent);
    }
    return [parovi,w] (double x){
        double sumabrojnik(0),sumanazivnik(0),suma(0);
        for(int i=1;i<=parovi.size();i++){
            if (DaLiSuJednaki(x,parovi[i-1].first)) return parovi[i-1].second;
            else{
            sumabrojnik+=(double(w[i-1]*parovi[i-1].second)/(x-parovi[i-1].first));
            sumanazivnik+=(double(w[i-1])/(x-parovi[i-1].first));
            }
        }
        suma=double(sumabrojnik/sumanazivnik);
        return suma;
    };
}
std::function<double(double)> BaricentricnaInterpolacija (double f(double),double xmin,double xmax,double deltax, double d){
    if(xmin>xmax || d<1) throw domain_error("Nekorektni parametri");
    vector<pair<double,double>> parovi;
    while(xmin<=xmax){
        parovi.push_back(make_pair(xmin,f(xmin)));
        xmin+=deltax;
    }
    return BaricentricnaInterpolacija(parovi,d);
}
double f (double x){
    return x*x+sin(x);
}
int main ()
{
    cout<<"Odaberite opciju (1 - unos cvorova, 2 - aproksimacija): ";
    int opcija;
    cin>>opcija;
    try{
        if (opcija==1){
            cout<<"Unesite broj cvorova: ";
            int n;
            cin>>n;
            cout<<"Unesite cvorove kao parove x y: ";
            vector<pair<double,double>> parovi (n);
            for(int i=0;i<n;i++){
                double x,y;
                cin>>x>>y;
                parovi[i]=make_pair(x, y);
            }
            cout<<"Unesite red interpolacije: ";
            double d;
            cin>>d;
            auto g(BaricentricnaInterpolacija(parovi,d));
            for(;;){
                cout<<"Unesite argument (ili \"kraj\" za kraj): ";
                double x;
                cin>>x;
                if (!cin) break;
                cout<<"f("<<x<<") = "<<g(x)<<endl;
            }
        }
        if (opcija==2){
            cout<<"Unesite krajeve intervala i korak: ";
            double xmin,xmax,deltax;
            cin>>xmin>>xmax>>deltax;
            cout<<"Unesite red interpolacije: ";
            double d;
            cin>>d;
            auto g(BaricentricnaInterpolacija(f,xmin,xmax,deltax,d));
            for(;;){
                cout<<"Unesite argument (ili \"kraj\" za kraj): ";
                double x;
                cin>>x;
                if (!cin) break;
                cout<<"f("<<x<<") = "<<f(x)<<" fapprox("<<x<<") = "<<g(x)<<endl;
            }
        }
    }
    catch(domain_error izuzetak){
        cout<<izuzetak.what();
    }
	return 0;
}