/B2017/2018: Zadaća 5, Zadatak 4
#include <iostream>
#include <initializer_list>
#include <functional>
#include <cmath>
#include <utility>
#include <new>

class FourierovRed {
    int velicina_a, velicina_b;
    double* niz_a;
    double* niz_b;
    double period;
    int stepen;
    static constexpr double PI=4*std::atan(1);
public:
    FourierovRed(double T, std::initializer_list<double> a_ovi, std::initializer_list<double> b_ovi);
    FourierovRed(int N, double T, std::function<double(int)> f1, std::function<double(int)> f2);
    FourierovRed(int N, double p, double q, std::function<double(double)> f, int M);
    double operator ()(double x) const;
    std::pair<double, double> operator [](int k) const;
    std::pair<double &, double &> operator [](int k);
    ~FourierovRed();
    FourierovRed(const FourierovRed &fr);
    FourierovRed(FourierovRed &&fr);
    FourierovRed &operator =(const FourierovRed &fr);
    FourierovRed &operator =(FourierovRed &&fr);
};

FourierovRed::~FourierovRed() {
    delete[] niz_a;
    niz_a=nullptr;
    delete[] niz_b;
    niz_b=nullptr;
}

FourierovRed::FourierovRed(double T, std::initializer_list<double> a_ovi, std::initializer_list<double> b_ovi) : 
velicina_a(a_ovi.size()), velicina_b(b_ovi.size()+1), niz_a(nullptr), niz_b(nullptr), period(T) {
    try {
        if (velicina_a==velicina_b) {
            niz_a=new double[velicina_a]{};
            niz_b=new double[velicina_b]{};
            auto iter1=a_ovi.begin();
            for (int i=0; i<velicina_a; i++) {
                niz_a[i]=(*iter1);
                iter1++;
            }
            auto iter2=b_ovi.begin();
            for (int i=1; i<velicina_b; i++) {
                niz_b[i]=(*iter2);
                iter2++;
            }
        }
        else if (velicina_a<velicina_b) {
            niz_a=new double[velicina_b]{};
            niz_b=new double[velicina_b]{};
            auto iter2=b_ovi.begin();
            for (int i=1; i<velicina_b; i++) {
                niz_b[i]=(*iter2);
                iter2++;
            }
            auto iter1=a_ovi.begin();
            for (int i=0; i<velicina_a; i++) {
                niz_a[i]=(*iter1);
                iter1++;
            }
            velicina_a=velicina_b;
        }
        else if (velicina_a>velicina_b) {
            niz_a=new double[velicina_a]{};
            niz_b=new double[velicina_a]{};
            auto iter1=a_ovi.begin();
            for (int i=0; i<velicina_a; i++) {
                niz_a[i]=(*iter1);
                iter1++;
            }
            auto iter2=b_ovi.begin();
            for (int i=1; i<velicina_b; i++) {
                niz_b[i]=(*iter2);
                iter2++;
            }
            velicina_b=velicina_a;
        }
        stepen=velicina_b-1;
    }
    catch(...) {
        delete[] niz_a; niz_a=nullptr;
        delete[] niz_b; niz_b=nullptr;
        throw;
    }
}

FourierovRed::FourierovRed(int N, double T, std::function<double(int)> f1, std::function<double(int)> f2) : 
velicina_a(N+1), velicina_b(N+1), period(T), stepen(N), niz_a(nullptr), niz_b(nullptr) {
    if (N<=0) throw std::domain_error("Stepen mora biti pozitivan");
    try {
        niz_a=new double[velicina_a]{};
        for (int i=0; i<velicina_a; i++) {
            niz_a[i]=f1(i);
        }
        niz_b=new double[velicina_b]{};
        niz_b[0]=0;
        for (int i=1; i<velicina_b; i++) {
            niz_b[i]=f2(i);
        }
    }
    catch(...) {
        delete[] niz_a; niz_a=nullptr;
        delete[] niz_b; niz_b=nullptr;
        throw;
    }
}

