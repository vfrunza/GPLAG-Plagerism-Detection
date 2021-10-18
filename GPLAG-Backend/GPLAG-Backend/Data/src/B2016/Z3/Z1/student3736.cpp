/B2016/2017: Zadaća 3, Zadatak 1
//Autotestovi by Enil Pajic (epajic1@etf.unsa.ba)
#include <iostream>
#include <utility>
#include <cmath>
#include <stdexcept>
#include <functional>
#include <vector>
#include <cctype>

using namespace std;

function<double (double)> BaricentricnaInterpolacija(vector< pair<double,double>> koordinate, int d)
{
    int n{int(koordinate.size())};
    
    for(int i=0;i<n;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            if(koordinate[i].first == koordinate[j].first) throw domain_error("Neispravni cvorovi");
        }
    }
    vector<double> w(n);
    for(int i=0;i<n;i++)
    {
        w[i]=0;
        int donjaGranica = (i-d>0) ? (i-d) : 0;
        int gornjaGranica = (n-d-1<i) ? (n-d-1) : i;
        for(int prolazOut =donjaGranica;prolazOut<=gornjaGranica;prolazOut++)
        {
            long double proizvod=1.;
            for(int prolazIn = prolazOut;prolazIn<=prolazOut+d;prolazIn++)
               {/*
                   if(prolazIn==prolazOut+d && n-d==prolazOut)
                    proizvod*=1;   //ili puta 1 ????
                  */
                  if(i!=prolazIn)
                        proizvod*=1./(koordinate[i].first-koordinate[prolazIn].first);
               }
            if(prolazOut%2==0)
                w[i]-=proizvod;
            else w[i] += proizvod;
        }
    }
    
    return [n,w,koordinate] (double x) ->double
    {
        long double suma1{0};
        long double suma2{0};
        for(int i=0;i<n;i++)
        {
            if(x==koordinate[i].first)
            {
                return koordinate[i].second;
            }
            suma1+=w[i]*koordinate[i].second/(x-koordinate[i].first);
            suma2+=w[i]/(x-koordinate[i].first);
        }
        return suma1/suma2;
    };
}

function <double (double)> BaricentricnaInterpolacija(double (*f)(double),double x_min,double x_max,double delta_x,int d)
{
    vector< pair<double, double>> koordinate;
    double opseg{x_max-x_min};
    if(opseg<0 || delta_x<=0) throw domain_error("Nekorektni parametri");
    double kolicnik{opseg/delta_x};
    int n{int(floor(kolicnik))+1};
    for(int i=0;i<n;i++) koordinate.push_back(make_pair( x_min+i*delta_x, f(x_min+i*delta_x)));
    if(d<0 || d>=n) throw domain_error("Nedozvoljen red");
    return BaricentricnaInterpolacija(koordinate,d);
}




int main ()
{
    cout<<"Odaberite opciju (1 - unos cvorova, 2 - aproksimacija): ";
    int opcija;
    cin>>opcija;
    if(opcija==1)
    {
        cout<<"Unesite broj cvorova: ";
        int br_cvorova;
        cin>>br_cvorova;
        vector<pair<double, double>> cvorovi;
        cout<<"Unesite cvorove kao parove x y: ";
        for(int i=0;i<br_cvorova;i++)
        {
            double prva_koordinata;
            cin>>prva_koordinata;
            double druga_koordinata;
            cin>>druga_koordinata;
            cvorovi.push_back(make_pair(prva_koordinata,druga_koordinata));
        }
        cout<<"Unesite red interpolacije: ";
        double d;
        cin>>d;
        cout<<"Unesite argument (ili \"kraj\" za kraj): ";
        cout.flush();
        //cin>>ws;
        //while(isdigit(cin.peek()))
        do
        {
            double broj;
            cin>>broj;
            if(!cin) break;
            auto fun=BaricentricnaInterpolacija(cvorovi,d);
            cout<<"f("<<broj<<") = "<<fun (broj)<<endl;
            cout<<"Unesite argument (ili \"kraj\" za kraj): ";
            cout.flush();
            cin>>ws;
        }while(1);
        //if(!isdigit(cin.peek()))
        if(!cin)
        {
            string s;
            getline(cin,s);
            if(s=="kraj") return 0;
        }
    }
   if(opcija==2)
   {
       cout<<"Unesite krajeve intervala i korak: ";
       double x_min,x_max,delta_x;
       cin>>x_min;
       cin>>x_max;
       cin>>delta_x;
       cout<<"Unesite red interpolacije: ";
       int d;
       cin>>d;
       cout<<"Unesite argument (ili \"kraj\" za kraj): ";
       cout.flush();
       //cin>>ws;
       do
       {
           double broj;
           cin>>broj;
           if(!cin) break;
           double rezultat{broj*broj+sin(broj)};
           cout<<"f("<<broj<<") = "<<rezultat;
           auto fun=BaricentricnaInterpolacija([](double x){return x*x+sin(x);},x_min,x_max,delta_x,d);
           cout<<" fapprox("<<broj<<") = "<<fun(broj)<<endl;
           cout<<"Unesite argument (ili \"kraj\" za kraj): ";
           cout.flush();
           cin>>ws;
       }while(1);
       if(!cin)
       {
           cin.clear();
           string s;
           getline(cin,s);
           //cin>>s;
           if(s=="kraj") return 0;
       }
       
   }
	return 0;
}