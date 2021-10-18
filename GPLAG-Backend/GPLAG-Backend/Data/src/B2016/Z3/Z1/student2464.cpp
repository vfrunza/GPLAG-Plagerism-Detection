#include <iostream>
#include <stdexcept>
#include <utility>
#include <vector>
#include <functional>
#include <cmath>

using std::cin;
using std::cout;
using std::pair;
using std::vector;

std::function<double(double)> BaricentricnaInterpolacija(vector<pair<double, double>> v, int d)
{
    if(d<0 || d>v.size()) throw std::domain_error("Nedozvoljen red");
    vector<double> w;
    for(int i=1;i<=v.size();i++)
    {
        for(int o=i;o<v.size();o++)
        {
            if(v[o].first==v[i-1].first) throw std::domain_error("Neispravni cvorovi");
        }
        w.push_back(0);
        int mx, mn;
        if(1>=i-d) mx=1; else mx=i-d;
        if(i<=v.size()-d) mn=i; else mn=v.size()-d;
        for(int k=mx;k<=mn;k++)
        {
            double pr=1;
            for(int j=k;j<=k+d;j++)
            {
                if(i!=j) pr*=(1/(v[i-1].first-v[j-1].first));
            }
            w[i-1]+=pow(-1, k-1)*pr;
        }
    }
    return [v, w](double x)
    {
        double s1=0, s2=0, s;
        for(int i=0;i<v.size();i++)
        {
            if(x==v[i].first) return v[i].second;
            s=w[i]/(x-v[i].first);
            s1+=s*v[i].second;
            s2+=s;
        }
        return s1/s2;
    };
}

std::function<double(double)> BaricentricnaInterpolacija(double f(double), double xmn, double xmx, double dtx, int d)
{
    if(xmn>xmx || dtx<=0) throw std::domain_error("Nekorektni parametri");
    vector<pair<double, double>> v;
    for(double i=xmn; i<=xmx; i+=dtx) v.push_back(std::make_pair(i, f(i)));
    try
    {
        return BaricentricnaInterpolacija(v, d);
    }
    catch(...)
    {
        throw;
    }
}

int main ()
{
    int op;
    cout << "Odaberite opciju (1 - unos cvorova, 2 - aproksimacija): ";
    cin >> op;
    int d;
    if(op==1)
    {
        int bc;
        cout << "Unesite broj cvorova: ";
        cin >> bc;
        vector<pair<double, double>> v(bc);
        cout << "Unesite cvorove kao parove x y: ";
        for(int i=0;i<bc;i++)
        {
            cin >> v[i].first;
            cin >> v[i].second;
        }
        cout << "Unesite red interpolacije: ";
        cin >> d;
        double a;
        try
        {
            auto f=BaricentricnaInterpolacija(v, d);
            while(cin)
            {
                cout << "Unesite argument (ili \"kraj\" za kraj): ";
                cin >> a;
                if(cin) cout << "f(" << a << ") = " << f(a) << "\n";       
            }
        }
        catch(std::domain_error ero)
        {
            cout << ero.what() << "\n";
            return 0;
        }
    }
    if(op==2)
    {
        double x1, x2, ko;
        cout << "Unesite krajeve intervala i korak: ";
        cin >> x1;
        cin >> x2;
        cin >> ko;
        cout << "Unesite red interpolacije: ";
        cin >> d;
        double a;
        try
        {
            auto f=BaricentricnaInterpolacija([](double x){return x*x + sin(x);}, x1, x2, ko, d);
            while(cin)
            {
                cout << "Unesite argument (ili \"kraj\" za kraj): ";
                cin >> a;
                if(cin) cout << "f(" << a << ") = " << a*a+sin(a) << " fapprox(" << a << ") = " << f(a) << "\n";
            }
        }
        catch(std::domain_error ero)
        {
            cout << ero.what() << "\n";
            return 0;
        }
    }
	return 0;
}