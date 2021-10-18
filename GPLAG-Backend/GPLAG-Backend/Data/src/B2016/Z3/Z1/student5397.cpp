/B2016/2017: Zadaća 3, Zadatak 1
//Autotestovi by Enil Pajic (epajic1@etf.unsa.ba)
#include <iostream>
#include <vector>
#include <utility>
#include <stdexcept>
#include <functional>
#include <string>
#include <cmath>

using std::cout;
using std::cin;
using std::endl;
using std::vector;
using std::pair;
using std::string;
using std::function;
using std::domain_error;


double funkcija (double x)
{
    double rez;
    
    rez=pow(x,2)+sin(x);
    
    return rez;
}

int minimum (int i, int razlika)
{
    if (i>razlika)
    {
        return razlika;
    }
    
    if (razlika>i)
    {
        return i;
    }
    
    return razlika;
}

int maksimum (int i, int razlika)
{
    if (i>razlika)
    {
        return i;
    }
    
    if (razlika>i)
    {
        return razlika;
    }
    
    return razlika;
}


double w (int brojcvorova, int d, int i, vector<pair<double, double>> grupa)
{
    int n1;
    double rezd1, rezd2, rez(0);
    
    n1=minimum(i,brojcvorova-d);
    
    for (int k=maksimum(1,i-d); k<=n1; k++)
    {
        rezd1=pow((-1),(k-1));
        rezd2=1;
        for (int j=k; j<=k+d; j++)
        {
            if (j!=i)
            {
                rezd2=rezd2*(1./(grupa[i-1].first-grupa[j-1].first));
            }
        }
        
        rez=rez+rezd1*rezd2;
    }
    
    return rez;
}


function<double(double)> BaricentricnaInterpolacija (vector<pair<double, double>> grupa, int d)
{
    return [grupa,d](double x)
    {
        int brojcvorova, tik(0);
        double rez, rezgornji(0), rezdonji(0), wi, temp;
        brojcvorova=grupa.size();
        
        if (d<0 || d>brojcvorova) throw domain_error ("Neispravni cvorovi");
        
        for (int i=1; i<=brojcvorova; i++)
        {
            wi=w(brojcvorova, d, i, grupa);
            if (x==grupa[i-1].first)
            {
                tik++;
                temp=grupa[i-1].second;
                break;
            }
            else
            {
                rezgornji=rezgornji+((wi*grupa[i-1].second)/(x-grupa[i-1].first));
                rezdonji=rezdonji+(wi/(x-grupa[i-1].first));
            }

        }
        
        if (tik>0)
        {
            rez=temp;
        }
        
        else
        {
            rez=rezgornji/rezdonji;
        }
        
        return rez;
    };
}

function<double(double)> BaricentricnaInterpolacija (function<double(double)> f, double xmin, double xmax, double korak, int d)
{
    double pov(xmin), temp;
    int cvorovi(0);
    pair <double, double> par;
    vector <pair <double, double>> grupa;
    
    while (pov!=xmax && pov<xmax)
    {
        cvorovi++;
        pov=pov+korak;
    }
    
    for (int i=0; i<cvorovi; i++)
    {
        temp=xmin+i*korak;
        par.first=temp;
        par.second=f(temp);
        grupa.push_back(par);
    }
    
    return [grupa,d](double x)
    {
        int brojcvorova, tik(0);
        double rez, rezgornji(0), rezdonji(0), wi, temp;
        brojcvorova=grupa.size();
        
        if (d<0 || d>brojcvorova) throw domain_error ("Neispravni cvorovi");
        
        for (int i=1; i<=brojcvorova; i++)
        {
            wi=w(brojcvorova, d, i, grupa);
            if (x==grupa[i-1].first)
            {
                tik++;
                temp=grupa[i-1].second;
                break;
            }
            else
            {
                rezgornji=rezgornji+((wi*grupa[i-1].second)/(x-grupa[i-1].first));
                rezdonji=rezdonji+(wi/(x-grupa[i-1].first));
            }

        }
        
        if (tik>0)
        {
            rez=temp;
        }
        
        else
        {
            rez=rezgornji/rezdonji;
        }
        
        return rez;
    };
}



int main ()
{
    int opcija, cvorovi, temp1, temp2, d;
    bool tacnost(true);
    pair <double, double> par;
    vector <pair <double, double>> grupa;
    string var;
    double poslati, korak, xmin, xmax;

    cout<<"Odaberite opciju (1 - unos cvorova, 2 - aproksimacija): ";
    cin>>opcija;
    
    if (opcija==1)
    {  
        try
        {
            cout<<"Unesite broj cvorova: ";
            cin>>cvorovi;
    
            cout<<"Unesite cvorove kao parove x y: ";
    
            for (int i=0; i<cvorovi; i++)
            {
                cin>>temp1>>temp2;
                par.first=temp1;
                par.second=temp2;
                grupa.push_back(par);
            }
    
            cout<<"Unesite red interpolacije: ";
            cin>>d;
            
            if (d<0 || d>cvorovi) throw domain_error ("Neispravni cvorovi");

            while (tacnost==true)
            {
                cout<<"Unesite argument (ili \"kraj\" za kraj): ";
                cin>>poslati;
        
                if (!cin)
                {
                    tacnost=false;
                }
        
                else if (poslati>0)
                {
                    auto f(BaricentricnaInterpolacija(grupa,d));
                    cout<<"f("<<poslati<<") = "<<f(poslati)<<endl;
                }
            }
        }
        
        catch (domain_error izuzetak)
        {
            cout<<izuzetak.what();
        }
    }
    
    if (opcija==2)
    {
        try
        {
            cout<<"Unesite krajeve intervala i korak: ";
            cin>>xmin>>xmax>>korak;
            
            if (xmin>xmax) throw domain_error ("Nekorektni parametri");
    
            cout<<"Unesite red interpolacije: ";
            cin>>d;

            while (tacnost==true)
            {
                cout<<"Unesite argument (ili \"kraj\" za kraj): ";
                cin>>poslati;
        
                if (!cin)
                {
                    tacnost=false;
                }
        
                else if (poslati>0||poslati<0)
                {
                    auto f(BaricentricnaInterpolacija([](double x){double rez; rez=pow(x,2)+sin(x); return rez;},xmin,xmax,korak,d));
                    cout<<"f("<<poslati<<") = "<<funkcija(poslati)<<" ";
                    cout<<"fapprox("<<poslati<<") = "<<f(poslati)<<endl;
                }
            }
        }
        
        catch (domain_error izuzetak)
        {
            cout<<izuzetak.what();
        }
    }
    
	return 0;
}