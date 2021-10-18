/B2017/2018: Zadaća 3, Zadatak 1
#include <iostream>
#include <stdexcept>
#include <vector>
#include <utility>
#include <functional>
#include <cmath>
#include <algorithm>
#define EPSILON 0.0001

double funkcija(double x)
{
 return x*x+std::sin(x);
}

bool kriterij(std::pair<double,double> par1, std::pair<double,double> par2)
{
 if(par1.first<par2.first) return true;
 return false;
}

bool kriterij_binarne(std::pair<double,double> par1, std::pair<double,double> par2)
{
 if(par1.first<=par2.first) return true;
 return false;
}

std::function<double(double)> LinearnaInterpolacija(std::vector<std::pair<double,double>> cvorovi)
{
 for(std::pair<double,double> vek : cvorovi)
 {
  auto broj=std::count_if(cvorovi.begin(),cvorovi.end(),[vek](std::pair<double,double> x) { if(fabs(x.first-vek.first)>EPSILON) return true; return false; });
  if(broj!=1) 
  {
   std::sort(cvorovi.begin(),cvorovi.end(),kriterij);
   break;
  }
 }
 for(std::pair<double,double> par : cvorovi)
 {
  auto prebroj=std::count_if(cvorovi.begin(),cvorovi.end(),[par](std::pair<double,double> x) { if(fabs(par.first-x.first)<EPSILON) return true; return false; });
  if(prebroj!=1) throw std::domain_error("Neispravni cvorovi");
 }
 return[=](double x) -> double
 {
  if(x<cvorovi[0].first || x>cvorovi[cvorovi.size()-1].first)
  {
   throw std::range_error("Argument izvan opsega");
  }
  auto par1=std::pair<double,double>(x,0);
  auto it=std::lower_bound(cvorovi.begin(),cvorovi.end(),par1,kriterij_binarne);
  it--;
  auto parx=it->first;
  auto pary=it->second;
  if((fabs(parx-cvorovi[cvorovi.size()-1].first)<EPSILON) && (fabs(pary-cvorovi[cvorovi.size()-1].second)<EPSILON))
  {
   return pary;
  }
  it++;
  auto parx_plus1=it->first;
  auto pary_plus1=it->second;
  double rez;
  rez=pary+(((pary_plus1-pary)/(parx_plus1-parx))*(x-parx));
  return rez;
 };
}

template<typename TipFunkcije>
std::function<double(double)> LinearnaInterpolacija(TipFunkcije fun, double xmin, double xmax, double deltax)
{
 if(xmin>xmax) throw std::domain_error("Nekorektni parametri");
 if(deltax<=0) throw std::domain_error("Nekorektni parametri");
 std::vector<std::pair<double,double>> vektor;
 while(xmin<xmax)
 {
  std::pair<double,double> pom{xmin,fun(xmin)};
  vektor.push_back(pom);
  xmin+=deltax;
 }
 return LinearnaInterpolacija(vektor);
}

int main ()
{
 int opcija1;
 std::cout << "Odaberite opciju (1 - unos cvorova, 2 - aproksimacija): ";
 std::cin >> opcija1;
 if(opcija1==1)
 {
  try
  {
   int broj_cvorova,unos1,unos2;
   std::cout << "Unesite broj cvorova: ";
   std::cin >> broj_cvorova;
   std::vector<std::pair<double,double>> cvorovi;
   std::cout << "Unesite cvorove kao parove x y: ";
   for(int i(0);i<broj_cvorova;i++)
   {
    std::cin >> unos1 >> unos2;
    cvorovi.push_back(std::make_pair(unos1,unos2));
   }
   double arg;
   do
   {
    try
    {
     auto f(LinearnaInterpolacija(cvorovi));
     std::cout << "Unesite argument (ili \"kraj\" za kraj): ";
     std::cin >> arg;
     if(!std::cin) break;
     std::cout << "f(" << arg << ") = " << f(arg);
     std::cout << std::endl;
    }
    catch(std::range_error e)
    {
     std::cout << e.what() << std::endl;
    }
   }while(std::cin);
  }
  catch(std::domain_error e)
  {
   std::cout << e.what() << std::endl;
  }
 }
 else if(opcija1==2)
 {
  try
  {
   double kraj1,kraj2,korak;
   std::cout << "Unesite krajeve intervala i korak: ";
   std::cin >> kraj1 >> kraj2 >> korak;
   double arg;
   do
   {
    try
    {
     auto f(LinearnaInterpolacija(funkcija,kraj1,kraj2,korak));
     std::cout << "Unesite argument (ili \"kraj\" za kraj): ";
     std::cin >> arg;
     if(!std::cin) break;
     std::cout << "f(" << arg << ") = " << funkcija(arg) << " fapprox(" << arg << ") = " << f(arg);
     std::cout << std::endl;
    }
    catch(std::range_error e)
    {
     std::cout << e.what() << std::endl;
    }
   }while(std::cin);
  }
  catch(std::domain_error e)
  {
   std::cout << e.what() << std::endl;
  }
 }
 return 0;
}
