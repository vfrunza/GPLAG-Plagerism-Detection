/B2017/2018: Zadaća 5, Zadatak 5
#include <iostream>
#include <initializer_list>
#include <functional>
#include <cmath>
#include <utility>
#include <vector>

class FourierovRed {
    std::vector<double> vektor_a;
    std::vector<double> vektor_b;
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
    ~FourierovRed()=default;
    FourierovRed(const FourierovRed &fr)=default;
    FourierovRed(FourierovRed &&fr)=default;
    FourierovRed &operator =(const FourierovRed &fr);
    FourierovRed &operator =(FourierovRed &&fr)=default;
};

FourierovRed::FourierovRed(double T, std::initializer_list<double> a_ovi, std::initializer_list<double> b_ovi) : 
period(T) {
    int velicina_a(a_ovi.size()); int velicina_b(b_ovi.size()+1);
    if (velicina_a==velicina_b) {
        for (auto iter=a_ovi.begin(); iter!=a_ovi.end(); iter++) {
            vektor_a.push_back(*iter);
        }
        vektor_b.push_back(0);
        for (auto iter=b_ovi.begin(); iter!=b_ovi.end(); iter++) {
            vektor_b.push_back(*iter);
        }
    }
    else if (velicina_a<velicina_b) {
        vektor_b.push_back(0);
        for (auto iter=b_ovi.begin(); iter!=b_ovi.end(); iter++) {
            vektor_b.push_back(*iter);
        }
        for (auto iter=a_ovi.begin(); iter!=a_ovi.end(); iter++) {
            vektor_a.push_back(*iter);
        }
        while (velicina_a<velicina_b) {
            vektor_a.push_back(0);
            velicina_a++;
        }
    }
    else if (velicina_a>velicina_b) {
        for (auto iter=a_ovi.begin(); iter!=a_ovi.end(); iter++) {
            vektor_a.push_back(*iter);
        }
        vektor_b.push_back(0);
        for (auto iter=b_ovi.begin(); iter!=b_ovi.end(); iter++) {
            vektor_b.push_back(*iter);
        }
        while (velicina_b<velicina_a) {
            vektor_b.push_back(0);
            velicina_b++;
        }
    }
    stepen=velicina_b-1;
}

FourierovRed::FourierovRed(int N, double T, std::function<double(int)> f1, std::function<double(int)> f2) : 
period(T), stepen(N) {
    if (N<=0) throw std::domain_error("Stepen mora biti pozitivan");
    int velicina_a(N+1); int velicina_b(N+1);
    vektor_a.resize(velicina_a); vektor_b.resize(velicina_b);
    for (int i=0; i<velicina_a; i++) {
        vektor_a[i]=f1(i);
    }
    vektor_b[0]=0;
    for (int i=1; i<velicina_b; i++) {
        vektor_b[i]=f2(i);
    }
}

FourierovRed::FourierovRed(int N, double p, double q, std::function<double(double)> f, int M) : 
stepen(N), period(q-p) {
    if (N<=0) throw std::domain_error("Stepen mora biti pozitivan");
    if (M<=0) throw std::domain_error("Broj podintervala mora biti pozitivan");
    if (p>=q) throw std::range_error("Neispravan interval");
    int velicina_a(N+1); int velicina_b(N+1);
    vektor_a.resize(velicina_a); vektor_b.resize(velicina_b);
    for (int k=0; k<velicina_a; k++) {
        double suma(0);
        for (int i=1; i<=M-1; i++) {
            suma+=f(p+(i*period/M))*std::cos(2*k*PI*(p/period+1.*i/M));
        }
        suma*=2./M;
        vektor_a[k]=suma+((f(p)+f(q))/M)*std::cos((2*k*PI*p)/period);
    }
    vektor_b[0]=0;
    for (int k=1; k<velicina_b; k++) {
        double suma(0);
        for (int i=1; i<=M-1; i++) {
            suma+=f(p+(i*period/M))*std::sin(2*k*PI*(p/period+1.*i/M));
        }
        suma*=2./M;
        vektor_b[k]=suma+((f(p)+f(q))/M)*std::sin((2*k*PI*p)/period);
    }
}

double FourierovRed::operator ()(double x) const {
    double suma(0);
    suma=vektor_a[0]/2;
    for (int k=1; k<=stepen; k++) {
        suma+=vektor_a[k]*std::cos(2*k*PI*x/period)+vektor_b[k]*std::sin(2*k*PI*x/period);
    }
    return suma;
}

std::pair<double, double> FourierovRed::operator [](int k) const {
    if (k<0 || k>stepen) throw std::range_error("Neispravan indeks");
    return std::make_pair(vektor_a[k], vektor_b[k]);
}

std::pair<double &, double &> FourierovRed::operator [](int k) {
    if (k<0 || k>stepen) throw std::range_error("Neispravan indeks");
    return {vektor_a[k], vektor_b[k]};
}

FourierovRed &FourierovRed::operator =(const FourierovRed &fr) {
    if (&fr==this) return *this;
    vektor_a=fr.vektor_a; vektor_b=fr.vektor_b;
    stepen=fr.stepen; period=fr.period;
    return *this;
}

int main ()
{
	return 0;
}
