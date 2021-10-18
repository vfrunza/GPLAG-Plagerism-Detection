/B2017/2018: Zadaća 5, Zadatak 4
#include <iostream>
#include <stdexcept>
#include <functional>
#include <algorithm>
#include <utility>
#include <cmath>

class FourierovRed {
private:
    double static constexpr PI = 4 * std::atan(1);
    double static constexpr ERROR = 0.0000000001;
    int N;
    double T;
    double* a;
    double* b;
    
    void static checkParams(int num, int M = 1, double p = 1, double q = 1, bool ntype = false) {
      if(num <= 0) throw std::domain_error("Stepen mora biti pozitivan");
      if(ntype) {
        if(M <= 0) throw std::domain_error("Broj podintervala mora biti pozitivan");
        if(p - q >= ERROR) throw std::range_error("Neispravan interval");
      }
    }
    void static createCoefficientArrays(double*& arrA, double*& arrB, int size) {
      try {
        arrA = new double[size]();
        arrB = new double[size]();
      } catch (...) {
        delete [] arrA; arrA = nullptr;
        delete [] arrB; arrB = nullptr;
        throw;
      }
    }
    void IsprazniMemoriju();
public:
  ~FourierovRed();
  FourierovRed(const FourierovRed& red);
  FourierovRed(FourierovRed&& red);
  
  FourierovRed& operator=(const FourierovRed& red);
  FourierovRed& operator=(FourierovRed&& red);
  
  int Dimenzija() const { return this-> N; }
  
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
	this->N = 0; this->T = 0;
}
void FourierovRed::IsprazniMemoriju() {
	  delete[] this->a; this->a = nullptr;
	  delete[] this->b; this->b = nullptr;
    this->N = 0; this->T = 0;
}
/// ctors
FourierovRed::FourierovRed(double t, std::initializer_list<double> k_a, std::initializer_list<double> k_b) : 
    T(t), a(nullptr), b(nullptr) {
  N = std::max(k_a.size(), k_b.size()) + (k_b.size() >= k_a.size() ? 1 : 0);
  
  createCoefficientArrays(a, b, N);

  int pos(0);
  for(auto it(k_a.begin()); it != k_a.end(); a[pos++] = *it++);
  pos = 1;
  for(auto it(k_b.begin()); it != k_b.end(); b[pos++] = *it++);
}
FourierovRed::FourierovRed(int N, double T, std::function<double(int)> funk_a, std::function<double(int)> funk_b) : 
	  N(N), T(T), a(nullptr), b(nullptr) {
  checkParams(N);
  
  createCoefficientArrays(a, b, N + 1);
  try { a[0] = funk_a(0); }
  catch (...) {
    this->IsprazniMemoriju();
    throw;
  }
  
  for(int i(1); i <= N; ++i) {
    try {
      a[i] = funk_a(i);
      b[i] = funk_b(i);
    } catch (...) {
      this->IsprazniMemoriju();
      throw;
    }
  }
}
FourierovRed::FourierovRed(int N, double p, double q, std::function<double(double)> f, int M) : 
	  N(N), T(q - p), a(nullptr), b(nullptr) {
  checkParams(N, M, p, q, true);
 
  double konstanta ((f(p) + f(q)) / M); /// downcasting, potential bug
  auto gen_function = [=](int k, std::function<double(double)> nizFunkcija) -> double {
    double sum(0);
    for(int i(1); i < M; ++i)
      sum += f(p + (i * T / M)) * nizFunkcija((2 * k * PI * (p / T + double(i) / M))); /// downcasting, potential bug
    return (konstanta * nizFunkcija(2 * k * PI * p / T) + 2. * sum / M);
  };
 
  createCoefficientArrays(a, b, N + 1);
  
  try { a[0] = gen_function(0, ::cos); }
  catch (...) {
    this->IsprazniMemoriju();
    throw;
  }
  for(int i(1); i <= N; ++i) {
    try {
      a[i] = gen_function(i, ::cos);
      b[i] = gen_function(i, ::sin);
    } catch (...) {
      this->IsprazniMemoriju();
      throw;
    }
  }
}
FourierovRed::FourierovRed(const FourierovRed& red) : N(red.N), T(red.T), a(nullptr), b(nullptr) {
  createCoefficientArrays(a, b, N + 1);
  for(int i(0); i <= N; ++i) {
    a[i] = red.a[i];
    b[i] = red.b[i];
  }
}
FourierovRed::FourierovRed(FourierovRed&& red) {
   this->IsprazniMemoriju();
   std::swap(N, red.N); std::swap(T, red.T);
   std::swap(a, red.a); std::swap(b, red.b);
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
  
  if(k == 0) return {a[0], 0};
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
	if (N != red.N) {
	  double* novi_a (nullptr); 
    double* novi_b (nullptr);
		createCoefficientArrays(novi_a, novi_b, red.N + 1);
		this->IsprazniMemoriju();
		std::swap(a, novi_a);
		std::swap(b, novi_b);
	}
	
  N = red.N; T = red.T;
  for(int i(0); i <= N; ++i) {
    a[i] = red.a[i];
    b[i] = red.b[i];
  }
  return *this;
}
FourierovRed& FourierovRed::operator=(FourierovRed&& red) {
   this->IsprazniMemoriju();
   std::swap(N, red.N); std::swap(T, red.T);
   std::swap(a, red.a); std::swap(b, red.b);
   return *this;
}

int main () {

	return 0;
}