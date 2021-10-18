/B2016/2017: Zadaća 3, Zadatak 1
//Autotestovi by Enil Pajic (epajic1@etf.unsa.ba)
#include <iostream>
#include <utility>
#include <vector>
#include <stdexcept>
#include <cmath>
#include <functional>
using namespace std;

double f(double x){ return x*x+sin(x); }

double Wi( vector <pair<double,double>> tacke, int i, int d ){
    double suma{0};
    int n{(int)tacke.size()};
    for(int k{max(1,i-d)}; k<=min(i,n-d); k++){
        double proizvod{1};
        for(int j{k}; j<=k+d; j++){
            if(j==i) continue;
            proizvod*=1/(tacke[i-1].first - tacke[j-1].first);
        }
        suma+=pow(-1,k-1)*proizvod;
    }
    return suma;
}

function <double(double)> BaricentricnaInterpolacija(vector<pair<double, double>> tacke, int d){
    int n{(int)tacke.size()};
    if(d>n || d<0) throw domain_error("Nedozvoljen red");
    for(int i{0}; i<n-1; i++){
        for(int j{i+1}; j<n; j++){
            if(tacke[i].first==tacke[j].first) throw domain_error("Neispravni cvorovi");
        }
    }
    vector<double> W(n+1);
    for(int i{1}; i<=n; i++) W[i] = Wi(tacke, i, d);
    
 
    return [=](double x){
        double brojnik{0},nazivnik{0};
        for (int i{0}; i<n; i++){
        if(x==tacke[i].first) return tacke[i].second;
    }
        for(int i{1}; i<=n; i++){
            
           
            brojnik+=W[i]*tacke[i-1].second/(x-tacke[i-1].first);
            nazivnik+=W[i]/(x-tacke[i-1].first);
            
             //
            //cout <<endl<<"Za i: "<<i<<" brojnik = "<<brojnik<<" i nazivnik = "<<nazivnik<<" a Wi = "<<W[i];
            
            //
        }
        return brojnik/nazivnik;
    };
}

function<double(double)> BaricentricnaInterpolacija( function <double (double)> f, double xMin, double xMax, double xDelta, int d ){
    if(xMin>xMax || xDelta <= 0) throw domain_error("Nekorektni parametri");
    std::vector<pair<double,double>> tacke ;
     
    while(xMin<=xMax){
        tacke.push_back({xMin, f(xMin)});
        xMin+=xDelta;
    }
    return BaricentricnaInterpolacija(tacke,d);
}

int main (){
    cout << "Odaberite opciju (1 - unos cvorova, 2 - aproksimacija): ";
    int odabir;
    cin>>odabir;
    if(odabir == 1){
        cout<<"Unesite broj cvorova: ";
        int n;
        cin >>n;
        vector<pair<double,double>> tacke(n);
        cout<<"Unesite cvorove kao parove x y: ";
        for(int i{0}; i<n; i++){
            int x,y;
            cin>>x>>y;
            tacke[i].first=x; tacke[i].second=y;
        }
        cout<<"Unesite red interpolacije: ";
        int d;
        cin>>d;
        double argument;
        while(cin){
            cout<<"Unesite argument (ili \"kraj\" za kraj): ";
            cin>>argument;
            if(!cin)break;
            cout<<"f("<<argument<<") = "<<BaricentricnaInterpolacija(tacke,d)(argument)<<endl;
        }
    } else if(odabir == 2){
        cout<<"Unesite krajeve intervala i korak: ";
        double xMin, xMax, xDelta;
        cin>> xMin >> xMax >> xDelta;
        cout<< "Unesite red interpolacije: ";
        int d;
        cin >> d;
        double argument;
        while (cin){
            cout<<"Unesite argument (ili \"kraj\" za kraj): ";
            cin >> argument;
            if(!cin) break;
            cout <<"f("<<argument<<") = "<<f(argument)<<" fapprox("<<argument<<") = "<<BaricentricnaInterpolacija(f, xMin, xMax, xDelta, d)(argument)<<endl;
        }
    }
	return 0;
}