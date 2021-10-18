/B2017/2018: Zadaća 5, Zadatak 5
// posluzio sam se kodom iz zadatka 4
#include <iostream>
#include <new>
#include <initializer_list>
#include <functional>
#include <map>
#include <stdexcept>
#include <cmath>
#include <vector>

typedef std::pair<double,double> Par;
typedef std::pair<double&, double&> RefPar;

double PI = ((atan(1)*4));

double Polinom (double f(double), double s_ili_c(double), int M, double T, double p, double q, int k){
  double vrati( ((f(p)+f(q))*s_ili_c((2*k*p*PI)/T))/double(M)   );
  double suma(0);
  for (int i = 1; i<=(M-1); i++) suma+=f(p+(i*T)/double(M))*s_ili_c(2*k*PI*(p/T+double(i)/M));
  suma=(suma*2.)/M;
  return suma+vrati;
}

class FourierovRed
{
  std::vector<double> a_k, b_k;
  double period;

public:
  FourierovRed (double period, std::initializer_list<double> a, std::initializer_list<double> b);
  FourierovRed (int N, double T, double a(int), double b(int));
  FourierovRed (int N, double p, double q, double f(double),int M);
  
  // operator dodjele
  FourierovRed &operator = (const FourierovRed &f_red) {
    if (this==&f_red) return *this; // destruktivna samododjela
    a_k=f_red.a_k;
    b_k=f_red.b_k;
    period=f_red.period;
    return *this;
  }
  
  // kopirajuco konstruktor
  FourierovRed (const FourierovRed &f_red) {
    if (this==&f_red) return;
    period=f_red.period;
    a_k=f_red.a_k;
    b_k=f_red.b_k;
  }
  // nevjerovatno sta sam pogrijesio
  // pomjerajuci operator dodjele
  FourierovRed &operator = (FourierovRed &&f_red){
    std::swap(a_k,f_red.a_k);
    std::swap(b_k,f_red.b_k);
    std::swap (period,f_red.period);
    return *this;
  }
  
  // pomjerajuci konstruktor
  FourierovRed (FourierovRed &&f_red) : a_k(f_red.a_k), b_k(f_red.b_k), period(f_red.period) {
    f_red.a_k.resize(0);
    f_red.b_k.resize(0);
  }
  
  double operator () (double k) const;
  Par operator [] (int k) const;
  RefPar operator [] (int k);
  
  void Ispisi() const;
  
};

FourierovRed::FourierovRed (double period, std::initializer_list<double> a, std::initializer_list<double> b) : period(period)
{
  int duzina;
  bool a_manji(false),b_manji(false);
  if (a.size()>b.size()) {
    duzina=a.size();
    b_manji=true;
  } else {
    duzina=b.size();
    a_manji=true;
  }
  if (a_manji) duzina++;
  a_k.resize(duzina);
  b_k.resize(duzina);

  for (int i = 0; i<duzina; i++) {
    if (a_manji && i>=a.size()) a_k.at(i)=0;
    else
      a_k.at(i)=*(a.begin()+i);

    if (b_manji && i>=b.size()) b_k.at(i)=0;
    else if (i==0) b_k.at(0)=0.;
    else
      b_k.at(i)=*(b.begin()+i-1);
  }
}

FourierovRed::FourierovRed (int N, double T, double a(int), double b(int)) : period(T) {
  if (N<=0) throw std::domain_error ("Stepen mora biti pozitivan");
  int duzina;
  duzina=N;
  duzina++;
  a_k.resize(duzina);
  b_k.resize(duzina);
  for (int i = 0; i<duzina; i++){
    a_k.at(i)=a(i);
    if (i==0) {b_k.at(0)=0.; continue; }
    b_k.at(i)=b(i);
  }
}

FourierovRed::FourierovRed (int N, double p, double q, double f(double), int M) {
  if (N<=0) throw std::domain_error ("Stepen mora biti pozitivan");
  if (M<=0) throw std::domain_error ("Broj podintervala mora biti pozitivan");
  if (p>=q) throw std::range_error ("Neispravan interval");
  int duzina;
  duzina=N;
  period=q-p;
  duzina++;
  a_k.resize(duzina);
  b_k.resize(duzina);
  for (int i = 0; i<duzina; i++){
    a_k.at(i)=Polinom(f,std::cos, M, period, p, q, i);
    if (i==0) { b_k.at(0)=0.; continue; }
    b_k.at(i)=Polinom(f,std::sin, M, period, p, q, i);
  }
  
}

Par FourierovRed::operator [](int k) const{
  if (k>=a_k.size() || k<0 ) throw std::range_error ("Neispravan indeks");
  return {a_k.at(k),b_k.at(k)};
}


RefPar FourierovRed::operator [](int k) {
  if (k>=a_k.size() || k<0) throw std::range_error ("Neispravan indeks");
  return {a_k.at(k),b_k.at(k)};
}

double FourierovRed::operator () (double x) const {
  double suma(0.);
  for (int i = 1; i<a_k.size(); i++) suma+=a_k[i]*cos((2*PI*i*x)/period)+b_k[i]*sin((2*PI*i*x)/period);
  return (a_k[0]/2+suma);
  
}

void FourierovRed::Ispisi() const
{
  for (int i = 0; i<a_k.size(); i++) std::cout<<"a_k"<<i<<" = "<<a_k[i]<<"              b_k"<<i<<" = "<<b_k[i]<<std::endl;
}

int main ()
{
  try {
    FourierovRed red1(50, 2*PI, [](int k)->double {if (k==0) return 8*PI*PI/3; return 4./(k*k);}, 
    [](int k)->double {return -4*PI/k;});
   // red1.Ispisi();
    FourierovRed red2(50,0,2*PI, [](double x) {return x*x;}, 1000);
    std::cout<<std::endl;
    red1.Ispisi();
   // red2.Ispisi();
   red2=red1=red2=red1;
   std::cout<<std::endl;
   red1[0].first=5;
   red1[0].second=3;
   red1.Ispisi();
    std::cout<<red1(3)<<std::endl;
    std::cout<<red2(3);
    /*
    double L=2;
    FourierovRed f1(2*L, {2*L, 1}, {});
    FourierovRed f2(2*L, {1}, {-1.27324, 0.63662, -0.42441, 0.31831, -0.25465, 0.21221, -0.18189, 0.15915, -0.14147, 0.12732});
    FourierovRed f3(2*L, {2*L}, {-1.27324, 0.63662, -0.42441, 0.31831, -0.25465, 0.21221, -0.18189, 0.15915, -0.14147, 0.12732});
    f1.Ispisi();
    f2.Ispisi();
    f3.Ispisi();
    std::cout<<f1[2].first<<" "<<f1[2].second;
    
  FourierovRed red(3, {1}, {1,2,8,9});
  FourierovRed red2(10, 2.6, [] (int k)->double { if (k==0) return 1; return 1./k;}, [](int k)->double {return 0;} );
  FourierovRed red3(50, 0, 2*PI, [](double k) { return k*k;}, 1000);
  std::cout<<red3(1)<<std::endl;
 // red3.Ispisi();*/
}
catch (std::range_error iz){
  std::cout<<iz.what();
}
  return 0;
}