FourierovRed::FourierovRed(int N, double p, double q, std::function<double(double)> f, int M) : 
stepen(N), period(q-p), velicina_a(N+1), velicina_b(N+1), niz_a(nullptr), niz_b(nullptr) {
    if (N<=0) throw std::domain_error("Stepen mora biti pozitivan");
    if (M<=0) throw std::domain_error("Broj podintervala mora biti pozitivan");
    if (p>=q) throw std::range_error("Neispravan interval");
    try {
        niz_a=new double[velicina_a]{};
        for (int k=0; k<velicina_a; k++) {
            double suma(0);
            for (int i=1; i<=M-1; i++) {
                suma+=(f(p+double(i*period/M)))*std::cos(2*k*PI*(p/period+1.*i/M));
            }
            suma*=(2./M);
            niz_a[k]=suma+double((f(p)+f(q))/M)*std::cos((2*k*PI*p)/period);
        }
        niz_b=new double[velicina_b]{};
        niz_b[0]=0;
        for (int k=1; k<velicina_b; k++) {
            double suma(0);
            for (int i=1; i<=M-1; i++) {
                suma+=(f(p+double(i*period/M)))*std::sin(2*k*PI*(p/period+1.*i/M));
            }
            suma*=(2./M);
            niz_b[k]=suma+double((f(p)+f(q))/M)*std::sin((2*k*PI*p)/period);
        }
    }
    catch(...) {
        delete[] niz_a; niz_a=nullptr;
        delete[] niz_b; niz_b=nullptr;
        throw;
    }
}

double FourierovRed::operator ()(double x) const {
    double suma(0);
    suma=niz_a[0]/2;
    for (int k=1; k<=stepen; k++) {
        suma+=niz_a[k]*std::cos(2*k*PI*x/period)+niz_b[k]*std::sin(2*k*PI*x/period);
    }
    return suma;
}

std::pair<double, double> FourierovRed::operator [](int k) const {
    if (k<0 || k>stepen) throw std::range_error("Neispravan indeks");
    return std::make_pair(niz_a[k], niz_b[k]);
}

std::pair<double &, double &> FourierovRed::operator [](int k) {
    if (k<0 || k>stepen) throw std::range_error("Neispravan indeks");
    return {niz_a[k], niz_b[k]};
}

FourierovRed::FourierovRed(const FourierovRed &fr) : 
velicina_a(fr.velicina_a), velicina_b(fr.velicina_b), stepen(fr.stepen), period(fr.period), niz_a(nullptr), niz_b(nullptr) {
    try {
        niz_a=new double[velicina_a]{};
        niz_b=new double[velicina_b]{};
        for (int i=0; i<velicina_a; i++) niz_a[i]=fr.niz_a[i];
        for (int i=0; i<velicina_b; i++) niz_b[i]=fr.niz_b[i];
    }
    catch(...) {
        delete[] niz_a; niz_a=nullptr;
        delete[] niz_b; niz_b=nullptr;
        throw;
    }
}

FourierovRed::FourierovRed(FourierovRed &&fr) : 
stepen(fr.stepen), period(fr.period), velicina_a(fr.velicina_a), velicina_b(fr.velicina_b) {
    niz_a=fr.niz_a; niz_b=fr.niz_b;
    fr.niz_a=nullptr; fr.niz_b=nullptr;
}

FourierovRed &FourierovRed::operator =(const FourierovRed &fr) {
    if (&fr==this) return *this;
    double* novi_prostor_a(nullptr);
    double* novi_prostor_b(nullptr);
    try {
        novi_prostor_a=new double[fr.velicina_a]{};
        novi_prostor_b=new double[fr.velicina_b]{};
        for (int i=0; i<fr.velicina_a; i++) novi_prostor_a[i]=fr.niz_a[i];
        for (int i=0; i<fr.velicina_b; i++) novi_prostor_b[i]=fr.niz_b[i];
        delete[] niz_a; delete[] niz_b;
        niz_a=novi_prostor_a; niz_b=novi_prostor_b;
        stepen=fr.stepen; period=fr.period;
        velicina_a=fr.velicina_a; velicina_b=fr.velicina_b;
    }
    catch(...) {
        delete[] novi_prostor_a; novi_prostor_a=nullptr;
        delete[] novi_prostor_b; novi_prostor_b=nullptr;
        throw;
    }
    return *this;
}

FourierovRed &FourierovRed::operator =(FourierovRed &&fr) {
    if (&fr==this) return *this;
    std::swap(niz_a, fr.niz_a); std::swap(niz_b, fr.niz_b);
    std::swap(velicina_a, fr.velicina_a); std::swap(velicina_b, fr.velicina_b);
    std::swap(stepen, fr.stepen); std::swap(period, fr.period);
    return *this;
}

int main ()
{
    
	return 0;
}
