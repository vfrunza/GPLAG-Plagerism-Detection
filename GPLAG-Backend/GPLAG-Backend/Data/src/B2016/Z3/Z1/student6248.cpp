/B2016/2017: Zadaća 3, Zadatak 1
//Autotestovi by Enil Pajic (epajic1@etf.unsa.ba)
#include <iostream>
#include <functional>
#include <vector>
#include <cmath>

int Max(int a, int b)
{
    if(a>b) return a;
    else return b;
}

int Min(int a, int b)
{
    if(a>b) return b;
    else return a;
}

bool JesuLiJednaki(double x, double y, double Eps=1e-10)
{
    return std::fabs(x-y)<=Eps*(std::fabs(x)+std::fabs(y));
}

double Stepenuj(double baza, int eksp)
{
    double rez(1);
    if(eksp>0)
    {
    for(int i(1); i<=eksp; i++)
    {
        rez*=baza;
    }
    }
    else if(eksp<0)
    {
        for(int i(1); i<=fabs(eksp); i++)
        {
            rez*=baza;
        }
        rez=1./rez;
    }
    else rez=1;
    return rez;
}

std::function<double(double)> BaricentricnaInterpolacija(std::vector<std::pair<double, double>> v, int d)
{
    // da li se testira sta se desi ako funkciji posaljemo prazan vektor
    if(d<0 || d>=v.size()) throw std::domain_error("Nedozvoljen red");
    
    for(int i(0); i<v.size(); i++)
    {
        for(int j(i+1); j<v.size(); j++)
        {
            if(JesuLiJednaki(v[i].first,v[j].first)) 
            {
                throw std::domain_error("Neispravni cvorovi");
            }
        }
    } 
    
    int n(v.size());
    std::vector<double> t(n);
    for(int m(0); m<n; m++)
    {
        double suma(0);
        int i(m+1);
        for(int k(Max(1,i-d)); k<=Min(i,n-d); k++)
        {
            int koef(Stepenuj(-1,k-1));
            double proizvod(1);
            for(int j(k); j<=k+d; j++)
            {
                if(i!=j)
                {
                    double nazivnik(v[i-1].first-v[j-1].first);
                    //if(nazivnik!=0)
                    proizvod*=1./nazivnik;
                }
            }
            suma+=koef*proizvod;
        }
        t[m]=suma;
        if(m==n) break;
    }
    return [t,v,d] (double x) {
    double suma1(0),suma2(0);
    for(int i(0); i<v.size(); i++)
    {
        if(JesuLiJednaki(v[i].first,x)==true) return v[i].second;
        else
        {
            double nazivnik(x-v[i].first);
            suma1+=v[i].second*(t[i]/nazivnik);
            suma2+=t[i]/nazivnik;
        }
    }
    return suma1/suma2;
    };
}

std::function<double(double)> BaricentricnaInterpolacija(double fun(double), double x_min, double x_max, double delta_x, int d)
{
    if(x_min>x_max || delta_x<=0) throw std::domain_error("Nekorektni parametri");
    std::vector<std::pair<double,double>> v;
    
    for(auto i(x_min); i<=x_max; i+=delta_x)
    {
        std::pair<double,double> par;
        par.first=i;
        par.second=fun(i);
        v.push_back(par);
    }
    auto f(BaricentricnaInterpolacija(v,d));
    return f;
}

double f(double x)
{
    return std::sin(x)+x*x;
}

int main ()
{
    try
    {
        std::cout << "Odaberite opciju (1 - unos cvorova, 2 - aproksimacija): ";
        int izbor;
        std::cin >> izbor;
        if(izbor==1)
        {
            std::cout << "Unesite broj cvorova: ";
            int n;
            std::cin >> n;
            std::cin.ignore(1000,'\n');
            std::vector<std::pair<double,double>> v;
            std::cout << "Unesite cvorove kao parove x y: ";
            for(int i(0); i<n; i++)
            {
                double prva, druga;
                std::cin >> prva;
                std::cin >> druga;
                v.push_back(std::make_pair(prva,druga));
            }
            
            std::cout << "Unesite red interpolacije: ";
            int red;
            std::cin >> red;
            while(true)
            {
                std::string s{"Unesite argument (ili "};
                s.push_back('"');
                s+="kraj";
                s.push_back('"');
                s+=" za kraj): ";
                std::cout << s;
                double arg;
                std::cin >> arg;
                if(!(std::cin)) break;
                std::cout << "f(" << arg << ") = " << BaricentricnaInterpolacija(v,red)(arg);
                std::cout << std::endl;
            }
        }
        else if(izbor==2)
        {
            std::cout << "Unesite krajeve intervala i korak: ";
            double x_min,x_max,delta_x;
            std::cin >> x_min >> x_max >> delta_x;
            std::cout << "Unesite red interpolacije: ";
            int red;
            std::cin >> red;
            while(true)
            {
                std::string s{"Unesite argument (ili "};
                s.push_back('"');
                s+="kraj";
                s.push_back('"');
                s+=" za kraj): ";
                std::cout << s;
                double arg;
                std::cin >> arg;
                if(!(std::cin)) break;
                std::cout << "f(" << arg << ") = " << f(arg) << " fapprox(" << arg << ") = " << BaricentricnaInterpolacija(f,x_min,x_max,delta_x,red)(arg);
                std::cout << std::endl;
            }
        }
    }
    catch(std::domain_error izuzetak)
    {
        std::cout << izuzetak.what();
    }
	return 0;
}