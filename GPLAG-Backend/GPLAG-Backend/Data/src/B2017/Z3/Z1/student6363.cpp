#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include <stdexcept>
#include <exception>
#include <cmath>
#include <string>
double e {0.00000001};
using std::vector;
using std::pair;
using std::string;
using std::cout;
using std::cin;
using std::endl;

template <class Iterator>
Iterator binarna_pretraga (Iterator prvi, Iterator zadnji, double x)
{
    Iterator y = std::lower_bound(prvi,zadnji,x,[](const std::pair<double, double> &x, double y) -> bool
    { return x.first < y; });
    if(y!=zadnji) std::advance(y,-1);
    return y;
}

std::function<double(double)> LinearnaInterpolacija(vector<pair<double,double>> v)
{
    std::sort(v.begin(),v.end(),[](pair<double,double> x,pair<double,double> y) {
        return ((x.first<y.first) || (x.first==y.first && x.second<y.second));
    });
    for(int i=0; i<v.size(); i++)
        if(i+1<v.size() && v.at(i).first==v.at(i+1).first)
            throw std::domain_error("Neispravni cvorovi");
    return [v](double x) ->double {
        vector<pair<double,double>>::const_iterator vIt(binarna_pretraga(v.begin(),v.end(),x));
        if(v.empty() || x<v.at(0).first || x>v.at(v.size()-1).first || vIt==v.end())
            throw std::range_error("Argument izvan opsega");
        if(x==v.at(v.size()-1).first) return v.at(v.size()-1).second;
        if(x==v.at(0).first) return v.at(0).second;
        auto vIt1 = vIt;
        vIt1++;
        if(vIt1==v.end()) vIt--;
        return (vIt->second + (vIt1->second - vIt->second)/(vIt1->first-vIt->first) * (x-vIt->first));
    };
}

std::function<double(double)> LinearnaInterpolacija(std::function<double(double)> f,double xmin, double xmax, double dx)
{

    if(xmin > xmax || dx <= 0) throw std::domain_error("Nekorektni parametri");
    vector<pair<double,double>> v;
    int faktor {};
    for(;;) {
        if(xmin+faktor*dx>=xmax) {
            v.push_back(std::make_pair(xmax,f(xmax)));
            break;
        }
        v.push_back(std::make_pair(xmin+faktor*dx,f(xmin+faktor*dx)));
        faktor++;
    }
    return LinearnaInterpolacija(v);
}

/* bool ispravanString(const string &s) {
    string::const_iterator sIt(s.begin());
    while(sIt!=s.end()) {
        if(*sIt==' ') sIt++;
        else if(!((*sIt>='0' && *sIt<='9') || *sIt=='.' || *sIt=='-')) return false;
        sIt++;
    }
    return true;
}*/

int main ()
{
    try {
        string opcija;
        do {
            cout << "Odaberite opciju (1 - unos cvorova, 2 - aproksimacija): ";
            cin >> opcija;
            if(!(opcija=="1" || opcija=="2")) cout << "Neispravan unos. Unesite ponovo: ";
        } while(!(opcija=="1" || opcija=="2"));

        if(opcija=="1") {
            int n;
            cout << "Unesite broj cvorova: ";
            cin >> n;
            cout << "Unesite cvorove kao parove x y: ";
            vector<pair<double,double>> vp;
            for(int i=0; i<n; i++) {
                int x,y;
                cin >> x >> y;
                vp.push_back(std::make_pair(x,y));
            }
            string unos;
            auto f(LinearnaInterpolacija(vp));
            for(;;) {
                double x;
                cout << "Unesite argument (ili \"kraj\" za kraj): ";
                cin >> unos;
                try {
                    x = std::stod(unos);
                } catch(...) {
                    return 0;
                }
                try {
                    cout << "f(" << x << ") = " << f(x) << endl;
                } catch(std::exception &ex) {
                    cout << ex.what() << endl;
                }
            }
        } else {
            cout << "Unesite krajeve intervala i korak: ";
            double xmin,xmax,dx;
            cin >> xmin >> xmax >> dx;
            auto fo([](double x) {
                return x*x+sin(x);
            });
            auto f(LinearnaInterpolacija(fo,xmin,xmax,dx));
            string unos;
            for(;;) {
                double x;
                cout << "Unesite argument (ili \"kraj\" za kraj): ";
                cin >> unos;
                try {
                    x = std::stod(unos);
                } catch(...) {
                    return 0;
                }
                try {
                    cout << "f(" << x << ") = " << fo(x) << " " << "fapprox(" << x << ") = " << f(x) << endl;
                } catch(std::exception &ex) {
                    cout << ex.what() << endl;
                }
            }
        }
    } catch(std::exception &ex) {
        cout << ex.what();
    }
    return 0;
}
