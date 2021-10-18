/B2017/2018: Zadaća 3, Zadatak 1
#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
#include <stdexcept>
#include <cmath>
#include <functional>

bool fun (const std::pair<double, double> &Prvi, const std::pair<double, double> &Drugi)
{
     if (Prvi.first < Drugi.first) return true;
     return false;
}

std::function<double(double)>LinearnaInterpolacija(std::vector<std::pair<double,double>>cvorovi)
{
     std::sort(cvorovi.begin(), cvorovi.end(), fun);

     for(int i (0); i<cvorovi.size(); i++) {
          for(int j(i+1); j<cvorovi.size(); j++) {
               if(cvorovi.at(i).first == cvorovi.at(j).first) {
                    throw std::domain_error ("Neispravni cvorovi");
               }
          }
     }
     return [cvorovi] (double x) {
          if(x < cvorovi.at(0).first || x > cvorovi.at(cvorovi.size()-1).first) {
               throw std::range_error ("Argument izvan opsega");
          }
          auto it = std::lower_bound(cvorovi.begin(),cvorovi.end(), x, [] (const std::pair<double,double> &Par, double x) {
               if (Par.first < x) return true;
               return false;
          });
          auto it1=it;
          if(it == cvorovi.begin()) it1= it + 1;
          else it1 = it - 1;
          return it->second + ((it1->second - it->second) / (it1->first - it->first)) * (x - it->first);
     };
}

std::function<double(double)> LinearnaInterpolacija(std::function<double(double)> f, double minimum, double maximum, double delta)
{
     if(minimum > maximum || delta <= 0) {
          throw std::domain_error ("Nekorektni parametri");
     }
     std::vector<std::pair<double,double>> cvor;
     while(minimum <= maximum) {
          cvor.push_back(std::make_pair(minimum, f(minimum)));
          minimum += delta;
     }
     return LinearnaInterpolacija(cvor);
}
double funkcija(double b)
{
     return b * b + std::sin(b);
}

int main ()
{

     std::vector<std::pair<double,double>> ve;

     int n;
     std::cout<<"Odaberite opciju (1 - unos cvorova, 2 - aproksimacija): ";
     std::cin>> n;
     if (n==1) {
          std::cout<<"Unesite broj cvorova: ";
          int a;
          std::cin>> a;
          std::cout<<"Unesite cvorove kao parove x y: ";

          try {
               double x,y;
               for(int i(0); i<a; i++) {
                    std::cin>> x >>y;
                    ve.push_back({x,y});
               }
               auto fun(LinearnaInterpolacija(ve));
               while(1) {
                    std::cout<<"Unesite argument (ili \"kraj\" za kraj): ";
                    double b;
                    std::cin>> b;
                    if(!std::cin || std::cin.get() != '\n') {
                         std::cin.ignore(1000,'\n');
                         break;
                    }
                    try {
                         std::cout<< "f("<< b << ") = " << fun(b);
                         std::cout << std::endl;

                    }

                    catch(std::range_error i) {
                         std::cout<< i.what()<< std::endl;
                    }
               }
          }

          catch(std::domain_error i) {
               std::cout << i.what();
          }

     } else if(n==2) {
          std::cout<<"Unesite krajeve intervala i korak: ";
          double x, y, z;
          try {
               std::cin>> x >> y >> z;
               auto fun(LinearnaInterpolacija(funkcija, x, y, z));
               while(1) {
                    std::cout<<"Unesite argument (ili \"kraj\" za kraj): ";
                    double b;
                    std::cin>> b;
                    if(!std::cin || std::cin.get() != '\n') {
                         std::cin.ignore(1000,'\n');
                         break;
                    }
                    try {
                         std::cout<< "f("<< b << ") = " << funkcija(b) << " fapprox(" << b << ") = " << fun(b);
                         std::cout << std::endl;
                    } catch (std::range_error i) {
                         std::cout << i.what() << std::endl;
                    }
               }
          } catch(std::domain_error i) {
               std::cout << i.what();
          }
     }
     return 0;
}
