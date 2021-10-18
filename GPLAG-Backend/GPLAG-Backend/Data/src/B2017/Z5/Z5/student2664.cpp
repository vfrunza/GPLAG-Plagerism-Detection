/B2017/2018: Zadaća 5, Zadatak 5
#include <cmath>
#include <utility> // pair
#include <vector>
#include <iostream>
#include <algorithm>
#include <stdexcept>
#include <functional>
#include <initializer_list>
using std::initializer_list;
using std::domain_error;
using std::range_error;
using std::function;
using std::vector;
using std::pair;
using std::copy;
using std::cos;
using std::sin;
using std::tie;

class FourierovRed {
    static constexpr double PI = 3.141592653589793;
    double T;
    vector<double> a, b;
    int N;
    void TestIndeksa(int k) const {
        if(k < 0 || k >= N) throw range_error("Neispravan indeks");
    }
  public:
    FourierovRed(double T, initializer_list<double> a_lista, initializer_list<double> b_lista) : T(T) {
        if(a_lista.size() <= b_lista.size()) N = b_lista.size()+1;
        else N = a_lista.size();
        a.resize(N, 0);
        b.resize(N, 0); 
        copy(a_lista.begin(), a_lista.end(), a.begin());
        copy(b_lista.begin(), b_lista.end(), b.begin()+1); // da bi b[0] bilo 0
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
