/B2017/2018: Zadaća 3, Zadatak 1
#include <iostream>
#include <functional>
#include <vector>
#include <tuple>
#include <algorithm>
#include <stdexcept>
#include <cmath>

using std::vector;
using std::cin;
using std::cout;
using std::pair;


std::function<double(double)> LinearnaInterpolacija(vector<pair<double,double>> vektor)
{
    std::sort(vektor.begin(), vektor.end(), [](pair<double, double> x, pair<double, double> y){
        return x.first<=y.first;
    });
    
    for(int i=0; i<vektor.size()-1; i++)
        if (vektor[i].first==vektor[i+1].first)
            throw std::domain_error("Neispravni cvorovi");
    
    if (vektor.size()<=0)
        throw std::domain_error("Prazan vektor");
    
    return [vektor] (double x)
    {
        if (x < vektor[0].first || x > vektor[vektor.size() - 1].first)
            throw std::range_error("Argument izvan opsega");
            
        if (x==vektor[vektor.size() - 1].first)
            return vektor[vektor.size() - 1].second;
        
        auto it2(std::upper_bound(vektor.begin(), vektor.end(),x,[](double drugi, pair<double, double> prvi){
        return prvi.first>=drugi;
        })); 
      //  cout<<it2->first;
        auto it1(it2);
        it1--;
        
        return it1->second + ((it2->second - it1->second)/(it2->first - it1->first))*(x - it1->first);
    };
}
template <typename Fun>
std::function<double(double)> LinearnaInterpolacija(Fun f, double xmin, double xmax, double deltax)
{
    if (xmin>xmax || deltax<=0)
        throw std::domain_error("Nekorektni parametri");
        
    vector<pair<double,double>> vektor;
    for(double x=xmin; x<xmax; x+=deltax)
        vektor.push_back(std::make_pair(x, f(x)));
    vektor.push_back(std::make_pair(xmax, f(xmax)));    
    return LinearnaInterpolacija(vektor);    
}

int main ()
{
    int opcija;
    cout<<"Odaberite opciju (1 - unos cvorova, 2 - aproksimacija): ";
    cin>>opcija;
    if (opcija==1)
    {
        int br;
        cout<<"Unesite broj cvorova: ";
        cin>>br;
        vector<pair<double, double>> vektor;
        try
        {
            cout<<"Unesite cvorove kao parove x y: ";
            for(int i=0; i<br; i++)
            {
                int x, y;
                cin>>x>>y;
                std::pair<double, double> par;
                par=std::make_pair(x, y);
                vektor.push_back(par);
            }
            auto f=LinearnaInterpolacija(vektor);
            for(;;)
            {
                cout<<"Unesite argument (ili \"kraj\" za kraj): ";
                double arg;
                cin>>arg;
                if (!cin)
                    break;
                
                try
                {
                    double rezultat=f(arg);
                    cout<<"f("<<arg<<") = "<<rezultat<<"\n";
                }
                catch(std::range_error baceno)
                {
                     cout<<baceno.what()<<"\n";
                }
                    
            }
            
        }
        catch(std::domain_error izuzetak)
        {
            cout<<izuzetak.what();
        }
    }
    else if (opcija==2)
    {
        try
        {
            cout<<"Unesite krajeve intervala i korak: ";
            double min, max, kor;
            cin>>min>>max>>kor;
            auto f=LinearnaInterpolacija([](double x){return x*x + std::sin(x);},min, max, kor);
            for(;;)
            {
                cout<<"Unesite argument (ili \"kraj\" za kraj): ";
                double arg;
                cin>>arg;
                if (!cin)
                    break;
                try
                {
                    double rezultat=f(arg);
                    cout<<"f("<<arg<<") = "<<arg*arg + std::sin(arg)<<" fapprox("<<arg<<") = "<<rezultat<<"\n"; 
                }
                catch(std::range_error baceno)
                {
                    cout<<baceno.what()<<"\n";
                }
            }
        }
        catch(std::domain_error izuzetak)
        {
            cout<<izuzetak.what();
        }
                
    }
   
	return 0;
}
