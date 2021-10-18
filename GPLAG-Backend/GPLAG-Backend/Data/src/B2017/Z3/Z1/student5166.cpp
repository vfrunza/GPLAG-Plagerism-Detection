/B2017/2018: Zadaća 3, Zadatak 1
#include <iostream>
#include <vector>
#include <stdexcept>
#include <functional>
#include <cmath>
using namespace std;

double xsinx (double x){
    return x*x + sin(x);
}

double min (double a, double b){
    if (a < b) return a;
    else return b;
}

double max (double a, double b){
    if (a > b) return a;
    else return b;
}

double w (int n, int d, int index, double xi, const vector<pair<double, double>> &x){
    double suma = 0;
    index++;
    for (int i = max(1, index-d); i<=min(index, n-d); i++){
        double proizvod = 1;
        for (int j=i-1; j<i+d; j++){
            if (index-1 == j) continue;
            proizvod *= (1/(xi-x[j].first));
        }
        proizvod *= pow(-1, i-1);
        suma += proizvod;
    }
    return suma;
}

function<double(double)>LinearnaInterpolacija(vector<pair<double, double>> v, int d){
    if (d<0 || d>v.size()) throw domain_error ("Argument izvan opsega");
    return [v,d](double x){
        for (int i=0; i<v.size(); i++){
            if (x == v[i].first) return v[i].second;
        }
        int n = v.size();
        int i=0; 
        auto f1 (double((w(n, d, i, v[i].first, v)*(v[i].second)) / (x - v[i].first)));
        auto f2 ((w(n, d, i, v[i].first, v)) / (x - v[i].first));
        for (i=1; i<n; i++){
            f1 = f1 + (w(n, d, i, v[i].first, v)*(v[i].second)) / (x-v[i].first);
            f2 = f2 + (w(n, d, i, v[i].first, v)) / (x-v[i].first);
        }
        return f1/f2;
    };
}


function<double(double)>LinearnaInterpolacija(function<double(double)> f, double x_min, double x_max, double dx, int d){
    if (x_min > x_max || dx<=0) throw domain_error ("Nekorektni parametri");
    vector<pair<double, double>> v;
    v.push_back(make_pair(x_min, f(x_min)));
    x_min += dx;
    for (;;){
        if (x_min > x_max) break;
        v.push_back(make_pair(x_min, f(x_min)));
        x_min += dx;
    }
    return LinearnaInterpolacija(v, d);
}


int main (){
    try {
        int d;
        double x_min, x_max, dx;
        vector<pair<double, double>> v;
        do {
            bool dobro = true;
            cout << "Odaberite opciju (1 - unos cvorova, 2 - aproksimacija): ";
            int unos;
            cin >> unos;
            if (!unos) break;
            if (unos == 1){
                cout << "Unesite broj cvorova: ";
                int n;
                cin >> n;
                cout << "Unesite cvorove kao parove x y: ";
                for (int i=0; i<n; i++){
                    double x, y;
                    cin >> x >> y;
                    v.push_back(make_pair(x, y));
                }
                for (int i=0; i<n; i++){
                    for (int j=i+1; j<n; j++){
                        if (v[i].first = v[j].first) throw domain_error ("Neispravni cvorovi");
                    }
                }
                
                do{
                    cout << "Unesite argument (ili \"kraj\" za kraj): ";
                    double a;
                    cin >> a;
                    if (!cin){
                        dobro = false;
                        break;
                    }
                    cout << "f(" << a << ") = " << LinearnaInterpolacija(v, d)(a) << endl;
                } while (1);
            }
            if (!dobro) break;
            bool dobro2 = true;
            if (unos == 2){
                cout << "Unesite krajeve intervala i korak: ";
                cin >> x_min >> x_max >> dx;
                
                double x_min2 = x_min;
                v.push_back(make_pair(x_min2, xsinx(x_min2)));
                x_min2 += dx;
                for (;;){
                    if (x_min2 > x_max) break;
                    v.push_back(make_pair(x_min2, xsinx(x_min2)));
                    x_min2 += dx;
                }
                do {
                    cout << "Unesite argument (ili \"kraj\" za kraj): ";
                    double a;
                    cin >> a;
                    if (!cin){
                        dobro2 = false;
                        break;
                    }
                    cout << "f(" << a << ") = " << xsinx(a) << " ";
                    cout << "fapprox(" << a << ") = " << LinearnaInterpolacija(xsinx, x_min, x_max, dx, d)(a) << endl;
                }while (1);
            }
            if (!dobro2) break;
            
        } while(1);
        
    }
    catch (domain_error Izuzetak){
        cout << Izuzetak.what() << endl;
    }
    
	return 0;
}