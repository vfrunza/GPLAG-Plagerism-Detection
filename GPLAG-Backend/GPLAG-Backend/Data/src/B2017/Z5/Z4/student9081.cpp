/B2017/2018: Zadaća 5, Zadatak 4
#include <iostream>
#include <initializer_list>
#include <new>
#include <stdexcept>
#include <functional>
#include <cmath>
#include <utility>

const double PI(4*std::atan(1));
double nula(0);

class FourierovRed
{
    double period;
    int stepen;
    double *ak,*bk;
public:
    FourierovRed (double T, std::initializer_list<double> koef1, std::initializer_list<double> koef2);
    FourierovRed (int n, double T, std::function<double(int)> f1, std::function<double(int)> f2);
    FourierovRed (int n, double p, double q, std::function<double(double)> f, int M);
    ~FourierovRed () {delete[] ak; delete[] bk;}
    FourierovRed (const FourierovRed &f);
    FourierovRed (FourierovRed &&f);
    FourierovRed &operator= (const FourierovRed &f);
    FourierovRed &operator= (FourierovRed &&f);
    double operator () (double x) const;
    std::pair<double,double> operator [] (int k) const;
    std::pair<double&,double&> operator [] (int k);
};

std::pair<double,double> FourierovRed::operator[] (int k) const
{
    if (k<0 || k>stepen) throw std::range_error ("Neispravan indeks");
    if (k==0) return std::make_pair(ak[0],0);
    return std::make_pair(ak[k],bk[k-1]);
}

std::pair<double&,double&> FourierovRed::operator[] (int k)
{
    if (k<0 || k>stepen) throw std::range_error ("Neispravan indeks");
    if (k==0)
    {
        nula=0;
        std::pair<double&,double&> par(ak[0],nula);
        return par;
    }
    std::pair<double&,double&> par(ak[k],bk[k-1]);
    return par;
}

double FourierovRed::operator() (double x) const
{
    double vrati(0);
    for (int i=1;i<stepen+1;i++)
        vrati+=ak[i]*std::cos(2*i*PI*x/period);
    for (int i=0;i<stepen;i++)
        vrati+=bk[i]*std::sin(2*(i+1)*PI*x/period);
    vrati+=ak[0]/2;
    return vrati;
}

FourierovRed::FourierovRed (int n, double p, double q, std::function<double(double)> f, int M):period(q-p),stepen(n),ak(nullptr),bk(nullptr)
{
    if (n<=0) throw std::domain_error ("Stepen mora biti pozitivan");
    if (M<=0) throw std::domain_error ("Broj podintervala mora biti pozitivan");
    if (!(p<q)) throw std::range_error ("Neispravan interval");
    try
    {
        ak=new double[n+1]; bk=new double [n];
    }
    catch (std::bad_alloc)
    {
        delete[]ak; delete[] bk;
        throw;
    }
    for (int i=0;i<n+1;i++)
    {
        double suma(0);
        for (int j=1;j<=M-1;j++)
            suma+=(f(p+j*period/M)*std::cos(2*i*PI*(double(p)/period+double(j)/M)));
        suma*=2; suma/=M;
        ak[i]=(f(p)+f(q))*std::cos(double(2*i*PI*p)/period)/M+suma;
    }
    for (int i=0;i<n;i++)
    {
        double suma(0);
        for (int j=1;j<=M-1;j++)
            suma+=f(p+double(j*period)/M)*std::sin(2*(i+1)*PI*(double(p)/period+double(j)/M));
        suma=suma*2/M;
        bk[i]=(f(p)+f(q))/M*std::sin(double(2*(i+1)*PI*p)/period)+suma;
    }
}

FourierovRed::FourierovRed (int n, double T, std::function<double(int)> f1, std::function<double(int)> f2):period(T),stepen(n),ak(nullptr),bk(nullptr)
{
    if (n<=0) throw std::domain_error ("Stepen mora biti pozitivan");
    try
    {
        ak=new double[n+1]; bk=new double [n];
    }
    catch (std::bad_alloc)
    {
        delete[] ak; delete[] bk;
        throw;
    }
    for (int i=0;i<n+1;i++)
        ak[i]=f1(i);
    for (int i=0;i<n;i++)
        bk[i]=f2(i+1);
}

