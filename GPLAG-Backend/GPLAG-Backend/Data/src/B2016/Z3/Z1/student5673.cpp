/B2016/2017: Zadaća 3, Zadatak 1
//Autotestovi by Enil Pajic (epajic1@etf.unsa.ba)
#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <functional>
#include <stdexcept>

using namespace std;

double SkontajW (vector<pair<double, double>> v, int d, int i)
{
    int n = v.size();
    
    int start = 1;
    if (i - d > 1) start = i - d;
    
    int limit = i;
    if (n - d < i) limit = n - d;
    
    double sum = 0;
    
    for (int k = start; k <= limit; k++)
    {
        double product = 1;
        
        for (int j = k; j <= k + d; j++)
        {
            if (i == j) continue;
            
            product *= 1. / (v[i - 1].first - v[j - 1].first);
        }
        
        sum += pow(-1, k - 1) * product;
    }
    
    return sum;
}

function<double(double)> BaricentricnaInterpolacija (vector<pair<double, double>> v, int d)
{
    if (d < 0 || d > v.size()) throw domain_error ("Nedozvoljen red");
    return [v, d] (double x) {
        double sum1 = 0;
        double sum2 = 0;
        double sum;
        
        for (int i = 1; i <= v.size(); i++)
        {
            double w;
            w = SkontajW(v, d, i);
            
            if (x == v[i - 1].first) return v[i - 1].second;
            
            sum1 += (w / (x - v[i - 1].first)) * v[i - 1].second;
            
            sum2 += w / (x - v[i - 1].first);
        }
        
        sum = sum1 / sum2;
        return sum;
    };
}

function<double(double)> BaricentricnaInterpolacija(double f(double), double xmin, double xmax, double dx, int d)
{
    if (xmin > xmax || dx <= 0) throw domain_error ("Nekorektni parametri");
    
    vector<pair<double, double>> v;
    
    double pom = xmin;
    int i = 0;
    
    while (pom <= xmax)
    {
        v.push_back(make_pair(xmin + i * dx, f(xmin + i * dx)));
        i++;
        pom += dx;
    }
    
    return [v, d] (double x) {
        double sum1 = 0;
        double sum2 = 0;
        double sum;
        
        for (int i = 1; i <= v.size(); i++)
        {
            double w;
            
            w = SkontajW(v, d, i);
            
            if (x == v[i - 1].first) return v[i - 1].second;
            
            sum1 += (w / (x - v[i - 1].first)) * v[i - 1].second;
            
            sum2 += w / (x - v[i - 1].first);
        }
        
        sum = sum1 / sum2;
        return sum;
    };
}

int main ()
{
    while (1)
    {
        cout << "Odaberite opciju (1 - unos cvorova, 2 - aproksimacija): ";
        int input;
        cin >> input;
        
        if (input == 1)
        {
            cout << "Unesite broj cvorova: ";
            int num;
            cin >> num;
            
            vector<pair<double, double>> v(num);
            cout << "Unesite cvorove kao parove x y: ";
            for (int i = 0; i < num; i++)
            {
                cin >> v[i].first;
                cin >> v[i].second;
            }
            cout << "Unesite red interpolacije: ";
            int d;
            cin >> d;
            
            double x;
            do
            {
                cout << "Unesite argument (ili \"kraj\" za kraj): ";
                if (cin >> x)
                {
                    auto fun = BaricentricnaInterpolacija(v, d);
                    
                    cout << "f(" << x << ") = " << fun(x) << endl;
                }
                else 
                {
                    return 0;
                    cin.clear();
                    cin.ignore(10000, '\n');
                    break;
                }
            } while (1);
        }
        else
        {
            cout << "Unesite krajeve intervala i korak: ";
            double xmin, xmax, dx;
            cin >> xmin >> xmax >> dx;
            
            cout << "Unesite red interpolacije: ";
            int d;
            cin >> d;
            
            double x;
            while (1)
            {
                cout << "Unesite argument (ili \"kraj\" za kraj): ";
                if (cin >> x)
                {
                    auto fun2 = BaricentricnaInterpolacija([] (double x){return x * x + sin(x);}, xmin, xmax, dx, d);
                    
                    cout << "f(" << x << ") = " << x * x + sin(x) <<" fapprox(" << x << ") = " << fun2(x)  << endl;
                }
                else
                {
                    return 0;
                    cin.clear();
                    cin.ignore(10000, '\n');
                    break;
                }
            }
            
        }
    }
	return 0;
}