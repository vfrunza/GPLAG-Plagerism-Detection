/B2016/2017: Zadaća 3, Zadatak 1
//Autotestovi by Enil Pajic (epajic1@etf.unsa.ba)
#include <iostream>
#include <utility>
#include <vector>
#include <functional>
#include <cmath>
#include <stdexcept>

using namespace std;

double omega(int i, int d, vector<pair<double,double>> v)
{
    double suma=0;
    for( int k=fmax(1,i-d); k<=fmin(i, v.size()-d); k++) {
        double p(1);
        for(int j=k; j<=k+d; j++) {
            if(j!=i) {
                p/=(v[i-1].first - v[j-1].first);
            }
        }
        suma=suma + (p*pow(-1,k-1));
    }
    return suma;
}

void ProvjeraPrveFunkcije(vector<pair<double,double>> v,int d) {
    if(d<0 || d>v.size()) throw std::domain_error("Nedozvoljen red");
    for(int i=0;i<v.size()-1;i++) {
        for(int j=i+1;j<v.size();j++) {
            if(v[i].first==v[j].first) throw std::domain_error("Neispravni cvorovi");
        }
    }
}

function<double(double)>BaricentricnaInterpolacija(vector<pair<double,double>> v, int d)
{
    ProvjeraPrveFunkcije(v,d);

    return [v,d](double x) {
        double s1(0), s2(0);
        for( int i=1; i<=v.size(); i++ ) {
            if(x==v[i-1].first) return v[i-1].second;
            double w(omega(i,d,v));
            s1+=(w/(x-v[i-1].first))*v[i-1].second;
        }
        for( int i=1; i<=v.size(); i++ ) {
            double w(omega(i,d,v));
            s2+=w/(x-v[i-1].first);
        }
        return s1/s2;
    };

}

double FunkcijaMaina(double broj)
{
    double vracanje;
    vracanje=pow(broj,2)+ sin(broj);
    return vracanje;
}

pair<double,double> NapraviPar(double a,double b)
{
    pair<double,double> par_za_vracanje;
    par_za_vracanje.first=a;
    par_za_vracanje.second=b;
    return par_za_vracanje;
}

void ProvjeraDrugeFunkcija(double delta, double najmanji, double najveci) {
    if ((delta<=0) || (najveci<najmanji)) throw domain_error("Nekorektni parametri");
}

function<double(double)> BaricentricnaInterpolacija(double f(double n), double najmanji, double najveci, double delta, int d)
{
    ProvjeraDrugeFunkcija(delta,najmanji,najveci);

    vector<pair<double,double>> v;
    for(double i=najmanji ; i<=najveci ; i+=delta ) {
        v.push_back(NapraviPar(i,f(i)));
    }

    function<double(double)> druga(BaricentricnaInterpolacija(v,d));
    return druga;

}

int main ()
{
    cout<<"Odaberite opciju (1 - unos cvorova, 2 - aproksimacija): ";
    int n;
    cin>>n;
    switch(n) {
    case 1: {
        cout<<"Unesite broj cvorova: ";
        int k;
        cin>>k;
        std::vector<pair<double,double>> vektor;
        cout<<"Unesite cvorove kao parove x y: ";
        for(int i=0; i<k; i++) {
            double jedan,dva;
            cin>>jedan>>dva;
            pair<double,double> par;
            par.first=jedan;
            par.second=dva;
            vektor.push_back(par);

        }
        cout<<"Unesite red interpolacije: ";
        int d;
        cin>>d;
        try {
            auto f(BaricentricnaInterpolacija(vektor,d));
            for(;;) {
                cout<<"Unesite argument (ili \"kraj\" za kraj): ";
                double x;
                cin>>x;
                if(!cin) break;
                cout<<"f("<<x<<") = "<<f(x)<<endl;
            }
        } catch(std::domain_error e) {
            cout<<e.what()<<endl;
        }
        break;
    }
    case 2: {
        cout<<"Unesite krajeve intervala i korak: ";
        double najmanji,najveci,delta;
        cin>>najmanji;
        cin>>najveci;
        cin>>delta;
        cout<<"Unesite red interpolacije: ";
        int red_interpolacije;
        cin>>red_interpolacije;
        for(;;) {
            cout<<("Unesite argument (ili \"kraj\" za kraj): ");
            double n;
            cin>>n;
            if(!std::cin) break;
            try {
                auto druga(BaricentricnaInterpolacija(FunkcijaMaina,najmanji,najveci,delta,red_interpolacije));
                cout<<"f("<<n<<") = "<<FunkcijaMaina(n)<< " fapprox("<<n<<") = "<<druga(n)<<endl;
            } catch(domain_error greska) {
                cout<<greska.what()<<endl;
            }
        }
        break;
    }
}
    return 0;
}