FourierovRed::FourierovRed (double T, std::initializer_list<double> koef1, std::initializer_list<double> koef2): period(T),ak(nullptr),bk(nullptr)
{
    int vel(koef2.size());
    if (int(koef1.size())-1>int(koef2.size())) vel=koef1.size()-1;
    stepen=vel;
    try
    {
        ak=new double [vel+1]; bk=new double[vel];
    }
    catch (std::bad_alloc)
    {
        delete[] ak; delete[] bk;
        throw;
    }
    auto lista1(koef1.begin()),lista2(koef2.begin());
    for (int i=0;i<vel+1;i++)
    {
        if (i<koef1.size())
        {
            ak[i]=*lista1;
            lista1++;
        }
        else ak[i]=0;
    }
    for (int i=0;i<vel;i++)
    {
        if (i<koef2.size())
        {
            bk[i]=*lista2;
            lista2++;
        }
        else bk[i]=0;
    }
}

FourierovRed::FourierovRed (const FourierovRed &f): period(f.period),stepen(f.stepen),ak(nullptr),bk(nullptr)
{
    try
    {
        ak=new double[stepen+1]; bk=new double[stepen];
    }
    catch (std::bad_alloc)
    {
        delete[] ak; delete[] bk; throw;
    }
    for (int i=0;i<stepen+1;i++)
        ak[i]=f.ak[i];
    for (int i=0;i<stepen;i++)
        bk[i]=f.bk[i];
}

FourierovRed::FourierovRed (FourierovRed &&f): period(f.period),stepen(f.stepen),ak(f.ak),bk(f.bk)
{
    f.ak=nullptr; f.bk=nullptr;
}

FourierovRed &FourierovRed::operator= (const FourierovRed &f)
{
    double *novi_ak(nullptr),*novi_bk(nullptr);
    try
    {
        novi_ak=new double[f.stepen+1]; novi_bk=new double[f.stepen];
        for (int i=0;i<f.stepen+1;i++)
            novi_ak[i]=f.ak[i];
        for (int i=0;i<f.stepen;i++)
            novi_bk[i]=f.bk[i];
    }
    catch(std::bad_alloc)
    {
        delete[] novi_ak; delete[] novi_bk;
        throw;
    }
    period=f.period; stepen=f.stepen;
    delete[] ak; delete[] bk;
    ak=novi_ak; bk=novi_bk;
    return *this;
}

FourierovRed &FourierovRed::operator= (FourierovRed &&f)
{
    std::swap(period,f.period); std::swap(stepen,f.stepen);
    std::swap(ak,f.ak); std::swap(bk,f.bk);
    return *this;
}

int main ()
{
    int n;
    for (;;) {
    int m;
    std::cout<<"Unesite stepen Fourierovog Reda: \n";
    std::cin>>m;
    if (m==-1) break;
    std::cout<<"Unesite broj podintervala: \n";
    std::cin>>n;
    double x;
    std::cout<<"Unesite tacku u kojoj se racuna vrijednost Fourierovog Reda: \n";
    std::cin>>x;
    try {
    FourierovRed f1(m,0,2*PI,[] (double x) {return x*x;},n),f2(m,2*PI,[] (int k) {return k==0 ? 8*PI*PI/3 : 4./(k*k);}, [] (int k) {return -4*PI/k;});
    std::cout<<"U tacki x = "<<x<<" je :\n";
    std::cout<<"f1("<<x<<") = "<<f1(x)<<" i f2("<<x<<") = "<<f2(x)<<std::endl;
    std::cout<<"Unesite indeks za poredbu: \n";
    int i;
    std::cin>>i;
    std::cout<<f1[i].first<<" i "<<f2[i].first<<"\n";
    std::cout<<f1[i].second<<" i "<<f2[i].second<<"\n";    
    }
    catch (...)
    {std::cout<<"Greska!Unesite ponovo!\n";}
    }
	return 0;
}
