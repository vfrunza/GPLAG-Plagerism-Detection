#include <iostream>
#include <initializer_list>
#include <functional>
#include <stdexcept>
#include <exception>
#include <cmath>
#include <algorithm>
#include <iomanip>
using std::initializer_list;
using std::cin;
using std::cout;
using std::endl;

class FourierovRed
{
    double period;
    int n;
    double *a=nullptr;
    double *b=nullptr;
    static constexpr double pi=3.14159265358979323846;
public:
    FourierovRed(double T, initializer_list<double> i1, initializer_list<double> i2) {
        n = (i1.size()>=i2.size())?i1.size():i2.size();
        if(n!=i1.size() && n==i2.size()) n++;
        period=T;
        a=new double[n] {};
        b=new double[n] {};
        std::copy(i1.begin(),i1.end(),a);
        std::copy(i2.begin(),i2.end(),b+1);
    }

    FourierovRed(int n, double T,std::function<double(int)> fun1, std::function<double(int)> fun2) {
        if(n<=0) throw std::domain_error("Stepen mora biti pozitivan");
        FourierovRed::n=n+1;
        period = T;
        a=new double[n+1] {};
        b=new double[n+1] {};
        for(int k=0; k<n+1; k++)
            a[k]=fun1(k);
        for(int k=1; k<n+1; k++)
            b[k]=fun2(k);
    }

    FourierovRed(int n, double p, double q,std::function<double(double)> fun, int m) {
        if(n<=0) throw std::domain_error("Stepen mora biti pozitivan");
        if(m<=0) throw std::domain_error("Broj podintervala mora biti pozitivan");
        if(!(p<q)) throw std::range_error("Neispravan interval");
        FourierovRed::n=n+1;
        period=q-p;
        a=new double[n+1] {};
        b=new double[n+1] {};

        for(int k=0; k<n+1; k++) {
            double suma {};
            for(int i=1; i<=m-1; i++) 
                suma+=fun(p+(i*period)/m)*cos(2*k*pi*(p/period+double(i)/m));
            a[k]=(fun(p)+fun(q))/m*cos((2*k*pi*p)/period)+ (2./m)*suma;
        }

        for(int k=1; k<n+1; k++) {
            double suma {};
            for(int i=1; i<=m-1; i++)
                suma+=fun(p+(i*period)/m)*sin(2*k*pi*(p/period+double(i)/m));
            b[k]=(fun(p)+fun(q))/m*sin((2*k*pi*p)/period)+ (2./m) *suma;
        }
    }

    FourierovRed(const FourierovRed &f) {
        n=f.n;
        period=f.period;
        a= new double[n] {};
        b= new double[n] {};
        std::copy(f.a,f.a+n,a);
        std::copy(f.b,f.b+n,b);
    }

    FourierovRed(FourierovRed&&f) {
        n=f.n;
        period=f.period;
        a=f.a;
        b=f.b;
        f.a=nullptr;
        f.b=nullptr;
    }

    FourierovRed & operator =(const FourierovRed &f) {
        if(this!=&f) {
            delete[] a;
            delete[] b;
            n=f.n;
            period=f.period;
            a = new double[n] {};
            b= new double[n] {};
            std::copy(f.a,f.a+n,a);
            std::copy(f.b,f.b+n,b);
        }
        return *this;
    }

    FourierovRed& operator =(FourierovRed &&f) {
        if(this!=&f) {
            delete[] a;
            delete[] b;
            n=f.n;
            period=f.period;
            a=f.a;
            b=f.b;
            f.a=nullptr;
            f.b=nullptr;
        }
        return *this;
    }

    double operator ()(double x) const {
        double suma=a[0]/2;
        for(int k=1; k<n; k++)
            suma+=(*(a+k)*std::cos((2*k*pi*x)/period)+*(b+k)*std::sin((2*k*pi*x)/period));
        return suma;
    }

    std::pair<double&,double &> operator [](int k) {
        if(k>=n || k<0) throw std::range_error("Neispravan indeks");
        return std::pair<double&,double &>(*(a+k),*(b+k));
    }

    std::pair<double,double> operator [](int k) const {
        if(k>=n || k<0) throw std::range_error("Neispravan indeks");
        return std::make_pair(a[k],b[k]);
    }

    ~FourierovRed() {
        delete[] a;
        delete[] b;
    }
};

int main (){
    return 0;
}
