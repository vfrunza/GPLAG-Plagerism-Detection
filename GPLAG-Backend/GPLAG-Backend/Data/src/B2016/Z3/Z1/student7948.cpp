#include <iostream>
#include <utility>
#include <vector>
#include <functional>
#include <cmath>
#include <stdexcept>
using namespace std;

int GornjaGranica (int i, int n, int d) {
    if(i>n-1-d) return n-1-d;
    return i;
}

int DonjaGranica (int i, int d) {
    if(0>i-d) return 0;
    return i-d;
}

double Produkt (double xi, double xy) {
    if(abs(xi-xy)<0.00001) return 1;
    return (1./(xi-xy));
}

double Tezinski (vector<pair<double,double>> cvorovi_interpolacije, int d, int i) {
    int g_granica(GornjaGranica(i, cvorovi_interpolacije.size(), d));
    int d_granica(DonjaGranica(i, d));
    double tezinski(0);
    for(int k=d_granica; k<=g_granica; k++) {
        double produkt(1);
        for(int j=k; j<=k+d; j++) {
            produkt*=Produkt(cvorovi_interpolacije[i].first, cvorovi_interpolacije[j].first);
        }
        tezinski+=produkt*(pow(-1, k));
    }
    return tezinski;
}

function<double(double)> BaricentricnaInterpolacija(vector<pair<double,double>> cvorovi_interpolacije, int d) {
    if(d<0 || d>cvorovi_interpolacije.size()) throw domain_error("Nedozvoljen red");
    for(int i=0; i<cvorovi_interpolacije.size(); i++) {
        for(int j=i; j<cvorovi_interpolacije.size(); j++) {
            if(i!=j) {
                if(cvorovi_interpolacije[i].first==cvorovi_interpolacije[j].first) throw domain_error("Neispravni cvorovi");
            }
        }
    }
    return [cvorovi_interpolacije, d] (double x) {
        vector<double> tezinski(cvorovi_interpolacije.size());
        for(int i=0; i<cvorovi_interpolacije.size(); i++) {
            tezinski[i]=Tezinski(cvorovi_interpolacije, d, i);
        }
        double f(0), clan(0), brojnik(0), nazivnik(0);
        for(int i=0; i<cvorovi_interpolacije.size(); i++) {
            if(abs(x-cvorovi_interpolacije[i].first)<0.001) return cvorovi_interpolacije[i].second;
            clan=tezinski[i]/(x-cvorovi_interpolacije[i].first);
            brojnik+=clan*cvorovi_interpolacije[i].second;
            nazivnik+=clan;
        }
        f=brojnik/nazivnik;
        return f;
    };
}

function<double(double)> BaricentricnaInterpolacija2(vector<pair<double,double>> cvorovi_interpolacije, int d) {
    if(d<0) throw domain_error("Nedozvoljen red");
    return [cvorovi_interpolacije, d] (double x) {
        vector<double> tezinski(cvorovi_interpolacije.size());
        for(int i=0; i<cvorovi_interpolacije.size(); i++) {
            tezinski[i]=Tezinski(cvorovi_interpolacije, d, i);
        }
        double f(0), clan(0), brojnik(0), nazivnik(0);
        for(int i=0; i<cvorovi_interpolacije.size(); i++) {
            if(abs(x-cvorovi_interpolacije[i].first)<0.001) return cvorovi_interpolacije[i].second;
            clan=tezinski[i]/(x-cvorovi_interpolacije[i].first);
            brojnik+=clan*cvorovi_interpolacije[i].second;
            nazivnik+=clan;
        }
        f=brojnik/nazivnik;
        return f;
    };
}

function<double(double)> BaricentricnaInterpolacija(function<double(double)> fanskhn, double x_min, double x_max, double x_delta, int d) {
    if(x_min>x_max || x_delta<=0) throw domain_error("Nekorektni parametri");

    vector<pair<double,double>> cvorovi_interpolacije;
    while(x_min<=x_max) {
        cvorovi_interpolacije.push_back(make_pair(x_min, fanskhn(x_min)));
        x_min+=x_delta;
    }
    auto f=BaricentricnaInterpolacija2(cvorovi_interpolacije, d);
    return f;
}

double funkc (double x) {return x * x + std::sin(x);}


int main ()
{
    cout << "Odaberite opciju (1 - unos cvorova, 2 - aproksimacija): ";
    int opcija;
    cin >> opcija;
    if(opcija==1) {
        cout << "Unesite broj cvorova: ";
        int br_cvorova;
        cin >> br_cvorova;
        cout << "Unesite cvorove kao parove x y: ";
        vector<pair<double,double>> cvorovi(br_cvorova);
        for(int i=0; i<br_cvorova; i++) {
            double prvi, drugi;
            cin >> prvi >> drugi;
            cvorovi[i].first=prvi; cvorovi[i].second=drugi;
        }
        cout << "Unesite red interpolacije: ";
        int d;
        cin >> d;
        try {
        auto fun = BaricentricnaInterpolacija(cvorovi, d);
        while(1) {
            cin.ignore(1000, '\n');
            cout << "Unesite argument (ili \"kraj\" za kraj): ";
            double argument;
            cin >> argument;
            if(!cin) break;
            cout << "f(" << argument << ") = " << fun(argument) << "\n";
        }
        }
        catch(domain_error he) {
            cout << "Izuzetak: " << he.what();
        }
    }
    if(opcija==2) {
        cout << "Unesite krajeve intervala i korak: ";
        double x_max, x_min, x_delta;
        cin >> x_min >> x_max >> x_delta;
        cout << "Unesite red interpolacije: ";
        int d;
        cin >> d;
        try {
        auto fun = BaricentricnaInterpolacija(funkc, x_min, x_max, x_delta, d);
        while(1) {
            cin.ignore(1000, '\n');
            cout << "Unesite argument (ili \"kraj\" za kraj): ";
            double argument;
            cin >> argument;
            if(!cin) break;
            cout << "f(" << argument << ") = " << funkc(argument) << " fapprox(" << argument << ") = " << fun(argument) << "\n";
        }
        }
        catch(domain_error he) {
            cout << "Izuzetak: " << he.what();
        }
    }

	return 0;
}