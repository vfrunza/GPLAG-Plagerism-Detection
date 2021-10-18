/B2016/2017: Zadaća 3, Zadatak 1
//Autotestovi by Enil Pajic (epajic1@etf.unsa.ba)
#include <iostream>
#include <vector>
#include <stdexcept>
#include <utility>
#include <functional>
#include <cmath>
using std::cout;
using std::cin;
using std::vector;
using std::pair;
bool JesuLiIsti(double x,double y,double eps=1e-10)
{
    return std::fabs(x-y)<=eps*(std::fabs(x)+std::fabs(y));
}
std::function<double(double)> funkcija(double x)
{
    return [] (double x) 
    {
    return (x*x+sin(x));
    };
}
std::function<double(double)> BaricentricnaInterpolacija(vector<pair<double,double>> cvorovi,int d)
{
    
    if(d<0 || d>=cvorovi.size())
    throw std::domain_error("Nedozvoljen red");
    for(int i=0;i<cvorovi.size()-1;i++)
    for(int j=i+1;j<cvorovi.size();j++)
    {
        auto it1=cvorovi.begin()+i;
        auto it2=cvorovi.begin()+j;
        if(JesuLiIsti(it1->first,it2->first))
        throw std::domain_error("Neispravni cvorovi");
    }
    vector<double> wi;
    int m,n;
    for(int i=1;i<=cvorovi.size();i++)
    {
       if(1>i-d)
       m=1;
       else
       m=i-d;
       if(i<cvorovi.size()-d)
       n=i;
       else
       n=cvorovi.size()-d;
       double suma(0);
       double proizvod(1);
       for(int k=m;k<=n;k++)
       {
           if(k%2==0)
           proizvod=-1;
           else 
           proizvod=1;
           for(int j=k;j<=k+d;j++)
           {
               if(j!=i)
               {
               double r;
               auto it1=cvorovi.begin()+i-1;
               auto it2=cvorovi.begin()+j-1;
               r=(1./(it1->first-it2->first));
               proizvod*=r;
               }
           }
           suma+=proizvod;
       }
       wi.push_back(suma);
    }
    return[=] (double x) 
    {
    double suma1(0); 
    double suma2(0);
    for(int i=0;i<cvorovi.size();i++)
    {
       auto it=cvorovi.begin()+i;
       
       if(JesuLiIsti(x,it->first))
       return it->second;
       suma1+=(wi[i]*it->second)/(x-it->first);
       suma2+=(wi[i])/(x-it->first);
    }
    return suma1/suma2;
    
    };
}
std::function<double(double)> BaricentricnaInterpolacija(std::function<double(double)> fja,double xmin,double xmax,double dx,int d)
{
    if(xmin>xmax || dx<=0)
    throw std::domain_error("Nekorektni parametri");
    vector<pair<double,double>> cvorovi;
    while(xmax>=xmin)
    {
        std::pair<double,double> cvor;
        cvor=std::make_pair(xmin,fja(xmin));
        cvorovi.push_back(cvor);
        xmin+=dx;
    }
    try
    {
    std::function<double(double)> f=BaricentricnaInterpolacija(cvorovi,d);
    return [=] (double x)
    {
        return f(x);
    };
    }
    catch(...)
    {
        throw;
    }
}
int main ()
{
    cout<<"Odaberite opciju (1 - unos cvorova, 2 - aproksimacija): ";
    int opcija;
    cin>>opcija;
    if(opcija==1)
    {
    cout<<"Unesite broj cvorova: ";
    int broj;
    cin>>broj;
    cout<<"Unesite cvorove kao parove x y: ";
    vector<pair<double,double>> cvorovi;
    for(int i=0;i<broj;i++)
    {
    double pom1,pom2;
    cin>>pom1>>pom2;
    std::pair<double,double> cvor;
    cvor=std::make_pair(pom1,pom2);
    cvorovi.push_back(cvor);
    }
    cout<<"Unesite red interpolacije: ";
    int d;
    cin>>d;
    while(cin)
    {
    cout<<"Unesite argument (ili "<<char(34)<<"kraj"<<char(34)<<" za kraj): ";
    double arg;
    cin>>arg;
    if(cin)
    {
    try
    {
    auto f(BaricentricnaInterpolacija(cvorovi,d));
    cout<<"f("<<arg<<") = "<<f(arg)<<std::endl;
    }
    catch(std::domain_error izuzetak)
    {
        cout<<izuzetak.what();
        return 0;
    }
    }
    else
    break;
    }
    }
    if(opcija==2)
    {
        cout<<"Unesite krajeve intervala i korak: ";
        double xmin,xmax,dx;
        cin>>xmin>>xmax>>dx;
        cout<<"Unesite red interpolacije: ";
        int d;
        cin>>d;
        while(cin)
        {
        cout<<"Unesite argument (ili "<<char(34)<<"kraj"<<char(34)<<" za kraj): ";
        double arg;
        cin>>arg;
        if(cin)
        {
            try
            {
            auto f(BaricentricnaInterpolacija(funkcija(arg),xmin,xmax,dx,d));
            auto f1=funkcija(arg);
            cout<<"f("<<arg<<") = "<<f1(arg)<<" fapprox("<<arg<<") = "<<f(arg)<<std::endl;
            }
            catch(std::domain_error izuzetak)
            {
                cout<<izuzetak.what();
                return 0;
            }
        }
        else
        break;
        }
    }
	return 0;
}