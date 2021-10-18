/B2017/2018: Zadaća 3, Zadatak 1
#include <iostream>
#include <vector>
#include <utility>
#include <stdexcept>
#include <algorithm>
#include <functional>
#include <cmath>

// predefined data
using Par = std::pair<double, double>;
using VeomaVelikTip = unsigned long long;
constexpr double _ERROR (0.0000001);
enum class InputType {PAIRS = 1, FUNCTION = 2};

// 2 parameters function to approximate function
std::function<double(double)> LinearnaInterpolacija(std::vector<Par> inputArr) {
     int _len (inputArr.size());
     std::sort(inputArr.begin(), inputArr.end(), [](const Par &p1, const Par &p2) { return p1.first < p2.first; });
     
     if(std::unique(inputArr.begin(), inputArr.end(), [](const Par& a, const Par& b) {
          return std::fabs(a.first - b.first) <= _ERROR;
     }) != inputArr.end())
          throw std::domain_error("Neispravni cvorovi");
          
     return [=](double x) {
          if(inputArr.empty() || x < inputArr.at(0).first || inputArr.at(_len-1).first < x)
               throw std::range_error("Argument izvan opsega");
               
          // special case x = xn
          if(std::fabs(x - inputArr.at(_len-1).first) <= _ERROR)
               return inputArr.at(_len-1).second;
               
          // calculate function
          auto pos = std::upper_bound (inputArr.begin(), inputArr.end(), Par(x, x)) - 1;
          if(pos < inputArr.begin()) pos++;
          
          return (pos->second + ((pos+1)->second - pos->second)/((pos+1)->first - pos->first) * (x - pos->first));
     };
}

// 4 parameters function to approximate function
std::function<double(double)> LinearnaInterpolacija(std::function<double(double)> f, const double &x_min, const double &x_max, const double &dx) {
     if(x_min > x_max || dx <= 0.)
          throw std::domain_error("Nekorektni parametri");
     
     return [=](double x) {
          if(x < x_min || x > x_max)
               throw std::range_error("Argument izvan opsega");
          
          if(std::fabs(x_min - x_max) < _ERROR) return f(x_min);
          
          VeomaVelikTip k (static_cast<VeomaVelikTip>((x - x_min) / dx));
          double _prev (x_min + k*dx), _next (k ? x_min + (k + 1)*dx : x_max);
          
          if(_next > x_max) _next = x_max;
          if(std::fabs(_next - _prev) < _ERROR) return f(_prev);
          return (f(_prev) + (f(_next) - f(_prev))/(_next - _prev) * (x - _prev));
     };
}

// main program logic
int main () {
     auto g = [](double x) -> double { 
          return x*x + std::sin(x); 
     };

     int _tip;
     std::cout << "Odaberite opciju (1 - unos cvorova, 2 - aproksimacija): ";
     for(;;) {
          std::cin >> _tip;
          if(_tip != 1 && _tip != 2) std::cout << "Greska, unesite ponovo!";
          else break;
     }

     /* create variables */
     InputType _type (static_cast<InputType>(_tip));
     int _size;
     double x_min, x_max, dx, args;
     std::vector<Par> inputArr;
     std::function<double(double)> fapprox;
     
     if(_type == InputType::PAIRS) {
          Par _temp;
          std::cout << "Unesite broj cvorova: "; std::cin >> _size;
          std::cout << "Unesite cvorove kao parove x y: ";
          for(int i(0); i < _size; ++i) {
               std::cin >> _temp.first >> _temp.second;
               inputArr.push_back(_temp);
          }
     }
     else if(_type == InputType::FUNCTION) {
          std::cout << "Unesite krajeve intervala i korak: "; std::cin >> x_min >> x_max >> dx;
     }
     
     // create function and start apr.
     try {
          if(_type == InputType::PAIRS) fapprox = LinearnaInterpolacija(inputArr);
          else fapprox = LinearnaInterpolacija(g, x_min, x_max, dx);
     }
     catch(std::exception& e) {
          std::cout << e.what();
          return -1;
     }
     
     for(;;) {
          std::cout << "Unesite argument (ili \"kraj\" za kraj): ";
          std::cin >> args;
          if(!std::cin || std::cin.peek() != '\n')
               return -1;
          try {
               if(_type == InputType::PAIRS) 
                    std::cout << "f(" << args << ") = " << fapprox(args) << std::endl;
               else if(_type == InputType::FUNCTION) 
                    std::cout << "f(" << args << ") = " << g(args) << " fapprox(" << args << ") = " << fapprox(args) << std::endl;
          }
          catch(std::exception& e) {
               std::cout << e.what() << std::endl;
          }
     }
	return 0;
}