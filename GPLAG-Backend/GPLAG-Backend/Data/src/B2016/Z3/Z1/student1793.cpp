#include <iostream>
#include <utility>
#include <stdexcept>
#include <vector>
#include <cmath>
#include <functional>
using namespace::std;

function<double(double)> BaricentricnaInterpolacija(vector<pair<double,double>> a,int d)
{
    if(d<0 || d > a.size())
        throw domain_error("Nedozvoljen red");
    for(int i = 0;i < a.size();i++)
    {
        for(int j = i+1;j < a.size();j++)
        {
        if(get<0>(a[i]) == get<0>(a[j]))
            throw domain_error("Neispravni cvorovi");
        }
    }
    int n = a.size();
    vector<double> w(n);
    double produkt(1),suma(0);
    for(int i = 0; i < n;i++)
    {
        suma = 0;
        for(int k = max(0,i-d);k <= min(i,n - d-1);k++)
        {
            produkt = 1;
            for(int j = k;j <= k+d;j++)
            {
                if(j != i)
                produkt = produkt*(1./(get<0>(a[i])-get<0>(a[j])));
            }
            produkt *= pow(-1,k);
            suma = suma + produkt;
        }
        w[i] = suma;
    }
    return [n,w,a](double x)
    {
        double suma1(0),suma2(0);
        for(int i = 0;i < n;i++)
        {
            if(x == get<0>(a[i]))
                return get<1>(a[i]);
            suma1 += w[i]/(x-get<0>(a[i]))*get<1>(a[i]);
            suma2 += w[i]/(x-get<0>(a[i]));
        }
        return suma1/suma2;
        
    };
}

function<double(double)> BaricentricnaInterpolacija(function<double(double)> a,double xmin,double xmax,double dx,int d)
{
    if(xmin > xmax || dx <= 0)
        throw domain_error("Nekorektni parametri");
    vector<pair<double,double>> v;
    while(xmin < xmax)
    {
        v.push_back(make_pair(xmin,a(xmin)));
        xmin += dx;
    }
    auto fun(BaricentricnaInterpolacija(v,d));
    return fun;
    
}
int main()
{
    function<double(double)> xxsinx([](double x){return sin(x)+x*x;});
    int opc,br,d;
    cout << "Odaberite opciju (1 - unos cvorova, 2 - aproksimacija): ";
    cin >> opc;
    if(opc == 1)
    {
        cout << "Unesite broj cvorova: ";
        cin >> br;
        int i(0);
        vector<pair<double,double>> cv;
        cout << "Unesite cvorove kao parove x y: ";
        while(i < br)
        {
            double x,y;
            cin >> x >> y;
            cv.push_back(make_pair(x,y));
            i++;
        }
        cout << "Unesite red interpolacije: ";
        cin >> d;
        auto f(BaricentricnaInterpolacija(cv,d));
        while(true)
        {
            cout << "Unesite argument (ili \"kraj\" za kraj): ";
            double arg;
            cin >> arg;
            if(!cin)
                break;
            cout << "f(" << arg << ") = " << f(arg)  << endl;
        }
    }
    else
    {
        double xmin,xmax,dx;
        cout << "Unesite krajeve intervala i korak: ";
        cin >> xmin >> xmax >> dx;
        cout << "Unesite red interpolacije: ";
        cin >> d;
        auto f(BaricentricnaInterpolacija(xxsinx,xmin,xmax,dx,d));
        while(true)
        {
            cout << "Unesite argument (ili \"kraj\" za kraj): ";
            double arg;
            cin >> arg;
            if(!cin)
                break;
            cout << "f(" << arg << ") = " << xxsinx(arg) << " fapprox(" << arg << ") = " << f(arg) << endl;
        }
    }
    return 0;
    
}