/B2016/2017: Zadaća 3, Zadatak 1
//Autotestovi by Enil Pajic (epajic1@etf.unsa.ba)
#include <iostream>
#include <utility>
#include <vector>
#include <functional>
#include <cmath>
#include <stdexcept>

using namespace std;

int Minimum(int a, int b)
{
	if(a<b) return a;
	return b;
}

int Maximum(int a, int b)
{
	if(a>b) return a;
	return b;
}

// Funkcija BaricentricnaInterpolacija racuna baricentricnu racionalnu interpolaciju funkcije
function<double(double)> BaricentricnaInterpolacija(vector<pair<double, double>> cvorovi, int d)
{
	if(d<0 || d>=cvorovi.size()) throw std::domain_error("Nedozvoljen red");
	for(int i=0; i<cvorovi.size(); i++)
	{
		for(int j=i+1; j<cvorovi.size(); j++)
		{
			if(cvorovi[i].first==cvorovi[j].first) throw std::domain_error("Neispravni cvorovi");
		}
	}
	int n(cvorovi.size());
	
	// Racunanje tezinskih koeficijenata
	vector<double> w;
	for(int i=1; i<=n; i++)
	{
		double suma(0);
		int max(Maximum(1, i-d));
		int min(Minimum(i, n-d));
		for(int k=max; k<=min; k++)
		{
			double proizvod(1);
			for(int j=k; j<=(k+d); j++)
			{
				if(j!=i) proizvod*=(1./(cvorovi[i-1].first-cvorovi[j-1].first));
				
				if(j==k+d) break;
			}
			suma+=(pow(-1, k-1)*proizvod);
			
			if(k==min) break;
		}
		w.push_back(suma);
		if(i==n) break;
	}
	
	return [w, cvorovi, n](double x)
	{
		double suma1(0), suma2(0);
		for(int i=1; i<=n; i++)
		{
			if(x==cvorovi[i-1].first) return cvorovi[i-1].second;
			else
			{
				suma1+=(w[i-1]*cvorovi[i-1].second/(x-cvorovi[i-1].first));
				suma2+=(w[i-1]/(x-cvorovi[i-1].first));
			}
			
			if(i==n) break;
		}
		return suma1/suma2;
	};
}
// Funkcija BaricentricnaInterpolacija vrsi aproksimaciju neke vec postojece funkcije uz pomoc baricentricne 
// racionalne interpolacije
function<double(double)> BaricentricnaInterpolacija(double fun(double), double x_min, double x_max, double delta_x, int d)
{
	if(x_min>x_max || delta_x<=0) throw std::domain_error("Nekorektni parametri");
	vector<pair<double, double>> cvorovi;
	for(double x=x_min; x<=x_max; x+=delta_x)
	{
		pair<double, double> pom;
		pom.first=x;
		pom.second=fun(x);
		cvorovi.push_back(pom);
		
		if(x==x_max) break;
	}
	return BaricentricnaInterpolacija(cvorovi, d);
}

int main ()
{
	try
	{
		int opcija;
		cout << "Odaberite opciju (1 - unos cvorova, 2 - aproksimacija): ";
		cin >> opcija;
		switch(opcija)
		{
		    case 1:
		    {
		        int br_cvorova;
		        cout << "Unesite broj cvorova: ";
		        cin >> br_cvorova;
		        vector<pair<double, double>> cvorovi;
		        cout << "Unesite cvorove kao parove x y: ";
		        for(int i=0; i<br_cvorova; i++)
		        {
		            pair<double, double> par;
		            cin >> par.first >> par.second;
		            cvorovi.push_back(par);
		        }
		        int red_interpolacije;
		        cout << "Unesite red interpolacije: ";
		        cin >> red_interpolacije;
		        while(1)
		        {
		            double x;
		            cout << "Unesite argument (ili \"kraj\" za kraj): ";
		            cin >> x;
		            if(!cin) break;
		            auto f(BaricentricnaInterpolacija(cvorovi, red_interpolacije));
		            cout << "f(" << x << ") = " << f(x) << endl;
		            
		        }
		        break;
		    }
		    case 2:
		    {
		        double x_min, x_max, delta_x;
		        cout << "Unesite krajeve intervala i korak: ";
		        cin >> x_min >> x_max >> delta_x;
		        
		        int red_interpolacije;
		        cout << "Unesite red interpolacije: ";
		        cin >> red_interpolacije;
		        while(1)
		        {
		            double x;
		            cout << "Unesite argument (ili \"kraj\" za kraj): ";
		            cin >> x;
		            if(!cin) break;
		            auto f([](double x){ return x*x+sin(x); });
		            auto g(BaricentricnaInterpolacija([](double x){ return x*x+sin(x); } , x_min, x_max, delta_x, red_interpolacije));
		            cout << "f(" << x << ") = " << f(x) << " fapprox(" << x << ") = " << g(x) << endl;
		            
		        }
		        break;
		     }
		  }
		}
		catch(std::domain_error izuzetak)
		{
			cout << izuzetak.what() << endl;
		}
		
	return 0;
}

