/B2017/2018: Zadaća 3, Zadatak 1
#include <iostream>
#include <vector>
#include <utility>
#include <functional>
#include <cmath>
#include <stdexcept>
#include <set>
#include <algorithm>

using namespace std;

bool JesuLiJednaki(double x, double y, double Eps = 1e-10)
{
    return fabs(x - y) <= Eps * (fabs(x) + fabs(y));
}

bool funkcijaKriterija(pair<double,double>par1, pair<double,double>par2)
{
    return par1.first<=par2.first;
}

function<double(double)> LinearnaInterpolacija(vector<pair<double,double>> parovi)
{
    for(int i = 0; i<parovi.size(); i++) {
        for (int j = i-1; j >= 0; j--) {
            if(JesuLiJednaki( parovi[j].first, parovi[i].first)) {
                throw domain_error("Neispravni cvorovi");
            }
        }
    }


    sort(parovi.begin(),parovi.end(),funkcijaKriterija);

    return [parovi](double x) {

        if(x<parovi[0].first || x>parovi[parovi.size()-1].first) {
            throw range_error("Argument izvan opsega");
        }
        auto veci = upper_bound(parovi.begin(), parovi.end(),pair<double,double>(x,0),funkcijaKriterija);
        int pozicija_veci = veci - parovi.begin();
        int pozicija_manji = pozicija_veci-1;

        double ym = parovi[pozicija_manji].second;
        double yv = parovi[pozicija_veci].second;
        double xm = parovi[pozicija_manji].first;
        double xv = parovi[pozicija_veci].first;



        return ym + ((yv-ym)/(xv-xm))*(x-xm);
    };
}

function<double(double)> LinearnaInterpolacija(function<double(double)>f, double xMin, double xMax, double delta)
{
    if(xMin>xMax || delta<=0) {
        throw domain_error("Nekorektni parametri");
    }

    vector<pair<double,double>> parovi;

    while(xMin<=xMax) {
        pair<double,double> par = pair<double,double>(xMin, f(xMin));

        parovi.push_back(par);

        xMin+=delta;
    }

    return LinearnaInterpolacija(parovi);
}

double testnaFunkcija(double x)
{
    return x*x+sin(x);
}
int main()
{
    try {
        int broj_cvorova;
        int opcija;
        cout<<"Odaberite opciju (1 - unos cvorova, 2 - aproksimacija): ";
        cin>>opcija;

        if(opcija == 1) {
            cout<<"Unesite broj cvorova: ";
            cin>>broj_cvorova;
            vector<pair<double,double>> parovi;
            cout<<"Unesite cvorove kao parove x y: ";
            for (int i = 0; i < broj_cvorova; i++) {
                double x,y;
                cin>>x>>y;
                parovi.push_back(make_pair(x,y));
            }
            auto f(LinearnaInterpolacija(parovi));

            string unos;
            while(true) {
                cout<<"Unesite argument (ili \"kraj\" za kraj): ";
                cin>>unos;
                if(unos=="kraj") {
                    break;
                }
                double argument = stod(unos);
                cout<<"f("<<argument<<") = "<<f(argument)<<endl;
            }
        } else if(opcija==2) {
            cout<<"Unesite krajeve intervala i korak: ";
            double pocetak,kraj,korak;
            cin>>pocetak>>kraj>>korak;

            auto fapprox(LinearnaInterpolacija(testnaFunkcija,pocetak,kraj,korak));
            string unos;
            while(true) {
                try {
                    cout<<"Unesite argument (ili \"kraj\" za kraj): ";
                    cin>>unos;
                    if(unos=="kraj") {
                        break;
                    }
                    double argument = stod(unos);
                    cout<<"f("<<argument<<") = "<<testnaFunkcija(argument)<<" fapprox("<<argument<<") = "<<fapprox(argument)<<endl;
                } catch(domain_error e) {
                    cout<<e.what()<<endl;
                } catch(range_error e) {
                    cout<<e.what()<<endl;
                }

            }

        }

    } catch(domain_error e) {
        cout<<e.what()<<endl;
    } catch(range_error e) {
        cout<<e.what()<<endl;
    }
}