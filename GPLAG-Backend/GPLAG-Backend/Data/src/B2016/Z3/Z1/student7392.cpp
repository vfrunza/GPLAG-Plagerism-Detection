/B2016/2017: Zadaća 3, Zadatakk 1
//Autotestovi by Enil Pajic (epajic1@etf.unsa.ba)
#include <iostream>
#include <functional>
#include <cstdio>
#include <vector> 
#include <map>
#include <cmath>
#include <utility>
#include <stdexcept>

int min(int a, int b){
    return a<b ? a : b;
}

int max(int a, int b){
    return a>b ? a : b;
}

double fija(double x){
    return x*x+std::sin(x);
}

std::function<double(double)> BaricentricnaInterpolacija(std::vector<std::pair<double, double>> v, int d){
    if(d<0 || d>=v.size())throw std::domain_error("Nedozvoljen red");
    int n=v.size();
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(v[i].first==v[j].first)throw std::domain_error("Neispravni cvorovi");
        }
    }
    std::vector<double> w(n, 0);
    for(int i=1;i<=n;i++){
        for(int k=max(1, i-d);k<=min(i, n-d);k++){
            double s=1;
            for(int j=k;j<=k+d;j++){
                if(i!=j)s*=1/(v[i-1].first-v[j-1].first);
            }
            if(k%2==0)w[i-1]-=s; else w[i-1]+=s; 
        }
    }
    return [n, v, d, w](double x){
        double brojnik=0, nazivnik=0;
        for(int i=1;i<=n;i++){
            if(x==v[i-1].first)return v[i-1].second;
            double a=w[i-1]/(x-v[i-1].first);
            brojnik+=a*v[i-1].second;
            nazivnik+=a;
        }
        return brojnik/nazivnik;
    };
}

template<typename tipf>
    std::function<double(double)> BaricentricnaInterpolacija(tipf f, double xmin, double xmax, double deltax, int d){
        if(xmin>xmax || deltax<=0)throw std::domain_error("Nekorektni parametri");
        std::vector<std::pair<double, double>> vec;
        double a=xmin;
        while(a<=xmax){
            vec.push_back(std::make_pair(a, f(a)));
            a+=deltax;
        }
        try{
            auto f=BaricentricnaInterpolacija(vec, d);
            return f;
        }
        catch(...){
            throw;
        }
    }

int main ()
{
    int p;
    std::cout<<"Odaberite opciju (1 - unos cvorova, 2 - aproksimacija): ";
    std::cin>>p;
    if(p==1){
        std::cout<<"Unesite broj cvorova: ";
        std::cin>>p;
        std::vector<std::pair<double, double>> vec(p);
        std::cout<<"Unesite cvorove kao parove x y: ";
        for(auto &i:vec){
            std::cin>>i.first>>i.second;
        }
        std::cout<<"Unesite red interpolacije: ";
        int g;
        std::cin>>g;
        std::cin.ignore(1000, '\n');
        try{
            auto f=BaricentricnaInterpolacija(vec, g);
            do{
                std::cout<<"Unesite argument (ili \"kraj\" za kraj): ";
                double x;
                int koliko=scanf("%lf", &x);
                if(koliko!=1 || std::cin.peek()!='\n')break;
                std::cout<<"f("<<x<<") = "<<f(x)<<'\n';
            }while(true);
        }
        catch(std::domain_error gg){
            std::cout<<gg.what();
            return 0;
        }
    } else if(p==2){
        double xmin, xmax, deltax;
        int d;
        std::cout<<"Unesite krajeve intervala i korak: ";
        std::cin>>xmin>>xmax>>deltax;
        std::cout<<"Unesite red interpolacije: ";
        std::cin>>d;
        try{
            auto f=BaricentricnaInterpolacija(fija, xmin, xmax, deltax, d);
            std::cin.ignore(1000, '\n');
            do{
                std::cout<<"Unesite argument (ili \"kraj\" za kraj): ";
                double x;
                int koliko=scanf("%lf", &x);
                if(koliko!=1 || std::cin.peek()!='\n')break;
                std::cout<<"f("<<x<<") = "<<fija(x)<<" fapprox("<<x<<") = "<<f(x)<<"\n";
            }while(true);
        }
        catch(std::domain_error gg){
            std::cout<<gg.what();
            return 0;
        }
    }
	return 0;
}