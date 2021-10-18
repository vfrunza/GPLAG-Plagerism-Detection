/B2016/2017: Zadaća 3, Zadatak 1
//Autotestovi by Enil Pajic (epajic1@etf.unsa.ba)
#include <iostream>
#include <cmath>
#include <functional>
#include <vector>
#include <stdexcept>

using namespace std;
function<double(double)> suma11(double prvi, double drugi, double koef)
         {
              return [prvi, drugi, koef](double y){if(y==prvi) return drugi; return koef*drugi/(y-prvi);};
         }
         
function<double(double)> suma22(double prvi, double drugi, double koef)
         {
              return [prvi, drugi, koef](double y){return koef/(y-prvi);};
         }
         
         
function<double(double)> fun(){return [](double x){return x*x+sin(x);};}
         
function<float(float)> BaricentricnaInterpolacija(vector<pair<double, double>> parovi, int d)
{
    if(d<0 || d>parovi.size()) throw domain_error("Nedozvoljen red");
    
    for(int i=0; i<parovi.size()-1; i++)
        for(int j=i+1; j<parovi.size(); j++)
            if(parovi[i].first==parovi[j].first)
                throw domain_error("Neispravni cvorovi");
         
    return [parovi, d](double x)
    {
        double suma1=0, suma2=0, proizvod=1, wi=0;
    int poc=1, end=1;
        //suma za f(x)
        for(int i=1; i<=parovi.size(); i++)
        {
          //računamo wi
         //suma za wi
         poc=1; end=i; wi=0;
         if(i-d>poc) poc=i-d;
         if(parovi.size()-d<end) end=parovi.size()-d;
         
         //cout<<endl<<"i="<<i<<"\npoc="<<poc<<"\nend= "<<end;
         //cout<<endl<<"j= ";
         for(int j=poc; j<=end; j++)
         { 
              //cout<<" "<<j<<" ";
              //proizvod za wi
              
              proizvod=1;
              
             //cout<<endl<<"k= ";
             
               for(int k=j; k<=j+d; k++)
              {
                 if(i==k) continue;
                 proizvod*=1./(parovi[i-1].first-parovi[k-1].first);
                 
                 //cout<<" "<<k<<" ";
             }
             wi+=pow(-1,j-1)*proizvod;
          }
          if(x==parovi[i-1].first)
            return parovi[i-1].second;
          
          suma1+=suma11(parovi[i-1].first, parovi[i-1].second, wi)(x);
          suma2+=suma22(parovi[i-1].first, parovi[i-1].second, wi)(x);
        }
        return suma1/suma2;
    };
    
}


function<double(double)> BaricentricnaInterpolacija(function<double(double)> fun, double x_min, double x_max, double dx, int d)
{
    if(x_min>x_max || dx<0)
        throw domain_error("Nekorektni parametri");
      
    return [fun, x_min, x_max, dx, d](double x)
    {
        vector<double> tacke;
        for(double i=x_min; i<=x_max; i+=dx)
            tacke.push_back(i);
            
        
        vector<pair<double, double>> parovi(tacke.size());
        for(int i=0; i<parovi.size(); i++)
        {
            parovi[i].first=tacke[i];
            parovi[i].second=fun(tacke[i]);
        }
            
        double suma1=0, suma2=0, proizvod=1, wi=0;
    int poc=1, end=1;
        //suma za f(x)
        for(int i=1; i<=parovi.size(); i++)
        {
          //računamo wi
         //suma za wi
         poc=1; end=i; wi=0;
         if(i-d>poc) poc=i-d;
         if(parovi.size()-d<end) end=parovi.size()-d;
         
         //cout<<endl<<"i="<<i<<"\npoc="<<poc<<"\nend= "<<end;
         //cout<<endl<<"j= ";
         for(int j=poc; j<=end; j++)
         { 
              //cout<<" "<<j<<" ";
              //proizvod za wi
              
              proizvod=1;
              
             //cout<<endl<<"k= ";
             
               for(int k=j; k<=j+d; k++)
              {
                 if(i==k) continue;
                 proizvod*=1./(parovi[i-1].first-parovi[k-1].first);
                 
                 //cout<<" "<<k<<" ";
             }
             wi+=pow(-1,j-1)*proizvod;
          }
          if(x==parovi[i-1].first)
            return parovi[i-1].second;
          
          suma1+=suma11(parovi[i-1].first, parovi[i-1].second, wi)(x);
          suma2+=suma22(parovi[i-1].first, parovi[i-1].second, wi)(x);
        }
        return suma1/suma2;
            
    };
    
    
}


int main ()
{
    //auto f(BaricentricnaInterpolacija({{1, 3}, {2, 5}, {4, 4}, {5, 2}, {7, 1}},2));
    //cout<<f(4);
    try
    {
        int opcija=0, broj_cvorova=0;
        double x, y, red, unos=0;
        for(;;)
        {
            cout<<"Odaberite opciju (1 - unos cvorova, 2 - aproksimacija): ";
            cin>>opcija;
            if(opcija==1)
            {
                cout<<"Unesite broj cvorova: ";
                cin>>broj_cvorova;
                cout<<"Unesite cvorove kao parove x y: ";
                vector<pair<double, double>> parovi(broj_cvorova);
                for(int i=0; i<broj_cvorova; i++)
                {
                    cin>>x; cin>>y;
                    parovi[i].first=x;
                    parovi[i].second=y;
                }
                cout<<"Unesite red interpolacije: ";
                cin>>red;
                while(1)
                {
                    cout<<"Unesite argument (ili \"kraj\" za kraj): ";
                    cin>>unos;
                    if(cin.fail())
                    {
                        return 0;
                    }
                    double rez=BaricentricnaInterpolacija(parovi,red)(unos);
                    cout<<"f("<<unos<<") = "<<rez<<endl;
                }
            }
            
            else if(opcija==2)
            {
                function<double(double)> pom(fun());
                cout<<"Unesite krajeve intervala i korak: ";
                double korak, poc, end;
                cin>>poc; cin>>end; cin>>korak; 
                cout<<"Unesite red interpolacije: ";
                cin>>red; cin.clear(); cin.ignore(10000, '\n'); 
                 while(1)
                {
                    cout<<"Unesite argument (ili \"kraj\" za kraj): ";
                    cin>>unos; 
                    if(cin.fail())
                    {
                        return 0;
                    }
                    double re=BaricentricnaInterpolacija(pom, poc, end, korak, red)(unos);
                    cout<<"f("<<unos<<") = "<<pom(unos)<<" fapprox("<<unos<<") = "<<re<<endl;
                }
            }
            break;
        }
    	return 0;
    }
    catch(domain_error dom)
    {
        cout<<dom.what();
    }
}