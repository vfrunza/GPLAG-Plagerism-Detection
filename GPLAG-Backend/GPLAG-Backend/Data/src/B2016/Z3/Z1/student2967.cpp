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
double xsinx (double x){
    return x * x + std::sin(x);
}
int max(int a,int b){
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
std::function<double(double)> BaricentricnaInterpolacija(std::vector<std::pair<double,double>> V, int d){
    bool ima=false;
    if(d<0 || d>=V.size()) throw std::domain_error ("Nedozvoljen red");
    for(int i=0; i<V.size(); i++)
        for(int j=i+1; j<V.size(); j++)
            if(fabs(V[i].first-V[j].first)<epsilon)
                ima=true;
    if(ima) throw std::domain_error ("Neispravni cvorovi");
    int n=V.size();
    return [V,n,d](double x) {
        double Suma1 {},Suma2 {},SumaW,sumaw;
        for(int i=1; i<=n; i++) {
            SumaW=0;
            for(int k=max(1,i-d); k<=min(i,n-d); k++) {
                sumaw=1;
                for(int j=k; j<=k+d; j++) {
                    if(i==j)
                        continue;
                    sumaw*=(1/(V[i-1].first-V[j-1].first));
                }
                SumaW+=(sumaw*pow(-1,k-1));
            }
            if(fabs(x-V[i-1].first)<epsilon)
                return V[i-1].second;
            else     Suma1+=((SumaW*V[i-1].second)/(x-V[i-1].first));

        }
        for(int i=1; i<=n; i++) {
            SumaW=0;
            for(int k=max(1,i-d); k<=min(i,n-d); k++) {
                sumaw=1;
                for(int j=k; j<=k+d; j++) {
                    if(i==j)
                        continue;
                    sumaw*=(1/(V[i-1].first-V[j-1].first));
                }
                SumaW+=(sumaw*pow(-1,k-1));
            }
            if(fabs(x-V[i-1].first)<epsilon)
                return V[i-1].second;
            else Suma2+=((SumaW)/(x-V[i-1].first));
        }
        return Suma1/Suma2;
    };
}
std::function<double(double)>  BaricentricnaInterpolacija(std::function<double(double)> f, double xMin,double xMax, double xD, int d){
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
}
int main ()
{
    int o;
    cout<<"Odaberite opciju (1 - unos cvorova, 2 - aproksimacija): ";
    cin>>o;
    int d;
    std::vector<std::pair<double,double>> V;

    if(o==1) {
        int n;
        cout<<"Unesite broj cvorova: ";
        cin>>n;
        V.resize(n);
        cout<<"Unesite cvorove kao parove x y: ";
        for(int i=0; i<n; i++) {
            cin>>V[i].first>>V[i].second;
        }
        cout<<"Unesite red interpolacije: ";
        cin>>d;
        for(;;) {
            std::string b,kraj="kraj";
            char c='"';
            cout<<"Unesite argument (ili "<<c<<kraj<<c<<" za kraj): ";
            cin>>b;
            if(b=="kraj")
                break;
            double a;
            a=std::stod(b);
            try{
                auto f(BaricentricnaInterpolacija(V,d));
                cout<<"f("<<a<<") = "<<f(a)<<endl;
            }
            catch(std::domain_error e){
                cout<<e.what()<<endl;
            }
        }
    }
    double xMin,xMax,xD;
    if(o==2) {
        cout<<"Unesite krajeve intervala i korak: ";
        cin>>xMin>>xMax>>xD;
        cout<<"Unesite red interpolacije: ";
        cin>>d;
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
            
            try{
                auto g(BaricentricnaInterpolacija(xsinx,xMin,xMax,xD,d));
                cout<<"f("<<a<<") = "<<xsinx(a)<<" fapprox("<<a<<") = "<<g(a)<<endl;            
            }
            catch(std::domain_error e){
                cout<<e.what()<<endl;
            }
        }
    }
// 1 2 5 6 7 8
    return 0;
}