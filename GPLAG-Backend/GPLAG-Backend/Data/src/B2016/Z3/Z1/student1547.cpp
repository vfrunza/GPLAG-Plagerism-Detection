/B2016/2017: Zadaća 3, Zadatak 1
//Autotestovi by Enil Pajic (epajic1@etf.unsa.ba)
#include <iostream>
#include <vector>
#include <stdexcept>
#include <utility>
#include <functional>
#include <cmath>

using std::cout;
using std::cin;

std::function<double(double)> BaricentricnaInterpolacija(std::vector<std::pair<double,double>> cvorovi, int d)
{
    if(d>=cvorovi.size() or d<0) throw std::domain_error ("Nedozvoljen red");
    for(int i=0; i<cvorovi.size(); i++) {
        for(int j=i+1; j<cvorovi.size(); j++) {
            if(cvorovi[j].first==cvorovi[i].first) throw std::domain_error ("Neispravni cvorovi");
        }
    }
    if(cvorovi.size()==0) return [](double x) {
        return 0;
    };
    std::vector<double> w(cvorovi.size(), 0);
    for(int i=1; i<=cvorovi.size(); i++) {
        int min(i), max(1);
        if(int(cvorovi.size()-d)<min) min=cvorovi.size()-d;
        if(i-d>max) max=i-d;
        for(int j=max; j<=min; j++) {
            double proizvod(1);
            for(int k=j; k<=j+d; k++) {
                if(k==i) continue;
                proizvod*=1./(cvorovi[i-1].first-cvorovi[k-1].first);
            }
            w[i-1]+=std::pow(int(-1),j-1)*proizvod;
        }
    }

    return [cvorovi, w](double x) {
        double suma1(0), suma2(0);
        for(int i=1; i<=cvorovi.size(); i++) {
            if(x==cvorovi[i-1].first) return cvorovi[i-1].second;
            suma1+=(w[i-1]*cvorovi[i-1].second)/(x-cvorovi[i-1].first);
            suma2+=w[i-1]/(x-cvorovi[i-1].first);
        }
        return double(suma1/suma2);
    };
}

std::function<double(double)> BaricentricnaInterpolacija (std::function<double(double)> fun, double xmin, double xmax, double x, int d)
{
    if(xmin>xmax or x<=0) throw std::domain_error ("Nekorektni parametri");
    std::vector<std::pair<double,double>> cvorovi;
    for(double i=xmin; i<=xmax; i+=x) {
        cvorovi.push_back(std::make_pair(i, fun(i)));
    }
    
        return BaricentricnaInterpolacija(cvorovi, d);
    
}


int main ()
{

    cout << "Odaberite opciju (1 - unos cvorova, 2 - aproksimacija): ";
    int n;
    cin >> n;
    if(n==1) {
        cout << "Unesite broj cvorova: ";
        cin >> n;
        std::vector<std::pair<double, double>> cvorovi;
        cout << "Unesite cvorove kao parove x y: ";
        for(int j=0; j<n; j++) {
            std::pair<double, double> cvor;
            cin >> cvor.first >> cvor.second;
            cvorovi.push_back(cvor);
        }
        int d;
        cout << "Unesite red interpolacije: ";
        cin >> d;
        cout << "Unesite argument (ili \"kraj\" za kraj): ";
        double x;
        cin >> x;
        try {
            auto f(BaricentricnaInterpolacija(cvorovi, d));


            while(cin) {
                cout << "f("<<x<<") = "<<f(x)<< std::endl;
                cout << "Unesite argument (ili \"kraj\" za kraj): ";
                cin >> x;
            }
        } catch(std::domain_error izuzetak) {
            cout << izuzetak.what();
            return 0;
        }
    }

    if(n==2) {
        cout << "Unesite krajeve intervala i korak: ";
        double xmin, xmax, dx;
        cin >> xmin >> xmax >> dx;
        int d;
        cout << "Unesite red interpolacije: ";
        cin >> d;
        cout << "Unesite argument (ili \"kraj\" za kraj): ";
        double x;
        cin >> x;

        try {
            auto fap(BaricentricnaInterpolacija([](double x) {
                return x*x+sin(x);
            }, xmin, xmax, dx, d));
            while(cin) {
                cout << "f("<<x<<") = "<<x*x+sin(x) << " fapprox("<<x<<") = "<<fap(x)<< std::endl;
                cout << "Unesite argument (ili \"kraj\" za kraj): ";
                cin >> x;
            }
        } catch(std::domain_error izuzetak) {
            cout << izuzetak.what();
            return 0;
        }
    }
    return 0;
}