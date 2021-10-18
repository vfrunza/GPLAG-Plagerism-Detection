/B2017/2018: Zadaća 3, Zadatak 1
#include <cmath>
#include <vector>
#include <utility>
#include <iostream>
#include <algorithm>
#include <stdexcept>
#include <functional>

std::pair<int, int> binarna_pretraga_okolnih_cvorova( std::vector< std::pair< double,  double> > ,double);
std::function<double(double)> LinearnaInterpolacija(std::function<double(double)>,double,double,double);
std::function<double(double)> LinearnaInterpolacija(std::vector<std::pair<double,double>> );
void LIUnosCvorova(void);
void LIAproksimacija(void);

int main ()
{
    std::cout<<"Odaberite opciju (1 - unos cvorova, 2 - aproksimacija): ";
    int opcija;
    std::cin>>opcija;
    if(opcija==1)
        LIUnosCvorova();
    else if (opcija==2)
        LIAproksimacija();
    return 0;
}

void LIAproksimacija(void)
{
    std::cout<<"Unesite krajeve intervala i korak: ";
    double x_min,x_max,dx;
    std::cin>>x_min>>x_max>>dx;
    try
    {
        double x;
        auto f(LinearnaInterpolacija([](double x)
        {
            return x*x+std::sin(x);
        },x_min,x_max,dx));
        for(;;)
        {
            std::cout<<"Unesite argument (ili \"kraj\" za kraj): ";
            std::cin>>x;
            if(!std::cin)break;
            try
            {
                std::cout<<"f("<<x<<") = "<<x*x+std::sin(x)<<" fapprox("<<x<<") = "<<f(x)<<std::endl;
            }
            catch(std::range_error izuzetak)
            {
                std::cout<<izuzetak.what();
            }
        }
    }
    catch(std::domain_error izuzetak)
    {
        std::cout<<izuzetak.what();
    }
}

void LIUnosCvorova(void)
{
    std::cout<<"Unesite broj cvorova: ";
    int n;
    std::cin>>n;
    std::cout<<"Unesite cvorove kao parove x y: ";
    std::vector<std::pair<double,double>> cvorovi;
    double x,y;
    for(int i = 0; i < n; i++)
    {
        std::cin>>x>>y;
        cvorovi.push_back(std::make_pair(x,y));
    }
    try
    {
        auto f(LinearnaInterpolacija(cvorovi));
        for(;;)
        {
            std::cout<<"Unesite argument (ili \"kraj\" za kraj): ";
            std::cin>>x;
            if(!std::cin)break;
            try
            {
                std::cout<<"f("<<x<<") = "<<f(x)<<std::endl;
            }
            catch(std::range_error izuzetak)
            {
                std::cout<<izuzetak.what()<<std::endl;
            }
        }
    }
    catch(std::domain_error izuzetak)
    {
        std::cout<<izuzetak.what();
    }
    return;
}

std::function<double(double)> LinearnaInterpolacija(std::function<double(double)> f, double x_min, double x_max, double dx)
{
    std::vector<std::pair<double,double>> cvorovi;
    constexpr double eps(1e-9);
    for(int i = 0;x_min+ dx*i<x_max && !(std::fabs(dx*i+x_min - x_max) < eps); i++)
    {
        cvorovi.push_back( std::make_pair(x_min+dx*i,f(x_min+dx*i)) );
       
    }
    cvorovi.push_back(std::make_pair(x_max,f(x_max)));

    return LinearnaInterpolacija(cvorovi);
}

std::function<double(double)> LinearnaInterpolacija(std::vector<std::pair<double,double>> cvorovi)
{
    //sortiranje cvorova
    std::sort(cvorovi.begin(),cvorovi.end(),
              [](std::pair<double,double> a ,std::pair<double,double> b )
    {
        return a.first<b.first;
    });
    //sortiranje zavrseno

    //provjera jedinstvenosti x koordinata
    constexpr double eps(0.00000000001);
    //std::cout<< cvorovi.size();
    for(int i = 1; i < cvorovi.size() ; i++ )
    {
       // std::cout<<"\nprvi "<<cvorovi.at(i-1).first<<" drugi "<<cvorovi.at(i).first;
        if ( std::fabs( cvorovi.at(i-1).first - cvorovi.at(i).first) < eps )
            throw std::domain_error("Neispravni cvorovi\n");
    }
    //provjera jedinstvenosti zavrsena

    //definisanje i vracanje funkcije

    //funkcija treba da sa sobom ponese cvorove
    return [cvorovi](double x)
    {

        //ako se cvor nalazi van domena argumenta
        if(x < cvorovi.at(0).first || x > cvorovi.at(cvorovi.size()-1).first )
            throw std::range_error("Argument izvan opsega\n");
        //provjera gotova

        //potraga za okolnim cvorovima(x koordinatama istih)
        std::pair<int, int> susjedni_cvorovi(binarna_pretraga_okolnih_cvorova(cvorovi,x));
        //potraga zavrsena

        //formula i zavrsetak
        return ( cvorovi.at(susjedni_cvorovi.first).second +
                 (
                     (x - cvorovi.at(susjedni_cvorovi.first).first)
                     *( cvorovi.at(susjedni_cvorovi.second).second
                        - cvorovi.at(susjedni_cvorovi.first).second  ) /
                     ( cvorovi.at(susjedni_cvorovi.second).first
                       - cvorovi.at( susjedni_cvorovi.first).first   )
                 )
               );
        //zavrseno
    };
    //kraj ove funkcije
}

std::pair< int, int> binarna_pretraga_okolnih_cvorova( std::vector<std::pair<double,double>> cvorovi, double x)
{
    int lijevi(0),desni(cvorovi.size()-1),sredina(0);
    for(; desni-lijevi>1;)
    {
        sredina=(desni+lijevi)/2;
        if( cvorovi.at(sredina).first > x)
        {
            desni=sredina;
        }
        else
        {
            lijevi=sredina;
        }
    }
    return std::make_pair(lijevi,desni);
}