/B2017/2018: Zadaća 5, Zadatak 4
#include <iostream>
#include <stdexcept>
#include <functional>
#include <algorithm>
#include <utility>
#include <cmath>
#include <vector>

class FourierovRed {
private:
    double static constexpr PI = 4 * std::atan(1);
    double static constexpr ERROR = 0.0000000001;
    int N;
    double T;
    std::vector<double> a, b;
    
    void static checkParams(int num, int M = 1, double p = 1, double q = 1, bool ntype = false) {
      if(num <= 0) throw std::domain_error("Stepen mora biti pozitivan");
      if(ntype) {
        if(M <= 0) throw std::domain_error("Broj podintervala mora biti pozitivan");
        if(p - q >= ERROR) throw std::range_error("Neispravan interval");
      }
    }
    void IsprazniMemoriju();
public:
  ~FourierovRed();
  FourierovRed(const FourierovRed& red);
  FourierovRed(FourierovRed&& red);
  
  FourierovRed& operator=(const FourierovRed& red);
  FourierovRed& operator=(FourierovRed&& red);
  
  FourierovRed(double T, std::initializer_list<double> k_a, std::initializer_list<double> k_b);
  FourierovRed(int N, double T, std::function<double(int)> funk_a, std::function<double(int)> funk_b);
  FourierovRed(int N, double p, double q, std::function<double(double)> f, int M);
  
  double operator()(double x) const;
  std::pair<double, double> operator[](int k) const;
  std::pair<double&, double&> operator[](int k);
};

/// implementation of FourierovRed interface
FourierovRed::~FourierovRed() {
	this->IsprazniMemoriju();
}
void FourierovRed::IsprazniMemoriju() {
	  a.clear(); b.clear();
    this->N = 0; this->T = 0;
}
/// ctors
FourierovRed::FourierovRed(double t, std::initializer_list<double> k_a, std::initializer_list<double> k_b) : 
    T(t), a(k_a) {
  N = std::max(k_a.size(), k_b.size()) + (k_b.size() >= k_a.size() ? 1 : 0);
  a.resize(N, 0);
  b.push_back(0);
  b.insert(b.end(), k_b);
  b.resize(N, 0);
}
FourierovRed::FourierovRed(int N, double T, std::function<double(int)> funk_a, std::function<double(int)> funk_b) : 
	  N(N), T(T) {
  checkParams(N);
  
  a.push_back(funk_a(0));
  b.push_back(0); 
  
  for(int i(1); i <= N; ++i) {
      a.push_back(funk_a(i));
      b.push_back(funk_b(i));
  }
}
FourierovRed::FourierovRed(int N, double p, double q, std::function<double(double)> f, int M) : 
	  N(N), T(q - p){
  checkParams(N, M, p, q, true);
 
  double konstanta ((f(p) + f(q)) / M); /// downcasting, potential bug
  auto gen_function = [=](int k, std::function<double(double)> nizFunkcija) -> double {
    double sum(0);
    for(int i(1); i < M; ++i)
      sum += f(p + (i * T / M)) * nizFunkcija((2 * k * PI * (p / T + double(i) / M))); /// downcasting, potential bug
    return (konstanta * nizFunkcija(2 * k * PI * p / T) + 2. * sum / M);
  };
  
  a.push_back(gen_function(0, ::cos));
  b.push_back(0);

  for(int i(1); i <= N; ++i) {
      a.push_back(gen_function(i, ::cos));
      b.push_back(gen_function(i, ::sin));
  }
}
FourierovRed::FourierovRed(const FourierovRed& red) : N(red.N), T(red.T), a(red.a), b(red.b) { }
FourierovRed::FourierovRed(FourierovRed&& red) {
    this->IsprazniMemoriju();
    std::swap(N, red.N); std::swap(T, red.T);
    a.swap(red.a); b.swap(red.b);
}

/// operator implementation for class FourierovRed
/// DIJELJENJE NULOM, STA OVDJE? ZA T = 0
double FourierovRed::operator()(double x) const {
  double sum(0);
  for(int k(1); k <= N; ++k) 
    sum += a[k]*::cos(2*k*PI*x/T) + b[k]*::sin(2*k*PI*x/T);
  return a[0]/2. + sum;
}
std::pair<double, double> FourierovRed::operator[](int k) const {
  if(k < 0 || k >= N)
    throw std::range_error("Neispravan indeks");

  if(k == 0) return { a[k], 0 };
  return {a[k], b[k]};
}
std::pair<double&, double&> FourierovRed::operator[](int k) {
  if(k < 0 || k >= N)
    throw std::range_error("Neispravan indeks");

  b[0] = 0;
  return {a[k], b[k]};
}

/// copy and move operators
FourierovRed& FourierovRed::operator=(const FourierovRed& red) {    
  this->IsprazniMemoriju();
  N = red.N;  T = red.T;
  a = red.a;  b = red.b;
  return *this;
}
FourierovRed& FourierovRed::operator=(FourierovRed&& red) {
   this->IsprazniMemoriju();
   std::swap(N, red.N); std::swap(T, red.T);
   a.swap(red.a); b.swap(red.b);
   return *this;
}

int main () {

	return 0;
}