/B2016/2017: Zadaća 3, Zadatak 1
//Autotestovi by Enil Pajic (epajic1@etf.unsa.ba)
#include <iostream>
#include<utility>
#include<vector>
#include<cmath>
#include<functional>
#include<stdexcept>
const double malavrjednost=pow(10,-7);
int max(int jedan, int razlika)
{
    if(jedan>razlika) return jedan;
    return razlika;
}
int min(int jedan, int razlika)
{
    if(jedan<razlika) return jedan;
    return razlika;
}
double racunajwi(std::vector<std::pair<double,double>> pv,int i ,int d)
{
    double rez=0;
    for(int k=max(1,i-d); k<=min(i,pv.size()-d); k++) {
        double proiz=1;
        int koef=pow(-1,k-1);
        for(int j=k; j<=k+d; j++)
            if(j!=i)
                proiz*=(1/(pv[i-1].first-pv[j-1].first));
        rez+=koef*proiz;
    }
    return rez;
}
std::function<double(double)> BaricentricnaInterpolacija(std::vector<std::pair<double,double>> vp,int d)
{
    int n=vp.size();
    if(d<0 || d>vp.size()) throw std::domain_error("Nedozvoljen red");
    for(int i=0; i<n-1; i++) {
        for(int j=i+1; j<n; j++) {
            if(fabs(vp[i].first-vp[j].first)<malavrjednost && fabs(vp[i].second-vp[j].second)<malavrjednost)
                throw std::domain_error("Neispravni cvorovi");
        }
    }
    std::function<double(double)> rez;
    rez=[vp,n,d](double x) {
        double rez,a=0,b=0;
        for(int i=1; i<=n; i++) {
            double wi=racunajwi(vp,i,d);
            if(fabs(x-vp[i-1].first)<malavrjednost)
            return vp[i-1].second;
            
            a+=(wi*vp[i-1].second/(x-vp[i-1].first));
            b+=(wi/(x-vp[i-1].first));
            
        }
        
        rez=a/b;
        return rez;
    };

    return rez;
}
std::vector<std::pair<double,double>> unoscvorova(int n)
{
    std::vector<std::pair<double,double>> rez(n);
    for(int i=0; i<n; i++) {
        double x,y;
        std::cin>>x;
        std::cin>>y;
        std::pair<double,double> pomparovi;
        pomparovi=std::make_pair(x,y);
        rez[i]=pomparovi;
    }
    
    return rez;
}
template <typename tf>
std::function<double(double)> BaricentricnaInterpolacija(tf fun,double xmin,double xmax, double deltax, int d)
{
    if(xmin>xmax || deltax<=0)throw std::domain_error("Nekorektni parametri");
    std::vector<std::pair<double,double>> vp;
    for(double i=xmin; i<=xmax; i+=deltax) {
        std::pair<double,double> pompar;
        pompar=std::make_pair(i,fun(i));
        vp.push_back(pompar);
    }
    if(d<0 || d>vp.size()) throw std::domain_error("Nedozvoljen red");
    std::function<double(double)> rez;
    int n=vp.size();
    rez=[vp,n,d,fun](double x) {
        double rez,a=0,b=0;
        for(int i=1; i<=n; i++) {
            double wi=racunajwi(vp,i,d);
            if(fabs(x-vp[i-1].first)<malavrjednost)
            return vp[i-1].second;
            
            a+=(wi*vp[i-1].second/(x-vp[i-1].first));
            b+=(wi/(x-vp[i-1].first));
        }
        rez=a/b;
        return rez;
    };

    return rez;

}
int main ()
{
    try {
        std::cout<<"Odaberite opciju (1 - unos cvorova, 2 - aproksimacija): ";
        int opcija;
        std::cin>>opcija;
        if(opcija==1) {
            std::cout<<"Unesite broj cvorova: ";
            int brcvorova;
            std::cin>>brcvorova;
            std::cout<<"Unesite cvorove kao parove x y: ";
            std::vector<std::pair<double,double>> cvorovi;
            try {
                cvorovi=unoscvorova(brcvorova);
            } catch(std::domain_error x) {
                std::cout<<x.what();
                return 0;
            }
            std::cout << "Unesite red interpolacije: ";
            int d;
            std::cin>>d;
            for(;;) {
                std::string s {"      "};
                s[0]='"';
                s[1]='k';
                s[2]='r';
                s[3]='a';
                s[4]='j';
                s[5]='"';
                std::cout<<"Unesite argument (ili "<<s<<" za kraj): ";
                double x;
                std::cin>>x;
                if(!std::cin) {
                    return 0;
                }
                auto f=BaricentricnaInterpolacija(cvorovi,d);
                std::cout<<"f("<<x<<") = "<<f(x)<<std::endl;
            }
        }
        if(opcija==2) {
            std::cout<<"Unesite krajeve intervala i korak: ";
            double kraj1,kraj2;
            double korak;
            std::cin>>kraj1;
            std::cin>>kraj2;
            std::cin>>korak;
            std::cout<<"Unesite red interpolacije: ";
            int d;
            std::cin>>d;
            for(;;) {
                std::string s {"      "};
                s[0]='"';
                s[1]='k';
                s[2]='r';
                s[3]='a';
                s[4]='j';
                s[5]='"';
                std::cout<<"Unesite argument (ili "<<s<<" za kraj): ";
                double x;
                std::cin>>x;
                if(!std::cin) {
                    return 0;
                }
                auto f=BaricentricnaInterpolacija([](double x) {
                    return x*x+sin(x);
                },kraj1,kraj2,korak,d);
                std::cout<<"f("<<x<<") = "<<x*x+sin(x)<<" fapprox("<<x<<") = "<<f(x)<<std::endl;
            }

        }
    } catch(std::domain_error x) {
        std::cout<<x.what();
    }

    return 0;
}