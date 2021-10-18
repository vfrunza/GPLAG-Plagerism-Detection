/B2016/2017: Zadaća 3, Zadatak 1
//Autotestovi by Enil Pajic (epajic1@etf.unsa.ba)
#include <iostream>
#include <functional>
#include <utility>
#include <vector>
#include <cmath>
#include <stdexcept>
#include <string>
#include <iomanip>

double fapprox(double x)
{
    return x*x+std::sin(x);
}

int VeciOd(int a, int b)
{
    if(a>b) return a;
    return b;
}
int ManjiOd(int a, int b)
{
    if(a<b) return a;
    return b;
}
std::function<double(double)>BaricentricnaInterpolacija(std::vector<std::pair<double, double>> v, int d)
{
    if(d<0 || d>v.size()) throw std::domain_error("Nedozvoljen red");
    for(int i=0; i<v.size(); i++) {
        for(int j=i+1; j<v.size(); j++) {
            if(v[i].first==v[j].first) throw std::domain_error("Neispravni cvorovi");
        }
    }
    std::vector<double>v2;
    for(int i=0; i<v.size(); i++) {
        double suma(0);
        for(int k=VeciOd(1,i+1-d); k<=ManjiOd(i+1, v.size()-d); k++) {
            double izraz, izraz2(1);
            for(int j=k-1; j<=k+d-1; j++) {
                if(j!=i)izraz2*=(1./(v[i].first-v[j].first));
            }
            izraz=std::pow(-1, k-1)*izraz2;
            suma+=izraz;
        }
        v2.push_back(suma);
    }
    return [v, d, v2](double x) {
        double y, z, suma2(0), suma3(0);
        for(int i=0; i<v.size(); i++) {
            if(x==v[i].first) return v[i].second;
        }
        for(int i=0; i<v.size(); i++) {
            y=(v2[i]/(x-v[i].first))*v[i].second;
            suma2+=y;
        }
        for(int i=0; i<v.size(); i++) {
            z=v2[i]/(x-v[i].first);
            suma3+=z;
        }
        double l=suma2/suma3;
        return l;
    };
}
std::function<double(double)> BaricentricnaInterpolacija(double f(double), double xmin, double xmax, double dx, int d)
{
    if(xmin>xmax || dx<=0) throw std::domain_error("Nekorektni parametri");
    std::vector<std::pair<double, double>> cvor;
    for(double i=xmin; i<xmax; i+=dx) {
        cvor.push_back(std::make_pair(i, f(i)));
    }
    return BaricentricnaInterpolacija(cvor, d);
}


int main ()
{
    try {
        std::cout<<"Odaberite opciju (1 - unos cvorova, 2 - aproksimacija): ";
        int n;
        std::cin>>n;
        if(n==1) {
            std::cout<<"Unesite broj cvorova: ";
            int m;
            std::cin>>m;
            std::cout<<"Unesite cvorove kao parove x y: ";
            std::vector<std::pair<double, double>> cvor(m);
            double a, b;
            for(int i=0; i<m; i++) {
                std::cin>>a>>b;
                cvor[i].first=a;
                cvor[i].second=b;
            }
            std::cout<<"Unesite red interpolacije: ";
            int d;
            std::cin>>d;
            std::cin.ignore(1000,'\n');
            for(;;) {
                std::cout<<"Unesite argument (ili "<< std::setw(5) << std::setfill('"')<<"kraj"<<std::setw(12)<<std::setfill('"')<<" za kraj): ";
                std::string s;
                std::getline(std::cin, s);
                int slovo(0);
                for(int i=0; i<s.length(); i++) {
                    if(!((s[i]>='0' && s[i]<='9')|| s[i]=='.' || s[i]=='-')) {
                        slovo=1;
                        break;
                    }
                }
                if(slovo) break;               
                auto fun=BaricentricnaInterpolacija(cvor, d);
                std::cout<<"f("<<std::stod(s)<<") = " << fun(std::stod(s))<<std::endl;

            }
        } else if(n==2) {
            std::cout<<"Unesite krajeve intervala i korak: ";
            double x, y, z;
            std::cin>>x>>y>>z;
            std::cout<<"Unesite red interpolacije: ";
            int r;
            std::cin>>r;
            std::cin.ignore(1000,'\n');
            for(;;) {
                std::cout<<"Unesite argument (ili "<< std::setw(5) << std::setfill('"')<<"kraj"<<std::setw(12)<<std::setfill('"')<<" za kraj): ";
                std::string s;
                std::getline(std::cin, s);
                int slovo(0);
                for(int i=0; i<s.length(); i++) {
                    if(!((s[i]>='0' && s[i]<='9')|| s[i]=='.' || s[i]=='-')) {
                        slovo=1;
                        break;
                    }
                }
                if(slovo) break;
                auto fun=BaricentricnaInterpolacija(fapprox, x, y, z, r);
                std::cout<<"f("<<std::stod(s)<<") = " << fapprox(std::stod(s))<<" fapprox("<<std::stod(s)<<") = " << fun(std::stod(s))<<std::endl;

            }
        }
    } catch(std::domain_error izuzetak) {
        std::cout<<izuzetak.what();
    }
    return 0;
}