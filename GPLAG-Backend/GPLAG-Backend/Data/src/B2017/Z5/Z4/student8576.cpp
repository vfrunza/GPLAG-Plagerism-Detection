#include <iostream>
#include <initializer_list>
#include <functional>
#include <stdexcept>
#include <cmath>
#include <algorithm>
#include <iomanip>
#include <utility>
using namespace std;
const double PI=3.14159265359;
class FourierovRed{
    int stepen;
    double *koef_a=nullptr;
    double *koef_b=nullptr;
    double period;
    static constexpr double PI=3.14159265359;
    public:
    FourierovRed(double t,const initializer_list<double> &l1, const initializer_list<double> &l2);
    FourierovRed(int n, double t, function<double(int)> f1, function<double(int)> f2);
    FourierovRed(int n, double p, double q, function<double(double)> f, long int m);
    /*void IspisiKoef() const{
        for(int i=0;i<stepen+1;i++){
            cout<<fixed<<setprecision(3)<<koef_a[i]<<" "<<koef_b[i]<<endl;
        }
    }*/
    double operator()(double x);
    pair<double&, double&> operator[](int k);
    pair<double, double> operator[](int k) const;
    FourierovRed(const FourierovRed &f);
    FourierovRed(FourierovRed &&f);
    FourierovRed &operator=(const FourierovRed &f);
    FourierovRed &operator=(FourierovRed &&f);
    ~FourierovRed(){delete[] koef_a; delete[] koef_b;}
};
FourierovRed::FourierovRed(double t,const initializer_list<double> &l1, const initializer_list<double> &l2){
    if(l1.size()>=l2.size()){
        try{
        koef_a=new double[l1.size()]{};//da svi budu nule
        koef_b=new double[l1.size()]{};
        }
        catch(...){
            delete[] koef_a;
            delete[] koef_b;
            throw;
        }
        period=t;
        stepen=l1.size()-1;
        int i(0);
        for(auto it=l1.begin();it!=l1.end();it++){
            koef_a[i]=*it;
            i++;
        }
        i=1;
        for(auto it=l2.begin();it!=l2.end();it++){
            koef_b[i]=*it;
            i++;
        }
    }
      if(l2.size()>l1.size()){
        try{
        koef_a=new double[l2.size()+1]{};//da svi budu nule
        koef_b=new double[l2.size()+1]{};
        }
        catch(...){
            delete[] koef_a;
            delete[] koef_b;
            throw;
        }
        period=t;
        stepen=l2.size();
        int i(0);
        for(auto it=l1.begin();it!=l1.end();it++){
            koef_a[i]=*it;
            i++;
        }
        i=1;
        for(auto it=l2.begin();it!=l2.end();it++){
            koef_b[i]=*it;
            i++;
        }
    }
}
FourierovRed::FourierovRed(int n, double t, function<double(int)> f1, function<double(int)> f2){
    if(n<=0) throw domain_error("Stepen mora biti pozitivan");
    try{
        koef_a=new double[n+1]{};//da svi budu nule
        koef_b=new double[n+1]{};
        }
        catch(...){
            delete[] koef_a;
            delete[] koef_b;
            throw;
        }
        stepen=n;
        period=t;
        for(int i=0;i<stepen+1;i++){
            koef_a[i]=f1(i);
        }
        for(int i=1;i<stepen+1;i++){
            koef_b[i]=f2(i);
        }
        
}
FourierovRed::FourierovRed(int n, double p, double q, function<double(double)> f, long int m){
    if(n<=0) throw domain_error("Stepen mora biti pozitivan");
    if(m<=0) throw domain_error("Broj podintervala mora biti pozitivan");
    if(!(p<q)) throw range_error("Neispravan interval");
    try{
        koef_a=new double[n+1]{};//da svi budu nule
        koef_b=new double[n+1]{};
        }
        catch(...){
            delete[] koef_a;
            delete[] koef_b;
            throw;
        }
        stepen=n;
        period=q-p;
        for(int i=0;i<stepen+1;i++){
            double suma(0);
            for(int j=1;j<m;j++){
                suma+=f(p+(j*period/m))*cos(2*PI*i*(p/period+double(j)/m));
            }
            koef_a[i]=((f(p)+f(q))/m)*cos(2*i*PI*p/period)+(2./m)*suma;
        }
        for(int i=1;i<stepen+1;i++){
            double suma(0);
            for(int j=1;j<m;j++){
                suma+=f(p+(j*period/m))*sin(2*PI*i*(p/period+double(j)/m));
            }
            koef_b[i]=((f(p)+f(q))/m)*sin(2*i*PI*p/period)+(2./m)*suma;
        }
}
double FourierovRed::operator()(double x){
    double suma(0);
    for(int i=1;i<=stepen;i++){
        suma+=koef_a[i]*cos((2*x*PI*i)/period)+koef_b[i]*sin((2*x*PI*i)/period);
    }
    return koef_a[0]/2+suma;
}
pair<double &, double &> FourierovRed::operator[](int k){
    if(k<0 || k>stepen) throw range_error("Neispravan indeks");
    pair<double &, double &> p(koef_a[k],koef_b[k]);
    return p;
}
pair<double, double> FourierovRed::operator[](int k) const{
    if(k<0 || k>stepen) throw range_error("Neispravan indeks");
    return make_pair(koef_a[k],koef_b[k]);
}
FourierovRed::FourierovRed(const FourierovRed &f){
    try {
        koef_a=new double[f.stepen+1]{};//da svi budu nule
        koef_b=new double[f.stepen+1]{};
    }
    catch (...) {
        delete[] koef_a;
        delete[] koef_b;
        throw;
    }
    stepen=f.stepen;
    period=f.period;
    for(int i=0;i<=stepen;i++){
        koef_a[i]=f.koef_a[i];
        koef_b[i]=f.koef_b[i];
    }
}
FourierovRed::FourierovRed(FourierovRed &&f):stepen(f.stepen),period(f.period){
    koef_a=f.koef_a;
    koef_b=f.koef_b;
    f.koef_a=nullptr;
    f.koef_b=nullptr;
}
FourierovRed &FourierovRed::operator=(const FourierovRed &f){
    if(stepen<f.stepen){
        double* novi_a(nullptr);
        double* novi_b(nullptr);
        try{
          novi_a=new double[stepen+1]{};
          novi_b=new double[stepen+1]{};
        }
        catch(...){
            delete[] novi_a;
            delete[] novi_b;
            throw;
        }
        delete[] koef_a;
        delete[] koef_b;
        koef_a=novi_a;
        koef_b=novi_b;
    }
    for(int i=0;i<=stepen;i++){
        koef_a[i]=f.koef_a[i];
        koef_b[i]=f.koef_b[i];
    }
    stepen=f.stepen;
    period=f.period;
    return *this;
}
FourierovRed &FourierovRed::operator=(FourierovRed &&f){
    swap(stepen,f.stepen);
    swap(period,f.period);
    swap(koef_a,f.koef_a);
    swap(koef_b,f.koef_b);
    return *this;
}
int main ()
{

FourierovRed f1(10,0,2*PI,[](double x){return x*x;},10000);
FourierovRed f2(10, 2*PI, [](int k){return k==0 ? 8*PI*PI/3 : 4./(k*k);}, [](int k){return -4*PI/k;});
cout<<f1(3)<<endl;
cout<<f2(3)<<endl;
cout<<f1[3].first<<" "<<f1[3].second<<endl;
f1[3]=make_pair(3,3);
cout<<f1[3].first<<" "<<f1[3].second;
	return 0;
}
