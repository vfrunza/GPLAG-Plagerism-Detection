/B2017/2018: Zadaća 5, Zadatak 4
#include <iostream>
#include <initializer_list>
#include <functional>
#include <stdexcept>
#include <cmath>
#include <tuple>
#include <utility>

constexpr double pi=4*std::atan(1);

class FourierovRed
{
double *a=nullptr,*b=nullptr;
int vel=0;
double T=0;
double ignore=0;
    public:
    FourierovRed(double period,std::initializer_list<double>,std::initializer_list<double>);
    FourierovRed(int stepen, double period, std::function<double(int)>,std::function<double(int)>);
    FourierovRed(int stepen, double p, double q,std::function<double(double)>, int m);
    //treba mi kopirajuci konstruktor
    FourierovRed(const FourierovRed&);
    //pomjerajuci konstruktor
    FourierovRed( FourierovRed&&);
    //kopirajuci operator dodjele
    FourierovRed& operator=(const FourierovRed&);
    //pomjerajuci operator dodjele
    FourierovRed& operator=( FourierovRed&&);
    
    std::pair<double,double> operator[](int)const;
    // std::pair<double&,double&> &operator[](int);
    
    double operator()(double);
    ~FourierovRed();
};
FourierovRed& FourierovRed::operator=( FourierovRed&& temp)
{
    if(this==&temp)return *this;
    
        if(a)delete[] a;
        if(b)delete[] b;
    
        vel=temp.vel;
        T=temp.T;
        a=temp.a;
        b=temp.b;
        temp.vel=0;
        temp.T=0;
        temp.a=nullptr;
        temp.b=nullptr;
        return *this;
    
}
FourierovRed& FourierovRed::operator=(const FourierovRed& temp)
{
    if(this==&temp)return *this;
        if(a)delete[] a;
        if(b)delete[] b;
    
    vel=temp.vel;
    T=temp.T;
    a=b=nullptr;
    try{
        a=new double[vel+1];
        b=new double[vel];
    }
    catch(...)
    {
        vel=0;
        if(a)delete[] a;
        if(b)delete[] b;
    }
    a[0]=temp.a[0];
    for(int i=0;i<vel;i++)
    {
        a[i+1]=temp.a[i+1];
        b[i]=temp.b[i];
    }
    return *this;
}
FourierovRed::FourierovRed( FourierovRed&& temp)
{
        vel=temp.vel;
        T=temp.T;
        a=temp.a;
        b=temp.b;
        temp.vel=0;
        temp.T=0;
        temp.a=nullptr;
        temp.b=nullptr;
}
FourierovRed::FourierovRed(const FourierovRed& temp)
{
    vel=temp.vel;
    T=temp.T;
    a=b=nullptr;
    try{
        a=new double[vel+1];
        b=new double[vel];
    }
    catch(...)
    {
        vel=0;
        if(a)delete[] a;
        if(b)delete[] b;
    }
    a[0]=temp.a[0];
    for(int i=0;i<vel;i++)
    {
        a[i+1]=temp.a[i+1];
        b[i]=temp.b[i];
    }
}

std::pair<double,double> FourierovRed::operator[](int i)const
{
    if(i<0||i>vel)throw std::range_error("Neispravan indeks");
    return std::make_pair(a[i],(i==0)?0:b[i-1]);    
}
// std::pair<double&,double&> &FourierovRed::operator[](int i)
// {
//     if(i<0||i>vel)throw std::range_error("Neispravan indeks");
//     return std::pair<double&,double&>&(a[i],(i==0)?ignore:b[i-1]);    
// }

double FourierovRed::operator()(double x)
{
    double f=0;
    f+=a[0]/2;
    // std::cout<<f;
    for(int i=0;i<vel;i++)
    {
        f+=a[i+1]*std::cos((2*(i+1)*pi*x)/T)+b[i]*std::sin((2*(i+1)*pi*x)/T);
    }
    return f;
}
FourierovRed::~FourierovRed()
{
    if(a)delete[] a;
    if(b)delete[] b;
    vel=0;
    T=0;
}
FourierovRed::FourierovRed(double period,std::initializer_list<double> ka,std::initializer_list<double>kb)
{
    T=period;
    vel=(ka.size()>kb.size())?ka.size()-1:kb.size();
    a=b=nullptr;
    try{
        a=new double[vel+1];
        b=new double[vel];
    }
    catch(...)
    {
        vel=0;
        if(a)delete[] a;
        if(b)delete[] b;
    }
    auto poka(ka.begin());
    auto pokb(kb.begin());
    a[0]=0;
    if(ka.size()>0)a[0]=*poka++;
    
    for(int i=0;i<vel;i++)
    {
        a[i+1]=0;
        b[i]=0;
        if(poka!=ka.end() && i+1<ka.size())a[i+1]=*poka++;
        if(pokb!=kb.end())b[i]=*pokb++;
    }
}

FourierovRed::FourierovRed(int stepen, double period, std::function<double(int)> f,std::function<double(int)> g)
{
    if(stepen<1)throw std::domain_error("Stepen mora biti pozitivan");
    a=b=nullptr;
    vel=stepen;
    try{
        a=new double[vel+1];
        b=new double[vel];
    }
    catch(...)
    {
        delete[] a;
        delete[] b;
        vel=0;
    }
    a[0]=f(0);
    for( int i = 0; i< vel;i++)
    {
        a[i+1]=f(i+1);
        b[i]=g(i+1);
    }
    T=period;
}

FourierovRed::FourierovRed(int stepen, double p, double q,std::function<double(double)> f, int m)
{
    
    if(stepen<1)throw std::domain_error("Stepen mora biti pozitivan");
    if(m<1)throw std::domain_error("Broj podintervala mora biti pozitivan");
    if(!(p<q))throw std::range_error("Neispravan interval");
    a=b=nullptr;
    vel=stepen;
    T=q-p;
    try{
        a=new double[vel+1];
        b=new double[vel];
    }
    catch(...)
    {
        delete[] a;
        delete[] b;
    }
    
    for(int k=0;k<vel+1;k++)
    {
        a[k]=((f(p)+f(q))/m)*std::cos(2*k*pi*p/static_cast<double>(T));

        for(int i=1;i<m;i++)
        {
            a[k]+=2./m*( f(p+i*T/static_cast<double>(m))*std::cos(2*k*pi*(p/T+i/static_cast<double>(m))));
        }
    }
    for(int k=0;k<vel;k++)
    {
        b[k]=(f(p)+f(q))/m*std::sin(2*(k+1)*pi*p/static_cast<double>(T));
        for(int i=1;i<m;i++)
        {
            b[k]+=2./m*( f(p+i*T/static_cast<double>(m))*std::sin(2*(k+1)*pi*(p/T+i/static_cast<double>(m))));
        }
    }
    
}

int main ()
{
    // std::cout<<"hasiuhkewekjkwefhwkef";
    FourierovRed f2(50, 0, 2*pi, [](double x) { return x * x; }, 1000);
    std::cout<<f2(3);
    
	return 0;
}
