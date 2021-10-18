/B2016/2017: Zadaća 3, Zadatak 1
//Autotestovi by Enil Pajic (epajic1@etf.unsa.ba)
#include <iostream>
#include<cmath>
#include<functional>
#include<algorithm>
#include<vector>
#include<list>
#include<set>
#include<stdexcept>
using namespace std;

vector<double> T(vector<pair<double, double>> CvorInterpolacije, int red_interpolacije)
{
 vector<double> v;
 CvorInterpolacije.insert(CvorInterpolacije.begin(), make_pair<double, double>(0.0, 0.0));
 double produkt;
 for(int i=1;i<CvorInterpolacije.size();i++)
 {
     int prvi(max(1, i-red_interpolacije));
     int drugi(min<int>(i, (CvorInterpolacije.size()-1-red_interpolacije)));
     double suma(0);
     for(int k=prvi;k<=drugi;k++)
     {
         produkt=1;
         for(int j=k;j<=k+red_interpolacije;j++)
         {
             if(i==j) continue;
             produkt=produkt*(1./(CvorInterpolacije[i].first-CvorInterpolacije[j].first));
         }
         produkt=pow(-1, k-1)*produkt;
         suma+=produkt;
     }
     v.push_back(suma);
 }
 return v;
}

function<double(double)> BaricentricnaInterpolacija(vector<pair<double, double>>CvorInterpolacije, int d)
{
    if(d<0) throw domain_error("Nedozvoljen red");
    if(d>CvorInterpolacije.size()) throw domain_error("Nedozvoljen red");
    vector<double>v{T(CvorInterpolacije, d)};
    for(int i=0;i<CvorInterpolacije.size();i++)
    {
        for(int j=i+1;j<CvorInterpolacije.size();j++)
        {
            if(CvorInterpolacije[i].first==CvorInterpolacije[j].first)
            throw domain_error("Neispravni cvorovi");
            else continue;
        }
    }
    return[CvorInterpolacije,v, d](double y)
    {
        double prva(0);
        double druga(0);
        for(int i=0;i<CvorInterpolacije.size();i++)
        {
            if(y==CvorInterpolacije[i].first) return CvorInterpolacije[i].second;
            prva+=v[i]/(y-CvorInterpolacije[i].first)*CvorInterpolacije[i].second;
        }
        for(int i=0;i<CvorInterpolacije.size();i++)
        {
            if(y==CvorInterpolacije[i].first) return CvorInterpolacije[i].second;
            druga+=v[i]/(y-CvorInterpolacije[i].first);
        }
         double povratna=prva/druga;
         return povratna;
    };
}

double Izracunaj(double x)
{
	return (x*x+sin(x));
}
function<double(double)> BaricentricnaInterpolacija(function<double(double)> baricentricna, double Xmin, double Xmax, double dx, int d)
{
    if(Xmin>Xmax || dx<0) throw domain_error("Nekorektni parametri");
    vector<pair<double, double>> Cvor;
    for(double i=Xmin; i<=Xmax; i+=dx)
    {
        Cvor.push_back(make_pair(i, baricentricna(i)));
    }
    return (BaricentricnaInterpolacija(Cvor, d));
}


int main ()
{
	cout<<"Odaberite opciju (1 - unos cvorova, 2 - aproksimacija): ";
	int izbor;
	cin>>izbor;
	
	if(izbor==1)
	{
	    cout<<"Unesite broj cvorova: ";
	    int broj_cvorova;
	    cin>>broj_cvorova;
	    cout<<"Unesite cvorove kao parove x y: ";
	    vector<pair<double, double>>Cvor;
	    for(int i=0;i<broj_cvorova;i++)
	    {
	        double x,y;
	        cin>>x;
	        cin>>y;
	        Cvor.push_back(make_pair(x,y));
	    }
	
	    	    
	    cout<<"Unesite red interpolacije: ";
	    int d;
	    cin>>d;
	    for(;;)
	    {
	        cout<<"Unesite argument (ili \"kraj\" za kraj): ";
	        double argument;
	        cin>>argument;
	        if(cin.fail())
	        {
	            return 0;
	        }
	        else
	        {
	            
	            auto novi(BaricentricnaInterpolacija(Cvor, d));
	            
	            cout<<"f("<<argument<<") = "<<novi(argument)<<endl;
	           
	        }
	    }
	}
	else if(izbor==2)
	{
	    
	    cout<<"Unesite krajeve intervala i korak: ";
	   double xmin, xmax, korak;
	   cin>>xmin>>xmax>>korak;
	   
	   
	   
	   cout<<"Unesite red interpolacije: ";
	   int d;
	   cin>>d;
	   for(;;)
	   {
	       cout<<"Unesite argument (ili \"kraj\" za kraj): ";
	       double argument;
	       cin>>argument;
	       if(cin.fail())
	       {
	           return 0;
	       }
	       else
	       {
	        double prvi=Izracunaj(argument);
	    
	            auto aprox(BaricentricnaInterpolacija(Izracunaj, xmin, xmax, korak, d));
	           cout<<"f("<<argument<<") = "<<prvi<<" ";
	         cout<<"fapprox("<<argument<<") = "<<aprox(argument);
	          cout<<endl;
	       }
	   }
	   
	}



}