/B2016/2017: Zadaća 3, Zadatak 1
//Autotestovi by Enil Pajic (epajic1@etf.unsa.ba)
#include <iostream>
#include <vector>
#include <utility>
#include <cmath>
#include <functional>
#define eps 0.000000000000001

using namespace std;


double wi(int i,vector<pair<double,double> > tacke,int d) {
        int poc=1,kr=tacke.size()-d;
        if(i-d>poc) poc=i-d;
        if(i<kr) kr=i;
        double suma=0, proizvod=1.;
        for(int k(poc);k<=kr;k++) {
            proizvod=1;
            for(int j(k);j<=k+d;j++) {
                if(i==j) continue;
                proizvod*= 1./(tacke[i-1].first-tacke[j-1].first);
            }
            proizvod*=pow(-1,k-1);
            suma+=proizvod;
        }
        return suma;
}

function<double(double)> BaricentricnaInterpolacija(vector<pair<double,double> > tacke, int d) {
    
    if(d<=0 || d>=tacke.size()) throw domain_error ("Nedozvoljen red");
    
    for(int i(0);i<tacke.size()-1;i++) {
        for(int j(i+1);j<tacke.size();j++) {
            if(abs(tacke[i].first-tacke[j].first)<eps) throw domain_error ("Neispravni cvorovi");
        }
    }
    vector<double> W;
    for(int i(1);i<=tacke.size();i++) {
        W.push_back(wi(i,tacke,d));
    }
    
    return [tacke,d,W](double x) {
        double brojnik=0, nazivnik=0;
        for(int i(1);i<=tacke.size();i++) {
            
            if(abs(x-tacke[i-1].first)<eps) return tacke[i-1].second;
            
            brojnik+=(W[i-1]*tacke[i-1].second)/(x-tacke[i-1].first);
            nazivnik+=W[i-1]/(x-tacke[i-1].first);
        }
        
        return brojnik/nazivnik;
    };
}

function<double(double)> BaricentricnaInterpolacija(double f(double),double Xmin,double Xmax,double Dx,double d) {
    if(Xmin>Xmax || Dx<=0) throw domain_error ("Nekorektni parametri");
    vector<pair<double,double> > tacke;
    while(Xmin<=Xmax){
        tacke.push_back({Xmin,f(Xmin)});
        Xmin+=Dx;                           //moguci granicni slucaj
    }
    return BaricentricnaInterpolacija(tacke,d);
}

int main ()
{
    cout<<"Odaberite opciju (1 - unos cvorova, 2 - aproksimacija): ";
    int opcija;
    cin>>opcija;
    if(opcija==1) {
        cout<< "Unesite broj cvorova: ";
        int brcvorova;
        cin>>brcvorova;
        cout<< "Unesite cvorove kao parove x y: ";
        int i=0;
        vector<pair<double,double> >cvorovi;
        while(i<brcvorova) {
            double prvi,drugi;
            cin>>prvi>>drugi;
            cvorovi.push_back(make_pair(prvi,drugi));
            i++;
        }
        cout<< "Unesite red interpolacije: ";
        int d; cin>>d;
        
        
        while(true) {
            char A='"';
            cout<< "Unesite argument (ili "<<A<<"kraj"<<A<<" za kraj): ";
            double arg;
            cin>>arg;
            if(!cin) break;
           try{
                auto fun = BaricentricnaInterpolacija(cvorovi,d);
                cout<< "f("<<arg<<") = "<<fun(arg)<<endl;
           }catch(domain_error izuzetak) { cout<<izuzetak.what(); return 0; }
        }
    }
    else if(opcija==2) {
        cout<< "Unesite krajeve intervala i korak: ";
        double a,b,c;
        cin>>a>>b>>c;
        cout<< "Unesite red interpolacije: ";
        double d; cin>>d;
        while(true) {
            char A='"';
            cout<<"Unesite argument (ili "<<A<<"kraj"<<A<<" za kraj): ";
            double arg;
            cin>>arg;
            if(!cin) break;
            try{
                auto fun = BaricentricnaInterpolacija([](double arg) { return arg*arg+sin(arg);},a,b,c,d);
                cout << "f("<<arg<<") = "<<arg*arg+sin(arg)<<" fapprox("<<arg<<") = "<<fun(arg)<<endl;
            }catch(domain_error izuzetak) { cout<<izuzetak.what(); return 0; }
        }
    }
	return 0;
}