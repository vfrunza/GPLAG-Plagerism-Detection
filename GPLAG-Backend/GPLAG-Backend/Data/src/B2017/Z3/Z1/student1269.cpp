/B2017/2018: Zadaća 3, Zadatak 1
#include <iostream>
#include <vector>
#include <utility>
#include <cmath>
#include <functional>
#include <stdexcept>

using std:: cout;
using std:: cin;
using std:: endl;
using std:: vector;
using std:: pair;

double fun(double x)
{
    return x*x+std::sin(x);
}


std:: function<double(double)> BaricentricnaInterpolacija(vector<pair<double,double>>cvorovi, int d)
{
    if(d<0 || d>cvorovi.size()) 
        throw std:: domain_error("Nedozvoljen red");
    for(int i=0; i<cvorovi.size(); i++)
    {
        for(int j=i+1; j<cvorovi.size(); j++)
        {
            if(cvorovi[i].first==cvorovi[j].first) throw std:: domain_error("Neispravni cvorovi");
        }
    }

    return[cvorovi, d](double x)
    {
        int n=cvorovi.size();
        
        long double brojnik(0);
        long double nazivnik(0);
        for(int i=1; i<=n; i++)
        {
            if(x==cvorovi[i-1].first)
                return cvorovi[i-1].second;
            
            long double suma(0);
            for(int k=fmax(1,i-d); k<=fmin(i, n-d); k++)
            {
                long double proizvod(1);
                for(int j=k; j<=k+d; j++)
                {
                    if(j==i) continue;
                    proizvod*=1/(cvorovi[i-1].first-cvorovi[j-1].first);
                }
                suma+=pow(-1, k-1)*proizvod;
            }
            
        brojnik+=(suma/(x-cvorovi[i-1].first)*cvorovi[i-1].second);
        nazivnik+=(suma/(x-cvorovi[i-1].first));
        }
    double rezultat(brojnik/nazivnik);
    return rezultat;
    };
}

std::function<double(double)> BaricentricnaInterpolacija(double f(double x), double xmin, double xmax, double deltax, int d)
{
    if(xmin>xmax || deltax<=0) throw std:: domain_error("Nekorektni parametri");
    std::vector<std::pair<double,double>> cvorovi ;
    for(double i=xmin; i<=xmax; i+=deltax)
    {
        std::pair<double,double> cvor;
        cvor.first=i;
        cvor.second=f(i);
        cvorovi.push_back(cvor);
        
    }
    return BaricentricnaInterpolacija(cvorovi,d);
}



int main ()
{
    cout<<"Odaberite opciju (1 - unos cvorova, 2 - aproksimacija): ";
    int opcija;
    cin>>opcija;
    if(opcija==1)
    {
        cout<<"Unesite broj cvorova: ";
        int n;
        cin>>n;
        vector<pair<double,double>>cvorovi;
        pair<double,double>cvor;
        cout<<"Unesite cvorove kao parove x y: ";
        for(int i=0; i<n; i++)
        {
            cin>>cvor.first;
            cin>>cvor.second;
            cvorovi.push_back(cvor);
        }
      
        while(1)
        {
            cout<<"Unesite argument (ili \"kraj\" za kraj): ";
            double x;
            cin>>x;
            if(!cin) 
                break;
                
            auto funkcija(BaricentricnaInterpolacija(cvorovi, d));
            std::cout << "f("<<x<<") = " << funkcija(x)<<endl;
        }
    }
    
    
    if(opcija==2)
    {
        cout<<"Unesite krajeve intervala i korak: ";
        double xmin, xmax, deltax;
        cin>>xmin>>xmax>>deltax;
        cout<<"Unesite red interpolacije: ";
        int d;
        cin>>d;
        
        while(1)
        {
            cout<<"Unesite argument (ili \"kraj\" za kraj): ";
            double x;
            cin>>x;
            if(!cin) 
                break;
                
            auto funkcija=BaricentricnaInterpolacija(fun, xmin, xmax, deltax, d);
            std::cout << "f("<<x<<") = " << fun(x)<<" fapprox("<<x<<") = "<<funkcija(x)<<endl;
        }
    }
   
	return 0;
}
