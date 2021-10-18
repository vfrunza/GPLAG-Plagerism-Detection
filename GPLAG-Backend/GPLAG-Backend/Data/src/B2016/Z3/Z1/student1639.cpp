/B2016/2017: Zadaća 3, Zadatak 1
//Autotestovi by Enil Pajic (epajic1@etf.unsa.ba)
#include <iostream>
#include <utility>
#include <vector> 
#include <functional>
#include <stdexcept>
#include <algorithm>
#include <cmath>

using namespace std;

vector<double> DajTezinske(vector<pair<double,double>> cvorovi, int d) // vjerovatno ovdje ne valja nesto
{
    vector<double> wi;
    int n=cvorovi.size();
    double a(0.), b(1.);
    double sum = 0;
    for(int i=1; i<=n; i++)
    {
        sum = 0;
        for(int k=max(1,i-d); k<=min(i,n-d); k++)
        {
                 a=pow(-1,k-1);
                 b = 1;
                for(int j=k; j<=k+d; j++)
                {
                    if(j!=i) b *= 1./(cvorovi.at(i - 1).first-cvorovi.at(j - 1).first);
                }
            
                sum += a * b;
        }
        
        wi.push_back(sum);
        
    }
    return wi;
}

function <double(double)> BaricentricnaInterpolacija(vector<pair<double,double>> cvorovi, int d) // prva varijanta
{
   if(d<0 or d>cvorovi.size()) throw domain_error("Nedozvoljen red");
   // JOS JEDAN THROW NE ZABORAVI
   auto tezinski(DajTezinske(cvorovi,d));
   return [cvorovi,tezinski](double x){
       double fu(0.),a(0.),b(0.);
       
       //specijaln slucaj, ako je x == neko xi
       for (int i= 0; i < cvorovi.size(); i ++ ) 
       {
           if ( cvorovi[i].first == x ) {
               return cvorovi[i].second;
           }
       }
       
       for(int i=0; i<cvorovi.size();i++)
       {
            a+=(tezinski.at(i)*cvorovi.at(i).second)/(x-cvorovi.at(i).first);
            b+=tezinski.at(i)/(x-cvorovi.at(i).first);
       }
       
       fu=a/b;
       return fu;
   };
}

function<double(double)> BaricentricnaInterpolacija(double f(double), double xmin, double xmax, double korak, int d)
{
    if(korak<=0 or xmax<xmin) throw domain_error("Nekorektni primjeri");
    vector<pair<double,double>> cvorovi;
    for(double i=xmin; i<=xmax; i+=korak)
    {
        cvorovi.push_back(make_pair(i, f(i)));
    }
  
   return BaricentricnaInterpolacija(cvorovi,d);
  
}

int main ()
{
ovdje: cout << "Odaberite opciju (1 - unos cvorova, 2 - aproksimacija): ";
            int opcija;
            cin >> opcija;
            if(opcija==1)
            {
                cout << "Unesite broj cvorova: ";
                int broj_cvorova;
                cin >> broj_cvorova;
                cout << "Unesite cvorove kao parove x y: ";
                vector<pair<double, double>> cvorovi;
                for(int i=0; i<broj_cvorova;i++)
                {
                    int x,y;
                    cin >> x >> y;
                    cvorovi.push_back(make_pair(x,y));
                }
                cout << "Unesite red interpolacije: ";
                int d;
                cin >> d;
                auto f(BaricentricnaInterpolacija(cvorovi,d));
                double argument;
                while(cin) 
                {
                    cout << "Unesite argument (ili \"kraj\" za kraj): ";
                    cin >> argument;
                    if(cin) cout << "f(" << argument << ") = "<< f(argument) <<endl;
                }
                
            }
            else if (opcija==2)
            {
                cout << "Unesite krajeve intervala i korak: ";
                double korak,poc,kr;
                cin >> poc >> kr >> korak;
                cout << "Unesite red interpolacije: ";
                int d;
                cin >> d;
                double argument;
                auto f([](double x){return x*x+sin(x);});
                while(cin) 
                {
                    cout << "Unesite argument (ili \"kraj\" za kraj): ";
                    cin >> argument;
                    if(cin) cout << "f(" << argument << ") = " << f(argument) << " fapprox("<< argument << ") = " << BaricentricnaInterpolacija(f,poc,kr,korak,d)(argument) <<endl;
                }
                
            }
            else goto ovdje;
	return 0;
}