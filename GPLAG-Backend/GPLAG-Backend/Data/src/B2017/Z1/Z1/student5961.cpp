#include <iostream>
#include <cmath>
#include <vector>
#include <deque>
#include <limits>
#include <algorithm>

#define BASE 		          3
using IntArr = std::vector<int>;
using DekArr = std::deque<int>;

/* integer validity */
inline bool isValidNum(const long &num) {
     return ((num <= std::numeric_limits<int>::max()) && (num >= std::numeric_limits<int>::min()));
}

/* prime check */
bool isPrime(const int &num) {
     /* error check */
     if(std::abs(num) <= 1 || !isValidNum(num)) return false;
     
	for(int i(2); i <= static_cast<int>(std::sqrt(std::abs(num))); ++i)
		if(num % i == 0) return false; 		
		
	return true;
}

/* symmetry check in respect of base / WITH CONVERSION */
bool isSymmetricalinBase3(int num, int base) {
     /* error check */
     if(!isValidNum(num) || (std::abs(num) == 1)) 
          return false;
          
     DekArr digits, digReversed;
     for(;abs(num) > 0;) {
          digits.push_back(std::abs(num) % base);
          digReversed.push_front(std::abs(num) % base);
          num /= base;
     }
     
     return (digits == digReversed);
}

/* check if exists in array */
bool PostojiUNizu(const IntArr &niz, const int &num) {
     for(int i(0); i < niz.size(); ++i) {
          if(niz.at(i) == num) return true;
     }
     return false;
}

/* function to find numbers with specified properties */
IntArr IzdvojiSimetricneTernarne(const IntArr &niz, bool returnPrime) {
	IntArr returnArr;
	
	for(int i(0); i < niz.size(); ++i) 
	     if(isSymmetricalinBase3(niz.at(i), BASE) && (isPrime(niz.at(i)) == returnPrime) && 
	          !PostojiUNizu(returnArr, niz.at(i)))
	          returnArr.push_back(niz.at(i));
	          
     return returnArr;
}

/* main function */
int main () {
     IntArr niz;
     int num, type;
     
     /* input (improve checking) */
     std::cout << "Unesite elemente vektora (-1 za kraj): ";
     for(;;) {
          std::cin >> num;
          /* error check */
          if(!std::cin) {
               std::cin.clear();
               std::cin.ignore(10000, '\n');
          } else {
               if(num == -1) break;
               niz.push_back(num);
          }
     }
     
     /* type */
     std::cout << "Unesite: 1 - za proste brojeve, 0 - za slozene brojeve: ";
     for(;;) {
          std::cin >> type;
          if((type != 1 && type != 0) || !std::cin) {
               std::cout << "Neispravan unos! Unesite ponovo: ";
               if(!std::cin) {
                    std::cin.clear();
                    std::cin.ignore(10000, '\n');
               }
          }
          else break;
     }
     
     /* do the job */
     niz = IzdvojiSimetricneTernarne(niz, type);
     if(niz.empty()) std::cout << "Nema " << (type ? "prostih":"slozenih") << " simetricnih brojeva u vektoru.";
     else {
          std::cout << (type ? "Prosti":"Slozeni") << " simetricni brojevi iz vektora su: ";
          for(int i = 0; i < niz.size()-1; (std::cout << niz.at(i++) << ", "));
          std::cout << niz.at((niz.size()-1)) << ".";
     }
	return 0;
}