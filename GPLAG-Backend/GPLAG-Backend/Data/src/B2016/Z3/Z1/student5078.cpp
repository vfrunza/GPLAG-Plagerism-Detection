/B2016/2017: Zadaća 3, Zadatak 1
//Autotestovi by Enil Pajic (epajic1@etf.unsa.ba)
#include <iostream>
#include <functional>
#include <vector>
#include <utility>
#include <iomanip>
#include <cmath>
#include <stdexcept>
#include <cstdlib>
bool provjeri_cvorove(std::vector<std::pair<double,double>> a){
    for(int i=0;i<a.size()-1;i++){
        for(int j=0;j<a.size();j++){
            if(i==j)continue;
            else if(fabs(a[i].first-a[j].first)<0.00000001)return true;
        }
    }
    return false;
}
std::function<double(double)> BaricentricnaInterpolacija(std::vector<std::pair<double,double>> tacke, int d){
    std::vector<double> Wi;
    int n=(tacke.size());
    if(d<0 || d>=n)throw std::domain_error("Nedozvoljen red");
    if(provjeri_cvorove(tacke))throw std::domain_error("Neispravni cvorovi");
    double w(0);
    double pp(1);
    for(int i=1;i<=n;i++){
        w=0;
        for(int k=std::max(1,i-d);k<=std::min(i,n-d);k++){
            pp=1;
            for(int j=k;j<=k+d;j++){
                if(j!=i)pp=pp/(tacke[i-1].first-tacke[j-1].first);
                if(k%2==0)pp=-pp;
            }
            w=w+pp;
        }
        Wi.push_back(w);
    }
    return [Wi,n,tacke](double x){
        double p(0);
        double q(0);
        double u(0);
        for(int i=1;i<=n;i++){
            u=0;
            if(fabs(x-tacke[i-1].first)<0.00000001)return tacke[i-1].second;
            u=Wi[i-1]/double(x-tacke[i-1].first);
            p=p+u*tacke[i-1].second;
            q=q+u;
        }
        return p/q;
    };
}
template <typename Funkcija>
std::function<double(double)> BaricentricnaInterpolacija(Funkcija f,double minx,double maxx,double deltaX,int d){
    if(minx>maxx || deltaX<=0)throw std::domain_error("Nekorektni parametri");
    std::vector<std::pair<double,double>> tacke;
    if(fabs(minx-maxx)==0)tacke.push_back(std::make_pair(minx,f(minx)));
    while(minx<maxx){
        tacke.push_back(std::make_pair(minx,f(minx)));
        minx+=deltaX;
    }
    std::vector<double> Wi;
    int n=(tacke.size());
    double w(0);
    double pp(1);
    if(d<0 || d>=n)throw std::domain_error("Nedozvoljen red");
    if(provjeri_cvorove(tacke))throw std::domain_error("Neispravni cvorovi");
    for(int i=1;i<=n;i++){
        w=0;
        for(int k=std::max(1,i-d);k<=std::min(i,n-d);k++){
            pp=1;
            for(int j=k;j<=k+d;j++){
                if(j!=i)pp=pp/(tacke[i-1].first-tacke[j-1].first);
                if(k%2==0)pp=-pp;
            }
            w=w+pp;
        }
        Wi.push_back(w);
    }
    return [Wi,n,tacke](double x){
        double p(0);
        double q(0);
        double u(0);
        for(int i=1;i<=n;i++){
            u=0;
            if(fabs(x-tacke[i-1].first)<0.00000001)return tacke[i-1].second;
            u=Wi[i-1]/double(x-tacke[i-1].first);
            p=p+u*tacke[i-1].second;
            q=q+u;
        }
        return p/q;
    };
}
double f(double x){
     return (x*x + sin(x));
}

int main ()
{
    try{
    std::cout<<"Odaberite opciju (1 - unos cvorova, 2 - aproksimacija): ";
    int x;
    std::cin>>x;
    if(x==1){
        std::cout<<"Unesite broj cvorova: ";
        int c;
        std::cin>>c;
        std::cout<<"Unesite cvorove kao parove x y: ";
        std::vector<std::pair<double,double>> tacke;
        for(int i=0;i<c;i++){
            int a,b;
            std::cin>>a>>b;
            tacke.push_back(std::make_pair(a,b));
        }
        std::cout<<"Unesite red interpolacije: ";
        int d;
        std::cin>>d;
        double koef;
        std::cout<<"Unesite argument (ili \"kraj\" za kraj): ";
        while(std::cin>>koef){
            auto ispisna=BaricentricnaInterpolacija(tacke,d)(koef);
            std::cout<<"f(";std::cout<<koef<<") = "<<ispisna<<std::endl;
            std::cout<<"Unesite argument (ili \"kraj\" za kraj): ";
        }return 0;
        
    }
    if(x==2){
        std::cout<<"Unesite krajeve intervala i korak: ";
        double xmin,xmax,deltax;
        std::cin>>xmin>>xmax>>deltax;
        std::cout<<"Unesite red interpolacije: ";
        int d;
        std::cin>>d;
        double koef;
        std::cout<<"Unesite argument (ili \"kraj\" za kraj): ";
        while(std::cin>>koef){
            auto ispisna=BaricentricnaInterpolacija(f,xmin,xmax,deltax,d)(koef);
            std::cout<<"f(";std::cout<<koef<<") = "<<f(koef);
            std::cout<<" fapprox("<<koef<<") = "<<ispisna<<std::endl;
            std::cout<<"Unesite argument (ili \"kraj\" za kraj): ";
        }
    }return 0;
    }
    catch(std::domain_error x){
        std::cout<< x.what();
        return 0;
    }
	return 0;
}