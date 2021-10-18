#include <iostream>
#include <cmath>
#include <vector>
#include <deque>
#include <limits>

using IntArr = std::vector<int>;
using DekVek = std::deque<std::vector<int>>;
enum Smjer {Rastuci, Opadajuci};  

/* integer validity */
inline bool isValidNum(const long &num) {
     return ((num <= std::numeric_limits<int>::max()) && (num >= std::numeric_limits<int>::min()));
}

/* check if m=2^n */
inline bool isPowTwo(const long &num) {
     return (isValidNum(num) && (num > 0) && !(num & (num-1)));
}

/* print an array */
void IspisiArr(const IntArr &niz) {
     for(auto element:niz) std::cout << element << " ";
     std::cout << std::endl;
}

/* function to implement */
DekVek MaksimalniPodnizoviStepenaDvojke(const IntArr &arr, Smjer p) {
     DekVek returnDek;
     
     /* validate input parameters first */
     if(arr.empty() || ((p != Rastuci) && (p != Opadajuci))) 
          return returnDek; 
     
     /* start checking */
     IntArr temp;
     int pos{0};
     for(;;) {
          temp.clear();
          if((pos >= (arr.size()-1))) break;
          /* start checking through array */
          while((pos+1 < arr.size()) 
                    && (((arr.at(pos) > arr.at(pos+1)) == static_cast<std::underlying_type<Smjer>::type>(p)) ||
                         ((arr.at(pos) == arr.at(pos+1))))
                    && isPowTwo(arr.at(pos)) && isPowTwo(arr.at(pos+1))) {
               temp.push_back(arr.at(pos));
               pos++;
          }
          /* add last element into array */
          if(!temp.empty()) {
               temp.push_back(arr.at(pos));
               returnDek.push_back(temp);
               
               /* in case of same elements, get back one place */
               if(arr.at(pos) == arr.at(pos-1)) pos--;
          }
          pos++;
     }
     
     /* default output */
     return returnDek;
}

/* main function */
int main () {
     IntArr niz;
     int size, type, num;
     /* read data (with error checking) */
     std::cout << "Unesite broj elemenata vektora: ";
     std::cin >> size;
     
     std::cout << "Unesite elemente vektora: ";
     for(int i(0); i < size; ++i) {
          std::cin >> num;
          niz.push_back(num);
     }
     
     std::cout << "Unesite: 1 - za rastuce podnizove, 2 - za opadajuce podnizove: ";
     for(;;) {
          std::cin >> type;
          if(type == 1 or type == 2) break;
          else std::cout << "Pogresan unos!" << std::endl;
     }
     
     /* do the job */
     DekVek arr{MaksimalniPodnizoviStepenaDvojke(niz, static_cast<Smjer>(type-1))};
     if(arr.empty()) std::cout << "U datom nizu nema monotono "<< ((type == 1) ? "rastucih":"opadajucih") << " podnizova.";
     else {
          std::cout << "Maksimalni "<< ((type == 1) ? "rastuci":"opadajuci") << " podnizovi: " << std::endl;
          for(auto niz:arr) IspisiArr(niz);
     }
	return 0;
}