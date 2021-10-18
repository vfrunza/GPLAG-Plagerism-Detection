/B2016/2017: Zadaća 3, Zadatak 1
//Autotestovi by Enil Pajic (epajic1@etf.unsa.ba)
#include <iostream>
#include <vector>
#include <utility>
#include <functional>
#include <stdexcept>
#include <cmath>
#include <string>

int OperatorMin (int x, int y)
{
    if (x<y)
        return x;
    return y;
}

int OperatorMax (int x, int y)
{
    if (x>y)
        return x;
    return y;
}

double funkcija (double x)
{
    return x*x+sin(x);
}

std::function<double(double)> BaricentricnaInterpolacija (std::vector<std::pair<double,double>> cvorovi_inter, int d)
{
    if(d<0 || d>cvorovi_inter.size())
        throw std::domain_error ("Nedozvoljen red");
    double eps(0.000001);
    for (int i=0; i<int(cvorovi_inter.size())-1; i++)
    {
        for (int j=i+1; j<cvorovi_inter.size(); j++)
        {
            if(fabs(cvorovi_inter[j].first-cvorovi_inter[i].first)<eps)
                throw std::domain_error ("Neispravni cvorovi");
        }
    }
    std::vector<double> t_koef(cvorovi_inter.size());
    int n(cvorovi_inter.size());
    for (int i=1; i<=n; i++)
    {
        int min(OperatorMin(i,n-d)), max(OperatorMax(1, i-d));
        double suma(0);
        for (int k=max; k<=min; k++)
        {
            double proizvod(1);
            for(int j=k; j<=k+d; j++)
            {
                if (j==i) continue;
                proizvod*=1./(cvorovi_inter[i-1].first-cvorovi_inter[j-1].first);
            }
            suma+=pow(-1, k-1)*proizvod;
        }
        t_koef[i-1]=suma;
    }
    
    return [t_koef, cvorovi_inter] (double x) { 
        double eps(0.00001);
        for (int i=0; i<cvorovi_inter.size(); i++)
        {
            if(fabs(x-cvorovi_inter[i].first)<eps)
                return cvorovi_inter[i].second;
        }
        
        double sum1(0), sum2(0);
        for (int i=1; i<=cvorovi_inter.size(); i++)
        {
            sum1+=t_koef[i-1]/(x-cvorovi_inter[i-1].first)*cvorovi_inter[i-1].second;
            sum2+=t_koef[i-1]/(x-cvorovi_inter[i-1].first);
        }
        return sum1/sum2;
    }; 
}

std::function<double(double)> BaricentricnaInterpolacija (std::function<double(double)> f, double x_min, double x_max, double delta_x, int d)
{
    if (x_min>x_max || delta_x<=0)
        throw std::domain_error("Nekorektni parametri");
    std::vector<std::pair<double, double>> novi_cvorovi;
    while (x_min<=x_max)
    {
        novi_cvorovi.push_back(std::make_pair(x_min, f(x_min)));
        x_min+=delta_x;
    }
    return BaricentricnaInterpolacija(novi_cvorovi,d); 
}

int main ()
{
    try
    {
        for(;;) //prepraviti
        {
            int opcija;
            std::cout<<"Odaberite opciju (1 - unos cvorova, 2 - aproksimacija): ";
            std::cin>>opcija;
            if (!std::cin)
                break;
            if(opcija==1)
            {
                int n;
                std::cout<<"Unesite broj cvorova: ";
                std::cin>>n;
                std::vector<std::pair<double, double>> cvorovi(n);
                std::cout<<"Unesite cvorove kao parove x y: ";
                for (int i=0; i<n; i++)
                    std::cin>>cvorovi[i].first>>cvorovi[i].second;
                /*for (int i=0; i<n; i++)
                    std::cout<<cvorovi[i].first<<" "<<cvorovi[i].second<<std::endl;*/
                int d;
                std::cout<<"Unesite red interpolacije: ";
                std::cin>>d;
                auto fun(BaricentricnaInterpolacija(cvorovi, d));
                for (;;)
                {
                    double argument;
                    std::cout<<"Unesite argument (ili \"kraj\" za kraj): "; //pronaci kako se pisu navodnici
                    std::cin>>argument;
                    if(!std::cin)
                        break;
                    std::cout<<"f("<<argument<<") = "<<fun(argument)<<std::endl;
                }
                if(!std::cin)
                    break;
            }
            else if (opcija==2)
            {
                double x_min, x_max, delta_x;
                std::cout<<"Unesite krajeve intervala i korak: ";
                std::cin>>x_min>>x_max>>delta_x;
                int d;
                std::cout<<"Unesite red interpolacije: ";
                std::cin>>d;
                auto fun(BaricentricnaInterpolacija(funkcija, x_min, x_max, delta_x, d));
                for (;;)
                {
                    double argument;
                    std::cout<<"Unesite argument (ili \"kraj\" za kraj): "; //pronaci kako se pisu navodnici
                    std::cin>>argument;
                    if(!std::cin)
                        break;
                    std::cout<<"f("<<argument<<") = "<<funkcija(argument)<<" fapprox("<<argument<<") = "<<fun(argument)<<std::endl;
                }
                if(!std::cin)
                    break;
            }
            else
                break;
        }
    }
    catch (std::domain_error e)
    {
        std::cout<<e.what()<<std::endl;
    }
	return 0;
}