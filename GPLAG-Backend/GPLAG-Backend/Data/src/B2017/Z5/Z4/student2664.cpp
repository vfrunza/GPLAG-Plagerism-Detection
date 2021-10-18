/B2017/2018: Zadaća 5, Zadatak 4
#include <cmath>
#include <utility> // pair
#include <iostream>
#include <algorithm>
#include <stdexcept>
#include <functional>
#include <initializer_list>
using std::initializer_list;
using std::domain_error;
using std::range_error;
using std::function;
using std::pair;
using std::copy;
using std::cos;
using std::sin;
using std::tie;

class FourierovRed {
    static constexpr double PI = 3.141592653589793;
    double T;
    double* a, *b;
    int N;
    void TestIndeksa(int k) const {
        if(k < 0 || k >= N) throw range_error("Neispravan indeks");
    }
  public:
    ~FourierovRed() { delete[] a; delete[] b;}
    FourierovRed(double T, initializer_list<double> a_lista, initializer_list<double> b_lista) : T(T), a(nullptr), b(nullptr) {
        if(a_lista.size() <= b_lista.size()) N = b_lista.size()+1;
        else N = a_lista.size();
        a = new double[N]{};
        try{ b = new double[N]{}; }
        catch(...){ delete a; throw; }
        copy(a_lista.begin(), a_lista.end(), a);
        copy(b_lista.begin(), b_lista.end(), b+1); // da bi b[0] bilo 0
    }
    FourierovRed(int N, double T, function<double(int)> f1, function<double(int)> f2) :  T(T), a(nullptr), b(nullptr), N(N) {
        if(N <= 0) throw domain_error("Stepen mora biti pozitivan");
        a = new double[N]{};
        try{ b = new double[N]{}; }
        catch(...){ delete a; throw; }
        for(int i=0; i<N; i++){
            a[i] = f1(i);
            if(i>0) b[i] = f2(i);
        }
    }
    FourierovRed(int N, double p, double q, function<double(double)> f, int M) : T(p-q), a(nullptr), b(nullptr) {
        if(!(N > 0)) throw domain_error("Stepen mora biti pozitivan");
        else if(!(M > 0))  throw domain_error("Broj podintervala mora biti pozitivan");
        if(!(p < q)) throw range_error("Neispravan interval");
        
        this->N = N;
        a = new double[N]{};
        try{ b = new double[N]{}; }
        catch(...) { delete a; throw;}
        
        for(int i=0; i<=N; i++) { // od 0 ?? <= ??
            double pom((f(p) + f(q))/M), tmp(2*i*PI*p/T);
            a[i] = pom * cos(tmp);
            if(i>0) b[i] = pom * sin(tmp);
            double suma_a(0), suma_b(0), pom1, pom2;
            for(int j=1; j<=M-1; j++) {// <= ??
                pom1 = p + j*T/M;
                pom2 = 2*j*PI*(p/T + j/M);
                suma_a += f(pom1)*cos(pom2);
                suma_b += f(pom1)*sin(pom2);
            }
            a[i] += suma_a * 2/M;
            if(i>0) b[i] += suma_b * 2/M;
        }
        
    }
    double operator ()(double x) const { // double ??
        double suma(a[0]/2), pom(2*PI*x/T);
        for(int k=1; k<=N; k++){
            suma += a[k]*cos(pom*k) + b[k]*cos(pom*k);
        }
        return suma;
    }
   pair<double, double> operator [](int k) const {
        TestIndeksa(k);
        return {a[k], b[k]};
    }
    pair<double &, double &> operator [](int k) {
        TestIndeksa(k);
        return {a[k], b[k]};
    }
    
};


int main (){
    
    
    
	return 0;
}
