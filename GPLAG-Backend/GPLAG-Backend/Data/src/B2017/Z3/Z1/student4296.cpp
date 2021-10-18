#include <iostream>
#include <vector>
#include <iomanip>
#include <stdexcept>
#include <cmath>
#include <utility>
#include <algorithm>
#include <functional>
#include <iterator>
#include <map>
#include <limits>
#define epsilon 0.0000000001
using std::cout;
using std::cin;
using std::endl;
using std::vector;
double xsinx (double x)
{
    return x * x + std::sin(x);
}
int max(int a,int b)
{
    if(a>=b)
        return a;
    else return b;
}
int min(int a,int b)
{
    if(a<=b)
        return a;
    else return b;
}
std::function<double(double)> LinearnaInterpolacija(std::vector<std::pair<double,double>> V)
{
    bool ima=false;
    for(int i=0; i<V.size(); i++)
        for(int j=i+1; j<V.size(); j++)
            if(fabs(V[i].first-V[j].first)<epsilon)
                ima=true;
    if(ima) throw std::domain_error ("Neispravni cvorovi");
    int n=V.size();
    return [V,n](double x) {
        std::pair<double,double> trazen;
        trazen={x,0};
        auto low=std::lower_bound(V.begin(),V.end(),trazen,[](std::pair<double,double> ba, std::pair<double,double> ca){return ba.first<=ca.first;});
                low--;

        if(low==V.end()) {
            throw std::range_error ("Argument izvan opsega");
        }
        
        int indeks=low-V.begin();
        if(low->second==V[indeks].first) return V[indeks].second;
        double y;
        y=V[indeks].second+(x-V[indeks].first)*((V[indeks+1].second-V[indeks].second)/(V[indeks+1].first-V[indeks].first));

        return y;
    };
}
std::function<double(double)>  LinearnaInterpolacija(std::function<double(double)> f, double xMin,double xMax, double xD)
{
    std::vector<std::pair<double,double>> V;
    if(xMin>xMax || xD<0) throw std::domain_error ("Nekorektni parametri");
    int i {};
    double m;
    m=(xMax-xMin)/xD;
    while(i<m) {
        V.resize(i+1);
        V[i].first=xMin+xD*i;
        V[i].second=f(V[i].first);
        if(i> std::numeric_limits<int>::max() || i<0)
            break;
        i++;

    }
    return        LinearnaInterpolacija(V);
}

/*
std::function<double(double)>  BaricentricnaInterpolacija(std::function<double(double)> f, double xMin,double xMax, double xD, int d)
{
    std::vector<std::pair<double,double>> V;
    if(xMin>xMax || xD<0) throw std::domain_error ("Nekorektni parametri");
    int i {};
    double m;
    m=(xMax-xMin)/xD;
    if(d>3)
        while(i<m) {
            V.resize(i+1);
            V[i].first=xMin+xD*i;
            V[i].second=f(V[i].first);
            if(i> std::numeric_limits<int>::max() || i<0)
                break;
            i++;

        }
    else  while(i<=m) {
            V.resize(i+1);
            V[i].first=xMin+xD*i;
            V[i].second=f(V[i].first);
            if(V[i].first> std::numeric_limits<double>::max() || V[i].first<0)
                break;
            i++;
        }
    // 2147483647
    return BaricentricnaInterpolacija(V,d);
}*/
int main(){
 auto li(LinearnaInterpolacija([](double x){return x*x;},-1.5,5,0.5));

std::cout << li(-0.5) << std::endl;
std::cout << li(0.6) << std::endl;
std::cout << li(1.5) << std::endl;
std::cout << li(0.1) << std::endl;
std::cout << li(2)<<std::endl;
std::cout << li(5);

}
int _main ()
{
    int o;
    cout<<"Odaberite opciju (1 - unos cvorova, 2 - aproksimacija): ";
    cin>>o;
    int d;
    std::vector<std::pair<double,double>> V;
    try {
        if(o==1) {
            int n;
            cout<<"Unesite broj cvorova: ";
            cin>>n;
            V.resize(n);
            for(int i=0; i<n; i++) {
                cin>>V[i].first>>V[i].second;
            }
            auto f(LinearnaInterpolacija(V));

            for(;;) {
                std::string b,kraj="kraj";
                char c='"';
                cout<<"Unesite argument (ili "<<c<<kraj<<c<<" za kraj): ";
                cin>>b;
                if(b=="kraj")
                    break;
                double a;
                a=std::stod(b);
                try {
                    auto f(LinearnaInterpolacija(V));
                    cout<<"f("<<a<<") = "<<f(a)<<endl;
                } catch(std::domain_error e) {
                    cout<<e.what()<<endl;
                }
            }
        }
    }

    catch(std::domain_error e) {
        cout<<e.what()<<endl;

    }
    try{
    double xMin,xMax,xD;
    if(o==2) {
        cout<<"Unesite krajeve intervala i korak: ";
        cin>>xMin>>xMax>>xD;
                    auto g(LinearnaInterpolacija(xsinx,xMin,xMax,xD));


        for(;;) {
            std::string b,kraj="kraj";
            char c='"';
            cout<<"Unesite argument (ili "<<c<<kraj<<c<<" za kraj): ";
            cin>>b;
            if(b=="kraj")
                break;
            double a;
            try {
                a=std::stod(b);
            } catch(...) {
                return 1;
            }
        
        try {
            auto g(LinearnaInterpolacija(xsinx,xMin,xMax,xD));
            cout<<"f("<<a<<") = "<<xsinx(a)<<" fapprox("<<a<<") = "<<g(a)<<endl;
        } catch(std::domain_error e) {
            cout<<e.what()<<endl;
        } catch(std::range_error e) {
            cout<<e.what()<<endl;
        }
        }
    }
    }catch(std::domain_error e){
                    cout<<e.what()<<endl;
    }


return 0;
}